// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef CellParameterUH
#define CellParameterUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  CanselClick(TObject *Sender);
    void  OKClick(TObject *Sender);
    void  btLineFloodClick(TObject *Sender);
    void  btLine0Click(TObject *Sender);
    void  btLineClick(TObject *Sender);
    void  btLineOne_TopClick(TObject *Sender);
    void  btLineOne_LeftClick(TObject *Sender);
    void  btLineOne_RightClick(TObject *Sender);
    void  btLineOne_BottomClick(TObject *Sender);
    void  imExampleBorderPaint(TObject *Sender);
    void  btLineOne_CenterHClick(TObject *Sender);
    void  btLineOne_CenterVClick(TObject *Sender);
    void  btLineFloodClearClick(TObject *Sender);
    void  cbValueTypeChange(TObject *Sender);
    void  cbTextHAlignChange(TObject *Sender);
    void  cbTextVAlignChange(TObject *Sender);
    void  chbTextWordBreakClick(TObject *Sender);
    void  chbTypeAutoSizeClick(TObject *Sender);
    void  cbFontStyleChange(TObject *Sender);
    void  cbFontSizeChange(TObject *Sender);
    void  cbFontNameChange(TObject *Sender);
    void  chbFontUnderlineClick(TObject *Sender);
    void  chbFontStrikeOutClick(TObject *Sender);
    void  btBkColorNotClick(TObject *Sender);
    void  pbBkColorPaint(TObject *Sender);
private:	// User declarations

public:		// User declarations
    
    TCellGrid* CellGrid;
     TCellParameter(TComponent* Owner, TCellGrid* _CellGrid);
    void  InvalidateU2();
    TColorComboBox* cbFontColor;
    TColorComboBox* cbBkColor;
    void  FontColorChanged(TObject *Sender);
    void  BkColorChanged(TObject *Sender);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TCellParameter *CellParameter;
//---------------------------------------------------------------------------
#endif
