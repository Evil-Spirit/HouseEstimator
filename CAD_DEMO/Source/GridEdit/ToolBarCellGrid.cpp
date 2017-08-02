#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "ToolBarCellGrid.h"
#include "ImagesU.h"
#include "CellGrid.h"
#include "SelectBorderU.h"
#include "SelectColorU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

int CALLBACK GetFontToMashine(LOGFONT* lplf, TEXTMETRIC* lptm, DWORD dwType, LPARAM lpData);

TCellGrid* FindGrid()
{
    if (!Application->MainForm)
        return NULL;
    else
        return (TCellGrid*)ComponentExists(__classid(TCellGrid),Application->MainForm);
}

__fastcall TToolBarCellGrid::TToolBarCellGrid(TComponent* Owner,TWinControl* aParent)
    : TToolBar(Owner)
{
//    Height =24;
    Width =Screen->Width;
    Align =alTop;
    Parent = aParent;
    Color =clBtnFace;
    Flat =true;
    Images =CGIL->ilToolBar;
    Images->Masked =true;
    Images->DrawingStyle =dsNormal;
    Images->ImageType =itImage;
    Images->ShareImages =false;

    // Отображение нумерованых (строк, столбцов)
    tb_VisOne =new TToolButton(this);
    tb_VisOne->Parent = this;
    tb_VisOne->Style =tbsButton;
    tb_VisOne->ImageIndex =10;
    tb_VisOne->Width =23;
    tb_VisOne->Height =22;
    tb_VisOne->Visible =true;
    tb_VisOne->OnClick =tb_VisOneClick;

    // Разделитель
    ToolButton5 =new TToolButton(this);
    ToolButton5->Parent = this;
    ToolButton5->Style =tbsSeparator;
    ToolButton5->Width =2;
    ToolButton5->Visible =true;


    PopupMenuFontColor =new TPopupMenu(this);
    PopupMenuFontColor->OnPopup =PopupMenuFontColorPopup;

    // Цвет шрифта
    tb_FontColor =new TToolButton(this);
    tb_FontColor->Parent = this;
    tb_FontColor->Style =tbsDropDown;
    tb_FontColor->ImageIndex =9;
    tb_FontColor->Width =23;
    tb_FontColor->Height =22;
    tb_FontColor->Visible =true;
    tb_FontColor->DropdownMenu =PopupMenuFontColor;
    tb_FontColor->DropdownMenu->OnPopup =PopupMenuFontColorPopup;
    tb_FontColor->OnClick =tb_FontColorClick;


    PopupMenuBgColor =new TPopupMenu(this);
    PopupMenuBgColor->OnPopup =PopupMenuBgColorPopup;

    // Цвет фона
    tb_BgColor =new TToolButton(this);
    tb_BgColor->Parent = this;
    tb_BgColor->Style =tbsDropDown;
    tb_BgColor->ImageIndex =8;
    tb_BgColor->Width =23;
    tb_BgColor->Height =22;
    tb_BgColor->Visible =true;
    tb_BgColor->DropdownMenu =PopupMenuBgColor;
    tb_BgColor->DropdownMenu->OnPopup =PopupMenuBgColorPopup;
    tb_BgColor->OnClick =tb_BgColorClick;

    PopupMenuBorder =new TPopupMenu(this);
    PopupMenuBorder->OnPopup =PopupMenuBorderPopup;

    // Border
    tb_Border =new TToolButton(this);
    tb_Border->Parent = this;
    tb_Border->Style =tbsDropDown;
    tb_Border->ImageIndex =7;
    tb_Border->Width =23;
    tb_Border->Height =22;
    tb_Border->Visible =true;
    tb_Border->DropdownMenu =PopupMenuBorder;
    tb_Border->DropdownMenu->OnPopup =PopupMenuBorderPopup;
    tb_Border->OnClick =tb_BorderClick;

    SetBorderIcoToToolBar(3);

    // Разделитель
    ToolButton4 =new TToolButton(this);
    ToolButton4->Parent = this;
    ToolButton4->Style =tbsSeparator;
    ToolButton4->Width =2;
    ToolButton4->Visible =true;

    // Объеденение
    tb_Union =new TToolButton(this);
    tb_Union->Parent = this;
    tb_Union->Style =tbsButton;
    tb_Union->ImageIndex =6;
    tb_Union->Width =23;
    tb_Union->Height =22;
    tb_Union->Visible =true;
    tb_Union->OnClick =tb_UnionClick;

    // Разделитель
    ToolButton3 =new TToolButton(this);
    ToolButton3->Parent = this;
    ToolButton3->Style =tbsSeparator;
    ToolButton3->Width =2;
    ToolButton3->Visible =true;

    // Выровнять по право
    tb_RightH =new TToolButton(this);
    tb_RightH->Parent = this;
    tb_RightH->Style =tbsButton;
    tb_RightH->ImageIndex =5;
    tb_RightH->Width =23;
    tb_RightH->Height =22;
    tb_RightH->Visible =true;
    tb_RightH->OnClick =tb_RightHClick;

    // Выровнять по Центру
    tb_CenterH =new TToolButton(this);
    tb_CenterH->Parent = this;
    tb_CenterH->Style =tbsButton;
    tb_CenterH->ImageIndex =4;
    tb_CenterH->Width =23;
    tb_CenterH->Height =22;
    tb_CenterH->Visible =true;
    tb_CenterH->OnClick =tb_CenterHClick;

    // Выровнять по лево
    tb_LeftH =new TToolButton(this);
    tb_LeftH->Parent = this;
    tb_LeftH->Style =tbsButton;
    tb_LeftH->ImageIndex =3;
    tb_LeftH->Width =23;
    tb_LeftH->Height =22;
    tb_LeftH->Visible =true;
    tb_LeftH->OnClick =tb_LeftHClick;


    // Разделитель
    ToolButton2 =new TToolButton(this);
    ToolButton2->Parent = this;
    ToolButton2->Style =tbsSeparator;
    ToolButton2->Width =2;
    ToolButton2->Visible =true;

    // Подчеркнутый шрифт
    tb_ch =new TToolButton(this);
    tb_ch->Parent = this;
    tb_ch->Style =tbsButton;
    tb_ch->ImageIndex =2;
    tb_ch->Width =23;
    tb_ch->Height =22;
    tb_ch->Visible =true;
    tb_ch->OnClick =tb_chClick;

    // Курсивный шрифт
    tb_k =new TToolButton(this);
    tb_k->Parent = this;
    tb_k->Style =tbsButton;
    tb_k->ImageIndex =1;
    tb_k->Width =23;
    tb_k->Height =22;
    tb_k->Visible =true;
    tb_k->OnClick =tb_kClick;

    // Жирный шрифт
    tb_j =new TToolButton(this);
    tb_j->Parent = this;
    tb_j->Style =tbsButton;
    tb_j->ImageIndex =0;
    tb_j->Width =23;
    tb_j->Height =22;
    tb_j->Visible =true;
    tb_j->OnClick =tb_jClick;


    // Разделитель
    ToolButton1 =new TToolButton(this);
    ToolButton1->Parent = this;
    ToolButton1->Style =tbsSeparator;
    ToolButton1->Width =2;
    ToolButton1->Visible =true;

    // Размер шрифта
    cbFontSize =new TComboBox(this);
    cbFontSize->Parent = this;
    cbFontSize->Top=0;
    cbFontSize->Width=64;
    cbFontSize->Height=21;
    cbFontSize->Visible =true;
    cbFontSize->OnChange =cbFontSizeChange;

    // Имя шрифта
    cbFontName =new TComboBox(this);
    cbFontName->Parent = this;
    int iLeftComponent =2;
    cbFontName->Left=iLeftComponent;
    cbFontName->Top=0;
    cbFontName->Width=145;
    cbFontName->Height=21;
    cbFontName->Visible =true;
    cbFontName->OnChange =cbFontNameChange;

    TCellGrid* CellGrid1 =FindGrid();
    int ii=0;
    if (CellGrid1 !=NULL)
    {
        TMDelTList<AnsiString> NameFont;
        EnumFonts(Canvas->Handle, NULL,(FARPROC)(&GetFontToMashine),(long)(&NameFont));
        TCell* Cell11 =CellGrid1->GetCell(1,1);
        for (int i=0; i<NameFont.Count; i++)
        {
            cbFontName->Items->Add(NameFont[i]);
            if (Cell11->FontName == NameFont[i]) cbFontName->ItemIndex =i;
        }


        for (int i=6; i<70; i+=2)
        {
            cbFontSize->Items->Add(IntToStr(i));
            if ((int)Cell11->CellFlags.FontSize == i) cbFontSize->ItemIndex =ii;
            ii++;
        }

    }
    else
    {
        TMDelTList<AnsiString> NameFont;
        EnumFonts(Canvas->Handle, NULL,(FARPROC)(&GetFontToMashine),(long)(&NameFont));
        for (int i=0; i<NameFont.Count; i++)
        {
            cbFontName->Items->Add(NameFont[i]);
        }
        cbFontName->Text ="Arial Cyr";


        for (int i=6; i<70; i+=2)
        {
            cbFontSize->Items->Add(IntToStr(i));
            ii++;
        }
        cbFontSize->Text ="10";
    }


}

