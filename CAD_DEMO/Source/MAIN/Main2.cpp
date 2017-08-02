//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "Main2.h"
#include "About.h"
#include "ExcelExchangeV.h"
#include "RegisterArchitectureV.h"
#include "RegisterKernelV.h"
#include "MySupportV.h"
#include "AUIV.h"
#include "OutPutV.h"
#include "MainToolsV.h"

#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "LuaStationV.h"

#include "VCLSCILEXERV.h"

#include "ProgBarV.h"
#include "ClassExplorerV.h"
#include "MetaToolV.h"

//----------------------------------------------------------------------------
#if !defined(INTERNET_VER) && !defined(TRADE_VER)
    #include "MDIConfigV.h"
    #include "MDIElementV.h"
#endif
//----------------------------------------------------------------------------
#include "MDI3DUserV.h"
#include "World.h"
#include "LOGOV.h"
#include "LogicNode.h"
#include "IntExplorerV.h"
#include "QuckList.h"
#include "UNDO.h"
#include "MDICountReportV.h"
#include "CounterBaseV.h"
#include "MDIVisibleSelectFloorV.h"
#include "UI.h"

/*#include "MDITVV.h"
#include "MDI3DUserV.h"
//#include "MDICheckV.h"
#include "OutPutV.h"
#include "MYIMPORTV.h"
//#include "MDIFloorControlV.h"
#include "Triangulation.h"
#include "MetaNodeCollectionV.h"  */
//---------------------------------------------------------------------------
#pragma link "VisTimer"

#pragma package(smart_init)
#pragma link "BaseDockSiteFormV"
#pragma resource "*.dfm"

//#define RUNLIMITED
TConfig1 *Config1;

//---------------------------------------------------------------------------

__fastcall TConfig1::TConfig1(TComponent *Owner)
	: TBaseDockSiteForm(Owner)
{
}
//---------------------------------------------------------------------------
TMDI3D* FindMDI3D()
{
    return ((TMDI3D*)ComponentExists(__classid(TMDI3D)));
}

void __fastcall TConfig1::FileNew1Execute(TObject *Sender)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    TMDIConfig *MDIC;
    if ( (MDIC = (TMDIConfig *)ComponentExists(__classid(TMDIConfig),Application))!=NULL )
    {
        MDIC->Close();
        Application->ProcessMessages();
    }
    if ( (MDIC = (TMDIConfig *)ComponentExists(__classid(TMDIConfig),Application))!=NULL )
        return;
    #endif

    if (!World)
    {
        World = new TMainTree();
        if (World->AddFloor(-1))
            new TMDI3DUser(Application,World);
        else
        {
            delete World;
            World = NULL;
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------




void __fastcall TConfig1::ScrollerMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Y>X)
        if (Y>22-X)
            MainTimer->Tag=2;
        else
            MainTimer->Tag=3;
    else
        if (Y>22-X)
            MainTimer->Tag=4;
        else
            MainTimer->Tag=1;
    Scroller->ImageIndex = Scroller->Tag;
    MainTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::ScrollerMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MainTimer->Tag=0;
    Scroller->ImageIndex = Scroller->Tag;
    MainTimer->Enabled = false;
}
//---------------------------------------------------------------------------

TMenuItem *FindMIByTag(TMenuItem *MI,int _Tag)
{
    for (int i=0;i<MI->Count;i++)
        if (MI->Items[i]->Tag == _Tag)
            return (MI->Items[i]);
    return NULL;
}

TMenuItem *MIByActionAndMode(int _TagAction,int _TagMode)
{
    TMenuItem *MI;
    TMenuItem *MI2;
    if ( (MI = FindMIByTag(Config1->miTransformation,_TagAction))!=NULL )
        if ( (MI2=FindMIByTag(MI,_TagMode))!=NULL)
            return MI2;
        else
            return MI;
    else
        return NULL;
}

TMenuItem *MIByAction(int _TagAction)
{
    return FindMIByTag(Config1->miTransformation,_TagAction);
}


