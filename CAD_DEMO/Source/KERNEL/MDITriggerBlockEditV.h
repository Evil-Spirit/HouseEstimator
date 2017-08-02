//---------------------------------------------------------------------------

#ifndef MDITriggerBlockEditVH
#define MDITriggerBlockEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include "TriggerBlockV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDITriggerBlockEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPopupMenu *PM;
    TToolBar *Buttons;
    TToolButton *tbtAdd;
    TToolButton *tbtEdit;
    TToolButton *tbtDel;
    TListView *LV;
    void __fastcall tbtAddClick(TObject *Sender);
    void __fastcall SelectClick(TObject *Sender);
    void __fastcall tbtDelClick(TObject *Sender);
    void __fastcall tbtEditClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TTriggerBlock *GetTB();
    void Refresh();
    bool Checked(){return true;}
    __fastcall TMDITriggerBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITriggerBlockEdit *MDITriggerBlockEdit;
//---------------------------------------------------------------------------
#endif
