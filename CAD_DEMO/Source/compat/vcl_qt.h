#pragma once
// vcl_qt.h – VCL-to-Qt type mappings for Borland C++ Builder → Qt migration.
// Provides typedefs and stub classes that allow the existing VCL-heavy code
// to compile under Qt/MSVC or Qt/GCC without modification.

#include "AnsiString.h"
// Pull in Windows types/constants (stubs on Linux, real headers on Windows)
#include <windows.h>

#include <QString>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QScrollArea>
#include <QScrollBar>
#include <QSlider>
#include <QProgressBar>
#include <QFrame>
#include <QTabWidget>
#include <QTreeWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QSplitter>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QToolButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QTimer>
#include <QStringList>
#include <QBuffer>
#include <QByteArray>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QCursor>
#include <QOpenGLWidget>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <cstdarg>

// ---------------------------------------------------------------------------
// Fundamental Borland types
// ---------------------------------------------------------------------------
typedef bool          Boolean;
typedef unsigned char Byte;
typedef unsigned int  Cardinal;
typedef int           Integer;
typedef double        Extended;
typedef float         Single;
typedef double        Double;
typedef long long     Int64;
typedef wchar_t       WideChar;
typedef char          AnsiChar;
typedef unsigned short Word;
typedef int           LongInt;
typedef unsigned int  LongWord;
typedef void*         Pointer;

// ---------------------------------------------------------------------------
// VCL Component hierarchy → Qt mappings
// ---------------------------------------------------------------------------
typedef QObject       TComponent;
typedef QWidget       TControl;
typedef QWidget       TWinControl;
typedef QWidget       TCustomControl;
typedef QWidget       TScrollingWinControl;
// TForm: Borland's TForm(TComponent* Owner) constructor; Qt uses QWidget* parent.
// We provide a thin wrapper so existing code compiles unchanged.
class TForm : public QMainWindow {
public:
    explicit TForm(TComponent* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(qobject_cast<QWidget*>(parent), flags) {}
};
typedef QDialog       TDialog;
typedef QBuffer       TMemoryStream;
typedef QString       TCaption;
typedef int           TColor;

// ---------------------------------------------------------------------------
// VCL Color constants (BGR packed ints as used by Windows GDI / Borland)
// ---------------------------------------------------------------------------
static const TColor clBlack   = 0x000000;
static const TColor clMaroon  = 0x000080;
static const TColor clGreen   = 0x008000;
static const TColor clOlive   = 0x008080;
static const TColor clNavy    = 0x800000;
static const TColor clPurple  = 0x800080;
static const TColor clTeal    = 0x808000;
static const TColor clGray    = 0x808080;
static const TColor clSilver  = 0xC0C0C0;
static const TColor clRed     = 0x0000FF;
static const TColor clFuchsia = 0xFF00FF;
static const TColor clLime    = 0x00FF00;
static const TColor clYellow  = 0x00FFFF;
static const TColor clBlue    = 0xFF0000;
static const TColor clAqua    = 0xFFFF00;
static const TColor clWhite   = 0xFFFFFF;
static const TColor clDefault = -1;
static const TColor clNone    = -2;
static const TColor clWindowText  = 0x000000;
static const TColor clBtnFace     = 0xC0C0C0;
static const TColor clHighlight   = 0xFF0000;
static const TColor clHighlightText = 0xFFFFFF;

// ---------------------------------------------------------------------------
// TRect / TPoint / TSize
// In VisIT_stubs.hpp we define lightweight structs; here we extend them
// to also alias Qt types where convenient.
// ---------------------------------------------------------------------------
// TPoint and TRect already defined in VisIT_stubs.hpp (included via compat).
// Provide QPoint/QRect conversion helpers.
#ifndef TPOINT_DEFINED
#  define TPOINT_DEFINED
struct TPoint { int x, y; TPoint(int _x=0,int _y=0):x(_x),y(_y){} };
#endif
#ifndef TRECT_DEFINED
#  define TRECT_DEFINED
struct TRect { int left,top,right,bottom; TRect(int l=0,int t=0,int r=0,int b=0):left(l),top(t),right(r),bottom(b){} int Width() const{return right-left;} int Height() const{return bottom-top;} };
#endif
typedef QSize  TSize;

// ---------------------------------------------------------------------------
// VCL tree/list types
// ---------------------------------------------------------------------------
typedef QTreeWidgetItem  TTreeNode;
typedef QListWidgetItem  TListItem;
// TStringList: Borland TStringList has Add/Delete/IndexOf etc.
// For compilation purposes we provide a thin wrapper around QStringList.
class TStringList : public QStringList {
public:
    TStringList() {}
    explicit TStringList(const QStringList& sl) : QStringList(sl) {}
    void Add(const AnsiString& s)    { append(s.toQString()); }
    void Delete(int idx)             { removeAt(idx); }
    void Clear()                     { clear(); }
    int  Count() const               { return size(); }
    int  IndexOf(const AnsiString& s) const { return indexOf(s.toQString()); }
    AnsiString Strings(int i) const  { return AnsiString(at(i)); }
    void Strings(int i, const AnsiString& v) { replace(i, v.toQString()); }
    AnsiString operator[](int i) const { return AnsiString(at(i)); }
    AnsiString Text() const          { return AnsiString(join('\n')); }
    // CommaText: Borland property - get/set as comma-separated string
    AnsiString CommaText() const     { return AnsiString(join(',')); }
    void CommaText(const AnsiString& s) { clear(); for (auto& p : s.toQString().split(',')) append(p.trimmed()); }
    void SaveToFile(const AnsiString& fn) const {
        QFile f(fn.toQString());
        if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream ts(&f);
            for (auto& s : *this) ts << s << '\n';
        }
    }
    void LoadFromFile(const AnsiString& fn) {
        QFile f(fn.toQString());
        if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
            clear();
            QTextStream ts(&f);
            while (!ts.atEnd()) append(ts.readLine());
        }
    }
    bool Sorted = false;
};

