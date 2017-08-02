//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyGL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DDistanceLinkV.h"
#include "G2DAngleLinkV.h"
#include "G2DFunctionsV.h"
#include "VESelect.h"
#include "G2DPointCutV.h"


#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"
#include <Poligon.h>

#include "ViewV.h"
#include "InfinityLineV.h"
//---------------------------------------------------------------------------

TSelect::TSelect():
    SelLinkPen( *(new TVisPen()) ),
    SelPointPen( *(new TVisPen()) ),
    SelRibPen( *(new TVisPen()) ),
    BackPen( *(new TVisPen()) )
{
    //--------------------------------------------
    SelLinkPen.Color = clRed;
    SelPointPen.Color = clRed;
    SelRibPen.Color = clRed;
    SelLinkPen.Width = 2;
    SelPointPen.Width = 2;
    SelRibPen.Width = 2;


    EpsValue = 5;//pixels
    ImageId = 0;
    Description = "Selection";
    CreateSelect = false;

    VCO->Init();
    VCO->ColorAsMaterial = cmAmbient;
    VCO->Color->Color = clBlue;
    VCO->AddPrimitiveArray(GL_LINES);

    for(int i = 0; i < 16; i++)
        VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);

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
    AddActionBlock(UpdateLink,sbiUpdateLink,btMenu,"UpdateLink");
    AddActionBlock(FixAction,sbiFixAction,btMenu,"FixAction");

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
    //---------------------------------------------------
    AddGoToBlockId(0, sbiFixAction, Key_Down, VK_F6);
    AddGoToBlockId(sbiFixAction, 0);
    //-----------------//Link----------------------------------
    //-----------------Update Link----------------------------------
    AddGoToBlockId(0, sbiUpdateLink, Key_Down, VK_F5);
    AddGoToBlockId(sbiUpdateLink, 0);
    //-----------------//Update Link---------------------------------
    EscCommands = _EscCommands;
}

void TSelect::UpdateLink()
{
/*    if ( EditorXD->Selection.Figures.Count == 1 && EditorXD->Selection.Figures[0].SLinks.Count==1)
    {
        //UpdateLink
        TFlowInfo FlowInfo;
        FlowInfo.Owner = EditorXD->Selection.Figures[0].Figure;
        EditorXD->Selection.Figures[0].SLinks[0].Update( FlowInfo );
        EditorXD->Selection.Figures[0].Figure->CreateView();
    }
    EditorXD->MyView->View->InvalidateGL();*/
}

