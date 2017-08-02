//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "TGObject.h"
#pragma hdrstop

#include "Triangulation.h"
#include "Poligon.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

TDelone* pDeloune = NULL;

TDelone& GetDelone()
{
    return *GetDeloune();
}
TDelone* GetDeloune()
{
    if (pDeloune == NULL)
        pDeloune = new TDelone();
    return pDeloune;
}


/*
bool  TDVec::operator == (const TDVec &rhs) const
{
    return (x == rhs.x) && (y == rhs.y);
}

bool  TDVec::operator != (const TDVec &rhs) const
{
    return (x != rhs.x) || (y != rhs.y);
}

TDVec TDVec::operator +(const TDVec &rhs) const
{
    TDVec Res;
    Res.x=x+rhs.x;
    Res.y=y+rhs.y;
    return(Res);
}

TDVec TDVec::operator -(const TDVec &rhs) const
{
    TDVec Res;
    Res.x=x-rhs.x;
    Res.y=y-rhs.y;
    return(Res);
}

TDVec TDVec::operator *(const TDVec &rhs) const
{
    TDVec Res;
    Res.x=x*rhs.x;
    Res.y=y*rhs.y;
    return(Res);
}

TDVec TDVec::operator /(const TDVec &rhs) const
{
    TDVec Res;
    Res.x=x/rhs.x;
    Res.y=y/rhs.y;
    return(Res);
}

TDVec& TDVec::operator +=(const TDVec &rhs)
{
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}

TDVec& TDVec::operator -=(const TDVec &rhs)
{
    x-=rhs.x;
    y-=rhs.y;
    return *this;
}

TDVec& TDVec::operator *=(const TDVec &rhs)
{
    x*=rhs.x;
    y*=rhs.y;
    return *this;
}

TDVec& TDVec::operator /=(const TDVec &rhs)
{
    x/=rhs.x;
    y/=rhs.y;
    return *this;
}

TDVec& TDVec::operator /=(MBTi rhs)
{
    x/=rhs;
    y/=rhs;
    return *this;
}

TDVec TDVec::operator /(MBTi rhs) const
{
    TDVec Res;
    Res.x=x/rhs;
    Res.y=y/rhs;
    return(Res);
}

TDVec TDVec::operator *(MBTi rhs) const
{
    TDVec Res;
    Res.x=x*rhs;
    Res.y=y*rhs;
    return(Res);
}

TDVec& TDVec::operator *=(MBTi rhs)
{
    x*=rhs;
    y*=rhs;
    return *this;
}

MBTi TDVec::Scalar2D(const TDVec& Vec)
{
    return x*Vec.x+y*Vec.y;
}

MBTi TDVec::Equal2D(const TDVec& Vec,MBTi USEEPS)
{
    return ((fabs(x-Vec.x) < USEEPS) &&  (fabs(y-Vec.y) < USEEPS));
}

MBTi TDVec::DLength()
{
    return x*x+y*y;
}
               */
//---------------------------------------------------------------------------
TDSide::TDSide(TDVec *_P0,TDVec *_P1)
{
    ORGN = _P0;
    DEST = _P1;
    Tag = -1;
}

bool TDSide::operator ==(const TDSide &rhs) const
{
    return (ORGN == (rhs.ORGN) && DEST == (rhs.DEST)) || (ORGN == (rhs.DEST) && DEST == (rhs.ORGN));
}

int TDSide::Crossed(const TDSide& ELSE,TDVec& CROSS_POINT,MBTi USEEPS)
{
    return IsCutsCrossed((TIntVec&)*(ORGN),(TIntVec&)*(DEST),(TIntVec&)*(ELSE.ORGN),(TIntVec&)*(ELSE.DEST),(TIntVec&)CROSS_POINT,USEEPS);
}

int TDSide::AnalizePoint(const TDVec& Point,MBTi USEEPS)
{
    return Classify((TIntVec&)Point,(TIntVec&)*(ORGN),(TIntVec&)*(DEST),USEEPS);
}

