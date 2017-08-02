//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "CellParameterU.h"
#include "SelectColorU.h"
#include "ColorComboBoxU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCellParameter *CellParameter = NULL;
//---------------------------------------------------------------------------
    // Текст
    bool ChangeValueType =false;

    // Выравнивание по горизонтали
    bool ChangeTextHAlign =false;

    // Выравнивание по Вертикали
    bool ChangeTextVAlign =false;

    // Перенос по словам
    bool ChangeTextWordBreak =false;

    // Авто размер
    bool ChangeTypeAutoSize =false;

    // Стиль шрифта
    bool ChangeFontStyle =false;

    // Размер шрифта
    bool ChangeFontSize =false;

    // Шрифт
    bool ChangeFontName =false;

    // Шрифт зачеркнутый
    bool ChangeFontStrikeOut =false;

    // Шрифт подчеркнутый
    bool ChangeFontUnderline =false;

    // Бордюр
    int iLine_Left =0;
    int iLine_Top =0;
    int iLine_Right =0;
    int iLine_Bottom =0;
    int iLine_CenterV =0;
    int iLine_CenterH =0;


    bool bLineBorderCenterV =false;
    bool bLineBorderCenterH =false;

    // Цвет Шрифта
    bool ChangeFontColor =false;

    // Цвет фона
    bool ChangeBkColor =false;

    // Цвет фона
    bool ChangeBkColorNot  =false;
    bool bBkColor=false;
//----------------------------------------------------------------------------------------

int CALLBACK GetFontToMashine(LOGFONT* lplf, TEXTMETRIC* lptm, DWORD dwType, LPARAM lpData);

