//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

//#include "MetaNodeCollectionV"
#include "MainToolsV.h"
#include "IntExplorerV.h"
#include "CatalogUnitV.h"
#include "ElementV.h"
#include "AUIV.h"
#include "World.h"
#include "MDI3DV.h"
#include "Select.h"
#include "Driver.h"
#include "Math.h"
#include "MetaClasses.h"
//#include "BaseToolV.h"
#include "BindedBaseToolEditV.h"
#include "BindedBlockEditV.h"
#include "BindedGoEditV.h"
#include "ToolFormV.h"
#include "MetaToolV.h"
#include "Windows.hpp"

#pragma package(smart_init)
TClassNode* TDialogBaseTool::StaticType = NULL;
TClassNode* TBindedBaseTool::StaticType = NULL;
TClassNode* TBindedStateBlock::StaticType = NULL;
TClassNode* TBindedActionBlock::StaticType = NULL;
TClassNode* TBindedConditionalBlock::StaticType = NULL;

TBindedBaseTool* CurrentTool = NULL;
//---------------------------------------------------------------------------

void RegisterBaseTool()
{
    TBindedStateBlock();
    TBindedActionBlock();
    TBindedConditionalBlock();
    TBindedBaseTool();
    TMDelTList<TBaseBlock>();
}
#pragma startup RegisterBaseTool

void RegisterMainTools()
{
//    IntExplorer->FTools.Matrix.Add( new TMTList<TBaseTool>() );
//    IntExplorer->FTools.ActiveIndices.Add( new int(0) );
	TMetaTool* DEFAULT = new TMetaTool( *(new TDefaultCreateTool()) );

    TMetaTool* MAIN = new TMetaTool( *(new TMainTool()) );

    IntExplorer->ControlList.Tools.Insert(0, DEFAULT );
    IntExplorer->ControlList.Tools.Insert(1, MAIN );
    IntExplorer->ControlList.ActiveIndex = 1;
}

void UnRegisterMainTools()
{
    delete IntExplorer->ControlList.Tools.Items[0];
    delete IntExplorer->ControlList.Tools.Items[1];
}

TElement* IdentifyElement(TVisRender* VR)
{
    TElement *El = NULL;
    if (VR)
    {
        while(VR->Node!=NULL)
            VR = VR->Node;
        El = (TElement *)TElement::StaticType->RecurrentFindByRender(VR);
    }
/*    if (El)
        if ( El->Is(TLabel3D::StaticType) )
			El = (TElement*)(El->Parent);*/

/*    if (!El && SelObj==VR)
        El = Element;

    if (!El && ErrObj==VR)
        El = ErrElement;*/

    if (El && AUI.ActiveWorld && AUI.ActiveWorld->Head && El!=AUI.ActiveWorld->Head
//        && El->MyMeta != MetaNodeCollection->FirstPlatform
        && El->Parent != AUI.ActiveWorld->Head)
        return El;
    return NULL;
}

TDefaultCreateTool::TDefaultCreateTool()
{
    ImageId = -1;
    Description = "Creating new element";
    Blocks.Clear();
    TDialogBaseTool::AddStateBlock(State1, 0, Mouse_Move, btMenu, "State0");
    TDialogBaseTool::AddActionBlock(Action2, 1, btMenu, "Create and position object");
    TDialogBaseTool::AddStateBlock(State3, 2, Mouse_Move, btNone, "NOne");
    TDialogBaseTool::AddActionBlock(Action4, 3, btNone, "None");
    TDialogBaseTool::AddConditionalBlock(Conditional5, 4, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action6, 5, btMenu, MSG_6);

	AddGoToBlockId( 0, 1, Mouse_Move, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Down, mbLeft);
	AddGoToBlockId( 3, 4);
    AddGoToBlockId( 4, 1, 5);
    AddGoToBlockId( 5, 0);

	EscCommands = EscAction;

    CustomElement = NULL;
    MetaType = NULL;
}

void TDefaultCreateTool::State1()
{
    UIP.Center = ZEROINTVEC;
}

void TDefaultCreateTool::Action2()
{
    MetaType = IntExplorer->MetaCatalogUnit->Associated;
    if ( !MetaType->Is( TMetaElement::StaticType ) &&
         !MetaType->Is( TMetaTexture::StaticType ) )
        throw EMyException("!IntExplorer->MetaCatalogUnit->Associated->Is( TMetaElement && TMetaTexture)");

    if ( MetaType->Is( TMetaElement::StaticType ) )
    {
        if ( CustomElement != NULL )
        {
            KillElement( CustomElement );
            CustomElement = NULL;
        }
        UndoStack.OpenSession("Creating" + IntExplorer->MetaCatalogUnit->Associated->Name);
		CustomElement = CreateElementFunction(AUI.ActiveWorld, IntExplorer->MetaCatalogUnit->Associated );
        Driver.Init(CustomElement, true, AUI.ActiveWorld->ActiveFloor->FirstElement);
    //    MGT->AddRender(1,CustomElement,CustomElement->MyRender());
//        State3();
	} else if ( MetaType->Is( TMetaTexture::StaticType ) ) {
    }
}

void TDefaultCreateTool::State3()
{
//    UIP.Center.x = 135 ;
//    TMDI3D* MDI = (TMDI3D*)UIP.Sender;
    if ( MetaType->Is( TMetaElement::StaticType ) )
    {
		A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ + CustomElement->AbsSize.z/2 );
        PlaneN = TIntVec(0, 0, 1);
        CustomElement->AbsPos = UIP.NewCursorPos;
        Driver.Check();
    }
}

void TDefaultCreateTool::Action4()
{
	int PID;
	if ( MetaType->Is( TMetaElement::StaticType ) )
	{
		if ( !Driver.Stop() )
			AUI.ActiveWorld->AutoConnect(AUI.ActiveWorld->ActiveFloor->FirstElement, CustomElement);
		CustomElement = NULL ;
	}
		else if ( MetaType->Is( TMetaTexture::StaticType ) )
		{
				TMDI3D* MDI = Sender;
				//TList* RenderList = new TList;
				TObject *Object;

				MDI->View->SelectHeight = 1;
				MDI->View->SelectWidth = 1;
				A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ );
				PlaneN = TIntVec(0, 0, 1);
				TIntVec Vec = Sender->ProjectToScreen(UIP.NewCursorPos);
		//Alex

				MDI->WinPoint.x = floor(Vec.x);
				MDI->WinPoint.y = floor(Vec.y);
				PID = MDI->View->GetObj(Vec.x, Vec.y, Object);
				TElement* El = IdentifyElement((TVisRender*)Object);
				if ( El != NULL )
				{
						if ( El->DynamicType != NULL )
							if ( El->DynamicType->Name == "TLabel3D" )
								if ( El->Parent != NULL )
									El = (TElement*)El->Parent;
						TIntVec Res = MDI->GettedPoint;
//						MDI->GetPoint(Vec.x, Vec.y, Res);
						UndoStack.OpenSession("Set texture");
						El->ApplyObject(Res, (TVisRender*)Object, IntExplorer->MetaCatalogUnit->Associated, PID);
                        MySelection.Clear();
						MySelection.Add(El);
				}

				/*
				MDI->View->GetColorSelection(Vec.x, Vec.y, RenderList);
				for ( int i = 0; i < RenderList->Count; i++ )
				{
						TElement* El = IdentifyElement((TVisRender*)RenderList->Items[i]);
						if ( El != NULL )
						{
								TIntVec Res;
								MDI->GetPoint(Vec.x, Vec.y, Res);
								UndoStack.OpenSession("Set texture");
								El->ApplyObject(Res, (TVisRender*)RenderList->Items[i], IntExplorer->MetaCatalogUnit->Associated);
								MySelection.Add(El);
								break;
						}
				}

				RenderList->Clear();
				delete RenderList;
				*/
		}
//    ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object);
		if ( UndoStack.Opened() )
				UndoStack.CloseSession();
}

bool TDefaultCreateTool::Conditional5()
{
    if ( UIP.Shift.Contains(ssCtrl) )
        return true;
	else
        return false;
}

void TDefaultCreateTool::Action6()
{
    IntExplorer->ControlList.ActiveIndex = 1;
}

void TDefaultCreateTool::OnRender()
{
	if ( CustomElement == NULL )
        return;
    TMDI3D* MDI = Sender;
    if ( MetaType->Is( TMetaElement::StaticType ) )
    {
        CustomElement->Render(MDI->View);
    }
}

void TDefaultCreateTool::EscAction()
{
	if ( MetaType!= NULL && MetaType->Is( TMetaElement::StaticType ) )
		if ( CustomElement != NULL )
		{
			Driver.Clear();
			KillElement( CustomElement );
            CustomElement = NULL;
        }
    if ( UndoStack.Opened() )
		UndoStack.BreakSession();
}

