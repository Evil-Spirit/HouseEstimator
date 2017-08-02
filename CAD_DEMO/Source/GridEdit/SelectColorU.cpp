//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "ColorComboBoxU.h"
#include "CellParameterU.h"
#include "SelectColorU.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectColor *SelectColor;
//---------------------------------------------------------------------------
__fastcall TSelectColor::TSelectColor(TComponent* Owner,TCellGrid* _CellGrid, TColorComboBox* _ColorComboBox)
    : TForm(Owner)
{
    CellGrid = _CellGrid;
    ColorComboBox =_ColorComboBox;

    bAutoColor =false;

    CL11->Brush->Color =(TColor)RGB(0,0,0);
    CL12->Brush->Color =(TColor)RGB(128,0,0);
    CL13->Brush->Color =(TColor)RGB(255,0,0);
    CL14->Brush->Color =(TColor)RGB(255,0,255);
    CL15->Brush->Color =(TColor)RGB(255,153,204);

    CL21->Brush->Color =(TColor)RGB(153,51,0);
    CL22->Brush->Color =(TColor)RGB(255,102,0);
    CL23->Brush->Color =(TColor)RGB(255,153,0);
    CL24->Brush->Color =(TColor)RGB(255,204,0);
    CL25->Brush->Color =(TColor)RGB(255,204,153);

    CL31->Brush->Color =(TColor)RGB(51,51,0);
    CL32->Brush->Color =(TColor)RGB(128,128,0);
    CL33->Brush->Color =(TColor)RGB(153,204,0);
    CL34->Brush->Color =(TColor)RGB(255,255,0);
    CL35->Brush->Color =(TColor)RGB(255,255,153);

    CL41->Brush->Color =(TColor)RGB(0,51,0);
    CL42->Brush->Color =(TColor)RGB(0,128,0);
    CL43->Brush->Color =(TColor)RGB(51,153,102);
    CL44->Brush->Color =(TColor)RGB(0,255,0);
    CL45->Brush->Color =(TColor)RGB(204,255,204);

    CL51->Brush->Color =(TColor)RGB(0,51,102);
    CL52->Brush->Color =(TColor)RGB(0,128,128);
    CL53->Brush->Color =(TColor)RGB(51,204,204);
    CL54->Brush->Color =(TColor)RGB(0,255,255);
    CL55->Brush->Color =(TColor)RGB(204,255,255);

    CL61->Brush->Color =(TColor)RGB(0,0,128);
    CL62->Brush->Color =(TColor)RGB(0,0,255);
    CL63->Brush->Color =(TColor)RGB(51,102,255);
    CL64->Brush->Color =(TColor)RGB(0,204,255);
    CL65->Brush->Color =(TColor)RGB(153,204,255);

    CL71->Brush->Color =(TColor)RGB(51,51,153);
    CL72->Brush->Color =(TColor)RGB(102,102,153);
    CL73->Brush->Color =(TColor)RGB(128,0,128);
    CL74->Brush->Color =(TColor)RGB(153,51,102);
    CL75->Brush->Color =(TColor)RGB(204,153,255);

    CL81->Brush->Color =(TColor)RGB(51,51,51);
    CL82->Brush->Color =(TColor)RGB(128,128,128);
    CL83->Brush->Color =(TColor)RGB(150,150,150);
    CL84->Brush->Color =(TColor)RGB(192,192,192);
    CL85->Brush->Color =(TColor)RGB(255,255,255);
}
//---------------------------------------------------------------------------
void __fastcall TSelectColor::CL11MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if ( IS (Sender,__classid(TShape)) )
    {
        CL11->Pen->Style =psClear;
        CL12->Pen->Style =psClear;
        CL13->Pen->Style =psClear;
        CL14->Pen->Style =psClear;
        CL15->Pen->Style =psClear;

        CL21->Pen->Style =psClear;
        CL22->Pen->Style =psClear;
        CL23->Pen->Style =psClear;
        CL24->Pen->Style =psClear;
        CL25->Pen->Style =psClear;

        CL31->Pen->Style =psClear;
        CL32->Pen->Style =psClear;
        CL33->Pen->Style =psClear;
        CL34->Pen->Style =psClear;
        CL35->Pen->Style =psClear;

        CL41->Pen->Style =psClear;
        CL42->Pen->Style =psClear;
        CL43->Pen->Style =psClear;
        CL44->Pen->Style =psClear;
        CL45->Pen->Style =psClear;

        CL51->Pen->Style =psClear;
        CL52->Pen->Style =psClear;
        CL53->Pen->Style =psClear;
        CL54->Pen->Style =psClear;
        CL55->Pen->Style =psClear;

        CL61->Pen->Style =psClear;
        CL62->Pen->Style =psClear;
        CL63->Pen->Style =psClear;
        CL64->Pen->Style =psClear;
        CL65->Pen->Style =psClear;

        CL71->Pen->Style =psClear;
        CL72->Pen->Style =psClear;
        CL73->Pen->Style =psClear;
        CL74->Pen->Style =psClear;
        CL75->Pen->Style =psClear;

        CL81->Pen->Style =psClear;
        CL82->Pen->Style =psClear;
        CL83->Pen->Style =psClear;
        CL84->Pen->Style =psClear;
        CL85->Pen->Style =psClear;

        TShape* SC = (TShape*)Sender;
        SC->Pen->Style =psSolid;
    }

}
//---------------------------------------------------------------------------
void __fastcall TSelectColor::CL11MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if ( IS (Sender,__classid(TShape)) )
    {
        TShape* SC = (TShape*)Sender;
        GetColors->Brush->Color =SC->Brush->Color;
        bAutoColor =false;
        CloseU2();
    }
}
//---------------------------------------------------------------------------
TColor __fastcall TSelectColor::GetColor()
{
    return GetColors->Brush->Color;
}
//---------------------------------------------------------------------------
void __fastcall TSelectColor::CloseU2()
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TSelectColor::AutoFontColorClick(TObject *Sender)
{
        GetColors->Brush->Color =shAutoColor->Brush->Color;
        bAutoColor =true;
        CloseU2();
}
//---------------------------------------------------------------------------
void __fastcall TSelectColor::FormDeactivate(TObject *Sender)
{
    if (ColorComboBox !=NULL)
    {
        TPoint point,pointclient;
        GetCursorPos(&point);
        pointclient =ColorComboBox->ScreenToClient(point);
        CloseU2();
        int x =pointclient.x;
        int y =pointclient.y;
        if (x > 0 && x < ColorComboBox->Width &&
            y >0 && y < ColorComboBox->Height
        )
        {
            Tag =2;
        }
        else
        {
            Tag =0;
        }
    }
    else
    {
        CloseU2();
    }
}
//---------------------------------------------------------------------------

