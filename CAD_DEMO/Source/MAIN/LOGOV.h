// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef LOGOVH
#define LOGOVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TLogo : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TTimer *Timer1;
    void  FormCreate(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  Timer1Timer(TObject *Sender);
    void  FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool Delete;
     TLogo(TComponent* Owner);
};
int RunLogo();
//---------------------------------------------------------------------------
extern  TLogo *Logo;
//---------------------------------------------------------------------------
#endif