bool TDSide::ConsistsPoint(const TDVec& Point,MBTi USEEPS)
{
    switch(AnalizePoint(Point,USEEPS))
    {
        //case etDESTINATION:
        //case etORIGIN:
        case etBETWEEN:
            return true;
        default:
            return false;
    }
}


//----------------------------------------------------------------------------
//-= пересекаются ли две прямые ?

bool TDelone::SimpleIntersection(TDSide& a,TDSide& b)
{
    if ( ((b.DEST->x - b.ORGN->x)*(a.ORGN->y - b.ORGN->y)-(b.DEST->y - b.ORGN->y)*(a.ORGN->x - b.ORGN->x)) *
        ((b.DEST->x - b.ORGN->x)*(a.DEST->y-b.ORGN->y) - (b.DEST->y - b.ORGN->y)*(a.DEST->x-b.ORGN->x)) < -EPS )
    if ( ((a.DEST->y - a.ORGN->y)*(a.ORGN->x - b.ORGN->x)-(a.DEST->x - a.ORGN->x)*(a.ORGN->y - b.ORGN->y)) *
        ((a.DEST->x - a.ORGN->x)*(b.DEST->y-a.ORGN->y)-(a.DEST->y - a.ORGN->y)*(b.DEST->x-a.ORGN->x)) < -EPS )
      return true;
  return false;
}

bool SI(TDSide* a,TDSide* b)
{
    if ( ((b->DEST->x - b->ORGN->x)*(a->ORGN->y - b->ORGN->y)-(b->DEST->y - b->ORGN->y)*(a->ORGN->x - b->ORGN->x)) *
        ((b->DEST->x - b->ORGN->x)*(a->DEST->y-b->ORGN->y) - (b->DEST->y - b->ORGN->y)*(a->DEST->x-b->ORGN->x)) < 0 )
    if ( ((a->DEST->y - a->ORGN->y)*(a->ORGN->x - b->ORGN->x)-(a->DEST->x - a->ORGN->x)*(a->ORGN->y - b->ORGN->y)) *
        ((a->DEST->x - a->ORGN->x)*(b->DEST->y-a->ORGN->y)-(a->DEST->y - a->ORGN->y)*(b->DEST->x-a->ORGN->x)) < 0 )
      return true;
  return false;
}

bool TDelone::CheckBldCrossing(int i, int i1, int i2)
{
    TDSide r1(pAll.Items[i],pAll.Items[i1]);
    TDSide r2(pAll.Items[i],pAll.Items[i2]);
    for (int j=0; j<rBld.Count; j++)
        if (SimpleIntersection(r2, rBld[j]) ||
            SimpleIntersection(r1, rBld[j]) )
            return true;
    return false;
}

//-= пересекаются ли построенные с исходными ребрами ?
bool TDelone::CheckSimpleCrossing(int i, int i1, int i2)
{
    TDSide r1(pAll.Items[i],pAll.Items[i1]);
    TDSide r2(pAll.Items[i],pAll.Items[i2]);
    for (int j=0; j<rAll.Count; j++)
        if (SimpleIntersection(r2, rAll[j]) ||
            SimpleIntersection(r1, rAll[j]) )
            return true;
    return false;
}

void TDelone::FindBaseRibs(int& i1,int& i2)
{
    //-= 1-я базовая точка
    for (int i=0; i<pAll.Count; i++)  //еще условие по x
        if (pAll[i].y > pAll[i1].y + EPS)
            i1 = i;
        else if ( fabs(pAll[i].y - pAll[i1].y) < EPS  && pAll[i].x < pAll[i1].x)
            i1 = i;

    //-= 2-я базовая точка
    float Angle = 1;
    float Length = 900000;
    for (int i=0; i<pAll.Count; i++)
        if (i != i1)
        {
            TDVec tmp = pAll[i1] - pAll[i];
            float a = tmp.x;//*tmp.x;
            if (fabs(a)<EPS)
                a=0;
            if (a < 0)
                a *= -a;
            else
                a *= a;
			float CurLength = tmp.DLength();
			if(CurLength != 0)
				a /= CurLength;
			else
				a = 0;
            if (a < Angle || fabs(a-Angle)<0.00001 && CurLength<Length)
            {
                Angle = a;
                Length = CurLength;
                i2 = i;
            }
        }
}

