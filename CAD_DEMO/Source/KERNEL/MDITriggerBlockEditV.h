// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDITriggerBlockEditVH
#define MDITriggerBlockEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
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
    void  tbtAddClick(TObject *Sender);
    void  SelectClick(TObject *Sender);
    void  tbtDelClick(TObject *Sender);
    void  tbtEditClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TTriggerBlock *GetTB();
    void Refresh();
    bool Checked(){return true;}
     TMDITriggerBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITriggerBlockEdit *MDITriggerBlockEdit;
//---------------------------------------------------------------------------
#endif
