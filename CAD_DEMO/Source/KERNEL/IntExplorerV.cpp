//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "IntExplorerV.h"
//#include "Main.h"
#include "MetaClasses.h"
#include "MyGL.h"
#include "MetaNodeCollectionV.h"
#include "CatalogUnitV.h"
#include "Select.h"
#include "World.h"
#include <mmsystem.hpp>
#include "MDI3DUserV.h"
#include "AUIV.h"
#include "MetaToolV.h"
#include "ElementV.h"
#include "ToolFormV.h"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIntExplorer *IntExplorer = NULL;
//---------------------------------------------------------------------------
TLVParam::TLVParam()
{
    BIG = new TImageList(NULL);
    SML = new TImageList(NULL);
}

TLVParam::TLVParam(TMetaNode* FirstParent,const AnsiString& _Caption,int _ImageIndex)
{
    MaxParent = FirstParent;
    CurParent = FirstParent;
    BIG = new TImageList(NULL);
    BIG->Width = ExplorerImageSizeX;
    BIG->Height = ExplorerImageSizeY;
    SML = new TImageList(NULL);
    SML->Width = PanelImageSizeX;
    SML->Height = PanelImageSizeY;
    Caption = _Caption;
    ImageIndex = _ImageIndex;
    BIG_Where = TRect(0,0,BIG->Width,BIG->Height);
    SML_Where = TRect(0,0,SML->Width,SML->Height);
}

TLVParam::~TLVParam()
{
    delete BIG;
    delete SML;
}

int TLVParam::ObjectStatus(TMetaNode* Object)
{
    if ( Object->Is(TMetaCatalogUnit::StaticType) )
        return osObject;
    else if (Object->Img1->Valid())
        return osValidFolder;
    else
        return osFolder;
}

bool USE_ITEM(TMetaNode* MN)
{
    if ( MN->Is(TMetaCatalogUnit::StaticType) )
        return true;
    TMTList<TMyRegObject> MRO;
    MetaNodeCollection->SelectByCT(MN,TMetaCatalogUnit::StaticType,&MRO,true,true);
    return MRO.Count>0;
}

void AddImageFromMetaNode(TImageList* MainIL,TMetaNode* MCU,bool Small)
{
    Graphics::TBitmap* serv_bmp = new Graphics::TBitmap();
    Graphics::TBitmap* mask = new Graphics::TBitmap();
    serv_bmp->HandleType = bmDIB;
    mask->HandleType = bmDIB;
    MCU->GetImage(Small,true,serv_bmp,mask);
    ImageResize(serv_bmp,MainIL->Width,MainIL->Height);
    ImageResize(mask,MainIL->Width,MainIL->Height);
    MainIL->Add(serv_bmp,mask);
    delete serv_bmp;
    delete mask;
}

