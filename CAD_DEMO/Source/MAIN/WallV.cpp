//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "WallV.h"
#include "MDICubeV.h"
#include "World.h"
#include "Triangulation.h"
#include "LogicNode.h"
#include "MyGL.h"
#include "VisPoly.hpp"
/*
#include "AUIV.h"
*/
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------TMetaCube-------------------------
TMyObject* TMetaCube::CreateFunction()
{
    return new TMetaCube();
}

const AnsiString aHoleNormal = AnsiString("HoleNormal");

TMetaCube::TMetaCube(TMetaNode *Parent,int _ID,const AnsiString& Name)
    :TMetaElement(Parent, _ID,  Name)
{
    RegisterNewClass< TMetaElement, TMetaCube >(this,false,&CreateFunction);
    ImageIndex=iiMetaCube;
    HoleNormal = -1;
    RegisterField(&HoleNormal,&aHoleNormal,mtInt);
}

TMetaCube::TMetaCube()
{
    RegisterNewClass< TMetaElement, TMetaCube >(this,false,&CreateFunction);
    ImageIndex=iiMetaCube;
    HoleNormal = -1;
    RegisterField(&HoleNormal,&aHoleNormal,mtInt);
}

void TMetaCube::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDICube(_Owner,this);
    #endif
}

//------------------------TCube--------------------------------------------------
TMyObject* TCube::CreateFunction()
{
	return new TCube();
}

const AnsiString aVHP = AnsiString("VHP");;

/*TCube::TCube(TMainTree *_MyTree,TMetaNode *_Meta)
    :TArchitectElement(_MyTree,_Meta)
{
    RegisterNewClass< TArchitectElement, TCube >(this,false,&CreateFunction);
    if (typeid(*_Meta)!=typeid(TMetaCube))
    {
		Application->MessageBox("Ожидалось MetaCube, получено Unknown. Приложение СТОП.","Error");
        Application->Terminate();
        return;
    }

    RegisterField(&VHP,&aVHP,mtMyObject);

	VP = new TVisCustomObj(NULL);
    VP->AutoCalcNormals=false;
    VP->Transformation->Order = toTraRotSca;
    VP->Transformation->Rotation->Order = roZXY;
    MGT->AddRender(1,this,VP);
    CurrentEnabled = true;
    CustomEnabled = true;
    CreateView();
}*/



TCube::TCube()
{
    RegisterNewClass< TArchitectElement, TCube >(this,false,&CreateFunction);
    RegisterField(&VHP,&aVHP,mtMyObject);
    VHP.Vertex->Add(new TIntVec(AbsSize.x/2,-AbsSize.z/2,0));
    VHP.Vertex->Add(new TIntVec(AbsSize.x/2,AbsSize.z/2,0));
    VHP.Vertex->Add(new TIntVec(-AbsSize.x/2,AbsSize.z/2,0));
    VHP.Vertex->Add(new TIntVec(-AbsSize.x/2,-AbsSize.z/2,0));

    VP = new TVisCustomObj(NULL);
	VP->AutoCalcNormals=false;
    VP->Transformation->Order = toTraRotSca;
    VP->Transformation->Rotation->Order = roZXY;
}

TCube::~TCube()
{
	RemoveRenderFromTree();
    delete VP;
}

void TCube::FillCompletePolygon(THoledPolygon* CP)
{
    CP->Clear();
    CP->Vertex->Assign( VHP.Vertex );
    for (int i=0;i<HP->Holes->Count;i++)
    {
        CP->Holes->Add( new TPolygon() );
		CP->Holes->Last()->Vertex->Assign(HP->Holes->Items[i]->Vertex);
    }
    for (int i=0;i<LinkHoles.Count;i++)
    {
        CP->Holes->Add( new TPolygon() );
        CP->Holes->Last()->Vertex->Assign( LinkHoles[i].Hole->Vertex );
    }
}

void TCube::Changed(void* Sender)
{
	TElement::Changed(Sender);
    if (Sender == &AbsSize)
    {
        VHP.Vertex->Items[0]->x = AbsSize.x/2;
        VHP.Vertex->Items[1]->x = AbsSize.x/2;
        VHP.Vertex->Items[VHP.Vertex->Count-2]->x = -AbsSize.x/2;
        VHP.Vertex->Items[VHP.Vertex->Count-1]->x = -AbsSize.x/2;
		if (VHP.Vertex->Count==4) //return this (зависимость размера от полигона м.б. по z брать самый маленький)
        {
            VHP.Vertex->Items[0]->y = -AbsSize.z/2;
            VHP.Vertex->Items[1]->y = AbsSize.z/2;
            VHP.Vertex->Items[VHP.Vertex->Count-2]->y = AbsSize.z/2;
            VHP.Vertex->Items[VHP.Vertex->Count-1]->y = -AbsSize.z/2;
        }
    }
}

bool FindIn(TMTList<int> *MAS,int *VAL)
{
    for (int i=0;i<MAS->Count;i++)
        if (*VAL == *(MAS->Items[i]))
            return true;
    return false;
}

void IntellectInsert(TMTList<MBTi> *MAS,MBTi *VAL,int index)
{
    if (index==MAS->Count)
        MAS->Add(VAL);
	else
        MAS->Insert(index,VAL);

}

void AddDirect(TMTList<MBTi> *MAS,MBTi *VAL)
{
	if (*(VAL)<=*(MAS->Items[0]))
        return;
    for (int i=0;i<MAS->Count;i++)
    {
        if (*(VAL)==*(MAS->Items[i]))
            return;
        if (*(VAL)<*(MAS->Items[i]))
        {
            MAS->Insert(i,VAL);
            return;
        }
	}
}



TIntVec sdvm;
TIntVec sdvp;
TIntVec tanp;
TIntVec tanm;