TDefaultCreateTool::~TDefaultCreateTool()
{
}
//----------------------------MainTool------------------------------------------
TMainTool::TMainTool()
{
/*//    EpsValue = 5;//pixels
	ImageId = -1;
    Description = "Main tool";
    Blocks.Clear();

    TDialogBaseTool::AddStateBlock(State1, 0, Mouse_Move, btMenu, "End");
    TDialogBaseTool::AddActionBlock(Action2, 1, btNone, "None");
    TDialogBaseTool::AddConditionalBlock(Condition3, 2, btMenu, "None");
    TDialogBaseTool::AddStateBlock(State4, 3, Mouse_Move, btMenu, MSG_5);
    TDialogBaseTool::AddConditionalBlock(Condition5, 4, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action6, 5, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action7, 6, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action8, 7, btMenu, "Move");
    TDialogBaseTool::AddStateBlock(State9, 8, Mouse_Move, btNone, "None");
    TDialogBaseTool::AddConditionalBlock(Condition5, 10, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action12, 11, btMenu, "Select");
    TDialogBaseTool::AddStateBlock(State15, 14, Mouse_Move, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action16, 15, btNone, "None");

    TDialogBaseTool::AddActionBlock(DeleteAction, 100, btMenu, "Delete");
    TDialogBaseTool::AddActionBlock(SelectAllAction, 101, btMenu, "Выделить всё");
	TDialogBaseTool::AddConditionalBlock(Condition5, 102, btNone, "None");
    TDialogBaseTool::AddActionBlock(CopyAction, 103, btNone, "None");
    TDialogBaseTool::AddStateBlock(CopyState, 104, Mouse_Move, btNone, "None");
    TDialogBaseTool::AddActionBlock(UndoAction, 105, btNone, "None");
	TDialogBaseTool::AddActionBlock(RedoAction, 106, btNone, "None");

	AddGoToBlockId(0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId(1, 2);
    AddGoToBlockId(2, 14, 3);
	AddGoToBlockId(3, 4, Mouse_Up, mbLeft);
    AddGoToBlockId(4, 6, 5);
    AddGoToBlockId(5, 6);
    AddGoToBlockId(6, 0);
    AddGoToBlockId(14, 7, Mouse_Move, mbLeft);
    AddGoToBlockId(14, 10, Mouse_Up, mbLeft);
    AddGoToBlockId(10, 11, 4);
    AddGoToBlockId(7, 8);
    AddGoToBlockId(8, 15, Mouse_Up, mbLeft);
    AddGoToBlockId(15, 0);
    AddGoToBlockId(11, 0);

    AddGoToBlockId(0, 100, Key_Down, VK_DELETE);
    AddGoToBlockId(100, 0);
    AddGoToBlockId(0, 102, Key_Down, 'a');
    AddGoToBlockId(0, 102, Key_Down, 'A');
    AddGoToBlockId(102, 101, 0);
    AddGoToBlockId(101, 0);

    AddGoToBlockId(0, 103, Key_Down, 'c');
    AddGoToBlockId(0, 103, Key_Down, 'C');
	AddGoToBlockId(103, 104);
    AddGoToBlockId(104, 0, Mouse_Down, mbLeft);

    AddGoToBlockId(0, 105, Key_Down, 'z');
	AddGoToBlockId(0, 105, Key_Down, 'Z');
    AddGoToBlockId(105, 0);
    AddGoToBlockId(0, 106, Key_Down, 'r');
    AddGoToBlockId(0, 106, Key_Down, 'R');
	AddGoToBlockId(106, 0);

    EscCommands = _EscCommands;

    FirstClickElement = NULL;
    UIP.Center = ZEROINTVEC;*/

//    EpsValue = 5;//pixels
    ImageId = -1;
    Description = "Main tool";
    Blocks.Clear();

    TDialogBaseTool::AddStateBlock(State1, 0, Mouse_Move, btMenu, "End");
    TDialogBaseTool::AddActionBlock(Action2, 1, btNone, "None");
    TDialogBaseTool::AddConditionalBlock(Condition3, 2, btMenu, "None");
    TDialogBaseTool::AddStateBlock(State4, 3, Mouse_Move, btMenu, MSG_5);
    TDialogBaseTool::AddConditionalBlock(Condition5, 4, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action6, 5, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action7, 6, btNone, "None");
	TDialogBaseTool::AddActionBlock(Action8, 7, btMenu, "Move");
    TDialogBaseTool::AddStateBlock(State9, 8, Mouse_Move, btNone, "None");
	TDialogBaseTool::AddConditionalBlock(Condition5, 10, btNone, "None");
	TDialogBaseTool::AddActionBlock(Action12, 11, btMenu, "Select");
    TDialogBaseTool::AddStateBlock(State15, 14, Mouse_Move, btNone, "None");
	TDialogBaseTool::AddConditionalBlock(MoveFinishCondition16, 15, btNone, "None");

	TDialogBaseTool::AddActionBlock(DeleteAction, 100, btMenu, "Delete");
    TDialogBaseTool::AddActionBlock(SelectAllAction, 101, btMenu, "Выделить всё");
    TDialogBaseTool::AddConditionalBlock(Condition5, 102, btNone, "None");
	TDialogBaseTool::AddActionBlock(CopyAction, 103, btNone, "None");
    TDialogBaseTool::AddStateBlock(CopyState, 104, Mouse_Move, btNone, "None");
    TDialogBaseTool::AddActionBlock(UndoAction, 105, btNone, "None");
    TDialogBaseTool::AddActionBlock(RedoAction, 106, btNone, "None");

    TDialogBaseTool::AddConditionalBlock(Condition201, 200, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action203, 202, btMenu, "Rotation");
    TDialogBaseTool::AddStateBlock(State204, 203, Mouse_Move, btNone, "None");
    TDialogBaseTool::AddConditionalBlock(Condition202, 201, btNone, "None");
    TDialogBaseTool::AddActionBlock(Action205, 204, btMenu, "Vertical move");
    TDialogBaseTool::AddStateBlock(State206, 205, Mouse_Move, btNone, "None");
	TDialogBaseTool::AddConditionalBlock(MoveFinishCondition16, 215, btNone, "None");
	TDialogBaseTool::AddConditionalBlock(MoveFinishCondition16, 216, btNone, "None");

    AddGoToBlockId(0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId(1, 2);
    AddGoToBlockId(2, 200, 5);
    AddGoToBlockId(200, 202, 201);
    AddGoToBlockId(202, 203);
    AddGoToBlockId(203, 216, Mouse_Up, mbLeft);
    AddGoToBlockId(201, 204, 14);
    AddGoToBlockId(204, 205);
    AddGoToBlockId(205, 215, Mouse_Up, mbLeft);
	AddGoToBlockId(215, 0, 205);
	AddGoToBlockId(216, 0, 203);
    AddGoToBlockId(5, 0);

	AddGoToBlockId(14, 7, Mouse_Move, mbLeft);
    AddGoToBlockId(14, 11, Mouse_Up, mbLeft);
    AddGoToBlockId(11, 0);
    AddGoToBlockId(7, 8);
    AddGoToBlockId(8, 15, Mouse_Up, mbLeft);
	AddGoToBlockId(15, 0, 8);

    //------------------------F4-----------------------------
    TDialogBaseTool::AddActionBlock(ActionF4,666, btMenu, "Edit");
    AddGoToBlockId(0, 666, Key_Down, VK_F4);
    AddGoToBlockId(666, 0);
    //------------------------F4-----------------------------

/*    AddGoToBlockId(3, 4, Mouse_Up, mbLeft);
    AddGoToBlockId(4, 6, 5);
    AddGoToBlockId(6, 0);
                           */
    AddGoToBlockId(0, 100, Key_Down, VK_DELETE);
    AddGoToBlockId(100, 0);
/*    AddGoToBlockId(0, 102, Key_Down, 'a');
    AddGoToBlockId(0, 102, Key_Down, 'A');
    AddGoToBlockId(102, 101, 0);
    AddGoToBlockId(101, 0);*/

/*    AddGoToBlockId(0, 103, Key_Down, 'c');
    AddGoToBlockId(0, 103, Key_Down, 'C');
	AddGoToBlockId(103, 104);
    AddGoToBlockId(104, 0, Mouse_Down, mbLeft);

    AddGoToBlockId(0, 105, Key_Down, 'z');
	AddGoToBlockId(0, 105, Key_Down, 'Z');
    AddGoToBlockId(105, 0);
    AddGoToBlockId(0, 106, Key_Down, 'r');
    AddGoToBlockId(0, 106, Key_Down, 'R');
    AddGoToBlockId(106, 0);*/

    EscCommands = _EscCommands;

    FirstClickElement = NULL;
    UIP.Center = ZEROINTVEC;
}

void TMainTool::ActionF4()
{
    if ( MySelection.Count > 0 )
        MySelection.GetElement(0)->Edit(Sender, Sender, NULL);
}

void TMainTool::_EscCommands()
{
	TElement *El;
	if ( UndoStack.Opened() )
		UndoStack.BreakSession();
	El = Driver.Element;
	if ( !Driver.Stop() )
	{
		if (El)
			KillElement( El );
		MySelection.Clear();
	}
	bool Process_AddElement_done = false;
    for ( int i = 0; i < MySelection.Count; i++ )
    {
        if ( !Process_AddElement_done && MySelection.GetElement(i) != NULL ) {
            if ( World && MySelection.GetElement(i)->MyMeta ) {
                World->Process_AddElement(MySelection.GetElement(i)->MyMeta,NULL);
                Process_AddElement_done = true;
            }
        }
    }
    Driver.Clear();
}

TMainTool::~TMainTool()
{
}

void TMainTool::State1()
{
	TMDI3D* MDI = Sender;
//    MDI->A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ );
//    MDI->PlaneN = TIntVec(0, 0, 1);
//    EpsValueP = MDI->Factor(EpsValue);
    MDI->View->InvalidateGL();
}

void TMainTool::Action2()
{
    UIP.Center = UIP.NewCursorPos;
}

bool TMainTool::IsSelected(TElement* _Element)
{
    if ( _Element == NULL )
        throw EMyException(" (TElement*) == NULL ");
    for ( int i = 0; i < MySelection.Count; i++ )
        if ( _Element == MySelection.GetElement(i) )
            return true;
    return false;
}

bool TMainTool::Condition3()
{
	TMDI3D* MDI = Sender;
	int PrimitiveID = 0;
		//TList* RenderList = new TList;
		TObject *Object;

		A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ );
		PlaneN = TIntVec(0, 0, 1);

		MDI->View->SelectHeight = 1;
		MDI->View->SelectWidth = 1;
		TIntVec Vec = Sender->ProjectToScreen(UIP.Center);
		PrimitiveID = MDI->View->GetObj(Vec.x, Vec.y, Object);

		SelectionTest = MySelection.Test(Object, PrimitiveID);
		if(SelectionTest)
			return true;

		TElement* El = IdentifyElement((TVisRender*)Object);
		if ( El != NULL )
		{
				if ( El->DynamicType != NULL )
					if ( El->DynamicType->Name == "TLabel3D" )
						if ( El->Parent != NULL )
							El = (TElement*)El->Parent;
				FirstClickElement = El;
				return true;
		}

		/*MDI->View->GetColorSelection(Vec.x, Vec.y, RenderList);
		for ( int i = 0; i < RenderList->Count; i++ )
		{
				TElement* El = IdentifyElement((TVisRender*)RenderList->Items[i]);
				if ( El != NULL )
				{
						FirstClickElement = El;
						RenderList->Clear();
						delete RenderList;
						return true;
				}
		}
		RenderList->Clear();
		delete RenderList;
		*/
		return false;
}

