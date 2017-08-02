//---------------------------------------------------------------------------

#ifndef MTLH
#define MTLH
#include "VisClass.hpp"
#include "VisMath.hpp"
#include "MathV.h"


const AnsiString StrTrue = AnsiString("TRUE");
const AnsiString StrFalse = AnsiString("FALSE");
const AnsiString StrBool[2] = {StrFalse,StrTrue};

const AnsiString StrPlus = AnsiString("+");
const AnsiString StrMinus = AnsiString("-");
const AnsiString StrZero = AnsiString("Z");
const AnsiString StrSign[3] = {StrMinus,StrZero,StrPlus};

const AnsiString StrTypes[9] = {    AnsiString("Integer"),    AnsiString("Folat"),
                                    AnsiString("String"),   AnsiString("Vector of integer"),
                                    AnsiString("Vector of float"),
                                    AnsiString("bool"),   AnsiString("Vector of bool"),
                                    AnsiString("Signed"), AnsiString("Vector of signed"),
                                };
const AnsiString DIGITS = AnsiString("1234567890");
const AnsiString DELIMS = AnsiString(".,");
const AnsiString _ABC_ = AnsiString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
const AnsiString RUS_ABC_ = AnsiString("¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ");
const AnsiString ERR_SYM = AnsiString("/\b\"\?:*<>|@");

class TIntVec;
class TBoolVec;
class TMBTRect;

#define COMMONAL_API __declspec(package)

COMMONAL_API bool ISINTEGER(const AnsiString& Str);
//COMMONAL_API bool ISFLOAT(const AnsiString&);
COMMONAL_API bool CHECKSTRVEC(const AnsiString&,bool);
COMMONAL_API bool CHECKTYPE(const AnsiString& Src, int MT);

COMMONAL_API bool IS_FLOAT(const AnsiString& FloatStr);
COMMONAL_API double TO_DOUBLE(const AnsiString& FloatStr);
COMMONAL_API AnsiString FLOATTOSTR(Extended Value);


COMMONAL_API MBTi TMyDistance(const TIntVec &A,const TIntVec &B);
COMMONAL_API TIntVec ABSINTVEC(const TIntVec & A);

COMMONAL_API bool TypeCompare(void *Data1, void *Data2, int MT);
COMMONAL_API void CopyType(int mt,void *Addr,void *Value );
COMMONAL_API void* CreateType(int mt);

COMMONAL_API MBTi StrToMBTi(const AnsiString& Str);
COMMONAL_API AnsiString MBTiToStr(MBTi mbti);

COMMONAL_API TIntVec ToIntVec(const TVisMathVector &rhs);
//--------------------------------------------
//rhs Á‡‰‡Ì ‚ ÏÂÚ‡ı ÂÁÛÎ¸Ú‡Ú ‚ ÏÏ
COMMONAL_API AnsiString ToBoolVecStr(const TBoolVec& Vec);

COMMONAL_API AnsiString VecToStrFormat(const TIntVec& Vec);
COMMONAL_API AnsiString VecToStrA(const TIntVec& Vec);

COMMONAL_API AnsiString ToRectStr(const TMBTRect& Rect);
COMMONAL_API TMBTRect RectFromStr(const AnsiString& RectStr);

COMMONAL_API TBoolVec BoolVecFromStr(const AnsiString& VecStr);
COMMONAL_API TIntVec IntVecFromStr(const AnsiString& VecStr);

const AnsiString ZEROVECSTR=AnsiString("X: 0 Y: 0 Z: 0");

COMMONAL_API AnsiString TYPETOSTR(const void * Address,int MT);
COMMONAL_API void* STRTOTYPE(const AnsiString& Src,int MT);


struct COMMONAL_API TInt3d_Old{
	union
	{
		struct
		{
			MBTi a[3];

		};
		struct
		{
			MBTi x;
			MBTi y;
			MBTi z;
		};
	};
} ;

class TMPoint;
class COMMONAL_API TChangeVec : public TIntVec {
protected:
    virtual void SetX(MBTi ax);
    virtual void SetY(MBTi ay);
    virtual void SetZ(MBTi az);
    virtual void SetA(int i,MBTi aa);
public:
    TChangeVec(){};
    TChangeVec(const TIntVec& rhs  );
//    TChangeVec(const TBoolVec& rhs  );
    TChangeVec(MBTi x,MBTi y,MBTi z);
    TChangeVec(const TVisMathVector &rhs);
    TChangeVec(const TVisVector &rhs);
    virtual ~TChangeVec(){};

