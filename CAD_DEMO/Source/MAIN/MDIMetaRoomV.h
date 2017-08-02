//---------------------------------------------------------------------------

#ifndef MDIMetaRoomVH
#define MDIMetaRoomVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIElementV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMetaRoom;
class TMDIMetaRoom : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsRoom;
    TToolBar *ToolBar1;
    TToolButton *tbtAdd;
    TToolButton *tbtDel;
    TListView *LV;
    TComboBox *cbDM;
    void __fastcall tbtAddClick(TObject *Sender);
    void __fastcall tbtDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIMetaRoom(TComponent* Owner,TMetaRoom *M);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaRoom *MDIMetaRoom;
//---------------------------------------------------------------------------
#endif