bool TMainTool::Condition201()
{
/*	if(SelectionTest == ROTATION_TOOL)
		return true;*/
	if(SelectionTest == ROTATION_TOOL)
//	if ( UIP.Shift.Contains(ssShift) )// UIP.Key == 'R' )
		if ( FirstClickElement )
			if ( FirstClickElement->DynamicType != NULL )
				if ( FirstClickElement->DynamicType->Name != "TRoom" )
				return true;

    return false;
}

bool TMainTool::Condition202()
{
/*	if(SelectionTest == UPDOWN_TOOL)
		return true;*/
	if(SelectionTest == UPDOWN_TOOL)
        if ( FirstClickElement )
            if ( FirstClickElement->DynamicType != NULL )
                if ( FirstClickElement->DynamicType->Name != "TRoom" )
                return true;
   	return false;
}

void TMainTool::Action203()
{
    if ( FirstClickElement ) {
		BufFromElement(FirstClickElement);
		UndoStack.OpenSession("Rotation" + FirstClickElement->Name);
		MySelection.Clear();
		MySelection.Add(FirstClickElement);
		Driver.Init(FirstClickElement, true, FirstClickElement->GetCurrentFloorElement());
		A = TIntVec( 0, 0, FirstClickElement->AbsPos.z);// + FirstClickElement->AbsSize.z/2 );
		PlaneN = TIntVec(0, 0, 1);
	}
	UIP.Center = UIP.NewCursorPos;
}

void TMainTool::State204()
{
	if ( FirstClickElement ) {
		BufToElement(FirstClickElement);
		MBTi tmpAbsZ = FirstClickElement->AbsPos.z;
		A = TIntVec( 0, 0, tmpAbsZ);// + FirstClickElement->AbsSize.z/2 );
		PlaneN = TIntVec(0, 0, 1);
		TIntVec D = Sender->ProjectToScreen(UIP.NewCursorPos) - Sender->ProjectToScreen(UIP.Center);
		D.z = D.x*0.8;
		D.x = 0;
		D.y = 0;
		FirstClickElement->AbsAngle += D;
		BufFromElement(FirstClickElement);
		Driver.Check();
	}
	UIP.Center = UIP.NewCursorPos;
}

void TMainTool::Action205()
{
	if ( FirstClickElement ) {
		BufFromElement(FirstClickElement);
		UndoStack.OpenSession("Vertical move" + FirstClickElement->Name);
		MySelection.Clear();
		MySelection.Add(FirstClickElement);
		Driver.Init(FirstClickElement, true, FirstClickElement->GetCurrentFloorElement());
		TIntVec vToObj;
		vToObj.x = FirstClickElement->AbsPos.x - AUI.ActiveView->View->Camera->LA_Position->X;
		vToObj.y = FirstClickElement->AbsPos.y - AUI.ActiveView->View->Camera->LA_Position->Y;
		vToObj.z = 0;
		vToObj.Normalize();
		A = TIntVec( FirstClickElement->AbsPos.x, FirstClickElement->AbsPos.y, 0);// + FirstClickElement->AbsSize.z/2 );
		PlaneN = vToObj;
	}
	UIP.Center = UIP.NewCursorPos;
}

void TMainTool::State206()
{
	if ( FirstClickElement ) {
		TIntVec vToObj;
		BufToElement(FirstClickElement);
		vToObj.x = FirstClickElement->AbsPos.x - AUI.ActiveView->View->Camera->LA_Position->X;
		vToObj.y = FirstClickElement->AbsPos.y - AUI.ActiveView->View->Camera->LA_Position->Y;
		vToObj.z = 0;
		vToObj.Normalize();
		A = TIntVec( FirstClickElement->AbsPos.x, FirstClickElement->AbsPos.y, 0);// + FirstClickElement->AbsSize.z/2 );
		PlaneN = vToObj;
		TIntVec D = UIP.NewCursorPos - UIP.Center;
//        D.z = -D.y*0.2;
		D.x = 0;
		D.y = 0;
		FirstClickElement->AbsPos += D;
		BufFromElement(FirstClickElement);
		Driver.Check();
	}
	UIP.Center = UIP.NewCursorPos;
}

void TMainTool::State4()
{
    TMDI3D* MDI = Sender;
//    UIP.Center = UIP.NewCursorPos;
    MDI->View->InvalidateGL();
}

bool TMainTool::Condition5()
{
    if (UIP.Shift.Contains(ssCtrl))
        return true;
    else
        return false;
}

void TMainTool::Action6()
{
    MySelection.Clear();
}

void TMainTool::Action7()
{
	TMDI3D* MDI = Sender;
		//TList* RenderList = new TList;

		A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ );
	PlaneN = TIntVec(0, 0, 1);
    TIntVec CurrentPoint = Sender->ProjectToScreen(UIP.NewCursorPos);
    TIntVec Center = Sender->ProjectToScreen(UIP.Center);

    MDI->View->SelectHeight = 1;
    MDI->View->SelectWidth = 1;

    A = TIntVec( 0, 0, AUI.ActiveWorld->ActiveFloor->AbsZ );
    PlaneN = TIntVec(0, 0, 1);

		TObject *Object;
		MDI->View->GetObj(CurrentPoint.x , CurrentPoint.y, Object);
		TElement* El = IdentifyElement((TVisRender*)Object);
		if ( El != NULL) {
            if ( El->DynamicType != NULL )
                if ( El->DynamicType->Name == "TLabel3D" )
                    if ( El->Parent != NULL )
                        El = (TElement*)El->Parent;
			MySelection.Add( El );
        }

		/*
		MDI->View->GetColorSelection(minx , maxy, RenderList);

		for ( int i = 0; i < RenderList->Count; i++ )
		{
				TElement* El = IdentifyElement((TVisRender*)RenderList->Items[i]);
				if ( El != NULL)
//            if ( !IsSelected( El ) )
								MySelection.Add( El );
//            else
//                MySelection.Remove( El );
		}

		delete RenderList;
		*/
}

