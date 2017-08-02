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
    //AddGoToBlockId( 5, 0);
    AddGoToBlockId( 5, 2);
    AddGoToBlockId( 2, 0, Mouse_Down, mbRight);
    //AddGoToBlockId( 2, 6, Key_Down, VK_ESCAPE);

}

void TCreateObjectLines::State1()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
    EditorXD->MyView->View->InvalidateGL();
}

void TCreateObjectLines::Action2()
{
    if ( EditorXD->CustomFigures.Count == 0 )
        EditorXD->CustomFigures.Add(new T2DGObject);
    MO = EditorXD->CustomFigures.Items[0];

    Point = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
    Point.z = EditorXD->DepthLevels.Figures;
}

void TCreateObjectLines::State3()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);

    VCO->Points->Point[0][0] = Point.x;
    VCO->Points->Point[0][1] = Point.y;
    VCO->Points->Point[0][2] = EditorXD->DepthLevels.Figures;
    VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
    VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
    VCO->Points->Point[1][2] = EditorXD->DepthLevels.Figures;
    VCO->CalcNormals();
    EditorXD->MyView->View->InvalidateGL();
}

bool TCreateObjectLines::Conditional4()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
    if(MO->FindPoint(EditorXD->MyCursor.Position) != -1)
        return true;
    else
        return false;
}

void TCreateObjectLines::Action5()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
    T2DGObject* CF = (T2DGObject*)MO;
//    CF->Color = EditorXD->Attributes.Colors.MyFigures;
//    CF->LineWidth = EditorXD->Attributes.LinesWidth.MyFigures;
    CF->AddCut(TIntVec(Point.x, Point.y, EditorXD->DepthLevels.Figures), TIntVec(EditorXD->MyCursor.Position.x, EditorXD->MyCursor.Position.y, EditorXD->DepthLevels.Figures));
    CF->CreateView();    
    Point = EditorXD->MyCursor.Position;
    EditorXD->Grid.Attr.ReBuild = true;
}

void TCreateObjectLines::Action6()
{
    EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
    T2DGObject* CF = (T2DGObject*)MO;
//    CF->Color = EditorXD->Attributes.Colors.MyFigures;
//    CF->LineWidth = EditorXD->Attributes.LinesWidth.MyFigures;
    CF->AddCut(TIntVec(Point.x, Point.y, EditorXD->DepthLevels.Figures), TIntVec(EditorXD->MyCursor.Position.x, EditorXD->MyCursor.Position.y, EditorXD->DepthLevels.Figures));
    CF->CreateView();    
    EditorXD->Grid.Attr.ReBuild = true;
}

void TCreateObjectLines::OnRender()
{
    if (ExecutedId == 2)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);

        VCO->Points->Point[0][0] = Point.x;
        VCO->Points->Point[0][1] = Point.y;
        VCO->Points->Point[0][2] = EditorXD->DepthLevels.Figures;
        VCO->Points->Point[1][0] = EditorXD->MyCursor.Position.x;
        VCO->Points->Point[1][1] = EditorXD->MyCursor.Position.y;
        VCO->Points->Point[1][2] = EditorXD->DepthLevels.Figures;
        VCO->Color->Color = EditorXD->Attributes.Colors.MyFigures;
        glLineWidth(EditorXD->Attributes.LinesWidth.MyFigures);
        VCO->Render(EditorXD->MyView->View);
    }
    if (ExecutedId == 0)
    {
        EditorXD->MyCursor.Position = EditorXD->AllSnap(EditorXD->MyCursor.Position, true, true, false, false, false);
        EditorXD->MyCursor.Position.z = EditorXD->DepthLevels.Selected;
        EditorXD->MyCursor.Render(EditorXD->MyView);
    }
}

AnsiString TCreateObjectLines::OnHint()
{
    if (ExecutedId == 2)
    {
        MBTi Angle = AngleRadOX(Point, EditorXD->MyCursor.Position);
        return " ("+FloatToStrF(Point.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(Point.y, ffGeneral, 4, EditorXD->Grid.Precision)+")  ("+FloatToStrF(EditorXD->MyCursor.Position.x, ffGeneral, 4, EditorXD->Grid.Precision)+"; "+FloatToStrF(EditorXD->MyCursor.Position.y, ffGeneral, 4, EditorXD->Grid.Precision)+")      ”гол: "+FloatToStrF(Angle*180/M_PI, ffGeneral, 4, EditorXD->Grid.Precision);
    }
    return "";
}
#pragma package(smart_init)
