//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ElementV.h"
#include "World.h"
#include "LogicNode.h"
#include "Select.h"
#include "TasksQueueV.h"
#include "MyGL.h"
#include "MySupportV.h"
#include "Label3DV.h"
#include "AUIV.h"
#include "Driver.h"
#include "TasksQueueV.h"
#include "VisLabel.hpp"
#include "LuaModuleV.h"
#include "LuaAttributeV.h"
#include "..\GeomObject\TGObject.h"
#include "..\GeomObject\TGPrimitive.h"
#include "..\GeomObject\Misc.h"
#include "CustomElementV.h"

#pragma package(smart_init)

TClassNode* TLink::StaticType = NULL;
TClassNode* TElement::StaticType = NULL;
__int64     TElement::TotalCount = 0;
TClassNode* THoleClient::StaticType = NULL;
TClassNode* TUnit::StaticType = NULL;

//---------------------------------------------------------------------------
TElement *CurElement = NULL;
TLink *CurLink = NULL;
//--------------------cache-------------------------------------
T3DScopeMem *T3DScopeCache::Find(void *_Object)
{
    for (int i=0;i<SCM.Count;i++)
        if (SCM[i].FObject == _Object)
            return &(SCM[i]);

    T3DScopeMem *MM = new T3DScopeMem();
    MM->FObject = _Object;
    MM->Inited = false;
    SCM.Add(MM);
    return MM;
}

void T3DScopeCache::SetFalse()
{
    for (int i=0;i<SCM.Count;i++)
		SCM[i].Inited=false;
}

void T3DScopeCache::SetTrue(void *_Object)
{
    Find(_Object)->Inited = true;
}

AnsiString CutMeta(const AnsiString& _MetaName)
{
    AnsiString _Name = _MetaName;
    int ind = _Name.AnsiPos("Meta");
    if (ind!=0)
        _Name.Delete(ind,4);
    else
        _Name = AnsiString();
    return(_Name);
}

//--------------------------------------------------------------------------
TElement *CreateElementFunction(TMainTree *_Tree,TMetaNode* MetaNode)
{
    AnsiString ClassType = CutMeta(MetaNode->DynamicType->Name).Trim();
    TElement *Un = (TElement *)Create_Default_Constructor( CutMeta(MetaNode->DynamicType->Name) );
    Un->MyTree = _Tree;
    Un->MetaObject = MetaNode;
    Un->DynamicType->RegisterNewInstance(Un);
    Un->UndoRegister(rmCreated);
    Un->CheckFields();
    Un->Init();


    if (Un==NULL)
    {
        Application->MessageBoxA("Error","Can not retrieve object",MB_OK);
        Application->Terminate();
    }
    else if (ClassType!=cUnit)
    {
        if (World && World->ActiveFloor)
            ((TElement*)Un)->UserChangePosition(TIntVec(0,0,((TElement*)Un)->MyMeta->StartZED + World->ActiveFloor->AbsZ-((TElement*)Un)->AbsPos.z),ZEROINTVEC);
        ((TElement*)Un)->RunElementTrigger(trCreate);
        Un->DynamicType->RegisterRender( ((TElement*)Un),((TElement*)Un)->MyRender() );
    }
    return(Un);
}

//--------------------------------------------------------------------------
TElement *CreateElementFunctionNotReg(TMainTree *_Tree,TMetaNode* MetaNode)
{
    AnsiString ClassType = CutMeta(MetaNode->DynamicType->Name).Trim();
    TElement *Un = (TElement *)Create_Default_Constructor( CutMeta(MetaNode->DynamicType->Name) );
    Un->MyTree = _Tree;
    Un->MetaObject = MetaNode;
    Un->CheckFields();
    Un->Init();

    if (Un==NULL)
    {
        Application->MessageBoxA("Error","Can not retrieve object",MB_OK);
        Application->Terminate();
    }
    else if (ClassType!=cUnit)
    {
        if (World && World->ActiveFloor)
            ((TElement*)Un)->UserChangePosition(TIntVec(0,0,((TElement*)Un)->MyMeta->StartZED + World->ActiveFloor->AbsZ-((TElement*)Un)->AbsPos.z),ZEROINTVEC);
        ((TElement*)Un)->RunElementTrigger(trCreate);
        if ( !Un->GUID.IsEmpty() )
            Un->DynamicType->RegisterRender( ((TElement*)Un),((TElement*)Un)->MyRender() );
    }
    return(Un);
}

TElement *CreateElementFunction(TMainTree *_Tree,int _METAID)
{
    return CreateElementFunction(_Tree,_METAID);
}

TLink* CreateLink(TDynamicLink *_Meta,TElement *Target,TElement *Source,const TIntVec &AbsCrossPoint)
{
    TLink* Link = new TLink(_Meta,Target,Source,AbsCrossPoint);
    Link->DynamicType->RegisterNewInstance(Link);
    Link->UndoRegister(rmCreated);
    return Link;
}


TLink* CreateLinkFunction(TElement* EL0,TElement* EL1,TDynamicLink* DynamicLink,const TIntVec& AbsPoint)
{
    TElement* Target = NULL;
	TElement* Source = NULL;
    if (!EL0 || !EL1 || !DynamicLink)
        throw EMyException("<CreateLinkFunction>: One of function arguments is missed.");
    if (DynamicLink->El0 == EL0->MyMeta)
        Target = EL0;
    else if (DynamicLink->El0 == EL1->MyMeta)
        Target = EL1;
    if (DynamicLink->El1 == EL0->MyMeta)
        Source = EL0;
    else if (DynamicLink->El1 == EL1->MyMeta)
        Source = EL1;
    if (!Source || !Target)
        throw EMyException("<CreateLinkFunction>: EL0 or EL1 is missed");
    if (DynamicLink->Needed && Source->NeededLink!=-1)
    {
        Source->DoNotDelete = true;
        Source->KillLink(Source,Source->NeededLink);
        Source->DoNotDelete = false;
    }
    return CreateLink(DynamicLink,Target,Source,AbsPoint);
}

void TElement::KillFunction()
{
    UndoRegister(rmDeleted);
    TUnit::KillFunction();
}

void KillElement(TElement* Element)
{
	Element->KillFunction();
//    Element->UndoRegister(rmDeleted);

/*void DeleteElement(TElement* El,bool UpdatePremises,TElement* Floor)
{
    if (World)
        World->CheckPremises = true;
    try
    {
        try
        {
            if (!World)
            {
                delete El;
                return;
            }
            if (UpdatePremises && !Floor)
            {
                int index = World->FloorOfUseDriver(El);
                if (index!=-1)
                    Floor = World->Floors[index].First.ADR;
            }
            World->CheckPremises = false;
            delete El;
            World->CheckPremises = true;
            if (UpdatePremises && !Floor)
                throw EMyException("Floor is not selected");
            if (UpdatePremises)
                World->Process_AddElement(El->MyMeta,Floor);
        }
		__except(EXCEPTION_EXECUTE_HANDLER)
        {
            throw EMyException("Can not delete element");
        }
    }
    catch(EMyException)
    {
        if (World)
            World->CheckPremises = true;
    }
}
*/
}

int BackDigits(const AnsiString &Word)
{
    AnsiString DIG = AnsiString();
    for (int i = Word.Length();i>=1;i--)
        if (DIGITS.Pos(Word[i])!=0)
            DIG = AnsiString(Word[i]) + DIG;
        else
            break;
    if (DIG.IsEmpty())
        return 0;
    else
        return(DIG.ToInt());
}

//--------------------------------------------------------------------------
const AnsiString aMETAGUID = AnsiString("METAGUID");
TMyObject* TUnit::CreateFunction()
{
    return new TUnit();
}

void TUnit::SetMETAGUID(const AnsiString& aMETAID)
{
        TMyRegObject* MRO = (TMetaNode*)TMetaNode::StaticType->RecurrentFindByGUID(aMETAID);
    if (MRO)
        SetMetaObject( MRO );
}

void TUnit::SynchronizeAttributes()
{
    for (int i=0;i<FMetaObject->Attributes->Count;i++)
    {
        bool Add = true;
        for (int j=0;j<Attributes->Count;j++)
            if (Attributes->Items[j]->Name == FMetaObject->Attributes->Items[i]->Name)
            {
                if ( Attributes->Items[j]->Type != FMetaObject->Attributes->Items[i]->Type )
                {
                    Attributes->Items[j]->Type = FMetaObject->Attributes->Items[i]->Type;
                    Attributes->Items[j]->VALUE = FMetaObject->Attributes->Items[i]->VALUE;
                }
                Add = false;
                break;
            }
        if (Add)
        {
			Attributes->Add(new TLuaAttribute());
            Attributes->Last()->Assign(FMetaObject->Attributes->Items[i]);
            Attributes->Last()->VALUE = FMetaObject->Attributes->Items[i]->VALUE;
        }
    }
    for (int j=0;j<Attributes->Count;j++)
        Attributes->Items[j]->ReadOnly = false;
}


