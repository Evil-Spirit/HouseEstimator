//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "RoofV.h"
#include "Poligon.h"
#include "math.h"
#include "MyGL.h"
#include "SomeMath.h"
#include "Math.h"
#include "Misc.h"
#include "TGPrimitive.h"
#include "SomeMath.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

MBTi PEPS = 0.0001;				//мера близости точек
MBTi CEPS = 0.0001;				//мера коллинеарности плоскостей
MBTi EEPS = 0.0001;				//общая мера близости 
MBTi ZERO_EPS = 0.000001;       //общая мера близости

/************************************************************************************************************************/
TRoof Roof;

int FindGroup(TMDelTList<TCollinearGroup>& Groups,int index1,int index2)
{
	for (int i=0;i<Groups.Count;i++)
		if ( FindInList( &Groups[i].indices,index1 ) != -1 || FindInList( &Groups[i].indices,index2 ) != -1)
			return i;
	return -1;
}

void TCollinearGroup::InsertPoint(TMDelTList<int> &PntPlane, TGPoint* Pnt,MBTi USEEPS)
{
	for (int i=0;i<indices.Count;i++)
	{
		int indexOf = FindInList(&PntPlane,indices[i]);
		if (indexOf != -1)
			PntPlane.Delete(indexOf);
	}

	//теперь проверим может точка лежит на прямой
	//обозначающей границу коллинеарности
	for (int i=0;i<Edges.Count;i++)
		if (Edges[i].COMMON.IndexOf(Pnt)!=-1)
		{
			//если да то добавляем ДВЕ плоскости в список плоскостей
			//через которые проходит точка
			PntPlane.Add(new int(indices[i]) );
			PntPlane.Add(new int(indices[i+1]) );
			return;
		}
	//точка не лежит на границе
	//теперь однозначно отнесем ее к одной из плоскостей
	//в смысле заданных границ коллинеарности
	TIntVec Intersect;
	int pln = indices.Count-1;
	TIntVec itr;
	for (int i=0;i<Edges.Count;i++)
	{
		TMDelTList<TIntVec> indicesVecs;
		TIntVec dir[2];	
		TIntVec pnt = Pnt->Point;	
		TIntVec normal = Roof.p_Normal[indices[0]];	

		dir[0] = Edges[i].rayDir[0];
		dir[1] = Edges[i].rayDir[1];

		MBTi Angle = (AngleRadOX(Roof.GetVertex(Roof.p_Slope[indices[0]]).Point, Roof.GetVertex( (Roof.p_Slope[indices[0]] + 1) % Roof.p_Roof.Count ).Point)*180)/M_PI;
		TIntVec Angle3D = TIntVec(0,0,-Angle);
		for (int m=0;m<Edges[i].sepPoint.Count;m++)
			indicesVecs.Add(new TIntVec(Edges[i].sepPoint[m].Point));
		TIntVec RotPoint = Edges[0].sepPoint[0].Point;
		for (int m=0;m<indicesVecs.Count;m++)
			indicesVecs[m] = RotateAround(indicesVecs[m],Angle3D,RotPoint);
		pnt = RotateAround(pnt,Angle3D,RotPoint);
		dir[0] = RotateAround(dir[0],Angle3D,TIntVec(0,0,0));
		dir[1] = RotateAround(dir[1],Angle3D,TIntVec(0,0,0));
		normal = RotateAround(normal,Angle3D,TIntVec(0,0,0)); 
		
		if (normal.z<0) 
			Angle = (acosDC(normal.z) + M_PI)*180/M_PI;
		else
			Angle = acosDC(normal.z)*180/M_PI;
				
		Angle3D = TIntVec(-Angle,0,0);

		for (int m=0;m<indicesVecs.Count;m++)
			indicesVecs[m] = RotateAround(indicesVecs[m],Angle3D,RotPoint);
		pnt = RotateAround(pnt,Angle3D,RotPoint);
		dir[0] = RotateAround(dir[0],Angle3D,TIntVec(0,0,0));
		dir[1] = RotateAround(dir[1],Angle3D,TIntVec(0,0,0));
		normal = RotateAround(normal,Angle3D,TIntVec(0,0,0)); 
		

		int res;
		for (int m=0;m<indicesVecs.Count-1;m++)
			if ((res = IsLinesCrossedFull(pnt, pnt + TIntVec(1,0,0), indicesVecs[m], indicesVecs[m + 1], true, false, true, true, itr, CEPS)) == lcCROSSING || res == lcCOMMONPOINT)
			{
				pln = i;
				break;			
			}
		if ((res = IsLinesCrossedFull(pnt, pnt + TIntVec(1,0,0), indicesVecs[0], indicesVecs[0] + dir[0], true, false, true, false, itr, CEPS)) == lcCROSSING || res == lcCOMMONPOINT)
		{
			pln = i;
			break;			
		}
		if ( (res = IsLinesCrossedFull(pnt, pnt + TIntVec(1,0,0), *indicesVecs.Last(), *indicesVecs.Last() + dir[1], true, false, true, false, itr, CEPS)) == lcCROSSING || res == lcCOMMONPOINT)
		{
			pln = i;
			break;	  		
		}        
	}
	PntPlane.Add(new int( indices.Val(pln) )); 
}


bool isIntersectPointGood(const TIntVec &pnt, int p1, int p2, int p3, const TIntVec &b_N, const TIntVec &b_O)
{
//	return !(ScalarP(pnt, b_N) < (ScalarP(b_O, b_N) - PEPS));
	
	int p[3];
	p[0] = p1;
	p[1] = p2;
	p[2] = p3;

	for (int i=0;i<3;i++)
	{
		if (Roof.p_Plane[p[i]] == 0)
		{
			if (ScalarP(pnt, b_N) < ScalarP(b_O, b_N) - PEPS*10) return false;
			if (Roof.p_Roof[Roof.p_Slope[p[i]]].Count>1)
				if (pnt.z > Roof.OrgMatrix[p[i]][Roof.p_Roof[Roof.p_Slope[p[i]]][1]].z + PEPS*10) return false;
		}
		else
		if (Roof.p_Plane[p[i]] == Roof.p_Roof[Roof.p_Slope[p[i]]].Count-1)
		{
			if (pnt.z < Roof.OrgMatrix[p[i]][Roof.p_Roof[Roof.p_Slope[p[i]]][Roof.p_Plane[p[i]]-1]].z - PEPS*10) return false;
		}	
		else
		{
			if (pnt.z < Roof.OrgMatrix[p[i]][Roof.p_Roof[Roof.p_Slope[p[i]]][Roof.p_Plane[p[i]]-1]].z - PEPS*10) return false;
			if (pnt.z > Roof.OrgMatrix[p[i]][Roof.p_Roof[Roof.p_Slope[p[i]]][Roof.p_Plane[p[i]]+1]].z + PEPS*10) return false;
		}
	}	
	return true;
}
void AddThreePlanes(TMDelTList<int> &Planes, int p1,int p2,int p3)
{
	bool Exists[3] = {false,false,false};
	for (int i=0;i<Planes.Count;i++)
		if (Planes[i] == p1)
			Exists[0] = true;
		else if(Planes[i] == p2)
			Exists[1] = true;
		else if(Planes[i] == p3)
			Exists[2] = true;
	if (!Exists[0])
		Planes.Add(new int(p1))	;
	if (!Exists[1])
		Planes.Add(new int(p2))	;
	if (!Exists[2])
		Planes.Add(new int(p3))	;
}
void ProcessAddPoint(int i,int j,int k,TGPoint* Pnt)
{
	Roof.PntCube[i][j].Items[k] = Pnt;
	Roof.PntCube[i][k].Items[j] = Pnt;
	Roof.PntCube[j][i].Items[k] = Pnt;
	Roof.PntCube[j][k].Items[i] = Pnt;
	Roof.PntCube[k][j].Items[i] = Pnt;
	Roof.PntCube[k][i].Items[j] = Pnt;
}
/************************************************************************************************************************/

