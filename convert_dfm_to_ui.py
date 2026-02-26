#!/usr/bin/env python3
"""
convert_dfm_to_ui.py – Convert Borland VCL .dfm form files to Qt Designer .ui files.

Usage:
    python convert_dfm_to_ui.py [path ...]

    path can be a .dfm file, or a directory (processed recursively).
    Defaults to CAD_DEMO/Source/ if no arguments given.

Each .dfm produces a same-name .ui file in the same directory.
Binary .dfm files are skipped (they need Borland IDE to convert to text first).
"""

import os
import re
import sys
import xml.etree.ElementTree as ET
from xml.dom import minidom
from pathlib import Path

# ---------------------------------------------------------------------------
# VCL class → Qt class mapping
# ---------------------------------------------------------------------------
VCL_TO_QT = {
    # Forms / windows
    "TForm":                    "QDialog",
    "TForm1":                   "QDialog",
    "TCustomForm":              "QDialog",
    "TBaseDockSiteForm":        "QMainWindow",
    "TBaseForm":                "QDialog",
    "TFloatForm":               "QWidget",
    "TMyMDIChild":              "QMdiSubWindow",
    "TCustomMDIChildForm":      "QMdiSubWindow",

    # Basic controls
    "TLabel":                   "QLabel",
    "TStaticText":              "QLabel",
    "TButton":                  "QPushButton",
    "TBitBtn":                  "QPushButton",
    "TSpeedButton":             "QToolButton",
    "TEdit":                    "QLineEdit",
    "TMemo":                    "QTextEdit",
    "TRichEdit":                "QTextEdit",
    "TCheckBox":                "QCheckBox",
    "TRadioButton":             "QRadioButton",
    "TComboBox":                "QComboBox",
    "TListBox":                 "QListWidget",
    "TRadioGroup":              "QGroupBox",
    "TGroupBox":                "QGroupBox",
    "TScrollBox":               "QScrollArea",
    "TScrollBar":               "QScrollBar",

    # Value inputs
    "TSpinEdit":                "QSpinBox",
    "TUpDown":                  "QSpinBox",
    "TTrackBar":                "QSlider",
    "TProgressBar":             "QProgressBar",
    "TDateTimePicker":          "QDateTimeEdit",
    "TColorBox":                "QComboBox",     # colour picker combo

    # Containers / layout
    "TPanel":                   "QFrame",
    "TSplitter":                "QSplitter",
    "TTabControl":              "QTabWidget",
    "TPageControl":             "QTabWidget",
    "TTabSheet":                "QWidget",       # tab page
    "TGroupBox":                "QGroupBox",

    # Grid / tree / list
    "TListView":                "QTreeWidget",
    "TTreeView":                "QTreeWidget",
    "TStringGrid":              "QTableWidget",
    "TDrawGrid":                "QTableWidget",
    "TValueListEditor":         "QTableWidget",

    # Images
    "TImage":                   "QLabel",        # carries a pixmap
    "TShape":                   "QFrame",        # coloured rectangle stub

    # Menus / toolbar
    "TMainMenu":                "QMenuBar",
    "TPopupMenu":               "QMenu",
    "TMenuItem":                "QAction",
    "TToolBar":                 "QToolBar",
    "TStatusBar":               "QStatusBar",
    "TActionList":              "QObject",
    "TImageList":               "QObject",

    # Misc
    "TTimer":                   "QTimer",
    "TOpenDialog":              "QObject",
    "TSaveDialog":              "QObject",
    "TFontDialog":              "QObject",
    "TColorDialog":             "QObject",
    "TPrintDialog":             "QObject",
    "TFindDialog":              "QObject",
    "TReplaceDialog":           "QObject",
    "TBevel":                   "QFrame",
    "TPanel":                   "QFrame",
}

# Qt classes that are dialogs (top-level form base classes)
DIALOG_CLASSES = {"QDialog", "QMainWindow", "QMdiSubWindow", "QWidget"}

