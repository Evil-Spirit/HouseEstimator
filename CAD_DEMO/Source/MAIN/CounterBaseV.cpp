//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MultiElementV.h"
#include "NomenclatureV.h"

#include "CounterBaseV.h"
#include "World.h"
#include "LuaAttributeV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TCounterBase* Counter = NULL;

void TCounterBase::ForceCount()
{
    TCounterBase* OldCounter = Counter;
    Counter = this;
    _TRY_

            Clear();
            TMTList<TMyRegObject> L;
            TMTList<TLink> LL;

            World->SelectByCT(NULL,TElement::StaticType,&L,true,true);
            World->SelectAllLinks(NULL,&LL);

            StartProcess("Calculating",L.Count+LL.Count);

            for (int j=0;j<L.Count;j++)
                ((TElement*)(L.Items[j]))->Counted=false;

            for (int i=0;i<LL.Count;i++)
                LL.Items[i]->Counted=false;

            for (int j=0;j<L.Count;j++)
            {
                TElement *El = (TElement*)(L.Items[j]);
                if (El->Counted)
                    continue;
                CountProcess(El->Name,1);

                El->RunElementTrigger(trPaymentCount);
                if ( El->Is(TMultiElement::StaticType) )
                {
                    TMultiElement* Mul = (TMultiElement*)El;
                    for (int mi=0;mi<Mul->ELS->Count;mi++)
                        for (int mj=0;mj<Mul->ELS->Items[mi]->Count;mj++)
                            Mul->ELS->Items[mi]->Items[mj]->RunElementTrigger(trPaymentCount);
                }
            }
            L.Clear();
            //<igor>
            for (int i=0; i<LL.Count; ++i)
            {
                if (!LL.Items[i]->Counted)
                    LL.Items[i]->RunLinkTrigger(trPaymentCount);
                CountProcess(LL.Items[i]->Name,1);
            }
            /*
            while (LL.Count)
            {
                if (!LL.Items[0]->Counted)
                    LL.Items[0]->RunLinkTrigger(trPaymentCount);
                CountProcess(LL.Items[0]->Name,1);
            }
            */
            //------------------------------------------
            ((TMetaNode*)MetaNodeCollection->Head)->TB->Run(trAfterCount);
            //------------------------------------------
    _ENDTRY_("<TCounterBase::ForceCount>: Calculation has not been done.",);
    Counter = OldCounter;
}

int FindInList__(TMDelTList<TLuaAttribute>* List,const AnsiString& Name)
{
    for (int i=0;i<List->Count;i++)
        if (List->Items[i]->Name.LowerCase() == Name.LowerCase())
            return i;
    return -1;
}

TCounterBase::TCounterBase()
{
    Counter = this;
    ShowImages = true;
}

TCounterBase::~TCounterBase()
{
    Counter = NULL;
    ShowImages = true;
}

void TCounterBase::Clear()
{
    Fields->Clear();
    FieldExs->Clear();
    Nomenclature->Clear();
    Objects->Clear();
    Data->Clear();
}


int TCounterBase::GetVisibleFieldCount()
{
    int Count=0;
    for (int i=0;i<vFieldExs.Count;i++)
        Count += vFieldExs[i].Visible;
    return Count;
}

int TCounterBase::UnvisibleInTheMiddle()
{
    int UnvisibleIndex = vFieldExs.Count;
    for (int k=0;k<vFieldExs.Count;k++)
        if (!vFieldExs[k].Visible)
        {
            UnvisibleIndex = k;
            break;
        }
    if (UnvisibleIndex<GetVisibleFieldCount())
        return UnvisibleIndex;
    else
        return -1;
}

void TCounterBase::UnVisibleToEnd()
{
    int index;
    while ( (index = UnvisibleInTheMiddle()) != -1)
    {
        vFields.Move(index,vFields.Count-1);
        vFieldExs.Move(index,vFields.Count-1);
        for (int i=0;i<Objects->Count;i++)
            for (int j=0;j<Nomenclature->Count;j++)
                Data->Items[i]->Items[j]->Move(index,vFields.Count-1);
    }
}

