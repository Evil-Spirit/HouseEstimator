// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaNodeVH
#define MDIMetaNodeVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaNode : public TMyMDIChild
{
__published:	// IDE-managed Components
    TPageControl *PCNode;
    TTabSheet *tsMain;
    TEdit *mnName;
    TPanel *Panel1;
    TButton *btOK;
    TButton *btCancel;
    TLabel *Label1;
    TLabel *indLabel;
    TEdit *METAID;
    TComboBoxEx *cbeImageSelect;
    TEdit *mnDescription;
    TLabel *LabelDescription;
    TTabSheet *tsAttributes;
    TPanel *Attributes;
    TSplitter *Splitter2;
    TPanel *TB;
    TTabSheet *tsAdvancedSuper;
    TImage *Image1;
    TBevel *Bevel1;
    TBevel *Bevel2;
    TImage *Image2;
    TLabel *lGUID;
    TEdit *eGUID;
    void  btOKClick(TObject *Sender);
    void  btCancelClick(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  Image2Click(TObject *Sender);
    void  Image2DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TMetaNode *MetaNode;
     TMDIMetaNode(TComponent* Owner,TMetaNode *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP(){};
    virtual void KILL(){};
    TBMPPointer *BMPPointer;
    TBMPPointer *SmallBMPPointer;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaNode *MDIMetaNode;
//---------------------------------------------------------------------------
#endif