__fastcall TIntExplorer::TIntExplorer(TComponent* Owner)
    : ControlList( *(new TToolControlList) ),
    TFloatForm(Owner)
{

    IntExplorer = this;

    TMetaNode* _Parent = (TMetaNode*)MetaNodeCollection->FindParent(cMetaCatalogUnit);
    if (!_Parent)
    {
        Close();
        return;
    }
    Color = ExplorerFaceColor;
    LV->Color = ExplorerBackColor;

    MainIL->Width = PanelImageSizeX;
    MainIL->Height = PanelImageSizeY;
    MainIL->Clear();
    TRect RES;

    Graphics::TBitmap* bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    bmp->Width = MainIL->Width;
    bmp->Height = MainIL->Height;

    Graphics::TBitmap* serv_bmp = new Graphics::TBitmap();
    Graphics::TBitmap* mask = new Graphics::TBitmap();

    serv_bmp->Assign(bmp);
    mask->Assign(bmp);

    bmp->Canvas->Brush->Color = ExplorerFaceColor;
    bmp->Canvas->FillRect(TRect(0,0,MainIL->Width,MainIL->Height));
    IL->GetBitmap(2,serv_bmp);
    RectForBMP(TRect(0,0,MainIL->Width,MainIL->Height),serv_bmp,RES);
    bmp->Canvas->StretchDraw(RES,serv_bmp);

    IL->Draw(serv_bmp->Canvas,0,0,2,dsNormal,itMask);

    mask->Canvas->Brush->Color = clWhite;
    mask->Canvas->FillRect(TRect(0,0,MainIL->Width,MainIL->Height));
    mask->Canvas->StretchDraw(RES,serv_bmp);

    MainIL->Add(bmp,mask);

    delete mask;
    delete bmp;
    delete serv_bmp;

    for (int i=0;i<_Parent->ChildList->Count;i++)
    {
        TMetaNode* MCU = (TMetaNode*)_Parent->ChildList->Items[i];
        LVS.Add(new TLVParam(MCU,MCU->Description,i));
        AddImageFromMetaNode(MainIL,MCU,true);
    }


    for (int k=0;k<LVS.Count;k++)
    {
        TMTList<TMyRegObject> MRO;
        TRect RES;
        MetaNodeCollection->SelectByCT(LVS[k].MaxParent,TMetaNode::StaticType,&MRO,true,true);
        for (int i=0;i<MRO.Count;i++)
        {
            TMetaNode* MT = (TMetaNode*)MRO.Items[i];
            if ( !USE_ITEM(MT) )
                continue;
            
            Graphics::TBitmap* serv_bmp = new Graphics::TBitmap();
            serv_bmp->HandleType = bmDIB;
            Graphics::TBitmap* mask = new Graphics::TBitmap();
            mask->HandleType = bmDIB;
            Graphics::TBitmap* bmp = new Graphics::TBitmap();
            bmp->HandleType = bmDIB;
            bmp->Width = LVS[k].BIG->Width;
            bmp->Height = LVS[k].BIG->Height;
            Graphics::TBitmap* little_bmp = new Graphics::TBitmap();
            little_bmp->HandleType = bmDIB;
            little_bmp->Width = LVS[k].SML->Width;
            little_bmp->Height = LVS[k].SML->Height;

            int status = LVS[k].ObjectStatus((TMetaNode*)MRO.Items[i]);
            MT->GetImage(false,true,serv_bmp,mask);
            bmp->Canvas->Brush->Color = ExplorerBackColor;
            bmp->Canvas->FillRect( TRect(0,0,bmp->Width,bmp->Height) );

            RectForBMP(LVS[k].BIG_Where,serv_bmp,RES);
            bmp->Canvas->StretchDraw(RES,serv_bmp);

            MT->GetImage(true,true,serv_bmp,mask);
            RectForBMP(LVS[k].SML_Where,serv_bmp,RES);
            little_bmp->Canvas->StretchDraw(RES,serv_bmp);

            if (status == osValidFolder)
                il_folders->Draw(bmp->Canvas,0,bmp->Height-il_folders->Height,0,dsNormal,itImage);

            LVS[k].BIG->Add(bmp,NULL);
            LVS[k].SML->Add(little_bmp,NULL);
            MRO[i].Tag1 = LVS[k].BIG->Count-1;

            delete serv_bmp;
            delete bmp;
            delete little_bmp;
            delete mask;
        }
    }

    SetExplorerStates();
    AL = AlignBottom;
	DefaultSize = 130;
	FixedSize = 31;

    //--------------Tools-----------------

    TMTList<TMyRegObject> LST;
    MetaNodeCollection->SelectByCT(NULL,TMetaTool::StaticType,&LST,true,true);
    for (int i=0;i<LST.Count;i++)
        if (  ControlList.Tools.IndexOf( (TMetaTool*)LST.Items[i] )==-1 )
            ControlList.Tools.Add( (TMetaTool*)LST.Items[i] );
    ControlList.ActiveIndex = 0;
    //------------------------------------

//    NeedToRebuildToolPanel = true;
    RefreshAlign();
    int ButtonIndex = (MainToolBar->ButtonCount>1)? 1 : 0;
    MainToolBar->Buttons[ ButtonIndex ]->Click();
    MainToolBar->Buttons[ ButtonIndex ]->Down = true;
}

