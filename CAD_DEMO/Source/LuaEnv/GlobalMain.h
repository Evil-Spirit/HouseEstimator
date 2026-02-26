// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef GlobalMainH
#define GlobalMainH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"


extern "C"
{
#include "lua.h"
}
//---------------------------------------------------------------------------
//Îïèñàíèå êëàññîâ è òèïîâ ïåðåìåííûõ ËÓÀ
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString Name,Type,Value;
}   TLuaVariable;

//---------------------------------------------------------------------------
class TLuaVariables : public TObject
{
    public:
     TLuaVariables();
     ~TLuaVariables();

//    void  FillGlobals(TMDelTLIst<TLuaVariable>& Vars);
//    void  FillLocals(TMDelTLIst<TLuaVariable>& Vars);

    TLuaVariable*  GetLocal(AnsiString Name);
    TLuaVariable*  GetGlobal(AnsiString Name);
    bool  SetGlobal(TLuaVariable *Var);
    bool  SetLocal(TLuaVariable *Var);
};
//---------------------------------------------------------------------------
//MDI-ôîðìà äëÿ ïåðåìåííûõ
//---------------------------------------------------------------------------
class TGlobal : public TForm
{
__published:	// IDE-managed Components
    TListView *List;
    void  ListClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void ViewGlobal();
    void ViewLocal();
     TGlobal(TComponent* Owner);
     ~TGlobal();
};
//---------------------------------------------------------------------------
extern  TGlobal *Global;
//---------------------------------------------------------------------------
#endif
