//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "CustomElementV.h"
#include "MYIMPORTV.h"
#include "MDICustomElementV.h"
#include "World.h"
#include "MyGL.h"
#include "MetaClasses.h"

#include "GeomObjV.h"
/*#include <typeinfo.h>

#include "MyGL.h"
#include "Poligon.h"
#include "VisView.hpp"
#include "VisCustomObj.hpp"
#include "MYIMPORTV.h"
#include "LogicNode.h"
#include "UNDO.h"
#include "MetaInterface.h"
//#include "MDIFloorControlV.h"
#include "QuckList.h"
#include "Triangulation.h"
#include "World.h"
#include "AUIV.h"
#include "DrawViewV.h"*/


AnsiString GOB = AnsiString(".GOB");
#pragma package(smart_init)
TClassNode* TCustomMetaElement::StaticType = NULL;
TClassNode* TCustomElement::StaticType = NULL;
//карпова 18 клуб метро 206386 417652 с 10-18,
//Светлана Валентиновна
//алтайская 163

void PrimitiveObjToGeomObj( TVisPrimitiveObj* PObj,TGeomObject* GObj )
{
	GObj->Clear();
/*    GObj->FromPrimitiveObj(PObj);*/
}

void UnpackMaterials(TVisPrimitiveObj *CO,
					 TMDelTList< TPointer<TMetaMaterial> >& MaterialRefs,
					 TMDelTList< TPointer<TMetaTexture> >& TextureRefs)
{
	TMetaTexture *Tex; //::StaticType->RecurrentFindByGUID(  )
	TMetaMaterial *Mat; //::StaticType->RecurrentFindByGUID(  )

	if(CO)
	{
		TStringList* SL = new TStringList();
		for(int i = 0; i < CO->PrimitiveCount; i ++)
		{
			AnsiString MatTex;

			SL->Values["MaterialName"] = "1";
			SL->Values["TextureName"] = "2";
			SL->Delimiter = ';';
			MatTex = SL->DelimitedText;
//			SL->DelimitedText = CO->Primitive[i]->MaterialName;

			if(SL->Values["MaterialName"] != "")
			{
				Mat = (TMetaMaterial*)TMetaMaterial::StaticType->RecurrentFindByGUID( SL->Values["MaterialName"] );
				MaterialRefs.Add( new TPointer<TMetaMaterial>(Mat) );
				CO->Primitive[i]->Material = Mat->VM;
			}
			if(SL->Values["TextureName"] != "")
			{
				Tex = (TMetaTexture*)TMetaTexture::StaticType->RecurrentFindByGUID( SL->Values["TextureName"] );
				TextureRefs.Add( new TPointer<TMetaTexture>(Tex) );
				CO->Primitive[i]->Texture = Tex->VT;
			}
		}
		delete SL;
	}
}

void MergeObjects(TVisPrimitiveObj *dest, TVisPrimitiveObj *src)
{
	int i, j;
	long vertBase = dest->Points->Count;
	int element;
	dest->Points->Add(src->Points);
	for(i = 0; i < src->PrimitiveCount; i ++)
	{
		element = dest->AddPrimitiveArray(GL_TRIANGLES);
		for(j = 0; j < src->Primitive[i]->Count; j ++)
		{
			dest->Primitive[element]->AddIndex(vertBase + src->Primitive[i]->Indices[j]);
//			dest->Primitive[element]->MaterialName = src->Primitive[i]->MaterialName;
			dest->Primitive[element]->Material = src->Primitive[i]->Material;
		}
	}
}

//---------------------------TCustomMetaElement-------------------------

TVisPrimitiveObj* TCustomMetaElement::GetVisObject()
{
	if (!FPrimitiveObject)
	{
		FPrimitiveObject = new TVisPrimitiveObj(NULL);
		if (!DirectoryExists(DataDir))
			if (!ForceDirectories(DataDir))
			{
				ErrorMsg("Can not open file.");
				Application->Terminate();
			}
		LoadGeometry(DataDir+SL+Name+GOB, FPrimitiveObject);
		//UnpackMaterials(FPrimitiveObject, MaterialRefs, TextureRefs);
	}
	return FPrimitiveObject;
}