void TSelect::FixAction()
{
    if ( EditorXD->Selection.Figures.Count == 1 && EditorXD->Selection.Figures[0].SCuts.Count==1)
    {
        //Fix Rib
        EditorXD->Selection.Figures[0].SCuts[0].Fixed = !EditorXD->Selection.Figures[0].SCuts[0].Fixed;
    }
    else if (   EditorXD->Selection.Figures.Count == 1 && EditorXD->Selection.Figures[0].SCuts.Count==2 &&
                EditorXD->Selection.Figures[0].SCuts[0].CanConnect(EditorXD->Selection.Figures[0].SCuts[1] )
            )
    {
        //Fix Point
        EditorXD->Selection.Figures[0].SCuts[0].CanConnect(EditorXD->Selection.Figures[0].SCuts[1])->Fixed
            = !EditorXD->Selection.Figures[0].SCuts[0].CanConnect(EditorXD->Selection.Figures[0].SCuts[1])->Fixed;
    }
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::CreateLinkAction()
{
    if ( EditorXD->Selection.Figures.Count == 1 && EditorXD->Selection.Figures[0].SCuts.Count==1)
    {
        //DistanceLink
        EditorXD->Selection.Figures[0].Figure->MakeDistanceLink(
            (TG2DPoint*)EditorXD->Selection.Figures[0].SCuts[0].Src,
            (TG2DPoint*)EditorXD->Selection.Figures[0].SCuts[0].Dst);
    }
    else if (   EditorXD->Selection.Figures.Count == 1 && EditorXD->Selection.Figures[0].SCuts.Count==2 )
    {
        //AngleLink
        EditorXD->Selection.Figures[0].Figure->MakeAngleLink(
                        (TG2DCut*)(&EditorXD->Selection.Figures[0].SCuts[0]),
                        (TG2DCut*)(&EditorXD->Selection.Figures[0].SCuts[1]),
                        alsFirst );

    }                        
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::_EscCommands()
{
    CreateSelect = false;
}

TSelect::~TSelect()
{
    delete &SelLinkPen;
    delete &SelPointPen;
    delete &SelRibPen;
    delete &BackPen;
    delete SelectedRender;
}

void TSelect::State1()
{
    EpsValueP = EditorXD->MyView->Factor(EpsValue);
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::Action2()
{
    Point1 = Point2 = UIP.NewCursorPos;
}

bool TSelect::Condition3()
{
    TIntVec SnapPoint;
    int CutIndex;
    T2DGObject* MF;
    SelectedMF = NULL;
    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
        if (EditorXD->CustomFigures[i].Snap(Point1, SnapPoint, CutIndex, EpsValueP, false) && !EditorXD->CustomFigures[i].Fixid)
        {
            SelectedMF = EditorXD->CustomFigures.Items[i];
            return true;
        }
    return false;
}

void TSelect::State4()
{
    Point2 = UIP.NewCursorPos;
    EditorXD->MyView->View->InvalidateGL();
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
    EditorXD->Selection.Figures.Clear();
    SelectedMF = NULL;
    CreateSelect = true;
    SelectedPoint = UIP.NewCursorPos;
    SnapSelectedPoint.x = 0;
    SnapSelectedPoint.y = 0;
}

void TSelect::State1to2()
{
    SelectedPoint.x += (UIP.NewCursorPos.x - OldCursorPos.x);
    SelectedPoint.y += (UIP.NewCursorPos.y - OldCursorPos.y);
    TIntVec D = SnapSelectedPoint - EditorXD->AllSnap(SelectedPoint, true, true, false, false, false);
    SnapSelectedPoint.x -= D.x;
    SnapSelectedPoint.y -= D.y;
    CreateSelect = true;
}

void TSelect::Action1to2ESC()
{
    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
    {
        for (int j = 0; j < EditorXD->CustomFigures[i].VertexCount; j++)
        {
            EditorXD->CustomFigures[i].GetVertex(j).Point.x -= SnapSelectedPoint.x;
            EditorXD->CustomFigures[i].GetVertex(j).Point.y -= SnapSelectedPoint.y;
        }
//        EditorXD->CustomFigures[i].CreateView();
    }
    EditorXD->MyView->VisOrtCam->Transformation->Translation->incX(SnapSelectedPoint.x);
    EditorXD->MyView->VisOrtCam->Transformation->Translation->incY(SnapSelectedPoint.y);
    EditorXD->Grid.Attr.ReBuild = true;
}

void TSelect::Action6()
{
    SelectedMF = NULL;
    EditorXD->Selection.Figures.Clear();
    CreateSelect = true;
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
    TIntVec P1 = EditorXD->MyView->ProjectToScreen(Point1);
    TIntVec P2 = EditorXD->MyView->ProjectToScreen(Point2);
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
    BuffSel.SCuts.Add(NULL);
    TIntVec P;
    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
    {
        if (EditorXD->CustomFigures[i].Fixid)
            continue;
        for (int j = 0; j < EditorXD->CustomFigures[i].CutsCount; j++)
        {
            TIntVec Src = EditorXD->MyView->ProjectToScreen(EditorXD->CustomFigures[i].GetCut(j).Src->Point);
            TIntVec Dst = EditorXD->MyView->ProjectToScreen(EditorXD->CustomFigures[i].GetCut(j).Dst->Point);
            bool b = false;
            int ICC = IsCutsCrossedExactly(TIntVec(P1.x, P1.y, 0),
                                           TIntVec(P2.x, P1.y, 0),
                                           Src,
                                           Dst,P);
            if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                b = true;
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P1.x, P2.y, 0),
                                           TIntVec(P2.x, P2.y, 0),
                                           Src,
                                           Dst,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P1.x, P1.y, 0),
                                           TIntVec(P1.x, P2.y, 0),
                                           Src,
                                           Dst,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                ICC = IsCutsCrossedExactly(TIntVec(P2.x, P1.y, 0),
                                           TIntVec(P2.x, P2.y, 0),
                                           Src,
                                           Dst,P);
                if ( ICC == lcCROSSING || ICC == lcEQUAL || ICC == lcCOMMONPOINT)
                    b = true;
            }
            if (!b)
            {
                if ((Src.x >= P1.x &&
                    Src.x <= P2.x &&
                    Src.y >= P1.y &&
                    Src.y <= P2.y) ||
                    (Dst.x >= P1.x &&
                    Dst.x <= P2.x &&
                    Dst.y >= P1.y &&
                    Dst.y <= P2.y))
                    b =true;
            }
            if (b){
                int ind = EditorXD->Selection.FindFigure(EditorXD->CustomFigures.Items[i]);
                if (!Click)
                {
                    if (ind == -1)
                    {
                        ind = EditorXD->Selection.Figures.Add(new TSelected);
                        EditorXD->Selection.Figures.Last()->Figure = EditorXD->CustomFigures.Items[i];
                    }
                    EditorXD->Selection.Figures[ind].SCuts.Add( &EditorXD->CustomFigures[i].GetCut(j) );
                    CreateSelect = true;
                }else
                {
                    if (MaxDepthLevel<EditorXD->CustomFigures[i].GetVertex(0).Point.z)
                    {
                        MaxDepthLevel = EditorXD->CustomFigures[i].GetVertex(0).Point.z;
                        BuffSel.Figure = EditorXD->CustomFigures.Items[i];
                        BuffSel.SCuts.Items[0] = &EditorXD->CustomFigures[i].GetCut(j);
                    }

                }
            }

        }
    }
    if (Click && MaxDepthLevel!=-10000000)
    {
        int ind = EditorXD->Selection.FindFigure(BuffSel.Figure);
        if (ind == -1)
        {
            ind = EditorXD->Selection.Figures.Add(new TSelected);
            EditorXD->Selection.Figures.Last()->Figure = BuffSel.Figure;
        }
        EditorXD->Selection.Figures[ind].SCuts.Add( BuffSel.SCuts.Items[0] );
        CreateSelect = true;
    }
    /* Выделение связки*/
    TPolygon SelectRgn;
    SelectRgn.Vertex->Add( new TIntVec(MIN(P1.x,P2.x),MIN(P1.y,P2.y),0) );
    SelectRgn.Vertex->Add( new TIntVec(MAX(P1.x,P2.x),MIN(P1.y,P2.y),0) );
    SelectRgn.Vertex->Add( new TIntVec(MAX(P1.x,P2.x),MAX(P1.y,P2.y),0) );
    SelectRgn.Vertex->Add( new TIntVec(MIN(P1.x,P2.x),MAX(P1.y,P2.y),0) );
    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
        for (int j = 0; j < EditorXD->CustomFigures[i].LinksCount; j++)
            if ( SelectRgn.ConsistsPoint( EditorXD->CustomFigures[i].GetLink(j).Position,_MBTi_eps_ ) != pipOUTSIDE )
            {
                CreateSelect = true;
                //добавляем связку в выделение
                int index = EditorXD->Selection.FindFigure( &EditorXD->CustomFigures[i] );
                TSelected* Sel;
                if (  index == -1  )
                {
                    EditorXD->Selection.Figures.Add( new TSelected() );
                    EditorXD->Selection.Figures.Last()->Figure = &EditorXD->CustomFigures[i];
                    Sel = EditorXD->Selection.Figures.Last();
                }
                else
                    Sel = EditorXD->Selection.Figures.GetItem(index);
                //----------------
                if ( Sel->SLinks.IndexOf( &EditorXD->CustomFigures[i].GetLink(j) ) == -1 )
                    Sel->SLinks.Add( &EditorXD->CustomFigures[i].GetLink(j) );
            }
                
}