void TRoof::CalculateStatistics(TMDelTList<TPreTriangle> &PRE_TRI)
{
		//расчитываем точки пересечения  у псевдотреугольников
		for (int i=0;i<PRE_TRI.Count;i++)
		if(PRE_TRI[i].Plane < PRE_TRI[i].Planes.Count-1)
		{
				TGPoint *crsPnt = PntCube[PRE_TRI.CycVal(i-1).Planes[PRE_TRI.CycVal(i-1).Plane]][PRE_TRI[i].Planes[PRE_TRI[i].Plane]].Items[PRE_TRI.CycVal(i+1).Planes[PRE_TRI.CycVal(i+1).Plane]];
				PRE_TRI[i].CrossPointLeft  = PntCube[PRE_TRI.CycVal(i-1).Planes[PRE_TRI.CycVal(i-1).Plane]][PRE_TRI[i].Planes[PRE_TRI[i].Plane]].Items[PRE_TRI[i].Planes[PRE_TRI[i].Plane + 1]];
				PRE_TRI[i].CrossPointRight = PntCube[PRE_TRI.CycVal(i+1).Planes[PRE_TRI.CycVal(i+1).Plane]][PRE_TRI[i].Planes[PRE_TRI[i].Plane]].Items[PRE_TRI[i].Planes[PRE_TRI[i].Plane + 1]];
				PRE_TRI[i].IAmTriangle = false;
				if ( crsPnt )
				if ( !PRE_TRI[i].CrossPointLeft || !PRE_TRI[i].CrossPointRight || MAX(PRE_TRI[i].CrossPointLeft->Point.z, PRE_TRI[i].CrossPointRight->Point.z)>crsPnt->Point.z )
				{
						PRE_TRI[i].CrossPointLeft = crsPnt;
						PRE_TRI[i].CrossPointRight = PRE_TRI[i].CrossPointLeft;
						PRE_TRI[i].IAmTriangle = true;
				}

		}
		else
		{
				PRE_TRI[i].CrossPointLeft = PntCube[PRE_TRI.CycVal(i-1).Planes[PRE_TRI.CycVal(i-1).Plane]][PRE_TRI[i].Planes[PRE_TRI[i].Plane]].Items[PRE_TRI.CycVal(i+1).Planes[PRE_TRI.CycVal(i+1).Plane]];
				PRE_TRI[i].CrossPointRight = PRE_TRI[i].CrossPointLeft;
				PRE_TRI[i].IAmTriangle = true;
		//			PRE_TRI[i].Plane++;
		}
		for (int i=0;i<PRE_TRI.Count;i++)
				PRE_TRI[i].amIEvil();

		for (int i=0;i<PRE_TRI.Count;i++)
				PRE_TRI[i].CalcScatProject(PRE_TRI.CycleItems[i-1], PRE_TRI.CycleItems[i+1]);
}

