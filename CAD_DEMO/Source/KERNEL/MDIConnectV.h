// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIConnectVH
#define MDIConnectVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
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
     TMDIConnect(TComponent* Owner,TMetaLink *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIConnect *MDIConnect;
//---------------------------------------------------------------------------
#endif
