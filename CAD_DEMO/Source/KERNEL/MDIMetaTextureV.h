//---------------------------------------------------------------------------

#ifndef MDIMetaTextureVH
#define MDIMetaTextureVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "MDITextureV.h"
#include <Buttons.hpp>
#include "MDITVV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaTexture : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsTexture;
    TSplitter *Splitter1;
    TPanel *Panel2;
    TPanel *P3;
    TBitBtn *BitBtn1;
  TButton *Button1;
    TGroupBox *GroupBox1;
    TLabel *Label2;
    TEdit *edRealSizeX;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *edRealSizeY;
    TLabel *Label5;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void SETUP();
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    TBMPPointer *BMPPointer;
    TMDITV *TV;
    TMainTree *MT;
    TVisTexture *VIST;
    TVisMaterial *VISM;
    TMDITexture *MDIT;
    TVisBox *VisBox;
    void KILL();
    TPointer<TBMPSet>* BMPS;
    __fastcall TMDIMetaTexture(TComponent* Owner,TMetaTexture *MM);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaTexture *MDIMetaTexture;
//---------------------------------------------------------------------------
#endif
