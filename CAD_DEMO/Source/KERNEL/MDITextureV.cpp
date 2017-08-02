 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDITextureV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDITexture *MDITexture;
//---------------------------------------------------------------------------
__fastcall TMDITexture::TMDITexture(TComponent* Owner,TVisTexture *_VT,TVisView *_VV,TWinControl *Par)
    : TForm(Owner)
{
    if (Par)
    {
        Parent = Par;
        BorderStyle = bsNone;
        Align = alClient;
    }
    VT = _VT;
    VV= _VV;
    CBE->Items->Add(AnsiString(""));
    CBE->Items->Add(AnsiString(""));
    CBE->Items->Add(AnsiString(""));
    CBE->Items->Add(AnsiString(""));
    CBE->Items->Strings[tmModulate] = AnsiString("tmModulate");
    CBE->Items->Strings[tmDecal] = AnsiString("tmDecal");
    CBE->Items->Strings[tmBlend] = AnsiString("tmBlend");
    CBE->Items->Strings[tmReplace] = AnsiString("tmReplace");

    cbMAG->Items->Add(AnsiString(""));
    cbMAG->Items->Add(AnsiString(""));
    cbMAG->Items->Strings[tfNearest] = TVisTexFilterStr[tfNearest];
    cbMAG->Items->Strings[tfLinear] = TVisTexFilterStr[tfLinear];

    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Add(AnsiString(""));
    cbMIN->Items->Strings[tfNearest] = TVisTexFilterStr[tfNearest];
    cbMIN->Items->Strings[tfLinear] = TVisTexFilterStr[tfLinear];
    cbMIN->Items->Strings[tfNearest_Nearest] = TVisTexFilterStr[tfNearest_Nearest];
    cbMIN->Items->Strings[tfLinear_Nearest] = TVisTexFilterStr[tfLinear_Nearest];
    cbMIN->Items->Strings[tfNearest_Linear] = TVisTexFilterStr[tfNearest_Linear];
    cbMIN->Items->Strings[tfLinear_Linear] = TVisTexFilterStr[tfLinear_Linear];
    ToForm();
}
//---------------------------------------------------------------------------
void TMDITexture::ToForm()
{
    Creation = true;
    //----------------------
    Blend->Brush->Color = VT->BlendColor->Color;
    BlendA->Position = (VT->BlendColor->Alpha*1000);
    Alpha->Position = VT->Alpha*1000;
    
    RotX->Position=360 -  (VT->Transformation->Rotation->X);
    RotY->Position=360 -  (VT->Transformation->Rotation->Y);
    RotZ->Position=360 -  (VT->Transformation->Rotation->Z);

    ScaX->Position=  -(VT->Transformation->Scale->X*10);
    ScaY->Position=  -(VT->Transformation->Scale->Y*10);
    ScaZ->Position=  -(VT->Transformation->Scale->Z*10);

    PosX->Position=  -(VT->Transformation->Translation->X*10);
    PosY->Position=  -(VT->Transformation->Translation->Y*10);
    PosZ->Position=  -(VT->Transformation->Translation->Z*10);
    
    CBE->ItemIndex = VT->Mode;
    cbMIN->ItemIndex = VT->MinFilter;
    cbMAG->ItemIndex = VT->MagFilter;
    //----------------------
    Creation = false;
}

void TMDITexture::Apply()
{
    if (Creation)
        return;
    VT->BlendColor->Color = Blend->Brush->Color;
    VT->BlendColor->Alpha = BlendA->Position/1000;
    VT->Alpha = ((double)Alpha->Position)/1000;

    VT->Transformation->Rotation->X = 360 - RotX->Position;
    VT->Transformation->Rotation->Y = 360 - RotY->Position;
    VT->Transformation->Rotation->Z = 360 - RotZ->Position;

    VT->Transformation->Scale->X = -((double)ScaX->Position)/10;
    VT->Transformation->Scale->Y = -((double)ScaY->Position)/10;
    VT->Transformation->Scale->Z = -((double)ScaZ->Position)/10;

    VT->Transformation->Translation->X = -((double)PosX->Position)/10;
    VT->Transformation->Translation->Y = -((double)PosY->Position)/10;
    VT->Transformation->Translation->Z = -((double)PosZ->Position)/10;

    VT->Mode = (TVisTexMode)CBE->ItemIndex;
    VT->MinFilter = (TVisTexFilter)cbMIN->ItemIndex;
    VT->MagFilter = (TVisTexFilter)cbMAG->ItemIndex;
    VV->Invalidate();
}

void __fastcall TMDITexture::BlendMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ColorDialog->Color = ((TShape *)Sender)->Brush->Color;
    if (ColorDialog->Execute())
        ((TShape *)Sender)->Brush->Color = ColorDialog->Color;
    Apply();
}
//---------------------------------------------------------------------------

void __fastcall TMDITexture::BlendAChange(TObject *Sender)
{
    if (__classid(TTrackBar) == Sender->ClassType())
        Application->Hint = ((TTrackBar*)Sender)->Position;
    Apply();
}
//---------------------------------------------------------------------------

