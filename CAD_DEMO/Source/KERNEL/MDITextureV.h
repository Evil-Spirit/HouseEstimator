// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDITextureVH
#define MDITextureVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
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
    void  BlendMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  BlendAChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TVisTexture *VT;
    TVisView *VV;
    void ToForm();
    bool Creation;
    void Apply();
     TMDITexture(TComponent* Owner,TVisTexture *VT,TVisView *VV,TWinControl *Par);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITexture *MDITexture;
//---------------------------------------------------------------------------
#endif