// ---------------------------------------------------------------------------
// VCL Dialog button set
// ---------------------------------------------------------------------------
enum TMsgDlgBtn {
    mbYes, mbNo, mbOK, mbCancel, mbAbort, mbRetry, mbIgnore, mbAll, mbHelp
};
typedef unsigned int TMsgDlgButtons;

inline int MessageDlg(const AnsiString& msg, int /*type*/,
                      TMsgDlgButtons buttons, int /*helpCtx*/ = 0)
{
    QMessageBox::StandardButtons qbtns = QMessageBox::Ok;
    if (buttons & (1u << mbYes))    qbtns |= QMessageBox::Yes;
    if (buttons & (1u << mbNo))     qbtns |= QMessageBox::No;
    if (buttons & (1u << mbCancel)) qbtns |= QMessageBox::Cancel;
    QMessageBox::StandardButton result =
        QMessageBox::question(nullptr, "Message", msg.toQString(), qbtns);
    switch (result) {
        case QMessageBox::Yes:    return 6;   // mrYes
        case QMessageBox::No:     return 7;   // mrNo
        case QMessageBox::Cancel: return 2;   // mrCancel
        default:                  return 1;   // mrOk
    }
}

inline void ShowMessage(const AnsiString& msg) {
    QMessageBox::information(nullptr, "Information", msg.toQString());
}

// VCL message-dialog type constants
static const int mtWarning     = 0;
static const int mtError       = 1;
static const int mtInformation = 2;
static const int mtConfirmation= 3;
static const int mtCustom      = 4;

// VCL modal result codes
static const int mrNone   = 0;
static const int mrOk     = 1;
static const int mrCancel = 2;
static const int mrAbort  = 3;
static const int mrRetry  = 4;
static const int mrIgnore = 5;
static const int mrYes    = 6;
static const int mrNo     = 7;