void TUnit::SetMetaObject(TMyRegObject* aMetaObject)
{
    if (!aMetaObject)
        throw EMyException("<TUnit::SetMetaObject>:Attempt to assign <NULL> to FMetaObject");
    if  (   ((DynamicType != TLink::StaticType) && (DynamicType->Name != CutMeta( aMetaObject->DynamicType->Name))) ||
            (DynamicType == TLink::StaticType && aMetaObject->DynamicType != TDynamicLink::StaticType)
        )
    {
        AnsiString Str = AnsiString("An instance of class <") + DynamicType->Name;
        Str += AnsiString("> can not have instance of class <");
        Str += aMetaObject->DynamicType->Name + AnsiString("> as metaobject.");
        throw EMyException(Str);
    }
    bool LoadDefaults = FMETAGUID.IsEmpty();
    FMETAGUID = aMetaObject->GUID;
    FMetaObject = aMetaObject;
    if (LoadDefaults)
    {
        Name = aMetaObject->Name;
        SynchronizeAttributes();
	}
}


TUnit::TUnit()
{
    UndoRegistered = false;
    RegisterNewClass< TMyRegObject, TUnit >(this,false,&CreateFunction);
    FMetaObject = NULL;
    RegisterField(&FMETAGUID,&aMETAGUID,mtString);
}

void TUnit::UndoRegister(TRegisterMode RM)
{
    if ( (!UndoRegistered || RM == rmDeleted) && !GUID.IsEmpty() )
        UndoRegistered = UndoStack.Register(this,RM);
}


bool TUnit::CheckFields()
{
    if (!TMyRegObject::CheckFields())
        return false;
    if (!MetaObject)
        MetaObject = (TMetaNode*)TMetaNode::StaticType->RecurrentFindByGUID(METAGUID);
    return (MetaObject!=NULL);
}

TMyObject* THoleClient::CreateFunction()
{
	return new THoleClient();
}

const AnsiString aClient = AnsiString("Client");
const AnsiString aHole = AnsiString("Hole");

THoleClient::THoleClient(TPolygon* _Hole,TElement* El)
{
    RegisterNewClass< TMyObject, THoleClient >(this,false,&CreateFunction);
    Hole = _Hole;
    Client.ADR = El;
    RegisterField(Hole,&aHole,mtMyObject);
    RegisterField(&Client,&aClient,mtMyObject);
}

THoleClient::THoleClient()
{
    RegisterNewClass< TMyObject, THoleClient >(this,false,&CreateFunction);
    Hole = new TPolygon();
    RegisterField(Hole,&aHole,mtMyObject);
    RegisterField(&Client,&aClient,mtMyObject);
}

THoleClient::~THoleClient()
{
    delete Hole;
}
const AnsiString aHP = AnsiString("HP");
const AnsiString aFAbsPos = AnsiString("FAbsPos");
const AnsiString aFAbsSize = AnsiString("FAbsSize");
const AnsiString aFAbsAngle = AnsiString("FAbsAngle");
const AnsiString aSideRender = AnsiString("SideRender");
const AnsiString aCanDriver = AnsiString("CanDriver");

const AnsiString aFMyRect = AnsiString("FMyRect");
const AnsiString aRectElementID = AnsiString("RectElementID");

const AnsiString aLinkHoles = AnsiString("LinkHoles");
const AnsiString aHoleElement = AnsiString("HoleElement");

const AnsiString aFragSet = AnsiString("FragSet");
const AnsiString aAdvancedTextureView = AnsiString("AdvancedTextureView");
const AnsiString aRenPars = AnsiString("RenPars");

TMyObject* TElement::CreateFunction()
{
    return new TElement();
}

void TElement::Changed(void* Sender)
{
    if (Sender == &AbsSize)
    {
        //чтобы не слали сообщения
        AbsSize.MyObjectParent = NULL;
        for (int i=0;i<3;i++)
            if (AbsSize.a[i]<MyMeta->Size.LOW.a[i])
                AbsSize.a[i] = MyMeta->Size.LOW.a[i];
            else if (AbsSize.a[i]>MyMeta->Size.HI.a[i])
                AbsSize.a[i] = MyMeta->Size.HI.a[i];
		if (MyMeta->Size.STEP.Hard)
            _Discrete(MyMeta->Size.LOW, MyMeta->Size.STEP.BaseStep.XYZ_Multiply(MyMeta->Size.STEP.DefMulti),AbsSize);
        AbsSize.MyObjectParent = this;
        if (MyMeta->InWeb)
            LN->Changed(this);
        SIZECACHE.SetFalse();
    }
    else if (Sender == &AbsAngle)
    {
        AbsAngle.MyObjectParent = NULL;
        AbsAngle = AbsAngle % 360;
        for (int i=0;i<3;i++)
        {
            if (AbsAngle.a[i]<0)
                AbsAngle.a[i] = AbsAngle.a[i]+360;
        }
        AbsAngle.MyObjectParent = this;
        if (MyMeta->InWeb)
            LN->Changed(this);
        UpgradeChildsPosition();
    }
    else if (Sender == &AbsPos)
    {
        if (MyMeta->InWeb)
            LN->Changed(this);
        UpgradeChildsPosition();
    }
}

void TElement::AboutToChange(void* Sender)
{
    TUnit::AboutToChange(Sender);
    //RegisterInUNDO
    UndoRegister(rmChanged);
    //RegisterInDriver;
    //сначала целевые
    if (!NeedUpdatePos)
        if ( Sender == &AbsPos || Sender == &AbsAngle)
        {
            RegisterUpdatePos();
            return;
        }
    if (!NeedCreateView)
        if (    Sender == &AbsSize                      ||
                Sender == HP                            ||
                Sender == &SlopeMinus                   ||
                Sender == &SlopePlus                    ||
                Sender == &SlopePlusParam               ||
                Sender == &SlopeMinusParam              ||
                Sender == &HoleElement                  ||
                Sender == &LinkHoles                    ||
                Sender == &FragSet                      /*||
                Sender == &AdvancedTextureView          ||*/
                )
        {
            RegisterCreateView();
            return;
        }
    if (!NeedTexturing)
        if ( Sender == &RenPars )
		{
            RegisterTexturing();
            return;
        }
}

void TElement::SetMetaObject(TMyRegObject* aMetaObject)
{
    bool LoadDefaults = FMETAGUID.IsEmpty();
    if (MyMeta && MyMeta->InWeb)
        LN->UnRegElem(this);
    //----------------------------------------------------------------------
    TUnit::SetMetaObject(aMetaObject);
    //----------------------------------------------------------------------
    if (MyMeta->InWeb)
        LN->RegElem(this);

    if (LoadDefaults)
    {
        SetSize(MyMeta->Size.DEFAULT);
        Description = MyMeta->Description+AnsiString(" ")+IntToStr(BackDigits(Name));
        SynchronizeRenderParams();
    }
    CurrentEnabled = true;
    CustomEnabled = true;
    //----------------------------------------------------------------------
}

TElement::TElement()
{
	RegisterNewClass< TUnit, TElement >(this,false,&CreateFunction);
    IntId = TotalCount++;
    //реально мы не знаем будет ли регится элемент
    //поэтому коментарим UndoRegister(rmCreated);
    ATVChanged = true;
    FAdvancedTextureView = true;
    FAdvancedTextured = false;
    ElementPoints = NULL;

    NeedCreateView=false;
    NeedUpdatePos=false;
    NeedTexturing=false;

    FEnabled[0] = true;
    FEnabled[1] = true;
    HP = new THoledPolygon();
    //UseFragsNow = false;
    DoNotDelete = false;
    DestroyStarted=false;
    SideRender=0;
    CanDriver = true;

    FMyTree = NULL;

    //----------------------------------------------------------------------
    RegisterField(HP,&aHP,mtMyObject);
    //----------------------------------------------------------------------
    RegisterField(&AbsPos,&aFAbsPos,mtIntVec);
    RegisterField(&AbsSize,&aFAbsSize,mtIntVec);
    RegisterField(&AbsAngle,&aFAbsAngle,mtIntVec);
	RegisterField(&SideRender,&aSideRender,mtInt);
    RegisterField(&CanDriver,&aCanDriver,mtBool);
//    RegisterField(&LinkHoles,&aLinkHoles,mtMyObject);
//    RegisterField(&HoleElement,&aHoleElement,mtMyObject);
    //----------------------------------------------------------------------
    RegisterField(&FragSet,&aFragSet,mtMyObject);
    RegisterField(&AdvancedTextureView,&aAdvancedTextureView,mtBool);
    RegisterField(&RenPars,&aRenPars,mtMyObject);

    LinkHoles.MyObjectParent = this;
    SlopePlus.MyObjectParent = this;
    SlopeMinus.MyObjectParent = this;
}


void TElement::ProcessCreateView()
{
  //-----------------------------
    FAdvancedTextured = false;
  //-----------------------------
  
    RunElementTrigger(trChangeSize);
    SetMyHoleFor(HoleElement.ADR);

    if (!RunElementTrigger(trConstruct))
        StandartCreateView();
    /* TODO : Проверка на вхождение в Select, чтобы апдейтить его */        
    /*
    if (Select->Element == this)
        Select->CreateSelectView();
	if (Select->ErrElement == this)
        Select->CreateErrView();
    */
    NeedCreateView = false;
}

