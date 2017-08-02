//---------------------------------------------------------------------------

#ifndef BaseVariableFormVH
#define BaseVariableFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MyTemplates.h"
#include "Usefuls.h"
#include <ActnList.hpp>
#include <Menus.hpp>
#include "QuckList.h"
#include "FloatingV.h"


extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
//MDI-����� ��� ����������
//---------------------------------------------------------------------------
class COMMONAL_API TGlobal : public TFloatForm
{
__published:	// IDE-managed Components
    TListView *List;
    TActionList *WatchActions;
    TPopupMenu *WatchPopup;
    TAction *AddItem;
    TAction *DelItem;
    TAction *ClearItem;
    TMenuItem *ClearItem1;
    TMenuItem *DelItem1;
    TAction *EditItem;
    TMenuItem *Editwatch1;
    TMenuItem *Inspectitem1;
    TAction *InspectItem;
    void __fastcall ListDblClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall AddItemExecute(TObject *Sender);
    void __fastcall DelItemExecute(TObject *Sender);
    void __fastcall ClearItemExecute(TObject *Sender);
    void __fastcall DelItemUpdate(TObject *Sender);
    void __fastcall EditItemExecute(TObject *Sender);
    void __fastcall EditItemUpdate(TObject *Sender);
    void __fastcall ClearItemUpdate(TObject *Sender);
    void __fastcall Evaluate(TObject *Sender);
    void __fastcall ListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall InspectItemExecute(TObject *Sender);
    void __fastcall InspectItemUpdate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void __fastcall ViewVars(TMDelTList<TLuaVariable>* Vars);
    __fastcall TGlobal(TComponent* Owner);
    __fastcall ~TGlobal();
    void __fastcall WndProc(Messages::TMessage &Message);
    TNotifyEvent OnUpdate;
};
//---------------------------------------------------------------------------
//extern COMMONAL_API TGlobal *Global;
COMMONAL_API void AddWatch(AnsiString Data);
//---------------------------------------------------------------------------
#endif
