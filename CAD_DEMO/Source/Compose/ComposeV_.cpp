//---------------------------------------------------------------------------
#include "MTL.h"
#include "Usefuls.h"
#include "MyTemplates.h"
#include "Poligon.h"
#include "Triangulation.h"
#include <vcl.h>

#pragma hdrstop

#include "ComposeV_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MBTi xCos(TIntVec v1, TIntVec v2)
{
    TIntVec normal = TIntVec(-v1.y, v1.x, 0);
    v1 = v1*-1;
    v1 = v1.Normalize();
    v2 = v2.Normalize();
    MBTi cs = ScalarP(v1, v2);
    MBTi Angle = acosDC(cs);
	if (ScalarP(normal, v2)<0) Angle = 2*M_PI - Angle;
    return Angle;
}
void Composing(TMDelTList<TLPoint>& Pnts, TMDelTList<TLCut>& Cuts, TMDelTList<TPolygon>& POLS)
{
    TLPoint *begin = NULL;

    TLPoint *src = NULL;
    TLPoint *dst = NULL;
    TLCut	*cut = NULL;

//Находим самую нижнюю точку
    for (int i=0;i<Pnts.Count;i++)
	{
	   	if (src == NULL)
        	src = &Pnts[i];
        else
        	if (src->Point.y > Pnts[i].Point.y)
    			src = &Pnts[i];
    }
    begin = src;

//Находим отрезок, самый поворачивающий направо
    for (int i=0;i<src->Cuts.Count;i++)
    	if (src->Cuts[i].Src == src)
        {
        	if (cut == NULL ||
            ((src->Cuts[i].Dst->Point - src->Cuts[i].Src->Point).Normalize()).x <
            ((dst->Point - src->Point).Normalize()).x)
            {
				cut = &src->Cuts[i];
                dst = &src->Cuts[i].Dst;
            }
        }
        else
        {
        	if (cut == NULL ||
            ((src->Cuts[i].Src->Point - src->Cuts[i].Dst->Point).Normalize()).x <
            ((dst->Point - src->Point).Normalize()).x)
            {
				cut = &src->Cuts[i];
                dst = &src->Cuts[i].Src;
            }
        }

    do
    {
        TLPoint *nxtDst = NULL;

        for (int i=0;i<dst->Cuts.Count;i++)
	        if (cut != &dst->Cuts[i])
                if (dst == dst->Cuts[i].Src)
                    if ( nxtDst == NULL ||
                    	xCos(dst->Point - src->Point, nxtDst->Point - dst->Point)>
                        xCos(dst->Point - src->Point, dst->Cuts[i].Dst->Point - dst->Point) )
                    {
                        nxtDst = dst->Cuts[i].Dst;
                        cut = &dst->Cuts[i];
                    }
                else
                    if ( nxtDst == NULL ||
                    	xCos(dst->Point - src->Point, nxtDst->Point - dst->Point)>
                        xCos(dst->Point - src->Point, dst->Cuts[i].Src->Point - dst->Point) )
                    {
                        nxtDst = dst->Cuts[i].Src;
                        cut = &dst->Cuts[i];
                    }
        src = dst;
        dst = nxtDst;
    }
    while(begin == dst);

}

/*void Composing(TPolygon& SRC, TMDelTList<TPolygon>& POLS)
{
	Delone.
} */
