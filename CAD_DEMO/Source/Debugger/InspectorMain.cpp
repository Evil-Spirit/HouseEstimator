//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "InspectorMain.h"
#include "syncobjs.hpp"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void Inspect(AnsiString Data, HANDLE hnd)
{
    TMDelTList<AnsiString> data;
    data.Clear();
    data.Add(new AnsiString(Data));
    FileMap->Position=0;
    data.WriteData(FileMap);
    if (!hnd)
    {
        TDbgInspector *Inspector = new TDbgInspector(Application);
        Inspector->Show();
        PostThreadMessage(ApplHnd,WM_USER,MSG_INSPECT,(int)Inspector->Handle);
    }
    else PostThreadMessage(ApplHnd,WM_USER,MSG_INSPECT,(int)hnd);

}

void __fastcall TDbgInspector::UpdateInspector(TObject *Sender)
{
    FileMap->Position=0;
    TMDelTList<TLuaVariable> Vars;
    Vars.Clear();
    Vars.ReadData(FileMap);
    AnsiString Caption=Vars.First()->Name;
    Vars.RealDelete(0);
    ShowProperty(Caption,&Vars);
    Vars.Clear();
}
//---------------------------------------------------------------------------
__fastcall TDbgInspector::TDbgInspector(TComponent* Owner)
    : TForm(Owner)
{
    AnsiString ColHeader="Name,Type,Value";
    DataWatch1->Rows[0]->CommaText=ColHeader;
    DataWatch2->Rows[0]->CommaText=ColHeader;
    OnUpdate=UpdateInspector;
}
//---------------------------------------------------------------------------
void __fastcall TDbgInspector::WndProc(Messages::TMessage &Message)
{
    if ((Message.Msg==WM_USER)&&(Message.WParam==MSG_UPDATE))
        TDbgInspector::OnUpdate(this);
    TForm::WndProc(Message);
}
//---------------------------------------------------------------------------
bool TDbgInspector::GetMethods()
{
    return Sheet2->TabVisible;
};
//---------------------------------------------------------------------------
void TDbgInspector::SetMethods(bool State)
{
    Sheet2->TabVisible=State;
};
//---------------------------------------------------------------------------
void __fastcall TDbgInspector::Clear()
{
    DataWatch1->RowCount=2;
    DataWatch1->Rows[2]->Clear();
    DataWatch2->RowCount=2;
    DataWatch2->Rows[2]->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TDbgInspector::ShowProperty(AnsiString Name,TMDelTList<TLuaVariable> *Vars)
{
    VariableName->Text=Name;
    Clear();
    if (Vars->Count>0)
    {
        TLuaVariable *Current = Vars->GetItem(0);
        for (int i=0;i<Vars->Count;i++)
        {
            if ((Current->Name.SubString(1,2)=="__")||(Current->Name[1]=='.'))
            {
                if (Current->Name.SubString(1,2)=="__")
                {
                    Vars->Next();
                    Current=Vars->Current;
                    continue;
                }
                DataWatch2->RowCount++;
                int Count=DataWatch2->RowCount-2;
                DataWatch2->Cells[0][Count] = Current->Name;
                DataWatch2->Cells[1][Count] = Current->Type;
                DataWatch2->Cells[2][Count] = Current->Value;
                if (Current->Name==".add") DataWatch2->Cells[0][Count]="operator +";
                if (Current->Name==".sub") DataWatch2->Cells[0][Count]="operator -";
                if (Current->Name==".mul") DataWatch2->Cells[0][Count]="operator *";
                if (Current->Name==".div") DataWatch2->Cells[0][Count]="operator /";
                if (Current->Name==".pow") DataWatch2->Cells[0][Count]="operator ^";
                if (Current->Name==".unm") DataWatch2->Cells[0][Count]="unary -";
                if (Current->Name==".concat") DataWatch2->Cells[0][Count]="operator ..";
                if (Current->Name==".eq") DataWatch2->Cells[0][Count]="operator =";
                if (Current->Name==".lt") DataWatch2->Cells[0][Count]="operator <";
                if (Current->Name==".le") DataWatch2->Cells[0][Count]="operator <=";
                if (Current->Name==".geti") DataWatch2->Cells[0][Count]="operator []";
                if (Current->Name==".seti") DataWatch2->Cells[0][Count]="operator []=";
                if (Current->Name==".gc") DataWatch2->Cells[0][Count]="destructor";
            }
            else
            {
                DataWatch1->RowCount++;
                int Count=DataWatch1->RowCount-2;
                DataWatch1->Cells[0][Count] = Current->Name;
                DataWatch1->Cells[1][Count] = Current->Type;
                DataWatch1->Cells[2][Count] = Current->Value;
            }
            Vars->Next();
            Current = Vars->GetCurrent();
        }
    }
    if (DataWatch2->RowCount>2)
    {
        IsMethods=true;
        DataWatch2->RowCount--;
    }
    if (DataWatch1->RowCount>2) DataWatch1->RowCount--;
    int myHeight = DataWatch1->RowCount*(DataWatch1->DefaultRowHeight+DataWatch1->GridLineWidth);
    int dH=Sheets->Height-Sheet1->Height+3;
    int dH1=this->Height-this->ClientHeight;

    if (myHeight< DataWatch1->ClientHeight-dH)
    {
        this->Height=VariableName->Height+myHeight+dH+dH1+StatusBar->Height;
        this->FormResize(this);
    }
    else if ((myHeight>this->Height)&&(this->Height<450))
    {
        this->Height=VariableName->Height+myHeight+dH+dH1+StatusBar->Height;
        this->FormResize(this);
    }
}

void __fastcall TDbgInspector::FormResize(TObject *Sender)
{
    VariableName->Width=ClientWidth;
    Sheets->Top=ClientRect.Top+VariableName->Height;
    Sheets->Height=ClientHeight-VariableName->Height-StatusBar->Height;
    Sheets->Width=ClientWidth;
    DataWatch1->ColWidths[2]=Sheets->ClientWidth-(DataWatch1->ColWidths[1]+DataWatch1->ColWidths[0]);
    DataWatch2->ColWidths[2]=Sheets->ClientWidth-(DataWatch2->ColWidths[1]+DataWatch2->ColWidths[0]);
    StatusBar->Width=ClientWidth;
    StatusBar->Top=ClientHeight-StatusBar->Height;
}
//---------------------------------------------------------------------------


void __fastcall TDbgInspector::DataWatch1DblClick(TObject *Sender)
{
    TStringGrid *Parent = (TStringGrid*)Sender;
    int Index=Parent->Selection.Top;
    if (Index==1) return;

    AnsiString Value;
    TMDelTList<AnsiString> Data;
    Data.Clear();
    AnsiString Text = VariableName->Text;
    AnsiString Type =Parent->Cells[1][Index];
    if ((Parent->Cells[0][Index]=="")||(Parent->Cells[0][Index]=="--None--")) return;
    Text+="."+Parent->Cells[0][Index];

    Data.Add(new AnsiString(Text));
    FileMap->Position=0;
    Data.WriteData(FileMap);
    TDbgInspector *Inspector = new TDbgInspector(this);
    Inspector->Show();
    PostThreadMessage(ApplHnd,WM_USER,MSG_INSPECT,(int)Inspector->Handle);

}
//---------------------------------------------------------------------------

void __fastcall TDbgInspector::VariableNameKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Key==VK_RETURN) Inspect(VariableName->Text,this->Handle);
}

void UpdateAllInspectors()
{
    TQuickList *Lst = new TQuickList();
    tagMSG Message;
    int Handled;
    SelectComponents(__classid(TDbgInspector),Lst);
    for (int i=0;i<Lst->Count;i++)
    {
        TDbgInspector *Inspector = (TDbgInspector*)Lst->Items[i];
        FileMap->Ready=false;
        Inspect(Inspector->VariableName->Text,Inspector->Handle);
        while (!FileMap->Ready)
        {
            PeekMessage(&Message,NULL,WM_USER,WM_USER,PM_NOREMOVE);
        };
    }
    delete Lst;
}
//---------------------------------------------------------------------------


void __fastcall TDbgInspector::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action=caFree;    
}
//---------------------------------------------------------------------------

