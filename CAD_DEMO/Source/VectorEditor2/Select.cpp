//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyGL.h"
#include "MyTemplates.h"
#include <vcl.h>
#include <Poligon.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "Select.h"
#include "ViewV.h"
#include "G2DObjectV.h"
#include "InfinityLineV.h"

class T2DGObject;
//---------------------------------------------------------------------------
TSelect::TSelect()
{
    EpsValue = 5;//pixels
    ImageId = 0;
    Description = "Selection";
    CreateSelect = false;
    SelectedRender = new TVisPrimitiveObj(NULL);
    SelectedRender->Init();
    SelectedRender->ColorAsMaterial = cmAmbient;
    SelectedRender->Color->Color = (TColor)0x000000;
    SelectedRender->AddPrimitiveArray(GL_LINES);
    SelectedRender->AddPrimitiveArray(GL_POINTS);
    pnts[11].X = 0;
    pnts[11].Y = 0;
    pnts[10].X = 10;
    pnts[10].Y = 0;
    pnts[9].X = 10;
    pnts[9].Y = -3;
    pnts[8].X = 14;
    pnts[8].Y = 1.5;
    pnts[7].X = 10;
    pnts[7].Y = 4.5;
    pnts[6].X = 10;
    pnts[6].Y = 3;
    pnts[5].X = 3;
    pnts[5].Y = 3;
    pnts[4].X = 3;
    pnts[4].Y = 10;
    pnts[3].Y = 4.5;
    pnts[3].X = 10;
    pnts[2].X = 1.5;
    pnts[2].Y = 14;
    pnts[1].X = -3;
    pnts[1].Y = 10;
    pnts[0].X = 0;
    pnts[0].Y = 10;

    AddStateBlock(State1,0,Mouse_Move,btNone,"State1");
    AddActionBlock(Action2,1,btNone,"Action2");
    AddConditionalBlock(Condition3,2,btNone,"Condition3");
    AddStateBlock(State4,3,Mouse_Move,btNone,"State4");
    AddConditionalBlock(Condition5,4,btNone,"Condition5");
    AddActionBlock(Action6,5,btNone,"Action6");
    AddActionBlock(Action7,6,btNone,"Action7");
    AddActionBlock(BeforePointMoving,sbiBeforePointMoving,btNone,"BeforePointMoving");
    AddStateBlock(PointMoving,sbiPointMoving,Mouse_Move,btNone,"PointMoving");
    AddActionBlock(Action10,9,btNone,"Action10");

    AddConditionalBlock(Condition1to2,10,btNone,"Condition1to2");
    AddActionBlock(Action1to2,11,btNone,"Action1to2");
    AddStateBlock(State1to2,12,Mouse_Move,btNone,"State1to2");
    AddActionBlock(Action1to2ESC,13,btNone,"Action1to2ESC");

    AddStateBlock(State15,14,Mouse_Move,btNone,"State15");

    AddStateBlock(State16,15,Mouse_Move,btNone,"State16");
    AddConditionalBlock(Condition17,16,btNone,"Condition17");
    AddStateBlock(State18,17,Mouse_Move,btNone,"State18");
    AddConditionalBlock(Condition19,18,btNone,"Condition19");
    AddStateBlock(State20,19,Mouse_Move,btNone,"State20");
    AddConditionalBlock(Condition21,20,btNone,"Condition21");
    AddConditionalBlock(Condition22,21,btNone,"Condition22");
    AddConditionalBlock(Condition23,22,btNone,"Condition23");
    AddActionBlock(Action24,23,btNone,"Action24");
    AddActionBlock(BeforePointMoving,24,btNone,"BeforePointMoving");
    AddActionBlock(BeforePointMoving,25,btNone,"BeforePointMoving");
    AddConditionalBlock(Condition5,26,btNone,"Condition5");
    AddActionBlock(AfterPointMoving,sbiAfterPointMoving,btNone,"AfterPointMoving");
    AddActionBlock(Action26,28,btNone,"Action26");
    AddActionBlock(CreateLinkAction,sbiCreateLinkAction,btMenu,"CreateLink");
    //    AddActionBlock(Action16,15);

    AddGoToBlockId(0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId(0, 9, Key_Down, VK_DELETE);
    AddGoToBlockId(2, 14, 3);
    AddGoToBlockId(14, sbiBeforePointMoving, Mouse_Move, mbLeft);
    AddGoToBlockId(14, 21, Mouse_Up, mbLeft);
    AddGoToBlockId(21, 26, 4);

    AddGoToBlockId(3, 4, Mouse_Up, mbLeft);
    AddGoToBlockId(4, 6, 5);
    AddGoToBlockId(5, 6);
    AddGoToBlockId(6, 0);

    AddGoToBlockId(sbiBeforePointMoving, sbiPointMoving);
    AddGoToBlockId(22, 20, 25);
    AddGoToBlockId(20, 0, 24);
    AddGoToBlockId(24, 28);
    AddGoToBlockId(28, 15);
    AddGoToBlockId(18, 19, 0);
    AddGoToBlockId(25, 0);
    AddGoToBlockId(26, 23, 22);
    AddGoToBlockId(23, 0);

    AddGoToBlockId(sbiPointMoving, sbiAfterPointMoving, Mouse_Up, mbLeft);
    AddGoToBlockId(sbiAfterPointMoving, 0);
    AddGoToBlockId(9, 0);

    AddGoToBlockId(1, 10);
    AddGoToBlockId(10, 11, 2);
    AddGoToBlockId(11, 12);
    AddGoToBlockId(12, 13, Mouse_Up, mbLeft);
    AddGoToBlockId(13, 0);

    AddGoToBlockId(15, 16, Mouse_Down, mbLeft);
    AddGoToBlockId(15, 9, Key_Down, VK_DELETE);
    AddGoToBlockId(16, 17, 18);
    AddGoToBlockId(17, 15, Mouse_Up, mbLeft);
    AddGoToBlockId(19, 15, Mouse_Up, mbLeft);
    //-----------------Link----------------------------------
    AddGoToBlockId(0, sbiCreateLinkAction, Key_Down, VK_SPACE);
    AddGoToBlockId(sbiCreateLinkAction, 0);
    //-----------------//Link----------------------------------

    EscCommands = _EscCommands;
}

void TSelect::CreateLinkAction()
{
    if ( Sender->Selection.Figures.Count == 1 && Sender->Selection.Figures[0].CutIndices.Count==1)
    {
        //DistanceLink
        TGCut* Cut = &Sender->Selection.Figures[0].Figure->GetCut(Sender->Selection.Figures[0].CutIndices[0]);
        TDistanceLink* DistanceLink = new TDistanceLink();
        Sender->Selection.Figures[0].Figure->AddLink(DistanceLink);
        DistanceLink->Client0 = Cut->Src;
        DistanceLink->Client1 = Cut->Dst;
        DistanceLink->Distance = (Cut->Dst->Point-Cut->Src->Point).Length();
    }
    else if (   Sender->Selection.Figures.Count == 1 && Sender->Selection.Figures[0].CutIndices.Count==2 &&
                abs( Sender->Selection.Figures[0].CutIndices[1]-Sender->Selection.Figures[0].CutIndices[0] )==1 )
    {
        //AngleLink
        TAngleLink* AngleLink = new TAngleLink();
        Sender->Selection.Figures[0].Figure->AddLink(AngleLink);
        AngleLink->Client0 = &Sender->Selection.Figures[0].Figure->GetCut(Sender->Selection.Figures[0].CutIndices[0]);
        AngleLink->Client1 = &Sender->Selection.Figures[0].Figure->GetCut(Sender->Selection.Figures[0].CutIndices[1]);

        /*TGPoint* Center = AngleLink->Client0->CanConnect(*AngleLink->Client1);
        TGPoint* A = AngleLink->Client0->GetAnotherPoint(Center);
        TGPoint* B = AngleLink->Client1->GetAnotherPoint(Center); */

        AngleLink->AngleLinkSector = alsFirst;

        MBTi Length0 = (AngleLink->Client0->Dst->Point - AngleLink->Client0->Src->Point).Length();
        MBTi Length1 = (AngleLink->Client1->Dst->Point - AngleLink->Client1->Src->Point).Length();
        AngleLink->LabelRadius = MIN(Length0,Length1);
        //AngleLink->Angle = (AngleRad(A->Point,Center->Point,B->Point)*180)/M_PI;
    }
}

void TSelect::_EscCommands()
{
    CreateSelect = false;
}

TSelect::~TSelect()
{
    delete SelectedRender;
}

void TSelect::State1()
{
    EpsValueP = fabs(Sender->ScreenToProject(EpsValue,0,0).x - Sender->ScreenToProject(0,0,0).x);
    Sender->View->InvalidateGL();
}

void TSelect::Action2()
{
    Point1 = Point2 = UIP.NewCursorPos;
    Sender->View->InvalidateGL();    
}

bool TSelect::Condition3()
{
    TIntVec SnapPoint;
    int CutIndex;
    T2DGObject* MF;
    for (int i = 0; i < Sender->CustomFigures.Count; i++)
        if (Sender->CustomFigures[i].Snap(Point1, SnapPoint, CutIndex, EpsValueP, false) && !Sender->CustomFigures[i].Fixid)
        {
            SelectedMF = Sender->CustomFigures.Items[i];
            return true;
        }
    return false;
}

void TSelect::State4()
{
    Point2 = UIP.NewCursorPos;
    Sender->View->InvalidateGL();    
}

bool TSelect::Condition5()
{
    if (UIP.Shift.Contains(ssCtrl))
        return true;
    else
        return false;
}

bool TSelect::Condition1to2()
{
    if (UIP.NewCursorPos.Equal2D(TIntVec(0,0,0), EpsValueP))
        return true;
    else
        return false;
}

void TSelect::Action1to2()
{
    Sender->Selection.Figures.Clear();
    CreateSelect = true;
    SelectedPoint = UIP.NewCursorPos;
    OldCursorPos = UIP.NewCursorPos;
    SnapSelectedPoint.x = 0;
    SnapSelectedPoint.y = 0;
    Sender->View->InvalidateGL();    
}

void TSelect::State1to2()
{
    SelectedPoint.x += (UIP.NewCursorPos.x - OldCursorPos.x);
    SelectedPoint.y += (UIP.NewCursorPos.y - OldCursorPos.y);
    TIntVec D = SnapSelectedPoint - Sender->AllSnap(SelectedPoint, true, true, false, false, false);
    SnapSelectedPoint.x -= D.x;
    SnapSelectedPoint.y -= D.y;
    CreateSelect = true;
    OldCursorPos = UIP.NewCursorPos;
    Sender->View->InvalidateGL();    
}

void TSelect::Action1to2ESC()
{
    for (int i = 0; i < Sender->CustomFigures.Count; i++)
    {
        for (int j = 0; j < Sender->CustomFigures[i].VertexCount; j++)
        {
            Sender->CustomFigures[i].GetVertex(j).Point.x -= SnapSelectedPoint.x;
            Sender->CustomFigures[i].GetVertex(j).Point.y -= SnapSelectedPoint.y;
        }
        Sender->CustomFigures[i].CreateView();
    }
    Sender->VisOrtCam->Transformation->Translation->incX(SnapSelectedPoint.x);
    Sender->VisOrtCam->Transformation->Translation->incY(SnapSelectedPoint.y);
    Sender->Grid.Attr.ReBuild = true;
    Sender->View->InvalidateGL();    
}

void TSelect::Action6()
{
    Sender->Selection.Figures.Clear();
    CreateSelect = true;
    Sender->View->InvalidateGL();    
}

void TSelect::Action7()
{
    bool Click = false;
    if ( (Point1.x == Point2.x) && (Point1.y == Point2.y))
    {
        Point1.x -= EpsValueP;
        Point2.x += EpsValueP;
        Point1.y -= EpsValueP;
        Point2.y += EpsValueP;
        Click = true;
    }
    TIntVec P1 = Point1;
    TIntVec P2 = Point2;
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
    MBTi MaxDepthLevel = -10000000;
    TSelected BuffSel;
    BuffSel.CutIndices.Add(new int(0));
    TIntVec P;
    for (int i = 0; i < Sender->CustomFigures.Count; i++)
    {
        if (Sender->CustomFigures[i].Fixid)
            continue;
        for (int j = 0; j < Sender->CustomFigures[i].CutsCount; j++)
        {
            bool b = false;
            int ICC = IsCutsCrossedExactly(TIntVec(P1.x, P1.y, 0),
                                           TIntVec(P2.x, P1.y, 0),
                                           Sender->CustomFigures[i].GetCut(j).Src->Point,
                                           Sender->CustomFigures[i].GetCut(j).Dst->Point,P);
            if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                b = true;
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P1.x, P2.y, 0),
                                           TIntVec(P2.x, P2.y, 0),
                                           Sender->CustomFigures[i].GetCut(j).Src->Point,
                                           Sender->CustomFigures[i].GetCut(j).Dst->Point,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P1.x, P1.y, 0),
                                           TIntVec(P1.x, P2.y, 0),
                                           Sender->CustomFigures[i].GetCut(j).Src->Point,
                                           Sender->CustomFigures[i].GetCut(j).Dst->Point,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P2.x, P1.y, 0),
                                           TIntVec(P2.x, P2.y, 0),
                                           Sender->CustomFigures[i].GetCut(j).Src->Point,
                                           Sender->CustomFigures[i].GetCut(j).Dst->Point,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                if ((Sender->CustomFigures[i].GetCut(j).Src->Point.x >= P1.x &&
                    Sender->CustomFigures[i].GetCut(j).Src->Point.x <= P2.x &&
                    Sender->CustomFigures[i].GetCut(j).Src->Point.y >= P1.y &&
                    Sender->CustomFigures[i].GetCut(j).Src->Point.y <= P2.y) ||
                    (Sender->CustomFigures[i].GetCut(j).Dst->Point.x >= P1.x &&
                    Sender->CustomFigures[i].GetCut(j).Dst->Point.x <= P2.x &&
                    Sender->CustomFigures[i].GetCut(j).Dst->Point.y >= P1.y &&
                    Sender->CustomFigures[i].GetCut(j).Dst->Point.y <= P2.y))
                    b =true;
            }
            if (b){
                int ind = Sender->Selection.FindFigure(Sender->CustomFigures.Items[i]);
                if (!Click)
                {
                    if (ind != -1)
                        Sender->Selection.Figures[ind].CutIndices.Add(new int(j));
                    else
                    {
                        Sender->Selection.Figures.Add(new TSelected);
                        Sender->Selection.Figures.Last()->Figure = Sender->CustomFigures.Items[i];
                        Sender->Selection.Figures.Last()->CutIndices.Add(new int(j));
                    }
                    CreateSelect = true;
                }else
                {
                    if (MaxDepthLevel<Sender->CustomFigures[i].GetVertex(0).Point.z)
                    {
                        MaxDepthLevel = Sender->CustomFigures[i].GetVertex(0).Point.z;
                        BuffSel.Figure = Sender->CustomFigures.Items[i];
                        BuffSel.CutIndices[0] = j;
                    }

                }
            }

        }
    }
    if (Click && MaxDepthLevel!=-10000000)
    {
        int ind = Sender->Selection.FindFigure(BuffSel.Figure);
        if (ind != -1)
            Sender->Selection.Figures[ind].CutIndices.Add(new int(BuffSel.CutIndices[0]));
        else
        {
            Sender->Selection.Figures.Add(new TSelected);
            Sender->Selection.Figures.Last()->Figure = BuffSel.Figure;
            Sender->Selection.Figures.Last()->CutIndices.Add(new int(BuffSel.CutIndices[0]));
        }
        CreateSelect = true;
    }
    Sender->View->InvalidateGL();
}

