//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"
#include <Poligon.h>
#include "MyGL.h"
#include "G2DObjectV.h"
#include "SeparationAreaView.h"
#include "G2DPointCutV.h"

//---------------------------------------------------------------------------
void TSeparationAreaView::Area(TEditor2D* MyEditorXD, TMyView* MyView, const TIntVec& V1, const TIntVec& V2, bool All)
{
    TIntVec P1 = V1;
    TIntVec P2 = V2;
    if (P1.x > P2.x)
    {
        MBTi buff = P1.x;
        P1.x = P2.x;
        P2.x = buff;
    }
    if (P1.y > P2.y)
    {
        MBTi buff = P1.y;
        P1.y = P2.y;
        P2.y = buff;
    }

    if (!All && (fabs(P2.x-P1.x)<20 || fabs(P2.y-P1.y)<20))
        return;

    MyView->A = TIntVec(*EditorXD->MyView->View->Camera->LA_LookAt);
    MyView->PlaneN = ( MyView->A - TIntVec(*EditorXD->MyView->View->Camera->LA_Position) ).Normalize();

    TIntVec ACam[4];
    TIntVec PlaneNCam[4];
    if (!All)
    {
        if ( IS(EditorXD->MyView->View->Camera,__classid(TVisPerspectiveCamera)) )
        {
            ACam[0] = MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0));
            PlaneNCam[0] = ((MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)*
                            (MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)).Normalize();
            ACam[1] = MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0));
            PlaneNCam[1] = ((MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)*
                            (MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)).Normalize();
            ACam[2] = MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0));
            PlaneNCam[2] = ((MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)*
                            (MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)).Normalize();
            ACam[3] = MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0));
            PlaneNCam[3] = ((MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)*
                            (MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0)) - *EditorXD->MyView->View->Camera->LA_Position)).Normalize();
        } else
        {
            ACam[0] = MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0));
            PlaneNCam[0] = ((MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0)) - MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0)))*MyView->PlaneN).Normalize();
            ACam[1] = MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0));
            PlaneNCam[1] = ((MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0)) - MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0)))*MyView->PlaneN).Normalize();
            ACam[2] = MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0));
            PlaneNCam[2] = ((MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0)) - MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0)))*MyView->PlaneN).Normalize();
            ACam[3] = MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0));
            PlaneNCam[3] = ((MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0)) - MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0)))*MyView->PlaneN).Normalize();
        }
    }
    TIntVec Center = TIntVec((P2.x + P1.x) / 2, (P2.y + P1.y) / 2, 0);

    TMDelTList<TIntVec> Points;
    TIntVec CP;
    for (int i = 0; i < MyEditorXD->CustomFigures.Count; i++)
    {
        for (int j = 0; j < MyEditorXD->CustomFigures[i].CutsCount; j++)
        {
            TIntVec Src = MyEditorXD->CustomFigures[i].GetCut(j).Src->Point;
            TIntVec Dst = MyEditorXD->CustomFigures[i].GetCut(j).Dst->Point;

            if (!All)
                for ( int i = 0 ; i < 4; i++ )
                {
                    int PLC = PlaneAndLineCrossed(ACam[i], PlaneNCam[i], Src, Dst, true, true, CP, 0.0001);
                    if (PLC == PL_CROSS_ONEPOINT || PLC == PL_CROSS_CONSISTS)
                        Points.Add(new TIntVec(CP));
                }

            Src = MyView->ProjectToScreen(Src);
            Dst = MyView->ProjectToScreen(Dst);

            if (All || (Src.x > P1.x &&
                Src.x < P2.x &&
                Src.y > P1.y &&
                Src.y < P2.y))
              Points.Add(new TIntVec( MyEditorXD->CustomFigures[i].GetCut(j).Src->Point ));

            if (All || (Dst.x > P1.x &&
                Dst.x < P2.x &&
                Dst.y > P1.y &&
                Dst.y < P2.y))
                Points.Add(new TIntVec( MyEditorXD->CustomFigures[i].GetCut(j).Dst->Point ));
        }
    }

    if (Points.Count < 1)
    {
        MyView->A = ZEROINTVEC;
        MyView->PlaneN = TIntVec(0, 0, -1);
        Points.Add(new TIntVec(MyView->ScreenToProject(TIntVec(P1.x, P1.y, 0))));
        Points.Add(new TIntVec(MyView->ScreenToProject(TIntVec(P2.x, P1.y, 0))));
        Points.Add(new TIntVec(MyView->ScreenToProject(TIntVec(P2.x, P2.y, 0))));
        Points.Add(new TIntVec(MyView->ScreenToProject(TIntVec(P1.x, P2.y, 0))));
    }

    MyView->A = TIntVec(*EditorXD->MyView->View->Camera->LA_LookAt);
    MyView->PlaneN = ( MyView->A - TIntVec(*EditorXD->MyView->View->Camera->LA_Position) ).Normalize();

    TIntVec BB[2];
    BB[0] = TIntVec(1<<20,1<<20,1<<20);
    BB[1] = BB[0]*(-1);
    for (int i = 0; i < Points.Count; i++)
    {
        UpdateMaxVector(BB[1],Points[i]);
        UpdateMinVector(BB[0],Points[i]);
    }
    TIntVec CenterG = (BB[0]+BB[1]) /2;
    MBTi minLenght = (TIntVec(*EditorXD->MyView->View->Camera->LA_Position) - Points[0]).Length();
    int minI = 0;
    for (int i = 1; i < Points.Count; i++ )
        if (minLenght > (TIntVec(*EditorXD->MyView->View->Camera->LA_Position) - Points[i]).Length())
        {
            minLenght = (TIntVec(*EditorXD->MyView->View->Camera->LA_Position) - Points[i]).Length();
            minI = i;
        }

    MyView->A = CenterG;
