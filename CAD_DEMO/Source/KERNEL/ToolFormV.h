//---------------------------------------------------------------------------

#ifndef ToolFormVH
#define ToolFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
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
    void __fastcall FormResize(TObject *Sender);
    void __fastcall pCoordinatesResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TToolForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TToolForm *ToolForm;
//---------------------------------------------------------------------------
#endif
