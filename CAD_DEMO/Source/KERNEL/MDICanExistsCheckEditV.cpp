//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDICanExistsCheckEditV.h"
//#include "MDIConfigV.h"
#include "MetaClasses.h"
#include "MDIElementSelectV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDICanExistsCheckEdit *MDICanExistsCheckEdit;
//---------------------------------------------------------------------------
__fastcall TMDICanExistsCheckEdit::TMDICanExistsCheckEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------

TTreeNode *TMDICanExistsCheckEdit::FindByData(TTreeNode *STN,void* _Data)
{
    if (TV->Items->Count)
    {
        if (!STN)
            return FindByData(TV->Items->Item[0],_Data);
    }
    else
        return NULL;
    if (STN->Data == _Data)
        return STN;
    for (int i=0;i<STN->Count;i++)
    {
        TTreeNode *TN = FindByData(STN->Item[i],_Data);
        if (TN)
            return TN;
    }
    return NULL;}

void FillTV(TTreeView *TV,/*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > > *GPRS)
{
    TV->Items->Clear();
    TTreeNode* Root = TV->Items->Add(NULL,AnsiString("Link groups"));
    for (int i=0;i<GPRS->Count;i++)
    {
        AnsiString _Name=AnsiString();
        TTreeNode* Group = TV->Items->AddChild( Root, "<Empty>");
        Group->Data = GPRS->Items[i];
        Group->ImageIndex = 2;
        Group->StateIndex = 2;
        Group->SelectedIndex = 2;
        for (int j=0;j<GPRS->Items[i]->Count;j++)
        {
            if (_Name.IsEmpty())
                _Name = GPRS->Items[i]->Items[j]->ADR->El0->Name;
            else
                _Name = _Name + AnsiString(" AND ") + GPRS->Items[i]->Items[j]->ADR->El0->Name;
            TTreeNode* Link = TV->Items->AddChild( Group, GPRS->Items[i]->Items[j]->ADR->Name);
            Link->Data = GPRS->Items[i]->Items[j];
            Link->ImageIndex = 4;
            Link->StateIndex = 4;
            Link->SelectedIndex = 4;
        }
        if (!_Name.IsEmpty())
            Group->Text = _Name;
    }
    Root->Expand(false);
}

void TMDICanExistsCheckEdit::Refresh()
{
    /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > > *Origin;
    Origin = ((TCanExistCheck*)Obj)->LinkGroups;
    ELSE->Clear();
    for (int i=0;i<Origin->Count;i++)
    {
        ELSE->Add( new /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >() );
        for (int j=0;j<Origin->Items[i]->Count;j++)
        {
            ELSE->Items[i]->Add(new TPointer< TDynamicLink >());
            ELSE->Items[i]->Last()->ADR = Origin->Items[i]->Items[j]->ADR;
        }
    }
    FillTV(TV,ELSE);
}

void TMDICanExistsCheckEdit::Apply()
{
    /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > > *Origin;
    Origin = ((TCanExistCheck*)Obj)->LinkGroups;
    Origin->Clear();
    for (int i=0;i<ELSE->Count;i++)
    {
        if (ELSE->Items[i]->Count)
        {
            Origin->Add( new /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >() );
            for (int j=0;j<ELSE->Items[i]->Count;j++)
            {
                Origin->Items[i]->Add(new TPointer< TDynamicLink >());
                Origin->Items[i]->Last()->ADR = ELSE->Items[i]->Items[j]->ADR;
            }
        }
    }
}

bool TMDICanExistsCheckEdit::Checked()
{
    return true;
}

void TMDICanExistsCheckEdit::SETUP()
{
    ELSE = new  /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > >;
}

void TMDICanExistsCheckEdit::KILL()
{
    delete ELSE;
}                                                                       

void __fastcall TMDICanExistsCheckEdit::N1Click(TObject *Sender)
{
    if (!TV->Selected)
        return;
    TMyObject* MO = (TMyObject*)TV->Selected->Data;
    if ( MO->Is( TMDelTList<TPointer< TDynamicLink > >::StaticType ) )
    {
        TDynamicLink* DL = (TDynamicLink*)SelectNode(TDynamicLink::StaticType,true,true,(TMetaNode*)(Obj->MyObjectParent));
        if (DL)
        {
            /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >* OBJ = (/*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >*)MO;
            int index = FindInPointerList(OBJ,DL);
            if (index==-1)
            {
                OBJ->Add( new TPointer< TDynamicLink > );
                OBJ->Last()->ADR = DL;
                FillTV(TV,ELSE);
                TTreeNode * IT = FindByData(TV->Items->Item[0],OBJ->Last());
                if (IT)
                    TV->Selected = IT;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMDICanExistsCheckEdit::N4Click(TObject *Sender)
{
    if (!TV->Selected)
        return;
    if (TV->Selected != TV->Items->Item[0])
        return;
    ELSE->Add( new /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > );
    FillTV(TV,ELSE);
    TTreeNode * IT = FindByData(TV->Items->Item[0],ELSE->Last());
    if (IT)
    TV->Selected = IT;
}
//---------------------------------------------------------------------------
void __fastcall TMDICanExistsCheckEdit::TVMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight)
    {
        TTreeNode *TN = TV->GetNodeAt(X,Y);
        TV->Select(TN);
        TPoint P = TPoint(X,Y);
        P = TV->ClientToScreen(P);
        PopupMenu1->Popup(P.x,P.y);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDICanExistsCheckEdit::N3Click(TObject *Sender)
{
    if (!TV->Selected)
        return;
    TMyObject* MO = (TMyObject*)TV->Selected->Data;
    if ( MO->Is(TMDelTList<TPointer< TDynamicLink > >::StaticType) )
    {
        int index = ELSE->IndexOf((/*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >*)MO);
        ELSE->Delete(index);
    }
    else if ( MO->Is(TPointer< TDynamicLink >::StaticType) )
    {
        /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >* PAR = (/*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > >*)TV->Selected->Parent->Data;
        int index = FindInPointerList(PAR,((TPointer< TDynamicLink >*)MO)->ADR);
        PAR->Delete(index);
    }
    FillTV(TV,ELSE);
}
//---------------------------------------------------------------------------

