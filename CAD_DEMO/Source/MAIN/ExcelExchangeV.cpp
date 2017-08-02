//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ExcelExchangeV.h"
#include "MetaNodeCollectionV.h"
#include <utilcls.h>
#include "Main.h"
#include "AddLuaVarV.h"
#include "CounterBaseV.h"      
#include "QuckList.h"
#include "MDICountReportV.h"
#include "NomenclatureV.h"
#include "LuaAttributeV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExcelExchange *ExcelExchange;
//---------------------------------------------------------------------------
__fastcall TExcelExchange::TExcelExchange(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

const int HAlignLeft = -1;     //0xFFFFEFDD
const int HAlignRight = 1;     //0xFFFFEFC8
const int HAlignCenter = 0;    //0xFFFFEFF4

void CellStyle(Variant& v2,int HorAlign,bool Border, int FontSize,bool FontBold)
{
    v2.OlePropertySet("VerticalAlignment", ((int)0xFFFFEFF4) );
    if (HorAlign == HAlignLeft)
        v2.OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFDD) );
    else if (HorAlign == HAlignRight)
        v2.OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFC8) );
    else
        v2.OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFF4) );

    v2.OlePropertyGet("Font").OlePropertySet("Size",FontSize);
    v2.OlePropertyGet("Font").OlePropertySet("Bold",FontBold);
    if (Border)
    {
        v2.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
        v2.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
        v2.OlePropertyGet("Borders",7).OlePropertySet("LineStyle",1);
        v2.OlePropertyGet("Borders",7).OlePropertySet("Weight",2);
        v2.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
        v2.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
        v2.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
        v2.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);
    }
}

int FindInListAnsi(TMDelTList<AnsiString>* List,const AnsiString& Value)
{
    for (int i=0;i<List->Count;i++)
        if ( *(List->Items[i]) == Value )
            return i;
    return -1;
}

AnsiString StringField(TMyObject*Obj,const AnsiString& FieldName)
{
    if (Obj->GetFieldIndex(FieldName)!=-1)
    {
        if ( Obj->GetFieldType(FieldName) == mtIntVec)
            return VecToStrFormat( *((TIntVec*)Obj->GetFieldAddress(FieldName)) );
        else
            return TYPETOSTR(Obj->GetFieldAddress(FieldName),Obj->GetFieldType(FieldName));
    }
    else
        return AnsiString();
}

AnsiString GetLastField(TMyObject*Obj,const AnsiString& FieldName,int index)
{
    AnsiString Result;
    TStringList* SL = new TStringList();
    SL->Delimiter = '.';
    SL->DelimitedText = FieldName;
    if (SL->Count>1)
        Result = SL->Strings[SL->CommaText-1];
    delete SL;
    return Result;
}

int FindAttribute(TMyRegObject* Obj,const AnsiString& _Name)
{
    for (int i=0;i<Obj->Attributes->Count;i++)
        if (_Name.Trim().LowerCase() == Obj->Attributes->Items[i]->Name.Trim().LowerCase())
            return i;
    return -1;
}

