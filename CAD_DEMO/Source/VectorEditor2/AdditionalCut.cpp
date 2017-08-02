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
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalCut::Action2()
{
    Point = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
}

void TAdditionalCut::State3()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = UIP.Sender->DepthLevels.Additional;
    VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[1][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[1][2] = UIP.Sender->DepthLevels.Additional;
    VCO->CalcNormals();
}

void TAdditionalCut::Action4()
{
    UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    UIP.Sender->CustomFigures.Add(new T2DGObject);
    T2DGObject* CF = (T2DGObject*)UIP.Sender->CustomFigures.Last();
    CF->Additional = true;
    CF->Color = UIP.Sender->Attributes.Colors.Additional;
    CF->LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
    Point.z = UIP.Sender->DepthLevels.Additional;
    UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Additional;
    CF->AddCut(Point,UIP.Sender->MyCursor.Position);
}

void TAdditionalCut::OnRender()
{
    if (ExecutedId == 2)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
        glLineWidth(UIP.Sender->Attributes.LinesWidth.Additional);
        VCO->Color->Color = UIP.Sender->Attributes.Colors.Additional;
        VCO->Points->Point[0][0] = Point.x;
        VCO->Points->Point[0][1] = Point.y;
        VCO->Points->Point[0][2] = UIP.Sender->DepthLevels.Additional;
        VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
        VCO->Points->Point[1][1] = UIP.Sender->MyCursor.Position.y;
        VCO->Points->Point[1][2] = UIP.Sender->DepthLevels.Additional;
        VCO->CalcNormals();
        VCO->Render(UIP.Sender->View);
    }
    if (ExecutedId == 0)
    {
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
    }
}

AnsiString TAdditionalCut::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, UIP.Sender->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")  ("+FloatToStrF(UIP.Sender->MyCursor.Position.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(UIP.Sender->MyCursor.Position.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, UIP.Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