void __fastcall TToolBarCellGrid::PopupMenuBgColorPopup(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormBgColor(CellGrid1);
        SBgColor->Show();
    }
}

void __fastcall TToolBarCellGrid::PopupMenuFontColorPopup(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormFontColor(CellGrid1);
        SFontColor->Show();
    }
}

void __fastcall TToolBarCellGrid::PopupMenuBorderPopup(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormBorder(CellGrid1);
        SBorder->Show();
    }
}

void __fastcall TToolBarCellGrid::SelectBgColorClose(TObject *Sender,TCloseAction &Action)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        if (SBgColor->bAutoColor)
        {
            CellGrid1->SetColorRegion(SBgColor->GetColor(),false);
            SetColorIcoTollBar(SBgColor->GetColor(),8);
        }
        else
        {
            CellGrid1->SetColorRegion(SBgColor->GetColor(),true);
            SetColorIcoTollBar(SBgColor->GetColor(),8);
        }
        CellGrid1->Paint();
    }
}

void __fastcall TToolBarCellGrid::SelectFontColorClose(TObject *Sender,TCloseAction &Action)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        if (SFontColor->bAutoColor)
        {
            CellGrid1->SetFontColorRegion(clBlack);
            SetColorIcoTollBar(clBlack,9);
        }
        else
        {
            CellGrid1->SetFontColorRegion(SFontColor->GetColor());
            SetColorIcoTollBar(SFontColor->GetColor(),9);
        }
        CellGrid1->Paint();
    }
}