TMyObject* TCustomMetaElement::CreateFunction()
{
	TCustomMetaElement *newCE = new TCustomMetaElement();
	return new TCustomMetaElement();
}

TCustomMetaElement::TCustomMetaElement(TMetaNode *Parent,int _ID,const AnsiString& Name)
	:TMetaElement(Parent,_ID,Name)
{
	RegisterNewClass< TMetaElement, TCustomMetaElement >(this,false,&CreateFunction);
	FPrimitiveObject = NULL;
	ImageIndex=iiCustomMetaElement;
};

TCustomMetaElement::TCustomMetaElement()
{
	RegisterNewClass< TMetaElement, TCustomMetaElement >(this,false,&CreateFunction);
	FPrimitiveObject = NULL;
	ImageIndex=iiCustomMetaElement;
}

TCustomMetaElement::~TCustomMetaElement()
{
	if (FPrimitiveObject)
	{
		delete FPrimitiveObject;
		FPrimitiveObject = NULL;
	}
}


void TCustomMetaElement::SetName(const AnsiString &newName)
{
	AnsiString Dir = MainDir+SL+DataDirName;
	//-------------------------------------
	if (!FileExists(Dir+SL+Name+GOB) || IsNew)
	{
		FILE *F = fopen((Dir+SL+Name+GOB).c_str(),"w");
		fclose(F);
		IsNew = false;
	}
	else
	{
		int attr = FileGetAttr(Dir+SL+Name+GOB);
		if (attr & faReadOnly)
			FileSetAttr(Dir+SL+Name+GOB,attr & !faReadOnly);
	}
	if (RenameFile(Dir+SL+Name+GOB,Dir+SL+newName+GOB))
	{
		TMetaNode::SetName(newName);
		if (newName != Name)
			RenameFile(Dir+SL+newName+GOB,Dir+SL+Name+GOB);
	}
}

void TCustomMetaElement::Assign(TMyObject* Obj)
{
	AnsiString Dir = MainDir+SL+DataDirName;
	TMetaElement::Assign(Obj);
	CopyFile((Dir+SL+Obj->Name+GOB).c_str(),(Dir+SL+Name+GOB).c_str(),false);
    VisObject->Assign( ((TCustomMetaElement*)Obj)->VisObject );
}

void TCustomMetaElement::SaveData(FILE *F) const
{
	TMetaElement::SaveData(F);

	if (FPrimitiveObject)
	{
		if (!DirectoryExists(DataDir))
			if (!ForceDirectories(DataDir) || !CHECK_FILE_SAVE(DataDir+SL+Name+GOB) )
			{
				ErrorMsg("Can not create file.");
				Application->Terminate();
			}
		SaveGeometry(DataDir+SL+Name+GOB,FPrimitiveObject);
		delete FPrimitiveObject;
		FPrimitiveObject = NULL;
	}

}

void TCustomMetaElement::WriteData(TMemoryStream *MS) const
{
	TMetaElement::WriteData(MS);
	/* TODO : Add Write logic */

	if (FPrimitiveObject)
	{
		if (!DirectoryExists(DataDir))
			if (!ForceDirectories(DataDir) || !CHECK_FILE_SAVE(DataDir+SL+Name+GOB) )
			{
				ErrorMsg("Can not create file.");
				Application->Terminate();
			}

		SaveGeometry(DataDir+SL+Name+GOB,FPrimitiveObject);
		delete FPrimitiveObject;
		FPrimitiveObject = NULL;
	}

}

void TCustomMetaElement::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDICustomElement(_Owner,this);
    #endif
}


TMyObject* TCustomElement::CreateFunction()
{
    return new TCustomElement();
}


