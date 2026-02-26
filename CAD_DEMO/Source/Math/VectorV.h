// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef VectorVH
#define VectorVH

#include "VisClass.hpp"
#include "VisMath.hpp"

//---------------------------------------------------------------------------

#define COMMONAL_API Q_DECL_EXPORT

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
			MBTi x;
			MBTi y;
			MBTi z;
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
	MBTi GetX() const { return x; }
	MBTi GetY() const { return y; }
	MBTi GetZ() const { return z; }
public:
	TIntVec();
	virtual ~TIntVec(){};
	
	TIntVec(const TIntVec& rhs  );
	TIntVec(MBTi x,MBTi y,MBTi z);
	TIntVec(const TVisMathVector &rhs);
	TIntVec(const TVisVector &rhs);

#ifdef _MSC_VER
	// MSVC property extension: enables obj.x / obj.x = v syntax
	__declspec(property(get=GetX, put=SetX)) MBTi x;
	__declspec(property(get=GetY, put=SetY)) MBTi y;
	__declspec(property(get=GetZ, put=SetZ)) MBTi z;
	__declspec(property(get=GetA, put=SetA)) MBTi a[];
#else
	// GCC/Clang: promote private base members to public for direct x/y/z access
	using TInt3d::x;
	using TInt3d::y;
	using TInt3d::z;
	using TInt3d::fa;
	// GCC/Clang: provide subscript operator for fa[] array access
	// (Borland __property a[int] is not available; use operator[] instead)
	MBTi& operator[](int i)       { return fa[i]; }
	MBTi  operator[](int i) const { return fa[i]; }
#endif

	// Cross-platform subscript operator for fa[] (always available)
	MBTi GetFa(int i) const { return fa[i]; }
	void SetFa(int i, MBTi v) { fa[i] = v; }

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
	//ñîîòâåòñòâóåò TIntVec(x,y,0)*TIntVec(0,0,1);
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

