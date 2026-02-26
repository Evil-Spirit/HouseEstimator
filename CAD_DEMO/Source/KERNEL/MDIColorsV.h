// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIColorsVH
#define MDIColorsVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
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
    void  AmbientMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ShininessChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
TVisRender *VisRender;
TVisView *VisView;
void ToForm();
void Apply();
bool Creating;
     TMDIColors(TComponent* Owner,TVisRender *_VisRender,TVisView *_VisView,TWinControl *_Parent=NULL);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIColors *MDIColors;
//---------------------------------------------------------------------------
#endif
