//---------------------------------------------------------------------------

#ifndef MDITextureVH
#define MDITextureVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <VisTex.hpp>
#include <VisView.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDITexture : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GRAmbient;
    TShape *Blend;
    TTrackBar *BlendA;
    TTrackBar *Alpha;
    TGroupBox *GroupBox1;
    TTrackBar *RotX;
    TTrackBar *RotY;
    TComboBox *CBE;
    TColorDialog *ColorDialog;
    TTrackBar *RotZ;
    TGroupBox *GroupBox2;
    TTrackBar *ScaX;
    TTrackBar *ScaY;
    TGroupBox *GroupBox3;
    TTrackBar *PosX;
    TTrackBar *PosY;
    TTrackBar *PosZ;
    TTrackBar *ScaZ;
  TLabel *Label1;
  TLabel *Label2;
  TComboBox *cbMAG;
  TLabel *Label3;
  TComboBox *cbMIN;
    void __fastcall BlendMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall BlendAChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TVisTexture *VT;
    TVisView *VV;
    void ToForm();
    bool Creation;
    void Apply();
    __fastcall TMDITexture(TComponent* Owner,TVisTexture *VT,TVisView *VV,TWinControl *Par);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITexture *MDITexture;
//---------------------------------------------------------------------------
#endif
