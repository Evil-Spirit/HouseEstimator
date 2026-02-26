// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaMaterialVH
#define MDIMetaMaterialVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
#include "VisShape.hpp"

class TMDITV;
class TMainTree;
class TMDIColors;

//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaMaterial : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsMaterial;
    TPanel *Panel2;
    TSplitter *Splitter1;
    TPanel *P3;
    void  FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void SETUP();
    virtual void MNRefresh();
    virtual void MNApply();
    TMDITV *TV;
    TMainTree *MT;
    TVisMaterial *VISM;
    TMDIColors *MDIC;
    TVisBox *VisBox;
    void KILL();
     TMDIMetaMaterial(TComponent* Owner,TMetaMaterial *MM);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaMaterial *MDIMetaMaterial;
//---------------------------------------------------------------------------
#endif
