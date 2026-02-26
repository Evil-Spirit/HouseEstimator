// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIElementSelectVH
#define MDIElementSelectVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIElementSelect : public TForm
{
__published:	// IDE-managed Components
    TListView *LV;
    TButton *OK;
    TButton *btCancel;
    void  OKClick(TObject *Sender);
    void  btCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TMetaNode *Selected;
     TMDIElementSelect(TComponent* Owner,TClassNode* CN,bool self,bool childs,TMetaNode *Parent);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIElementSelect *MDIElementSelect;
//---------------------------------------------------------------------------

TMetaNode* COMMONAL_API SelectNode(TClassNode* CN,bool self,bool childs,TMetaNode *Parent);
#endif
