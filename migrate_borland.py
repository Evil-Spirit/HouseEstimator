#!/usr/bin/env python3
"""
migrate_borland.py – Transform Borland C++ Builder source files for Qt/MSVC.

Usage:
    python migrate_borland.py [path ...]

    path can be:
        - A single .h or .cpp file
        - A directory (all .h and .cpp files inside are processed recursively)
        - Defaults to CAD_DEMO/Source/ if no arguments are given

The script is idempotent: running it twice produces the same result.
"""

import os
import re
import sys
import argparse
from pathlib import Path

# ---------------------------------------------------------------------------
# VCL / Borland system headers that should be replaced by vcl_qt.h
# ---------------------------------------------------------------------------
VCL_HEADERS = {
    "<vcl.h>",
    "<basepch.h>",
    "<ActnList.hpp>",
    "<Classes.hpp>",
    "<ComCtrls.hpp>",
    "<Controls.hpp>",
    "<Dialogs.hpp>",
    "<ExtCtrls.hpp>",
    "<ImgList.hpp>",
    "<Menus.hpp>",
    "<StdActns.hpp>",
    "<StdCtrls.hpp>",
    "<ToolWin.hpp>",
    "<AppEvnts.hpp>",
    "<Forms.hpp>",
    "<Buttons.hpp>",
    "<Graphics.hpp>",
    "<Grids.hpp>",
    "<CheckLst.hpp>",
    "<Clipbrd.hpp>",
    "<dateutils.hpp>",
    "<Math.hpp>",
    "<SysUtils.hpp>",
    "<System.hpp>",
    "<typeinfo.h>",  # Borland RTTI typeinfo, not standard
}

# Sentinel comment added once per file to mark it as already processed
IDEMPOTENCY_MARKER = "// [migrated-to-qt]"

# ---------------------------------------------------------------------------
# Helper: check whether a file is binary
# ---------------------------------------------------------------------------
def is_binary(path: Path) -> bool:
    try:
        with open(path, "rb") as f:
            chunk = f.read(8192)
        return b"\x00" in chunk
    except OSError:
        return True


