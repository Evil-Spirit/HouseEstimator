//---------------------------------------------------------------------------

#ifndef MDIBMPSetEditVH
#define MDIBMPSetEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
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
    void __fastcall tbtDelClick(TObject *Sender);
    void __fastcall tbtUpClick(TObject *Sender);
    void __fastcall tbtDownClick(TObject *Sender);
    void __fastcall tbtAddClick(TObject *Sender);
    void __fastcall eXChange(TObject *Sender);
    void __fastcall ColorBoxMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
    TMDelTList<int>* findices;
    __fastcall TMDIBMPSetEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIBMPSetEdit *MDIBMPSetEdit;
void COMMONAL_API FillLV(TListView *LV, TImageList *IL);
//---------------------------------------------------------------------------
#endif
