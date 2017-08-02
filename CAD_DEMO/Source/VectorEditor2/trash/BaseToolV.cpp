//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "BaseToolV.h"
#include "EditorV.h"

//---------------------------------------------------------------------------
TGo::TGo(int _Event, TMouseButton _MouseButton, int _NextBlockId)
{
    RegisterNewClass< TMyObject, TGo >(this, false, &CreateFunction);
    Event = _Event;
    NextBlockId = _NextBlockId;
    MouseButton = _MouseButton;
}
TGo::TGo(int _Event, const WORD &_Key, int _NextBlockId)
{
    RegisterNewClass< TMyObject, TGo >(this, false, &CreateFunction);
    Event = _Event;
    NextBlockId = _NextBlockId;
    Key = _Key;
}

TMyObject* TGo::CreateFunction()
{
    return new TGo();
}

TBaseBlock::TBaseBlock()
{
    RegisterNewClass< TMyObject, TBaseBlock >(this, false, &CreateFunction);
}

TMyObject* TBaseBlock::CreateFunction()
{
    return new TBaseBlock();
}

TMyObject* TStateBlock::CreateFunction()
{
    return new TStateBlock();
}

TStateBlock::TStateBlock(TCommands _Commands, int _Id, int _ExexutedEvent)
{
    RegisterNewClass< TBaseBlock, TStateBlock >(this, false, &CreateFunction);
    Commands = _Commands;
    Id = _Id;
    FExexutedEvent = _ExexutedEvent;
}

TActionBlock::TActionBlock(TCommands Com, int _Id)
{
    RegisterNewClass< TBaseBlock, TActionBlock >(this, false, &CreateFunction);
    Commands = Com;
    Id = _Id;
}

TMyObject* TActionBlock::CreateFunction()
{
    return new TActionBlock();
}

TConditionalBlock::TConditionalBlock(TCondition _Condition, int _Id)
{
    RegisterNewClass< TBaseBlock, TConditionalBlock >(this, false, &CreateFunction);
    Condition = _Condition;
    Id = _Id;
}

TMyObject* TConditionalBlock::CreateFunction()
{
    return new TConditionalBlock();
}

TBaseTool::TBaseTool()
{
    RegisterNewClass< TMyObject, TBaseTool >(this, false, &CreateFunction);
    VCO = new TVisPrimitiveObj(NULL);
    SnapCursor = new TVisPrimitiveObj(NULL);
    EscCommands = NULL;
    UIP.Sender = NULL;
    FExecutedId = -2;//&&&
}

TBaseTool::~TBaseTool()
{
    delete VCO;
    delete SnapCursor;
}

TMyObject* TBaseTool::CreateFunction()
{
    return new TBaseBlock;
}

