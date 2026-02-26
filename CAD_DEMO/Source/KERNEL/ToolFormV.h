// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ToolFormVH
#define ToolFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TToolForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *pCoordinates;
    TEdit *eDecX;
    TEdit *ePolR;
    TEdit *eDecY;
    TEdit *ePolA;
    TSpeedButton *bDecD;
    TSpeedButton *bPolD;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TPanel *pCustom;
    void  FormResize(TObject *Sender);
    void  pCoordinatesResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TToolForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TToolForm *ToolForm;
//---------------------------------------------------------------------------
#endif
