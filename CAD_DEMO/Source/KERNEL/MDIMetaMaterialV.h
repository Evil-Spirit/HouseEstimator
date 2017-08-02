//---------------------------------------------------------------------------

#ifndef MDIMetaMaterialVH
#define MDIMetaMaterialVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    void __fastcall FormActivate(TObject *Sender);
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
    __fastcall TMDIMetaMaterial(TComponent* Owner,TMetaMaterial *MM);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaMaterial *MDIMetaMaterial;
//---------------------------------------------------------------------------
#endif