void TCounterBase::ProcessAddField( const AnsiString& FieldName,
                                    int Type,
                                    const AnsiString& _Meters,
                                    int Digits,
                                    bool Visible,
                                    bool Accumulate,
                                    bool Total)
{
    TLuaAttribute * LV = new TLuaAttribute();
    LV->ReadOnly = false;
    LV->Type = Type;
    LV->Name = FieldName;
    Fields->Add(LV);
    FieldExs->Add( new TFieldEx() );
    FieldExs->Last()->Meter = _Meters;
    if (Type == mtDouble)
        FieldExs->Last()->Digits = Digits;
    else
        FieldExs->Last()->Digits = 0;
    FieldExs->Last()->Visible = Visible;
    FieldExs->Last()->Accumulate = Accumulate;
    FieldExs->Last()->Total = Total;

    //------------------------------ add to each object field
    for (int i=0;i<Objects->Count;i++)
        for (int j=0;j<Nomenclature->Count;j++)
            Data->Items[i]->Items[j]->Add(new AnsiString("0"));
    UnVisibleToEnd();            
}

char* TCounterBase::GetSum(TMyObject *Sender,TNomenclature * Nom,char* FieldName,bool Round)
{
    int i0;
    int j0;
    int k0;
    if (Sender == NULL)
        i0 = -1;
    else
    {
        i0 = Objects->IndexOf(Sender);
        if (i0 == -1)
            return AnsiString().c_str();
    }
    if (Nom == NULL)
        j0 = -1;
    else
    {
        j0 = Nomenclature->IndexOf(Nom);
        if (j0 == -1)
            return AnsiString().c_str();
    }
    k0 = FindInList__(Fields,AnsiString(FieldName));
    if (k0 == -1)
        return AnsiString().c_str();
    return GetSum(i0,j0,k0,Round).c_str();
}


TLuaAttribute ServiceLV;
AnsiString TCounterBase::GetSum(int i0,int j0,int k0,bool Round)
{
    if (FieldExs->Items[k0]->Accumulate)
    {
        int iMin = i0;
        int iMax = i0;
        int jMin = j0;
        int jMax = j0;
        if (i0==-1)
        {
            iMin = 0;
            iMax = Objects->Count-1;
        }
        if (j0==-1)
        {
            jMin = 0;
            jMax = Nomenclature->Count-1;
        }
        Fields->Items[k0]->VALUE = AnsiString("0");
        for (int i=iMin;i<=iMax;i++)
            for (int j=jMin;j<=jMax;j++)
                Fields->Items[k0]->AddData(*(Data->Items[i]->Items[j]->Items[k0]));
        AnsiString Result;
        if (Round)
            Result = Fields->Items[k0]->ValueRoundTo(FieldExs->Items[k0]->Digits);
        else
            Result = Fields->Items[k0]->VALUE;
        if (Result == AnsiString("0"))
            return AnsiString("");
        else
            return Result;
    }
    else
    {
        for (int i=0;i<Objects->Count;i++)
            if (*(Data->Items[i]->Items[j0]->Items[k0])!=AnsiString("0") &&
                *(Data->Items[i]->Items[j0]->Items[k0])!=AnsiString(""))
            {
                return *(Data->Items[i]->Items[j0]->Items[k0]);
            }
        return AnsiString("");
    }
}

char* TCounterBase::GetSumByNomFilter(TMyRegObject* Parent,TMyObject *Sender,char* FieldName,bool Round)
{
    int i0;
    int k0;
    if (Sender == NULL)
        i0 = -1;
    else
    {
        i0 = Objects->IndexOf(Sender);
        if (i0 == -1)
            return AnsiString().c_str();
    }
    k0 = FindInList__(Fields,AnsiString(FieldName));
    if (k0 == -1)
        return AnsiString().c_str();
    return GetSumByNomFilter(Parent,i0,k0,Round).c_str();
}

