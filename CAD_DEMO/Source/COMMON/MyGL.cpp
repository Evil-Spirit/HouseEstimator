 //---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MyGL.h"
//#include "VisObj.hpp"
#include "VisView.hpp"
//#include "VisClass.hpp"
#include "VisShape.hpp"
#include "VisGL.hpp"
#include "Math.hpp"
#include "Poligon.h"
//#include "TBox.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)
const int BestCount=2;
double Opredelitel2d(double x11,double x12,double x21,double x22)
{
    return(x11*x22-x12*x21);
}

double PointInPrimitiv(TVisMathVector &P1,TVisMathVector &P2,TVisMathVector &P3,TVisMathVector &P)
{
    double res= (P.x-P1.x)*Opredelitel2d(P2.y-P1.y,P2.z-P1.z,P3.y-P1.y,P3.z-P1.z)
        -(P.y-P1.y)*Opredelitel2d(P2.x-P1.x,P2.z-P1.z,P3.x-P1.x,P3.z-P1.z)
        +(P.z-P1.z)*Opredelitel2d(P2.x-P1.x,P2.y-P1.y,P3.x-P1.x,P3.y-P1.y);

    return (fabs(res));
}

void BestPrimitive(TVisView *VV,TVisNode *VN,TVisCustomObj *OBJ,TVisMathVector &Point,int *Bests,int N)
{
        double EPSCurrent;
        double EPSBest[BestCount];
        int iBest[BestCount];
        for (int i=0;i<2;i++)
        {
            EPSBest[i]=1000000;
            iBest[i]=-1;
        }
        TVisMathVector j[3];
        for (int i=0;i<OBJ->PrimitiveCount;i++)
        {
            j[0]=VV->ProjectVector(VN,OBJ->Points->PointVec[OBJ->Primitive[i]->Indices[0]]);
            j[1]=VV->ProjectVector(VN,OBJ->Points->PointVec[OBJ->Primitive[i]->Indices[1]]);
            j[2]=VV->ProjectVector(VN,OBJ->Points->PointVec[OBJ->Primitive[i]->Indices[2]]);
            EPSCurrent=PointInPrimitiv(j[0],j[1],j[2],Point);
            if (EPSCurrent>EPSBest[N-1])
                continue;
            int Replaced;
            for (Replaced=N-1;Replaced>0;Replaced--)
                if (EPSCurrent>=EPSBest[Replaced-1])
                    break;
            for (int j=N-1;j>Replaced;j--){
                EPSBest[j]=EPSBest[j-1];
                iBest[j]=iBest[j-1];
            }
            EPSBest[Replaced]=EPSCurrent;
            iBest[Replaced]=i;
       }
       for (int i=0;i<N;i++)
       {
        *Bests=iBest[i];
        Bests++;
       }
}
void UpdateMinVector(TIntVec& Min,const TIntVec& Vec)
{
    for (int i=0;i<3;i++)
        if (Vec.a[i]<Min.a[i])
            Min.a[i]=Vec.a[i];
}

void UpdateMaxVector(TIntVec& Max,const TIntVec& Vec)
{
    for (int i=0;i<3;i++)
        if (Vec.a[i]>Max.a[i])
            Max.a[i]=Vec.a[i];
}

void UpdateMaxVector(TIntVec& Max,const TIntVec& Vec);

void UpdateMinVector(TVisMathVector &Min,TVisMathVector Vec)
{
    for (int i=0;i<3;i++)
        if (Vec.a[i]<Min.a[i])
            Min.a[i]=Vec.a[i];
}

void UpdateMaxVector(TVisMathVector &Max,TVisMathVector Vec)
{
    for (int i=0;i<3;i++)
        if (Vec.a[i]>Max.a[i])
            Max.a[i]=Vec.a[i];
}

TVisMathVector ObjectSize(TVisCustomObj *OBJ)
{
    TVisMathVector Size=ZEROVEC;
    TVisMathVector Min=ToVec(1<<30,1<<30,1<<30);
    TVisMathVector Max=ToVec(-(1<<30),-(1<<30),-(1<<30));
    for (int i=0;i<OBJ->Points->Count;i++)
    {
        UpdateMinVector(Min,OBJ->Points->PointVec[i]);
        UpdateMaxVector(Max,OBJ->Points->PointVec[i]);
    }
    for (int i=0;i<3;i++)
        Size.a[i]=Max.a[i]-Min.a[i];
    return(Size);
}