void CreateOneHoleView(TVisPrimitiveObj* VP, TMDelTList<TIntVec>* Vectors,MBTi SIZEZ)
{
    TMDelTList<TIntVec>& Vecs = *(Vectors);
    //VP->AddPrimitiveArray(GL_TRIANGLES);
    for (int i=0;i<Vecs.Count;i++)
    {
        int PCount = VP->Points->Count;
        VP->Points->Add(ToVec(Vecs[i].x,SIZEZ/2,Vecs[i].y), ZEROVEC, ZEROVEC);
		VP->Points->Add(ToVec(Vecs.CycVal(i+1).x,SIZEZ/2,Vecs.CycVal(i+1).y), ZEROVEC, ZEROVEC);
        VP->Points->Add(ToVec(Vecs.CycVal(i+1).x,-SIZEZ/2,Vecs.CycVal(i+1).y), ZEROVEC, ZEROVEC);
        VP->Points->Add(ToVec(Vecs[i].x,-SIZEZ/2,Vecs[i].y), ZEROVEC, ZEROVEC);
        VP->AddIndex(PCount+2,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+1,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+0,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+3,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+2,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+0,VP->PrimitiveCount-1);
    }
}

void TCube::ApplyObjectToFragment(TMyObject* Object,int SideIndex,int Param)
{
    if ( Object->Is(TMetaTexture::StaticType) )
    {
        TMetaTexture* MT = (TMetaTexture*)Object;
        SynhronizeFragments();
        //-------------------------------------------
        for (int i=0;i<FragSet.Count;i++)
            if (FragSet[i].SideIndex == SideIndex)
            {
				FragSet[i].Parameteres.CycVal(Param).Texture = MT;
                RegisterTexturing(NULL);
                return;
            }
    }
    else if ( typeid(*Object) == typeid(TFragmentSettings) )
    {
		SynhronizeFragments();
        for (int i=0;i<FragSet.Count;i++)
            if (FragSet[i].SideIndex == SideIndex)
            {
                FragSet[i].Parameteres.Assign( &(((TFragmentSettings*)Object)->Parameteres) );
                FragSet[i].Polygons.Assign( &(((TFragmentSettings*)Object)->Polygons) );
                FragSet[i].RecurrentCheck();
                RegisterCreateView(NULL);
                return;
            }
    }
}

void TCube::IterateContour(int Fragment,TMTList<TCube>& Cubes,TMDelTList<int>& Indices)
{
    if (!World)
        return;
    int floorindex = World->FloorOf(this);
    if (floorindex == -1)
        return;
    LN->SetDefaultMetaFilter();
    LN->DefinePermises_06( World->Floors[floorindex].First.ADR );
	if (SideCount==0)
        return;
    SynhronizeFragments();
    TFragmentSettings* Frag=FragSet.Items[Fragment];
    TSide* Side = GetSide(Frag->SideIndex);
    if (!Side->Premises || !Side->Premises->Router)
        return;
	TMDelTList<TRoutePoint>& Router = *(Side->Premises->Router);
    _TRY_

        for (int i=0;i<Router.Count;i++)
        {
            TSide* Side = NULL;
            Side = Router[i].InputSide;

            if (!Side || !Side->Element || !Side->Element->ElementPoints)
            {
                continue;
			}
            if ( ! Side->Element->Is(TCube::StaticType) )
                continue;
            TCube* Cube = (TCube*)Side->Element;
            Cubes.Add(Cube);
            Indices.Add( new int(Cube->ElementPoints->Sides.IndexOf(Side)) );
        }
    _ENDTRY_("<TCube::IterateContour>: Texture or material apply error.",);
}

void TCube::ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID)
{
    if ( TotalAllowAdvancedTexture && MyMeta && MyMeta->InWeb)
    {
        if ( !Object->Is(TMetaTexture::StaticType) )
             return;
        TMetaTexture* MT = (TMetaTexture*)Object;
        //-------------------------------------------
		if (!World)
            return;
        int floorindex = World->FloorOf(this);
        if (floorindex == -1)
            return;
        LN->SetDefaultMetaFilter();
        LN->DefinePermises_06( World->Floors[floorindex].First.ADR );
        if (SideCount==0)
            return;
        SynhronizeFragments();
        //-------------------------------------------
		TIntVec LocPoint;
        LocalFromAbs(AbsPoint,LocPoint);
        //найти fragment;
        int FragIndex = -1;
        int index = -1;
        for (int i=0;i<FragSet.Count;i++)
            if (  (index = FragSet[i].FragmentOfPoint(LocPoint,0)) != -1 )
            {
                FragIndex = i;
                break;
            }
		if (FragIndex == -1)
            return;
        TMTList<TCube> Cubes;
        TMDelTList<int> Indices;
        IterateContour(FragIndex,Cubes,Indices);

        for (int i=0;i<Cubes.Count;i++)
			Cubes[i].ApplyObjectToFragment(MT,Indices[i],index);
        for (int i=0;i<Cubes.Count;i++)
            Cubes[i].ForceCreateView();
    }

}


void TCube::NominateVHP()
{
    TMDelTList<TIntVec>& Vert = *(VHP.Vertex);
	while (Vert.Count<4)
        Vert.Add(new TIntVec());
    while (Vert.Count>4)
        Vert.Delete(Vert.Count-1);
    Vert[0].x               = AbsSize.x/2;
    Vert[1].x               = AbsSize.x/2;
    Vert[Vert.Count-2].x    = -AbsSize.x/2;
    Vert[Vert.Count-1].x    = -AbsSize.x/2;
    Vert[0].y               = -AbsSize.z/2;
    Vert[Vert.Count-1].y    = -AbsSize.z/2;
    Vert[1].y               = AbsSize.z/2;
	Vert[Vert.Count-2].y    = AbsSize.z/2;
}

void TCube::ValidateVHP()
{
    TMDelTList<TIntVec>& Vert = *(VHP.Vertex);
    if (Vert.Count<4)
	{
        while (Vert.Count<4)
            Vert.Add(new TIntVec());
        Vert[1].z = AbsSize.z/2;
        Vert[Vert.Count-2].z = AbsSize.z/2;
    }
    if (Vert.Count>4)
        for (int i=2;i<Vert.Count-3;i++)
            if (Vert[i].x<Vert[i+1].x-0.0001)
                Vert.Delete(i--);
    //-------------------------------------------------------------------
	Vert[0].x = AbsSize.x/2;
    Vert[1].x = AbsSize.x/2;
    Vert[Vert.Count-2].x = -AbsSize.x/2;
    Vert[Vert.Count-1].x = -AbsSize.x/2;
    //-------------------------------------------------------------------
    Vert[0].y = -AbsSize.z/2;
    Vert[Vert.Count-1].y = -AbsSize.z/2;
    for (int i=0;i<Vert.Count;i++)
        if (Vert[i].y>AbsSize.z/2)
            Vert[i].y = AbsSize.z/2;
}