bool TSelect::Condition21()
{
    if (typeid(*SelectedMF) == typeid(TInfinityLine))
        return true;
    else
        return false;
}

/*
void TSelect::BeforeAllMoving()
{
    TIntVec MP = UIP.NewCursorPos;
    OldCursorPos = UIP.NewCursorPos;
    Sender->Selection.Figures.Clear();
    Sender->Selection.Figures.Add(new TSelected);
    Sender->Selection.Figures.Last()->Figure = SelectedMF;
    for (int i = 0; i < Sender->Selection.Figures.Last()->Figure->CutsCount; i++)
        Sender->Selection.Figures.Last()->CutIndices.Add(new int(i));
    CreateSelect = true;
    if (typeid(*SelectedMF) == typeid(TInfinityLine))
    {
        int CutIndex;
        MBTi EpsValueF = fabs(Sender->ScreenToProject(EpsValue+2,0,0).x - Sender->ScreenToProject(0,0,0).x);
        SelectedMF->Snap(MP, SelectedPoint, CutIndex, EpsValueF, true);
    }else
    {
        MBTi min = 10000000;
        for (int i = 0; i < SelectedMF->VertexCount; i++)
        {
			MBTi d = sqrtDC(fabs(pow(SelectedMF->GetVertex(i).Point.x-MP.x,2))+fabs(pow(SelectedMF->GetVertex(i).Point.y-MP.y,2)));
            if (min > d)
            {
                min = d;
                SelectedPoint = SelectedMF->GetVertex(i).Point;
            }
        }
    }
    TIntVec D = SelectedPoint - Sender->AllSnap(SelectedPoint, true, false, false, false, false);
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x -= D.x;
        SelectedMF->GetVertex(i).Point.y -= D.y;
        SelectedMF->CreateView();
    }
    SelectedPoint.x -= D.x;
    SelectedPoint.y -= D.y;
    SnapSelectedPoint = SelectedPoint;
    Sender->View->InvalidateGL();
}
void TSelect::AllMoving()
{
    TIntVec DD = (UIP.NewCursorPos - OldCursorPos);
    SelectedPoint += DD;
    TIntVec D = SnapSelectedPoint - Sender->AllSnap(SelectedPoint, true, true, true, true, false);
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x += DD.x;
        SelectedMF->GetVertex(i).Point.y += DD.y;
        SelectedMF->CreateView();
    }
    SelectedMF->RotateCenter.x -= D.x;
    SelectedMF->RotateCenter.y -= D.y;
    SnapSelectedPoint.x -= D.x;
    SnapSelectedPoint.y -= D.y;
    OldCursorPos = UIP.NewCursorPos;
    Sender->View->InvalidateGL();    
}

void TSelect::AfterAllMoving()
{
    TIntVec D = SnapSelectedPoint - SelectedPoint;
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x += D.x;
        SelectedMF->GetVertex(i).Point.y += D.y;
    }
    SelectedMF->CreateView();
    Sender->View->InvalidateGL();
}*/