//only one object
void ObjectMinMax(TVisPrimitiveObj *OBJ,TVisMathVector &Min,TVisMathVector &Max)
{
    Min=ToVec(1<<20,1<<20,1<<20);
    Max=ToVec(-(1<<20),-(1<<20),-(1<<20));
    for (int i=0;i<OBJ->Points->Count;i++)
    {
        UpdateMinVector(Min,OBJ->Points->PointVec[i]);
        UpdateMaxVector(Max,OBJ->Points->PointVec[i]);
    }
}

void NodeMinMax(TVisNode *Node,TVisMathVector &Min,TVisMathVector &Max)
{
    Min=ToVec(1<<30,1<<30,1<<30);
    Max=ToVec(-(1<<30),-(1<<30),-(1<<30));
    TVisMathVector oMin=ToVec(1<<30,1<<30,1<<30);
    TVisMathVector oMax=ToVec(-(1<<30),-(1<<30),-(1<<30));
    for (int i=0;i<Node->Count;i++)
    {
        if (__classid(TVisNode)==Node->Items[i]->ClassType())
        {
            NodeMinMax( ((TVisNode *)Node->Items[i]),oMin,oMax);
            oMin=Node->ProjectVector(Node->Items[i],oMin);
            oMax=Node->ProjectVector(Node->Items[i],oMax);
            UpdateMinVector(Min,oMin);
            UpdateMaxVector(Max,oMax);
            continue;
        }
        if (__classid(TVisPrimitiveObj)==Node->Items[i]->ClassType()||Node->Items[i]->InheritsFrom(__classid(TVisPrimitiveObj)))
        {
            ObjectMinMax((TVisPrimitiveObj *)Node->Items[i],oMin,oMax);
//            oMin=Node->ProjectVector(Node->Items[i],oMin);
  //          oMax=Node->ProjectVector(Node->Items[i],oMax);
            UpdateMinVector(Min,oMin);
            UpdateMaxVector(Max,oMax);
            continue;
        }
    }
}

TVisMathVector NodeSize(TVisNode *Node)
{
    TVisMathVector Size=ZEROVEC;
    TVisMathVector Min=ZEROVEC;
    TVisMathVector Max=ZEROVEC;
    NodeMinMax(Node,Min,Max);
    for (int i=0;i<3;i++)
        Size.a[i]=Max.a[i]-Min.a[i];
    return(Size);
}


int u(int i)
{
    return((i+1) % 3);
}

int d(int i)
{
    return((i+2) % 3);
}

void CopyVisNode(TVisNode *Source,TVisNode *Target)
{
    Target->Clear();
    Target->Matrix->Assign(Source->Matrix);
    // SetIdentityMatrix();
    //Target->Matrix->MultMatrix(Source->Matrix);
    for (int i=0;i<Source->Count;i++)
    {
        if (Source->Items[i]->ClassType()==__classid(TVisCustomObj))
        {
            TVisCustomObj *obj= (TVisCustomObj *)Source->Items[i];
            TVisCustomObj *newobj= new TVisCustomObj(NULL);
            newobj->Assign(obj);
            Target->AddIndirect(newobj);
        }
    }
}

//вызывается внутри рендера
TVisMathVector CameraPosition(TVisView *VV)
{
    TVisBox *VC = new TVisBox(NULL);
    VC->Transformation->Assign(VV->Camera->Transformation);
    VC->Transformation->Order = toRotTraSca;
    VC->Transformation->Rotation->Order = roZYX;
    VC->Transformation->Translation->X = - VC->Transformation->Translation->X;
    VC->Transformation->Translation->Y = - VC->Transformation->Translation->Y;
    VC->Transformation->Translation->Z = - VC->Transformation->Translation->Z;
    VC->Transformation->Rotation->X = - VC->Transformation->Rotation->X;
    VC->Transformation->Rotation->Y = - VC->Transformation->Rotation->Y;
    VC->Transformation->Rotation->Z = - VC->Transformation->Rotation->Z;
    VC->ProjectionEnabled=true;
    VC->Render(VV);
    TVisMathVector Vector= VV->ProjectVector(VC,ZEROVEC);
    delete VC;
    return(Vector);
}


TVisMathVector GetPointOnRender(TVisView *VV,int X,int Y)
{
    TVisBox *VC = new TVisBox(NULL);
    TVisMathVector Vector;
    VV->GetPoint(X,Y,Vector);
    VV->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
    VC->Transformation->Assign(VV->Camera->Transformation);
    VC->Transformation->Order = VV->Camera->Transformation->Order;
    VC->Transformation->Rotation->Order = VV->Camera->Transformation->Rotation->Order;
    VC->ProjectionEnabled=true;
    VC->Render(VV);
    Vector= VC->ProjectVector(VV,Vector);
    VV->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
    delete VC;
    return(Vector);
}