bool TRoof::ProcessGeometry(	TMDelTList< TMDelTList<TIntVec> > &p_N,
								TMDelTList< TMDelTList<TIntVec> > &p_O,
								TIntVec& b_N,
								TIntVec& b_O)
{
	for (int i=0;i<p_N.Count;i++)
		for (int j=0;j<p_N[i].Count;j++)
			p_N[i][j] = p_N[i][j].Normalize();

	int iIndex = 0;
	for (int i=0;i<p_N.Count;i++)
	{

		p_Roof.Add(new TMDelTList <int>);		
		for (int j=0;j<p_N[i].Count;j++)
		{
			p_Normal.Add(&p_N[i][j]);
			p_Origin.Add(&p_O[i][j]);
			p_Slope.Add(new int(i));
			p_Plane.Add(new int(j));
			p_Roof[i].Add(new int(iIndex++));
		}
	}

	TMDelTList< TMDelTList<int> > Parallel;		//Матрица коллинеарности-параллельности (для каждой пары плоскостй)
	//заполнение матриц пустыми значениями
	for (int i=0;i<p_Normal.Count;i++)
	{
		DirMatrix.Add(new TMDelTList<TIntVec>());
		OrgMatrix.Add(new TMDelTList<TIntVec>());
		Parallel.Add(new TMDelTList<int> );
		for (int j=0;j<p_Normal.Count;j++)
		{
			DirMatrix[i].Add( new TIntVec() );
			OrgMatrix[i].Add( new TIntVec() );
			Parallel[i].Add( new int(0) );
		}
	}

	//расчет матрицы нормалей и матрицы коллинеарности
	for (int i=0;i<p_Normal.Count;i++)
		for (int j=i+1;j<p_Normal.Count;j++)
			if ( PlanesCollinear(p_Origin[i], p_Normal[i], p_Origin[j], p_Normal[j], CEPS ))
			{
				DirMatrix[i][j] = ZEROINTVEC;
				DirMatrix[j][i] = DirMatrix[i][j];

				OrgMatrix[i][j] = ZEROINTVEC;
				OrgMatrix[j][i] = OrgMatrix[i][j];

				Parallel[i][j] = 2;
				Parallel[j][i] = 2;
			}
			else if ( PlanesParallel(p_Normal[i],p_Normal[j],CEPS) )
			{
				DirMatrix[i][j] = ZEROINTVEC;
				DirMatrix[j][i] = DirMatrix[i][j];

				OrgMatrix[i][j] = ZEROINTVEC;
				OrgMatrix[j][i] = OrgMatrix[i][j];

				Parallel[i][j] = 1;
				Parallel[j][i] = 1;
			}
			else
			{
				DirMatrix[i][j] = VectorP(p_Normal[i], p_Normal[j]).Normalize();
				DirMatrix[j][i] = DirMatrix[i][j];

				TIntVec n = VectorP(DirMatrix[i][j], p_Normal[i]);

				n = n.Normalize();

				PlaneCrossPoint(p_Origin[j], p_Normal[j], p_Origin[i], p_Origin[i]+ n, OrgMatrix[i][j]);
				OrgMatrix[j][i] = OrgMatrix[i][j];
			}

	//создаем геометрический интерфейс контура
	TPolygon Contour;

	for (int i=0;i<p_Roof.Count;i++)
	{
		TIntVec CUR;
		TIntVec P1 = OrgMatrix[ p_Roof[i][0] ][ p_Roof.CycVal(i-1)[0] ];
		TIntVec P2 = OrgMatrix[ p_Roof[i][0] ][ p_Roof.CycVal(i-1)[0] ] + DirMatrix[p_Roof[i][0]][ p_Roof.CycVal(i-1)[0] ];
		if (!PlaneCrossPoint(b_O, b_N, P1, P2, CUR))
		{	
			InfoMsg("Contour: one of the points is missing!");
			return false;
		}
		else
		{
			Contour.Vertex->Add(new TIntVec(CUR));	
			int point = FVertex.IndexOf(AddPoint(CUR));
			if (point>=PntPlane.Count)
			{
				PntPlane.Add(new TMDelTList <int>);
				PntPlane.Last()->Add(new int(p_Roof[i][0]));
				PntPlane.Last()->Add(new int(p_Roof.CycVal(i-1)[0]));
			}	
			else	
			{
				PntPlane[point].Add(new int(p_Roof[i][0]));
				PntPlane[point].Add(new int(p_Roof.CycVal(i-1)[0]));
			}
		}
	}

	//заполнений списка отрезков отрезками исходного контура крыши

	for (int i=0;i<VertexCount;i++)
		AddCut(&GetVertex(i), &GetVertex((i+1) % VertexCount));

	//инициализируем список пре-трианглов
/*	for (int i=0;i<PRE_TRI.Count;i++)
	{
		TIntVec normal = PRE_TRI[i].TruePointRight->Point - PRE_TRI[i].TruePointLeft->Point;
		MBTi temp;
		temp = normal.x;
		normal.x = normal.y;
		normal.y = -temp;
		TIntVec nxt;
		nxt = PRE_TRI.CycVal(i+1).TruePointRight->Point - PRE_TRI.CycVal(i+1).TruePointLeft->Point;
		Convex.Add(new bool(ScalarP(normal,nxt)<=0));	
	}
*/
	//перескаем не коллинеарные
	//пока только не коллинеарные и не параллельные

	for (int i=0;i<p_Normal.Count;i++)
	{
		for (int j=i+1;j<p_Normal.Count;j++)
		{
			//для каждой пары плоскостей
			//перебираем остальные плоскости и ищем точку пересечения тройи
			if (Parallel[i][j]>=1)
				continue;

			//поиск точки по двум плоскостям

			TIntVec CUR;
			//две точки - прямая пересечения пары плоскостей
			TIntVec P1 = OrgMatrix[i][j];
			TIntVec P2 = OrgMatrix[i][j] + DirMatrix[i][j];
			//теперь полученную прямую пересекаем с остальными плоскостями
			for (int k=j+1;k<p_Normal.Count;k++)
			{
				//понятно здесь только неколллинеарные-непараллельные
				if (Parallel[i][k]>=1 || Parallel[j][k]>=1)
					continue;
				//типа не пересекаются
				//ищем точку пересечения
				int RoofByPoint = -1;
				if ( PlaneCrossPoint2(p_Origin[k], p_Normal[k], P1, P2, CUR, EEPS) == 1 )
				{
					//есть такая точка
					if (isIntersectPointGood(CUR, i, j ,k, b_N, b_O)/* && Contour.ConsistsPoint(CUR, EEPS*100) != pipOUTSIDE*/)
					{
						RoofByPoint = FVertex.IndexOf(AddPoint(CUR));
						if (RoofByPoint>=PntPlane.Count)
						{
							PntPlane.Add(new TMDelTList <int>);
							AddThreePlanes(*PntPlane.Last(), i, j, k);
						}	
						else	
							AddThreePlanes(PntPlane[RoofByPoint], i, j, k);
					}	
				}   
			}
		}
	 }


//заполнение коллинеарных групп         
//сначала происходит просто заполнение
//групп плоскостями, а потом на основе этого инициализация групп

	TMDelTList<TCollinearGroup> Groups;

	for (int i=0;i<p_Normal.Count;i++)
	{
		//в этот список собираем номера коллинеарных плоскостей
		TMDelTList<int> CollinearTo_i;
		for (int j=i+1;j<p_Normal.Count;j++)
			if (Parallel[i][j] == 2)
				CollinearTo_i.Add(new int(j));

		//если список не пуст
		if (CollinearTo_i.Count>0)
		{
			//то осталось внести плоскости в соотв. группу
			//поищем группу
			int gr = FindGroup(Groups,i,-1);
			//если не существует то создадим
			if (gr==-1)
				gr = Groups.Add( new TCollinearGroup() );
			//добавим плоскость i если надо
			if ( FindInList(&Groups[gr].indices,i)==-1 )
				Groups[gr].indices.Add(new int(i));
			//если надо добавим плоскости из списка
			for (int k=0;k<CollinearTo_i.Count;k++)
				if ( FindInList(&Groups[gr].indices,CollinearTo_i[k])==-1 )
					Groups[gr].indices.Add(new int( CollinearTo_i[k] ));
		}
	}
//инициализация групп
	for (int i=0;i<Groups.Count;i++)
		Groups[i].Init(*Contour.Vertex, p_Normal);


//пересекаем коллинеарные
//в соответствии с предположением линией пересечения
//коллинеарных плоскостей является заданны нами граница
//пересекаем такие границы с сотальными плоскостями
	for (int i=0;i<Groups.Count;i++)
		for (int j=0;j<Groups[i].Edges.Count;j++)
			for (int k=0;k<p_Normal.Count;k++)
			{
				if (Groups[i].indices[j] ==k || Groups[i].indices[j+1] == k)
					continue;
				//тем не менее третья плоскость должна быть даже непараллельна
				if ( Parallel[ Groups[i].indices[j] ][k]>=1 || Parallel[ Groups[i].indices[j+1] ][k]>=1)
					continue;

				TIntVec CUR;
				TIntVec P1;
				TIntVec P2;
				bool found = false;
				for (int p = 0;p<Groups[i].Edges[j].sepPoint.Count-1;p++)
				{
					P1 =  Groups[i].Edges[j].sepPoint[p].Point;
					P2 =  Groups[i].Edges[j].sepPoint[p+1].Point;
					if (PlaneAndLineCrossed(p_Origin[k], p_Normal[k], P1, P2, true, true, CUR, CEPS) ==  PL_CROSS_ONEPOINT)
					{
						found = true;
						break;
					}
				}
				if (!found) 
				{
					P1 =  Groups[i].Edges[j].sepPoint[0].Point;
					P2 = P1 +  Groups[i].Edges[j].rayDir[0];
					if (PlaneAndLineCrossed(p_Origin[k], p_Normal[k], P1, P2, true, false, CUR, CEPS) ==  PL_CROSS_ONEPOINT)
						found = true;
				}		
				if (!found) 
				{

					P1 =  Groups[i].Edges[j].sepPoint.Last()->Point;
					P2 = P1 +  Groups[i].Edges[j].rayDir[1];
					if (PlaneAndLineCrossed(p_Origin[k], p_Normal[k], P1, P2, true, false, CUR, CEPS) ==  PL_CROSS_ONEPOINT)
						found = true;
				}
				
				//далее аналогично предыдущему
				int RoofByPoint = -1;
				if ( found )
				{
					if (isIntersectPointGood(CUR, i, j ,k, b_N, b_O) /*&& Contour.ConsistsPoint(CUR, EEPS) != pipOUTSIDE*/)
					{
						RoofByPoint = FVertex.IndexOf(AddPoint(CUR));
						if (RoofByPoint>=PntPlane.Count)
						{
							PntPlane.Add(new TMDelTList <int>);
							AddThreePlanes(*PntPlane.Last(), i, j, k);
						}	
						else	
							AddThreePlanes(PntPlane[RoofByPoint], i, j, k);
					}	
				}
			}
//теперь строгое раскидывание всех точек пересечения
//по областям разделенным границами коллинеарных плоскостей
	for (int i=0;i<PntPlane.Count;i++)
	{
		TMDelTList<int> groupindices;
		//берем точку и пробегая по ее плоскостям
		//смотрим нет ли плоскости из какой нибудь группы коллинеарности
		for (int j=0;j<PntPlane[i].Count;j++)
		{
			int gr = FindGroup(Groups,PntPlane[i][j],-1);
			if (gr!=-1 && FindInList(&groupindices,gr)==-1)
				groupindices.Add(new int(gr));
		}
		//если нашли некоторые группы коллинеарности
		//то запускаем функцию внедрения точки в группу коллинарности
		for(int gr = 0;gr<groupindices.Count;gr++)
			Groups[groupindices[gr]].InsertPoint(Roof.PntPlane[i],&Roof.GetVertex(i),PEPS);
	}

//теперь каждой тройке плоскостей
//поставим в соответствие точку их пересечения
//разумеется в одной точке могут пересекаться три и более плоскостей
//но точка може быть образована как минимум тремя плоскостями

//заполняем PntCube пустыми значениями
	for (int i=0;i<p_Normal.Count;i++)
	{
		PntCube.Add( new TMDelTList<  TMTList<TGPoint>  >() );
		for (int j=0;j<p_Normal.Count;j++)
		{
			PntCube[i].Add( new  TMTList<TGPoint> () );
			for (int k=0;k<p_Normal.Count;k++)
				PntCube[i][j].Add(NULL);
		}
	}

//далее заполняем PntCube
	for (int p=0;p<VertexCount;p++)
		for (int i=0;i<PntPlane[p].Count;i++)
			for (int j=i+1;j<PntPlane[p].Count;j++)
				for (int k=j+1;k<PntPlane[p].Count;k++)
					ProcessAddPoint(PntPlane[p][i],PntPlane[p][j],PntPlane[p][k], &GetVertex(p));

//раскидываем по полигонам отрезки
//исходного контура


	for (int i=0;i<p_Normal.Count;i++)
		POLY.Add(new TMTList <TGCut>);

	for (int i=0;i<p_Roof.Count;i++)
		POLY[ p_Roof[i][0] ].Add(&GetCut(i));

	iIndex = 0;
		
	return true;
}
void TRoof::Clean()
{
//	FreeUnused(fuAll);

	PntCube.Clear();
	DirMatrix.Clear();
	OrgMatrix.Clear();
	PntPlane.Clear();
	p_Normal.Clear();
	p_Origin.Clear();
	p_Roof.Clear();
	p_Slope.Clear();
	p_Plane.Clear();
	PRE_TRI.Clear();
	Convex.Clear();
	POLY.Clear();
}