void __fastcall TToolBarCellGrid::SelectBorderClose(TObject *Sender,TCloseAction &Action)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormBorder(CellGrid1);
        switch (SBorder->SelectBorderIndex)
        {
            case 1:
            {
                CellGrid1->SetCellLineFlood(0,0,0,0);
            } break;
            case 2:
            {
                CellGrid1->SetCellLineFlood(1,1,1,1);
            } break;
            case 3:
            {
                CellGrid1->SetCellLine(1,1,1,1);
            } break;
            case 4:
            {
                CellGrid1->SetCellLine(2,2,2,2);
            } break;
            case 5:
            {
                CellGrid1->SetCellLineOne(1,1);
            } break;
            case 6:
            {
                CellGrid1->SetCellLineOne(2,1);
            } break;
            case 7:
            {
                CellGrid1->SetCellLineOne(3,1);
            } break;
            case 8:
            {
                CellGrid1->SetCellLineOne(4,1);
            } break;
            case 9:
            {
                CellGrid1->SetCellLineOne(1,2);
            } break;
            case 10:
            {
                CellGrid1->SetCellLineOne(2,2);
            } break;
            case 11:
            {
                CellGrid1->SetCellLineOne(3,2);
            } break;
            case 12:
            {
                CellGrid1->SetCellLineOne(4,2);
            } break;
        }
        if (SBorder->SelectBorderIndex >0)
        {
            SetBorderIcoToToolBar(SBorder->SelectBorderIndex);
        }
        CellGrid1->Paint();
    }
}

