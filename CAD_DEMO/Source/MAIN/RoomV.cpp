//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "RoomV.h"
#include "World.h"
#include "LogicNode.h"
#include "PlatformV.h"
#include "MDIMetaRoomV.h"
#include "Triangulation.h"
#include "MyGL.h"

/*#include "World.h"
#include "LogicNode.h"
#include "VisPoly.hpp"

#include "AUIV.h"
*/

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------TMetaPlatform-------------------------
TMyObject* TMetaRoom::CreateFunction()
{
    return new TMetaRoom();
}

const AnsiString aDeterminateList = AnsiString("DeterminateList");
const AnsiString aDeterminateMode = AnsiString("DeterminateMode");

TMetaRoom::TMetaRoom(TMetaNode *Parent,int _ID,const AnsiString& Name):
    TMetaElement(Parent,_ID,Name)
{
    RegisterNewClass< TMetaElement, TMetaRoom >(this,false,&CreateFunction);
    IsAuto=true;
    RegisterField(&DeterminateList,&aDeterminateList,mtMyObject);
    RegisterField(&DeterminateMode,&aDeterminateMode,mtInt);
    DeterminateMode = 1;
    ImageIndex = iiMetaRoom;
}

TMetaRoom::TMetaRoom()
{
    RegisterNewClass< TMetaElement, TMetaRoom >(this,false,&CreateFunction);
    IsAuto=true;
    RegisterField(&DeterminateList,&aDeterminateList,mtMyObject);
    RegisterField(&DeterminateMode,&aDeterminateMode,mtInt);
    DeterminateMode = 1;
    ImageIndex = iiMetaRoom;
}

void TMetaRoom::Fix_Changes(TMetaElement *MEL,TElement* UsedElement)
{
    bool CanContinue = World && World->Head && FindInPointerList(&DeterminateList,MEL) != -1;
    CanContinue = CanContinue && !World->FloorDeleted();
    if (!CanContinue)
        return;
    if (!UsedElement)
        UsedElement = (TElement*)World->Head;

    if (UsedElement->DestroyStarted)
        return;

    LN->SetDefaultMetaFilter();
    LN->DefinePermises_06(UsedElement);
    TMTList<THoledPolygon> Premises;
    Premises.Assign(&LN->Premises);
    TMTList<TMyRegObject> Rooms;
    World->SelectByCT(NULL,TRoom::StaticType,&Rooms,true,true);
    for (int i=0;i<Rooms.Count;)
        if ( !Rooms.Items[i++]->In(UsedElement) )
            Rooms.Delete(--i);

    TMDelTList<TMTList<TElement> > PRMS;
    for (int i=0;i<LN->Premises.Count;i++)
    {
        PRMS.Add( new TMTList<TElement> );
        TMDelTList<TRoutePoint>* ROUTES = LN->Premises[i].Router;
        for (int j=0;j<ROUTES->Count;j++)
            if ( PRMS[i].IndexOf(ROUTES->Items[j]->InputSide->Element) == -1 )
                PRMS[i].Add(ROUTES->Items[j]->InputSide->Element);
    }

    int k=0;
    while(k<Rooms.Count)
    {
        int index = -1;
        TRoom *R = ((TRoom*)Rooms.Items[k]);
        for (int i=0;i<PRMS.Count;i++)
            if (R->Determinators->Same(PRMS.Items[i]))
            {
                index = i;
                break;
            }
        if (index!=-1)
        {
            //------------------------------
            //помещение осталось но возможно дырок стало больше

/*            R->Exclusion->Clear();
            for (int h=0;h<EXCL->Items[index]->Count;h++)
            {
                TMTList<TElement>* newEXCL1 = new TMTList<TElement>();
                newEXCL1->Assign(EXCL->Items[index]->Items[h]);
                R->Exclusion->Add(newEXCL1);
            }*/

            R->HP->Assign(Premises.Items[index]);
            R->SetSize(R->Determinators->Items[0]->AbsSize);
            R->LocalizePolygon();
            R->Init();
            int FloorIndex = World->FloorOf((TElement*)R->Determinators->Items[0]);
            if (FloorIndex == -1)
                delete R;
            if (!GoDriver(R,World->Floors[FloorIndex].First.ADR))
                delete R;
            //------------------------------
            PRMS.Delete(index);
//            EXCL->Delete(index);
            Premises.Delete(index);
            Rooms.Delete(k);
        }
        else
            k++;
    }

    for (int jj=0;jj<Rooms.Count;jj++)
    {
/*        for (int il=0;il<((TRoom*)Rooms.Items[jj])->Determinators->Count;il++)
            if ( EL_WEB.IndexOf(((TRoom*)Rooms.Items[jj])->Determinators->Items[il])==-1 && MGT->InstantIndex(tUnit,((TRoom*)Rooms.Items[jj])->Determinators->Items[il])!=-1 )
                EL_WEB.Add(((TRoom*)Rooms.Items[jj])->Determinators->Items[il]);  */
        ((TRoom*)Rooms.Items[jj])->DeleteNeededLink();
    }


    for (int l=0;l<PRMS.Count;l++)
    {
        TRoom *Room=  (TRoom*)CreateElementFunction(World,this);
        Room->Determinators->Assign(PRMS.Items[l]);
/*        for (int i=0;i<Room->Determinators->Count;i++)
            if (EL_WEB.IndexOf(Room->Determinators->Items[i])==-1)
                EL_WEB.Add(Room->Determinators->Items[i]);  */
/*        Room->Exclusion->Clear();
        for (int h=0;h<EXCL->Items[l]->Count;h++)
        {
            TMTList<TElement>* newEXCL1 = new TMTList<TElement>();
            newEXCL1->Assign(EXCL->Items[l]->Items[h]);
            Room->Exclusion->Add(newEXCL1);
        } */
        Room->HP->Assign(Premises.Items[l]);
        Room->SetSize(Room->Determinators->Items[0]->AbsSize);
        Room->LocalizePolygon();
        Room->Init();
        int FloorIndex = World->FloorOf((TElement*)Room->Determinators->Items[0]);
        if (FloorIndex == -1)
            delete Room;
        if (!GoDriver(Room,World->Floors[FloorIndex].First.ADR))
            delete Room;
    }

    ApplyPlatformSize( CalculatePlatformSize() );
}