//    TIntVec CP1 = CenterG;
    TIntVec CP1 = MyView->ScreenToProject(Center);
    TIntVec Shift = CP1 - *EditorXD->MyView->View->Camera->LA_LookAt;
    AssignVisVec(*EditorXD->MyView->View->Camera->LA_LookAt, CP1);
    AssignVisVec(*EditorXD->MyView->View->Camera->LA_Position, Shift + *EditorXD->MyView->View->Camera->LA_Position);


    MyView->A = Points[minI];
    TIntVec CP0 = MyView->ScreenToProject(Center);
    /*TIntVec CP0;
    PlaneCrossPoint(Points[minI], NormalCam,
                    TIntVec(*EditorXD->MyView->View->Camera->LA_Position),
                    TIntVec(*EditorXD->MyView->View->Camera->LA_LookAt),
                    CP0);   */

    if (! IS(EditorXD->MyView->View->Camera,__classid(TVisPerspectiveCamera)) )
    {
        TVisOrthographicCamera* VisOrtCam = (TVisOrthographicCamera*)EditorXD->MyView->View->Camera;
        MBTi f = MIN( MBTi(EditorXD->MyView->Width)/fabs(P2.x-P1.x),MBTi(EditorXD->MyView->Height)/fabs(P2.y-P1.y) );
        VisOrtCam->ViewWidth = VisOrtCam->ViewWidth/f;
        VisOrtCam->ViewHeight = VisOrtCam->ViewHeight/f;
    }else
    {
        TVisPerspectiveCamera* VisPerspCam = (TVisPerspectiveCamera*)EditorXD->MyView->View->Camera;
//------------------------------------------------------------------------------
        MyView->A = CP0;
        TIntVec NormalCam =  ( TIntVec(*EditorXD->MyView->View->Camera->LA_LookAt)-
                               TIntVec(*EditorXD->MyView->View->Camera->LA_Position) ).Normalize();
        MBTi AB = (TIntVec(*EditorXD->MyView->View->Camera->LA_Position) - CP0 ).Length();
        MBTi EF,BC;
        MBTi D;
        MBTi f = MIN( MBTi(EditorXD->MyView->Width)/fabs(P2.x-P1.x),MBTi(EditorXD->MyView->Height)/fabs(P2.y-P1.y) );
        AssignVisVec(*EditorXD->MyView->View->Camera->LA_Position,
            PointOfLineOnCut(TIntVec(*EditorXD->MyView->View->Camera->LA_Position),
                TIntVec(*EditorXD->MyView->View->Camera->LA_Position)+ NormalCam , AB*(1-1/f) )
        );
//------------------------------------------------------------------------------
    }
    Points.Clear();

    MyEditorXD->Grid.Attr.ReBuild = true;

    MyView->A = ZEROINTVEC;
    MyView->PlaneN = TIntVec(0,0,-1);
}

