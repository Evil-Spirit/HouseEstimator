//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "BaseToolV.h"
#include "math.h"

#pragma package(smart_init)

TClassNode* TUserInterfaceParam::StaticType = NULL;
TClassNode* TBaseBlock::StaticType = NULL;
TClassNode* TGo::StaticType = NULL;
TClassNode* TStateBlock::StaticType = NULL;
TClassNode* TActionBlock::StaticType = NULL;
TClassNode* TConditionalBlock::StaticType = NULL;
TClassNode* TBaseTool::StaticType = NULL;
TClassNode* TMyControls::StaticType = NULL;
//TClassNode* TToolCommand::StaticType = NULL;


TClassNode* LuaModuleClassNode = NULL;


TLuaModule* CreateLuaModule()
{
	/*if (LuaModuleClassNode == NULL)
    {
		if (!GetClassHead())
    		return NULL;
	 	LuaModuleClassNode = GetClassHead()->Find("TLuaModule");
    }
	if (LuaModuleClassNode!=NULL)
    	return (TLuaModule*)LuaModuleClassNode->CreateFunction();*/
    return NULL;
}

bool LuaConditionResult = false;
//---------------------------------------------------------------------------
void RegisterBaseTool()
{
    TStateBlock();
    TActionBlock();
    TConditionalBlock();
    TBaseTool();
}
#pragma startup RegisterBaseTool

const AnsiString aCenter = "Center";
const AnsiString aNewCursorPos = "NewCursorPos";
TUserInterfaceParam::TUserInterfaceParam()
{
    RegisterNewClass< TMyObject, TUserInterfaceParam >(this, false, &CreateFunction);
    Sender = NULL;
    ChangeCenter = NULL;
    ChangeNewCursorPos = NULL;
    RegisterField(&Center, &aCenter, mtIntVec);
    RegisterField(&NewCursorPos, &aNewCursorPos, mtIntVec);
}

TMyObject* TUserInterfaceParam::CreateFunction()
{
    return new TUserInterfaceParam();
}

void TUserInterfaceParam::Changed(void* Field)
{
    if ( Field == &Center )
    {
        if ( ChangeCenter != NULL )
            ChangeCenter();
    }else
        if ( Field == &NewCursorPos )
            if ( ChangeNewCursorPos != NULL )
                ChangeNewCursorPos();
}

/*TIntVec TUserInterfaceParam::GetCenter()
{
    return FCenter;
}

TIntVec TUserInterfaceParam::GetNewCursorPos()
{
    return FNewCursorPos;
}

void TUserInterfaceParam::SetCenter(TIntVec _Center)
{
    FCenter = _Center;
    if ( ChangeCenter != NULL )
    {
        ChangeCenter();
    }
}

void TUserInterfaceParam::SetNewCursorPos(TIntVec _NewCursorPos)
{
    FNewCursorPos = _NewCursorPos;
    if ( ChangeNewCursorPos != NULL )
    {
        ChangeNewCursorPos();
    }
}*/

const AnsiString agFKey = "FKey";
const AnsiString agFMouseButton = "FMouseButton";
const AnsiString agEvent = "Event";
const AnsiString agNextBlockId = "NextBlockId";
TGo::TGo(int _Event, TMouseButton _MouseButton, int _NextBlockId)
{
    RegisterNewClass< TMyObject, TGo >(this, false, &CreateFunction);
    Event = _Event;
    NextBlockId = _NextBlockId;
    MouseButton = _MouseButton;
    Key = 0;
    RegisterField(&FKey, &agFKey, mtInt);
    RegisterField(&FMouseButton, &agFMouseButton, mtInt);
    RegisterField(&Event, &agEvent, mtInt);
    RegisterField(&NextBlockId, &agNextBlockId, mtInt);
}

