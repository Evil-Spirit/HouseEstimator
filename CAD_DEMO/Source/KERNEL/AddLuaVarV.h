// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef AddLuaVarVH
#define AddLuaVarVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  FormCreate(TObject *Sender);
    void  FormShow(TObject *Sender);
    void  btOKClick(TObject *Sender);
    void  btCancelClick(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    int VarType;
    AnsiString VarName;
    AnsiString VarVal;
    AnsiString Comment;
    AnsiString Meter;
bool OK;
     TAddLuaVar(TComponent* Owner);
};
bool COMMONAL_API VariantNameOK(const AnsiString& Name);
//---------------------------------------------------------------------------
extern COMMONAL_API TAddLuaVar *AddLuaVar;
//---------------------------------------------------------------------------
#endif
