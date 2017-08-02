//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "ViewV.h"
#include "math.h"
#include "EditorV.h"

//---------------------------------------------------------------------------
const AnsiString aSize = "Size";
const AnsiString aLineWidth = "LineWidth";
const AnsiString aColor = "Color";

TMyCursor::TMyCursor()
{
    Visible = true;
    Size = 20;
    LineWidth = 1;
    Color = (TColor)0xffffff;
    VCO = new TVisPrimitiveObj(NULL);
    VCO->Init();
    VCO->Color->Color = Color;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->CalcNormals();

    RegisterField(&Size, &aSize, mtInt);
    RegisterField(&LineWidth, &aLineWidth, mtInt);
    RegisterField(&Color, &aColor, mtInt);
}

/*TMyCursor::TMyCursor(bool _Visible, MBTi _SizeCursor)
{
    LineWidth = 1;
    Visible = _Visible;
    Size = _SizeCursor;
    Color = (TColor)0xffffff;
    VCO = new TVisPrimitiveObj(NULL);
    VCO->Init();
    VCO->Color->Color = Color;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->CalcNormals();
}*/

void TMyCursor::Render(TEditor2D* aView)
{
    VCO->Color->Color = Color;
    MBTi SizeS = fabs(Editor2D->ScreenToProject(0,0,0).x-Editor2D->ScreenToProject(Size,0,0).x);
    VCO->Points->Point[0][0] = Position.x-SizeS;
    VCO->Points->Point[0][1] = Position.y;
    VCO->Points->Point[0][2] = Position.z;
    VCO->Points->Point[1][0] = Position.x+SizeS;
    VCO->Points->Point[1][1] = Position.y;
    VCO->Points->Point[1][2] = Position.z;
    VCO->Points->Point[2][0] = Position.x;
    VCO->Points->Point[2][1] = Position.y-SizeS;
    VCO->Points->Point[2][2] = Position.z;
    VCO->Points->Point[3][0] = Position.x;
    VCO->Points->Point[3][1] = Position.y+SizeS;
    VCO->Points->Point[3][2] = Position.z;
    glLineWidth(LineWidth);
    VCO->Render(aView->View);
}

TMyObject* TMyCursor::CreateFunction()
{
    return new TMyCursor();
}

#pragma package(smart_init)
