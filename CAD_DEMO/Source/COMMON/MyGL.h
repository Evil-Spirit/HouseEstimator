//---------------------------------------------------------------------------

#ifndef MyGLH
#define MyGLH
#include "VisMath.hpp"
#include "VisView.hpp"
#include "VisCustomObj.hpp"
#include "math.h"

//---------------------------------------------------------------------------
const double EPS=0.2;
//возможно необходима проверка на принадлежность точек одной прямой
COMMONAL_API double Opredelitel2d(double x11,double x12,double x21,double x22);
COMMONAL_API double PointInPrimitiv(TVisMathVector &P1,TVisMathVector &P2,TVisMathVector &P3,TVisMathVector &P);
COMMONAL_API void BestPrimitive(TVisView *VV,TVisNode *VN,TVisCustomObj *OBJ,TVisMathVector &Point,int *Bests,int N=2);
COMMONAL_API TVisMathVector ObjectSize(TVisCustomObj *OBJ);
COMMONAL_API TVisMathVector NodeSize(TVisNode *Node);
COMMONAL_API int u(int i);
COMMONAL_API int d(int i);
COMMONAL_API void CopyVisNode(TVisNode *Source,TVisNode *Target);

COMMONAL_API TVisMathVector CameraPosition(TVisView *VV);
COMMONAL_API TVisMathVector GetPointOnRender(TVisView *VV,int X,int Y);
COMMONAL_API bool GetPointOnRender2(int X,int Y,TVisMathVector& Vector);

COMMONAL_API TIntVec SlopeAround(  const TIntVec& Point,
                      const TIntVec& Slope,
                      const TIntVec& Param,
                      const TIntVec& Center);

COMMONAL_API MBTi slope_around(MBTi x, MBTi y, MBTi y0, MBTi angle);
COMMONAL_API MBTi slope_delta(MBTi y, MBTi y0, MBTi angle);

COMMONAL_API void ObjectMinMax(TVisPrimitiveObj *OBJ,TVisMathVector &Min,TVisMathVector &Max);

COMMONAL_API void UpdateMinVector(TIntVec& Min,const TIntVec& Vec);
COMMONAL_API void UpdateMaxVector(TIntVec& Max,const TIntVec& Vec);

COMMONAL_API void Slope( TVisPrimitiveObj *Obj,
            const TIntVec& ParamPlus,
            const TIntVec& ParamMinus );

COMMONAL_API void SlopeMinMax( TVisPrimitiveObj *Obj,
            const TIntVec& ParamPlus,
            const TIntVec& ParamMinus,
            const TVisMathVector _Min,
            const TVisMathVector _Max);

COMMONAL_API void SlopeNode( TVisRender *Obj,
                const TIntVec& ParamPlus,
                const TIntVec& ParamMinus);

COMMONAL_API TVisMathVector RotateAroundVMV(const TVisMathVector& Point,const TVisMathVector& Angle,const TVisMathVector& Center);

COMMONAL_API void EconomRotate(  const TIntVec& Point,
                    const TIntVec& Angle,
                    const TIntVec& Center,
                    TIntVec& Result);


COMMONAL_API void CreateArrow(TVisPrimitiveObj* Obj, const TIntVec& Size, TColor Color);

COMMONAL_API void CreateNetLine(TVisPrimitiveObj* Net, const TIntVec& Size, const TIntVec& Step);
COMMONAL_API void CreateNetPoint(TVisPrimitiveObj* Net, const TIntVec& Size, const TIntVec& Step);
COMMONAL_API void CreateSizer(TVisPrimitiveObj* Sizer, const TIntVec& Size, TColor Color);


//TVisMathVector WinFrom3D(const TVisMathVector& Value);


COMMONAL_API void InflateRectEx(TRect& R,int lOffset,int tOffset,int rOffset,int bOffset);

COMMONAL_API void RectForBMP(const TRect& Where,Graphics::TBitmap* BMP,TRect& Res );

COMMONAL_API bool VisMathVectorsEqual(const TVisMathVector& A,const TVisMathVector& B);

COMMONAL_API bool VectorsEqual(const TVisVector* A,const TVisMathVector& B);

COMMONAL_API bool VisVectorsEqual(const TVisVector* A,const TVisVector* B);

COMMONAL_API MBTi CalcTriangleArea(  const TVisMathVector& A,
                        const TVisMathVector& B,
                        const TVisMathVector& C,int plane);

COMMONAL_API MBTi CalcTriangleArea(  const TIntVec& A,
                        const TIntVec& B,
                        const TIntVec& C,int plane);


COMMONAL_API void BMPResize(Graphics::TBitmap* bmp,int nWidth,int nHeight);
COMMONAL_API void Smooth(Graphics::TBitmap* temp_bmp,Graphics::TBitmap* bmp,int AD);
COMMONAL_API void Smooth(Graphics::TBitmap* bmp,int AD);
COMMONAL_API void ImageResize(Graphics::TBitmap* bmp,int nWidth,int nHeight);

COMMONAL_API void scale2x(Graphics::TBitmap* bmpFrom, Graphics::TBitmap* bmpTo);

#endif