int classify(TDVec& p2,TDVec &p0, TDVec &p1)
{
  TDVec a = p1 - p0;
  TDVec b = p2 - p0;
  float sa = a.x * b.y - b.x * a.y;
  if (sa > 0.0) return etLEFT;
  if (sa < 0.0) return etRIGHT;
  if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return etBEHIND;
  if (a.DLength() < b.DLength()) return etBEYOND;
  if (p0 == p2) return etORIGIN;
  if (p1 == p2) return etDESTINATION;
  return etBETWEEN;
}


bool TDelone::FindDeloneBrother(int i1,int i2)
{
                TDSide *nSide = new TDSide(pAll.Items[i1], pAll.Items[i2]);
                for (int i=0; i<rBld.Count; i++)
                    if (*nSide == rBld[i] || SimpleIntersection(*nSide, rBld[i])) //-= Было ли уже ребро ?
                    {
                        delete nSide;
                        return false;
                    }
    rBld.Add(nSide);
    MBTi _max = 1;
    int iN;
    for (int i=0; i<pAll.Count; i++)
    {
        if (i != i1 && i != i2)                                   //  nSide->AnalizePoint(pAll[i],EPS)
            if ( classify(pAll[i],*(nSide->ORGN), *(nSide->DEST) ) == etRIGHT )
            {

                TDVec ii1 = pAll[i] - pAll[i1];
                TDVec ii2 = pAll[i] - pAll[i2];
                float Angle = (ii1.Scalar2D(ii2));//*ii1.Scalar2D(ii2));
                float tmp = (ii1.DLength()*ii2.DLength());
                if (fabs(Angle)<EPS)
                    Angle=0;
                if (tmp == 0.0)
                    continue;
                if (Angle < 0.0)
                    Angle *= -Angle;
                else
                    Angle *= Angle;
                Angle /= tmp;
                if ( (-1 < Angle && Angle < _max)/* || (fabs(Angle - _max)<EPS && () ) */)
                if (!CheckSimpleCrossing(i, i1, i2))
                {
                    _max = Angle;
                    iN = i;
                }
            } // if (LEFT)
    } // for
    if (_max != 1)
    {
        bool f = FindDeloneBrother(i1, iN); //-= запустим 2 новые базовые линии
        bool s = FindDeloneBrother(iN, i2);
        bool not_cross = !CheckBldCrossing(iN, i1, i2);
        if ( not_cross && (f || s) )                //-= нашли новый теругольник
        {
            
            Triangles.Add( (TIntVec*)pAll.Items[iN] );
            Triangles.Add( (TIntVec*)pAll.Items[i2] );
            Triangles.Add( (TIntVec*)pAll.Items[i1] );
        }
    }
    return true;
}

TDSide* TDelone::FindRibByPoints(TDVec* P0,TDVec* P1)
{
    TDSide Side(P0,P1);
    for (int i=0;i<rBld.Count;i++)
        if ( rBld[i] == Side )
            return rBld.Items[i];
    for (int i=0;i<rAll.Count;i++)
        if ( rAll[i] == Side )
            return rAll.Items[i];
    return NULL;
}

