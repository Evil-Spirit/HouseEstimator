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
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalDivLine::Action2()
{
    Point = EditorXD->AllSnap(UIP.NewCursorPos, true, true, true, false, false);
}

void TAdditionalDivLine::State3()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
    VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
    VCO->CalcNormals();
}

void TAdditionalDivLine::Action4()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    TIntVec Sr = (EditorXD->MyCursor.Position + Point) / 2;
    InfLine.GetPoint(0).Point = Sr;
    InfLine.GetPoint(1).Point = Sr;
    if (fabs(EditorXD->MyCursor.Position.x-Point.x)<0.0001)
        InfLine.GetPoint(1).Point.x = Sr.x-100;
    else
    {
        InfLine.GetPoint(1).Point.x = Sr.x - ((EditorXD->MyCursor.Position.y-Point.y)*(100-Sr.y)/(EditorXD->MyCursor.Position.x-Point.x));
        InfLine.GetPoint(1).Point.y = 100;
    }
    InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
    InfLine.GetPoint(1).Point.z = EditorXD->DepthLevels.Additional;
    EditorXD->CustomFigures.Add(new TInfinityLine);
    TInfinityLine* IL = (TInfinityLine*)EditorXD->CustomFigures.Last();

    IL->GetPoint(0).Point = InfLine.GetPoint(0).Point;
    IL->GetPoint(1).Point = InfLine.GetPoint(1).Point;

    IL->GetCut(696).Src = &IL->GetPoint(0);
    IL->GetCut(696).Dst = &IL->GetPoint(1);

    IL->LineWidth = EditorXD->Attributes.LinesWidth.Additional;
    IL->Color = EditorXD->Attributes.Colors.Additional;
    
    EditorXD->Grid.Attr.ReBuild = true;
}

void TAdditionalDivLine::OnRender()
{
    if (ExecutedId == 2)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);

        InfLine.Color = EditorXD->Attributes.Colors.Additional;
        InfLine.LineWidth = EditorXD->Attributes.LinesWidth.Additional;
        TIntVec Sr = (EditorXD->MyCursor.Position + Point) / 2;
        InfLine.GetPoint(0).Point.z = EditorXD->DepthLevels.Additional;
        InfLine.GetPoint(1).Point.z = EditorXD->DepthLevels.Additional;
        InfLine.GetPoint(0).Point = Sr;
        InfLine.GetPoint(1).Point = Sr;
        if (fabs(EditorXD->MyCursor.Position.x-Point.x)<0.0001)
            InfLine.GetPoint(1).Point.x = Sr.x-100;
        else
        {
            InfLine.GetPoint(1).Point.x = Sr.x - ((EditorXD->MyCursor.Position.y-Point.y)*(100-Sr.y)/(EditorXD->MyCursor.Position.x-Point.x));
            InfLine.GetPoint(1).Point.y = 100;
        }
//        InfLine.CreateView();
        InfLine.Render(EditorXD->MyView);
        VCO->Color->Color = EditorXD->Attributes.Colors.Additional;
        glLineWidth(EditorXD->Attributes.LinesWidth.Additional);
        VCO->Render(EditorXD->MyView->View);
    }
    if (ExecutedId == 0)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
        SnapCursor->Render(EditorXD->MyView->View);
    }
}

AnsiString TAdditionalDivLine::OnHint()
{
    if (ExecutedId == 2)
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(EditorXD->MyCursor.Position.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(EditorXD->MyCursor.Position.y, ffGeneral, 4, EditorXD->Grid.Precision)+")";
    return "";
}
#pragma package(smart_init)
