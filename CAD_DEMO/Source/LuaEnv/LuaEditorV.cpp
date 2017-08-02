 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop


#include "VCLSCILEXERV.h"
#include "LuaEditorV.h"
#include "LuaModuleV.h"
#include "LuaEnvV.h"
#include "InspectorMain.h"
#include "BaseVariableFormV.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLuaEditor *FLuaEditor;
//---------------------------------------------------------------------------

TFLuaEditor::TFLuaEditor(TComponent* Owner,TWinControl* _Parent,TLuaModule *_Module,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Module,Text,Data)
{
}

TLuaModule* TFLuaEditor::GetModule()
{
    return (TLuaModule*)Obj;
}


void TFLuaEditor::Refresh()
{
    SciLexer->Text = Module->CODE;
    SciLexer->SendEditor(SCI_CANCEL);
    for (int i=0;i<Module->BreakPoints.Count;i++)
    {
        SciLexer->SendEditor(SCI_MARKERADD,*Module->BreakPoints.GetItem(i),1);
        SciLexer->SendEditor(SCI_MARKERADD,*Module->BreakPoints.GetItem(i),2);
    }
}

void TFLuaEditor::Apply()
{
    Module->CODE = SciLexer->Text;
    Module->CheckFields();
}

//---------------------------------------------------------------------------
void __fastcall TFLuaEditor::Notify(TSciLexer* SciLexer,SCNotification *notification)
{
	switch (notification->nmhdr.code)
    {
        case SCN_MARGINCLICK:      
        {
            int Line = SciLexer->SendEditor(SCI_LINEFROMPOSITION,notification->position);
            int Marked = SciLexer->SendEditor(SCI_MARKERGET,Line);
            if ((SciLexer->SendEditor(SCI_LINELENGTH,Line)>2)&&((Marked & 6)==0))
            {
                SciLexer->SendEditor(SCI_MARKERADD,Line,1);
                SciLexer->SendEditor(SCI_MARKERADD,Line,2);
                Module->AddBreakPoint(Line);
            }
            if ((Marked & 6)==6)
            {
                SciLexer->SendEditor(SCI_MARKERDELETE,Line,1);
                SciLexer->SendEditor(SCI_MARKERDELETE,Line,2);
                Module->RemoveBreakPoint(Line);
            }
            if (FileMap)
            {
                TMDelTList<AnsiString> *ModName = new TMDelTList<AnsiString>;
                ModName->Add(new AnsiString(Module->GUID));
                FileMap->Position=0;
                ModName->WriteData(FileMap);
                Module->BreakPoints.WriteData(FileMap);
                SendMessage(Application->MainForm->Handle,WM_USER,MSG_UPDATE,0);
                if (DebugHnd) SendMessage(DebugHnd,WM_USER,MSG_UPDATE,0);
                if (ApplHnd) PostThreadMessage(ApplHnd,WM_USER,MSG_UPDATE,0);
                delete ModName;
            }
            break;
        }

        case SCN_HOTSPOTCLICK:
        {
            AnsiString Delimiters=" ,;=";
            int Brackets[3]={0,0,0};

            if (notification->position!=1)
            {
                int line=SciLexer->SendEditor(SCI_LINEFROMPOSITION,notification->position);
                int length=SciLexer->SendEditor(SCI_LINELENGTH,line);
                int st1=SciLexer->SendEditor(SCI_POSITIONFROMLINE,line);
                char *Text = new char[length+1];
                SciLexer->SendEditor(SCI_GETLINE,line,(long)Text);
                AnsiString aText=AnsiString(Text);
                int st=SciLexer->SendEditor(SCI_WORDSTARTPOSITION,notification->position,0);
                int i=0;
                while ((st-st1-i+1>0)&&(Delimiters.Pos(Text[st-st1-i])==0))
                {
                    char Symb=Text[st-st1-i];
                    if (Symb==')') Brackets[0]++;
                    if (Symb=='(') Brackets[0]--;
                    if (Symb=='}') Brackets[1]++;
                    if (Symb=='{') Brackets[1]--;
                    if (Symb==']') Brackets[2]++;
                    if (Symb=='[') Brackets[2]--;
                    i++;
                    if ((Brackets[0]<0)||(Brackets[1]<0)||(Brackets[2]<0))
                    {
                        i--;
                        break;
                    }
                    if ((Symb=='\"')&&(Brackets[0]==0)&&(Brackets[1]==0)&&(Brackets[2]==0))
                    {
                        i--;
                        break;
                    }
                }
                int en=SciLexer->SendEditor(SCI_WORDENDPOSITION,notification->position,0);
                aText=aText.SubString(st-st1-i+2,en-st+i-1);
                Inspect(aText);
            }
            break;
        }
        case SCN_DWELLSTART:
        {
            break;
        }
        case SCN_DWELLEND:
        {
            break;
        }
        case SCN_CHARADDED  :
        case SCN_UPDATEUI   :
            Label1->Caption = AnsiString("Строка ")+IntToStr( SciLexer->SendEditor(SCI_LINEFROMPOSITION,SciLexer->SendEditor(SCI_GETCURRENTPOS))+1 );
        break;
    }
}