# ---------------------------------------------------------------------------
# Core transformation
# ---------------------------------------------------------------------------
def transform(source: str, filepath: Path) -> tuple[str, bool]:
    """
    Apply all transformations to *source* text.
    Returns (new_source, changed).
    """
    if IDEMPOTENCY_MARKER in source:
        # Already processed – skip
        return source, False

    lines = source.splitlines(keepends=True)
    out: list[str] = []

    vcl_qt_added = False     # have we emitted the vcl_qt include yet?
    borland_h_added = False  # have we emitted borland.h guard?

    # Regex patterns compiled once
    RE_PRAGMA_HDRSTOP   = re.compile(r"^\s*#\s*pragma\s+hdrstop\b.*$")
    RE_PRAGMA_PACKAGE   = re.compile(r"^\s*#\s*pragma\s+package\s*\(.*\).*$")
    RE_INCLUDE_VCL      = re.compile(r'^\s*#\s*include\s+([<"][^>"]+[>"])')
    RE_INCLUDE_SUI      = re.compile(r'^\s*#\s*include\s+"SUISkinEngine\.hpp"')
    RE_INCLUDE_SUI_ANG  = re.compile(r'^\s*#\s*include\s+<SUISkinEngine\.hpp>')
    RE_USEFORM          = re.compile(r"^\s*USEFORM\s*\(.*\)\s*;?\s*$")
    RE_USEFILE          = re.compile(r"^\s*USE(?:FILE|UNIT|OBJ|LIB|RES)\s*\(.*\)\s*;?\s*$")
    RE_FASTCALL         = re.compile(r"\b__fastcall\b")
    RE_CLOSURE          = re.compile(r"\b__closure\b")
    RE_PACKAGE_KW       = re.compile(r"\bPACKAGE\b(?!\s*\()")
    RE_DECLSPEC_PACKAGE = re.compile(r"__declspec\s*\(\s*package\s*\)")

    # __property transformations
    # Simple: __property TYPE NAME = {read=G};
    # Read-write: __property TYPE NAME = {read=G, write=S};
    # Indexed (complex): __property TYPE NAME[...] = {...};
    RE_PROP_RW  = re.compile(
        r"__property\s+([\w\s\*&:<>]+?)\s+(\w+)\s*=\s*\{\s*read\s*=\s*(\w+)\s*,\s*write\s*=\s*(\w+)\s*\}\s*;")
    RE_PROP_R   = re.compile(
        r"__property\s+([\w\s\*&:<>]+?)\s+(\w+)\s*=\s*\{\s*read\s*=\s*(\w+)\s*\}\s*;")
    RE_PROP_IDX = re.compile(
        r"__property\s+.*\[.*\]\s*=\s*\{[^}]*\}\s*;")

    def replace_property(line: str) -> str:
        """Transform __property declarations."""
        # Skip indexed properties (comment them out)
        m = RE_PROP_IDX.search(line)
        if m:
            return "// [indexed property - needs manual migration]: " + line

        # Read-write property
        m = RE_PROP_RW.search(line)
        if m:
            ptype, pname, getter, setter = m.groups()
            ptype = ptype.strip()
            indent = line[: len(line) - len(line.lstrip())]
            # MSVC supports __declspec(property(...)); GCC/Clang do not.
            if os.environ.get("USE_MSVC_PROPERTY", ""):
                return (f"{indent}"
                        f"__declspec(property(get={getter}, put={setter})) "
                        f"{ptype} {pname};\n")
            # Default: emit a comment so the intent is preserved.
            return (f"{indent}// __property {ptype} {pname} "
                    f"{{read={getter}, write={setter}}}; "
                    f"// [manual migration needed]\n")

        # Read-only property
        m = RE_PROP_R.search(line)
        if m:
            ptype, pname, getter = m.groups()
            ptype = ptype.strip()
            indent = line[: len(line) - len(line.lstrip())]
            if os.environ.get("USE_MSVC_PROPERTY", ""):
                return (f"{indent}"
                        f"__declspec(property(get={getter})) "
                        f"{ptype} {pname};\n")
            return (f"{indent}// __property {ptype} {pname} "
                    f"{{read={getter}}}; // [manual migration needed]\n")

        return line

    # Add idempotency marker + borland.h guard at the top
    header_lines: list[str] = [
        f"{IDEMPOTENCY_MARKER}\n",
        '#ifndef __BORLANDC__\n',
        '#include "compat/borland.h"\n',
        '#endif\n',
    ]

    for line in lines:
        stripped = line.strip()

        # ----------------------------------------------------------------
        # 1. Remove #pragma hdrstop
        # ----------------------------------------------------------------
        if RE_PRAGMA_HDRSTOP.match(stripped):
            continue  # drop line

        # ----------------------------------------------------------------
        # 2. Remove #pragma package(...)
        # ----------------------------------------------------------------
        if RE_PRAGMA_PACKAGE.match(stripped):
            continue  # drop line

        # ----------------------------------------------------------------
        # 3. Remove USEFORM / USEFILE / USEUNIT etc.
        # ----------------------------------------------------------------
        if RE_USEFORM.match(stripped) or RE_USEFILE.match(stripped):
            continue

        # ----------------------------------------------------------------
        # 4. Replace VCL system includes with vcl_qt.h (once per file)
        # ----------------------------------------------------------------
        m_inc = RE_INCLUDE_VCL.match(stripped)
        if m_inc:
            token = m_inc.group(1)
            # Normalize: strip quotes/angle-brackets for lookup
            inner = token.strip('"<>')
            lookup_token = f"<{inner}>" if token.startswith("<") else f'"{inner}"'
            if lookup_token in VCL_HEADERS or (token.startswith('"') and f"<{inner}>" in VCL_HEADERS):
                if not vcl_qt_added:
                    out.append('#include "compat/vcl_qt.h"\n')
                    vcl_qt_added = True
                continue  # drop original VCL include
            # Also catch quoted VCL headers
            if inner in {h.strip('<>"') for h in VCL_HEADERS}:
                if not vcl_qt_added:
                    out.append('#include "compat/vcl_qt.h"\n')
                    vcl_qt_added = True
                continue

        # ----------------------------------------------------------------
        # 5. Replace SUISkinEngine.hpp include
        # ----------------------------------------------------------------
        if RE_INCLUDE_SUI.match(stripped) or RE_INCLUDE_SUI_ANG.match(stripped):
            out.append('#include "compat/SUISkinEngine.hpp"\n')
            continue

        # ----------------------------------------------------------------
        # 6. Strip __fastcall
        # ----------------------------------------------------------------
        line = RE_FASTCALL.sub("", line)

        # ----------------------------------------------------------------
        # 7. Strip __closure
        # ----------------------------------------------------------------
        line = RE_CLOSURE.sub("", line)

        # ----------------------------------------------------------------
        # 8. Strip standalone PACKAGE keyword (not inside __declspec)
        # ----------------------------------------------------------------
        line = RE_PACKAGE_KW.sub("", line)

        # ----------------------------------------------------------------
        # 9. Replace __declspec(package) → Q_DECL_EXPORT
        # ----------------------------------------------------------------
        line = RE_DECLSPEC_PACKAGE.sub("Q_DECL_EXPORT", line)

        # ----------------------------------------------------------------
        # 10. Transform __property declarations
        # ----------------------------------------------------------------
        if "__property" in line:
            line = replace_property(line)

        out.append(line)

    # Prepend the header (marker + borland.h guard)
    final_lines = header_lines + out
    new_source = "".join(final_lines)
    return new_source, True


