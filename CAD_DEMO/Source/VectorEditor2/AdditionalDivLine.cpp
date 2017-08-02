//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalDivLine.h"

//---------------------------------------------------------------------------
TAdditionalDivLine::TAdditionalDivLine()
{
    ImageId = 9;
    Description = "Dividing auxiliary line";
    VCO->Init();
    VCO->Color->Color = (TColor)0x000000;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,10,20),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(10,0,20),ZEROVEC,ZEROVEC),0);
    VCO->CalcNormals();

    AddStateBlock(State1,0,Mouse_Move);
    AddActionBlock(Action2,1);
    AddStateBlock(State3,2,Mouse_Move);
    AddActionBlock(Action4,3);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Down, mbLeft);
    AddGoToBlockId( 3, 0);
    AddGoToBlockId( 2, 0, Mouse_Down, mbRight);

    TIntVec V1,V2;
    InfLine.Color = (TColor)0x000000;
    InfLine.GetPoint(0).Point = V1;
    InfLine.GetPoint(1).Point = V2;
    InfLine.GetCut(int('X')).Src = &InfLine.GetPoint(0);
    InfLine.GetCut(int('X')).Dst = &InfLine.GetPoint(1);
}

void TAdditionalDivLine::State1()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalDivLine::Action2()
{
    Point = UIP.Sender->AllSnap(UIP.NewCursorPos, true, true, true, false, false);
}

void TAdditionalDivLine::State3()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[1][1] = UIP.Sender->MyCursor.Position.y;
    VCO->CalcNormals();
}

void TAdditionalDivLine::Action4()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    TIntVec Sr = (UIP.Sender->MyCursor.Position + Point) / 2;
    InfLine.GetPoint(0).Point = Sr;
    InfLine.GetPoint(1).Point = Sr;
    if (fabs(UIP.Sender->MyCursor.Position.x-Point.x)<0.0001)
        InfLine.GetPoint(1).Point.x = Sr.x-100;
    else
    {
        InfLine.GetPoint(1).Point.x = Sr.x - ((UIP.Sender->MyCursor.Position.y-Point.y)*(100-Sr.y)/(UIP.Sender->MyCursor.Position.x-Point.x));
        InfLine.GetPoint(1).Point.y = 100;
    }
    InfLine.GetPoint(0).Point.z = UIP.Sender->DepthLevels.Additional;
    InfLine.GetPoint(1).Point.z = UIP.Sender->DepthLevels.Additional;
    UIP.Sender->CustomFigures.Add(new TInfinityLine);
    TInfinityLine* IL = (TInfinityLine*)UIP.Sender->CustomFigures.Last();

    IL->GetPoint(0).Point = InfLine.GetPoint(0).Point;
    IL->GetPoint(1).Point = InfLine.GetPoint(1).Point;

    IL->GetCut(696).Src = &IL->GetPoint(0);
    IL->GetCut(696).Dst = &IL->GetPoint(1);

    IL->LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
    IL->Color = UIP.Sender->Attributes.Colors.Additional;
}

void TAdditionalDivLine::OnRender()
{
    if (ExecutedId == 2)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);

        InfLine.Color = UIP.Sender->Attributes.Colors.Additional;
        InfLine.LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
        TIntVec Sr = (UIP.Sender->MyCursor.Position + Point) / 2;
        InfLine.GetPoint(0).Point.z = UIP.Sender->DepthLevels.Additional;
        InfLine.GetPoint(1).Point.z = UIP.Sender->DepthLevels.Additional;
        InfLine.GetPoint(0).Point = Sr;
        InfLine.GetPoint(1).Point = Sr;
        if (fabs(UIP.Sender->MyCursor.Position.x-Point.x)<0.0001)
            InfLine.GetPoint(1).Point.x = Sr.x-100;
        else
        {
            InfLine.GetPoint(1).Point.x = Sr.x - ((UIP.Sender->MyCursor.Position.y-Point.y)*(100-Sr.y)/(UIP.Sender->MyCursor.Position.x-Point.x));
            InfLine.GetPoint(1).Point.y = 100;
        }
        InfLine.CreateView();
        InfLine.Render(UIP.Sender);
        VCO->Color->Color = UIP.Sender->Attributes.Colors.Additional;
        glLineWidth(UIP.Sender->Attributes.LinesWidth.Additional);
        VCO->Render(UIP.Sender->View);
    }
    if (ExecutedId == 0)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
        SnapCursor->Render(UIP.Sender->View);
    }
}

AnsiString TAdditionalDivLine::OnHint()
{
    if (ExecutedId == 2)
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")  ("+FloatToStrF(UIP.Sender->MyCursor.Position.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(UIP.Sender->MyCursor.Position.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")    отношение: "+FloatToStrF(100, ffGeneral, 4, 2)+"%";
    return "";
}
#pragma package(smart_init)