bool TDelone::FindDeloneBrother_Ribs(int i1,int i2)
{
                TDSide *nSide = new TDSide(pAll.Items[i1], pAll.Items[i2]);
                for (int i=0; i<rBld.Count; i++)
                    if (*nSide == rBld[i] || SimpleIntersection(*nSide, rBld[i])) //-= Было ли уже ребро ?
                    {
                        delete nSide;
                        return false;
                    }
    rBld.Add(nSide);
    MBTi _max = 1;
    int iN;
    for (int i=0; i<pAll.Count; i++)
    {
        if (i != i1 && i != i2)                                   //  nSide->AnalizePoint(pAll[i],EPS)
            if ( classify(pAll[i],*(nSide->ORGN), *(nSide->DEST) ) == etRIGHT )
            {
                TDVec ii1 = pAll[i] - pAll[i1];
                TDVec ii2 = pAll[i] - pAll[i2];
                float Angle = (ii1.Scalar2D(ii2));//*ii1.Scalar2D(ii2));
                float tmp = (ii1.DLength()*ii2.DLength());
                if (fabs(Angle)<EPS)
                    Angle=0;
                if (tmp != 0.0)
                {
                    if (Angle < 0.0)
                        Angle *= -Angle;
                    else
                        Angle *= Angle;
                    Angle /= tmp;
                    if ( (-1+EPS < Angle && Angle < _max-EPS)/* || (fabs(Angle - _max)<EPS && () ) */)
                    if (!CheckSimpleCrossing(i, i1, i2))
                    {
                        _max = Angle;
                        iN = i;
                    }
                } // if (!=0.0)
            } // if (LEFT)
    } // for
    if (_max != 1)
    {
        bool f = FindDeloneBrother_Ribs(i1, iN); //-= запустим 2 новые базовые линии
        bool s = FindDeloneBrother_Ribs(iN, i2);
        bool not_cross = !CheckBldCrossing(iN, i1, i2);
        if ( not_cross && (f || s) )                //-= нашли новый теругольник
        {
            Tri_Ribs.Add( FindRibByPoints(pAll.Items[iN],pAll.Items[i2]) );
            Tri_Ribs.Add( FindRibByPoints(pAll.Items[i2],pAll.Items[i1]) );
            Tri_Ribs.Add( FindRibByPoints(pAll.Items[i1],pAll.Items[iN]) );
        }
    }
    return true;
}

void TDelone::MergePolygon(TPolygon* P)
{
    for (int j=0; j<P->Vertex->Count-1; j++)
    {
        pAll.Add( (TDVec*)P->Vertex->Items[j] );
        rAll.Add( new TDSide((TDVec*)P->Vertex->Items[j],(TDVec*)P->Vertex->Items[j+1]) );
        rAll.Last()->Tag = j;
    }
    pAll.Add( (TDVec*)P->Vertex->Last() );
    rAll.Add( new TDSide((TDVec*)P->Vertex->Last(),(TDVec*)P->Vertex->First()) );
    rAll.Last()->Tag = P->Vertex->Count-1;
}

void TDelone::MergeHPolygon(THoledPolygon* HP)
{
    MergePolygon(HP);
    for (int j=0; j<HP->Holes->Count; j++)
        MergePolygon(HP->Holes->Items[j]);
}

