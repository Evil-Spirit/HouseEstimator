//---------------------------------------------------------------------------

#ifndef MDIPointerListEditVH
#define MDIPointerListEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMetaNode;
typedef TPointer<TMetaNode>* (*TNewItem)();

class COMMONAL_API TMDIPointerListEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TListView *LV;
    TPanel *PButtons;
	TToolBar *ToolBar1;
	TToolButton *tbtAdd;
	TToolButton *tbtDel;
	TToolButton *tbtUp;
	TToolButton *tbtDown;
	TToolButton *tbReset;
	void __fastcall btAddClick(TObject *Sender);
	void __fastcall btDelClick(TObject *Sender);
	void __fastcall sbupClick(TObject *Sender);
	void __fastcall sbdownClick(TObject *Sender);
	void __fastcall tbResetClick(TObject *Sender);
private:	// User declarations
	bool AllowDuplicates;
	TMetaNode* FEXCL;
	TMetaNode* SetEXCL(TMetaNode* EXCL);
public:		// User declarations
	void Apply();
	void Refresh();
	bool Checked();
	TClassNode* CN;
	virtual void SETUP();
	/*TMDelLSTList*/TMDelTList< TPointer<TMetaNode> >* List;
	__property TMetaNode* EXCL = {read = FEXCL, write = SetEXCL};
	TNewItem NewItem;
	__fastcall TMDIPointerListEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void* Data, bool AllowDuplicates=false);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIPointerListEdit *MDIPointerListEdit;

template <class T> void EditPointerList(  TComponent* Owner,
                                    TControl *_Parent,
                                    /*TMDelLSTList*/TMDelTList< TPointer<T> >* LST,
                                    const AnsiString& Text,
                                    TClassNode* CN,
                                    TMetaNode* EXCL,TNewItem NewItem, bool AllowDuplicates=false)
{
    if ( !CN->is( TMetaNode::StaticType ) )
        throw EMyException("Can not edit list of pointers of the given type");
    TMDIPointerListEdit* PLE = new TMDIPointerListEdit(Owner,_Parent,LST,Text,CN, AllowDuplicates);
    PLE->EXCL = EXCL;
    PLE->NewItem = NewItem;
}

TPointer<TMetaNode>* COMMONAL_API CreateMetaElementPointer();

//---------------------------------------------------------------------------
#endif