void TMetaRoom::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaRoom(Owner,this);
    #endif
}

//----------------------------TRoom----------------------------
TMyObject* TRoom::CreateFunction()
{
    return new TRoom();
}

const AnsiString aDeterminators = AnsiString("Determinators");
const AnsiString aFFloorServiceZ = AnsiString("FFloorServiceZ");
const AnsiString aFCeilServiceZ = AnsiString("FCeilServiceZ");

const AnsiString aFloorParam = AnsiString("FloorParam");
const AnsiString aCeilParam = AnsiString("CeilParam");
const AnsiString aStatus = AnsiString("Status");

/*TRoom::TRoom(TMainTree *_MyTree,TMetaNode *_Meta)
    :TArchitectElement(_MyTree,_Meta)
{
    RegisterNewClass< TArchitectElement, TRoom >(this,false,&CreateFunction);
    Determinators = new TMTList<TElement>();
    Exclusion = new TMDelTList <TMTList <TElement> >();
    RegisterField(Determinators,&aDeterminators,mtMyObject);
    RegisterField(&FloorParam,&aFloorParam,mtMyObject);
    RegisterField(&CeilParam,&aCeilParam,mtMyObject);
    RegisterField(&Status,&aStatus,mtInt);
    Status = 1;
    rFloor = new TVisPrimitiveObj(NULL);
    rFloor->AutoCalcNormals=false;
    rFloor->Transformation->Order = toTraRotSca;
    rFloor->Transformation->Rotation->Order = roZXY;
    rFloor->Material = RenPars[MyTree->ModeIndex].UseMaterial;
    if (RenPars[MyTree->ModeIndex].Texture)
    {
        rFloor->Texture = RenPars[MyTree->ModeIndex].UseTexture;
        rFloor->Textured = true;
    }
    rCeil = new TVisPrimitiveObj(NULL);
    rCeil->AutoCalcNormals=false;
    rCeil->Transformation->Order = toTraRotSca;
    rCeil->Transformation->Rotation->Order = roZXY;
    rCeil->Material = RenPars[MyTree->ModeIndex].UseMaterial;
    rCeil->Texture = NULL;
    rCeil->Textured = false;

    RoomRender = new TVisNode(NULL);
    RoomRender->Transformation->Order = toTraRotSca;
    RoomRender->Transformation->Rotation->Order = roZXY;
    RoomRender->Add(rCeil);
    RoomRender->Add(rFloor);
    MGT->AddRender(1,this,RoomRender);
    FFloorServiceZ = (MyTree->ActiveFloor)? (MyTree->ActiveFloor->Down_Lost): 0;
    FCeilServiceZ = (MyTree->ActiveFloor)? (MyTree->ActiveFloor->Up_Lost) : 0;
    CreateView();
    CurrentEnabled = true;
    CustomEnabled = true;
}*/

