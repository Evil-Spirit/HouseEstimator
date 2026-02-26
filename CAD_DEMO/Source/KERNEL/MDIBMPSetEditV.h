// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIBMPSetEditVH
#define MDIBMPSetEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIBMPSetEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TListView *LV;
    TToolBar *ToolBar1;
    TToolButton *tbtAdd;
    TToolButton *tbtDel;
    TToolButton *tbtUp;
    TToolButton *tbtDown;
    TEdit *eX;
    TEdit *eY;
    TLabel *lX;
    TLabel *Label1;
    TOpenDialog *OpenDialog;
    TImageList *IL;
    TShape *ColorBox;
    TColorDialog *ColorDialog;
    TCheckBox *cbTrans;
    void  tbtDelClick(TObject *Sender);
    void  tbtUpClick(TObject *Sender);
    void  tbtDownClick(TObject *Sender);
    void  tbtAddClick(TObject *Sender);
    void  eXChange(TObject *Sender);
    void  ColorBoxMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
    TMDelTList<int>* findices;
     TMDIBMPSetEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIBMPSetEdit *MDIBMPSetEdit;
void COMMONAL_API FillLV(TListView *LV, TImageList *IL);
//---------------------------------------------------------------------------
#endif