void TSelect::BeforePointMoving()
{
    SelectedPointIndex = -1;
    OldCursorPos = UIP.NewCursorPos;

    TIntVec MP = UIP.NewCursorPos;
    Sender->Selection.Figures.Clear();
    Sender->Selection.Figures.Add(new TSelected);
    Sender->Selection.Figures.Last()->Figure = SelectedMF;
    for (int i = 0; i < Sender->Selection.Figures.Last()->Figure->CutsCount; i++)
        Sender->Selection.Figures.Last()->CutIndices.Add(new int(i));
    CreateSelect = true;
    if (typeid(*SelectedMF) == typeid(TInfinityLine))
    {
        /*not supported for one point moving*/
        int CutIndex;
        MBTi EpsValueF = fabs(Sender->ScreenToProject(EpsValue+2,0,0).x - Sender->ScreenToProject(0,0,0).x);
        SelectedMF->Snap(MP, SelectedPoint, CutIndex, EpsValueF, true);
    }else
    {
        MBTi min = 10000000;
        for (int i = 0; i < SelectedMF->VertexCount; i++)
        {
			MBTi d = sqrtDC(fabs(pow(SelectedMF->GetVertex(i).Point.x-MP.x,2))+fabs(pow(SelectedMF->GetVertex(i).Point.y-MP.y,2)));
            if (min > d)
            {
                min = d;
                SelectedPoint = SelectedMF->GetVertex(i).Point;
                SelectedPointIndex = i;
            }
        }
    }

/*    TIntVec D = SelectedPoint - Sender->AllSnap(SelectedPoint, true, false, false, false, false);
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x -= D.x;
        SelectedMF->GetVertex(i).Point.y -= D.y;
        SelectedMF->CreateView();
    }
    SelectedPoint.x -= D.x;
    SelectedPoint.y -= D.y;
    SnapSelectedPoint = SelectedPoint;
    Sender->View->InvalidateGL();  */
}


