// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef LuaVarsEditVH
#define LuaVarsEditVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TLuaVarsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TListView *LV;
    TToolBar *Buttons;
    TToolButton *tbtAdd;
    TToolButton *tbtEdit;
    TToolButton *tbtDel;
    void  btAddClick(TObject *Sender);
    void  btEditClick(TObject *Sender);
    void  btDelClick(TObject *Sender);
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
     TLuaVarsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
void COMMONAL_API EditAttributes(TComponent *Owner,TWinControl *Parent,void *Data,TMetaNode *Elem)
{
    new TLuaVarsEdit(Owner,Parent,Elem,"Attributes",Data);
}

extern COMMONAL_API TLuaVarsEdit *LuaVarsEdit;
//---------------------------------------------------------------------------
#endif
