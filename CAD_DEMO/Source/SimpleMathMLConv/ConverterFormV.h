//---------------------------------------------------------------------------

#ifndef ConverterFormVH
#define ConverterFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VVV_02Proj1_OCX.h"
#include <OleCtrls.hpp>
#include "EDITOR_OCX.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TConverterForm : public TForm
{
__published:	// IDE-managed Components
    TRichEdit *RichEdit1;
	TRichEdit *RichEdit2;
	TPanel *Panel1;
	TButton *Button1;
	TSplitter *Splitter1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TConverterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConverterForm *ConverterForm;
//---------------------------------------------------------------------------
#endif
 