void ExcelExport(TMetaNode* MN,bool All,const AnsiString& FileName)
{
    Variant XL,v0,v1,v2,v3;
    _TRY_
            XL=CreateOleObject("Excel.Application");

            v0=XL.OlePropertyGet("Workbooks");
            v1=v0.OleFunction("Add");
            v0=v1.OlePropertyGet("Worksheets") ;
            AnsiString WSCaption = AnsiString("Unload ")+MN->Name;
            if (All)
                WSCaption = WSCaption + AnsiString(" and belong to");
            v1=v0.OlePropertyGet("Item",1);


            TMTList<AnsiString> Fields;
            TMTList<TMyRegObject> LST;
            if (All)
                MetaNodeCollection->SelectByCT(MN,TMetaNode::StaticType,&LST,true,true);
            else
                LST.Add(MN);
            for (int i=0;i<LST.Count;i++)
                for (int j=0;j<LST[i].GetFieldCount();j++)
                    if (LST[i].GetFieldType(j)!=mtMyObject && Fields.IndexOf(LST[i].GetFieldName(j))==-1)
                        Fields.Add( (AnsiString*) LST[i].GetFieldName(j));

            int FieldCount = Fields.Count;
            TMDelTList<AnsiString> AttrNames;
            for (int i=0;i<LST.Count;i++)
                for (int j=0;j<LST[i].Attributes->Count;j++)
                {
                    int IndexInListAnsi=FindInListAnsi(&AttrNames,LST[i].Attributes->Items[j]->Name);
                    if ( IndexInListAnsi==-1 )
                    {
                        IndexInListAnsi = AttrNames.Add(new AnsiString(LST[i].Attributes->Items[j]->Name));
                        Fields.Add(AttrNames.Items[IndexInListAnsi]);
                    }
                }

            //Шапка
            for (int i=0;i<Fields.Count;i++)
            {
                    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,i+1);
                    v2.OlePropertySet("Value",Fields[i].c_str());

                    v2.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
                    v2.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
                    v2.OlePropertyGet("Borders",7).OlePropertySet("LineStyle",1);
                    v2.OlePropertyGet("Borders",7).OlePropertySet("Weight",2);
                    v2.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
                    v2.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
                    v2.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
                    v2.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);
            }
            int rowshift = 1;
            StartProcess("Экспорт данных в Excel...",Fields.Count);
            for (int i=0;i<FieldCount;i++)
            {
                CountProcess(Fields[i],1);
                int MaxSymbolCount = Fields[i].Length();
                int MinSymbolCount = MaxSymbolCount;
                for (int j=0;j<LST.Count;j++)
                {
                    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",j+rowshift+1,i+1);
                    if (typeid(LST[j])==typeid(TMetaNode))
                    {
                        v2.OlePropertyGet("Interior").OlePropertySet("ColorIndex",37);
                        CellStyle(v2,HAlignCenter,true,10,false);
                    }
                    AnsiString Value;
                    if (LST[j].GetFieldIndex(Fields[i])!=-1)
                    {
                        if ( LST[j].GetFieldType(Fields[i]) == mtIntVec)
                            Value = VecToStrFormat( *((TIntVec*)LST[j].GetFieldAddress(Fields[i])) );
                        else
                            Value = LST[j].GetExcelStrField(LST[j].GetFieldIndex(Fields[i]));
                        v2.OlePropertySet("Value", Value.c_str() );
                        if (Value.Length()>MaxSymbolCount)
                            MaxSymbolCount = Value.Length();
                        else if (Value.Length()<MinSymbolCount)
                            MinSymbolCount = Value.Length();
                    }
                }
            }

            for (int i=FieldCount;i<Fields.Count;i++)
            {
                CountProcess(Fields[i],1);
//                int MaxSymbolCount = Fields[i].Length();
//                int MinSymbolCount = MaxSymbolCount;
                for (int j=0;j<LST.Count;j++)
                {
                    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",j+rowshift+1,i+1);
                    if (typeid(LST[j])==typeid(TMetaNode))
                    {
                        v2.OlePropertyGet("Interior").OlePropertySet("ColorIndex",37);
                        CellStyle(v2,HAlignCenter,true,10,false);
                    }
                    int index = FindAttribute(&LST[j],Fields[i]);
                    if (index!=-1)
                        v2.OlePropertySet("Value",LST[j].Attributes->Items[index]->ExcelValue(-5).c_str());
                }
            }

            XL.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
            XL.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",FileName.c_str());
            XL.OleProcedure("Quit");
            XL=CreateOleObject("Excel.Application");
            v0=XL.OlePropertyGet("Workbooks");
            v0.OleProcedure("Add",FileName.c_str());
            XL.OlePropertySet("Visible",true);

    _ENDTRY_("<ExcelExport>: Экспорт не был завершен",);

    XL = Unassigned;
    v0 = Unassigned;
    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;
}

