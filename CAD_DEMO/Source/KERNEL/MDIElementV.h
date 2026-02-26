// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIElementVH
#define MDIElementVH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"

class TElement;
class TMDITV;
//---------------------------------------------------------------------------
class COMMONAL_API TMDIElement : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TPanel *Panel2;
    TSplitter *Splitter1;
    TTabSheet *tSize;
    TButton *bShow;
    TTabSheet *tsEPS;
    TPanel *EPS;
    TTabSheet *tsAdditional;                
    TCheckBox *cbEnabled;
    TLabel *Label2;
    TEdit *eStartZED;
    TTabSheet *tsInterface;
    TPanel *MAS;
    TPanel *pInterface;
    TTabSheet *tsVisual;
    TPanel *MAT;
    TPanel *MTF;
    TPanel *TEX;
    TLabel *Label3;
    TLabel *Label4;
  TTabSheet *tMMSL;
  TTabSheet *tsDrawView;
  TPanel *PanelDraw;
  TCheckBox *cbDrawView;
    TTabSheet *tCanExistCheck;
    TCheckBox *cbInWeb;
    TButton *btGen;
    TTabSheet *tsDepend;
    TCheckBox *cbLight;
    TButton *Button2;
    void  FormActivate(TObject *Sender);
    void  FormCreate(TObject *Sender);
    void  bShowClick(TObject *Sender);
    void  btGenClick(TObject *Sender);
    void  Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
//TMetaElement * MetaNode;
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
void SETUP();
void KILL();
void ShowChanges();
TMDITV *TV;
TElement *Element;
TMainTree *MT;
//------------tsSize--------------------
 TMDIElement(TComponent* Owner,TMetaElement *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIElement *MDIElement;
//---------------------------------------------------------------------------
#endif
