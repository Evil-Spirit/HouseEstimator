//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaMaterialV.h"
#include "World.h"
#include "MDITVV.h"
#include "MDIColorsV.h"
#include "MySupportV.h"
#include "AUIV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "MDIMetaNodeV"
#pragma link "VisMat"
#pragma link "VisShape"
#pragma link "MDIMetaNodeV"

#pragma resource "*.dfm"
TMDIMetaMaterial *MDIMetaMaterial;
//---------------------------------------------------------------------------
__fastcall TMDIMetaMaterial::TMDIMetaMaterial(TComponent* Owner,TMetaMaterial *MM)
    : TMDIMetaNode(Owner,MM)
{
}
//------------------------------------------------------------ ---------------
void TMDIMetaMaterial::SETUP()
{
    MT = new TMainTree();
    MT->AddFloor();
    TV = new TMDITV(this,Panel2,MT);
    TV->Attributes->ShadeModel = smFlat;
    //TV->DiscInvisible->Enabled = true;
    VisBox = new TVisBox(NULL);
    VisBox->Transformation->Order = toTraRotSca;
    VisBox->Transformation->Translation->incY(-0.5);
    VisBox->Transformation->Translation->incZ(-0.5);
    VISM = new TVisMaterial(NULL);
    //VisBox->Stacks = 2;
    //VisBox->Slices = 4;
    VisBox->Material = VISM;

	//KillElement( MT->ActiveFloor->First.ADR );
	MT->ActiveFloor->First.ADR->CurrentEnabled = false;
    MT->ActiveFloor->VTRANS->AddIndirect(VisBox);
    MDIC = new TMDIColors(this,VISM,TV->View,P3);
    MDIC->Visible = true;
    TV->Mode = MetaNodeCollection->KernelSupport->_3D_MODE;
}

void TMDIMetaMaterial::MNApply()
{
    TMDIMetaNode::MNApply();
    
    TMetaMaterial *MM = (TMetaMaterial *)MetaNode;
    MM->Ambient.Color = VISM->ColorAmbient->Color;
    MM->Diffuse.Color = VISM->ColorDiffuse->Color;
    MM->Emission.Color = VISM->ColorEmission->Color;
    MM->Specular.Color = VISM->ColorSpecular->Color;
    MM->Ambient.Alpha = VISM->ColorAmbient->Alpha;
    MM->Diffuse.Alpha = VISM->ColorDiffuse->Alpha;
    MM->Emission.Alpha = VISM->ColorEmission->Alpha;
    MM->Specular.Alpha = VISM->ColorSpecular->Alpha;
    MM->Shininess = VISM->Shininess;
    MM->Face = VISM->Face;
}

void TMDIMetaMaterial::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    TMetaMaterial *MM = (TMetaMaterial *)MetaNode;
    VISM->ColorAmbient->Color = MM->Ambient.Color;
    VISM->ColorDiffuse->Color = MM->Diffuse.Color;
    VISM->ColorEmission->Color = MM->Emission.Color;
    VISM->ColorSpecular->Color = MM->Specular.Color;

    VISM->ColorAmbient->Alpha = MM->Ambient.Alpha;
    VISM->ColorDiffuse->Alpha = MM->Diffuse.Alpha;
    VISM->ColorEmission->Alpha = MM->Emission.Alpha;
    VISM->ColorSpecular->Alpha = MM->Specular.Alpha;
    VISM->Shininess = (MM->Shininess>=0)*(MM->Shininess % 129);
    VISM->Face = (TMaterialFace)MM->Face;

    MDIC->ToForm();
}

void TMDIMetaMaterial::KILL()
{
    MT->ActiveFloor->VTRANS->Clear();
    MT->Clear();
    TV->MyMT = NULL;
    delete VISM;
    delete VisBox;
}
void __fastcall TMDIMetaMaterial::FormActivate(TObject *Sender)
{
    AUI.ActivateView(TV);
}
//---------------------------------------------------------------------------