TGo::TGo()
{
    RegisterNewClass< TMyObject, TGo >(this, false, &CreateFunction);
    Event = Mouse_Down;
    NextBlockId = -1;
    Key = 0;
    MouseButton = mbLeft;
    RegisterField(&FKey, &agFKey, mtInt);
    RegisterField(&FMouseButton, &agFMouseButton, mtInt);
    RegisterField(&Event, &agEvent, mtInt);
    RegisterField(&NextBlockId, &agNextBlockId, mtInt);
}

TGo::TGo(int _Event, const WORD &_Key, int _NextBlockId)
{
    RegisterNewClass< TMyObject, TGo >(this, false, &CreateFunction);
    Event = _Event;
    NextBlockId = _NextBlockId;
    Key = _Key;
    MouseButton = mbLeft;
    RegisterField(&FKey, &agFKey, mtInt);
    RegisterField(&FMouseButton, &agFMouseButton, mtInt);
    RegisterField(&Event, &agEvent, mtInt);
    RegisterField(&NextBlockId, &agNextBlockId, mtInt);
}

/*void TGo::Assign(TMyObject* MO)
{
    if (!MO->Is(TGo::StaticType) )
        throw EMyException("Copying error");

    TMyObject::Assign(MO);

    TGo* G = (TGo*)G;
    Event = G->Event;
    Key = G->Key;
    MouseButton = G->MouseButton;
    NextBlockId = G->NextBlockId;
}*/

TMyObject* TGo::CreateFunction()
{
    return new TGo();
}

void TGo::SetKey(WORD _Key)
{
    FKey = (int)_Key;
}

WORD TGo::GetKey()
{
    return (WORD)FKey;
}

void TGo::SetMB(TMouseButton MB)
{
    FMouseButton = (int)MB;
}

TMouseButton TGo::GetMB()
{
    return (TMouseButton)FMouseButton;
}

const AnsiString aFName = "FName";
const AnsiString abbId = "MyId";
const AnsiString abbGOS = "GOS";
const AnsiString aType = "Type";
const AnsiString aDescription = "Description";


TBaseBlock::TBaseBlock()
{
    RegisterNewClass< TMyObject, TBaseBlock >(this, false, &CreateFunction);

    RegisterField(&FName, &aFName, mtString);
    RegisterField(&Id, &abbId, mtInt);
    RegisterField(&GOS, &abbGOS, mtMyObject);
    RegisterField(&Type, &aType, mtInt);
    RegisterField(&Description, &aDescription, mtString);
}

TBaseBlock::~TBaseBlock()
{
	//delete FLuaModule;
}

void TBaseBlock::SetName(AnsiString _Name)
{
    FName = _Name;
}

TMyObject* TBaseBlock::CreateFunction()
{
    return new TBaseBlock();
}

TMyObject* TStateBlock::CreateFunction()
{
    return new TStateBlock();
}

const AnsiString asbFExexutedEvent = "FExexutedEvent";
TStateBlock::TStateBlock()
{
    RegisterNewClass< TBaseBlock, TStateBlock >(this, false, &CreateFunction);
    Commands = NULL;
    Id = -1;
    Type = btNone;
    Description = "None";
    FExexutedEvent = -1;
    RegisterField(&FExexutedEvent, &asbFExexutedEvent, mtInt);
}

TStateBlock::TStateBlock(TCommands _Commands, int _Id, int _ExexutedEvent, int _Type, AnsiString _Description)
{
    RegisterNewClass< TBaseBlock, TStateBlock >(this, false, &CreateFunction);
    Commands = _Commands;
    Id = _Id;
    Type = _Type;
    Description = _Description;
    FExexutedEvent = _ExexutedEvent;
    RegisterField(&FExexutedEvent, &asbFExexutedEvent, mtInt);
}

TActionBlock::TActionBlock()
{
    RegisterNewClass< TBaseBlock, TActionBlock >(this, false, &CreateFunction);
    Commands = NULL;
    Id = -1;
    Type = btNone;
    Description = "None";
}

TActionBlock::TActionBlock(TCommands Com, int _Id, int _Type, AnsiString _Description)
{
    RegisterNewClass< TBaseBlock, TActionBlock >(this, false, &CreateFunction);
    Commands = Com;
    Id = _Id;
    Type = _Type;
    Description = _Description;
}

