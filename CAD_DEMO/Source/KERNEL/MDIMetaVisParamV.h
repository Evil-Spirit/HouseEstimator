//---------------------------------------------------------------------------

#ifndef MDIMetaVisParamVH
#define MDIMetaVisParamVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    __fastcall TMDIMetaVisParam(TComponent* Owner,TMetaVisParam *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaVisParam *MDIMetaVisParam;
//---------------------------------------------------------------------------
#endif