void __fastcall TConfig1::FormCreate(TObject *Sender)
{
    // change wnd procs for the docking panels
    OldLeftDockWndProc = pnlLeftSide->WindowProc;
    OldRightDockWndProc = pnlRightSide->WindowProc;
    OldBottomDockWndProc = pnlBottomSide->WindowProc;

    pnlLeftSide->WindowProc = LeftDockWindowProc;
    pnlRightSide->WindowProc = RightDockWindowProc;
    pnlBottomSide->WindowProc = BottomDockWindowProc;

    #if defined(INTERNET_VER)
    Caption = AnsiString(" Personal planner");
    #elif defined(TRADE_VER)
    Caption = AnsiString(" Distributors planner");
    #else
    Caption = AnsiString(" Advanced planner");
    #endif

    SetStdOut(&MyStdOut);
//    DockOrientation = doHorizontal	;

    Application->OnMessage = AppMessage;
    Application->OnActionUpdate = AppActionUpdate;
    Application->OnActionExecute = AppActionExecute;
    Application->OnIdle = AppIdle;

    Screen->Cursors[crHand] = LoadCursorFromFile("CRHAND.CUR");

    MainDir=GetCurrentDir();
    AnsiString _Name = MainDir+SL+AnsiString("LOGO")+BMP;
    if (FileExists(_Name))
        RunLogo();
    SetMaxTexture(4);

    new TProgBar(Application);
    //инициализация информации о классах и библиотеках
    RegisterKernel();
//    RegisterBaseTool();
    RegisterArchitecture();
    /* TODO : выключена инициализация Actions */

    
//    InitActions();
    //Создание основных объектов
    //------------------------------------------------
    LuaEnvMode = AnsiString(GetCommandLineA()).Pos("DEBUG")!=0;

    LuaAllOpen();
    int  tolua_z_All_open (lua_State*);
    int  tolua_z_List_int_open (lua_State*);
    int  tolua_z_Attributes_open (lua_State*);
    int  tolua_z_Pointer_open (lua_State*);
    int  tolua_z_VisIt_open (lua_State*);
    int  tolua_z_List_open (lua_State* tolua_S);
    int  tolua_z_VCL_open (lua_State* tolua_S);
    tolua_z_All_open(_LUA_); /* My Binding Lua*/
    tolua_z_List_open(_LUA_);
    tolua_z_List_int_open(_LUA_); /* My Binding Lua*/
    tolua_z_Attributes_open(_LUA_);/* My Binding Lua*/
    tolua_z_Pointer_open (_LUA_);
    tolua_z_VisIt_open (_LUA_);
    tolua_z_VCL_open (_LUA_);

//    tolua_ALists_open(_LUA_); /* My Binding Lua*/
//    #ifdef RUNLIMITED
    /*
        HINSTANCE lib = LoadLibrary("chk.dll");
        typedef bool (WINAPI* TCheckDsk) ();
	    TCheckDsk CheckDsk;
        if ( lib != NULL )
            CheckDsk = (TCheckDsk)GetProcAddress(lib,"CheckDsk");
        if ( !lib || !CheckDsk || !CheckDsk())
        {
            ErrorMsg("Access violation at address 0056BCD3 in module 'pConfig.exe'. Write of address 00000020.");
            Application->Terminate();
        };
     */
/*        bool CheckDsk();
        if (!CheckDsk())
        {
            ErrorMsg("Access violation at address 0056BCD3 in module 'pConfig.exe'. Write of address 00000020.");
            Application->Terminate();
        };

    #endif  */

    MetaNodeCollection = new TMetaNodeCollection;
    if (!DirectoryExists(MainDir+SL+DataDirName))
        if (!ForceDirectories(MainDir+SL+DataDirName))
        {
            Application->Terminate();
        }

    SetDefaults();
    //------------------------------------------------
    LN = new TLinkNodes();
//    Select = new TSelect();
//    BIF = new TInterFace();
    //------------------------------------------------
    DataDir = MainDir + SL + DataDirName;
//    _TRY_
            #if !defined(INTERNET_VER) && !defined(TRADE_VER)
                MetaNodeCollection->Load();
            #else
                MetaNodeCollection->Read();
            #endif
/*        }
        __except(EXCEPTION_EXECUTE_HANDLER)
        {
            throw EMyException("Error");
        }
    }
    catch(EMyException)
    {
            #if !defined(INTERNET_VER) && !defined(TRADE_VER)
                MetaNodeCollection->Validate();
            #else
                ErrorMsg("Error");
                Application->Terminate();
            #endif
    }; */

//    ALLACTIONS->FillMenuItem(miTransformation,N12Click,E3Click);
  //  FillButtonBar(NULL);
//    E3Click(MIByActionAndMode(ioScale,stXY));
  //  E3Click(MIByActionAndMode(ioDraw,dtMultiple));
//    N12Click(FindMIByTag(miTransformation,ioMove));

    MetaNodeCollection->FillModes(pmModes,miModeClick);
//    MetaNodeCollection->FillToolBar(NULL,MainToolBar,ButtonMouseDown,ButtonMouseMove,ButtonMouseUp);

//    ButtonMouseDown(MainToolBar->Buttons[0],TMouseButton(),TShiftState()<<ssLeft,0,0);
//    MainToolBar->Buttons[0]->Down = true;
//    MainToolBar->Images = UserImages;
    if (Logo!= NULL)
        Logo->Delete = true;
    //-----------------------------------
    new TIntExplorer(Application);
    RegisterMainTools();
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::FormDestroy(TObject *Sender)
{
    //-----------------------------------
// /* TODO : там где select terminate там intexplorer->terminate */   Select->Terminate();
    //-----------------------------------
    delete IntExplorer;
    IntExplorer = NULL;
    while(MDIChildCount)
        MDIChildren[0]->Close();
//    delete BIF;
//    delete Select;
    delete LN;
    delete MetaNodeCollection;
    //инициализация информации о классах
//    FreeActions();
    //---------------------
    //close LUA
    
    LuaAllClose();
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::ConfiguratorExecute(TObject *Sender)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
  if (!ComponentExists(__classid(TMDIConfig)))
  {
    TQuickList *L = new TQuickList();
    SelectComponents(__classid(TMDI3DUser),L,Application);
    for (int i=0;i<L->Count;i++)
      ((TMDI3DUser*)L->Items[i])->Close();
    Application->ProcessMessages();
    L->Clear();
    SelectComponents(__classid(TMDI3DUser),L,Application);
    if (L->Count>0)
    {
      delete L;
      return;
    }
    else
      delete L;
    new TMDIConfig(Application);
  }
    #endif
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::ToolButton15Click(TObject *Sender)
{
    for (int i=0;i<MDIChildCount;i++)
    {
        if (__classid(TMDI3D)==MDIChildren[i]->ClassType()||MDIChildren[i]->InheritsFrom(__classid(TMDI3D)))
        {
            ((TMDI3D *)MDIChildren[i])->ToggleCamera();
        }
        #if !defined(INTERNET_VER) && !defined(TRADE_VER)

        if (__classid(TMDIElement)==MDIChildren[i]->ClassType()||MDIChildren[i]->InheritsFrom(__classid(TMDIElement)))
        {
            ((TMDI3D *)((TMDIElement *)MDIChildren[i])->TV)->ToggleCamera();
        }
        #endif
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::ToolButton16Click(TObject *Sender)
{
    if (AUI.ActiveView)
        AUI.CameraEngine.ViewAll(AUI.ActiveView->View->Camera);
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::mfNewClick(TObject *Sender)
{
    int index = World->ActiveIndex+1;
    UndoStack.OpenSession("Add floor above actual");
    World->AddFloor(index);
    UndoStack.CloseSession();
}
//---------------------------------------------------------------------------
bool TConfig1::Process_Save_Project()//возвращает истина если ответ не cancel
{
//-------------
    _TRY_
//-------------
    if (!World)
        return false;
    switch(Application->MessageBox( (AnsiString("Сохранить изменения в проекте: ")+World->Name+AnsiString("?")).c_str(),"Confirmation",MB_YESNOCANCEL))
    {
        case 0:
        case IDCANCEL:
            return false;
        case IDYES:
        {
            SaveDialog1->FileName = World->Name;
            if (!SaveDialog1->Execute())
                return false;
            World->WriteFile(ChangeFileExt(SaveDialog1->FileName,eHOME));
        }
        case IDNO:
        {
            World->AskedToSave = true;
            return true;
        }
        default:
            return false;
    }
//---------------------
    _ENDTRY_("<TConfig::Process_Save_Project>: Ошибка при записи файла",return (Application->MessageBox("Ошибка при записи файла, закрыть все равно?","Confirmation",MB_YESNO) == IDYES););
//---------------------

}

void __fastcall TConfig1::FileSaveAs1Execute(TObject *Sender)
{
    //-----------
    _TRY_
    //-----------

        if (World && ComponentExists(__classid(TMDI3DUser)) )
            SaveDialog1->FileName = World->Name;
        if (SaveDialog1->Execute())
        {
          switch(SaveDialog1->FilterIndex)
          {
            case 1:
            {
                if ( World && ComponentExists(__classid(TMDI3DUser)) )
                {
                    World->WriteFile(ChangeFileExt(SaveDialog1->FileName,".home"));
                }
            }
            break;
            case 2:
              if (ActiveMDIChild  && IS(ActiveMDIChild,__classid(TMDI3DUser)))
              {
                TMDI3D* mdi3d = (TMDI3D*)ActiveMDIChild;
                Graphics::TBitmap * bmp = new Graphics::TBitmap();
                bmp->HandleType = bmDIB;
                bmp->Width= 1280;
                bmp->Height= 1024;
                mdi3d->View->GetImage2(bmp);
                bmp->SaveToFile(ChangeFileExt(SaveDialog1->FileName,BMP));
                delete bmp;
              }
/*              else if (ActiveMDIChild  && IS(ActiveMDIChild,__classid(TMDI2D)))
              {
                TMDI2D* mdi2d = (TMDI2D*)ActiveMDIChild;
                Graphics::TBitmap * bmp = new Graphics::TBitmap();
                bmp->HandleType = bmDIB;
                bmp->Width= 1280;
                bmp->Height= 1024;
                mdi2d->DrawView->GetImage(bmp);
                bmp->SaveToFile(ChangeFileExt(SaveDialog1->FileName,BMP));
                delete bmp;
              }       */
            break;
            case 3:
            {
                TMDICountReport* mdicr = (TMDICountReport*)ComponentExists(__classid(TMDICountReport));
                if (mdicr)
                    mdicr->ToExcel(ChangeFileExt(SaveDialog1->FileName,XLS));
            }
            break;
            case 4:
            {
                #if !defined(INTERNET_VER)
                    Act(ChangeFileExt(SaveDialog1->FileName,XLS));
                #endif
            }
            break;
          }
        }
    _ENDTRY_("<TConfig::FileSaveAs1Execute>: Ошибка при записи файла",);
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::FileOpen1Execute(TObject *Sender)
{
//    ShowClasses();
    _TRY_
        if (AUI.ActiveView && IntExplorer)
            IntExplorer->ControlList.CustomExit(AUI.ActiveView);
        if (!OpenDialog->Execute())
            return;
        if (!World)
            World = new TMainTree();
        UndoStack.Clear();
        World->ReadFile(ChangeFileExt(OpenDialog->FileName,".home"));
        if (!ComponentExists(__classid(TMDI3DUser)))
            new TMDI3DUser(Application,World);

    _ENDTRY_("<TConfig::FileOpen1Execute>: Ошибка при открытии файла",);
//    ShowClasses();    
}

void __fastcall TConfig1::btCheckClick(TObject *Sender)
{   /* TODO : Здесь исправить TluaEditor */
    TWinControl* F= Screen->ActiveControl;
    if (F&&F->ClassType()==__classid(TSciLexer))
        StdOut(CheckSintax(((TSciLexer*)F)->Text),true);
}

//---------------------------------------------------------------------------
void __fastcall TConfig1::mCountClick(TObject *Sender)
{

    TQuickList QL;
    TMDICountReport *CR = NULL;
    SelectComponents(__classid(TMDICountReport),&QL);
    for (int i=0;i<QL.Count;i++)
        if ( ((TMDICountReport*)QL.Items[i])->CB->CountMode == PaymentCount )
            CR = (TMDICountReport*)QL.Items[i];

    if (!CR)
    {
        TakeMode = PaymentCount;
        CR = new TMDICountReport(Application);
    }
    else
        CR->UpdateReport();
    Application->ProcessMessages();
    Application->MainForm->TileMode = tbVertical;
    Application->MainForm->Tile();
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::mWorkCountClick(TObject *Sender)
{
    AnsiString Str;
    if (!World->TechCheck(Str))
    {
        if (!Str.IsEmpty())
            ShowMessage(Str);
        ShowMessage("Проверка на соответствие технологии незавершена.");
        return;
    }

    TQuickList QL;
    TMDICountReport *CR = NULL;
    SelectComponents(__classid(TMDICountReport),&QL);
    for (int i=0;i<QL.Count;i++)
        if ( ((TMDICountReport*)QL.Items[i])->CB->CountMode == WorkCount )
            CR = (TMDICountReport*)QL.Items[i];
    if (!CR)
    {
        TileMode = tbVertical;
        Tile();
        Application->ProcessMessages();
        TakeMode = WorkCount;
        CR = new TMDICountReport(Application);
    }
    else
        CR->UpdateReport();
    TileMode = tbVertical;
    ::SetFocus(CR->SG->Handle);
    Tile();
}
//---------------------------------------------------------------------------

int Mes(char *Text,char* Caption)
{
    if (Caption == NULL)
        Caption = "Information";
    return Application->MessageBox(Text,Caption,MB_OK);
};

void __fastcall TConfig1::PrintDlg1Accept(TObject *Sender)
{
    if (!Config->ActiveMDIChild)        
        return;
    if ( IS(Config->ActiveMDIChild,__classid(TMDI3D)) )
    {
        /*
        Graphics::TBitmap *bmp = new Graphics::TBitmap();
                bmp->HandleType = bmDIB;
        TMDI3D *mdi3d = (TMDI3D*)Config->ActiveMDIChild;
        bmp->Width = mdi3d->View->Width;
        bmp->Height = mdi3d->View->Height;
        mdi3d->View->InvalidateGL();
        Application->ProcessMessages();
        TRect r1 = TRect(0,0,bmp->Width,bmp->Height);
        bmp->Canvas->CopyRect(mdi3d->ClientRect,mdi3d->Canvas,mdi3d->ClientRect);
        TRect Rect;
        double q1 = ((double)Printer()->PageHeight) / ((double)bmp->Height);
        double q2 = ((double)Printer()->PageWidth) / ((double)bmp->Width);
        if (q1<q2)
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q1) )-50, int( (((double)(bmp->Height))*q1) ) -100);
        else
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q2) )-50, int( (((double)(bmp->Height))*q2) ) -100);
        Printer()->BeginDoc();
        Printer()->Canvas->StretchDraw(Rect,bmp);
        Printer()->EndDoc();
        delete bmp;
        */
        Graphics::TBitmap *bmp = new Graphics::TBitmap();
        bmp->HandleType = bmDIB;
        TMDI3D *mdi3d = (TMDI3D*)Config->ActiveMDIChild;
        bmp->Width = 1280;
        bmp->Height = ((double)mdi3d->View->Height) *(((double)1280)/((double)mdi3d->View->Width));
        mdi3d->View->GetImage2(bmp);
        TRect Rect;
        double q1 = ((double)Printer()->PageHeight) / ((double)bmp->Height);
        double q2 = ((double)Printer()->PageWidth) / ((double)bmp->Width);
        if (q1<q2)
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q1) )-100, int( (((double)(bmp->Height))*q1) ) -100);
        else
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q2) )-100, int( (((double)(bmp->Height))*q2) ) -100);
        Printer()->BeginDoc();
        Printer()->Canvas->StretchDraw(Rect,bmp);
        Printer()->EndDoc();
        delete bmp;
    }
    if ( IS(Config->ActiveMDIChild,__classid(TMDICountReport)) )
    {
/*        Graphics::TBitmap *bmp = new Graphics::TBitmap();
        TMDICountReport *mdicr = (TMDICountReport*)Config->ActiveMDIChild;
        
        bmp->Width = mdicr->LV->ClientWidth;
        bmp->Height = mdicr->LV->ClientHeight;
                bmp->HandleType = bmDIB;

        TRect r1 = TRect(0,0,bmp->Width,bmp->Height);
        bmp->Canvas->CopyRect(mdicr->LV->ClientRect,mdicr->LV->Canvas,mdicr->LV->ClientRect);
        TRect Rect;
        double q1 = ((double)Printer()->PageHeight) / ((double)bmp->Height);
        double q2 = ((double)Printer()->PageWidth) / ((double)bmp->Width);
        if (q1<q2)
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q1) )-50, int( (((double)(bmp->Height))*q1) ) -100);
        else
            Rect = TRect(50,50,int( (((double)(bmp->Width))*q2) )-50, int( (((double)(bmp->Height))*q2) ) -100);

        Printer()->Title = AnsiString("Print");
        Printer()->BeginDoc();
        Printer()->Canvas->StretchDraw(Rect,bmp);
        Printer()->EndDoc();
        
        delete bmp;   */
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::PrintDlg1BeforeExecute(TObject *Sender)
{
    PrintDlg1->Dialog->Options.Clear();
}
//---------------------------------------------------------------------------
                                      

void __fastcall TConfig1::ToolButton12MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  MainTimer->Tag = ((TWinControl*)Sender)->Tag;
  MainTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::cbFloorsCloseUp(TObject *Sender)
{
    if (World && cbFloors->ItemIndex != World->ActiveIndex)
        World->SetActiveFloor(cbFloors->ItemIndex);
    if ( ActiveMDIChild && IS(ActiveMDIChild,__classid(TMDI3DUser)) )
        ::SetFocus(ActiveMDIChild->Handle);
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::miModeClick(TObject *Sender)
{
  /* TODO : Переключение режимов не работает */  
  if ( !AUI.ActiveView || !AUI.ActiveWorld)
    return;

  AnsiString GUID = pmModes->Items->Items[tbModes->Tag]->Name;
  GUID.Delete(1,4);
  TMetaMyMode *MN = (TMetaMyMode *)TMetaMyMode::StaticType->RecurrentFindByGUID( GUID );
  if (MN==NULL)
  {
    Application->MessageBox("None aviable modes","Error",MB_OK);
    return;
  }

  if (AUI.ActiveView )
    AUI.ActiveView->Mode = MN;    
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::AppMessage(TMsg& AMessage, bool& Handled)
{
    if (ProgBar && ProgBar->Visible && AMessage.message != WM_PAINT)
    {
        Msgs.Add( new TMsg(AMessage) );
        Handled = true;
        return;
    }
    if ( Screen->Cursor!=crDefault && AMessage.message == WM_MOUSEMOVE)
    {
        if (!AMessage.wParam && MK_MBUTTON )
            Screen->Cursor = crDefault;
    }
    /*if ( IntExplorer && IntExplorer->DragObj && AMessage.message == WM_MOUSEMOVE)
    {
        if (!(AMessage.wParam && MK_LBUTTON) )
        {
            Screen->Cursor = crDefault;
            IntExplorer->DragObj = NULL;
        }
    }*/       
/*    if (AMessage.message == WM_KEYDOWN)
    {
        if ( ActiveMDIChild && IS(ActiveMDIChild,__classid(TMyMDIChild) ))
            ((TMyMDIChild*)ActiveMDIChild)->AppMessage(AMessage,Handled);
    }  */
}

void __fastcall TConfig1::AppActionUpdate(Classes::TBasicAction* Action, bool &Handled)
{
    if (Action == SearchFindNext1)
        if (SearchFind1->Dialog->FindText.IsEmpty())
        {
            ((TCustomAction*)Action)->Enabled = false;
            Handled=true;
        }
    if (!Handled && Action == SearchFindNext1 || Action == SearchFind1 || Action == SearchReplace1)
        if (Screen->ActiveControl && IS (Screen->ActiveControl,__classid(TSciLexer)))
        {
            ((TCustomAction*)Action)->Enabled = true;
            Handled=true;
        }
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    if (!Handled && Action == SearchAllModules)
        if ( ComponentExists(__classid(TMDIConfig)))
        {
            SearchAllModules->Enabled = true;
            Handled=true;
        }
    #endif
    if (Action==Configurator)
    {
        #if !defined(INTERNET_VER) && !defined(TRADE_VER)
        Configurator->Visible = true;
        #else
        Configurator->Visible = false;
        #endif
    }
    if (!Handled &&  IS(Action,__classid(TEditAction)) )
        if (Screen->ActiveControl && IS (Screen->ActiveControl,__classid(TSciLexer)))
        {
            ((TEditAction*)Action)->Enabled = true;
            Handled=true;
        }
    if (!Handled &&  EditRedo1 == Action )
    {
        ((TAction*)Action)->Enabled = ActiveMDIChild && IS (ActiveMDIChild,__classid(TMDI3DUser)) && (UndoStack.CanRedo());
        Handled=true;
    }
    if (!Handled &&  EditUndo1 == Action )
    {
        ((TAction*)Action)->Enabled = ActiveMDIChild && IS (ActiveMDIChild,__classid(TMDI3DUser)) && (UndoStack.CanUndo());
        Handled=true;
    }

    if (World && ::GetFocus() != cbFloors->Handle )
    {
        bool UpdateCombo = false;
        if (cbFloors->Items->Count != World->Floors.Count)
            UpdateCombo = true;
        else if (cbFloors->ItemIndex != World->ActiveIndex)
            UpdateCombo = true;
        else
            for (int i=0;i<cbFloors->Items->Count;i++)
                if (cbFloors->Items->Strings[i] != World->Floors[i].Description )
                {
                    UpdateCombo = true;
                    break;
                }
        if (UpdateCombo)
        {
            cbFloors->Items->Clear();
            for (int i=0;i<World->Floors.Count;i++)
                cbFloors->AddItem(World->Floors[i].Description,NULL);
            cbFloors->ItemIndex = World->ActiveIndex;
        }
    }

    if ( AUI.Mode )
    {
        for ( int i=0;i<pmModes->Items->Count;i++ )
            if ( pmModes->Items->Items[i]->Name == AnsiString("Mode") + AUI.Mode->GUID )
            {
                if (tbModes->Tag!=(i+1) % pmModes->Items->Count)
                {
                    tbModes->Tag = (i+1) % pmModes->Items->Count;
                    tbModes->Caption = pmModes->Items->Items[tbModes->Tag]->Caption;
                    tbModes->ImageIndex = pmModes->Items->Items[tbModes->Tag]->ImageIndex;
                }
                break;
            }
    }

    if (!Handled && ViewLand == Action)
    {
        ViewLand->Enabled = (World!=NULL);
        if (World)
            ViewLand->Checked = World->RenderLand;
        Handled = true;
    }
    if (!Handled && ViewNet == Action)
    {
        ViewNet->Enabled = (World!=NULL);
        if (World)
            ViewNet->Checked = World->RenderNet;
        Handled = true;
    }
    if (World)
        if (ActiveMDIChild && IS(ActiveMDIChild,__classid(TMDI3DUser)))
        {
            ActiveMDIChild->Caption = World->AskedToSave ? World->Name : World->Name + AnsiString(" (Изменен)");
        }

/*    if (!Handled)
    {
        TMTList<TMyRegObject> LST;
        MetaNodeCollection->SelectByCT(NULL,typeid(TMetaAction),&LST,true,true);
        for (int i=0;i<LST.Count;i++)
            ((TMetaAction*)LST.Items[i])->Update();
        LST.Clear();
        MetaNodeCollection->SelectByCT(NULL,typeid(TMetaMenuItem),&LST,true,true);
        for (int i=0;i<LST.Count;i++)
            ((TMetaMenuItem*)LST.Items[i])->Update();
        Handled = true;
    }*/
}

void __fastcall TConfig1::AppActionExecute(Classes::TBasicAction* Action, bool &Handled)
{
    HWND hwnd = GetActiveWindow();
    if (hwnd == SearchFind1->Dialog->Handle)
        return;
    if (hwnd == SearchReplace1->Dialog->Handle)
        return;
    if (!Handled && Config1->ActiveMDIChild && IS(Config1->ActiveMDIChild,__classid(TMDI3DUser)) && Action == EditUndo1)
    {
        UndoStack.Undo();
        Handled = true;
    }
    if (!Handled && Config1->ActiveMDIChild && IS(Config1->ActiveMDIChild,__classid(TMDI3DUser)) && Action == EditRedo1)
    {
        UndoStack.Redo();
        Handled = true;
    }
    if ( IS(Action,__classid(TEditAction) ) )
    {
        TEditAction *EA = (TEditAction *)Action;
        if ( !Handled && Screen->ActiveControl && IS(Screen->ActiveControl,__classid(TEdit)) )
        {
            EA->ExecuteTarget(Screen->ActiveControl);
            Handled = true;
        }
        if (!Handled && Screen->ActiveControl && IS(Screen->ActiveControl,__classid(TSciLexer)))
        {
            TSciLexer * LE = (TSciLexer*)(Screen->ActiveControl);
            if (LE)
            {
                LE->Command(EA->Tag);
                Handled = true;
            }

        }
    }
    if ( !Handled && Screen->ActiveControl && IS (Screen->ActiveControl,__classid(TSciLexer)) )
    {
        if (Action == SearchFindNext1)
        {
            SearchFind1->Dialog->OnFind(SearchFind1->Dialog);
            Handled=true;
        }
        if (Action == SearchFind1)
        {
            SearchFind1->Dialog->Execute();
            Handled=true;
        }
        if (Action == SearchReplace1)
        {
            SearchReplace1->Dialog->Execute();
            Handled=true;
        }
    }
}

int FindLuaText(TSciLexer *mdile,TFindDialog *Dialog)
{
    int flags=0;
    if ( Dialog->Options.Contains(frMatchCase) )
        flags = flags|SCFIND_MATCHCASE;
    if ( Dialog->Options.Contains(frWholeWord) )
        flags = flags|SCFIND_WHOLEWORD;

    int FoundAt = -1;
    if (Dialog->Options.Contains(frDown))
    {
        mdile->SendEditor(SCI_SETSELECTIONSTART,mdile->SendEditor(SCI_GETSELECTIONEND));
        mdile->SendEditor(SCI_SEARCHANCHOR);
        FoundAt = mdile->SendEditor(SCI_SEARCHNEXT,flags,(long)Dialog->FindText.c_str());
    }
    else
    {
        mdile->SendEditor(SCI_SETSELECTIONEND,mdile->SendEditor(SCI_GETSELECTIONSTART)-1);
        mdile->SendEditor(SCI_SEARCHANCHOR);
        FoundAt = mdile->SendEditor(SCI_SEARCHPREV,flags,(long)Dialog->FindText.c_str());
    }
    if (FoundAt != -1)
    {
        ::SetFocus(mdile->Handle);
        mdile->SendEditor(SCI_SCROLLCARET);
        int starty;
        int endy;
        TCommonDialog *dlg;
        starty = mdile->SendEditor(SCI_POINTYFROMPOSITION, FoundAt );
        endy = mdile->SendEditor(SCI_POINTYFROMPOSITION, FoundAt + Dialog->FindText.Length());
        RECT R;
        ::GetClientRect(Dialog->Handle,&R);
        if (starty > Dialog->Top && starty < Dialog->Top + R.bottom)
        {
            if (starty > Screen->Height - endy)
                Dialog->Top = starty-R.bottom-10;
            else
                Dialog->Top = endy+20;
        }
    }
    return FoundAt;
}

void __fastcall TConfig1::SearchFind1FindDialogFind(TObject *Sender)
{
    if ( !Screen->ActiveControl || !IS (Screen->ActiveControl,__classid(TSciLexer)) )
        return;
    TSciLexer *mdile = (TSciLexer *)Screen->ActiveControl;
    if ( Sender != SearchFind1->Dialog && Sender != SearchReplace1->Dialog )
        return;

    AnsiString FindText;

    TFindDialog *Dialog;

    if (Sender == SearchFind1->Dialog)
        Dialog  = SearchFind1->Dialog;
    else if (Sender == SearchReplace1->Dialog)
        Dialog  = SearchReplace1->Dialog;

    int FoundAt = FindLuaText(mdile,Dialog);
    if (FoundAt ==-1)
    {
        Mes("Поиск в модуле завершен.");
        return;
    }
}

void ToggleToolBar(TToolBar *TB, bool Status)
{
    if (TB->Enabled != Status)
        TB->Enabled = Status;
    for (int i=0;i<TB->ButtonCount;i++)
        if (TB->Buttons[i]->Enabled!=Status)
            TB->Buttons[i]->Enabled=Status;
    TB->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TConfig1::AppIdle(TObject *Sender, bool &Done)
{
    lua_setgcthreshold (_LUA_, 0);
    Garbage.Clear();
    
    bool lua = false;
    bool _prj = false;
    bool cam = false;
    if ( ActiveMDIChild)
    {
        #if !defined(INTERNET_VER) && !defined(TRADE_VER)
        if ( IS(ActiveMDIChild,__classid(TSciLexer) ) )
            lua = true;
        if ( ComponentExists(__classid(TMDIConfig)) )
            lua = true;


        else
        #endif
        if ( ComponentExists(__classid(TMDI3DUser))  )
        {
            _prj = true;
            cam = true;
        }
    }

    if (miModule->Visible!=lua)
        miModule->Visible = lua;

    if (miTransformation->Visible!=_prj)
        miTransformation->Visible = _prj;

    if (miView->Visible!=_prj)
        miView->Visible = _prj;

    if (miView->Visible!=TBFloors->Visible)
        TBFloors->Visible = miView->Visible;

    if ( miModule->Visible != tbLua_Edit->Visible)
        tbLua_Edit->Visible = miModule->Visible;

    if (MainToolBar->Enabled!=_prj)
        ToggleToolBar(MainToolBar,_prj);
        
    if (tbMyActions->Enabled != _prj)
        ToggleToolBar(tbMyActions,_prj);

    if (tbCamera->Visible!=cam)
        tbCamera->Visible=cam;

    if (miFloors->Visible!=_prj)
        miFloors->Visible = _prj;
    if (IntExplorer&&IntExplorer->Visible!=_prj)
        IntExplorer->Visible = _prj;
    if (ProgBar && ProgBar->Visible)
    {
        ProgBar->Hide();
        while (Msgs.Count)
        {
            ::SendMessage(Msgs[0].hwnd,Msgs[0].message,Msgs[0].wParam,Msgs[0].lParam);
            Msgs.Delete(0);
        }
    }
    Done = true;
}

void __fastcall TConfig1::SearchReplace1ReplaceDialogReplace(
      TObject *Sender)
{
    if ( !Screen->ActiveControl || !IS (Screen->ActiveControl,__classid(TSciLexer)) )
        return;
    TSciLexer *mdile = (TSciLexer *)Screen->ActiveControl;
    if (Sender!=SearchReplace1->Dialog)
        return;
    int startsel = mdile->SendEditor(SCI_GETSELECTIONSTART);
    int endsel = mdile->SendEditor(SCI_GETSELECTIONEND);
    if (startsel == endsel)
    {
        ShowMessage(AnsiString("Не выделен текст для замены."));
        return;
    }
    if (SearchReplace1->Dialog->Options.Contains(frReplace) || SearchReplace1->Dialog->Options.Contains(frReplaceAll))
    {
        mdile->SendEditor(SCI_REPLACESEL,0,(long)SearchReplace1->Dialog->ReplaceText.c_str());
    }
    if (SearchReplace1->Dialog->Options.Contains(frReplaceAll))
        while (FindLuaText(mdile,SearchReplace1->Dialog)!=-1)
            mdile->SendEditor(SCI_REPLACESEL,0,(long)SearchReplace1->Dialog->ReplaceText.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::MainTimerTimer(TObject *Sender)
{
    if ( ActiveMDIChild && IS(ActiveMDIChild,__classid(TMDI3D)))
    {
        ((TMDI3D *)ActiveMDIChild)->CameraAction(TCameraOperation(abs(MainTimer->Tag)),SIGN(MainTimer->Tag)*7.5);
        return;
    }
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    if ( IS (ActiveMDIChild,__classid(TMDIElement))  )
    {
        ((TMDI3D *)((TMDIElement *)ActiveMDIChild)->TV)->CameraAction(TCameraOperation(abs(MainTimer->Tag)),SIGN(MainTimer->Tag)*7.5);
        return;
    }
    #endif
                     
    for (int i=0;i<MDIChildCount;i++)
        if ( IS (MDIChildren[i],__classid(TMDI3D)) )
        {
            ((TMDI3D *)MDIChildren[i])->CameraAction(TCameraOperation(abs(MainTimer->Tag)),SIGN(MainTimer->Tag)*7.5);
            break;
        }
        else
        #if !defined(INTERNET_VER) && !defined(TRADE_VER)
        if ( IS (MDIChildren[i],__classid(TMDIElement))  )
        {
            ((TMDI3D *)((TMDIElement *)MDIChildren[i])->TV)->CameraAction(TCameraOperation(abs(MainTimer->Tag)),SIGN(MainTimer->Tag)*7.5);
            break;
        }
        #endif
  TPoint P = tbCamera->ScreenToClient(Mouse->CursorPos);
  if (P.x<=0||P.y<=0||P.x>=tbCamera->Width||P.y>=tbCamera->Height)
    ScrollerMouseUp(this,TMouseButton(),TShiftState(),0,0);    

}
//---------------------------------------------------------------------------

void __fastcall TConfig1::FindAllDialogFind(TObject *Sender)
{
    LuaStation.FindInAllModules(FindAllDialog->FindText,FindAllDialog->Options);
    FindAllDialog->CloseDialog();
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::SearchAllModulesExecute(TObject *Sender)
{
    FindAllDialog->Execute();
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::mShowElTreeClick(TObject *Sender)
{
//    MDIFloorControl->Show();
    if (World)
    {
        TileMode = tbVertical;
        Tile();
        new TMDI3DUser(Application,World);
        Tile();
    }
}
//---------------------------------------------------------------------------



TMenuItem* NewMenuItem(const AnsiString& Caption,int ImageIndex,TComponent* Owner,bool RadioItem)
{
    TMenuItem* MI = new TMenuItem(Owner);
    MI->ImageIndex = ImageIndex;
    MI->Caption = Caption;
    if (RadioItem)
    {
        MI->RadioItem = RadioItem;
        MI->AutoCheck = true;
        MI->Checked = false;
    }
    return MI;
}

void __fastcall TConfig1::miFloorsClick(TObject *Sender)
{
    MActualFloor->Clear();
    if (World->Head)
        for (int i=0;i<World->Floors.Count;i++)
        {
            TMenuItem* MI = NewMenuItem(World->Floors[i].Description,-1,MActualFloor,true);
            MActualFloor->Add(MI);
            if (i == World->ActiveIndex)
                MI->Checked = true;
            MI->Tag = i;
            MI->OnClick = MActualFloorClick;
        }
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::N10Click(TObject *Sender)
{
    UndoStack.OpenSession("Добавить этаж сверху");
    World->AddFloor();
    UndoStack.CloseSession();
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::N5Click(TObject *Sender)
{
    if (World->Floors.Count==1)
        return;
    UndoStack.OpenSession("Удалить актуальный этаж");
    World->RemoveFloor(World->ActiveIndex);
    UndoStack.CloseSession();
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::MActualFloorClick(TObject *Sender)
{
    TComponent* WC = (TComponent*)Sender;
    World->SetActiveFloor(WC->Tag);
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::N11Click(TObject *Sender)
{
    (new TMDIVisibleSelectFloor(Application))->ShowModal();
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------



void __fastcall TConfig1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (World && !World->AskedToSave && !Config->Process_Save_Project())
        Action = caNone;
    else
    {
      if (&OldLeftDockWndProc != NULL)
        pnlLeftSide->WindowProc = OldLeftDockWndProc;

      if (&OldRightDockWndProc != NULL)
        pnlRightSide->WindowProc = OldRightDockWndProc;

      if (&OldBottomDockWndProc != NULL)
        pnlBottomSide->WindowProc = OldBottomDockWndProc;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::LuaExecute(TObject *Sender)
{
    TMTList<TMyRegObject> LST;
    MetaNodeCollection->SelectByCT(NULL,TMetaAction::StaticType,&LST,true,true);
    for (int i=0;i<LST.Count;i++)
        if (((TMetaAction*)LST.Items[i])->Action == Sender)
        {
            ((TMetaAction*)LST.Items[i])->Execute();
            return;
        }
    LST.Clear();
    MetaNodeCollection->SelectByCT(NULL,TMetaMenuItem::StaticType,&LST,true,true);
    for (int i=0;i<LST.Count;i++)
        if (((TMetaMenuItem*)LST.Items[i])->MI == Sender)
        {
            ((TMetaMenuItem*)LST.Items[i])->Execute();
            return;
        }
}

void __fastcall TConfig1::ViewNetExecute(TObject *Sender)
{
    if (World)
        World->RenderNet = !World->RenderNet;
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::ViewLandExecute(TObject *Sender)
{
    if (World)
        World->RenderLand = !World->RenderLand;
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::tbCatalogClick(TObject *Sender)
{
//    IntExplorer->Visible = !IntExplorer->Visible;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
float GetRF(int max)
{
    return float(random(max))/float(random(max))+float(random(max));
}

void FillPolygon(TPolygon& P,float Sizex,float Sizey,float sdvigx,float sdvigy)
{
    P.Vertex->Add(new TIntVec( Sizex,    Sizey,    0));
    P.Vertex->Add(new TIntVec( 0,      Sizey,    0));
    P.Vertex->Add(new TIntVec( -Sizex,   Sizey,    0));
    P.Vertex->Add(new TIntVec( -Sizex,   0,      0));
    P.Vertex->Add(new TIntVec( -Sizex,   -Sizey,   0));
    P.Vertex->Add(new TIntVec( 0,    -Sizey,    0));
    P.Vertex->Add(new TIntVec( Sizex,    -Sizey,    0));
    P.Vertex->Add(new TIntVec( Sizex,    0,    0));
    for (int i=0;i<P.Vertex->Count;i++)
    {
        P.Vertex->Items[i]->x = P.Vertex->Items[i]->x+sdvigx;
        P.Vertex->Items[i]->y = P.Vertex->Items[i]->y+sdvigy;
    }
}

void ReFillPolygon(TPolygon& P,TQuickList* Inner)
{
    for(int i=0;i<P.Vertex->Count;i++)
        Inner->Add(P.Vertex->Items[i]);
}

    unsigned short H;
    unsigned short M;
    unsigned short S;
    unsigned short ms;
    TDateTime DT1;
    TDateTime DT2;
    TDateTime DT3;

    THoledPolygon HP;
    TQuickList Outer;
    TQuickList Inners;
    int HC = 60;

//---------------------------------------------------------------------------

void __fastcall TConfig1::AdvTextureExecute(TObject *Sender)
{
    AUI.AdvancedTexturing = !AUI.AdvancedTexturing;
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::AdvTextureUpdate(TObject *Sender)
{
    AdvTexture->Checked = AUI.AdvancedTexturing;
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::mSimpleCountClick(TObject *Sender)
{
    AnsiString Str;
    if (!World->TechCheck(Str))
    {
        if (!Str.IsEmpty())
            ShowMessage(Str);
        ShowMessage("Проверка на соответствие технологии незавершена.");
        return;
    }

    TQuickList QL;
    TMDICountReport *CR = NULL;
    SelectComponents(__classid(TMDICountReport),&QL);
    for (int i=0;i<QL.Count;i++)
        if ( ((TMDICountReport*)QL.Items[i])->CB->CountMode == SimpleCount )
            CR = (TMDICountReport*)QL.Items[i];
    if (!CR)
    {
        TileMode = tbVertical;
        Tile();
        Application->ProcessMessages();
        TakeMode = SimpleCount;
        CR = new TMDICountReport(Application);
    }
    else
        CR->UpdateReport();
    TileMode = tbVertical;
    ::SetFocus(CR->SG->Handle);
    Tile();
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlLeftSideDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
    TRect aRect;
    if ( (((TPanel*)Sender)->Width == 0) || (((TPanel*)Sender)->Height == 0) )
    {
        aRect = Source->DockRect;
        if (Sender == pnlRightSide)
            aRect.Left = Source->DockRect.Left - Source->Control->LRDockWidth;
        else if (Sender == pnlLeftSide)
            aRect.Right = Source->DockRect.Left + Source->Control->LRDockWidth;
        else if (Sender == pnlBottomSide)
            aRect.Top = Source->DockRect.Top - Source->Control->TBDockHeight;
        Source->DockRect = aRect;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlLeftSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
    spltrLeft->Visible = true;
    pnlLeftSide->Left = 0;
    pnlLeftSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlLeftSide);
//    pnlLeftSide->Width = Source->Control->LRDockWidth;
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlRightSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
  spltrRight->Visible = true;
//  pnlRightSide->Width = Source->Control->LRDockWidth;
  pnlRightSide->Left = spltrRight->Left + spltrRight->Width;
  pnlRightSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlRightSide);
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlBottomSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
    spltrBottom->Visible = true;
//    pnlRightSide->Height = Source->Control->TBDockHeight;
    pnlBottomSide->Top = spltrBottom->Top+spltrBottom->Height;
    pnlBottomSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlBottomSide);
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlLeftSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlLeftSide->VisibleDockClientCount == 1)
    {
        spltrLeft->Visible = false;
        pnlLeftSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlRightSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlRightSide->VisibleDockClientCount == 1)
    {
        spltrRight->Visible = false;
        pnlRightSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::pnlBottomSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlBottomSide->VisibleDockClientCount == 1)
    {
        spltrBottom->Visible = false;
        pnlBottomSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TConfig1::LeftDockWindowProc(Messages::TMessage &Message)
{
    OldLeftDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlLeftSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TConfig1::RightDockWindowProc(Messages::TMessage &Message)
{
    OldRightDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlRightSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TConfig1::BottomDockWindowProc(Messages::TMessage &Message)
{
    OldBottomDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlBottomSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TConfig1::ControlVisibilityChanged(TPanel* DockTarget,TControl* Control,bool Visible)
{
    // all removed
    if (DockTarget->VisibleDockClientCount == 0)
    {
        DockTarget->AutoSize = true;
        if (DockTarget == pnlLeftSide)
            spltrLeft->Visible = false;
        else if (DockTarget == pnlRightSide)
            spltrRight->Visible = false;
        else
            spltrBottom->Visible = false;
    }
  // showing the first one
    else if (Visible && (DockTarget->VisibleDockClientCount == 1))
    {
        DockTarget->AutoSize = false;
        if ((DockTarget == pnlLeftSide || DockTarget == pnlRightSide) && (DockTarget->Width == 0) )
            DockTarget->Width = Control->LRDockWidth;
        else if (DockTarget->Height == 0)
            DockTarget->Height = Control->TBDockHeight;
        if (DockTarget == pnlLeftSide)
        {
            spltrLeft->Visible = true;
            pnlLeftSide->Left = 0;
        }else if (DockTarget == pnlRightSide)
        {
            spltrRight->Visible = true;
            pnlRightSide->Left = spltrRight->Left + spltrRight->Width;
        }
        else
        {
            spltrBottom->Visible = true;
            pnlBottomSide->Top = spltrBottom->Top+spltrBottom->Height;
        }
    }
}
void __fastcall TConfig1::pnlBottomSideResize(TObject *Sender)
{
    StatusBar1->Top = pnlBottomSide->Top + pnlBottomSide->Height;
//            pnlBottomSide->Top = spltrBottom->Top+spltrBottom->Height;
//    pnlBottomSide->Top = StatusBar1->Top - StatusBar1->Height - pnlBottomSide->Height;
}
//---------------------------------------------------------------------------

void __fastcall TConfig1::FormShow(TObject *Sender)
{
    if ( IntExplorer )
    {
        IntExplorer->ManualDock(pnlLeftSide);
        pnlLeftSide->AutoSize = true;
        spltrLeft->Visible = false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TConfig1::FileDigitalSaveExecute(TObject *Sender)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    TMDIConfig* mdic = (TMDIConfig*)ComponentExists(__classid(TMDIConfig));
    if (mdic && MetaNodeCollection)
    {
        MetaNodeCollection->Write();
    }
    #endif
}
//---------------------------------------------------------------------------

