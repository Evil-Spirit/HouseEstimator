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
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
}

void TCreateObjectLinesFixid::Action2()
{
    UIP.Sender->CustomFigures.Add(new TCustomFigure);
    UIP.Sender->CustomFigures.Last()->Additional = true;
    UIP.Sender->CustomFigures.Last()->Fixid = true;
    UIP.Sender->CustomFigures.Last()->Color = UIP.Sender->Attributes.Colors.Fixid;
    UIP.Sender->CustomFigures.Last()->LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
    MO = UIP.Sender->CustomFigures.Last();
    Point = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
}

void TCreateObjectLinesFixid::State3()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);

    VCO->Color->Color = UIP.Sender->Attributes.Colors.Fixid;
    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = UIP.Sender->DepthLevels.Figures;
    VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[1][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[1][2] = UIP.Sender->DepthLevels.Figures;
    VCO->CalcNormals();
}

bool TCreateObjectLinesFixid::Conditional4()
{
    if(MO->FindPoint(UIP.Sender->MyCursor.Position) != -1)
        return true;
    else
        return false;
}

void TCreateObjectLinesFixid::Action5()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->Color = UIP.Sender->Attributes.Colors.Fixid;
    CF->AddCut(TIntVec(Point.x, Point.y, UIP.Sender->DepthLevels.Figures), TIntVec(UIP.Sender->MyCursor.Position.x, UIP.Sender->MyCursor.Position.y, UIP.Sender->DepthLevels.Fixid));
    Point = UIP.Sender->MyCursor.Position;
}

void TCreateObjectLinesFixid::Action6()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->Color = UIP.Sender->Attributes.Colors.Fixid;
    CF->AddCut(TIntVec(Point.x, Point.y, UIP.Sender->DepthLevels.Figures), TIntVec(UIP.Sender->MyCursor.Position.x, UIP.Sender->MyCursor.Position.y, UIP.Sender->DepthLevels.Fixid));
}

void TCreateObjectLinesFixid::OnRender()
{
    if (ExecutedId == 2)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
        VCO->Color->Color = UIP.Sender->Attributes.Colors.Fixid;
        glLineWidth(UIP.Sender->Attributes.LinesWidth.Additional);
        VCO->Render(UIP.Sender->View);
    }
    if (ExecutedId == 0)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
    }
}

AnsiString TCreateObjectLinesFixid::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, UIP.Sender->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")  ("+FloatToStrF(UIP.Sender->MyCursor.Position.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(UIP.Sender->MyCursor.Position.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, UIP.Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
