  //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDITVV.h"
//#include "MDITransformationV.h"
#include "MDIColorsV.h"
#include "MetaClasses.h"
#include "ImgLibV.h"
#include "MultiElementV.h"
#include "AUIV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDI3DV"
#pragma link "VisAttr"
#pragma link "VisCam"
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisComp"
#pragma link "VisLight"
#pragma link "VisMat"
#pragma link "VisObj"
#pragma link "VisView"
#pragma link "VisPoly"
#pragma link "VisPrimitiveObj"
#pragma link "VisShape"
#pragma link "VisTex"
#pragma link "VisCntrl"
#pragma link "VisTimer"
#pragma resource "*.dfm"
TMDITV *MDITV;
//---------------------------------------------------------------------------
__fastcall TMDITV::TMDITV(TComponent* Owner,TWinControl *_Parent,TMainTree* MT)
    : TMDI3D(Owner,MT)
{
    Parent=_Parent;
    Align=alClient;
    EL = NULL;
//    Mode = NULL;
}
//---------------------------------------------------------------------------
void TMDITV::CustomRender(TVisCustomView *aView)
{
//    VisNode->Render(aView);
//    BIF->CustomRender();
    if (AUI.ActiveView == this)
    {
        if (DiscInvisible->Enabled)
            DiscInvisible->Render(aView);
        if (EL&&EL->MyRender())
        {
            EL->MyRender()->Transformation->Translation->AsMathVector=ZEROVEC;
            EL->MyRender()->Transformation->Rotation->AsMathVector=ZEROVEC;
            if ( EL->Is(TMultiElement::StaticType) )
            {
                ((TMultiElement*)EL)->VTRANS->Transformation->Translation->AsMathVector=ZEROVEC;
                ((TMultiElement*)EL)->VTRANS->Transformation->Rotation->AsMathVector=ZEROVEC;
            }  
        }
        Label2->Caption = VecToStrFormat(TIntVec(_3DCamera->LA_Position->AsMathVector));
        Label3->Caption = VecToStrFormat(TIntVec(_3DCamera->LA_LookAt->AsMathVector));
        AUI.CustomRender();
    }
}
TPoint LP;
/*void TMDITV::CustomMouseDown(TVisRender *Obj,TMouseButton Button,
          TShiftState Shift,TVisMathVector _Vector)
{
    TMyMDIChild *Child = (TMyMDIChild *)ComponentExists(__classid(TMDITransformation));
    if (Child)
        delete Child;
    new TMDITransformation(this,Obj,View);
    Child = (TMyMDIChild *)ComponentExists(__classid(TMDIColors));
    if (Child)
        delete Child;
    new TMDIColors(this,Material,View);
} */


void __fastcall TMDITV::ViewMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    LP.x = X;
    LP.y = Y;
}
//---------------------------------------------------------------------------

void __fastcall TMDITV::FormShow(TObject *Sender)
{
    LP = TPoint(-1,-1);
}
//---------------------------------------------------------------------------


void __fastcall TMDITV::tbPlusMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    _Timer->Tag=0;
    _Timer->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TMDITV::tbMinusMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  _Timer->Tag = ((TComponent*)Sender)->Tag;
  _Timer->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TMDITV::_TimerTimer(TObject *Sender)
{
  CameraAction(coLA_DEPTH_TRANSLATION_NO_ORIENT,10*_Timer->Tag);
  TPoint P = pViewButtons->ScreenToClient(Mouse->CursorPos);
  if (P.x<=0||P.y<=0||P.x>=pViewButtons->Width||P.y>=pViewButtons->Height)
    tbPlusMouseUp(this,TMouseButton(),TShiftState(),0,0);   
  
}
//---------------------------------------------------------------------------




void __fastcall TMDITV::ViewResize(TObject *Sender)
{
    Label1->Caption = IntToStr(View->Width)+AnsiString(" : ")+IntToStr(View->Height);
}
//---------------------------------------------------------------------------

void __fastcall TMDITV::ToolButton1Click(TObject *Sender)
{
    AUI.CameraEngine.ViewAll(View->Camera);
}
//---------------------------------------------------------------------------



