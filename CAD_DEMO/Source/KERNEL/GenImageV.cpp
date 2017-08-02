//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "GenImageV.h"
#include "MDIPointerEditV.h"
#include "MDITVV.h"
#include "MyGL.h"
#include "IntExplorerV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGenImage *GenImage;
//---------------------------------------------------------------------------
__fastcall TGenImage::TGenImage(TComponent* Owner,TMDITV* _TV,Graphics::TBitmap* _BMP,Graphics::TBitmap* _mask)
    : TForm(Owner)
{
    mask = _mask;
    bmp = _BMP;
    TV = _TV;
    BMPS = new TPointer<TBMPSet>();
    EditPointer(this,LIST,BMPS,AnsiString(), TBMPSet::StaticType);
    ((TMDIPointerEdit*)LIST->Controls[0])->Change = OnLISTChange;
    sColor->Brush->Color = ExplorerBackColor;
}
//---------------------------------------------------------------------------

void __fastcall TGenImage::FormDestroy(TObject *Sender)
{
    delete BMPS;    
}
//---------------------------------------------------------------------------
void __fastcall TGenImage::sColorMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ColorDialog1->Color = sColor->Brush->Color;
    if (ColorDialog1->Execute())
        sColor->Brush->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------
void __fastcall TGenImage::OnLISTChange(TObject *Sender)
{
    ((TMDIPointerEdit*)LIST->Controls[0])->Apply();
    Image->Picture->Bitmap->Assign(NULL);
    btOK->Enabled = false;
    if (BMPS->ADR)
    {
        btGen->Enabled = true;
        lWidth->Caption = IntToStr(BMPS->ADR->IL->Width);
        lHeight->Caption = IntToStr(BMPS->ADR->IL->Height);
        bmp->Width = BMPS->ADR->IL->Width;
        bmp->Width = BMPS->ADR->IL->Height;
    }
    else
    {
        lWidth->Caption = IntToStr(0);
        lHeight->Caption = IntToStr(0);
        btGen->Enabled = false;
        bmp->Width = 0;
        bmp->Width = 0;
    }
}

void __fastcall TGenImage::btGenClick(TObject *Sender)
{
    Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
    if (!BMPS->ADR)
        return;
    Bitmap->HandleType = bmDIB;
    Bitmap->Width = 2*BMPS->ADR->IL->Width;
    Bitmap->Height = 2*BMPS->ADR->IL->Height;

    bool CoordVis = TV->View->Coordinates->Visible;
    bool antialiasing = TV->Attributes->Antialiasing;
    bool AntiAliasingLine = TV->AntiAliasingLine;
    TColor col = TV->View->BackgroundColor;

    TV->View->Coordinates->Visible = false;
    TV->View->BackgroundColor = sColor->Brush->Color;
    TV->Attributes->Antialiasing = cbAA->Checked;
    TV->AntiAliasingLine = cbAntiAliasingLine->Checked;

    InvalidateTextures();

    TV->View->GetImage2(Bitmap);

	bmp->HandleType = bmDIB;
    bmp->Width = BMPS->ADR->IL->Width;
    bmp->Height = BMPS->ADR->IL->Height;
    scale2x(Bitmap,bmp);
    delete Bitmap;
    /*
    for (int i=0;i<bmp->Width;i++)
        for (int j=0;j<bmp->Height;j++)
        {
            bmp->Canvas->Pixels[i][j] = SmoothMatrix(bmp, i, j, 2);
        }
	*/
    mask->Width = bmp->Width;
    mask->Height = bmp->Height;
    /*bmp->HandleType = bmDIB;
    if (cbSmooth->Checked)
    {
        bmp->Width = BMPS->ADR->IL->Width;
        bmp->Height = BMPS->ADR->IL->Height;
    }
    else
    {
        bmp->Width = BMPS->ADR->IL->Width;
        bmp->Height = BMPS->ADR->IL->Height;
    }
    mask->Width = bmp->Width;
    mask->Height = bmp->Height;
    bool CoordVis = TV->View->Coordinates->Visible;
    bool antialiasing = TV->Attributes->Antialiasing;
    bool AntiAliasingLine = TV->AntiAliasingLine;
    TColor col = TV->View->BackgroundColor;

    TV->View->Coordinates->Visible = false;
    TV->View->BackgroundColor = sColor->Brush->Color;
    TV->Attributes->Antialiasing = cbAA->Checked;
    TV->AntiAliasingLine = cbAntiAliasingLine->Checked;

    InvalidateTextures();

    TV->View->GetImage2(bmp);

    TImageList* IL = new TImageList(NULL);
    if (cbSmooth->Checked)
    {
       // bmp->Canvas->Brush->Color = clWhite;
       // bmp->Canvas->FloodFill(0,0,sColor->Brush->Color,fsSurface	);
       Smooth(bmp,3);
//        BMPResize(bmp,BMPS->ADR->IL->Width,BMPS->ADR->IL->Height);
//        ImageResize(mask,BMPS->ADR->IL->Width,BMPS->ADR->IL->Height);
    }
    */
    TImageList* IL = new TImageList(NULL);

    IL->Width = bmp->Width;
    IL->Height = bmp->Height;
    IL->AddMasked(bmp,sColor->Brush->Color);
    IL->Draw(mask->Canvas,0,0,0,dsNormal,itMask,true);

    TV->AntiAliasingLine = AntiAliasingLine;
    TV->View->Coordinates->Visible = CoordVis;
    TV->Attributes->Antialiasing = antialiasing;
    InvalidateTextures();
    TV->View->BackgroundColor = col;

    Image->Picture->Bitmap->Assign(bmp);
    Image->Width = bmp->Width;
    Image->Height = bmp->Height;
    Image->Top = (Panel1->Height-Image->Height)/2;
    Image->Left = (Panel1->Width-Image->Width)/2;
    btOK->Enabled = true;
    delete IL;
}
//---------------------------------------------------------------------------
void __fastcall TGenImage::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    int nWidth;
    int nHeight;
    if ( Button == mbLeft)
    {
        nWidth = Image->Width*1.25;
        nHeight = Image->Height*1.25;
    }
    else
    {
        nWidth = Image->Width/1.25;
        nHeight = Image->Height/1.25;
    }

    if ( bmp->Width>MIN(nWidth,Image->Width) &&  bmp->Width<MAX(nWidth,Image->Width))
    {
        Image->Width = bmp->Width;
        Image->Height = bmp->Height;
    }
    else
    {
        Image->Width = nWidth;
        Image->Height = nHeight;
    }

    Image->Top = (Panel1->Height-Image->Height)/2;
    Image->Left = (Panel1->Width-Image->Width)/2;
}
//---------------------------------------------------------------------------