void __fastcall TToolBarCellGrid::SetBorderIcoToToolBar(int Index)
{
    Graphics::TBitmap *bit = new Graphics::TBitmap();
    Graphics::TBitmap *msk = new Graphics::TBitmap();
    bit->Width =16;
    bit->Height =16;

    CGIL->ilBorders->GetBitmap(Index-1,bit);
    msk->Assign(bit);
    CGIL->ilBorders->Draw(msk->Canvas,0,0,Index-1,dsNormal,itMask);

    if ( CGIL->ilToolBar->HandleAllocated() )
    {
        ImageList_Replace((_IMAGELIST*)CGIL->ilToolBar->Handle, 7, bit->Handle,msk->Handle);
        tb_Border->Repaint();
    }
    delete bit;
    delete msk;
}

void __fastcall TToolBarCellGrid::SetColorIcoTollBar(TColor Color,int Index)
{
    Graphics::TBitmap *bit = new Graphics::TBitmap();
    Graphics::TBitmap *msk = new Graphics::TBitmap();
    bit->Width =16;
    bit->Height =16;

    CGIL->ilToolBar->GetBitmap(Index,bit);
    msk->Assign(bit);

    CGIL->ilToolBar->Draw(msk->Canvas,0,0,Index,dsNormal,itMask);

    bit->Canvas->Brush->Color =Color;
    bit->Canvas->Pen->Color =Color;
    bit->Canvas->Rectangle(0,12,16,16);

    if ( CGIL->ilToolBar->HandleAllocated() )
    {
        ImageList_Replace((_IMAGELIST*)CGIL->ilToolBar->Handle, Index, bit->Handle,msk->Handle);
        tb_BgColor->Repaint();
        tb_FontColor->Repaint();
    }
    delete bit;
    delete msk;
}

void __fastcall TToolBarCellGrid::tb_BgColorClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormBgColor(CellGrid1);
        CellGrid1->SetColorRegion(SBgColor->GetColor(),true);
        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_BorderClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        TCloseAction ca;
        SelectBorderClose(NULL,ca);
        CellGrid1->Invalidate();
    }
}


void __fastcall TToolBarCellGrid::tb_FontColorClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        NewFormFontColor(CellGrid1);
        CellGrid1->SetFontColorRegion(SFontColor->GetColor());
        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::cbFontNameChange(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->SetFontNameRegion(cbFontName->Items->Strings[cbFontName->ItemIndex]);
        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::cbFontSizeChange(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        if (cbFontSize->Text.Length()>0)
        if (ISINTEGER(cbFontSize->Text))
        {
            int i=StrToInt(cbFontSize->Text);
            CellGrid1->SetFontSizeRegion(i);
            CellGrid1->Invalidate();
        }
    }
}
void __fastcall TToolBarCellGrid::tb_jClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {

        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==0)
        {
            CellGrid1->SetFontStyleRegion(2);
        }
        else  if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==1)
        {
            CellGrid1->SetFontStyleRegion(3);
        }
        else if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==2)
        {
            CellGrid1->SetFontStyleRegion(0);
        }
        else
        {
            CellGrid1->SetFontStyleRegion(1);
        }
        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_kClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==0)
            CellGrid1->SetFontStyleRegion(1);
        else  if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==1)
            CellGrid1->SetFontStyleRegion(0);
        else if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontStyle ==2)
            CellGrid1->SetFontStyleRegion(3);
        else
            CellGrid1->SetFontStyleRegion(2);

        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_chClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {

        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.FontUnderline ==0)
            CellGrid1->SetFontUnderlineRegion(1);
        else
            CellGrid1->SetFontUnderlineRegion(0);

        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_LeftHClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {

        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.TextHAlign ==0)
            CellGrid1->SetTextHAlignRegion(0);
        else
            CellGrid1->SetTextHAlignRegion(0);

        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_CenterHClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {

        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.TextHAlign ==1)
            CellGrid1->SetTextHAlignRegion(0);
        else
            CellGrid1->SetTextHAlignRegion(1);

        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_RightHClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        if (CellGrid1->GetCellParam(CellGrid1->FCurrent.X, CellGrid1->FCurrent.Y)->CellFlags.TextHAlign ==2)
            CellGrid1->SetTextHAlignRegion(0);
        else
            CellGrid1->SetTextHAlignRegion(2);

        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_UnionClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->SetUnionCell(true);
        CellGrid1->Invalidate();
    }
}