TToolButton* TIntExplorer::CreateToolButton(TToolBar* TB,int index)
{
    TToolButton *SB = new TToolButton(TB);
    if (index!=-1)
    {
        SB->Tag = index;
        SB->Hint = LVS[index].Caption;
        SB->ImageIndex = index+1;
        SB->Down = false;
    }
    else
    {
        SB->Tag = IDMouseAction;
        SB->Hint = "";
        SB->ImageIndex = 0;
        SB->Down = true;
    }
    SB->OnClick = tbObjectsClick;
    SB->Style = tbsCheck;
    SB->Grouped = true;
    SB->AllowAllUp = false;
    if (AL == AlignLeft || AL == AlignRight)
    {
        SB->Top = (TB->ButtonCount)*SB->Height+1;
        SB->Left = 0;
    }
    else
    {
        SB->Top = 0;
        SB->Left = (TB->ButtonCount)*SB->Width+1;
    }  
    SB->Parent = TB;
    return SB;
}

void TIntExplorer::RefreshAlign()
{
    while (MainToolBar->ButtonCount)
    {
        delete MainToolBar->Buttons[0];
    }
    ExpStates[AL].ApplyToExplorer(this);
    CreateToolButton(MainToolBar,-1);
    for (int i=0;i<LVS.Count;i++)
        CreateToolButton(MainToolBar,i);
    if (AL == AlignLeft || AL == AlignRight)
    {
        MainToolBar->Height = (MainToolBar->ComponentCount)*MainToolBar->ButtonHeight;
        MainToolBar->Width = MainToolBar->ButtonWidth;
        LV->IconOptions->Arrangement = iaTop;
        //Width = StateSize[State];
    }
    else
    {
        MainToolBar->Height = MainToolBar->ButtonHeight;
        MainToolBar->Width = (MainToolBar->ComponentCount)*MainToolBar->ButtonWidth;
        LV->IconOptions->Arrangement = iaLeft;
        //Height = StateSize[State];
    }
    MainToolBar->Buttons[0]->Tag = IDMouseAction;
    MainToolBar->Buttons[0]->ImageIndex = 0;
    MainToolBar->Buttons[0]->Down = true;
    for (int i=1;i<MainToolBar->ButtonCount;i++)
    {
        MainToolBar->Buttons[i]->Tag = i-1;
        MainToolBar->Buttons[i]->ImageIndex = i;
        MainToolBar->Buttons[i]->Down = false;
    }
}

//---------------------------------------------------------------------------
TToolButton* TIntExplorer::CreateRealToolButton(TToolBar* ToolButtons,int index,TMetaTool* MetaTool,int ImageIndex)
{
    TToolButton *SB = new TToolButton(ToolButtons);
    SB->Parent = ToolButtons;
    SB->Tag = index;
    SB->Hint = (MetaTool)? MetaTool->Description : AnsiString("");
    SB->ImageIndex = ImageIndex;
    SB->Down = false;
    SB->Style = tbsCheck;
    SB->Grouped = true;
    SB->AllowAllUp = false;
    SB->OnClick = ToolClick;
    /*if (AL == AlignLeft || AL == AlignRight)
    {
        SB->Top = (ToolButtons->ButtonCount)*SB->Height+1;
        SB->Left = 0;
    }
    else
    {
        SB->Top = 0;
        SB->Left = (ToolButtons->ButtonCount)*SB->Width+1;
    }*/
    return SB;
}

void TIntExplorer::SetMetaCatalogUnit(TMetaCatalogUnit* Value)
{
    MySelection.Clear();
    if (FMetaCatalogUnit != Value)
    {
        FMetaCatalogUnit = Value;
        ActivateTools();
    }
    SwitchTool( (ToolButtons->ButtonCount>1)? ToolButtons->Buttons[1]->Tag:ToolButtons->Buttons[0]->Tag );
}

void TIntExplorer::ActivateTools()
{
    SendMessage( IntExplorer->Handle,WM_NOTIFY, SELECTION_CHANGED,0);
}

void TIntExplorer::SwitchTool(int NewToolIndex)
{
    if (ControlList.Tools.Count)
    {
        ControlList.Tools[ControlList.ActiveIndex].BindedTool.Exit(AUI.ActiveView);
        //if currently active tool index is NewToolIndex then refresh only
        if (ControlList.ActiveIndex != NewToolIndex)
        {
            ControlList.ActiveIndex = NewToolIndex;
            for (int i=0;i<ToolButtons->ButtonCount;i++)
                ToolButtons->Buttons[i]->Down = (ToolButtons->Buttons[i]->Tag == NewToolIndex);
            /*
            while (ToolForms->ControlCount>0)
            {
                ToolForms->Controls[0]->Visible = false;
                ToolForms->Controls[0]->Align = alNone;
                ToolForms->Controls[0]->Parent = NULL;
            }
            ((TDialogBaseTool&)FTools.Matrix[0][NewToolIndex]).ToolForm->Parent = ToolForms;
            ((TDialogBaseTool&)FTools.Matrix[0][NewToolIndex]).ToolForm->Align = alTop;
            ((TDialogBaseTool&)FTools.Matrix[0][NewToolIndex]).ToolForm->Visible = true;
            */
        }
    }
}

