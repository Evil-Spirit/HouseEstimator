// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ColorComboBoxRoutineU.pas' rev: 6.00

#ifndef ColorComboBoxRoutineUHPP
#define ColorComboBoxRoutineUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include "compat/vcl_qt.h"
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Colorcomboboxroutineu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomGroupBox;
class PASCALIMPLEMENTATION TCustomGroupBox : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	HIDESBASE MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void  CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  WMSize(Messages::TMessage &Message);
	
protected:
	virtual void  AdjustClientRect(Types::TRect &Rect);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  Paint(void);
	
public:
	 virtual TCustomGroupBox(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline  virtual ~TCustomGroupBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomGroupBox(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TGroupBox;
class PASCALIMPLEMENTATION TGroupBox : public TCustomGroupBox 
{
	typedef TCustomGroupBox inherited;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DockSite  = {default=0};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TCustomGroupBox.Create */ inline  virtual TGroupBox(Classes::TComponent* AOwner) : TCustomGroupBox(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline  virtual ~TGroupBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TGroupBox(HWND ParentWindow) : TCustomGroupBox(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTextLayout { tlTop, tlCenter, tlBottom };
#pragma option pop

class DELPHICLASS TCustomLabel;
class PASCALIMPLEMENTATION TCustomLabel : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	Controls::TWinControl* FFocusControl;
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	TTextLayout FLayout;
	bool FWordWrap;
	bool FShowAccelChar;
	Classes::TNotifyEvent FOnMouseLeave;
	Classes::TNotifyEvent FOnMouseEnter;
	bool  GetTransparent(void);
	void  SetAlignment(Classes::TAlignment Value);
	void  SetFocusControl(Controls::TWinControl* Value);
	void  SetShowAccelChar(bool Value);
	void  SetTransparent(bool Value);
	void  SetLayout(TTextLayout Value);
	void  SetWordWrap(bool Value);
	MESSAGE void  CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMFontChanged(Messages::TMessage &Message);
	MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void  CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMMouseLeave(Messages::TMessage &Message);
	
protected:
	DYNAMIC void  AdjustBounds(void);
	DYNAMIC void  DoDrawText(Types::TRect &Rect, int Flags);
	virtual AnsiString  GetLabelText();
	virtual void  Loaded(void);
	virtual void  Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void  Paint(void);
	virtual void  SetAutoSize(bool Value);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	// __property Controls::TWinControl* FocusControl {read=FFocusControl, write=SetFocusControl}; // [manual migration needed]
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, default=0};
	__property TTextLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
	
public:
	 virtual TCustomLabel(Classes::TComponent* AOwner);
	__property Caption ;
	__property Canvas ;
	// __property Classes::TNotifyEvent OnMouseEnter {read=FOnMouseEnter, write=FOnMouseEnter}; // [manual migration needed]
	// __property Classes::TNotifyEvent OnMouseLeave {read=FOnMouseLeave, write=FOnMouseLeave}; // [manual migration needed]
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline  virtual ~TCustomLabel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLabel;
class PASCALIMPLEMENTATION TLabel : public TCustomLabel 
{
	typedef TCustomLabel inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=1};
	__property BiDiMode ;
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FocusControl ;
	__property Font ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowAccelChar  = {default=1};
	__property ShowHint ;
	__property Transparent  = {default=0};
	__property Layout  = {default=0};
	__property Visible  = {default=1};
	__property WordWrap  = {default=0};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomLabel.Create */ inline  virtual TLabel(Classes::TComponent* AOwner) : TCustomLabel(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline  virtual ~TLabel(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEditCharCase { ecNormal, ecUpperCase, ecLowerCase };
#pragma option pop

class DELPHICLASS TCustomEdit;
class PASCALIMPLEMENTATION TCustomEdit : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	int FMaxLength;
	Forms::TFormBorderStyle FBorderStyle;
	char FPasswordChar;
	bool FReadOnly;
	bool FAutoSize;
	bool FAutoSelect;
	bool FHideSelection;
	bool FOEMConvert;
	TEditCharCase FCharCase;
	bool FCreating;
	bool FModified;
	Classes::TNotifyEvent FOnChange;
	void  AdjustHeight(void);
	bool  GetModified(void);
	bool  GetCanUndo(void);
	void  SetBorderStyle(Forms::TBorderStyle Value);
	void  SetCharCase(TEditCharCase Value);
	void  SetHideSelection(bool Value);
	void  SetMaxLength(int Value);
	void  SetModified(bool Value);
	void  SetOEMConvert(bool Value);
	void  SetPasswordChar(char Value);
	void  SetReadOnly(bool Value);
	void  SetSelText(const AnsiString Value);
	void  UpdateHeight(void);
	MESSAGE void  WMSetFont(Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void  CMFontChanged(Messages::TMessage &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	MESSAGE void  CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  WMContextMenu(Messages::TWMContextMenu &Message);
	
protected:
	DYNAMIC void  Change(void);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWindowHandle(const Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	virtual void  DestroyWnd(void);
	virtual void  DoSetMaxLength(int Value);
	virtual int  GetSelLength(void);
	virtual int  GetSelStart(void);
	virtual AnsiString  GetSelText();
	virtual void  SetAutoSize(bool Value);
	virtual void  SetSelLength(int Value);
	virtual void  SetSelStart(int Value);
	__property bool AutoSelect = {read=FAutoSelect, write=FAutoSelect, default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=0};
	__property bool OEMConvert = {read=FOEMConvert, write=SetOEMConvert, default=0};
	__property char PasswordChar = {read=FPasswordChar, write=SetPasswordChar, default=0};
	__property ParentColor  = {default=0};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	// __property Classes::TNotifyEvent OnChange {read=FOnChange, write=FOnChange}; // [manual migration needed]
	
public:
	 virtual TCustomEdit(Classes::TComponent* AOwner);
	virtual void  Clear(void);
	void  ClearSelection(void);
	void  CopyToClipboard(void);
	void  CutToClipboard(void);
	virtual void  DefaultHandler(void *Message);
	void  PasteFromClipboard(void);
	void  Undo(void);
	void  ClearUndo(void);
	virtual int  GetSelTextBuf(char * Buffer, int BufSize);
	void  SelectAll(void);
	void  SetSelTextBuf(char * Buffer);
	__property bool CanUndo = {read=GetCanUndo, nodefault};
	__property bool Modified = {read=GetModified, write=SetModified, nodefault};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	// __property AnsiString SelText {read=GetSelText, write=SetSelText}; // [manual migration needed]
	__property Text ;
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomEdit(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TCustomEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEdit;
class PASCALIMPLEMENTATION TEdit : public TCustomEdit 
{
	typedef TCustomEdit inherited;
	
__published:
	__property Anchors  = {default=3};
	__property AutoSelect  = {default=1};
	__property AutoSize  = {default=1};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property CharCase  = {default=0};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HideSelection  = {default=1};
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property MaxLength  = {default=0};
	__property OEMConvert  = {default=0};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PasswordChar  = {default=0};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Text ;
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TCustomEdit.Create */ inline  virtual TEdit(Classes::TComponent* AOwner) : TCustomEdit(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TEdit(HWND ParentWindow) : TCustomEdit(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TEdit(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TScrollStyle { ssNone, ssHorizontal, ssVertical, ssBoth };
#pragma option pop

class DELPHICLASS TCustomMemo;
class PASCALIMPLEMENTATION TCustomMemo : public TCustomEdit 
{
	typedef TCustomEdit inherited;
	
private:
	Classes::TStrings* FLines;
	Classes::TAlignment FAlignment;
	TScrollStyle FScrollBars;
	bool FWordWrap;
	bool FWantReturns;
	bool FWantTabs;
	MESSAGE void  WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void  WMNCDestroy(Messages::TWMNoParams &Message);
	
protected:
	virtual Types::TPoint  GetCaretPos();
	virtual void  SetCaretPos(const Types::TPoint &Value);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWindowHandle(const Controls::TCreateParams &Params);
	DYNAMIC void  KeyPress(char &Key);
	virtual void  Loaded(void);
	void  SetAlignment(Classes::TAlignment Value);
	void  SetLines(Classes::TStrings* Value);
	void  SetScrollBars(TScrollStyle Value);
	void  SetWordWrap(bool Value);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=0};
	__property bool WantReturns = {read=FWantReturns, write=FWantReturns, default=1};
	__property bool WantTabs = {read=FWantTabs, write=FWantTabs, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=1};
	
public:
	 virtual TCustomMemo(Classes::TComponent* AOwner);
	 virtual ~TCustomMemo(void);
	DYNAMIC Classes::TAlignment  GetControlsAlignment(void);
	// __property Types::TPoint CaretPos {read=GetCaretPos, write=SetCaretPos}; // [manual migration needed]
	// __property Classes::TStrings* Lines {read=FLines, write=SetLines}; // [manual migration needed]
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomMemo(HWND ParentWindow) : TCustomEdit(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TMemo;
class PASCALIMPLEMENTATION TMemo : public TCustomMemo 
{
	typedef TCustomMemo inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HideSelection  = {default=1};
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property Lines ;
	__property MaxLength  = {default=0};
	__property OEMConvert  = {default=0};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ScrollBars  = {default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property WantReturns  = {default=1};
	__property WantTabs  = {default=0};
	__property WordWrap  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TCustomMemo.Create */ inline  virtual TMemo(Classes::TComponent* AOwner) : TCustomMemo(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMemo.Destroy */ inline  virtual ~TMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMemo(HWND ParentWindow) : TCustomMemo(ParentWindow) { }
	#pragma option pop
	
};


typedef void  ( *TDrawItemEvent)(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);

typedef void  ( *TMeasureItemEvent)(Controls::TWinControl* Control, int Index, int &Height);

class DELPHICLASS TCustomComboBoxStrings;
class DELPHICLASS TMyCustomCombo;
typedef TMetaClass*TCustomComboBoxStringsClass;

class PASCALIMPLEMENTATION TMyCustomCombo : public Controls::TCustomListControl 
{
	typedef Controls::TCustomListControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	int FMaxLength;
	int FDropDownCount;
	int FItemIndex;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnSelect;
	Classes::TNotifyEvent FOnDropDown;
	Classes::TNotifyEvent FOnCloseUp;
	int FItemHeight;
	Classes::TStrings* FItems;
	MESSAGE void  WMCreate(Messages::TWMCreate &Message);
	MESSAGE void  CMCancelMode(Controls::TCMCancelMode &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void  WMDrawItem(Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void  WMMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void  WMDeleteItem(Messages::TWMDeleteItem &Message);
	MESSAGE void  WMGetDlgCode(Messages::TWMNoParams &Message);
	
protected:
	HWND FEditHandle;
	HWND FListHandle;
	HWND FDropHandle;
	void *FEditInstance;
	void *FDefEditProc;
	void *FListInstance;
	void *FDefListProc;
	bool FDroppingDown;
	bool FFocusChanged;
	bool FIsFocused;
	int FSaveIndex;
	virtual void  AdjustDropDown(void);
	virtual void  ComboWndProc(Messages::TMessage &Message, HWND ComboWnd, void * ComboProc);
	virtual void  CreateWnd(void);
	void  EditWndProc(Messages::TMessage &Message);
	virtual TMetaClass*  GetItemsClass(void) = 0 ;
	virtual void  WndProc(Messages::TMessage &Message);
	virtual int  GetItemHt(void) = 0 ;
	virtual void  SetItemHeight(int Value);
	virtual int  GetCount(void);
	virtual int  GetItemCount(void) = 0 ;
	virtual int  GetItemIndex(void);
	bool  GetDroppedDown(void);
	int  GetSelLength(void);
	int  GetSelStart(void);
	void  ListWndProc(Messages::TMessage &Message);
	virtual void  Loaded(void);
	DYNAMIC void  Change(void);
	DYNAMIC void  Select(void);
	DYNAMIC void  DropDown(void);
	DYNAMIC void  CloseUp(void);
	virtual void  DestroyWindowHandle(void);
	void  SetDroppedDown(bool Value);
	void  SetSelLength(int Value);
	void  SetSelStart(int Value);
	void  SetMaxLength(int Value);
	virtual void  SetDropDownCount(const int Value);
	virtual void  SetItemIndex(const int Value)/* overload */;
	virtual void  SetItems(const Classes::TStrings* Value);
	__property int DropDownCount = {read=FDropDownCount, write=SetDropDownCount, default=8};
	__property HWND EditHandle = {read=FEditHandle, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int ItemHeight = {read=GetItemHt, write=SetItemHeight, nodefault};
	__property HWND ListHandle = {read=FListHandle, nodefault};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=0};
	__property ParentColor  = {default=0};
	// __property Classes::TNotifyEvent OnChange {read=FOnChange, write=FOnChange}; // [manual migration needed]
	// __property Classes::TNotifyEvent OnDropDown {read=FOnDropDown, write=FOnDropDown}; // [manual migration needed]
	// __property Classes::TNotifyEvent OnSelect {read=FOnSelect, write=FOnSelect}; // [manual migration needed]
	// __property Classes::TNotifyEvent OnCloseUp {read=FOnCloseUp, write=FOnCloseUp}; // [manual migration needed]
	
public:
	 virtual TMyCustomCombo(Classes::TComponent* AOwner);
	 virtual ~TMyCustomCombo(void);
	virtual void  AddItem(AnsiString Item, System::TObject* AObject);
	virtual void  Clear(void);
	virtual void  ClearSelection(void);
	virtual void  CopySelection(Controls::TCustomListControl* Destination);
	virtual void  DeleteSelected(void);
	DYNAMIC bool  Focused(void);
	virtual void  SelectAll(void);
	// __property Graphics::TCanvas* Canvas {read=FCanvas}; // [manual migration needed]
	__property bool DroppedDown = {read=GetDroppedDown, write=SetDroppedDown, nodefault};
	// __property Classes::TStrings* Items {read=FItems, write=SetItems}; // [manual migration needed]
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TMyCustomCombo(HWND ParentWindow) : Controls::TCustomListControl(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomComboBoxStrings : public Classes::TStrings 
{
	typedef Classes::TStrings inherited;
	
private:
	TMyCustomCombo* FComboBox;
	
protected:
	virtual int  GetCount(void);
	virtual AnsiString  Get(int Index);
	virtual System::TObject*  GetObject(int Index);
	virtual void  PutObject(int Index, System::TObject* AObject);
	virtual void  SetUpdateState(bool Updating);
	// __property TMyCustomCombo* ComboBox {read=FComboBox, write=FComboBox}; // [manual migration needed]
	
public:
	virtual void  Clear(void);
	virtual void  Delete(int Index);
	virtual int  IndexOf(const AnsiString S);
public:
	#pragma option push -w-inl
	/* TStrings.Destroy */ inline  virtual ~TCustomComboBoxStrings(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline  TCustomComboBoxStrings(void) : Classes::TStrings() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TComboBoxStyle { csDropDown, csSimple, csDropDownList, csOwnerDrawFixed, csOwnerDrawVariable };
#pragma option pop

class DELPHICLASS TCustomComboBox;
class PASCALIMPLEMENTATION TCustomComboBox : public TMyCustomCombo 
{
	typedef TMyCustomCombo inherited;
	
private:
	bool FAutoComplete;
	bool FAutoDropDown;
	unsigned FLastTime;
	AnsiString FFilter;
	TEditCharCase FCharCase;
	bool FSorted;
	TComboBoxStyle FStyle;
	Classes::TStringList* FSaveItems;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	void  SetCharCase(TEditCharCase Value);
	void  SetSelText(const AnsiString Value);
	void  SetSorted(bool Value);
	HIDESBASE MESSAGE void  WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void  CMParentColorChanged(Messages::TMessage &Message);
	MESSAGE void  CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void  CNMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void  WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void  WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void  WMNCCalcSize(Messages::TWMNCCalcSize &Message);
	
protected:
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	virtual void  DestroyWnd(void);
	virtual void  DrawItem(int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	virtual int  GetItemHt(void);
	virtual TMetaClass*  GetItemsClass(void);
	AnsiString  GetSelText();
	DYNAMIC void  KeyPress(char &Key);
	virtual void  MeasureItem(int Index, int &Height);
	bool  SelectItem(const AnsiString AnItem);
	virtual void  SetStyle(TComboBoxStyle Value);
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	__property TComboBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	// __property TDrawItemEvent OnDrawItem {read=FOnDrawItem, write=FOnDrawItem}; // [manual migration needed]
	// __property TMeasureItemEvent OnMeasureItem {read=FOnMeasureItem, write=FOnMeasureItem}; // [manual migration needed]
	virtual void  WndProc(Messages::TMessage &Message);
	virtual int  GetItemCount(void);
	
public:
	 virtual TCustomComboBox(Classes::TComponent* AOwner);
	 virtual ~TCustomComboBox(void);
	__property bool AutoComplete = {read=FAutoComplete, write=FAutoComplete, default=1};
	__property bool AutoDropDown = {read=FAutoDropDown, write=FAutoDropDown, default=0};
	__property TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	// __property AnsiString SelText {read=GetSelText, write=SetSelText}; // [manual migration needed]
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomComboBox(HWND ParentWindow) : TMyCustomCombo(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TComboBox;
class PASCALIMPLEMENTATION TComboBox : public TCustomComboBox 
{
	typedef TCustomComboBox inherited;
	
__published:
	__property AutoComplete  = {default=1};
	__property AutoDropDown  = {default=0};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property Style  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property CharCase  = {default=0};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property DropDownCount  = {default=8};
	__property Enabled  = {default=1};
	__property Font ;
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property ItemHeight ;
	__property ItemIndex  = {default=-1};
	__property MaxLength  = {default=0};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Text ;
	__property Visible  = {default=1};
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
	__property Items ;
public:
	#pragma option push -w-inl
	/* TCustomComboBox.Create */ inline  virtual TComboBox(Classes::TComponent* AOwner) : TCustomComboBox(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomComboBox.Destroy */ inline  virtual ~TComboBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TComboBox(HWND ParentWindow) : TCustomComboBox(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TButtonActionLink;
class DELPHICLASS TButtonControl;
class PASCALIMPLEMENTATION TButtonControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FClicksDisabled;
	bool  IsCheckedStored(void);
	
protected:
	DYNAMIC void  ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC TMetaClass*  GetActionLinkClass(void);
	virtual bool  GetChecked(void);
	virtual void  SetChecked(bool Value);
	virtual void  WndProc(Messages::TMessage &Message);
	__property bool Checked = {read=GetChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property bool ClicksDisabled = {read=FClicksDisabled, write=FClicksDisabled, nodefault};
	
public:
	 virtual TButtonControl(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TButtonControl(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TButtonControl(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TButtonActionLink : public Controls::TWinControlActionLink 
{
	typedef Controls::TWinControlActionLink inherited;
	
protected:
	TButtonControl* FClient;
	virtual void  AssignClient(System::TObject* AClient);
	virtual bool  IsCheckedLinked(void);
	virtual void  SetChecked(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline  virtual TButtonActionLink(System::TObject* AClient) : Controls::TWinControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline  virtual ~TButtonActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TButtonActionLinkClass;

class DELPHICLASS TButton;
class PASCALIMPLEMENTATION TButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	bool FDefault;
	bool FCancel;
	bool FActive;
	Controls::TModalResult FModalResult;
	void  SetDefault(bool Value);
	HIDESBASE MESSAGE void  CMDialogKey(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void  CMFocusChanged(Controls::TCMFocusChanged &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void  WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	virtual void  SetButtonStyle(bool ADefault);
	
public:
	 virtual TButton(Classes::TComponent* AOwner);
	DYNAMIC void  Click(void);
	DYNAMIC bool  UseRightToLeftAlignment(void);
	
__published:
	__property Action ;
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property bool Cancel = {read=FCancel, write=FCancel, default=0};
	__property Caption ;
	__property Constraints ;
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Controls::TModalResult ModalResult = {read=FModalResult, write=FModalResult, default=0};
	__property ParentBiDiMode  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TButton(HWND ParentWindow) : TButtonControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCheckBoxState { cbUnchecked, cbChecked, cbGrayed };
#pragma option pop

class DELPHICLASS TCustomCheckBox;
class PASCALIMPLEMENTATION TCustomCheckBox : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAllowGrayed;
	TCheckBoxState FState;
	void  SetAlignment(Classes::TLeftRight Value);
	void  SetState(TCheckBoxState Value);
	HIDESBASE MESSAGE void  WMSize(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	
protected:
	virtual void  Toggle(void);
	DYNAMIC void  Click(void);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	virtual bool  GetChecked(void);
	virtual void  SetChecked(bool Value);
	__property Classes::TLeftRight Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, default=0};
	__property TCheckBoxState State = {read=FState, write=SetState, default=0};
	
public:
	 virtual TCustomCheckBox(Classes::TComponent* AOwner);
	DYNAMIC Classes::TAlignment  GetControlsAlignment(void);
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomCheckBox(HWND ParentWindow) : TButtonControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TCustomCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCheckBox;
class PASCALIMPLEMENTATION TCheckBox : public TCustomCheckBox 
{
	typedef TCustomCheckBox inherited;
	
__published:
	__property Action ;
	__property Alignment  = {default=1};
	__property AllowGrayed  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property Caption ;
	__property Checked  = {default=0};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property State  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TCustomCheckBox.Create */ inline  virtual TCheckBox(Classes::TComponent* AOwner) : TCustomCheckBox(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCheckBox(HWND ParentWindow) : TCustomCheckBox(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRadioButton;
class PASCALIMPLEMENTATION TRadioButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FChecked;
	void  SetAlignment(Classes::TLeftRight Value);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	
protected:
	virtual bool  GetChecked(void);
	virtual void  SetChecked(bool Value);
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	
public:
	 virtual TRadioButton(Classes::TComponent* AOwner);
	DYNAMIC Classes::TAlignment  GetControlsAlignment(void);
	
__published:
	__property Action ;
	__property Classes::TLeftRight Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property Caption ;
	__property Checked  = {default=0};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TRadioButton(HWND ParentWindow) : TButtonControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TRadioButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TListBoxStyle { lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable, lbVirtual, lbVirtualOwnerDraw };
#pragma option pop

typedef void  ( *TLBGetDataEvent)(Controls::TWinControl* Control, int Index, AnsiString &Data);

typedef void  ( *TLBGetDataObjectEvent)(Controls::TWinControl* Control, int Index, System::TObject* &DataObject);

typedef int  ( *TLBFindDataEvent)(Controls::TWinControl* Control, AnsiString FindString);

class DELPHICLASS TCustomListBox;
class PASCALIMPLEMENTATION TCustomListBox : public Controls::TCustomMultiSelectListControl 
{
	typedef Controls::TCustomMultiSelectListControl inherited;
	
private:
	bool FAutoComplete;
	int FCount;
	Classes::TStrings* FItems;
	AnsiString FFilter;
	unsigned FLastTime;
	Forms::TFormBorderStyle FBorderStyle;
	Graphics::TCanvas* FCanvas;
	int FColumns;
	int FItemHeight;
	int FOldCount;
	TListBoxStyle FStyle;
	bool FIntegralHeight;
	bool FSorted;
	bool FExtendedSelect;
	int FTabWidth;
	Classes::TStringList* FSaveItems;
	int FSaveTopIndex;
	int FSaveItemIndex;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	TLBGetDataEvent FOnData;
	TLBFindDataEvent FOnDataFind;
	TLBGetDataObjectEvent FOnDataObject;
	int  GetItemHeight(void);
	int  GetTopIndex(void);
	MESSAGE void  LBGetText(Messages::TMessage &Message);
	MESSAGE void  LBGetTextLen(Messages::TMessage &Message);
	void  SetBorderStyle(Forms::TBorderStyle Value);
	void  SetColumnWidth(void);
	void  SetColumns(int Value);
	void  SetCount(const int Value);
	void  SetExtendedSelect(bool Value);
	void  SetIntegralHeight(bool Value);
	void  SetItemHeight(int Value);
	void  SetItems(Classes::TStrings* Value);
	void  SetSelected(int Index, bool Value);
	void  SetSorted(bool Value);
	void  SetStyle(TListBoxStyle Value);
	void  SetTabWidth(int Value);
	void  SetTopIndex(int Value);
	HIDESBASE MESSAGE void  WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void  WMSize(Messages::TWMSize &Message);
	MESSAGE void  CNCommand(Messages::TWMCommand &Message);
	MESSAGE void  CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void  CNMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void  WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void  CMCtl3DChanged(Messages::TMessage &Message);
	int  GetScrollWidth(void);
	void  SetScrollWidth(const int Value);
	
protected:
	bool FMoving;
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	virtual void  DestroyWnd(void);
	AnsiString  DoGetData(const int Index);
	System::TObject*  DoGetDataObject(const int Index);
	int  DoFindData(const AnsiString Data);
	virtual void  WndProc(Messages::TMessage &Message);
	DYNAMIC void  DragCanceled(void);
	virtual void  DrawItem(int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	virtual int  GetCount(void);
	virtual int  GetSelCount(void);
	virtual void  MeasureItem(int Index, int &Height);
	DYNAMIC int  InternalGetItemData(int Index);
	DYNAMIC void  InternalSetItemData(int Index, int AData);
	DYNAMIC int  GetItemData(int Index);
	virtual int  GetItemIndex(void);
	bool  GetSelected(int Index);
	DYNAMIC void  KeyPress(char &Key);
	DYNAMIC void  SetItemData(int Index, int AData);
	DYNAMIC void  ResetContent(void);
	DYNAMIC void  DeleteString(int Index);
	virtual void  SetMultiSelect(bool Value);
	virtual void  SetItemIndex(const int Value)/* overload */;
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int Columns = {read=FColumns, write=SetColumns, default=0};
	__property bool ExtendedSelect = {read=FExtendedSelect, write=SetExtendedSelect, default=1};
	__property bool IntegralHeight = {read=FIntegralHeight, write=SetIntegralHeight, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, nodefault};
	__property ParentColor  = {default=0};
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	__property TListBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property int TabWidth = {read=FTabWidth, write=SetTabWidth, default=0};
	// __property TDrawItemEvent OnDrawItem {read=FOnDrawItem, write=FOnDrawItem}; // [manual migration needed]
	// __property TMeasureItemEvent OnMeasureItem {read=FOnMeasureItem, write=FOnMeasureItem}; // [manual migration needed]
	// __property TLBGetDataEvent OnData {read=FOnData, write=FOnData}; // [manual migration needed]
	// __property TLBGetDataObjectEvent OnDataObject {read=FOnDataObject, write=FOnDataObject}; // [manual migration needed]
	// __property TLBFindDataEvent OnDataFind {read=FOnDataFind, write=FOnDataFind}; // [manual migration needed]
	
public:
	 virtual TCustomListBox(Classes::TComponent* AOwner);
	 virtual ~TCustomListBox(void);
	virtual void  AddItem(AnsiString Item, System::TObject* AObject);
	virtual void  Clear(void);
	virtual void  ClearSelection(void);
	virtual void  CopySelection(Controls::TCustomListControl* Destination);
	virtual void  DeleteSelected(void);
	int  ItemAtPos(const Types::TPoint &Pos, bool Existing);
	Types::TRect  ItemRect(int Index);
	virtual void  SelectAll(void);
	__property bool AutoComplete = {read=FAutoComplete, write=FAutoComplete, default=1};
	// __property Graphics::TCanvas* Canvas {read=FCanvas}; // [manual migration needed]
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	// __property Classes::TStrings* Items {read=FItems, write=SetItems}; // [manual migration needed]
// [indexed property - needs manual migration]: 	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int ScrollWidth = {read=GetScrollWidth, write=SetScrollWidth, default=0};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomListBox(HWND ParentWindow) : Controls::TCustomMultiSelectListControl(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TListBox;
class PASCALIMPLEMENTATION TListBox : public TCustomListBox 
{
	typedef TCustomListBox inherited;
	
__published:
	__property Style  = {default=0};
	__property AutoComplete  = {default=1};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Columns  = {default=0};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ExtendedSelect  = {default=1};
	__property Font ;
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property IntegralHeight  = {default=0};
	__property ItemHeight ;
	__property Items ;
	__property MultiSelect  = {default=0};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollWidth  = {default=0};
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TabWidth  = {default=0};
	__property Visible  = {default=1};
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
public:
	#pragma option push -w-inl
	/* TCustomListBox.Create */ inline  virtual TListBox(Classes::TComponent* AOwner) : TCustomListBox(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomListBox.Destroy */ inline  virtual ~TListBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TListBox(HWND ParentWindow) : TCustomListBox(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TScrollCode { scLineUp, scLineDown, scPageUp, scPageDown, scPosition, scTrack, scTop, scBottom, scEndScroll };
#pragma option pop

typedef void  ( *TScrollEvent)(System::TObject* Sender, TScrollCode ScrollCode, int &ScrollPos);

class DELPHICLASS TScrollBar;
class PASCALIMPLEMENTATION TScrollBar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Forms::TScrollBarKind FKind;
	int FPosition;
	int FMin;
	int FMax;
	int FPageSize;
	int FRTLFactor;
	Forms::TScrollBarInc FSmallChange;
	Forms::TScrollBarInc FLargeChange;
	Classes::TNotifyEvent FOnChange;
	TScrollEvent FOnScroll;
	void  DoScroll(Messages::TWMScroll &Message);
	bool  NotRightToLeft(void);
	void  SetKind(Forms::TScrollBarKind Value);
	void  SetMax(int Value);
	void  SetMin(int Value);
	void  SetPosition(int Value);
	void  SetPageSize(int Value);
	MESSAGE void  CNHScroll(Messages::TWMScroll &Message);
	MESSAGE void  CNVScroll(Messages::TWMScroll &Message);
	MESSAGE void  CNCtlColorScrollBar(Messages::TMessage &Message);
	HIDESBASE MESSAGE void  WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  CreateWnd(void);
	DYNAMIC void  Change(void);
	DYNAMIC void  Scroll(TScrollCode ScrollCode, int &ScrollPos);
	
public:
	 virtual TScrollBar(Classes::TComponent* AOwner);
	void  SetParams(int APosition, int AMin, int AMax);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Forms::TScrollBarKind Kind = {read=FKind, write=SetKind, default=0};
	__property Forms::TScrollBarInc LargeChange = {read=FLargeChange, write=FLargeChange, default=1};
	__property int Max = {read=FMax, write=SetMax, default=100};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property int PageSize = {read=FPageSize, write=SetPageSize, nodefault};
	__property ParentBiDiMode  = {default=1};
	__property ParentCtl3D  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property ShowHint ;
	__property Forms::TScrollBarInc SmallChange = {read=FSmallChange, write=FSmallChange, default=1};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnContextPopup ;
	// __property Classes::TNotifyEvent OnChange {read=FOnChange, write=FOnChange}; // [manual migration needed]
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	// __property TScrollEvent OnScroll {read=FOnScroll, write=FOnScroll}; // [manual migration needed]
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TScrollBar(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TScrollBar(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TStaticBorderStyle { sbsNone, sbsSingle, sbsSunken };
#pragma option pop

class DELPHICLASS TCustomStaticText;
class PASCALIMPLEMENTATION TCustomStaticText : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	TStaticBorderStyle FBorderStyle;
	Controls::TWinControl* FFocusControl;
	bool FShowAccelChar;
	HIDESBASE MESSAGE void  CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void  CMFontChanged(Messages::TMessage &Message);
	MESSAGE void  CMTextChanged(Messages::TMessage &Message);
	void  AdjustBounds(void);
	void  SetAlignment(Classes::TAlignment Value);
	void  SetBorderStyle(TStaticBorderStyle Value);
	void  SetFocusControl(Controls::TWinControl* Value);
	void  SetShowAccelChar(bool Value);
	
protected:
	virtual void  CreateParams(Controls::TCreateParams &Params);
	virtual void  Loaded(void);
	virtual void  Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void  SetAutoSize(bool Value);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property TStaticBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	// __property Controls::TWinControl* FocusControl {read=FFocusControl, write=SetFocusControl}; // [manual migration needed]
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	
public:
	 virtual TCustomStaticText(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TCustomStaticText(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TCustomStaticText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStaticText;
class PASCALIMPLEMENTATION TStaticText : public TCustomStaticText 
{
	typedef TCustomStaticText inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=1};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property BiDiMode ;
	__property BorderStyle  = {default=0};
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FocusControl ;
	__property Font ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowAccelChar  = {default=1};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomStaticText.Create */ inline  virtual TStaticText(Classes::TComponent* AOwner) : TCustomStaticText(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TStaticText(HWND ParentWindow) : TCustomStaticText(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline  virtual ~TStaticText(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Colorcomboboxroutineu */
using namespace Colorcomboboxroutineu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ColorComboBoxRoutineU
