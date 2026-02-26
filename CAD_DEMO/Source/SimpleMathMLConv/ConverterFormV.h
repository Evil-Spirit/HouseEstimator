// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ConverterFormVH
#define ConverterFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "VVV_02Proj1_OCX.h"
#include <OleCtrls.hpp>
#include "EDITOR_OCX.h"
//---------------------------------------------------------------------------
class TConverterForm : public TForm
{
__published:	// IDE-managed Components
    TRichEdit *RichEdit1;
	TRichEdit *RichEdit2;
	TPanel *Panel1;
	TButton *Button1;
	TSplitter *Splitter1;
	void  Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TConverterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TConverterForm *ConverterForm;
//---------------------------------------------------------------------------
#endif
 