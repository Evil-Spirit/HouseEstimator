// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GridRoutineU.pas' rev: 6.00

#ifndef GridRoutineUHPP
#define GridRoutineUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Mask.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Gridroutineu
{
//-- type declarations -------------------------------------------------------
typedef void * *PPointer;

#pragma pack(push, 4)
struct TSelection
{
	int StartPos;
	int EndPos;
} ;
#pragma pack(pop)

class DELPHICLASS TMyInplaceEdit;
class DELPHICLASS TMyCustomGrid;
class PASCALIMPLEMENTATION TMyCustomGrid : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
public:
	int UnionCellPas;
	Grids::TGridCoord FAnchor;
	Grids::TGridCoord FCurrent;
	bool FixedColSize;
	bool FixedRowSize;
	Forms::TFormBorderStyle FBorderStyle;
	bool FCanEditModify;
	int FColCount;
	void *FColWidths;
	void *FTabStops;
	int FDefaultColWidth;
	int FDefaultRowHeight;
	int FFixedCols;
	int FFixedRows;
	Graphics::TColor FFixedColor;
	int FGridLineWidth;
	Grids::TGridOptions FOptions;
	int FRowCount;
	void *FRowHeights;
	Stdctrls::TScrollStyle FScrollBars;
	Grids::TGridCoord FTopLeft;
	int FSizingIndex;
	int FSizingPos;
	int FSizingOfs;
	int FMoveIndex;
	int FMovePos;
	#pragma pack(push, 1)
	Types::TPoint FHitTest;
	#pragma pack(pop)
	
	TMyInplaceEdit* FInplaceEdit;
	int FInplaceCol;
	int FInplaceRow;
	int FColOffset;
	bool FDefaultDrawing;
	bool FEditorMode;
	Grids::TGridCoord __fastcall CalcCoordFromPoint(int X, int Y, const Grids::TGridDrawInfo &DrawInfo);
	void __fastcall CalcDrawInfoXY(Grids::TGridDrawInfo &DrawInfo, int UseWidth, int UseHeight);
	Grids::TGridCoord __fastcall CalcMaxTopLeft(const Grids::TGridCoord &Coord, const Grids::TGridDrawInfo &DrawInfo);
	void __fastcall CancelMode(void);
	void __fastcall ChangeSize(int NewColCount, int NewRowCount);
	void __fastcall ClampInView(const Grids::TGridCoord &Coord);
	void __fastcall DrawSizingLine(const Grids::TGridDrawInfo &DrawInfo);
	void __fastcall DrawMove(void);
	void __fastcall GridRectToScreenRect(const Grids::TGridRect &GridRect, Types::TRect &ScreenRect, bool IncludeLine);
	void __fastcall Initialize(void);
	void __fastcall InvalidateRect(const Grids::TGridRect &ARect);
	virtual void __fastcall ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft);
	void __fastcall MoveAdjust(int &CellPos, int FromIndex, int ToIndex);
	void __fastcall MoveAnchor(const Grids::TGridCoord &NewAnchor);
	void __fastcall MoveAndScroll(int Mouse, int CellHit, Grids::TGridDrawInfo &DrawInfo, Grids::TGridAxisDrawInfo &Axis, int Scrollbar, const Types::TPoint &MousePt);
	void __fastcall MoveCurrent(int ACol, int ARow, bool MoveAnchor, bool Show);
	void __fastcall MoveTopLeft(int ALeft, int ATop);
	virtual void __fastcall ResizeCol(int Index, int OldSize, int NewSize);
	virtual void __fastcall ResizeRow(int Index, int OldSize, int NewSize);
	void __fastcall SelectionMoved(const Grids::TGridRect &OldSel);
	void __fastcall ScrollDataInfo(int DX, int DY, Grids::TGridDrawInfo &DrawInfo);
	void __fastcall TopLeftMoved(const Grids::TGridCoord &OldTopLeft);
	void __fastcall UpdateScrollPos(void);
	void __fastcall UpdateScrollRange(void);
	int __fastcall GetColWidths(int Index);
	int __fastcall GetRowHeights(int Index);
	Grids::TGridRect __fastcall GetSelection();
	bool __fastcall GetTabStops(int Index);
	int __fastcall GetVisibleColCount(void);
	int __fastcall GetVisibleRowCount(void);
	bool __fastcall IsActiveControl(void);
	void __fastcall ReadColWidths(Classes::TReader* Reader);
	void __fastcall ReadRowHeights(Classes::TReader* Reader);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetCol(int Value);
	void __fastcall SetColCount(int Value);
	void __fastcall SetColWidths(int Index, int Value);
	void __fastcall SetDefaultColWidth(int Value);
	void __fastcall SetDefaultRowHeight(int Value);
	void __fastcall SetEditorMode(bool Value);
	void __fastcall SetFixedColor(Graphics::TColor Value);
	void __fastcall SetFixedCols(int Value);
	void __fastcall SetFixedRows(int Value);
	void __fastcall SetGridLineWidth(int Value);
	void __fastcall SetLeftCol(int Value);
	void __fastcall SetOptions(Grids::TGridOptions Value);
	void __fastcall SetRow(int Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetRowHeights(int Index, int Value);
	void __fastcall SetScrollBars(Stdctrls::TScrollStyle Value);
	void __fastcall SetSelection(const Grids::TGridRect &Value);
	void __fastcall SetTabStops(int Index, bool Value);
	void __fastcall SetTopRow(int Value);
	void __fastcall UpdateEdit(void);
	void __fastcall UpdateText(void);
	void __fastcall WriteColWidths(Classes::TWriter* Writer);
	void __fastcall WriteRowHeights(Classes::TWriter* Writer);
	MESSAGE void __fastcall CMCancelMode(Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Msg);
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMChar(Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall WMCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TWMScroll &Msg);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Msg);
	MESSAGE void __fastcall WMTimer(Messages::TWMTimer &Msg);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Msg);
	HIDESBASE virtual void __fastcall Paint(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	
protected:
	Grids::TGridState FGridState;
	bool FSaveCellExtents;
	Grids::TGridOptions DesignOptionsBoost;
	bool VirtualView;
	void __fastcall CalcDrawInfo(Grids::TGridDrawInfo &DrawInfo);
	void __fastcall CalcFixedInfo(Grids::TGridDrawInfo &DrawInfo);
	virtual void __fastcall CalcSizingState(int X, int Y, Grids::TGridState &State, int &Index, int &SizingPos, int &SizingOfs, Grids::TGridDrawInfo &FixedInfo);
	void __fastcall ChangeGridOrientation(bool RightToLeftOrientation);
	virtual TMyInplaceEdit* __fastcall CreateEditor(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	HIDESBASEDYNAMIC void __fastcall AdjustSize(int Index, int Amount, bool Rows);
	Types::TRect __fastcall BoxRect(int ALeft, int ATop, int ARight, int ABottom);
	DYNAMIC void __fastcall DoExit(void);
	Types::TRect __fastcall CellRect(int ACol, int ARow);
	DYNAMIC bool __fastcall CanEditAcceptKey(char Key);
	DYNAMIC bool __fastcall CanGridAcceptKey(Word Key, Classes::TShiftState Shift);
	DYNAMIC bool __fastcall CanEditModify(void);
	virtual bool __fastcall CanEditShow(void);
	void __fastcall FocusCell(int ACol, int ARow, bool MoveAnchor);
	DYNAMIC AnsiString __fastcall GetEditText(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const AnsiString Value);
	DYNAMIC int __fastcall GetEditLimit(void);
	DYNAMIC AnsiString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC Grids::TEditStyle __fastcall GetEditStyle(int ACol, int ARow);
	int __fastcall GetGridWidth(void);
	int __fastcall GetGridHeight(void);
	void __fastcall HideEdit(void);
	void __fastcall HideEditor(void);
	void __fastcall ShowEditor(void);
	void __fastcall ShowEditorChar(char Ch);
	void __fastcall InvalidateEditor(void);
	void __fastcall InvalidateGrid(void);
	void __fastcall MoveColumn(int FromIndex, int ToIndex);
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	void __fastcall MoveRow(int FromIndex, int ToIndex);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState) = 0 ;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall MoveColRow(int ACol, int ARow, bool MoveAnchor, bool Show);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	DYNAMIC void __fastcall SizeChanged(int OldColCount, int OldRowCount);
	bool __fastcall Sizing(int X, int Y);
	void __fastcall ScrollData(int DX, int DY);
	void __fastcall InvalidateCell(int ACol, int ARow);
	void __fastcall InvalidateCol(int ACol);
	void __fastcall InvalidateRow(int ARow);
	DYNAMIC void __fastcall TopLeftChanged(void);
	DYNAMIC void __fastcall TimedScroll(Grids::TGridScrollDirection Direction);
	DYNAMIC void __fastcall ColWidthsChanged(void);
	DYNAMIC void __fastcall RowHeightsChanged(void);
	virtual void __fastcall DeleteColumn(int ACol);
	virtual void __fastcall DeleteRow(int ARow);
	void __fastcall UpdateDesigner(void);
	DYNAMIC bool __fastcall BeginColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall BeginRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall CheckColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall CheckRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall EndColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall EndRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int Col = {read=FCurrent.X, write=SetCol, nodefault};
	__property Color  = {default=-2147483643};
	__property int ColCount = {read=FColCount, write=SetColCount, default=5};
	__property int ColWidths[int Index] = {read=GetColWidths, write=SetColWidths};
	__property int DefaultColWidth = {read=FDefaultColWidth, write=SetDefaultColWidth, default=64};
	__property bool DefaultDrawing = {read=FDefaultDrawing, write=FDefaultDrawing, default=1};
	__property int DefaultRowHeight = {read=FDefaultRowHeight, write=SetDefaultRowHeight, default=24};
	__property bool EditorMode = {read=FEditorMode, write=SetEditorMode, nodefault};
	__property Graphics::TColor FixedColor = {read=FFixedColor, write=SetFixedColor, default=-2147483633};
	__property int FixedCols = {read=FFixedCols, write=SetFixedCols, default=1};
	__property int FixedRows = {read=FFixedRows, write=SetFixedRows, default=1};
	__property int GridHeight = {read=GetGridHeight, nodefault};
	__property int GridLineWidth = {read=FGridLineWidth, write=SetGridLineWidth, default=1};
	__property int GridWidth = {read=GetGridWidth, nodefault};
	__property Types::TPoint HitTest = {read=FHitTest};
	__property TMyInplaceEdit* InplaceEditor = {read=FInplaceEdit};
	__property int LeftCol = {read=FTopLeft.X, write=SetLeftCol, nodefault};
	__property Grids::TGridOptions Options = {read=FOptions, write=SetOptions, default=31};
	__property ParentColor  = {default=0};
	__property int Row = {read=FCurrent.Y, write=SetRow, nodefault};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=5};
	__property int RowHeights[int Index] = {read=GetRowHeights, write=SetRowHeights};
	__property Stdctrls::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	__property Grids::TGridRect Selection = {read=GetSelection, write=SetSelection};
	__property bool TabStops[int Index] = {read=GetTabStops, write=SetTabStops};
	__property int TopRow = {read=FTopLeft.Y, write=SetTopRow, nodefault};
	__property int VisibleColCount = {read=GetVisibleColCount, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	
public:
	__fastcall virtual TMyCustomGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyCustomGrid(void);
	Grids::TGridCoord __fastcall MouseCoord(int X, int Y);
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMyCustomGrid(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TMyInplaceEdit : public Mask::TCustomMaskEdit 
{
	typedef Mask::TCustomMaskEdit inherited;
	
private:
	TMyCustomGrid* FGrid;
	int FClickTime;
	void __fastcall InternalMove(const Types::TRect &Loc, bool Redraw);
	void __fastcall SetGrid(TMyCustomGrid* Value);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPaste(void *Message);
	HIDESBASE MESSAGE void __fastcall WMCut(void *Message);
	MESSAGE void __fastcall WMClear(void *Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	virtual bool __fastcall EditCanModify(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall BoundsChanged(void);
	virtual void __fastcall UpdateContents(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property TMyCustomGrid* Grid = {read=FGrid};
	
public:
	__fastcall virtual TMyInplaceEdit(Classes::TComponent* AOwner);
	void __fastcall Deselect(void);
	HIDESBASE void __fastcall Hide(void);
	HIDESBASE void __fastcall Invalidate(void);
	void __fastcall Move(const Types::TRect &Loc);
	bool __fastcall PosEqual(const Types::TRect &Rect);
	HIDESBASE void __fastcall SetFocus(void);
	void __fastcall UpdateLoc(const Types::TRect &Loc);
	HIDESBASE bool __fastcall Visible(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMyInplaceEdit(HWND ParentWindow) : Mask::TCustomMaskEdit(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TMyInplaceEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMyCustomDrawGrid;
class PASCALIMPLEMENTATION TMyCustomDrawGrid : public TMyCustomGrid 
{
	typedef TMyCustomGrid inherited;
	
private:
	Grids::TMovedEvent FOnColumnMoved;
	Grids::TDrawCellEvent FOnDrawCell;
	Grids::TGetEditEvent FOnGetEditMask;
	Grids::TGetEditEvent FOnGetEditText;
	Grids::TMovedEvent FOnRowMoved;
	Grids::TSelectCellEvent FOnSelectCell;
	Grids::TSetEditEvent FOnSetEditText;
	Classes::TNotifyEvent FOnTopLeftChanged;
	
protected:
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	DYNAMIC AnsiString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC AnsiString __fastcall GetEditText(int ACol, int ARow);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const AnsiString Value);
	DYNAMIC void __fastcall TopLeftChanged(void);
	__property Grids::TMovedEvent OnColumnMoved = {read=FOnColumnMoved, write=FOnColumnMoved};
	__property Grids::TDrawCellEvent OnDrawCell = {read=FOnDrawCell, write=FOnDrawCell};
	__property Grids::TGetEditEvent OnGetEditMask = {read=FOnGetEditMask, write=FOnGetEditMask};
	__property Grids::TGetEditEvent OnGetEditText = {read=FOnGetEditText, write=FOnGetEditText};
	__property Grids::TMovedEvent OnRowMoved = {read=FOnRowMoved, write=FOnRowMoved};
	__property Grids::TSelectCellEvent OnSelectCell = {read=FOnSelectCell, write=FOnSelectCell};
	__property Grids::TSetEditEvent OnSetEditText = {read=FOnSetEditText, write=FOnSetEditText};
	__property Classes::TNotifyEvent OnTopLeftChanged = {read=FOnTopLeftChanged, write=FOnTopLeftChanged};
	
public:
	HIDESBASE Types::TRect __fastcall CellRect(int ACol, int ARow);
	void __fastcall MouseToCell(int X, int Y, int &ACol, int &ARow);
	__property Canvas ;
	__property Col ;
	__property ColWidths ;
	__property EditorMode ;
	__property GridHeight ;
	__property GridWidth ;
	__property LeftCol ;
	__property Selection ;
	__property Row ;
	__property RowHeights ;
	__property TabStops ;
	__property TopRow ;
public:
	#pragma option push -w-inl
	/* TMyCustomGrid.Create */ inline __fastcall virtual TMyCustomDrawGrid(Classes::TComponent* AOwner) : TMyCustomGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMyCustomGrid.Destroy */ inline __fastcall virtual ~TMyCustomDrawGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMyCustomDrawGrid(HWND ParentWindow) : TMyCustomGrid(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TMyDrawGrid;
class PASCALIMPLEMENTATION TMyDrawGrid : public TMyCustomDrawGrid 
{
	typedef TMyCustomDrawGrid inherited;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property ColCount  = {default=5};
	__property Constraints ;
	__property Ctl3D ;
	__property DefaultColWidth  = {default=64};
	__property DefaultRowHeight  = {default=24};
	__property DefaultDrawing  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2147483633};
	__property FixedCols  = {default=1};
	__property RowCount  = {default=5};
	__property FixedRows  = {default=1};
	__property Font ;
	__property GridLineWidth  = {default=1};
	__property Options  = {default=31};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property Visible  = {default=1};
	__property VisibleColCount ;
	__property VisibleRowCount ;
	__property OnClick ;
	__property OnColumnMoved ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawCell ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetEditMask ;
	__property OnGetEditText ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnRowMoved ;
	__property OnSelectCell ;
	__property OnSetEditText ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnTopLeftChanged ;
public:
	#pragma option push -w-inl
	/* TMyCustomGrid.Create */ inline __fastcall virtual TMyDrawGrid(Classes::TComponent* AOwner) : TMyCustomDrawGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMyCustomGrid.Destroy */ inline __fastcall virtual ~TMyDrawGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMyDrawGrid(HWND ParentWindow) : TMyCustomDrawGrid(ParentWindow) { }
	#pragma option pop
	
};


typedef int __fastcall (*TSPAApply)(int TheIndex, void * TheItem);

typedef int __fastcall (__closure *TMyFunc)(int Col, int Row, void * TheItem);

typedef void *TSecDir[4096];

typedef void * *PSecDir;

#pragma option push -b-
enum TSPAQuantum { SPASmall, SPALarge };
#pragma option pop

class DELPHICLASS TSparsePointerArray;
class PASCALIMPLEMENTATION TSparsePointerArray : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void * operator[](int Index) { return Items[Index]; }
	
private:
	void * *secDir;
	Word slotsInDir;
	Word indexMask;
	Word secShift;
	int FHighBound;
	Word FSectionSize;
	int cachedIndex;
	void *cachedPointer;
	void * __fastcall GetAt(int Index);
	PPointer __fastcall MakeAt(int Index);
	void __fastcall PutAt(int Index, void * Item);
	
public:
	__fastcall TSparsePointerArray(TSPAQuantum Quantum);
	__fastcall virtual ~TSparsePointerArray(void);
	int __fastcall ForAll(void * ApplyFunction);
	int __fastcall SForAll(const Types::TRect &rect, TMyFunc Func);
	int __fastcall CForAll(int min, int max, int Row, TMyFunc ApplyFunction);
	void __fastcall ResetHighBound(void);
	__property int HighBound = {read=FHighBound, nodefault};
	__property Word SectionSize = {read=FSectionSize, nodefault};
	__property void * Items[int Index] = {read=GetAt, write=PutAt/*, default*/};
};


class DELPHICLASS TSparseList;
class PASCALIMPLEMENTATION TSparseList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void * operator[](int Index) { return Items[Index]; }
	
private:
	TSparsePointerArray* FList;
	int FCount;
	TSPAQuantum FQuantum;
	void __fastcall NewList(TSPAQuantum Quantum);
	
protected:
	void * __fastcall Get(int Index);
	void __fastcall Put(int Index, void * Item);
	
public:
	__fastcall TSparseList(TSPAQuantum Quantum);
	__fastcall virtual ~TSparseList(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Exchange(int Index1, int Index2);
	int __fastcall ForAll(void * ApplyFunction);
	int __fastcall SForAll(const Types::TRect &rect, TMyFunc Func);
	int __fastcall CForAll(int min, int max, int Row, TMyFunc ApplyFunction);
	void __fastcall Insert(int Index, void * Item);
	void __fastcall Move(int CurIndex, int NewIndex);
	__property int Count = {read=FCount, nodefault};
	__property void * Items[int Index] = {read=Get, write=Put/*, default*/};
};


typedef int TIntArray[134217728];

typedef int *PIntArray;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Byte SPAIndexMask[2];
extern PACKAGE Byte SPASecShift[2];
extern PACKAGE AnsiString __fastcall IntToBin(unsigned Value);
extern PACKAGE void __fastcall FillDWord(void *Dest, int Count, int Value);
extern PACKAGE void * __fastcall StackAlloc(int Size);
extern PACKAGE void __fastcall StackFree(void * P);

}	/* namespace Gridroutineu */
using namespace Gridroutineu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GridRoutineU