bool TRoof::BuildRoofRecurrent(TMDelTList<TPreTriangle> &PRE_TRI, TMDelTList<TMTList<TGCut> > &RESULT)
{                                   
	if (!PRE_TRI.Count)
		return true;
	CalculateStatistics(PRE_TRI);

	int minindex = -1;
	for (int i=0;i<PRE_TRI.Count;i++)
	{
		if ( !PRE_TRI[i].iAmNotBad )
			continue;
		if (minindex==-1)
		{
			minindex = i;
			continue;
		}
		
		
		{
			if ( (PRE_TRI[minindex].Length - PRE_TRI[i].Length) > ZERO_EPS )
				minindex = i;
			if (fabs(PRE_TRI[minindex].Length - PRE_TRI[i].Length) <= ZERO_EPS)
				if (PRE_TRI[minindex].Criteria < PRE_TRI[i].Criteria)
					minindex = i;
		}		
	}

	//в случае неожиданного завершения алгоритма
	if (minindex==-1)
	{
		//for (int i=0;i<RESULT.Count;i++)
		   //	for (int j=0;j<RESULT[i].Count;j++)
		   //		RESULT[i][j].RepairCUTS();
		return false;
	}
	TIntVec l1;
	TIntVec l2;
	bool LeftNotEdge = false;
	bool RightNotEdge = false;
	if (PRE_TRI.CycleItems[minindex+1]->CrossPointLeft && !PRE_TRI.CycleItems[minindex+1]->yesIAm)
	{
		TIntVec l1 = (PRE_TRI[minindex].CrossPointRight->Point - PRE_TRI[minindex].TruePointRight->Point).Normalize();
		TIntVec l2 = (PRE_TRI.CycleItems[minindex+1]->CrossPointLeft->Point - PRE_TRI.CycleItems[minindex+1]->TruePointLeft->Point).Normalize();
		RightNotEdge = !(ScalarP(l1, l2)>0);
	}
	if (PRE_TRI.CycleItems[minindex-1]->CrossPointRight && !PRE_TRI.CycleItems[minindex-1]->yesIAm)
	{
		TIntVec l1 = (PRE_TRI[minindex].CrossPointLeft->Point - PRE_TRI[minindex].TruePointLeft->Point).Normalize();
		TIntVec l2 = (PRE_TRI.CycleItems[minindex-1]->CrossPointRight->Point - PRE_TRI.CycleItems[minindex-1]->TruePointRight->Point).Normalize();
		LeftNotEdge = !(ScalarP(l1, l2)>0);
	}
	if (!LeftNotEdge && !RightNotEdge)
	{
		ProcessPreTriangle(minindex, PRE_TRI, RESULT);
		return BuildRoofRecurrent(PRE_TRI,RESULT);
	}
	else
	{
		int startindex = (minindex+PRE_TRI.Count-1)%PRE_TRI.Count;
		if (RightNotEdge)
			startindex = (minindex+PRE_TRI.Count)%PRE_TRI.Count;

		TMDelTList<int> indices;
		for (int i = startindex;i<2+startindex;i++)
			if (PRE_TRI.CycleItems[i]->CrossPointRight && PRE_TRI.CycleItems[i]->CrossPointLeft && !PRE_TRI.CycleItems[i]->yesIAm)
				indices.Add(new int( i%PRE_TRI.Count ));
		if (!indices.Count)
		{
			InfoMsg("indices.Count == 0!");
			return false;
		}
		TMDelTList< TMDelTList<TPreTriangle> > PRE_TRI_S;
		TMDelTList<TMDelTList<TMTList<TGCut> > > RESULT_S;
		TMDelTList<bool> res;
		TMDelTList<MBTi> len;
		for (int i=0;i<indices.Count;i++)
		{
			PRE_TRI_S.Add(new TMDelTList<TPreTriangle>);
			RESULT_S.Add(new TMDelTList<TMTList<TGCut> >);
			res.Add(new bool(false));
			len.Add(new MBTi(0));
			PRE_TRI_S.Last()->Assign(&PRE_TRI);
			RESULT_S.Last()->Assign(&RESULT);
			ProcessPreTriangle( indices[i] , PRE_TRI_S[i], RESULT_S[i]);
			res[i] = BuildRoofRecurrent(PRE_TRI_S[i],RESULT_S[i]);
			for (int j=0;j<RESULT_S[i].Count;j++)
				for (int k=0;k<RESULT_S[i].Count;k++);
//!!!!				len[i] += RESULT_S[i][j][k].cutsLength();
		}
		for (int i=0;i<indices.Count;i++)
			if (!res[i])
			{
			  PRE_TRI_S.Delete(i);
			  RESULT_S.Delete(i);
			  res.Delete(i);
			  len.Delete(i);
			  indices.Delete(i);
			  i--;
			}
		int newminindex = -1;
		for (int i=0;i<indices.Count;i++)
			if (newminindex==-1 || len[newminindex]>len[i])
				newminindex = i;

		if (newminindex == -1)
			return false;
		else
		{
			RESULT.Assign(&RESULT_S[newminindex]);
			return true;
		}

   }
}

