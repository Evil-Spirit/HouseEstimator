//---------------------------------------------------------------------------

#ifndef btcheckVH
#define btcheckVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    TBindedStateBlock* SBE;
    void State1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
