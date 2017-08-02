//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
        
#include "UNDO.h"
#include "CellGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TGridUndoStack UndoStack;

TGridStateStep::TGridStateStep()
{
    RegisterMode = rmChanged;
    Object = NULL;
}

TGridStateStep::~TGridStateStep()
{
}


TGridUndoSession::TGridUndoSession(TCellGrid* aCG)
{
    CG = aCG;
    MS = new TMemoryStream();
    FClosed = true;
}

TGridUndoSession::TGridUndoSession()
{
    CG = NULL;
    MS = new TMemoryStream();
    FClosed = true;
}

TGridUndoSession::~TGridUndoSession()
{
    delete MS;
}

void TGridUndoSession::Open(const AnsiString& vName)
{
    Name = vName;
    MS->Clear();
    FClosed = false;
}

void TGridUndoSession::Close()
{
    for (bool OK = SSL.Start(); OK; OK = SSL.Next() )
        if (SSL.Current->Object)
            SSL.Current->Object->UndoRegistered = false;
    FClosed = true;
}

void TGridUndoSession::RegisterChanges(const TPoint ColRow, TCell* EL)
{
    SSL.Add( new TGridStateStep() );
    TMDelTList<TCell> LST;
    SSL.Last()->Position     =MS->Position;
    SSL.Last()->RegisterMode =rmChanged;
    SSL.Last()->Object       =EL;
    if (EL)
    {
        SSL.Last()->ColRow =ColRow;
        LST.Add(EL);
    }
    LST.WriteData(MS);
    LST.NoDelClear();
}

void TGridUndoSession::RegisterCreation(const TPoint ColRow, TCell* MRO)
{
    RegisterChanges(ColRow,NULL);
    SSL.Last()->Object          =MRO;
    SSL.Last()->ColRow          =ColRow;
    SSL.Last()->RegisterMode    =rmCreated;
}

void TGridUndoSession::RegisterDeletion(const TPoint ColRow, TCell* MRO)
{
    for (bool OK = SSL.End();OK;OK = SSL.Prev() )
        if (MRO == SSL.Current->Object)
        {
            SSL.Current->Object = NULL;
            SSL.Current->RegisterMode = rmDeleted;
            return;
        }
    RegisterChanges(ColRow,MRO);
    SSL.Last()->Object = NULL;
    SSL.Last()->RegisterMode = rmDeleted;
}


//строгое требование:
//невозможна регистрация дважды
//исключение повторная регистрация о удалении
void TGridUndoSession::ReadCondition()
{
    MS->Position = 0;
    TMDelTList<TCell> LST;
    for (bool OK = SSL.Start(); OK; OK = SSL.Next() )
    {
        TCell* Sender = CG->GetCellSimple( SSL.Current->ColRow.x,SSL.Current->ColRow.y );
        if (Sender)
            CG->DelCell(SSL.Current->ColRow.x,SSL.Current->ColRow.y);
    }
    //---------------------
    //Важно т.к. адреса совпадают
//    TaskQueue.Clear();
    //---------------------
    /*
    for (bool OK = SSL.Start();OK;OK = SSL.Next() )
    {
        MS->Position = SSL.Current->Position;
        LST.ReadData(MS);

        for (bool OK1 = LST.Start();OK1;OK1 = LST.Next() )
            if ( LST.Current->Is(TCell::StaticType) )
            {
  //              World->ELS.Add((TElement*)LST.Current);
//                World->ELS.Last()->MyTree = World;
            }
            else
            {
//                World->LLS.Add((TLink*)LST.Current);
            }

        LST.NoDelClear();
    }
    */
}

void TGridStack::Clear()
{
    Sessions.Clear();
}