int TCube::CrossXYPolygon(const TIntVec& Point,int& index,TIntVec& CrossPoint)
{
    TMDelTList<TIntVec>& Vert = *(VHP.Vertex);
    int max_i= -1;
    int min_i= -1;
	for (int i=0;i<Vert.Count;i++)
    {
        if (max_i == -1 || Vert[max_i].x <= Vert[i].x + 0.0001 )
            max_i = i;
        if (min_i == -1 || Vert[min_i].x > Vert[i].x + 0.0001 )
            min_i = i;
    }
    if (fabs(Point.x-Vert[max_i].x)<0.0001)
    {
        CrossPoint = Vert[max_i];
        index = max_i;
		return resPoint;
    }
    if (Point.x>Vert[max_i].x)
    {

        MBTi alpha = (Point.x - Vert[max_i+1].x)/(Vert[max_i].x - Vert[max_i+1].x);
        CrossPoint = ( Vert[max_i] - Vert[max_i+1] )*alpha + Vert[max_i+1];
        index = max_i;
        return resRib;
    }
    if (fabs(Point.x-Vert[min_i].x)<0.0001)
	{
        CrossPoint = Vert[min_i];
        index = min_i;
        return resPoint;
    }
    if (Point.x<Vert[min_i].x)
    {
		MBTi alpha = (Point.x - Vert[min_i-1].x)/(Vert[min_i].x - Vert[min_i-1].x);
        CrossPoint = ( Vert[min_i] - Vert[min_i-1] )*alpha + Vert[min_i-1];
        index = min_i+1;
        return resRib;
    }

    for (int i=1;i<Vert.Count-1;i++)
    {
        if ( fabs(Point.x - Vert[i].x)<=0.0001)
        {
            CrossPoint = Vert[i];
			index = i;
            return resPoint;
        }
        if ( Point.x > Vert[i].x )
        {
            MBTi alpha = (Point.x - Vert[i].x)/(Vert[i-1].x - Vert[i].x);
            CrossPoint = ( Vert[i-1] - Vert[i] )*alpha + Vert[i];
            index = i;
            return resRib;
        }
    }
	MBTi alpha = (Point.x - Vert[Vert.Count-1].x)/(Vert[Vert.Count-2].x - Vert[Vert.Count-1].x);
    CrossPoint = ( Vert[Vert.Count-2] - Vert[Vert.Count-1] )*alpha + Vert[Vert.Count-1];
    index = Vert.Count-1;
    return resRib;
}

void TCube::GetWallEdge(TRouteNode* RN,TIntVec& CP)
{
    TMDelTList<TIntVec>& Vert = *(VHP.Vertex);
    ValidateVHP();
    TIntVec LocalPoint;
    LocalFromAbs(RN->LinkPoint,LocalPoint);
    MBTi alpha = (LocalPoint.x - Vert[Vert.Count-2].x)/(Vert[1].x - Vert[Vert.Count-2].x);
    CP = (Vert[1] - Vert[Vert.Count-2])*alpha + Vert[Vert.Count-2];
}

