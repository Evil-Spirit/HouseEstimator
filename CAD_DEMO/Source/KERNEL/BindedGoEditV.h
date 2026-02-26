// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BindedGoEditVH
#define BindedGoEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
class TBaseBlock;
class TGo;
//---------------------------------------------------------------------------
class  TBindedGoEdit : public TForm
{
__published:	// IDE-managed Components
    TLabel *lEvent;
    TLabel *lKey;
    TLabel *lMouseButton;
    TComboBox *cbEvent;
    TEdit *eKey;
    TComboBox *cbMouseButton;
    TComboBox *cbNextBlock;
    TLabel *lNextBlock;
    TButton *bOk;
    TButton *bCancel;
    void  eKeyKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  eKeyChange(TObject *Sender);
    void  bOkClick(TObject *Sender);
    void  bCancelClick(TObject *Sender);
    void  cbEventChange(TObject *Sender);
//    void  bOkClick(TObject *Sender);
private:	// User declarations
    TGo* FObj;
    TMDelTList<int> MyBlocksIds;
    int FBlockType;
public:		// User declarations
     TBindedGoEdit(TComponent* Owner, TGo *Obj, const TMDelTList<AnsiString>& BlocksNames, TMDelTList<int>& BlocksIds, int BlockType);
    int flag;
    bool Checked();
    void Apply();
    void Refresh();
};
//---------------------------------------------------------------------------
extern  TBindedGoEdit *BindedGoEdit;
//---------------------------------------------------------------------------
#endif