void TElement::ProcessUpdatePos()
{
    if (MyRender())
    {
        AssignVisVec(*(MyRender()->Transformation->Rotation),AbsAngle);
        AssignVisVec(*(MyRender()->Transformation->Translation),AbsPos);
        if ( RenPars[MyTree->ModeIndex].OverPosMode )
            MyRender()->Transformation->Translation->Z = AbsPos.z + RenPars[MyTree->ModeIndex].OverPos.z - AbsSize.z/2;
    }
    /* TODO : Проверка на вхождение в Select, чтобы апдейтить его 2 */
    /*if (Select->Element == this)
    {
        AssignVisVec(*(Select->SelObj->Transformation->Rotation),AbsAngle);
        AssignVisVec(*(Select->SelObj->Transformation->Translation),AbsPos);
    }
    if (Select->ErrElement == this)
    {
        AssignVisVec(*(Select->ErrObj->Transformation->Rotation),AbsAngle);
        AssignVisVec(*(Select->ErrObj->Transformation->Translation),AbsPos);
    }*/

    CurrentEnabled = CurrentEnabled;
    NeedUpdatePos = false;
}

void TElement::UpdateDependenceElements()
{
    for (int i=0;i<FLinks.Count;i++)
    {
        TElement* OtherEl = FLinks[i].OtherElement(this);
        if ( FLinks[i].DependElement(OtherEl) && !OtherEl->DestroyStarted)
            OtherEl->RegisterCreateView();
    }
}

void TElement::UpgradeChildsPosition()
{
    //thischild
    for(int i=0;i<ChildList->Count;i++)
        ((TElement *)ChildList->Items[i])->FLinks[((TElement *)ChildList->Items[i])->NeededLink].Refresh();
}


void TElement::TexturePrimitive(TVisPrimitiveObj* Obj,int Index,TRenderParam& RP)
{
    if (Index>=Obj->PrimitiveCount || Index < 0)
		return;
    TVisPrimitiveArray* Array = Obj->Primitive[Index];
	TexturePrimitive(Obj,Array,RP,Index);
}

void TElement::TexturePrimitive(TVisPrimitiveObj* Obj,TVisPrimitiveArray* Array,TRenderParam& RP, int Index)
{
	Array->Material = RP.GetMaterial(0);
	Array->Texture = RP.GetTexture(0);
	TMetaTexture* MTex = RP.GetMetaTex(0);
	Array->Textured = (Array->Texture!=NULL);

	if (Array->Textured)
	{
		Obj->Textured = true;

		Obj->TextureFlags->ScaleX = 1/MTex->RealSizeX;//MyMeta->MTF.Scale.x;
		Obj->TextureFlags->ScaleY = 1/MTex->RealSizeY;//MyMeta->MTF.Scale.y;
		Obj->TextureFlags->ShiftX = MyMeta->MTF.Shift.x/MTex->RealSizeX;
		Obj->TextureFlags->ShiftY = MyMeta->MTF.Shift.y/MTex->RealSizeY;
		Obj->TextureFlags->Mode = (TVisTextureMode)MyMeta->MTF.Mode;
        //----------------------------------------------------------------------
		for (int i=0;i<Array->Count;i++)
		{
			Obj->Points->SharePosition[Array->Indices[i]] = false;
		}
		if (RP.TexCenter != ZEROINTVEC)
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = VisMathVec( TIntVec(Obj->Points->PointVec[Array->Indices[i]]) - RP.TexCenter );
		if (RP.TexAngle != ZEROINTVEC)
		{
			TVisMathVector MinusAngle = VisMathVec( RP.TexAngle*(-1) );
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = RotateAroundVMV(Obj->Points->PointVec[Array->Indices[i]],MinusAngle,ZEROVEC);
		}
		//----------------------------------------------------------------------

		//calc texture points
		for (int i=0;i<Array->Count;i++)
			Obj->CalcTexturePoint(Array->Indices[i]);

		//----------------------------------------------------------------------
		if (RP.TexAngle != ZEROINTVEC)
		{
			TVisMathVector Angle = VisMathVec(RP.TexAngle);
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = RotateAroundVMV(Obj->Points->PointVec[Array->Indices[i]],Angle,ZEROVEC);
		}
		if (RP.TexCenter != ZEROINTVEC)
			for (int i=0;i<Array->Count;i++)
				Obj->Points->PointVec[Array->Indices[i]] = VisMathVec( TIntVec(Obj->Points->PointVec[Array->Indices[i]]) + RP.TexCenter );
		//----------------------------------------------------------------------
	}
	else
	{
	}
}

void TElement::TextureObject(TVisPrimitiveObj* Obj,TRenderParam& RP)
{
    Obj->Textured = false;
    Obj->Texture = NULL;
    for (int i=0;i<Obj->PrimitiveCount;i++)
    {
        TexturePrimitive(Obj,i,RP);
        if ( Obj->Primitive[i]->Textured )
            Obj->Textured = true;
    }
}

void TElement::ProcessTexturing()
{
    TVisRender* Render = MyRender();
    if (Render && IS( Render,__classid(TVisPrimitiveObj) ) )
        TextureObject((TVisPrimitiveObj*)Render,RenPars[MyTree->ModeIndex]);
    NeedTexturing = false;
}


void TElement::ProcessTasks(void* ModeValue)
{
	if (NeedCreateView)
        ProcessCreateView();
    if (NeedUpdatePos)
        ProcessUpdatePos();
    if ( NeedTexturing )
        ProcessTexturing();
}

void TElement::UnRegisterCreateView(TMyObject* Obj)
{
	NeedCreateView = false;
	MySelection.UnRegisterCreateSelView();
}

void TElement::RegisterCreateView(TMyObject* Obj)
{
    TaskQueue.Register(this);
	NeedCreateView = true;
	SelectionCollection.Changed(this);
    UpdateDependenceElements();
    ATVChanged = true;
}

void TElement::RegisterUpdatePos(TMyObject* Obj)
{
    TaskQueue.Register(this);
    SelectionCollection.Changed(this);
	MySelection.RegisterPositionSelView();
	NeedUpdatePos = true;
}

void TElement::RegisterTexturing(TMyObject* Obj)
{
    TaskQueue.Register(this);
    NeedTexturing = true;
}


TLabel3D *TElement::CreateLabel(bool Rotateble,const TIntVec& Pos)
{
    TIntVec TMP_POS;
    for (int i=0;i<ChildList->Count;i++)
        if ( ChildList->Items[i]->Is(TLabel3D::StaticType) )
        {
            ((TLabel3D*)ChildList->Items[i])->Text = Description;
            return (TLabel3D*)ChildList->Items[i];
        }
	TLabel3D* Label= (TLabel3D*)CreateElementFunction(MyTree,MetaNodeCollection->KernelSupport->MetaLabel3D);
    Label->Rotateble = Rotateble;
    if (Pos == ZEROINTVEC)
    {
        TMP_POS = ZEROINTVEC;
        TMP_POS.z = AbsSize.z*0.5;
        TMP_POS = RotateAround(TMP_POS,AbsAngle,ZEROINTVEC);
    }
    else
        TMP_POS = RotateAround(Pos,AbsAngle,ZEROINTVEC);

    Label->UserChangePosition(TMP_POS + AbsPos-Label->AbsPos,AbsAngle);
    Label->Text=Description;
    Label->CurrentEnabled = GetTotalEnabled();
    MyTree->AutoConnect(this,Label);
    return Label;
}

void TElement::KillLabel()
{
    DoNotDelete = true;
    for (int i=0;i<ChildList->Count;i++)
        if ( ChildList->Items[i]->Is(TLabel3D::StaticType) )
            delete ((TLabel3D*)ChildList->Items[i]);
    DoNotDelete = false;
}


bool TElement::DependOf(TElement* El)
{
	//(TMDelTList<TPointer<TMetaElement> >*)
    return FindInPointerList( &MyMeta->DEPENDLST,El->MyMeta)!=-1;
}


int TElement::GetSideCount()
{
    if (ElementPoints)
        return ElementPoints->Sides.Count;
    else
        throw EMyException(AnsiString("Element ") + Name + AnsiString(" is not registred"));
}

TSide* TElement::GetSide(int i)
{
    if (ElementPoints)
        return ElementPoints->Sides.Items[i];
    else
        throw EMyException(AnsiString("Element ") + Name + AnsiString("  is not registred"));
}

void TElement::AbsFromLocal(const TIntVec& Vector,TIntVec& Result)
{
    Result = RotateAround(Vector,AbsAngle,ZEROINTVEC);
    Result+=AbsPos;
}

void TElement::LocalFromAbs(const TIntVec& Vector,TIntVec& Result)
{
    Result = Vector - AbsPos;
	Result = RotateAround(Result,AbsAngle*(-1),ZEROINTVEC);
}


void TElement::RemoveRenderFromTree()
{
    if (Parent || MyTree && this == MyTree->Head)
        MyTree->RemoveElement(this);
}


void TElement::SetParent(TMyRegObject *_Parent)
{
//    if (Parent == _Parent)
//        return;//т.к. динамические связки прыгают из конца в начало
    if (Parent)
        MyTree->RemoveElement(this);
    if (Parent)
        Parent->ChildList->Remove(this);
    FParent = _Parent;
    if (Parent)
        Parent->ChildList->Add(this);
    if (Parent)
        MyTree->AddElement((TElement*)Parent,this);
}

bool TElement::RunElementTrigger(int Trigger)
{
    TLuaModule* LM = MyMeta->TB->GetModule(Trigger);
    if (LM)
	{
        TElement* BackElement = CurElement;
        CurElement = this;
        RunForm(LM);
        CurElement = BackElement;
        return true;
    }
    return false;
}


