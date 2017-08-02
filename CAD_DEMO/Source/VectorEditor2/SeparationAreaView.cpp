//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "SeparationAreaView.h"

//---------------------------------------------------------------------------
TSeparationAreaView::TSeparationAreaView()
{
    ImageId=1;
    Description = "Selection view region";
    AddStateBlock(State1,0,Mouse_Move,btNone,"State1");
    AddActionBlock(Action2,1,btNone,"Action2");
    AddStateBlock(State3,2,Mouse_Move,btNone,"State3");
    AddActionBlock(Action4,3,btNone,"Action4");

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Up, mbLeft);
    AddGoToBlockId( 3, 0);
}

void TSeparationAreaView::Action2()
{
    Point = UIP.NewCursorPos;
}

void TSeparationAreaView::State3()
{
}

void TSeparationAreaView::Action4()
{
    TIntVec P1 = Sender->ProjectToScreen(Point);
    TIntVec P2 = Sender->ProjectToScreen(Sender->MyCursor.Position);
    TIntVec Point1 = Point;
    TIntVec Point2 = Sender->MyCursor.Position;
    if (fabs(P2.x-P1.x)<20 || fabs(P2.y-P1.y)<20)
        return;

    TIntVec VS1 = Sender->ScreenToProject(0,Sender->View->Height,0);
    TIntVec VS2 = Sender->ScreenToProject(Sender->View->Width,0,0);

    Sender->VisOrtCam->Transformation->Translation->X = -(Point2.x + Point1.x) / 2;
    Sender->VisOrtCam->Transformation->Translation->Y = -(Point2.y + Point1.y) / 2;

    MBTi f, x, y;
    x = fabs(Point2.x - Point1.x);
    y = fabs(Point2.y - Point1.y);
    if ( fabs(Point2.x-Point1.x)/fabs(VS2.x-VS1.x) < fabs(Point2.y-Point1.y)/fabs(VS2.y-VS1.y) )
        x = fabs(VS2.x-VS1.x)/fabs(VS2.y-VS1.y)*fabs(Point2.y - Point1.y);
    else
        y = fabs(VS2.y-VS1.y)/fabs(VS2.x-VS1.x)*fabs(Point2.x - Point1.x);
    if (x<y)
        f = x;
    else
        f = y;
    Sender->VisOrtCam->ViewWidth = f;
    Sender->VisOrtCam->ViewHeight = f;
    Sender->Grid.Attr.ReBuild = true;
}

void TSeparationAreaView::OnRender()
{
    if (ExecutedId == 2)
    {
        Sender->View->Canvas->Pen->Style = lsDash;
        Sender->View->Canvas->Pen->Color = clWhite;
        Sender->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = Sender->ProjectToScreen(Point);
        TIntVec P2 = Sender->ProjectToScreen(Sender->MyCursor.Position);
        Sender->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        Sender->View->Canvas->LineTo(floor(P2.x), floor(P1.y));
        Sender->View->Canvas->LineTo(floor(P2.x), floor(P2.y));
        Sender->View->Canvas->LineTo(floor(P1.x), floor(P2.y));
        Sender->View->Canvas->LineTo(floor(P1.x), floor(P1.y));
    }
}

AnsiString TSeparationAreaView::OnHint()
{
    if (ExecutedId == 2)
    {
        TIntVec Point1 = Point;
        TIntVec Point2 = Sender->MyCursor.Position;
        return " ("+FloatToStrF(Point1.x, ffGeneral, 4, Sender->Grid.Precision)+", "+FloatToStrF(Point1.y, ffGeneral, 4, Sender->Grid.Precision)+")  ("+FloatToStrF(Point2.x, ffGeneral, 4, Sender->Grid.Precision)+", "+FloatToStrF(Point2.y, ffGeneral, 4, Sender->Grid.Precision)+")    Ширина: "+FloatToStrF(fabs(Point2.x - Point1.x), ffGeneral, 4, Sender->Grid.Precision)+" Высота: "+FloatToStrF(fabs(Point2.y - Point1.y), ffGeneral, 4, Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