void TCube::SynhronizeFragments()
{
	//----------------важно для работы алгоритма синхронизации
    if (!MyMeta || !MyMeta->InWeb)
        return ;
    if (FragSet.Count == 0)
    {
        FragSet.Add( new TFragmentSettings() );
        FragSet[0].Parameteres[0].Texture = NULL;
        FragSet[0].Parameteres[0].Material = RenPars[MyTree->ModeIndex].Material;
//        FragSet[0].Polygons[0].Vertex->Add() //return this задание по умолчанию
    }
    //----------------важно для работы алгоритма синхронизации
	TMTList<TFragmentSettings> FSL;
    FSL.Assign(&FragSet);
    FSL.RecurrentCheck();
    TMDelTList<TFragmentSettings> SDL;
    for (int i=0;i<SideCount;i++)
    {
		TSide* Side = GetSide(i);
		SDL.Add(new TFragmentSettings());
        LocalFromAbs(*Side->P0,SDL.Last()->LocalP0);
        LocalFromAbs(*Side->P1,SDL.Last()->LocalP1);
        SDL.Last()->SideType = Side->SideType;
        SDL.Last()->IsOutSide = Side->IsOutSide();
        SDL.Last()->SideIndex = i;
        SDL.Last()->ISWALLEND = Side->ISWALLEND;
        SDL.Last()->ISWALLSTART = Side->ISWALLSTART;
    }

    for (int i=0;i<SDL.Count;i++)
	{
        int MAXCROSSINDEX;
        MBTi MAXCROSS = -1;
        MBTi CURCROSS = -1;
        MBTi EDGE1;
        MBTi EDGE2;
        for (int j=0;j<FSL.Count;j++)
        {
            if ( SDL[i].SideType != FSL[j].SideType )
                CURCROSS = 0;
			else if (SDL[i].SideType == stYMinus || SDL[i].SideType == stYPlus)
			{
                Cross_Length(SDL[i].LocalP0.x,SDL[i].LocalP1.x,FSL[j].LocalP0.x,FSL[j].LocalP1.x,EDGE1,EDGE2,0,0);
                CURCROSS = fabs(EDGE1-EDGE2);
            }
            else
            {
                Cross_Length(SDL[i].LocalP0.y,SDL[i].LocalP1.y,FSL[j].LocalP0.y,FSL[j].LocalP1.y,EDGE1,EDGE2,0,0);
				CURCROSS = fabs(EDGE1-EDGE2);
            }
            if (CURCROSS>MAXCROSS)
            {
                MAXCROSS = CURCROSS;
                MAXCROSSINDEX = j;
            }
        }
        SDL[i].Parameteres.Assign(&FSL[MAXCROSSINDEX].Parameteres);
        SDL[i].Parameteres.RecurrentCheck();

		//не можем сделать просто ассигн
        //потому что первый полигон использует полигон "is read only"
        //а не копирует список векторов проема
        //а во время работы с окнами этот список меняется
        //происходит обращение не в те участки памяти
        while (SDL[i].Polygons.Count>FSL[MAXCROSSINDEX].Polygons.Count)
            SDL[i].Polygons.Delete(SDL[i].Polygons.Count-1);
        while (SDL[i].Polygons.Count<FSL[MAXCROSSINDEX].Polygons.Count)
            SDL[i].Polygons.Add(new THoledPolygon());
        for (int k=1;k<SDL[i].Polygons.Count;k++)
        {
			SDL[i].Polygons[k].Assign(&FSL[MAXCROSSINDEX].Polygons[k]);
            SDL[i].Polygons[k].RecurrentCheck();
        }
    }
    FragSet.Clear();
	for (int i=0;i<SDL.Count;i++)
        FragSet.Add(SDL.Items[i]);
	SDL.NoDelClear();
    ValidateVHP();
    
    //теперь получение первых полигонов
    for (int i=0;i<FragSet.Count;i++)
    {
        FragSet[i].Polygons[0].Vertex->Clear();
        FragSet[i].Polygons[0].Holes->Clear();
        switch (FragSet[i].SideType)
        {
            case stYPlus:
			case stYMinus:
            {
                TIntVec LOCLEFT = (FragSet[i].SideType == stYPlus) ? FragSet[i].LocalP0 : FragSet[i].LocalP1;
                TIntVec LOCRIGHT = (FragSet[i].SideType == stYPlus) ? FragSet[i].LocalP1 : FragSet[i].LocalP0;
                bool LeftEdge = (FragSet[i].SideType == stYPlus) ? FragSet[i].ISWALLSTART : FragSet[i].ISWALLEND;
                bool RightEdge = (FragSet[i].SideType == stYPlus) ? FragSet[i].ISWALLEND : FragSet[i].ISWALLSTART;
                TRouteNode* RIGHTNODE = (FragSet[i].SideType == stYPlus) ? GetSide(FragSet[i].SideIndex)->Node1 : GetSide(FragSet[i].SideIndex)->Node0;
                TRouteNode* LEFTNODE = (FragSet[i].SideType == stYPlus) ? GetSide(FragSet[i].SideIndex)->Node0 : GetSide(FragSet[i].SideIndex)->Node1;
                FragSet[i].Polygons[0].Vertex->Clear();
                FragSet[i].Polygons[0].Holes->Clear();
                int RightWallIndex = -1;
				int LeftWallIndex = -1;
                int MinusLeftFragIndex = -1;
                if (RightEdge)
                {
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(VHP.Vertex->Val(0)));
                    FragSet[i].Polygons[0].Vertex->Last()->x = LOCRIGHT.x;
                    FragSet[i].Polygons[0].Vertex->Last()->z = LOCRIGHT.y;
					FragSet[i].Polygons[0].Vertex->Add(new TIntVec(VHP.Vertex->Val(1)));
                    //int _index;
                    //CrossXYPolygon(LOCRIGHT,_index,*(FragSet[i].Polygons[0].Vertex->Last()));
                    FragSet[i].Polygons[0].Vertex->Last()->x = LOCRIGHT.x;
					FragSet[i].Polygons[0].Vertex->Last()->z = LOCRIGHT.y;
                    RightWallIndex = 1;
                    RIGHT_LINK_HEIGHT = VHP.Vertex->CycVal(1).y;
                }
                else
                {
                    TIntVec CP;
					int res = CrossXYPolygon(LOCRIGHT,RightWallIndex,CP);
                    if (res == resRib)
                        RightWallIndex--;
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCRIGHT.x,-AbsSize.z/2,LOCRIGHT.y));
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(CP));
                    FragSet[i].Polygons[0].Vertex->Last()->z = LOCRIGHT.y;
                }
                if (LeftEdge)
                {
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(VHP.Vertex->CycVal(-2)));
                    //предпоследний
					//int _index;
                    //CrossXYPolygon(LOCLEFT,_index,*(FragSet[i].Polygons[0].Vertex->Last()));
                    //-------------
                    FragSet[i].Polygons[0].Vertex->Last()->x = LOCLEFT.x;
                    FragSet[i].Polygons[0].Vertex->Last()->z = LOCLEFT.y;
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(VHP.Vertex->CycVal(-1)));
                    FragSet[i].Polygons[0].Vertex->Last()->x = LOCLEFT.x;
					FragSet[i].Polygons[0].Vertex->Last()->z = LOCLEFT.y;
                    LeftWallIndex = VHP.Vertex->Count-2;
                    MinusLeftFragIndex = 2;
                    LEFT_LINK_HEIGHT = VHP.Vertex->CycVal(-2).y;
                }
                else
                {
                    TIntVec CP;
                    CrossXYPolygon(LOCLEFT,LeftWallIndex,CP);
                    FragSet[i].Polygons[0].Vertex->Add(new TIntVec(CP));
					FragSet[i].Polygons[0].Vertex->Last()->z = LOCLEFT.y;
					FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCLEFT.x,-AbsSize.z/2,LOCLEFT.y));
                    MinusLeftFragIndex = 2;
                }
                for (int j=RightWallIndex+1;j<LeftWallIndex;j++)
                {
                    int insindex = FragSet[i].Polygons[0].Vertex->Count-MinusLeftFragIndex;
                    FragSet[i].Polygons[0].Vertex->Insert(insindex,new TIntVec(VHP.Vertex->Val(j)));
                    FragSet[i].Polygons[0].Vertex->Items[insindex]->z = LOCRIGHT.y;
                }

                //now vaidate fragment
				if (LEFTNODE)
                {
                    TIntVec MINPOINT;
                    MINPOINT.y = FragSet[i].Polygons[0].Vertex->CycVal(-2).y;
                    for (int i=0;i<LEFTNODE->LNKS.Count;i++)
                    {
                        if (FLinks.IndexOf(LEFTNODE->LNKS[i].Link)==-1)
							continue;
                        TElement* El = LEFTNODE->LNKS[i].Link->OtherElement(this);
                        TIntVec CurPoint;
                        if ( El->Is(TCube::StaticType) )
                            ((TCube*)El)->GetWallEdge(LEFTNODE,CurPoint);
                        else
                            CurPoint.y = El->AbsSize.z/2;
                        CurPoint.z = CurPoint.y;
                        El->AbsFromLocal(CurPoint,CurPoint);
                        LocalFromAbs(CurPoint,CurPoint);
                        CurPoint.y = CurPoint.z;
						if (MINPOINT.y > CurPoint.y)
                            MINPOINT.y = CurPoint.y;
                    }
                  //  if ( fabs(MINPOINT.y-FragSet[i].Polygons[0].Vertex->CycVal(-2).y)>0.0001 )
                  //  {
						TIntVec CP;
                        int index;
                        TIntVec LOC_CENTER_LEFT = LEFTNODE->LinkPoint;
                        LocalFromAbs(LOC_CENTER_LEFT,LOC_CENTER_LEFT);
                        CrossXYPolygon(LOC_CENTER_LEFT,index,CP);
                        if (LeftEdge)
							LEFT_LINK_HEIGHT = MINPOINT.y;

                        FragSet[i].Polygons[0].Vertex->Insert(FragSet[i].Polygons[0].Vertex->Count-2,new TIntVec(CP));
                        FragSet[i].Polygons[0].Vertex->Insert(FragSet[i].Polygons[0].Vertex->Count-2,new TIntVec(CP));

                        FragSet[i].Polygons[0].Vertex->CycVal(-2).y = MINPOINT.y;
                        FragSet[i].Polygons[0].Vertex->CycVal(-3).x = CP.x;
						FragSet[i].Polygons[0].Vertex->CycVal(-3).y = MINPOINT.y;

                        FragSet[i].Polygons[0].Vertex->CycVal(-3).z = LOCLEFT.y;
                        FragSet[i].Polygons[0].Vertex->CycVal(-4).z = LOCLEFT.y;
                   // }
                }

                if (RIGHTNODE)
                {
                    TIntVec MINPOINT;
                    MINPOINT.y = FragSet[i].Polygons[0].Vertex->CycVal(1).y;
					for (int i=0;i<RIGHTNODE->LNKS.Count;i++)
                    {
                        if (FLinks.IndexOf(RIGHTNODE->LNKS[i].Link)==-1)
                            continue;
                        TElement* El = RIGHTNODE->LNKS[i].Link->OtherElement(this);
                        TIntVec CurPoint;
                        if ( El->Is(TCube::StaticType) )
                            ((TCube*)El)->GetWallEdge(RIGHTNODE,CurPoint);
                        else
                            CurPoint.y = El->AbsSize.z/2;
                        CurPoint.z = CurPoint.y;
						El->AbsFromLocal(CurPoint,CurPoint);
                        LocalFromAbs(CurPoint,CurPoint);
                        CurPoint.y = CurPoint.z;
                        if (MINPOINT.y > CurPoint.y)
                            MINPOINT.y = CurPoint.y;
                    }
//                    if ( fabs(MINPOINT.y-FragSet[i].Polygons[0].Vertex->CycVal(1).y)>0.0001 )
  //                  {
                        TIntVec CP;
                        int index;
                        TIntVec LOC_CENTER_RIGHT = RIGHTNODE->LinkPoint;
                        LocalFromAbs(LOC_CENTER_RIGHT,LOC_CENTER_RIGHT);
                        CrossXYPolygon(LOC_CENTER_RIGHT,index,CP);
                        if (RightEdge)
                            RIGHT_LINK_HEIGHT = MINPOINT.y;

                        FragSet[i].Polygons[0].Vertex->Insert(2,new TIntVec(CP));
                        FragSet[i].Polygons[0].Vertex->Insert(2,new TIntVec(CP));

                        FragSet[i].Polygons[0].Vertex->CycVal(1).y = MINPOINT.y;

                        FragSet[i].Polygons[0].Vertex->CycVal(2).x = CP.x;
                        FragSet[i].Polygons[0].Vertex->CycVal(2).y = MINPOINT.y;

                        FragSet[i].Polygons[0].Vertex->CycVal(2).z = LOCRIGHT.y;
                        FragSet[i].Polygons[0].Vertex->CycVal(3).z = LOCRIGHT.y;

                //    }
                }
				FragSet[i].Polygons[0].KillCloseEdges_0(Delone.EPS);

            }
            break;
            default:
            {
				TIntVec LOCLEFT = (FragSet[i].SideType == stXPlus) ? FragSet[i].LocalP0 : FragSet[i].LocalP1;
				TIntVec LOCRIGHT = (FragSet[i].SideType == stXPlus) ? FragSet[i].LocalP1 : FragSet[i].LocalP0;
                FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCRIGHT.y,VHP.Vertex->Val(1).y,LOCRIGHT.x) );
                FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCLEFT.y,VHP.Vertex->Val(1).y,LOCLEFT.x) );
                FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCLEFT.y,VHP.Vertex->Val(0).y,LOCLEFT.x) );
                FragSet[i].Polygons[0].Vertex->Add(new TIntVec(LOCRIGHT.y,VHP.Vertex->Val(0).y,LOCRIGHT.x) );
        
            }
        }
    }
    for (int i=0;i<FragSet.Count;i++)
    {
		if (FragSet[i].SideType == stXPlus || FragSet[i].SideType == stXMinus)
            continue;
        for (int j=0;j<LinkHoles.Count;j++)
            if ( FragSet[i].Polygons[0].CrossedWithPolygon(LinkHoles[j].Hole,0.0001) )
            {
                FragSet[i].Polygons[0].Holes->Add(new TPolygon());
                FragSet[i].Polygons[0].Holes->Last()->Vertex->Assign(LinkHoles[j].Hole->Vertex);
/*                FragSet[i].Polygons[0].Holes->Add(new TPolygon());
                FragSet[i].Polygons[0].Holes->Last()->Vertex->Assign(LinkHoles[j].Hole->Vertex);*/
            }
    }
}

