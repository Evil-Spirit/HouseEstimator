//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#include <Poligon.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalInfinityParLine.h"

//---------------------------------------------------------------------------
TAdditionalInfinityParLine::TAdditionalInfinityParLine()
{
    ImageId = 10;
    Description = "Parallel auxiliary line";
    PerLine = false;

    SnapCursor->Init();
    SnapCursor->Color->Color = (TColor)0x000000;
    SnapCursor->ColorAsMaterial = cmAmbient;
    SnapCursor->AddPrimitiveArray(GL_LINES);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,90),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,90),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,90),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,90),ZEROVEC,ZEROVEC),0);
    SnapCursor->CalcNormals();

    AddStateBlock(State1,0,Mouse_Move);
    AddConditionalBlock(Conditional2,1);
    AddActionBlock(Action3,2);
    AddStateBlock(State4,3,Mouse_Move);
    AddActionBlock(Action5,4);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2, 0);
    AddGoToBlockId( 2, 3);
    AddGoToBlockId( 3, 4, Mouse_Down, mbLeft);
    AddGoToBlockId( 4, 0);
    AddGoToBlockId( 3, 0, Mouse_Down, mbRight);

    TIntVec V1,V2;
    InfLine.Color = (TColor)0x000000;
    InfLine.GetPoint(0).Point = V1;
    InfLine.GetPoint(1).Point = V2;
    InfLine.GetCut(int('X')).Src = &InfLine.GetPoint(0);
    InfLine.GetCut(int('X')).Dst = &InfLine.GetPoint(1);
}

void TAdditionalInfinityParLine::State1()
{
    Point = Point2 = Point1 = EditorXD->MyCursor.Position = EditorXD->AllSnap(UIP.NewCursorPos, true, true, true, false, false);
    TIntVec P1, P2;
    if (EditorXD->AllFigureSnap(UIP.NewCursorPos, P1, P2, true, true))
    {
        PerLine = true;
        Point2 = P2;
    }else
    {
        PerLine = false;
    }
}

bool TAdditionalInfinityParLine::Conditional2()
{
    return PerLine;
}

void TAdditionalInfinityParLine::Action3()
{
    D.x = Point2.x - Point1.x;
    D.y = Point2.y - Point1.y;
}

void TAdditionalInfinityParLine::State4()
{
    Point1 = EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    Point2 = Point1+D;
    PerLine = true;
    SnapCursor->CalcNormals();
}

void TAdditionalInfinityParLine::Action5()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    InfLine.GetPoint(0).Point = Point1;
    InfLine.GetPoint(1).Point = Point2;
    InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
    InfLine.GetPoint(1).Point.z = EditorXD->DepthLevels.Additional;
    EditorXD->CustomFigures.Add(new TInfinityLine);
    TInfinityLine* IL = (TInfinityLine*)EditorXD->CustomFigures.Last();

    IL->GetPoint(0).Point = InfLine.GetPoint(0).Point;
    IL->GetPoint(1).Point = InfLine.GetPoint(1).Point;

    IL->GetCut(696).Src = &IL->GetPoint(0);
    IL->GetCut(696).Dst = &IL->GetPoint(1);

    IL->Color = EditorXD->Attributes.Colors.Additional;
    IL->LineWidth = EditorXD->Attributes.LinesWidth.Additional;
    
    EditorXD->Grid.Attr.ReBuild = true;
}

void TAdditionalInfinityParLine::OnRender()
{
    if (ExecutedId == 0 || ExecutedId == 3)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);

        if (PerLine)
        {
            InfLine.Color = EditorXD->Attributes.Colors.Additional;
            InfLine.LineWidth = EditorXD->Attributes.LinesWidth.Additional;
            InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
            InfLine.GetPoint(1).Point.z = EditorXD->DepthLevels.Additional;
            InfLine.GetPoint(0).Point = Point1;
            InfLine.GetPoint(1).Point = Point2;
 //           InfLine.CreateView();
            InfLine.Render(EditorXD->MyView);
        }
    }
}

AnsiString TAdditionalInfinityParLine::OnHint()
{
    if (ExecutedId == 0 && PerLine)
    {
        MBTi Angle = AngleRadOX(Point1, Point2);
        return " ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision)+" grad.";
    }
    if (ExecutedId == 3)
    {
        TIntVec V1 = Point;
        TIntVec V2 = V1;
        TIntVec V = V1;
        V2.x += D.y;
        V2.y -= D.x;
//        int ICC = IsLinesCrossedExactly(Point1, Point2, V1, V2, V);
        MBTi d = sqrtDC(fabs(fabs(pow(Point.x - V.x, 2))+fabs(pow(Point.y - V.y, 2))));
        MBTi Angle = AngleRadOX(Point, Point+D);
        return " ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision)+"      —мещение: "+FloatToStrF(d, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