bool TRoof::Build(	TMDelTList< TMDelTList<TIntVec> > &p_N,
					TMDelTList< TMDelTList<TIntVec> > &p_O,
					TIntVec& b_N,
					TIntVec& b_O)
{
	if (!Roof.ProcessGeometry( p_N, p_O, b_N, b_O ))
	{
		InfoMsg("Couldn't calculate roof geometry!");	
		return false;
	}
	int iIndex = 0;
	for (int i=0;i<p_N.Count;i++)
	{
		PRE_TRI.Add(new TPreTriangle);
		PRE_TRI[i].Slope = i;
		for (int j=0;j<p_N[i].Count;j++)
			PRE_TRI[i].Planes.Add(new int(iIndex++));
	}
	for (int i=0;i<p_Roof.Count;i++)
	{
		PRE_TRI[i].TruePointLeft	= &GetVertex(i);
		PRE_TRI[i].TruePointRight	= &GetVertex((i+1) % p_Roof.Count);
	}
	bool ret = BuildRoofRecurrent(PRE_TRI, POLY);
	if (ret)
	{
		for(int i=0;i<POLY.Count;i++)
		{
//			SortCutsByConnect(POLY[i]);
			if (AddPolygon(POLY[i]) == NULL)
			{
				TMTList<TGCut> cuts;

				TGPoint *p1 = AddPoint(TIntVec(0,0,0));
				TGPoint *p2 = AddPoint(TIntVec(1,1,0));
				TGPoint *p3 = AddPoint(TIntVec(1,-1,0));

				cuts.Add(AddCut(p1,p2));
				cuts.Add(AddCut(p2,p3));
				cuts.Add(AddCut(p3,p1));
				AddPolygon(cuts)->Tag = 0xFF;
			}
		}
	}
	return ret;
}

void ConstructRoof(
				TMDelTList< TMDelTList<TIntVec> > &p_N,
				TMDelTList< TMDelTList<TIntVec> > &p_O,
				TIntVec& b_N,
				TIntVec& b_O,
				TGeomObject &O
				)
{
	Roof.Clear();
	Roof.Clean();

	Roof.Build(p_N, p_O, b_N, b_O);

	Roof.Clean();
	O.Assign(&Roof);
	Roof.Clear();
}

class TLuaRoofCut
{

};

void CreateRoof(TMDelTList< TMDelTList<TIntVec> > &p_N,
				TMDelTList< TMDelTList<TIntVec> > &p_O,
				TIntVec& b_N,
				TIntVec& b_O,
				TMDelTList< TMDelTList<TPolygon> >& RES,
				TMDelTList<TLuaRoofCut>& FLEGS,
				TMDelTList<TLuaRoofCut>& FSCATES)
{
	InfoMsg("Not used...");
};

int FindRoofByThreePlane(int i1,int i2, int i3)
{
	//проходим по списку точек и проверяем
	//принадлежат ли ее списку плоскостей заданные плоскости
	for (int i=0;i<Roof.PntPlane.Count;i++)
		if ( (FindInList(&Roof.PntPlane[i],i1)!=-1) && (FindInList(&Roof.PntPlane[i],i2)!=-1)&& (FindInList(&Roof.PntPlane[i],i3)!=-1) )
			return i;
	return -1;
}
//инициализировать границы коллинеарных плоскостей
//если заданы плоскости
//точки и нормали плоскостей переданы в качестве аргументов
void TCollinearGroup::Init(TMTList<TIntVec>& Vert,TMTList<TIntVec>& Norm)
{
		//сортируем индексы плоскостей по
		//соотв. точкам контура
		TMDelTList<TIntVec> indicesVecs;
		for (int i=0;i<indices.Count;i++)
			indicesVecs.Add(new TIntVec(Vert[ Roof.p_Slope[ indices[i] ] ]));
		MBTi AngleOX = (AngleRadOX(Vert[Roof.p_Slope[indices[0]]],Vert[ (Roof.p_Slope[indices[0]]+1)%Vert.Count ])*180)/M_PI;
		TIntVec Angle3D = TIntVec(0,0,-AngleOX);
		TIntVec RotPoint = indicesVecs[0];
		for (int i=0;i<indicesVecs.Count;i++)
			indicesVecs[i] = RotateAround(indicesVecs[i],Angle3D,RotPoint);
		bool WasChanged = true;
		while(WasChanged)
		{
			WasChanged = false;
			for (int i=0;i<indices.Count-1;i++)
				if (indicesVecs[i].x>indicesVecs[i+1].x)
				{
					WasChanged = true;
					TIntVec Vec = indicesVecs[i];
					indicesVecs[i] = indicesVecs[i+1];
					indicesVecs[i+1] = Vec;
					int buf = indices[i];
					indices[i] = indices[i+1];
					indices[i+1] = buf;
				}
		}
	for (int i=0;i<indices.Count-1;i++)
	{	
		Edges.Add(new TCollinearEdge);
		if (Roof.p_Plane[indices[i]]==0) 
			Edges.Last()->sepPoint.Add(&Roof.GetVertex( (Roof.p_Slope[indices[i]] + 1)%Vert.Count  ));
		for (int u = 0;u<Roof.p_Roof.CycVal(Roof.p_Slope[indices[i]] + 1).Count-1;u++)
		{
			int pnt = FindRoofByThreePlane(
				indices[i], 
				Roof.p_Roof.CycVal( Roof.p_Slope[indices[i]] + 1)[u], 
				Roof.p_Roof.CycVal( Roof.p_Slope[indices[i]] + 1 ).CycVal( u+1 ) );
			Edges.Last()->sepPoint.Add(&Roof.GetVertex(pnt));
		}
		Edges.Last()->rayDir[0] = Roof.DirMatrix[indices[i]][Roof.p_Roof.CycVal(Roof.p_Slope[indices[i]] + 1)[0]];
		Edges.Last()->rayDir[1] = Roof.DirMatrix[indices[i]][*Roof.p_Roof.CycVal(Roof.p_Slope[indices[i]] + 1).Last()];
		if (Edges.Last()->rayDir[0].z>0)
			Edges.Last()->rayDir[0] = Edges.Last()->rayDir[0]*(-1);
		if (Edges.Last()->rayDir[1].z<0)
			Edges.Last()->rayDir[1] = Edges.Last()->rayDir[1]*(-1);
	}
}
/*
//добавляем в КУБ точек очереную точку
//формируя зависимость три плоскости - пересечения
// i < j < k 

//рассчитать критерий для псевдотреугольника
*/
void TPreTriangle::amIEvil()
{
	yesIAm = false;
	if (CrossPointRight == TruePointLeft || CrossPointRight == TruePointRight)
	{
//        InfoMsg(AnsiString("The CrossPoint == TruePointLeft\nPlane: ")+IntToStr(Plane));
		yesIAm = true;
	}
	if (CrossPointRight == TruePointRight || CrossPointRight == TruePointLeft )
	{
//        InfoMsg(AnsiString("The CrossPoint == TruePointRight\nPlane: ")+IntToStr(Plane));
		yesIAm = true;
	}
}

