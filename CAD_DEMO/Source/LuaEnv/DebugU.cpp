//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "MyRegTreeV.h"
#pragma hdrstop

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"

#include "ImgLibV.h"
#include "DebugU.h"
#include "BaseVariableFormV.h"
#include "StackMain.h"
#include "TreeFormV.h"
#include "InspectorMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDebugForm *DebugForm;
lua_Debug DebugInfo;

TMDelTList<TLuaVariable> *AllLVars;
TMDelTList<TLuaVariable> *AllGVars;
TMDelTList<TLuaVariable> *AllStack;

TLuaRegObject *AllTree;
TLuaModule* LM;

PROCESS_INFORMATION pi;

void __fastcall InitDebug()
{   
    AllGVars->Clear();
    AllLVars->Clear();
    AllStack->Clear();
}

void __fastcall CloseDebug()
{
    if (DebugMode!=DBGMODE_STOP)
    {
        PostThreadMessage(ApplHnd,WM_USER,MSG_STOP,0);
        DebugMode=DBGMODE_STOP;
    }
    CloseAllInspectors();
    TerminateProcess(pi.hProcess,0);
}

void __fastcall RunProcess(AnsiString appName, AnsiString appCmdLine)
{
    if (FileMap)
    {
        delete FileMap;FileMap=NULL;
    }
    FileMap=new TFileMapStream("LUA");

    STARTUPINFO si;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    if (!CreateProcess(
          appName.c_str(),       // pointer to name of executable module
          appCmdLine.c_str(),	// pointer to command line string
          NULL,	// pointer to process security attributes
          NULL,	// pointer to thread security attributes
          FALSE,	// handle inheritance flag
          0,	// creation flags
          NULL,	// pointer to new environment block
          NULL,	// pointer to current directory name
          &si,	// pointer to STARTUPINFO
          &pi 	// pointer to PROCESS_INFORMATION
          )
        )
    {
        DisplayMessage(GetLastError());
    }
    ApplHnd=pi.dwThreadId;
    DebugMode=DBGMODE_WORK;
}

