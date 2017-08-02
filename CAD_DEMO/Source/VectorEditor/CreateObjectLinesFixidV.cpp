//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "CreateObjectLinesFixidV.h"

//---------------------------------------------------------------------------
TCreateObjectLinesFixid::TCreateObjectLinesFixid()
{
    ImageId = 5;
    Description = "Fixed outline";
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
    AddConditionalBlock(Conditional4,3);
    AddActionBlock(Action5,4);
    AddActionBlock(Action6,5);

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Down, mbLeft);

    AddGoToBlockId( 3, 5, 4);

    AddGoToBlockId( 4, 2);
    AddGoToBlockId( 5, 0);
    AddGoToBlockId( 2, 0, Mouse_Down, mbRight);
    //AddGoToBlockId( 2, 6, Key_Down, VK_ESCAPE);

}

void TCreateObjectLinesFixid::State1()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
}

void TCreateObjectLinesFixid::Action2()
{
    EditorXD->CustomFigures.Add(new TCustomFigure);
    EditorXD->CustomFigures.Last()->Additional = true;
    EditorXD->CustomFigures.Last()->Fixid = true;
    EditorXD->CustomFigures.Last()->Color = EditorXD->Attributes.Colors.Fixid;
    EditorXD->CustomFigures.Last()->LineWidth = EditorXD->Attributes.LinesWidth.Additional;
    MO = EditorXD->CustomFigures.Last();
    Point = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
}

void TCreateObjectLinesFixid::State3()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);

    VCO->Color->Color = EditorXD->Attributes.Colors.Fixid;
    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = EditorXD->DepthLevels.Figures;
    VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
    VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
    VCO->Points->Point[1][2] = EditorXD->DepthLevels.Figures;
    VCO->CalcNormals();
}

bool TCreateObjectLinesFixid::Conditional4()
{
    if(MO->FindPoint(EditorXD->MyCursor.Position) != -1)
        return true;
    else
        return false;
}

void TCreateObjectLinesFixid::Action5()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->Color = EditorXD->Attributes.Colors.Fixid;
    CF->AddCut(TIntVec(Point.x, Point.y, EditorXD->DepthLevels.Figures), TIntVec(EditorXD->MyCursor.Position.x, EditorXD->MyCursor.Position.y, EditorXD->DepthLevels.Fixid));
    Point = EditorXD->MyCursor.Position;
    EditorXD->Grid.Attr.ReBuild = true;
}

void TCreateObjectLinesFixid::Action6()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->Color = EditorXD->Attributes.Colors.Fixid;
    CF->AddCut(TIntVec(Point.x, Point.y, EditorXD->DepthLevels.Figures), TIntVec(EditorXD->MyCursor.Position.x, EditorXD->MyCursor.Position.y, EditorXD->DepthLevels.Fixid));
    EditorXD->Grid.Attr.ReBuild = true;
}

void TCreateObjectLinesFixid::OnRender()
{
    if (ExecutedId == 2)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
        VCO->Color->Color = EditorXD->Attributes.Colors.Fixid;
        glLineWidth(EditorXD->Attributes.LinesWidth.Additional);
        VCO->Render(EditorXD->MyView->View);
    }
    if (ExecutedId == 0)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, true, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
    }
}

AnsiString TCreateObjectLinesFixid::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, EditorXD->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(EditorXD->MyCursor.Position.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(EditorXD->MyCursor.Position.y, ffGeneral, 4, EditorXD->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