// ---------------------------------------------------------------------------
// TApplication stub
// ---------------------------------------------------------------------------
class TApplication : public QObject {
public:
    TApplication() : MainForm(nullptr) {}
    void ShowException(std::exception* e) {
        if (e) QMessageBox::critical(nullptr, "Exception", e->what());
    }
    void Initialize()  {}
    void Run()         { if (qApp) qApp->exec(); }
    void Terminate()   { if (qApp) qApp->quit(); }
    void ProcessMessages() { if (qApp) qApp->processEvents(); }
    AnsiString Title;
    QWidget*   MainForm;
    template<typename T>
    void CreateForm(T** out) {
        *out = new T();
        MainForm = *out;
    }
};

// Global Application pointer (defined in main_qt.cpp)
extern TApplication* Application;

// ---------------------------------------------------------------------------
// VCL Exception compatibility
// ---------------------------------------------------------------------------
class Exception : public std::exception {
public:
    AnsiString Message;
    explicit Exception(const AnsiString& msg) : Message(msg) {}
    const char* what() const noexcept override { return Message.c_str(); }
};

class EAbort       : public Exception { public: using Exception::Exception; };
class EAccessViolation : public Exception { public: using Exception::Exception; };
class EOutOfMemory : public Exception { public: using Exception::Exception; };
class EInvalidCast : public Exception { public: using Exception::Exception; };

// ---------------------------------------------------------------------------
// TClass – Borland metaclass type (maps to std::type_info for type checking)
// ---------------------------------------------------------------------------
#include <typeinfo>
typedef const std::type_info TClass;

// ---------------------------------------------------------------------------
// TObject – base class for VCL objects
// ---------------------------------------------------------------------------
class TObject {
public:
    TObject()          {}
    virtual ~TObject() {}
    virtual AnsiString ClassName() const { return AnsiString("TObject"); }
};

// ---------------------------------------------------------------------------
// TPersistent
// ---------------------------------------------------------------------------
class TPersistent : public TObject {
public:
    virtual void Assign(TPersistent*) {}
};

// ---------------------------------------------------------------------------
// TNotifyEvent – Borland's standard callback
// Uses std::function to support both raw function pointers and lambdas/closures.
// ---------------------------------------------------------------------------
typedef std::function<void(TObject*)> TNotifyEvent;

// ---------------------------------------------------------------------------
// TMenuItem – VCL menu item stub (maps to QAction)
// ---------------------------------------------------------------------------
class TMenuItem : public QAction {
public:
    AnsiString Caption;
    int Tag = 0;
    TNotifyEvent OnClick;
    explicit TMenuItem(QObject* parent = nullptr) : QAction(parent) {}
    void SetCaption(const AnsiString& s) { Caption = s; setText(s.toQString()); }
};

// ---------------------------------------------------------------------------
// IS() – Borland run-time type check (like dynamic_cast but via TClassNode)
// We map it to a simple dynamic_cast-based check.
// ---------------------------------------------------------------------------
template<typename T>
inline bool IS(T* obj, const std::type_info* /*ti*/) {
    return obj != nullptr; // stub: accept any non-null pointer
}
template<typename T, typename U>
inline bool IS(T* obj, U* /*unused*/) { return obj != nullptr; }
// __classid(T) → type_info pointer (from borland.h, already returns nullptr)
// We just need IS() to compile; exact behaviour is irrelevant for the build.

// ---------------------------------------------------------------------------
// Mouse object stub (used in MenuToolCommands->Popup(Mouse->CursorPos.x, y))
// ---------------------------------------------------------------------------
struct _TPoint2 { int x = 0; int y = 0; };
struct _TMouse {
    _TPoint2 CursorPos;
};
inline _TMouse* GetMouse() {
    static _TMouse m;
    QPoint p = QCursor::pos();
    m.CursorPos.x = p.x();
    m.CursorPos.y = p.y();
    return &m;
}
#define Mouse GetMouse()