long double FAngle[3];
long double SIN[3];
long double COS[3];
TIntVec Decart;

MBTi sAngle;
int xi;
int yi;
int zi;
MBTi SX;
MBTi SY;
void EconomRotate(  const TIntVec& Point,
                    const TIntVec& Angle,
                    const TIntVec& Center,
                    TIntVec& Result)
{
    if (Point == Center)
    {
        Result = Center;
        return;
    }

    Result=Point-Center;

    for (int i=0;i<3;i++)
    {
        zi = (i+2) % 3;                           
        sAngle = Angle.a[zi];
        if ( sAngle == 0)
            continue;
        xi = i;
        yi = (i+1) % 3;
        SX = Result.a[xi];
        SY = Result.a[yi];
        sAngle = (sAngle*M_PI)/180;
        if (SX!=0||SY!=0)
        {
            if (sAngle!=FAngle[i])
                SinCos(FAngle[i],SIN[i],COS[i]);
            Result.a[xi] = SX*COS[i] - SY*SIN[i];
            Result.a[yi] = SX*SIN[i] + SY*COS[i];
        }
    }
    Result+=Center;
}

TIntVec SLOPE_TEMP;
MBTi temp_angle;



MBTi slope_around(MBTi x, MBTi y, MBTi y0, MBTi angle)
{
  if ( fabs( (angle/90) - RoundTo(angle/90,0) ) < _MBTi_eps_ )
    return x;
  return x + (y-y0)*tan( (angle*M_PI)/180 );
}

MBTi slope_delta(MBTi y, MBTi y0, MBTi angle)
{
  if ( fabs( (angle/90) - RoundTo(angle/90,0) ) < _MBTi_eps_ )
    return 0;
  return (y-y0)*tan( (angle*M_PI)/180 );
}

TIntVec SlopeAround(  const TIntVec& Point,
                      const TIntVec& Slope,
                      const TIntVec& Param,
                      const TIntVec& Center)
{
  SLOPE_TEMP = Point - Center;
  for (int axe=0;axe<3;axe++)
  {
    temp_angle = Slope.a[axe]/90;
    if ( fabs( temp_angle - RoundTo(temp_angle,0) ) < _MBTi_eps_ )
      continue;
    int one = ( (Param.intA(axe)>0) + axe ) % 3;
    int two = ( ( 1 - (Param.intA(axe)>0) ) + axe ) % 3;
    SLOPE_TEMP.a[ one ] = SLOPE_TEMP.a[ one ] + SLOPE_TEMP.a[two]*tan( (Slope.a[axe]*M_PI)/180 );
  }
  return (SLOPE_TEMP + Center);
}


TVisMathVector RotateAroundVMV(const TVisMathVector& Point,const TVisMathVector& Angle,const TVisMathVector& Center)
{
    Decart.x = Point.x-Center.x;
    Decart.y = Point.y-Center.y;
    Decart.z = Point.z-Center.z;
    if (Decart==ZEROINTVEC)
        return(Point);
    for (int i=0;i<3;i++)
    {
        if (Angle.a[(i+2) % 3] == 0)
            continue;
        MBTi x = Decart.a[i];
        MBTi y = Decart.a[(i+1) % 3];
        MBTi _angle = (Angle.a[(i+2) % 3]*M_PI)/180;
        if (x!=0||y!=0)
        {
            if (_angle!=FAngle[i])
            {
                SinCos(_angle,SIN[i],COS[i]);
                FAngle[i] = _angle;
            }
            Decart.a[i]             = x*COS[i] - y*SIN[i];
            Decart.a[(i+1) % 3]     = x*SIN[i] + y*COS[i];
        }
    }
    Decart.x=Center.x+Decart.x;
    Decart.y=Center.y+Decart.y;
    Decart.z=Center.z+Decart.z;
    return(ToVec(Decart.x,Decart.y,Decart.z));
}
//------------------------------------------------------------------------------
    GLdouble projmat[16],modmat[16];
    GLint  viewport[4];

bool GetPointOnRender2(int X,int Y,TVisMathVector& Vector)
{
    GLdouble  px,py,pz;
    GLfloat value;
    GLint really;
    bool returned=false;
    glGetDoublev(GL_PROJECTION_MATRIX,projmat);
    glGetIntegerv(GL_VIEWPORT,viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX,modmat);
    really = viewport[3] - (GLint)Y-1;
    glReadPixels((GLint)X,really,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&value);
    if (value!=1)
        if (gluUnProject((GLdouble)X,(GLdouble)really,value,modmat,projmat,viewport,&px,&py,&pz)==GL_TRUE)
            returned=true;
      Vector=ToVec(px,py,pz);
    return(returned);
}

