//---------------------------------------------------------------------------

#ifndef MDIElementVH
#define MDIElementVH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MDIMetaNodeV.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>

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
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall bShowClick(TObject *Sender);
    void __fastcall btGenClick(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
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
__fastcall TMDIElement(TComponent* Owner,TMetaElement *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIElement *MDIElement;
//---------------------------------------------------------------------------
#endif