void TBaseTool::AddStateBlock(TCommands _Commands, int Id, const int _ExecutedEvent)
{
    if (_Commands == NULL)
        throw EMyException("Mandatory parameter TCommands is missing");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Incorrect identifier");
    Blocks.Add(new TStateBlock(_Commands, Id, _ExecutedEvent));
    int n = 0;
    for (int i =0; i<Blocks.Count; i++)
      if (typeid(Blocks[i]) == typeid(TStateBlock)) n++;
    if (n==1)
    {
        AddActionBlock(ProcessEscapeCommands,IdEscAction);
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

void TBaseTool::AddActionBlock(TCommands _Commands,int Id)
{
    if (_Commands == NULL)
        throw EMyException("ÏMandatory parameter TCommands is missing");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Incorrect identifier");
    Blocks.Add(new TActionBlock(_Commands, Id));
}

void TBaseTool::AddConditionalBlock(TCondition Condition,int Id)
{
    if (Condition == NULL)
        throw EMyException("Mandatory parameter TCommands is missing");
    if (FindIndexFromId(Id) != -1)
        throw EMyException("Incorrect identifier");
    Blocks.Add(new TConditionalBlock(Condition, Id));
}

void TBaseTool::AddGoToBlockId(int Id, int TrueBlockId, int FalseBlockId)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Could not find identifier");
    if (FindIndexFromId(TrueBlockId) == -1)
        throw EMyException("Could not find identifier");
    if (FindIndexFromId(FalseBlockId) == -1)
        throw EMyException("Could not find identifier");
    if ( typeid(Blocks[Index]) == typeid(TStateBlock) )
        throw EMyException("Event must be assigned");
    if ( typeid(Blocks[Index]) == typeid(TActionBlock) )
        throw EMyException("Must have two transitions");
    if(Blocks[Index].GOS.Count>0)
        throw EMyException("The block already has transition(s)");
    Blocks[Index].GOS.Add(new TGo(0, mbLeft, TrueBlockId));
    Blocks[Index].GOS.Add(new TGo(0, mbLeft, FalseBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId, const int Event, TMouseButton MouseButton)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Could not find identifier");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Could not find identifier");
    if ( typeid(Blocks[Index]) == typeid(TActionBlock) )
        throw EMyException("Selected event is not needed");
    if ( typeid(Blocks[Index]) == typeid(TConditionalBlock) )
        throw EMyException("Must have two transitions");
    Blocks[Index].GOS.Add(new TGo(Event, MouseButton, NextBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId, const int Event, const WORD &Key)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Can not find identifier");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Can not find identifier");
    if ( typeid(Blocks[Index]) == typeid(TActionBlock) )
        throw EMyException("Selected event is not needed");
    if ( typeid(Blocks[Index]) == typeid(TConditionalBlock) )
        throw EMyException("Need select two transition");
    Blocks[Index].GOS.Add(new TGo(Event, Key, NextBlockId));
}

void TBaseTool::AddGoToBlockId(int Id, int NextBlockId)
{
    int Index = FindIndexFromId(Id);
    if (Index == -1)
        throw EMyException("Could not find identifier");
    if (FindIndexFromId(NextBlockId) == -1)
        throw EMyException("Could not find identifier");
    if ( typeid(Blocks[Index]) == typeid(TStateBlock) )
        throw EMyException("Event must be assigned");
    if ( typeid(Blocks[Index]) == typeid(TConditionalBlock) )
        throw EMyException("Must have two transitions");
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
    try
    {
        try
        {
            int i = FindIndexFromId(Id);
            if ( typeid(Blocks[i]) == typeid(TStateBlock) )
                FExecutedId = Id;
            else if ( typeid(Blocks[i]) == typeid(TActionBlock) )
            {
                TActionBlock* AB = (TActionBlock*)Blocks.Items[i];
                AB->Commands();
                GoToBlock(Blocks[i].GOS[0].NextBlockId);
            }
            else
            {
                TConditionalBlock* CB = (TConditionalBlock*)Blocks.Items[i];
                if (CB->Condition())
                    GoToBlock(Blocks[i].GOS[0].NextBlockId);
                else
                    GoToBlock(Blocks[i].GOS[1].NextBlockId);
            }
        }
        __except(EXCEPTION_EXECUTE_HANDLER)
        {
            throw EMyException("System exception");
        }
    }
    catch(EMyException)
    {
        AnsiString Str = "Error in state transition ";
        Str += IntToStr(Id);
        ErrorMsg(Str);
    }
}

bool TBaseTool::FindExit(int Event)
{
    for(int i = 0; i<Blocks[FindIndexFromId(ExecutedId)].GOS.Count; i++)
        if (Blocks[FindIndexFromId(ExecutedId)].GOS[i].Event == Event)
        {
            GoToBlock(Blocks[FindIndexFromId(ExecutedId)].GOS[i].NextBlockId);
            UIP.Sender->View->InvalidateGL();
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
            UIP.Sender->View->InvalidateGL();
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
            UIP.Sender->View->InvalidateGL();
            return true;
        }
    return false;
}

void TBaseTool::MouseMove(TEditor2D* Sender, TShiftState Shift)
{
    UIP.OldCursorPos = UIP.NewCursorPos;
    UIP.NewCursorPos = Sender->MyCursor.Position;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Move))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Move)
                ST->Commands();
            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::MouseDown(TEditor2D* Sender, TMouseButton Button, TShiftState Shift)
{
    UIP.OldCursorPos = UIP.NewCursorPos;
    UIP.NewCursorPos = Sender->MyCursor.Position;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Down, Button))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Down)
                ST->Commands();
            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::MouseUp(TEditor2D* Sender, TMouseButton Button, TShiftState Shift)
{
    UIP.OldCursorPos = UIP.NewCursorPos;
    UIP.NewCursorPos = Sender->MyCursor.Position;
    UIP.Shift = Shift;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Mouse_Up, Button))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Mouse_Up)
                ST->Commands();
            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::KeyDown(TEditor2D* Sender, WORD &Key, TShiftState Shift)
{
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
                UIP.Sender->View->InvalidateGL();
            }
        }else
        {
            if(!FindExit(Key_Down,Key))
            {
                TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
                if (ST->ExecutedEvent == Key_Down)
                    ST->Commands();
                UIP.Sender->View->InvalidateGL();
            }
        }

    }
}

