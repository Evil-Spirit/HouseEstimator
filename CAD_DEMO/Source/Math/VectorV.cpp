// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------



#include "VectorV.h"
#include "math.h"
#include "MathV.h"

//---------------------------------------------------------------------------




//TIntVec

void TIntVec::SetX(MBTi ax)
{
    x = ax;
}

void TIntVec::SetY(MBTi ay)
{
    y = ay;
}

void TIntVec::SetZ(MBTi az)
{
    z = az;
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
    x = 0;
    y = 0;
    z = 0;
    MyObjectParent = NULL;
}
/*
TIntVec::TIntVec(const TBoolVec &rhs)
{
    x=(MBTi)rhs.x;
    y=(MBTi)rhs.y;
    z=(MBTi)rhs.z;
    MyObjectParent = NULL;
}

*/
TIntVec::TIntVec(const TVisVector &rhs)
{
    x=(MBTi)rhs.X;
    y=(MBTi)rhs.Y;
    z=(MBTi)rhs.Z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(MBTi _x,MBTi _y,MBTi _z)
{
    x=_x;
    y=_y;
    z=_z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(const TVisMathVector &rhs)
{
    x=(MBTi)rhs.x;
    y=(MBTi)rhs.y;
    z=(MBTi)rhs.z;
    MyObjectParent = NULL;
}

TIntVec::TIntVec(const TIntVec& rhs  )
{
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
    MyObjectParent = NULL;
}

TIntVec & TIntVec::operator = (const TIntVec &rhs)
{
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
    return *this;
}


TIntVec & TIntVec::operator =(const TVisMathVector &rhs)
{
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
    return *this;
}

TIntVec & TIntVec::operator = (const TVisVector &rhs)
{
    x=rhs.X;
	y=rhs.Y;
    z=rhs.Z;
    return *this;
}

bool  TIntVec::operator == (const TIntVec &rhs) const
{
    return (x==rhs.x && y==rhs.y && z==rhs.z);
}

bool  TIntVec::operator != (const TIntVec &rhs) const
{
    return !( this->operator ==(rhs) );
}

bool TIntVec::operator <= (const TIntVec &rhs) const
{
    return (x<=rhs.x && y<=rhs.y && z<=rhs.z);
}

bool TIntVec::operator >= (const TIntVec &rhs) const
{
    return (x>=rhs.x && y>=rhs.y && z>=rhs.z);
}

TIntVec TIntVec::operator +(const TIntVec &rhs) const
{
	return( TIntVec(x+rhs.x,y+rhs.y,z+rhs.z) );
}

TIntVec TIntVec::operator -(const TIntVec &rhs) const
{
    return( TIntVec(x-rhs.x,y-rhs.y,z-rhs.z) );
}

TIntVec TIntVec::XYZ_Multiply(const TIntVec &rhs) const
{
    return( TIntVec(x*rhs.x,y*rhs.y,z*rhs.z) );
}

TIntVec TIntVec::XYZ_Divide(const TIntVec &rhs) const
{
    return( TIntVec(x/rhs.x,y/rhs.y,z/rhs.z) );
}

TIntVec TIntVec::operator *(const TIntVec &rhs) const
{
    return TIntVec(y*rhs.z - z*rhs.y,z*rhs.x - x*rhs.z,x*rhs.y - y*rhs.x);
}

MBTi TIntVec::operator &(const TIntVec &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}

TIntVec TIntVec::operator ^(const TIntVec &rhs) const
{
    return TIntVec(x*rhs.x,y*rhs.y,z*rhs.z);
}

TIntVec TIntVec::operator /(const TIntVec &rhs) const
{
    return TIntVec(x/rhs.x,y/rhs.y,z/rhs.z);
}

TIntVec& TIntVec::operator +=(const TIntVec &rhs)
{
    x+=rhs.x;
    y+=rhs.y;
    z+=rhs.z;
    return *this;
}

TIntVec& TIntVec::operator -=(const TIntVec &rhs)
{
    x-=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
    return *this;
}

TIntVec& TIntVec::operator *=(const TIntVec &rhs)
{
    *this = TIntVec(y*rhs.z - z*rhs.y,z*rhs.x - x*rhs.z,x*rhs.y - y*rhs.x);
    return *this;
}

TIntVec& TIntVec::operator ^=(const TIntVec &rhs)
{
    x*=rhs.x;
    y*=rhs.y;
    z*=rhs.z;
    return *this;
}

TIntVec& TIntVec::operator /=(const TIntVec &rhs)
{
    x/=rhs.x;
    y/=rhs.y;
    z/=rhs.z;
    return *this;
}

TIntVec& TIntVec::operator /=(MBTi rhs)
{
    x/=rhs;
    y/=rhs;
    z/=rhs;
	return *this;
}

TIntVec TIntVec::operator /(MBTi rhs) const
{
    return( TIntVec(x/rhs,y/rhs,z/rhs) );
}

MBTi TIntVec::Length() const
{
	return sqrtDC((x*x)+(y*y)+(z*z));
}

TIntVec TIntVec::operator *(MBTi rhs) const
{
    return( TIntVec(x*rhs,y*rhs,z*rhs) );
}

TIntVec& TIntVec::operator *=(MBTi rhs)
{
    x*=rhs;
    y*=rhs;
    z*=rhs;
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
	Res.x = CycleOf( x, Cycle);
    Res.y = CycleOf( y, Cycle);
    Res.z = CycleOf( z, Cycle);
    return(Res);
}

int TIntVec::intX() const
{
    return (int)RoundTo(x,0);
}

int TIntVec::intY() const
{
    return (int)RoundTo(y,0);
}

int TIntVec::intZ() const
{
    return (int)RoundTo(z,0);
}

int TIntVec::intA(int index) const
{
    return (int)RoundTo(fa[index % 3],0);
}

TIntVec& TIntVec::Assign(const TIntVec& Vec)
{
    x = Vec.x;
    y = Vec.y;
    z = Vec.z;
    return *this;
}

bool TIntVec::Equal2D(const TIntVec& P,MBTi USEEPS) const
{
    if ( (fabs(x-P.x) <= USEEPS) &&  (fabs(y-P.y) <= USEEPS))
        return ((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y))<=USEEPS*USEEPS;
    else
        return false;
}

MBTi TIntVec::Length2D() const
{
    return sqrtDC(x*x + y*y);
}

TIntVec TIntVec::Perpendicular2D() const
{
	//ñîîòâåòñòâóåò TIntVec(x,y,0)*TIntVec(0,0,1);
    return TIntVec(y,-x,0);
}

bool TIntVec::Equal(const TIntVec& P,MBTi USEEPS) const
{
    if ( ((fabs(x-P.x) <= USEEPS) &&  (fabs(y-P.y) <= USEEPS) && (fabs(z-P.z) <= USEEPS)) )
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
		VC[i] = a[(i+1)%3]*b[(i+2)%3] - b[(i+1)%3]*a[(i+2)%3];
		
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

