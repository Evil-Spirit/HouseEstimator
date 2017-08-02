//---------------------------------------------------------------------------

#ifndef GridFormVH
#define GridFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CellGrid.h"
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <AppEvnts.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TCellGrid;
class TSelectColor;
class TSelectBorder;
class TToolBarCellGrid;

class TGridForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TButton *Button5;
    TButton *Button8;
    TButton *Button1;
    TApplicationEvents *ApplicationEvents1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TButton *Button6;
    TButton *Button9;
    TActionList *ActionList;
    TAction *EditRedo;
    TPopupMenu *PopupMenuCellGrid;
    TMenuItem *Cut1;
    TMenuItem *Copy1;
    TMenuItem *Paste1;
    TMenuItem *Delete1;
    TMenuItem *SelectAll1;
    TImageList *ImageActionList;
    TEditCut *EditCut;
    TEditCopy *EditCopy;
    TEditPaste *EditPaste;
    TEditSelectAll *EditSelectAll;
    TEditUndo *EditUndo;
    TEditDelete *EditDelete;
    TAction *EditClear;
    TAction *EditFormatCell;
    TMenuItem *N1;
    TMenuItem *N2;
    TButton *Button7;
    TButton *Button10;
    void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall EditCutExecute(TObject *Sender);
    void __fastcall EditCopyExecute(TObject *Sender);
    void __fastcall EditPasteExecute(TObject *Sender);
    void __fastcall EditSelectAllExecute(TObject *Sender);
    void __fastcall EditDeleteExecute(TObject *Sender);
    void __fastcall EditClearExecute(TObject *Sender);
    void __fastcall EditFormatCellExecute(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button10Click(TObject *Sender);
    void __fastcall PopupMenuCellGridPopup(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TGridForm(TComponent* Owner);
    void __fastcall CellGrid1DrawCell(System::TObject *Sender, int ACol, int ARow,Types::TRect &Rect, TGridDrawState State);
    TCellGrid* CellGrid1;
    TToolBarCellGrid *ToolBarCellGrid;
};
//---------------------------------------------------------------------------
extern PACKAGE TGridForm *GridForm;
//---------------------------------------------------------------------------
#endif
