//---------------------------------------------------------------------------

#ifndef MDIConnectVH
#define MDIConnectVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MDIMetaNodeV.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIConnect : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsAngle;
    TPanel *Angle;
    TTabSheet *tsExtended;
    TCheckBox *cbHoleCreated;
    TGroupBox *gblcm;
    TComboBox *cblcmX;
    TComboBox *cblcmY;
    TComboBox *cblcmZ;
    TCheckBox *cbClient;
    TGroupBox *GroupBox1;
    TComboBox *cbNormal0;
    TLabel *Label2;
    TComboBox *cbNormal1;
    TLabel *Label3;
    TTabSheet *TabSheet1;
    TPanel *EPS;
    TGroupBox *GroupBox2;
    TUpDown *UpDown1;
    TEdit *ePriority;
    TLabel *lMetaLinkType;
    TComboBox *cbMetaLinkType;
    TCheckBox *cbControl;
    TTabSheet *tsNew;
    TPanel *STEP;
    TCheckBox *cbWallLink;
    TRadioGroup *rgTransMode;
    TCheckBox *cbRunOnStop;
private:	// User declarations
public:		// User declarations
void SETUP();
    __fastcall TMDIConnect(TComponent* Owner,TMetaLink *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIConnect *MDIConnect;
//---------------------------------------------------------------------------
#endif