/*TVisMathVector WinFrom3D(const TVisMathVector& Value)
{
    TVisMathVector RES;
    glGetDoublev(GL_PROJECTION_MATRIX,projmat);
    glGetIntegerv(GL_VIEWPORT,viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX,modmat);
    gluProject(Value.x,Value.y,Value.z,modmat,projmat,viewport,RES.x,RES.y,RES.z);
    RES.y = (viewport[3]-viewport[1])-RES.y;
    return RES;
} */

void SlopeMinMax( TVisPrimitiveObj *Obj,
            const TIntVec& ParamPlus,
            const TIntVec& ParamMinus,
            const TVisMathVector _Min,
            const TVisMathVector _Max)
{
    TIntVec __AnglePlus = ParamPlus*M_PI/180;
    TIntVec __AngleMinus = ParamMinus*M_PI/180;;
    MBTi __angle;
    int one,two,three;

    TIntVec TanPlus;
    TIntVec TanMinus;
    for (int i=0;i<3;i++)
    {
        if (__AnglePlus.a[i]!=0)
            TanPlus.a[i] = tan(__AnglePlus.a[i]*180/M_PI);
        if (__AngleMinus.a[i]!=0)
            TanMinus.a[i] = tan(__AngleMinus.a[i]*180/M_PI);
    }

    for(int i=0;i<Obj->Points->Count;i++)
        for (int axe=0;axe<3;axe++)
        {
            one = axe;
            two = (axe+1)%3;
            three = (axe+2)%3;
            if (Obj->Points->PointVec[i].a[one]<0)
                __angle = __AngleMinus.a[three];//*Obj->Points->PointVec[i].a[one]/_Min.a[one];
            else
                __angle = __AnglePlus.a[three];//*Obj->Points->PointVec[i].a[one]/_Max.a[one];
            if (__angle == 0)
                continue;
            Obj->Points->Point[i][one] = Obj->Points->Point[i][one]+(Obj->Points->PointVec[i].a[two]*tan(__angle));
            Obj->CalcTexturePoint(i);
            i=i;
        }
}

void Slope( TVisPrimitiveObj *Obj,
            const TIntVec& ParamPlus,
            const TIntVec& ParamMinus )
{
    //запомнили положение
    TVisMathVector TR = Obj->Transformation->Translation->AsMathVector;
    TVisMathVector RO = Obj->Transformation->Rotation->AsMathVector;
    //задали исходное положение
    Obj->Transformation->Translation->AsMathVector = ZEROVEC;
    Obj->Transformation->Rotation->AsMathVector = ZEROVEC;

    TVisMathVector _Min;
    TVisMathVector _Max;
    ObjectMinMax(Obj,_Min,_Max);
    bool Move=false;
    for (int i=0;i<3;i++)
        if (_Max.a[i]!=-_Min.a[i])
        {
            Move = true;
            break;
        }

    if (Move)
        Obj->Points->MovePoints(-(_Max.a[0]+_Min.a[0])/2,-(_Max.a[1]+_Min.a[1])/2,-(_Max.a[2]+_Min.a[2])/2);
///-------------------------------------------------
    TVisMathVector _Min1;
    TVisMathVector _Max1;
    for (int i=0;i<3;i++)
    {
        _Max1.a[i] = (_Max.a[i]-_Min.a[i])/2;
        _Min1.a[i] = -_Max1.a[i];
    }
    SlopeMinMax(Obj,ParamPlus,ParamMinus,_Min1,_Max1);
///-------------------------------------------------
    if (Move)
        Obj->Points->MovePoints((_Max.a[0]+_Min.a[0])/2,(_Max.a[1]+_Min.a[1])/2,(_Max.a[2]+_Min.a[2])/2);
    Obj->Transformation->Translation->AsMathVector = TR;
    Obj->Transformation->Rotation->AsMathVector = RO;
}

void SlopeNode( TVisRender *Obj,
                const TIntVec& ParamPlus,
                const TIntVec& ParamMinus)
{
    if (Obj->ClassType() == __classid(TVisPrimitiveObj)||
        Obj->InheritsFrom(__classid(TVisPrimitiveObj)))
    {
        Slope((TVisPrimitiveObj*)Obj,ParamPlus,ParamMinus);
        return;
    }
    if (Obj->ClassType() == __classid(TVisNode)||
        Obj->InheritsFrom(__classid(TVisNode)))
    {
        TVisNode *Node = (TVisNode *)Obj;
        for (int i=0;i<Node->Count;i++)
            SlopeNode(Node->Items[i],ParamPlus,ParamMinus);
    }
}

