//---------------------------------------------------------------------------

#ifndef RoofEditVH
#define RoofEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "ElementViewerV.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TRoofForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TImageList *ImageList1;
	TTabSheet *TabSheet6;
	TTabSheet *TabSheet7;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel10;
	TPanel *Panel12;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *edDConvexLevel;
	TPanel *Panel18;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *edRConvexSubdiv;
	TPanel *Panel19;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *edRConvexHeight;
	TPanel *Panel20;
	TLabel *Label21;
	TLabel *Label22;
	TEdit *edRConvexRound;
	TPanel *Panel21;
	TLabel *Label23;
	TLabel *Label24;
	TEdit *edRConcaveSubdiv;
	TPanel *Panel22;
	TLabel *Label25;
	TLabel *Label26;
	TEdit *edRConcaveHeight;
	TPanel *Panel23;
	TLabel *Label27;
	TLabel *Label28;
	TEdit *edRConcaveRound;
	TPanel *Panel24;
	TLabel *Label29;
	TLabel *Label30;
	TEdit *edDomeRound2;
	TPanel *Panel25;
	TLabel *Label31;
	TLabel *Label32;
	TEdit *edDomeRound1;
	TPanel *Panel27;
	TLabel *Label35;
	TLabel *Label36;
	TEdit *edDomeSubdiv;
	TPanel *Panel26;
	TLabel *Label33;
	TLabel *Label34;
	TEdit *edDomeHeight;
	TPanel *Panel11;
	TButton *edSlopePrev;
	TButton *edSlopeNext;
	TLabel *Label11;
	TPanel *Panel15;
	TLabel *Label12;
	TButton *Button8;
	TButton *Button9;
	TPanel *Panel28;
	TLabel *Label37;
	TLabel *Label38;
	TEdit *edSlopeAngle;
	TCheckBox *cbSlopeFront;
	TPanel *Panel29;
	TLabel *Label39;
	TLabel *Label40;
	TEdit *edSlopeLevel;
	TPanel *Panel4;
	TLabel *Label3;
	TLabel *Label5;
	TEdit *edSimpleAngle;
	TCheckBox *cbSimpleFront;
	TPanel *Panel13;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *edDConvexSlope1;
	TCheckBox *cbDConvexFront1;
	TPanel *Panel30;
	TLabel *Label41;
	TLabel *Label42;
	TEdit *edDConvexSlope2;
	TCheckBox *cbDConvexFront2;
	TPanel *cbDConcaveSlope2;
	TLabel *Label4;
	TLabel *Label6;
	TEdit *edDConcaveSlope2;
	TCheckBox *cbDConcaveFront2;
	TPanel *Panel31;
	TLabel *Label43;
	TLabel *Label44;
	TEdit *edDConcaveSlope1;
	TCheckBox *cbDConcaveFront1;
	TPanel *Panel14;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *edDConcaveLevel;
	TPanel *Panel16;
	TLabel *Label13;
	TButton *edWallPrev;
	TButton *edWallNext;
	TGroupBox *GroupBox3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button10;
	TButton *Button11;
	TPanel *Panel17;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *edSalient;
	TLabel *lbSlopeNumber;
	TLabel *lbSlopeIndex;
	TLabel *lbWallIndex;
	TPanel *Panel32;
	TGroupBox *GroupBox4;
	TCheckBox *cbCover;
	TCheckBox *cbWalls;
	TCheckBox *cbConstruction;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image6;
	TImage *Image5;
	TImage *Image7;
	void __fastcall edWallPrevClick(TObject *Sender);
	void __fastcall edWallNextClick(TObject *Sender);
	void __fastcall edSlopePrevClick(TObject *Sender);
	void __fastcall edSlopeNextClick(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall TabSheet7ContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TElementViewer *TElementViewer1;
	__fastcall TRoofForm(TComponent* Owner);
	void EditRoof(TElement *);
	void SaveSide();
	void UpdateSide(int nextSide, int nextPlane);
};

void EditRoof(TElement *el);


//---------------------------------------------------------------------------
extern PACKAGE TRoofForm *RoofForm;
//---------------------------------------------------------------------------

#endif