TMyObject* TActionBlock::CreateFunction()
{
    return new TActionBlock();
}

TConditionalBlock::TConditionalBlock()
{
    RegisterNewClass< TBaseBlock, TConditionalBlock >(this, false, &CreateFunction);
    Condition = NULL;
    Id = -1;
    Type = btNone;
    Description = "None";
}

TConditionalBlock::TConditionalBlock(TCondition _Condition, int _Id, int _Type, AnsiString _Description)
{
    RegisterNewClass< TBaseBlock, TConditionalBlock >(this, false, &CreateFunction);
    Condition = _Condition;
    Id = _Id;
    Type = _Type;
    Description = _Description;
}

TMyObject* TConditionalBlock::CreateFunction()
{
    return new TConditionalBlock();
}

//const AnsiString abtFExecutedId = "FExecutedId";
const AnsiString abtBlocks = "Blocks";
const AnsiString abtImageId = "ImageId";
TBaseTool::TBaseTool()
{
    RegisterNewClass< TMyObject, TBaseTool >(this, false, &CreateFunction);
    VCO = new TVisPrimitiveObj(NULL);
    SnapCursor = new TVisPrimitiveObj(NULL);
    EscCommands = NULL;
    UIP.Sender = NULL;
    FExecutedId = -2;//&&&
//    RegisterField(&FExecutedId, &abtFExecutedId, mtInt);
    RegisterField(&Blocks, &abtBlocks, mtMyObject);
    RegisterField(&ImageId, &abtImageId, mtInt);
    MenuToolCommands = new TPopupMenu( Application );
}

//------------------------------------Menu--------------------------------------
void TBaseTool::GetToolCommands(TMTList<TGo>* _GOS)
{
    if ( _GOS == NULL )
    {
        int _Index = FindIndexFromId( ExecutedId );
        if ( _Index == -1 )
            throw EMyException("Wrong identifier");
        for ( int i = 0; i < Blocks[_Index].GOS.Count; i++ )
        {
            TMTList<TGo>* BufGOS = new TMTList<TGo>();
            BufGOS->Add( Blocks[_Index].GOS.Items[i] );
            GetToolCommands( BufGOS );
            delete BufGOS;
        }
        return;
    }

    int Index = FindIndexFromId( _GOS->Last()->NextBlockId );
    if ( Index == -1 )
        throw EMyException("Wrong identifier");

    if ( Blocks[Index].Type == btMenu && !Blocks[Index].Is(TConditionalBlock::StaticType) )
    {
        for ( int i = 0; i < ToolCommands.Count; i++ )
            if ( _GOS->Last()->NextBlockId == ToolCommands[i].Last()->NextBlockId )
                return;
        if ( _GOS->Last()->NextBlockId == IdEscAction || _GOS->Last()->NextBlockId == ExecutedId )
            return;
        TMTList<TGo>* BufGOS = new TMTList<TGo>();
        BufGOS->Assign( _GOS );
        ToolCommands.Add( BufGOS );
        ToolCommands.Last()->Description = Blocks[Index].Description;
        return;
    }

    if ( Blocks[Index].GOS.Count == 0 )
        throw EMyException(AnsiString("Block %i has no transitions", Index));

    for ( int i = 0; i < Blocks[Index].GOS.Count; i++ )
    {
        TMTList<TGo>* BufGOS = new TMTList<TGo>();
        BufGOS->Assign( _GOS );
        int j = 0;
        for ( ; j < BufGOS->Count; j++ )
            if ( BufGOS->Items[j] == Blocks[Index].GOS.Items[i] )
                break;
        if ( j ==  BufGOS->Count)
        {
            BufGOS->Add( Blocks[Index].GOS.Items[i] );
            GetToolCommands( BufGOS );
        }
        delete BufGOS;
    }
}