void CreateArrow(TVisPrimitiveObj* Obj, const TIntVec& Size, TColor Color)
{
    Obj->Init();
    Obj->AddPrimitiveArray(GL_LINES);
    //-----------------создание углоков
    Obj->AddIndex(Obj->Points->Add(ToVec(-Size.x/2,0,0),ZEROVEC,ZEROVEC));
    Obj->AddIndex(Obj->Points->Add(ToVec(Size.x/2,0,0),ZEROVEC,ZEROVEC));
    Obj->AddIndex(Obj->Points->Add(ToVec(0,-Size.y/2,0),ZEROVEC,ZEROVEC));
    Obj->AddIndex(Obj->Points->Add(ToVec(0,Size.y/2,0),ZEROVEC,ZEROVEC));
    Obj->AddIndex(Obj->Points->Add(ToVec(0,0,-Size.z/2),ZEROVEC,ZEROVEC));
    Obj->AddIndex(Obj->Points->Add(ToVec(0,0,Size.z/2),ZEROVEC,ZEROVEC));
    Obj->Color->Color = Color;
    Obj->ColorAsMaterial = cmAmbient;
}


void CreateNetLine(TVisPrimitiveObj* Net, const TIntVec& Size, const TIntVec& Step)
{
    Net->Init();
    Net->AddPrimitiveArray(GL_LINES);
    TIntVec Count = Size.XYZ_Divide(Step);
    Count.x = Floor(Count.x);
    Count.y = Floor(Count.y);
    int index;
    for (int i=0;i<=Count.x;i++)
    {
        index = Net->Points->Add(ToVec(-Size.x/2+Step.x*i,-Size.y/2,0),ZEROVEC,ZEROVEC);
        Net->Primitive[0]->AddIndex(index);
        index = Net->Points->Add(ToVec(-Size.x/2+Step.x*i,Size.y/2,0),ZEROVEC,ZEROVEC);
        Net->Primitive[0]->AddIndex(index);
    }
    for (int i=0;i<=Count.y;i++)
    {
        index = Net->Points->Add(ToVec(-Size.x/2,-Size.y/2+Step.y*i,0),ZEROVEC,ZEROVEC);
        Net->Primitive[0]->AddIndex(index);
        index = Net->Points->Add(ToVec(Size.x/2,-Size.y/2+Step.y*i,0),ZEROVEC,ZEROVEC);
        Net->Primitive[0]->AddIndex(index);
    }
    Net->Texture = NULL;
    Net->CalcNormals();
}

void CreateNetPoint(TVisPrimitiveObj* Net, const TIntVec& Size, const TIntVec& Step)
{
    Net->Init();
    Net->AddPrimitiveArray(GL_POINTS);
    TIntVec Count = Size.XYZ_Divide(Step);
    Count.x = Floor(Count.x);
    Count.y = Floor(Count.y);
    int index;
    for (int i=0;i<=Count.x;i++)
        for (int j=0;j<=Count.y;j++)
    {
        index = Net->Points->Add(ToVec(-Size.x/2+Step.x*i,-Size.y/2+Step.y*j,0),ZEROVEC,ZEROVEC);
        Net->Primitive[0]->AddIndex(index);
    }
    Net->Texture = NULL;
    Net->CalcNormals();
}

void CreateSizer(TVisPrimitiveObj* Sizer, const TIntVec& Size, TColor Color)
{
    Sizer->Init();
    Sizer->AddPrimitiveArray(GL_LINES);
    //основная линия
    Sizer->AddIndex(Sizer->Points->Add(ToVec(-Size.x/2,0,0),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(Size.x/2,0,0),ZEROVEC,ZEROVEC));

    //крест линия
    Sizer->AddIndex(Sizer->Points->Add(ToVec(-Size.x,-Size.y/2,0),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(-Size.x,Size.y/2,0),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(-Size.x,0,-Size.z/2),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(-Size.x,0,Size.z/2),ZEROVEC,ZEROVEC));

    //крест линия
    Sizer->AddIndex(Sizer->Points->Add(ToVec(Size.x,-Size.y/2,0),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(Size.x,Size.y/2,0),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(Size.x,0,-Size.z/2),ZEROVEC,ZEROVEC));
    Sizer->AddIndex(Sizer->Points->Add(ToVec(Size.x,0,Size.z/2),ZEROVEC,ZEROVEC));

    Sizer->CalcNormals();
    Sizer->Color->Color = Color;
    Sizer->ColorAsMaterial = cmAmbient;
}

