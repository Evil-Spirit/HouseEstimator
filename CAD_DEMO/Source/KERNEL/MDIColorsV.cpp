 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIColorsV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisComp"
#pragma link "VisLight"
#pragma link "VisMat"
#pragma link "VisView"
#pragma resource "*.dfm"
TMDIColors *MDIColors;
//---------------------------------------------------------------------------

__fastcall TMDIColors::TMDIColors(TComponent* Owner,TVisRender *_VisRender,TVisView *_VisView,TWinControl *_Parent)
    : TForm(Owner)
{
    if (_Parent)
    {
        Parent = _Parent;
        BorderStyle = bsNone;
        Align = alClient;
    }
    Creating = true;
    VisRender = _VisRender;
    VisView = _VisView;

    if (VisView == NULL || VisRender == NULL)
        Close();

    if (__classid(TVisMaterial) != VisRender->ClassType())
    {
        GREmission->Enabled=false;
        GRShininess->Enabled = false;
    }
    cbFace->Clear();
    cbFace->Items->Add(TMaterialFaceStr[mfFront]);
    cbFace->Items->Add(TMaterialFaceStr[mfBack]);
    cbFace->Items->Add(TMaterialFaceStr[mfFrontBack]);
    ToForm();
    Creating = false;
}
//---------------------------------------------------------------------------
void __fastcall TMDIColors::AmbientMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ColorDialog->Color = ((TShape *)Sender)->Brush->Color;
    if (ColorDialog->Execute())
        ((TShape *)Sender)->Brush->Color = ColorDialog->Color;
    Apply();
}
//---------------------------------------------------------------------------
void __fastcall TMDIColors::ShininessChange(TObject *Sender)
{
Apply();
}
//---------------------------------------------------------------------------

void TMDIColors::ToForm()
{
    if (__classid(TVisMaterial) == VisRender->ClassType())
    {
        Creating = true;
        TVisMaterial *Mat = (TVisMaterial *)VisRender;
        Emission->Brush->Color = Mat->ColorEmission->Color;
        EmissionA->Position = (Mat->ColorEmission->Alpha*1000);

        Ambient->Brush->Color = Mat->ColorAmbient->Color;
        AmbientA->Position = (Mat->ColorAmbient->Alpha*1000);

        Diffuse->Brush->Color = Mat->ColorDiffuse->Color;
        DiffuseA->Position = (Mat->ColorDiffuse->Alpha*1000);

        Specular->Brush->Color = Mat->ColorSpecular->Color;
        SpecularA->Position = (Mat->ColorSpecular->Alpha*1000);

        Shininess->Position = (Mat->Shininess*1000);

        cbFace->ItemIndex = Mat->Face;
        Creating = false;
    }
}

void TMDIColors::Apply()
{
    if (Creating)
        return;
    if (__classid(TVisMaterial) == VisRender->ClassType())
    {
        TVisMaterial *Mat = (TVisMaterial *)VisRender;
        
        Mat->ColorEmission->Color=Emission->Brush->Color;
        Mat->ColorEmission->Alpha = ((double)EmissionA->Position)/1000;

        Mat->ColorAmbient->Color=Ambient->Brush->Color;
        Mat->ColorAmbient->Alpha = ((double)AmbientA->Position)/1000;

        Mat->ColorDiffuse->Color=Diffuse->Brush->Color;
        Mat->ColorDiffuse->Alpha = ((double)DiffuseA->Position)/1000;

        Mat->ColorSpecular->Color=Specular->Brush->Color;
        Mat->ColorSpecular->Alpha = ((double)SpecularA->Position)/1000;

        Mat->Shininess = ((double)Shininess->Position)/1000;

        Mat->Face = (TMaterialFace)cbFace->ItemIndex;
    }
    VisView->InvalidateGL();
}

