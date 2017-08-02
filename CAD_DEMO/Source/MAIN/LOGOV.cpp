 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LOGOV.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"                   
TLogo *Logo = NULL;
//---------------------------------------------------------------------------
__fastcall TLogo::TLogo(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLogo::FormCreate(TObject *Sender)
{
    AnsiString _Name = MainDir+SL+AnsiString("LOGO")+BMP;
    if (FileExists(_Name))
    {
        Graphics::TBitmap *BMP = new Graphics::TBitmap();
                BMP->HandleType = bmDIB;
        BMP->LoadFromFile(_Name);
        Image1->Picture->Bitmap->Assign(BMP);
        delete BMP;
    }
    Logo = this;
    Left = Config->Width/2 - Width/2 + Config->Left;
    Top = Config->Height/2 - Height/2 + Config->Top;
}
//---------------------------------------------------------------------------
void __fastcall TLogo::FormDestroy(TObject *Sender)
{
    Logo = NULL;    
}
//---------------------------------------------------------------------------
void __fastcall TLogo::Timer1Timer(TObject *Sender)
{
    if (Delete)
    {
        Timer1->Enabled=false;
        delete this;
    }

}
//---------------------------------------------------------------------------
int RunLogo()
{
    new TLogo(NULL);
    Logo->Show();
    Logo->Image1->Invalidate();
    Application->ProcessMessages();
    return 1;
}
void __fastcall TLogo::FormShow(TObject *Sender)
{
    Delete = false;
    Timer1->Enabled=true;

}
//---------------------------------------------------------------------------
