//---------------------------------------------------------------------------

#ifndef VecFormH
#define VecFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MTL.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------

class TForm3 : public TForm
{
	TIntVec FDefault;
	void SetDefault(TIntVec v);
__published:	// IDE-managed Components
	TLabeledEdit *EditX;
	TLabeledEdit *EditY;
	TLabeledEdit *EditZ;
	TBitBtn *Accept;
	void __fastcall AcceptClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	__property TIntVec Default = {read = FDefault, write = SetDefault};
	TIntVec Vector;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