void TMainTool::Action8()
{
/*		UndoStack.OpenSession("Moving" + FirstClickElement->Name);
    if ( IsSelected( FirstClickElement ) )
    {
        if ( MySelection.Count == 1 )
        {
            BufFromElement(MySelection.GetElement(0));
            Driver.Init(FirstClickElement, true, FirstClickElement->GetCurrentFloorElement());
		}
		return;
	}
	MySelection.Clear();
	MySelection.Add(FirstClickElement);
	BufFromElement(MySelection.GetElement(0));
	Driver.Init(FirstClickElement, true, FirstClickElement->GetCurrentFloorElement());
	A = TIntVec( 0, 0, FirstClickElement->AbsPos.z);// + FirstClickElement->AbsSize.z/2 );
    PlaneN = TIntVec(0, 0, 1);
	UIP.Center = UIP.NewCursorPos;*/
		UndoStack.OpenSession("Moving" + FirstClickElement->Name);
	if ( !FirstClickElement )
		return;
	MySelection.Clear();
	MySelection.Add(FirstClickElement);
	BufFromElement(MySelection.GetElement(0));
	Driver.Init(FirstClickElement, true, FirstClickElement->GetCurrentFloorElement());
	A = TIntVec( 0, 0, FirstClickElement->AbsPos.z);// + FirstClickElement->AbsSize.z/2 );
    PlaneN = TIntVec(0, 0, 1);
    UIP.Center = UIP.NewCursorPos;
}

void TMainTool::BufToElement(TElement* _Element)
{
    _Element->AbsPos = BufPos;
    _Element->AbsAngle = BufAngle;
	_Element->AbsSize = BufSize;
	_Element->UnRegisterCreateView();
}

void TMainTool::BufFromElement(TElement* _Element)
{
    BufPos = _Element->AbsPos;
    BufAngle = _Element->AbsAngle;
    BufSize = _Element->AbsSize;
}

void TMainTool::State9()
{
//    if ( MySelection.Count == 1 )
	BufToElement(MySelection.GetElement(0));
	for ( int i = 0; i < MySelection.Count; i++ )
	{
		if ( MySelection.GetElement(i)->DynamicType->Name != "TRoom" ) {
			MBTi tmpAbsZ = MySelection.GetElement(i)->AbsPos.z;
			A = TIntVec( 0, 0, tmpAbsZ);// + FirstClickElement->AbsSize.z/2 );
			PlaneN = TIntVec(0, 0, 1);
			TIntVec D = UIP.NewCursorPos - UIP.Center;
			D.z = 0;
			MySelection.GetElement(i)->AbsPos += D;
//            MySelection.Changed(MySelection.GetElement(i));
		}
	}
	if ( MySelection.Count == 1 )
	{
		BufFromElement(MySelection.GetElement(0));
		Driver.MainMode = ocmPosition;
        Driver.CorrectMode = ocmSize;
        Driver.Check();
    }
    UIP.Center = UIP.NewCursorPos;
}

bool TMainTool::MoveFinishCondition16()
{
	TElement *Element;
	try
	{
		for ( int i = MySelection.Count-1; i >=0 ; i-- )
		{
			if ( MySelection.Count > 1 )
				Driver.Init( MySelection.GetElement(i), true, MySelection.GetElement(i)->GetCurrentFloorElement() );
			Driver.MainMode = ocmPosition;
			Driver.CorrectMode = ocmSize;
			Element = Driver.Element;
			if ( !Driver.Stop() )
			{
				WarningMsg("Used technology does not allow you to insert the element such a way.");
				Driver.Init( Element, true, NULL );
				return false;
			}
		}
        // Process_AddElement по завершению таскания
        bool Process_AddElement_done = false;
        for ( int i = 0; i < MySelection.Count; i++ )
        {
            if ( !Process_AddElement_done && MySelection.GetElement(i) != NULL ) {
                if ( World && MySelection.GetElement(i)->MyMeta ) {
                    World->Process_AddElement(MySelection.GetElement(i)->MyMeta,NULL);
                    Process_AddElement_done = true;
                }
            }
        }
    }
    catch(Exception& Exc)
	{
		ErrorMsg("Can not set element");
		return false;
    }
    // Process_AddElement по завершению таскания
	UndoStack.CloseSession();
	return true;
}

void TMainTool::Action12()
{
    if ( IsSelected(FirstClickElement) )
        MySelection.Remove(FirstClickElement);
    else {
        MySelection.Clear();
        MySelection.Add(FirstClickElement);
    }
}

void TMainTool::State15()
{
}

void TMainTool::SelectAllAction()
{
//    if ( !UIP.Shift.Contains(ssCtrl) )
//        return;
    MySelection.Clear();
    TMTList<TElement> ListEl;
//    AUI.ActiveWorld->SelectByCT(AUI.ActiveWorld->Head, TElement::StaticType, &ObjList, true, true);
    for ( int i = 0; i < AUI.ActiveWorld->Floors.Count; i++ )
        if ( AUI.ActiveWorld->Floors[i].Visible )
        {
            SelectElements(i, AUI.ActiveWorld, ListEl);
            for ( int j = 0; j < ListEl.Count; j++ )
                MySelection.Add(ListEl.Items[j]);
		}
}

void TMainTool::CopyAction()
{
/*    for ( int i =0; i < MySelection.Count; i++ )
        CopyElements = (TElement*)CreateUnitFunction(AUI.ActiveWorld, CutMeta(MySelection.GetElement(i)->Associated->DynamicType->Name), IntExplorer->MetaCatalogUnit->Associated->ID );
    MGT->AddRender(1,CustomElement,CustomElement->MyRender());
    State3();*/
}

void TMainTool::CopyState()
{

}

void TMainTool::UndoAction()
{
}

void TMainTool::RedoAction()
{
}

void TMainTool::DeleteAction()
{
    if ( MySelection.Count < 1 )
        return;
    AnsiString UndoStr = AnsiString("Deleting ");
    if ((MySelection.Count > 1))
				UndoStr += ( IntToStr(MySelection.Count)+AnsiString(" objects") );
    else
        UndoStr += MySelection.GetElement(0)->Description;
    UndoStack.OpenSession(UndoStr);
    while ( MySelection.Count > 0 )
        KillElement( MySelection.GetElement(0) );
    MySelection.Clear();
    UndoStack.CloseSession();
}

