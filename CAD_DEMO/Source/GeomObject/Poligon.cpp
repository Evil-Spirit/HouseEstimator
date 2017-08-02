 //---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#include <stdlib.h>
#include "Poligon.h"
#include "math.h"
#include "MyGL.h"
#include "TGObject.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TClassNode* TLPoint::StaticType = NULL;
TClassNode* TLCut::StaticType = NULL;
TClassNode* TPolygon::StaticType = NULL;
TClassNode* THoledPolygon::StaticType = NULL;

TLPoint::TLPoint()
{
    RegisterNewClass<TMyObject,TLPoint>(this,false,&CreateFunction);
};

TLPoint::~TLPoint()
{
    for (int i=0;i<Cuts.Count;)
        if (Cuts[i].Src == this)
            Cuts[i].Src = NULL;
        else if (Cuts[i].Dst == this)
            Cuts[i].Dst = NULL;
        else
            i++;
};

TMyObject* TLPoint::CreateFunction()
{
    return new TLPoint();
}

TLCut::TLCut()
{
    RegisterNewClass<TMyObject,TLCut>(this,false,&CreateFunction);
    FSrc=NULL;
    FDst=NULL;
    Tag = -1;
};

TLCut::~TLCut()
{
    Src=NULL;
    Dst=NULL;
};

TMyObject* TLCut::CreateFunction()
{
    return new TLCut();
}

bool TLCut::ConsistsDstAndSrc(TLPoint* R1,TLPoint* R2)
{
    return ((R1==Src)&&(R2==Dst)) || ((R1==Dst)&&(R2==Src));
}

void TLCut::SetSrc(TLPoint* Value)
{
    if (FSrc)
        FSrc->Cuts.Remove(this);
    FSrc = Value;
    if (FSrc)
        FSrc->Cuts.Add(this);
}

void TLCut::SetDst(TLPoint* Value)
{
    if (FDst)
        FDst->Cuts.Remove(this);
    FDst = Value;
    if (FDst)
        FDst->Cuts.Add(this);
}

const AnsiString aVertex = AnsiString("Vertex");

TPolygon::TPolygon()
{
    RegisterNewClass< TMyObject, TPolygon >(this,false,&CreateFunction);
    NotInstanced = false;
	Vertex = new /*TMDelLSTList*/TMDelTList<TIntVec>();
    RegisterField(Vertex,&aVertex,mtMyObject);
    Router = NULL;
}

TPolygon::TPolygon(TMDelTList<TIntVec>* PNTS)
{
    RegisterNewClass< TMyObject, TPolygon >(this,false,&CreateFunction);
    NotInstanced = true;
    Vertex = (/*TMDelLSTList*/TMDelTList<TIntVec>*)PNTS;
    //регистрация здесь нелопустима из-за переадресации сообщений
    //с нижнего уровня на верхний
//    RegisterField(Vertex,&aVertex,mtMyObject);
    Router = NULL;
}

TPolygon::TPolygon(TMTList<TIntVec>* PNTS)
{
    RegisterNewClass< TMyObject, TPolygon >(this,false,&CreateFunction);
    NotInstanced = true;
    Vertex = (/*TMDelLSTList*/TMDelTList<TIntVec>*)PNTS;
//    RegisterField(Vertex,&aVertex,mtMyObject);
    Router = NULL;
}

TMyObject* TPolygon::CreateFunction()
{
    return new TPolygon();
}


TPolygon::~TPolygon()
{
    if (!NotInstanced)
        delete Vertex;
}

void TPolygon::Clear()
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Clear()>: Полигон is read only!");
    Vertex->Clear();
}

int TPolygon::FindLowRight(MBTi EPS)
{
    if (Vertex->Count==0)
        return -1;
    int index = 0;
    for (int i=1;i<Vertex->Count;i++)
        if (Vertex->Items[index]->y < (Vertex->Items[i]->y - EPS))
            index = i;
		else if ( fabs( Vertex->Items[index]->y - Vertex->Items[i]->y ) < EPS &&
        Vertex->Items[index]->x > Vertex->Items[i]->x)
            index = i;
    return index;
}

int TPolygon::IsClockWize()
{
    if (Vertex->Count<3)
        return 0;
    int Index = FindLowRight(_MBTi_eps_);

    switch ( Classify(  *(Vertex->CycleItems[Index+1]),
                        *(Vertex->CycleItems[Index-1]),
                        *(Vertex->CycleItems[Index]),_MBTi_eps_ ))
    {
        case etLEFT:
            return -1;
        case etRIGHT:
            return 1;
        default:
            return 0;
    };
}

