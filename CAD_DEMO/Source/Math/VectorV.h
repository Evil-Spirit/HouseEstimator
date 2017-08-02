//---------------------------------------------------------------------------

#ifndef VectorVH
#define VectorVH

#include "VisClass.hpp"
#include "VisMath.hpp"

//---------------------------------------------------------------------------

#define COMMONAL_API __declspec(package)

typedef float MBTi;
typedef double MBTf;



class TMyObject;

struct COMMONAL_API TInt3d
{
	union
	{
		struct
		{
			MBTi fa[3];

		};
		struct
		{
			MBTi fx;
			MBTi fy;
			MBTi fz;
		};
	};
};

class COMMONAL_API TIntVec : private TInt3d {
protected:
	virtual void SetX(MBTi ax);
	virtual void SetY(MBTi ay);
	virtual void SetZ(MBTi az);
	virtual void SetA(int i,MBTi aa);
	MBTi GetA(int i) const;
public:
	TIntVec();
	virtual ~TIntVec(){};
	
	TIntVec(const TIntVec& rhs  );
	TIntVec(MBTi x,MBTi y,MBTi z);
	TIntVec(const TVisMathVector &rhs);
	TIntVec(const TVisVector &rhs);

	__property MBTi x = {read = fx,write = SetX};
	__property MBTi y = {read = fy,write = SetY};
	__property MBTi z = {read = fz,write = SetZ};
	__property MBTi a[int] = {read = GetA,write = SetA};

	virtual TIntVec & operator = (const TVisMathVector &rhs);
	virtual TIntVec & operator = (const TVisVector &rhs);
	virtual TIntVec & operator = (const TIntVec &rhs);
	
	bool operator <=(const TIntVec &rhs) const;
	bool operator >=(const TIntVec &rhs) const;
	bool operator ==(const TIntVec &rhs) const;
	bool operator !=(const TIntVec &rhs) const;

	TIntVec operator +(const TIntVec &rhs) const;
	TIntVec operator -(const TIntVec &rhs) const;
	TIntVec XYZ_Multiply(const TIntVec &rhs) const;
	TIntVec XYZ_Divide(const TIntVec &rhs) const;
	TIntVec operator *(const TIntVec &rhs) const;
	MBTi operator &(const TIntVec &rhs) const;

	TIntVec operator ^(const TIntVec &rhs) const;
	TIntVec operator /(const TIntVec &rhs) const;
	TIntVec operator /(MBTi rhs) const;
	TIntVec operator *(MBTi rhs) const;
	//------------------------------------------

	virtual TIntVec& operator +=(const TIntVec &rhs);
	virtual TIntVec& operator -=(const TIntVec &rhs);
	virtual TIntVec& operator *=(const TIntVec &rhs);

	virtual TIntVec& operator /=(const TIntVec &rhs);
	virtual TIntVec& operator ^=(const TIntVec &rhs);
	//------------------------------------------

	virtual TIntVec& operator /=(MBTi rhs);
	virtual TIntVec& operator *=(MBTi rhs);

	MBTi Length() const;
	MBTi Length2D() const;
	//соответствует TIntVec(x,y,0)*TIntVec(0,0,1);
	TIntVec Perpendicular2D() const;

	int intX() const;
	int intY() const;
	int intZ() const;
	int intA(int index) const;
	TIntVec operator %(MBTi Cycle) const;
	virtual TIntVec& Assign(const TIntVec& Vec);
	bool Equal2D(const TIntVec& P,MBTi USEEPS=0) const;
	bool Equal(const TIntVec& P,MBTi USEEPS=0) const;
	TIntVec Normalize() const;
	//----------------------------------------
	TMyObject* MyObjectParent;
	//----------------------------------------
	operator TVisMathVector() const;
};

COMMONAL_API TIntVec VectorP(const TIntVec& a, const TIntVec& b);
COMMONAL_API MBTi ScalarP(const TIntVec& a, const TIntVec& b);
COMMONAL_API TIntVec VectorP2d(const TIntVec &src);

#endif

