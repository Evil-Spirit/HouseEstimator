//---------------------------------------------------------------------------

#ifndef InspectorMainH
#define InspectorMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ImgList.hpp>
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
    void __fastcall FormResize(TObject *Sender);
    void __fastcall DataWatch1DblClick(TObject *Sender);
    void __fastcall VariableNameKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool GetMethods();
    void SetMethods(bool State);
    void __fastcall UpdateInspector(TObject *Sender); 
public:		// User declarations
    TNotifyEvent OnUpdate;
    void __fastcall WndProc(Messages::TMessage &Message);
    void __fastcall ShowProperty(AnsiString Name,TMDelTList<TLuaVariable> *Vars);
    void __fastcall Clear();
    __fastcall TDbgInspector(TComponent* Owner);
    __property bool IsMethods = {read=GetMethods, write=SetMethods, default=false};
};


//---------------------------------------------------------------------------
extern COMMONAL_API TDbgInspector *DbgInspector;
COMMONAL_API void Inspect(AnsiString Data, HANDLE hnd=0);
COMMONAL_API void UpdateAllInspectors();
COMMONAL_API void CloseAllInspectors();
//---------------------------------------------------------------------------
#endif