bool TPolygon::FindSelfCrossing(int& i1,int& i2,MBTi USEEPS)
{
    i1 = -1;
    i2 = -1;
    TIntVec CROSSPOINT;
    TIntVec *P[4];
    for (int i=0;i<Vertex->Count;i++)
        for (int j=i+2;j<Vertex->Count;j++)
        {
            P[0] = Vertex->CycleItems[i];
            P[1] = Vertex->CycleItems[i+1];
            P[2] = Vertex->CycleItems[j];
            P[3] = Vertex->CycleItems[j+1];

            if ( P[0] == P[2] || P[1] == P[2] || P[0]==P[3] || P[1] ==  P[3] )
                continue;
            int res = IsCutsCrossed(       *(P[0]) ,
                                            *(P[1]),
                                            *(P[2]),
                                            *(P[3]),
                                            CROSSPOINT,
                                            USEEPS);
            if (res!=lcNONE && res!= lcPARALLEL && res != lcCOLLINEAR)
            {
                i1 = i;
                i2 = j;
                return true;
			}
		}
	return false;
}

bool __fastcall SortByX(void *item1, void *item2)
{
	return ((TIntVec*)item1)->x > ((TIntVec*)item2)->x;
}

void TPolygon::GetCrossPoints(
								const TIntVec& P1,
								const TIntVec& P2,
								TMDelTList<TIntVec>* PointList,    								bool UseLinePoints,
								bool Edge,
								MBTi USEEPS
								)
{
	TGeomObject go;
	go.PEPS = USEEPS;

	TMDelTList<TIntVec>& Vert = *(Vertex);
	TMDelTList<TIntVec>& PList = *(PointList);
	PList.Clear();

	for (int i=0;i<Vert.Count;i++)
		go.AddPoint(Vert[i]);

	for (int i=0;i<go.VertexCount;i++)
		go.AddCut(&go.GetVertex(i), &go.GetVertex((i + 1) % go.VertexCount));

	TMTList<TGCut> cuts;

	go.GetCuts(cuts);

	TGPolygon *p = go.AddPolygon(cuts);

	TGPoint *p1 = go.AddPoint(P1);
	TGPoint *p2 = go.AddPoint(P2);


	MBTi AngleOX = (AngleRadOX(P1, P2,USEEPS)*180)/M_PI;
	TIntVec Angle3D = TIntVec(0,0,-AngleOX);
	TIntVec RotPoint = P1;

	for (int i=0;i<go.VertexCount;i++)
		go.GetVertex(i).Point = RotateAround(go.GetVertex(i).Point, Angle3D, RotPoint);
	MBTi d = (p1->Point.y+p2->Point.y)/2.0;
	for (int i=0;i<go.VertexCount;i++)
		go.GetVertex(i).Point.y = go.GetVertex(i).Point.y - d;

	TMTList <TGPoint> cps;
	if (UseLinePoints)
	{
		cps.Add(p1);
		cps.Add(p2);
	}
	for (int i=0;i<cuts.Count;i++)
	{
		TGPoint *cp = go.Slice.CrossCutOX(cuts[i], USEEPS);
		if (cp)
			cps.Add(cp);
	}

	for (int i=0;i<cps.Count;i++)
		for (int j=i+1;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

	for (int i=0;i<cps.Count-1;i++)
	{
		if (cps.Items[i] == cps.Items[i+1])
			continue;
		// Принадлежность отрезков полигонам
		// Эпсилон принадлежности должен быть в несколько раз меньше эпсилона точек
		TIntVec mid = (cps[i].Point + cps[i+1].Point)/2.0;

		int a = p->PointInPolygon2d( mid, USEEPS/2);

		// Если отрезок принадлежит обоим полигонам, добавляем общий отрезок
		if (a == pipINSIDE || a == pipBOUNDARY)
		{
			PList.Add( new TIntVec(cps[i].Point) );
			PList.Add( new TIntVec(cps[i+1].Point) );
		}
	}
	Angle3D = TIntVec(0,0,AngleOX);
	for (int i=0;i<PList.Count;i++)
	{
		PList[i].y = PList[i].y + d;
		PList[i] = RotateAround(PList[i], Angle3D, RotPoint);
	}
}

int TPolygon::FindCollinear(MBTi USEEPS)
{
	TMDelTList<TIntVec>& vVertex = *(Vertex);
	for (int i=0;i<vVertex.Count;i++)
		if ( IsLinesCollinear(   *(vVertex.CycleItems[i-1]),
								*(vVertex.CycleItems[i]),
								*(vVertex.CycleItems[i]),
								*(vVertex.CycleItems[i+1]),USEEPS) )
			return i;
	return -1;
}

bool TPolygon::KillCloseEdges_0(MBTi USEEPS)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::KillCloseEdges_0()>: Полигон is read only!");
    TMDelTList<TIntVec>& vVertex = *(Vertex);
    for (int i=0;i<vVertex.Count;i++)
        if (vVertex.Count>=2 && (vVertex[i]-vVertex[(i+1)%vVertex.Count]).Length()<USEEPS )
			vVertex.Delete(i--);
    return vVertex.Count>=3;
}


