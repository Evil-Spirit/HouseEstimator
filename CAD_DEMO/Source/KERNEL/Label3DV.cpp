//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "Label3DV.h"
#include "AUIV.h"
#include "math.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TClassNode* TMetaLabel3D::StaticType = NULL;
TClassNode* TLabel3D::StaticType = NULL;


//------------------------TMetaLabel3D--------------------------------------------------
TMyObject* TMetaLabel3D::CreateFunction()
{
    return new TMetaLabel3D();
}

TMetaLabel3D::TMetaLabel3D(TMetaNode *Parent,int _ID,const AnsiString& Name)
    :TMetaElement(Parent, _ID,  Name)
{
    RegisterNewClass< TMetaElement, TMetaLabel3D >(this,false,&CreateFunction);
    ImageIndex=iiMetaLabel3D;
}

TMetaLabel3D::TMetaLabel3D()
{
    RegisterNewClass< TMetaElement, TMetaLabel3D >(this,false,&CreateFunction);
    ImageIndex=iiMetaLabel3D;
}





//------------------------TLabel3D--------------------------------------------------
/*void TLabel3D::StandartRender2D(TDrawView *DrawView)
{
  if (Labels3D.Count)
  {
    DrawView->Font->Assign(Labels3D.Items[0]->Font);
    DrawView->TextOut(this, -(DrawView->TextWidth(Text.c_str()))/2,
                            -(DrawView->TextHeight(Text.c_str()))/2,Text.c_str());
  }
} */

/*TLabel3D::TLabel3D(TMainTree *_MyTree,TMetaNode *_Meta)
    :TElement(_MyTree,_Meta)
{
    RegisterNewClass< TElement, TLabel3D >(this,false,&CreateFunction);
    if (typeid(*_Meta)!=typeid(TMetaLabel3D))
    {
        Application->MessageBox("Ожидалось TMetaLabel3D, получено Unknown. Приложение СТОП.","Error");
        Application->Terminate();
        return;
    }
    Rotateble = false;
    Label_Node = new TVisNode(NULL);
    Label_Node->Transformation->Order = toTraRotSca;
    Label_Node->Transformation->Rotation->Order = roZXY;
    RegisterField(&Rotateble,&aRotateble,mtBool);
    MGT->AddRender(1,this,Label_Node);
    CreateView();
    CurrentEnabled = true;
    CustomEnabled = true;
} */

TMyObject* TLabel3D::CreateFunction()
{
    return new TLabel3D();
}

const AnsiString aRotateble = AnsiString("Rotateble");

TLabel3D::TLabel3D()
{
    RegisterNewClass< TElement, TLabel3D >(this,false,&CreateFunction);
    Rotateble = false;
    RegisterField(&Rotateble,&aRotateble,mtBool);
    Label = new TVisPrimitiveObj(NULL);
    Label->Transformation->Order = toTraRotSca;
    Label->Transformation->Rotation->Order = roZXY;
    VT = new TVisTexture(NULL);
}

TLabel3D::~TLabel3D()
{
    RemoveRenderFromTree();
    delete Label;
    delete VT;
}

void TLabel3D::SetText(const AnsiString& _Text)
{
    Description = _Text;
    ForceCreateView();
}

void TLabel3D::SetCharText(char* _Text )
{
    SetText(AnsiString(_Text));
}

const MBTi Factor = 0.015;

