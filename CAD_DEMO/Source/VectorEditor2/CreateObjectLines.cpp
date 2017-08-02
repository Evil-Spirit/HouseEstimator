//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop
#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

#include "CreateObjectLines.h"
#include "G2DObjectV.h"

//---------------------------------------------------------------------------
TCreateObjectLines::TCreateObjectLines()
{
    ImageId = 5;
    Description = "Outline";
    VCO->Init();
    VCO->Color->Color = (TColor)0x000000;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->CalcNormals();

    AddStateBlock(State1,0,Mouse_Move,btNone,"State1");
    AddActionBlock(Action2,1,btNone,"Action2");
    AddStateBlock(State3,2,Mouse_Move,btNone,"State3");
    AddConditionalBlock(Conditional4,3,btNone,"Conditional4");
    AddActionBlock(Action5,4,btNone,"Action5");
    AddActionBlock(Action6,5,btNone,"Action6");

    AddGoToBlockId( 0, 1, Mouse_Down, mbLeft);
    AddGoToBlockId( 1, 2);
    AddGoToBlockId( 2, 3, Mouse_Down, mbLeft);

    AddGoToBlockId( 3, 5, 4);

    AddGoToBlockId( 4, 2);
    AddGoToBlockId( 5, 0);
    AddGoToBlockId( 2, 0, Mouse_Down, mbRight);
    //AddGoToBlockId( 2, 6, Key_Down, VK_ESCAPE);

}

void TCreateObjectLines::State1()
{
    Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
    Sender->View->InvalidateGL();    
}

void TCreateObjectLines::Action2()
{
    Sender->CustomFigures.Add(new T2DGObject);
    MO = Sender->CustomFigures.Last();
    Point = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
    MO->CreateView();    
    Sender->View->InvalidateGL();    
}

void TCreateObjectLines::State3()
{
    Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = Sender->DepthLevels.Figures;
    VCO->Points->Point[1][0] = Sender->MyCursor.Position.x;
    VCO->Points->Point[1][1] = Sender->MyCursor.Position.y;
    VCO->Points->Point[1][2] = Sender->DepthLevels.Figures;
    VCO->CalcNormals();
    Sender->View->InvalidateGL();    
}

bool TCreateObjectLines::Conditional4()
{
    Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
    if(MO->FindPoint(Sender->MyCursor.Position) != -1)
        return true;
    else
        return false;
}

void TCreateObjectLines::Action5()
{
    Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
    T2DGObject* CF = (T2DGObject*)MO;
//    CF->Color = Sender->Attributes.Colors.MyFigures;
//    CF->LineWidth = Sender->Attributes.LinesWidth.MyFigures;
    CF->AddCut(TIntVec(Point.x, Point.y, Sender->DepthLevels.Figures), TIntVec(Sender->MyCursor.Position.x, Sender->MyCursor.Position.y, Sender->DepthLevels.Figures));
    Point = Sender->MyCursor.Position;
    CF->CreateView();
    Sender->View->InvalidateGL();
}

void TCreateObjectLines::Action6()
{
    Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
    T2DGObject* CF = (T2DGObject*)MO;
//    CF->Color = Sender->Attributes.Colors.MyFigures;
//    CF->LineWidth = Sender->Attributes.LinesWidth.MyFigures;
    CF->AddCut(TIntVec(Point.x, Point.y, Sender->DepthLevels.Figures), TIntVec(Sender->MyCursor.Position.x, Sender->MyCursor.Position.y, Sender->DepthLevels.Figures));
    CF->CreateView();
    Sender->View->InvalidateGL();
}

void TCreateObjectLines::OnRender()
{
    if (ExecutedId == 2)
    {
        Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
        Sender->MyCursor.Position.z = Sender->DepthLevels.Selected;
        Sender->MyCursor.Render(Sender);
        VCO->Points->Point[0][0] = Point.x;
        VCO->Points->Point[0][1] = Point.y;
        VCO->Points->Point[0][2] = Sender->DepthLevels.Figures;
        VCO->Points->Point[1][0] = Sender->MyCursor.Position.x;
        VCO->Points->Point[1][1] = Sender->MyCursor.Position.y;
        VCO->Points->Point[1][2] = Sender->DepthLevels.Figures;
        VCO->Color->Color = Sender->Attributes.Colors.MyFigures;
        glLineWidth(Sender->Attributes.LinesWidth.MyFigures);
        VCO->Render(Sender->View);
    }
    if (ExecutedId == 0)
    {
        Sender->MyCursor.Position = Sender->AllSnap(Sender->MyCursor.Position, true, true, false, false, false);
        Sender->MyCursor.Position.z = Sender->DepthLevels.Selected;
        Sender->MyCursor.Render(Sender);
    }
}

AnsiString TCreateObjectLines::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, Sender->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, Sender->Grid.Precision)+")  ("+FloatToStrF(Sender->MyCursor.Position.x, ffGeneral, 4, Sender->Grid.Precision)+"; "+FloatToStrF(Sender->MyCursor.Position.y, ffGeneral, 4, Sender->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, Sender->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