void TCube::ProcessTexturing()
{
	if ( TotalAllowAdvancedTexture )
	{
		TMTList<TVisPrimitiveArray> Arrays;
		for (int i=0;i<VP->PrimitiveCount;i++)
			Arrays.Add(VP->Primitive[i]);

		VP->Textured = false;

		for (int i=0;i<FragSet.Count;i++)
			for (int j=0;j<FragSet[i].PolygonCount;j++)
			{
				TexturePrimitive(VP, VP->Primitive[FragSet[i].Parameteres[j].Tag] ,FragSet[i].Parameteres[j],0);
				if (FragSet[i].Parameteres[j].Tag >= 0 && FragSet[i].Parameteres[j].Tag < VP->PrimitiveCount)
					Arrays.Remove( VP->Primitive[FragSet[i].Parameteres[j].Tag] );
			}
		for (int i=0;i<Arrays.Count;i++)
		{
			TexturePrimitive(VP,Arrays.Items[i],RenPars[MyTree->ModeIndex],0);
		}
	}
	else
	{
		//TElement::ProcessTexturing();

		TVisRender* Render = MyRender();
		if (Render && IS( Render,__classid(TVisPrimitiveObj) ) )
		{
			TVisPrimitiveObj* Render1 = (TVisPrimitiveObj*)Render;
			Render1->Textured = false;
			Render1->Texture = NULL;
			for (int i=0;i<Render1->PrimitiveCount;i++)
			{
				TexturePrimitive(Render1,Render1->Primitive[i],RenPars[MyTree->ModeIndex],0);
				if ( Render1->Primitive[i]->Textured )
				{
					Render1->Textured = true;
				}
			}
		}
	}
	NeedTexturing = false;
}

bool TCube::AdvancedCreateView()
{
	//----------------важно для работы алгоритма синхронизации
    if (!MyMeta || !MyMeta->InWeb)
        return false ;
    if (FragSet.Count == 0)
    {
        FragSet.Add( new TFragmentSettings() );
        FragSet[0].Parameteres[0].Texture = NULL;
        FragSet[0].Parameteres[0].Material = RenPars[MyTree->ModeIndex].Material;
//        FragSet[0].Polygons[0].Vertex->Add() //return this задание по умолчанию 
    }
    //----------------важно для работы алгоритма синхронизации
  TIntVec UseSize(AbsSize);
  if (RenPars[MyTree->ModeIndex].OverSizeMode)
	UseSize += RenPars[MyTree->ModeIndex].OverSize;
  //-----------------------------

    if (!World)
        return false;
	int index = World->FloorOf(this);
    if (index == -1)
        return false;
    LN->SetDefaultMetaFilter();
    LN->DefinePermises_06( World->Floors[index].First.ADR );
    if (SideCount==0)
        return false;
    SynhronizeFragments();

    VP->Init();

	/*TIntVec vhp_hi_max = TIntVec(AbsSize.x/2,AbsSize.y/2,0);
    TIntVec vhp_hi_min = TIntVec(-AbsSize.x/2,AbsSize.y/2,0);
    TIntVec vhp_low_max = TIntVec(AbsSize.x/2,-AbsSize.y/2,0);
    TIntVec vhp_low_min = TIntVec(-AbsSize.x/2,-AbsSize.y/2,0);*/

    TIntVec hi_max;
	TIntVec hi_min;
    TIntVec low_max;
    TIntVec low_min;

    for (int k=0;k<FragSet.Count;k++)
	{
        FragSet[k].Parameteres[0].Tag = VP->AddPrimitiveArray(GL_TRIANGLES);
        TMTList<TIntVec>& TRI = *(Delone.Triangulate(FragSet[k].Polygons.Items[0]));
		switch(FragSet[k].SideType)
        {
            case stYPlus:
            {
				if (FragSet[k].ISWALLEND)
                    hi_max = FragSet[k].LocalP1;      //himax
                if (FragSet[k].ISWALLSTART)
                    hi_min = FragSet[k].LocalP0;      //himin
            }break;
            case stYMinus:
            {
                if (FragSet[k].ISWALLEND)
                    low_min = FragSet[k].LocalP1;      //lomin
                if (FragSet[k].ISWALLSTART)
                    low_max = FragSet[k].LocalP0;      //lomax
			}break;
        }
        if (FragSet[k].SideType == stYPlus || FragSet[k].SideType == stYMinus)
            for (int g=0;g<TRI.Count;g++)
            {
                int g_index = (FragSet[k].SideType == stYMinus) ? (g) : TRI.Count-1-g;
                int index = VP->Points->Add(TRI[g_index].x,FragSet[k].Polygons[0].Vertex->Val(0).z,TRI[g_index].y);
                VP->AddIndex(index,VP->PrimitiveCount-1);
            }
        else
            for (int g=0;g<TRI.Count;g++)
			{
                int g_index = (FragSet[k].SideType == stXPlus) ? (g) : TRI.Count-1-g;
                int index = VP->Points->Add(FragSet[k].Polygons[0].Vertex->Val(0).z,TRI[g_index].x,TRI[g_index].y);
				VP->AddIndex(index,VP->PrimitiveCount-1);
            }
    }

		VP->AddPrimitiveArray(GL_TRIANGLES);
        //LOW
        int PCount = VP->Points->Count;
        VP->Points->Add(ToVec(MAX(hi_max.x,AbsSize.x/2),hi_max.y,-AbsSize.z/2), ZEROVEC, ZEROVEC);
        VP->Points->Add(ToVec(MAX(low_max.x,AbsSize.x/2),low_max.y,-AbsSize.z/2), ZEROVEC, ZEROVEC);
        VP->Points->Add(ToVec(MIN(low_min.x,-AbsSize.x/2),low_min.y,-AbsSize.z/2), ZEROVEC, ZEROVEC);
        VP->Points->Add(ToVec(MIN(hi_min.x,-AbsSize.x/2),hi_min.y,-AbsSize.z/2), ZEROVEC, ZEROVEC);
        VP->AddIndex(PCount+0,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+1,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+2,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+0,VP->PrimitiveCount-1);
		VP->AddIndex(PCount+2,VP->PrimitiveCount-1);
        VP->AddIndex(PCount+3,VP->PrimitiveCount-1);
        
        //HI
//        VP->AddPrimitiveArray(GL_TRIANGLES);
            TMTList<TIntVec> NEW_VHP;
            NEW_VHP.Assign(VHP.Vertex);
            NEW_VHP.Delete(0);
            NEW_VHP.Delete(NEW_VHP.Count-1);
			TIntVec LEFT;
            TIntVec RIGHT;
			if ( fabs(LEFT_LINK_HEIGHT-VHP.Vertex->CycVal(-2).y)>0.0001 )
            {
                LEFT = TIntVec(NEW_VHP[NEW_VHP.Count-1].x,LEFT_LINK_HEIGHT,0);
				NEW_VHP.Add(&LEFT);
            }
            if ( fabs(RIGHT_LINK_HEIGHT-VHP.Vertex->Val(1).y)>0.0001 )
            {
				RIGHT = TIntVec(NEW_VHP[0].x,RIGHT_LINK_HEIGHT,0);
                NEW_VHP.Insert(0,&RIGHT);
            }
            for (int i=0;i<NEW_VHP.Count-1;i++)
            {
                VP->AddIndex(VP->Points->Add(NEW_VHP[i].x,-AbsSize.y/2,NEW_VHP[i].y),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(NEW_VHP[i].x,AbsSize.y/2,NEW_VHP[i].y),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(NEW_VHP[i+1].x,AbsSize.y/2,NEW_VHP[i+1].y),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(NEW_VHP[i].x,-AbsSize.y/2,NEW_VHP[i].y),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(NEW_VHP[i+1].x,AbsSize.y/2,NEW_VHP[i+1].y),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(NEW_VHP[i+1].x,-AbsSize.y/2,NEW_VHP[i+1].y),VP->PrimitiveCount-1);
			}

        //right triangle
        if ( hi_max.x>AbsSize.x/2 || low_max.x>AbsSize.x/2 )
        {
            if ( hi_max.x>AbsSize.x/2 )
            {
                VP->AddIndex(VP->Points->Add(AbsSize.x/2,-AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(hi_max.x,AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(AbsSize.x/2,AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
            }
			else
            {
                VP->AddIndex(VP->Points->Add(AbsSize.x/2,-AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
				VP->AddIndex(VP->Points->Add(low_max.x,-AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(AbsSize.x/2,AbsSize.y/2,RIGHT_LINK_HEIGHT),VP->PrimitiveCount-1);
            }
        }

        //left triangle
        if ( hi_min.x<-AbsSize.x/2 || low_min.x<-AbsSize.x/2 )
        {
            if ( hi_min.x<-AbsSize.x/2 )
            {
                VP->AddIndex(VP->Points->Add(-AbsSize.x/2,-AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(-AbsSize.x/2,AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(hi_min.x,AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
            }
            else
			{
                VP->AddIndex(VP->Points->Add(low_min.x,-AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(-AbsSize.x/2,-AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
                VP->AddIndex(VP->Points->Add(-AbsSize.x/2,AbsSize.y/2,LEFT_LINK_HEIGHT),VP->PrimitiveCount-1);
			}
        }
    //проемы
    for (int i=0;i<LinkHoles.Count;i++)
    {
        CreateOneHoleView(VP,LinkHoles[i].Hole->Vertex,AbsSize.y);
    }

	VP->CalcNormals();
	VP->Texture = NULL;
	VP->Material = NULL;
	for (int i=0;i<VP->Points->Count;i++)
	{
		VP->Points->TextureVec[i] = ZEROVEC;
	}

	ProcessTexturing();
	FAdvancedTextured = true;
	return true;
}



void TCube::CalcFragments()
{
    if (!World)
        throw EMyException("Calculating not done") ;
    int index = World->FloorOf(this);
    if (index == -1)
        throw EMyException("Calculating not done") ;
    LN->SetDefaultMetaFilter();
    LN->DefinePermises_06( World->Floors[index].First.ADR );
	if (SideCount==0)
        throw EMyException("Calculating not done") ;
    SynhronizeFragments();
    for (int i=0;i<FragSet.Count;i++)
		for (int j=0;j<FragSet[i].Parameteres.Count;j++)
        {
            FragSet[i].Parameteres[j].Area = 0;
            TMTList<TIntVec>& TRI = *(Delone.Triangulate(FragSet[i].Polygons.Items[j]));
            for (int k=0;k<TRI.Count;k+=3)
                FragSet[i].Parameteres[j].Area += CalcTriangleArea(TRI[k],TRI[k+1],TRI[k+2],2);
        }
    ATVChanged = false;
}

MBTi TCube::FragmentArea(int Fragment,int Param)
{
    if (ATVChanged)
        CalcFragments();
    return FragSet[Fragment].Parameteres[Param].Area;
}

int DirectInsert(TMDelTList< MBTi >& AXE,MBTi Val,MBTi USEEPS)
{
    for (int i=0;i<AXE.Count;i++)
        if ( fabs(AXE[i]-Val)<=USEEPS )
            return i;
        else if ( AXE[i]<Val-USEEPS )
        {
            AXE.Insert(i,new MBTi(Val));
			return i;
        }
    AXE.Add(new MBTi(Val));
    return AXE.Count-1;
}

int FindArea(TMDelTList< MBTi >& AXE,MBTi Val)
{
    for (int i=0;i<AXE.Count;i++)
        if ( AXE[i]>Val )
            return i;
    return -1;
}


void TCube::StandartCreateView()
{
    if ( TotalAllowAdvancedTexture && FLinks.Count > 0 && AdvancedCreateView() )
      return;
  TIntVec UseSize(AbsSize);
  if (RenPars[MyTree->ModeIndex].OverSizeMode)
    UseSize += RenPars[MyTree->ModeIndex].OverSize;
  //-----------------------------
  //-----------------------------
  VP->Init();
  VP->AutoCalcNormals=false;

  for (int i=0;i<3;i++)
  {
	tanm.a[i] = SlopeMinus.a[(i+2)%3]*M_PI/180;
    if (tanm.a[i])
      tanm.a[i] = tan(tanm.a[i]);
    sdvm.a[i] = fabs(tanm.a[i]*UseSize.a[(i+1)%3]/2);

    tanp.a[i] = SlopePlus.a[(i+2)%3]*M_PI/180;
    if (tanp.a[i])
        tanp.a[i] = tan(tanp.a[i]);
    sdvp.a[i] = fabs(tanp.a[i]*UseSize.a[(i+1)%3]/2);
  }

    if ((LinkHoles.Count>0 || MyMeta->InWeb) && (!RenPars[MyTree->ModeIndex].FLAT2D))
    {
        if (VP->PrimitiveCount==0)
            VP->AddPrimitiveArray(GL_TRIANGLES);

        MBTi __pos1p = UseSize.x/2 - sdvp.x;
        MBTi __pos1m = sdvm.x - UseSize.x/2;

        TRouteNode* NODES[2];
        NODES[0]=NULL;
        NODES[1]=NULL;
        MBTi Ygreks[2];
        Ygreks[0] = VHP.Vertex->CycVal(-2).y;
        Ygreks[1] = VHP.Vertex->Val(1).y;
        for (int i=0;i<SideCount;i++)
        {
            TSide& Side = *(GetSide(i));
            if ( (Side.SideType == stYPlus && Side.ISWALLEND) )
				NODES[1] = Side.Node1;
            if (  (Side.SideType == stYMinus && Side.ISWALLSTART) )
                NODES[1] = Side.Node0;
            if ( (Side.SideType == stYPlus && Side.ISWALLSTART) )
				NODES[0] = Side.Node0;
            if (  (Side.SideType == stYMinus && Side.ISWALLEND) )
                NODES[0] = Side.Node1;
        }
        for (int j=0;j<2;j++)
            if (NODES[j])
                    for (int i=0;i<NODES[j]->LNKS.Count;i++)
                    {
                        if (FLinks.IndexOf(NODES[j]->LNKS[i].Link)==-1)
                            continue;
                        TElement* El = NODES[j]->LNKS[i].Link->OtherElement(this);
                        TIntVec CurPoint;
                        if ( El->Is(TCube::StaticType) )
                            ((TCube*)El)->GetWallEdge(NODES[j],CurPoint);
                        else
                            CurPoint.y = El->AbsSize.z/2;
                        CurPoint.z = CurPoint.y;
                        El->AbsFromLocal(CurPoint,CurPoint);
                        LocalFromAbs(CurPoint,CurPoint);
                        CurPoint.y = CurPoint.z;
                        if (Ygreks[j] > CurPoint.y)
                            Ygreks[j] = CurPoint.y;
                    }

        THoledPolygon HP2;
		HP2.Assign(&VHP);
        TMDelTList<TIntVec>& Vert = *(HP2.Vertex);
        Vert.Insert(2,new TIntVec(Vert[1]));
        Vert.Insert(2,new TIntVec(Vert[1]));
		Vert.Insert(Vert.Count-2,new TIntVec(Vert[Vert.Count-2]) );
        Vert.Insert(Vert.Count-2,new TIntVec(Vert[Vert.Count-2]) );

        Vert[0] = TIntVec(__pos1p,-UseSize.z/2,0);
        Vert[1] = TIntVec(__pos1p,Ygreks[1],0);
        Vert[2] = TIntVec(VHP.Vertex->Val(0).x,Ygreks[1],0);
        Vert[Vert.Count-1] = TIntVec(__pos1m,-UseSize.z/2,0);
        Vert[Vert.Count-2] = TIntVec(__pos1m,Ygreks[0],0);
        Vert[Vert.Count-3] = TIntVec(VHP.Vertex->Last()->x,Ygreks[0],0);

        HP2.KillCloseEdges_0(Delone.EPS);
        for (int i=0;i<LinkHoles.Count;i++)
            HP2.Holes->Add( new THoledPolygon(LinkHoles[i].Hole->Vertex) );

        TMTList<TIntVec>& Triangles = *(Delone.Triangulate(&HP2));
        TVisMathVector V;
        for (int i=Triangles.Count-1;i>=0;i--)
        {
            V.x = Triangles[i].x;
            V.z = Triangles[i].y;
            V.y = -(UseSize.y/2);
            int index = VP->Points->Add(V, ZEROVEC, ZEROVEC);
            VP->AddIndex(index);
        }
        VP->CalcNormals();
		VP->Extrude(UseSize.y,1,false,NULL);
        if (sdvp.x!=0)
        {
            TVisPolygon *Pol = new TVisPolygon(NULL);
			Pol->Init();
            Pol->AutoCalcNormals=false;
            if (SlopePlus.z>0)
                Pol->AddValues(UseSize.x/2+sdvp.x,  UseSize.y/2,    -UseSize.z/2,0,0);
            Pol->AddValues(UseSize.x/2-sdvp.x,  UseSize.y/2,    -UseSize.z/2,0,0);
            Pol->AddValues(UseSize.x/2-sdvp.x,  -UseSize.y/2,   -UseSize.z/2,0,0);
            if (SlopePlus.z<0)
                Pol->AddValues(UseSize.x/2+sdvp.x,  -UseSize.y/2,   -UseSize.z/2,0,0);
            Pol->CalcNormals();
            Pol->Extrude(Ygreks[1]+UseSize.z/2,1,false,NULL);
            VP->AddPrimitiveObj(Pol);
            delete Pol;
        }
        if (sdvm.x!=0)
        {
            TVisPolygon *Pol = new TVisPolygon(NULL);
            Pol->Init();
            Pol->AutoCalcNormals=false;
            Pol->AddValues(-UseSize.x/2+sdvm.x, UseSize.y/2,-UseSize.z/2,0,0);
            if (SlopeMinus.z<0)
                Pol->AddValues(-UseSize.x/2-sdvm.x, UseSize.y/2,-UseSize.z/2,0,0);
            if (SlopeMinus.z>0)
                Pol->AddValues(-UseSize.x/2-+sdvm.x,-UseSize.y/2,-UseSize.z/2,0,0);
            Pol->AddValues(-UseSize.x/2+sdvm.x, -UseSize.y/2,-UseSize.z/2,0,0);
            Pol->CalcNormals();
			Pol->Extrude(Ygreks[0]+UseSize.z/2,1,false,NULL);
            Pol->CalcNormals();
            VP->AddPrimitiveObj(Pol);
            delete Pol;
		}
    }
    else
    {
        if (VP->PrimitiveCount==0)
            VP->AddPrimitiveArray(GL_TRIANGLES);
        TVisMathVector P1,P2,P3,P4;
        P1 = ToVec(UseSize.x/2,UseSize.y/2,-UseSize.z/2);
        P2 = ToVec(-UseSize.x/2,UseSize.y/2,-UseSize.z/2);
        P3 = ToVec(-UseSize.x/2,-UseSize.y/2,-UseSize.z/2);
        P4 = ToVec(UseSize.x/2,-UseSize.y/2,-UseSize.z/2);
        VP->Points->Add(P1,ZEROVEC,ZEROVEC);
        VP->Points->Add(P2,ZEROVEC,ZEROVEC);
        VP->Points->Add(P3,ZEROVEC,ZEROVEC);
        VP->Points->Add(P4,ZEROVEC,ZEROVEC);
        VP->AddIndex(0,0);
        VP->AddIndex(1,0);
        VP->AddIndex(2,0);
        VP->AddIndex(2,0);
        VP->AddIndex(3,0);
        VP->AddIndex(0,0);

        VP->CalcNormals();
        Slope(VP,SlopePlus,SlopeMinus);
        if (!RenPars[MyTree->ModeIndex].FLAT2D)
		  VP->Extrude(UseSize.z,1,false,NULL);
    }
    VP->CalcNormals();
    ProcessTexturing();
}