# Qt classes that cannot be children in the normal sense (skip in child list)
NON_VISUAL = {"QMenuBar", "QMenu", "QAction", "QToolBar", "QStatusBar",
              "QObject", "QTimer"}

# VCL Align values → Qt layout hints (stored as a comment in the .ui)
ALIGN_MAP = {
    "alTop":    "top",
    "alBottom": "bottom",
    "alLeft":   "left",
    "alRight":  "right",
    "alClient": "fill",
    "alNone":   "none",
}

# VCL BorderStyle → Qt window flags (informational)
BORDER_STYLE_MAP = {
    "bsNone":        "Qt::FramelessWindowHint",
    "bsSingle":      "Qt::MSWindowsFixedSizeDialogHint",
    "bsDialog":      "Qt::Dialog",
    "bsSizeable":    "Qt::Window",
    "bsToolWindow":  "Qt::Tool",
    "bsSizeToolWin": "Qt::Tool",
}

# ---------------------------------------------------------------------------
# Colour constants
# ---------------------------------------------------------------------------
VCL_COLORS = {
    "clBlack":       "#000000",
    "clMaroon":      "#800000",
    "clGreen":       "#008000",
    "clOlive":       "#808000",
    "clNavy":        "#000080",
    "clPurple":      "#800080",
    "clTeal":        "#008080",
    "clGray":        "#808080",
    "clSilver":      "#C0C0C0",
    "clRed":         "#FF0000",
    "clFuchsia":     "#FF00FF",
    "clLime":        "#00FF00",
    "clYellow":      "#FFFF00",
    "clBlue":        "#0000FF",
    "clAqua":        "#00FFFF",
    "clWhite":       "#FFFFFF",
    "clBtnFace":     "#F0F0F0",
    "clBtnText":     "#000000",
    "clWindowText":  "#000000",
    "clWindow":      "#FFFFFF",
    "clHighlight":   "#0078D7",
    "clHighlightText": "#FFFFFF",
}

# ---------------------------------------------------------------------------
# DFM parser
# ---------------------------------------------------------------------------

def _decode_string(raw: str) -> str:
    """Decode a DFM string literal: strip outer quotes, handle #NNN escapes."""
    result = []
    i = 0
    while i < len(raw):
        c = raw[i]
        if c == '#':
            # character code  #NNN
            j = i + 1
            while j < len(raw) and raw[j].isdigit():
                j += 1
            try:
                code = int(raw[i+1:j])
                result.append(chr(code))
            except ValueError:
                result.append(raw[i:j])
            i = j
        elif c == "'":
            # quoted string segment
            j = i + 1
            seg = []
            while j < len(raw):
                if raw[j] == "'":
                    if j + 1 < len(raw) and raw[j+1] == "'":
                        seg.append("'")
                        j += 2
                    else:
                        break
                else:
                    seg.append(raw[j])
                    j += 1
            result.append(''.join(seg))
            i = j + 1
        else:
            result.append(c)
            i += 1
    return ''.join(result)


class DfmNode:
    def __init__(self, obj_name: str, class_name: str):
        self.obj_name = obj_name          # instance name
        self.class_name = class_name      # VCL class name
        self.props: dict[str, str] = {}   # property_name → raw value string
        self.children: list["DfmNode"] = []

    def __repr__(self):
        return f"DfmNode({self.obj_name}: {self.class_name}, {len(self.children)} children)"


