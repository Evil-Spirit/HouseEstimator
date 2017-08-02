 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MyGL.h"

#include "MDICustomElementV.h"
#include "MYIMPORTV.h"
#include "CustomElementV.h"
#include "Wizard3DSImport.h"
#include "MySupportV.h"
#include "MetaNodeCollectionV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDICustomElement *MDICustomElement;
//---------------------------------------------------------------------------
__fastcall TMDICustomElement::TMDICustomElement(TComponent* Owner,TCustomMetaElement *N)
    : TMDIElement(Owner,N)
{
}
//---------------------------------------------------------------------------
void __fastcall TMDICustomElement::SpeedButton1Click(TObject *Sender)
{
    if (OpenDialog1->Execute())
    {
        bShowClick(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDICustomElement::btImportClick(TObject *Sender)
{
	std::vector<TMetaMaterial *> Materials;
	if (!IS_FLOAT(EdEPS->Text))
		return;

	bool Econom = ((TWinControl*)Sender)->Tag;
	if (!OpenDialog1->Execute())
		return;
	if (!FileExists(OpenDialog1->FileName))
		return;

	TVisPrimitiveObj *obj = TfrmWizard3DSImport::ImportFile(OpenDialog1->FileName, Materials);
	if(!obj)
		return;
	((TCustomMetaElement*)MetaNode)->VisObject->Init();
	((TCustomMetaElement*)MetaNode)->VisObject->Assign(obj);
	((TCustomMetaElement*)MetaNode)->MMSL.Mode_Set_List->Clear();
	((TCustomMetaElement*)MetaNode)->MMSL.Mode_Set_List->Add( new TMyModeSettings() );
	((TCustomMetaElement*)MetaNode)->MMSL.Mode_Set_List->Items[0]->Meta_Mode.ADR =
											MetaNodeCollection->KernelSupport->_3D_MODE;
	((TCustomMetaElement*)MetaNode)->MMSL.DefaultMode.ADR =
											MetaNodeCollection->KernelSupport->_3D_MODE;
	for(int i = 0; i < Materials.size(); i ++)
	{
		((TCustomMetaElement*)MetaNode)->MMSL.Mode_Set_List->Items[0]->MATs.Add(new TPointer<TMetaMaterial>(Materials[i]));
	}
	if (((TCustomMetaElement*)MetaNode)->VisObject->Points->Count)
	{
		TVisMathVector _Min;
		TVisMathVector _Max;
		ObjectMinMax(((TCustomMetaElement*)MetaNode)->VisObject,_Min,_Max);
		((TCustomMetaElement*)MetaNode)->VisObject->Points->MovePoints((-(_Min.x+_Max.x))/2,(-(_Min.y+_Max.y))/2,(-(_Min.z+_Max.z))/2);
		TIntVec FV;
		for (int i=0;i<3;i++)
			FV.a[i] = (_Max.a[i]-_Min.a[i])/2;
		TIntVec NS = FV;
		((TCustomMetaElement*)MetaNode)->Size.LOW = FV * 0.00001;
		((TCustomMetaElement*)MetaNode)->Size.HI = FV * 10000;
		((TCustomMetaElement*)MetaNode)->Size.DEFAULT = FV;
		AnsiString StrOut = AnsiString("Original object size ")+VecToStrA(NS);
		StdOut(StrOut,true);
	}
	delete obj;
	MNRefresh();
	MNApply();
//		((TCustomMetaElement*)MetaNode)->VisObject->Primitive[0]->MaterialName = "MaterialName=0685;TextureName="; // = ((TMetaMaterial*)TMetaMaterial::StaticType->RecurrentFindByGUID("0685"))->VM;
//	((TCustomMetaElement*)MetaNode)->VisObject->Primitive[3]->MaterialName = "MaterialName=0242;TextureName="; //((TMetaMaterial*)TMetaMaterial::StaticType->RecurrentFindByGUID("0242"))->VM;
//	UnpackMaterials(((TCustomMetaElement*)MetaNode)->VisObject,
//					((TCustomMetaElement*)MetaNode)->MaterialRefs,
//					((TCustomMetaElement*)MetaNode)->TextureRefs);
//	}
//	delete OBJ;
//  delete DefaultMat;
//  delete PO;
}
//---------------------------------------------------------------------------

