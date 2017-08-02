//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "PlatformV.h"
#include "MDIMetaPlatformV.h"
#include "MyGL.h"
#include "AUIV.h"
#include "MDI3DV.h"
#include "World.h"
#include "Triangulation.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//---------------------------TMetaPlatform-------------------------
TMyObject* TMetaPlatform::CreateFunction()
{
    return new TMetaPlatform();
}

const AnsiString aFirst = AnsiString("First");
const AnsiString aLand = AnsiString("Land");

TMetaPlatform::TMetaPlatform(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
:TMetaElement (_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaElement, TMetaPlatform >(this,false,&CreateFunction);
//    ChildType = c;
    RegisterField(&First,&aFirst,mtBool);
    RegisterField(&Land,&aLand,mtBool);
    First = false;
    Land = false;
    ImageIndex = iiMetaPlatform;
}

TMetaPlatform::TMetaPlatform()
{
    RegisterNewClass< TMetaElement, TMetaPlatform >(this,false,&CreateFunction);
    RegisterField(&First,&aFirst,mtBool);
    RegisterField(&Land,&aLand,mtBool);
    First = false;
    Land = false;
    ImageIndex = iiMetaPlatform;
}


void TMetaPlatform::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaPlatform(Owner,this);
    #endif
}


//------------------------TPlatform--------------------------------------------------

MBTi AngleRadZX(const TIntVec& P0,const TIntVec& P1)
{
    TIntVec _P0(P0.x,P0.z,0);
    TIntVec _P1(P1.x,P1.z,0);
    return AngleRadOX(_P0,_P1);
}

void VecTo2D(TIntVec& Vec,TIntVec& Vec2,const TIntVec& AngleXY,const TIntVec& AngleZY,const TIntVec& RotCenter)
{
    Vec2 = RotateAround(Vec,AngleXY,RotCenter);
    Vec2 = RotateAround(Vec2,AngleZY,RotCenter);
}

void VecTo3D(TIntVec& Vec,TIntVec& Vec2,const TIntVec& AngleXY,const TIntVec& AngleZY,const TIntVec& RotCenter)
{
    Vec2 = RotateAround(Vec,AngleZY,RotCenter);
    Vec2 = RotateAround(Vec2,AngleXY,RotCenter);
}

TMyObject* TPlatform::CreateFunction()
{
    return new TPlatform();
}

/*TPlatform::TPlatform(TMainTree *_MyTree,TMetaNode *_Meta)
    :TArchitectElement(_MyTree,_Meta)
{
    RegisterNewClass< TArchitectElement, TPlatform >(this,false,&CreateFunction);
    if (typeid(*_Meta)!=typeid(TMetaPlatform))
    {
        Application->MessageBox("Ожидалось MetaPlatform, получено Unknown. Приложение СТОП.","Error");
        Application->Terminate();
        return;
    }
    POL = new TVisCustomObj(NULL);
    POL->AutoCalcNormals=false;
//    POL->InitClearPoints = true;
    POL->Transformation->Order = toTraRotSca;
    POL->Transformation->Rotation->Order = roZXY;
    MGT->AddRender(1,this,POL);
    ClearPoints();
    AddArrPoint(TIntVec(AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(-AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(-AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
    CreateView();
    CurrentEnabled = true;
    CustomEnabled = true;
} */