__fastcall TCellParameter::TCellParameter(TComponent* Owner, TCellGrid* _CellGrid)
    : TForm(Owner)
{
    //---------------------

    cbFontColor = new TColorComboBox(this,_CellGrid,CellParameter);
    cbFontColor->Parent = TabSheet3;
    cbFontColor->Visible = true;
    cbFontColor->SC->shAutoColor->Brush->Color =clBlack;
    cbFontColor->SC->GetColors->Brush->Color =clBlack;
    cbFontColor->Left = 160;
    cbFontColor->Top = 128;
    cbFontColor->OnColorChange = FontColorChanged;
    //---------------------


    cbBkColor = new TColorComboBox(this,_CellGrid,CellParameter);
    cbBkColor->Parent = TabSheet5;
    cbBkColor->Visible = true;
    cbBkColor->SC->shAutoColor->Brush->Color =clWhite;
    cbBkColor->SC->GetColors->Brush->Color =clWhite;
    cbBkColor->Left = 8;
    cbBkColor->SC->AutoFontColor->Caption = "None";
    cbBkColor->Top = 50;
    cbBkColor->OnColorChange =BkColorChanged;

    CellGrid = _CellGrid;


    btLine0->Tag=-1;
    btLine1->Tag=1;
    btLine2->Tag=-1;
    btLine1->Down = true;

    // Текст
    ChangeValueType =false;
    cbValueType->Items->Add("Text");
    cbValueType->Items->Add("Expression");
    cbValueType->Items->Add("Teamplate");

    bool bValueType=true;
    unsigned int iValueType;

    // Выравнивание
    cbTextHAlign->Items->Add("Left side");
    cbTextHAlign->Items->Add("Center");
    cbTextHAlign->Items->Add("Right side");

    cbTextVAlign->Items->Add("Top side");
    cbTextVAlign->Items->Add("Center");
    cbTextVAlign->Items->Add("Bottom side");

    bool bTextHAlign=true;
    ChangeTextHAlign =false;
    unsigned int iTextHAlign;

    bool bTextVAlign=true;
    ChangeTextVAlign =false;
    unsigned int iTextVAlign;

    //  Перенос по словам
    bool bTextWordBreak=true;
    ChangeTextWordBreak =false;
    unsigned int iTextWordBreak;

    //  Авто размер
    bool bTypeAutoSize=true;
    ChangeTypeAutoSize =false;
    unsigned int iTypeAutoSize;

    // Шрифт
    TMDelTList<AnsiString> NameFont;

//    int GetFont = EnumFonts(Canvas->Handle, NULL,(FARPROC)(&GetFontToMashine),(long)(&NameFont));
    EnumFonts(Canvas->Handle, NULL,(FARPROC)(&GetFontToMashine),(long)(&NameFont));
    for (int i=0; i<NameFont.Count; i++)
    {
        cbFontName->Items->Add(NameFont[i]);
    }
    bool bFontName=true;
    ChangeFontName =false;
    AnsiString sFontName;
    int iFontName;


    // Стиль Шрифта
    cbFontStyle->Items->Add("Normal");
    cbFontStyle->Items->Add("Italic");
    cbFontStyle->Items->Add("Bold");
    cbFontStyle->Items->Add("Bold italic");

    bool bFontStyle=true;
    ChangeFontStyle =false;
    unsigned int iFontStyle;

    // Размер
    for (int i=6; i<70; i+=2)
    {
        cbFontSize->Items->Add(IntToStr(i));
    }

    bool bFontSize=true;
    ChangeFontSize =false;
    unsigned int iFontSize;

    //  Шрифт зачеркнутый
    bool bFontStrikeOut=true;
    ChangeFontStrikeOut =false;
    unsigned int iFontStrikeOut;

    //  Шрифт подчеркнутый
    bool bFontUnderline=true;
    ChangeFontUnderline =false;
    unsigned int iFontUnderline;

    //  Бордюр
    iLine_Left =0;
    iLine_Top =0;
    iLine_Right =0;
    iLine_Bottom =0;
    iLine_CenterV =0;
    iLine_CenterH =0;

    bLineBorderCenterV =false;
    bLineBorderCenterH =false;


    //  Цвет шрифта
    bool bFontColor=true;
    ChangeFontColor =false;
    TColor tcFontColor;

    //  Цвет фона
    bBkColor=true;
    ChangeBkColor =false;
    TColor tcBkColor;

    // Цвет фона
    ChangeBkColorNot  =false;

//--- Проверка на одинаковое содержимое ячеек

    CellGrid->GetSelectCells(true);
    int End=CellGrid->ListFilling.Count;

    TCell* Cell00 =CellGrid->GetCellParam(CellGrid->ListFilling[0].x,CellGrid->ListFilling[0].y);
    TCell* CellEnd =CellGrid->GetCellParam(CellGrid->ListFilling[End-1].x,CellGrid->ListFilling[End-1].y);
    // TypeText
    iValueType = Cell00->CellFlags.ValueType;


    // Выравнивание
    iTextHAlign =Cell00->CellFlags.TextHAlign;
    iTextVAlign =Cell00->CellFlags.TextVAlign;

    // Переносить по словам
    iTextWordBreak =Cell00->CellFlags.TextWordBreak;

    // Авто размер
    iTypeAutoSize =Cell00->CellFlags.TypeAutoSize;

    // Стиль текста
    iFontStyle =Cell00->CellFlags.FontStyle;

    // Стиль текста
    iFontSize =Cell00->CellFlags.FontSize;

    // Имя шрифта
    sFontName =Cell00->FontName;

    // Шрифт зачеркнутый
    iFontStrikeOut =Cell00->CellFlags.FontStrikeOut;

    // Шрифт подчеркнутый
    iFontUnderline =Cell00->CellFlags.FontUnderline;

    //  Бордюр
    iLine_Left =Cell00->Line.WidthLeft;
    iLine_Top =Cell00->Line.WidthTop;
    iLine_Right =CellEnd->Line.WidthRight;
    iLine_Bottom =CellEnd->Line.WidthBottom;
    iLine_CenterV =Cell00->Line.WidthRight;
    iLine_CenterH =Cell00->Line.WidthBottom;

    iLine_Left =CellGrid->GetLeftBorder(CellGrid->ListFilling[0].x,CellGrid->ListFilling[0].y);
    iLine_Top =CellGrid->GetTopBorder(CellGrid->ListFilling[0].x,CellGrid->ListFilling[0].y);

    iLine_Right =CellGrid->GetRightBorder(CellGrid->ListFilling[End-1].x,CellGrid->ListFilling[End-1].y);
    iLine_Bottom =CellGrid->GetBottomBorder(CellGrid->ListFilling[End-1].x,CellGrid->ListFilling[End-1].y);

    iLine_CenterV =CellGrid->GetRightBorder(CellGrid->ListFilling[0].x,CellGrid->ListFilling[0].y);
    iLine_CenterH =CellGrid->GetBottomBorder(CellGrid->ListFilling[0].x,CellGrid->ListFilling[0].y);

    //  Цвет шрифта
    tcFontColor =Cell00->FontColor;

    //  Цвет фона
    tcBkColor =Cell00->bgColor;

//-----------------------------
    TCell* Cell;
    for (int i=0; i<End; i++)
    {
        Cell =CellGrid->GetCellParam(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y);
        // TypeText
        if (iValueType !=Cell->CellFlags.ValueType)
        {
            bValueType =false;
        }

        // Выравнивание
        if (iTextHAlign !=Cell->CellFlags.TextHAlign)
        {
            bTextHAlign=false;
        }
        if (iTextVAlign !=Cell->CellFlags.TextVAlign)
        {
            bTextVAlign=false;
        }

        // переносить по словам
        if (iTextWordBreak !=Cell->CellFlags.TextWordBreak)
        {
            bTextWordBreak =false;
        }
        // Авто размер
        if (iTypeAutoSize !=Cell->CellFlags.TypeAutoSize)
        {
            bTypeAutoSize =false;
        }

        // Стиль текста
        if (iFontStyle !=Cell->CellFlags.FontStyle)
        {
            bFontStyle=false;
        }

        // Размер текста
        if (iFontSize !=Cell->CellFlags.FontSize)
        {
            bFontSize=false;
        }

        // Имя шрифта
        if (sFontName !=Cell->FontName)
        {
            bFontName=false;
        }

        // Шрифт зачеркнутый
        if (iFontStrikeOut !=Cell->CellFlags.FontStrikeOut)
        {
            bFontStrikeOut =false;
        }
        // Шрифт подчеркнутый
        if (iFontUnderline !=Cell->CellFlags.FontUnderline)
        {
            bFontUnderline =false;
        }

        //  Бордюр
        //Top
        if (iLine_Top !=CellGrid->GetTopBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y) &&
            CellGrid->ListFilling[i].y ==CellGrid->ListFilling[0].y)
        {
            iLine_Top =-1;
        }

        //Left
        if (iLine_Left !=CellGrid->GetLeftBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y) &&
            CellGrid->ListFilling[i].x ==CellGrid->ListFilling[0].x)
        {
            iLine_Left =-1;
        }
        //Right
        if (iLine_Right !=CellGrid->GetRightBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y) &&
            CellGrid->ListFilling[i].x ==CellGrid->ListFilling[End-1].x)
        {
            iLine_Right =-1;
        }
        //Bottom
        if (iLine_Bottom !=CellGrid->GetBottomBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y) &&
            CellGrid->ListFilling[i].y ==CellGrid->ListFilling[End-1].y)
        {
            iLine_Bottom =-1;
        }

        //CenterH
        if (i>0 && i<End-1 &&
            CellGrid->ListFilling[i].y >=CellGrid->ListFilling[0].y &&
            CellGrid->ListFilling[i].y <CellGrid->ListFilling[End-1].y
        )
        {
            if (iLine_CenterH !=CellGrid->GetBottomBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y))
            {
                iLine_CenterH =-1;
            }
        }
        //CenterV
        if (i>0 && i<End-1 &&
            CellGrid->ListFilling[i].x >=CellGrid->ListFilling[0].x &&
            CellGrid->ListFilling[i].x <CellGrid->ListFilling[End-1].x

        )
        {
            if (iLine_CenterV !=CellGrid->GetRightBorder(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y))
            {
                iLine_CenterV =-1;
            }
        }

        // Цвет шрифта
        if (tcFontColor !=Cell->FontColor)
        {
            bFontColor =false;
        }

        // Цвет фона
        if (tcBkColor !=Cell->bgColor)
        {
            bBkColor =false;
        }
    }
    // Таблица
    if (CellGrid->ListFilling[0].x ==1 &&
        CellGrid->ListFilling[0].y ==1
    )
    {
        btLineOne_CenterH->Enabled =false;
        btLineOne_CenterV->Enabled =false;
        btLine->Enabled =false;
        btLineOne_Top->Enabled =false;
        btLineOne_Left->Enabled =false;
        btLineOne_Right->Enabled =false;
        btLineOne_Bottom->Enabled =false;
    }
    else if (CellGrid->ListFilling[0].x >1 &&
        CellGrid->ListFilling[0].y ==1
    )
    {// Столбец
        btLineOne_CenterH->Enabled =false;
        btLineOne_CenterV->Enabled =false;

        if (CellGrid->ListFilling[0].x ==CellGrid->ListFilling[End-1].x)
            bLineBorderCenterV =true;

        btLine->Enabled =false;
        btLineOne_Top->Enabled =false;
        btLineOne_Bottom->Enabled =false;
    }
    else if (CellGrid->ListFilling[0].y >1 &&
        CellGrid->ListFilling[0].x ==1
    )
    {// Строка
        btLineOne_CenterH->Enabled =false;
        btLineOne_CenterV->Enabled =false;

        if (CellGrid->ListFilling[0].y ==CellGrid->ListFilling[End-1].y)
            bLineBorderCenterH =true;

        btLine->Enabled =false;
        btLineOne_Left->Enabled =false;
        btLineOne_Right->Enabled =false;
    }
    else
    {
        if (CellGrid->ListFilling[0].x ==CellGrid->ListFilling[End-1].x &&
            CellGrid->ListFilling[0].y ==CellGrid->ListFilling[End-1].y
        )
        {
            iLine_CenterV =-2;
            iLine_CenterH =-2;
            btLineOne_CenterH->Enabled =false;
            btLineOne_CenterV->Enabled =false;
            bLineBorderCenterV =true;
            bLineBorderCenterH =true;
        }
        // Строка
        if (CellGrid->ListFilling[0].x ==CellGrid->ListFilling[End-1].x &&
            CellGrid->ListFilling[0].y !=CellGrid->ListFilling[End-1].y
        )
        {
            iLine_CenterV =-2;
            btLineOne_CenterV->Enabled =false;
            bLineBorderCenterV =true;
        }
        // Столбец
        if (CellGrid->ListFilling[0].x !=CellGrid->ListFilling[End-1].x &&
            CellGrid->ListFilling[0].y ==CellGrid->ListFilling[End-1].y
        )
        {
            iLine_CenterH =-2;
            btLineOne_CenterH->Enabled =false;
            bLineBorderCenterH =true;
        }
    }

    Cell =NULL;

    CellGrid->ClearListFilling();