//---------------------------------------------------------------------------
void InflateRectEx(TRect& R,int lOffset,int tOffset,int rOffset,int bOffset)
{
    R.Left = R.Left+lOffset;
    R.Top = R.Top+tOffset;
    R.Right = R.Right+rOffset;
    R.Bottom = R.Bottom+bOffset;
}


void RectForBMP(const TRect& Where,Graphics::TBitmap* BMP,TRect& Res )
{
    TPoint Center;
    Center.x = (Where.Left+Where.Right)/2;
    Center.y = (Where.Top+Where.Bottom)/2;
    Res.Left = Center.x - BMP->Width/2;
    Res.Right = Res.Left + BMP->Width;
    Res.Top = Center.y - BMP->Height/2;
    Res.Bottom = Res.Top + BMP->Height;

    int RX = MAX(BMP->Width - Where.Width(),0);
    int RY = MAX(BMP->Height - Where.Height(),0);

    int RaznostY;
    int RaznostX;

    if (RX>RY)
    {
        RaznostX = RX;
        RaznostY = int(double(RX)*double(BMP->Height)/double(BMP->Width));
    }
    else
    {
        RaznostY = RY;
        RaznostX = int(double(RY)*double(BMP->Width)/double(BMP->Height));
    }
    RaznostY++;
    RaznostX++;
    InflateRectEx(Res,RaznostX/2,RaznostY/2,-RaznostX/2,-RaznostY/2);
}

bool VisMathVectorsEqual(const TVisMathVector& A,const TVisMathVector& B)
{
    return (A.x == B.x) && (A.y == B.y) && (A.z == B.z);
}

bool VectorsEqual(const TVisVector* A,const TVisMathVector& B)
{
    return (A->X == B.x) && (A->Y == B.y) && (A->Z == B.z);
}

bool VisVectorsEqual(const TVisVector* A,const TVisVector* B)
{
    return (A->X == B->X) && (A->Y == B->Y) && (A->Z == B->Z);
}

MBTi CalcTriangleArea(  const TIntVec& A,
                        const TIntVec& B,
                        const TIntVec& C,int plane)
{
    int x = (plane+1)%3;
    int y = (plane+2)%3;
	double a =  sqrtDC( (B.a[x]-C.a[x])*(B.a[x]-C.a[x]) + (B.a[y]-C.a[y])*(B.a[y]-C.a[y]) );
	double b =  sqrtDC( (A.a[x]-C.a[x])*(A.a[x]-C.a[x]) + (A.a[y]-C.a[y])*(A.a[y]-C.a[y]) );
	double c =  sqrtDC( (B.a[x]-A.a[x])*(B.a[x]-A.a[x]) + (B.a[y]-A.a[y])*(B.a[y]-A.a[y]) );

    double p = (a+b+c)/2;
	return sqrtDC(p*(p-a)*(p-b)*(p-c));
}

MBTi CalcTriangleArea(  const TVisMathVector& A,
                        const TVisMathVector& B,
                        const TVisMathVector& C,int plane)
{
    int x = (plane+1)%3;
    int y = (plane+2)%3;
	MBTi a =  sqrtDC( (B.a[x]-C.a[x])*(B.a[x]-C.a[x]) + (B.a[y]-C.a[y])*(B.a[y]-C.a[y]) );
	MBTi b =  sqrtDC( (A.a[x]-C.a[x])*(A.a[x]-C.a[x]) + (A.a[y]-C.a[y])*(A.a[y]-C.a[y]) );
    MBTi c =  sqrtDC( (B.a[x]-A.a[x])*(B.a[x]-A.a[x]) + (B.a[y]-A.a[y])*(B.a[y]-A.a[y]) );

    MBTi p = (a+b+c)/2;
    return p*(p-a)*(p-b)*(p-c);    
}

/*  Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
// This example shows drawing directly to the Bitmap
  Byte *ptr;
  try
  {
    pBitmap->LoadFromFile("C:\\Program Files\\Common Files\\Borland Shared\\Images\\Splash\\256color\\factory.bmp");
    for (int y = 0; y < pBitmap->Height; y++)
    {
      ptr = (Byte *)pBitmap->ScanLine[y];

      for (int x = 0; x < pBitmap->Width; x++)
        ptr[x] = (Byte)y;
    }
    Canvas->Draw(0,0,pBitmap);
  }
  catch (...)
  {
    ShowMessage("Could not load or alter bitmap");
  }
  delete pBitmap;
*/

