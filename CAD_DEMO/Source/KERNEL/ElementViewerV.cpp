//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#pragma hdrstop

#include "ElementViewerV.h"
#include "ElementV.h"
#include "QuckList.h"
#include "MDITVV.h"
#include "World.h"
#include "Select.h"
#include "UNDO.h"
#include "MySupportV.h"
#include "MultiElementV.h"
#include "AUIV.h"

#include "LuaModuleV.h"
#include "LuaEnvV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TElementViewer *ElementViewer = NULL;
//---------------------------------------------------------------------------
__fastcall TElementViewer::TElementViewer(TComponent* Owner)
		: TForm(Owner)
{
		//Align = alClient;
		FShowElement = NULL;
		FShowMetaElement = NULL;
}

void __fastcall TElementViewer::SetShowElement(TElement *NewElement)
{
	FShowElement = NewElement;
	if (FShowElement)
	{
		Element = FShowElement;
		MT = new TMainTree();
		MT->AddFloor(-1);
		TV = new TMDITV(this,pView,MT);
		TV->Parent = this;
		Start();
	}
	else
	{
		if (TV)
		{
			delete TV;
			TV = NULL;
		}
		if (MT)
		{
			delete MT;
			MT=NULL;
		}
	}
}

void __fastcall TElementViewer::SetShowMetaElement(TMetaElement *NewElement)
{
	FShowMetaElement = NewElement;
	if (FShowMetaElement)
	{
		AnsiString CN = CutMeta( AnsiString(typeid(*(ShowMetaElement)).name()).Trim() );
		Element = CreateElementFunction(MT,ShowMetaElement);
		MT = new TMainTree();
		MT->AddFloor(-1);
		TV = new TMDITV(this,pView,MT);
		TV->Parent = this;		
		Start();
	}
	else
	{
		if (TV)
		{
			delete TV;
			TV = NULL;
		}
		if (MT)
		{
			delete MT;
			MT=NULL;
		}
	}
}

__fastcall TElementViewer::~TElementViewer()
{
		if (ShowElement || ShowMetaElement)
		{
				SelectionCollection.Enabled=true;
				MT->RemoveElement(Element);
				if (ShowElement)
				{
						Element->UserChangePosition(ZEROINTVEC,ZEROINTVEC);
						Element->SetMyHoleFor(NULL);
				}
				else
					KillElement(Element);
				Element = NULL;
//        MT->Clear();
//        delete MT;
				TV->MyMT = NULL;
		}
}

//---------------------------------------------------------------------------
void TElementViewer::Start()
{
		//Top =  Screen->Height/2-Height/2;
		//Left = Screen->Width/2 -Width/2;
		//--------------------------------------------------------------------------
		if (ShowElement || ShowMetaElement)
		{
				MT->AddFirst(Element);
				MT->RenderLand = true;
				TV->Mode = MetaNodeCollection->KernelSupport->_3D_MODE;
				TV->EL = Element;

				AUI.CameraEngine.ViewAll(TV->View->Camera);
				TVisPerspectiveCamera* PC = (TVisPerspectiveCamera*)TV->View->Camera;
				TIntVec NEW_POS = TIntVec(PC->LA_Position->AsMathVector) - TIntVec(PC->LA_LookAt->AsMathVector);
				AssignVisVec(*PC->LA_LookAt,ZEROINTVEC);
				AssignVisVec(*PC->LA_Position,NEW_POS);

				if (Element->MyRender())
				{
						Element->MyRender()->Transformation->Translation->AsMathVector=ZEROVEC;
						Element->MyRender()->Transformation->Rotation->AsMathVector=ZEROVEC;

						if ( Element->Is (TMultiElement::StaticType ) )
						{
							((TMultiElement*)Element)->VTRANS->Transformation->Translation->AsMathVector=ZEROVEC;
							((TMultiElement*)Element)->VTRANS->Transformation->Rotation->AsMathVector=ZEROVEC;
						}
				}
				SelectionCollection.Enabled=false;
		}
//		ShowModal();
}

void __fastcall TElementViewer::FormActivate(TObject *Sender)
{
		if (ShowElement || ShowMetaElement)
		{
				AUI.ActivateView(TV);
				SelectionCollection.Enabled=false;
		}
}
//---------------------------------------------------------------------------