void TSelect::PointMoving()
{
    TIntVec DD = (UIP.NewCursorPos - OldCursorPos);
    DD.z = 0;
    SelectedMF->GetVertex(SelectedPointIndex).Point += DD;
    SnapSelectedPoint = SelectedMF->GetVertex(SelectedPointIndex).Point;
    SelectedPoint = SnapSelectedPoint;
    SelectedMF->CreateView();
    OldCursorPos = UIP.NewCursorPos;
    Sender->View->InvalidateGL();
}

void TSelect::AfterPointMoving()
{
/*    TIntVec D = SnapSelectedPoint - SelectedPoint;
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x += D.x;
        SelectedMF->GetVertex(i).Point.y += D.y;
    }*/
    SelectedMF->CreateView();
    Sender->View->InvalidateGL();
}

void TSelect::State15()
{
    Sender->View->InvalidateGL();    
}

void TSelect::RotateCursor(MBTi Angle, TPoint Point)
{
    pnts[11].X = 0;
    pnts[11].Y = 0;
    pnts[10].X = 10;
    pnts[10].Y = 0;
    pnts[9].X = 10;
    pnts[9].Y = -2;
    pnts[8].X = 14;
    pnts[8].Y = 1.5;
    pnts[7].X = 10;
    pnts[7].Y = 5;
    pnts[6].X = 10;
    pnts[6].Y = 3;
    pnts[5].X = 3;
    pnts[5].Y = 3;
    pnts[4].X = 3;
    pnts[4].Y = 10;
    pnts[3].X = 5;
    pnts[3].Y = 10;
    pnts[2].X = 1.5;
    pnts[2].Y = 14;
    pnts[1].X = -2;
    pnts[1].Y = 10;
    pnts[0].X = 0;
    pnts[0].Y = 10;

    for (int i = 0; i < 12; i++)
    {
        TIntVec B = RotateAround(TIntVec(pnts[i].X, pnts[i].Y, 0), TIntVec(0, 0, Angle), TIntVec(0,0,0));
        pnts[i].X = B.x;
        pnts[i].Y = B.y;
    }
    for (int i = 0; i < 12; i++)
    {
        pnts[i].X += Point.x;
        pnts[i].Y += Point.y;
    }
    Sender->View->InvalidateGL();    
}

