//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VectorsViewV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMyView *MyView;
//---------------------------------------------------------------------------
__fastcall TMyView::TMyView(TComponent* Owner)
    : TForm(Owner)
{
}
/*void __fastcall TEditor2D::Render(TVisView *aView)
{
    VisAttributes1->Render(aView);
    VisLight1->Render(aView);

    for(int i = 0; i < CustomFigures.Count; i++)
        CustomFigures[i].Render(Editor2D);

    if (Grid.Attr.ReBuild)
    {
        TIntVec V1 = ScreenToProject(0,View->Height,0);
        TIntVec V2 = ScreenToProject(View->Width,0,0);
        TestGrid(V1,V2);
        Grid.Create(V1, V2, DepthLevels.Grid);
        Grid.Attr.ReBuild = false;
    }

    Grid.Render(Editor2D);
    MyControls.Render(Editor2D);
    SB->Panels->Items[1]->Text = MyControls.Hint(Editor2D);
}
void TEditor2D::WinFrom3D(const TIntVec& P1,TIntVec& RES)
{
    TVisMathVector V;
    gluProject(P1.x,P1.y,P1.z,ModMat,ProjMat,ViewPort,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (ViewPort[3]-ViewPort[1])-V.y;
    RES.z = V.z;
}

bool TEditor2D::WinTo3D(int X,int Y,double value,TIntVec& RES)
{
    GLdouble  px,py,pz;
    GLint really;
    bool returned=false;
    really = ViewPort[3] - (GLint)Y-1;
    if (gluUnProject((GLdouble)X,(GLdouble)really,value,ModMat,ProjMat,ViewPort,&px,&py,&pz)==GL_TRUE)
        returned=true;
    RES.x = px;
    RES.y = py;
    RES.z = pz;
    return(returned);
}

TIntVec TEditor2D::ScreenToProject(MBTi x, MBTi y, MBTi z)
{
    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec P1, P2;
    WinTo3D( floor(x), floor(y), 0, P1);
    WinTo3D( floor(x), floor(y), 10, P2);
    TIntVec Res;
    PlaneCrossPoint( A, PlaneN, P1, P2, Res);
    return Res;
}

TIntVec TEditor2D::ScreenToProject(const TIntVec& V)
{
    return  ScreenToProject(V.x, V.y, V.z);
}

TIntVec TEditor2D::ProjectToScreen(const TIntVec& Vv)
{
    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec Res;
    WinFrom3D(Vv, Res);
    return Res;
}

void __fastcall TEditor2D::MouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (Grid.Attr.Step > Grid.Attr.ZoomLimit && WheelDelta<0)
        return;
    if (Grid.Attr.Step < (MBTi)1/Grid.Attr.ZoomLimit && WheelDelta>0)
        return;
    TIntVec V = ScreenToProject( TIntVec(View->ScreenToClient(MousePos).x,View->ScreenToClient(MousePos).y,0) );

    MBTi wd = MBTi(WheelDelta);
    VisOrtCam->ViewWidth -= wd*Grid.Attr.ZoomStep*VisOrtCam->ViewWidth;
    VisOrtCam->ViewHeight -= wd*Grid.Attr.ZoomStep*VisOrtCam->ViewHeight;

    TIntVec V1 = ScreenToProject( TIntVec(View->ScreenToClient(MousePos).x,View->ScreenToClient(MousePos).y,0)) - V;


    VisOrtCam->Transformation->Translation->incX(V1.x);
    VisOrtCam->Transformation->Translation->incY(V1.y);
    Grid.Attr.ReBuild = true;
}
void __fastcall TEditor2D::MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MyCursor.Position = ScreenToProject(TIntVec(X,Y,MyCursor.Position.z));
    if (Shift.Contains(ssAlt))
    {
        ParamEntering->Param = MyCursor.Position;
        if ( ParamEntering->ShowModal() != mrOk )
            return;
        MyCursor.Position = ParamEntering->Param;
    }
    MyControls.MouseDown(Editor2D, Button, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MyCursor.Position.x = ScreenToProject(TIntVec(X,Y,0)).x;
    MyCursor.Position.y = ScreenToProject(TIntVec(X,Y,0)).y;
    MyControls.MouseUp(Editor2D, Button, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F2)
   {
        if (CHECK_FILE_SAVE("Attributes\\Figures.dat"))
        {
            TMemoryStream* MS = new TMemoryStream();
            CustomFigures.WriteData(MS);
            MS->SaveToFile("Attributes\\Figures.dat");
            delete MS;
        }
    }
    if (Key == VK_F3)
    {
        if (CHECK_FILE_LOAD("Attributes\\Figures.dat"))
        {
            TMemoryStream* MS = new TMemoryStream();
            MS->LoadFromFile("Attributes\\Figures.dat");
            CustomFigures.ReadData(MS);
            delete MS;
        }
    }
    MyControls.KeyDown(Editor2D, Key, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    MyControls.KeyUp(Editor2D, Key, Shift);
}*/
//---------------------------------------------------------------------------
