// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef InspectorMainH
#define InspectorMainH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include <ValEdit.hpp>
#include "MyTemplates.h"
#include "Usefuls.h"
#include "QuckList.h"
#include "FloatingV.h"

extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
class COMMONAL_API TDbgInspector : public TFloatForm
{
__published:	// IDE-managed Components
    TPageControl *Sheets;
    TTabSheet *Sheet1;
    TStatusBar *StatusBar;
    TStringGrid *DataWatch1;
    TComboBoxEx *VariableName;
    TTabSheet *Sheet2;
    TStringGrid *DataWatch2;
    void  FormResize(TObject *Sender);
    void  DataWatch1DblClick(TObject *Sender);
    void  VariableNameKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool GetMethods();
    void SetMethods(bool State);
    void  UpdateInspector(TObject *Sender); 
public:		// User declarations
    TNotifyEvent OnUpdate;
    void  WndProc(Messages::TMessage &Message);
    void  ShowProperty(AnsiString Name,TMDelTList<TLuaVariable> *Vars);
    void  Clear();
     TDbgInspector(TComponent* Owner);
    __property bool IsMethods = {read=GetMethods, write=SetMethods, default=false};
};


//---------------------------------------------------------------------------
extern COMMONAL_API TDbgInspector *DbgInspector;
COMMONAL_API void Inspect(AnsiString Data, HANDLE hnd=0);
COMMONAL_API void UpdateAllInspectors();
COMMONAL_API void CloseAllInspectors();
//---------------------------------------------------------------------------
#endif
