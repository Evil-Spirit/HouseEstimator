//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MultiElmentV.h"
#include "MDIMultiElementV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//---------------------------TMetaMultiElement-------------------------
TMyObject* TMetaMultiElement::CreateFunction()
{
    return new TMetaMultiElement();
}

const AnsiString aUNITS = AnsiString("UNITS");
const AnsiString aIsSizer = AnsiString("IsSizer");

TMetaMultiElement::TMetaMultiElement(TMetaNode *Parent,int _ID,const AnsiString& Name)
    :TMetaElement(Parent,_ID,Name)
{
    RegisterNewClass< TMetaElement, TMetaMultiElement >(this,false,&CreateFunction);
    UNITS = new /*TMDelLSTList*/TMDelTList< TPointer<TMetaElement> >();
    RegisterField(UNITS,&aUNITS,mtMyObject);
    RegisterField(&IsSizer,&aIsSizer,mtBool);
    ImageIndex=iiMetaMultiElement;
    IsSizer = false;
}

TMetaMultiElement::TMetaMultiElement()
{
    RegisterNewClass< TMetaElement, TMetaMultiElement >(this,false,&CreateFunction);
    UNITS = new /*TMDelLSTList*/TMDelTList< TPointer<TMetaElement> >();
    RegisterField(UNITS,&aUNITS,mtMyObject);
    RegisterField(&IsSizer,&aIsSizer,mtBool);
    ImageIndex=iiMetaMultiElement;
    IsSizer = false;
}

TMetaMultiElement::~TMetaMultiElement()
{
    delete UNITS;
}

void TMetaMultiElement::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMultiElement(_Owner,this);
    #endif
}

TMyObject* TMultiElement::CreateFunction()
{
    return new TMultiElement();
}

TMultiElement::TMultiElement(TMainTree *_MyTree,TMetaNode *_Meta)
    :TElement(_MyTree,_Meta)
{
    RegisterNewClass< TElement, TMultiElement >(this,false,&CreateFunction);
    if (typeid(*_Meta)!=typeid(TMetaMultiElement))
    {
        Application->MessageBox("Expected MetaMultiElement, got Unknown. Application stopped.","Error");
        Application->Terminate();
        return;
    }
    ELS = new TMDelTList < TMDelTList< TElement > >();
    for (int i=0;i<MetaMultiElement->UNITS->Count;i++)
        ELS->Add( new TMDelTList< TElement >() );
    VFIRST = new TVisNode(NULL);
    VFIRST->Transformation->Order = toTraRotSca;
    VFIRST->Transformation->Rotation->Order = roZXY;
    VTRANS = new TVisNode(NULL);
    VTRANS->Transformation->Order = toTraRotSca;
    VTRANS->Transformation->Rotation->Order = roZXY;
    MGT->AddRender(1,this,VFIRST);
    CreateView();
    CurrentEnabled = true;
    CustomEnabled = true;
}

void TMultiElement::SetEnabled(int type,bool Value)
{
    TElement::SetEnabled(type,Value);
    VTRANS->Enabled = VFIRST->Enabled;
}

TMultiElement::TMultiElement()
{
    RegisterNewClass< TElement, TMultiElement >(this,false,&CreateFunction);
    ELS = new TMDelTList < TMDelTList< TElement > >();
    VFIRST = new TVisNode(NULL);
    VFIRST->Transformation->Order = toTraRotSca;
    VFIRST->Transformation->Rotation->Order = roZXY;
    VTRANS = new TVisNode(NULL);
    VTRANS->Transformation->Order = toTraRotSca;
    VTRANS->Transformation->Rotation->Order = roZXY;
}

bool TMultiElement::CheckFields()
{
    if (!TElement::CheckFields())
        return false;
    for (int i=0;i<MetaMultiElement->UNITS->Count;i++)
        ELS->Add( new TMDelTList< TElement >() );
    return true;
}

TMultiElement::~TMultiElement()
{
    RemoveRenderFromTree();
    delete ELS;
    delete VFIRST;
    delete VTRANS;
}