void TDelone::Clear()
{
    Started = false;
	CashContour.Clear();
	CL_EDGE.Clear();
	rBld.Clear();
	pBld.Clear();
	rAll.Clear();
	pAll.Clear();
	Triangles.Clear();
	Tri_Ribs.Clear();
	Contour.Clear();
}
void TDelone::DeleteClosePoints()
{
	TGeomObject go;
	go.CheckCutData = false;
	go.PEPS = EPS;
	for (int i=0;i<rAll.Count;i++)
	{
		TGCut *c = go.AddCut(*rAll[i].ORGN, *rAll[i].DEST);
		if (c)
		{
			c->Tag = rAll[i].Tag;
//			c->Src->Tag = rAll[i].ORGN->Tag;
//			c->Dst->Tag = rAll[i].DEST->Tag;
		}
	}

	pAll.Clear();
	rAll.Clear();



	go.AnRender.drProcessCrossCuts2d();

	TMTList <TGCut> cuts;
	go.GetCuts(cuts);

//	go.Fix.BridgesByPolygonize(cuts);
//	go.Fix.BridgesByContourize(cuts);
	go.Fix.Repeated(cuts);
	go.Fix.Branches(cuts);
	cuts.Clear();

	go.GetCuts(cuts);

	for (int i=0;i<go.VertexCount;i++)
	{
		pAll.Add( new TDVec( go.GetVertex(i).Point ) );
//		pAll.Last()->Tag = go.GetVertex(i)->Tag
	}

	for (int i=0;i<cuts.Count;i++)
	{
		int src = go.IndexOf(cuts[i].Src);
		int dst = go.IndexOf(cuts[i].Dst);
		rAll.Add(new TDSide (pAll.Items[src], pAll.Items[dst]) );
		rAll.Last()->Tag = cuts[i].Tag;
	}



/*
	for (int i=0;i<pAll.Count;i++)
		for (int j=i+1;j<pAll.Count;j++)
			if ( pAll[i].Equal2D(pAll[j],EPS) )
			{
				if (CL_EDGE.Count==0 || CL_EDGE.Last()->INDICES[0]!=i )
				{
					CL_EDGE.Add( new TCloseEdges() );
					CL_EDGE.Last()->VECS.Add( pAll.Items[i] );
					CL_EDGE.Last()->INDICES.Add( new int(i) );
				}
				CL_EDGE.Last()->VECS.Add( pAll.Items[j] );
				CL_EDGE.Last()->INDICES.Add( new int(j) );
			}
	for (int i=0;i<rAll.Count;i++)
	{
		bool DESTFINDED = false;
		bool ORGNFINDED = false;
		for (int j=0;j<CL_EDGE.Count;j++)
		{
			if (CL_EDGE[j].VECS.IndexOf(rAll[i].ORGN)!=-1)
			{
				ORGNFINDED = true;
				rAll[i].ORGN = CL_EDGE[j].VECS.Items[0];
			}
			if (CL_EDGE[j].VECS.IndexOf(rAll[i].DEST)!=-1)
			{
				DESTFINDED = true;
				rAll[i].DEST = CL_EDGE[j].VECS.Items[0];
			}
			if (ORGNFINDED&&DESTFINDED)
			{
				if (rAll[i].DEST == rAll[i].ORGN)
					rAll.Delete(i--);
				break;
			}
		}
	}
	for (int j=0;j<CL_EDGE.Count;j++)
		for (int k=1;k<CL_EDGE[j].VECS.Count;k++)
			pAll.Remove(CL_EDGE[j].VECS.Items[k]);*/
}

int TDelone::FindClosePoint(const TDVec& Vec,MBTi USEEPS)
{
	for (int i=0;i<pAll.Count;i++)
		if ( pAll[i].Equal2D(Vec,USEEPS) )
			return i;
	return -1;
}