AnsiString TCounterBase::GetSumByNomFilter(TMyRegObject* Parent,int i0,int k0,bool Round)
{
    AnsiString Result;
    if (vFieldExs[k0].Accumulate)
    {
        int iMin = i0;
        int iMax = i0;
        if (i0==-1)
        {
            iMin = 0;
            iMax = Objects->Count-1;
            vFields[k0].VALUE = AnsiString("0");
            for (int i=iMin;i<=iMax;i++)
                for (int j=0;j<=vNom.Count-1;j++)
                    if ( !Parent || (vNom[j].In(Parent) || vNom.Items[j] == Parent) )
                        vFields[k0].AddData( vData[i][j][k0] );
        }
        Result = vFields[k0].VALUE;
    }
    else
    {
        int iMin = i0;
        int iMax = i0;
        if (i0==-1)
        {
            iMin = 0;
            iMax = Objects->Count-1;
            vFields[k0].VALUE = AnsiString("0");
            for (int i=iMin;i<=iMax;i++)
                for (int j=0;j<=vNom.Count-1;j++)
                    if ( !Parent || (vNom[j].In(Parent) || vNom.Items[j] == Parent) )
                    {
                        if (EmptyVariant(vData[i][j][k0]))
                            continue;
                        if ( EmptyVariant(vFields[k0].VALUE) )
                            vFields[k0].VALUE = vData[i][j][k0];
                        else if (!vFields[k0].EqualTo(vData[i][j][k0],vFieldExs[k0].Digits))
                            return AnsiString("");
                    }
        }
        Result = vFields[k0].VALUE;
    }
    if (Round)
        Result = vFields[k0].ValueRoundTo(vFieldExs[k0].Digits);
    if (Result == AnsiString("0"))
        Result = AnsiString("");
    return Result;
}


int TCounterBase::ProcessAddObject(TMyObject *Sender)
{
    if (!Sender)
        throw EMyException("Object is not assigned");
    Objects->Add(Sender);
    Data->Add( new TMDelTList< TMDelTList< AnsiString > >() );

    for (int j=0;j<Nomenclature->Count;j++)
    {
        Data->Last()->Add( new TMDelTList< AnsiString > );
        for (int k=0;k<Fields->Count;k++)
            Data->Last()->Last()->Add(new AnsiString("0"));
    }
    return Objects->Count-1;
}

int TCounterBase::ProcessAddNomenclature(TNomenclature* Nom)
{
    if (!Nom)
        throw EMyException("Nomenclature is not selected");
    Nomenclature->Add(Nom);
    for (int i=0;i<Objects->Count;i++)
    {
        Data->Items[i]->Add(new TMDelTList<AnsiString>());
        for (int k=0;k<Fields->Count;k++)
            Data->Items[i]->Last()->Add(new AnsiString("0"));
    }
    return Nomenclature->Count-1;
}

AnsiString *TCounterBase::Iterate( TMyObject* Sender,
                            TNomenclature* Nom,
                            const AnsiString& FieldName,
                            const AnsiString& KeyField,
                            const AnsiString& KeyValue,
                            bool ByKeyValue)
{
    int iIndex;
    int jIndex;
    int kIndex;
    int kKeyIndex;

    iIndex = Objects->IndexOf(Sender);
    if (iIndex == -1)
        iIndex = ProcessAddObject(Sender);

    if ( ByKeyValue )
    {
        kKeyIndex = FindInList__(Fields,KeyField);
        if (kKeyIndex == -1)
            return NULL;
        jIndex = -1;
        for (int _i=0;_i<Objects->Count;_i++)
            for (int j0 = 0;j0<Nomenclature->Count;j0++)
                if ( Nomenclature->Items[j0] == Nom && *(Data->Items[_i]->Items[j0]->Items[kKeyIndex]) == KeyValue )
                {
                    jIndex = j0;
                    break;
                }
        if (jIndex == -1)
        {
            jIndex = ProcessAddNomenclature(Nom);
            *(Data->Items[iIndex]->Items[jIndex]->Items[kKeyIndex]) = KeyValue;
        }
    }
    else
    {
        jIndex = Nomenclature->IndexOf(Nom);
        if (jIndex == -1)
            jIndex = ProcessAddNomenclature(Nom);
    }

    kIndex = FindInList__(Fields,FieldName);
    if (kIndex==-1)
        return NULL;

    return Data->Items[iIndex]->Items[jIndex]->Items[kIndex];
}