/*void TBaseTool::CommandGoToBlock(int _Id)
{
    FExecutedId = _Id;
    int i = FindIndexFromId( _Id );
    if ( Blocks[i].Is(TActionBlock::StaticType) )
    {
        TActionBlock* AB = (TActionBlock*)Blocks.Items[i];
        AB->Commands();
    }
    else if ( Blocks[i].Is(TConditionalBlock::StaticType) )
    {
        TConditionalBlock* CB = (TConditionalBlock*)Blocks.Items[i];
    }
}*/

/*
    TChangeCursorPos ChangeCenter;
    TChangeCursorPos ChangeNewCursorPos;
    TChangeVec Center;
    TChangeVec NewCursorPos;
    void* Sender;
    WORD Key;
    TShiftState Shift;
    void Changed(void* Field);
*/

void TBaseTool::ExecuteCommand(int _Index)
{
    for ( int i = 0; i < ToolCommands[_Index].Count-1; i++ )
    {
        FExecutedId = ToolCommands[_Index][i].NextBlockId;
        int Ind = FindIndexFromId( FExecutedId );

        UIP.Key = ToolCommands[_Index][i].Key;
        if ( ToolCommands[_Index][i].MouseButton == mbLeft )
            UIP.Shift<<ssLeft;
        else if ( ToolCommands[_Index][i].MouseButton == mbRight )
            UIP.Shift<<ssRight;
        else if ( ToolCommands[_Index][i].MouseButton == mbMiddle )
            UIP.Shift<<ssMiddle;

        if ( Blocks[Ind].Is(TStateBlock::StaticType) )
            ((TStateBlock*)Blocks.Items[Ind])->Commands();
        if ( Blocks[Ind].Is(TActionBlock::StaticType) )
            ((TActionBlock*)Blocks.Items[Ind])->Commands();
        else if ( Blocks[Ind].Is(TConditionalBlock::StaticType) )
            {
                bool Ret = ((TConditionalBlock*)Blocks.Items[Ind])->Condition();
                if ( Blocks[Ind].Type == btMenu )
                    if ( (Ret && Blocks.Items[Ind]->GOS.Items[0] != ToolCommands[_Index].Items[i+1]) ||
                         (!Ret && Blocks.Items[Ind]->GOS.Items[1] != ToolCommands[_Index].Items[i+1]) )
                    {
                        FExecutedId = -1;
                        GoToBlock( FExecutedId );
                        return;
                    }
            }
    }
    FExecutedId = ToolCommands[_Index].Last()->NextBlockId;
    int Ind = FindIndexFromId( FExecutedId );

    UIP.Key = ToolCommands[_Index].Last()->Key;
    if ( ToolCommands[_Index].Last()->MouseButton == mbLeft )
        UIP.Shift<<ssLeft;
    else if ( ToolCommands[_Index].Last()->MouseButton == mbRight )
        UIP.Shift<<ssRight;
    else if ( ToolCommands[_Index].Last()->MouseButton == mbMiddle )
        UIP.Shift<<ssMiddle;

    if ( Blocks[Ind].Is(TActionBlock::StaticType) || Blocks[Ind].Is(TConditionalBlock::StaticType) )
        GoToBlock( FExecutedId );
}

void TBaseTool::FillMenu()
{
    for ( int i = 0; i < ToolCommands.Count; i++ )
    {
        TMenuItem* menu = new TMenuItem( MenuToolCommands );
        menu->Caption = ToolCommands[i].Description;
        menu->Tag = i;
        menu->OnClick = MenuClick;
        MenuToolCommands->Items->Add(menu);
    }
}

void __fastcall TBaseTool::MenuClick(TObject *Sender)
{
    if ( !IS( Sender, __classid(TMenuItem) ) )
        return;
    TMenuItem* menu = (TMenuItem*)Sender;
    if ( menu->Caption != "Break" )
    {
        if ( menu->Tag < 0 || menu->Tag >= ToolCommands.Count )
            throw EMyException("Selected menu item's Tag is not valid");
        ExecuteCommand( menu->Tag );
    }else
    {
        ::SendMessage( Application->MainForm,WM_KEYDOWN,VK_ESCAPE,0);
    }
}
//------------------------------------Menu--------------------------------------