int FindAttribute(const AnsiString& Name,int type,TMetaNode* MN,bool Create)
{
    AnsiString _Name = Name.Trim().LowerCase();
    for (int i=0;i<MN->Attributes->Count;i++)
        if (_Name.Trim().LowerCase() == MN->Attributes->Items[i]->Name.Trim().LowerCase() )
        {
            if (MN->Attributes->Items[i]->Type!=type)
            {
                AnsiString STR = AnsiString("Invalid type <") + StrTypes[MN->Attributes->Items[i]->Type]+
                AnsiString("> of attribute <")+Name+AnsiString("> object <")+
                MN->Name+AnsiString(">. Fixed.");
                StdOut(STR);
                MN->Attributes->Items[i]->Type=type;
            }
            return i;
        }
    if (Create)
    {
        if (!VariantNameOK(Name))
        {
            StdOut(AnsiString("Invalid attribute name")+Name+AnsiString(". Can not create attribute."));
            return -1;
        }
        int res = MN->Attributes->Add(new TLuaAttribute());
        TLuaAttribute* L = MN->Attributes->Items[res];
        L->ReadOnly = false;
        L->Name = Name;
        L->Type = type;
            AnsiString STR = AnsiString("Attribute: type <")+Name+AnsiString("> object <")+
            MN->Name+AnsiString(">.");
            StdOut(STR);
//        L->VALUE = LI->SubItems->Strings[1];
        L->Description = AnsiString("Created on import ")+TDateTime().CurrentDate().DateString();
        L->Meter = "None.";
        L->ReadOnly = true;
        return res;
    }
    return -1;
}

void ExcelImport(const AnsiString& FileName)
{

    Variant XL,v0,v1,v2,v3;
    _TRY_

        XL=CreateOleObject("Excel.Application");
        v0=XL.OlePropertyGet("Workbooks");
        v0.OleProcedure("Open",FileName.c_str());
        v1=v0.OlePropertyGet("Item",v0.OlePropertyGet("Count"));
        v0=v1.OlePropertyGet("Worksheets") ;
        v1=v0.OlePropertyGet("Item",1);
        TMDelTList<AnsiString> Fields;

        bool NotEmpty = true;
        int index=1;
        int GUIDField=-1;
        int NameField = -1;
        while (NotEmpty)
        {
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,index);
            AnsiString Str = AnsiString(v2.OlePropertyGet("Value")).Trim();
            NotEmpty = !Str.IsEmpty();
            if (NotEmpty)
                Fields.Add(new AnsiString(Str));
            index++;
        }
        TMDelTList<int> Types;
        TExcelExchange* EE = new TExcelExchange(Application);
        for (int i=0;i<Fields.Count;i++)
        {
            Types.Add(new int(2));
            EE->LV->Items->Add()->Caption = Fields[i];
            EE->LV->Items->Item[i]->Checked=false;
            EE->LV->Items->Item[i]->Data = Types.Items[i];
            EE->LV->Items->Item[i]->SubItems->Add(StrTypes[Types[i]]);
        }
        EE->ShowModal();
        TMDelTList<bool> Checked;
        bool CreateAttributes = EE->cbCreateAttributes->Checked;
        bool JustText = EE->cbText->Checked;
        for (int i=0;i<Fields.Count;i++)
            if (Fields[i].AnsiCompareIC(AnsiString("GUID"))==0)
            {
                Checked.Add(new bool(true));
                GUIDField = i;
            }
            else if (Fields[i].AnsiCompareIC(AnsiString("Name"))==0)
            {
                NameField = i;
                Checked.Add(new bool(EE->LV->Items->Item[i]->Checked));
            }
            else
                Checked.Add(new bool(EE->LV->Items->Item[i]->Checked));
        delete EE;

        if (GUIDField == -1 || NameField==-1 )
            throw EMyException("Не найдено поле \"GUID\" или \"Name\". Импорт прерван.");
        StartProcess("Анализ рабочей книги...",100);
        bool NotEmptyString = true;
        int index_2=2;
        while (NotEmptyString)
        {
            CountProcess("",0);
            NotEmptyString = false;
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",index_2,GUIDField+1);
            AnsiString GUID = AnsiString(v2.OlePropertyGet("Text")).Trim();
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",index_2,NameField+1);
            AnsiString _Name = AnsiString(v2.OlePropertyGet("Text")).Trim();
            if ( !GUID.IsEmpty() && !_Name.IsEmpty())
                NotEmptyString = true;
            index_2++;
        }
        int StrCount = index_2-1;
        StartProcess("Прием данных ...",StrCount-1);
        for (int s=2;s<StrCount;s++)
        {
            TMDelTList<AnsiString> Data;
            for (int i=0;i<Fields.Count;i++)
            {
                v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",s,i+1);
                Data.Add(new AnsiString());
                if (JustText)
                    Data[i] = AnsiString(v2.OlePropertyGet("Text")).Trim();
                else
                    Data[i] = AnsiString(v2.OlePropertyGet("Value")).Trim();
            }
            CountProcess(Data[NameField],1);
            //---------------------------------------------------------------------
            _TRY_
            //---------------------------------------------------------------------
                AnsiString GUID = Data[GUIDField].Trim();
                TMetaNode* MN = (TMetaNode*)TMetaNode::StaticType->RecurrentFindByGUID(GUID);
                for (int i=0;i<Fields.Count;i++)
                {
                    if (i == GUIDField)
                        continue;
                    if (Checked[i]==false || Data[i].IsEmpty())
                        continue;
                    int FieldIndex = MN->GetFieldIndex(Fields[i]);
                    if (FieldIndex!=-1)
                    {
                        CopyType(MN->GetFieldType(FieldIndex),MN->GetFieldAddress(FieldIndex),STRTOTYPE(Data[i],MN->GetFieldType(FieldIndex)));
                    }
                    else
                    {
                        int res = FindAttribute(Fields[i],Types[i],MN,CreateAttributes);
                        if (res!=-1)
                        {
                            MN->Attributes->Items[res]->ReadOnly = false;
                            MN->Attributes->Items[res]->VALUE = Data[i];
                            MN->Attributes->Items[res]->ReadOnly = true;
                        }
                    }
                }
                if (MN && !MN->CheckFields())
                {
                    throw EMyException(AnsiString("Error on check fields link ")+Data[NameField]);
                }
                StdOut(Data[NameField]+AnsiString(" - OK!"));
            _ENDTRY_(AnsiString("<ExcelImport>: Error on check fields link ")+Data[NameField],)
            //---------------------------------------------------------------------
        }
        InfoMsg("Import done!");

    _ENDTRY_("<ExcelImport>: Import not finished",);
