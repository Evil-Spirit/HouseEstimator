//---------------------------------------------------------------------------

#ifndef BindedGoEditVH
#define BindedGoEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
class TBaseBlock;
class TGo;
//---------------------------------------------------------------------------
class PACKAGE TBindedGoEdit : public TForm
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
    void __fastcall eKeyKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eKeyChange(TObject *Sender);
    void __fastcall bOkClick(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall cbEventChange(TObject *Sender);
//    void __fastcall bOkClick(TObject *Sender);
private:	// User declarations
    TGo* FObj;
    TMDelTList<int> MyBlocksIds;
    int FBlockType;
public:		// User declarations
    __fastcall TBindedGoEdit(TComponent* Owner, TGo *Obj, const TMDelTList<AnsiString>& BlocksNames, TMDelTList<int>& BlocksIds, int BlockType);
    int flag;
    bool Checked();
    void Apply();
    void Refresh();
};
//---------------------------------------------------------------------------
extern PACKAGE TBindedGoEdit *BindedGoEdit;
//---------------------------------------------------------------------------
#endif