void TLabel3D::StandartCreateView()
{
    Graphics::TBitmap* bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    bmp->Canvas->Font->Size = 15;
    bmp->Canvas->Font->Name = "Arial";
    int THeight = bmp->Canvas->TextHeight(Description);
    int TWidth = bmp->Canvas->TextWidth(Description);
    int RHeight = 0;
    int RWidth = 0;
    int i=0;
    while ( RHeight<THeight )
        RHeight = pow(2,i++);
    i=0;        
    while ( RWidth<TWidth )
        RWidth = pow(2,i++);

    TIntVec vS = TIntVec(MBTi(RWidth)*Factor,MBTi(RHeight)*Factor,0.1);
    bmp->Canvas->Brush->Color = clBlack;
    bmp->Canvas->Pen->Color = clWhite;
    bmp->Canvas->Font->Color = clWhite;
    bmp->Width = RWidth;
    bmp->Height = RHeight;
    bmp->Canvas->FillRect(TRect(0,0,RWidth,RHeight));
    bmp->Canvas->TextOut((RWidth-TWidth)/2,(RHeight-THeight)/2,Description);
    VT->Bitmap->Assign(bmp);
    VT->Invalidate();
    VT->SetMaskAlpha(1,clBlack,0);
//    VT->MagFilter = tfLinear_Linear;
//    VT->MinFilter = tfLinear_Linear;
    delete bmp;

    Label->Init();
    Label->AddPrimitiveArray(GL_POLYGON);

    Label->AddIndex( Label->Points->Add( ToVec(vS.y/2,  vS.x/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(-vS.y/2, vS.x/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(-vS.y/2, -vS.x/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(vS.y/2,- vS.x/2,0),ZEROVEC,ZEROVEC ) );

    Label->CalcNormals();
    Label->Material = MaterialDefault;

    Label->TextureFlags->ScaleX = 1/vS.x;
    Label->TextureFlags->ScaleY = -1/vS.y;
/*    Label->AddIndex( Label->Points->Add( ToVec(vS.x/2,  vS.y/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(-vS.x/2, vS.y/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(-vS.x/2, -vS.y/2,0),ZEROVEC,ZEROVEC ) );
    Label->AddIndex( Label->Points->Add( ToVec(vS.x/2,- vS.y/2,0),ZEROVEC,ZEROVEC ) );

    Label->CalcNormals();
    Label->Material = MaterialDefault;

    Label->TextureFlags->ScaleX = 1/vS.x;
    Label->TextureFlags->ScaleY = 1/vS.y;*/
    Label->TextureFlags->ShiftX = 0.5;
    Label->TextureFlags->ShiftY = 0.5;
    Label->Texture = VT;
    Label->Textured = true;
    Label->Primitive[0]->Texture = VT;
    Label->Primitive[0]->Textured = true;
//    Label->TextureFlags->Mode = txLinearXY;
    Label->TextureFlags->Mode = txLinearYX;
    Label->CalcTexture();
    InvalidateTextures();

    NeedTexturing = false;



/*    TStringList *LL = new TStringList();
    AnsiString _Text = Description;
    ReplaceAll(_Text, AnsiString("^"), AnsiString(" "));
    ReplaceAll(_Text, AnsiString(" "), AnsiString("^"));
    ReplaceAll(_Text, AnsiString("_"), AnsiString("^"));
    ReplaceAll(_Text, AnsiString("\n"), AnsiString("_"));
    LL->Delimiter = '_';
    LL->QuoteChar = '_';
    LL->DelimitedText = _Text;
    Label_Node->Clear();

    Labels3D.RealClear();
    for (int i=0;i<LL->Count;i++)
    {
        TVisLabel *VL = new TVisLabel(NULL);
        VL->Transformation->Order = toTraRotSca;
        VL->Transformation->Rotation->Order = roZXY;
        VL->Font->Color=MyMeta->VM->ColorDiffuse->Color;
        _Text = LL->Strings[i];
        ReplaceAll(_Text, AnsiString("^"), AnsiString(" "));
        VL->Caption = _Text;
//        VL->Texture->Invalidate();
//        VL->Texture->Enabled = true;
        Labels3D.Add(VL);
    }
    delete LL;
    double max_Width=0;
    double sum_Height=0;
    for (int i=0;i<Labels3D.Count;i++)
    {
        sum_Height = sum_Height+Labels3D.Items[i]->Height;
        if (max_Width<Labels3D.Items[i]->Width);
            max_Width = Labels3D.Items[i]->Width;
    }
    double cur_SumHeight=0;
    for (int i=0;i<Labels3D.Count;i++)
    {
        Labels3D.Items[i]->ShiftX = -(max_Width/2);
        Labels3D.Items[i]->ShiftY = -(sum_Height/2)+cur_SumHeight;
        cur_SumHeight = cur_SumHeight+Labels3D.Items[i]->Height;
        Label_Node->Add(Labels3D.Items[i]);
    }
    AUI.InvalidateView(); */
}


/*TMyObject* TLabel3D::CreateFunction()
{
    return new TLabel3D();
}

const AnsiString aRotateble = AnsiString("Rotateble");

TLabel3D::TLabel3D()
{
    RegisterNewClass< TElement, TLabel3D >(this,false,&CreateFunction);
    Rotateble = false;
    RegisterField(&Rotateble,&aRotateble,mtBool);
    Label_Node = new TVisNode(NULL);
    Label_Node->Transformation->Order = toTraRotSca;
    Label_Node->Transformation->Rotation->Order = roZXY;
}

TLabel3D::~TLabel3D()
{
    Labels3D.RealClear();
    RemoveRenderFromTree();
    Label_Node->Clear();
    delete Label_Node;
}

void TLabel3D::SetText(const AnsiString& _Text)
{
    Description = _Text;
    ForceCreateView();
}

void TLabel3D::SetCharText(char* _Text )
{
    SetText(AnsiString(_Text));
}

void TLabel3D::StandartCreateView()
{
    TStringList *LL = new TStringList();
    AnsiString _Text = Description;
    ReplaceAll(_Text, AnsiString("^"), AnsiString(" "));
    ReplaceAll(_Text, AnsiString(" "), AnsiString("^"));
    ReplaceAll(_Text, AnsiString("_"), AnsiString("^"));
    ReplaceAll(_Text, AnsiString("\n"), AnsiString("_"));
    LL->Delimiter = '_';
    LL->QuoteChar = '_';
    LL->DelimitedText = _Text;
    Label_Node->Clear();

    Labels3D.RealClear();
    for (int i=0;i<LL->Count;i++)
    {
        TVisLabel *VL = new TVisLabel(NULL);
        VL->Transformation->Order = toTraRotSca;
        VL->Transformation->Rotation->Order = roZXY;
        VL->Font->Color=MyMeta->VM->ColorDiffuse->Color;
        _Text = LL->Strings[i];
        ReplaceAll(_Text, AnsiString("^"), AnsiString(" "));
        VL->Caption = _Text;
//        VL->Texture->Invalidate();
//        VL->Texture->Enabled = true;
        Labels3D.Add(VL);
    }
    delete LL;
    double max_Width=0;
    double sum_Height=0;
    for (int i=0;i<Labels3D.Count;i++)
    {
        sum_Height = sum_Height+Labels3D.Items[i]->Height;
        if (max_Width<Labels3D.Items[i]->Width);
            max_Width = Labels3D.Items[i]->Width;
    }
    double cur_SumHeight=0;
    for (int i=0;i<Labels3D.Count;i++)
    {
        Labels3D.Items[i]->ShiftX = -(max_Width/2);
        Labels3D.Items[i]->ShiftY = -(sum_Height/2)+cur_SumHeight;
        cur_SumHeight = cur_SumHeight+Labels3D.Items[i]->Height;
        Label_Node->Add(Labels3D.Items[i]);
    }
    AUI.InvalidateView();
}*/