void TSelect::Action26()
{
    Sender->View->InvalidateGL();    
}

void TSelect::State16()
{
    MBTi max = -100000000;
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        MBTi d = sqrtDC(fabs(pow(SelectedMF->GetVertex(i).Point.x-SelectedMF->RotateCenter.x,2))+fabs(pow(SelectedMF->GetVertex(i).Point.y-SelectedMF->RotateCenter.y,2)));
        if (d > max){
            max = d;
            RotatePoint = SelectedMF->GetVertex(i).Point;
        }
    }
    Radius = max;
    SelectedMF->CreateBBox();
    MBTi SV5 = fabs(Sender->ScreenToProject(5,0,0).x - Sender->ScreenToProject(0,0,0).x);
    BB[0] = TIntVec(SelectedMF->BBoxLU.x-SV5, SelectedMF->BBoxLU.y-SV5, SelectedMF->BBoxLU.z);
    BB[1] = TIntVec(SelectedMF->BBoxRD.x+SV5, SelectedMF->BBoxLU.y-SV5, SelectedMF->BBoxLU.z);
    BB[2] = TIntVec(SelectedMF->BBoxRD.x+SV5, SelectedMF->BBoxRD.y+SV5, SelectedMF->BBoxRD.z);
    BB[3] = TIntVec(SelectedMF->BBoxLU.x-SV5, SelectedMF->BBoxRD.y+SV5, SelectedMF->BBoxLU.z);
    Sender->View->InvalidateGL();    
}

