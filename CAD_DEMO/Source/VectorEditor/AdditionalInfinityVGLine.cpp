//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalInfinityVGLine.h"

//---------------------------------------------------------------------------
TAdditionalInfinityVGLine::TAdditionalInfinityVGLine(MBTi _dx, MBTi _dy)
{
    ImageId = 4;
    Description = "auxiliary line";
    if (_dx == 0 && _dy != 0)
    {
        Description = "Vertical auxiliary line";
        ImageId = 7;
    }
    if (_dx != 0 && _dy == 0)
    {
        Description = "Horizontal auxiliary line";
        ImageId = 8;
    }
    dx = _dx;
    dy = _dy;

    AddStateBlock(State1,0,Mouse_Move);
    AddActionBlock(Action2,1);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 0);

    TIntVec V1,V2;
    InfLine.Color = (TColor)0x000000;
    InfLine.GetPoint(0).Point = V1;
    InfLine.GetPoint(1).Point = V2;
    InfLine.GetCut(int('X')).Src = &InfLine.GetPoint(0);
    InfLine.GetCut(int('X')).Dst = &InfLine.GetPoint(1);
}

void TAdditionalInfinityVGLine::State1()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalInfinityVGLine::Action2()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    TIntVec Point = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    InfLine.GetPoint(0).Point = Point;
    InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
    InfLine.GetPoint(1).Point = TIntVec(Point.x+dx,Point.y+dy,EditorXD->DepthLevels.Additional);
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

void TAdditionalInfinityVGLine::OnRender()
{
    if (ExecutedId == 0)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);

        InfLine.LineWidth = EditorXD->Attributes.LinesWidth.Additional;
        InfLine.Color = EditorXD->Attributes.Colors.Additional;
        TIntVec Point = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        InfLine.GetPoint(0).Point = Point;
        InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
        InfLine.GetPoint(1).Point = TIntVec(Point.x+dx,Point.y+dy,EditorXD->DepthLevels.Additional);
 //       InfLine.CreateView();
        InfLine.Render(EditorXD->MyView);
   }
}

AnsiString TAdditionalInfinityVGLine::OnHint()
{
    if (ExecutedId == 0)
    {
        if (dx == 0 && dy != 0)
            return " X:"+FloatToStrF(EditorXD->MyCursor.Position.x, ffGeneral, 4, EditorXD->Grid.Precision);
        if (dx != 0 && dy == 0)
            return " Y:"+FloatToStrF(EditorXD->MyCursor.Position.y, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
