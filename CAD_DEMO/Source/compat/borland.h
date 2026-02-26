#pragma once
// borland.h – Handles Borland-specific keywords and pragmas for MSVC/GCC.
// Include this header (or let vcl_qt.h include it) to neutralize Borland
// extensions before compiling with a standard toolchain.

// ---------------------------------------------------------------------------
// Calling-convention keywords (empty on non-Borland compilers)
// ---------------------------------------------------------------------------
#if !defined(__BORLANDC__)
#  ifndef __fastcall
#    define __fastcall
#  endif
#  ifndef __closure
#    define __closure
#  endif
#  ifndef PACKAGE
#    define PACKAGE
#  endif
#  ifndef __cdecl
     // MSVC/GCC already define __cdecl, but guard anyway
#  endif
#endif

// ---------------------------------------------------------------------------
// __declspec(package) → visibility equivalent
// ---------------------------------------------------------------------------
#if !defined(__BORLANDC__)
#  if defined(_MSC_VER)
#    ifndef __declspec_package_defined
#      define __declspec_package_defined
       // Redefine 'package' inside __declspec to 'dllexport' on MSVC.
       // This is done by suppressing the keyword entirely; classes that
       // used PACKAGE macro already have it mapped to empty above.
#    endif
#  elif defined(__GNUC__)
#    ifndef __attribute__visibility_defined
#      define __attribute__visibility_defined
#    endif
#  endif
#endif

// ---------------------------------------------------------------------------
// __property helpers
//   Borland: __property int Foo = {read=GetFoo, write=SetFoo};
//   MSVC:    __declspec(property(get=GetFoo, put=SetFoo)) int Foo;
//   GCC/Clang: no equivalent; define as no-op (field access via getter/setter
//              won't be transparent, but code will at least compile).
// ---------------------------------------------------------------------------
#if defined(_MSC_VER) && !defined(__BORLANDC__)
    // MSVC supports __declspec(property(...))
#   define BORLAND_PROPERTY_R(type, name, getter) \
        __declspec(property(get=getter)) type name
#   define BORLAND_PROPERTY_RW(type, name, getter, setter) \
        __declspec(property(get=getter, put=setter)) type name
#else
    // GCC/Clang: emit nothing; callers use getter/setter directly.
#   define BORLAND_PROPERTY_R(type, name, getter)
#   define BORLAND_PROPERTY_RW(type, name, getter, setter)
#endif

// ---------------------------------------------------------------------------
// MFC-style message map macros (VCL doesn't use them, but some ported code
// may include them; define as empty to prevent compilation errors).
// ---------------------------------------------------------------------------
#if !defined(__BORLANDC__)
#  define BEGIN_MESSAGE_MAP(...)
#  define END_MESSAGE_MAP(...)
#endif

// ---------------------------------------------------------------------------
// #pragma hdrstop and #pragma package(smart_init) are Borland-only.
// Define them as pragmas that are understood by the preprocessor but ignored.
// (They must NOT be redefined as macros because they appear after #pragma.)
// Instead the migration script strips them; these are left as documentation.
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// WINAPI / DllEntryPoint compatibility
// ---------------------------------------------------------------------------
#if !defined(_WIN32) && !defined(_WIN64)
#  ifndef WINAPI
#    define WINAPI
#  endif
#  ifndef HINSTANCE
     typedef void* HINSTANCE;
#  endif
#endif

// ---------------------------------------------------------------------------
// Borland RTTI helpers (__classid, __typeinfo)
// ---------------------------------------------------------------------------
#if !defined(__BORLANDC__)
#  define __classid(cls)  (nullptr)
#  define __typeinfo(cls) (nullptr)
#endif

// ---------------------------------------------------------------------------
// Borland integer types that may be missing
// ---------------------------------------------------------------------------
#ifndef __INT64
    typedef long long          __int64;
#endif