bool TPolygon::KillCollinear_1(MBTi USEEPS)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::KillCollinear_1()>: Полигон is read only!");
    TMDelTList<TIntVec>& vVertex = *(Vertex);
    if (vVertex.Count<3)
        return false;
    for (int i=0;i<vVertex.Count;i++)
        if (vVertex.Count>2 && IsLinesCollinear(   *(vVertex.CycleItems[i-1]),
                                *(vVertex.CycleItems[i]),
                                *(vVertex.CycleItems[i]),
                                *(vVertex.CycleItems[i+1]),USEEPS) )
            vVertex.Delete(i--);
    return vVertex.Count>=3;
}

void TPolygon::SquareCreate(const TIntVec& Size)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::SquareCreate()>: Полигон is read only!");
    Clear();
    Vertex->Add( new TIntVec(Size.x/2,Size.y/2,-Size.z/2) );
	Vertex->Add( new TIntVec(-Size.x/2,Size.y/2,-Size.z/2) );
    Vertex->Add( new TIntVec(-Size.x/2,-Size.y/2,-Size.z/2) );
    Vertex->Add( new TIntVec(Size.x/2,-Size.y/2,-Size.z/2) );
}


bool TPolygon::Valid(MBTi USEEPS)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Valid()>: Полигон is read only!");
    if (!KillCloseEdges_0(USEEPS) || !KillCollinear_1(USEEPS))
        return false;
    if (Vertex->Count<3)
        return false;
    switch (IsClockWize())
    {
        case cwNotDefined:
            return false;
        case cwClockWize:
            Vertex->Invert();
    }
    int i1=-1;
    int i2=-1;
    return !FindSelfCrossing(i1,i2,USEEPS);
}


//call after
//KillCloseEdges_0
//KillCollinear_1

void TPolygon::KillSelfCrossing_2(TMDelTList<TPolygon>* POLS,MBTi USEEPS)
{
    TMTList<TIntVec> V;
    V.Assign(Vertex);
    TMDelTList<TIntVec> Build;
    TPolygon P(&V);
    int i1,i2;
    if (P.FindSelfCrossing(i1,i2,USEEPS))
    {
        Build.Add( new TIntVec() );
        IsLinesCrossedExactly(V[i1],V[(i1+1)%V.Count],V[i2],V[(i2+1)%V.Count],*(Build.Last()));
        V.Insert(i1,Build.Last());
        V.Insert(i2+1,Build.Last());

        int i = i1;
        int j = i2+1;
        //----------------------------------------------------------------------
        POLS->Add(new TPolygon());
        for (int k=i;k<=j-1;k++)
            POLS->Last()->Vertex->Add(new TIntVec(V[k]));
        POLS->Last()->KillSelfCrossing_2(POLS,USEEPS);
        //----------------------------------------------------------------------
        int VCount = V.Count;
        POLS->Add(new TPolygon());
        for (int k=j;k<=VCount+i-1;k++)
            POLS->Last()->Vertex->Add(new TIntVec(V[k%VCount]));
        POLS->Last()->KillSelfCrossing_2(POLS,USEEPS);
    }
    if (POLS->IndexOf(this)!=-1)
        POLS->Remove(this);
}


//call after killcloseedges;
//call after killcollinear;
//must be un_clockwize
void TPolygon::ExtrudeRib(int i,MBTi Value,MBTi USEEPS)
{
    TMDelTList<TIntVec>& Vert = *(Vertex);

    if (Vert.Count<3)
        return;
    TIntVec newVert_i;
    TIntVec newVert_ip1;
//    bool i_close=false;
//    bool ip1_close=false;
    MBTi i_Angle = AngleRad(Vert.CycVal(i-1),Vert[i],Vert.CycVal(i+1),USEEPS);
    MBTi ip1_Angle = AngleRad(Vert[i],Vert.CycVal(i+1),Vert.CycVal(i+2),USEEPS);
    if (i_Angle<M_PI)
    {
        MBTi new_iAngle = M_PI-i_Angle;
        MBTi WasLength = (Vert.CycVal(i-1)-Vert[i]).Length2D();
        MBTi fsin = fabs(sin(new_iAngle));
        MBTi AddOn(Value);
        if (fsin > 0.000001)
            AddOn = Value/fsin;
        newVert_i = PointOfLineOnCut( Vert.CycVal(i-1),Vert[i], WasLength + AddOn );
//        i_close = fabs(WasLength + AddOn)<USEEPS;
    }
    else
    {
        MBTi new_iAngle = i_Angle - M_PI;
        MBTi WasLength = (Vert.CycVal(i-1)-Vert[i]).Length2D();
        MBTi fsin = fabs(sin(new_iAngle));
        MBTi AddOn(Value);
        if (fsin > 0.000001)
            AddOn = Value/fsin;
        newVert_i = PointOfLineOnCut( Vert.CycVal(i-1),Vert[i], WasLength - AddOn );
//        i_close = fabs(WasLength - AddOn)<USEEPS;
    }
    
    if (ip1_Angle<M_PI)
    {
        MBTi new_ip1_Angle = M_PI-ip1_Angle;
        MBTi WasLength = (Vert.CycVal(i+1)-Vert.CycVal(i+2)).Length2D();
        MBTi fsin = fabs(sin(new_ip1_Angle));
        MBTi AddOn(Value);
        if (fsin > 0.000001)
            AddOn = Value/fsin;
        newVert_ip1 = PointOfLineOnCut( Vert.CycVal(i+2),Vert.CycVal(i+1), WasLength + AddOn );
//        ip1_close = fabs(WasLength + AddOn)<USEEPS;
    }
    else
    {
        MBTi new_ip1_Angle = ip1_Angle - M_PI;
        MBTi WasLength = (Vert.CycVal(i+1)-Vert.CycVal(i+2)).Length2D();
        MBTi fsin = fabs(sin(new_ip1_Angle));
        MBTi AddOn(Value);
        if (fsin > 0.000001)
            AddOn = Value/fsin;
        newVert_ip1 = PointOfLineOnCut( Vert.CycVal(i+2),Vert.CycVal(i+1), WasLength - AddOn );
//        ip1_close = fabs(WasLength - AddOn)<USEEPS;
    }
    Vert[i] = newVert_i;
    Vert[ (i+1)%Vert.Count ] = newVert_ip1;
/*    TIntVec* old_i_point = &Vert[i];
    TIntVec* old_ip1_point = &Vert[i+1];
    if (i_close)
        Vert.Remove(old_i_point);
    if (ip1_close)
        Vert.Remove(old_ip1_point);   */
}

