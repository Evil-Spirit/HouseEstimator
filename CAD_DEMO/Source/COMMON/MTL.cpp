 //---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "math.h"
#include "Math.hpp"
#include "math.h"
#include "stdlib.h"

#pragma package(smart_init)

TIntVec tmpIntVec;
int tmpint;
AnsiString tmpAnsiString;
double tmpdouble;
float tmpfloat;
bool tmpbool;
int tmpsign;
TBoolVec tmpBoolVec;
TMBTRect tmpRect;


bool ISINTEGER(const AnsiString &Src)
{
    try
    {
        Src.ToInt();
        return(true);
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        return(false);
    }

}

bool __fastcall TINTCOMP(void *item1, void *item2)
{
    return (*((int*)item1)) < (*((int*)item2));
}

TIntVec ABSINTVEC(const TIntVec & A)
{
    return( TIntVec( fabs(A.x), fabs(A.y), fabs(A.z) ) );
}

bool IS_FLOAT(const AnsiString& FloatStr)
{
    AnsiString NEW_FLOAT_STR = FloatStr;
    if (AnsiString(",") == AnsiString(DecimalSeparator))
        ReplaceSymbol(NEW_FLOAT_STR,'.',DecimalSeparator);
    else
        ReplaceSymbol(NEW_FLOAT_STR,',',DecimalSeparator);
    try
    {
        NEW_FLOAT_STR.ToDouble();
        return(true);
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        return(false);
    }
}

AnsiString FLOATTOSTR(Extended Value)
{
    AnsiString NEW_FLOAT_STR = FloatToStr(Value);
    ReplaceSymbol(NEW_FLOAT_STR,DecimalSeparator,'.');
    return NEW_FLOAT_STR;
}

double TO_DOUBLE(const AnsiString& FloatStr)
{
    AnsiString NEW_FLOAT_STR = FloatStr;
    if (AnsiString(",") == AnsiString(DecimalSeparator))
        ReplaceSymbol(NEW_FLOAT_STR,'.',DecimalSeparator);
    else
        ReplaceSymbol(NEW_FLOAT_STR,',',DecimalSeparator);
    return NEW_FLOAT_STR.ToDouble();
}

bool CHECKTYPE(const AnsiString& Src, int MT)
{
    switch (MT)
    {
        case mtInt:
            return(ISINTEGER(Src));
        case mtDouble:
            return(IS_FLOAT(Src));
        case mtFloat:
            return(IS_FLOAT(Src));
        case mtString:
            return(true);
        case mtIntVec:
            return(CHECKSTRVEC(Src,false));
        case mtBoolVec:
            return(CHECKSTRVEC(Src,false));
        case mtSignVec:
            return(CHECKSTRVEC(Src,true));
        case mtBool:
            return(ISINTEGER(Src));
        }
        return(false);
}

AnsiString VecToStrA(const TIntVec& Vec)
{
    return("X: "+FLOATTOSTR(Vec.x)+" "+"Y: "+FLOATTOSTR(Vec.y)+" "+"Z: "+FLOATTOSTR(Vec.z));
}

AnsiString VecToStrFormat(const TIntVec& Vec)
{
    return Format("X: %.4f Y: %.4f Z: %.4f", ARRAYOFCONST( (Vec.x,Vec.y,Vec.z) ) );
}

AnsiString ToRectStr(const TMBTRect& Rect)
{
    return (MBTiToStr(Rect.left)+" "+MBTiToStr(Rect.top)+" "+MBTiToStr(Rect.right)+" "+MBTiToStr(Rect.bottom));
}

TMBTRect RectFromStr(const AnsiString& RectStr)
{
    TStringList *B=new TStringList();
    TMBTRect Res;
    B->Delimiter=' ';
    B->DelimitedText=RectStr;
    Res.left = StrToMBTi(B->Strings[0]);
    Res.top = StrToMBTi(B->Strings[1]);
    Res.right = StrToMBTi(B->Strings[2]);
    Res.bottom = StrToMBTi(B->Strings[3]);
    delete B;
    return Res;
}


MBTi StrToMBTi(const AnsiString& Str)
{
    MBTi mbti;
    CopyType(mtMBTi,&mbti,STRTOTYPE(Str,mtMBTi));
    return mbti;
}

AnsiString MBTiToStr(MBTi mbti)
{
    return TYPETOSTR(&mbti,mtMBTi);
}

TIntVec IntVecFromStr(const AnsiString& VecStr)
{
    TStringList *B=new TStringList();
    B->Delimiter=' ';
    B->DelimitedText=VecStr;
    TIntVec res;
    for (int i=0;i<3;i++)
        res.a[i]=StrToMBTi(B->Strings[2*i+1]);
    delete B;
    return(res);
}

