// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ProgBarVH
#define ProgBarVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class COMMONAL_API TProgBar : public TForm
{
__published:	// IDE-managed Components
    TProgressBar *Progress;
    TLabel *Main;
    TLabel *Detail;
	TLabel *lProcessName;
    void  FormCreate(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TProgBar(TComponent* Owner);
    AnsiString ProcessName;
};
//---------------------------------------------------------------------------
void COMMONAL_API RealStartProcess(const AnsiString& ProcessName,int Count);
void COMMONAL_API RealCountProcess(const AnsiString& ObjectName,int Count);
extern COMMONAL_API TProgBar *ProgBar;

//---------------------------------------------------------------------------
#endif
