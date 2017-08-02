//---------------------------------------------------------------------------

#ifndef CellParameterUH
#define CellParameterUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TColorComboBox;
class COMMONAL_API TCellParameter : public TForm
{
__published:	// IDE-managed Components
    TButton *OK;
    TButton *Cansel;
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet4;
    TTabSheet *TabSheet5;
    TGroupBox *GroupBox2;
    TLabel *Label2;
    TGroupBox *GroupBox1;
    TComboBox *cbTextHAlign;
    TLabel *Label1;
    TLabel *Label3;
    TComboBox *cbTextVAlign;
    TGroupBox *GroupBox3;
    TCheckBox *chbTextWordBreak;
    TCheckBox *chbTypeAutoSize;
    TComboBox *cbValueType;
    TComboBox *cbFontName;
    TLabel *Label4;
    TComboBox *cbFontStyle;
    TLabel *Label5;
    TComboBox *cbFontSize;
    TLabel *Label6;
    TGroupBox *GroupBox4;
    TCheckBox *chbFontUnderline;
    TCheckBox *chbFontStrikeOut;
    TGroupBox *GroupBox5;
    TSpeedButton *btLineFlood;
    TSpeedButton *btLine;
    TGroupBox *GroupBox6;
    TSpeedButton *btLineOne_Top;
    TSpeedButton *btLineOne_Left;
    TSpeedButton *btLineOne_Right;
    TSpeedButton *btLineOne_Bottom;
    TGroupBox *GroupBox7;
    TSpeedButton *btLine0;
    TSpeedButton *btLine1;
    TSpeedButton *btLine2;
    TSpeedButton *btLineFloodClear;
    TPaintBox *imExampleBorder;
    TSpeedButton *btLineOne_CenterH;
    TSpeedButton *btLineOne_CenterV;
    TLabel *Label7;
    TLabel *Label8;
    TButton *btBkColorNot;
    TGroupBox *GroupBox8;
    TPaintBox *pbBkColor;
    void __fastcall CanselClick(TObject *Sender);
    void __fastcall OKClick(TObject *Sender);
    void __fastcall btLineFloodClick(TObject *Sender);
    void __fastcall btLine0Click(TObject *Sender);
    void __fastcall btLineClick(TObject *Sender);
    void __fastcall btLineOne_TopClick(TObject *Sender);
    void __fastcall btLineOne_LeftClick(TObject *Sender);
    void __fastcall btLineOne_RightClick(TObject *Sender);
    void __fastcall btLineOne_BottomClick(TObject *Sender);
    void __fastcall imExampleBorderPaint(TObject *Sender);
    void __fastcall btLineOne_CenterHClick(TObject *Sender);
    void __fastcall btLineOne_CenterVClick(TObject *Sender);
    void __fastcall btLineFloodClearClick(TObject *Sender);
    void __fastcall cbValueTypeChange(TObject *Sender);
    void __fastcall cbTextHAlignChange(TObject *Sender);
    void __fastcall cbTextVAlignChange(TObject *Sender);
    void __fastcall chbTextWordBreakClick(TObject *Sender);
    void __fastcall chbTypeAutoSizeClick(TObject *Sender);
    void __fastcall cbFontStyleChange(TObject *Sender);
    void __fastcall cbFontSizeChange(TObject *Sender);
    void __fastcall cbFontNameChange(TObject *Sender);
    void __fastcall chbFontUnderlineClick(TObject *Sender);
    void __fastcall chbFontStrikeOutClick(TObject *Sender);
    void __fastcall btBkColorNotClick(TObject *Sender);
    void __fastcall pbBkColorPaint(TObject *Sender);
private:	// User declarations

public:		// User declarations
    
    TCellGrid* CellGrid;
    __fastcall TCellParameter(TComponent* Owner, TCellGrid* _CellGrid);
    void __fastcall InvalidateU2();
    TColorComboBox* cbFontColor;
    TColorComboBox* cbBkColor;
    void __fastcall FontColorChanged(TObject *Sender);
    void __fastcall BkColorChanged(TObject *Sender);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TCellParameter *CellParameter;
//---------------------------------------------------------------------------
#endif