AnsiString ToBoolVecStr(const TBoolVec& Vec)
{
    return( VecToStrA( TIntVec(Vec.x,Vec.y,Vec.z) ) );
}

TBoolVec BoolVecFromStr(const AnsiString& VecStr)
{
    TIntVec A = IntVecFromStr(VecStr);
    return(TBoolVec((bool)A.x,(bool)A.y,(bool)A.z));
}

bool CHECKSTRVEC(const AnsiString& VecStr,bool IsDouble)
{
    TStringList *B=new TStringList();
    B->Delimiter=' ';
    B->DelimitedText=VecStr;
    if (B->Count<6)
        return(false);
    for (int i=0;i<3;i++)
        if (IsDouble)
        {
            if (!IS_FLOAT(B->Strings[2*i+1]))
            {
                delete B;
                return(false);
            }
        }
        else
        {
            if (!CHECKTYPE(B->Strings[2*i+1],mtMBTi))
            {
                delete B;
                return(false);
            }
        }
    delete B;
    return(true);
}

AnsiString TYPETOSTR(const void *Address,int MT)
{
    switch (MT)
    {
        case mtInt:
        {
            int *Src = (int *)Address;
            return(IntToStr(*Src));
        }
        case mtDouble:
        {
            double *Src = (double*)Address;
            return(FLOATTOSTR(*Src));
        }
        case mtFloat:
        {
			float *Src = (float*)Address;
            return(FLOATTOSTR(*Src));
        }
        case mtString:
        {
            AnsiString *Src = (AnsiString*)Address;
            return(*Src);
        }
        case mtIntVec:
        {
            TIntVec *Src = (TIntVec*)Address;
            return(VecToStrA(*Src));
        }
        case mtBool:
        {
            bool *Src = (bool*)Address;
            if (*Src==true)
                return(StrTrue);
            else
                return(StrFalse);
        }
        case mtBoolVec:
        {
            TBoolVec *Src = (TBoolVec*)Address;
            return(ToBoolVecStr(*Src));
        }
        case mtSignVec:
        {
            TIntVec *Src = (TIntVec*)Address;
            return(VecToStrA(*Src));
        }
        case mtRect:
        {
            TMBTRect *Src = (TMBTRect*)Address;
            return(ToRectStr(*Src));
        }
    }
    return(AnsiString());
}

void *STRTOTYPE(const AnsiString& Src,int MT)
{
    switch (MT)
    {
        case mtInt:
        {
            tmpint=Src.ToInt();
            return(&tmpint);
        }
        case mtDouble:
        {
            tmpdouble=TO_DOUBLE(Src);
            return(&tmpdouble);
        }
        case mtFloat:
        {tmpfloat=TO_DOUBLE(Src);
            return(&tmpfloat);
        }
        case mtString:
        {
            tmpAnsiString =Src;
            return(&tmpAnsiString);
        }
        case mtIntVec:
        {
            tmpIntVec = IntVecFromStr(Src);
            return(&tmpIntVec);
        }
        case mtBool:
        {
            if (Src==StrTrue)
                tmpbool = true;
            else
                tmpbool = false;
            return(&tmpbool);
        }
        case mtSignVec:
        {
            tmpIntVec =IntVecFromStr(Src);
            return(&tmpIntVec);
        }
        case mtBoolVec:
        {
            tmpBoolVec =BoolVecFromStr(Src);
            return(&tmpBoolVec);
        }
        case mtRect:
        {
            tmpRect = RectFromStr(Src);
            return(&tmpRect);
        }
    }
    return(NULL);
}