bool TSelect::Condition17()
{
    Sender->View->InvalidateGL();    
    if (UIP.NewCursorPos.Equal2D(SelectedMF->RotateCenter, Sender->Attributes.SnapValue))
    {
        return true;
    }else
        return false;
}

void TSelect::Action18to19()
{
    Sender->View->InvalidateGL();    
}

void TSelect::State18()
{
    SelectedMF->RotateCenter = Sender->AllSnap(UIP.NewCursorPos, true, false, false, false, false);
    Sender->View->InvalidateGL();    
}

bool TSelect::Condition19()
{
    TIntVec MP = UIP.NewCursorPos;
    MBTi D = fabs(Sender->ScreenToProject(12,0,0).x - Sender->ScreenToProject(0,0,0).x);

    SRP = SelectedMF->BBoxLU;
    FirstVector = TIntVec(SelectedMF->BBoxLU.x-D, SelectedMF->BBoxLU.y-D, 30);
    if (MP.Equal2D(FirstVector))
        return true;

    SRP = SelectedMF->BBoxRD;
    FirstVector = TIntVec(SelectedMF->BBoxRD.x+D, SelectedMF->BBoxRD.y+D, 30);
    if (MP.Equal2D(FirstVector, Sender->Attributes.SnapValue))
        return true;

    SRP = TIntVec(SelectedMF->BBoxLU.x,SelectedMF->BBoxRD.y, SelectedMF->BBoxLU.z);
    FirstVector = TIntVec(SelectedMF->BBoxLU.x-D, SelectedMF->BBoxRD.y+D, 30);
    if (MP.Equal2D(FirstVector, Sender->Attributes.SnapValue))
        return true;

    SRP = TIntVec(SelectedMF->BBoxRD.x,SelectedMF->BBoxLU.y, SelectedMF->BBoxLU.z);
    FirstVector = TIntVec(SelectedMF->BBoxRD.x+D, SelectedMF->BBoxLU.y-D, 30);
    if (MP.Equal2D(FirstVector, Sender->Attributes.SnapValue))
        return true;

    Sender->View->InvalidateGL();    
    return false;
}

void TSelect::State20()
{
    TIntVec V1 = OldCursorPos;
    TIntVec V2 = UIP.NewCursorPos;
    MBTi Angle = 0;
     if (fabs(V1.x-SelectedMF->RotateCenter.x)>0.00001 && fabs(V2.x-SelectedMF->RotateCenter.x)>0.00001 && fabs(V1.y-SelectedMF->RotateCenter.y)>0.00001 && fabs(V2.y-SelectedMF->RotateCenter.y)>0.00001)
        Angle = ArcTan2(V1.y-SelectedMF->RotateCenter.y, V1.x-SelectedMF->RotateCenter.x) - ArcTan2(V2.y-SelectedMF->RotateCenter.y, V2.x-SelectedMF->RotateCenter.x);

    for (int i = 0; i < SelectedMF->VertexCount; i++)
        SelectedMF->GetVertex(i).Point = RotateAround(SelectedMF->GetVertex(i).Point, TIntVec(0, 0, -Angle*180/M_PI), SelectedMF->RotateCenter);

    RotatePoint = RotateAround(RotatePoint, TIntVec(0, 0, -Angle*180/M_PI), SelectedMF->RotateCenter);
    for (int i = 0; i < 4; i++)
        BB[i] = RotateAround(BB[i], TIntVec(0, 0, -Angle*180/M_PI), SelectedMF->RotateCenter);
    for (int i = 0; i < Sender->CustomFigures.Count; i++)
        Sender->CustomFigures[i].CreateView();
    OldCursorPos = UIP.NewCursorPos;
    Sender->View->InvalidateGL();    
}

void TSelect::Action10()
{
    for(int i = 0; i < Sender->Selection.Figures.Count; i++)
    {
        if (typeid(*(Sender->Selection.Figures[i].Figure)) == typeid(T2DGObject))
        {
            T2DGObject* CF = (T2DGObject*)Sender->Selection.Figures[i].Figure;
            TMTList<TGCut> DeletedCuts;
            for(int j = 0; j < Sender->Selection.Figures[i].CutIndices.Count; j++)
                DeletedCuts.Add(&CF->GetCut(Sender->Selection.Figures[i].CutIndices[j]));
            for(int j = 0; j < DeletedCuts.Count; j++)
                CF->Delete(&DeletedCuts[j]);
        }
    }

    for(int i = 0; i < Sender->Selection.Figures.Count; i++)
    {
        if (typeid(*(Sender->Selection.Figures[i].Figure)) == typeid(T2DGObject))
        {
            if (Sender->Selection.Figures[i].Figure->CutsCount<1)
                Sender->CustomFigures.Remove(Sender->Selection.Figures[i].Figure);
        }
        else if (typeid(*(Sender->Selection.Figures[i].Figure)) == typeid(TInfinityLine))
            Sender->CustomFigures.Remove(Sender->Selection.Figures[i].Figure);
    }

    Sender->Selection.Figures.Clear();
    Sender->View->InvalidateGL();    
}