void TMainTool::OnRender()
{
    TMDI3D* MDI = Sender;
    if ( ExecutedId == 8 || ExecutedId == 203 || ExecutedId == 205 )
    {
        for ( int i = 0; i < MySelection.Count; i++ )
            MySelection.GetElement(i)->Render(MDI->View);
/*        TMDI3D* MDI = Sender;
        MDI->View->InvalidateGL();*/
    }
    if ( ExecutedId == 3 )
    {
/*        MDI->View->Canvas->Pen->Style = lsDash;
        MDI->View->Canvas->Pen->Color = clWhite;
        MDI->View->Canvas->Brush->Color = clWhite;
        TIntVec Vec1 = Sender->ProjectToScreen(UIP.NewCursorPos);
        TIntVec Vec2 = Sender->ProjectToScreen(UIP.Center);
        MDI->View->Canvas->MoveTo(floor(Vec1.x), floor(Vec1.y));
        MDI->View->Canvas->LineTo(floor(Vec2.x), floor(Vec1.y));
        MDI->View->Canvas->LineTo(floor(Vec2.x), floor(Vec2.y));
		MDI->View->Canvas->LineTo(floor(Vec1.x), floor(Vec2.y));
        MDI->View->Canvas->LineTo(floor(Vec1.x), floor(Vec1.y));*/
    }
    MySelection.Render(MDI->View);
}
/*    if (ExecutedId == 3)
    {
        EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
        EditorXD->MyView->View->Canvas->Pen->Color = clWhite;
        EditorXD->MyView->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = EditorXD->MyView->ProjectToScreen(UIP.NewCursorPos);
        TIntVec P2 = EditorXD->MyView->ProjectToScreen(UIP.Center);
        EditorXD->MyView->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P1.y));

        if (UIP.Shift.Contains(ssShift))
        {
//            for(int i = 0; i < SelectionList->Count; i++);
//              EditorXD->MyView->View->
  //            SelectionList->Items[0]->Names[0]->
        }
    }
    if (CreateSelect)
    {
        SelectedRender->Init();
        SelectedRender->ColorAsMaterial = cmAmbient;
        glLineWidth(EditorXD->Attributes.LinesWidth.Selected);
		SelectedRender->Color->Color = EditorXD->Attributes.Colors.Selected;
        SelectedRender->AddPrimitiveArray(GL_LINES);
        SelectedRender->AddPrimitiveArray(GL_POINTS);
        int Index = 0;
        for (int i = 0; i < EditorXD->Selection.Figures.Count; i++)
        {
            for (int j = 0; j < EditorXD->Selection.Figures[i].CutIndices.Count; j++)
            {
                Index = SelectedRender->Points->Add(ToVec(EditorXD->Selection.Figures[i].Figure->GetCut(EditorXD->Selection.Figures[i].CutIndices[j]).Src->Point.x,
                                                          EditorXD->Selection.Figures[i].Figure->GetCut(EditorXD->Selection.Figures[i].CutIndices[j]).Src->Point.y,
                                                          EditorXD->DepthLevels.Selected),ZEROVEC,ZEROVEC);
                SelectedRender->AddIndex(Index,0);
                Index = SelectedRender->Points->Add(ToVec(EditorXD->Selection.Figures[i].Figure->GetCut(EditorXD->Selection.Figures[i].CutIndices[j]).Dst->Point.x,
                                                          EditorXD->Selection.Figures[i].Figure->GetCut(EditorXD->Selection.Figures[i].CutIndices[j]).Dst->Point.y,
                                                          EditorXD->DepthLevels.Selected),ZEROVEC,ZEROVEC);
                SelectedRender->AddIndex(Index,0);
//                VCO->AddIndex(Index-2,0);
  //              VCO->AddIndex(Index-1,0);
            }
        }
        if (ExecutedId == 8 || ExecutedId == 12)
        {
            glPointSize(5);
            Index = SelectedRender->Points->Add(ToVec(SelectedPoint.x,
                                                      SelectedPoint.y,
                                                      EditorXD->DepthLevels.Selected),ZEROVEC,ZEROVEC);
            SelectedRender->AddIndex(Index,1);

            SelectCursor.Position = TIntVec(SnapSelectedPoint.x, SnapSelectedPoint.y, EditorXD->DepthLevels.Selected);
            SelectCursor.Render(EditorXD->MyView);
		}
        if (ExecutedId == 15 || ExecutedId == 17 || ExecutedId == 19)
        {
            RotatedCursor.Position = TIntVec(SelectedMF->RotateUIP.Center.x, SelectedMF->RotateUIP.Center.y, EditorXD->DepthLevels.Selected);
            RotatedCursor.Render(EditorXD->MyView);

            EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
            TIntVec P = EditorXD->MyView->ProjectToScreen(SelectedMF->RotateUIP.Center);
            P = EditorXD->MyView->ProjectToScreen(RotatePoint);
            EditorXD->MyView->View->Canvas->Pen->Color = clBlue;
            EditorXD->MyView->View->Canvas->Brush->Color = clBlue;
            EditorXD->MyView->View->Canvas->Brush->Alpha = 0;
            EditorXD->MyView->View->Canvas->Transparency = tmAlpha;
//            Sender->View->Canvas->Polygon(pnts,13);

//            Sender->View->Canvas->Ellipse(P.x+Rad, P.y+Rad, P.x-Rad, P.y-Rad);
//            P = MyView->ProjectToScreen(RotatePoint);
//            Sender->View->Canvas->Ellipse(P.x+10, P.y+10, P.x-10, P.y-10);
            if (ExecutedId == 19)
            {
                TIntVec P1 = EditorXD->MyView->ProjectToScreen(BB[0]);
                EditorXD->MyView->View->Canvas->MoveTo(P1.x, P1.y);
                for (int i = 1; i < 4; i++)
                {
                    TIntVec P1 = EditorXD->MyView->ProjectToScreen(BB[i]);
                    EditorXD->MyView->View->Canvas->LineTo(P1.x, P1.y);
                }
                P1 = EditorXD->MyView->ProjectToScreen(BB[0]);
                EditorXD->MyView->View->Canvas->LineTo(P1.x, P1.y);
            }
			TIntVec P1 = EditorXD->MyView->ProjectToScreen(SelectedMF->BBoxLU);
            TIntVec P2 = EditorXD->MyView->ProjectToScreen(SelectedMF->BBoxRD);
//            Sender->MyView->View->Canvas->Pen->Style = lsDash;
//            Sender->MyView->View->Canvas->MoveTo(P1.x-5, P1.y+5);
//            Sender->MyView->View->Canvas->LineTo(P2.x+5, P1.y+5);
//            Sender->MyView->View->Canvas->LineTo(P2.x+5, P2.y-5);
//            Sender->MyView->View->Canvas->LineTo(P1.x-5, P2.y-5);
//            Sender->MyView->View->Canvas->LineTo(P1.x-5, P1.y+5);
//            for(int i = 0; i < 8; i+=2)
//            {
//                VCO->Points->Point[i][0] = SelectedMF->BBoxLU.x;
//                VCO->Points->Point[i][1] = SelectedMF->BBoxLU.y;
//                VCO->Points->Point[i][2] = SelectedMF->BBoxLU.z;
//
//                VCO->Points->Point[i+1][0] = SelectedMF->BBoxRD.x;
//                VCO->Points->Point[i+1][1] = SelectedMF->BBoxRD.y;
//                VCO->Points->Point[i+1][2] = SelectedMF->BBoxRD.z;
//            }

            VCO->Points->Point[0][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[0][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[0][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[1][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[1][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[1][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[2][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[2][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[2][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[3][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[3][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[3][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[4][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[4][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[4][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[5][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[5][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[5][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[6][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[6][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[6][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[7][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[7][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[7][2] = EditorXD->DepthLevels.Selected;

            VCO->Render(EditorXD->MyView->View);
//            Sender->MyView->View->Canvas->Pen->Style = lsSolid;
//            TIntVec PP = MyView->ProjectToScreen(SelectedMF->BBoxRD);
//            RotateCursor(90, TPoint(PP.x+15, PP.y-15));
//            Sender->MyView->View->Canvas->Polygon(pnts,11);
//            PP = MyView->ProjectToScreen(SelectedMF->BBoxLU);
//            RotateCursor(270, TPoint(PP.x-15, PP.y+15));
//            Sender->MyView->View->Canvas->Polygon(pnts,11);
//            PP = MyView->ProjectToScreen(TIntVec(SelectedMF->BBoxRD.x, SelectedMF->BBoxLU.y, 30));
//            RotateCursor(180, TPoint(PP.x+15, PP.y+15));
//            Sender->MyView->View->Canvas->Polygon(pnts,11);
//            PP = MyView->ProjectToScreen(TIntVec(SelectedMF->BBoxLU.x, SelectedMF->BBoxRD.y, 30));
//            RotateCursor(0, TPoint(PP.x-15, PP.y-15));
//            Sender->MyView->View->Canvas->Polygon(pnts,11);
        }
    }
    SelectedRender->Render(EditorXD->MyView->View);
}
*/
void SelectElements(int FloorIndex, TMainTree* ActiveWorld, TMTList<TElement>& List)
{
    if (ActiveWorld == NULL)
        return;

    TMTList<TMyRegObject> ObjList;
    if ( FloorIndex != -1 )
    {
        ActiveWorld->SelectByCT(ActiveWorld->Floors[FloorIndex].FirstElement, TElement::StaticType, &ObjList, true, true);
        for ( int i = 0; i < ObjList.Count; i++ )
        {
            TElement* El = (TElement*)ObjList.Items[i];
            if (El && AUI.ActiveWorld->Head && El!=AUI.ActiveWorld->Head && El->Parent != AUI.ActiveWorld->Head)
                List.Add(El);
        }
    }else
        for ( int i = 0; i < ActiveWorld->Floors.Count; i++ )
        {
            ActiveWorld->SelectByCT(ActiveWorld->Floors[FloorIndex].FirstElement, TElement::StaticType, &ObjList, true, true);
            for ( int i = 0; i < ObjList.Count; i++ )
			{
                TElement* El = (TElement*)ObjList.Items[i];
                if (El && AUI.ActiveWorld->Head && El!=AUI.ActiveWorld->Head && El->Parent != AUI.ActiveWorld->Head)
                    List.Add(El);
            }
        }
}
//---------------------------------------------------------------
const AnsiString aFormType = "FormType";
const AnsiString aA = "A";
const AnsiString aPlaneN = "PlaneN";
TDialogBaseTool::TDialogBaseTool()
{
    RegisterNewClass< TBaseTool, TDialogBaseTool >(this, false, &CreateFunction);
    RegisterField(&FormType, &aFormType, mtInt);
    RegisterField(&A, &aA, mtIntVec);
    RegisterField(&PlaneN, &aPlaneN, mtIntVec);

//    UIP.Center = ZEROINTVEC;
//    UIP.NewCursorPos = ZEROINTVEC;
    FormType = 1;
    ToolForm = new TToolForm(NULL);
    ToolForm->eDecX->OnKeyDown = eDecKeyDown;
    ToolForm->eDecY->OnKeyDown = eDecKeyDown;
    ToolForm->eDecX->OnExit = eDecExit;
    ToolForm->eDecY->OnExit = eDecExit;
    ToolForm->ePolR->OnKeyDown = ePolKeyDown;
    ToolForm->ePolA->OnKeyDown = ePolKeyDown;
    ToolForm->ePolR->OnExit = ePolExit;
    ToolForm->ePolA->OnExit = ePolExit;

    ToolForm->bDecD->OnClick = bDecDClick;
    ToolForm->bPolD->OnClick = bPolDClick;
    Forms.Add(ToolForm);
//    UIP.ChangeCenter = &SetCenter;
    UIP.ChangeNewCursorPos = &SetNewCursorPos;

//    A = ZEROINTVEC;
//    PlaneN = TIntVec(0, 0, 1);
}