int TPolygon::ConsistsPoint(const TIntVec& Point,MBTi USEEPS)
{
    int parity = 0;
    for (int i=0;i<Vertex->Count;i++)
    {
        switch (EdgeType(Point,*(Vertex->CycleItems[i]),*(Vertex->CycleItems[i+1]),USEEPS))
        {
            case ettTOUCHING:
                return pipBOUNDARY;
            case ettCROSSING:
                parity = 1 - parity;
        }
    }
    return (parity ? pipINSIDE : pipOUTSIDE);
}

TIntVec TPolygon::AnyPoint(MBTi STEP)
{
    TMDelTList<TIntVec>& Vert = *Vertex;
    MBTi Angle = (AngleRad( Vert.CycVal(-1), Vert[0], Vert.CycVal(1),MBTi_EPS )*180 )/M_PI;
    TIntVec NewPoint = RotateAround(Vert.CycVal(-1),TIntVec(0,0,-Angle/2),Vert[0]);
    return PointOfLineOnCut(Vert[0],NewPoint,STEP);
}

bool TPolygon::CrossedWithPolygon(TPolygon* ElsePol,MBTi USEEPS)
{
    TMDelTList<TIntVec>& Vert0 = *(Vertex);
    TMDelTList<TIntVec>& Vert1 = *(ElsePol->Vertex);
    if (Vert0.Count==0 || Vert1.Count==0)
        return false;
    TIntVec CP;
    for (int i=0;i<Vert0.Count;i++)
        for (int j=0;j<Vert1.Count;j++)
        {
           /* int res1 = Classify(Vert0[i],Vert1[j],Vert1.CycVal(j+1),USEEPS);
            int res2 = Classify(Vert0.CycVal(i+1),Vert1[j],Vert1.CycVal(j+1),USEEPS);
            if ( (res1 != etLEFT || res2 != etRIGHT) && (res1 != etRIGHT || res2 != etLEFT))
                continue;
            res1 = Classify(Vert1[j],Vert0[i],Vert0.CycVal(i+1),USEEPS);
            res2 = Classify(Vert1.CycVal(j+1),Vert0[i],Vert0.CycVal(i+1),USEEPS);
            if ( (res1 != etLEFT || res2 != etRIGHT) && (res1 != etRIGHT || res2 != etLEFT))
                continue;  */
            int res = IsCutsCrossed(Vert0[i],Vert0.CycVal(i+1),Vert1[j],Vert1.CycVal(j+1),CP,USEEPS);
            if (res == lcNONE)
                continue;
            if (  (res == lcCOLLINEAR || res == lcPARALLEL) && !IsCutsCollinearAndCrossing(Vert0[i],Vert0.CycVal(i+1),Vert1[j],Vert1.CycVal(j+1),USEEPS))
                continue;
            return true;
        }
    return (ConsistsPoint(ElsePol->AnyPoint(0.2),USEEPS) != pipOUTSIDE) || (ElsePol->ConsistsPoint(AnyPoint(0.2),USEEPS) != pipOUTSIDE) ;
}