bool TSelect::Condition22()
{
    TIntVec SnapPoint;
    int CutIndex;
    for (int i = 0; i < Sender->Selection.Figures.Count; i++)
        if (Sender->Selection.Figures[i].Figure->Snap(Point1, SnapPoint, CutIndex, EpsValueP, false))
        {
            int index = FindInList(&Sender->Selection.Figures[i].CutIndices,CutIndex);
            if ( index!=-1 )
            {
                SelectedMF = Sender->Selection.Figures[i].Figure;
                return true;
            }
            break;
        }
    Point2 = Point1;
    Sender->View->InvalidateGL();    
    return false;
}

bool TSelect::Condition23()
{
    int FigSelInd, CutSelInd;
    for (int i = 0; i < SelectedMF->CutsCount; i++)
        if (!Sender->Selection.FindCutAndFigureIndices(SelectedMF, i, FigSelInd, CutSelInd))
            return false;
    Sender->View->InvalidateGL();
    return true;
}

void TSelect::Action24()
{
    TIntVec SnapPoint;
    int CutIndex;
    if (SelectedMF->Snap(Point1, SnapPoint, CutIndex, EpsValueP, false))
    {
        int FigSelInd, CutSelInd;
        if (Sender->Selection.FindCutAndFigureIndices(SelectedMF, CutIndex, FigSelInd, CutSelInd))
        {
            Sender->Selection.Figures[FigSelInd].CutIndices.Delete(CutSelInd);
            if (Sender->Selection.Figures[FigSelInd].CutIndices.Count == 0)
                Sender->Selection.Figures.Delete(FigSelInd);
        }
    }
    Sender->View->InvalidateGL();    
}