TDialogBaseTool::~TDialogBaseTool()
{
    delete ToolForm;
}

TMyObject* TDialogBaseTool::CreateFunction()
{
    return new TDialogBaseTool();
}

TMDI3D* TDialogBaseTool::GetTMDI3D()
{
    if ( UIP.Sender == NULL )
        throw EMyException("UIP.Sender == NULL");
    return (TMDI3D*)UIP.Sender;
}

/*void TDialogBaseTool::SetCenter()
{

}*/

void TDialogBaseTool::SetNewCursorPos()
{
    if ( ToolForm != NULL )
    {
        if ( ToolForm->bDecD->Down )
        {
            ToolForm->eDecX->Text = FloatToStrF(UIP.NewCursorPos.x - UIP.Center.x, ffGeneral, 4, 4);
            ToolForm->eDecY->Text = FloatToStrF(UIP.NewCursorPos.y - UIP.Center.y, ffGeneral, 4, 4);
        }else
        {
            ToolForm->eDecX->Text = FloatToStrF(UIP.NewCursorPos.x, ffGeneral, 4, 4);
            ToolForm->eDecY->Text = FloatToStrF(UIP.NewCursorPos.y, ffGeneral, 4, 4);
        }

        if ( ToolForm->bPolD->Down )
        {
            ToolForm->ePolR->Text = FloatToStrF((UIP.NewCursorPos - UIP.Center).Length2D(), ffGeneral, 4, 4);
            ToolForm->ePolA->Text = FloatToStrF(AngleRadOX(UIP.Center, UIP.NewCursorPos)*180/M_PI, ffGeneral, 4, 4);
        }else
        {
            ToolForm->ePolR->Text = FloatToStrF(UIP.NewCursorPos.Length2D(), ffGeneral, 4, 4);
            ToolForm->ePolA->Text = FloatToStrF(AngleRadOX(ZEROINTVEC, UIP.NewCursorPos)*180/M_PI, ffGeneral, 4, 4);
        }
    }
}

/*TIntVec TDialogBaseTool::GetCenter()
{
    return FCenter;
}

TIntVec TDialogBaseTool::GetCurrentPoint()
{
    return FCurrentPoint;
}

void TDialogBaseTool::SetCenter(TIntVec _Center)
{
    FCenter = _Center;
}

void TDialogBaseTool::SetCurrentPoint(TIntVec _CurrentPoint)
{
    FCurrentPoint = _CurrentPoint;
    if ( ToolForm != NULL )
    {
        if ( ToolForm->bDecD->Down )
        {
            ToolForm->eDecX->Text = FloatToStrF(FCurrentPoint.x - FCenter.x, ffGeneral, 4, 4);
            ToolForm->eDecY->Text = FloatToStrF(FCurrentPoint.y - FCenter.y, ffGeneral, 4, 4);
        }else
        {
            ToolForm->eDecX->Text = FloatToStrF(FCurrentPoint.x, ffGeneral, 4, 4);
            ToolForm->eDecY->Text = FloatToStrF(FCurrentPoint.y, ffGeneral, 4, 4);
        }

        if ( ToolForm->bPolD->Down )
		{
            ToolForm->ePolR->Text = FloatToStrF((FCurrentPoint - FCenter).Length2D(), ffGeneral, 4, 4);
            ToolForm->ePolA->Text = FloatToStrF(AngleRadOX(FCenter, FCurrentPoint)*180/M_PI, ffGeneral, 4, 4);
        }else
        {
            ToolForm->ePolR->Text = FloatToStrF(FCurrentPoint.Length2D(), ffGeneral, 4, 4);
            ToolForm->ePolA->Text = FloatToStrF(AngleRadOX(ZEROINTVEC, FCurrentPoint)*180/M_PI, ffGeneral, 4, 4);
        }
    }
}*/

TIntVec TDialogBaseTool::SetCursorDec(MBTi DecX, MBTi DecY, bool SetMouse)
{
    TIntVec Res;
    PlaneCrossPoint( Sender->A, Sender->PlaneN, TIntVec(DecX, DecY, 0), TIntVec(DecX, DecY, 1), Res);
//    UIP.NewCursorPos = Res;
    TIntVec CoordScreen = Sender->ProjectToScreen(Res);
    MouseMove( Sender, TShiftState(), CoordScreen);
    if ( SetMouse )
        Mouse->CursorPos = Sender->ClientToScreen(TPoint(floor(CoordScreen.x), floor(CoordScreen.y)));
    return CoordScreen;
}

void __fastcall TDialogBaseTool::bDecDClick(TObject *_Sender)
{
    SetNewCursorPos();
}

void __fastcall TDialogBaseTool::bPolDClick(TObject *_Sender)
{
	SetNewCursorPos();
}

TIntVec TDialogBaseTool::DecExit(bool SetMouse)
{
    if ( ToolForm->bDecD->Down )
        return SetCursorDec(StrToMBTi(ToolForm->eDecX->Text) + UIP.Center.x, StrToMBTi(ToolForm->eDecY->Text) + UIP.Center.y, SetMouse);
    else
        return SetCursorDec(StrToMBTi(ToolForm->eDecX->Text), StrToMBTi(ToolForm->eDecY->Text), SetMouse);
}

TIntVec TDialogBaseTool::PolExit(bool SetMouse)
{
    MBTi PolR = StrToMBTi(ToolForm->ePolR->Text);
    MBTi PolA = StrToMBTi(ToolForm->ePolA->Text);
    if ( ToolForm->bPolD->Down )
        return SetCursorDec(PolR*cos(PolA*M_PI/180) + UIP.Center.x, PolR*sin(PolA*M_PI/180) + UIP.Center.y, SetMouse);
    else
        return SetCursorDec(PolR*cos(PolA*M_PI/180), PolR*sin(PolA*M_PI/180), SetMouse);
}

void __fastcall TDialogBaseTool::eDecKeyDown(TObject* _Sender, WORD &Key, TShiftState Shift)
{
    if ( int(Key) == VK_RETURN )
        MouseDown(_Sender, mbLeft, TShiftState()<<ssLeft, DecExit(true));
/*    else
        if ( int(Key) == VK_TAB )
            if ( _Sender == ToolForm->eDecX )
                ToolForm->eDecY->SetFocus();
            else
				if ( _Sender == ToolForm->eDecY )
                    DecExit();*/
}

void __fastcall TDialogBaseTool::eDecExit(TObject *_Sender)
{
    DecExit(false);
/*            if ( _Sender == ToolForm->eDecX )
                ToolForm->eDecY->SetFocus();
            else
                if ( _Sender == ToolForm->eDecY )
                    ToolForm->eDecX->SetFocus();    */
}

void __fastcall TDialogBaseTool::ePolKeyDown(TObject* _Sender, WORD &Key, TShiftState Shift)
{
    if ( int(Key) == VK_RETURN )
        MouseDown(_Sender, mbLeft, TShiftState()<<ssLeft, PolExit(true));
/*    else
        if ( int(Key) == VK_TAB )
            if ( _Sender == ToolForm->ePolR )
                ToolForm->ePolA->SetFocus();
            else
                if ( _Sender == ToolForm->ePolA )
                    PolExit();*/
}

void __fastcall TDialogBaseTool::ePolExit(TObject *_Sender)
{
    PolExit(false);
/*            if ( _Sender == ToolForm->ePolR )
                ToolForm->ePolA->SetFocus();
            else
                if ( _Sender == ToolForm->ePolA )
                    ToolForm->ePolR->SetFocus();*/
}

void TDialogBaseTool::UpdateNewCursorPos()
{
    if ( UIP.Sender != NULL )
    {
        Sender->A = A;
        Sender->PlaneN = PlaneN;
        UIP.NewCursorPos = Sender->ScreenToProject(Sender->ProjectToScreen(UIP.NewCursorPos));
    }
}

void TDialogBaseTool::Changed(void* Field)
{
    if ( Field == &A || Field == &PlaneN )
        UpdateNewCursorPos();
}

void TDialogBaseTool::MouseMove(void* _Sender, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMDI3D* MDI3D = (TMDI3D*)_Sender;
    TBaseTool::MouseMove(_Sender, Shift, MDI3D->ScreenToProject( CursorPosition ));
}

void TDialogBaseTool::MouseDown(void* _Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMDI3D* MDI3D = (TMDI3D*)_Sender;
    TBaseTool::MouseDown(_Sender, Button, Shift, MDI3D->ScreenToProject( CursorPosition ));
}

void TDialogBaseTool::MouseUp(void* _Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMDI3D* MDI3D = (TMDI3D*)_Sender;
    TBaseTool::MouseUp(_Sender, Button, Shift, MDI3D->ScreenToProject( CursorPosition ));
}