/*TCustomElement::TCustomElement(TMainTree *_MyTree,TMetaNode *_Meta)
    :TElement(_MyTree,_Meta)
{
    RegisterNewClass< TElement, TCustomElement >(this,false,&CreateFunction);
    if (typeid(*_Meta)!=typeid(TCustomMetaElement))
    {
        Application->MessageBox("CustomMetaElement is expected, but Unknown got. Application will be terminated.","Error");
        Application->Terminate();
        return;
    }

    OBJ = new TVisPrimitiveObj(NULL);
    MGT->AddRender(1,this,OBJ);
	OBJ->Transformation->Order = toTraRotSca;
    OBJ->Init();
    OBJ->AddPrimitiveObj(CustomMetaElement->CustomObject);
    CurrentEnabled = true;
    CustomEnabled = true;

/*    try
    {
        AnsiString Dir = MainDir+SL+DataDirName;
        if (FileExists(Dir+SL+CustomMetaElement->Name+GOB))
            LoadGeometry(Dir+SL+CustomMetaElement->Name+GOB,OBJ);
    }
	__except(EXCEPTION_EXECUTE_HANDLER)
    {
        Application->MessageBox("Can not open file","Error");
    }  */

    //return this
    //return this
/*    CreateView();
}*/

TCustomElement::TCustomElement()
{
	RegisterNewClass< TElement, TCustomElement >(this,false,&CreateFunction);
	OBJ = new TVisPrimitiveObj(NULL);
	OBJ->Init();
	OBJ->Transformation->Order = toTraRotSca;
//	FPrimitiveObject = new TVisPrimitiveObj();
}

void TCustomElement::SetMetaObject(TMyRegObject* aMetaObject)
{
	TElement::SetMetaObject(aMetaObject);
	OBJ->Assign( ((TCustomMetaElement*)aMetaObject)->VisObject );
}


bool TCustomElement::CheckFields()
{
	if (!TElement::CheckFields())
        return false;
    return true;
	try
	{
		AnsiString Dir = MainDir+SL+DataDirName;
		if (FileExists(Dir+SL+CustomMetaElement->Name+GOB))
			LoadGeometry(Dir+SL+CustomMetaElement->Name+GOB,OBJ);
		return true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		Application->MessageBox("Can not open file","Error");
		return false;
	}
}



//---------------------------TCustomElement-----------------------------------------------
TCustomElement::~TCustomElement()
{
    RemoveRenderFromTree();
    //delete FGeomObject;
    //FGeomObject = NULL;
	delete OBJ;
}

TVisMathVector _min,_max;
void TCustomElement::StandartCreateView()
{
	//OBJ->Init();
	//GeomObject->ToPrimitiveObj2(OBJ,coSOLID,rtSMOOTH);
	OBJ->Enabled = true;
	TIntVec UseSize(AbsSize);
	if (RenPars[MyTree->ModeIndex].OverSizeMode)
		UseSize += RenPars[MyTree->ModeIndex].OverSize;
  //-----------------------------
	ObjectMinMax(OBJ,_min,_max);
	TVisMathVector rSize = VisMathVec(TIntVec(_max) - TIntVec(_min));
	if (rSize.x==0||rSize.y==0||rSize.z==0)
		return;
	OBJ->Points->MovePoints(-(_max.x+_min.x)/2,-(_max.y+_min.y)/2,-(_max.z+_min.z)/2);
	//----------------------------------------------------
	if (SlopePlus!=ZEROINTVEC&&SlopeMinus!=ZEROINTVEC)
		SlopeMinMax(OBJ,SlopePlus,SlopeMinus,_min,_max);
	//----------------------------------------------------
	if (UseSize.x&&UseSize.y&&UseSize.z)
		OBJ->Points->ScalePoints(UseSize.x/rSize.x,UseSize.y/rSize.y,UseSize.z/rSize.z);
	//----------------------

	ProcessTexturing();
}

