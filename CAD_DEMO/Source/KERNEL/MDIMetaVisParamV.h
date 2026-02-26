// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaVisParamVH
#define MDIMetaVisParamVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class TMetaVisParam;
class COMMONAL_API TMDIMetaVisParam : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsparam;
    TPanel *TML;
    TLabel *Label3;
    TLabel *Label4;
    TPanel *MAT;
    TPanel *TEX;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
     TMDIMetaVisParam(TComponent* Owner,TMetaVisParam *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaVisParam *MDIMetaVisParam;
//---------------------------------------------------------------------------
#endif