bool TCounterBase::ProcessUpdateField(  TMyObject *Sender,
                                        TNomenclature * Nom,
                                        const AnsiString& FieldName,
                                        const AnsiString& NewData,
                                        bool Add)
{
    AnsiString EMPTY = AnsiString();
    AnsiString *Place = Iterate(Sender,Nom,FieldName,EMPTY,EMPTY,false);
    if (Place == NULL)
        return false;
    int kIndex = FindInList__(Fields,FieldName);
    if (Add)
    {
        Fields->Items[kIndex]->VALUE = *Place;
        Fields->Items[kIndex]->AddData(NewData);
    }
    else
        Fields->Items[kIndex]->VALUE = NewData;
    *Place = Fields->Items[kIndex]->VALUE;
    return true;
}

bool TCounterBase::ProcessUpdateFieldByValue(   TMyObject *Sender,
                                                TNomenclature * Nom,
                                                const AnsiString& FieldName,
                                                const AnsiString& NewData,
                                                bool Add,
                                                const AnsiString& KeyField,
                                                const AnsiString& KeyData)
{
    AnsiString EMPTY = AnsiString();
    AnsiString *Place = Iterate(Sender,Nom,FieldName,KeyField,KeyData,true);
    if (!Place)
        return false;
    int kIndex = FindInList__(Fields,FieldName);
    if (Add)
    {
        Fields->Items[kIndex]->VALUE = *Place;
        Fields->Items[kIndex]->AddData(NewData);
    }
    else
        Fields->Items[kIndex]->VALUE = NewData;
    *Place = Fields->Items[kIndex]->VALUE;
    return true;
}


AnsiString TEMP_FieldName;
AnsiString TEMP_Value;
AnsiString TEMP_KeyField;
AnsiString TEMP_KeyValue;
AnsiString TEMP_Meter;

void TCounterBase::DefineField(char *FieldName,int Type,char* _Meter,int Digits,bool Visible,bool Accumulate,bool Total)
{
    TEMP_FieldName = AnsiString(FieldName);
    TEMP_Meter = AnsiString(_Meter);
    ProcessAddField(TEMP_FieldName,Type,TEMP_Meter,Digits,Visible,Accumulate,Total);
}

bool TCounterBase::SetData(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* _Data)
{
    TEMP_FieldName = AnsiString(FieldName);
    TEMP_Value = AnsiString(_Data);
    return ProcessUpdateField(Sender,Nom,TEMP_FieldName,TEMP_Value,false);
}

bool TCounterBase::AddData(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* _Data)
{
    TEMP_FieldName = AnsiString(FieldName);
    TEMP_Value = AnsiString(_Data);
    return ProcessUpdateField(Sender,Nom,TEMP_FieldName,TEMP_Value,true);
}

bool TCounterBase::SetDataByValue(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* _Data,char* KeyField,char* KeyData)
{
    TEMP_FieldName = AnsiString(FieldName);
    TEMP_Value = AnsiString(_Data);
    TEMP_KeyField = AnsiString(KeyField);
    TEMP_KeyValue = AnsiString(KeyData);
    return ProcessUpdateFieldByValue(Sender,Nom,TEMP_FieldName,TEMP_Value,false,TEMP_KeyField,TEMP_KeyValue);
}

