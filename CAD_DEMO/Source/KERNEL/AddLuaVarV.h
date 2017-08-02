//---------------------------------------------------------------------------

#ifndef AddLuaVarVH
#define AddLuaVarVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TAddLuaVar : public TForm
{
__published:	// IDE-managed Components
    TComboBox *cbVarType;
    TEdit *eVarName;
    TEdit *eVarVal;
    TLabel *lName;
    TLabel *lType;
    TLabel *Label1;
    TButton *btOK;
    TButton *btCancel;
    TLabel *Label2;
    TEdit *eComment;
    TLabel *Label3;
    TEdit *eMeter;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btOKClick(TObject *Sender);
    void __fastcall btCancelClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    int VarType;
    AnsiString VarName;
    AnsiString VarVal;
    AnsiString Comment;
    AnsiString Meter;
bool OK;
    __fastcall TAddLuaVar(TComponent* Owner);
};
bool COMMONAL_API VariantNameOK(const AnsiString& Name);
//---------------------------------------------------------------------------
extern COMMONAL_API TAddLuaVar *AddLuaVar;
//---------------------------------------------------------------------------
#endif