void TBaseTool::KeyUp(TEditor2D* Sender, WORD &Key, TShiftState Shift)
{
    UIP.Shift = Shift;
    UIP.Key = Key;
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
        if(!FindExit(Key_Up,Key))
        {
            TStateBlock* ST = (TStateBlock*)Blocks.Items[FindIndexFromId(ExecutedId)];
            if (ST->ExecutedEvent == Key_Up)
                ST->Commands();
            UIP.Sender->View->InvalidateGL();
        }
}

void TBaseTool::Exit(TEditor2D* Sender)
{
    UIP.Sender = Sender;
    if (Blocks.Count > 0)
    {
        bool b = false;
        for ( int i = 0; i < Blocks.Count && !b; i++)
            if (typeid(Blocks[i]) == typeid(TStateBlock))
                b = true;
        if (b)
            FindExit(EXIT);
    }
    OnExit(Sender);
}

void TBaseTool::Render(TEditor2D* Sender)
{
    UIP.Sender = Sender;
    OnRender();
}

AnsiString TBaseTool::Hint(TEditor2D* Sender)
{
    UIP.Sender = Sender;
    return OnHint();
}

TMyControls::TMyControls()
{
    RegisterNewClass< TMyObject, TMyControls >(this, false, &CreateFunction);
}

TMyObject* TMyControls::CreateFunction()
{
    return new TMyControls();
}

void TMyControls::MouseMove(TEditor2D* Sender, TShiftState Shift)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseMove(Sender, Shift);
}

void TMyControls::MouseDown(TEditor2D* Sender, TMouseButton Button, TShiftState Shift)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseDown(Sender, Button, Shift);
}

void TMyControls::MouseUp(TEditor2D* Sender, TMouseButton Button, TShiftState Shift)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].MouseUp(Sender, Button, Shift);
}

void TMyControls::KeyDown(TEditor2D* Sender, WORD &Key, TShiftState Shift)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].KeyDown(Sender, Key, Shift);
}

void TMyControls::KeyUp(TEditor2D* Sender, WORD &Key, TShiftState Shift)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].KeyUp(Sender, Key, Shift);
}

void TMyControls::Exit(TEditor2D* Sender)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].Exit(Sender);
}

void TMyControls::Render(TEditor2D* Sender)
{
    Matrix[ActiveList][ActiveIndices[ActiveList]].Render(Sender);
}

AnsiString TMyControls::Hint(TEditor2D* Sender)
{
    return  Matrix[ActiveList][ActiveIndices[ActiveList]].Hint(Sender);
}
#pragma package(smart_init)
