//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "AdditionalBox.h"

//---------------------------------------------------------------------------
TAdditionalBox::TAdditionalBox(bool _AdditionalFigure)
{
    if(_AdditionalFigure)
    {
        ImageId = 4;
        Description = "Auxiliary rectangle";
    }else
    {
        ImageId = 2;
        Description = "Contour Rectangle";
    }
    AdditionalFigure = _AdditionalFigure;
    VCO->Init();
    VCO->Color->Color = (TColor)0x000000;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);

    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);

    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);

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


void TAdditionalBox::State1()
{
    if (AdditionalFigure)
        ZZZ = UIP.Sender->DepthLevels.Additional;
    else
        ZZZ = UIP.Sender->DepthLevels.Figures;
    if(AdditionalFigure)
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    else
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
}

void TAdditionalBox::Action2()
{
    if(AdditionalFigure)
        Point = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    else
        Point = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
}

void TAdditionalBox::State3()
{
    if(AdditionalFigure)
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    else
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = ZZZ;

    VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[1][1] = Point.y;
    VCO->Points->Point[1][2] = ZZZ;

    VCO->Points->Point[2][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[2][1] = Point.y;
    VCO->Points->Point[2][2] = ZZZ;

    VCO->Points->Point[3][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[3][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[3][2] = ZZZ;

    VCO->Points->Point[4][0] = UIP.Sender->MyCursor.Position.x;
    VCO->Points->Point[4][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[4][2] = ZZZ;

    VCO->Points->Point[5][0] = Point.x;
    VCO->Points->Point[5][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[5][2] = ZZZ;

    VCO->Points->Point[6][0] = Point.x;
    VCO->Points->Point[6][1] = UIP.Sender->MyCursor.Position.y;
    VCO->Points->Point[6][2] = ZZZ;

    VCO->Points->Point[7][0] = Point.x;
    VCO->Points->Point[7][1] = Point.y;
    VCO->Points->Point[7][2] = ZZZ;

    VCO->CalcNormals();
}

void TAdditionalBox::Action4()
{
    if(AdditionalFigure)
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
    else
        UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
    UIP.Sender->CustomFigures.Add(new TCustomFigure);
    TCustomFigure* CF = (TCustomFigure*)UIP.Sender->CustomFigures.Last();
    CF->Additional = AdditionalFigure;
    if (AdditionalFigure)
    {
        CF->Color = UIP.Sender->Attributes.Colors.Additional;
        CF->LineWidth = UIP.Sender->Attributes.LinesWidth.Additional;
    }else
    {
        CF->Color = UIP.Sender->Attributes.Colors.MyFigures;
        CF->LineWidth = UIP.Sender->Attributes.LinesWidth.MyFigures;
    }
    CF->AddCut(TIntVec(Point.x,Point.y,ZZZ),TIntVec(UIP.Sender->MyCursor.Position.x,Point.y,ZZZ));
    CF->AddCut(TIntVec(UIP.Sender->MyCursor.Position.x,Point.y,ZZZ),TIntVec(UIP.Sender->MyCursor.Position.x,UIP.Sender->MyCursor.Position.y,ZZZ));
    CF->AddCut(TIntVec(UIP.Sender->MyCursor.Position.x,UIP.Sender->MyCursor.Position.y,ZZZ),TIntVec(Point.x,UIP.Sender->MyCursor.Position.y,ZZZ));
    CF->AddCut(TIntVec(Point.x,UIP.Sender->MyCursor.Position.y,ZZZ),TIntVec(Point.x,Point.y,ZZZ));
}

void TAdditionalBox::OnRender()
{
    if (ExecutedId == 2)
    {
        if(AdditionalFigure)
            UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        else
            UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
        if (AdditionalFigure)
        {
            VCO->Color->Color = UIP.Sender->Attributes.Colors.Additional;
            glLineWidth(UIP.Sender->Attributes.LinesWidth.Additional);
        }else
        {
            glLineWidth(UIP.Sender->Attributes.LinesWidth.MyFigures);
            VCO->Color->Color = UIP.Sender->Attributes.Colors.MyFigures;
        }

        VCO->Points->Point[0][0] = Point.x;
        VCO->Points->Point[0][1] = Point.y;
        VCO->Points->Point[0][2] = ZZZ;

        VCO->Points->Point[1][0] = UIP.Sender->MyCursor.Position.x;
        VCO->Points->Point[1][1] = Point.y;
        VCO->Points->Point[1][2] = ZZZ;

        VCO->Points->Point[2][0] = UIP.Sender->MyCursor.Position.x;
        VCO->Points->Point[2][1] = Point.y;
        VCO->Points->Point[2][2] = ZZZ;

        VCO->Points->Point[3][0] = UIP.Sender->MyCursor.Position.x;
        VCO->Points->Point[3][1] = UIP.Sender->MyCursor.Position.y;
        VCO->Points->Point[3][2] = ZZZ;

        VCO->Points->Point[4][0] = UIP.Sender->MyCursor.Position.x;
        VCO->Points->Point[4][1] = UIP.Sender->MyCursor.Position.y;
        VCO->Points->Point[4][2] = ZZZ;

        VCO->Points->Point[5][0] = Point.x;
        VCO->Points->Point[5][1] = UIP.Sender->MyCursor.Position.y;
        VCO->Points->Point[5][2] = ZZZ;

        VCO->Points->Point[6][0] = Point.x;
        VCO->Points->Point[6][1] = UIP.Sender->MyCursor.Position.y;
        VCO->Points->Point[6][2] = ZZZ;

        VCO->Points->Point[7][0] = Point.x;
        VCO->Points->Point[7][1] = Point.y;
        VCO->Points->Point[7][2] = ZZZ;

        VCO->CalcNormals();
        VCO->Render(UIP.Sender->View);
    }
    if (ExecutedId == 0)
    {
        if(AdditionalFigure)
            UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, true, false, false);
        else
            UIP.Sender->MyCursor.Position = UIP.Sender->AllSnap(UIP.Sender->MyCursor.Position, true, true, false, false, false);
        UIP.Sender->MyCursor.Position.z = UIP.Sender->DepthLevels.Selected;
        UIP.Sender->MyCursor.Render(UIP.Sender);
    }
}

AnsiString TAdditionalBox::OnHint()
{
    if (ExecutedId == 2)
        return " ("+FloatToStrF(Point.x, ffGeneral	, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")  ("+FloatToStrF(UIP.Sender->MyCursor.Position.x, ffGeneral, 4, UIP.Sender->Grid.Precision)+"; "+FloatToStrF(UIP.Sender->MyCursor.Position.y, ffGeneral, 4, UIP.Sender->Grid.Precision)+")    Ширина: "+FloatToStrF(fabs(UIP.Sender->MyCursor.Position.x - Point.x), ffGeneral, 4, UIP.Sender->Grid.Precision)+" Высота: "+FloatToStrF(fabs(UIP.Sender->MyCursor.Position.y - Point.y), ffGeneral, 4, UIP.Sender->Grid.Precision);
    return "";
}
#pragma package(smart_init)