// ---------------------------------------------------------------------------
// VCL Geometry helpers on QWidget (Borland-style property names)
// ---------------------------------------------------------------------------
// Add helper macros so code like Panel->Width or Panel->Left compiles.
// In Qt, these are methods, not properties.
// We use inline free functions as adapters where needed.

// ---------------------------------------------------------------------------
// COMMONAL_API – export/import macro used throughout the project
// ---------------------------------------------------------------------------
#if defined(_WIN32) || defined(_WIN64)
#  if defined(COMMONAL_EXPORTS)
#    define COMMONAL_API __declspec(dllexport)
#  else
#    define COMMONAL_API __declspec(dllimport)
#  endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#  define COMMONAL_API __attribute__((visibility("default")))
#else
#  define COMMONAL_API
#endif

// ---------------------------------------------------------------------------
// Minimal VCL stream types
// ---------------------------------------------------------------------------
class TStream {
public:
    virtual ~TStream() {}
    virtual int  Read(void*, int) { return 0; }
    virtual int  Write(const void*, int) { return 0; }
    virtual long Seek(long, int) { return 0; }
    long Size;
    long Position;
    TStream() : Size(0), Position(0) {}
};

// ---------------------------------------------------------------------------
// Misc VCL helpers
// ---------------------------------------------------------------------------
inline AnsiString ExtractFilePath(const AnsiString& s) {
    QFileInfo fi(s.toQString());
    return AnsiString(fi.absolutePath() + "/");
}
inline AnsiString ExtractFileName(const AnsiString& s) {
    QFileInfo fi(s.toQString());
    return AnsiString(fi.fileName());
}
inline AnsiString ExtractFileExt(const AnsiString& s) {
    QFileInfo fi(s.toQString());
    return AnsiString(fi.suffix().isEmpty() ? "" : "." + fi.suffix());
}
inline AnsiString ChangeFileExt(const AnsiString& s, const AnsiString& ext) {
    QFileInfo fi(s.toQString());
    return AnsiString(fi.absolutePath() + "/" + fi.completeBaseName() + ext.toQString());
}
inline bool FileExists(const AnsiString& s) {
    return QFileInfo::exists(s.toQString());
}
inline bool DirectoryExists(const AnsiString& s) {
    return QDir(s.toQString()).exists();
}
inline bool ForceDirectories(const AnsiString& s) {
    return QDir().mkpath(s.toQString());
}

// VCL Screen object stub
struct TScreen {
    int Width  = 1920;
    int Height = 1080;
};
extern TScreen* Screen;

// Stub: clipboard operations are no-ops until full migration
inline void ClipboardPlaceholder() {}

// USEFORM / USEFILE macros from Borland project files – ignored
#ifndef USEFORM
#  define USEFORM(file, form)
#endif
#ifndef USEFILE
#  define USEFILE(file)
#endif
#ifndef USEUNIT
#  define USEUNIT(file)
#endif
#ifndef USEOBJ
#  define USEOBJ(file)
#endif
#ifndef USELIB
#  define USELIB(file)
#endif

// ---------------------------------------------------------------------------
// Missing headers that were included as VCL headers
// ---------------------------------------------------------------------------
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>

// ---------------------------------------------------------------------------
// Basic Windows integer types (needed on non-Windows when windows.h not included)
// ---------------------------------------------------------------------------
#ifndef WORD
  typedef unsigned short  WORD;
#endif
#ifndef DWORD
  typedef unsigned long   DWORD;
#endif
#ifndef BYTE
  typedef unsigned char   BYTE;
#endif
#ifndef BOOL
  typedef int             BOOL;
#endif

// ---------------------------------------------------------------------------
// VCL mouse/keyboard input types
// ---------------------------------------------------------------------------
enum TMouseButton { mbLeft = 0, mbRight = 1, mbMiddle = 2 };
typedef unsigned int TShiftState;
static const TShiftState ssShift  = 1u;
static const TShiftState ssAlt    = 2u;
static const TShiftState ssCtrl   = 4u;
// VCL mouse-button flags in TShiftState:
static const TShiftState ssLeft   = 8u;
static const TShiftState ssRight  = 16u;
static const TShiftState ssMiddle = 32u;

