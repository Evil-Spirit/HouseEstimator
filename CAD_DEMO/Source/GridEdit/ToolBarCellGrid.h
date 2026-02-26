// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef SectionDialogUH
#define SectionDialogUH
//---------------------------------------------------------------------------
class TCellGrid;
class TSelectColor;
class TSelectBorder;

class COMMONAL_API TToolBarCellGrid : public TToolBar
{
__published:	// IDE-managed Components

    TComboBox *cbFontName;
    TComboBox *cbFontSize;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;

    TToolButton *tb_j;
    TToolButton *tb_k;
    TToolButton *tb_ch;
    TToolButton *ToolButton6;
    TToolButton *tb_LeftH;
    TToolButton *tb_CenterH;
    TToolButton *tb_RightH;
    TToolButton *tb_Union;
    TToolButton *tb_Border;
    TToolButton *tb_BgColor;
    TToolButton *tb_FontColor;
    TToolButton *tb_VisOne;
    
    TPopupMenu *PopupMenuBgColor;
    TPopupMenu *PopupMenuFontColor;
    TPopupMenu *PopupMenuBorder;

private:	// User declarations
public:		// User declarations

    TSelectColor* SBgColor;
    TSelectColor* SFontColor;
    TSelectBorder* SBorder;

    //Ýòîò toolbar äîëæåí âñåãäà èìåòü ðîäèòåëüñêóþ ôîðìó

     TToolBarCellGrid(TComponent* Owner,TWinControl* aParent);

    void  PopupMenuBgColorPopup(TObject *Sender);
    void  PopupMenuFontColorPopup(TObject *Sender);
    void  PopupMenuBorderPopup(TObject *Sender);

    void  SelectBgColorClose(TObject *Sender,TCloseAction &Action);
    void  SelectFontColorClose(TObject *Sender,TCloseAction &Action);
    void  SelectBorderClose(TObject *Sender,TCloseAction &Action);

    void  SetColorIcoTollBar(TColor Color,int Index);
    void  SetBorderIcoToToolBar(int Index);

    void  tb_BgColorClick(TObject *Sender);
    void  tb_FontColorClick(TObject *Sender);
    void  tb_BorderClick(TObject *Sender);

    void  cbFontNameChange(TObject *Sender);
    void  cbFontSizeChange(TObject *Sender);

    void  tb_jClick(TObject *Sender);
    void  tb_kClick(TObject *Sender);
    void  tb_chClick(TObject *Sender);

    void  tb_LeftHClick(TObject *Sender);
    void  tb_CenterHClick(TObject *Sender);
    void  tb_RightHClick(TObject *Sender);

    void  tb_UnionClick(TObject *Sender);
    void  tb_VisOneClick(TObject *Sender);

    //Ñîçäàíèå èëè ïðèñâîåíèå íîâûõ óêàçàòåëåé
    void  NewFormBgColor(TCellGrid* CellGrid1);
    void  NewFormFontColor(TCellGrid* CellGrid1);
    void  NewFormBorder(TCellGrid* CellGrid1);

    void  FillFontName(TCellGrid* CellGrid1);
    //Ñîçäàíèå èëè ïðèñâîåíèå íîâûõ óêàçàòåëåé END

    void  SetDownToolBar(TCellGrid* CellGrid1); // Óñòàíîâèòü íàæàòèå èêîíîê ToolBar â ñîîòâåòñòâèè ñ âûäåëåííîé îáëàñòüþ
};
//---------------------------------------------------------------------------
//extern COMMONAL_API TToolBarCellGrid *ToolBarCellGrid;
//---------------------------------------------------------------------------
#endif