bool TSelect::Condition21()
{
    if (SelectedMF && typeid(*SelectedMF) == typeid(TInfinityLine))
        return true;
    else
        return false;
}

/*
void TSelect::BeforePointMoving()
{
    TIntVec MP = UIP.NewCursorPos;
    OldCursorPos = UIP.NewCursorPos;
    EditorXD->Selection.Figures.Clear();
    EditorXD->Selection.Figures.Add(new TSelected);
    EditorXD->Selection.Figures.Last()->Figure = SelectedMF;
    for (int i = 0; i < EditorXD->Selection.Figures.Last()->Figure->CutsCount; i++)
        EditorXD->Selection.Figures.Last()->CutIndices.Add(new int(i));
    CreateSelect = true;
    if (typeid(*SelectedMF) == typeid(TInfinityLine))
    {
        int CutIndex;
        MBTi EpsValueF = fabs(EditorXD->MyView->ScreenToProject(EpsValue+2,0,0).x - EditorXD->MyView->ScreenToProject(0,0,0).x);
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
    TIntVec D = SelectedPoint - EditorXD->AllSnap(SelectedPoint, true, false, false, false, false);
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x -= D.x;
        SelectedMF->GetVertex(i).Point.y -= D.y;
        SelectedMF->CreateView();
    }
    SelectedPoint.x -= D.x;
    SelectedPoint.y -= D.y;
    SnapSelectedPoint = SelectedPoint;
    EditorXD->MyView->View->InvalidateGL();
}
void TSelect::PointMoving()
{
    TIntVec DD = (UIP.NewCursorPos - OldCursorPos);
    SelectedPoint += DD;
    TIntVec D = SnapSelectedPoint - EditorXD->AllSnap(SelectedPoint, true, true, true, true, false);
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
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::AfterPointMoving()
{
    TIntVec D = SnapSelectedPoint - SelectedPoint;
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x += D.x;
        SelectedMF->GetVertex(i).Point.y += D.y;
    }
    SelectedMF->CreateView();
    EditorXD->MyView->View->InvalidateGL();
}
*/

