//-----------------------------------------------------------------------------
#ifndef VCL2H
#define VCL2H
//-----------------------------------------------------------------------------
//-- Types --------------------------------------------------------------------
//-- SetBase ------------------------------------------------------------------
class SetBase
{
    public:
    SetBase();
    ~SetBase();
};

//-- Set ----------------------------------------------------------------------
class Set : SetBase <T, minEl, maxEl>
{
    public:
    TEMPLATE_BIND(T minEl maxEl, TMenuAnimations maLeftToRight maNone, TBorderIcon biSystemMenu biHelp, Classes__74 csLoading csDesignInstance, Classes__84 csInheritable csTransient, Forms__6 fsCreating fsActivated, TBevelEdge beLeft beBottom, Controls__01 csLButtonDown csDocking, Controls__11 csAcceptsControls csMenuEvents, TAnchorKind akLeft akBottom, TFontStyle fsBold fsStrikeOut)
    Set();
    ~Set();
    Set(const Set& src);
    Set& operator =(const Set& rhs);
    Set& operator +=(const Set& rhs);
    Set& operator -=(const Set& rhs);
    Set& operator *=(const Set& rhs);
    Set operator +(const Set& rhs) const;
    Set operator -(const Set& rhs) const;
    Set operator *(const Set& rhs) const;
    Set& operator <<(const T el);
    Set& operator >>(const T el);
    bool Contains(const T el) const;
    Set& Clear();
    bool Empty() const;
    bool operator ==(const Set& rhs) const;
    bool operator !=(const Set& rhs) const;
};

//-----------------------------------------------------------------------------
enum TMenuAnimations { maLeftToRight, maRightToLeft, maTopToBottom, maBottomToTop, maNone };
typedef Set<TMenuAnimations, maLeftToRight, maNone>  TMenuAnimation;
enum TBorderIcon { biSystemMenu, biMinimize, biMaximize, biHelp };
typedef Set<TBorderIcon, biSystemMenu, biHelp>  TBorderIcons;
enum Classes__74 { csLoading, csReading, csWriting, csDestroying, csDesigning, csAncestor, csUpdating, csFixups, csFreeNotification, csInline, csDesignInstance };
typedef Set<Classes__74, csLoading, csDesignInstance>  TComponentState;
enum Classes__84 { csInheritable, csCheckPropAvail, csSubComponent, csTransient };
typedef Set<Classes__84, csInheritable, csTransient>  TComponentStyle;
enum Forms__6 { fsCreating, fsVisible, fsShowing, fsModal, fsCreatedMDIChild, fsActivated };
typedef Set<Forms__6, fsCreating, fsActivated>  TFormState;
typedef Set<TBevelEdge, beLeft, beBottom>  TBevelEdges;
enum Controls__01 { csLButtonDown, csClicked, csPalette, csReadingState, csAlignmentNeeded, csFocusing, csCreating, csPaintCopy, csCustomPaint, csDestroyingHandle, csDocking };
typedef Set<Controls__01, csLButtonDown, csDocking>  TControlState;
enum Controls__11 { csAcceptsControls, csCaptureMouse, csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque, csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible, csReplicatable, csNoStdEvents, csDisplayDragImage, csReflector, csActionClient, csMenuEvents };
typedef Set<Controls__11, csAcceptsControls, csMenuEvents>  TControlStyle;
enum TAnchorKind { akLeft, akTop, akRight, akBottom };
typedef Set<TAnchorKind, akLeft, akBottom>  TAnchors;
enum TFontStyle { fsBold, fsItalic, fsUnderline, fsStrikeOut };
typedef Set<TFontStyle, fsBold, fsStrikeOut>  TFontStyles;

//-----------------------------------------------------------------------------
typedef Byte TFontCharset;
typedef Word TScrollBarInc;
typedef Word TShortCut;
typedef TResStringRec *PResStringRec;
typedef Shortint TOverlay;
typedef TAlignment TLeftRight;
typedef TFormBorderStyle TBorderStyle;
typedef void **PPointerList;
typedef int TImageIndex;
typedef int TConstraintSize;
typedef int TModalResult;
typedef int THelpContext;
typedef int TBevelWidth;
typedef int TBorderWidth;
typedef int (*TListSortCompare)(void* Item1, void* Item2);
typedef short TTabOrder;

//-----------------------------------------------------------------------------
enum TTrackButton { tbRightButton, tbLeftButton };
enum TPopupAlignment { paLeft, paRight, paCenter };
enum TTileMode { tbHorizontal, tbVertical };
enum TFormBorderStyle { bsNone, bsSingle, bsSizeable, bsDialog, bsToolWindow, bsSizeToolWin };
enum TFormStyle { fsNormal, fsMDIChild, fsMDIForm, fsStayOnTop };
enum TComboBoxStyle { csDropDown, csSimple, csDropDownList, csOwnerDrawFixed, csOwnerDrawVariable };
enum TWindowState { wsNormal, wsMinimized, wsMaximized };
enum TPrintScale { poNone, poProportional, poPrintToFit };
enum TPosition { poDesigned, poDefault, poDefaultPosOnly, poDefaultSizeOnly, poScreenCenter, poDesktopCenter, poMainFormCenter, poOwnerFormCenter };
enum TDefaultMonitor { dmDesktop, dmPrimary, dmMainForm, dmActiveForm };
enum TAlign { alNone, alTop, alBottom, alLeft, alRight, alClient, alCustom };
enum TAlignment { taLeftJustify, taRightJustify, taCenter };
enum TScrollBarKind { sbHorizontal, sbVertical };
enum TScrollStyle { ssNone, ssHorizontal, ssVertical, ssBoth };
enum TListBoxStyle { lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable, lbVirtual, lbVirtualOwnerDraw };
enum TCheckBoxState { cbUnchecked, cbChecked, cbGrayed };
enum TPenStyle { psSolid, psDash, psDot, psDashDot, psDashDotDot, psClear, psInsideFrame };
enum TPenMode { pmBlack, pmWhite, pmNop, pmNot, pmCopy, pmNotCopy, pmMergePenNot, pmMaskPenNot, pmMergeNotPen, pmMaskNotPen, pmMerge, pmNotMerge, pmMask, pmNotMask, pmXor, pmNotXor };
enum TTransparentMode { tmAuto, tmFixed };
enum TPixelFormat { pfDevice, pf1bit, pf4bit, pf8bit, pf15bit, pf16bit, pf24bit, pf32bit, pfCustom };
enum TBitmapHandleType { bmDIB, bmDDB };
enum TCursor {crMin=-32768, crMax=32767};
enum THelpType { htKeyword, htContext };
enum TListAssignOp { laCopy, laAnd, laOr, laXor, laSrcUnique, laDestUnique };
enum TFindItemKind { fkCommand, fkHandle, fkShortCut };
enum TSeekOrigin { soBeginning, soCurrent, soEnd };
enum TColor {clMin=-0x7fffffff-1, clMax=0x7fffffff};
enum TBevelEdge { beLeft, beTop, beRight, beBottom };
enum TBevelCut { bvNone, bvLowered, bvRaised, bvSpace };
enum TBevelKind { bkNone, bkTile, bkSoft, bkFlat };
enum TImeMode { imDisable, imClose, imOpen, imDontCare, imSAlpha, imAlpha, imHira, imSKata, imKata, imChinese, imSHanguel, imHanguel };
enum TDockOrientation { doNoOrient, doHorizontal, doVertical };
enum TBiDiMode { bdLeftToRight, bdRightToLeft, bdRightToLeftNoAlign, bdRightToLeftReadingOnly };
enum TEditCharCase { ecNormal, ecUpperCase, ecLowerCase };
enum TLoadResource { lrDefaultColor, lrDefaultSize, lrFromFile, lrMap3DColors, lrTransparent, lrMonoChrome };
enum TResType { rtBitmap, rtCursor, rtIcon };
enum TImageType { itImage, itMask };
enum TDrawingStyle { dsFocus, dsSelected, dsNormal, dsTransparent };
enum TMenuItemAutoFlag { maAutomatic, maManual, maParent };
enum TMenuBreak { mbNone, mbBreak, mbBarBreak };
enum TScrollBarStyle { ssRegular, ssFlat, ssHotTrack };
enum TBrushStyle { bsSolid, bsClear, bsHorizontal, bsVertical, bsFDiagonal, bsBDiagonal, bsCross, bsDiagCross };
enum TFillStyle { fsSurface, fsBorder };
enum TCanvasOrientation { coLeftToRight, coRightToLeft };
enum TFontPitch { fpDefault, fpVariable, fpFixed };
enum TEditCharCase { ecNormal, ecUpperCase, ecLowerCase };
enum TDragKind { dkDrag, dkDock };
enum TDragMode { dmManual, dmAutomatic };