/*void TElement::Render2D(TDrawView *DrawView)
{
  if ( !MyMeta->DrawView )
    return;
  if ( MyMeta->TB->Exists(trRender2D) )
  {
    TDrawView *OldRender2D = CurDrawView;
    CurDrawView = (TDrawView *)DrawView;
    RunElementTrigger(trRender2D);
    CurDrawView = OldRender2D;
  }
  else
    StandartRender2D(DrawView);
}*/

bool TElement::CheckFields()
{
    if (!TUnit::CheckFields())
        return false;

    _TRY_

        if (MyMeta->InWeb)
            LN->RegElem(this);
        if (MyRender())
        {
            if (!GUID.IsEmpty())
                DynamicType->RegisterRender(this,MyRender());
            if ( IS(MyRender(),__classid(TVisPrimitiveObj)) )
                ((TVisPrimitiveObj*)MyRender())->Material = MyMeta->VM;
            else if (IS(MyRender(),__classid(TVisLabel)))
                ((TVisLabel*)MyRender())->Material = MyMeta->VM;

            if (MyMeta->TEX.ADR)
            {
                if ( IS(MyRender(),__classid(TVisPrimitiveObj)) )
                {
                    ((TVisPrimitiveObj*)MyRender())->Texture = MyMeta->TEX.ADR->VT;
                    ((TVisPrimitiveObj*)MyRender())->Textured = true;
                }
                else if (IS(MyRender(),__classid(TVisLabel)))
                    ((TVisLabel*)MyRender())->Texture = MyMeta->TEX.ADR->VT;
            }

        }
        return true;
        
    _ENDTRY_(AnsiString("<TElement::CheckFields>: An error occured during checking of element:")+Description,return false;);
}

void TElement::SynchronizeRenderParams()
{
    TMDelTList<TRenderParam> OLD;
    OLD.Assign(&RenPars);
    OLD.CheckFields();
    OLD.Init();
    //--------------------------------------
    for (int i=0;i<MetaNodeCollection->KernelSupport->Modes.Count;i++)
    {
        RenPars.Add( new TRenderParam() );
        TMyModeSettings* _MMS = MyMeta->MMSL.FindByMode(MetaNodeCollection->KernelSupport->Modes.Items[i]);

		RenPars[i].MODE.ADR =  MetaNodeCollection->KernelSupport->Modes.Items[i];
		RenPars[i].AssignMode(_MMS);
/*		RenPars[i].Texture =  (_MMS)? _MMS->TEX.ADR : MyMeta->TEX.ADR;
		RenPars[i].Material = (_MMS)? _MMS->MAT.ADR : MyMeta->MAT.ADR;
		RenPars[i].OverPos = (_MMS)? _MMS->OverPos : ZEROINTVEC;
		RenPars[i].OverSize = (_MMS)? _MMS->OverSize : ZEROINTVEC;
		RenPars[i].OverSizeMode = (_MMS)? _MMS->OverSizeMode == omAdd : false;
		RenPars[i].OverPosMode = (_MMS)? _MMS->OverPosMode == omReplace : false;
		RenPars[i].FLAT2D = (_MMS)? _MMS->FLAT_2D : false;
		RenPars[i].Enabled = (_MMS)? _MMS->Render : true; */

	}
    for (int j=0;j<RenPars.Count;j++)
        for (int i=0;i<OLD.Count;i++)
            if (RenPars[j].MODE.ADR == OLD[i].MODE.ADR)
            {
                RenPars[j].Assign( &OLD[i] );
				RenPars[j].RecurrentCheck();
                break;
            }
}

bool TElement::Init()
{
    _TRY_

        SynchronizeRenderParams();
        SetMyHoleFor(HoleElement.ADR);
        UserChangePosition(ZEROINTVEC,ZEROINTVEC);
        if (MyMeta->InWeb)
            LN->RegElem(this);
        CurrentEnabled = true;
        CustomEnabled = true;
        return true;

    _ENDTRY_(AnsiString("<TElement::Init>: An error occured during initialzing of element: ")+Description,return false;);
}

TElement::~TElement()
{
    if (DestroyStarted)
        InfoMsg("Deleting in progress");
    DestroyStarted = true;

    //Нельзя этого делать т.к. реальные поля в в доч. объектоах уже сдохли 
    // поэтому коментируем UndoRegister(rmDeleted);
    
	bool ProcessAddElement = false;
    if (World && World->IsFloorElement(this))
        ProcessAddElement = true;
    DeleteAllLinksOnly();
    if (MyMeta && MyMeta->InWeb)
        LN->UnRegElem(this);
    if (MyTree && this == MyTree->Head)
    {
        MyTree->Head = NULL;
    }
    if (World && MyMeta)
        World->Process_AddElement(MyMeta,NULL);
    DelMyHole();
    if (World && ProcessAddElement && MetaNodeCollection->KernelSupport->WEBMETA.Count)
        World->Process_AddElement(MetaNodeCollection->KernelSupport->WEBMETA.Items[0],NULL);

    //TaskQueue.UnRegister(this); // не нужно т.к. следующая строка
    ElementQueueCollection.Remove(this);
    delete HP;
    LinkHoles.MyObjectParent = NULL;
}

int TElement::GetFragmentCount()
{
    return FragSet.Count;
}

TFragmentSettings* TElement::GetFragment(int i)
{
    return FragSet.Items[i];
}

int TElement::GetRenderParamCount()
{
    return RenPars.Count;
}

TRenderParam* TElement::GetRenderParam(int i)
{
    return RenPars.Items[i];
}

void TElement::ClearPoints()
{
    HP->Clear();
}

void TElement::AddArrPoint(const TIntVec &_Point)
{
    HP->Vertex->Add(new TIntVec(_Point));
}

TElement *TElement::GetChild(int i)
{
    if (i<ChildList->Count&&i>=0)
        return (TElement *)(ChildList->Items[i]);
    else
        return NULL;
}

int TElement::GetChildCount()
{
    return ChildList->Count;
}

bool TElement::TechCheck(AnsiString& Str)
{

    return MyMeta->TechCheck(this,Str);
}

TVisRender *Temp_Render;
void TElement::Render(TVisCustomView* aView)
{
    Temp_Render = MyRender();
    if (Temp_Render)
        Temp_Render->Render(aView);
}

void TElement::CreateClient(TElement * Target)
{
    if ( !Target->HP->Vertex->Count || !HP->Vertex->Count)
    {
        Application->MessageBox("Target link is only for Cylinder","Error");
        Application->Terminate();
        return;
    }
    ClearPoints();
    HP->Assign(Target->HP);
    HP->Set(2,-AbsSize.z/2);
	UserChangePosition(ZEROINTVEC,Target->AbsAngle-AbsAngle);
} 

/*void TElement::SetRectElement(TElement *newRElement)
{
    FRectElement = newRElement;
    if ( FRectElement==NULL)
        RectElementID = -1;
    else
        RectElementID = FRectElement->ID;
}*/


void TElement::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
  if (MyMeta->TB->Exists(trEdit))
    RunElementTrigger(trEdit);
}


TElement* TElement::Create_SIZER(int ID,const TIntVec& P1,const TIntVec& P2)
{
    TElement *EL = NULL;;
    for (int i=0;i<ChildList->Count;i++)
        if ( ((TElement*)ChildList->Items[i])->MyMeta == MetaNodeCollection->KernelSupport->DEFAULT_SIZE )
            if ( ((TElement*)ChildList->Items[i])->Description == IntToStr(ID) )
            {
                EL = ((TElement*)ChildList->Items[i]);
                break;
            }

    if (!EL)
    {
        EL = CreateElementFunction(MyTree,
                                MetaNodeCollection->KernelSupport->DEFAULT_SIZE);
        EL->UserChangePosition(AbsPos - EL->AbsPos,ZEROINTVEC);
        EL->CurrentEnabled = TotalEnabled;
        EL->Description = IntToStr(ID);
    }

    TMDelTList<TIntVec> *VC = new  TMDelTList<TIntVec>();

    VC->Add( new TIntVec(RotateAround(P1,AbsAngle,ZEROINTVEC)+AbsPos) );
    VC->Add( new TIntVec(RotateAround(P2,AbsAngle,ZEROINTVEC)+AbsPos) );
    EL->ConstructBy2Points(VC);
    EL->CurrentEnabled = GetTotalEnabled();
    MyTree->AutoConnect(this,EL);
    delete VC;
    return EL;
}

void TElement::Kill_SIZER(int ID)
{
    TElement *EL;
    for (int i=0;i<ChildList->Count;i++)
        if ( ((TElement*)ChildList->Items[i])->MyMeta == MetaNodeCollection->KernelSupport->DEFAULT_SIZE )
            if ( ((TElement*)ChildList->Items[i])->Description == IntToStr(ID) )
            {
                EL = ((TElement*)ChildList->Items[i]);
                delete EL;
			}
}

void TElement::SetPos(const TIntVec& newPos)
{
    AbsPos = newPos;
}

void TElement::SetAngle(const TIntVec& newAngle)
{
    AbsAngle = newAngle;
}

void TElement::SetSize(const TIntVec& newSize)
{
    AbsSize = newSize;
}

