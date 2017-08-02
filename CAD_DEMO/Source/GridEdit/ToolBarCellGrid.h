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

    //Ётот toolbar должен всегда иметь родительскую форму

    __fastcall TToolBarCellGrid(TComponent* Owner,TWinControl* aParent);

    void __fastcall PopupMenuBgColorPopup(TObject *Sender);
    void __fastcall PopupMenuFontColorPopup(TObject *Sender);
    void __fastcall PopupMenuBorderPopup(TObject *Sender);

    void __fastcall SelectBgColorClose(TObject *Sender,TCloseAction &Action);
    void __fastcall SelectFontColorClose(TObject *Sender,TCloseAction &Action);
    void __fastcall SelectBorderClose(TObject *Sender,TCloseAction &Action);

    void __fastcall SetColorIcoTollBar(TColor Color,int Index);
    void __fastcall SetBorderIcoToToolBar(int Index);

    void __fastcall tb_BgColorClick(TObject *Sender);
    void __fastcall tb_FontColorClick(TObject *Sender);
    void __fastcall tb_BorderClick(TObject *Sender);

    void __fastcall cbFontNameChange(TObject *Sender);
    void __fastcall cbFontSizeChange(TObject *Sender);

    void __fastcall tb_jClick(TObject *Sender);
    void __fastcall tb_kClick(TObject *Sender);
    void __fastcall tb_chClick(TObject *Sender);

    void __fastcall tb_LeftHClick(TObject *Sender);
    void __fastcall tb_CenterHClick(TObject *Sender);
    void __fastcall tb_RightHClick(TObject *Sender);

    void __fastcall tb_UnionClick(TObject *Sender);
    void __fastcall tb_VisOneClick(TObject *Sender);

    //—оздание или присвоение новых указателей
    void __fastcall NewFormBgColor(TCellGrid* CellGrid1);
    void __fastcall NewFormFontColor(TCellGrid* CellGrid1);
    void __fastcall NewFormBorder(TCellGrid* CellGrid1);

    void __fastcall FillFontName(TCellGrid* CellGrid1);
    //—оздание или присвоение новых указателей END

    void __fastcall SetDownToolBar(TCellGrid* CellGrid1); // ”становить нажатие иконок ToolBar в соответствии с выделенной областью
};
//---------------------------------------------------------------------------
//extern COMMONAL_API TToolBarCellGrid *ToolBarCellGrid;
//---------------------------------------------------------------------------
#endif
