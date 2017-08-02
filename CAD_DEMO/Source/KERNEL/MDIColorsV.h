//---------------------------------------------------------------------------

#ifndef MDIColorsVH
#define MDIColorsVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisView.hpp"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIColors : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GRAmbient;
    TColorDialog *ColorDialog;
    TShape *Ambient;
    TTrackBar *AmbientA;
    TGroupBox *GBDiffuse;
    TShape *Diffuse;
    TTrackBar *DiffuseA;
    TGroupBox *GBSpecular;
    TShape *Specular;
    TTrackBar *SpecularA;
    TGroupBox *GREmission;
    TShape *Emission;
    TTrackBar *EmissionA;
    TGroupBox *GRShininess;
    TTrackBar *Shininess;
    TGroupBox *GroupBox1;
    TComboBox *cbFace;
    void __fastcall AmbientMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ShininessChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
TVisRender *VisRender;
TVisView *VisView;
void ToForm();
void Apply();
bool Creating;
    __fastcall TMDIColors(TComponent* Owner,TVisRender *_VisRender,TVisView *_VisView,TWinControl *_Parent=NULL);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIColors *MDIColors;
//---------------------------------------------------------------------------
#endif