void TGridStack::MoveLastSessionTo(TGridStack& OtherStack)
{
    TMDelTList<TGridStateStep>& SSL = Sessions.Last()->SSL;
    //---------------------------------------------------
    TGridUndoSession& NewSession = *(new TGridUndoSession());
    NewSession.Open(Sessions.Last()->Name);
    //---------------------------------------------------
    for (bool OK = SSL.Start(); OK; OK = SSL.Next() )
        if ( SSL.Current->RegisterMode == rmChanged )
        {
            //rmChanges
            TCell* Obj = CG->GetCellSimple( SSL.Current->ColRow.x,SSL.Current->ColRow.y );
            NewSession.RegisterChanges(SSL.Current->ColRow, Obj);
        }
        else if ( SSL.Current->RegisterMode == rmDeleted )
        {
            //rmDeleted
            NewSession.RegisterChanges(SSL.Current->ColRow, NULL );
            NewSession.SSL.Last()->ColRow = SSL.Current->ColRow;
            NewSession.SSL.Last()->RegisterMode = rmCreated;
        }
        else
        {
            //rmCreated
            TCell* Obj = CG->GetCellSimple( SSL.Current->ColRow.x,SSL.Current->ColRow.y );
            NewSession.RegisterChanges( SSL.Current->ColRow,Obj );
            NewSession.RegisterDeletion(SSL.Current->ColRow, Obj );
        }
    NewSession.Close();
    OtherStack.Sessions.Add( &NewSession );
}


void TGridUndoStack::OpenSession(const AnsiString& SessionName)
{
    if (Sessions.Count && !Sessions.Last()->Closed)
    {
        WarningMsg("<TGridUndoStack::OpenSession>: Сессия стека изменений уже открыта");
        return;
    }
    RedoStack.Clear();
    Sessions.Add( new TGridUndoSession() );
    Sessions.Last()->Open(SessionName);
}

void TGridUndoStack::OpenSessionC(char* _Name)
{
    OpenSession(AnsiString(_Name));
}

void TGridUndoStack::CloseSession()
{
    if (Sessions.Count && Sessions.Last()->Closed)
    {
        WarningMsg("<TGridUndoStack::CloseSession>: Сессия стека изменений уже закрыта");
        return;
    }
    if (Sessions.Count)
        Sessions.Last()->Close();
}

void TGridUndoStack::BreakSession()
{
    if (Sessions.Count && Sessions.Last()->Closed)
    {
        WarningMsg("<TGridUndoStack::BreakSession>: Сессия стека изменений уже закрыта");
        return;
    }
    if (Sessions.Count)
        Sessions.Delete(Sessions.Count-1);
}

bool TGridUndoStack::Register(int Col,int Row,TCell* Sender,TGridRegisterMode RM)
{
    if (!Sessions.Count || Sessions.Last()->Closed )
        return false;
    switch(RM)
    {
        case rmCreated  :
            Sessions.Last()->RegisterCreation(TPoint(Col,Row), Sender);
        break;
        case rmDeleted  :
            Sessions.Last()->RegisterDeletion(TPoint(Col,Row), Sender);
        break;
        case rmChanged  :
            Sessions.Last()->RegisterChanges(TPoint(Col,Row), Sender);
        break;
    };
    return true;
}

void TGridUndoStack::ReadCondition()
{
    if (Sessions.Count )
        Sessions.Last()->ReadCondition();
}


void TGridUndoStack::Clear()
{
    TGridStack::Clear();
    Sessions.Clear();
}


void TGridUndoStack::Direct_Undo()
{
    if (Sessions.Count==0)
        return;
    //save
    MoveLastSessionTo(RedoStack);
    //read
    ReadCondition();
    Sessions.Delete(Sessions.Count-1);
}

void TGridUndoStack::Direct_Redo()
{
    if (RedoStack.Sessions.Count==0)
        return;
    //save
    RedoStack.MoveLastSessionTo(*this);
    //read
    RedoStack.Sessions.Last()->ReadCondition();
    RedoStack.Sessions.Delete(RedoStack.Sessions.Count-1);
}

void TGridUndoStack::Undo()
{
    _TRY_
        Direct_Undo();
    _ENDTRY_("<TGridUndoStack::Undo>: Отмена не выполнена",);
}

void TGridUndoStack::Redo()
{
    _TRY_
        Direct_Redo();
    _ENDTRY_("<TGridUndoStack::Redo>: Возврат отмены не выполнен",);
}

bool TGridUndoStack::CanUndo()
{
    return Sessions.Count>0 && Sessions.Last()->Closed;
}

bool TGridUndoStack::CanRedo()
{
    return RedoStack.Sessions.Count>0 && RedoStack.Sessions.Last()->Closed;
}

bool TGridUndoStack::Opened()
{
    return Sessions.Count>0 && !Sessions.Last()->Closed;
}