//---------------------------------------------------------------------------
__fastcall TDebugForm::TDebugForm(TComponent *Owner)
	: TBaseDockSiteForm(Owner)
{
    TLuaStation();
    LuaAllOpen();
    AllLVars = new TMDelTList<TLuaVariable>;
    AllGVars = new TMDelTList<TLuaVariable>;
    AllStack = new TMDelTList<TLuaVariable>;
    AllTree = new TLuaRegObject;
    AllTree->MyTree=NULL;
    LM = NULL;

    GlobalVars=NULL;
    LocalVars=NULL;
    StackWnd=NULL;
    TreeWnd=NULL;
    WatchWnd=NULL;
    BreakPointsWnd=NULL;
}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormCreate(TObject *Sender)
{
    InitDebug();
    RunProcess("pConfig.exe"," DEBUG INIT");
}
//---------------------------------------------------------------------------
__fastcall TDebugForm::~TDebugForm()
{
    CloseDebug();
    if (GlobalVars) delete GlobalVars;
    if (LocalVars) delete LocalVars;
    if (StackWnd) delete StackWnd;
    if (BreakPointsWnd) delete BreakPointsWnd;
    if (WatchWnd) delete WatchWnd;
    if (AllStack) delete AllStack;
    if (AllLVars) delete AllLVars;
    if (AllGVars) delete AllGVars;
    LuaAllClose();

}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::OnTreeDblClick(TObject *Sender)
{
    TMyRegObject *Data = NULL;
    TTreeNode *Item = ((TTreeView*)Sender)->Selected;
    if (Item) Data = (TMyRegObject*)Item->Data;
    if ((Data)&&(Data->ImageIndex==28))
        LM = (TLuaModule*)TLuaModule::StaticType->RecurrentFindByGUID(Data->Description);
    if (LM)
    {
        TFLuaEditor* Ed= (LM->FindEditor());
        if (!Ed)
            {
                LM->Edit(Application,NULL,NULL);
                Ed= (LM->FindEditor());
            }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::OnBrkpntDblClick(TObject *Sender)
{
    TListView *List = (TListView*)Sender;
    TListItem *Item = List->Selected;
    if (Item)
    {
        TLuaModule *Module = (TLuaModule*)Item->Data;
        TFLuaEditor* Ed= (Module->FindEditor());
        if (!Ed)
            {
                Module->Edit(Application,NULL,NULL);
                Ed= (Module->FindEditor());
            }
        Ed->SciLexer->SendEditor(SCI_GOTOLINE,StrToInt(Item->SubItems[0][0]));
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ViewStackUpdate(TObject *Sender)
{
    StackViewItem->Enabled=(AllTree->MyTree);
    StackViewItem->Checked=((StackWnd)&&(StackWnd->Visible));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StartItemUpdate(TObject *Sender)
{
   StartItem->Enabled=((DebugMode==DBGMODE_STOP)||(DebugMode==DBGMODE_PAUSE));
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::StopItemUpdate(TObject *Sender)
{
    StopItem->Enabled=(DebugMode!=DBGMODE_STOP);
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::TraceInItemUpdate(TObject *Sender)
{
    TraceInItem->Enabled=((DebugMode==DBGMODE_STOP)||(DebugMode==DBGMODE_PAUSE));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::PauseItemUpdate(TObject *Sender)
{
    PauseItem->Enabled=((DebugMode!=DBGMODE_STOP)&&(DebugMode!=DBGMODE_PAUSE));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StepOverItemUpdate(TObject *Sender)
{
    StepOverItem->Enabled=(DebugMode==DBGMODE_PAUSE);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FindItemUpdate(TObject *Sender)
{
    FindModule1->Enabled=(AllTree->MyTree);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ShowTreeItemUpdate(TObject *Sender)
{
    ShowMdlsTree->Enabled=(AllTree->MyTree);
    ShowMdlsTree->Checked=((AllTree->MyTree)&&(TreeWnd)&&(TreeWnd->Active));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ShowBrkpntItemUpdate(TObject *Sender)
{
    ShowBreakpoints->Enabled=(AllTree->MyTree);
    ShowBreakpoints->Checked=((BreakPointsWnd)&&(BreakPointsWnd->Visible));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ViewLocalVarsUpdate(TObject *Sender)
{
    LocalVariableItem->Enabled=(AllTree->MyTree);
    LocalVariableItem->Checked=((LocalVars)&&(LocalVars->Visible));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ViewGlobalVarsUpdate(TObject *Sender)
{
    GlobalVariableItem->Enabled=(AllTree->MyTree);
    GlobalVariableItem->Checked=((GlobalVars)&&(GlobalVars->Visible));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::WatchItemUpdate(TObject *Sender)
{
    WatchViewItem->Enabled=(AllTree->MyTree);
    WatchViewItem->Checked=((WatchWnd)&&(WatchWnd->Visible));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::EvaluteItemUpdate(TObject *Sender)
{
    EvaluteItem->Enabled=(AllTree->MyTree);
}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::WatchItemExecute(TObject *Sender)
{
    if (!WatchWnd)
    {
        WatchWnd = new TGlobal(this);
        WatchWnd->Width=500;
        WatchWnd->Height=200;
        WatchWnd->BorderStyle=bsSizeToolWin;
        WatchWnd->Caption="Watches";
        WatchWnd->OnActivate=WatchWnd->Evaluate;
        WatchWnd->OnUpdate=UpdateWatches;
        TListView *MyList = WatchWnd->List;
        MyList->Columns->Clear();
        MyList->OnDblClick=WatchWnd->EditItem->OnExecute;
        MyList->PopupMenu=WatchWnd->WatchPopup;
        TListColumn *Item = MyList->Columns->Add();
        Item->Caption = "Выражение";
        Item->Width=-2;
        Item = MyList->Columns->Add();
        Item->Caption = "Значение";
        Item->Width=-2;
    }
    if (!WatchViewItem->Checked)
    {
        WatchWnd->Evaluate(Sender);
        WatchWnd->Show();
    }
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::ViewStackExecute(TObject *Sender)
{
    if (!StackViewItem->Checked)
    {
        if (StackWnd!=NULL)
        {
            StackWnd->Show();
            StackWnd->ViewStack(AllStack);
        }
        else
        {
            StackWnd = new TStackWindow(this);
            StackWnd->Caption="Содержимое стека";
            StackWnd->Show();
            StackWnd->ViewStack(AllStack);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ViewLocalVarsExecute(TObject *Sender)
{
    if (!LocalVariableItem->Checked)
    {
        if (this->LocalVars!=NULL)
        {
            LocalVars->Show();
            LocalVars->ViewVars(AllLVars);
        }
        else
        {
            LocalVars = new TGlobal(this);
            LocalVars->Caption="Локальные переменные";
            LocalVars->BorderStyle=bsSizeToolWin;
            LocalVars->ViewVars(AllLVars);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ViewGlobalVarsExecute(TObject *Sender)
{
    if (!GlobalVariableItem->Checked)
    {
        if (this->GlobalVars!=NULL)
        {
            GlobalVars->Show();
            GlobalVars->ViewVars(AllGVars);
        }
        else
        {
            GlobalVars = new TGlobal(this);
            GlobalVars->Caption="Глобальные переменные";
            GlobalVars->BorderStyle=bsSizeToolWin;
            GlobalVars->ViewVars(AllGVars);
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::StopItemExecute(TObject *Sender)
{
    CloseDebug();
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::TraceInItemExecute(TObject *Sender)
{
    if (DebugMode!=DBGMODE_STOP)
        PostThreadMessage(ApplHnd,WM_USER,MSG_TRACEIN,0);
    else
    {
        InitDebug();
        RunProcess("pConfig.exe", " DEBUG");
        DebugMode=DBGMODE_TRACEIN;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StepOverItemExecute(TObject *Sender)
{
    PostThreadMessage(ApplHnd,WM_USER,MSG_STEPOVER,0);
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::PauseItemExecute(TObject *Sender)
{
    PostThreadMessage(ApplHnd,WM_USER,MSG_PAUSE,0);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StartItemExecute(TObject *Sender)
{
    if (DebugMode==DBGMODE_STOP)
    {
        InitDebug();
        RunProcess("pConfig.exe"," DEBUG");
    }
    else
        PostThreadMessage(ApplHnd,WM_USER,MSG_RESUME,0);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FindItemExecute(TObject *Sender)
{
    FndDialog->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::ShowTreeItemExecute(TObject *Sender)
{
    if (!ShowMdlsTree->Checked)
    {
        TreeWnd = new TTreeWindow(this);
        TreeWnd->Tree->OnDblClick=DebugForm->OnTreeDblClick;
        TreeWnd->FormStyle=fsMDIChild;
        TreeWnd->BorderStyle=bsSizeable;
        TreeWnd->WindowState=wsMaximized;
        TreeWnd->Caption="Дерево объектов";
        TreeWnd->Tree->Images=ImageLibrary->TreeImages;
        if (AllTree->MyTree) AllTree->MyTree->FillTreeView(TreeWnd->Tree);
        TreeWnd->Tree->Items->GetFirstNode()->Expand(false);
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::UpdateBreakpoints(TObject *Sender)
{
    TClassNode *Node = TLuaModule::StaticType;
    if (BreakPointsWnd)
    {
        TListView *MyList = BreakPointsWnd->List;
        MyList->Items->BeginUpdate();
        MyList->Clear();
        for (int i=0;i<Node->GetRegInfoCount();i++)
        {
            TLuaModule *Module = (TLuaModule*)Node->GetRegInfo(i)->Object;
            for (int j=0;j<Module->BreakPoints.Count;j++)
            {
                TListItem *Item = MyList->Items->Add();
                Item->Caption=Module->Name;
                Item->Data=Module;
                Item->SubItems->Add(*Module->BreakPoints.GetItem(j));
            }
        }
        MyList->Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::UpdateWatches(TObject *Sender)
{
    if (WatchWnd)
    {
        TMDelTList<AnsiString> Data;
        TListItem *Item = NULL;
        FileMap->Position=0;
        Data.ReadData(FileMap);
        WatchWnd->List->Items->BeginUpdate();
        for (int i=0;i<Data.Count;i++)
        {
            Item = WatchWnd->List->Items->Item[i];
            if (Item) Item->SubItems[0].Text=(*Data.GetItem(i));
        }
        WatchWnd->List->Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ShowBrkpntItemExecute(TObject *Sender)
{
    if (!BreakPointsWnd)
    {
        BreakPointsWnd = new TGlobal(this);
        BreakPointsWnd->Width=500;
        BreakPointsWnd->Height=200;
        BreakPointsWnd->BorderStyle=bsSizeToolWin;
        BreakPointsWnd->Caption="Breakpoints";
        BreakPointsWnd->OnUpdate=UpdateBreakpoints;
        TListView *MyList = BreakPointsWnd->List;
        MyList->Columns->Clear();
        MyList->OnDblClick=OnBrkpntDblClick;
        TListColumn *Item = MyList->Columns->Add();
        Item->Caption = "Module";
        Item->Width=-2;
        Item = MyList->Columns->Add();
        Item->Caption = "Line";
        Item->Width=-2;
    }
    if (!ShowBreakpoints->Checked)
    {
        BreakPointsWnd->Show();
        UpdateBreakpoints(this);
    }
}
//---------------------------------------------------------------------------
//Процедура чтения информации
//---------------------------------------------------------------------------
void __fastcall StateRead(int Line)
{
    bool bCurrent=false;
    TMDelTList<AnsiString> ModuleName;
    FileMap->Position=0;
    ModuleName.ReadData(FileMap);
    AnsiString mGUID=*ModuleName.Last();
    if (!(mGUID=="Unknown"))
    {
        if ((LM)&&(LM->GUID==mGUID)) bCurrent=true;
        if (!bCurrent)
        {
            if (LM)
            {
                TFLuaEditor* Ed= (LM->FindEditor());
                if (Ed)
                {
                    Ed->SciLexer->SendEditor(SCI_MARKERDELETE,LM->OldLine,4);
                    Ed->SciLexer->SendEditor(SCI_MARKERDELETE,LM->OldLine,8);
                }
                LM->OldLine=0;
            }
            LM = (TLuaModule*)TLuaModule::StaticType->RecurrentFindByGUID(mGUID);
        }
        if (LM)
        {
            TFLuaEditor* Ed= (LM->FindEditor());
            if (!Ed)
                {
                    LM->Edit(Application,NULL,NULL);
                    Ed= (LM->FindEditor());
                }
            ((TForm*)Ed->Parent)->Caption=LM->Name;
            Ed->SciLexer->SendEditor(SCI_MARKERDELETE,LM->OldLine,4);
            Ed->SciLexer->SendEditor(SCI_MARKERDELETE,LM->OldLine,8);
            Ed->SciLexer->SendEditor(SCI_GOTOLINE,Line+3);
            Ed->SciLexer->SendEditor(SCI_GOTOLINE,Line-1);
            Ed->SciLexer->SendEditor(SCI_MARKERADD,Line-1,4);
            Ed->SciLexer->SendEditor(SCI_MARKERADD,Line-1,8);
            LM->OldLine=Line-1;
        }
    }
    AllGVars->Clear();
    AllGVars->ReadData(FileMap);

    AllLVars->Clear();
    AllLVars->ReadData(FileMap);

    AllStack->Clear();
    AllStack->ReadData(FileMap);
    if((DebugForm->LocalVars)&&(DebugForm->LocalVars->Visible))
        DebugForm->LocalVars->ViewVars(AllLVars);
    if((DebugForm->GlobalVars)&&(DebugForm->GlobalVars->Visible))
        DebugForm->GlobalVars->ViewVars(AllGVars);
    if((DebugForm->StackWnd)&&(DebugForm->StackWnd->Visible))
        DebugForm->StackWnd->ViewStack(AllStack);
}

void ReccurentAddChilds(TLuaRegObject *Root)
{
    if (Root->Modules.Count>0)
        for (int i=0;i<Root->Modules.Count;i++)
        {
            TLuaRegObject *Module = new TLuaRegObject;
            Module->ImageIndex=28;
            Module->Name=Root->Modules.GetItem(i)->Name;
            Module->Description=Root->Modules.GetItem(i)->GUID;
            Root->MyTree->AddChild(Root,Module);
        }
    for (int i=0;i<Root->ChildList->Count-Root->Modules.Count;i++)
    {
        ReccurentAddChilds((TLuaRegObject*)Root->ChildList->GetItem(i));
    }
}
//---------------------------------------------------------------------------
//Обработчик событий окна
//---------------------------------------------------------------------------

void _fastcall TDebugForm::WndProc(Messages::TMessage &Message)
{
    switch(Message.Msg)
    {
        case WM_USER:
        {
            switch (Message.WParam)
            {
                case MSG_GETEVALUATE:
                {
                    char *Text = (char*)Message.LParam;
                    Inspect(AnsiString(Text));
                    delete []Text;
                    break;
                }
                case MSG_UPDATE:
                {
                    TMDelTList<AnsiString> ModuleName;
                    FileMap->Position=0;
                    ModuleName.ReadData(FileMap);
                    LM = (TLuaModule*)TLuaModule::StaticType->RecurrentFindByGUID(*ModuleName.Last());
                    LM->BreakPoints.ReadData(FileMap);
                    UpdateBreakpoints(this);
                    /*TFLuaEditor* Ed= (LM->FindEditor());
                    if (Ed) Ed->Refresh();
                    */
                    FileMap->Position=0;
                }break;

                case MSG_RETHOOK:
                {
                }break;
                case MSG_UPDATEWATCH:
                {
                    UpdateWatches(this);
                }break;
                case MSG_CALLHOOK:
                {
                }break;
                case MSG_BREAKPOINT:
                case MSG_LINEHOOK:
                {
                    StateRead(Message.LParam);
                    if (InSendMessage()) ReplyMessage(0);
                    UpdateAllInspectors();
                    if  (WatchWnd) WatchWnd->Evaluate(this);
                }break;
                case MSG_READY:
                {
                    if (!AllTree->MyTree)
                    {
                        FileMap->Position=0;
                        AllTree->MyTree = new TMyRegTree;
                        AllTree->MyTree->ReadData(FileMap);
                        AllTree->MyTree->CheckData(AllTree);
                        ReccurentAddChilds((TLuaRegObject*)AllTree->MyTree->Head);
                        CloseDebug();
                        Actions->State=asNormal;
                        //ShowTreeItemExecute(this);
                    }
                    else
                    {
                        FileMap->Position=0;
                        TMDelTList<AnsiString> GUIDs;
                        for (int i=0;i<TLuaModule::StaticType->GetRegInfoCount();i++)
                            GUIDs.Add(new AnsiString(TLuaModule::StaticType->GetRegInfo(i)->Object->GUID));
                        GUIDs.WriteData(FileMap);
                        for (int i=0;i<TLuaModule::StaticType->GetRegInfoCount();i++)
                            ((TLuaModule*)(TLuaModule::StaticType->GetRegInfo(i)->Object))->BreakPoints.WriteData(FileMap);
                        PostThreadMessage(ApplHnd,WM_USER,MSG_UPDATEALL,0);
                    }
                    if (DebugMode==DBGMODE_WORK) PostThreadMessage(ApplHnd,WM_USER,MSG_RESUME,0);
                    if (DebugMode==DBGMODE_TRACEIN) PostThreadMessage(ApplHnd,WM_USER,MSG_TRACEIN,0);
                }
                break;
                case MSG_SETMODE:
                {
                    DebugMode=Message.LParam;
                }break;
                case MSG_FINISH:
                {
                    CloseDebug();
                }break;
                case MSG_FMSTATE:
                {
                    switch (Message.LParam)
                    {
                        case 0:{FileMap->Close();break;}
                        case 1:{FileMap->Open();break;}
                    }
                }
                break;

                case MSG_ERROR:DebugMode=DBGMODE_STOP;
            }
        }
        default: TForm::WndProc(Message);
    };
}
//---------------------------------------------------------------------------


void __fastcall TDebugForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FndDialogFind(TObject *Sender)
{
    TFindDialog *Dlg = (TFindDialog*)Sender;
    LM=(TLuaModule*)(TLuaModule::StaticType->RecurrentFindByName(Dlg->FindTextA));
    if (LM)
    {
        TFLuaEditor* Ed= (LM->FindEditor());
        if (!Ed)
            {
                LM->Edit(Application,NULL,NULL);
                Ed= (LM->FindEditor());
            }
    }
    Dlg->CloseDialog();
}
//---------------------------------------------------------------------------

void __fastcall TDebugForm::EvaluteModify1Click(TObject *Sender)
{
    AnsiString Text = InputBox("Quick evaluate", "Введите код", "");
    if (Text!="") Inspect(Text);
}