int TPolygon::ConsistsPolygon(TPolygon* ElsePol)
{
    //working only inside or outside
    int CountBOUNDARY=0;
    int CountINSIDE=0;
    int CountOUTSIDE=0;
    for (int i=0;i<ElsePol->Vertex->Count;i++)
    {
        switch (ConsistsPoint(*(ElsePol->Vertex->Items[i]),INTEPS))
        {
            case pipBOUNDARY:
                CountBOUNDARY++;
                break;
            case pipINSIDE:
                CountINSIDE++;
                break;
            case pipOUTSIDE:
                CountOUTSIDE++;
                break;
        }
    }
    if (CountINSIDE&&CountOUTSIDE)
        return(p_pCROSSING);
    if (CountINSIDE)
        return(p_pINSIDE);
    if (CountOUTSIDE)
        return(p_pOUTSIDE);
    //все точки граничные
    //теперь надо проверить одну внутреннюю точку Elsepol
    TIntVec ElseCenter = ElsePol->Center();
    switch (ConsistsPoint(ElseCenter,INTEPS))
    {
        case pipINSIDE:
          return(p_pINSIDE);
        case pipOUTSIDE:
          return(p_pOUTSIDE);
        default:
          throw (EMyException("Incorrect belong to point"));
    }
}

bool TPolygon::ExistsVertex(const TIntVec& V,TIntVec D)
{
    for (int i=0;i<Vertex->Count;i++)
        if ( V.XYZ_Multiply(D).Equal(Vertex->Val(i).XYZ_Multiply(D),_MBTi_eps_)  )
            return(true);
    return(false);
}

TIntVec TPolygon::MIN()
{
    TIntVec Vec = TIntVec(1<<30,1<<30,1<<30);
    for (int i=0;i<Vertex->Count;i++)
        for (int j=0;j<3;j++)
            if (Vec.a[j]>Vertex->Items[i]->a[j])
                Vec.a[j] = Vertex->Items[i]->a[j];
    return(Vec);
}

TIntVec TPolygon::MAX()
{
    TIntVec Vec = TIntVec((-1)*(1<<30),(-1)*(1<<30),(-1)*(1<<30));
    for (int i=0;i<Vertex->Count;i++)
        for (int j=0;j<3;j++)
            if (Vec.a[j]<Vertex->Items[i]->a[j])
                Vec.a[j] = Vertex->Items[i]->a[j];
    return(Vec);
}

void TPolygon::Assign(TMyObject *MO)
{
    if (NotInstanced)
        throw EMyException("<TPolygon::Assign()>: Полигон is read only!");
    if ( typeid(*MO) == typeid(TPolygon) || typeid(*MO) == typeid(THoledPolygon) )
    {
        TPolygon* P = (TPolygon*)MO;
        Vertex->Clear();
        for (int i=0;i<P->Vertex->Count;i++)
            Vertex->Add( new TIntVec( *(P->Vertex->Items[i]) ) );
    }
    else
        throw EMyException("Assign incorrect type.");
}

TPolygon& TPolygon::operator =(TPolygon& Pol)
{
    Assign(&Pol);
    return *this;
}

TIntVec TPolygon::Center()
{
    TIntVec MIN = TIntVec(1<<20,1<<20,1<<20);
    TIntVec MAX = MIN*(-1);

    if (Vertex->Count == 0)
        return ZEROINTVEC;
    for (int i=0;i<Vertex->Count;i++)
    {
        UpdateMinVector(MIN,*(Vertex->Items[i]));
        UpdateMaxVector(MAX,*(Vertex->Items[i]));
    }
    return((MIN+MAX)/2);
}

int TPolygon::IntrudeRib(int i, MBTi Value, MBTi USEEPS)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::IntrudeRib()>: Полигон is read only!");
    TMDelTList<TIntVec>& vVertex = *Vertex;
    if (vVertex.Count<3)
        return psNoPoints;
    if ( IsLinesCollinear(*(vVertex.CycleItems[i-1]),vVertex[i],vVertex[i],*(vVertex.CycleItems[i+1]),USEEPS) ||
         IsLinesCollinear(vVertex[i],*(vVertex.CycleItems[i+1]),*(vVertex.CycleItems[i+1]),*(vVertex.CycleItems[i+2]),USEEPS))
         return psCollinear;
    TIntVec EdgeNormal = *(vVertex.CycleItems[i+1]) - vVertex[i];
    MBTi EdgeLength = EdgeNormal.Length2D();
    if ( EdgeLength < _MBTi_eps_)
        return psTooCloseEdges;
    EdgeNormal /= EdgeLength;
    TIntVec OrthoEdgeNormal(-EdgeNormal.y,EdgeNormal.x,0);
    TIntVec P0 = vVertex[i] + OrthoEdgeNormal;
    TIntVec P1 = *(vVertex.CycleItems[i+1]) + OrthoEdgeNormal;
    P0 = PointOfLineOnCut(vVertex[i],P0,Value);
    P1 = PointOfLineOnCut(*(vVertex.CycleItems[i+1]),P1,Value);

    TIntVec CP1,CP2;
    int res1 = IsLinesCrossedExactly(P0,P1,*(vVertex.CycleItems[i-1]),vVertex[i],CP1);
    int res2 = IsLinesCrossedExactly(P0,P1,*(vVertex.CycleItems[i+1]),*(vVertex.CycleItems[i+2]),CP2);

    if ( res1!=lcNONE && res1!=lcPARALLEL && res1!=lcCOLLINEAR && res2!=lcNONE && res2!=lcPARALLEL && res2!=lcCOLLINEAR)
    {
        vVertex[i] = CP1;
        *(vVertex.CycleItems[i+1]) = CP2;
        return psOK;
    }
    else
        return psNoCrossPoints; 
}