//--- Проверка на одинаковое содержимое ячеек

    // Текст
    if (bValueType)
    {
        cbValueType->ItemIndex=iValueType;
    } else
        cbValueType->ItemIndex=-1;

    // Выравнивание
    if (bTextHAlign)
    {
        cbTextHAlign->ItemIndex=iTextHAlign;
    } else
        cbTextHAlign->ItemIndex=-1;

    if (bTextVAlign)
    {
        cbTextVAlign->ItemIndex=iTextVAlign;
    } else
        cbTextVAlign->ItemIndex=-1;

    // переносить по словам
    if (bTextWordBreak)
    {
        if (iTextWordBreak ==0)
            chbTextWordBreak->Checked =false;
        if (iTextWordBreak ==1)
            chbTextWordBreak->Checked =true;
    } else
        chbTextWordBreak->State = cbGrayed;

    // Авто размер
    if (bTypeAutoSize)
    {
        if (iTypeAutoSize ==0)
            chbTypeAutoSize->Checked =false;
        if (iTypeAutoSize ==1)
            chbTypeAutoSize->Checked =true;
    } else
        chbTypeAutoSize->State = cbGrayed;

    // Стиль текста
    if (bFontStyle)
    {
        cbFontStyle->ItemIndex=iFontStyle;
    } else
        cbFontStyle->ItemIndex=-1;

    // Размер текста
    if (bFontSize)
    {
        bool ok=false;
        for (int i=0; i<cbFontSize->Items->Count && !ok; i++)
        {
            if (StrToInt(cbFontSize->Items->Strings[i]) ==(int)iFontSize)
            {
                ok=true;
            }
            if (ok) cbFontSize->ItemIndex=i;
        }
        if (!ok)
        {
            cbFontSize->ItemIndex=-1;
            cbFontSize->Text =iFontSize;
        }
    } else
        cbFontSize->ItemIndex=-1;

    // Имя шрифта
    if (bFontName)
    {
        bool ok=false;
        for (int i=0; i<cbFontName->Items->Count && !ok; i++)
        {
            if (cbFontName->Items->Strings[i] == sFontName)
            {
                ok=true;
            }
            if (ok) cbFontName->ItemIndex=i;
        }
        if (!ok)
        {
            cbFontName->ItemIndex=-1;
            cbFontName->Text =sFontName;
        }
    } else
        cbFontName->ItemIndex=-1;

    // Шрифт зачеркнутый
    if (bFontStrikeOut)
    {
        if (iFontStrikeOut ==0)
            chbFontStrikeOut->Checked =false;
        if (iFontStrikeOut ==1)
            chbFontStrikeOut->Checked =true;
    } else
        chbFontStrikeOut->State = cbGrayed;

    // Шрифт подчеркнутый
    if (bFontUnderline)
    {
        if (iFontUnderline ==0)
            chbFontUnderline->Checked =false;
        if (iFontUnderline ==1)
            chbFontUnderline->Checked =true;
    } else
        chbFontUnderline->State = cbGrayed;

    // Цвет шрифта
    if (bFontColor)
    {
        cbFontColor->Color =tcFontColor;
    }
    else
    {
        cbFontColor->Color =clWhite;
    }

    // Цвет фона
    if (bBkColor)
    {
        cbBkColor->Color =tcBkColor;
    }
    else
    {
        cbBkColor->Color =clWhite;
    }

}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::CanselClick(TObject *Sender)
{// Отмена
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::OKClick(TObject *Sender)
{// OK
    // TypeText
    TCellFlag CF;
    if (cbValueType->ItemIndex != -1 && ChangeValueType)
        CellGrid->SetValueTypeRegion(cbValueType->ItemIndex);

    // Выравнивание
    if (cbTextHAlign->ItemIndex != -1 && ChangeTextHAlign)
        CellGrid->SetTextHAlignRegion(cbTextHAlign->ItemIndex);

    if (cbTextVAlign->ItemIndex != -1 && ChangeTextVAlign)
        CellGrid->SetTextVAlignRegion(cbTextVAlign->ItemIndex);

    // переносить по словам
    if (chbTextWordBreak->State != cbGrayed && ChangeTextWordBreak)
    {
        if (chbTextWordBreak->Checked)
        {
            CellGrid->SetTextWordBreakRegion(1);
            CellGrid->UseTextWordBreakRegion();
        }
        else
            CellGrid->SetTextWordBreakRegion(0);
    }

    // Авто размер
    if (chbTypeAutoSize->State != cbGrayed && ChangeTypeAutoSize)
    {
        if (chbTypeAutoSize->Checked)
            CellGrid->SetTypeAutoSizeRegion(1);
        else
            CellGrid->SetTypeAutoSizeRegion(0);
    }

    // Стиль текста
    if (cbFontStyle->ItemIndex != -1 && ChangeFontStyle)
        CellGrid->SetFontStyleRegion(cbFontStyle->ItemIndex);

    // Размер текста
    if (cbFontSize->ItemIndex == -1 && cbFontSize->Text.Length()>0 && ChangeFontSize)
    {
        if (ISINTEGER(cbFontSize->Text))
        {
            int i=StrToInt(cbFontSize->Text);
            CellGrid->SetFontSizeRegion(i);
        }
    }
    else if (cbFontSize->ItemIndex != -1 && ChangeFontSize)
        CellGrid->SetFontSizeRegion(StrToInt(cbFontSize->Items->Strings[cbFontSize->ItemIndex]));

    // Имя шрифта
    if (cbFontName->ItemIndex != -1 && ChangeFontName)
        CellGrid->SetFontNameRegion(cbFontName->Items->Strings[cbFontName->ItemIndex]);

    // Шрифт зачеркнутый
    if (chbFontStrikeOut->State != cbGrayed && ChangeFontStrikeOut)
    {
        if (chbFontStrikeOut->Checked)
            CellGrid->SetFontStrikeOutRegion(1);
        else
            CellGrid->SetFontStrikeOutRegion(0);
    }

    // Шрифт подчеркнутый
    if (chbFontUnderline->State != cbGrayed && ChangeFontUnderline)
    {
        if (chbFontUnderline->Checked)
        {
            CellGrid->SetFontUnderlineRegion(1);
        } else
            CellGrid->SetFontUnderlineRegion(0);
    }

    // Бордюр
    if (btLineFlood->Tag ==1 || btLineFloodClear->Tag==1)
        CellGrid->SetCellLineFlood(iLine_CenterV,iLine_CenterH,iLine_CenterV,iLine_CenterH);

    if (btLineOne_CenterH->Tag ==1)
        CellGrid->SetCellLineFloodHorz(iLine_CenterH);

    if (btLineOne_CenterV->Tag ==1)
        CellGrid->SetCellLineFloodVert(iLine_CenterV);

    // Бордюр обвести
    if (btLine->Tag ==1)
        CellGrid->SetCellLine(iLine_Left,iLine_Top,iLine_Right,iLine_Bottom);

    // Бордюр одинарный
    if (btLineOne_Top->Tag ==1)
        CellGrid->SetCellLineOne(2,iLine_Top);

    if (btLineOne_Left->Tag ==1)
        CellGrid->SetCellLineOne(1,iLine_Left);

    if (btLineOne_Right->Tag ==1)
        CellGrid->SetCellLineOne(3,iLine_Right);

    if (btLineOne_Bottom->Tag ==1)
        CellGrid->SetCellLineOne(4,iLine_Bottom);

    // Цвет шрифта
    if (ChangeFontColor)
        CellGrid->SetFontColorRegion(cbFontColor->Color);

    // Цвет фона
    if (ChangeBkColor)
        CellGrid->SetColorRegion(cbBkColor->Color, 1);

    // Цвет фона нет
    if (ChangeBkColorNot)
        CellGrid->SetColorRegion(cbBkColor->Color, 0);


    CanselClick(Sender);
}
//---------------------------------------------------------------------------
int CALLBACK GetFontToMashine(LOGFONT* lplf, TEXTMETRIC* lptm, DWORD dwType, LPARAM lpData)
{
    TMDelTList<AnsiString>* NameFont =(TMDelTList<AnsiString>*) lpData;
    NameFont->Add(new AnsiString(lplf->lfFaceName));
    return 1;
}

void __fastcall TCellParameter::btLineFloodClick(TObject *Sender)
{
    int iWidth=0;

    if (btLine0->Tag !=1)
    {
        btLineOne_CenterV->Down =true;
        btLineOne_CenterH->Down =true;
        btLineOne_Top->Down =true;
        btLineOne_Left->Down =true;
        btLineOne_Right->Down =true;
        btLineOne_Bottom->Down =true;
    }
    else
    {
        btLineOne_CenterV->Down =false;
        btLineOne_CenterH->Down =false;
        btLineOne_Top->Down =false;
        btLineOne_Left->Down =false;
        btLineOne_Right->Down =false;
        btLineOne_Bottom->Down =false;
    }


    btLineFlood->Tag=1;
    btLine->Tag=1;

    if (btLine0->Tag ==1)
        iWidth=0;
    if (btLine1->Tag ==1)
        iWidth=1;
    if (btLine2->Tag ==1)
        iWidth=2;

    iLine_Top=iWidth;
    iLine_Left =iWidth;
    iLine_Right=iWidth;
    iLine_Bottom =iWidth;

    iLine_CenterH =iWidth;
    iLine_CenterV =iWidth;

    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLine0Click(TObject *Sender)
{
    if ( IS (Sender,__classid(TSpeedButton)) )
    {
        btLine0->Tag=-1;
        btLine1->Tag=-1;
        btLine2->Tag=-1;
        TSpeedButton* SB = (TSpeedButton*)Sender;
        SB->Tag = 1;
    }
    InvalidateU2();
}
//---------------------------------------------------------------------------


void __fastcall TCellParameter::btLineClick(TObject *Sender)
{
    int iWidth=0;;

    if (btLine0->Tag !=1)
    {
        btLineOne_Top->Down =true;
        btLineOne_Left->Down =true;
        btLineOne_Right->Down =true;
        btLineOne_Bottom->Down =true;
    }
    else
    {
        btLineOne_Top->Down =false;
        btLineOne_Left->Down =false;
        btLineOne_Right->Down =false;
        btLineOne_Bottom->Down =false;
    }

    btLine->Tag=1;

    if (btLine0->Tag ==1)
        iWidth=0;
    if (btLine1->Tag ==1)
        iWidth=1;
    if (btLine2->Tag ==1)
        iWidth=2;

    iLine_Top=iWidth;
    iLine_Left =iWidth;
    iLine_Right=iWidth;
    iLine_Bottom =iWidth;

    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_TopClick(TObject *Sender)
{
    btLineOne_Top->Tag=1;

    if (btLine0->Tag != 1 || iLine_Top !=0)
    {
        if (iLine_Top >0)
        {
            iLine_Top=0;
            btLineOne_Top->Down =false;
        }
        else
        {
            btLineOne_Top->Down =true;
            if (btLine0->Tag ==1)
                iLine_Top=0;
            if (btLine1->Tag ==1)
                iLine_Top=1;
            if (btLine2->Tag ==1)
                iLine_Top=2;
        }
    } else
        btLineOne_Top->Down =false;
    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_LeftClick(TObject *Sender)
{
    btLineOne_Left->Tag=1;
    if (btLine0->Tag != 1 || iLine_Left !=0)
    {
        if (iLine_Left >0)
        {
            iLine_Left=0;
            btLineOne_Left->Down =false;
        }
        else
        {
            btLineOne_Left->Down =true;
            if (btLine0->Tag ==1)
                iLine_Left=0;
            if (btLine1->Tag ==1)
                iLine_Left=1;
            if (btLine2->Tag ==1)
                iLine_Left=2;
        }
    }
    else
        btLineOne_Left->Down =false;

    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_RightClick(TObject *Sender)
{
    btLineOne_Right->Tag=1;
    if (btLine0->Tag != 1 || iLine_Right !=0)
    {
        if (iLine_Right >0)
        {
            iLine_Right=0;
            btLineOne_Right->Down =false;
        }
        else
        {
            btLineOne_Right->Down =true;
            if (btLine0->Tag ==1)
                iLine_Right=0;
            if (btLine1->Tag ==1)
                iLine_Right=1;
            if (btLine2->Tag ==1)
                iLine_Right=2;
        }
    }
    else
        btLineOne_Right->Down =false;

    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_BottomClick(TObject *Sender)
{
    btLineOne_Bottom->Tag=1;
    if (btLine0->Tag != 1 || iLine_Bottom !=0)
    {
        if (iLine_Bottom >0)
        {
            iLine_Bottom=0;
            btLineOne_Bottom->Down =false;
        }
        else
        {
            btLineOne_Bottom->Down =true;
            if (btLine0->Tag ==1)
                iLine_Bottom=0;
            if (btLine1->Tag ==1)
                iLine_Bottom=1;
            if (btLine2->Tag ==1)
                iLine_Bottom=2;
        }
    }
    else
        btLineOne_Bottom->Down =false;
    InvalidateU2();
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::InvalidateU2()
{
    imExampleBorder->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::imExampleBorderPaint(TObject *Sender)
{
    int x=7;
    int y=7;
    int xWidth=163;
    int yHeight=83;

    imExampleBorder->Canvas->Brush->Color =clWhite;
    imExampleBorder->Canvas->Rectangle(-1,-1,179,99);

    imExampleBorder->Canvas->Pen->Color = clSilver;
    imExampleBorder->Canvas->Pen->Width=1;
    imExampleBorder->Canvas->Pen->Style =psDot;

    if (iLine_Top ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;

    }
    else
    {
        if (iLine_Top ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_Top;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (btLineOne_Top->Enabled)
    {
        imExampleBorder->Canvas->MoveTo(x,y);
        imExampleBorder->Canvas->LineTo(x+xWidth,y);
    }

    if (iLine_Right ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;

    } else
    {
        if (iLine_Right ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_Right;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (btLineOne_Right->Enabled)
    {
        imExampleBorder->Canvas->MoveTo(x+xWidth,y);
        imExampleBorder->Canvas->LineTo(x+xWidth,y+yHeight);
    }
    if (iLine_Bottom ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;

    } else
    {
        if (iLine_Bottom ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_Bottom;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (btLineOne_Bottom->Enabled)
    {
        imExampleBorder->Canvas->MoveTo(x+xWidth,y+yHeight);
        imExampleBorder->Canvas->LineTo(x,y+yHeight);
    }
    if (iLine_Left ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;

    } else
    {
        if (iLine_Left ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_Left;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (btLineOne_Left->Enabled)
    {
        imExampleBorder->Canvas->MoveTo(x,y+yHeight);
        imExampleBorder->Canvas->LineTo(x,y);
    }
    
    if (iLine_CenterV ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;
    }
    else
    {
        if (iLine_CenterV ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_CenterV;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (!bLineBorderCenterV)
    {
        imExampleBorder->Canvas->MoveTo(x+xWidth/2,y);
        imExampleBorder->Canvas->LineTo(x+xWidth/2,y+yHeight);
    }

    if (iLine_CenterH ==-1)
    {
        imExampleBorder->Canvas->Pen->Color = clGray;
        imExampleBorder->Canvas->Pen->Width=3;
        imExampleBorder->Canvas->Pen->Style =psDot;

    }
    else
    {
        if (iLine_CenterH ==0)
        {
            imExampleBorder->Canvas->Pen->Color = clSilver;
            imExampleBorder->Canvas->Pen->Width=1;
            imExampleBorder->Canvas->Pen->Style =psDot;
        } else
        {
            imExampleBorder->Canvas->Pen->Color = clBlack;
            imExampleBorder->Canvas->Pen->Width=iLine_CenterH;
            imExampleBorder->Canvas->Pen->Style =psSolid;
        }
    }
    if (!bLineBorderCenterH)
    {
        imExampleBorder->Canvas->MoveTo(x,y+yHeight/2);
        imExampleBorder->Canvas->LineTo(x+xWidth,y+yHeight/2);
    }
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_CenterHClick(TObject *Sender)
{
    btLineOne_CenterH->Tag=1;

    if (btLine0->Tag != 1 || iLine_CenterH !=0)
    {
        if (iLine_CenterH >0)
        {
            iLine_CenterH=0;
            btLineOne_CenterH->Down =false;
        }
        else
        {
            btLineOne_CenterH->Down =true;
            if (btLine0->Tag ==1)
                iLine_CenterH=0;
            if (btLine1->Tag ==1)
                iLine_CenterH=1;
            if (btLine2->Tag ==1)
                iLine_CenterH=2;
        }
    }
    else
        btLineOne_CenterH->Down =false;
    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineOne_CenterVClick(TObject *Sender)
{

    btLineOne_CenterV->Tag=1;
    if (btLine0->Tag != 1 || iLine_CenterV !=0)
    {
        if (iLine_CenterV >0)
        {
            iLine_CenterV=0;
            btLineOne_CenterV->Down =false;
        }
        else
        {
            btLineOne_CenterV->Down =true;
            if (btLine0->Tag ==1)
                iLine_CenterV=0;
            if (btLine1->Tag ==1)
                iLine_CenterV=1;
            if (btLine2->Tag ==1)
                iLine_CenterV=2;
        }
    }
    else
        btLineOne_CenterV->Down =false;

    InvalidateU2();

}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::btLineFloodClearClick(TObject *Sender)
{
    int iWidth=0;

    
    btLineOne_CenterV->Down =false;
    btLineOne_CenterH->Down =false;
    btLineOne_Top->Down =false;
    btLineOne_Left->Down =false;
    btLineOne_Right->Down =false;
    btLineOne_Bottom->Down =false;

    btLineFloodClear->Tag=1;

    iLine_Top=iWidth;
    iLine_Left =iWidth;
    iLine_Right=iWidth;
    iLine_Bottom =iWidth;
    iLine_CenterH =iWidth;
    iLine_CenterV =iWidth;

    InvalidateU2();
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbValueTypeChange(TObject *Sender)
{
    ChangeValueType =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbTextHAlignChange(TObject *Sender)
{
    ChangeTextHAlign =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbTextVAlignChange(TObject *Sender)
{
    ChangeTextVAlign =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::chbTextWordBreakClick(TObject *Sender)
{
    ChangeTextWordBreak =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::chbTypeAutoSizeClick(TObject *Sender)
{
    ChangeTypeAutoSize =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbFontStyleChange(TObject *Sender)
{
    ChangeFontStyle =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbFontSizeChange(TObject *Sender)
{
    ChangeFontSize =true;    
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::cbFontNameChange(TObject *Sender)
{
    ChangeFontName =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::chbFontUnderlineClick(TObject *Sender)
{
    ChangeFontUnderline =true;
}
//---------------------------------------------------------------------------

void __fastcall TCellParameter::chbFontStrikeOutClick(TObject *Sender)
{
    ChangeFontStrikeOut =true;
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::FontColorChanged(TObject *Sender)
{
    ChangeFontColor  =true;
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::BkColorChanged(TObject *Sender)
{
    if (cbBkColor->Tag ==1)
    {
        ChangeBkColor  =false;
        ChangeBkColorNot  =true;
        cbBkColor->Color =clWhite;
    }
    else
    {
        ChangeBkColor  =true;
        ChangeBkColorNot  =false;
    }
    pbBkColor->Invalidate();
}

void __fastcall TCellParameter::btBkColorNotClick(TObject *Sender)
{
    ChangeBkColor  =false;
    ChangeBkColorNot  =true;
    cbBkColor->Color =clWhite;
    pbBkColor->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TCellParameter::pbBkColorPaint(TObject *Sender)
{

    // Цвет фона
    if (bBkColor)
    {
        pbBkColor->Canvas->Brush->Color =cbBkColor->Color;
        pbBkColor->Canvas->Pen->Color =clBlack;
    }
    else
    {
        pbBkColor->Canvas->Brush->Color =clBtnFace;
        pbBkColor->Canvas->Pen->Color =clBtnFace;
    }

    pbBkColor->Canvas->Rectangle(0,0,pbBkColor->Width -1,pbBkColor->Height -1);
}
//---------------------------------------------------------------------------