TColor ApplyMatrix(Graphics::TBitmap* bmp,int wi,int hj,int AD)
{
    int SUM = 4 + 4*AD;
    int r = GetRValue(bmp->Canvas->Pixels[wi][hj])*4;
    int g = GetGValue(bmp->Canvas->Pixels[wi][hj])*4;
    int b = GetBValue(bmp->Canvas->Pixels[wi][hj])*4;

    int CURSUM = SUM;
    for (int i=-AD;i<=AD;i++)
    {
        if (i==0)
            continue;
        if (wi+i>=0 && wi+i<bmp->Width)
        {
            r = r + GetRValue(bmp->Canvas->Pixels[wi+i][hj]);
            g = g + GetGValue(bmp->Canvas->Pixels[wi+i][hj]);
            b = b + GetBValue(bmp->Canvas->Pixels[wi+i][hj]);
        }
        else
            CURSUM--;
        if (hj+i>=0 && hj+i<bmp->Height)
        {
            r = r + GetRValue(bmp->Canvas->Pixels[wi][hj+i]);
            g = g + GetGValue(bmp->Canvas->Pixels[wi][hj+i]);
            b = b + GetBValue(bmp->Canvas->Pixels[wi][hj+i]);
        }
        else
            CURSUM--;
    }

    r = RoundTo(double(r)/double(CURSUM),0);
    g = RoundTo(double(g)/double(CURSUM),0);
    b = RoundTo(double(b)/double(CURSUM),0);

    return (TColor)RGB(r,g,b);
}


TColor SmoothMatrix(Graphics::TBitmap* bmp,int wi,int hj,int AD)
{
    int SUM = (AD*2+1)*(AD*2+1);
    int r = 0;
    int g = 0;
    int b = 0;
    Byte* sl;
    for (int j=-AD;j<=AD;j++)
    {
        if (hj+j<0 || hj+j>=bmp->Height)
            continue;
        sl = (Byte *)bmp->ScanLine[hj+j];
        for (int i=-AD;i<=AD;i++)
            if (wi+i>=0 && wi+i<bmp->Width)
            {
                r = r + GetRValue((DWORD)sl[4*(wi+i)]);
                g = g + GetGValue((DWORD)sl[4*(wi+i)]);
                b = b + GetBValue((DWORD)sl[4*(wi+i)]);
            }
            else
                SUM--;
    }

    r = RoundTo(double(r)/double(SUM),0);
    g = RoundTo(double(g)/double(SUM),0);
    b = RoundTo(double(b)/double(SUM),0);

    return (TColor)RGB(r,g,b);
}

COLORREF SmoothMatrix2(Graphics::TBitmap* bmp,int wi,int hj,int AD)
{
    int SUM = (AD*2+1)*(AD*2+1);
    int r = 0;
    int g = 0;
    int b = 0;
    for (int j=-AD;j<=AD;j++)
    {
        if (hj+j<0 || hj+j>=bmp->Height)
            continue;
        for (int i=-AD;i<=AD;i++)
            if (wi+i>=0 && wi+i<bmp->Width)
            {
                COLORREF Color = ::GetPixel( bmp->Canvas->Handle,(wi+i),hj+j );
                r = r + GetRValue(Color);
                g = g + GetGValue(Color);
                b = b + GetBValue(Color);
            }
            else
                SUM--;
    }

    r = RoundTo(double(r)/double(SUM),0);
    g = RoundTo(double(g)/double(SUM),0);
    b = RoundTo(double(b)/double(SUM),0);

    return RGB(r,g,b);
}

void Smooth(Graphics::TBitmap* temp_bmp,Graphics::TBitmap* bmp,int AD)
{
    StartProcess("Smoothing ...",bmp->Width*bmp->Height);
    for (int i=0;i<bmp->Width;i++)
        for (int j=0;j<bmp->Height;j++)
        {
            CountProcess("",1);
            temp_bmp->Canvas->Pixels[i][j] = SmoothMatrix(bmp,i,j,AD);
        }
}

void Smooth(Graphics::TBitmap* bmp,int AD)
{
    Graphics::TBitmap* _bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDDB;
    _bmp->HandleType = bmDDB;
    _bmp->Assign(bmp);

    for (int i=0;i<_bmp->Width;i++)
        for (int j=0;j<_bmp->Height;j++)
            ::SetPixelV(bmp->Canvas->Handle,i,j,SmoothMatrix2(_bmp,i,j,AD));
    delete _bmp;
    bmp->HandleType = bmDIB;
}