void __fastcall TIntExplorer::ToolClick(TObject *Sender)
{
    TToolButton* Tool = (TToolButton*)Sender;
    if ( Tool->Tag != ControlList.ActiveIndex )
        SwitchTool(Tool->Tag);
}
//---------------------------------------------------------------------------
//
void TIntExplorer::UpdateToolImages(TMTList<TMetaTool>& Tools)
{
    IL_TOOLS->Clear();
    IL_TOOLS->Width = PanelImageSizeX;
    IL_TOOLS->Height = PanelImageSizeY;
    for (int i=0;i<Tools.Count;i++)
        AddImageFromMetaNode(IL_TOOLS,Tools.Items[i],true);
}

void TIntExplorer::ProcessActivateTools()
{
    //вычищаем панель кнопок
    while (ToolButtons->ButtonCount)
        delete ToolButtons->Buttons[0];

    //работаем с selection
    TMTList<TMetaTool> Tools;
    if (GetSelection().Count )
    {
        for (int i=0;i<GetSelection().GetElement(0)->MyMeta->MAS.Tools.Count;i++)
            Tools.Add( GetSelection().GetElement(0)->MyMeta->MAS.Tools[i].ADR );

        for (int i=0;i<GetSelection().Count;i++)
        {
            TMTList< TMetaTool> MTools;
            for (int j=0;j<GetSelection().GetElement(i)->MyMeta->MAS.Tools.Count;j++)
                MTools.Add( GetSelection().GetElement(i)->MyMeta->MAS.Tools[j].ADR );

            for (int j=0;j<Tools.Count;j++)
                if ( MTools.IndexOf( Tools.Items[j] ) == -1 )
                    Tools.Delete(j--);
        }
    }
    else if (!MetaCatalogUnit || !MetaCatalogUnit->Associated )
    {
        //нет объекта создания
    }
    else if ( MetaCatalogUnit->Associated->Is(TMetaElement::StaticType) )
    {
        //работаем с TMetaElement
        TMetaElement* ME = (TMetaElement*)MetaCatalogUnit->Associated;
        for ( int i = 0;i<ME->MAS.CreateTools.Count;i++)
            Tools.Add( ME->MAS.CreateTools[i].ADR );
        if (!Tools.Count)
            Tools.Add( ControlList.Tools.Items[0] );
    }
    else
    {
        //работаем с TMetaTexture, TMetaMaterial
        Tools.Add( ControlList.Tools.Items[0] );
    }

    Tools.Insert(0, ControlList.Tools.Items[1] );
    UpdateToolImages(Tools);
    int ActiveButtonIndex = -1;
    for ( int i = Tools.Count-1;i>=0;i-- )
    {
        int index = ControlList.Tools.IndexOf( &Tools[i] );
        CreateRealToolButton(ToolButtons,index,&Tools[i],i);
        if ( index == ControlList.ActiveIndex )
            ActiveButtonIndex = i;
    }
    if ( ActiveButtonIndex!=-1 )
    {
        ToolButtons->Buttons[ActiveButtonIndex]->Down = true;
    }
    else
    {
        //переключаем тул
        SwitchTool(ToolButtons->Buttons[ ToolButtons->ButtonCount>1 ? 1 : 0 ]->Tag);
    }
    ToolButtons->Realign();
}

void __fastcall TIntExplorer::tbObjectsClick(TObject *Sender)
{
    TToolButton* BT = (TToolButton*)Sender;
    if (BT->Tag != IDMouseAction)
    {
        LV->Tag = BT->Tag;
        UpdateView(true);
    }
    else
    {
        MetaCatalogUnit = NULL;
    }
}