    virtual TChangeVec & operator = (const TVisMathVector &rhs);
    virtual TChangeVec & operator = (const TVisVector &rhs);
    virtual TChangeVec & operator = (const TIntVec &rhs);

    virtual TChangeVec& operator +=(const TIntVec &rhs);
    virtual TChangeVec& operator -=(const TIntVec &rhs);
    virtual TChangeVec& operator *=(const TIntVec &rhs);

    virtual TChangeVec& operator /=(const TIntVec &rhs);
    virtual TChangeVec& operator ^=(const TIntVec &rhs);

	virtual TChangeVec& operator /=(MBTi rhs);
	virtual TChangeVec& operator *=(MBTi rhs);

    virtual TChangeVec& Assign(const TIntVec& Vec);

    void AboutToChange(void* Field);
    void Changed(void* Field);
};

class COMMONAL_API TMPoint{
public:
    MBTi x;
    MBTi y;
    TMPoint();
    TMPoint(MBTi x,MBTi y);
    virtual ~TMPoint(){};
    TMPoint& operator = (const TMPoint& P);
    bool operator == (const TMPoint& P) const;
};

const TMPoint ZEROMPOINT = TMPoint(0,0);


class COMMONAL_API TBool3d {
public:
    TBool3d(){};
    virtual ~TBool3d(){};
	union
	{
		struct
		{
			bool a[3];

		};
		struct
		{
			bool x;
			bool y;
			bool z;

		};

	};
};

class COMMONAL_API TBoolVec :public TBool3d {
public:
    TBoolVec(){x=0;y=0;z=0;};
    virtual ~TBoolVec(){};
    TBoolVec (bool x,bool y,bool z);
    TBoolVec & operator = (const TBoolVec &rhs);
    bool operator == (const TBoolVec &rhs);
    bool operator != (const TBoolVec &rhs);
    TBoolVec operator *(const TBoolVec &rhs);
};

COMMONAL_API void _Discrete(const TIntVec& LOW,const TIntVec& Step, TIntVec& Point);

class COMMONAL_API T3DScope{
    public:
    T3DScope(){};
    T3DScope(const TIntVec & VecLow,const TIntVec & VecHi);
    virtual ~T3DScope(){};
    TIntVec LOW;
    TIntVec HI;
    bool CheckFields();
    bool Valid(const TIntVec & Vec);
    void CrossedWithStep(const T3DScope& OS,TIntVec &Step);
    bool Crossed(T3DScope* OS);
    void Move(const TIntVec &Trans);
    void Scale(const TIntVec &Scale);
    bool PointAbout(const TIntVec&Point,TIntVec &Step,const TIntVec& DiscrStep=ZEROINTVEC);
    void Discrete(TIntVec& Point,const TIntVec &Step);
};



class COMMONAL_API T3DAngleScope :public T3DScope
{
    public:
    T3DAngleScope(const T3DScope &SC,const TIntVec &Angle,const TIntVec &Center);
    virtual ~T3DAngleScope(){};
    TIntVec Angle;
    TIntVec Center;
    bool CheckFields();
//    bool Valid(const TIntVec & Vec){return(true);};
    void CrossedWithStep(const T3DAngleScope& OS,TIntVec &Step){};
    void CrossedWithStep2D(const T3DAngleScope& OS,int ind1,int ind2,int Step);
};

COMMONAL_API MBTi Measure(const TIntVec& IV);

class COMMONAL_API __MBTRect {
public:
    __MBTRect(){};
    virtual ~__MBTRect(){};
    MBTi left;
    MBTi bottom;
    MBTi right;
    MBTi top;
};

class COMMONAL_API TMBTRect : public __MBTRect{
public:
    TMBTRect(){ left=0; top=0; right=0; bottom=0;};
    TMBTRect(MBTi l, MBTi t, MBTi r, MBTi b) { left=l; top=t; right=r; bottom=b; }
    MBTi Width () const { return right  - left; }
    MBTi Height() const { return bottom - top ; }
    bool operator ==(const TMBTRect& rc) const
    {
        return left ==  rc.left  && top==rc.top &&
            right == rc.right && bottom==rc.bottom;
    }
    bool operator !=(const TMBTRect& rc) const
    {   return !(rc==*this); }
};


COMMONAL_API bool CompareTMPoint(const TMPoint& P1,const TMPoint& P2);

COMMONAL_API bool CompareTMPointWithEPS(const TMPoint& P1,const TMPoint& P2,MBTi CompareEPS);

COMMONAL_API MBTi AngleOf(const TMPoint& _P1,const TMPoint& _P2);

#endif
