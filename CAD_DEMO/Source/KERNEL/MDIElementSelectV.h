//---------------------------------------------------------------------------

#ifndef MDIElementSelectVH
#define MDIElementSelectVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <typeinfo.h>
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIElementSelect : public TForm
{
__published:	// IDE-managed Components
    TListView *LV;
    TButton *OK;
    TButton *btCancel;
    void __fastcall OKClick(TObject *Sender);
    void __fastcall btCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TMetaNode *Selected;
    __fastcall TMDIElementSelect(TComponent* Owner,TClassNode* CN,bool self,bool childs,TMetaNode *Parent);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIElementSelect *MDIElementSelect;
//---------------------------------------------------------------------------

TMetaNode* COMMONAL_API SelectNode(TClassNode* CN,bool self,bool childs,TMetaNode *Parent);
#endif