//---------------------------------------------------------------------------
void TIntExplorer::Start()
{
    if (!LV->Selected)
        return;

    TMetaNode *MN = (TMetaNode*)LV->Selected->Data;
    if ( MN && MN->Is(TMetaCatalogUnit::StaticType))
        MetaCatalogUnit = (TMetaCatalogUnit*)MN;
    else
        MetaCatalogUnit = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TIntExplorer::LVMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (LV->Selected)
    {
        TMetaNode* MN = (TMetaNode*)LV->Selected->Data;
        if ( MN->Is(TMetaCatalogUnit::StaticType) )
        {
            Start();
        }
        else if ( MN->DynamicType == TMetaNode::StaticType )
        {
            MainToolBar->Buttons[0]->Click();
            MainToolBar->Buttons[0]->Down = true;
            LVS[LV->Tag].CurParent = MN;
            UpdateView(true);
        }
    }
}

void TIntExplorer::UpdateView(bool CanStart)
{
    if ( (LV->Tag < 0) || (LV->Tag >= LVS.Count) )
        return;
    LV->Clear();
    LV->LargeImages = LVS[LV->Tag].BIG;
    LV->SmallImages = LVS[LV->Tag].SML;
    TMTList<TMyRegObject> MRO;

    for (int i=0;i<LVS[LV->Tag].CurParent->ChildList->Count;i++)
    {
        TMetaNode* MN = (TMetaNode*)LVS[LV->Tag].CurParent->ChildList->Items[i];
        if ( !USE_ITEM(MN) )
            continue;
        TListItem* LI = LV->Items->Add();
        LI->Caption = MN->Description;
        LI->ImageIndex = MN->Tag1;
        LI->Data = MN;
    }
    if (CanStart && LV->Items->Count)
    {
        LV->Selected = LV->Items->Item[0];
        Start();
    }
}

//-----------------------512179----------------------------------------------------

void __fastcall TIntExplorer::FormDestroy(TObject *Sender)
{
    IntExplorer = NULL;
    delete &(ControlList);
}
//---------------------------------------------------------------------------

void __fastcall TIntExplorer::tbUpClick(TObject *Sender)
{
    if ( LVS[LV->Tag].CurParent!=LVS[LV->Tag].MaxParent )
    {
        LVS[LV->Tag].CurParent = (TMetaNode*)LVS[LV->Tag].CurParent->Parent;
        UpdateView(false);
    }
}

void __fastcall TIntExplorer::LVMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if (!LV->Focused())
        ::SetFocus(LV->Handle);
}
//---------------------------------------------------------------------------

void __fastcall TIntExplorer::MinimizeClick(TObject *Sender)
{
    Fixed = !Fixed;
}
//---------------------------------------------------------------------------

void TExplorerState::ApplyToExplorer(TIntExplorer* Explorer)
{
    ApplyToControl(Explorer);
    BackPanel.ApplyToControl(Explorer->BackPanel);
    MainToolBar.ApplyToControl(Explorer->MainToolBar);
    MinPanel.ApplyToControl(Explorer->MinPanel);

    UgolPanel.ApplyToControl(Explorer->UgolPanel);
    ParentUp.ApplyToControl(Explorer->ParentUp);
    ToolPanel.ApplyToControl(Explorer->ToolPanel);
    ToolButtons.ApplyToControl(Explorer->ToolButtons);
//    PanelPos.ApplyToControl(Explorer->PanelPos);
//    BIG.ApplyToControl(Explorer->BIG);
//    SMALL.ApplyToControl(Explorer->SMALL);
}


