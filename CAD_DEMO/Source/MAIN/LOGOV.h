//---------------------------------------------------------------------------

#ifndef LOGOVH
#define LOGOVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TLogo : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TTimer *Timer1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool Delete;
    __fastcall TLogo(TComponent* Owner);
};
int RunLogo();
//---------------------------------------------------------------------------
extern PACKAGE TLogo *Logo;
//---------------------------------------------------------------------------
#endif