const AnsiString aLuaModule = "LuaModule";
TBindedStateBlock::TBindedStateBlock()
{
    RegisterNewClass< TStateBlock, TBindedStateBlock >(this, false, &CreateFunction);
    Commands = NULL;
    Id = -1;
    ExecutedEvent = -1;
    FName = "State";
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TBindedStateBlock::TBindedStateBlock(AnsiString _Name, TCommands _Commands, int _Id, int _ExexutedEvent)
{
    RegisterNewClass< TStateBlock, TBindedStateBlock >(this, false, &CreateFunction);
	Commands = _Commands;
    Id = _Id;
    ExecutedEvent = _ExexutedEvent;
    FName = _Name;
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TMyObject* TBindedStateBlock::CreateFunction()
{
    return new TBindedStateBlock();
}

void TBindedStateBlock::Edit(TComponent *Owner, TWinControl *Parent, void *Data)
{
    new TBindedBlockEdit(Owner,Parent,this,"StateBlock",Data);
}

TBindedActionBlock::TBindedActionBlock()
{
    RegisterNewClass< TActionBlock, TBindedActionBlock >(this, false, &CreateFunction);
    Commands = NULL;
    Id = -1;
    FName = "action";
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
	GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TBindedActionBlock::TBindedActionBlock(AnsiString _Name, TCommands _Commands, int _Id)
{
    RegisterNewClass< TActionBlock, TBindedActionBlock >(this, false, &CreateFunction);
    Commands = _Commands;
    Id = _Id;
    FName = _Name;
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TMyObject* TBindedActionBlock::CreateFunction()
{
    return new TBindedActionBlock();
}

void TBindedActionBlock::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    new TBindedBlockEdit(Owner,Parent,this,"ActionBlock",Data);
}

TBindedConditionalBlock::TBindedConditionalBlock()
{
    RegisterNewClass< TConditionalBlock, TBindedConditionalBlock >(this, false, &CreateFunction);
    Condition = NULL;
    Id = -1;
    FName = "conditional";
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbRight;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TBindedConditionalBlock::TBindedConditionalBlock(AnsiString _Name, TCondition _Condition, int _Id)
{
    RegisterNewClass< TConditionalBlock, TBindedConditionalBlock >(this, false, &CreateFunction);
    Condition = _Condition;
    Id = _Id;
    FName = _Name;
    GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbLeft;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
	GOS.Add(new TGo());
    GOS.Last()->Event = Mouse_Down;
    GOS.Last()->MouseButton = mbRight;
    GOS.Last()->Key = VK_CONTROL;
    GOS.Last()->NextBlockId = -1;
    RegisterField(&LuaModule, &aLuaModule, mtMyObject);
}

TMyObject* TBindedConditionalBlock::CreateFunction()
{
    return new TBindedConditionalBlock();
}

void TBindedConditionalBlock::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    new TBindedBlockEdit(Owner,Parent,this,"ConditionalBlock",Data);
}

const AnsiString aRenderLuaModule = "RenderLuaModule";
const AnsiString aFName = "FName";
//const AnsiString aLuaAttribute = "LuaAttribute";
TBindedBaseTool::TBindedBaseTool()
{
    RegisterNewClass< TDialogBaseTool, TBindedBaseTool >(this, false, &CreateFunction);
    RegisterField(&FName, &aFName, mtString);
    RegisterField(&RenderLuaModule, &aRenderLuaModule, mtMyObject);
//    RegisterField(&LuaAttribute, &aLuaAttribute, mtMyObject);
	Blocks.Add(new TBindedActionBlock("escaction", &UniversalCommands, IdEscAction));
    Blocks.Last()->GOS[0].NextBlockId = IdEscAction;
}

TMyObject* TBindedBaseTool::CreateFunction()
{
    return new TBindedBaseTool();
}

void TBindedBaseTool::Edit(TComponent *Owner, TWinControl *Parent, void *Data)
{
    new TBindedBaseToolEdit(Owner,Parent,this,"Tool",Data );
}

AnsiString TBindedBaseTool::GetBlockName(int _Index)
{
    return Blocks[_Index].Name;
}

AnsiString TBindedBaseTool::GetBlockNameFromId(int _Id)
{
    for (int i = 0; i < Blocks.Count; i++)
        if (Blocks[i].Id == _Id)
            return Blocks[i].Name;
    return "none";
}

int TBindedBaseTool::GetBlockIdFromName(AnsiString _Name)
{
    for (int i = 0; i < Blocks.Count; i++)
        if (Blocks[i].Name == _Name)
            return Blocks[i].Id;
    return -1;
}

int TBindedBaseTool::AddStateBlock(int _ExecutedEvent)
{
    int BuffId = GetUnicId();
    Blocks.Add(new TBindedStateBlock("state"+IntToStr(BuffId), &UniversalCommands, BuffId, _ExecutedEvent));
    int n = 0;
    for (int i =0; i<Blocks.Count; i++)
        if (Blocks[i].Is(TStateBlock::StaticType))
            n++;
    if ( n == 1 )
    {
//        IdEscAction = GetUnicId();
//        Blocks.Add(new TBindedActionBlock("escaction", &ProcessEscapeCommands, IdEscAction));
        Blocks[FindIndexFromId(IdEscAction)].GOS[0].NextBlockId = BuffId;
        FExecutedId = BuffId;
    }
    AddGoToBlockId(BuffId, IdEscAction, EXIT, mbLeft);
    return BuffId;
}

int TBindedBaseTool::AddActionBlock()
{
    int BuffId = GetUnicId();
    Blocks.Add(new TBindedActionBlock("action"+IntToStr(BuffId),&UniversalCommands, BuffId));
    return BuffId;
}

int TBindedBaseTool::AddConditionalBlock()
{
	int BuffId = GetUnicId();
    Blocks.Add(new TBindedConditionalBlock("conditional"+IntToStr(BuffId), &UniversalConditional, BuffId));
    return BuffId;
}

TBaseBlock* TBindedBaseTool::GetBlockFromId( int _Id )
{
    int Index = FindIndexFromId(_Id);
    if (Index == -1)
        throw EMyException("Could not find identifier");
    return Blocks.Items[Index];
}

TBaseBlock* TBindedBaseTool::GetBlock( int _Index )
{
    return Blocks.Items[_Index];
}

bool TBindedBaseTool::CheckId( int _Id )
{
    if ( FindIndexFromId(_Id) == -1 )
        return false;
    else
        return true;
}

void TBindedBaseTool::DeleteBlock( int _Id )
{
    int Index = FindIndexFromId(_Id);
    if (Index == -1)
		throw EMyException("Could not find identifier");
    Blocks.Delete(Index);
}

void TBindedBaseTool::RemoveBlock( TBaseBlock* _Block )
{
    Blocks.Remove( _Block );
}

int TBindedBaseTool::BlocksCount()
{
    return Blocks.Count;
}

bool TBindedBaseTool::CheckFields()
{
    int FirstState = true;
    for (int i = 0; i < Blocks.Count; i++)
        if ( Blocks[i].Is( TBindedStateBlock::StaticType ) )
        {
            TBindedStateBlock* BSB = (TBindedStateBlock*)Blocks.Items[i];
            if ( BSB->Commands == NULL )
                BSB->Commands = UniversalCommands;
            if ( FirstState )
            {
                FExecutedId = Blocks[i].Id;
                FirstState = false;
            }
        }else
            if ( Blocks[i].Is( TBindedActionBlock::StaticType ) )
			{
                TBindedActionBlock* BSB = (TBindedActionBlock*)Blocks.Items[i];
                if ( BSB->Commands == NULL )
//                    if ( BSB->Id != IdEscAction )
                        BSB->Commands = UniversalCommands;
//                    else
//                        BSB->Commands = ProcessEscapeCommands;
            }else
                if ( Blocks[i].Is( TBindedConditionalBlock::StaticType ) )
                {
                    TBindedConditionalBlock* BSB = (TBindedConditionalBlock*)Blocks.Items[i];
                    if ( BSB->Condition == NULL )
                        BSB->Condition = UniversalConditional;
                }
    return true;
}


void TBindedBaseTool::UniversalCommands()
{
    if (Blocks[FindIndexFromId(FExecutedId)].Is(TBindedStateBlock::StaticType))
    {
        TBindedBaseTool* OldCurrentTool = CurrentTool;
        CurrentTool = this;
        TBindedStateBlock* BB = (TBindedStateBlock*)Blocks.Items[FindIndexFromId(FExecutedId)];
        BB->LuaModule.Run();
        CurrentTool = OldCurrentTool;
    }
    else if (Blocks[FindIndexFromId(FExecutedId)].Is(TBindedActionBlock::StaticType))
    {
		TBindedBaseTool* OldCurrentTool = CurrentTool;
        CurrentTool = this;
        TBindedActionBlock* BB = (TBindedActionBlock*)Blocks.Items[FindIndexFromId(FExecutedId)];
        BB->LuaModule.Run();
        CurrentTool = OldCurrentTool;
    }
    else
        throw EMyException("Unknown block");
}

bool TBindedBaseTool::UniversalConditional()
{
    if (Blocks[FindIndexFromId(FExecutedId)].Is(TBindedConditionalBlock::StaticType))
    {
        LuaConditionResult = false;
        TBindedBaseTool* OldCurrentTool = CurrentTool;
        CurrentTool = this;
        TBindedConditionalBlock* BB = (TBindedConditionalBlock*)Blocks.Items[FindIndexFromId(FExecutedId)];
        BB->LuaModule.Run();
        CurrentTool = OldCurrentTool;
        return LuaConditionResult;
    }else
        throw EMyException("Unknown block");
}

char* TBindedBaseTool::KeyToStrChar(WORD Key)
{
    return KeyToStr( Key ).c_str();
}

char* TBindedBaseTool::GetExecutedName()
{
		return GetBlockFromId(ExecutedId)->Name.c_str();
}

void TBindedBaseTool::OnRender()
{
    TBindedBaseTool* OldCurrentTool = CurrentTool;
    CurrentTool = this;
    RenderLuaModule.Run();
    CurrentTool = OldCurrentTool;
}

AnsiString TBindedBaseTool::KeyToStr(WORD Key)
{
    switch (Key){
        case VK_LBUTTON	:
            return("VK_LBUTTON"); //Left mouse button
        case VK_RBUTTON	:	//Right mouse button
            return("VK_RBUTTON");

        case VK_CANCEL	:	//Control+Break
            return("VK_CANCEL");

        case VK_MBUTTON	:	//Middle mouse button
            return("VK_MBUTTON");

        case VK_BACK	://Backspace key
            return("VK_BACK");

		case VK_TAB		: //key
            return("VK_TAB");

        case VK_CLEAR 	:	//Clear key
            return("VK_CLEAR");

        case VK_RETURN	:	//Enter key
            return("VK_RETURN");

        case VK_SHIFT	:	//Shift key
            return("VK_SHIFT");
        
        case VK_CONTROL	:	//Ctrl key
            return("VK_CONTROL");
        
        case VK_MENU	:	//Alt key
            return("VK_MENU");
        
        case VK_PAUSE	:	//Pause key
            return("VK_PAUSE");
        
        case VK_CAPITAL	:	//Caps Lock key
            return("VK_CAPITAL");
        
        case VK_ESCAPE	:	//Esc key
            return("VK_ESCAPE");
        
        case VK_SPACE	:	//Space bar
            return("VK_SPACE");

		case VK_PRIOR	:	//Page Up key
            return("VK_PRIOR");
        
        case VK_NEXT	:	//Page Down key
            return("VK_NEXT");
        
        case VK_END	    ://	End //key
            return("VK_END");

        case VK_HOME	:	//Home key
            return("VK_HOME");
        
        case VK_LEFT 	:	//Left Arrow key
            return("VK_LEFT");

        case VK_UP  	:	    //Up Arrow key
            return("VK_UP");
        
        case VK_RIGHT 	:	//Right Arrow key
            return("VK_RIGHT");

        case VK_DOWN 	:	//Down Arrow key
            return("VK_DOWN");
        
        case VK_SELECT	:	//Select key
            return("VK_SELECT");
        
        case VK_PRINT	:	//Print key (keyboard-specific)
            return("VK_PRINT");
        
		case VK_EXECUTE	:	//Execute key
            return("VK_EXECUTE");
        
        case VK_SNAPSHOT	://	Print Screen key
            return("VK_SNAPSHOT");
        
        case VK_INSERT	:	//Insert key
            return("VK_INSERT");
        
        case VK_DELETE	:	//Delete key
            return("VK_DELETE");

        case VK_HELP	:	//Help key
            return("VK_HELP");
        
        case VK_LWIN	:	//Left Windows key (Microsoft keyboard)
            return("VK_LWIN");
        
        case VK_RWIN	:    //	Right Windows key (Microsoft keyboard)
            return("VK_RWIN");
        
        case VK_APPS	:	//Applications key (Microsoft keyboard)
            return("VK_APPS");
        
        case VK_NUMPAD0	:	//0 key (numeric keypad)
            return("VK_NUMPAD0");

        case VK_NUMPAD1	:	//1 key (numeric keypad)
            return("VK_NUMPAD1");

		case VK_NUMPAD2	:	//2 key (numeric keypad)
            return("VK_NUMPAD2");

        case VK_NUMPAD3	:	//3 key (numeric keypad)
            return("VK_NUMPAD3");

        case VK_NUMPAD4	:	//4 key (numeric keypad)
            return("VK_NUMPAD4");

        case VK_NUMPAD5	:	//5 key (numeric keypad)
            return("VK_NUMPAD5");

        case VK_NUMPAD6	:	//6 key (numeric keypad)
            return("VK_NUMPAD6");

        case VK_NUMPAD7	:	//7 key (numeric keypad)
            return("VK_NUMPAD7");

        case VK_NUMPAD8	:	//8 key (numeric keypad)
            return("VK_NUMPAD8");

        case VK_NUMPAD9	:	//9 key (numeric keypad)
            return("VK_NUMPAD9");

        case VK_MULTIPLY 	:	//Multiply key (numeric keypad)
            return("VK_MULTIPLY");

        case VK_ADD	:	//Add key //(numeric keypad)
            return("VK_ADD");

		case VK_SEPARATOR	:	//Separator key (numeric keypad)
            return("VK_SEPARATOR");

        case VK_SUBTRACT	:	//Subtract key (numeric keypad)
            return("VK_SUBTRACT");

        case VK_DECIMAL	:	//Decimal key (numeric keypad)
            return("VK_DECIMAL");

        case VK_DIVIDE	:	//Divide key (numeric keypad)
            return("VK_DIVIDE");

        case VK_F1	:	//F1 key
            return("VK_F1");

        case VK_F2	:	//F2 key
            return("VK_F2");

        case VK_F3	:	//F3 key
            return("VK_F3");

        case VK_F4	:	//F4 key
            return("VK_F4");
        
        case VK_F5	:	//F5 key
            return("VK_F5");
        
        case VK_F6	:	//F6 key
            return("VK_F6");
        
		case VK_F7	:	//F7 key
            return("VK_F7");
        
        case VK_F8	:	//F8 key
            return("VK_F8");

        case VK_F9	:	// key
            return("VK_F9");
        
        case VK_F10	:	//F10 key
            return("VK_F10");
        
        case VK_F11	:	//F11 key
            return("VK_F11");
        
        case VK_F12	:	//F12 key
            return("VK_F12");
        
        case VK_F13	:	//F13 key
            return("VK_F13");
        
        case VK_F14	:	//F14 key
            return("VK_F14");
        
        case VK_F15	:	//F15 key
            return("VK_F15");

        case VK_F16	:	//F16 key
            return("VK_F16");
        
		case VK_F17	:	//F17 key
            return("VK_F17");

        case VK_F18	:	//F18 key
            return("VK_F18");
        
        case VK_F19	:	//F19 key
            return("VK_F19");

        case VK_F20	:	//F20 key
            return("VK_F20");
        
        case VK_F21	:	//F21 key
            return("VK_F21");
        
        case VK_F22	:	//F22 key
            return("VK_F22");

        case VK_F23	:	//F23 key
            return("VK_F23");
        
        case VK_F24	:	//F24 key
            return("VK_F24");
        
        case VK_NUMLOCK	:	//Num Lock key
            return("VK_NUMLOCK");
        
        case VK_SCROLL	:	//Scroll Lock key
            return("VK_SCROLL");
        
		case VK_LSHIFT	:	//Left Shift key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_LSHIFT");
        
        case VK_RSHIFT 	:	//Right Shift key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_RSHIFT");
        
        case VK_LCONTROL	:	//Left Ctrl key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_LCONTROL");

        case VK_RCONTROL	:	//Right Ctrl key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_RCONTROL");
        
        case VK_LMENU	:	//Left Alt key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_LMENU");
        
        case VK_RMENU	:	//Right Alt key (only used with GetAsyncKeyState and GetKeyState)
            return("VK_RMENU");
        
        case VK_PROCESSKEY	:	//Process key
            return("VK_PROCESSKEY");

        case VK_ATTN	:	//Attn key
            return("VK_ATTN");
        
        case VK_CRSEL	:	//CrSel key
            return("VK_CRSEL");

        case VK_EXSEL	:	//ExSel key
            return("VK_EXSEL");

        case VK_EREOF	:	//Erase EOF key
            return("VK_EREOF");
        
        case VK_PLAY	:	//Play key
            return("VK_PLAY");
        
        case VK_ZOOM	:	//Zoom key
            return("VK_ZOOM");
        
        case VK_NONAME	:	//Reserved for future use
            return("VK_NONAME");
        
        case VK_PA1	:	//PA1 key
            return("VK_PA1");
        
        case VK_OEM_CLEAR	:	//Clear key
            return("VK_OEM_CLEAR");

        default : return(AnsiString().StringOfChar((char)Key,1));
    }
}
//--------------------------------------------------------------