void TSelect::BeforePointMoving()
{
    SelectedPointIndex = -1;
    OldCursorPos = UIP.NewCursorPos;

    TIntVec MP = UIP.NewCursorPos;
    EditorXD->Selection.Figures.Clear();
    EditorXD->Selection.Figures.Add(new TSelected);
    EditorXD->Selection.Figures.Last()->Figure = SelectedMF;
    for (int i = 0; i < SelectedMF->CutsCount; i++)
        EditorXD->Selection.Figures.Last()->SCuts.Add( &(SelectedMF->GetCut(i)) );
    CreateSelect = true;
    if (SelectedMF && typeid(*SelectedMF) == typeid(TInfinityLine))
    {
        /*not supported for one point moving*/
        int CutIndex;
        MBTi EpsValueF = fabs(EditorXD->MyView->ScreenToProject(EpsValue+2,0,0).x - EditorXD->MyView->ScreenToProject(0,0,0).x);
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
    SelectedMF->PrepareMoving( &SelectedMF->GetVertex(SelectedPointIndex) );
/*    TIntVec D = SelectedPoint - EditorXD->AllSnap(SelectedPoint, true, false, false, false, false);
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x -= D.x;
        SelectedMF->GetVertex(i).Point.y -= D.y;
        SelectedMF->CreateView();
    }
    SelectedPoint.x -= D.x;
    SelectedPoint.y -= D.y;
    SnapSelectedPoint = SelectedPoint;
    EditorXD->MyView->View->InvalidateGL();  */
}


void TSelect::PointMoving()
{
    TIntVec DD = (UIP.NewCursorPos - OldCursorPos);
    DD.z = 0;
    SelectedMF->ContinueMoving( SelectedMF->GetVertex(SelectedPointIndex).Point + DD );
//    SelectedMF->ChangePointCoordinate( &SelectedMF->GetVertex(SelectedPointIndex),SelectedMF->GetVertex(SelectedPointIndex).Point + DD);
//    SelectedMF->GetVertex(SelectedPointIndex).Point += DD;
    SnapSelectedPoint = SelectedMF->GetVertex(SelectedPointIndex).Point;
    SelectedPoint = SnapSelectedPoint;
    SelectedMF->CreateView();
    OldCursorPos = SelectedMF->GetVertex(SelectedPointIndex).Point;
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::AfterPointMoving()
{
    SelectedMF->EndMoving();
/*    TIntVec D = SnapSelectedPoint - SelectedPoint;
    for (int i = 0; i < SelectedMF->VertexCount; i++)
    {
        SelectedMF->GetVertex(i).Point.x += D.x;
        SelectedMF->GetVertex(i).Point.y += D.y;
    }*/
    SelectedMF->CreateView();
    EditorXD->MyView->View->InvalidateGL();
}

void TSelect::State15()
{
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
}

void TSelect::Action26()
{
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
    MBTi SV5 = EditorXD->MyView->Factor(5);
    BB[0] = TIntVec(SelectedMF->BBoxLU.x-SV5, SelectedMF->BBoxLU.y-SV5, SelectedMF->BBoxLU.z);
    BB[1] = TIntVec(SelectedMF->BBoxRD.x+SV5, SelectedMF->BBoxLU.y-SV5, SelectedMF->BBoxLU.z);
    BB[2] = TIntVec(SelectedMF->BBoxRD.x+SV5, SelectedMF->BBoxRD.y+SV5, SelectedMF->BBoxRD.z);
    BB[3] = TIntVec(SelectedMF->BBoxLU.x-SV5, SelectedMF->BBoxRD.y+SV5, SelectedMF->BBoxLU.z);
}

bool TSelect::Condition17()
{
    if (UIP.NewCursorPos.Equal2D(SelectedMF->RotateCenter, EditorXD->Attributes.SnapValue))
    {
        return true;
    }else
        return false;
}

void TSelect::Action18to19()
{
}

void TSelect::State18()
{
    SelectedMF->RotateCenter = EditorXD->AllSnap(UIP.NewCursorPos, true, false, false, false, false);
}

bool TSelect::Condition19()
{
    TIntVec MP = UIP.NewCursorPos;
    MBTi D = EditorXD->MyView->Factor(12);

    SRP = SelectedMF->BBoxLU;
    FirstVector = TIntVec(SelectedMF->BBoxLU.x-D, SelectedMF->BBoxLU.y-D, 30);
    if (MP.Equal2D(FirstVector))
        return true;

    SRP = SelectedMF->BBoxRD;
    FirstVector = TIntVec(SelectedMF->BBoxRD.x+D, SelectedMF->BBoxRD.y+D, 30);
    if (MP.Equal2D(FirstVector, EditorXD->Attributes.SnapValue))
        return true;

    SRP = TIntVec(SelectedMF->BBoxLU.x,SelectedMF->BBoxRD.y, SelectedMF->BBoxLU.z);
    FirstVector = TIntVec(SelectedMF->BBoxLU.x-D, SelectedMF->BBoxRD.y+D, 30);
    if (MP.Equal2D(FirstVector, EditorXD->Attributes.SnapValue))
        return true;

    SRP = TIntVec(SelectedMF->BBoxRD.x,SelectedMF->BBoxLU.y, SelectedMF->BBoxLU.z);
    FirstVector = TIntVec(SelectedMF->BBoxRD.x+D, SelectedMF->BBoxLU.y-D, 30);
    if (MP.Equal2D(FirstVector, EditorXD->Attributes.SnapValue))
        return true;

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
//    for (int i = 0; i < EditorXD->CustomFigures.Count; i++)
//        EditorXD->CustomFigures[i].CreateView();
}

void TSelect::Action10()
{
    for(int i = 0; i < EditorXD->Selection.Figures.Count; i++)
    {
        if (typeid(*(EditorXD->Selection.Figures[i].Figure)) == typeid(T2DGObject))
        {
            T2DGObject* CF = (T2DGObject*)EditorXD->Selection.Figures[i].Figure;

            for(int j = 0; j < EditorXD->Selection.Figures[i].SLinks.Count; j++)
                CF->Delete( &EditorXD->Selection.Figures[i].SLinks[j] );

            for(int j = 0; j < EditorXD->Selection.Figures[i].SCuts.Count; j++)
                CF->Delete( &EditorXD->Selection.Figures[i].SCuts[j] );
            for(int j = 0; j < CF->VertexCount; j++)
                if (CF->GetVertex(j).CutsCount == 0)
                    CF->DeletePoint( j-- );
        }
    }

    for(int i = 0; i < EditorXD->Selection.Figures.Count; i++)
    {
        if (typeid(*(EditorXD->Selection.Figures[i].Figure)) == typeid(T2DGObject))
        {
            if (EditorXD->Selection.Figures[i].Figure->CutsCount<1)
                EditorXD->CustomFigures.Remove(EditorXD->Selection.Figures[i].Figure);
        }
        else if (typeid(*(EditorXD->Selection.Figures[i].Figure)) == typeid(TInfinityLine))
            EditorXD->CustomFigures.Remove(EditorXD->Selection.Figures[i].Figure);
    }

    EditorXD->Selection.Figures.Clear();
    SelectedMF = NULL;
}

bool TSelect::Condition22()
{
    TIntVec SnapPoint;
    SelectedMF = NULL;
    int CutIndex;
    for (int i = 0; i < EditorXD->Selection.Figures.Count; i++)
        if (EditorXD->Selection.Figures[i].Figure->Snap(Point1, SnapPoint, CutIndex, EpsValueP, false))
        {
            int index = EditorXD->Selection.Figures[i].FindCutIndex( &EditorXD->Selection.Figures[i].Figure->GetCut(CutIndex) );
            if ( index!=-1 )
            {
                SelectedMF = EditorXD->Selection.Figures[i].Figure;
                return true;
            }
            break;
        }
    Point2 = Point1;
    return false;
}

bool TSelect::Condition23()
{
    int FigSelInd, CutSelInd;
    for (int i = 0; i < SelectedMF->CutsCount; i++)
        if ( !EditorXD->Selection.FindCutAndFigureIndices(SelectedMF, &SelectedMF->GetCut(i), FigSelInd, CutSelInd) )
            return false;
    return true;
}

void TSelect::Action24()
{
    TIntVec SnapPoint;
    int CutIndex;
    if (SelectedMF->Snap(Point1, SnapPoint, CutIndex, EpsValueP, false))
    {
        int FigSelInd = EditorXD->Selection.FindFigure(SelectedMF);
        if ( FigSelInd != -1)
        {
            EditorXD->Selection.Figures[FigSelInd].SCuts.Remove( &SelectedMF->GetCut(CutIndex) );
            if (EditorXD->Selection.Figures[FigSelInd].SCuts.Count == 0)
                EditorXD->Selection.Figures.Delete(FigSelInd);
        }
    }
}

void TSelect::OnRender()
{
    if (ExecutedId == 3)
    {
        EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
        EditorXD->MyView->View->Canvas->Pen->Color = clWhite;
        EditorXD->MyView->View->Canvas->Brush->Color = clWhite;
        TIntVec P1 = EditorXD->MyView->ProjectToScreen(Point1);
        TIntVec P2 = EditorXD->MyView->ProjectToScreen(Point2);
        EditorXD->MyView->View->Canvas->MoveTo(floor(P1.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P1.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P2.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P2.y));
        EditorXD->MyView->View->Canvas->LineTo(floor(P1.x), floor(P1.y));
    }
    if (CreateSelect)
    {
        SelectedRender->Init();
        SelectedRender->ColorAsMaterial = cmAmbient;
        glLineWidth(EditorXD->Attributes.LinesWidth.Selected);
        SelectedRender->Color->Color = EditorXD->Attributes.Colors.Selected;
        SelectedRender->AddPrimitiveArray(GL_LINES);
        SelectedRender->AddPrimitiveArray(GL_POINTS);
        int Index = 0;
        if (SelectedMF)
        {
            EditorXD->MyView->View->Canvas->Pen->Style = lsSolid;
            TIntVec P = EditorXD->MyView->ProjectToScreen(SelectedMF->RotateCenter);
            P = EditorXD->MyView->ProjectToScreen(RotatePoint);
            EditorXD->MyView->View->Canvas->Pen->Color = clRed;
            EditorXD->MyView->View->Canvas->Brush->Color = clRed;
            EditorXD->MyView->View->Canvas->Brush->Alpha = 0;
            EditorXD->MyView->View->Canvas->Pen->Width = 3;
        }
        for (int i = 0; i < EditorXD->Selection.Figures.Count; i++)
            EditorXD->Selection.Figures[i].Figure->RenderSelection
                                                    (
                                                        EditorXD->MyView->View,
                                                        SelPointPen,
                                                        SelRibPen,
                                                        SelLinkPen,
                                                        EditorXD->Selection.Figures[i].SPoints,
                                                        EditorXD->Selection.Figures[i].SCuts,
                                                        EditorXD->Selection.Figures[i].SLinks
                                                    );

        if (ExecutedId == 8 || ExecutedId == 12)
        {
            glPointSize(5);
            Index = SelectedRender->Points->Add(ToVec(SelectedPoint.x,
                                                      SelectedPoint.y,
                                                      EditorXD->DepthLevels.Selected),ZEROVEC,ZEROVEC);
            SelectedRender->AddIndex(Index,1);

            SelectCursor.Position = TIntVec(SnapSelectedPoint.x, SnapSelectedPoint.y, EditorXD->DepthLevels.Selected);
            SelectCursor.Render(EditorXD->MyView);
        }
        if (ExecutedId == 15 || ExecutedId == 17 || ExecutedId == 19)
        {
            RotatedCursor.Position = TIntVec(SelectedMF->RotateCenter.x, SelectedMF->RotateCenter.y, EditorXD->DepthLevels.Selected);
            RotatedCursor.Render(EditorXD->MyView);

            EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
            TIntVec P = EditorXD->MyView->ProjectToScreen(SelectedMF->RotateCenter);
            P = EditorXD->MyView->ProjectToScreen(RotatePoint);
            EditorXD->MyView->View->Canvas->Pen->Color = clBlue;
            EditorXD->MyView->View->Canvas->Brush->Color = clBlue;
            EditorXD->MyView->View->Canvas->Brush->Alpha = 0;
            EditorXD->MyView->View->Canvas->Transparency = tmAlpha;
//            EditorXD->MyView->View->Canvas->Polygon(pnts,13);

/*            EditorXD->MyView->View->Canvas->Ellipse(P.x+Rad, P.y+Rad, P.x-Rad, P.y-Rad);
            P = MyView->ProjectToScreen(RotatePoint);
            EditorXD->MyView->View->Canvas->Ellipse(P.x+10, P.y+10, P.x-10, P.y-10);*/
            if (ExecutedId == 19)
            {
                TIntVec P1 = EditorXD->MyView->ProjectToScreen(BB[0]);
                EditorXD->MyView->View->Canvas->MoveTo(P1.x, P1.y);
                for (int i = 1; i < 4; i++)
                {
                    TIntVec P1 = EditorXD->MyView->ProjectToScreen(BB[i]);
                    EditorXD->MyView->View->Canvas->LineTo(P1.x, P1.y);
                }
                P1 = EditorXD->MyView->ProjectToScreen(BB[0]);
                EditorXD->MyView->View->Canvas->LineTo(P1.x, P1.y);
            }
            TIntVec P1 = EditorXD->MyView->ProjectToScreen(SelectedMF->BBoxLU);
            TIntVec P2 = EditorXD->MyView->ProjectToScreen(SelectedMF->BBoxRD);
/*            UIP.EditorXD->MyView->View->Canvas->Pen->Style = lsDash;
            UIP.EditorXD->MyView->View->Canvas->MoveTo(P1.x-5, P1.y+5);
            UIP.EditorXD->MyView->View->Canvas->LineTo(P2.x+5, P1.y+5);
            UIP.EditorXD->MyView->View->Canvas->LineTo(P2.x+5, P2.y-5);
            UIP.EditorXD->MyView->View->Canvas->LineTo(P1.x-5, P2.y-5);
            UIP.EditorXD->MyView->View->Canvas->LineTo(P1.x-5, P1.y+5);*/
/*            for(int i = 0; i < 8; i+=2)
            {
                VCO->Points->Point[i][0] = SelectedMF->BBoxLU.x;
                VCO->Points->Point[i][1] = SelectedMF->BBoxLU.y;
                VCO->Points->Point[i][2] = SelectedMF->BBoxLU.z;

                VCO->Points->Point[i+1][0] = SelectedMF->BBoxRD.x;
                VCO->Points->Point[i+1][1] = SelectedMF->BBoxRD.y;
                VCO->Points->Point[i+1][2] = SelectedMF->BBoxRD.z;
            }*/

            VCO->Points->Point[0][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[0][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[0][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[1][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[1][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[1][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[2][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[2][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[2][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[3][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[3][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[3][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[4][0] = SelectedMF->BBoxRD.x;
            VCO->Points->Point[4][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[4][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[5][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[5][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[5][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[6][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[6][1] = SelectedMF->BBoxRD.y;
            VCO->Points->Point[6][2] = EditorXD->DepthLevels.Selected;

            VCO->Points->Point[7][0] = SelectedMF->BBoxLU.x;
            VCO->Points->Point[7][1] = SelectedMF->BBoxLU.y;
            VCO->Points->Point[7][2] = EditorXD->DepthLevels.Selected;

            VCO->Render(EditorXD->MyView->View);
/*            UIP.EditorXD->MyView->View->Canvas->Pen->Style = lsSolid;
            TIntVec PP = MyView->ProjectToScreen(SelectedMF->BBoxRD);
            RotateCursor(90, TPoint(PP.x+15, PP.y-15));
            UIP.EditorXD->MyView->View->Canvas->Polygon(pnts,11);
            PP = MyView->ProjectToScreen(SelectedMF->BBoxLU);
            RotateCursor(270, TPoint(PP.x-15, PP.y+15));
            UIP.EditorXD->MyView->View->Canvas->Polygon(pnts,11);
            PP = MyView->ProjectToScreen(TIntVec(SelectedMF->BBoxRD.x, SelectedMF->BBoxLU.y, 30));
            RotateCursor(180, TPoint(PP.x+15, PP.y+15));
            UIP.EditorXD->MyView->View->Canvas->Polygon(pnts,11);
            PP = MyView->ProjectToScreen(TIntVec(SelectedMF->BBoxLU.x, SelectedMF->BBoxRD.y, 30));
            RotateCursor(0, TPoint(PP.x-15, PP.y-15));
            UIP.EditorXD->MyView->View->Canvas->Polygon(pnts,11);*/
        }
    }
    SelectedRender->Render(EditorXD->MyView->View);
}

AnsiString TSelect::OnHint()
{
    if (ExecutedId == 2)
        return " ("+FloatToStrF(Point1.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point1.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(Point2.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point2.y, ffGeneral, 4, EditorXD->Grid.Precision)+")    Ширина: "+FloatToStrF(fabs(Point2.x - Point1.x), ffGeneral, 4, EditorXD->Grid.Precision)+" Высота: "+FloatToStrF(fabs(Point2.y - Point1.y), ffGeneral, 4, EditorXD->Grid.Precision);
    if (ExecutedId == 15 || ExecutedId == 17)
        return " ("+FloatToStrF(SelectedMF->RotateCenter.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(SelectedMF->RotateCenter.y, ffGeneral, 4, EditorXD->Grid.Precision)+")";
    if (ExecutedId == 19)
    {
        MBTi Angle = AngleRad(UIP.NewCursorPos,SelectedMF->RotateCenter,FirstVector);
        return " ("+FloatToStrF(SelectedMF->RotateCenter.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(SelectedMF->RotateCenter.y, ffGeneral, 4, EditorXD->Grid.Precision)+")      Угол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