void TElement::SetSlope(const TIntVec& _SlopeMinus,const TIntVec& _SlopePlus,bool Render)
{
    SlopeMinus = _SlopeMinus;
    SlopePlus = _SlopePlus;
}

TLink *TElement::GetLinkOf(TElement *El)
{
    if (!El || El == this)
        return NULL;
    for (int i=0;i<FLinks.Count;i++)
        if (FLinks[i].Exists(El))
			return &FLinks[i];
    return NULL;
}

void TElement::DeleteAllLinks()
{
    while(FLinks.Count)
        KillLink(this,0);
}

void TElement::DeleteAllLinksOnly()
{
    DoNotDelete = true;
    DeleteAllLinks();
    DoNotDelete = false;
}

void TElement::ForceCreateView()
{
    RegisterCreateView();
}


void TElement::DeleteNeededLink()
{
    if (NeededLink!=-1)
        KillLink(this,NeededLink);
    int i=0;
    while(i<FLinks.Count)
    {
		TElement *ElOther=NULL;
        if (FLinks[i].Exists(this,0))
            ElOther = FLinks[i].Elements[1];
        if (FLinks[i].Exists(this,1))
            ElOther = FLinks[i].Elements[0];
        if (ElOther == NULL)
        {
            Application->MessageBox("The link is incorrect","Error");
            Application->Terminate();
        }
        if (!FLinks[i].NeededFor(ElOther))
            KillLink(this,i);
        else
            i++;
    }
}

void TElement::AddLink(TLink *Link)
{
    FLinks.Add(Link);
    //Связка сама себя добавляет
}

int TElement::GetNeededLink()
{
    //return this
    //эту функцию переделать чтобы был индекс
    int Needed=-1;
    int NeededCount=0;
    for (int i=0;i<FLinks.Count;i++)
		if (FLinks[i].NeededFor(this))
        {
            Needed = i;
            NeededCount++;
        }
    if (NeededCount>1)
    {
        Application->MessageBox("There are more than one needed links.","Error");
        Application->Terminate();
    }
    return(Needed);
}


void TElement::KillLink(void *Sender,int Index)
{
    if (Index<0 || Index>=FLinks.Count)
    {
        Application->MessageBox("Index of link is incorrect.","Error",MB_OK);
        Application->Terminate();
    }
    if (!FLinks[Index].Exists(this))
    {
        Application->MessageBox("Attempt to delete one link twice!","Error",MB_OK);
        Application->Terminate();
    }
    TLink* KillingLink = &FLinks[Index];
    int ind = KillingLink->Exists(this,1);
    if (KillingLink->Elements[1-ind]==HoleElement.ADR)
        DelMyHole();
	if (KillingLink != Sender)
    {
        KillingLink->UnLinkElement(this,ind);
        //связка еще раз должна вызвать
        return;
    }
    bool Depend = KillingLink->DependElement(this);
    FLinks.Remove(KillingLink);

    if (NeededLink==-1)
    {
    //------------------попадает ли в драйвер----------------------------------
        Parent = NULL;
        if (MyTree->Head==this)//У корня обязательных связок нет
            return;
        if (Driver.Element==this)
            return;
        if (DoNotDelete)
            return;
        if (!DestroyStarted)
            KillElement(this);
    }
    else if (Depend)
        RegisterCreateView();

}

int TElement::IOF(TLink *Lnk)
{
    return( FLinks.IndexOf(Lnk));
}

bool TElement::EditStatus(int &Operation,int &Type)
{
   /* TODO : Проверка на редактирование - редактируется ли элемент сейчас */ 
/*    if (BIF->Element != this)
    {
        Operation = ioNone;
        Type = 0;
        return false;
    }
    else
    {
        Operation = BIF->GetOperation();
        Type = BIF->MCS[Operation]->Mode;
        return true;
    }
*/
    return false;
}

void TElement::UserChangePosition(const TIntVec& Move,const TIntVec& Rotate)
{
    AbsPos += Move;
    AbsAngle += Rotate;
}