/*    if (XL!=Unassigned)
    {
        XL.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
        XL.OleProcedure("Quit");
    }   */
    XL = Unassigned;
    v0 = Unassigned;
    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;
}
void __fastcall TExcelExchange::btOKClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------


void __fastcall TExcelExchange::LVClick(TObject *Sender)
{
    if (LV->Selected)
    {
        cbType->Enabled = true;
        cbType->ItemIndex = *((int*)LV->Selected->Data);
    }
    else
        cbType->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TExcelExchange::cbTypeCloseUp(TObject *Sender)
{
    if (LV->Selected)
    {
        *((int*)LV->Selected->Data) = cbType->ItemIndex;
        LV->Selected->SubItems->Strings[0] = StrTypes[cbType->ItemIndex];
    }
}


//---------------------------------------------------------------------------
AnsiString DecodeHM(const TDateTime& DT)
{
    unsigned short h,m,s,ms;
    int days = DT.operator int();
    DT.DecodeTime(&h,&m,&s,&ms);
    h = h + days*24;
    return (IntToStr(h)+AnsiString("ч.")+IntToStr(m))+AnsiString("м.");
}

int OneAct(Variant& Sheet,int RowCount,TMTList<TQuerryNode>& QNS)
{
    Variant v1,v2,v3;
    int ColCount = 7;
    int Start = RowCount+1;
    int Current = Start + 1 + 1 + 1;
    _TRY_

        v1 = Sheet;
        //заголовок
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Start,1);
        AnsiString Str = MSG_8;
        v2.OlePropertySet("Value",Str.c_str());
        v2.OlePropertyGet("Font").OlePropertySet("Name","Times New Roman");
        v1.OlePropertyGet("Rows",Start).OlePropertySet("RowHeight",60 );
        v2.OlePropertySet("WrapText", true );
        CellStyle(v2,HAlignCenter,false,18,false);
        v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Start,ColCount);
        v1.OlePropertyGet("Range",v2,v3).OleFunction("Merge",false);

        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Start+1,1);
        v2.OlePropertySet("Value",QNS[0].Parent->Nom->Description.c_str());
        v2.OlePropertyGet("Font").OlePropertySet("Name","Times New Roman");
        v1.OlePropertyGet("Rows",Start+1).OlePropertySet("RowHeight",16 );
        CellStyle(v2,HAlignCenter,false,10,false);
        v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Start+1,ColCount);
        v1.OlePropertyGet("Range",v2,v3).OleFunction("Merge",false);

        //шапка
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,1);
        v2.OlePropertySet("Value","Brigade ________________");
        CellStyle(v2,HAlignLeft,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,ColCount);
        v2.OlePropertySet("Value","Team-leader ________________");
        CellStyle(v2,HAlignRight,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,1);
        v2.OlePropertySet("Value","Starting date and time _________________________");
        CellStyle(v2,HAlignLeft,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+2,1);
        v2.OlePropertySet("Value","Place ___________________________");
        CellStyle(v2,HAlignLeft,false,10,false);
        //--------------------------------------------------------------------------
        Current = Current + 3 + 1;
        //строковая часть
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,1);
        v2.OlePropertySet("Value","Name of work");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,2);
        v2.OlePropertySet("Value","Value");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,3);
        v2.OlePropertySet("Value","unit");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,4);
        v2.OlePropertySet("Value","з. ч.ч.");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,5);
        v2.OlePropertySet("Value","Time");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,6);
        v2.OlePropertySet("Value","ф. ч.ч.");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,7);
        v2.OlePropertySet("Value","Pay");
        CellStyle(v2,HAlignCenter,true,10,true);
        //--------------------------------------------------------------------------
        double TotalMoney = 0;
        for (int i=0;i<QNS.Count;i++)
        {
            if ( !QNS[i].Nom->Is(TNomenclature::StaticType) )
                continue;
            Current++;
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,1);
            v2.OlePropertySet("Value",(QNS[i].Nom->Description+AnsiString(" ")+QNS[i].GetExcelValue(0)).c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,2);
            v2.OlePropertySet("Value",QNS[i].GetExcelValue(1).c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,3);
            v2.OlePropertySet("Value",QNS[i].GetExcelValue(2).c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,4);
            v2.OlePropertySet("Value",QNS[i].GetExcelValue(4).c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
            //v2.OlePropertySet("NumberFormat","h:mm;@");
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,5);
            v2.OlePropertySet("Value",QNS[i].GetExcelValue(5).c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,6);
            CellStyle(v2,HAlignCenter,true,10,false);
            //--------------------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,7);
            double Money = TO_DOUBLE(QNS[i].GetValueNotRounded(8));
            TotalMoney += Money;
            Str = Format("%.2f", ARRAYOFCONST( (Money*0.8) ) );
            v2.OlePropertySet("Value",Str.c_str());
            CellStyle(v2,HAlignCenter,true,10,false);
        }
        //итого
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,1);
        v2.OlePropertySet("Value","Total");
        CellStyle(v2,HAlignCenter,true,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,4);
        v2.OlePropertySet("Value",QNS[0].Parent->GetExcelValue(4).c_str());
        CellStyle(v2,HAlignCenter,true,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,5);
        v2.OlePropertySet("Value",QNS[0].Parent->GetExcelValue(5).c_str());
        CellStyle(v2,HAlignCenter,true,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,6);
        CellStyle(v2,HAlignCenter,true,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,7);
        Str = Format("%.2f", ARRAYOFCONST( (TotalMoney*0.8) ) );
        v2.OlePropertySet("Value",Str.c_str());
        CellStyle(v2,HAlignCenter,true,10,false);
        //--------------------------------------------------------------------------
        //подвал
        Current+=3;
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,1);
        v2.OlePropertySet("Value","Finished Date and Time _________________________");
        CellStyle(v2,HAlignLeft,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,ColCount);
        Str = Format("Premium %.2f р.", ARRAYOFCONST( (TotalMoney*0.2) ) );
        v2.OlePropertySet("Value",Str.c_str());
        CellStyle(v2,HAlignRight,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,1);
        v2.OlePropertySet("Value","Foreman ________________");
        CellStyle(v2,HAlignLeft,false,10,false);
        //--------------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current+1,ColCount);
        v2.OlePropertySet("Value","Team-leader ________________");
        CellStyle(v2,HAlignRight,false,10,false);
        //--------------------------------------------------------------------------
        Current = Current+3;
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,1);
        v2.OlePropertySet("Value","для аттестации бригады по нормам выполнения работ по системе");
        CellStyle(v2,HAlignCenter,false,8,false);
        v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Current,ColCount);
        v1.OlePropertyGet("Range",v2,v3).OleFunction("Merge",false);
        v1.OlePropertyGet("Rows",Current+1).OlePropertySet("PageBreak",(int)0xFFFFEFD9);
        for (int i=Start + 1;i<=Current;i++)
            v1.OlePropertyGet("Rows",i).OlePropertySet("RowHeight",16 );
    _ENDTRY_("<OneAct>: Creation of act not finished",);

    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;
    return Current;

}
//---------------------------------------------------------------------------


