// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIActionsEditVH
#define MDIActionsEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIActionsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TGroupBox *Tools;
    TGroupBox *CreateTools;
    void  FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void SETUP();
    void Refresh();
    void Apply();
    bool Checked();
     TMDIActionsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    //---------------------------------------------------------
    void ActionAndModeByTreeNode(TTreeNode *TN, int &_Action,int &_Mode);
    TTreeNode *FindByActionAndMode(int _TagAction,int _TagMode);
    TTreeNode *FindByAction(int _TagAction);
    TTreeNode *FindByData(TTreeNode *TN,void* Data);
    TListItem * AddAction(TTreeNode* TN);
    void RemoveAction(TListItem *LV);
    //---------------------------------------------------------
    TMyActionSettings *MAS();

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIActionsEdit *MDIActionsEdit;
//---------------------------------------------------------------------------
#endif