bool TCounterBase::AddDataByValue(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* _Data,char* KeyField,char* KeyData)
{
    TEMP_FieldName = AnsiString(FieldName);
    TEMP_Value = AnsiString(_Data);
    TEMP_KeyField = AnsiString(KeyField);
    TEMP_KeyValue = AnsiString(KeyData);
    return ProcessUpdateFieldByValue(Sender,Nom,TEMP_FieldName,TEMP_Value,true,TEMP_KeyField,TEMP_KeyValue);
}

bool TCounterBase::FieldExists(char *FieldName)
{
    TEMP_FieldName = AnsiString(FieldName).Trim().LowerCase();
    return (FindInList__(Fields,TEMP_FieldName)!=-1);
}

TQuerryNode::TQuerryNode(TQuerryNode* newParent,TCounterBase* _CB,TMetaNode* _Nom)
{
    BMP = new Graphics::TBitmap;
                        BMP->HandleType = bmDIB;
    CB = _CB;
    Nom = _Nom;
    index = -1;
    o_index = -1;
    FParent = NULL;
    Parent = newParent;
}

TQuerryNode::~TQuerryNode()
{
    Clear();
    Parent = NULL;
    delete BMP;
}

void TQuerryNode::SetParent(TQuerryNode* newParent)
{
    if (Parent == newParent)
        return;//т.к. динамические связки прыгают из конца в начало
    if (Parent)
        Parent->Childs.Remove(this);
    FParent = newParent;
    if (Parent)
        Parent->Childs.Add(this);
}

void TQuerryNode::Clear()
{
    while(Childs.Count)
        delete Childs.Last();
}

TQuerryNode* TQuerryNode::FindByMetaNode(TMetaNode* MN)
{
    if (MN == Nom)
        return this;
    for (int i=0;i<Childs.Count;i++)
    {
        TQuerryNode* QN = Childs[i].FindByMetaNode(MN);
        if ( QN )
            return QN;
    }
    return NULL;
}

void TQuerryNode::GoMultiply_1()
{
    if (Nom->ChildList->Count>0)
        for (int i=0;i<Nom->ChildList->Count;i++)
            (new TQuerryNode( this,CB,(TMetaNode*)Nom->ChildList->Items[i] ))->GoMultiply_1();
}

void TQuerryNode::ChildConnect_2()
{
    index=-1;
    if (Nom->ChildList->Count == 0)
    {
        TMDelTList<int> indices;
        for (int i=0;i<CB->vNom.Count;i++)
            if (CB->vNom.Items[i] == Nom)
                indices.Add(new int(i));
        if (indices.Count == 1)
            index = indices[0];
        else
            for (int i=0;i<indices.Count;i++)
                (new TQuerryNode(this,CB,(TMetaNode*)Nom))->index = indices[i];
    }
    else
        for (int i=0;i<Childs.Count;i++)
            Childs[i].ChildConnect_2();

}

void TQuerryNode::ChildConnect_2_5()
{
/*    if (Childs.Count == 0 && index!=-1)
    {
        o_index
    }   */
}

void TQuerryNode::CopyBMP_6()
{
    for (int i=0;i<Childs.Count;i++)
        Childs[i].CopyBMP_6();
    if ( Nom->Is(TNomenclature::StaticType) || Nom->Img1->Valid() )
        Nom->Img1->GetBitmap(BMP);
    else
        Nom->Img1->GetStandartBitmap(siFOLDER,BMP);
}

void TQuerryNode::TotalCheck_3()
{
    TMTList<TQuerryNode> COPY;
    COPY.Assign(&Childs);
    for (int i=0;i<COPY.Count;i++)
        COPY[i].TotalCheck_3();
    if (Childs.Count==0 && index == -1)
        delete this;
}
TMDelTList<AnsiString>& TQuerryNode::GetvData()
{
	return vData;
}