void TPolygon::Move(const TIntVec& _Move)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Move()>: Полигон is read only!");
    for (int i=0;i<Vertex->Count;i++)
        (*(Vertex->Items[i])) += _Move;
}

void TPolygon::Rotate(const TIntVec &Angle,const TIntVec &Center)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Rotate()>: Полигон is read only!");
    for (int i=0;i<Vertex->Count;i++)
        RotateAround(*(Vertex->Items[i]),Angle,Center);
}

TIntVec* TPolygon::GetPoint(int i)
{
    return Vertex->Items[i];
}

TIntVec* TPolygon::GetCyclePoint(int i)
{
    return Vertex->CycleItems[i];
}


void TPolygon::Insert(int index,TIntVec* Item)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Insert()>: Полигон is read only!");
    Vertex->Insert(index,Item);
}

void TPolygon::Set(int axes,MBTi Value)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::Set()>: Полигон is read only!");
    for (int i=0;i<Vertex->Count;i++)
        Vertex->Items[i]->a[axes] = Value;
}


double TPolygon::TriangleArea()
{
    if (Vertex->Count!=3)
    {
        Application->MessageBox("Triangle with two points","Error");
        return 0;
    }
    if (*(Vertex->Items[1])==*(Vertex->Items[2])||*(Vertex->Items[1])==*(Vertex->Items[0]))
    {
        Application->MessageBox("Equal points in triangle","Error");
        return 0;
    }
    return ( (*Vertex->Items[1]-*Vertex->Items[2])*(*Vertex->Items[1]-*Vertex->Items[3]) ).Length()/2;
}

double TPolygon::CentralArea()
{
    double S=0;
    double dx;
    double dy;
    for (int i=0;i<Vertex->Count;i++)
    {
        dx = Vertex->Items[i]->x+Vertex->CycleItems[i+1]->x;
        dy = Vertex->Items[i]->y-Vertex->CycleItems[i+1]->y;
        S=S+dx*dy;
    }
    return fabs(S/2);
}

bool TPolygon::IsConvex(MBTi USEEPS)
{
    for (int i=0;i<Vertex->Count;i++)
        if (!RibIsConvex(i,USEEPS))
            return false;
    return true;
}

bool TPolygon::PointIsConvex(int index,MBTi USEEPS)
{
    return (RibIsConvex(index,USEEPS) && RibIsConvex((index+Vertex->Count-1)%Vertex->Count,USEEPS));
}

bool TPolygon::RibIsConvex(int index,MBTi USEEPS)
{
    TMDelTList<TIntVec>& Vert = *Vertex;
    int CountLeft = 0;
    int CountRight = 0;
    int indexplus1 = (index+1)%Vert.Count;
    for (int i=0;i<Vert.Count;i++)
        if ( i!=index && i!= indexplus1 )
            switch ( Classify( Vert[i],Vert[index],Vert[indexplus1],USEEPS ) )
            {
                case etLEFT:
                    CountLeft++;
                break;
                case etRIGHT:
                    CountRight++;
                break;
            };
    return (CountLeft*CountRight == 0);
}

void TPolygon::ToConvex(MBTi USEEPS)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::ToConvex()>: Полигон is read only!");
    bool WasDelete = true;
    while (WasDelete)
    {
        if (Vertex->Count<=3)
            return;
        WasDelete = false;
        for (int i=0;i<Vertex->Count;i++)
        {
            if ( !RibIsConvex(i,USEEPS) )
            {
                if ( !RibIsConvex((i+1)%Vertex->Count,USEEPS) )
                {
                    Vertex->Delete((i+1)%Vertex->Count);
                    WasDelete = true;
                    break;
                }
                else if ( !RibIsConvex((i+Vertex->Count-1)%Vertex->Count,USEEPS) )
                {
                    Vertex->Delete(i);
                    WasDelete = true;
                    break;
                }
            }
        }
    }
    KillCollinear_1 (USEEPS);
}

