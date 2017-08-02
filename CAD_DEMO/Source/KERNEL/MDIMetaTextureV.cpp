//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaTextureV.h"
#include "MDIElementSelectV.h"
#include "World.h"
#include "MDIObjectEditV.h"
#include "MySupportV.h"
#include "AUIV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaTexture *MDIMetaTexture;
//---------------------------------------------------------------------------
__fastcall TMDIMetaTexture::TMDIMetaTexture(TComponent* Owner,TMetaTexture *MM)
    : TMDIMetaNode(Owner,MM)
{
}
//---------------------------------------------------------------------------


void TMDIMetaTexture::SETUP()
{
    BMPS = new TPointer<TBMPSet>();
    MT = new TMainTree();
    MT->AddFloor();
    TV = new TMDITV(this,Panel2,MT);

    VisBox = new TVisBox(NULL);
    VisBox->Transformation->Order = toTraRotSca;
    VisBox->Transformation->Translation->incY(-0.5);
    VisBox->Transformation->Translation->incZ(-0.5);
    VISM = new TVisMaterial(NULL);
    VIST = new TVisTexture(NULL);
    VisBox->Material = VISM;
    VisBox->Texture = VIST;
    VisBox->Textured = true; 

	//KillElement( MT->ActiveFloor->First.ADR );
	MT->ActiveFloor->First.ADR->CustomEnabled = false;
    MT->ActiveFloor->VTRANS->AddIndirect(VisBox);

    MDIT = new TMDITexture(this,VIST,TV->View,P3);
    MDIT->Visible = true;
    BMPPointer = new TBMPPointer();
    TV->Mode = MetaNodeCollection->KernelSupport->_3D_MODE;
}

void TMDIMetaTexture::MNApply()
{
    TMDIMetaNode::MNApply();
    TMetaTexture *MM = (TMetaTexture *)MetaNode;

    MM->Blend.Color = VIST->BlendColor->Color;
    MM->Blend.Alpha = VIST->BlendColor->Alpha;
    MM->Alpha = VIST->Alpha;

    MM->Rotate = *(VIST->Transformation->Rotation);
    MM->Translation = *(VIST->Transformation->Translation);
    MM->Scale = *(VIST->Transformation->Scale);
    MM->MipMaps.ADR = BMPS->ADR;

    MM->MinFilter = VIST->MinFilter;
    MM->MagFilter = VIST->MagFilter;
    MM->Mode = VIST->Mode;
    MM->BMP.Assign(BMPPointer);
    MM->CheckFields();
    MM->RealSizeX = TO_DOUBLE(edRealSizeX->Text);
    MM->RealSizeY = TO_DOUBLE(edRealSizeY->Text);
}

bool TMDIMetaTexture::MNChecked()
{
    if (!TMDIMetaNode::MNChecked())
        return false;
    if (!IS_FLOAT(edRealSizeX->Text) || !IS_FLOAT(edRealSizeY->Text))
        return false;
    if (TO_DOUBLE(edRealSizeX->Text)<0.01 || TO_DOUBLE(edRealSizeY->Text)<0.01)
        return false;

    return true;
}

void TMDIMetaTexture::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    TMetaTexture *MM = (TMetaTexture *)MetaNode;
    VIST->BlendColor->Color = MM->Blend.Color;
    VIST->BlendColor->Alpha = MM->Blend.Alpha;
    VIST->Alpha = MM->Alpha;

    AssignVisVec(*(VIST->Transformation->Rotation),MM->Rotate);
    AssignVisVec(*(VIST->Transformation->Translation),MM->Translation);
    AssignVisVec(*(VIST->Transformation->Scale),MM->Scale);

    VIST->Mode = (TVisTexMode)MM->Mode;
    VIST->MinFilter = (TVisTexFilter)MM->MinFilter;
    VIST->MagFilter = (TVisTexFilter)MM->MagFilter;

    edRealSizeX->Text = FLOATTOSTR(MM->RealSizeX);
    edRealSizeY->Text = FLOATTOSTR(MM->RealSizeY);

    BMPPointer->Assign(&(MM->BMP));

    Graphics::TBitmap *bmp = new Graphics::TBitmap();
                bmp->HandleType = bmDIB;
    BMPPointer->GetBitmap(bmp);
    VIST->Bitmap->Assign(bmp);
    delete bmp;

    BMPS->ADR = MM->MipMaps.ADR;
    ApplyMipMaps(VIST,*BMPS);

    MDIT->ToForm();
}

void TMDIMetaTexture::KILL()
{
    delete BMPS;
    MT->ActiveFloor->VTRANS->Clear();
    MT->Clear();

    TV->MyMT = NULL;
    delete VISM;
    delete VIST;
    delete VisBox;
    delete BMPPointer;
}

//---------------------------------------------------------------------------
void __fastcall TMDIMetaTexture::BitBtn1Click(TObject *Sender)
{
    BMPPointer->Select();
    Graphics::TBitmap *bmp = new Graphics::TBitmap();
                bmp->HandleType = bmDIB;
    BMPPointer->GetBitmap(bmp);
    VIST->Bitmap->Assign(bmp);
    delete bmp;
    TV->View->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TMDIMetaTexture::FormActivate(TObject *Sender)
{
    AUI.ActivateView(TV);
}
//---------------------------------------------------------------------------

void __fastcall TMDIMetaTexture::Button1Click(TObject *Sender)
{
    BMPS->ADR = (TBMPSet*)SelectNode(TBMPSet::StaticType,true,true,NULL);
    ApplyMipMaps(VIST,*BMPS);
}
//---------------------------------------------------------------------------

