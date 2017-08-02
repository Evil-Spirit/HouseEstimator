 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
     
#include "OutPutV.h"
#include "LuaModuleV.h"
#include "LuaEditorV.h"
#include "MDILuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "Scintilla.h"
#include "SciLexer.h"
#include "MDILuaEditorV.h"
//#include "Select.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
//output == null если не активен
TOutPut *OutPut = NULL;
//---------------------------------------------------------------------------
__fastcall TOutPut::TOutPut(TComponent* Owner)
    : TFloatForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOutPut::FormDestroy(TObject *Sender)
{
    OutPut=NULL;
}
//---------------------------------------------------------------------------
void CloseAllWindows()
{
    for (int i=0;i<Application->MainForm->MDIChildCount;i++)
        if ( !IS(Application->MainForm->MDIChildren[i],__classid(TFLuaEditor)) &&
             !IS(Application->MainForm->MDIChildren[i],__classid(TMDILuaEditor)) )
            Application->MainForm->MDIChildren[i]->Close();
}

bool AllWindowsAreClosed()
{
    for (int i=0;i<Application->MainForm->MDIChildCount;i++)
        if ( !IS(Application->MainForm->MDIChildren[i],__classid(TFLuaEditor)) &&
             !IS(Application->MainForm->MDIChildren[i],__classid(TMDILuaEditor)) )
            return false;
    return true;
}


void __fastcall TOutPut::LVDblClick(TObject *Sender)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    CloseAllWindows();
    if (!AllWindowsAreClosed())
        return;
    if (LV->Selected)
        if (LV->Selected->Data && ((TMyObject*)LV->Selected->Data)->Is(TLuaModule::StaticType) )
        {
            TLuaModule* LM = (TLuaModule*)LV->Selected->Data;
            if (!LM->FindEditor() )
                LM->Edit(Application,NULL,NULL);
            TFLuaEditor* LE = LM->FindEditor();

/*            Select->Terminate();
            TMDIConfig* MDIC;
            MDIC = (TMDIConfig*)ComponentExists(__classid(TMDIConfig));
            if (!MDIC)
            {
                Config->ConfiguratorExecute(NULL);
                MDIC = (TMDIConfig*)ComponentExists(__classid(TMDIConfig));
            }
            if (!MDIC)
                return;
            TLuaEditor* LE = (TLuaEditor*)LM->LuaModuleEdit(MDIC,MDIC);
            */
            ::SetFocus( LE->SciLexer->Handle );
            if (LV->Selected->StateIndex == -10)
            {
                LE->SciLexer->SendEditor(SCI_GOTOLINE,LV->Selected->ImageIndex);
            }
            else
            {
                LE->SciLexer->SendEditor(SCI_SETSELECTIONSTART,LV->Selected->ImageIndex-1);
                LE->SciLexer->SendEditor(SCI_SETSELECTIONEND,LV->Selected->StateIndex-1);
                LE->SciLexer->SendEditor(SCI_SCROLLCARET);
            }
        }   
    #endif
}
//---------------------------------------------------------------------------

void __fastcall TOutPut::LVResize(TObject *Sender)
{
    LV->Column[0]->Width = LV->ClientWidth;
}
//---------------------------------------------------------------------------

void MyStdOut(const AnsiString& Str,bool opClear)
{
    if (!OutPut||!(OutPut->Visible))
    {
        TForm * GlueForm = NULL;//Config->ActiveMDIChild;
        /*if (!GlueForm)
            GlueForm = Screen->ActiveForm;
        if (!GlueForm)
            GlueForm = Application->MainForm;*/
        OutPut = new TOutPut(Application);
        if (GlueForm)
        {
            /*if (Application->MainForm)
            {
                OutPut->Parent = Application->MainForm;
                OutPut->Align = alBottom;
                OutPut->Parent = NULL;
                OutPut->Align = alNone;
            } */

/*            OutPut->Width = GlueForm->Width;
            OutPut->Height = 100;
            TPoint P = TPoint(0,GlueForm->Height);
            P = GlueForm->ClientToScreen(P);
//            OutPut->Top = Config->ClientOrigin.y + GlueForm->Top + GlueForm->Height;
  //          OutPut->Left = Config->ClientOrigin.x + GlueForm->Left;
            OutPut->Top = P.y;
            OutPut->Left = P.x;
            if (OutPut->Top + OutPut->Height > Screen->Height)
            {
                int Shift = OutPut->Top + OutPut->Height - Screen->Height;
                if (GlueForm != Application->MainForm)
                    GlueForm->Height -= Shift;
                OutPut->Top -= Shift;
            }   */
        }
        OutPut->Show();
    }
    if (opClear)
        OutPut->LV->Items->Clear();
    OutPut->LV->Items->Add()->Caption = Str.Trim();
}

void LinkStdOut(const AnsiString& Str,bool opClear,TMyObject *Obj,int Data1,int Data2)
{
    MyStdOut(Str,opClear);
    if ( OutPut && OutPut->LV->Items->Count)
    {
        OutPut->LV->Items->Item[OutPut->LV->Items->Count-1]->Data = Obj;
        OutPut->LV->Items->Item[OutPut->LV->Items->Count-1]->ImageIndex = Data1;
        OutPut->LV->Items->Item[OutPut->LV->Items->Count-1]->StateIndex = Data2;
    }
}




