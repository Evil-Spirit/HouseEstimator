// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ProgramPropertyVH
#define ProgramPropertyVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//#include ""
//---------------------------------------------------------------------------
class TProgramProperty : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PC;
    TTabSheet *pSnap;
    TLabel *Label1;
    TLabel *lSnapStep;
    TCheckBox *cbSnapOn;
    TCheckBox *cbAdditionalSnapOn;
    TCheckBox *cbMyFigureSnapOn;
    TEdit *eSnapValue;
    TEdit *eSnapStep;
    TTabSheet *pGrid;
    TLabel *lGridStep;
    TLabel *lMultiplier;
    TLabel *lSwitchEpsilon;
    TLabel *lZoomLimit;
    TEdit *eStep;
    TEdit *eMultiplier;
    TCheckBox *cbGridOn;
    TEdit *eSwitchEpsilon;
    TEdit *eZoomLimit;
    TTabSheet *pColors;
    TLabel *lGridMINColor;
    TLabel *lGridMAXColor;
    TLabel *lGridOSIColor;
    TLabel *lAdditionalColor;
    TLabel *lMyFiguresColor;
    TLabel *lSelectedColor;
    TLabel *lBackGroundColor;
    TLabel *lCursor;
    TColorBox *cbGridMIN;
    TColorBox *cbGridMAX;
    TColorBox *cbGridOSI;
    TColorBox *cbAdditional;
    TColorBox *cbMyFigures;
    TColorBox *cbSelected;
    TColorBox *cbBackGround;
    TColorBox *cbCursor;
    TColorBox *cbFixid;
    TLabel *lLinesFixid;
    TButton *bOk;
    TButton *bCancel;
    void  StepExit(TObject *Sender);
    void  bOkClick(TObject *Sender);
    void  bCancelClick(TObject *Sender);
    void  FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TProgramProperty(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TProgramProperty *ProgramProperty;
//---------------------------------------------------------------------------
#endif
