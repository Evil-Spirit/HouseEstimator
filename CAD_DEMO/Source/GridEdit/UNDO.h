//---------------------------------------------------------------------------

#ifndef UNDOH
#define UNDOH

//---------------------------------------------------------------------------
//tundostep
class TCell;
class TCellGrid;
enum TGridRegisterMode  {rmChanged,rmDeleted,rmCreated};
class COMMONAL_API TGridStateStep
{
  public:
  TGridStateStep();
  virtual ~TGridStateStep();
  TCell* Object;
  TGridRegisterMode RegisterMode;
  AnsiString GUID;
  TPoint ColRow;
  __int64 Position;
  AnsiString ClassName;
};

class COMMONAL_API TGridUndoSession {
    TMemoryStream *MS;
    bool FClosed;
public:
    TCellGrid* CG;
    AnsiString Name;
    TPoint ColRow;
    TMDelTList<TGridStateStep> SSL;
    TGridUndoSession(TCellGrid* CG);
    TGridUndoSession();
    virtual ~TGridUndoSession();
    void Open(const AnsiString& aName);
    void Close();
    __property bool Closed = {read = FClosed};
    void RegisterChanges(const TPoint ColRow, TCell* MRO);
    void RegisterCreation(const TPoint ColRow, TCell* MRO);
    void RegisterDeletion(const TPoint ColRow, TCell* MRO);
    void ReadCondition();
};

class TGridUndoStack;

class COMMONAL_API TGridStack {
friend class TGridUndoStack;
protected:
    TMDelTList<TGridUndoSession> Sessions;
public:
    TCellGrid* CG;
    TGridStack(){};
    ~TGridStack(){};
    virtual void Clear();
    void MoveLastSessionTo(TGridStack& OtherStack);
};

class COMMONAL_API TGridUndoStack : public TGridStack{
    void Direct_Undo();
    void Direct_Redo();
    TGridStack RedoStack;
public:
//    TCellGrid* CG;
    TGridUndoStack(){};
    virtual ~TGridUndoStack(){};
    void OpenSession(const AnsiString& SessionName);
    void OpenSessionC(char* _Name);
    void CloseSession();
    void BreakSession();
    void ReadCondition();
    bool Register(int Col,int Row,TCell* Sender,TGridRegisterMode RM);
    void Undo();
    void Redo();
    virtual void Clear();
    bool CanUndo();
    bool CanRedo();
    bool Opened();
};
extern COMMONAL_API TGridUndoStack UndoStack;
#endif
