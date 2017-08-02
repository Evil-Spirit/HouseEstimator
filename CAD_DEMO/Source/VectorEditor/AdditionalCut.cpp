//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalCut.h"

//---------------------------------------------------------------------------
TAdditionalCut::TAdditionalCut()
{
    ImageId = 6;
    Description = "Limited auxiliary line";
    VCO->Init();
    VCO->Color->Color = (TColor)0x000000;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
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
}

void TAdditionalCut::State1()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalCut::Action2()
{
    Point = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalCut::State3()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = EditorXD->DepthLevels.Additional;
    VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
    VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
    VCO->Points->Point[1][2] = EditorXD->DepthLevels.Additional;
    VCO->CalcNormals();
}

void TAdditionalCut::Action4()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    EditorXD->CustomFigures.Add(new TCustomFigure);
    TCustomFigure* CF = (TCustomFigure*)EditorXD->CustomFigures.Last();
    CF->Additional = true;
    CF->Color = EditorXD->Attributes.Colors.Additional;
    CF->LineWidth = EditorXD->Attributes.LinesWidth.Additional;
    Point.z = EditorXD->DepthLevels.Additional;
    EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Additional;
    CF->AddCut(Point,EditorXD->MyCursor.Position);
    EditorXD->Grid.Attr.ReBuild = true;
}

void TAdditionalCut::OnRender()
{
    if (ExecutedId == 2)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
        glLineWidth(EditorXD->Attributes.LinesWidth.Additional);
        VCO->Color->Color = EditorXD->Attributes.Colors.Additional;
        VCO->Points->Point[0][0] = Point.x;
        VCO->Points->Point[0][1] = Point.y;
        VCO->Points->Point[0][2] = EditorXD->DepthLevels.Additional;
        VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
        VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
        VCO->Points->Point[1][2] = EditorXD->DepthLevels.Additional;
        VCO->CalcNormals();
        VCO->Render(EditorXD->MyView->View);
    }
    if (ExecutedId == 0)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
    }
}

AnsiString TAdditionalCut::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, EditorXD->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(EditorXD->MyCursor.Position.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(EditorXD->MyCursor.Position.y, ffGeneral, 4, EditorXD->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
