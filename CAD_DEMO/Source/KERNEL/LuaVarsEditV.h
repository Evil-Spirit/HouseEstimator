//---------------------------------------------------------------------------

#ifndef LuaVarsEditVH
#define LuaVarsEditVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "MDIObjectEditV.h"
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TLuaVarsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TListView *LV;
    TToolBar *Buttons;
    TToolButton *tbtAdd;
    TToolButton *tbtEdit;
    TToolButton *tbtDel;
    void __fastcall btAddClick(TObject *Sender);
    void __fastcall btEditClick(TObject *Sender);
    void __fastcall btDelClick(TObject *Sender);
private:	// User declarations
    TMetaNode *GetElemFromObj()
    {
        return (TMetaNode *)Obj;
    }
public:		// User declarations
    virtual void  Refresh();
    virtual void  Apply();
    virtual bool Checked(){return true;}
    __property TMetaElement *Element = {read = GetElemFromObj};
    void AddItem(           const AnsiString& _Name,
                            int _Type,
                            const AnsiString& _Value,
                            const AnsiString& _Comment,
                            const AnsiString& _Meter);
    void AddLuaVar(TLuaAttribute *LV);
    __fastcall TLuaVarsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
void COMMONAL_API EditAttributes(TComponent *Owner,TWinControl *Parent,void *Data,TMetaNode *Elem)
{
    new TLuaVarsEdit(Owner,Parent,Elem,"Attributes",Data);
}

extern COMMONAL_API TLuaVarsEdit *LuaVarsEdit;
//---------------------------------------------------------------------------
#endif