void TPreTriangle::CalcScatProject(TPreTriangle *left, TPreTriangle *right)
{
	iAmNotBad = true;
	if (!CrossPointRight || !CrossPointLeft || yesIAm)
		iAmNotBad = false;
	else
		iAmNotBad = !(IAmBadLeft(left)||IAmBadRight(right));

	if(iAmNotBad)
	{
		Length = MIN(CrossPointLeft->Point.z, CrossPointRight->Point.z);//(TruePointRight->Point - CrossPoint->Point).Length() + (TruePointLeft->Point - CrossPoint->Point).Length();
		Criteria = fabs( Roof.p_Normal[ Planes[Plane] ].z);
	}
}
/*
//функция реализует выбранный псевдотреугольник
//по соответствующим скатам
//соответствующим в смысле соответствующий псевдотреугольнику,
//а также левый и правый от него
*/
void TRoof::DivideTriangle( TMDelTList<TPreTriangle>& PRE_TRI,int index,TMDelTList<TMTList <TGCut> > &RP )
{
	//работаем с левой стороной псевдотреугольника

	if (ExistsCut(PRE_TRI[index].TruePointLeft, PRE_TRI[index].CrossPointLeft)==NULL && 
		PRE_TRI[index].TruePointLeft != PRE_TRI[index].CrossPointLeft)
	{
		//отрезок еще не встречался значит создаем его
		TGCut *ct = AddCut( PRE_TRI[index].TruePointLeft, PRE_TRI[index].CrossPointLeft );
		RP[p_Roof[PRE_TRI[index].Slope][PRE_TRI[index].Plane]].Add(ct);
		RP[p_Roof[PRE_TRI.CycVal(index-1).Slope][PRE_TRI.CycVal(index-1).Plane]].Add(ct);
	}                                       

	//работаем с правой стороной псевдотреугольника

	if (ExistsCut(PRE_TRI[index].TruePointRight, PRE_TRI[index].CrossPointRight)==NULL && 
		PRE_TRI[index].TruePointRight != PRE_TRI[index].CrossPointRight)
	{
		//отрезок еще не встречался значит создаем его
		TGCut *ct = AddCut( PRE_TRI[index].TruePointRight, PRE_TRI[index].CrossPointRight );
		RP[p_Roof[PRE_TRI[index].Slope][PRE_TRI[index].Plane]].Add(ct);
		RP[p_Roof[PRE_TRI.CycVal(index+1).Slope][PRE_TRI.CycVal(index+1).Plane]].Add(ct);
	}                                       

	if (PRE_TRI[index].Plane != PRE_TRI[index].Planes.Count-1 )
	{
		//работаем с верхней стороной псевдотреугольника

		if ((ExistsCut(PRE_TRI[index].CrossPointLeft, PRE_TRI[index].CrossPointRight)==NULL)  && 
			PRE_TRI[index].CrossPointLeft != PRE_TRI[index].CrossPointRight)
		{
			
			TGCut *ct = AddCut(PRE_TRI[index].CrossPointLeft, PRE_TRI[index].CrossPointRight);
			RP[p_Roof[PRE_TRI[index].Slope][PRE_TRI[index].Plane]].Add(ct);
			RP[p_Roof[PRE_TRI[index].Slope].CycVal(PRE_TRI[index].Plane+1)].Add(ct);
		}
	}
}

/*
//используется на заключительном этапе работы алгоритма
//когда список отрезков принадлежащих скату
//упорядочивается в контур

//левая сторона длиннее правой стороны левого треугольника
*/
bool TPreTriangle::IAmBadLeft(TPreTriangle* Left)
{
	if (!CrossPointLeft || !CrossPointRight)
		return true;
	else if(!Left->CrossPointRight)
		return false;
	else if(Left->yesIAm)
		return false;
	else
		return ((Left->TruePointRight->Point - Left->CrossPointRight->Point).Length() <
				(TruePointLeft->Point - CrossPointLeft->Point).Length() - ZERO_EPS);
}

