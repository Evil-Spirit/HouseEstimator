// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIViewSettingsVH
#define MDIViewSettingsVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  shBackColor2dMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
     TMDIViewSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIViewSettings *MDIViewSettings;
//---------------------------------------------------------------------------
#endif