void TCustomElement::TexturePrimitive(TVisPrimitiveObj* Obj,TVisPrimitiveArray* Array,TRenderParam& RP, int Index)
{
	Array->Material = RP.GetMaterial(Index);
	Array->Texture = RP.GetTexture(Index);
	TMetaTexture* MTex = RP.GetMetaTex(Index);
	Array->Textured = (Array->Texture!=NULL);

	if (Array->Textured)
	{
		Obj->TextureFlags->ScaleX = 1/MTex->RealSizeX;//MyMeta->MTF.Scale.x;
		Obj->TextureFlags->ScaleY = 1/MTex->RealSizeY;//MyMeta->MTF.Scale.y;
		Obj->TextureFlags->ShiftX = MyMeta->MTF.Shift.x/MTex->RealSizeX;
		Obj->TextureFlags->ShiftY = MyMeta->MTF.Shift.y/MTex->RealSizeY;
		Obj->TextureFlags->Mode = (TVisTextureMode)MyMeta->MTF.Mode;
		//----------------------------------------------------------------------
		for (int i=0;i<Array->Count;i++)
			Obj->Points->SharePosition[Array->Indices[i]] = false;
		if (RP.TexCenter != ZEROINTVEC)
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = VisMathVec( TIntVec(Obj->Points->PointVec[Array->Indices[i]]) - RP.TexCenter );
		if (RP.TexAngle != ZEROINTVEC)
		{
			TVisMathVector MinusAngle = VisMathVec( RP.TexAngle*(-1) );
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = RotateAroundVMV(Obj->Points->PointVec[Array->Indices[i]],MinusAngle,ZEROVEC);
		}
		//----------------------------------------------------------------------

		//calc texture points
		for (int i=0;i<Array->Count;i++)
			Obj->CalcTexturePoint(Array->Indices[i]);

		//----------------------------------------------------------------------
		if (RP.TexAngle != ZEROINTVEC)
		{
			TVisMathVector Angle = VisMathVec(RP.TexAngle);
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = RotateAroundVMV(Obj->Points->PointVec[Array->Indices[i]],Angle,ZEROVEC);
		}
		if (RP.TexCenter != ZEROINTVEC)
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = VisMathVec( TIntVec(Obj->Points->PointVec[Array->Indices[i]]) + RP.TexCenter );
		//----------------------------------------------------------------------
	}
	else
	{   /*
		for (int i=0;i<Array->Count;i++)
			Obj->Points->TextureVec[Array->Indices[i]] = ZEROVEC;
		*/
	}
}

void TCustomElement::ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID)
{
	TMetaMaterial *Mat = RenPars[MyTree->ModeIndex].GetMetaMat(PrimID);
	TMetaTexture *Tex = RenPars[MyTree->ModeIndex].GetMetaTex(PrimID);
	if(!Object)
		return;
	for(int i = 0; i < OBJ->PrimitiveCount; i ++)
	{
		if(Object->Is( TMetaMaterial::StaticType ))
		{
			if(RenPars[MyTree->ModeIndex].GetMetaMat(i) == Mat)
			{
				RenPars[MyTree->ModeIndex].SetMetaMat((TMetaMaterial*)Object, i);
			}
		}
		else if(Object->Is( TMetaTexture::StaticType ))
		{
			if(RenPars[MyTree->ModeIndex].GetMetaMat(i) == Mat)
			{
				RenPars[MyTree->ModeIndex].SetMetaTex((TMetaTexture*)Object, i);
			}
		}
	}
}
	/*

void TCustomElement::ProcessTexturing()
{
	TRenderParam *rp;
	if(OBJ)
	{
		rp = new TRenderParam();
		for(int i = 0; i < OBJ->PrimitiveCount; i ++)
		{
			rp->Texture = NULL;
			rp->Material = ((TCustomMetaElement*)MyMeta)->MaterialRefs[i].ADR;
			TexturePrimitive(OBJ, OBJ->Primitive[i], *rp);
		}
		delete rp;
	}
}
	*/

/*void Triangulate(THoledPolygon* HP,TMDelTList<TIntVec>* Tri)
{
	TMTList<TIntVec>* tri1 = Delone.Triangulate(HP);
    for (int i=0;i<tri1->Count;i++)
        Tri->Add( new TIntVec(tri1->Val(i)) );
} */



