//---------------------------------------------------------------------------

#ifndef MDIMetaActionListVH
#define MDIMetaActionListVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMetaNode;
class TMDIMetaActionList : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsAction;
    TLabel *Label3;
    TPanel *BMPSet;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();
    __fastcall TMDIMetaActionList(TComponent* Owner,TMetaNode* N);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaActionList *MDIMetaActionList;
//---------------------------------------------------------------------------
#endif