void BMPResize(Graphics::TBitmap* bmp, int nWidth, int nHeight)
{
    Graphics::TBitmap* temp_bmp = new Graphics::TBitmap();
    temp_bmp->HandleType = bmDDB;

    int K;
    if (nWidth>bmp->Width)
        K = (double(nWidth)/double(bmp->Width));
    else
        K = (double(bmp->Width)/double(nWidth));

    int AD = RoundTo(K/2,0);
    if (AD == 0)
        AD = 1;
    if (nWidth > bmp->Width)
    {
        temp_bmp->Width = nWidth;
        temp_bmp->Height = nHeight;
        temp_bmp->Canvas->StretchDraw(TRect(0,0,nWidth,nHeight),bmp);
        bmp->Width = nWidth;
        bmp->Height = nHeight;
        Smooth(bmp,temp_bmp,AD);
    }
    else
    {
        temp_bmp->Width = bmp->Width;
        temp_bmp->Height = bmp->Height;
        Smooth(temp_bmp,bmp,AD);
        bmp->Width = nWidth;
        bmp->Height = nHeight;
        bmp->Canvas->StretchDraw(TRect(0,0,nWidth,nHeight),temp_bmp);
    }

    delete temp_bmp;
}

void ImageResize(Graphics::TBitmap* bmp,int nWidth,int nHeight)
{
    if (bmp->Width == nWidth &&  bmp->Height == nHeight)
        return;
    Graphics::TBitmap* _bmp = new Graphics::TBitmap();
    _bmp->HandleType = bmDIB;
    _bmp->Width = nWidth;
    _bmp->Height = nHeight;
    TRect RES;
    RectForBMP(TRect(0,0,nWidth,nHeight),bmp,RES);
    _bmp->Canvas->StretchDraw(RES,bmp);

    bmp->Assign(_bmp);
    delete _bmp;
}

void scale2x(Graphics::TBitmap* bmpFrom, Graphics::TBitmap* bmpTo)
{
    UINT* ptrFr1;
    UINT* ptrFr2;
    UINT* ptrTo;
    UINT *ptr[2];
    int r = 0;
    int g = 0;
    int b = 0;
    int rc;
    for ( int j = 0; j < bmpFrom->Height; j++ )
        if ( j % 2 == 0 ) {
            ptrTo = (UINT*) bmpTo->ScanLine[j>>1];
            ptrFr1 = (UINT*) bmpFrom->ScanLine[j];
            ptrFr2 = (UINT*) bmpFrom->ScanLine[j+1];
            ptr[0] = ptrFr1;
            ptr[1] = ptrFr2;
            for ( int i = 0; i < bmpFrom->Width; i++ )
                if ( i % 2 == 0 )
                {
                    /*
                    r = GetRValue(ptrFr1[i]) + GetRValue(ptrFr1[i+1]) + GetRValue(ptrFr2[i]) + GetRValue(ptrFr2[i+1]);
                    g = GetGValue(ptrFr1[i]) + GetGValue(ptrFr1[i+1]) + GetGValue(ptrFr2[i]) + GetGValue(ptrFr2[i+1]);
                    b = GetBValue(ptrFr1[i]) + GetBValue(ptrFr1[i+1]) + GetBValue(ptrFr2[i]) + GetBValue(ptrFr2[i+1]);
                    ptrTo[i>>1] = RGB(r>>2, g>>2, b>>2);
                    */
                    r = 0;
                    rc = 0;
                    for (int l=0;l<2;l++)
                        for (int m=0;m<2;m++)
                            if ( GetRValue(ptr[l][i+m])!=0 )
                            {
                                r+=GetRValue(ptr[l][i+m]);
                                rc++;
                            }
                    if (rc!=0)
                        r = r/rc;

                    g = 0;
                    rc = 0;
                    for (int l=0;l<2;l++)
                        for (int m=0;m<2;m++)
                            if ( GetGValue(ptr[l][i+m])!=0 )
                            {
                                g+=GetGValue(ptr[l][i+m]);
                                rc++;
                            }
                    if (rc!=0)
                        g = g/rc;

                    b = 0;
                    rc = 0;
                    for (int l=0;l<2;l++)
                        for (int m=0;m<2;m++)
                            if ( GetBValue(ptr[l][i+m])!=0 )
                            {
                                b+=GetBValue(ptr[l][i+m]);
                                rc++;
                            }
                    if (rc!=0)
                        b = b/rc;
                    ptrTo[i>>1] = RGB(r, g, b);
                }
        }
}