void TSelect::OnRender()
{
    if (ExecutedId == 3)
    {
        Sender->View->Canvas->Pen->Style = lsDash;
        Sender->View->Canvas->Pen->Color = clWhite;
        Sender->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = Sender->ProjectToScreen(Point1);
        TIntVec P2 = Sender->ProjectToScreen(Point2);
        Sender->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        Sender->View->Canvas->LineTo(floor(P2.x), floor(P1.y));
        Sender->View->Canvas->LineTo(floor(P2.x), floor(P2.y));
        Sender->View->Canvas->LineTo(floor(P1.x), floor(P2.y));
        Sender->View->Canvas->LineTo(floor(P1.x), floor(P1.y));
    }
    if (CreateSelect)
    {
        SelectedRender->Init();
        SelectedRender->ColorAsMaterial = cmAmbient;
        glLineWidth(Sender->Attributes.LinesWidth.Selected);
        SelectedRender->Color->Color = Sender->Attributes.Colors.Selected;
        SelectedRender->AddPrimitiveArray(GL_LINES);
        SelectedRender->AddPrimitiveArray(GL_POINTS);
        int Index = 0;
        for (int i = 0; i < Sender->Selection.Figures.Count; i++)
        {
            for (int j = 0; j < Sender->Selection.Figures[i].CutIndices.Count; j++)
            {
                Index = SelectedRender->Points->Add(ToVec(Sender->Selection.Figures[i].Figure->GetCut(Sender->Selection.Figures[i].CutIndices[j]).Src->Point.x,
                                                          Sender->Selection.Figures[i].Figure->GetCut(Sender->Selection.Figures[i].CutIndices[j]).Src->Point.y,
                                                          Sender->DepthLevels.Selected),ZEROVEC,ZEROVEC);
                SelectedRender->AddIndex(Index,0);
                Index = SelectedRender->Points->Add(ToVec(Sender->Selection.Figures[i].Figure->GetCut(Sender->Selection.Figures[i].CutIndices[j]).Dst->Point.x,
                                                          Sender->Selection.Figures[i].Figure->GetCut(Sender->Selection.Figures[i].CutIndices[j]).Dst->Point.y,
                                                          Sender->DepthLevels.Selected),ZEROVEC,ZEROVEC);
                SelectedRender->AddIndex(Index,0);
//                VCO->AddIndex(Index-2,0);
  //              VCO->AddIndex(Index-1,0);
            }
        }
        if (ExecutedId == sbiPointMoving || ExecutedId == 12)
        {
            glPointSize(5);
            Index = SelectedRender->Points->Add(ToVec(SelectedPoint.x,
                                                      SelectedPoint.y,
                                                      Sender->DepthLevels.Selected),ZEROVEC,ZEROVEC);
            SelectedRender->AddIndex(Index,1);

            SelectCursor.Position = TIntVec(SnapSelectedPoint.x, SnapSelectedPoint.y, Sender->DepthLevels.Selected);
            SelectCursor.Render(Sender);
        }
        if (ExecutedId == 15 || ExecutedId == 17 || ExecutedId == 19)
        {
            RotatedCursor.Position = TIntVec(SelectedMF->RotateCenter.x, SelectedMF->RotateCenter.y, Sender->DepthLevels.Selected);
            RotatedCursor.Render(Sender);

            Sender->View->Canvas->Pen->Style = lsDash;
            TIntVec P = Sender->ProjectToScreen(SelectedMF->RotateCenter);
            P = Sender->ProjectToScreen(RotatePoint);
            Sender->View->Canvas->Pen->Color = clBlue;
            Sender->View->Canvas->Brush->Color = clBlue;
            Sender->View->Canvas->Brush->Alpha = 0;
            Sender->View->Canvas->Transparency = tmAlpha;
//            Sender->View->Canvas->Polygon(pnts,13);

/*            Sender->View->Canvas->Ellipse(P.x+Rad, P.y+Rad, P.x-Rad, P.y-Rad);
            P = Sender->ProjectToScreen(RotatePoint);
            Sender->View->Canvas->Ellipse(P.x+10, P.y+10, P.x-10, P.y-10);*/
            if (ExecutedId == 19)
            {
                TIntVec P1 = Sender->ProjectToScreen(BB[0]);
                Sender->View->Canvas->MoveTo(P1.x, P1.y);
                for (int i = 1; i < 4; i++)
                {
                    TIntVec P1 = Sender->ProjectToScreen(BB[i]);
                    Sender->View->Canvas->LineTo(P1.x, P1.y);
                }
                P1 = Sender->ProjectToScreen(BB[0]);
                Sender->View->Canvas->LineTo(P1.x, P1.y);
            }
            TIntVec P1 = Sender->ProjectToScreen(SelectedMF->BBoxLU);
            TIntVec P2 = Sender->ProjectToScreen(SelectedMF->BBoxRD);
            Sender->View->Canvas->Pen->Style = lsDash;
            Sender->View->Canvas->MoveTo(P1.x-5, P1.y+5);
            Sender->View->Canvas->LineTo(P2.x+5, P1.y+5);
            Sender->View->Canvas->LineTo(P2.x+5, P2.y-5);
            Sender->View->Canvas->LineTo(P1.x-5, P2.y-5);
            Sender->View->Canvas->LineTo(P1.x-5, P1.y+5);
            Sender->View->Canvas->Pen->Style = lsSolid;
            TIntVec PP = Sender->ProjectToScreen(SelectedMF->BBoxRD);
            RotateCursor(90, TPoint(PP.x+15, PP.y-15));
            Sender->View->Canvas->Polygon(pnts,11);
            PP = Sender->ProjectToScreen(SelectedMF->BBoxLU);
            RotateCursor(270, TPoint(PP.x-15, PP.y+15));
            Sender->View->Canvas->Polygon(pnts,11);
            PP = Sender->ProjectToScreen(TIntVec(SelectedMF->BBoxRD.x, SelectedMF->BBoxLU.y, 30));
            RotateCursor(180, TPoint(PP.x+15, PP.y+15));
            Sender->View->Canvas->Polygon(pnts,11);
            PP = Sender->ProjectToScreen(TIntVec(SelectedMF->BBoxLU.x, SelectedMF->BBoxRD.y, 30));
            RotateCursor(0, TPoint(PP.x-15, PP.y-15));
            Sender->View->Canvas->Polygon(pnts,11);
        }
    }
    SelectedRender->Render(Sender->View);
    Sender->View->InvalidateGL();    
}

AnsiString TSelect::OnHint()
{
    if (ExecutedId == 2)
        return " ("+FloatToStrF(Point1.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(Point1.y, ffGeneral, 4, Sender->Grid.Precision)+")  ("+FloatToStrF(Point2.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(Point2.y, ffGeneral, 4, Sender->Grid.Precision)+")    Ширина: "+FloatToStrF(fabs(Point2.x - Point1.x), ffGeneral, 4, Sender->Grid.Precision)+" Высота: "+FloatToStrF(fabs(Point2.y - Point1.y), ffGeneral, 4, Sender->Grid.Precision);
    if (ExecutedId == 15 || ExecutedId == 17)
        return " ("+FloatToStrF(SelectedMF->RotateCenter.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(SelectedMF->RotateCenter.y, ffGeneral, 4, Sender->Grid.Precision)+")";
    if (ExecutedId == 19)
    {
        MBTi Angle = AngleRad(UIP.NewCursorPos,SelectedMF->RotateCenter,FirstVector);
        return " ("+FloatToStrF(SelectedMF->RotateCenter.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(SelectedMF->RotateCenter.y, ffGeneral, 4, Sender->Grid.Precision)+")      Угол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
