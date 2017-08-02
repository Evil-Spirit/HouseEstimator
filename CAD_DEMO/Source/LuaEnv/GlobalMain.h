//---------------------------------------------------------------------------

#ifndef GlobalMainH
#define GlobalMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>


extern "C"
{
#include "lua.h"
}
//---------------------------------------------------------------------------
//Описание классов и типов переменных ЛУА
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString Name,Type,Value;
}   TLuaVariable;

//---------------------------------------------------------------------------
class TLuaVariables : public TObject
{
    public:
    __fastcall TLuaVariables();
    __fastcall ~TLuaVariables();

//    void __fastcall FillGlobals(TMDelTLIst<TLuaVariable>& Vars);
//    void __fastcall FillLocals(TMDelTLIst<TLuaVariable>& Vars);

    TLuaVariable* __fastcall GetLocal(AnsiString Name);
    TLuaVariable* __fastcall GetGlobal(AnsiString Name);
    bool __fastcall SetGlobal(TLuaVariable *Var);
    bool __fastcall SetLocal(TLuaVariable *Var);
};
//---------------------------------------------------------------------------
//MDI-форма для переменных
//---------------------------------------------------------------------------
class TGlobal : public TForm
{
__published:	// IDE-managed Components
    TListView *List;
    void __fastcall ListClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void ViewGlobal();
    void ViewLocal();
    __fastcall TGlobal(TComponent* Owner);
    __fastcall ~TGlobal();
};
//---------------------------------------------------------------------------
extern PACKAGE TGlobal *Global;
//---------------------------------------------------------------------------
#endif