TElement *TMultiElement::AddOnly(int index)
{
    TMetaElement *ME = MetaMultiElement->UNITS->Items[index]->ADR;
    AnsiString CN = AnsiString(typeid(*ME).name()).Trim();
    CN = CutMeta(CN);
    TElement *EL = (TElement *)Create_Default_Constructor(CN);
    EL->DoNotReg = true;
    EL->MyTree = MyTree;
    EL->Name = Name + AnsiSpace + AnsiString("UNIT") + AnsiSpace + IntToStr(index)+AnsiSpace+IntToStr(CountOf(index)+1);
    EL->SetField("METAID",&(ME->ID));
    EL->CheckFields();
    EL->Init();
    if ( EL->Is (TMultiElement::StaticType) )
    {
        VTRANS->Add(((TMultiElement*)EL)->VTRANS);
        VFIRST->Add(((TMultiElement*)EL)->VFIRST);
    }
    else
    {
        if (EL->MyMeta->VM->ColorDiffuse->Alpha!=1)
            VTRANS->Add(EL->MyRender());
        else
            VFIRST->Add(EL->MyRender());
    }
    ELS->Items[index]->Add(EL);
    return EL;
}


TElement *TMultiElement::Add(int index)
{
    TMetaElement *ME = MetaMultiElement->UNITS->Items[index]->ADR;
    AnsiString CN = AnsiString(typeid(*ME).name()).Trim();
    CN = CutMeta(CN);
    TElement *EL = (TElement *)Create_Default_Constructor(CN);
    EL->DoNotReg = true;
    EL->MyTree = MyTree;
    EL->Name = Name + AnsiSpace + AnsiString("UNIT") + AnsiSpace + IntToStr(index)+AnsiSpace+IntToStr(CountOf(index)+1);
    EL->SetField("METAID",&(ME->ID));
    EL->CheckFields();
    EL->SetSize(EL->MyMeta->Size.DEFAULT);
    EL->Init();

    if ( EL->Is(TMultiElement::StaticType) )
    {
        VTRANS->Add(((TMultiElement*)EL)->VTRANS);
        VFIRST->Add(((TMultiElement*)EL)->VFIRST);
    }
    else
    {
        if (EL->MyMeta->VM->ColorDiffuse->Alpha!=1)
            VTRANS->Add(EL->MyRender());
        else
            VFIRST->Add(EL->MyRender());
    }
    ELS->Items[index]->Add(EL);
    return EL;
}

void TMultiElement::DeleteOne(TElement *El)
{
    for (int i=0;i<ELS->Count;i++)
        for (int j=0;j<ELS->Items[i]->Count;j++)
            if (ELS->Items[i]->Items[j]==El)
            {
                DeleteOne(i,j);
                return;
            }
}

void TMultiElement::DeleteOne(int typeindex,int index)
{
    TElement *El = ELS->Items[typeindex]->Items[index];
    int ind = VTRANS->IndexOf(El->MyRender());
    if (ind!=-1)
        VTRANS->Delete(ind);
    else
    {
        ind = VFIRST->IndexOf(El->MyRender());
        if (ind!=-1)
            VFIRST->Delete(ind);
    }
    ELS->Items[typeindex]->Delete(index);
}

void TMultiElement::Clear()
{
    for (int i=0;i<ELS->Count;i++)
        while(ELS->Items[i]->Count)
            DeleteOne(i,0);
}

void TMultiElement::ProcessTasks(int Action)
{
    TElement::ProcessTasks(Action);
    VTRANS->Transformation->Translation->Assign(VFIRST->Transformation->Translation);
    VTRANS->Transformation->Rotation->Assign(VFIRST->Transformation->Rotation);
}

void TMultiElement::StandartCreateView()
{
/**/
}

void TMultiElement::ProcessTexturing()
{
    NeedTexturing = false;
/*    TextureObject(rFloor,FloorParam);
    TextureObject(rCeil,CeilParam);*/
}

void TMultiElement::Render(TVisCustomView* aView)
{
    VFIRST->Render(aView);
    VTRANS->Render(aView);
}

int TMultiElement::GetMetaPartCount()
{
    return ELS->Count;
}

TElement *TMultiElement::GetPart(int i,int j)
{
    return ( ELS->Items[i]->Items[j] );
}

int TMultiElement::CountOf(int type)
{
    return ELS->Items[type]->Count;
}

