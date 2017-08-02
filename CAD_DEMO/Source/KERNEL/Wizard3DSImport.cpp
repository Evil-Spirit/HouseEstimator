//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Wizard3DSImport.h"
#include "MDI3DV.h"
#include "World.h"
#include "MDIElementSelectV.h"
#include "CustomElementV.h"
#include "MyGL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWizard3DSImport *frmWizard3DSImport;
//---------------------------------------------------------------------------
float RGBDifference(TColor col1, TColor col2)
{
	float dif = 0;
	// Find differences in differences of color components
	dif += fabs((float)((col1 & 0xFF) - ((col1 >> 8) & 0xFF)) / (float)(255)
				- (float)((col2 & 0xFF) - ((col2 >> 8) & 0xFF)) / (float)(255));

	dif += fabs((float)((col1 & 0xFF) - ((col1 >> 16) & 0xFF)) / (float)(255)
				- (float)((col2 & 0xFF) - ((col2 >> 16) & 0xFF)) / (float)(255));

	dif += fabs((float)(((col1 >> 8) & 0xFF) - ((col1 >> 16) & 0xFF)) / (float)(255)
				- (float)(((col2 >> 8) & 0xFF) - ((col2 >> 16) & 0xFF)) / (float)(255));

	dif += fabs((float)((col1 & 0xFF) - (col2 & 0xFF)) / (float)255);
	col1 >>= 8;
	col2 >>= 8;
	dif += fabs((float)((col1 & 0xFF) - (col2 & 0xFF)) / (float)255);
	col1 >>= 8;
	col2 >>= 8;
	dif += fabs((float)((col1 & 0xFF) - (col2 & 0xFF)) / (float)255);
	return dif;
}
//---------------------------------------------------------------------------
TVisPrimitiveObj* TfrmWizard3DSImport::ImportFile(AnsiString filename, std::vector<TMetaMaterial *> &Materials)
{
	TVisPrimitiveObj *Result = NULL;
	TfrmWizard3DSImport *myImportWizard;
	myImportWizard = new TfrmWizard3DSImport(NULL);
	if(myImportWizard->Import(filename) == mrOk)
	{
		Result = myImportWizard->ResultObject;
		Materials.resize(myImportWizard->ResultMaterials.size());
		for(int i = 0; i < Materials.size(); i ++)
		{
			Materials[i] = myImportWizard->ResultMaterials[i];
		}
	}
	else
	{
		delete myImportWizard->ResultObject;
	}
	delete myImportWizard;
	return Result;
}
//---------------------------------------------------------------------------
__fastcall TfrmWizard3DSImport::TfrmWizard3DSImport(TComponent* Owner)
	: TForm(Owner)
{
	VisNode = NULL;
	TV = NULL;
	MT = NULL;
	SelectedItem = NULL;
}
//---------------------------------------------------------------------------
float TfrmWizard3DSImport::MaterialMatch(TVisMaterial *mat1, TVisMaterial *mat2, float eps)
{
	float difference = 0;
	difference += RGBDifference(mat1->ColorAmbient->Color, mat2->ColorAmbient->Color);
	difference += fabs(mat1->ColorAmbient->Alpha - mat2->ColorAmbient->Alpha);
	difference += RGBDifference(mat1->ColorDiffuse->Color, mat2->ColorDiffuse->Color);
	difference += fabs(mat1->ColorDiffuse->Alpha - mat2->ColorDiffuse->Alpha);
	difference += RGBDifference(mat1->ColorSpecular->Color, mat2->ColorSpecular->Color);
	difference += fabs(mat1->ColorSpecular->Alpha - mat2->ColorSpecular->Alpha);
	difference += RGBDifference(mat1->ColorEmission->Color, mat2->ColorEmission->Color);
	difference += fabs(mat1->ColorEmission->Alpha - mat2->ColorEmission->Alpha);
	difference += fabs((float)(mat1->Shininess - mat2->Shininess) / (float)20);
	difference /= 1 + 4 * 4; // 4 components of 4 colors plus shininess
	return difference;
}
//---------------------------------------------------------------------------
int __fastcall TfrmWizard3DSImport::Import(AnsiString fileName)
{
	int i;
	FILE *f = NULL;
	WorkDirectory = fileName.SubString(0, fileName.LastDelimiter("\\/") );
	f = fopen(fileName.c_str(), "rb");
	if(f)
	{
		Read3DS(Objects, Materials, Textures, f);
	}
	fclose(f);
	ObjectsSelected.resize(Objects.size());
	for(i = 0; i < Objects.size(); i ++)
	{
		ObjectsSelected[i] = true;
	}
	Replacements.resize(Materials.size());
	for(i = 0; i < Replacements.size(); i ++)
	{
		Replacements[i] = NULL;
	}

	Restructure();
	pcSteps->ActivePageIndex = 0;
	PrepareRenderer();
	SyncObjectsList();
	SyncMaterialsList();
	if(Visible)
		Hide();
	return ShowModal();
}
//---------------------------------------------------------------------------
void TfrmWizard3DSImport::Restructure()
{
	int i;
	// Normalize object's size
	TVisMathVector Min;
	TVisMathVector Max;
	TIntVec FV;
	for(i = 0; i < Objects.size(); i ++)
	{
		TVisMathVector _Min;
		TVisMathVector _Max;
		if(!ObjectsSelected[i])
			continue;
		ObjectMinMax(Objects[i],_Min,_Max);
		if(i == 0 || (_Min.x < Min.x))
			Min.x = _Min.x;
		if(i == 0 || (_Min.y < Min.y))
			Min.y = _Min.y;
		if(i == 0 || (_Min.z < Min.z))
			Min.z = _Min.z;
		if(i == 0 || (_Min.x < Min.x))
			Max.x = _Min.x;
		if(i == 0 || (_Min.y < Min.y))
			Max.y = _Min.y;
		if(i == 0 || (_Max.z < Max.z))
			Max.z = _Max.z;
	}
	//
	for (int i=0;i<3;i++)
		FV.a[i] = (Max.a[i]-Min.a[i]);
	double scaleFactor = 0;

	for (int i=0; i<3; i++)
		if(FV.a[i] != 0)
			if(scaleFactor < ((double)1 / FV.a[i]))
				scaleFactor = 1 / FV.a[i];

	for(i = 0; i < Objects.size(); i ++)
	{
		Objects[i]->Points->MovePoints((-(Min.x+Max.x))/2,(-(Min.y+Max.y))/2,(-(Min.z+Max.z))/2);
		Objects[i]->Points->ScalePoints(scaleFactor, scaleFactor, scaleFactor);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::pcStepsChange(TObject *Sender)
{
	this->Caption = "Import 3DS scene - step " + IntToStr(pcSteps->ActivePageIndex + 1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::SyncObjectsList()
{
	int i;

	lvObjectsList->OnChange = NULL;
	lvObjectsList->Clear();
	for(i = 0; i < Objects.size(); i ++)
	{
		lvObjectsList->AddItem("&&&", NULL);//Objects[i]->Alias, NULL);//&&&
		lvObjectsList->Items->Item[i]->Data = (void*)&(ObjectsSelected[i]);
		if(ObjectsSelected[i])
		{
			lvObjectsList->Items->Item[i]->Checked = true;
		}
		else
		{
			lvObjectsList->Items->Item[i]->Checked = false;
		}
	}
	lvObjectsList->OnChange = lvObjectsListChange;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::SyncMaterialsList()
{
	int i;

	lvMaterials->OnChange = NULL;
	lvMaterials->Clear();
	for(i = 0; i < Materials.size(); i ++)
	{
		lvMaterials->AddItem("&&&", NULL);//Materials[i]->Alias,//&&&
		lvMaterials->Items->Item[i]->Data = (void*)&(ObjectsSelected[i]);
		if(Replacements[i] != NULL)
		{
			lvMaterials->Items->Item[i]->SubItems->Add(Replacements[i]->Name);
		}
		else
		{
			lvMaterials->Items->Item[i]->SubItems->Add("<import original>");
		}
	}
	lvMaterials->OnChange = lvMaterialsChange;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::SyncObjects()
{
	int i, j;

	for(i = 0; i < Objects.size(); i ++)
	{
		VisNode->Remove(Objects[i]);
		if(lvObjectsList->Items->Item[i]->Checked)
		{
			*((bool*)lvObjectsList->Items->Item[i]->Data) = true;
			VisNode->AddIndirect(Objects[i]);
		}
		else
		{
			*((bool*)lvObjectsList->Items->Item[i]->Data) = false;
		}
	}
	Restructure();
	TV->CameraEngine.ViewAll(TV->_3DCamera );
	TV->View->InvalidateGL();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::SyncMaterials()
{
	int i, j, k;

	for(i = 0; i < Objects.size(); i ++)
	{
		for(j = 0; j < Objects[i]->PrimitiveCount; j ++)
		{
			for(k = 0; k < Materials.size(); k ++)
			{
				Objects[i]->Primitive[j]->Material = MaterialDefault;
/*				if(Objects[i]->Primitive[j]->MaterialName == Materials[k]->Alias)
				{
					if(Replacements[k])
					{
						Objects[i]->Primitive[j]->Material = Replacements[k]->VM;
					}
					else
					{
						Objects[i]->Primitive[j]->Material = Materials[k];
					}
					break;
				}*/
			}
		}
	}

	TV->View->InvalidateGL();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::FormCreate(TObject *Sender)
{
	ResultObject = new TVisPrimitiveObj(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::FormDestroy(TObject *Sender)
{
	int i;
	for(i = 0; i < Objects.size(); i ++)
	{
		delete Objects[i];
	}

	if (MT)
	{
//		delete TV;
//		delete MT;
//		delete VisNode;
		//delete SelectedItem;
	}
//	delete Result;
}
//---------------------------------------------------------------------------
void TfrmWizard3DSImport::FinishImport()
{
	if(!ResultObject)
		ResultObject = new TVisPrimitiveObj(NULL);
	ResultObject->Init();
	for(int i = 0; i < Objects.size(); i ++)
	{
		if(ObjectsSelected[i])
			MergeObjects(ResultObject, Objects[i]);
	}
	//Obj->Points->ScalePoints(0.001, 0.001, 0.001);
	ResultMaterials.resize(ResultObject->PrimitiveCount);
	for(int i = 0; i < ResultObject->PrimitiveCount; i ++)
	{
		for(int j = 0; j < Replacements.size(); j ++)
		{
/*			if(Materials[j]->Alias == ResultObject->Primitive[i]->MaterialName)
			{
				if(!Replacements[j])
				{
					if(TMetaMaterial::StaticType->RegInfoCount > 0)
					{
						TMetaNode *MN = (TMetaNode *)((TMetaMaterial *)TMetaMaterial::StaticType->RegInfo[0]->Object)->Parent;

						AnsiString ClassName = MN->ChildType;
						if ( !ClassName.IsEmpty() )
							ClassName = MetaNodeCollection->SelectClassIfNeed(ClassName);
						Replacements[j] = (TMetaMaterial *)MetaNodeCollection->AddMetaChild(MN,ClassName,-1,MN->Name);
						TMetaMaterial *MM = Replacements[j];
						MM->Ambient.Color = Materials[j]->ColorAmbient->Color;
						MM->Diffuse.Color = Materials[j]->ColorDiffuse->Color;
						MM->Emission.Color = Materials[j]->ColorEmission->Color;
						MM->Specular.Color = Materials[j]->ColorSpecular->Color;
						MM->Ambient.Alpha = Materials[j]->ColorAmbient->Alpha;
						MM->Diffuse.Alpha = Materials[j]->ColorDiffuse->Alpha;
						MM->Emission.Alpha = Materials[j]->ColorEmission->Alpha;
						MM->Specular.Alpha = Materials[j]->ColorSpecular->Alpha;
						MM->Shininess = Materials[j]->Shininess;
						MM->Face = Materials[j]->Face;
						MM->Name = Materials[j]->Alias;
						MM->CheckFields();
					}
				}           

				ResultMaterials[i] = Replacements[j];
			} */
		}
	}
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::btnNextClick(TObject *Sender)
{
	int aP = pcSteps->ActivePageIndex;
	if(aP < 2)
	{
		aP = (aP + 1) % 3;
		if(aP < 2)
			btnNext->Caption = "Next >>";
		else
			btnNext->Caption = "Finish";
	}
	else
	{
		FinishImport();
	}
	pcSteps->ActivePageIndex = aP;
}
//---------------------------------------------------------------------------
void TfrmWizard3DSImport::PrepareRenderer()
{
	//TVisColor *Col = new TVisColor();
	MT = new TMainTree();
	TV = new TMDITV(this,Renderer,MT);
	TV->Align = alNone;
	TV->Align = alClient;
	VisNode = new TVisNode(NULL);
	//SelectedItem = new TVisMaterial(NULL);

	//SelectedItem->Shininess = 50;
	MT->AddFloor();
	for (int i=0;i<(int)Objects.size();i++)
		VisNode->AddIndirect(Objects[i]);

	MT->ActiveFloor->First.ADR->CustomEnabled = false;
	MT->ActiveFloor->VTRANS->AddIndirect(VisNode);

	TV->Mode = MetaNodeCollection->KernelSupport->_3D_MODE;
	//TV->CameraEngine.Operation(TV,coLA_DEPTH_TRANSLATION_NO_ORIENT,-500);
	TV->CameraEngine.ViewAll(TV->_3DCamera );
}
//---------------------------------------------------------------------------
void __fastcall TfrmWizard3DSImport::lvObjectsListChange(TObject *Sender,
	  TListItem *Item, TItemChange Change)
{
	SyncObjects();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWizard3DSImport::btnPrevClick(TObject *Sender)
{
	int aP = pcSteps->ActivePageIndex;
	if(aP > 0)
	{
		aP = (aP - 1) % 3;
		if(aP < 2)
			btnNext->Caption = "Next >>";
		else
			btnNext->Caption = "Finish";
	}
	pcSteps->ActivePageIndex = aP;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWizard3DSImport::btnRestoreClick(TObject *Sender)
{
	if(!lvMaterials->Selected)
		return;
	int matIndex = lvMaterials->Selected->Index;
	Replacements[matIndex] = NULL;
	SyncMaterialsList();
	SyncMaterials();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWizard3DSImport::btnFindClick(TObject *Sender)
{
	float percent, bestMatch = 100, match;
	TMetaMaterial *bestMaterial = NULL, *current;
	TVisMaterial *toFind;
	int i;
	bool findAll = true;
	if(lvMaterials->Selected)
	{
		i = lvMaterials->Selected->Index;
		toFind = Materials[i];
		findAll = false;
	}

	try
	{
		percent = StrToFloat(EPS->Text);
	}
	catch( ... )
	{
		Application->MessageBoxA("Find material", "Incorrect number format!", MB_OK);
		return;
	}
	percent = (100 - percent) / 100;

	if(findAll)
	{
		for(i = 0; i < Materials.size(); i ++)
		{
			toFind = Materials[i];
			bestMaterial = NULL;
			bestMatch = 100;
			for(int j = 0; j < TMetaMaterial::StaticType->RegInfoCount; j ++)
			{
				current = (TMetaMaterial*)TMetaMaterial::StaticType->RegInfo[j]->Object;//getmaterial[i]
				match = fabs(MaterialMatch(current->VM, toFind, percent));
				if(match < bestMatch && match <= percent)
				{
					bestMatch = match;
					bestMaterial = current;
				}
			}
			Replacements[i] = bestMaterial;
		}
	}
	else
	{
		for(int j = 0; j < TMetaMaterial::StaticType->RegInfoCount; j ++)
		{
			current = (TMetaMaterial*)TMetaMaterial::StaticType->RegInfo[j]->Object;//getmaterial[i]
			match = fabs(MaterialMatch(current->VM, toFind, percent));
			if(match < bestMatch && match < percent)
			{
				bestMatch = match;
				bestMaterial = current;
			}
		}
		Replacements[i] = bestMaterial;
	}
	SyncMaterialsList();
	SyncMaterials();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWizard3DSImport::btnReplaceClick(TObject *Sender)
{
	if(!lvMaterials->Selected)
		return;
	TMetaMaterial *mat;
	mat = (TMetaMaterial *)SelectNode(TMetaMaterial::StaticType, true, true, NULL);
	Replacements[lvMaterials->Selected->Index] = mat;
	SyncMaterialsList();
	SyncMaterials();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWizard3DSImport::lvMaterialsChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
	//SyncMaterials();	
}
//---------------------------------------------------------------------------

