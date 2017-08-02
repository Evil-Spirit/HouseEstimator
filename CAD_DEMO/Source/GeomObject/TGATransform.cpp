//---------------------------------------------------------------------------


#pragma hdrstop

#include "TGATransform.h"
#include "TGObject.h"
#include "Misc.h"
#include "math.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void TGATransform::Rotate(const TIntVec &angle, const TIntVec &center)
{
	for (int i=0;i<go.FVertex.Count;i++)
		go.FVertex[i].Point = RotateAround(go.FVertex[i].Point, angle, center);
}		
void TGATransform::Translate(const TIntVec &delta)
{
	for (int i=0;i<go.FVertex.Count;i++)
		go.FVertex[i].Point += delta;
}		

void TGATransform::Scale(const TIntVec &ratio)
{
	for (int i=0;i<go.FVertex.Count;i++)
		go.FVertex[i].Point = go.FVertex[i].Point.XYZ_Multiply(ratio);
}

void TGATransform::Translate(TMTList<TMyObject> &what, const TIntVec &org)
{
	go.FillPointsFlags(flMARK, gfFALSE);
	go.FillPointsFlags(what, flMARK, gfTRUE);
	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point += org;
}
void TGATransform::ToPlaneAndOX(TMTList<TMyObject> &what, const TIntVec& Normal, const TIntVec& n)
{
	go.FillPointsFlags(flMARK, gfFALSE);
	go.FillPointsFlags(what, flMARK, gfTRUE);

	TIntVec n_n = n;
	TIntVec angle;

	MBTi AngX = -ArcTan2(Normal.y, Normal.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, angle, TIntVec(0,0,0));

	TIntVec nNormal = Normal;
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));
	nNormal = RotateAround(nNormal, angle, TIntVec(0,0,0));

	MBTi AngY = ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, angle, TIntVec(0,0,0));
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));
	

	MBTi AngZ = ArcTan2(n_n.y, n_n.x)/M_PI*180;
	angle = TIntVec(0, 0, -AngZ);
	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, angle, TIntVec(0,0,0));
}

void TGATransform::ToPlane(TMTList<TMyObject> &what, const TIntVec& n)
{
	go.FillPointsFlags(flMARK, gfFALSE);
	go.FillPointsFlags(what, flMARK, gfTRUE);
	
	TIntVec angle;
	
	MBTi AngX = -ArcTan2(n.y, n.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, angle, TIntVec(0,0,0));
	TIntVec nNormal = RotateAround(n, angle, TIntVec(0,0,0));

	MBTi AngY = ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<go.VertexCount;i++)
		if (go.GetVertex(i).Flags.Mark == gfTRUE)
			go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, angle, TIntVec(0,0,0));
	nNormal = RotateAround(nNormal, angle, TIntVec(0,0,0));			
}


		