TBaseTool::~TBaseTool()
{
    delete VCO;
    delete SnapCursor;
}

TMyObject* TBaseTool::CreateFunction()
{
    return new TBaseBlock;
}

void TBaseTool::AddStateBlock(TCommands _Commands, int Id, const int _ExecutedEvent, int _Type, AnsiString _Description)
{
    if (_Commands == NULL)
        throw EMyException("Mandatory parameter TCommands missed");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Identifier is not unique");
    Blocks.Add(new TStateBlock(_Commands, Id, _ExecutedEvent, _Type, _Description));
    int n = 0;
    for (int i =0; i<Blocks.Count; i++)
        if (Blocks[i].Is(TStateBlock::StaticType))
            n++;
    if ( n == 1 )
    {
//        IdEscAction = GetUnicId();
        AddActionBlock(ProcessEscapeCommands,IdEscAction, btMenu, "Break");
        Blocks[FindIndexFromId(IdEscAction)].SetName("escaction"+IntToStr(IdEscAction));
        AddGoToBlockId(IdEscAction,Id);
        FExecutedId = Id;
    }
    AddGoToBlockId(Id, IdEscAction, EXIT, mbLeft);
}

void TBaseTool::ProcessEscapeCommands()
{
    if (EscCommands)
        EscCommands();
}

void TBaseTool::AddActionBlock(TCommands _Commands, int Id, int _Type, AnsiString _Description)
{
    if (_Commands == NULL)
        throw EMyException("Mandatory parameter TCommands missed");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Wrong identifier");
    Blocks.Add(new TActionBlock(_Commands, Id, _Type, _Description));
}

void TBaseTool::AddConditionalBlock(TCondition Condition,int Id, int _Type, AnsiString _Description)
{
    if (Condition == NULL)
        throw EMyException("Mandatory parameter TCondition missed");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Wrong identifier");
    Blocks.Add(new TConditionalBlock(Condition, Id, _Type, _Description));
}

void TBaseTool::AddGoToBlockId(int Id, int TrueBlockId, int FalseBlockId)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Identifier not found");
    if (FindIndexFromId(TrueBlockId) == -1)
        throw EMyException("Identifier not found");
    if (FindIndexFromId(FalseBlockId) == -1)
        throw EMyException("Identifier not found");
    if ( Blocks[Index].Is(TStateBlock::StaticType) )
        throw EMyException("Must assign an event");
    if ( Blocks[Index].Is(TActionBlock::StaticType) )
        throw EMyException("Can't assign two transitions");
    if(Blocks[Index].GOS.Count>0)
        throw EMyException("The Block already has transition(s)");
    Blocks[Index].GOS.Add(new TGo(0, mbLeft, TrueBlockId));
    Blocks[Index].GOS.Add(new TGo(0, mbLeft, FalseBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId, const int Event, TMouseButton MouseButton)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Identifier not found");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Identifier not found");
    if ( Blocks[Index].Is(TActionBlock::StaticType) )
        throw EMyException("Must not assign an event");
    if ( Blocks[Index].Is(TConditionalBlock::StaticType) )
        throw EMyException("Must assign two transitions");
    Blocks[Index].GOS.Add(new TGo(Event, MouseButton, NextBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId, const int Event, const WORD &Key)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Identifier not found");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Identifier not found");
    if ( Blocks[Index].Is(TActionBlock::StaticType) )
        throw EMyException("Must not assign an event");
    if ( Blocks[Index].Is(TConditionalBlock::StaticType) )
        throw EMyException("Must assign two transitions");
    Blocks[Index].GOS.Add(new TGo(Event, Key, NextBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Identifier not found");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Identifier not found");
    if ( Blocks[Index].Is(TStateBlock::StaticType) )
        throw EMyException("Must to assign an event");
    if ( Blocks[Index].Is(TConditionalBlock::StaticType) )
        throw EMyException("Need select two transition");
    if(Blocks[Index].GOS.Count>0)
        throw EMyException("Event already has transition(s)");
    Blocks[Index].GOS.Add(new TGo(0, mbLeft, NextBlockId));
}

