#pragma once
// compat/windows.h – Minimal Windows API stub for Linux/non-Windows builds.
// Provides just enough definitions to allow compilation of code that
// historically included <windows.h> for basic Win32 types.

#ifndef _WINDOWS_H_COMPAT_
#define _WINDOWS_H_COMPAT_

#if defined(_WIN32) || defined(_WIN64)
// On real Windows we get the real windows.h (MSVC/MinGW already have it).
// This file should only be hit from the compat system-include directory
// on non-Windows platforms, so this branch should not normally be reached.
#  include_next <windows.h>
#else

#include <stdint.h>
#include <string.h>  // memset

// ---------------------------------------------------------------------------
// Fundamental Windows integer types
// ---------------------------------------------------------------------------
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef long                LONG;
typedef unsigned int        UINT;
typedef intptr_t            INT_PTR;
typedef uintptr_t           UINT_PTR;
typedef intptr_t            LONG_PTR;

#ifndef FALSE
#  define FALSE 0
#endif
#ifndef TRUE
#  define TRUE  1
#endif
#ifndef NULL
#  define NULL  nullptr
#endif

// ---------------------------------------------------------------------------
// Handle types
// ---------------------------------------------------------------------------
typedef void*               HANDLE;
typedef void*               HWND;
typedef void*               HDC;
typedef void*               HINSTANCE;
typedef void*               HMODULE;
typedef void*               HBITMAP;
typedef void*               HBRUSH;
typedef void*               HPEN;
typedef void*               HFONT;
typedef void*               HRGN;
typedef void*               HCURSOR;
typedef void*               HICON;
typedef void*               HMENU;
typedef void*               HFILE;
typedef HINSTANCE           HGLOBAL;

// ---------------------------------------------------------------------------
// String types
// ---------------------------------------------------------------------------
typedef char*               LPSTR;
typedef const char*         LPCSTR;
typedef wchar_t*            LPWSTR;
typedef const wchar_t*      LPCWSTR;
typedef void*               LPVOID;
typedef const void*         LPCVOID;

// ---------------------------------------------------------------------------
// GDI colour helpers
// ---------------------------------------------------------------------------
typedef DWORD               COLORREF;
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r))|((WORD)((BYTE)(g))<<8)|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb)      ((BYTE)(rgb))
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      ((BYTE)((rgb)>>16))

// ---------------------------------------------------------------------------
// GUID / UUID
// ---------------------------------------------------------------------------
#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
typedef GUID UUID;
typedef GUID CLSID;
typedef GUID IID;
#endif

// ---------------------------------------------------------------------------
// POINT / RECT (Windows variants – not the same as TPoint/TRect)
// ---------------------------------------------------------------------------
#ifndef POINT
struct POINT { long x; long y; };
#endif
#ifndef RECT
struct RECT  { long left; long top; long right; long bottom; };
#endif
#ifndef SIZE
struct SIZE  { long cx; long cy; };
#endif

// ---------------------------------------------------------------------------
// Windows message struct (minimal)
// ---------------------------------------------------------------------------
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    UINT   wParam;
    LONG   lParam;
    DWORD  time;
    POINT  pt;
} MSG, *PMSG;

// ---------------------------------------------------------------------------
// Error / status codes
// ---------------------------------------------------------------------------
#define NO_ERROR            0
#define ERROR_SUCCESS       0
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define MAX_PATH            260

// ---------------------------------------------------------------------------
// Windows SEH keywords – treated as regular try/catch on non-Windows
// ---------------------------------------------------------------------------
#ifndef __try
#  define __try        try
#endif
#ifndef __except
#  define __except(x)  catch(...)
#endif
#ifndef __finally
#  define __finally    /* finally not supported */
#endif
#ifndef EXCEPTION_EXECUTE_HANDLER
#  define EXCEPTION_EXECUTE_HANDLER 1
#endif

// ---------------------------------------------------------------------------
// Calling conventions
// ---------------------------------------------------------------------------
#ifndef WINAPI
#  define WINAPI
#endif
#ifndef CALLBACK
#  define CALLBACK
#endif
#ifndef STDAPICALLTYPE
#  define STDAPICALLTYPE
#endif

// ---------------------------------------------------------------------------
// Stub: CoCreateGuid (requires COM on Windows; use QUuid on Qt instead)
// Declared but not defined here – callers that actually use it should
// include the Qt UUID header or link against libuuid.
// ---------------------------------------------------------------------------
// inline DWORD CoCreateGuid(GUID*) { return 1; }  // stub – use QUuid instead

// ---------------------------------------------------------------------------
// Stub: ComObj.hpp equivalents (Borland COM helper – not needed on Linux)
// ---------------------------------------------------------------------------
inline char* GUIDToString(const GUID& /*g*/) { return nullptr; }

// ---------------------------------------------------------------------------
// Noop stubs for registry & process functions used in legacy code
// ---------------------------------------------------------------------------
#define RegOpenKeyEx(...)   ERROR_SUCCESS
#define RegCloseKey(...)    ERROR_SUCCESS
#define SetCurrentDirectory(p) (0)
#define GetCurrentDirectory(n,p) (0)

// ---------------------------------------------------------------------------
// Windows message constants (minimal set used in the project)
// ---------------------------------------------------------------------------
#define WM_KEYDOWN          0x0100
#define WM_KEYUP            0x0101
#define WM_CHAR             0x0102
#define WM_MOUSEMOVE        0x0200
#define WM_LBUTTONDOWN      0x0201
#define WM_LBUTTONUP        0x0202
#define WM_RBUTTONDOWN      0x0204
#define WM_RBUTTONUP        0x0205
#define WM_SIZE             0x0005
#define WM_PAINT            0x000F
#define WM_CLOSE            0x0010
#define WM_DESTROY          0x0002

// ---------------------------------------------------------------------------
// Virtual key codes
// ---------------------------------------------------------------------------
#define VK_ESCAPE       0x1B
#define VK_RETURN       0x0D
#define VK_BACK         0x08
#define VK_TAB          0x09
#define VK_DELETE       0x2E
#define VK_INSERT       0x2D
#define VK_LEFT         0x25
#define VK_RIGHT        0x27
#define VK_UP           0x26
#define VK_DOWN         0x28
#define VK_HOME         0x24
#define VK_END          0x23
#define VK_PRIOR        0x21
#define VK_NEXT         0x22
#define VK_SHIFT        0x10
#define VK_CONTROL      0x11
#define VK_MENU         0x12

// ---------------------------------------------------------------------------
// SendMessage / PostMessage stubs (no-op on non-Windows)
// ---------------------------------------------------------------------------
#define SendMessage(hwnd, msg, wp, lp)  (0)
#define PostMessage(hwnd, msg, wp, lp)  (0)

#endif // !_WIN32 && !_WIN64

#endif // _WINDOWS_H_COMPAT_
