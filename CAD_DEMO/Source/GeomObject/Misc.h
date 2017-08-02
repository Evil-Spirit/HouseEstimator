//---------------------------------------------------------------------------

#ifndef MiscH
#define MiscH
//---------------------------------------------------------------------------
#include "Types.h"
#include "Poligon.h"
#include "TGPolygon.h"
#include "TGObject.h"

class TGPolygon;

COMMONAL_API void GetBasePoints(const TMTList<TGCut> &cuts, TMTList<TGPoint> &points);
TGeomFlags  FlagUnite(const TGeomFlags &a, const TGeomFlags &b);
COMMONAL_API void Triangulate_(TGPolygon* GHP, TMDelTList <TIntVec> &tris);
void SetFlag(TGeomFlags &tgt, TClassifyFlags Flag, TClassify State);
TIntVec GetToPlaneAnglesXZ(const TIntVec &n);
void TransformXZ(const TIntVec &a, TIntVec &v);
void BackXZ(const TIntVec &a, TIntVec &v);

template <class T>
void IndexBy(TMTList <T> &by)
{
	int i(0);
	for (bool ok=by.Start(); ok; ok=by.Next())
	{
		by.GetCurrent()->Index = i;
		i++;
	}	
}
template <class T>
void TMTListAdd(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		src.Add(dst.Items[i]);
}

template <class T>
void TMTListSub(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		src.Remove(dst.Items[i]);
}

template <class T>
void TMTListUnite(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		if (dst.Items[i])
		{	
			int n=-1;
			if ((n = src.IndexOf(NULL)) != -1)
				src.Items[n] = dst.Items[i];
			else if (src.IndexOf(dst.Items[i]) == -1)
				src.Add(dst.Items[i]);
		}		
}

template <class T>
bool TMTListCompare(const TMTList<T> &src, const TMTList<T> &dst)
{
	if (src.Count != dst.Count)
		return false;
	for (int i=0;i<src.Count;i++)
		if (dst.IndexOf(src.Items[i]) == -1)
			return false;
	return true;
}

void COMMONAL_API ConstructVCO(TVisPrimitiveObj *VCO, TGeomObject* GO);


#endif