//-----------------------------------------------------------------------------
typedef _RTL_CRITICAL_SECTION *PRTLCriticalSection;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef long LONG;
typedef void *PVOID;
typedef PVOID HANDLE;
typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;

//-----------------------------------------------------------------------------
//-- Structures ---------------------------------------------------------------
struct TWMMenuChar
{
    TWMMenuChar();
    ~TWMMenuChar();
	unsigned Msg;
	char User;
	Byte Unused;
	Word MenuFlag;
	int Result;
} ;

//-----------------------------------------------------------------------------
struct TResStringRec
{
    TResStringRec();
    ~TResStringRec();
    long        *module;
    long        ident;
};

//-----------------------------------------------------------------------------
typedef struct tagSIZE
{
    tagSIZE();
    ~tagSIZE();
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

//-----------------------------------------------------------------------------
typedef struct _LIST_ENTRY
{
   _LIST_ENTRY();
   ~_LIST_ENTRY();
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER PRLIST_ENTRY;

//-----------------------------------------------------------------------------
typedef struct _RTL_CRITICAL_SECTION_DEBUG
{
    _RTL_CRITICAL_SECTION_DEBUG();
    ~_RTL_CRITICAL_SECTION_DEBUG();
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Spare[2];
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

//-----------------------------------------------------------------------------
typedef struct _RTL_CRITICAL_SECTION
{
    _RTL_CRITICAL_SECTION();
    ~_RTL_CRITICAL_SECTION();
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

//-----------------------------------------------------------------------------
struct TWMKey
{
    TWMKey();
    ~TWMKey();
	unsigned Msg;
	Word CharCode;
	Word Unused;
	int KeyData;
	int Result;
};

//-----------------------------------------------------------------------------
struct TMessage
{
    TMessage();
    ~TMessage();
    Word WParamLo;
    Word WParamHi;
    Word LParamLo;
    Word LParamHi;
    Word ResultLo;
    Word ResultHi;
    int WParam;
    int LParam;
    int Result;
};

//-----------------------------------------------------------------------------
typedef struct tagRECT
{
    tagRECT();
    ~tagRECT();
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

//-----------------------------------------------------------------------------
typedef struct tagPOINT
{
    tagPOINT();
    ~tagPOINT();
    LONG  x;
    LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;

//-----------------------------------------------------------------------------
struct TPoint : public POINT
{
    TPoint();
    TPoint(int _x, int _y);
    TPoint(POINT& pt);
    ~TPoint();
};

//-----------------------------------------------------------------------------
struct TRect : public RECT
{
    TRect();
    ~TRect();
    TRect(const TPoint& TL, const TPoint& BR);
    TRect(int l, int t, int r, int b);
    TRect(RECT& r);
    int Width () const;
    int Height() const;
    bool operator ==(const TRect& rc) const;
    bool operator !=(const TRect& rc) const;
    LONG Left;
    LONG Top;
    LONG Right;
    LONG Bottom;
};

//-- Classes ------------------------------------------------------------------
//-- TMetaClass ---------------------------------------------------------------
class TMetaClass
{
    public:
    TMetaClass();
    virtual ~TMetaClass();
};

//-- TObject ------------------------------------------------------------------
class TObject
{
    public:
    TObject();
    virtual ~TObject();
};

//-- TChangeLink --------------------------------------------------------------
class TChangeLink : public TObject
{
    public:
	virtual ~TChangeLink();
	void Change();
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	TCustomImageList* Sender;
    TChangeLink();
};

//-- TList --------------------------------------------------------------------
class TList : public TObject
{
    public:
	void* operator[](int Index);
	virtual ~TList();
	int Add(void* Item);
	virtual void Clear();
	void Delete(int Index);
	virtual void Error(TMetaClass* vmt, const AnsiString Msg, int Data);
	void Error(TMetaClass* vmt, PResStringRec Msg, int Data);
	void Exchange(int Index1, int Index2);
	TList* Expand();
	void* Extract(void* Item);
	void* First();
	int IndexOf(void* Item);
	void Insert(int Index, void* Item);
	void* Last();
	void Move(int CurIndex, int NewIndex);
	int Remove(void* Item);
	void Pack();
	void Sort(TListSortCompare Compare);
	void Assign(TList* ListA, TListAssignOp AOperator = (TListAssignOp)(0x0), TList* ListB = (TList*)(0x0));
	int Capacity;
	int Count;
	void* Items[LUA_N];
	tolua_readonly PPointerList List;
	TList();
};

//-- TStream ------------------------------------------------------------------
class TStream : public TObject
{
    public:
	virtual int Read(void *Buffer, int Count) = 0 ;
	virtual int Write(const void *Buffer, int Count) = 0 ;
	virtual int Seek(int Offset, Word Origin);
	virtual __int64 Seek(const __int64 Offset, TSeekOrigin Origin);
	void ReadBuffer(void *Buffer, int Count);
	void WriteBuffer(const void *Buffer, int Count);
	__int64 CopyFrom(TStream* Source, __int64 Count);
	TComponent* ReadComponent(TComponent* Instance);
	TComponent* ReadComponentRes(TComponent* Instance);
	void WriteComponent(TComponent* Instance);
	void WriteComponentRes(const AnsiString ResName, TComponent* Instance);
	virtual void WriteDescendent(TComponent* Instance, TComponent* Ancestor);
	void WriteDescendentRes(const AnsiString ResName, TComponent* Instance, TComponent* Ancestor);
	void WriteResourceHeader(const AnsiString ResName, int &FixupInfo);
	void FixupResourceHeader(int FixupInfo);
	void ReadResHeader();
	__int64 Position;
	__int64 Size;
	TStream();
	virtual ~TStream();
};

//-- TDragObject --------------------------------------------------------------
class TDragObject : public TObject
{
    public:
	virtual void Assign(TDragObject* Source);
	virtual AnsiString GetName();
	virtual void HideDragImage();
	virtual unsigned Instance();
	virtual void ShowDragImage();
	bool Cancelling;
	TPoint DragPos;
	TPoint DragTargetPos;
	void* DragTarget;
	tolua_readonly bool Dropped;
	tolua_readonly double MouseDeltaX;
	tolua_readonly double MouseDeltaY;
	TDragObject();
	virtual ~TDragObject();
};

//-- TBaseDragControlObject ---------------------------------------------------
class TBaseDragControlObject : public TDragObject
{
    public:
	TControl* Control;
    virtual TBaseDragControlObject(TControl* AControl);
	virtual void Assign(TDragObject* Source);
	virtual ~TBaseDragControlObject();
};

//-- TDragDockObject ----------------------------------------------------------
class TDragDockObject : public TBaseDragControlObject
{
    public:
	virtual TDragDockObject(TControl* AControl);
	virtual ~TDragDockObject();
	virtual void Assign(TDragObject* Source);
	Brush* Brush;
	TRect DockRect;
	tolua_readonly TAlign DropAlign;
	tolua_readonly TControl* DropOnControl;
	bool Floating;
	tolua_readonly int FrameWidth;
};

//-- TMonitor -----------------------------------------------------------------
class TMonitor : public TObject
{
    public:
	tolua_readonly int MonitorNum;
	tolua_readonly int Left;
	tolua_readonly int Height;
	tolua_readonly int Top;
	tolua_readonly int Width;
	tolua_readonly TRect BoundsRect;
	tolua_readonly TRect WorkareaRect;
	tolua_readonly bool Primary;
	TMonitor();
	virtual ~TMonitor();
};

//-- TBasicActionLink ---------------------------------------------------------
class TBasicActionLink : public TObject
{
    public:
	virtual TBasicActionLink(TObject* AClient);
	virtual ~TBasicActionLink();
	virtual bool Execute(TComponent* AComponent = (TComponent*)(0x0));
	virtual bool Update();
	TBasicAction* Action;
    //	__property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};

//-- TPersistent --------------------------------------------------------------
class TPersistent : public TObject
{
    public:
	TPersistent();
	virtual ~TPersistent();
	virtual void Assign(TPersistent* Source);
};

//-- TCanvas ------------------------------------------------------------------
class TCanvas : public TPersistent
{
    public:
	TCanvas();
    virtual ~TCanvas();
	void Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void BrushCopy(const TRect &Dest, Graphics::TBitmap* Bitmap, const TRect &Source, TColor Color);
	void Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void CopyRect(const TRect &Dest, TCanvas* Canvas, const TRect &Source);
	void Draw(int X, int Y, TGraphic* Graphic);
	void DrawFocusRect(const TRect &Rect);
	void Ellipse(int X1, int Y1, int X2, int Y2);
	void Ellipse(const TRect &Rect);
	void FillRect(const TRect &Rect);
	void FloodFill(int X, int Y, TColor Color, TFillStyle FillStyle);
	void FrameRect(const TRect &Rect);
	bool HandleAllocated();
	void LineTo(int X, int Y);
	void Lock();
	void MoveTo(int X, int Y);
	void Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void Polygon(const TPoint* Points, const int Points_Size);
	void Polyline(const TPoint* Points, const int Points_Size);
	void PolyBezier(const TPoint* Points, const int Points_Size);
	void PolyBezierTo(const TPoint* Points, const int Points_Size);
	void Rectangle(int X1, int Y1, int X2, int Y2);
	void Rectangle(const TRect &Rect);
	void Refresh();
	void RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3);
	void StretchDraw(const TRect &Rect, TGraphic* Graphic);
	tagSIZE TextExtent(const AnsiString Text);
	int TextHeight(const AnsiString Text);
	void TextOut(int X, int Y, const AnsiString Text);
	void TextRect(const TRect &Rect, int X, int Y, const AnsiString Text);
	int TextWidth(const AnsiString Text);
	bool TryLock();
	void Unlock();
    tolua_readonly TRect ClipRect;
	tolua_readonly int LockCount;
	tolua_readonly TCanvasOrientation CanvasOrientation;
	TPoint PenPos;
	TColor Pixels[LUA_N][LUA_N];
	int TextFlags;
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	//__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	TBrush* Brush;
	int CopyMode;
	TFont* Font;
	TPen* Pen;
};

//-- TInterfacedPersistent ----------------------------------------------------
class TInterfacedPersistent : public TPersistent
{
    public:
	virtual void AfterConstruction();
    virtual ~TInterfacedPersistent();
    TInterfacedPersistent();
	operator IInterface*();
};

//-- TPicture -----------------------------------------------------------------
class TPicture : public TInterfacedPersistent
{
    public:
	TPicture();
    virtual ~TPicture();
	void LoadFromFile(const AnsiString Filename);
	void SaveToFile(const AnsiString Filename);
    bool SupportsClipboardFormat(TMetaClass* vmt, Word AFormat);
	virtual void Assign(TPersistent* Source);
    void RegisterFileFormat(TMetaClass* vmt, const AnsiString AExtension, const AnsiString ADescription, TMetaClass* AGraphicClass);
    void RegisterFileFormatRes(TMetaClass* vmt, const AnsiString AExtension, int ADescriptionResID, TMetaClass* AGraphicClass);
    void RegisterClipboardFormat(TMetaClass* vmt, Word AFormat, TMetaClass* AGraphicClass);
    void UnregisterGraphicClass(TMetaClass* vmt, TMetaClass* AClass);
    TBitmap* Bitmap;
    TGraphic* Graphic;
	//_di_IChangeNotifier PictureAdapter;
    tolua_readonly int Height;
    TIcon* Icon;
	TMetafile* Metafile;
	tolua_readonly int Width;
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	//__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	operator IStreamPersist*();
};

//-- TGraphic -----------------------------------------------------------------
class TGraphic : public TInterfacedPersistent
{
    public:
	virtual TGraphic();
	virtual void LoadFromFile(const AnsiString Filename);
	virtual void SaveToFile(const AnsiString Filename);
	virtual void LoadFromStream(TStream* Stream) = 0 ;
	virtual void SaveToStream(TStream* Stream) = 0 ;
	tolua_readonly bool Empty;
	int Height;
	bool Modified;
	bool PaletteModified;
	bool Transparent;
	int Width;
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	//__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
    virtual ~TGraphic();
	operator IStreamPersist*();
};

//-- TMetafile ----------------------------------------------------------------
class TMetafile : public TGraphic
{
    public:
	virtual TMetafile();
	virtual ~TMetafile();
	void Clear();
	bool HandleAllocated();
	virtual void LoadFromStream(TStream* Stream);
	virtual void SaveToFile(const AnsiString Filename);
	virtual void SaveToStream(TStream* Stream);
	virtual void Assign(TPersistent* Source);
	unsigned ReleaseHandle();
	tolua_readonly AnsiString CreatedBy;
	tolua_readonly AnsiString Description;
	bool Enhanced;
	unsigned Handle;
	int MMWidth;
	int MMHeight;
    Word Inch;
};

//-- TIcon --------------------------------------------------------------------
class TIcon : public TGraphic
{
    public:
	virtual TIcon();
    virtual ~TIcon();
	virtual void Assign(TPersistent* Source);
	bool HandleAllocated();
	virtual void LoadFromStream(TStream* Stream);
	virtual void SaveToStream(TStream* Stream);
};

//-- TBitmap ------------------------------------------------------------------
class TBitmap : public TGraphic
{
    public:
	virtual TBitmap();
    virtual ~TBitmap();
	virtual void Assign(TPersistent* Source);
	void Dormant();
	void FreeImage();
	bool HandleAllocated();
	virtual void LoadFromStream(TStream* Stream);
	void LoadFromResourceName(unsigned Instance, const AnsiString ResName);
	void LoadFromResourceID(unsigned Instance, int ResID);
	void Mask(TColor TransparentColor);
	virtual void SaveToStream(TStream* Stream);
	tolua_readonly TCanvas* Canvas;
	TBitmapHandleType HandleType;
	bool IgnorePalette;
	bool Monochrome;
	TPixelFormat PixelFormat;
	tolua_readonly void* ScanLine[LUA_N];
	TColor TransparentColor;
    TTransparentMode TransparentMode;
};


//-- TGraphicsObject ----------------------------------------------------------
class TGraphicsObject : public TPersistent
{
    public:
	bool HandleAllocated();
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	PRTLCriticalSection OwnerCriticalSection;
	virtual ~TGraphicsObject();
	TGraphicsObject();
};

//-- TFont --------------------------------------------------------------------
class TFont : public TGraphicsObject
{
    public:
	TFont();
	virtual ~TFont();
	virtual void Assign(TPersistent* Source);
    //_di_IChangeNotifier FontAdapter;
	int PixelsPerInch;
	TFontCharset Charset;
	TColor Color;
	int Height;
	AnsiString Name;
	TFontPitch Pitch;
	int Size;
	TFontStyles Style;
};

//-- TPen ---------------------------------------------------------------------
class TPen : public TGraphicsObject
{
    public:
    TPen();
    virtual ~TPen();
	virtual void Assign(TPersistent* Source);
    TColor Color;
    TPenMode Mode;
    TPenStyle Style;
    int Width;
};

//-- TBrush -------------------------------------------------------------------
class TBrush : public TGraphicsObject
{
    public:
	TBrush();
	virtual ~TBrush();
	virtual void Assign(TPersistent* Source);
	TBitmap* Bitmap;
	TColor Color;
	TBrushStyle Style;
};

//-- TStrings --------------------------------------------------------------
class TStrings : public TPersistent
{
    public:
	AnsiString operator[](int Index);
	virtual ~TStrings();
	virtual int Add(const AnsiString S);
	virtual int AddObject(const AnsiString S, TObject* AObject);
	void Append(const AnsiString S);
	virtual void AddStrings(TStrings* Strings);
	virtual void Assign(TPersistent* Source);
	void BeginUpdate();
	virtual void Clear() = 0 ;
	virtual void Delete(int Index) = 0 ;
	void EndUpdate();
	bool Equals(TStrings* Strings);
	virtual void Exchange(int Index1, int Index2);
	virtual char* GetText();
	virtual int IndexOf(const AnsiString S);
	virtual int IndexOfName(const AnsiString Name);
	virtual int IndexOfObject(TObject* AObject);
	virtual void Insert(int Index, const AnsiString S) = 0 ;
	virtual void InsertObject(int Index, const AnsiString S, TObject* AObject);
	virtual void LoadFromFile(const AnsiString FileName);
	virtual void LoadFromStream(TStream* Stream);
	virtual void Move(int CurIndex, int NewIndex);
	virtual void SaveToFile(const AnsiString FileName);
	virtual void SaveToStream(TStream* Stream);
	virtual void SetText(char* Text);
	int Capacity;
	AnsiString CommaText;
	tolua_readonly int Count;
	char Delimiter;
	AnsiString DelimitedText;
	tolua_readonly AnsiString Names[LUA_N];
	TObject* Objects[LUA_N];
	char QuoteChar;
	AnsiString Values[LUA_N];
	AnsiString Strings[LUA_N];
	AnsiString Text;
	TStrings();
};

//-- TControlScrollBar --------------------------------------------------------
class TControlScrollBar : public TPersistent
{
    public:
	virtual void Assign(TPersistent* Source);
	void ChangeBiDiPosition();
	tolua_readonly TScrollBarKind Kind;
	bool IsScrollBarVisible();
	tolua_readonly int ScrollPos;
	int ButtonSize;
	TColor Color;
	TScrollBarInc Increment;
	Word Margin;
	bool ParentColor;
	int Position;
	int Range;
    bool Smooth;
	int Size;
	TScrollBarStyle Style;
	int ThumbSize;
	bool Tracking;
	bool Visible;
	virtual ~TControlScrollBar();
	TControlScrollBar();
};

//-- TSizeConstraints ---------------------------------------------------------
class TSizeConstraints : public TPersistent
{
    public:
	virtual TSizeConstraints(TControl* Control);
	TConstraintSize MaxHeight;
	TConstraintSize MaxWidth;
	TConstraintSize MinHeight;
	TConstraintSize MinWidth;
	virtual ~TSizeConstraints();
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};

//-- TComponent ---------------------------------------------------------------
class TComponent : public TPersistent
{
    public:
  	AnsiString Name;
    int Tag;
    virtual TComponent(TComponent* AOwner);
	virtual ~TComponent();
	bool ExecuteAction(TBasicAction* Action);
	bool HasParent();
	bool UpdateAction(TBasicAction* Action);
	tolua_readonly TComponent* Components[LUA_N];
	tolua_readonly int ComponentCount;
	int ComponentIndex;
	tolua_readonly TComponentState ComponentState;
	tolua_readonly TComponentStyle ComponentStyle;
	int DesignInfo;
	tolua_readonly TComponent* Owner;
};

//-- TMenuItem ----------------------------------------------------------------
class TMenuItem : public TComponent
{
    public:
	TMenuItem* operator[](int Index);
	virtual TMenuItem(TComponent* AOwner);
	virtual ~TMenuItem();
	virtual void InitiateAction();
	void Insert(int Index, TMenuItem* Item);
	void Delete(int Index);
	void Clear();
	virtual void Click();
	TMenuItem* Find(AnsiString ACaption);
	int IndexOf(TMenuItem* Item);
	bool IsLine();
	TCustomImageList* GetImageList();
	TComponent* GetParentComponent();
	TMenu* GetParentMenu();
	bool HasParent();
	int NewTopLine();
	int NewBottomLine();
	int InsertNewLineBefore(TMenuItem* AItem);
	int InsertNewLineAfter(TMenuItem* AItem);
	void Add(TMenuItem* Item);
	void Add(const TMenuItem** AItems, const int AItems_Size);
	void Remove(TMenuItem* Item);
	bool RethinkHotkeys();
	bool RethinkLines();
	tolua_readonly Word Command;
	tolua_readonly int Count;
	tolua_readonly TMenuItem* Items[LUA_N];
	int MenuIndex;
	tolua_readonly TMenuItem* Parent;
	TBasicAction* Action;
	bool AutoCheck;
	TMenuItemAutoFlag AutoHotkeys;
	TMenuItemAutoFlag AutoLineReduction;
	Graphics::TBitmap* Bitmap;
	TMenuBreak Break;
	AnsiString Caption;
	bool Checked;
	TCustomImageList* SubMenuImages;
	bool Default;
	bool Enabled;
	Byte GroupIndex;
	THelpContext HelpContext;
	AnsiString Hint;
    TImageIndex ImageIndex;
	bool RadioItem;
	TShortCut ShortCut;
	bool Visible;
	//__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	//__property TMenuDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	//__property TAdvancedMenuDrawItemEvent OnAdvancedDrawItem = {read=FOnAdvancedDrawItem, write=FOnAdvancedDrawItem};
	//__property TMenuMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
};

//-- TMenu --------------------------------------------------------------------
class TMenu : public TComponent
{
    public:
	virtual TMenu(TComponent* AOwner);
	virtual ~TMenu();
	bool DispatchCommand(Word ACommand);
	TMenuItem* FindItem(int Value, TFindItemKind Kind);
	THelpContext GetHelpContext(int Value, bool ByCommand);
	TCustomImageList* Images;
	bool IsRightToLeft();
	bool IsShortCut(TWMKey &Message);
	void ParentBiDiModeChanged();
	void ParentBiDiModeChanged(TObject* AControl);
	void ProcessMenuChar(TWMMenuChar &Message);
    TMenuAutoFlag AutoHotkeys;
	TMenuAutoFlag AutoLineReduction;
	TBiDiMode BiDiMode;
	bool OwnerDraw;
	bool ParentBiDiMode;
	tolua_readonly TMenuItem* Items;
};

//-- TPopupMenu ---------------------------------------------------------------
class TPopupMenu : public TMenu
{
    public:
	virtual TPopupMenu(TComponent* AOwner);
	virtual ~TPopupMenu();
	virtual void Popup(int X, int Y);
	TComponent* PopupComponent;
	tolua_readonly TPoint PopupPoint;
	TPopupAlignment Alignment;
	bool AutoPopup;
	THelpContext HelpContext;
	TMenuAnimation MenuAnimation;
	TTrackButton TrackButton;
	//__property Classes::TNotifyEvent OnPopup = {read=FOnPopup, write=FOnPopup};
};

//-- TMainMenu ----------------------------------------------------------------
class TMainMenu : public TMenu
{
    public:
	void Merge(TMainMenu* Menu);
	void Unmerge(TMainMenu* Menu);
	bool AutoMerge;
	virtual TMainMenu(TComponent* AOwner);
	virtual ~TMainMenu();
};

//-- TCustomImageList ---------------------------------------------------------
class TCustomImageList : public TComponent
{
    public:
	virtual TCustomImageList(TComponent* AOwner);
	TCustomImageList(int AWidth, int AHeight);
	virtual ~TCustomImageList();
	virtual void Assign(TPersistent* Source);
	int Add(Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	int AddIcon(TIcon* Image);
	void AddImages(TCustomImageList* Value);
	int AddMasked(Graphics::TBitmap* Image, TColor MaskColor);
	void Clear();
	void Delete(int Index);
	void Draw(TCanvas* Canvas, int X, int Y, int Index, bool Enabled = true);
	void Draw(TCanvas* Canvas, int X, int Y, int Index, TDrawingStyle ADrawingStyle, TImageType AImageType, bool Enabled = true);
	void DrawOverlay(TCanvas* Canvas, int X, int Y, int ImageIndex, TOverlay Overlay, bool Enabled = true);
	void DrawOverlay(TCanvas* Canvas, int X, int Y, int ImageIndex, TOverlay Overlay, TDrawingStyle ADrawingStyle, TImageType AImageType, bool Enabled = true);
	bool FileLoad(TResType ResType, const AnsiString Name, TColor MaskColor);
	bool GetBitmap(int Index, Graphics::TBitmap* Image);
	virtual TPoint __fastcall GetHotSpot();
	void GetIcon(int Index, TIcon* Image);
	void GetIcon(int Index, TIcon* Image, TDrawingStyle ADrawingStyle, TImageType AImageType);
	bool GetResource(TResType ResType, const AnsiString Name, int Width, TLoadResources LoadFlags, TColor MaskColor);
	bool GetInstRes(unsigned Instance, TResType ResType, const AnsiString Name, int Width, TLoadResources LoadFlags, TColor MaskColor);
	bool GetInstRes(unsigned Instance, TResType ResType, unsigned ResID, int Width, TLoadResources LoadFlags, TColor MaskColor);
	bool HandleAllocated();
	void Insert(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void InsertIcon(int Index, TIcon* Image);
	void InsertMasked(int Index, Graphics::TBitmap* Image, TColor MaskColor);
	void Move(int CurIndex, int NewIndex);
	bool Overlay(int ImageIndex, TOverlay Overlay);
	void RegisterChanges(TChangeLink* Value);
	bool ResourceLoad(TResType ResType, const AnsiString Name, TColor MaskColor);
	bool ResInstLoad(unsigned Instance, TResType ResType, const AnsiString Name, TColor MaskColor);
	void Replace(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void ReplaceIcon(int Index, TIcon* Image);
	void ReplaceMasked(int Index, Graphics::TBitmap* NewImage, TColor MaskColor);
	void UnRegisterChanges(TChangeLink* Value);
	tolua_readonly int Count;
	unsigned Handle;
	int AllocBy;
	TColor BlendColor;
	TColor BkColor;
	TDrawingStyle DrawingStyle;
	int Height;
	TImageType ImageType;
	bool Masked;
	bool ShareImages;
	int Width;
	//__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};

//-- TBasicAction -------------------------------------------------------------
class TBasicAction : public TComponent
{
    public:
	virtual TBasicAction(TComponent* AOwner);
	virtual ~TBasicAction();
	virtual bool HandlesTarget(TObject* Target);
	virtual void UpdateTarget(TObject* Target);
	virtual void ExecuteTarget(TObject* Target);
	bool Execute();
	void RegisterChanges(TBasicActionLink* Value);
	void UnRegisterChanges(TBasicActionLink* Value);
	virtual bool Update();
    TComponent* ActionComponent;
	//__property TNotifyEvent OnExecute = {read=FOnExecute, write=SetOnExecute};
	//__property TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
};

//-- TControl -----------------------------------------------------------------
class TControl : public TComponent
{
    public:
	int Left;
    int Top;
	int Width;
	int Height;
	TCursor Cursor;
	AnsiString Hint;
	THelpType HelpType;
	AnsiString HelpKeyword;
	THelpContext HelpContext;
    virtual TControl(TComponent* AOwner);
	virtual ~TControl();
	void BeginDrag(bool Immediate, int Threshold = 0xffffffff);
	void BringToFront();
	TPoint ClientToScreen(const TPoint &Point);
	TPoint ClientToParent(const TPoint &Point, TWinControl* AParent = (TWinControl*)(0x0));
	void Dock(TWinControl* NewDockSite, const TRect &ARect);
	virtual void DefaultHandler(void *Message);
	bool Dragging();
	void DragDrop(TObject* Source, int X, int Y);
	int DrawTextBiDiModeFlags(int Flags);
	int DrawTextBiDiModeFlagsReadingOnly();
	bool Enabled;
	void EndDrag(bool Drop);
    TAlignment GetControlsAlignment();
	TComponent* GetParentComponent();
	int GetTextBuf(char* Buffer, int BufSize);
	int GetTextLen();
	bool HasParent();
	void Hide();
	virtual void InitiateAction();
	virtual void Invalidate();
	void MouseWheelHandler(TMessage &Message);
	bool IsRightToLeft();
	bool ManualDock(TWinControl* NewDockSite, TControl* DropControl = (TControl*)(0x0), TAlign ControlSide = (TAlign)(0x0));
	bool ManualFloat(const TRect &ScreenPos);
	int Perform(unsigned Msg, int WParam, int LParam);
	void Refresh();
	virtual void Repaint();
	bool ReplaceDockedControl(TControl* Control, TWinControl* NewDockSite, TControl* DropControl, TAlign ControlSide);
	TPoint ScreenToClient(const TPoint &Point);
	TPoint ParentToClient(const TPoint &Point, TWinControl* AParent = (TWinControl*)(0x0));
	void SendToBack();
	virtual void SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void SetTextBuf(char* Buffer);
	void Show();
	virtual void Update();
	bool UseRightToLeftAlignment();
	bool UseRightToLeftReading();
	bool UseRightToLeftScrollBar();
	TBasicAction* Action;
	TAlign Align;
	TAnchors Anchors;
	TBiDiMode BiDiMode;
	TRect BoundsRect;
	int ClientHeight;
	tolua_readonly TPoint ClientOrigin;
    tolua_readonly TRect ClientRect;
	int ClientWidth;
	TSizeConstraints* Constraints;
	TControlState ControlState;
	TControlStyle ControlStyle;
	TDockOrientation DockOrientation;
	tolua_readonly bool Floating;
	TMetaClass* FloatingDockSiteClass;
	TWinControl* HostDockSite;
	int LRDockWidth;
	TWinControl* Parent;
	bool ShowHint;
	int TBDockHeight;
	int UndockHeight;
	int UndockWidth;
	bool Visible;
};

//-- TGraphicControl ----------------------------------------------------------
class TGraphicControl : public TControl
{
    public:
	virtual TGraphicControl(TComponent* AOwner);
	virtual ~TGraphicControl();
};

//-- TImage -------------------------------------------------------------------
class TImage : public TGraphicControl
{
    public:
	virtual TImage(TComponent* AOwner);
	virtual ~TImage();
	tolua_readonly TCanvas* Canvas;
	bool Center;
	bool IncrementalDisplay;
	TPicture* Picture;
	bool Proportional;
	bool Stretch;
	bool Transparent;
/*	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Graphics::TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property OnStartDock ;
	__property OnStartDrag ;
*/
};

//-- TWinControl --------------------------------------------------------------
class TWinControl : public TControl
{
    public:
	virtual TWinControl(TComponent* AOwner);
	virtual ~TWinControl();
	void Broadcast(void *Message);
	bool CanFocus();
	bool ContainsControl(TControl* Control);
	TControl* ControlAtPos(const TPoint &Pos, bool AllowDisabled, bool AllowWinControls = false);
	virtual void DefaultHandler(void *Message);
	void DisableAlign();
	tolua_readonly int DockClientCount;
	tolua_readonly TControl* DockClients[LUA_N];
	void DockDrop(TDragDockObject* Source, int X, int Y);
	bool DoubleBuffered;
	void EnableAlign();
	TControl* FindChildControl(const AnsiString ControlName);
	void FlipChildren(bool AllLevels);
	bool Focused();
	void GetTabOrderList(TList* List);
	bool HandleAllocated();
	void HandleNeeded();
	void InsertControl(TControl* AControl);
	virtual void Invalidate();
	void PaintTo(TCanvas* Canvas, int X, int Y);
	void RemoveControl(TControl* AControl);
	void Realign();
	virtual void Repaint();
	void ScaleBy(int M, int D);
	void ScrollBy(int DeltaX, int DeltaY);
	virtual void SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void SetFocus();
	virtual void Update();
	void UpdateControlState();
	tolua_readonly bool AlignDisabled;
	tolua_readonly int VisibleDockClientCount;
	tolua_readonly TBrush* Brush;
	tolua_readonly TControl* Controls[LUA_N];
	tolua_readonly int ControlCount;
	tolua_readonly bool Showing;
	TTabOrder TabOrder;
    bool TabStop;
};

//-- TCustomListControl -------------------------------------------------------
class TCustomListControl : public TWinControl
{
    public:
	virtual void AddItem(AnsiString Item, TObject* AObject) = 0 ;
	virtual void Clear() = 0 ;
	virtual void ClearSelection() = 0 ;
	virtual void CopySelection(TCustomListControl* Destination) = 0 ;
	virtual void DeleteSelected() = 0 ;
	virtual void MoveSelection(TCustomListControl* Destination);
	virtual void SelectAll() = 0 ;
	int ItemIndex;
    virtual TCustomListControl(TComponent* AOwner);
	virtual ~TCustomListControl();
};

//-- TCustomCombo -------------------------------------------------------------
class TCustomCombo : public TCustomListControl
{
    public:
	virtual TCustomCombo(TComponent* AOwner);
    virtual ~TCustomCombo();
	virtual void AddItem(AnsiString Item, TObject* AObject);
	virtual void Clear();
	virtual void ClearSelection();
	virtual void CopySelection(TCustomListControl* Destination);
	virtual void DeleteSelected();
	bool Focused();
	virtual void SelectAll();
	tolua_readonly TCanvas* Canvas;
	bool DroppedDown;
	tolua_readonly TStrings* Items;
	int SelLength;
	int SelStart;
};

//-- TCustomMultiSelectListControl --------------------------------------------
class TCustomMultiSelectListControl : public TCustomListControl
{
    public:
	bool MultiSelect;
	tolua_readonly int SelCount;
	virtual TCustomMultiSelectListControl(TComponent* AOwner);
	virtual ~TCustomMultiSelectListControl();
};

//-- TScrollingWinControl -----------------------------------------------------
class TScrollingWinControl : public TWinControl
{
    public:
	TControlScrollBar* HorzScrollBar;
	TControlScrollBar* VertScrollBar;
	virtual TScrollingWinControl(TComponent* AOwner);
	virtual ~TScrollingWinControl();
	void DisableAutoRange();
	void EnableAutoRange();
	void ScrollInView(TControl* AControl);
};

//-- TButtonControl -----------------------------------------------------------
class TButtonControl : public TWinControl
{
    public:
	virtual TButtonControl(TComponent* AOwner);
	virtual ~TButtonControl();
};

//-- TCustomControl -----------------------------------------------------------
class TCustomControl : public TWinControl
{
    public:
	virtual TCustomControl(TComponent* AOwner);
	virtual ~TCustomControl();
};

//-- TEdit --------------------------------------------------------------------
class TEdit : public TWinControl
{
    public:
	bool ParentCtl3D;
	bool Ctl3D;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool AutoSelect;
	bool AutoSize;
	bool HideSelection;
	bool OEMConvert;
	bool ReadOnly;
	bool Modified;
	char PasswordChar;
	int MaxLength;
	TEditCharCase CharCase;
	AnsiString SelText;
	AnsiString Text;
	TFont* Font;
	TPopupMenu* PopupMenu;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
    TBevelEdges BevelEdges;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
    TBevelKind BevelKind;
	TBorderWidth BorderWidth;
	TImeMode ImeMode;
	AnsiString ImeName;
	tolua_readonly bool CanUndo;
    /*
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TEdit(TComponent* AOwner);
	virtual ~TEdit();
	virtual void Clear();
	void ClearSelection();
	void CopyToClipboard();
	void CutToClipboard();
	virtual void DefaultHandler(void *Message);
	void PasteFromClipboard();
	void Undo();
	void ClearUndo();
	virtual int GetSelTextBuf(char* Buffer, int BufSize);
	void SelectAll();
	void SetSelTextBuf(char* Buffer);
};

//-- TMemo --------------------------------------------------------------------
class TMemo : public TEdit
{
    public:
	int MaxLength;
	bool OEMConvert;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ParentCtl3D;
	bool ReadOnly;
	bool Ctl3D;
  	bool Enabled;
	bool HideSelection;
	bool WantReturns;
	bool WantTabs;
	bool WordWrap;
    TAlign Align;
	TAlignment Alignment;
    TBevelEdges BevelEdges;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
    TBevelKind BevelKind;
	TBorderWidth BorderWidth;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TImeMode ImeMode;
	AnsiString ImeName;
	TPoint CaretPos;
    TStrings* Lines;
	TScrollStyle ScrollBars;
    /*
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TMemo(TComponent* AOwner);
	virtual ~TMemo();
	TAlignment GetControlsAlignment();
};

//-- TButton ------------------------------------------------------------------
class TButton : public TButtonControl
{
    public:
	bool Cancel;
	bool Default;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentFont;
	bool ParentShowHint;
    TBevelEdges BevelEdges;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
    TBevelKind BevelKind;
	TBorderWidth BorderWidth;
	TImeMode ImeMode;
	AnsiString ImeName;
	AnsiString Caption;
    TBasicAction* Action;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TModalResult ModalResult;
    /*
	__property PopupMenu ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TButton(TComponent* AOwner);
	void Click();
	bool UseRightToLeftAlignment();
    virtual ~TButton();
};

//-- TCheckBox ----------------------------------------------------------------
class TCheckBox : public TButtonControl
{
    public:
	bool AllowGrayed;
	bool Checked;
	bool Ctl3D;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ParentCtl3D;
	TBasicAction* Action;
	TAlignment Alignment;
	AnsiString Caption;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TCheckBoxState State;
    /*
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TCheckBox(TComponent* AOwner);
	virtual ~TCheckBox();
	TAlignment GetControlsAlignment();
};

//-- TRadioButton -------------------------------------------------------------
class TRadioButton : public TButtonControl
{
    public:
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ParentCtl3D;
	bool Checked;
	bool Ctl3D;
  	bool Enabled;
	TBasicAction* Action;
    TLeftRight Alignment;
	AnsiString Caption;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
    TPopupMenu* PopupMenu;
    /*
	__property PopupMenu ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TRadioButton(TComponent* AOwner);
	TAlignment GetControlsAlignment();
    virtual ~TRadioButton();
};

//-- TListBox -----------------------------------------------------------------
class TListBox : public TCustomMultiSelectListControl
{
    public:
	short TabWidth;
	int Columns;
	int Count;
	int ItemHeight;
	int ScrollWidth;
	int TopIndex;
	bool Ctl3D;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ExtendedSelect;
	bool IntegralHeight;
	bool ParentCtl3D;
	bool Sorted;
	bool AutoComplete;
	bool Selected[LUA_N];
	TListBoxStyle Style;
	TAlign Align;
    TBevelEdges BevelEdges;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
    TBevelKind BevelKind;
	TBorderStyle BorderStyle;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
	TImeMode ImeMode;
	AnsiString ImeName;
    /*
	__property OnClick ;
	__property OnContextPopup ;
	__property OnData ;
	__property OnDataFind ;
	__property OnDataObject ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
    virtual TListBox(TComponent* AOwner);
	virtual ~TListBox();
	virtual void AddItem(AnsiString Item, TObject* AObject);
	virtual void Clear();
	virtual void ClearSelection();
	virtual void CopySelection(TCustomListControl* Destination);
	virtual void DeleteSelected();
	int ItemAtPos(const TPoint &Pos, bool Existing);
	TRect ItemRect(int Index);
	virtual void SelectAll();
};

//-- TScrollBar ---------------------------------------------------------------
class TScrollBar : public TWinControl
{
    public:
	int Max;
	int Min;
	int PageSize;
	int Position;
	bool ParentCtl3D;
	bool Ctl3D;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentShowHint;
	TAlign Align;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TScrollBarKind Kind;
	TScrollBarInc LargeChange;
	TPopupMenu* PopupMenu;
	TScrollBarInc SmallChange;
    /*
	__property OnContextPopup ;
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TScrollBar(TComponent* AOwner);
	void SetParams(int APosition, int AMin, int AMax);
    virtual ~TScrollBar();
};

//-- TComboBox ----------------------------------------------------------------
class TComboBox : public TCustomCombo
{
    public:
	int ItemHeight;
	int DropDownCount;
	int ItemIndex;
	int MaxLength;
	bool ParentCtl3D;
	bool Sorted;
	bool AutoComplete;
	bool AutoDropDown;
    bool Ctl3D;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	TEditCharCase CharCase;
	AnsiString SelText;
    TBevelEdges BevelEdges;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
    TBevelKind BevelKind;
	TComboBoxStyle Style;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
	TImeMode ImeMode;
	AnsiString ImeName;
	AnsiString Text;
    /*
	__property OnChange ;
	__property OnClick ;
	__property OnCloseUp ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnDropDown ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnSelect ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
	virtual TComboBox(TComponent* AOwner);
	virtual ~TComboBox();
};

//-- TGroupBox ----------------------------------------------------------------
class TGroupBox : public TCustomControl
{
    public:
	bool Ctl3D;
	bool DockSite;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ParentCtl3D;
	TAlign Align;
	AnsiString Caption;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
    /*
	__property PopupMenu ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
    */
	virtual TGroupBox(TComponent* AOwner);
	virtual ~TGroupBox();
};

//-- TRadioGroup --------------------------------------------------------------
class TRadioGroup : public TGroupBox
{
    public:
	int Columns;
	bool Ctl3D;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool ParentCtl3D;
	TAlign Align;
	AnsiString Caption;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
    /*
	__property PopupMenu ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDock ;
	__property OnStartDrag ;
    */
    virtual TRadioGroup(TComponent* AOwner);
	virtual ~TRadioGroup();
	void FlipChildren(bool AllLevels);
};

//-- TPanel -------------------------------------------------------------------
class TPanel : public TCustomControl
{
    public:
	bool AutoSize;
    bool ParentBiDiMode;
	bool ParentColor;
	bool ParentFont;
	bool ParentShowHint;
	bool FullRepaint;
	bool Locked;
	bool ParentCtl3D;
  	bool Enabled;
	bool Ctl3D;
	bool DockSite;
	bool UseDockManager;
	TAlign Align;
	TAlignment Alignment;
	TBevelCut BevelInner;
	TBevelCut BevelOuter;
	TBevelWidth BevelWidth;
	TBorderWidth BorderWidth;
	TBorderStyle BorderStyle;
	AnsiString Caption;
	TColor Color;
	TDragKind DragKind;
	TCursor DragCursor;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
    /*
	__property PopupMenu ;
	__property OnCanResize ;
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
	__property DockManager ;
    */
	virtual TPanel(TComponent* AOwner);
	virtual ~TPanel();
	TAlignment GetControlsAlignment();
};

//-- TForm --------------------------------------------------------------------
class TForm : public TScrollingWinControl
{
    public:
	int ClientHeight;
	int PixelsPerInch;
	int ClientWidth;
	bool DropTarget;
	bool KeyPreview;
	bool AlphaBlend;
	bool AutoScroll;
	bool AutoSize;
	bool TransparentColor;
	bool Ctl3D;
	bool UseDockManager;
	bool DockSite;
  	bool Enabled;
    bool ParentBiDiMode;
	bool ParentFont;
	bool KeyPreview;
	bool OldCreateOrder;
	bool Scaled;
	TTileMode TileMode;
	TBasicAction* Action;
	TAlign Align;
	Byte AlphaBlendValue;
	TBorderIcons BorderIcons;
	TFormBorderStyle BorderStyle;
	TBorderWidth BorderWidth;
	AnsiString Caption;
	TColor Color;
	TColor TransparentColorValue;
	TDefaultMonitor DefaultMonitor;
	TDragKind DragKind;
	TDragMode DragMode;
	TFont* Font;
	TPopupMenu* PopupMenu;
	TFormStyle FormStyle;
	TControlScrollBar* HorzScrollBar;
	TIcon* Icon;
	TMainMenu* Menu;
	TMenuItem* ObjectMenuItem;
	AnsiString HelpFile;
	TModalResult ModalResult;
    TWindowState WindowState;
	TWinControl* ActiveControl;
	TWinControl* ActiveOleControl;
	TPosition Position;
	TPrintScale PrintScale;
	TControlScrollBar* VertScrollBar;
	tolua_readonly TForm* ActiveMDIChild;
	tolua_readonly int MDIChildCount;
	tolua_readonly TForm* MDIChildren[LUA_N];
    tolua_readonly TFormState FormState;
	tolua_readonly TMonitor* Monitor;
	tolua_readonly bool Active;
    //_di_IDesignerHook Designer;
    //_di_IOleForm OleFormObject;
	//tolua_readonly _di_IDockManager DockManager;
    /*
	__property WindowMenu ;
	__property OnActivate ;
	__property OnCanResize ;
	__property OnClick ;
	__property OnClose ;
	__property OnCloseQuery ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnCreate ;
	__property OnDblClick ;
	__property OnDestroy ;
	__property OnDeactivate ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnHide ;
	__property OnHelp ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnShortCut ;
	__property OnShow ;
	__property OnStartDock ;
	__property OnUnDock ;
    */
	virtual TForm(TComponent* AOwner);
	virtual TForm(TComponent* AOwner, int Dummy);
	virtual ~TForm();
	void ArrangeIcons();
	void Cascade();
	void Next();
	void Previous();
	void Tile();
	virtual void AfterConstruction();
	virtual void BeforeDestruction();
	void Close();
	virtual bool CloseQuery();
	virtual void DefaultHandler(void *Message);
	void DefocusControl(TWinControl* Control, bool Removing);
	void Dock(TWinControl* NewDockSite, const TRect &ARect);
	void FocusControl(TWinControl* Control);
	Graphics::TBitmap* GetFormImage();
	void Hide();
	bool IsShortCut(TWMKey &Message);
	void MakeFullyVisible(TMonitor* AMonitor = (TMonitor*)(0x0));
	void MouseWheelHandler(TMessage &Message);
	void Print();
	void Release();
	void SendCancelMode(TControl* Sender);
	virtual void SetFocus();
	virtual bool SetFocusedControl(TWinControl* Control);
	void Show();
	virtual int ShowModal();
	virtual bool WantChildKey(TControl* Child, TMessage &Message);
};

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