bool TFLuaEditor::CheckSave()
{
    AnsiString NewStr = SciLexer->Text.Trim();
    if (Parent)
    {
        Module->CODE = NewStr;
        Module->CheckFields();
    }
    if ( NewStr == Module->CODE.Trim())
        return true;
    switch(Application->MessageBox( (AnsiString("Сохранить текст в модуле: ")+Caption+AnsiString("?")).c_str(),"Подтверждение",MB_YESNOCANCEL))
    {
        case 0:
        case IDCANCEL:
            return false;
        case IDYES:
        {
            Module->CODE = NewStr;
            Module->CheckFields();
        }
        case IDNO:
            return true;
        default:
            return false;
    }
}

AnsiString CheckSintax(const AnsiString& Code)
{
    int l = Code.Length();
    char *s = Code.c_str();
    bool OK = (luaL_loadbuffer(_LUA_, s, l, "")==0);
    if (OK)
        return AnsiString();
    else
    {
        AnsiString Err = AnsiString(lua_tostring(_LUA_,0))+AnsiString("\n")+AnsiString(lua_tostring(_LUA_,-1));
        return Err;
    }
}

void TFLuaEditor::SETUP()
{
    SciLexer = new TSciLexer(this);
    SciLexer->Parent = this;
    SciLexer->Align = alClient;
    SciLexer->Visible = true;
    SciLexer->OnKeyDown = FormKeyDown;
    SciLexer->OnKeyUp = FormKeyUp;
    Caption = Module->Name;
    SciLexer->OnNotify = Notify;
}

void __fastcall TFLuaEditor::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ((AnsiString(GetCommandLine()).UpperCase().Pos("DEBUG")!=0)||(Application->MainForm->Caption=="Debuger"))
        if (Key==VK_CONTROL)
        {
            SciLexer->SendEditor(SCI_STYLESETHOTSPOT,SCE_LUA_IDENTIFIER, 1);
        }
    if ((Key == VK_RETURN)&&(GetKeyState(VK_CONTROL)))
    {
        int length=SciLexer->SendEditor(SCI_GETSELECTIONEND)-SciLexer->SendEditor(SCI_GETSELECTIONSTART)+1;
        if (length==1) return;
        char *text = new char[length];
        SciLexer->SendEditor(SCI_GETSELTEXT,0, (long)text);
        Inspect(AnsiString(text));
        delete []text;
    }
    if ((Key==VK_F5)&&(Shift.Contains(ssCtrl)))
    {
        int length=SciLexer->SendEditor(SCI_GETSELECTIONEND)-SciLexer->SendEditor(SCI_GETSELECTIONSTART)+1;
        if (length==1) return;
        char *text = new char[length];
        SciLexer->SendEditor(SCI_GETSELTEXT,0, (long)text);
        AddWatch(AnsiString(text));
        delete []text;
    }

}
//---------------------------------------------------------------------------
void __fastcall TFLuaEditor::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ((AnsiString(GetCommandLine()).UpperCase().Pos("DEBUG")!=0)||(Application->MainForm->Caption=="Debuger"))
        if (Key==VK_CONTROL)
        {   
            SciLexer->SendEditor(SCI_STYLESETHOTSPOT,SCE_LUA_IDENTIFIER, 0);
        }
}
//---------------------------------------------------------------------------