TRoom::TRoom()
{
    RegisterNewClass< TArchitectElement, TRoom >(this,false,&CreateFunction);
    Determinators = new TMTList<TElement>();
    Exclusion = new TMDelTList <TMTList <TElement> >();
//    RegisterField(Determinators,&aDeterminators,mtMyObject);
    RegisterField(&FloorParam,&aFloorParam,mtMyObject);
    RegisterField(&CeilParam,&aCeilParam,mtMyObject);
    RegisterField(&Status,&aStatus,mtInt);
    Status = 1;

    rFloor = new TVisPrimitiveObj(NULL);
    rFloor->AutoCalcNormals=false;
    rFloor->Transformation->Order = toTraRotSca;
    rFloor->Transformation->Rotation->Order = roZXY;

    rCeil = new TVisPrimitiveObj(NULL);
    rCeil->AutoCalcNormals=false;
    rCeil->Transformation->Order = toTraRotSca;
    rCeil->Transformation->Rotation->Order = roZXY;

    RoomRender = new TVisNode(NULL);
    RoomRender->Transformation->Order = toTraRotSca;
    RoomRender->Transformation->Rotation->Order = roZXY;
    RoomRender->Add(rCeil);
    RoomRender->Add(rFloor);
    FFloorServiceZ = 0;
    FCeilServiceZ = 0.25;
    
}


TRoom::~TRoom()
{
    delete Determinators;
    delete Exclusion;

    RemoveRenderFromTree();
    delete rCeil;
    delete rFloor;
    delete RoomRender;
}

void TRoom::SetCeilServiceZ(MBTi Value)
{
    AboutToChange(&FCeilServiceZ);
    FCeilServiceZ = Value;
    Changed(&FCeilServiceZ);
}

void TRoom::SetFloorServiceZ(MBTi Value)
{
    AboutToChange(&FCeilServiceZ);
    FFloorServiceZ = Value;
    Changed(&FCeilServiceZ);
}

void PolygonFromOneToTwo(TElement* One,TElement* Two,TPolygon* HP)
{
    for (int i=0;i<HP->Vertex->Count;i++)
    {
        Two->AbsFromLocal( *(HP->Vertex->Items[i]),*(HP->Vertex->Items[i]) );
        One->LocalFromAbs( *(HP->Vertex->Items[i]),*(HP->Vertex->Items[i]) );
    }
}

void CreateCrossingObject(TRoom* One,TPlatform* Two, TVisPrimitiveObj* Obj, MBTi Z,bool Invert)
{
    if ( !Two->Is(TPlatform::StaticType))
        return;//исключить крышу
    THoledPolygon ELSEHP;
    Two->FillCompletePolygon(&ELSEHP);
    PolygonFromOneToTwo(One,Two,&ELSEHP);
    for (int i=0;i<ELSEHP.Holes->Count;i++)
        PolygonFromOneToTwo(One,Two,ELSEHP.Holes->Items[i]);

    TMTList<THoledPolygon> HPL;
    HPL.Add(&ELSEHP);
    HPL.Add(One->HP);
    TMTList<TIntVec>* Triangles = Delone.Triangulate2(&HPL,mpoAND);
    int Start = Invert ? Triangles->Count-1 : 0;
    int End = Invert ? -1 : Triangles->Count;
    int Add = Invert ? -1 : 1;
    if (Obj->PrimitiveCount == 0)
        Obj->AddPrimitiveArray(GL_TRIANGLES);

    for (int i=Start;i!=End;i+=Add)
    {
        TIntVec* Vec = Triangles->Items[i];
        int index = Obj->Points->Add(Vec->x,Vec->y,Z);
        Obj->AddIndex(index,Obj->PrimitiveCount-1);
    }
}

void TRoom::StandartCreateView()
{
    rCeil->Init();
    rFloor->Init();
    if ( !TotalAllowAdvancedTexture )
      return;
    //floor
    TMTList<TPlatform> FloorPlatforms;
    TMTList<TPlatform> CeilPlatforms;
    for (int i=0;i<FLinks.Count;i++)
        if (!FLinks[i].NeededFor(this) && !FLinks[i].NeededFor(FLinks[i].OtherElement(this) ))
        {
            if (AbsPos.z < FLinks[i].OtherElement(this)->AbsPos.z)
                CeilPlatforms.Add((TPlatform*)FLinks[i].OtherElement(this));
            else
                FloorPlatforms.Add((TPlatform*)FLinks[i].OtherElement(this));
        }
    for (int i=0;i<CeilPlatforms.Count;i++)
        CreateCrossingObject(this,CeilPlatforms.Items[i],rCeil,AbsSize.z/2 - FCeilServiceZ-0.01,true);
    for (int i=0;i<FloorPlatforms.Count;i++)
        CreateCrossingObject(this,FloorPlatforms.Items[i],rFloor,-AbsSize.z/2+FFloorServiceZ+0.01,false);

    rCeil->CalcNormals();
    rFloor->CalcNormals();
    ProcessTexturing();
    //---------------------------
    FAdvancedTextured = true;
    //---------------------------
}