//правая сторона длиннее левой стороны правого треугольника
bool TPreTriangle::IAmBadRight(TPreTriangle* Right)
{
	if (!CrossPointLeft || !CrossPointRight)
		return true;
	else if(!Right->CrossPointLeft)
		return false;
	else if(Right->yesIAm)
		return false;
	else
		return((Right->TruePointLeft->Point - Right->CrossPointLeft->Point).Length() <
			   (TruePointRight->Point - CrossPointRight->Point).Length() - ZERO_EPS);
}
void TRoof::ProcessPreTriangle(int minindex, TMDelTList<TPreTriangle> &PRE_TRI, TMDelTList<TMTList<TGCut> > &RESULT)
{
		//определения одинаковых треугольников слева и справа от выбранного
		//таких какие имеют одну точку пересечения
		TMDelTList<int> SameTriangles;
		int i = minindex-1;
		SameTriangles.Add(new int(minindex) );
		while ( PRE_TRI.CycVal(i).CrossPointRight == PRE_TRI.CycVal(i+1).CrossPointLeft  && (i+PRE_TRI.Count)%PRE_TRI.Count!=minindex)
		{
			SameTriangles.Insert(0,new int((i+PRE_TRI.Count)%PRE_TRI.Count));
			i--;
		}
		i = minindex+1;
		while ( PRE_TRI.CycVal(i).CrossPointLeft == PRE_TRI.CycVal(i-1).CrossPointRight && (i%PRE_TRI.Count)!=minindex)
		{
			if ( FindInList(&SameTriangles,(i+PRE_TRI.Count)%PRE_TRI.Count)==-1 )
				SameTriangles.Add(new int(i%PRE_TRI.Count));
			i++;
		}

		//раскидывание отрезков из этих треугольников
		//по соответствующим скатам
/*		bool exit = false;
		for (int j=0;j<SameTriangles.Count;j++)
		{
			int index = SameTriangles[j];
			if ( !Convex.CycVal(index-1) && PRE_TRI[index].CrossPointRight != PRE_TRI[index].CrossPointLeft)
			{
				TGPoint *point = PRE_TRI[index].CrossPointLeft;
				for(int i=0;i<PntCube.Count;i++)
				{
					TGPoint *itr;
					if ((itr = PntCube[PRE_TRI[index].Planes[PRE_TRI[index].Plane]][PRE_TRI.CycVal(index-1).Planes[PRE_TRI.CycVal(index-1).Plane]].Items[i])!=NULL)
					{
						if (itr->Point.z > PRE_TRI[index].TruePointLeft->Point.z+PEPS && itr->Point.z < point->Point.z)
							point = itr;
					}
				}
				if (point!=PRE_TRI[index].CrossPointLeft)
				{
					PRE_TRI[index].CrossPointLeft = point; 
					//работаем с левой стороной псевдотреугольника
					TGCut* cut = GetCut(PRE_TRI[index].TruePointLeft,PRE_TRI[index].CrossPointLeft);
					if (cut==NULL && PRE_TRI[index].TruePointLeft != PRE_TRI[index].CrossPointLeft)
					{
						//отрезок еще не встречался значит создаем его
						Cuts.Add( new TGCut() );
						Cuts.Last()->Src = PRE_TRI[index].TruePointLeft;
						Cuts.Last()->Dst = PRE_TRI[index].CrossPointLeft;
						cut = Cuts.Last();
					}                                       
					if (cut)
					{
						// добавляем отрезок соответствующему скату
						if (RESULT[p_Roof[PRE_TRI[index].Slope][PRE_TRI[index].Plane]].FCuts.IndexOf(cut)==-1 )
							RESULT[p_Roof[PRE_TRI[index].Slope][PRE_TRI[index].Plane]].FCuts.Add(cut);
						// добавляем отрезок левому скату
						if (RESULT[PRE_TRI.CycVal(index-1).Slope][PRE_TRI.CycVal(index-1).Plane].POLSCUT.IndexOf(cut)==-1 )
							RESULT[PRE_TRI.CycVal(index-1).Slope][PRE_TRI.CycVal(index-1).Plane].POLSCUT.Add(cut);
					}
					PRE_TRI[index].TruePointLeft = PRE_TRI[index].CrossPointLeft; 
					PRE_TRI.CycVal(index-1).TruePointRight = PRE_TRI[index].CrossPointLeft; 
					exit = true;
				}
			}

			if ( !Convex[index] && PRE_TRI[index].CrossPointRight!=PRE_TRI[index].CrossPointLeft)
			{
				TRoofPoint *point = PRE_TRI[index].CrossPointRight;
				for(int i=0;i<PntCube.Count;i++)
				{
					TRoofPoint *itr;
					if ((itr = PntCube[PRE_TRI[index].Planes[PRE_TRI[index].Plane]][PRE_TRI.CycVal(index+1).Planes[PRE_TRI.CycVal(index+1).Plane]].Items[i])!=NULL)
					{
						if (itr->Point.z > PRE_TRI[index].TruePointRight->Point.z+PEPS && itr->Point.z < point->Point.z)
							point = itr;
					}
				}
				if (point!=PRE_TRI[index].CrossPointRight)
				{
					PRE_TRI[index].CrossPointRight = point; 
					//работаем с правой стороной псевдотреугольника
					TRoofCut* cut = GetCut(PRE_TRI[index].TruePointRight,PRE_TRI[index].CrossPointRight);
					if (cut==NULL && PRE_TRI[index].TruePointRight != PRE_TRI[index].CrossPointRight)
					{
						//отрезок еще не встречался значит создаем его
						CUTS.Add( new TRoofCut() );
						CUTS.Last()->Src = PRE_TRI[index].TruePointRight;
						CUTS.Last()->Dst = PRE_TRI[index].CrossPointRight;
						cut = CUTS.Last();
					}                                       
					if (cut)
					{
						// добавляем отрезок соответствующему скату
						if (RESULT[PRE_TRI[index].Slope][PRE_TRI[index].Plane].POLSCUT.IndexOf(cut)==-1 )
							RESULT[PRE_TRI[index].Slope][PRE_TRI[index].Plane].POLSCUT.Add(cut);
						// добавляем отрезок правому скату
						if (RESULT[PRE_TRI.CycVal(index+1).Slope][PRE_TRI.CycVal(index+1).Plane].POLSCUT.IndexOf(cut)==-1 )
							RESULT[PRE_TRI.CycVal(index+1).Slope][PRE_TRI.CycVal(index+1).Plane].POLSCUT.Add(cut);
					}
					PRE_TRI[index].TruePointRight = PRE_TRI[index].CrossPointRight; 
					PRE_TRI.CycVal(index+1).TruePointLeft = PRE_TRI[index].CrossPointRight; 
					exit = true;
				}
			}
		}	

		if (exit) return;
*/
		for (int j=0;j<SameTriangles.Count;j++)
			DivideTriangle(PRE_TRI, SameTriangles[j], RESULT);

		//правый треугольник от самого правого и
		//левый от самого левого принимают новые точки

		if (SameTriangles.Count < PRE_TRI.Count)
		{
			PRE_TRI.CycVal(SameTriangles[0]-1).TruePointRight = PRE_TRI.CycVal(SameTriangles[0]).CrossPointLeft;
			PRE_TRI.CycVal(SameTriangles[SameTriangles.Count-1]+1).TruePointLeft = PRE_TRI.CycVal(SameTriangles[SameTriangles.Count-1]).CrossPointRight;
		}
		//треугольники из списка одинаковых треугольников удаляются
		TMTList<TPreTriangle> ToDelete;
		for (int i=0;i<SameTriangles.Count;i++)
			if (PRE_TRI.CycVal(SameTriangles[i]).Plane >= PRE_TRI.CycVal(SameTriangles[i]).Planes.Count-1 || PRE_TRI.CycVal(SameTriangles[i]).CrossPointLeft == PRE_TRI.CycVal(SameTriangles[i]).CrossPointRight)
				ToDelete.Add( PRE_TRI.CycleItems[SameTriangles[i]] );
			else
			{
				PRE_TRI.GetCycleItem(SameTriangles[i])->Plane++;
				PRE_TRI.GetCycleItem(SameTriangles[i])->TruePointLeft =  PRE_TRI.CycleItems[SameTriangles[i]]->CrossPointLeft;
				PRE_TRI.GetCycleItem(SameTriangles[i])->TruePointRight =  PRE_TRI.CycleItems[SameTriangles[i]]->CrossPointRight;
			}
		for (int i=0;i<ToDelete.Count;i++)
			PRE_TRI.Remove(ToDelete.Items[i]);
}


void CreateRoofOld( TMDelTList<TIntVec>* RoofPolygon,
					TMDelTList<TIntVec>* Param,
					TMDelTList<TPolygon>* RES,
					TMDelTList<TLuaRoofCut>* FLEGS,
					TMDelTList<TLuaRoofCut>* FSCATES)
{
	InfoMsg("Not used...");
}

void CreateRoof2(   TMDelTList<TIntVec>* RoofPolygon,
					TMDelTList<TIntVec>* Param,
					TMDelTList<TPolygon>* RES,
					TMDelTList<TLuaRoofCut>* FLEGS,
					TMDelTList<TLuaRoofCut>* FSCATES)
{
	InfoMsg("Not used...");
}

void GetRoofPlanes(const TMDelTList<TRoofSide> &side, TMDelTList<TMDelTList<TIntVec> > &N,  TMDelTList<TMDelTList<TIntVec> > &O)
{
	N.Clear();
	O.Clear();
	for (int i=0;i<side.Count;i++)
	{
		TIntVec sideN = VectorP2d((side[i].Cut->Dst->Point - side[i].Cut->Src->Point).Normalize());
		TIntVec sideO = (side[i].Cut->Dst->Point + side[i].Cut->Src->Point)*0.5;

		N.Add(new TMDelTList <TIntVec>);
		O.Add(new TMDelTList <TIntVec>);

		for (int j=0;j<side[i].Planes.Count;j++)
		{
			TIntVec n = sideN*sin(DegToRad(side[i].Planes[j].Angle));
			n.z = cos(DegToRad(side[i].Planes[j].Angle));

			TIntVec o = sideO;
			o += TIntVec(0, 0, side[i].Planes[j].Height);
			if (j)
			{
				TIntVec nn, oo;
				PlanePlaneCross(TIntVec(0,0,1), o, *N.Last()->Last(), *O.Last()->Last(), nn, oo, PEPS);
				o = oo;
			}

			N.Last()->Add(new TIntVec(n));
			O.Last()->Add(new TIntVec(o));
		}
	}	
}

void CutsToPlanes(const TMTList <TGCut> &cuts, TRoofSide &side)
{
	TMTList <TGPoint> pnts;
	GetBasePoints(cuts, pnts);

	while (side.Planes.Count>cuts.Count)
		side.Planes.Delete(0);

	while (side.Planes.Count<cuts.Count)
		side.Planes.Add(new TRoofPlane);

	
	for (int i=0;i<pnts.Count;i++)
		for (int j=i+1;j<pnts.Count;j++)
			if (pnts[i].Point.y>pnts[j].Point.y)
				pnts.Exchange(i, j);
		
	for (int i=0;i<pnts.Count-1;i++)
	{
		side.Planes[i].Height = pnts[i].Point.y - pnts[0].Point.y;
		side.Planes[i].Angle = RadToDeg(AngleRadOX(pnts[i].Point, pnts[i+1].Point));
	}
}

void Lathing(const TGeomObject &roof, TGeomObject &lath)
{
	TGeomObject g;
	g.Assign((TMyObject *)&roof);
	g.SnapPoints = false;

	if (!g.PolygonsCount)	
		return;

	
	for (int i=0;i<g.PolygonsCount;i++)
	{
		TGPolygon &p = g.GetPolygon(i);
		TIntVec ang = GetToPlaneAnglesXZ(p.Normal);
		p.Cache();
		for (int j=0;j<p.Count;j++)
			BackXZ(ang, p.GetPoint(j).Point);

		TMTList <TGCut>  cuts;

		MBTi step = 1;

// Горизонтальная обрешетка
		int cnt = (int)((p.BBox.Max.y - p.BBox.Min.y)/step)+1;
		
		MBTi delta = p.BBox.Max.y;

		for (int k=0;k<p.Count;k++)
			p.GetPoint(k).Point.y -= delta;


		TMTList <TGPoint> points;
		for (int j=1;j<cnt;j++)
		{
			for (int k=0;k<p.Count;k++)
				p.GetPoint(k).Point.y += step;
			delta -= step;
			TMTList <TGCut>  cts;
			TMTList <TGPoint> pnts;
			g.Slice.TransfixPolygonOX(&p, cts);

			GetBasePoints(cts, pnts);
			for (int k=0;k<pnts.Count;k++)
			{
				pnts[k].Point.y += delta;
				pnts[k].Point.z += 0.2;
			}	

			TMTListAdd(cuts, cts);
		}
		for (int k=0;k<p.Count;k++)
			p.GetPoint(k).Point.y += delta;
//Вертикальная обрешетка
		step = 4;
		for (int k=0;k<p.Count;k++)
		{
			MBTi temp = p.GetPoint(k).Point.x;
			p.GetPoint(k).Point.x = p.GetPoint(k).Point.y;
			p.GetPoint(k).Point.y = temp;
		}	
		
		cnt = (int)((p.BBox.Max.y - p.BBox.Min.y)/step)+1;
		delta = p.BBox.Max.y;

		for (int k=0;k<p.Count;k++)
			p.GetPoint(k).Point.y -= delta;

		for (int j=1;j<cnt;j++)
		{
			for (int k=0;k<p.Count;k++)
				p.GetPoint(k).Point.y += step;
			delta -= step;
			TMTList <TGCut>  cts;
			TMTList <TGPoint> pnts;
			g.Slice.TransfixPolygonOX(&p, cts);

			GetBasePoints(cts, pnts);
			for (int k=0;k<pnts.Count;k++)
			{
				pnts[k].Point.y += delta;
//				pnts[k].Point.z += 0.2;
									 
				MBTi temp = pnts[k].Point.x;
				pnts[k].Point.x = pnts[k].Point.y;
				pnts[k].Point.y = temp;
			}	

			TMTListAdd(cuts, cts);
		}
  


		GetBasePoints(cuts, points);
		for (int j=0;j<points.Count;j++)
			if (points[j].Flags.Cached == gfFALSE)
				TransformXZ(ang, points[j].Point);
				
		p.Restore();
	}

	
	
	
	for (int i=0;i<g.CutsCount;i++)
	{
		TGCut &c = g.GetCut(i);
		PrimitiveLineUnit(&lath, 0.1, 0.2, c.Src->Point, c.Dst->Point);
	}
}