def parse_dfm(text: str) -> DfmNode | None:
    """Parse DFM text into a DfmNode tree. Returns None on parse error."""
    lines = text.splitlines()
    stack: list[DfmNode] = []
    root: DfmNode | None = None
    i = 0
    current_prop_value: list[str] = []
    current_prop_name: str | None = None
    in_multiline = False  # inside { ... } or ( ... ) block

    while i < len(lines):
        raw = lines[i]
        line = raw.strip()

        # Continuation of a multi-line value block
        if in_multiline:
            if current_prop_value:
                current_prop_value.append(line)
            if line.endswith('}') or line.endswith(')'):
                # End of block
                if stack and current_prop_name:
                    stack[-1].props[current_prop_name] = ' '.join(current_prop_value)
                current_prop_name = None
                current_prop_value = []
                in_multiline = False
            i += 1
            continue

        # Object declaration: "object Name: TClass" or "inherited Name: TClass"
        m = re.match(r'^(?:object|inherited)\s+(\w+)\s*:\s*(\w+)', line, re.IGNORECASE)
        if m:
            node = DfmNode(m.group(1), m.group(2))
            if stack:
                stack[-1].children.append(node)
            else:
                root = node
            stack.append(node)
            i += 1
            continue

        # "end" closes the current object
        if line.lower() == 'end':
            if stack:
                stack.pop()
            i += 1
            continue

        # Property assignment: "Name = Value" or "Name.Sub = Value"
        m = re.match(r'^([\w.]+)\s*=\s*(.*)', line)
        if m and stack:
            prop_name = m.group(1)
            prop_val = m.group(2).strip()

            # Check for multi-line block starting with { or (
            open_cnt = prop_val.count('{') + prop_val.count('(')
            close_cnt = prop_val.count('}') + prop_val.count(')')
            if open_cnt > close_cnt or (prop_val.endswith('{') or prop_val.endswith('(')):
                current_prop_name = prop_name
                current_prop_value = [prop_val]
                in_multiline = True
                i += 1
                continue

            # Continuation lines (value doesn't end a balanced string)
            full_val = prop_val
            # Collect continuation lines for string literals that span lines
            while full_val.count("'") % 2 != 0:
                i += 1
                if i >= len(lines):
                    break
                full_val += ' ' + lines[i].strip()

            stack[-1].props[prop_name] = full_val

        i += 1

    return root


# ---------------------------------------------------------------------------
# Qt .ui XML generator
# ---------------------------------------------------------------------------

def _qt_class(vcl_class: str) -> str:
    """Return the Qt class for a VCL class name."""
    return VCL_TO_QT.get(vcl_class, "QWidget")


def _vcl_color_to_qt(val: str) -> str:
    """Convert a VCL colour constant or hex value to a Qt stylesheet color."""
    val = val.strip()
    if val in VCL_COLORS:
        return VCL_COLORS[val]
    # e.g. $00FF0000 (BGR hex)
    m = re.match(r'\$([0-9A-Fa-f]{8})', val)
    if m:
        bgr = int(m.group(1), 16)
        b = (bgr >> 16) & 0xFF
        g = (bgr >> 8) & 0xFF
        r = bgr & 0xFF
        return f"#{r:02X}{g:02X}{b:02X}"
    return val