# ---------------------------------------------------------------------------
# File processor
# ---------------------------------------------------------------------------
def process_file(path: Path, dry_run: bool = False) -> bool:
    """Process a single file. Returns True if the file was (or would be) changed."""
    if is_binary(path):
        return False

    try:
        # Try UTF-8, fall back to Latin-1
        try:
            source = path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            source = path.read_text(encoding="latin-1")
    except OSError as e:
        print(f"  [ERROR] Cannot read {path}: {e}", file=sys.stderr)
        return False

    new_source, changed = transform(source, path)

    if not changed:
        print(f"  [skip]  {path}  (already migrated)")
        return False

    print(f"  [write] {path}")
    if not dry_run:
        try:
            path.write_text(new_source, encoding="utf-8")
        except OSError as e:
            print(f"  [ERROR] Cannot write {path}: {e}", file=sys.stderr)
            return False
    return True


# ---------------------------------------------------------------------------
# Collect files
# ---------------------------------------------------------------------------
def collect_files(paths: list[str]) -> list[Path]:
    result: list[Path] = []
    for p in paths:
        pp = Path(p)
        if pp.is_file():
            if pp.suffix in (".h", ".cpp", ".hpp", ".cxx", ".cc"):
                result.append(pp)
        elif pp.is_dir():
            for ext in ("*.h", "*.cpp", "*.hpp", "*.cxx", "*.cc"):
                for fp in sorted(pp.rglob(ext)):
                    # Skip the compat/ directory itself
                    parts = fp.parts
                    if "compat" in parts:
                        continue
                    result.append(fp)
        else:
            print(f"[WARNING] Path not found: {p}", file=sys.stderr)
    return result


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------
def main() -> int:
    parser = argparse.ArgumentParser(
        description="Migrate Borland C++ Builder source to Qt/MSVC."
    )
    parser.add_argument(
        "paths",
        nargs="*",
        help="Files or directories to process "
             "(default: CAD_DEMO/Source/)",
    )
    parser.add_argument(
        "--dry-run", "-n",
        action="store_true",
        help="Show what would be changed without writing files.",
    )
    args = parser.parse_args()

    # Default target
    if not args.paths:
        default = Path(__file__).parent / "CAD_DEMO" / "Source"
        if not default.exists():
            print(f"[ERROR] Default source directory not found: {default}",
                  file=sys.stderr)
            return 1
        args.paths = [str(default)]

    files = collect_files(args.paths)
    if not files:
        print("[WARNING] No .h/.cpp files found.")
        return 0

    print(f"Processing {len(files)} file(s)...")
    changed = 0
    for f in files:
        if process_file(f, dry_run=args.dry_run):
            changed += 1

    mode = "(dry-run) " if args.dry_run else ""
    print(f"\n{mode}Done. {changed}/{len(files)} file(s) modified.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
