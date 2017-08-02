//---------------------------------------------------------------------------

#ifndef ProgramPropertyVH
#define ProgramPropertyVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
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
    void __fastcall StepExit(TObject *Sender);
    void __fastcall bOkClick(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TProgramProperty(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgramProperty *ProgramProperty;
//---------------------------------------------------------------------------
#endif
