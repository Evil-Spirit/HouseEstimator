//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "FixidCOLV.h"

//---------------------------------------------------------------------------
TCreateObjectLines::TCreateObjectLines()
{
    ImageId = 5;
    Description = "Outline";
    SnapValue = 5;//Pixels
    VCO->Init();
    VCO->Color->Color = (TColor)0xff0000;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->CalcNormals();

    SnapCursor->Init();
    SnapCursor->Color->Color = (TColor)0xffffff;
    SnapCursor->ColorAsMaterial = cmAmbient;
    SnapCursor->AddPrimitiveArray(GL_LINES);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    SnapCursor->AddIndex(SnapCursor->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    SnapCursor->CalcNormals();

    EscCommands = _EscCommands;

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

void TCreateObjectLines::_EscCommands()
{
    UIP.Sender->View->InvalidateGL();
}


void TCreateObjectLines::State1()
{
    SnapValueP = fabs(UIP.Sender->ScreenToProject(SnapValue,0,0).x - UIP.Sender->ScreenToProject(0,0,0).x);
    CursorPos = UIP.Sender->AllSnap(UIP.NewCursorPos, true, true, false, false, SnapValueP);
    SnapCursor->CalcNormals();
    UIP.Sender->View->InvalidateGL();
}

void TCreateObjectLines::Action2()
{
    UIP.Sender->CustomFigures.Add(new TCustomFigure(true, true));
    MO = UIP.Sender->CustomFigures.Last();
    Point1 = UIP.Sender->AllSnap(UIP.NewCursorPos, true, true, false, false, SnapValueP);
}

void TCreateObjectLines::State3()
{
    Point2 = CursorPos = UIP.Sender->AllSnap(UIP.NewCursorPos, true, true, false, false, SnapValueP);

    VCO->Points->Point[0][0] = Point1.x;
    VCO->Points->Point[0][1] = Point1.y;
    VCO->Points->Point[0][2] = UIP.Sender->DepthLevels.Figures;
    VCO->Points->Point[1][0] = Point2.x;
    VCO->Points->Point[1][1] = Point2.y;
    VCO->Points->Point[1][2] = UIP.Sender->DepthLevels.Figures;
    VCO->CalcNormals();
    UIP.Sender->View->InvalidateGL();
}

bool TCreateObjectLines::Conditional4()
{
    if(MO->FindPoint(Point2) != -1)
        return true;
    else
        return false;
}

void TCreateObjectLines::Action5()
{
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->AddCut(TIntVec(Point1.x, Point1.y, UIP.Sender->DepthLevels.Figures), TIntVec(Point2.x, Point2.y, UIP.Sender->DepthLevels.Figures));
    Point1 = Point2;
}

void TCreateObjectLines::Action6()
{
    TCustomFigure* CF = (TCustomFigure*)MO;
    CF->AddCut(TIntVec(Point1.x, Point1.y, UIP.Sender->DepthLevels.Figures), TIntVec(Point2.x, Point2.y, UIP.Sender->DepthLevels.Figures));
    UIP.Sender->View->InvalidateGL();
}

void TCreateObjectLines::OnRender()
{
    if (ExecutedId == 2)
    {
        UIP.Sender->MyCursor.Render(UIP.Sender->View);
        VCO->Render(UIP.Sender->View);
    }
    if (ExecutedId == 0)
        UIP.Sender->MyCursor.Render(UIP.Sender->View);
}

AnsiString TCreateObjectLines::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point1, Point2);
        return " ("+FloatToStrF(Point1.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(fabs(Point1.y), ffGeneral, 4, UIP.Sender->Grid.Precision)+")  ("+FloatToStrF(Point2.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(fabs(Point2.y), ffGeneral, 4, UIP.Sender->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, UIP.Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)

