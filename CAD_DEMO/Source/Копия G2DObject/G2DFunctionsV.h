//---------------------------------------------------------------------------

#ifndef G2DFunctionsVH
#define G2DFunctionsVH
#include "VisView.hpp"
#include "VisPrimitiveObj.hpp"
//---------------------------------------------------------------------------
void COMMONAL_API AddVectorToList(
                        TMDelTList<TIntVec>& PointList,
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& P00,
                        const TIntVec& P11,
                        MBTi USEEPS);

bool COMMONAL_API ConsistsNotStrictly(const TIntVec& P,const TIntVec& A,const TIntVec& B,MBTi USEEPS);
                        
bool COMMONAL_API CrossPointStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS);


bool COMMONAL_API CrossPointNotStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS);

TPoint COMMONAL_API PointFromVMV(const TVisMathVector& VMV);

MBTi COMMONAL_API Factor(TVisView* VisView,double Depth);

void COMMONAL_API Arc3D(
            TMDelTList<TIntVec>& PointList,
            const TIntVec& Center,
            const TIntVec& P1,
            const TIntVec& P2,
            int Detail);

void COMMONAL_API MakeArrow(const TIntVec& P0,const TIntVec& P1,TIntVec& ArrowP11,TIntVec& ArrowP12,MBTi Length,MBTi Width,bool Back);

void COMMONAL_API MakeArrowsOnList(TMDelTList<TIntVec>& PointList,MBTi Length,MBTi Width,bool Back);

template <class T>
void ExchangeItem(T& item1,T& item2)
{
    T item = item1;
    item1 = item2;
    item2 = item;
}

void COMMONAL_API Arc3D(
            TVisPrimitiveObj* Obj,
            int PrimitiveArrayIndex,
            const TIntVec& Center,
            const TIntVec& P1,
            const TIntVec& P2,
            int Detail);

void COMMONAL_API AddRayToPointList(
                        TMDelTList<TIntVec>& PointList,
                        const TIntVec& ArcPoint,
                        const TIntVec& P0,
                        const TIntVec& P1,
                        const TIntVec& Center);

void COMMONAL_API  SetPen(TVisPen& ChangedPen,const TVisPen& NewPen,TVisPen* SavePen);

#endif