//function fill list by polygons thats extruded by z +;
//------------------------TCylinder---------------------------------------
void TElement::GetEdges(TMDelTList<TPolygon> *pList)
{
    if (HP->Vertex->Count)
    {
        TPolygon *P = new TPolygon();
        P->Assign(HP);
        pList->Add(P);
        for (int i=0;i<HP->Holes->Count;i++)
        {
            P =new TPolygon();
            P->Assign(HP->Holes->Items[i]);
            pList->Add(P);
        }
    }
    else
    {
        TPolygon *P = new TPolygon();
        P->Vertex->Add( new TIntVec(AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2) );
        P->Vertex->Add( new TIntVec(-AbsSize.x/2,AbsSize.y/2,-AbsSize.z/2));
        P->Vertex->Add( new TIntVec(-AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
        P->Vertex->Add( new TIntVec(AbsSize.x/2,-AbsSize.y/2,-AbsSize.z/2));
        pList->Add(P);
    }
}

void TElement::LOW_HI(TIntVec& LOW,TIntVec& HI)
{
    TMDelTList<TPolygon> *pList = new TMDelTList<TPolygon>();
    GetEdges(pList);
    TIntVec AbsVec;
    for (int i=0;i<pList->Count;i++)
		for (int j=0;j<pList->Items[i]->Vertex->Count;j++)
        {
            AbsFromLocal(*(pList->Items[i]->Vertex->Items[j]),AbsVec);
            UpdateMinVector(LOW,AbsVec);
            AbsVec.z=AbsVec.z+AbsSize.z;
            UpdateMaxVector(HI,AbsVec);
        }
    delete pList;
}

bool TElement::GetEnabled(int type)
{
    return FEnabled[type];
}

bool TElement::GetModeEnabled()
{
    return RenPars[MyTree->ModeIndex].Enabled;
}

bool TElement::GetTotalEnabled()
{
    return MIN(MIN(CustomEnabled,CurrentEnabled),RenPars[MyTree->ModeIndex].Enabled);
}

void TElement::SetEnabled(int type,bool Value)
{
    FEnabled[type] = Value;
    bool TotEnabled = GetTotalEnabled();
    TVisRender *R = MyRender();
	if (R)
        R->Enabled = TotEnabled;
    for (int i=0;i<ChildList->Count;i++)
        if ( ((TElement*)ChildList->Items[i])->MyMeta == MetaNodeCollection->KernelSupport->DEFAULT_SIZE
            ||((TElement*)ChildList->Items[i])->MyMeta == MetaNodeCollection->KernelSupport->MetaLabel3D )
            ((TElement*)ChildList->Items[i])->CurrentEnabled = TotEnabled;
}

void TElement::ChangeSize(const TIntVec& ChangeVector,const TIntVec& ChangeDirection,bool Try)
{
    TIntVec OldSize;
    TIntVec MoveVector;
    OldSize = AbsSize;
    SetSize(AbsSize+ChangeVector);
    MoveVector = ChangeDirection.XYZ_Multiply(AbsSize - OldSize)/2;
    UserChangePosition(RotateAround(MoveVector,AbsAngle,ZEROINTVEC),ZEROINTVEC);
    if (!Try)
    {
        for(int i=0;i<ChildList->Count;i++)
            ((TElement *)ChildList->Items[i])->SetMyHoleFor(NULL);
    }
}

bool TElement::LinkPosition(TElement * ElOther,TIntVec& Position)
{
    for (int i=0;i<FLinks.Count;i++)
        if (FLinks[i].Exists(ElOther))
            {
                Position = FLinks[i].AbsPositionBy(this);
                return true;
            }
    return false;
}

/*void TElement::StandartRender2D(TDrawView *DrawView)
{
  bool clear=false;
  if (HP->Vertex->Count==0)
  {
    clear=true;
    AddArrPoint(TIntVec(slope_around(AbsSize.x/2,AbsSize.y/2,0,SlopePlus.z),AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(slope_around(-AbsSize.x/2,AbsSize.y/2,0,SlopeMinus.z),AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(slope_around(-AbsSize.x/2,-AbsSize.y/2,0,SlopeMinus.z),-AbsSize.y/2,-AbsSize.z/2));
    AddArrPoint(TIntVec(slope_around(AbsSize.x/2,-AbsSize.y/2,0,SlopePlus.z),-AbsSize.y/2,-AbsSize.z/2));
  }
  DrawView->Polygon(this,HP->Vertex);
  if (clear)
    ClearPoints();
}*/

bool TElement::GetTotalAllowAdvancedTexture()
{
    return  AUI.Mode &&
            AUI.Mode->CAM == camPerspective &&
            FAdvancedTextureView &&
            AUI.AdvancedTexturing;
}

void TElement::SetAdvancedTextureView(bool Value)
{
    FAdvancedTextureView = Value;
    if ( TotalAllowAdvancedTexture != FAdvancedTextured)
        RegisterCreateView(NULL);
}

void TElement::SetMode()
{
    //-----------------------------------------------
    AdvancedTextureView = AdvancedTextureView;
    //-----------------------------------------------
    int prevmode = MyTree->PrevModeIndex;
    int now_mode = MyTree->ModeIndex;
    if ( RenPars[prevmode].FLAT2D != RenPars[now_mode].FLAT2D ||
         RenPars[prevmode].OverSizeMode != RenPars[now_mode].OverSizeMode ||
         RenPars[prevmode].OverSize != RenPars[now_mode].OverSize)
        RegisterCreateView(NULL);
    if ( RenPars[prevmode].OverPosMode != RenPars[now_mode].OverPosMode ||
         RenPars[prevmode].OverPos != RenPars[now_mode].OverPos ||
         RenPars[prevmode].Enabled != RenPars[now_mode].Enabled )
        RegisterUpdatePos(NULL);
    if ( RenPars[prevmode].Texture != RenPars[now_mode].Texture ||
         RenPars[prevmode].Material != RenPars[now_mode].Material )
        RegisterTexturing(NULL);
}

TElement* TElement::GetCurrentFloorElement()
{
    if (!World)
		throw EMyException("The 'World' is not defined.");
    int FloorIndex = World->FloorOf(this);

    if ( FloorIndex != -1 )
        return World->Floors[FloorIndex].First.ADR;
    else if (Driver.Element == this)
        return Driver.FloorElement;
    else
        throw EMyException("'FloorElement' is not found.");
}



void TElement::LocalizePolygon()
{
    TIntVec Center = HP->Center();
    UserChangePosition(Center-AbsPos,ZEROINTVEC);
    Center.z = 0;
    HP->Move(Center*(-1));
    HP->Set(2,-AbsSize.z/2);
}

void TElement::ValidateConstruction(MBTi USEEPS)
{
    if (AbsSize.x<USEEPS)
        AbsSize.x = 0.3;
    if (AbsSize.y<USEEPS)
        AbsSize.y = 0.3;
    if (AbsSize.z<USEEPS)
        AbsSize.z = 0.25;
	if (HP->Vertex->Count)
    {
        if (!HP->Valid(USEEPS))
            HP->SquareCreate(AbsSize);
    }
}

void TElement::ConstructByNPoints(TMDelTList<TIntVec>* Points)
{
    TPolygon* POL = new TPolygon(Points);
    bool result = POL->Valid(_MBTi_eps_);
    //--------------------------------------------------------------------------
    if (result == true && MyMeta->ID == 123) //!!!!!!!!!!!!!!!!!!!
    {
		float MaxLength= -(1<<28);
        float MinLength = 1<<28;
        for (int i=0;i<POL->Vertex->Count;i++)
        {
            float L = (*(POL->Vertex->CycleItems[i+1]) - *(POL->Vertex->Items[i])).Length2D();
            if (L>MaxLength)
                MaxLength = L;
            if (L<MinLength)
                MinLength = L;
        }
        result = false;
        if (MinLength>0.5 && (MaxLength/MinLength)<20)
            result = true;
    }
    //--------------------------------------------------------------------------
    delete POL;
	if (!result)
        return;
    HP->Clear();
    HP->Vertex->Assign(Points);
    LocalizePolygon();
    if (MyMeta->ID == 123 && World)   ///!!!!!!!!!!!!!!!!!!!!
    {
        UserChangePosition(TIntVec(0,0,AbsSize.z/2),ZEROINTVEC);
    }
}

void TElement::ConstructBy2Points(TMDelTList<TIntVec>* Points)
{
//position
    TIntVec Center = (*(Points->Items[0])+*(Points->Items[1]))/2;
    Center.z = AbsPos.z;
//angle
    MBTi Angle = AngleRadOX(*Points->Items[0],*Points->Items[1])*180/M_PI;
    Angle = Angle - AbsAngle.z;
//size
    double DeltaX = Points->Items[1]->x - Points->Items[0]->x;
    double DeltaY = Points->Items[1]->y - Points->Items[0]->y;
	MBTi SizeX = (MBTi)sqrtDC( DeltaX*DeltaX+DeltaY*DeltaY );
    SetSize(TIntVec(SizeX,AbsSize.y,AbsSize.z));

    UserChangePosition(ZEROINTVEC,TIntVec(0,0,Angle));
    UserChangePosition(Center-AbsPos,ZEROINTVEC);
}

//--------------------------------------------------------------------------

void TElement::SetMyHoleFor(TElement *El)
{
    if (!El)
        El = HoleElement.ADR;
    if (!El)
        return;
    DelMyHole();
    TPolygon* POL = new TPolygon();
    El->HoleInMeFor(this,POL);
    if (!POL->Vertex->Count)
    {
        delete POL;
        return;
    }
    HoleElement.ADR = El;
    El->AddHole(POL,this);
//    El->ForceCreateView();
}

void TElement::DelMyHole()
{
    if (!HoleElement.ADR)
        return;
    int index = HoleElement.ADR->FindHoleFor(this);
    if (index != -1)
        HoleElement.ADR->DeleteHole(index);
    HoleElement.ADR = NULL;
}

void TElement::AddHole(TPolygon* Hole,TElement* Client)
{
    if ( FindHoleFor(Client)!=-1 )
        throw EMyException("Aperture for client already exists");
    LinkHoles.Add( new THoleClient(Hole,Client) );
}

void TElement::DeleteHole(int i)
{
    LinkHoles.Delete(i);
}

int TElement::FindHoleFor(TElement* Element)
{
    if (DestroyStarted)
        return -1;
    for (int i=0;i<LinkHoles.Count;i++)
        if (LinkHoles[i].Client.ADR == Element)
            return i;
    return -1;
}

TElement& TElement::operator =(TElement& Element)
{
    Assign(&Element);
    return *this;
}

//----------------------------TLink----------------------------------------------
const AnsiString aPos0 = AnsiString("Pos0");
const AnsiString aPos1 = AnsiString("Pos1");
const AnsiString aAngle = AnsiString("Angle");
const AnsiString aEL0 = AnsiString("EL0");
const AnsiString aEL1 = AnsiString("EL1");
const AnsiString aVisual = AnsiString("Visual");

TLink& TLink::operator =(TLink& Link)
{
    Assign(&Link);
    return *this;
}

TMyObject* TLink::CreateFunction()
{
    return new TLink();
}

void TLink::SetMetaObject(TMyRegObject* aMetaObject)
{
    TUnit::SetMetaObject(aMetaObject);
}

void TLink::SetElement(int index,TElement* El)
{
    ELS[index].ADR = El;
}

TElement* TLink::GetElement(int index)
{
    return ELS[index].ADR;
}

TLink::TLink(TMetaNode *_Meta,TElement *Target,TElement *Source,const TIntVec &AbsCrossPoint):
    TUnit()
{
    RegisterNewClass< TUnit, TLink >(this,false,&CreateFunction);
    //------------------------------
    //Здесь мы не знаем будет ли регистрироваться
    //поэтому комментирум UndoRegister(rmCreated);

    ELS.Add(new TPointer<TElement>());
    ELS.Add(new TPointer<TElement>());
    SetMetaObject(_Meta);
    //return this
    if ( typeid(*_Meta) != typeid(TDynamicLink) )
    {
        Application->MessageBoxA("Error","The parent class is incorrect.",MB_OK);
        Application->Terminate();
    }
    RegisterField(&Pos0,&aPos0,mtIntVec);
    RegisterField(&Pos1,&aPos1,mtIntVec);
    RegisterField(&Angle,&aAngle,mtIntVec);
    RegisterField(&ELS[0],&aEL0,mtMyObject);
    RegisterField(&ELS[1],&aEL1,mtMyObject);
    RegisterField(&Visual,&aVisual,mtBool);

    Visual = false;
    El0Depend = false;
    El1Depend = false;
    if (Target==NULL||Source==NULL)
    {
        Application->MessageBox("Target or Source is not defined for the link","Error");
        Application->Terminate();
        return;
    }
    if (Target==Source)
    {
        Application->MessageBox("Attempt to create cycled link","Error");
        Application->Terminate();
        return;
    }
    Deletion=false;
    Pos1 = RotateAround(AbsCrossPoint - Source->AbsPos,Source->AbsAngle*(-1),ZEROINTVEC);
    LinkElement(this,0,Target);
    LinkElement(this,1,Source);

    if (MyMeta && MyMeta->Link->InWeb && MyMeta->El0->InWeb && MyMeta->El1->InWeb )
        LN->Reg(this);
    if ( El1->MyMeta && El1->DependOf(El0))
        El1Depend = true;
    if (El0->MyMeta && El0->DependOf(El1))
        El0Depend = true;
    if (El0->MyMeta && El0Depend)
        El0->ForceCreateView();
    else if (El1->MyMeta && El1Depend)
        El1->ForceCreateView();
}

TLink::TLink()
{
	RegisterNewClass< TUnit, TLink >(this,false,&CreateFunction);
    //Здесь мы не знаем будет ли регистрироваться
    //поэтому комментирум UndoRegister(rmCreated);
    ELS.Add(new TPointer<TElement>());
    ELS.Add(new TPointer<TElement>());
    RegisterField(&Pos0,&aPos0,mtIntVec);
    RegisterField(&Pos1,&aPos1,mtIntVec);
    RegisterField(&Angle,&aAngle,mtIntVec);
    RegisterField(&ELS[0],&aEL0,mtMyObject);
    RegisterField(&ELS[1],&aEL1,mtMyObject);
    RegisterField(&Visual,&aVisual,mtBool);
    Deletion=false;
    Visual = false;
    El0Depend = false;
    El1Depend = false;
}

TLink::~TLink()
{
    if (Deletion)
        return;
    Deletion=true;
    //------------------------
    UndoRegister(rmDeleted);
    //------------------------
    ProcessUnVisual();

    if (MyMeta && El0 && !El0->DestroyStarted)
        RunLinkTrigger(trLinkDestroyEl0);
    if (MyMeta && El1 && !El1->DestroyStarted)
		RunLinkTrigger(trLinkDestroyEl1);

    if (MyMeta && MyMeta->Link->InWeb && MyMeta->El0->InWeb && MyMeta->El1->InWeb )
        LN->UnReg(this);
    if (MyMeta && El1 && El0 && MyMeta->Link->HoleCreated && El0->FindHoleFor(El1)!=-1 )
        El1->DelMyHole();
    if (El1)
        El1->KillLink(this,El1->IOF(this));
    if (El0)
        El0->KillLink(this,El0->IOF(this));
}

void TLink::AboutToChange(void* Sender)
{
    //RegisterInUndo
    UndoRegister(rmChanged);
}

void TLink::Changed(void* Sender)
{
    if (Sender == &Angle)
    {
        Angle.MyObjectParent = NULL;
        Angle = Angle % 360;
        Angle.MyObjectParent = this;
    }
}

MBTi TLink::GeomAngle()
{
	MBTi Ang = Angle.z;
    if (Pos0.x*Pos1.x<0)
        Ang = Ang-180;
    return Ang;
}

void TLink::ProcessUnVisual()
{
    if (Visual)
    {
        if (Pos0.x<=0)
            El0->SetSlope(TIntVec(0,0,0),El0->SlopePlus,false);
        else
            El0->SetSlope(El0->SlopeMinus,TIntVec(0,0,0),false);
        if (Pos1.x<=0)
            El1->SetSlope(TIntVec(0,0,0),El1->SlopePlus,false);
        else
            El1->SetSlope(El1->SlopeMinus,TIntVec(0,0,0),false);
    }
    Visual = false;
}

void TLink::ProcessVisual()
{
    Visual = true;

    MBTi _Ang = GeomAngle();
    while (_Ang>=360)
        _Ang-=360;
    while (_Ang<0)
		_Ang+=360;

    if ( fabs(_Ang - 180)<=0.005 )
        return;

    TIntVec PIN[2][2];
    TIntVec POUT[2][2];
    TIntVec CP[2];
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        {
            int DELITEL = IntPower(-1,j+1)*2;
            PIN[i][j] = Elements[i]->AbsSize/DELITEL;
            POUT[i][j] = Elements[i]->AbsSize/DELITEL;
            if (Pos0.x*Pos1.x<0)
            {
                PIN[i][j].y  = -(Elements[i]->AbsSize.y/2);
                POUT[i][j].y = (Elements[i]->AbsSize.y/2);
            }
            else
            {
                int sgn = IntPower(-1,i);
                PIN[i][j].y  = -sgn*(Elements[i]->AbsSize.y/2);
                POUT[i][j].y = sgn*(Elements[i]->AbsSize.y/2);
            }
        }
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        {
            PIN[i][j]  = RotateAround(    PIN[i][j],Elements[i]->AbsAngle,ZEROINTVEC)+Elements[i]->AbsPos;
			POUT[i][j]  = RotateAround(    POUT[i][j],Elements[i]->AbsAngle,ZEROINTVEC)+Elements[i]->AbsPos;
        }
    IsLinesCrossedExactly(PIN[0][0],PIN[0][1],PIN[1][0],PIN[1][1],CP[0]);
    IsLinesCrossedExactly(POUT[0][0],POUT[0][1],POUT[1][0],POUT[1][1],CP[1]);

    CP[0].z = CP[1].z;
    MBTi GIP = (CP[1]-CP[0]).Length();
    if (GIP<=_MBTi_eps_ )
        return;
    if (Elements[0]->AbsSize.y >= GIP - _MBTi_eps_  && Elements[1]->AbsSize.y >= GIP - _MBTi_eps_ )
        return;
	MBTi Ang0 = acosDC(Elements[0]->AbsSize.y/GIP)*180/M_PI;
    MBTi Ang1 = acosDC(Elements[1]->AbsSize.y/GIP)*180/M_PI;
    //--------------------------------------------------------------------------
    //-----check sign of angle -------------------------------------------------
    if (Pos0.x>0)
        switch(Classify(CP[0],CP[1],POUT[0][1],0))
        {
            case etLEFT:
                El0->SetSlope(El0->SlopeMinus,TIntVec(0,0,Ang0),false);
            break;
            case etRIGHT:
                El0->SetSlope(El0->SlopeMinus,TIntVec(0,0,-Ang0),false);
            break;
        }
    else
        switch(Classify(CP[0],CP[1],POUT[0][0],0))
        {
            case etLEFT:
                El0->SetSlope(TIntVec(0,0,Ang0),El0->SlopePlus,false);
			break;
            case etRIGHT:
                El0->SetSlope(TIntVec(0,0,-Ang0),El0->SlopePlus,false);
            break;
        }

    if (Pos1.x>0)
        switch(Classify(CP[0],CP[1],POUT[1][1],0))
        {
            case etLEFT:
                El1->SetSlope(El1->SlopeMinus,TIntVec(0,0,Ang1),false);
            break;
            case etRIGHT:
                El1->SetSlope(El1->SlopeMinus,TIntVec(0,0,-Ang1),false);
            break;
        }
    else
        switch(Classify(CP[0],CP[1],POUT[1][0],0))
        {
            case etLEFT:
                El1->SetSlope(TIntVec(0,0,Ang1),El1->SlopePlus,false);
            break;
            case etRIGHT:
                El1->SetSlope(TIntVec(0,0,-Ang1),El1->SlopePlus,false);
            break;
        }

    //--------------------------------------------------------------------------


/*    MBTi Ang = GeomAngle();
    while(Ang>=180)
        Ang = Ang-360;
    while(Ang<=-180)
        Ang = Ang+360;
    Ang = Ang/2;
    if (Ang!=0)
        Ang = Sign(Ang)*fabs(90 - fabs(Ang));
    if (Pos0.x>0)
    {
        El0->SetSlope(El0->SlopeMinus,TIntVec(0,0,Ang));
        El0_Plus = true;
    }
    else
        El0->SetSlope(TIntVec(0,0,Ang),El0->SlopePlus);
    if (Pos1.x>0)
    {
        El1->SetSlope(El1->SlopeMinus,TIntVec(0,0,-Ang));
        El1_Plus = true;
    }
    else
        El1->SetSlope(TIntVec(0,0,-Ang),El1->SlopePlus);  */
}

bool TLink::CheckFields()
{
    if (!TUnit::CheckFields())
        return false;

    _TRY_

        if (!El0 || !El1)
            return false;
        LinkElement(this,0,El0);
        LinkElement(this,1,El1);
        return true;

    _ENDTRY_(AnsiString("<TLink::CheckFields>: Check link fields error!"),return false;);
}

bool TLink::Init()
{
    if (MyMeta->Link->InWeb && MyMeta->El0->InWeb && MyMeta->El1->InWeb )
        LN->Reg(this);
    if (MyMeta->Link->HoleCreated && El0->FindHoleFor(El1)==-1)
        El1->SetMyHoleFor(El0);
    if (Visual)
        ProcessVisual();
    if ( El1->MyMeta && El1->DependOf(El0))
        El1Depend = true;
    if (El0->MyMeta && El0->DependOf(El1))
        El0Depend = true;
    if (El0->MyMeta && El0Depend)
        El0->ForceCreateView();
    else if (El1->MyMeta && El1Depend)
        El1->ForceCreateView();
    return true;
}


bool TLink::Exists(TElement *El,int i)
{
    int ind=-1;
    if (El==El0)
        ind = 0;
    if (El==El1)
        ind = 1;
    if (ind == -1)
        return(false);
    if (i==-1)
        return(true);
    return(i == ind);
}

bool TLink::Exists(TMetaElement *mel,int i)
{
    return(MyMeta->Exists(mel,i));
}

bool TLink::DependElement(TElement* Sender)
{
    return (Sender == El0)&&El0Depend || (Sender == El1)&&El1Depend;
}

void TLink::LinkElement(void * Sender, int i, TElement * El)
{
    ELS[i].ADR = El;
    //перед линком
    if (El0!=NULL&&El1!=NULL)
    {   //Задать позиции
		Pos0 = RotateAround(Pos1,El1->AbsAngle,ZEROINTVEC);
        Pos0 = Pos0 + El1->AbsPos - El0->AbsPos;
        Pos0 = RotateAround(Pos0,El0->AbsAngle*(-1),ZEROINTVEC);
        Angle = El1->AbsAngle-El0->AbsAngle;
    }
    Elements[i]->AddLink(this);

    //после линка
    if ( El0!=NULL && El1!=NULL)
    {
        if (MyMeta->Needed)
            El1->Parent = El0;
    }
}

void TLink::UnLinkElement(void *Sender,int i)
{
    if (i!=1&&i!=0)
    {
        Application->MessageBox("Link index error!","Error",MB_OK);
        Application->Terminate();
    }
    delete this;
}

bool TLink::NeededFor(TElement *El)
{
    return(MyMeta->NeededFor(El->MyMeta));
}

TElement* TLink::OtherElement(TElement* Sender)
{
    if (Sender == El0)
        return El1;
    else if (Sender == El1)
        return El0;
    else
        throw EMyException("Could not obtain access to the link");            
}


bool TLink::TargetChangeSize(bool Try,const TIntVec &RealSizeChange,const TIntVec& Direction)
{
    //size and pos must be already changed
    //size and pos must be already changed
    //size and pos must be already changed
/*    bool returned = true;
    if (El0!=NULL&&El1!=NULL)
    {
        if (RealSizeChange!=ZEROINTVEC)
        {
            TIntVec MoveVector = (Direction*RealSizeChange)/VEC222;
            Pos0 = Pos0 - MoveVector;
            TMetaLink *ML = MyMeta->Link;

            for (int i=0;i<3;i++)
                switch (ML->LCM.a[i])
                {
                    case lcmMinus:
                    {
						if (Direction.a[i]==-1)
                            Pos0.a[i] = Pos0.a[i]-RealSizeChange.a[i];
                    }
                    break;
                    case lcmPlus:
                    {
                        if (Direction.a[i]==1)
                            Pos0.a[i] = Pos0.a[i]+RealSizeChange.a[i];
                    }
                    break;
                    case lcmZero:
                    {
                        Pos0.a[i] = Pos0.a[i] + MoveVector.a[i];
                    }
                    break;
                    case lcmAuto:
                    {
                        if (Pos0.a[i]+MoveVector.a[i] == 0)
                        {
                            Pos0.a[i] = 0;
                            break;
                        }

                        if (abs(Pos0.a[i]+MoveVector.a[i]) == abs(El0->AbsSize.a[i]-RealSizeChange.a[i])/2)
                        {
                            Pos0.a[i] = El0->AbsSize.a[i]/2;
                            break;
                        }
//                        Pos0.a[i] = Pos0.a[i] - MoveVector.a[i];
                    }break;
					case lcmFreeze:
                    {
  //                      Pos0.a[i] = Pos0.a[i] - MoveVector.a[i];
                    }
                    break;
                }
        }
    }
    if (!returned&&!Try)
        delete this;
    return(returned);  */
    El1->SetMyHoleFor(NULL);
    return false;
}

TIntVec TLink::GetPos(int i)
{
    if (i==0)
        return(Pos0);
    if (i==1)
        return(Pos1);
    Application->MessageBox("The link can consist of only two elements!","Error");
    Application->Terminate();
    return(TIntVec(0,0,0));
}

void TLink::Refresh()
{
    if (El0!=NULL&&El1!=NULL)
    {
		TIntVec newAbsPos0;
        TIntVec newAbsPos1;
        TIntVec DeltaAngle;
        newAbsPos0 = RotateAround(Pos0,El0->AbsAngle,ZEROINTVEC)+El0->AbsPos;
        newAbsPos1 = RotateAround(Pos1,El1->AbsAngle,ZEROINTVEC)+El1->AbsPos;
        DeltaAngle = Angle - El1->AbsAngle + El0->AbsAngle;
        El1->UserChangePosition(newAbsPos0-newAbsPos1,DeltaAngle);
    }
}

TIntVec TLink::AbsPositionBy(TElement *El)
{
    if (El == Elements[0])
        return(RotateAround(Pos0,El0->AbsAngle,ZEROINTVEC)+El0->AbsPos);
    if (El == Elements[1])
        return(RotateAround(Pos1,El1->AbsAngle,ZEROINTVEC)+El1->AbsPos);
    Application->MessageBox("Can not find linked element!","Error");
    Application->Terminate();
    return(ZEROINTVEC);
}

void TLink::RunLinkTrigger(int Trigger)
{
    TLuaModule* LM = MyMeta->TB->GetModule(Trigger);
    if (LM)
    {
        TLink* BackLink = CurLink;
        CurLink = this;
        RunForm(LM);
        CurLink = BackLink;
	}
}


TIntVec CalculatePlatformSize()
{
    if (LN->Buldings.Count == 0)
        return TIntVec(36,36,0.02);

    TIntVec MIN;
    TIntVec MAX;
    for (int i=0;i<LN->Buldings.Count;i++)
        for (int j=0;j<LN->Buldings[i].Vertex->Count;j++)
        {
            UpdateMinVector(MIN,LN->Buldings[i].Vertex->Val(j));
            UpdateMaxVector(MAX,LN->Buldings[i].Vertex->Val(j));
        }
    TIntVec SIZE = TIntVec(1<<30,1<<30,1<<30)*(-1);
    UpdateMaxVector(SIZE,ABSINTVEC(MIN));
    UpdateMaxVector(SIZE,ABSINTVEC(MAX));
    SIZE = SIZE*2 + TIntVec(10,10,10);
    SIZE.z = 0.02;
    return SIZE;
}

void CreateSelView(TElement* El,TVisPrimitiveObj *SelObj, TVisPrimitiveObj *RT, TVisPrimitiveObj *UDT)
{
	TMDelTList<TPolygon> pList;
	TGeomObject g;
	TVisPrimitiveObj *obj;
	obj = new TVisPrimitiveObj(NULL);
	TVisMathVector AngleVec = VisMathVec( TIntVec(0, 0, 0) );

	if (El)
	{
		El->GetEdges(&pList);
		SelObj->Init();

		double Xcenter = 0, Ycenter = 0, Zcenter = 0;
		double MinSize = El->AbsSize.x, MinZ = 100000;
		MinSize = MinSize > El->AbsSize.y ? El->AbsSize.y : MinSize;

		int index;
		for (int i=0;i<pList.Count;i++)
		{
			SelObj->AddPrimitiveArray(GL_LINE_STRIP	);
			for (int j=0;j<pList[i].Vertex->Count;j++)
			{
				if((pList[i].Vertex->Val(j) - pList[i].Vertex->CycVal(j + 1)).Length() < MinSize)
					MinSize = (pList[i].Vertex->Val(j) - pList[i].Vertex->CycVal(j + 1)).Length();
				index = SelObj->Points->Add( VisMathVec( pList[i].Vertex->Val(j) ),ZEROVEC,ZEROVEC );
				SelObj->Primitive[i]->AddIndex(index);
				index = SelObj->Points->Add( VisMathVec( pList[i].Vertex->CycVal(j+1) ),ZEROVEC,ZEROVEC );
				SelObj->Primitive[i]->AddIndex(index);
				index = SelObj->Points->Add( VisMathVec( pList[i].Vertex->CycVal(j+1)+TIntVec(0,0,El->AbsSize.z) ),ZEROVEC,ZEROVEC );
				SelObj->Primitive[i]->AddIndex(index);
				index = SelObj->Points->Add( VisMathVec( pList[i].Vertex->Val(j)+TIntVec(0,0,El->AbsSize.z) ),ZEROVEC,ZEROVEC );
				SelObj->Primitive[i]->AddIndex(index);
				index = SelObj->Points->Add( VisMathVec( pList[i].Vertex->Val(j) ),ZEROVEC,ZEROVEC );
				SelObj->Primitive[i]->AddIndex(index);
			}
		}

		for (int i=0;i<pList[0].Vertex->Count; i++)
		{
			MBTi Angle = (AngleRad( pList[0].Vertex->CycVal(i-1), pList[0].Vertex->Val(i), pList[0].Vertex->CycVal(i+1),MBTi_EPS )*180 )/M_PI;
			TIntVec myPoint = RotateAround(pList[0].Vertex->CycVal(i-1),TIntVec(0,0,-Angle/2),pList[0].Vertex->Val(i));
			Angle = AngleRadOX(pList[0].Vertex->Val(i),myPoint);
			Angle = Angle * 180 / M_PI;

			obj->Init();
			obj->Assign(RT);
			Angle += 225;
			AngleVec.z = Angle;

			obj->Points->ScalePoints(0.3, 0.3, 0.3);
			for(int i = 0; i < obj->Points->Count; i ++)
				obj->Points->PointVec[i] = RotateAroundVMV(obj->Points->PointVec[i], AngleVec,ZEROVEC);
			obj->Points->MovePoints(pList[0].Vertex->Val(i).x, pList[0].Vertex->Val(i).y, pList[0].Vertex->Val(i).z+El->AbsSize.z / 2);

			Angle -= 225;
			AngleVec.z = Angle;


			TIntVec pointInside = (myPoint - pList[0].Vertex->Val(i)).Normalize()+pList[0].Vertex->Val(i);

			TIntVec FACTOR = PointOfLineOnCut(pointInside,pList[0].Vertex->Val(i),2)-pList[0].Vertex->Val(i);
			obj->Points->MovePoints(FACTOR.x, FACTOR.y, 0);

			if(MinZ > pList[0].Vertex->Val(i).z)
				MinZ = pList[0].Vertex->Val(i).z;
			MergeObjects(SelObj, obj);
			Xcenter += pList[0].Vertex->Val(i).x;
			Ycenter += pList[0].Vertex->Val(i).y;
			Zcenter += pList[0].Vertex->Val(i).z;
		}
		Xcenter /= 4;
		Ycenter /= 4;
		Zcenter /= 4;

		obj->Init();
		obj->Assign(UDT);

		obj->Points->ScalePoints(1, 1, 1);
		obj->Points->MovePoints(Xcenter, Ycenter, MinZ + El->AbsSize.z + 1);
		MergeObjects(SelObj, obj);

		SelObj->CalcNormals();
//        SelObj->Enabled = //Element->GetEnable();
		delete obj;
	}

}

