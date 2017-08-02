//---------------------------------------------------------------------------

#ifndef ProgBarVH
#define ProgBarVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TProgBar : public TForm
{
__published:	// IDE-managed Components
    TProgressBar *Progress;
    TLabel *Main;
    TLabel *Detail;
	TLabel *lProcessName;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TProgBar(TComponent* Owner);
    AnsiString ProcessName;
};
//---------------------------------------------------------------------------
void COMMONAL_API RealStartProcess(const AnsiString& ProcessName,int Count);
void COMMONAL_API RealCountProcess(const AnsiString& ObjectName,int Count);
extern COMMONAL_API TProgBar *ProgBar;

//---------------------------------------------------------------------------
#endif
