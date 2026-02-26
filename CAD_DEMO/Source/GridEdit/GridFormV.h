// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef GridFormVH
#define GridFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "CellGrid.h"
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
    void  StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void  Button5Click(TObject *Sender);
    void  FormActivate(TObject *Sender);
    void  Button8Click(TObject *Sender);
    void  Button1Click(TObject *Sender);
    void  ApplicationEvents1Idle(TObject *Sender, bool &Done);
    void  Button2Click(TObject *Sender);
    void  Button3Click(TObject *Sender);
    void  Button4Click(TObject *Sender);
    void  Button6Click(TObject *Sender);
    void  Button9Click(TObject *Sender);
    void  EditCutExecute(TObject *Sender);
    void  EditCopyExecute(TObject *Sender);
    void  EditPasteExecute(TObject *Sender);
    void  EditSelectAllExecute(TObject *Sender);
    void  EditDeleteExecute(TObject *Sender);
    void  EditClearExecute(TObject *Sender);
    void  EditFormatCellExecute(TObject *Sender);
    void  Button7Click(TObject *Sender);
    void  Button10Click(TObject *Sender);
    void  PopupMenuCellGridPopup(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TGridForm(TComponent* Owner);
    void  CellGrid1DrawCell(System::TObject *Sender, int ACol, int ARow,Types::TRect &Rect, TGridDrawState State);
    TCellGrid* CellGrid1;
    TToolBarCellGrid *ToolBarCellGrid;
};
//---------------------------------------------------------------------------
extern  TGridForm *GridForm;
//---------------------------------------------------------------------------
#endif
