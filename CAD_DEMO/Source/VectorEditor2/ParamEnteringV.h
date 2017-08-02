//---------------------------------------------------------------------------

#ifndef ParamEnteringVH
#define ParamEnteringVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TParamEntering : public TForm
{
__published:	// IDE-managed Components
    TEdit *E1;
    TLabel *lX;
    TEdit *E2;
    TLabel *Label1;
    TButton *OK;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sbOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
TIntVec Param;
    __fastcall TParamEntering(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParamEntering *ParamEntering;
//---------------------------------------------------------------------------
#endif