void __fastcall TToolBarCellGrid::tb_VisOneClick(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {

        if (!CellGrid1->VisibleOfficialMargin)
        {
            CellGrid1->VisibleOfficialMargin = true;
            tb_VisOne->Down =false;
        } else
        {
            CellGrid1->VisibleOfficialMargin = false;
            tb_VisOne->Down =true;
        }
        CellGrid1->Invalidate();
    }
}

//----------------------- Создание или присвоение новых указателей
void __fastcall TToolBarCellGrid::NewFormBgColor(TCellGrid* CellGrid1)
{
    if (SBgColor ==NULL)
    {
        SBgColor = new TSelectColor(this,CellGrid1, NULL);
        SBgColor->shAutoColor->Brush->Color =clWhite;
        SBgColor->GetColors->Brush->Color =clYellow;
        SBgColor->AutoFontColor->Caption ="None";

        int x =tb_BgColor->Left;
        int y =tb_BgColor->Top +tb_BgColor->Height +CellGrid1->Top;

        SBgColor->Left =x;
        SBgColor->Top =y;
        SBgColor->OnClose =SelectBgColorClose;
    }
    else
    {
        SBgColor->CellGrid =CellGrid1;

        int x =tb_BgColor->Left;
        int y =tb_BgColor->Top +tb_BgColor->Height +CellGrid1->Top;

        SBgColor->Left =x;
        SBgColor->Top =y;
    }
}

void __fastcall TToolBarCellGrid::NewFormFontColor(TCellGrid* CellGrid1)
{
    if (SFontColor ==NULL)
    {
        SFontColor = new TSelectColor(this,CellGrid1, NULL);
        SFontColor->shAutoColor->Brush->Color =clBlack;
        SFontColor->GetColors->Brush->Color =clRed;

        int x =tb_FontColor->Left;
        int y =tb_FontColor->Top +tb_FontColor->Height +CellGrid1->Top;

        SFontColor->Left =x;
        SFontColor->Top =y;
        SFontColor->OnClose =SelectFontColorClose;
    }
    else
    {
        SFontColor->CellGrid =CellGrid1;

        int x =tb_FontColor->Left;
        int y =tb_FontColor->Top +tb_FontColor->Height +CellGrid1->Top;

        SFontColor->Left =x;
        SFontColor->Top =y;
    }
}

void __fastcall TToolBarCellGrid::NewFormBorder(TCellGrid* CellGrid1)
{
    if (SBorder ==NULL)
    {
        SBorder =new TSelectBorder(Application);
        SBorder->SelectBorderIndex =3;

        int x =tb_Border->Left;
        int y =tb_Border->Top +tb_Border->Height +CellGrid1->Top;

        SBorder->Left =x;
        SBorder->Top =y;
        SBorder->OnClose =SelectBorderClose;
    }
    else
    {
        int x =tb_Border->Left;
        int y =tb_Border->Top +tb_Border->Height +CellGrid1->Top;

        SBorder->Left =x;
        SBorder->Top =y;
    }
}

//----------------------- Создание или присвоение новых указателей END

void SetBtnDown(TToolButton* BT,bool Flag)
{
    if (BT->Down!=Flag)
        BT->Down=Flag;
}