void Graphic( Variant& XL,const Variant& Sheet,TMTList<TQuerryNode>& QNL)
{
    Variant v1 = Sheet;
    Variant v2;
    Variant v3;
    _TRY_

        v1.OlePropertySet("Name","Line graph");
        v1.OlePropertyGet("Columns",1).OlePropertySet("ColumnWidth",20);
        v1.OlePropertyGet("Columns",2).OlePropertySet("ColumnWidth",2);
        int ColWidth = v1.OlePropertyGet("Columns",3).OlePropertyGet("Left") - v1.OlePropertyGet("Columns",2).OlePropertyGet("Left");
        int HourInColumn=24;
        double HourLen = double(ColWidth)/double(HourInColumn);

        int curcount = 3;
        v1.OlePropertyGet("Columns",2).OlePropertySet("ColumnWidth",12);
        v1.OlePropertyGet("Columns",3).OlePropertySet("ColumnWidth",12);
        v1.OlePropertyGet("Columns",4).OlePropertySet("ColumnWidth",12);
        double curpos = v1.OlePropertyGet("Columns",5).OlePropertyGet("Left");
        double totaltime= (TO_DOUBLE(QNL[0].Parent->GetValueNotRounded(5)));
        double totalpoint = totaltime* (HourLen*24);
        int col=5;
        while (v1.OlePropertyGet("Columns",col).OlePropertyGet("Left")<totalpoint+curpos)
        {
            v1.OlePropertyGet("Columns",col).OlePropertySet("ColumnWidth",2);
            col++;
        }
        //------------------------------------------------------------------
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,1);
        AnsiString Str = AnsiString("Line graph building");
        v2.OlePropertySet("Value",Str.c_str());
        v2.OlePropertyGet("Font").OlePropertySet("Name","Times New Roman");
        v1.OlePropertyGet("Rows",1).OlePropertySet("RowHeight",60 );
        v1.OlePropertyGet("Rows",3).OlePropertySet("RowHeight",30 );
        v2.OlePropertySet("WrapText", true );
        CellStyle(v2,HAlignCenter,false,18,false);
        v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,col-1);
        v1.OlePropertyGet("Range",v2,v3).OleFunction("Merge",false);
        v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,2);
        v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,4);
        v1.OlePropertyGet("Range",v2,v3).OlePropertyGet("Columns").OleFunction("Group");

            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,1);
            v2.OlePropertySet("Value","Name");
            CellStyle(v2,HAlignCenter,false,8,true);
            v2.OlePropertySet("WrapText",true);
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,2);
            v2.OlePropertySet("Value","Трудовы Ресурсы");
            CellStyle(v2,HAlignCenter,false,8,true);
            v2.OlePropertySet("WrapText",true);
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,3);
            v2.OlePropertySet("Value","Механизмы");
            CellStyle(v2,HAlignCenter,false,8,true);
            v2.OlePropertySet("WrapText",true);
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,4);
            v2.OlePropertySet("Value","Tools");
            CellStyle(v2,HAlignCenter,false,8,true);
            v2.OlePropertySet("WrapText",true);

        //------------------------------------------------------------------
        for (int i=0;i<QNL.Count;i++)
        {
            TMTList<TQuerryNode> qnr;
            QNL[i].Select(qnr,true,false);
            for (int j=0;j<qnr.Count;j++)
                if ( !qnr[j].Nom->Is(TNomenclature::StaticType) )
                    qnr.Delete(j--);
            if (qnr.Count==0)
                QNL.Delete(i--);
        }
        for (int i=1;i<=QNL.Count;i++)
            v1.OlePropertyGet("Rows",i+curcount).OlePropertySet("RowHeight",60 );

        StartProcess("Создание линейного графика...",QNL.Count*10);
        v1.OleProcedure("Select");
        for (int i=0;i<QNL.Count;i++)
        {
            CountProcess(QNL[i].Nom->Description,10);


            curcount++;
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,1);
            v2.OlePropertySet("Value",QNL[i].Nom->Description.c_str());
            CellStyle(v2,HAlignCenter,false,10,true);
            v2.OlePropertySet("WrapText",true);

            char* PeopleStr= QNL[i].Nom->GetAttributeValue("peoples");
            char* VehicleStr= QNL[i].Nom->GetAttributeValue("vehicles");
            char* ToolStr= QNL[i].Nom->GetAttributeValue("tools");

            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,2);
            if (PeopleStr)
                v2.OlePropertySet("Value",PeopleStr);
            CellStyle(v2,HAlignCenter,false,8,false);
            v2.OlePropertySet("WrapText",true);
            //--------------------------------------------------------------
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,3);
            if (VehicleStr)
                v2.OlePropertySet("Value",VehicleStr);
            CellStyle(v2,HAlignCenter,false,8,false);
            v2.OlePropertySet("WrapText",true);

            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,4);
            if (ToolStr)
                v2.OlePropertySet("Value",ToolStr);
            CellStyle(v2,HAlignCenter,false,8,false);
            v2.OlePropertySet("WrapText",true);

            double time = (TO_DOUBLE(QNL[i].GetValueNotRounded(5)));
            double curlen = time* (HourLen*24);

            v1.OlePropertyGet("Shapes").OleProcedure("AddShape",1, curpos, v2.OlePropertyGet("Top")+2, curlen, 60-4);
            int shcount = v1.OlePropertyGet("Shapes").OlePropertyGet("Count");
            v2 = v1.OlePropertyGet("Shapes").OleFunction("Item",shcount);
            v2.OleProcedure("Select");
            XL.OlePropertyGet("Selection").OlePropertyGet("Characters").OlePropertySet("Text",QNL[i].GetExcelValue(5).c_str());
            XL.OlePropertyGet("Selection").OlePropertySet("VerticalAlignment",((int)0xFFFFEFF4));
            XL.OlePropertyGet("Selection").OlePropertySet("HorizontalAlignment",((int)0xFFFFEFF4));

            v2.OlePropertyGet("Fill").OlePropertyGet("ForeColor").OlePropertySet("SchemeColor",44);
            curpos = curpos + curlen;
        }
    _ENDTRY_("<Graphic>: Ошибка при создании графика",);
    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;
}