void TPolygon::ToConvexAndExtrude(MBTi USEEPS,MBTi Value)
{
//    if (NotInstanced)
  //      throw EMyException("<TPolygon::ToConvexAndExtrude()>: Полигон is read only!");
    ToConvex(USEEPS);
    if (Vertex->Count<3)
        return;
    TMDelTList<TIntVec>& Vert = *Vertex;
    TMDelTList<MBTi> Angles;
    for (int i=0;i<Vert.Count;i++)
        Angles.Add( new MBTi( (AngleRad(Vert.CycVal(i+1),Vert[i],Vert.CycVal(i-1),USEEPS)*180)/M_PI ) );

    TMDelTList<TIntVec> NewPoints;
    for (int i=0;i<Vert.Count;i++)
        NewPoints.Add( new TIntVec( RotateAround(Vert.CycVal(i+1),TIntVec(0,0,-Angles[i]/2),Vert[i]) ) );

    TMDelTList<MBTi> STEPS;
    for (int i=0;i<Vert.Count;i++)
    {
        if ( fabs(Angles[i]/2 - 90) >_MBTi_eps_)
            STEPS.Add( new MBTi( Value/fabs(cos( ((Angles[i]/2 - 90)*M_PI)/180 )) ) );
        else
            STEPS.Add( new MBTi(Value) );
    }

    for (int i=0;i<Vert.Count;i++)
        Vert[i] = PointOfLineOnCut(Vert[i],NewPoints[i],STEPS[i]);
}


double THoledPolygon::CentralArea()
{
    double S=TPolygon::CentralArea();
    for (int i=0;i<Holes->Count;i++)
        S = S - Holes->Items[i]->CentralArea();
    return S;
}


void THoledPolygon::Assign(TMyObject *MO)
{
    if (MO == NULL)
        return;
    if (typeid(*MO) == typeid(THoledPolygon) )
    {
        THoledPolygon* P = (THoledPolygon*)MO;
        Holes->Clear();
        TPolygon::Assign(P);
        for (int i=0;i<P->Holes->Count;i++)
        {
            TPolygon* p = new TPolygon();
            p->Assign(P->Holes->Items[i]);
            Holes->Add(p);
        }
    }
    else if (typeid(*MO) == typeid(TPolygon))
    {
        TPolygon* P = (TPolygon*)MO;
        TPolygon::Assign(P);
    }
    else
        throw EMyException("Assign incorrect type.");

}

THoledPolygon& THoledPolygon::operator =(THoledPolygon& HP)
{
    Assign(&HP);
    return *this;
}


bool THoledPolygon::Valid(MBTi USEEPS)
{
    if (!TPolygon::Valid(USEEPS))
        return false;
    for (int i=0;i<Holes->Count;i++)
        if (!Holes->Items[i]->Valid(USEEPS))
            return false;
    return true;
}

THoledPolygon::THoledPolygon()
{
    RegisterNewClass< TPolygon, THoledPolygon >(this,false,&CreateFunction);
    Holes = new /*TMDelLSTList*/TMDelTList<TPolygon>();
    RegisterField(Holes,&aHoles,mtMyObject);
};

THoledPolygon::~THoledPolygon()
{
    delete Holes;
};

THoledPolygon::THoledPolygon(TMTList<TIntVec>* PNTS)
    :TPolygon(PNTS)
{
    RegisterNewClass< TPolygon, THoledPolygon >(this,false,&CreateFunction);
    Holes = new /*TMDelLSTList*/TMDelTList<TPolygon>();
//    RegisterField(Holes,&aHoles,mtMyObject);
}

void THoledPolygon::Move(const TIntVec& _Move)
{
    TPolygon::Move(_Move);
    for (int i=0;i<Holes->Count;i++)
        Holes->Items[i]->Move(_Move);
}

void THoledPolygon::Rotate(const TIntVec &Angle,const TIntVec &Center)
{
    TPolygon::Rotate(Angle,Center);
    for (int i=0;i<Holes->Count;i++)
        Holes->Items[i]->Rotate(Angle,Center);
}

void THoledPolygon::Set(int axes,MBTi Value)
{
    TPolygon::Set(axes,Value);
    for (int i=0;i<Holes->Count;i++)
        Holes->Items[i]->Set(axes,Value);
}

int THoledPolygon::ConsistsPoint_UseHoles(const TIntVec &Point,MBTi USEEPS)
{
    int result = ConsistsPoint(Point,USEEPS);
    if (result != pipINSIDE)
        return result;
    for (int i=0;i<Holes->Count;i++)
    {
       int result_hole = Holes->Items[i]->ConsistsPoint(Point,USEEPS);
       if ( result_hole == pipINSIDE)
            return pipOUTSIDE;
       if ( result_hole == pipBOUNDARY)
            return pipHOLEBOUNDARY;
    }
    return pipINSIDE;
}

TMyObject* THoledPolygon::CreateFunction()
{
    return new THoledPolygon();
}

