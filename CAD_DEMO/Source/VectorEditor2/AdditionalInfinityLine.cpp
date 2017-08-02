//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalInfinityLine.h"
//---------------------------------------------------------------------------
TAdditionalInfinityLine::TAdditionalInfinityLine()
{
    ImageId = 3;
    Description = "auxiliary line";

    AddStateBlock(State1,0,Mouse_Move);
    AddActionBlock(Action2,1);
    AddStateBlock(State3,2,Mouse_Move);
    AddActionBlock(Action4,3);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Down, mbLeft);
    AddGoToBlockId( 3, 0);

    TIntVec V1,V2;
    InfLine.Color = (TColor)0x000000;
    InfLine.GetPoint(0).Point = V1;
    InfLine.GetPoint(1).Point = V2;
    InfLine.GetCut(0).Src = &InfLine.GetPoint(0);
    InfLine.GetCut(0).Dst = &InfLine.GetPoint(1);
}

void TAdditionalInfinityLine::State1()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalInfinityLine::Action2()
{
    Point = UIP.Sender->AllSnap(UIP.NewCursorPos, true, true, true, false, false);
}
                        
void TAdditionalInfinityLine::State3()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    InfLine.GetPoint(0).Point = Point;
    InfLine.GetPoint(1).Point = UIP.Sender->MyCursor.Position;
    InfLine.GetPoint(0).Point.z = UIP.Sender->DepthLevels.Additional;
    InfLine.GetPoint(1).Point.z = UIP.Sender->DepthLevels.Additional;
}

void TAdditionalInfinityLine::Action4()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    InfLine.GetPoint(0).Point = Point;
    InfLine.GetPoint(1).Point = UIP.Sender->MyCursor.Position;
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

void TAdditionalInfinityLine::OnRender()
{
    if (ExecutedId == 2)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);


        InfLine.LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
        InfLine.Color = UIP.Sender->Attributes.Colors.Additional;
        InfLine.CreateView();
        InfLine.Render(UIP.Sender);
    }
    if (ExecutedId == 0)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
    }
}

AnsiString TAdditionalInfinityLine::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, UIP.Sender->MyCursor.Position);
        return " ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, UIP.Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
