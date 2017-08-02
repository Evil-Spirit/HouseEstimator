//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

#include "Usefuls.h"
#include "MTL.h"
#include "MyTEmplates.h"
#include "MathV.h"
//---------------------------------------------------------------------------


///typedef bool (__closure *TConditionForPass)(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
class TGPoint;
class TGCut;
class TGeomObject;

enum TRenderType		// ��� �����������
{
	rtCLASSIFY,			// �������������
	rtMARK,				// ����������
	rtSMOOTH,			// �����������
	rtCOLOR,			// �����
	rtERROR				// ������
};

enum TTag				// ��� ���
{
	tgOTHER	  	= 0,
	tgTHIS		= 3,

	tgPOSITIVE	= 1,
	tgNEGATIVE	= -1,
	tgINTERSECT	= 2,

	tgTRUE		= 1,
	tgFALSE		= 0,
};

enum TConstructFlags	// ����� �����������
{
	coPOINTS		= 0x0001,			// �����
	coCUTS			= 0x0002,			// �������
	coPOLYGONS		= 0x0004,			// ��������
	coNORMALS		= 0x0008,			// �������
	coPOLYGONHOLES  = 0x0010,			// ����� ���������

	coWIRE			= 0x0001 | 0x0002,	// ��������� (�����+�������)
	coSOLID			= 0x0004,			// ������� ���� (������ ��������)
	coALL			= 0xFFFF			// ���
};

enum TGeomResult	// ��������� �������������� �������
{
	grOK	=	0x0001,		// ��
	grERROR =	0x0000,		// ������
};

enum TGeomFixFlags			// ����� ��������������� ��������������
{
	gfxPOINTSINCUTS		=	0x0001,		// 
	gfxCUTSCROSS		=	0x0002,
	gfxCLOSEPOINTS		=	0x0004,
	gfxALL				=	0xFFFF
};
	
enum TStructFixFlags		// ����� ������������ ��������������
{
	sfxREMOVE_BRANCHES					= 0x0001,	// ������� �����
	sfxREMOVE_REPEATED					= 0x0002,	// ������� ��������� 	
	sfxREMOVE_BRIDGES_BY_CONTOURIZE     = 0x0004,	// ������� ����� �������������
	sfxREMOVE_BRIDGES_BY_POLYGONIZE     = 0x0008,	// ������� ����� ��������������
};

enum TGeomPrimitiveType		
{
	gpPOINT		= 0x0001,
	gpPOINTS	= 0x0001,

	gpCUT		= 0x0002,
	gpCUTS		= 0x0002,

	gpPOLYGON	= 0x0003,
	gpPOLYGONS	= 0x0003,

	gpALL		= 0xFFFFFFFF
};

enum TClassifyFlags			// ����� 
{                       	
	flORIGIN		= 0x0001,	// ���������
	flHOLE			= 0x0002,	// �����
	flINTERSECT		= 0x0004,	// �����������
	flCONTOUR		= 0x0008,	// ������
	flMARK			= 0x0010,	// ����������
	flALREDY		= 0x0020,	// ��� ����
	flBELONG		= 0x0040,	// ��������������
	flSAME			= 0x0080,	// �������������
	flERROR			= 0x0100,	// ������
	flCACHED		= 0x0200,	// ����������
	flNEEDCALCN		= 0x0400,	// ����� ��������(�����������)
	flBOUNDARY		= 0x0800,	// ���������
	flNEEDCALCB		= 0x1000,	// ����� ��������(�����������)
	flALL			= 0xFFFF,	// ���
};

enum TGBoolean					// ����� ������� �������� ��� ����������
{
	gbA_MINUS_B		= 0x01,		// A - B
	gbB_MINUS_A		= 0x02,     // B - A

	gbA_AND_B		= 0x03,		// ���������� A � B
	gbINTERSECTION	= 0x03,		//

	gbA_XOR_B		= 0x04,		// ����������� A � B
	gbUNION			= 0x04,		//

	gbSPLIT			= 0x05		// ������ ���������
};

enum TClassify					// ����� ����
{
	gfFALSE			= 0x00,		// ������
	gfTRUE			= 0x01,		// ��������

	gfUNDEFINED		= 0x00,		// ����������������

	gfNEGATIVE		= 0x01,		// ���������������
	gfPOSITIVE 		= 0x02,		// ���������������
	gfINTERSECT 	= 0x03,		// �����������
	gfCOLLINEAR 	= 0x04,		// ��������������

	gfOTHER		 	= 0x00,		// ��������
	gfTHIS		 	= 0x01,		// ���������

};

template <class t1, class t2>		// ������� �������. ������ � ���������(������)
struct TMTwinElement
{
	t1 Data;
	t2 Target;
};

struct TGeomFlags					// ������� �������������� �����
{
	// ����� ������ �������
	unsigned Origin:3;				// ��������� ��� �������������
	unsigned Cached:1;				// ���������������� 
	unsigned Intersect:1;           // �����������
	unsigned Solid:1;				// ����������� (�������������� ��������� �������� ����)
	unsigned Alredy:1;				// �������������, �����������, �������������

	// ���������� �����
	unsigned Mark:1;				// ����������
	unsigned Hole:1;				// �����
	unsigned Belong:1;				// ��������������
	unsigned Contour:1;				// ������
	unsigned Same:1;				// �������������
	unsigned Error:1;				// �����������
	unsigned NeedCalcN:1;			// ���������� 
	unsigned NeedCalcB:1;			// ���������� 
	unsigned Boundary:1;			// �����������

	unsigned reserved:19;			// ������
};

class TBBox
{
public:
	TIntVec Min;
	TIntVec Max;

	TBBox(){} 
	TBBox(const TIntVec &min, const TIntVec &max) : Min(min), Max(max){}
	bool Overlaps(const TBBox &other, MBTi EPS = 0.0) const;
	bool Overlaps2d(const TBBox &other, MBTi EPS = 0.0) const;
	void Calculate(const TMTList <TGPoint> &pnts);
	void Calculate(const TMTList <TGCut> &cuts);
	void Calculate(const TGCut &cut);
};

class TGAlgorithm
{
protected:
	TGeomObject &go;
public:	
	TGAlgorithm(TGeomObject &obj) : go(obj) {};
};


#endif
 