int TBaseTool::FindIndexFromId(int Id)
{
    for(int i = 0; i < Blocks.Count; i++)
        if (Blocks[i].Id == Id)
            return i;
    return -1;
}

void TBaseTool::GoToBlock(int Id)
{
    _TRY_

            FExecutedId = Id;
            int i = FindIndexFromId(Id);
            if ( Blocks[i].Is(TActionBlock::StaticType) )
            {
                TActionBlock* AB = (TActionBlock*)Blocks.Items[i];
                AB->Commands();
                GoToBlock(Blocks[i].GOS[0].NextBlockId);
            }
            else if ( Blocks[i].Is(TConditionalBlock::StaticType) )
            {
                TConditionalBlock* CB = (TConditionalBlock*)Blocks.Items[i];
                if (CB->Condition())
                    GoToBlock(Blocks[i].GOS[0].NextBlockId);
                else
                    GoToBlock(Blocks[i].GOS[1].NextBlockId);
            }
    _ENDTRY_(AnsiString("<TBaseTool::GoToBlock>: Error in state transition ")+IntToStr(Id),);
}

bool TBaseTool::FindExit(int Event)
{
    for(int i = 0; i<Blocks[FindIndexFromId(ExecutedId)].GOS.Count; i++)
        if (Blocks[FindIndexFromId(ExecutedId)].GOS[i].Event == Event)
        {
            GoToBlock(Blocks[FindIndexFromId(ExecutedId)].GOS[i].NextBlockId);
//            UIP.Sender->View->InvalidateGL();
            return true;
        }
    return false;
}

bool TBaseTool::FindExit(int Event, TMouseButton MouseButton)
{
    for(int i = 0; i<Blocks[FindIndexFromId(ExecutedId)].GOS.Count; i++)
        if (Blocks[FindIndexFromId(ExecutedId)].GOS[i].Event == Event && Blocks[FindIndexFromId(ExecutedId)].GOS[i].MouseButton == MouseButton)
        {
            GoToBlock(Blocks[FindIndexFromId(ExecutedId)].GOS[i].NextBlockId);
//            UIP.Sender->View->InvalidateGL();
            return true;
        }
    return false;
}

bool TBaseTool::FindExit(int Event, WORD &Key)
{
    for(int i = 0; i<Blocks[FindIndexFromId(ExecutedId)].GOS.Count; i++)
        if (Blocks[FindIndexFromId(ExecutedId)].GOS[i].Event == Event && Blocks[FindIndexFromId(ExecutedId)].GOS[i].Key == Key )
        {
            GoToBlock(Blocks[FindIndexFromId(ExecutedId)].GOS[i].NextBlockId);
//            UIP.Sender->View->InvalidateGL();
            return true;
        }
    return false;
}

void TBaseTool::MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition)
{
//    UIP.Center = UIP.NewCursorPos;
    UIP.NewCursorPos = CursorPosition;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Move))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Move)
                ST->Commands();
//            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
//    UIP.Center = UIP.NewCursorPos;
    UIP.NewCursorPos = CursorPosition;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Down, Button))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Down)
                ST->Commands();
//            UIP.Sender->View->InvalidateGL();
        }
    if ( Button == mbRight )
    {
        MenuToolCommands->Items->Clear();
        ToolCommands.Clear();
        if ( ExecutedId != 0 )
        {
            TMenuItem* menu = new TMenuItem(MenuToolCommands);
/*            menu->Caption = "Break";
            menu->OnClick = MenuClick;
            MenuToolCommands->Items->Add(menu);*/
        }
        GetToolCommands(NULL);
        FillMenu();
        MenuToolCommands->Popup(Mouse->CursorPos.x, Mouse->CursorPos.y);
    }
}

void TBaseTool::MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
//    UIP.Center = UIP.NewCursorPos;
    UIP.NewCursorPos = CursorPosition;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Up, Button))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Up)
                ST->Commands();
