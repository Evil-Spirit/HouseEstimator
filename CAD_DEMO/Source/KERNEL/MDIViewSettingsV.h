//---------------------------------------------------------------------------

#ifndef MDIViewSettingsVH
#define MDIViewSettingsVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIViewSettings : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TRadioButton *rbPoints2d;
    TRadioButton *rbLines2d;
    TShape *shBackColor2d;
    TShape *shNetColor2d;
    TGroupBox *GroupBox2;
    TLabel *Label3;
    TLabel *Label4;
    TShape *shBackColor3d;
    TShape *shNetColor3d;
    TRadioButton *rbPoints3d;
    TRadioButton *rbLines3d;
    TBitBtn *btOK;
    TBitBtn *btCancel;
    TColorDialog *CD;
    void __fastcall shBackColor2dMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIViewSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIViewSettings *MDIViewSettings;
//---------------------------------------------------------------------------
#endif
