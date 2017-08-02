 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#include "VisPrimitiveObj.hpp"
#include "Select.h"
#include "ElementV.h"
#include "IntExplorerV.h"
#include "MYIMPORTV.h"
#include "..\GeomObject\TGObject.h"
#include "..\GeomObject\TGPrimitive.h"
#include "..\GeomObject\Misc.h"

#pragma package(smart_init)

TVisPrimitiveObj *TSelection::RotationTool = NULL;
TVisPrimitiveObj *TSelection::UpDownTool = NULL;
int TSelection::UpDownToolPrimitives = 0;
int TSelection::RotationToolPrimitives = 0;
TVisMaterial *TSelection::Red = NULL;
TVisMaterial *TSelection::Green = NULL;
TVisMaterial *TSelection::Blue = NULL;

TElementQueueCollection* FSelectionCollection = NULL;
TSelection* FSelection = NULL;

TElementQueueCollection& GetSelectionCollection()
{
	if (!FSelectionCollection)
		FSelectionCollection = new TElementQueueCollection();
	return *FSelectionCollection;
}

TSelection& GetSelection()
{
	if (!FSelection)
		FSelection = new TSelection();
	return *FSelection;
}

TSelection::TSelection()
{
    Material = new TVisMaterial(NULL);
    Material->ColorDiffuse->Color = clBlue;
    SelectionCollection.Queues.Add(this);
}

TSelection::~TSelection()
{
    SelectionCollection.Queues.Remove(this);
    delete Material;
    FObjects.RealClear();
}

void TSelection::Render(TVisView* aView)
{
	if (NeedToCreateSelView)
	{
		CreateSelView();
		NeedToCreateSelView = false;
	}
	if (NeedToPositionSelView)
	{
		PositionSelView();
		NeedToPositionSelView = false;
	}
	if(FObjects.Count > 0 && FObjects[0].PrimitiveCount < 1)
		CreateSelView();
	Process();
	float width;
	glGetFloatv(GL_LINE_WIDTH,&width);
	if ( width!=3 )
		glLineWidth(3);

    for ( bool OK = FObjects.Start();OK;OK = FObjects.Next() )
        FObjects.GetCurrent()->Render(aView);
            
    if ( width!=3 )
        glLineWidth(width);
}

int TSelection::Test(TObject *Object, int PrimitiveID)
{
	for(int i = 0; i < FObjects.Count; i ++)
	{
		if((&(FObjects[i])) == ((TVisPrimitiveObj *)Object))
		{
			if(PrimitiveID >= FObjects[i].PrimitiveCount - UpDownToolPrimitives)
			{
				return UPDOWN_TOOL;
			}
			else if((PrimitiveID > 0) &&
					(PrimitiveID < FObjects[i].PrimitiveCount - UpDownToolPrimitives))
				return ROTATION_TOOL;
			else
				return NO_HIT;
		}
	}
	return NO_HIT;
}

void TSelection::Add(TElement* Element)
{
    
    if (FindElementInPsevdoPointerList(&ElementList,Element) == -1)
    {
        ElementList.Add( new TPsevdoPointer<TElement>());
        ElementList.Last()->FAdr = Element;
        ElementList.Last()->TargetID = Element->IntId;
		FObjects.Add( new TVisPrimitiveObj(NULL) );
        FObjects.Last()->AutoCalcNormals=false;
        FObjects.Last()->Transformation->Order = toTraRotSca;
        FObjects.Last()->Transformation->Rotation->Order = roZXY;
//        FObjects.Last()->Material = Material;
		RegisterCreateSelView(/*Element,FObjects.Last()*/);
		OnChange();
	}
}

void TSelection::Changed(TElement* Element)
{
	RegisterCreateSelView(/*Element,FObjects.Last()*/);
}

void TSelection::Remove(TElement* Element)
{
	int index = FindElementInPsevdoPointerList(&ElementList,Element);
	if ( index != -1)
	{
		ElementList.Delete(index);
		FObjects.RealDelete(index);
		OnChange();
	}
}