void TDelone::ProcessCrossList()
{
	bool OrgnOrgn = false;
	bool OrgnDest;
	bool DestOrgn;
	bool DestDest;
	bool iC_Orgn;
	bool iC_Dest;
	bool jC_Orgn;
	bool jC_Dest;
	for (int i=0; i<rAll.Count; i++)
		for (int j=i+1; j<rAll.Count; j++)
		{
			OrgnOrgn = rAll[i].ORGN == rAll[j].ORGN;
			OrgnDest = rAll[i].ORGN == rAll[j].DEST;
			DestOrgn = rAll[i].DEST == rAll[j].ORGN;
			DestDest = rAll[i].DEST == rAll[j].DEST;
			if ( int(OrgnOrgn)+int(OrgnDest)+int(DestOrgn)+int(DestDest)>=2 )
			{
				//равны
				rAll.Delete(j--);
				continue;
			}

            bool iC_Orgn = rAll[i].ConsistsPoint(*rAll[j].ORGN,EPS);
            bool iC_Dest = rAll[i].ConsistsPoint(*rAll[j].DEST,EPS);
            bool jC_Orgn = rAll[j].ConsistsPoint(*rAll[i].ORGN,EPS);
            bool jC_Dest = rAll[j].ConsistsPoint(*rAll[i].DEST,EPS);;

 /*           if ( int(iC_Orgn)+int(iC_Dest)+int(jC_Orgn)+int(jC_Dest)>=2 )
            {
                //коллинеарны
                TDVec* P[4];
                P[0] = rAll[i].ORGN;
                P[1] = rAll[i].DEST;
                P[2] = rAll[j].ORGN;
                P[3] = rAll[j].DEST;
                TDVec Normal = *(P[1]) - *(P[0]);
                TDVec CurNormal;
                bool Changed = true;
				while (Changed)
                {
                    Changed = false;
                    for (int i=0;i<3;i++)
                    {
                        CurNormal = *(P[i+1]) - *(P[i]);
                        if (CurNormal.x*Normal.x<-EPS || CurNormal.y*Normal.y<-EPS)
                        {
                            TDVec* Vec = P[i];
                            P[i] = P[i+1];
                            P[i+1] = Vec;
                            Changed = true;
						}
                    }
                }
                rAll.Add(new TDSide(P[0],P[1]));
                rAll.Add(new TDSide(P[1],P[2]));
                rAll.Add(new TDSide(P[2],P[3]));

                rAll.Delete(MAX(i,j));
                rAll.Delete(MIN(i,j));
                i--;
                j--;
                break;
            }     */
            
            //просто содержит точку
            //не рассмотрен случай когда
            bool OneCommonPoint = OrgnOrgn || OrgnDest || DestOrgn || DestDest;
			if (OneCommonPoint && (iC_Orgn || iC_Dest))
            {
                rAll.Delete(j--);
                continue;
            }
            if (OneCommonPoint && (jC_Orgn || jC_Dest))
            {
                rAll.Delete(i--);
                break;
            }
            if (iC_Orgn)
            {
				rAll.Add(new TDSide(rAll[j].ORGN,rAll[i].DEST));
                rAll[i].DEST = rAll[j].ORGN;
                rAll.Last()->Tag = rAll[i].Tag;
                continue;
            }
            if (iC_Dest)
            {
                rAll.Add(new TDSide(rAll[j].DEST,rAll[i].DEST));
                rAll[i].DEST = rAll[j].DEST;
                rAll.Last()->Tag = rAll[i].Tag;
                continue;
            }
            if (jC_Orgn)
            {
                rAll.Add(new TDSide(rAll[i].ORGN,rAll[j].DEST));
                rAll[j].DEST = rAll[i].ORGN;
                rAll.Last()->Tag = rAll[j].Tag;
				continue;
            }
            if (jC_Dest)
            {
                rAll.Add(new TDSide(rAll[i].DEST,rAll[j].DEST));
                rAll[j].DEST = rAll[i].DEST;
                rAll.Last()->Tag = rAll[j].Tag;
                continue;
            }
            if (OneCommonPoint)
                continue;
            //простое пересечение
			TDVec CROSS_VEC;
            if ( rAll[i].Crossed(rAll[j],CROSS_VEC,EPS) == lcCROSSING )
            {
                int index = FindClosePoint(CROSS_VEC,EPS);
                TDVec* Vec = NULL;
                if (index != -1)
                    Vec = pAll.Items[index];
                else
                {
                    Vec = new TDVec(CROSS_VEC);
                    pBld.Add(Vec);
                    pAll.Add(Vec);
                }


                MBTi Z_HOLE = HoleStartIndex-1;
                if (rAll[i].ORGN->z >= HoleStartIndex && rAll[i].DEST->z >= HoleStartIndex && rAll[i].ORGN->z == rAll[i].DEST->z)
					Z_HOLE = rAll[i].ORGN->z;
                if (rAll[j].ORGN->z >= HoleStartIndex && rAll[j].DEST->z >= HoleStartIndex && rAll[j].ORGN->z == rAll[j].DEST->z)
                    Z_HOLE = rAll[j].ORGN->z;    


                if (Vec!=rAll[i].DEST)
                {
                    rAll.Add(new TDSide(Vec,rAll[i].DEST));
                    rAll.Last()->Tag = rAll[i].Tag;
                }
                if (Vec!=rAll[j].DEST)
                {
					rAll.Add(new TDSide(Vec,rAll[j].DEST));
					rAll.Last()->Tag = rAll[j].Tag;
                }

                TDSide* iSide = rAll.Items[i];
                TDSide* jSide = rAll.Items[j];
                if (iSide->ORGN == Vec)
                    rAll.Remove(iSide);
                else
                    iSide->DEST = Vec;
                if (jSide->ORGN == Vec)
                    rAll.Remove(jSide);
                else
                    jSide->DEST = Vec;

                if (Z_HOLE>=HoleStartIndex)
                    Vec->z = Z_HOLE;

            }
        }
}