void __fastcall TToolBarCellGrid::SetDownToolBar(TCellGrid* CellGrid1)
{ // Установить нажатие иконок ToolBar в соответствии с выделенной областью
    if (CellGrid1 !=NULL &&
        CellGrid1->FCurrent.X >1 &&
        CellGrid1->FCurrent.Y >1 &&
        CellGrid1->FAnchor.X != CellGrid1->ColCount-1 &&
        CellGrid1->FAnchor.Y != CellGrid1->RowCount-1
        )
    {
        //--- Установка флагов
        // Выравнивание
        bool bTextHAlign=true;
        unsigned int iTextHAlign;

        // Имя шрифта
        bool bFontName=true;
        AnsiString sFontName;

        // Стиль Шрифта
        bool bFontStyle=true;
        unsigned int iFontStyle;

        // Размер
        bool bFontSize=true;
        unsigned int iFontSize;

        //  Шрифт подчеркнутый
        bool bFontUnderline=true;
        unsigned int iFontUnderline;

        //  Объедененная ячейка
        bool bUnion=false;

        //--- Получение параметров первой ячейки

        CellGrid1->GetSelectCells(false);
        int End=CellGrid1->ListFilling.Count;

        TCell* Cell00 =CellGrid1->GetCellParam(CellGrid1->ListFilling[0].x,CellGrid1->ListFilling[0].y);

        // Выравнивание
        iTextHAlign =Cell00->CellFlags.TextHAlign;

        // Стиль текста
        iFontStyle =Cell00->CellFlags.FontStyle;

        // Размер текста
        iFontSize =Cell00->CellFlags.FontSize;

        // Имя шрифта
        sFontName =Cell00->FontName;

        // Шрифт подчеркнутый
        iFontUnderline =Cell00->CellFlags.FontUnderline;

        //  Объедененная ячейка
        if (CellGrid1->GetCell(CellGrid1->ListFilling[0].x,CellGrid1->ListFilling[0].y) !=NULL &&
            CellGrid1->GetCell(CellGrid1->ListFilling[0].x,CellGrid1->ListFilling[0].y)->UnionRect !=NULL
        )
            bUnion =true;

        //------- Цикл проверки с остальными ячейками
        TCell* Cell;
        for (int i=0; i<End; i++)
        {
            Cell =CellGrid1->GetCellParam(CellGrid1->ListFilling[i].x,CellGrid1->ListFilling[i].y);

            // Выравнивание
            if (iTextHAlign !=Cell->CellFlags.TextHAlign)
                bTextHAlign=false;

            // Стиль текста
            if (iFontStyle !=Cell->CellFlags.FontStyle)
                bFontStyle=false;

            // Размер текста
            if (iFontSize !=Cell->CellFlags.FontSize)
                bFontSize=false;


            // Имя шрифта
            if (sFontName !=Cell->FontName)
                bFontName=false;


            // Шрифт подчеркнутый
            if (iFontUnderline !=Cell->CellFlags.FontUnderline)
                bFontUnderline =false;

            //  Объедененная ячейка
            if (!bUnion && CellGrid1->GetCell(CellGrid1->ListFilling[i].x,CellGrid1->ListFilling[i].y) !=NULL &&
                CellGrid1->GetCell(CellGrid1->ListFilling[i].x,CellGrid1->ListFilling[i].y)->UnionRect !=NULL
            )
                bUnion =true;

        }
        Cell =NULL;

        //--- Установка соответствующего положения

        // Выравнивание
        SetBtnDown(tb_LeftH,    bTextHAlign&&(iTextHAlign==0));
        SetBtnDown(tb_CenterH,  bTextHAlign&&(iTextHAlign==1));
        SetBtnDown(tb_RightH,   bTextHAlign&&(iTextHAlign==2));

        // Стиль текста

        SetBtnDown(tb_k,bFontStyle&&(iFontStyle==1 || iFontStyle==3));
        SetBtnDown(tb_j,bFontStyle&&(iFontStyle==2 || iFontStyle==3));

        // Шрифт подчеркнутый
        SetBtnDown(tb_ch,bFontUnderline&&iFontUnderline ==1);

        // Размер текста
        if (bFontSize)
            cbFontSize->Text =iFontSize;
        else
            cbFontSize->ItemIndex =-1;

        // Имя шрифта
        if (bFontName)
            cbFontName->Text =sFontName;
        else
            cbFontName->ItemIndex =-1;

        //  Объедененная ячейка
        SetBtnDown(tb_Union,bUnion);
    }
}

int CALLBACK GetFontToMashine(LOGFONT* lplf, TEXTMETRIC* lptm, DWORD dwType, LPARAM lpData)
{
    TMDelTList<AnsiString>* NameFont =(TMDelTList<AnsiString>*) lpData;
    NameFont->Add(new AnsiString(lplf->lfFaceName));
    return 1;
}

