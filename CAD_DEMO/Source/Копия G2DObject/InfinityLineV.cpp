//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "InfinityLineV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TClassNode* TInfinityLine::StaticType = NULL;

    //инициализация классов
void Register2DGObject()
{
    T2DGObject CF;
    TInfinityLine IL;
}

#pragma startup Register2DGObject

//------------------------------TInfinityLine------------------------------------------------
TMyObject* TInfinityLine::CreateFunction()
{
    return new TInfinityLine();
}

//------------------------------TInfinityLine------------------------------------------------
TInfinityLine::TInfinityLine()
{
    RegisterNewClass< T2DGObject, TInfinityLine >(this, false, &CreateFunction);
    Additional = true;
}

/*void TInfinityLine::Render(TEditor2D* aView)
{
//    CreateView();
    if (NeedCreateView)
    {
        TIntVec a = aView->ScreenToProject(0, aView->View->Height, 0);
        TIntVec b = aView->ScreenToProject(aView->View->Width, 0, 0);
        if (a.x > b.x)
        {
            MBTi buff = a.x;
            a.x = b.x;
            b.x = buff;
        }
        if (a.y > b.y)
        {
            MBTi buff = a.y;
            a.y = b.y;
            b.y = buff;
        }
        TIntVec P,V1,V2;
        bool V1b = false;
        bool V2b = false;
        int ICC = IsLinesCrossedExactly(TIntVec(a.x, a.y, 0),
                                       TIntVec(b.x, a.y, 0),
                                       GetVertex(0).Point,
                                       GetVertex(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.x >= a.x && P.x < b.x)
            {
                V1 = P;
                V1b = true;
            }
        ICC = IsLinesCrossedExactly(TIntVec(b.x, a.y, 0),
                                    TIntVec(b.x, b.y, 0),
                                       GetVertex(0).Point,
                                       GetVertex(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.y >= a.y && P.y < b.y)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        ICC = IsLinesCrossedExactly(TIntVec(a.x, b.y, 0),
                                    TIntVec(b.x, b.y, 0),
                                       GetVertex(0).Point,
                                       GetVertex(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.x >= a.x && P.x < b.x)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        ICC = IsLinesCrossedExactly(TIntVec(a.x, a.y, 0),
                                    TIntVec(a.x, b.y, 0),
                                       GetVertex(0).Point,
                                       GetVertex(1).Point,P);
        if (ICC == lcCROSSING || ICC == lcCOMMONPOINT)
            if (P.y >= a.y && P.y < b.y)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        if (V1b && V2b && (V1 != V2) )
        {
            RedPoint[0].Point = V1;
            RedPoint[1].Point = V2;
            VCO->Points->Point[0][0] = V1.x;
            VCO->Points->Point[0][1] = V1.y;
            VCO->Points->Point[0][2] = V1.z;
            VCO->Points->Point[1][0] = V2.x;
            VCO->Points->Point[1][1] = V2.y;
            VCO->Points->Point[1][2] = V2.z;
            VCO->CalcNormals();
        }
    }
    VCO->Color->Color = Color;
    glLineWidth(LineWidth);
    VCO->Render(aView->View);
} */