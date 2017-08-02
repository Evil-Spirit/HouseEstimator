//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
        
#include "UNDO.h"
#include "World.h"
#include "ElementV.h"
#include "TasksQueueV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TUndoStack UndoStack;

TStateStep::TStateStep()
{
    RegisterMode = rmChanged;
    Object = NULL;
}

TStateStep::~TStateStep()
{
}


TUndoSession::TUndoSession()
{
    MS = new TMemoryStream();
    FClosed = true;
}

TUndoSession::~TUndoSession()
{
    delete MS;
}

void TUndoSession::Open(const AnsiString& vName)
{
    Name = vName;
    MS->Clear();
    World->TMyObject::WriteData( MS );
    FClosed = false;
}

void TUndoSession::Close()
{
    for (bool OK = SSL.Start();OK;OK = SSL.Next() )
        if (SSL.Current->Object)
            SSL.Current->Object->UndoRegistered = false;
    FClosed = true;
}

void TUndoSession::RegisterChanges(TUnit* EL)
{
    SSL.Add( new TStateStep() );
    SSL.Last()->Position = MS->Position;
    SSL.Last()->RegisterMode = rmChanged;
    SSL.Last()->Object = EL;
    TMDelTList<TUnit> LST;
    if (EL)
    {
        SSL.Last()->GUID = EL->GUID;
        LST.Add(EL);
    }
    LST.WriteData(MS);
    LST.NoDelClear();
}

void TUndoSession::RegisterCreation(TUnit* MRO)
{
    RegisterChanges(NULL);
    SSL.Last()->Object = MRO;
    SSL.Last()->GUID = MRO->GUID;
    SSL.Last()->RegisterMode = rmCreated;
}

void TUndoSession::RegisterDeletion(TUnit* MRO)
{
    for (bool OK = SSL.End();OK;OK = SSL.Prev() )
        if (MRO == SSL.Current->Object)
        {
            SSL.Current->Object = NULL;
            SSL.Current->RegisterMode = rmDeleted;
            return;
        }
    RegisterChanges(MRO);
    SSL.Last()->Object = NULL;
    SSL.Last()->RegisterMode = rmDeleted;
}


//строгое требование:
//невозможна регистрация дважды
//исключение повторная регистрация о удалении 
void TUndoSession::ReadCondition()
{
    MS->Position = 0;
    World->TMyObject::ReadData( MS );
    TMDelTList<TUnit> LST;
    for (bool OK = SSL.Start();OK;OK = SSL.Next() )
    {
        TUnit* Sender = (TUnit*)TUnit::StaticType->RecurrentFindByGUID(SSL.Current->GUID);
        if (Sender)
            delete Sender;
    }
    //---------------------
    //Важно т.к. адреса совпадают
    TaskQueue.Clear();
    //---------------------
    for (bool OK = SSL.Start();OK;OK = SSL.Next() )
    {
        MS->Position = SSL.Current->Position;
        LST.ReadData(MS);
        for (bool OK1 = LST.Start();OK1;OK1 = LST.Next() )
            if ( LST.Current->Is(TElement::StaticType) )
            {
                World->ELS.Add((TElement*)LST.Current);
                World->ELS.Last()->MyTree = World;
            }
            else
                World->LLS.Add((TLink*)LST.Current);
        LST.NoDelClear();
    }
    World->load = true;
    World->CheckFields();
    World->Init();
    World->ELS.NoDelClear();
    World->LLS.NoDelClear();
    World->load = false;
    World->ReFillElements();
}

void TMyStack::Clear()
{
    Sessions.Clear();
}