void TSelection::Delete(int index)
{
    ElementList.Delete(index);
    FObjects.RealDelete(index);
	OnChange();
}

void TSelection::Clear()
{
    if (ElementList.Count>0)
    {
        ElementList.Clear();
        FObjects.RealClear();
        OnChange();
    }
}

void TSelection::OnChange()
{
    if (IntExplorer)
        PostMessage( IntExplorer->Handle,WM_NOTIFY, SELECTION_CHANGED,0);
}

void TSelection::RegisterCreateSelView()
{
	NeedToCreateSelView = true;
	RegisterPositionSelView();
}

void TSelection::UnRegisterCreateSelView()
{
	NeedToCreateSelView = false;
}

void TSelection::RegisterPositionSelView()
{
	NeedToPositionSelView = true;
}

void TSelection::CreateSelView()
{
	TGeomObject g;

	if(!Red)
	{
		Red = new TVisMaterial(NULL);
		Red->ColorDiffuse->Color = clRed / 1.5;
		Red->ColorAmbient->Color = clRed / 1.5;
		Red->Shininess = 5;
	}
	if(!Green)
	{
		Green = new TVisMaterial(NULL);
		Green->ColorDiffuse->Color = clGreen;
		Green->ColorAmbient->Color = clGreen;
		Green->Shininess = 5;
	}
	if(!Blue)
	{
		Blue = new TVisMaterial(NULL);
		Blue->ColorDiffuse->Color = clBlue;
		Blue->ColorAmbient->Color = clBlue;
		Blue->Shininess = 5;
	}

	if (!RotationTool)
	{
		RotationTool = new TVisPrimitiveObj(NULL);
		if (FileExists(MainDir + "\\RotationTool.GOB"))
		{
			RotationTool->Init();
			LoadGeometry(MainDir + "\\RotationTool.GOB", RotationTool);
			for(int i = 0; i < RotationTool->PrimitiveCount; i ++)
			{
				RotationTool->Primitive[i]->Material = Red;
			}
			RotationTool->Primitive[0]->Material = Green;
		}
		else
		{
			g.Clear();
			RotationTool->Init();
			PrimitiveRoundArrow(&g, 1, 0);
			ConstructVCO(RotationTool, &g);
		}
		RotationToolPrimitives = RotationTool->PrimitiveCount;
	}
	if (!UpDownTool)
	{
		UpDownTool = new TVisPrimitiveObj(NULL);
		if (FileExists(MainDir + "\\UpDownTool.GOB"))
		{
			UpDownTool->Init();
			LoadGeometry(MainDir + "\\UpDownTool.GOB", UpDownTool);
			for(int i = 0; i < UpDownTool->PrimitiveCount; i ++)
			{
				UpDownTool->Primitive[i]->Material = Red;
			}
			UpDownTool->Primitive[0]->Material = Green;
		}
		else
		{
			g.Clear();
			UpDownTool->Init();
			PrimitivePyramid(&g, 1, 1, 5);
			ConstructVCO(UpDownTool, &g);
		}
		UpDownToolPrimitives = UpDownTool->PrimitiveCount;
	}
	if (ElementList.Count>0)
	{
		FObjects[0].ClearAll();
		FObjects[0].Init();
		::CreateSelView(ElementList[0].ADR,&FObjects[0], RotationTool, UpDownTool);
		FObjects[0].Primitive[0]->Material = Blue;
	}
}

void TSelection::PositionSelView()
{
	if (ElementList.Count>0)
	{
		AssignVisVec(*(FObjects[0].Transformation->Rotation),ElementList[0].ADR->AbsAngle);
		AssignVisVec(*(FObjects[0].Transformation->Translation),ElementList[0].ADR->AbsPos);
		//::CreateSelView(ElementList[0],FObjects[0]);
	}
}