void TQuerryNode::DoQuerry_4()
{
    for (int i=0;i<Childs.Count;i++)
        Childs[i].DoQuerry_4();
    GetvData().Clear();
    if (index!=-1 && Childs.Count==0)
        for (int i=0;i<CB->vFields.Count;i++)
        {
            GetvData().Add( new AnsiString( CB->GetSum(-1,index,i,false) ) );
            if (EmptyVariant(GetvData()[i]))
            {
                CB->vFields[i].ToEmpty();
                GetvData()[i] = CB->vFields[i].VALUE;
            }
        }
    else
        for (int i=0;i<CB->vFields.Count;i++)
        {
            CB->vFields[i].VALUE = AnsiString("0");
            GetvData().Add( new AnsiString() );
            if (CB->vFieldExs[i].Accumulate)
                for (int j=0;j<Childs.Count;j++)
                    CB->vFields[i].AddData( Childs[j].GetvData()[i] );
            else
                for (int j=0;j<Childs.Count;j++)
                {
                    if (EmptyVariant( Childs[j].GetvData()[i] ))
                        continue;
                    if ( EmptyVariant(CB->vFields[i].VALUE) )
                        CB->vFields[i].VALUE = Childs[j].GetvData()[i];
                    else if (!CB->vFields[i].EqualTo(Childs[j].GetvData()[i],CB->vFieldExs[i].Digits))
                    {
                        CB->vFields[i].ToEmpty();
                        break;
                    }
                }
            GetvData()[i] = CB->vFields[i].VALUE;
        }
}

void TQuerryNode::Select(TMTList<TQuerryNode>& QNS,bool TreeView,bool AllDirectory)
{
    if (Childs.Count==1 && !AllDirectory && Childs[0].Childs.Count)
        Childs[0].Select(QNS,TreeView,AllDirectory);
    else
        for (int i=0;i<Childs.Count;i++)
        {
            QNS.Add(Childs.Items[i]);
            if (!TreeView)
                Childs[i].Select(QNS,TreeView,AllDirectory);
        }
}

AnsiString TQuerryNode::GetExcelValue(int index)
{
    CB->vFields[index].VALUE = GetvData()[index];
    if ( EmptyVariant( CB->vFields[index].VALUE ) )
        return AnsiString();
    else
        return (CB->vFields[index].ExcelValue( CB->vFieldExs[index].Digits )+ AnsiString(" ") + CB->vFieldExs[index].Meter.Trim());
}

AnsiString TQuerryNode::GetValue(int index)
{
    CB->vFields[index].VALUE = GetvData()[index];
    if ( EmptyVariant( CB->vFields[index].VALUE ) )
        return AnsiString();
    else
        return (CB->vFields[index].ValueRoundTo( CB->vFieldExs[index].Digits ) + AnsiString(" ") + CB->vFieldExs[index].Meter.Trim());
}

AnsiString TQuerryNode::GetValueNotRounded(int index)
{
    return GetvData()[index];
}


THierarchyQuerry::THierarchyQuerry(TCounterBase* _CB)
{
    CB = _CB;
    TMetaNode* NFParent=NULL;
    for (int i=0;i<MetaNodeCollection->Head->ChildList->Count;i++)
        if ( ((TMetaNode*)MetaNodeCollection->Head->ChildList->Items[i])->ChildType == cNomenclature)
            NFParent = (TMetaNode*)MetaNodeCollection->Head->ChildList->Items[i];
    Head = new TQuerryNode(NULL,CB,NFParent);
}

THierarchyQuerry::~THierarchyQuerry()
{
    delete Head;
}

void THierarchyQuerry::FullProcess()
{
    Head->Clear();
    Head->GoMultiply_1();
    Head->ChildConnect_2();
//    Head->TotalCheck_3();

    TMTList<TQuerryNode> COPY;
    COPY.Assign(&Head->Childs);
    for (int i=0;i<COPY.Count;i++)
        COPY[i].TotalCheck_3();

    Head->DoQuerry_4();
    Head->CopyBMP_6();
}