TSeparationAreaView::TSeparationAreaView()
{
    ImageId=1;
    Description = "Select view";
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
    Point = EditorXD->MyCursor.Position;
}

void TSeparationAreaView::State3()
{
}

void TSeparationAreaView::Action4()
{
    TIntVec P1 = EditorXD->MyView->ProjectToScreen(Point);
    TIntVec P2 = EditorXD->MyView->ProjectToScreen(EditorXD->MyCursor.Position);
    Area(EditorXD, EditorXD->MyView, P1, P2, false);
}

void TSeparationAreaView::OnRender()
{
    if (ExecutedId == 2)
    {
        EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
        EditorXD->MyView->View->Canvas->Pen->Color = clWhite;
        EditorXD->MyView->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = EditorXD->MyView->ProjectToScreen(Point);
        TIntVec P2 = EditorXD->MyView->ProjectToScreen(EditorXD->MyCursor.Position);
        EditorXD->MyView->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P1.y));
    }
/*    if (ExecutedId == 0)
    {
        EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
        EditorXD->MyView->View->Canvas->Pen->Color = clWhite;
        EditorXD->MyView->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = MyView->ProjectToScreen(BB[0]);
        TIntVec P2 = MyView->ProjectToScreen(BB[1]);
        EditorXD->MyView->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P1.y));
    }*/
}

AnsiString TSeparationAreaView::OnHint()
{
    if (ExecutedId == 2)
    {
        TIntVec Point1 = Point;
        TIntVec Point2 = EditorXD->MyCursor.Position;
        return " ("+FloatToStrF(Point1.x, ffGeneral, 4, EditorXD->Grid.Precision)+", "+FloatToStrF(Point1.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(Point2.x, ffGeneral, 4, EditorXD->Grid.Precision)+", "+FloatToStrF(Point2.y, ffGeneral, 4, EditorXD->Grid.Precision)+")    Ширина: "+FloatToStrF(fabs(Point2.x - Point1.x), ffGeneral, 4, EditorXD->Grid.Precision)+" Высота: "+FloatToStrF(fabs(Point2.y - Point1.y), ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}

//---------------------------------------------------------------------------
TSeparationAllView::TSeparationAllView()
{
    ImageId=1;
    Description = "Select optimal view";
    AddActionBlock(Action,1,btNone,"Action");
}
void TSeparationAllView::Action()
{
    TIntVec AllBB[2];
    AllBB[0] = TIntVec(1<<20,1<<20,1<<20);
    AllBB[1] = AllBB[0]*(-1);
    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
        for (int j = 0; j < EditorXD->CustomFigures[i].VertexCount; j++)
        {
            UpdateMaxVector(AllBB[1],EditorXD->CustomFigures[i].GetVertex(j).Point);
            UpdateMinVector(AllBB[0],EditorXD->CustomFigures[i].GetVertex(j).Point);
        }
    Area(EditorXD, EditorXD->MyView, EditorXD->MyView->ProjectToScreen(AllBB[0]), EditorXD->MyView->ProjectToScreen(AllBB[1]), false);
}
#pragma package(smart_init)