void TRoom::ProcessTexturing()
{
    TextureObject(rFloor,FloorParam);
    TextureObject(rCeil,CeilParam);
    NeedTexturing = false;
}

void TRoom::FloorCeilArea()
{
    TMTList<TPlatform> FloorPlatforms;
    TMTList<TPlatform> CeilPlatforms;
    for (int i=0;i<FLinks.Count;i++)
        if (!FLinks[i].NeededFor(this) &&
            !FLinks[i].NeededFor(FLinks[i].OtherElement(this) ) &&
            FLinks[i].OtherElement(this)->Is(TPlatform::StaticType) )
        {
            if (AbsPos.z < FLinks[i].OtherElement(this)->AbsPos.z)
                CeilPlatforms.Add((TPlatform*)FLinks[i].OtherElement(this));
            else
                FloorPlatforms.Add((TPlatform*)FLinks[i].OtherElement(this));
        }
    CeilParam.Area = 0;
    for (int i=0;i<CeilPlatforms.Count;i++)
    {
        THoledPolygon ELSEHP;
        CeilPlatforms[i].FillCompletePolygon(&ELSEHP);
        PolygonFromOneToTwo(this,CeilPlatforms.Items[i],&ELSEHP);
        for (int i=0;i<ELSEHP.Holes->Count;i++)
            PolygonFromOneToTwo(this,CeilPlatforms.Items[i],ELSEHP.Holes->Items[i]);

        TMTList<THoledPolygon> HPL;
        HPL.Add(&ELSEHP);
        HPL.Add(HP);
        TMTList<TIntVec>& TRI = *(Delone.Triangulate2(&HPL,mpoAND));
        for (int k=0;k<TRI.Count;k+=3)
            CeilParam.Area += CalcTriangleArea(TRI[k],TRI[k+1],TRI[k+2],2);
    }
    FloorParam.Area=0;
    for (int i=0;i<FloorPlatforms.Count;i++)
    {
        THoledPolygon ELSEHP;
        FloorPlatforms[i].FillCompletePolygon(&ELSEHP);
        PolygonFromOneToTwo(this,FloorPlatforms.Items[i],&ELSEHP);
        for (int i=0;i<ELSEHP.Holes->Count;i++)
            PolygonFromOneToTwo(this,FloorPlatforms.Items[i],ELSEHP.Holes->Items[i]);
        TMTList<THoledPolygon> HPL;
        HPL.Add(&ELSEHP);
        HPL.Add(HP);
        TMTList<TIntVec>& TRI = *(Delone.Triangulate2(&HPL,mpoAND));
        for (int k=0;k<TRI.Count;k+=3)
            FloorParam.Area += CalcTriangleArea(TRI[k],TRI[k+1],TRI[k+2],2);
    }
    ATVChanged = false;
}

MBTi TRoom::GetFloorArea()
{
    if (ATVChanged)
        FloorCeilArea();
    return FloorParam.Area;
}

MBTi TRoom::GetCeilArea()
{
    if (ATVChanged)
        FloorCeilArea();
    return CeilParam.Area;
}


void TRoom::ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID)
{
    if ( Object->Is(TMetaTexture::StaticType) )
    {
        TMetaTexture* MT = (TMetaTexture*)Object;
        if (Render == rCeil)
        {
            CeilParam.Texture = MT;
        }
        else
        {
            FloorParam.Texture = MT;
        }
        RegisterTexturing(NULL);
    }
}

bool TRoom::Init()
{
//    if (!TElement::Init())
  //      return false;
//    LocalizePolygon();
    TIntVec Pos = AbsPos;
    if (Determinators->Count)
        Pos.z = Determinators->Items[0]->AbsPos.z;
    UserChangePosition(Pos-AbsPos,ZEROINTVEC);
//    RunElementTrigger(trChangeSize);
    //пока высота стен может быть разной
    //но связки таковы что стены соединяются если высота одинаковая
/*    ChangeSize(Determinators->Items[0]->AbsSize-AbsSize,ZEROINTVEC);
    TIntVec Pos = HP->Center();
    Pos.z = Determinators->Items[0]->AbsPos.z+Determinators->Items[0]->AbsSize.z/2;
    HP->Move(MINUSINTVEC*Pos);

    Pos.z = Determinators->Items[0]->AbsPos.z;
    UserChangePosition(Pos-AbsPos,ZEROINTVEC);  */

//    Pos.z = Determinators->Items[0]->AbsPos.z;
/*    int zptind = Description.Pos(AnsiString(","));
    if (zptind!=0)
        Description.Delete(zptind,Description.Length()-zptind+1);
    Description = Description+ AnsiString(",   ")+FLOATTOSTR(RoundTo(HP->Area(atCentral),-2))+AnsiString(" m");
*/
//    TLabel3D *L = CreateLabel(false);
//    L->Enable(true);
    return true;
}
