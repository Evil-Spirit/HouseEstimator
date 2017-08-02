//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalInfinityPerLine.h"

//---------------------------------------------------------------------------
TAdditionalInfinityPerLine::TAdditionalInfinityPerLine()
{
    ImageId = 11;
    Description = "Perpendicular auxiliary line";
    PerLine = false;

    AddStateBlock(State1,0,Mouse_Move);
    AddConditionalBlock(Conditional2,1);
    AddActionBlock(Action3,2);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2, 0);
    AddGoToBlockId( 2, 0);

    TIntVec V1,V2;
    InfLine.Color = (TColor)0x000000;
    InfLine.GetPoint(0).Point = V1;
    InfLine.GetPoint(1).Point = V2;
    InfLine.GetCut(int('X')).Src = &InfLine.GetPoint(0);
    InfLine.GetCut(int('X')).Dst = &InfLine.GetPoint(1);
}

void TAdditionalInfinityPerLine::State1()
{
    Point2 = Point1 = UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    TIntVec P1, P2;
    if (UIP.Sender->AllFigureSnap(UIP.NewCursorPos, P1, P2, true, true))
    {
        PerLine = true;
        if (fabs(P2.x-P1.x)<0.0001)
            Point2.x = Point1.x-100;
        else
        {
            Point2.x = Point1.x - ((P2.y-P1.y)*(100-Point2.y)/(P2.x-P1.x));
            Point2.y = 100;
        }
        InfLine.GetPoint(0).Point = Point1;
        InfLine.GetPoint(1).Point = Point2;
        InfLine.GetPoint(0).Point.z = UIP.Sender->DepthLevels.Additional;
        InfLine.GetPoint(1).Point.z = UIP.Sender->DepthLevels.Additional;
    }else
    {
        PerLine = false;
    }
}

bool TAdditionalInfinityPerLine::Conditional2()
{
    return PerLine;
}

void TAdditionalInfinityPerLine::Action3()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    InfLine.GetPoint(0).Point = Point1;
    InfLine.GetPoint(1).Point = Point2;
    InfLine.GetPoint(0).Point.z = UIP.Sender->DepthLevels.Additional;
    InfLine.GetPoint(1).Point.z = UIP.Sender->DepthLevels.Additional;
    UIP.Sender->CustomFigures.Add(new TInfinityLine);
    TInfinityLine* IL = (TInfinityLine*)UIP.Sender->CustomFigures.Last();

    IL->GetPoint(0).Point = InfLine.GetPoint(0).Point;
    IL->GetPoint(1).Point = InfLine.GetPoint(1).Point;

    IL->GetCut(696).Src = &IL->GetPoint(0);
    IL->GetCut(696).Dst = &IL->GetPoint(1);

    IL->Color = UIP.Sender->Attributes.Colors.Additional;
    IL->LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
}

void TAdditionalInfinityPerLine::OnRender()
{
    if (ExecutedId == 0)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);

        if (PerLine)
        {
            InfLine.Color = UIP.Sender->Attributes.Colors.Additional;
            InfLine.LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
            InfLine.CreateView();
            InfLine.Render(UIP.Sender);
        }
    }
}

AnsiString TAdditionalInfinityPerLine::OnHint()
{
    if (ExecutedId == 0 && PerLine)
    {
        MBTi Angle = AngleRadOX(Point1, Point2);
        return " ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, UIP.Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
