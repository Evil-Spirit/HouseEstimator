//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop         

#include "MDIObjectEditV.h"

#include "SimpleEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIObjectEdit *MDIObjectEdit;
//---------------------------------------------------------------------------
__fastcall TMDIObjectEdit::TMDIObjectEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TBaseForm(Owner)
{
    DATA = Data;
    BoundsRect = _Parent->ClientRect;
    Parent = (TWinControl *)_Parent;
    Align = alClient;
    Visible=true;                                    
    Obj = _Obj;
    LBL->Caption = Text;
    Count=0;
    Constructing = true;
    SETUP();
    for (int i=0;i<Count;i++)
    {
        int MT = _Obj->GetFieldType(P[i]->Name);
        if (MT ==mtMyObject)
            ((TMyObject*)_Obj->GetFieldAddress(P[i]->Name))->Edit(this,P[i],NULL);
        else
        CallDialog(this,P[i],_Obj,MT,P[i]->Name,Data);
    }
    Refresh();
    Constructing=false;
}
//---------------------------------------------------------------------------

void TMDIObjectEdit::Refresh()
{
    for (int i=0;i<Count;i++)
    {
        if (P[i]->Controls[0]->ClassType()==__classid(TMDIObjectEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDIObjectEdit))
        {
            ((TMDIObjectEdit *)P[i]->Controls[0])->Refresh();
            continue;
        }
        if (P[i]->Controls[0]->ClassType()==__classid(TMDISimpleEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDISimpleEdit))
        {
            ((TMDISimpleEdit *)P[i]->Controls[0])->Refresh();
            continue;
        }
    }
}

void TMDIObjectEdit::ObjectApply()
{
    for (int i=0;i<Count;i++)
        if (P[i]->Controls[0]->ClassType()==__classid(TMDISimpleEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDISimpleEdit))
        {
            TMDISimpleEdit * SE= (TMDISimpleEdit *)(P[i]->Controls[0]);
            Obj->SetFieldDirectly(SE->L->Caption,SE->Value());
        }
}

void TMDIObjectEdit::Apply()
{
    ObjectApply();
    for (int i=0;i<Count;i++)
        if (P[i]->Controls[0]->ClassType()==__classid(TMDIObjectEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDIObjectEdit))
            ((TMDIObjectEdit *)P[i]->Controls[0])->Apply();
}

bool TMDIObjectEdit::ObjectChecked()
{
    for (int i=0;i<Count;i++)
        if (P[i]->Controls[0]->ClassType()==__classid(TMDISimpleEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDISimpleEdit))
        {
            TMDISimpleEdit * SE= (TMDISimpleEdit *)(P[i]->Controls[0]);
            if (SE->CustomChecked()==false)
                return(false);
        }
    bool result;
    TStringList *SL = new TStringList();
    for (int i=0;i<Count;i++)
        if (P[i]->Controls[0]->ClassType()==__classid(TMDISimpleEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDISimpleEdit))
        {
            TMDISimpleEdit * SE= (TMDISimpleEdit *)(P[i]->Controls[0]);
            SL->Add(TYPETOSTR(Obj->GetFieldAddress(SE->L->Caption),Obj->GetFieldType(SE->L->Caption)));
            Obj->SetFieldDirectly(SE->L->Caption,SE->Value());
        }
    result = Obj->CheckFields();
    int next=0;
    for (int i=0;i<Count;i++)
        if (P[i]->Controls[0]->ClassType()==__classid(TMDISimpleEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDISimpleEdit))
        {
            TMDISimpleEdit * SE= (TMDISimpleEdit *)(P[i]->Controls[0]);
            Obj->SetFieldDirectly(SE->L->Caption,STRTOTYPE(SL->Strings[next],Obj->GetFieldType(SE->L->Caption)));
        }
    delete SL;
    return(result);
}

bool TMDIObjectEdit::Checked()
{
    if (Constructing)
        return(true);
    for (int i=0;i<Count;i++)
    {
        if (P[i]->Controls[0]->ClassType()==__classid(TMDIObjectEdit)||
                P[i]->Controls[0]->ClassParent()==__classid(TMDIObjectEdit))
            if ( ((TMDIObjectEdit *)P[i]->Controls[0])->ObjectChecked()==false )
                return(false);
    }
    return(ObjectChecked());
}