void TMyStack::MoveLastSessionTo(TMyStack& OtherStack)
{
    TMDelTList<TStateStep>& SSL = Sessions.Last()->SSL;
    //---------------------------------------------------
    TUndoSession& NewSession = *(new TUndoSession());
    NewSession.Open(Sessions.Last()->Name);
    //---------------------------------------------------
    for (bool OK = SSL.Start();OK;OK = SSL.Next() )
        if ( SSL.Current->RegisterMode == rmChanged )
        {
            //rmChanges
            TUnit* Obj = (TUnit*)TUnit::StaticType->RecurrentFindByGUID(SSL.Current->GUID);
            NewSession.RegisterChanges( Obj);
        }
        else if ( SSL.Current->RegisterMode == rmDeleted )
        {
            //rmDeleted
            NewSession.RegisterChanges( NULL );
            NewSession.SSL.Last()->GUID = SSL.Current->GUID;
            NewSession.SSL.Last()->RegisterMode = rmCreated;
        }
        else
        {
            //rmCreated      ]
            TUnit* Obj = (TUnit*)TUnit::StaticType->RecurrentFindByGUID(SSL.Current->GUID);
            NewSession.RegisterChanges( Obj );
            NewSession.RegisterDeletion( Obj );
        }
    NewSession.Close();
    OtherStack.Sessions.Add( &NewSession );
}


void TUndoStack::OpenSession(const AnsiString& SessionName)
{
	//**/
	return;
	//**/
	if (Sessions.Count && !Sessions.Last()->Closed)
    {
        WarningMsg("<TUndoStack::OpenSession>: Changes stack session is already opened");
        return;
    }
    RedoStack.Clear();
    Sessions.Add( new TUndoSession() );
    Sessions.Last()->Open(SessionName);
}

void TUndoStack::OpenSessionC(char* _Name)
{
    OpenSession(AnsiString(_Name));
}

void TUndoStack::CloseSession()
{
	//**/
	return;
	//**/
	if (Sessions.Count && Sessions.Last()->Closed)
    {
        WarningMsg("<TUndoStack::CloseSession>: Changes stack session is already closed");
        return;
    }
    if (Sessions.Count)
    {
        Sessions.Last()->Close();
    }
}

void TUndoStack::BreakSession()
{
	//**/
	return;
	//**/
	if (Sessions.Count && Sessions.Last()->Closed)
    {
        WarningMsg("<TUndoStack::BreakSession>: Changes stack session is already closed");
        return;
    }
    if (Sessions.Count)
    {
        Sessions.Delete(Sessions.Count-1);
    }
}

bool TUndoStack::Register(TUnit* Sender,TRegisterMode RM)
{
	//**/
	return false;
	//**/
	if (!Sessions.Count || Sessions.Last()->Closed )
        return false;
    switch(RM)
    {
        case rmCreated  :
            Sessions.Last()->RegisterCreation(Sender);
        break;
        case rmDeleted  :
            Sessions.Last()->RegisterDeletion(Sender);
        break;
        case rmChanged  :
            Sessions.Last()->RegisterChanges(Sender);
        break;
    };
    return true;
}

void TUndoStack::ReadCondition()
{
    if (Sessions.Count )
        Sessions.Last()->ReadCondition();
}


void TUndoStack::Clear()
{
    TMyStack::Clear();
    Sessions.Clear();
}


void TUndoStack::Direct_Undo()
{
    if (Sessions.Count==0)
        return;
    //save
    MoveLastSessionTo(RedoStack);
    //read
    ReadCondition();
    Sessions.Delete(Sessions.Count-1);
}

void TUndoStack::Direct_Redo()
{
    if (RedoStack.Sessions.Count==0)
        return;
    //save
    RedoStack.MoveLastSessionTo(*this);
    //read
    RedoStack.Sessions.Last()->ReadCondition();
    RedoStack.Sessions.Delete(RedoStack.Sessions.Count-1);
}

void TUndoStack::Undo()
{
    _TRY_
        Direct_Undo();
    _ENDTRY_("<TUndoStack::Undo>: Could not undo",);
}

void TUndoStack::Redo()
{
    _TRY_
        Direct_Redo();
    _ENDTRY_("<TUndoStack::Redo>: Could not redo",);
}

bool TUndoStack::CanUndo()
{
    return Sessions.Count>0 && Sessions.Last()->Closed;
}

bool TUndoStack::CanRedo()
{
    return RedoStack.Sessions.Count>0 && RedoStack.Sessions.Last()->Closed;
}

bool TUndoStack::Opened()
{
    return Sessions.Count>0 && !Sessions.Last()->Closed;
}

