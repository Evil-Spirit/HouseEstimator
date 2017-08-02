//---------------------------------------------------------------------------


#pragma hdrstop

#include "VectorV.h"
#include "math.h"
#include "MathV.h"

//---------------------------------------------------------------------------


#pragma package(smart_init)


//TIntVec

void TIntVec::SetX(MBTi ax)
{
    fx = ax;
}

void TIntVec::SetY(MBTi ay)
{
    fy = ay;
}

void TIntVec::SetZ(MBTi az)
{
    fz = az;
}

void TIntVec::SetA(int i,MBTi aa)
{
    fa[i] = aa;
}

MBTi TIntVec::GetA(int i) const
{
    return fa[i];
}

TIntVec::TIntVec()
{
    fx = 0;
    fy = 0;
    fz = 0;
    MyObjectParent = NULL;
}
/*
TIntVec::TIntVec(const TBoolVec &rhs)
{
    fx=(MBTi)rhs.x;
    fy=(MBTi)rhs.y;
    fz=(MBTi)rhs.z;
    MyObjectParent = NULL;
}

*/
TIntVec::TIntVec(const TVisVector &rhs)
{
    fx=(MBTi)rhs.X;
    fy=(MBTi)rhs.Y;
    fz=(MBTi)rhs.Z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(MBTi _x,MBTi _y,MBTi _z)
{
    fx=_x;
    fy=_y;
    fz=_z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(const TVisMathVector &rhs)
{
    fx=(MBTi)rhs.x;
    fy=(MBTi)rhs.y;
    fz=(MBTi)rhs.z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(const TIntVec& rhs  )
{
    fx=rhs.fx;
    fy=rhs.fy;
    fz=rhs.fz;
    MyObjectParent = NULL;
}

TIntVec & TIntVec::operator = (const TIntVec &rhs)
{
    fx=rhs.x;
    fy=rhs.y;
    fz=rhs.z;
    return *this;
}


TIntVec & TIntVec::operator =(const TVisMathVector &rhs)
{
    fx=rhs.x;
    fy=rhs.y;
    fz=rhs.z;
    return *this;
}

TIntVec & TIntVec::operator = (const TVisVector &rhs)
{
    fx=rhs.X;
	fy=rhs.Y;
    fz=rhs.Z;
    return *this;
}

bool  TIntVec::operator == (const TIntVec &rhs) const
{
    return (fx==rhs.fx && fy==rhs.fy && fz==rhs.fz);
}

bool  TIntVec::operator != (const TIntVec &rhs) const
{
    return !( this->operator ==(rhs) );
}

bool TIntVec::operator <= (const TIntVec &rhs) const
{
    return (fx<=rhs.fx && fy<=rhs.fy && fz<=rhs.fz);
}

bool TIntVec::operator >= (const TIntVec &rhs) const
{
    return (fx>=rhs.fx && fy>=rhs.fy && fz>=rhs.fz);
}

TIntVec TIntVec::operator +(const TIntVec &rhs) const
{
	return( TIntVec(fx+rhs.fx,fy+rhs.fy,fz+rhs.fz) );
}

TIntVec TIntVec::operator -(const TIntVec &rhs) const
{
    return( TIntVec(fx-rhs.fx,fy-rhs.fy,fz-rhs.fz) );
}

TIntVec TIntVec::XYZ_Multiply(const TIntVec &rhs) const
{
    return( TIntVec(fx*rhs.fx,fy*rhs.fy,fz*rhs.fz) );
}

TIntVec TIntVec::XYZ_Divide(const TIntVec &rhs) const
{
    return( TIntVec(fx/rhs.fx,fy/rhs.fy,fz/rhs.fz) );
}

TIntVec TIntVec::operator *(const TIntVec &rhs) const
{
    return TIntVec(fy*rhs.fz - fz*rhs.fy,fz*rhs.fx - fx*rhs.fz,fx*rhs.fy - fy*rhs.fx);
}

MBTi TIntVec::operator &(const TIntVec &rhs) const
{
    return fx*rhs.fx+fy*rhs.fy+fz*rhs.fz;
}

TIntVec TIntVec::operator ^(const TIntVec &rhs) const
{
    return TIntVec(fx*rhs.fx,fy*rhs.fy,fz*rhs.fz);
}

TIntVec TIntVec::operator /(const TIntVec &rhs) const
{
    return TIntVec(fx/rhs.fx,fy/rhs.fy,fz/rhs.fz);
}

TIntVec& TIntVec::operator +=(const TIntVec &rhs)
{
    fx+=rhs.fx;
    fy+=rhs.fy;
    fz+=rhs.fz;
    return *this;
}

TIntVec& TIntVec::operator -=(const TIntVec &rhs)
{
    fx-=rhs.fx;
    fy-=rhs.fy;
    fz-=rhs.fz;
    return *this;
}

TIntVec& TIntVec::operator *=(const TIntVec &rhs)
{
    *this = TIntVec(fy*rhs.fz - fz*rhs.fy,fz*rhs.fx - fx*rhs.fz,fx*rhs.fy - fy*rhs.fx);
    return *this;
}

TIntVec& TIntVec::operator ^=(const TIntVec &rhs)
{
    fx*=rhs.fx;
    fy*=rhs.fy;
    fz*=rhs.fz;
    return *this;
}

TIntVec& TIntVec::operator /=(const TIntVec &rhs)
{
    fx/=rhs.fx;
    fy/=rhs.fy;
    fz/=rhs.fz;
    return *this;
}

TIntVec& TIntVec::operator /=(MBTi rhs)
{
    fx/=rhs;
    fy/=rhs;
    fz/=rhs;
	return *this;
}

TIntVec TIntVec::operator /(MBTi rhs) const
{
    return( TIntVec(fx/rhs,fy/rhs,fz/rhs) );
}

MBTi TIntVec::Length() const
{
	return sqrtDC((fx*fx)+(fy*fy)+(fz*fz));
}

TIntVec TIntVec::operator *(MBTi rhs) const
{
    return( TIntVec(fx*rhs,fy*rhs,fz*rhs) );
}

TIntVec& TIntVec::operator *=(MBTi rhs)
{
    fx*=rhs;
    fy*=rhs;
    fz*=rhs;
    return *this;
}

MBTi CycleOf(MBTi Angle,MBTi Cycle)
{
	while (Angle>=Cycle)
		Angle -= Cycle;
	return Angle;
}

TIntVec TIntVec::operator %(MBTi Cycle) const
{
	TIntVec Res;
	Res.fx = CycleOf( fx, Cycle);
    Res.fy = CycleOf( fy, Cycle);
    Res.fz = CycleOf( fz, Cycle);
    return(Res);
}

int TIntVec::intX() const
{
    return (int)RoundTo(fx,0);
}

int TIntVec::intY() const
{
    return (int)RoundTo(fy,0);
}

int TIntVec::intZ() const
{
    return (int)RoundTo(fz,0);
}

int TIntVec::intA(int index) const
{
    return (int)RoundTo(fa[index % 3],0);
}

TIntVec& TIntVec::Assign(const TIntVec& Vec)
{
    fx = Vec.fx;
    fy = Vec.fy;
    fz = Vec.fz;
    return *this;
}

bool TIntVec::Equal2D(const TIntVec& P,MBTi USEEPS) const
{
    if ( (fabs(fx-P.fx) <= USEEPS) &&  (fabs(fy-P.fy) <= USEEPS))
        return ((fx-P.fx)*(fx-P.fx)+(fy-P.fy)*(fy-P.fy))<=USEEPS*USEEPS;
    else
        return false;
}

MBTi TIntVec::Length2D() const
{
    return sqrtDC(fx*fx + fy*fy);
}

TIntVec TIntVec::Perpendicular2D() const
{
	//соответствует TIntVec(x,y,0)*TIntVec(0,0,1);
    return TIntVec(y,-x,0);
}

bool TIntVec::Equal(const TIntVec& P,MBTi USEEPS) const
{
    if ( ((fabs(fx-P.fx) <= USEEPS) &&  (fabs(fy-P.fy) <= USEEPS) && (fabs(fz-P.fz) <= USEEPS)) )
		return ScalarP( (*this - P),(*this - P) ) <= USEEPS*USEEPS;
    else
        return false;
}

TIntVec TIntVec::Normalize() const
{
    MBTi _Length = Length();
    TIntVec Res = *(this);
    if (_Length>0.00001)
        return Res/_Length;
    else
        return Res;
}

TIntVec::operator TVisMathVector() const
{
    return ToVec(x,y,z);
}

TIntVec VectorP(const TIntVec& a,const TIntVec& b)
{
	TIntVec VC;
	
	for (int i=0;i<3;i++)
		VC.a[i] = a.a[(i+1)%3]*b.a[(i+2)%3] - b.a[(i+1)%3]*a.a[(i+2)%3];
		
	return VC;
}

TIntVec VectorP2d(const TIntVec &src)
{
	return VectorP(src, TIntVec(0, 0, 1));
}

MBTi ScalarP(const TIntVec& a,const TIntVec& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