def _font_height_to_pt(height_str: str) -> int:
    """Convert DFM Font.Height (negative pixel height) to point size."""
    try:
        h = int(height_str)
        # height is in pixels; roughly 72/96 * abs(h) for 96 dpi
        return max(1, abs(h) * 3 // 4)
    except ValueError:
        return 9


def _props_to_geometry(props: dict, parent_props: dict | None = None) -> tuple[int, int, int, int]:
    """Extract x, y, width, height from DFM properties (fallback to 0)."""
    def _i(key, default=0):
        return int(props.get(key, default) or default)

    left = _i("Left")
    top = _i("Top")
    w = _i("Width") or _i("ClientWidth")
    h = _i("Height") or _i("ClientHeight")
    return left, top, max(w, 1), max(h, 1)


def _add_property(parent_el: ET.Element, name: str, ptype: str, value: str):
    prop = ET.SubElement(parent_el, "property", attrib={"name": name})
    el = ET.SubElement(prop, ptype)
    el.text = value
    return prop


def _add_string_property(parent_el: ET.Element, name: str, value: str):
    return _add_property(parent_el, name, "string", value)


def _add_bool_property(parent_el: ET.Element, name: str, value: bool):
    return _add_property(parent_el, name, "bool", "true" if value else "false")


def _add_number_property(parent_el: ET.Element, name: str, value):
    return _add_property(parent_el, name, "number", str(value))


def _add_rect_property(parent_el: ET.Element, name: str, x: int, y: int, w: int, h: int):
    prop = ET.SubElement(parent_el, "property", attrib={"name": name})
    rect = ET.SubElement(prop, "rect")
    ET.SubElement(rect, "x").text = str(x)
    ET.SubElement(rect, "y").text = str(y)
    ET.SubElement(rect, "width").text = str(w)
    ET.SubElement(rect, "height").text = str(h)


def _add_size_policy(parent_el: ET.Element, h_policy="Preferred", v_policy="Preferred"):
    prop = ET.SubElement(parent_el, "property", attrib={"name": "sizePolicy"})
    sp = ET.SubElement(prop, "sizepolicy", attrib={
        "hsizetype": h_policy, "vsizetype": v_policy
    })
    ET.SubElement(sp, "horstretch").text = "0"
    ET.SubElement(sp, "verstretch").text = "0"


def _add_font(parent_el: ET.Element, props: dict):
    """Add a <property name='font'> element if Font properties are present."""
    height = props.get("Font.Height")
    bold = "fsBold" in props.get("Font.Style", "")
    italic = "fsItalic" in props.get("Font.Style", "")
    underline = "fsUnderline" in props.get("Font.Style", "")
    name = props.get("Font.Name", "").strip("'\"")

    if not (height or bold or italic or underline or name):
        return

    prop = ET.SubElement(parent_el, "property", attrib={"name": "font"})
    font = ET.SubElement(prop, "font")
    if name:
        ET.SubElement(font, "family").text = name
    if height:
        ET.SubElement(font, "pointsize").text = str(_font_height_to_pt(height))
    if bold:
        ET.SubElement(font, "bold").text = "true"
    if italic:
        ET.SubElement(font, "italic").text = "true"
    if underline:
        ET.SubElement(font, "underline").text = "true"


def _decode_caption(raw: str) -> str:
    """Decode a DFM caption value (quoted string or #NNN escapes)."""
    raw = raw.strip()
    if raw.startswith("'") or raw.startswith("#"):
        return _decode_string(raw)
    return raw


def _node_to_ui(node: DfmNode, parent_el: ET.Element | None,
                is_root: bool = False) -> ET.Element | None:
    """
    Recursively convert a DfmNode to a Qt .ui widget element.
    Returns the created element (or None for non-visual items).
    """
    qt_class = _qt_class(node.class_name)
    props = node.props

    # Skip non-visual component stubs that have no .ui representation
    if qt_class in ("QObject",):
        return None

    # Determine element tag: top-level is just a widget; children too
    widget = ET.SubElement(
        parent_el if parent_el is not None else ET.Element("dummy"),
        "widget",
        attrib={"class": qt_class, "name": node.obj_name}
    )

    # Geometry
    x, y, w, h = _props_to_geometry(props)
    _add_rect_property(widget, "geometry", x, y, w, h)

    # Window title / caption
    caption = props.get("Caption", "")
    if caption:
        _add_string_property(widget, "windowTitle", _decode_caption(caption))

    # Text for label / button etc.
    text_prop = None
    if qt_class in ("QLabel", "QPushButton", "QCheckBox", "QRadioButton",
                    "QGroupBox", "QToolButton"):
        text_prop = "text"
        text_val = _decode_caption(caption)
        _add_string_property(widget, text_prop, text_val)

    # QLineEdit: Text property
    if qt_class == "QLineEdit":
        text_val = props.get("Text", "''")
        _add_string_property(widget, "text", _decode_caption(text_val))

    # Font
    _add_font(widget, props)

    # Tooltip (hint)
    hint = props.get("Hint", "")
    if hint:
        _add_string_property(widget, "toolTip", _decode_caption(hint))

    # Enabled
    enabled = props.get("Enabled", "True")
    if enabled.lower() == "false":
        _add_bool_property(widget, "enabled", False)

    # Visible
    visible = props.get("Visible", "True")
    if visible.lower() == "false":
        _add_bool_property(widget, "visible", False)

    # QProgressBar: min/max/value
    if qt_class == "QProgressBar":
        mn = props.get("Min", "0")
        mx = props.get("Max", "100")
        _add_number_property(widget, "minimum", mn)
        _add_number_property(widget, "maximum", mx)

    # QSlider orientation
    if qt_class == "QSlider":
        orientation = props.get("Orientation", "trHorizontal")
        orient_val = "Qt::Horizontal" if "Horizontal" in orientation else "Qt::Vertical"
        prop = ET.SubElement(widget, "property", attrib={"name": "orientation"})
        enum_el = ET.SubElement(prop, "enum")
        enum_el.text = orient_val
        mn = props.get("Min", "0")
        mx = props.get("Max", "100")
        _add_number_property(widget, "minimum", mn)
        _add_number_property(widget, "maximum", mx)

    # QSpinBox / QUpDown
    if qt_class == "QSpinBox":
        mn = props.get("Min", "0")
        mx = props.get("Max", "100")
        _add_number_property(widget, "minimum", mn)
        _add_number_property(widget, "maximum", mx)

    # QFrame (TPanel, TBevel, TShape)
    if qt_class == "QFrame":
        bevel_outer = props.get("BevelOuter", "")
        if bevel_outer == "bvNone":
            prop = ET.SubElement(widget, "property", attrib={"name": "frameShape"})
            ET.SubElement(prop, "enum").text = "QFrame::NoFrame"
        else:
            prop = ET.SubElement(widget, "property", attrib={"name": "frameShape"})
            ET.SubElement(prop, "enum").text = "QFrame::StyledPanel"

    # QComboBox: add items if defined inline
    if qt_class == "QComboBox":
        items_str = props.get("Items.Strings", "")
        if items_str:
            for item_line in items_str.split("'"):
                item_line = item_line.strip()
                if item_line and item_line not in ("(", ")"):
                    item_el = ET.SubElement(widget, "item")
                    _add_string_property(item_el, "text", item_line)

    # QListWidget: add items if defined inline
    if qt_class == "QListWidget":
        items_str = props.get("Items.Strings", "")
        if items_str:
            for item_line in items_str.split("'"):
                item_line = item_line.strip()
                if item_line and item_line not in ("(", ")"):
                    item_el = ET.SubElement(widget, "item")
                    prop = ET.SubElement(item_el, "property", attrib={"name": "text"})
                    ET.SubElement(prop, "string").text = item_line

    # QTabWidget: TPageControl / TTabSheet hierarchy
    # Tab sheets are already added as children – Qt .ui handles this naturally

    # Add alignment comment for layout guidance
    align = props.get("Align", "")
    if align and align != "alNone":
        comment = ET.Comment(f" vcl-align: {align} → arrange in a Qt layout manager ")
        widget.append(comment)

    # Recurse into children
    for child in node.children:
        _node_to_ui(child, widget, is_root=False)

    return widget


def _build_ui_xml(root_node: DfmNode) -> str:
    """Build the complete .ui XML string from a parsed DFM root node."""
    qt_class = _qt_class(root_node.class_name)

    # Root <ui> element
    ui_el = ET.Element("ui", attrib={"version": "4.0"})

    # <class>
    class_el = ET.SubElement(ui_el, "class")
    class_el.text = root_node.obj_name

    # Top-level widget
    x, y, w, h = _props_to_geometry(root_node.props)
    widget_el = ET.SubElement(ui_el, "widget",
                               attrib={"class": qt_class, "name": root_node.obj_name})
    _add_rect_property(widget_el, "geometry", 0, 0, w, h)

    caption = root_node.props.get("Caption", "")
    if caption:
        _add_string_property(widget_el, "windowTitle", _decode_caption(caption))
    _add_font(widget_el, root_node.props)

    # Border style → window flags comment
    border = root_node.props.get("BorderStyle", "")
    if border in BORDER_STYLE_MAP:
        widget_el.append(ET.Comment(
            f" vcl-BorderStyle: {border} → set windowFlags {BORDER_STYLE_MAP[border]} in constructor "
        ))

    # FormStyle
    form_style = root_node.props.get("FormStyle", "")
    if form_style == "fsStayOnTop":
        widget_el.append(ET.Comment(
            " vcl-FormStyle: fsStayOnTop → setWindowFlag(Qt::WindowStaysOnTopHint) "
        ))
    elif form_style == "fsMDIChild":
        widget_el.append(ET.Comment(
            " vcl-FormStyle: fsMDIChild → use QMdiSubWindow "
        ))

    # Children
    for child in root_node.children:
        _node_to_ui(child, widget_el, is_root=False)

    # <resources/> and <connections/>
    ET.SubElement(ui_el, "resources")
    ET.SubElement(ui_el, "connections")

    # Pretty-print
    raw_xml = ET.tostring(ui_el, encoding="unicode", xml_declaration=False)
    try:
        dom = minidom.parseString(raw_xml)
        pretty = dom.toprettyxml(indent="  ", encoding="UTF-8").decode("UTF-8")
        # Remove the redundant XML declaration added by toprettyxml
        lines = pretty.splitlines()
        if lines and lines[0].startswith("<?xml"):
            lines[0] = '<?xml version="1.0" encoding="UTF-8"?>'
        return "\n".join(lines)
    except Exception:
        return '<?xml version="1.0" encoding="UTF-8"?>\n' + raw_xml


# ---------------------------------------------------------------------------
# File processing
# ---------------------------------------------------------------------------

def is_binary(path: Path) -> bool:
    try:
        with open(path, "rb") as f:
            chunk = f.read(512)
        return b"\x00" in chunk
    except OSError:
        return True


def convert_file(dfm_path: Path) -> bool:
    """Convert a single .dfm file. Returns True on success."""
    if is_binary(dfm_path):
        print(f"  [skip-binary] {dfm_path}")
        return False

    try:
        text = dfm_path.read_text(encoding="utf-8", errors="replace")
    except OSError as e:
        print(f"  [error] Cannot read {dfm_path}: {e}")
        return False

    root_node = parse_dfm(text)
    if root_node is None:
        print(f"  [skip-parse-error] {dfm_path}")
        return False

    ui_xml = _build_ui_xml(root_node)
    ui_path = dfm_path.with_suffix(".ui")
    try:
        ui_path.write_text(ui_xml, encoding="utf-8")
        print(f"  [ok] {dfm_path.name}  →  {ui_path.name}")
        return True
    except OSError as e:
        print(f"  [error] Cannot write {ui_path}: {e}")
        return False


def process_path(target: str):
    p = Path(target)
    if p.is_file() and p.suffix.lower() == ".dfm":
        convert_file(p)
    elif p.is_dir():
        dfm_files = sorted(p.rglob("*.dfm"))
        ok = skip = 0
        for f in dfm_files:
            if convert_file(f):
                ok += 1
            else:
                skip += 1
        print(f"\nDone. Converted: {ok}  Skipped: {skip}  Total: {ok+skip}")
    else:
        print(f"[warning] {target}: not a .dfm file or directory – skipped")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------
if __name__ == "__main__":
    targets = sys.argv[1:] or ["CAD_DEMO/Source"]
    for t in targets:
        process_path(t)
