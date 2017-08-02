//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "Label3DV.h"
#include "AUIV.h"

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

TMyObject* TLabel3D::CreateFunction()
{
    return new TLabel3D();
}

const AnsiString aRotateble = AnsiString("Rotateble");

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

TLabel3D::TLabel3D()
{
    RegisterNewClass< TElement, TLabel3D >(this,false,&CreateFunction);
    Rotateble = false;
    RegisterField(&Rotateble,&aRotateble,mtBool);
    VisLabel = new TVisLabel(NULL);
    VisLabel->Transformation->Order = toTraRotSca;
    VisLabel->Transformation->Rotation->Order = roZXY;
    VisText = new TVisText(NULL);
    VisText->Transformation->Order = toTraRotSca;
    VisText->Transformation->Rotation->Order = roZXY;
    VisText->Font->Height = -10;
    VisText->Depth = 0;
    VisText->Quality = 0.5;
}

TLabel3D::~TLabel3D()
{
    RemoveRenderFromTree();
    delete VisLabel;
    delete VisText;
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
    VisLabel->Caption = Description;
    VisLabel->ShiftX = -VisLabel->Width/2;
    VisLabel->ShiftY = -VisLabel->Height/2;
    VisText->Text = Description;
    
}

void TLabel3D::UserChangePosition(const TIntVec& Move,const TIntVec& Rotate)
{
    if (Rotateble)
        TElement::UserChangePosition(Move,Rotate);
    else
        TElement::UserChangePosition(Move,ZEROINTVEC);
}