void Act(const AnsiString& FileName)
{
/*    TQuickList L;
    SelectComponents(__classid(TMDICountReport),&L);
    TMDICountReport* mdicr = NULL;
    for (int i=0;i<L.Count;i++)
        if ( ((TMDICountReport*)L.Items[i])->CB->CountMode == PaymentCount )
        {
            mdicr = ((TMDICountReport*)L.Items[i]);
            break;
        }
    TMetaNode* MN = MetaNodeCollection->FindMDByID(1569);
    if (!mdicr || !MN || !mdicr->QNParent)
        return;

    TQuerryNode* QN = mdicr->HQ->Head->FindByMetaNode(MN);
    TMTList<TQuerryNode> QNL;
    QN->Select(QNL,false,false);
    for (int i=0;i<QNL.Count;i++)
        if ( typeid(*(QNL[i].Nom)) != typeid(TMetaNode) )
            QNL.Delete(i--);

    if (QNL.Count==0)
        return;
    Variant XL,v0,v1,v2,v3;
    try
    {
        try
        {
            XL=CreateOleObject("Excel.Application");
            v0=XL.OlePropertyGet("Workbooks");
            v1=v0.OleFunction("Add");
            v0=v1.OlePropertyGet("Worksheets") ;
            v1=v0.OlePropertyGet("Item",1);
            v1.OlePropertySet("Name","Акты соответствия");

            int curcount = 0;
            StartProcess("Создание актов соответствия...",10*QNL.Count);
            for (int i=0;i<QNL.Count;i++)
            {
                curcount++;
                v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,1);
                v2.OlePropertySet("Value","Demo");
                CellStyle(v2,HAlignLeft,false,8,false);
                v2.OlePropertyGet("Font").OlePropertySet("Color",RGB(128,128,128));

                v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",curcount,6);
                v2.OlePropertySet("Value",(AnsiString("страница ")+IntToStr(i+1)+AnsiString(" из ")+IntToStr(QNL.Count) ).c_str());
                CellStyle(v2,HAlignRight,false,8,false);
                v2.OlePropertyGet("Font").OlePropertySet("Color",RGB(128,128,128));
                v1.OlePropertyGet("Rows",curcount).OlePropertySet("RowHeight",12);

                CountProcess(QNL[i].Nom->Description,10);
                TMTList<TQuerryNode> qnr;
                QNL[i].Select(qnr,true,false);
                for (int j=0;j<qnr.Count;j++)
                    if ( !qnr[j].Nom->Is(TNomenclature::StaticType) )
                        qnr.Delete(j--);
                if (qnr.Count>0)
                   curcount = OneAct(v1,curcount,qnr);
            }

            v1.OlePropertyGet("Columns",1).OlePropertySet("ColumnWidth", 55);
            v1.OlePropertyGet("Columns",2).OlePropertySet("ColumnWidth", 9.5);
            v1.OlePropertyGet("Columns",3).OlePropertySet("ColumnWidth", 4);
            v1.OlePropertyGet("Columns",4).OlePropertySet("ColumnWidth", 6);
            v1.OlePropertyGet("Columns",5).OlePropertySet("ColumnWidth", 6);
            v1.OlePropertyGet("Columns",6).OlePropertySet("ColumnWidth", 6);
            v1.OlePropertyGet("Columns",7).OlePropertySet("ColumnWidth", 8);

            if (v1.OlePropertyGet("VPageBreaks").OlePropertyGet("Item",1).OlePropertyGet("Location").OlePropertyGet("Column")<8)
            {
                XL.OlePropertySet("Visible",true);
                Variant Window = XL.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OlePropertyGet("Windows").OlePropertyGet("Item",1);
                Window.OlePropertySet("View",2);
                v1.OlePropertyGet("VPageBreaks").OlePropertyGet("Item",1).OleProcedure("DragOff",(int)0xFFFFEFBF,1);
            }
            
            v1 = v0.OlePropertyGet("Item",2);
            Graphic(XL,v1,QNL);

            XL.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
            XL.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",FileName.c_str());
            XL.OleProcedure("Quit");
            
            XL=CreateOleObject("Excel.Application");
            v0=XL.OlePropertyGet("Workbooks");
            v0.OleProcedure("Add",FileName.c_str());
            XL.OlePropertySet("Visible",true);
        }
        __except(EXCEPTION_EXECUTE_HANDLER)
        {
            throw EMyException("Error");
        }
    }
    catch(EMyException)
    {
        ErrorMsg("Error");
    }

    XL = Unassigned;
    v0 = Unassigned;
    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;  */
}

