// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ParamEnteringVH
#define ParamEnteringVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TParamEntering : public TForm
{
__published:	// IDE-managed Components
    TEdit *E1;
    TLabel *lX;
    TEdit *E2;
    TLabel *Label1;
    TButton *OK;
    void  FormShow(TObject *Sender);
    void  sbOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
TIntVec Param;
     TParamEntering(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TParamEntering *ParamEntering;
//---------------------------------------------------------------------------
#endif
