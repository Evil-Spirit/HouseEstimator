//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#pragma hdrstop

#include "LuaUniFormV.h"
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
TLuaUniForm *LuaUniForm = NULL;
//---------------------------------------------------------------------------
__fastcall TLuaUniForm::TLuaUniForm(TComponent* Owner,TLuaModule* _Module)
    : TForm(Owner)
{
    AutoAlign = true;
    Module = _Module;
    ShowElement = NULL;
    ShowMetaElement = NULL;
    Ihs.Clear();
    Names.Clear();
    FPanels[0] = Panel1;
    FPanels[1] = Panel2;
    FPanels[2] = Panel3;
    FPanels[3] = Panel4;
    FPanels[4] = Panel5;
    for (int i=0;i<5;i++)
    {
        FPanels[i]->Top = 0;
        FPanels[i]->Left = 0;
        FPanels[i]->Width = pView->Left;
        FPanels[i]->Height = pView->Height;
        FPanels[i]->Visible = false;
    }
}

__fastcall TLuaUniForm::TLuaUniForm(TComponent* Owner)
    : TForm(Owner)
{
    throw EMyException("Invalid constructor");
}

TWinControl* TLuaUniForm::GetPanel(int PanelIndex)
{
    if (PanelIndex<5 && PanelIndex>=0)
        return FPanels[PanelIndex];
    else
        return NULL;
}

TWinControl* TLuaUniForm::GetPage(int PanelIndex,int PageIndex)
{
    if (PanelIndex<5 && PanelIndex>=0 && FPanels[PanelIndex]->ControlCount)
    {
        TControl* C = FPanels[PanelIndex]->Controls[0];
        if ( IS(C,__classid(TPageControl)) )
        {
            TPageControl* PC = (TPageControl*)C;
            if (PC->PageCount>PageIndex && PageIndex>=0)
                return PC->Pages[PageIndex];
        }
    }
    return NULL;
}

void TLuaUniForm::SetCaption(char* _Caption)
{
    Caption = AnsiString(_Caption);
}

void TLuaUniForm::SetPageCountForPanel(int PanelIndex, int PageCount)
{
    TPageControl* PC = NULL;
    if (PanelIndex>=5 || PanelIndex<0)
        return;
    if(FPanels[PanelIndex]->ControlCount)
    {
        TControl* C = FPanels[PanelIndex]->Controls[0];
        if ( IS(C,__classid(TPageControl)) )
            PC = (TPageControl*)C;
        else
            while( FPanels[PanelIndex]->ControlCount )
                delete FPanels[PanelIndex]->Controls[0];
    }
    if (PC == NULL)
    {
        PC = new TPageControl(FPanels[PanelIndex]);
        PC->Parent = FPanels[PanelIndex];
        PC->Align = alClient;
    }
    while (PC->PageCount<PageCount)
    {
        TTabSheet* TS = new TTabSheet(PC);
        TS->PageControl = PC;
    }
}

void TLuaUniForm::SetPageCaption(int PanelIndex,int PageIndex,char* Caption)
{
    TWinControl* C = GetPage(PanelIndex,PageIndex);
    if ( IS(C,__classid(TTabSheet)) )
        ((TTabSheet*)C)->Caption = AnsiString(Caption);
}

void TLuaUniForm::SetDialogParent(TWinControl* Parent,char* DialogName)
{
/* TODO :  */
		//Ihandle* H = IupGetHandle( DialogName );
		void *H = NULL;
		if (!H)
				throw EMyException("Error""SetDialogParent"": The handle is empty");
		/*
		IupSetAttribute(H , "NATIVEPARENT", (char*)(Parent->Handle ));
		Ihs.Add( H );
		IupShowXY(H,0,0);
		*/
		Names.Add(new AnsiString(DialogName));
}

//---------------------------------------------------------------------------
bool TLuaUniForm::ShowView()
{
		return (ShowElement || ShowMetaElement);
}

//---------------------------------------------------------------------------
void __fastcall TLuaUniForm::FormCreate(TObject *Sender)
{
    CloseOK = false;
    LuaUniForm = this;
}
//---------------------------------------------------------------------------
void TLuaUniForm::Start()
{
    if (!LuaUniForm)
        return;
    Top =  Screen->Height/2-Height/2;
    Left = Screen->Width/2 -Width/2;
    //--------------------------------------------------------------------------
    if (ShowView())
    {
        MT = new TMainTree();
        MT->AddFloor(-1);
        TV = new TMDITV(this,pView,MT);

        if (ShowElement)
        {
            Element = ShowElement;
//            UndoStack.Register(Element);
        }
        else
        {
            AnsiString CN = CutMeta( AnsiString(typeid(*(ShowMetaElement)).name()).Trim() );
            Element = CreateElementFunction(MT,ShowMetaElement);
        }

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
    if (AutoAlign)
    {
        bool VisibleView = ShowView();
        bool Buttons = btOK->Visible || btApply->Visible || btCancel->Visible;
        if (!Buttons)
            pView->Height = ClientHeight;
        for (int i=0;i<5;i++)
            {
                FPanels[i]->Left = 0;
                FPanels[i]->Top = 0;
                if (VisibleView)
                    FPanels[i]->Width = pView->Left;
                else
                {
                    FPanels[i]->Align = alClient;
                    FPanels[i]->Align = alNone;
                }
                FPanels[i]->Height = pView->Height;
            }
    }
    //--------------------------------------------------------------------------
    ShowModal();
}
void __fastcall TLuaUniForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
		if (!LuaUniForm)
        return;
    for (int i=0;i<Ihs.Count;i++)
    {
				/* TODO :  */
				/*IupHide((Ihandle*)Ihs.Items[i]);
				IupSetHandle(Names[i].c_str(), NULL);
				*/
		}
		//Ihs.Clear();
		Names.Clear();
		if( !CloseOK )
		{
//        if (ShowElement)
//            UndoStack.DeleteLast();
				RUN_LUA("DIALOG_CALLBACK_CANCEL();");
		}
}
//---------------------------------------------------------------------------

void __fastcall TLuaUniForm::FormDestroy(TObject *Sender)
{
		if (ShowView())
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
    LuaUniForm = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TLuaUniForm::btOKClick(TObject *Sender)
{
    CloseOK = true;
    RUN_LUA("DIALOG_CALLBACK_OK();");
}
//---------------------------------------------------------------------------
void __fastcall TLuaUniForm::btCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TLuaUniForm::btApplyClick(TObject *Sender)
{
    RUN_LUA( "DIALOG_CALLBACK_APPLY();");
    SelectionCollection.Enabled=false;
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------
void __fastcall TLuaUniForm::FormActivate(TObject *Sender)
{
    if (ShowView())
    {
        AUI.ActivateView(TV);
        SelectionCollection.Enabled=false;
    }
}
//---------------------------------------------------------------------------