void THoledPolygon::GetCrossPoints_UseHoles(    const TIntVec& P1,
                                                const TIntVec& P2,
                                                TMDelTList<TIntVec>* PointList,
                                                bool UseLinePoints,
                                                bool Edge,
                                                bool HoleEdge,
                                                MBTi USEEPS)
{
    TMDelTList<TIntVec>& Vert = *(Vertex);
    TMDelTList<TIntVec>& PList = *(PointList);
    PList.Clear();

    if (UseLinePoints)
        PList.Add(new TIntVec(P1));
        
    TIntVec CrossPoint;
    //Найти пересечения
    for (int i=0;i<Vert.Count;i++)
        switch( IsCutsCrossed(P1,P2,Vert[i],Vert[(i+1)%Vert.Count],CrossPoint,USEEPS) )
        {
            //если равны то общие точки  в i и в i+1
            case lcEQUAL:
                continue;
            case lcCOMMONPOINT:
            case lcCROSSING:
                PList.Add(new TIntVec(CrossPoint.x,CrossPoint.y,0));
        };

    //Найти пересечения с дырами
    for (int h=0;h<Holes->Count;h++)
        for (int i=0;i<Holes->Items[h]->Vertex->Count;i++)
            switch( IsCutsCrossed(P1,P2,*(Holes->Items[h]->Vertex->Items[i]),*(Holes->Items[h]->Vertex->CycleItems[i+1]),CrossPoint,USEEPS) )
            {
                //если равны то общие точки  в i и в i+1
                case lcEQUAL:
                    continue;
                case lcCOMMONPOINT:
                case lcCROSSING:
                    PList.Add(new TIntVec(CrossPoint.x,CrossPoint.y,i));
            };


    if (UseLinePoints)
        PList.Add(new TIntVec(P2));

    //повернем для упорядочивания
    MBTi AngleOX = (AngleRadOX(P1,P2,USEEPS)*180)/M_PI;
    TIntVec Angle3D = TIntVec(0,0,-AngleOX);
    if (PList.Count == 0 )
        return;
    TIntVec RotPoint = PList[0];
    for (int i=0;i<PList.Count;i++)
        PList[i] = RotateAround(PList[i],Angle3D,RotPoint);

    //Точки упорядочить
    PList.Sort(SortByX);

    //откинем близкие
    bool Was_Delete = true;
    while (Was_Delete)
    {
        Was_Delete = false;
        for (int i=0;i<PList.Count-1;i++)
            if (fabs(PList[i].x-PList[i+1].x)<USEEPS)
            {
                PList.Delete(i);
                Was_Delete = true;
                break;
            }
    }

    Angle3D.z = - Angle3D.z;
    for (int i=0;i<PList.Count;i++)
        PList[i] = RotateAround(PList[i],Angle3D,RotPoint);

    if (PList.Count == 0)
        return;
    if (PList.Count == 1)
    {
        PList.Clear();
        return;
    }
    //развернем список в изначальное положение
//    if ( (PList[0]-P1).Length2D() > (PList[PList.Count-1]-P1).Length2D() )
//        PList.Invert();

    //посмотрим на принадлежность 1 отрезок принадлежит -1 нет 0 неизвестно
    TMDelTList<int> Status;
    TIntVec Point;

    for (int i=0;i<PList.Count-1;i++)
    {
        Point =  PList[i] + (PList[i+1]-PList[i])/2;
        switch (ConsistsPoint_UseHoles(Point,USEEPS))
        {
            case pipINSIDE:
                Status.Add(new int(1) );
            break;
            case pipOUTSIDE:
                Status.Add( new int(-1) );
            break;
            case pipBOUNDARY:
                Status.Add( new int(Edge) );
            break;
            case pipHOLEBOUNDARY:
                Status.Add( new int(HoleEdge) );
            break;
        }
    }

    Was_Delete = true;
    while (Was_Delete)
    {
        Was_Delete = false;
        for (int i=0;i<Status.Count-1;i++)
            if (Status[i] == Status[i+1])
            {
                Status.Delete(i+1);
                PList.Delete(i+1);
                Was_Delete = true;
                break;
            }
    }
    if (PList.Count==0)
        return;
    if (PList.Count==1)
    {
        PList.Clear();
        return;
    }
    if (Status[0] == -1)
    {
        PList.Delete(0);
        Status.Delete(0);
    }
    if (PList.Count==1)
    {
        PList.Clear();
        return;
    }
    if (Status[Status.Count-1] == -1)
    {
        PList.Delete(PList.Count-1);
        Status.Delete(Status.Count-1);
    }
    if (PList.Count==1)
    {
        PList.Clear();
        return;
    }
    if ( PList.Count % 2 != 0 )
        throw EMyException(MSG_ERR_8);
}

void THoledPolygon::AddHole(TPolygon *newHole,bool Invert)
{
    Holes->Add(new TPolygon());
    Holes->Items[Holes->Count-1]->Assign( newHole );
    if (Invert)
        Holes->Items[Holes->Count-1]->Invert();
}

bool THoledPolygon::ExistsVertex(const TIntVec &P,TIntVec D)
{
    if (TPolygon::ExistsVertex(P,D))
        return(true);
    for (int i=0;i<Holes->Count;i++)
        if (Holes->Items[i]->ExistsVertex(P,D))
            return(true);
    return(false);
}