void TPlatform::SetMetaObject(TMyRegObject* aMetaObject)
{
    bool LoadDefaults = FMETAGUID.IsEmpty();
    TElement::SetMetaObject(aMetaObject);
    if (LoadDefaults)
    {
        ClearPoints();
        AddArrPoint(TIntVec(AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(-AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(-AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
    }
}

TPlatform::TPlatform()
{
    RegisterNewClass< TArchitectElement, TPlatform >(this,false,&CreateFunction);
    POL = new TVisCustomObj(NULL);
    POL->AutoCalcNormals=false;
    POL->Transformation->Order = toTraRotSca;
    POL->Transformation->Rotation->Order = roZXY;
//    MGT->AddRender(1,this,POL);
}

bool TPlatform::Init()
{
    if (!TElement::Init())
        return false;
    if ((NeededLink!=-1)&&FLinks[NeededLink].MyMeta->Link->Client)
        CreateClient(FLinks[NeededLink].Elements[0]);
    return true;
}

TPlatform::~TPlatform()
{
    RemoveRenderFromTree();
    delete POL;
}

void TPlatform::FillCompletePolygon(THoledPolygon* CP)
{
    CP->Clear();
    CP->Vertex->Assign( HP->Vertex );
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


void TPlatform::StandartCreateView()
{
    if (MetaPlatform->First || MetaPlatform->Land)
    {
        ClearPoints();
        AddArrPoint(TIntVec(AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(-AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(-AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
        AddArrPoint(TIntVec(AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
        if ( AUI.ActiveView && MetaPlatform->First)
            switch(AUI.ActiveView->CurSet->NetLine)
            {
                case nLine:
                {
                    CreateNetLine(POL,AUI.ActiveView->CurSet->NetSize,TIntVec(AUI.ActiveView->CurSet->STEP,AUI.ActiveView->CurSet->STEP,0.25));
                    POL->Material = RenPars[MyTree->ModeIndex].UseMaterial;
                    POL->CalcNormals();
                    POL->Texture = NULL;
                    POL->Textured = false;
                    return;
                }
                case nPoint:
                {
                    CreateNetPoint(POL,AbsSize,TIntVec(AUI.ActiveView->CurSet->STEP,AUI.ActiveView->CurSet->STEP,0.25));
                    POL->Material = RenPars[MyTree->ModeIndex].UseMaterial;
                    POL->CalcNormals();
                    POL->Texture = NULL;
                    POL->Textured = false;
                    return;
                }
            };
    }
    //---------------------------------------------
    //проверим параллельна ли плоскость земле
    TMDelTList<TIntVec>& PL = *(HP->Vertex);
    TIntVec Platform_Normal = ZEROINTVEC;
    for (int i=1;i<PL.Count;i++ )
        if ( !IsLinesParallel(PL[0],PL[1],PL[0],PL[i],0.00001 ) )
        {
            Platform_Normal = VectorP ( PL[i] - PL[0], PL[1] - PL[0] );
            break;
        }
    if ( Platform_Normal.Length()<0.00001 )
    {
        void StdOut(const AnsiString& Str,bool opClear = false);
        StdOut("TPlatform::StandartCreateView has not been done");
        return;
    }

    Platform_Normal = Platform_Normal.Normalize();
    TIntVec N_Z1 = TIntVec(0,0,1);
    bool Ground_Parallel = ((Platform_Normal-N_Z1).Length()<0.01) || ((Platform_Normal+N_Z1).Length()<0.01);
    //---------------------------------------------
    THoledPolygon CHP;
    FillCompletePolygon(&CHP);
    TMTList<TIntVec>& Triangles = *(Delone.Triangulate(&CHP));

  //-----------------------------
  TIntVec UseSize(AbsSize);
  if (RenPars[MyTree->ModeIndex].OverSizeMode)
    UseSize += RenPars[MyTree->ModeIndex].OverSize;
  //-----------------------------

    POL->Init();
    POL->AddPrimitiveArray(GL_TRIANGLES);
    //----------------------
        //for (int i=Triangles.Count-1;i>=0;i--)
        for (int i=0;i<Triangles.Count;i++)
        {
            int index;
            if (Ground_Parallel)
                index = POL->Points->Add(ToVec(Triangles[i].x,Triangles[i].y,-(UseSize.z/2)),ZEROVEC,ZEROVEC);
            else
            {
                TIntVec CP;
                PlaneCrossPoint(PL[0],Platform_Normal,(Triangles[i]-N_Z1),(Triangles[i]+N_Z1),CP);
                index = POL->Points->Add(ToVec(Triangles[i].x,Triangles[i].y,CP.z-(UseSize.z/2)),ZEROVEC,ZEROVEC);
            }
            POL->AddIndex(index);
        }

    //----------------------
    POL->CalcNormals();
    //----------------------
    for (int i=0;i<RenPars.Count;i++)
    {
        RenPars[i].TexCenter = *(HP->Vertex->CycleItems[SideRender]);
        RenPars[i].TexAngle.z = AngleRadOX(*(HP->Vertex->CycleItems[SideRender]),*(HP->Vertex->CycleItems[SideRender+1]))*180/M_PI;
    }
    if ( !RenPars[MyTree->ModeIndex].FLAT2D )
    {
        POL->Extrude(UseSize.z,1,false,NULL);//+0.005,1,false,NULL);
        POL->CalcNormals();
    }
   //--------------------------------------------------------------------------
    ProcessTexturing();
    //--------------------------------------------------------------------------
    RegisterUpdatePos(NULL);
}

void ApplyPlatformSize(const TIntVec& SIZE)
{
    if (!World)
        return;
    for (int i=0;i<World->Clients.Count;i++)
        if ( IS(World->Clients[i].MDI3D,__classid(TMDI3D)) )
            ((TMDI3D*)World->Clients[i].MDI3D)->ViewSet3D.NetSize = SIZE;

    for (int i=0;i<World->Floors.Count;i++)
        World->Floors[i].First.ADR->ForceCreateView();
}