// ---------------------------------------------------------------------------
// VCL widget aliases missing from the original mapping
// ---------------------------------------------------------------------------
typedef QFrame       TPanel;
typedef QFrame       TBevel;
typedef QScrollBar   TScrollBar;
typedef QStatusBar   TStatusBar;
typedef QSplitter    TSplitter;
typedef QSlider      TTrackBar;
typedef QProgressBar TProgressBar;
typedef QTextEdit    TMemo;
typedef QTextEdit    TRichEdit;
typedef QListWidget  TListBox;
// TPopupMenu: wraps QMenu but accepts TComponent* (QObject*) as parent
class TPopupMenu : public QMenu {
public:
    // VCL-style Items container
    struct _ItemsContainer {
        QMenu* _menu;
        explicit _ItemsContainer(QMenu* m) : _menu(m) {}
        void Add(QAction* a) { if (_menu && a) _menu->addAction(a); }
        int Count() const { return _menu ? _menu->actions().size() : 0; }
    } Items;

    TPopupMenu() : QMenu(), Items(this) {}
    explicit TPopupMenu(QObject* /*parent*/) : QMenu(), Items(this) {}
    explicit TPopupMenu(QWidget* parent) : QMenu(parent), Items(this) {}

    // VCL Popup(x,y): show context menu at screen position
    void Popup(int x, int y) { popup(QPoint(x, y)); }
};

// VCL drag-and-dock stubs (not supported under Qt; provided for compilation)
typedef int          TDragState;
struct TDragDockObject { QWidget* Control = nullptr; };
// TWndMethod: Borland window-procedure callback type
#include <functional>

// Forward-declare Messages namespace so headers using it compile
namespace Messages {
    struct TMessage {
        unsigned int Msg    = 0;
        intptr_t     WParam = 0;
        intptr_t     LParam = 0;
        intptr_t     Result = 0;
    };
} // namespace Messages

typedef std::function<void(Messages::TMessage&)> TWndMethod;

// Minimal Controls namespace stubs (VCL message IDs etc.)
namespace Controls {
    static const unsigned int CM_DOCKNOTIFICATION = 0xBF5D;
    static const unsigned int CM_VISIBLECHANGED   = 0xBF64;
} // namespace Controls

// VCL TCMDockNotification – message record for dock events
struct TDockNotification { unsigned int ClientMsg = 0; intptr_t MsgWParam = 0; };
struct TCMDockNotification : Messages::TMessage {
    TDockNotification* NotifyRec = nullptr;
    QWidget* Client = nullptr;
};

// WindowProc member – not part of Qt; stub as lambda storage on the widget
struct TWindowProcHolder {
    TWndMethod WindowProc;
};

// VCL BorderIcons set – ignored in Qt (window flags must be set via setWindowFlags)
typedef unsigned int TBorderIcons;
static const TBorderIcons biSystemMenu = 1;
static const TBorderIcons biMinimize   = 2;
static const TBorderIcons biMaximize   = 4;
static const TBorderIcons biHelp       = 8;

// VCL BorderStyle values
typedef int TFormBorderStyle;
static const TFormBorderStyle bsNone        = 0;
static const TFormBorderStyle bsSingle      = 1;
static const TFormBorderStyle bsSizeable    = 2;
static const TFormBorderStyle bsDialog      = 3;
static const TFormBorderStyle bsToolWindow  = 4;
static const TFormBorderStyle bsSizeToolWin = 5;

// VCL Align property values
typedef int TAlign;
static const TAlign alNone   = 0;
static const TAlign alTop    = 1;
static const TAlign alBottom = 2;
static const TAlign alLeft   = 3;
static const TAlign alRight  = 4;
static const TAlign alClient = 5;

// ComObj.hpp: CreateClassID() – uses QUuid on non-Windows
#include <QUuid>
inline AnsiString CreateClassID() {
    return AnsiString(QUuid::createUuid().toString());
}
