// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaRoomVH
#define MDIMetaRoomVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIElementV.h"
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
    void  tbtAddClick(TObject *Sender);
    void  tbtDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDIMetaRoom(TComponent* Owner,TMetaRoom *M);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
};
//---------------------------------------------------------------------------
extern  TMDIMetaRoom *MDIMetaRoom;
//---------------------------------------------------------------------------
#endif