void TIntExplorer::SetExplorerStates()
{
    //----------------------------------------
//    ExpStates[AlignBottom].Height = 100;
    //----------------------------------------
    ExpStates[AlignBottom].BackPanel.Height = GetToolBarHeight();
    ExpStates[AlignBottom].BackPanel.Align = alBottom;
    //----------------------------------------
    ExpStates[AlignBottom].MinPanel.Parent = BackPanel;
    ExpStates[AlignBottom].MinPanel.Align = alLeft;

    //----------------------------------------
    ExpStates[AlignBottom].MainToolBar.Height = GetToolBarHeight();
    ExpStates[AlignBottom].MainToolBar.Left = GetToolBarWidth();
    ExpStates[AlignBottom].MainToolBar.Top = 0;
    //----------------------------------------
    ExpStates[AlignBottom].UgolPanel.Width = GetToolBarHeight();
    ExpStates[AlignBottom].UgolPanel.Align = alLeft;
    //----------------------------------------
    ExpStates[AlignBottom].ParentUp.Left = 1;
    ExpStates[AlignBottom].ParentUp.Top = 1;

    ExpStates[AlignBottom].ToolPanel.Align = alLeft;
    ExpStates[AlignBottom].ToolButtons.Align = alLeft;

    //----------------------------------------
    //----------------------------------------
//    ExpStates[AlignLeft].BackPanel.Width = 156;
    //----------------------------------------
    ExpStates[AlignLeft].BackPanel.Width = GetToolBarHeight();
    ExpStates[AlignLeft].BackPanel.Align = alLeft;
    //----------------------------------------
    ExpStates[AlignLeft].MinPanel.Parent = UgolPanel;
    ExpStates[AlignLeft].MinPanel.Align = alLeft;
    //----------------------------------------
    ExpStates[AlignLeft].MainToolBar.Width = GetToolBarHeight();
    ExpStates[AlignLeft].MainToolBar.Height = 220;
    ExpStates[AlignLeft].MainToolBar.Left = 0;
    ExpStates[AlignLeft].MainToolBar.Top = 0;
    //----------------------------------------
    ExpStates[AlignLeft].UgolPanel.Height = GetToolBarHeight();
    ExpStates[AlignLeft].UgolPanel.Align = alTop;
    //----------------------------------------
    ExpStates[AlignLeft].ParentUp.Left = 87;
    ExpStates[AlignLeft].ParentUp.Top = 1;
    //----------------------------------------
    ExpStates[AlignLeft].ToolPanel.Align = alTop;
    ExpStates[AlignLeft].ToolButtons.Align = alTop;
    //----------------------------------------

    //----------------------------------------
//    ExpStates[AlignRight].BackPanel.Width = 156;
    //----------------------------------------
    ExpStates[AlignRight].BackPanel.Width = GetToolBarHeight();
    ExpStates[AlignRight].BackPanel.Align = alRight;
    //----------------------------------------
    ExpStates[AlignRight].MinPanel.Parent = UgolPanel;
    ExpStates[AlignRight].MinPanel.Align = alRight;
    //----------------------------------------
    ExpStates[AlignRight].MainToolBar.Width = GetToolBarHeight();
    ExpStates[AlignRight].MainToolBar.Height = 220;
    ExpStates[AlignRight].MainToolBar.Left = 0;
    ExpStates[AlignRight].MainToolBar.Top = 0;
    //----------------------------------------
    ExpStates[AlignRight].UgolPanel.Height = GetToolBarHeight();
    ExpStates[AlignRight].UgolPanel.Align = alTop;
    //----------------------------------------
    ExpStates[AlignRight].ParentUp.Left = 1;
    ExpStates[AlignRight].ParentUp.Top = 1;
    //----------------------------------------
    ExpStates[AlignRight].ToolPanel.Align = alTop;
    ExpStates[AlignRight].ToolButtons.Align = alTop;
    //----------------------------------------

}

void TIntExplorer::OnMyResize()
{
    RefreshAlign();
    UpdateView(false);
    btnMinimize->ImageIndex = (Fixed)? 1 : 0;
}


void TIntExplorer::AUIChanged()
{
	IntExplorer->Visible = AUI.CheckExplorerVisible();
	/* TODO :  HARDCORE*/
	if (!IntExplorer->Parent && Application->MainForm)
	{
		TPanel *pnlLeftSide = (TPanel*)Application->MainForm->FindComponent("pnlLeftSide");
		IntExplorer->ManualDock(pnlLeftSide);
	}
	MainToolBar->Buttons[0]->Click();
}

void __fastcall TIntExplorer::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if ( AUI.CheckExplorerVisible() )
    {
        Action = caNone;
        Fixed = true;
    }
}



void _fastcall TIntExplorer::WndProc(Messages::TMessage &Message)
{
    switch(Message.Msg)
    {
        case WM_NOTIFY:
        case CN_NOTIFY:
        {
            if ( Message.WParam == SELECTION_CHANGED )
                ProcessActivateTools();  
        }break;
        default:
            TFloatForm::WndProc(Message);
    };
}