//            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::KeyDown(void* Sender, WORD &Key, TShiftState Shift)
{
/*    UIP.Center = UIP.NewCursorPos;
    UIP.NewCursorPos = CursorPosition;*/
    UIP.Shift = Shift;
    UIP.Key = Key;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
    {
        if (Key == VK_ESCAPE)
        {
            if(!FindExit(EXIT))
            {
                TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
                if (ST->ExecutedEvent == EXIT)
                    ST->Commands();
//                UIP.Sender->View->InvalidateGL();
            }
        }else
        {
            if(!FindExit(Key_Down,Key))
            {
                TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
                if (ST->ExecutedEvent == Key_Down)
                    ST->Commands();
//                UIP.Sender->View->InvalidateGL();
            }
        }

    }
}

void TBaseTool::KeyUp(void* Sender, WORD &Key, TShiftState Shift)
{
/*    UIP.Center = UIP.NewCursorPos;
    UIP.NewCursorPos = CursorPosition;*/
    UIP.Shift = Shift;
    UIP.Key = Key;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Key_Up,Key))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Key_Up)
                ST->Commands();
//            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::Exit(void* Sender)
{
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        for ( int i = 0; i < Blocks.Count; i++)
            if (Blocks[i].Is(TStateBlock::StaticType))
            {
                FindExit(EXIT);
                break;
            }
    OnExit(Sender);
    UIP.Sender = NULL;
}

void TBaseTool::Render(void* Sender)
{
    UIP.Sender = Sender;
    OnRender();
}

AnsiString TBaseTool::Hint(void* Sender)
{
    UIP.Sender = Sender;
    return OnHint();
}

int TBaseTool::GetUnicId()
{
    if (Blocks.Count > 0)
    {
        int max = Blocks[0].Id;
        for ( int i = 0; i < Blocks.Count; i++ )
            if (Blocks[i].Id > max)
                max = Blocks[i].Id;
        return max+1;
    }else
        return 1;
}

void TBaseTool::SetName(AnsiString _Name)
{
    FName = _Name;
}

const AnsiString amcMatrix = "Matrix";
const AnsiString amcActiveIndices = "ActiveIndices";
const AnsiString amcActiveList = "ActiveList";
TMyControls::TMyControls()
{
    RegisterNewClass< TMyObject, TMyControls >(this, false, &CreateFunction);
    RegisterField(&Matrix, &amcMatrix, mtMyObject);
    RegisterField(&ActiveIndices, &amcActiveIndices, mtMyObject);
    RegisterField(&ActiveList, &amcActiveList, mtInt);
}

TMyObject* TMyControls::CreateFunction()
{
    return new TMyControls();
}

bool TMyControls::IndicesValid()
{
    if ( ActiveList < 0 || ActiveList >= Matrix.Count )
        return false;
    for ( int i = 0; i < ActiveIndices.Count; i++ )
        if ( ActiveIndices[i] < 0 || ActiveIndices[i] >= Matrix[i].Count )
            return false;
    return true;
}

void TMyControls::MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseMove(Sender, Shift, CursorPosition);
}

void TMyControls::MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseDown(Sender, Button, Shift, CursorPosition);
}

void TMyControls::MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseUp(Sender, Button, Shift, CursorPosition);
}

void TMyControls::KeyDown(void* Sender, WORD &Key, TShiftState Shift)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].KeyDown(Sender, Key, Shift);
}

void TMyControls::KeyUp(void* Sender, WORD &Key, TShiftState Shift)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].KeyUp(Sender, Key, Shift);
}

void TMyControls::Exit(void* Sender)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].Exit(Sender);
}

void TMyControls::Render(void* Sender)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    Matrix[ActiveList][ActiveIndices[ActiveList]].Render(Sender);
}

AnsiString TMyControls::Hint(void* Sender)
{
    if ( !IndicesValid() )
        throw EMyException("Active MyControl !IndicesValid()");
    return  Matrix[ActiveList][ActiveIndices[ActiveList]].Hint(Sender);
}
