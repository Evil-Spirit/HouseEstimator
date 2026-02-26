// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIPointerEditVH
#define MDIPointerEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"

#include "MDIObjectEditV.h"
#include "MetaClasses.h"

//---------------------------------------------------------------------------
class COMMONAL_API TMDIPointerEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TComboBoxEx *CBE;
    void  CBEChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void SETUP();
    virtual void KILL();
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual  bool Checked_NotEmpty();
     TPointer<TMetaNode>* Pointer() {return (TPointer<TMetaNode>*)Obj;};
     TMDIPointerEdit::TMDIPointerEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    TNotifyEvent Change;
    TMTList< TClassNode >* LST;
};

void COMMONAL_API EditPointer(TComponent* _Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& Text,TClassNode *Data)
{
    TMTList< TClassNode > LST;
    LST.Add( (TClassNode*)Data );
    new TMDIPointerEdit(_Owner,_Parent,_Obj,Text,&LST);
};

void COMMONAL_API EditPointerByList(TComponent* _Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& Text,TMTList< TClassNode >* LST)
{
    new TMDIPointerEdit(_Owner,_Parent,_Obj,Text,LST);
};

//---------------------------------------------------------------------------
extern COMMONAL_API TMDIPointerEdit *MDIPointerEdit;
//---------------------------------------------------------------------------
#endif
