// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClassPas.pas' rev: 6.00

#ifndef ClassPasHPP
#define ClassPasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include "compat/vcl_qt.h"
#include <Mask.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Classpas
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
	Grids::TGridCoord  CalcCoordFromPoint(int X, int Y, const Grids::TGridDrawInfo &DrawInfo);
	void  CalcDrawInfoXY(Grids::TGridDrawInfo &DrawInfo, int UseWidth, int UseHeight);
	Grids::TGridCoord  CalcMaxTopLeft(const Grids::TGridCoord &Coord, const Grids::TGridDrawInfo &DrawInfo);
	void  CancelMode(void);
	void  ChangeSize(int NewColCount, int NewRowCount);
	void  ClampInView(const Grids::TGridCoord &Coord);
	void  DrawSizingLine(const Grids::TGridDrawInfo &DrawInfo);
	void  DrawMove(void);
	void  GridRectToScreenRect(const Grids::TGridRect &GridRect, Types::TRect &ScreenRect, bool IncludeLine);
	void  Initialize(void);
	void  InvalidateRect(const Grids::TGridRect &ARect);
	virtual void  ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft);
	void  MoveAdjust(int &CellPos, int FromIndex, int ToIndex);
	void  MoveAnchor(const Grids::TGridCoord &NewAnchor);
	void  MoveAndScroll(int Mouse, int CellHit, Grids::TGridDrawInfo &DrawInfo, Grids::TGridAxisDrawInfo &Axis, int Scrollbar, const Types::TPoint &MousePt);
	void  MoveCurrent(int ACol, int ARow, bool MoveAnchor, bool Show);
	void  MoveTopLeft(int ALeft, int ATop);
	void  ResizeCol(int Index, int OldSize, int NewSize);
	void  ResizeRow(int Index, int OldSize, int NewSize);
	void  SelectionMoved(const Grids::TGridRect &OldSel);
	void  ScrollDataInfo(int DX, int DY, Grids::TGridDrawInfo &DrawInfo);
	void  TopLeftMoved(const Grids::TGridCoord &OldTopLeft);
	void  UpdateScrollPos(void);
	void  UpdateScrollRange(void);
	int  GetColWidths(int Index);
	int  GetRowHeights(int Index);
	Grids::TGridRect  GetSelection();
	bool  GetTabStops(int Index);
	int  GetVisibleColCount(void);
	int  GetVisibleRowCount(void);
	bool  IsActiveControl(void);
	void  ReadColWidths(Classes::TReader* Reader);
	void  ReadRowHeights(Classes::TReader* Reader);
	void  SetBorderStyle(Forms::TBorderStyle Value);
	void  SetCol(int Value);
	void  SetColCount(int Value);
	void  SetColWidths(int Index, int Value);
	void  SetDefaultColWidth(int Value);
	void  SetDefaultRowHeight(int Value);
	void  SetEditorMode(bool Value);
	void  SetFixedColor(Graphics::TColor Value);
	void  SetFixedCols(int Value);
	void  SetFixedRows(int Value);
	void  SetGridLineWidth(int Value);
	void  SetLeftCol(int Value);
	void  SetOptions(Grids::TGridOptions Value);
	void  SetRow(int Value);
	void  SetRowCount(int Value);
	void  SetRowHeights(int Index, int Value);
	void  SetScrollBars(Stdctrls::TScrollStyle Value);
	void  SetSelection(const Grids::TGridRect &Value);
	void  SetTabStops(int Index, bool Value);
	void  SetTopRow(int Value);
	void  UpdateEdit(void);
	void  UpdateText(void);
	void  WriteColWidths(Classes::TWriter* Writer);
	void  WriteRowHeights(Classes::TWriter* Writer);
	MESSAGE void  CMCancelMode(Messages::TMessage &Msg);
	HIDESBASE MESSAGE void  CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMDesignHitTest(Messages::TWMMouse &Msg);
	MESSAGE void  CMWantSpecialKey(Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void  CMShowingChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  WMChar(Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void  WMCancelMode(Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void  WMCommand(Messages::TWMCommand &Message);
	MESSAGE void  WMGetDlgCode(Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void  WMHScroll(Messages::TWMScroll &Msg);
	HIDESBASE MESSAGE void  WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void  WMLButtonDown(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  WMNCHitTest(Messages::TWMNCHitTest &Msg);
	HIDESBASE MESSAGE void  WMSetCursor(Messages::TWMSetCursor &Msg);
	HIDESBASE MESSAGE void  WMSetFocus(Messages::TWMSetFocus &Msg);
	HIDESBASE MESSAGE void  WMSize(Messages::TWMSize &Msg);
	MESSAGE void  WMTimer(Messages::TWMTimer &Msg);
	HIDESBASE MESSAGE void  WMVScroll(Messages::TWMScroll &Msg);
	HIDESBASE virtual void  Paint(void);
	DYNAMIC bool  DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool  DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC void  KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void  KeyPress(char &Key);
	
protected:
	Grids::TGridState FGridState;
	bool FSaveCellExtents;
	Grids::TGridOptions DesignOptionsBoost;
	bool VirtualView;
	void  CalcDrawInfo(Grids::TGridDrawInfo &DrawInfo);
	void  CalcFixedInfo(Grids::TGridDrawInfo &DrawInfo);
	virtual void  CalcSizingState(int X, int Y, Grids::TGridState &State, int &Index, int &SizingPos, int &SizingOfs, Grids::TGridDrawInfo &FixedInfo);
	void  ChangeGridOrientation(bool RightToLeftOrientation);
	virtual TMyInplaceEdit*  CreateEditor(void);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void  MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void  MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void  MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	HIDESBASEDYNAMIC void  AdjustSize(int Index, int Amount, bool Rows);
	Types::TRect  BoxRect(int ALeft, int ATop, int ARight, int ABottom);
	DYNAMIC void  DoExit(void);
	Types::TRect  CellRect(int ACol, int ARow);
	DYNAMIC bool  CanEditAcceptKey(char Key);
	DYNAMIC bool  CanGridAcceptKey(Word Key, Classes::TShiftState Shift);
	DYNAMIC bool  CanEditModify(void);
	virtual bool  CanEditShow(void);
	void  FocusCell(int ACol, int ARow, bool MoveAnchor);
	DYNAMIC AnsiString  GetEditText(int ACol, int ARow);
	DYNAMIC void  SetEditText(int ACol, int ARow, const AnsiString Value);
	DYNAMIC int  GetEditLimit(void);
	DYNAMIC AnsiString  GetEditMask(int ACol, int ARow);
	DYNAMIC Grids::TEditStyle  GetEditStyle(int ACol, int ARow);
	int  GetGridWidth(void);
	int  GetGridHeight(void);
	void  HideEdit(void);
	void  HideEditor(void);
	void  ShowEditor(void);
	void  ShowEditorChar(char Ch);
	void  InvalidateEditor(void);
	void  InvalidateGrid(void);
	void  MoveColumn(int FromIndex, int ToIndex);
	DYNAMIC void  ColumnMoved(int FromIndex, int ToIndex);
	void  MoveRow(int FromIndex, int ToIndex);
	DYNAMIC void  RowMoved(int FromIndex, int ToIndex);
	virtual void  DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState) = 0 ;
	virtual void  DefineProperties(Classes::TFiler* Filer);
	void  MoveColRow(int ACol, int ARow, bool MoveAnchor, bool Show);
	virtual bool  SelectCell(int ACol, int ARow);
	DYNAMIC void  SizeChanged(int OldColCount, int OldRowCount);
	bool  Sizing(int X, int Y);
	void  ScrollData(int DX, int DY);
	void  InvalidateCell(int ACol, int ARow);
	void  InvalidateCol(int ACol);
	void  InvalidateRow(int ARow);
	DYNAMIC void  TopLeftChanged(void);
	DYNAMIC void  TimedScroll(Grids::TGridScrollDirection Direction);
	DYNAMIC void  ColWidthsChanged(void);
	DYNAMIC void  RowHeightsChanged(void);
	virtual void  DeleteColumn(int ACol);
	virtual void  DeleteRow(int ARow);
	void  UpdateDesigner(void);
	DYNAMIC bool  BeginColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool  BeginRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool  CheckColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool  CheckRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool  EndColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool  EndRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int Col = {read=FCurrent.X, write=SetCol, nodefault};
	__property Color  = {default=-2147483643};
	__property int ColCount = {read=FColCount, write=SetColCount, default=5};
// [indexed property - needs manual migration]: 	__property int ColWidths[int Index] = {read=GetColWidths, write=SetColWidths};
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
	// __property Types::TPoint HitTest {read=FHitTest}; // [manual migration needed]
	// __property TMyInplaceEdit* InplaceEditor {read=FInplaceEdit}; // [manual migration needed]
	__property int LeftCol = {read=FTopLeft.X, write=SetLeftCol, nodefault};
	__property Grids::TGridOptions Options = {read=FOptions, write=SetOptions, default=31};
	__property ParentColor  = {default=0};
	__property int Row = {read=FCurrent.Y, write=SetRow, nodefault};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=5};
// [indexed property - needs manual migration]: 	__property int RowHeights[int Index] = {read=GetRowHeights, write=SetRowHeights};
	__property Stdctrls::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	// __property Grids::TGridRect Selection {read=GetSelection, write=SetSelection}; // [manual migration needed]
// [indexed property - needs manual migration]: 	__property bool TabStops[int Index] = {read=GetTabStops, write=SetTabStops};
	__property int TopRow = {read=FTopLeft.Y, write=SetTopRow, nodefault};
	__property int VisibleColCount = {read=GetVisibleColCount, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	
public:
	 virtual TMyCustomGrid(Classes::TComponent* AOwner);
	 virtual ~TMyCustomGrid(void);
	Grids::TGridCoord  MouseCoord(int X, int Y);
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMyCustomGrid(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TMyInplaceEdit : public Mask::TCustomMaskEdit 
{
	typedef Mask::TCustomMaskEdit inherited;
	
private:
	TMyCustomGrid* FGrid;
	int FClickTime;
	void  InternalMove(const Types::TRect &Loc, bool Redraw);
	void  SetGrid(TMyCustomGrid* Value);
	HIDESBASE MESSAGE void  CMShowingChanged(Messages::TMessage &Message);
	MESSAGE void  WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void  WMPaste(void *Message);
	HIDESBASE MESSAGE void  WMCut(void *Message);
	MESSAGE void  WMClear(void *Message);
	
protected:
	virtual void  CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void  DblClick(void);
	DYNAMIC bool  DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	virtual bool  EditCanModify(void);
	DYNAMIC void  KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void  KeyPress(char &Key);
	DYNAMIC void  KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void  BoundsChanged(void);
	virtual void  UpdateContents(void);
	virtual void  WndProc(Messages::TMessage &Message);
	// __property TMyCustomGrid* Grid {read=FGrid}; // [manual migration needed]
	
public:
	 virtual TMyInplaceEdit(Classes::TComponent* AOwner);
	void  Deselect(void);
	HIDESBASE void  Hide(void);
	HIDESBASE void  Invalidate(void);
	void  Move(const Types::TRect &Loc);
	bool  PosEqual(const Types::TRect &Rect);
	HIDESBASE void  SetFocus(void);
	void  UpdateLoc(const Types::TRect &Loc);
	HIDESBASE bool  Visible(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMyInplaceEdit(HWND ParentWindow) : Mask::TCustomMaskEdit(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TMyInplaceEdit(void) { }
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
	DYNAMIC void  ColumnMoved(int FromIndex, int ToIndex);
	virtual void  DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	DYNAMIC AnsiString  GetEditMask(int ACol, int ARow);
	DYNAMIC AnsiString  GetEditText(int ACol, int ARow);
	DYNAMIC void  RowMoved(int FromIndex, int ToIndex);
	virtual bool  SelectCell(int ACol, int ARow);
	DYNAMIC void  SetEditText(int ACol, int ARow, const AnsiString Value);
	DYNAMIC void  TopLeftChanged(void);
	// __property Grids::TMovedEvent OnColumnMoved {read=FOnColumnMoved, write=FOnColumnMoved}; // [manual migration needed]
	// __property Grids::TDrawCellEvent OnDrawCell {read=FOnDrawCell, write=FOnDrawCell}; // [manual migration needed]
	// __property Grids::TGetEditEvent OnGetEditMask {read=FOnGetEditMask, write=FOnGetEditMask}; // [manual migration needed]
	// __property Grids::TGetEditEvent OnGetEditText {read=FOnGetEditText, write=FOnGetEditText}; // [manual migration needed]
	// __property Grids::TMovedEvent OnRowMoved {read=FOnRowMoved, write=FOnRowMoved}; // [manual migration needed]
	// __property Grids::TSelectCellEvent OnSelectCell {read=FOnSelectCell, write=FOnSelectCell}; // [manual migration needed]
	// __property Grids::TSetEditEvent OnSetEditText {read=FOnSetEditText, write=FOnSetEditText}; // [manual migration needed]
	// __property Classes::TNotifyEvent OnTopLeftChanged {read=FOnTopLeftChanged, write=FOnTopLeftChanged}; // [manual migration needed]
	
public:
	HIDESBASE Types::TRect  CellRect(int ACol, int ARow);
	void  MouseToCell(int X, int Y, int &ACol, int &ARow);
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
	/* TMyCustomGrid.Create */ inline  virtual TMyCustomDrawGrid(Classes::TComponent* AOwner) : TMyCustomGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMyCustomGrid.Destroy */ inline  virtual ~TMyCustomDrawGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMyCustomDrawGrid(HWND ParentWindow) : TMyCustomGrid(ParentWindow) { }
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
	/* TMyCustomGrid.Create */ inline  virtual TMyDrawGrid(Classes::TComponent* AOwner) : TMyCustomDrawGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMyCustomGrid.Destroy */ inline  virtual ~TMyDrawGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMyDrawGrid(HWND ParentWindow) : TMyCustomDrawGrid(ParentWindow) { }
	#pragma option pop
	
};


typedef int  (*TSPAApply)(int TheIndex, void * TheItem);

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
	void *  GetAt(int Index);
	PPointer  MakeAt(int Index);
	void  PutAt(int Index, void * Item);
	
public:
	 TSparsePointerArray(TSPAQuantum Quantum);
	 virtual ~TSparsePointerArray(void);
	int  ForAll(void * ApplyFunction);
	void  ResetHighBound(void);
	__property int HighBound = {read=FHighBound, nodefault};
	__property Word SectionSize = {read=FSectionSize, nodefault};
// [indexed property - needs manual migration]: 	__property void * Items[int Index] = {read=GetAt, write=PutAt/*, default*/};
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
	void  NewList(TSPAQuantum Quantum);
	
protected:
	void *  Get(int Index);
	void  Put(int Index, void * Item);
	
public:
	 TSparseList(TSPAQuantum Quantum);
	 virtual ~TSparseList(void);
	void  Clear(void);
	void  Delete(int Index);
	void  Exchange(int Index1, int Index2);
	int  ForAll(void * ApplyFunction);
	void  Insert(int Index, void * Item);
	void  Move(int CurIndex, int NewIndex);
	__property int Count = {read=FCount, nodefault};
// [indexed property - needs manual migration]: 	__property void * Items[int Index] = {read=Get, write=Put/*, default*/};
};


typedef int TIntArray[134217728];

typedef int *PIntArray;

//-- var, const, procedure ---------------------------------------------------
extern  Byte SPAIndexMask[2];
extern  Byte SPASecShift[2];
extern  void  FillDWord(void *Dest, int Count, int Value);
extern  void *  StackAlloc(int Size);
extern  void  StackFree(void * P);

}	/* namespace Classpas */
using namespace Classpas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClassPas
