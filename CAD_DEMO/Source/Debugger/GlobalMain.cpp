// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "GlobalMain.h"
#include "InspectorMain.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
 TGlobal::TGlobal(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
 TGlobal::~TGlobal()
{
    List->Free();
}
//---------------------------------------------------------------------------
void  TGlobal::ViewVars(TMDelTList<TLuaVariable>* Vars)
{
    TListItem *Item;
    List->Clear();

    List->Items->BeginUpdate();
    if (Vars->Count>0)
    {
        TLuaVariable *Current = Vars->First();
        for (int i=0;i<Vars->Count;i++)
        {
            Item=List->Items->Add();
            Item->Caption=Current->Name;
            Item->SubItems->Add(Current->Type);
            Item->SubItems->Add(Current->Value);
            Vars->Next();
            Current = Vars->GetCurrent();
        }
    }
    List->Items->EndUpdate();
}
//---------------------------------------------------------------------------

void  TGlobal::ListDblClick(TObject *Sender)
{
    TListItem *Item;
    //TLuaVariable *Var = new TLuaVariable;
    //bool Glob=(((TForm*)(((TListView*)(Sender))->Parent))->Caption=="Global variables");
    Item=((TListView*)(Sender))->ItemFocused;
    if (Item)
    {
        Inspect(Item->Caption);
        /*Var->Name=Item->Caption;
        Var->Type=Item->SubItems[0][0];
        if (Var->Type=="table")
        {
            TMDelTList<AnsiString> name;
            name.Add(new AnsiString(Var->Name));
            FileMap->Position=0;
            name.WriteData(FileMap);
            PostThreadMessage(ApplHnd,WM_USER,MSG_GONEXTBREAK,0);
            delete Var;
            return;
        }
        Var->Value=InputBox("Changing variable", "Input new value",Item->SubItems[0][1]);
        FileMap->Position=0;
        //filedat=fopen("Exchange.dat","w+");
        Var->WriteData(FileMap);
        //Var->SaveData(filedat);
        delete Var;
        //fclose(filedat);
        if ((ApplHnd)&&(Glob)) PostThreadMessage(ApplHnd,WM_USER,MSG_SETGLOBAL,0);
        if ((ApplHnd)&&(!Glob)) PostThreadMessage(ApplHnd,WM_USER,MSG_SETLOCAL,0);
        */
    }
}
//---------------------------------------------------------------------------


void  TGlobal::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action=caHide;
}
//---------------------------------------------------------------------------
void  TGlobal::WndProc(Messages::TMessage &Message)
{
    if ((Message.Msg==WM_USER)&&(Message.WParam==MSG_UPDATE))
        TGlobal::OnUpdate(this);
    TForm::WndProc(Message);
}
//---------------------------------------------------------------------------
void  TGlobal::Evaluate(TObject *Sender)
{
    //if (DebugMode!=DBGMODE_PAUSE) return;
    AnsiString Text;
    TListItem *Item = NULL;
    FileMap->Position=0;
    TMDelTList<AnsiString> Data;
    Data.Clear();
    if (List->Items->Count==0) return;
    for (int i=0;i<List->Items->Count;i++)
    {
        Text="";
        Item = List->Items->Item[i];
        if ((Item->Caption.Pos("return")==0)&&(Item->Caption.Pos('=')==0)) Text="return ";
        Text+=Item->Caption;
        if (Item->Caption[Item->Caption.Length()]!=';') Text+=';';
        Data.Add(new AnsiString(Text));
    }
    Data.WriteData(FileMap);
    PostThreadMessage(ApplHnd,WM_USER,MSG_EVALUATE,0);
}
//---------------------------------------------------------------------------
void  TGlobal::DelItemUpdate(TObject *Sender)
{
    ((TAction*)Sender)->Enabled=List->ItemFocused;
}
//---------------------------------------------------------------------------
void  TGlobal::EditItemUpdate(TObject *Sender)
{
    TListItem *Item = List->ItemFocused;
    ((TAction*)Sender)->Enabled=Item;
}
//---------------------------------------------------------------------------

void  TGlobal::ClearItemUpdate(TObject *Sender)
{
    ((TAction*)Sender)->Enabled=List->Items->Count>0;
}
//---------------------------------------------------------------------------
void  TGlobal::InspectItemUpdate(TObject *Sender)
{
    InspectItem->Enabled=List->ItemFocused;
}
//---------------------------------------------------------------------------

void  TGlobal::EditItemExecute(TObject *Sender)
{
    TListItem *Item = List->ItemFocused;
    if (!Item)
    {
        AddItemExecute(Sender);return;
    }
    AnsiString Code = InputBox("Enter watch","Enter watch:",Item->Caption);
    if (Code!="")
    {
        Item->Caption=Code;
        Item->SubItems[0].Text="{not avaible}";
        Evaluate(Sender);
    }
}
//---------------------------------------------------------------------------
void  TGlobal::DelItemExecute(TObject *Sender)
{
    TListItem *Item = List->ItemFocused;
    if (Item) Item->Delete();
}
//---------------------------------------------------------------------------
void  TGlobal::ClearItemExecute(TObject *Sender)
{
    List->Items->Clear();
}
//---------------------------------------------------------------------------
void  TGlobal::AddItemExecute(TObject *Sender)
{
    AnsiString Code = InputBox("Adding watch","Ââåäèòå watch:","");
    if (Code!="")
    {
        TListItem *Item = List->Items->Add();
        Item->Caption=Code;
        Item->SubItems->Add("{not available}");
        Evaluate(Sender);
    }
}
//---------------------------------------------------------------------------
void  TGlobal::InspectItemExecute(TObject *Sender)
{
    TListItem *Item = List->ItemFocused;
    Inspect(Item->Caption);
}
//---------------------------------------------------------------------------

void  TGlobal::ListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    TListItem *Item = List->ItemFocused;
    switch (Key)
    {
        case VK_RETURN:
        {
            if (Item) EditItemExecute(this);
            if (!Item) AddItemExecute(this);
        }break;
        case VK_DELETE:
        {
            if (Item) DelItemExecute(this);
        }break;
    }
}
//---------------------------------------------------------------------------