bool TypeCompare(void *Data1, void *Data2, int MT)
{
    switch (MT)
    {
        case mtInt:
        {
            int *Src1 = (int *)Data1;
            int *Src2 = (int *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtDouble:
        {
            double *Src1 = (double *)Data1;
            double *Src2 = (double *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtFloat:
        {
            float *Src1 = (float *)Data1;
            float *Src2 = (float *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtString:
        {
            AnsiString *Src1 = (AnsiString *)Data1;
            AnsiString *Src2 = (AnsiString *)Data2;
            return((*Src1).Trim().LowerCase()==(*Src2).Trim().LowerCase());
        }
        case mtIntVec:
        {
            TIntVec *Src1 = (TIntVec *)Data1;
            TIntVec *Src2 = (TIntVec *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtBool:
        {
            bool *Src1 = (bool *)Data1;
            bool *Src2 = (bool *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtBoolVec:
        {
            TBoolVec *Src1 = (TBoolVec *)Data1;
            TBoolVec *Src2 = (TBoolVec *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtSignVec:
        {
            TIntVec *Src1 = (TIntVec *)Data1;
            TIntVec *Src2 = (TIntVec *)Data2;
            return((*Src1)==(*Src2));
        }
        case mtRect:
        {
            TMBTRect *Src1 = (TMBTRect *)Data1;
            TMBTRect *Src2 = (TMBTRect *)Data2;
            return( (*Src1) == (*Src2) );
        }
    }
    return(false);
}

void* CreateType(int mt)
{
    switch (mt)
    {
        case mtInt:
            return new int();
        case mtDouble:
            return new double();
        case mtFloat:
            return new float();
        case mtString:
            return new AnsiString();
        case mtIntVec:
            return new TIntVec();
        case mtBool:
            return new bool();
        case mtBoolVec:
            return new TBoolVec();
        case mtSignVec:
            return new TIntVec();
        case mtRect:
            return new TMBTRect();
    }
    throw EMyException("CreateType: Type is not recognized.");
}

void CopyType(int mt,void *Addr,void *Value )
{
    switch (mt)
    {
        case mtInt:
        {
            int *Src = (int*)Addr;
            int *Dest = (int *)Value;
            *Src = *Dest;
        }
        break;
        case mtDouble:
        {
            double *Src = (double*)Addr;
            double *Dest = (double *)Value;
            *Src = *Dest;
        }
        break;
        case mtFloat:
        {
            float *Src = (float*)Addr;
            float *Dest = (float *)Value;
            *Src = *Dest;
        }
        break;
        case mtString:
        {
            AnsiString *Src = (AnsiString*)Addr;
            AnsiString *Dest = (AnsiString *)Value;
            *Src = *Dest;
        }
        break;
        case mtIntVec:
        {
            TIntVec *Src = (TIntVec*)Addr;
            TIntVec *Dest = (TIntVec *)Value;
            *Src = *Dest;
        }
        break;
        case mtBool:
        {
            bool *Src = (bool*)Addr;
            bool *Dest = (bool *)Value;
            *Src = *Dest;
        }
        break;
        case mtBoolVec:
        {
            TBoolVec *Src = (TBoolVec*)Addr;
            TBoolVec *Dest = (TBoolVec *)Value;
            *Src = *Dest;
        }
        break;
        case mtSignVec:
        {
            TIntVec *Src = (TIntVec*)Addr;
            TIntVec *Dest = (TIntVec *)Value;
            *Src = *Dest;
        }
        break;
        case mtRect:
        {
            TMBTRect *Src = (TMBTRect*)Addr;
            TMBTRect *Dest = (TMBTRect *)Value;
            *Src = *Dest;
        }
        break;
    }
}

//---------------------------------------------------------------------------
TChangeVec::TChangeVec(const TVisVector &rhs)
    :TIntVec(rhs)
{
}

TChangeVec::TChangeVec(const TIntVec& rhs  )
    :TIntVec(rhs)
{
}

/*TChangeVec::TChangeVec(const TBoolVec& rhs  )
    :TIntVec(rhs)
{
} */

TChangeVec::TChangeVec(MBTi x,MBTi y,MBTi z)
    :TIntVec(x,y,z)
{
}

TChangeVec::TChangeVec(const TVisMathVector &rhs)
    :TIntVec(rhs)
{
}


void TChangeVec::AboutToChange(void* Field)
{
    if (MyObjectParent)
        MyObjectParent->AboutToChange(Field);
}

void TChangeVec::Changed(void* Field)
{
    if ( MyObjectParent )
        MyObjectParent->Changed(Field);
}

void TChangeVec::SetX(MBTi ax)
{
    AboutToChange(this);
    TIntVec::SetX(ax);
    Changed(this);
}

void TChangeVec::SetY(MBTi ay)
{
    AboutToChange(this);
    TIntVec::SetY(ay);
    Changed(this);
}

void TChangeVec::SetZ(MBTi az)
{
    AboutToChange(this);
    TIntVec::SetZ(az);
    Changed(this);
}

void TChangeVec::SetA(int i,MBTi aa)
{
    AboutToChange(this);
    TIntVec::SetA(i, aa);
    Changed(this);
}

TChangeVec & TChangeVec::operator = (const TVisMathVector &rhs)
{
    AboutToChange(this);
    TIntVec::operator = (rhs);
    Changed(this);
    return *this;
}

TChangeVec & TChangeVec::operator = (const TVisVector &rhs)
{
    AboutToChange(this);
    TIntVec::operator = (rhs);
    Changed(this);
    return *this;
}

TChangeVec & TChangeVec::operator = (const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator = (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator +=(const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator += (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator -=(const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator -= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator *=(const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator *= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator /=(const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator /= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator ^=(const TIntVec &rhs)
{
    AboutToChange(this);
    TIntVec::operator ^= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator /=(MBTi rhs)
{
    AboutToChange(this);
    TIntVec::operator /= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::operator *=(MBTi rhs)
{
    AboutToChange(this);
    TIntVec::operator *= (rhs);
    Changed(this);
    return *this;
}

TChangeVec& TChangeVec::Assign(const TIntVec& Vec)
{
    AboutToChange(this);
    TIntVec::Assign(Vec);
    Changed(this);
    return *this;
}

//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
TBoolVec::TBoolVec(bool _x,bool _y,bool _z)
{
    x=_x;
    y=_y;
    z=_z;
}

TBoolVec & TBoolVec::operator = (const TBoolVec &rhs)
{
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
    return *this;
}

bool  TBoolVec::operator == (const TBoolVec &rhs)
{
    if (x!=rhs.x)
        return (false);
    if (y!=rhs.y)
        return(false);
    if (z!=rhs.z)
        return(false);
    return true;
}

bool  TBoolVec::operator != (const TBoolVec &rhs)
{
    if (x==rhs.x&&y==rhs.y&&z==rhs.z)
        return(false);
    return true;
}

TBoolVec TBoolVec::operator *(const TBoolVec &rhs)
{
    TBoolVec Res;
    Res.x=x*rhs.x;
    Res.y=y*rhs.y;
    Res.z=z*rhs.z;
    return(Res);
}

MBTi AngleOf(const TMPoint& _P1,const TMPoint& _P2)
{
    if (CompareTMPoint(_P1,_P2))
      return 0;
    if (_P1.y==_P2.y)
        return(180*(_P2.x<_P1.x));
    if (_P1.x == _P2.x)
        return(90*(_P1.y<_P2.y)+270*(_P1.y>_P2.y));
    TMPoint P1,P2;
    if (_P2.y<_P1.y)
    {
        P2 = _P1;
        P1 = _P2;
    }
    else
    {
            P2 = (_P2);
            P1 = (_P1);
    }

	double angle = acosDC((P2.x-P1.x)/sqrtDC( (P2.x-P1.x)*(P2.x-P1.x)+(P2.y-P1.y)*(P2.y-P1.y) ));
    angle = (angle*180)/M_PI ;
    if (CompareTMPoint(P2,_P1))
    {
        angle = 180 + angle;
    }
    return( (MBTi) angle );
}

TMPoint::TMPoint()
{
    x = 0;
    y = 0;
}

TMPoint::TMPoint(MBTi _x,MBTi _y)
{
    x = _x;
    y = _y;
}

bool TMPoint::operator == (const TMPoint& P) const
{
    return(x==P.x&&y==P.y);
}

TMPoint& TMPoint::operator = (const TMPoint& P)
{
    x = P.x;
    y = P.y;
    return *this;
}

bool CompareTMPoint(const TMPoint& P1,const TMPoint& P2)
{
    return( (P1.x==P2.x&&P1.y==P2.y) );
}

bool CompareTMPointWithEPS(const TMPoint& P1,const TMPoint& P2,MBTi CompareEPS)
{
    return ( fabs(P1.x-P2.x)<=CompareEPS && fabs(P1.y-P2.y)<=CompareEPS ) ;
}


T3DScope::T3DScope(const TIntVec & VecLow,const TIntVec & VecHi)
{
    if (VecLow<=VecHi)
    {
        LOW = VecLow;
        HI = VecHi;
        return;
    }
    if (VecLow>=VecHi)
    {
        HI = VecLow;
        LOW = VecHi;
        return;
    }
    Application->MessageBoxA("Assigned LOW and HI are wrong","Error",MB_OK);
}

bool T3DScope::CheckFields()
{
    for (int i=0;i<3;i++)
        if (LOW.a[i]>HI.a[i])
            return(false);
    return(true);
}

bool T3DScope::Valid(const TIntVec & Vec)
{
    for (int i=0;i<3;i++)
    {
        if (LOW.a[i]>Vec.a[i])
            return(false);
        if (Vec.a[i]>HI.a[i])
            return(false);
    }
    return(true);
}

bool T3DScope::Crossed(T3DScope* OS)
{
    if ( (LOW<=OS->HI)&&(LOW>=OS->LOW) )
        return(true);
    if ( (OS->LOW<=HI)&&(OS->LOW>=LOW) )
        return(true);
    return(false);
}

void T3DScope::Move(const TIntVec &Trans)
{
    for (int i=0;i<3;i++)
    {
        LOW.a[i]+=Trans.a[i];
        HI.a[i]+=Trans.a[i];
    }
}

void T3DScope::Scale(const TIntVec &Scale)
{
    for (int i=0;i<3;i++)
    {
        LOW.a[i]*=fabs(Scale.a[i]);
        HI.a[i]*=fabs(Scale.a[i]);
    }
}

void T3DScope::CrossedWithStep(const T3DScope& OS,TIntVec &Step)
{
    Step = ZEROINTVEC;
    if ( (LOW<=OS.HI)&&(LOW>=OS.LOW) )
        return;
    if ( (OS.LOW<=HI)&&(OS.LOW>=LOW) )
        return;

    for (int i=0;i<3;i++)
    {
        if (LOW.a[i]>OS.HI.a[i])
            Step.a[i] = OS.HI.a[i]-LOW.a[i];
        if (HI.a[i]<OS.LOW.a[i])
            Step.a[i] = OS.LOW.a[i]-HI.a[i];
    }
}

TIntVec __Point;

bool T3DScope::PointAbout(const TIntVec& pPoint,TIntVec &Step,const TIntVec& DiscrStep)
{
    __Point = pPoint;
    Step = ZEROINTVEC;
    if ( (LOW<=__Point)&&(HI>=__Point) )
    {
        Discrete(__Point,DiscrStep);
        Step = __Point-pPoint;
        return true;
    }
    else if (!CheckFields())
        return false;
    for (int i=0;i<3;i++)
        if (__Point.a[i]<LOW.a[i]||__Point.a[i]>HI.a[i])
        {
            if(fabs(__Point.a[i]-LOW.a[i])<fabs(__Point.a[i]-HI.a[i]))
                Step.a[i] = LOW.a[i]-__Point.a[i];
            else
                Step.a[i] = HI.a[i]-__Point.a[i];
        }
    __Point = __Point+Step;
    Discrete(__Point,DiscrStep);
    Step = __Point - pPoint;
    return true;
}

void _Discrete(const TIntVec& LOW, const TIntVec& Step,TIntVec& Point)
{
    for (int i=0;i<3;i++)
        if (Step.a[i]!=0)
            Point.a[i] = RoundTo((Point.a[i]-LOW.a[i])/Step.a[i],0)*Step.a[i]+LOW.a[i];
}


void T3DScope::Discrete(TIntVec& Point,const TIntVec& Step)
{
    _Discrete(LOW, Step, Point);
}

T3DAngleScope::T3DAngleScope(   const T3DScope &SC,
                                const TIntVec &_Angle,
                                const TIntVec &_Center)
                            :T3DScope(SC.LOW,SC.HI)
{
    for (int i=0;i<3;i++)
        if (Angle.a[i]>360||Angle.a[i]<0)
        {
            Application->MessageBoxA(MSG_ERR_6.c_str(),"Error",MB_OK);
            {Application->Terminate(); return;}
        }
    Angle = _Angle;
    Center = _Center;
}

bool T3DAngleScope::CheckFields()
{
    for (int i=0;i<3;i++)
        if (Angle.a[i]>360 || Angle.a[i]<0)
            return(false);
    return(T3DScope::CheckFields());
}

void CrossedWithStep2D(const T3DAngleScope& OS,int ind1,int ind2,int Step)
{

}



MBTi Measure(const TIntVec& IV)
{
    return fabs(IV.x)+fabs(IV.y)+fabs(IV.z);
}


int PlaneAndLineCrossed(const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //точка пересечения
						MBTi USEEPS)    //мера параллельности
{
	TIntVec V = A - X;
	// расстояние до плоскости по нормали
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// приближение к плоскости по нормали при прохождении отрезка
	MBTi e = ScalarP ( N, W );

	if( fabs(e)>USEEPS )
	{
		MBTi k = d/e;
		O = X + W * k;
		if ( (xFixed && !( k>=-USEEPS)) || (yFixed && !(k<= 1+USEEPS)) ) 
			return PL_CROSS_OUTOFBORDER;
		else
			return PL_CROSS_ONEPOINT;
	}
	else if( fabs(d)<=USEEPS)
	{
		O = X;
		return PL_CROSS_CONSISTS;
	}
	else
		return PL_CROSS_PARALLEL;               
}