void TDelone::TriangulateByPoints()
{
    int i1 = 0;
    int i2;
    FindBaseRibs(i1,i2);
    FindDeloneBrother(i1,i2);
}

void TDelone::TriangulateByRibs()
{
    int i1 = 0;
    int i2;
    FindBaseRibs(i1,i2);
    FindDeloneBrother_Ribs(i1,i2);
}

TMTList<TIntVec>* TDelone::Triangulate(THoledPolygon* HP)
{
	Clear();
	MergeHPolygon(HP);
//	ProcessCrossList();
	DeleteClosePoints();
	TriangulateByPoints();
    int j=0;
	for (int i=0;i<Triangles.Count;)
    {
		TIntVec Center = (Triangles[i]+Triangles[i+1]+Triangles[i+2])/3;
        bool Delete = false;
        if (HP->ConsistsPoint_UseHoles(Center,EPS) == pipOUTSIDE)
                Delete = true;
        if (Delete)
        {
            Triangles.Delete(i);
            Triangles.Delete(i);
            Triangles.Delete(i);
        }
		else
            i+=3;
        j++;            
     }     

    return &Triangles;
}

TMTList<TIntVec>* TDelone::Triangulate2(TMTList<THoledPolygon>* HPL,TMyPolOperation pOP)
{
    Clear();
    for (int i=0;i<HPL->Count;i++)
        MergeHPolygon(HPL->Items[i]);
    DeleteClosePoints();
    ProcessCrossList();
    TriangulateByPoints();
	for (int i=0;i<Triangles.Count;)
	{
        TIntVec Center = (Triangles[i]+Triangles[i+1]+Triangles[i+2])/3;
        bool Delete = false;
        for (int j=0;j<HPL->Count;j++)
            if (HPL->Items[j]->ConsistsPoint_UseHoles(Center,EPS) == pipOUTSIDE)
            {
                Delete = true;
                break;
            }
        if (Delete)
        {
            Triangles.Delete(i);
			Triangles.Delete(i);
            Triangles.Delete(i);
        }
        else
            i+=3;
    }
    return &Triangles;
}

TMTList<TIntVec>* TDelone::Triangulate3(THoledPolygon* HP,TMTList<TIntVec>* LineEdges)
{
    Clear();
	MergeHPolygon(HP);
	for (int i=0;i<LineEdges->Count;i+=2)
    {
        pAll.Add((TDVec*)LineEdges->Items[i]);
        pAll.Add((TDVec*)LineEdges->Items[i+1]);
		rAll.Add(new TDSide( (TDVec*)LineEdges->Items[i],(TDVec*)LineEdges->Items[i+1] ));
    }

	DeleteClosePoints();
    ProcessCrossList();
    TriangulateByPoints();
    for (int i=0;i<Triangles.Count;)
        if (Triangles[i].z == 1234 && Triangles[i+1].z == 1234 && Triangles[i+2].z == 1234)
        {
            Triangles.Delete(i);
            Triangles.Delete(i);
            Triangles.Delete(i);
		}
        else
            i+=3;
    return &Triangles;
}

