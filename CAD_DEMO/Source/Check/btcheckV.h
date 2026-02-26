// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef btcheckVH
#define btcheckVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    void  Button1Click(TObject *Sender);
    void  FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TForm1(TComponent* Owner);
    TBindedStateBlock* SBE;
    void State1();
};
//---------------------------------------------------------------------------
extern  TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
