// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIPointerEditV.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIPointerEdit *MDIPointerEdit;
//---------------------------------------------------------------------------
 TMDIPointerEdit::TMDIPointerEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void TMDIPointerEdit::KILL()
{
    delete LST;
}

void TMDIPointerEdit::SETUP()
{
    LST = new TMTList<TClassNode>();
    Change = NULL;
    TMTList<TClassNode> *__classlist = (TMTList<TClassNode> *)DATA;
    for (int i=0;i<__classlist->Count;i++)
        LST->Add(__classlist->Items[i]);

    CBE->Clear();
    TMetaNode *MN;
    TComboExItem *CEI;
    TMTList<TMyRegObject> List;
    CEI = CBE->ItemsEx->AddItem(AnsiString("<NULL>"),-1,-1,-1,0,0);
    CEI->Data = NULL;

    for (int k=0;k<LST->Count;k++)
    {
        List.Clear();
        MetaNodeCollection->SelectByCT(NULL,LST->Items[k] ,&List,true,true);
        for (int i=0;i<List.Count;i++)
        {
            MN = (TMetaNode *)List.Items[i];
            int ind = MN->ImageIndex;
            CEI = CBE->ItemsEx->AddItem(MN->Name,ind,ind,ind,0,0);
            CEI->Data = MN;
        }
    }
}

void TMDIPointerEdit::Refresh()
{
    for (int i=0;i<CBE->ItemsEx->Count;i++)
        if (CBE->ItemsEx->Items[i]->Data == Pointer()->ADR)
        {
            CBE->ItemIndex = i;
            return;
        }
    CBE->ItemIndex = 0;
}

void TMDIPointerEdit::Apply()
{
    if (CBE->ItemIndex != -1)
        Pointer()->ADR = (TMetaNode*) CBE->ItemsEx->Items[CBE->ItemIndex]->Data;
    else
        Pointer()->ADR = NULL;
}

bool TMDIPointerEdit::Checked()
{
    return CBE->ItemIndex != -1;
}

bool TMDIPointerEdit::Checked_NotEmpty()
{
    return CBE->ItemIndex>0;
}


void  TMDIPointerEdit::CBEChange(TObject *Sender)
{
    if (Change)
        Change(this);    
}
//---------------------------------------------------------------------------