TDVec* Find_Pnt_In_List( TMTList<TDSide>& SideList,TDSide* Side,TDVec* Point,int& index)
{
    for (int i=0;i<SideList.Count;i++)
    {
        if (SideList.Items[i] == Side)
            continue;
        if ( SideList[i].ORGN == Point )
        {
            index = i;
            return SideList[i].DEST;
        }
		if ( SideList[i].DEST == Point )
        {
            index = i;
            return SideList[i].ORGN;
		}
	}
	index=-1;
	return NULL;
}

TMTList<TIntVec>* TDelone::OPERATION(TPolygon* P0,TPolygon* P1,int oper)
{
	TIntVec first = *P0->Vertex->Items[0];
	Clear();
	Started = true;
	MergePolygon(P0);
	MergePolygon(P1);
	DeleteClosePoints();
	ProcessCrossList();

	TriangulateByRibs();

	for (int i=0;i<Tri_Ribs.Count;)
	{
		TIntVec Center = (  *((TIntVec*)Tri_Ribs[i].ORGN) + *((TIntVec*)Tri_Ribs[i+1].ORGN) + *((TIntVec*)Tri_Ribs[i+2].ORGN) +
							*((TIntVec*)Tri_Ribs[i].DEST) + *((TIntVec*)Tri_Ribs[i+1].DEST) + *((TIntVec*)Tri_Ribs[i+2].DEST) )/6;
		bool p0_yes = ( P0->ConsistsPoint(Center,EPS) != pipOUTSIDE );
		bool p1_yes = ( P1->ConsistsPoint(Center,EPS) != pipOUTSIDE );
		bool Delete = false;
		switch (oper)
		{
			case opAND :
				Delete = !(p0_yes && p1_yes);
			break;
			case opMINUS :
				Delete = !(p0_yes && !p1_yes);
			break;
			case opOR :
				Delete = !(p0_yes || p1_yes);
			break;
			case opXOR :
				Delete = !(p0_yes || !p1_yes);
			break;
		};
		if (Delete)
		{
			Tri_Ribs.Delete(i);
			Tri_Ribs.Delete(i);
			Tri_Ribs.Delete(i);
		}
		else
			i+=3;
	}



	TMTList<TDSide> SideList;
	TMDelTList<int> stat;
	for (int i=0;i<Tri_Ribs.Count;i++)
	{
		int index = SideList.IndexOf(Tri_Ribs.Items[i]);
		if (index == -1)
		{
			index = SideList.Add(Tri_Ribs.Items[i]);
			stat.Add(new int(0));
		}
		stat[index]++;
	}
	for (int i=0;i<SideList.Count;i++)
		if ( stat[i] == 2 )
		{
			SideList.Delete(i);
			stat.Delete(i--);
		}
	if (SideList.Count == 0)
	{
		Started = false;
		return &Contour;
	}

	int index = 0;
	TDVec* Pnt = SideList[index].ORGN;
	while (Pnt)
	{
		if (Contour.IndexOf((TIntVec*)Pnt)!=-1)
			break;
		else
			Contour.Add((TIntVec*)Pnt);
		//----------------------------------
		TDSide* Side = SideList.Items[index];
		Pnt = Find_Pnt_In_List(SideList,Side,Pnt,index);
	}

	TPolygon POL(&Contour);
	if (POL.IsClockWize() == 1)
		POL.Invert();


	int nol_index = -1;
	MBTi MAXEPS = 0.1;
	MBTi CUREPS = EPS;
/************************************************/
// SUXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/************************************************/
	for (int i=0;i<Contour.Count;i++)
		if (nol_index == -1 || (Contour[i]-first).Length()<(Contour[nol_index]-first).Length())
			nol_index = i;
/************************************************/
// SUXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/************************************************/

	for (int i=0;i<Contour.Count;i++)
		CashContour.Add( new TIntVec(Contour[(i+nol_index)%Contour.Count]) );

	TPolygon POL2(&CashContour);
	POL2.KillCollinear_1(EPS);

	Contour.Assign(&CashContour);

	Started = false;
	return &Contour;
}

TMTList<TIntVec>* TDelone::GetContour(TPolygon* SelfCrossed)
{
	return NULL;
};

