// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BaseVariableFormVH
#define BaseVariableFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyTemplates.h"
#include "Usefuls.h"
#include "QuckList.h"
#include "FloatingV.h"


extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
//MDI-ôîðìà äëÿ ïåðåìåííûõ
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
    void  ListDblClick(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  AddItemExecute(TObject *Sender);
    void  DelItemExecute(TObject *Sender);
    void  ClearItemExecute(TObject *Sender);
    void  DelItemUpdate(TObject *Sender);
    void  EditItemExecute(TObject *Sender);
    void  EditItemUpdate(TObject *Sender);
    void  ClearItemUpdate(TObject *Sender);
    void  Evaluate(TObject *Sender);
    void  ListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  InspectItemExecute(TObject *Sender);
    void  InspectItemUpdate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void  ViewVars(TMDelTList<TLuaVariable>* Vars);
     TGlobal(TComponent* Owner);
     ~TGlobal();
    void  WndProc(Messages::TMessage &Message);
    TNotifyEvent OnUpdate;
};
//---------------------------------------------------------------------------
//extern COMMONAL_API TGlobal *Global;
COMMONAL_API void AddWatch(AnsiString Data);
//---------------------------------------------------------------------------
#endif
