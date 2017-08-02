//---------------------------------------------------------------------------

#ifndef UNDOH
#define UNDOH

//---------------------------------------------------------------------------
//tundostep

class TUnit;

enum TRegisterMode  {rmChanged,rmDeleted,rmCreated};

class COMMONAL_API TStateStep
{
  public:
  TStateStep();
  virtual ~TStateStep();
  TUnit* Object;
  TRegisterMode RegisterMode;
  AnsiString GUID;
  __int64 Position;
  AnsiString ClassName;
};

class COMMONAL_API TUndoSession {
    TMemoryStream *MS;
    bool FClosed;
public:
    AnsiString Name;
    TMDelTList<TStateStep> SSL;
    TUndoSession();
    virtual ~TUndoSession();
    void Open(const AnsiString& aName);
    void Close();
    __property bool Closed = {read = FClosed};
    void RegisterChanges(TUnit* MRO);
    void RegisterCreation(TUnit* MRO);
    void RegisterDeletion(TUnit* MRO);
    void ReadCondition();
};

class TUndoStack;

class COMMONAL_API TMyStack {
friend class TUndoStack;
protected:
    TMDelTList<TUndoSession> Sessions;
public:
    TMyStack(){};
    ~TMyStack(){};
    virtual void Clear();
    void MoveLastSessionTo(TMyStack& OtherStack);
};

class COMMONAL_API TUndoStack : public TMyStack{
    void Direct_Undo();
    void Direct_Redo();
    TMyStack RedoStack;
public:
    TUndoStack(){};
    virtual ~TUndoStack(){};
    void OpenSession(const AnsiString& SessionName);
    void OpenSessionC(char* _Name);
    void CloseSession();
    void BreakSession();
    void ReadCondition();
    bool Register(TUnit* Sender,TRegisterMode RM);
    void Undo();
    void Redo();
    virtual void Clear();
    bool CanUndo();
    bool CanRedo();
    bool Opened();
};

extern COMMONAL_API TUndoStack UndoStack;

#endif
