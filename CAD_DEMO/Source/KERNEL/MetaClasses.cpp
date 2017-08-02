//-------------  .h>
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MetaClasses.h"
#include <typeinfo.h>
#include "VisMat.hpp"
#include "VisComp.hpp"
#include "VisObj.hpp"
#include "VisExchange.hpp"
//--------------------------------------------------------------------------
#include "MyGL.h"
#include "Poligon.h"
#include "World.h"
#include "LogicNode.h"
#include "MYIMPORTV.h"
#include "ImgLibV.h"
#include "LuaModuleV.h"
//--------------------------------------------------------------------------
    #include "MDIMetaTextureV.h"
#include "MetaToolV.h"
//--------------------------------------------------------------------------
#if !defined(INTERNET_VER) && !defined(TRADE_VER)
    #include "MDIElementV.h"
    #include "MDIEpsEditV.h"
    #include "MDIMetaNodeV.h"
    #include "MDIConnectV.h"
    #include "MDIHasAngleV.h"
    #include "MDIHasSizeV.h"
    #include "MDIDynamicLinkEditV.h"
    #include "MDIActionsEditV.h"
    #include "MDIBMPSetV.h"
    #include "SelectBMPV.h"
    #include "MDIMetaMaterialV.h"
    #include "MDIMyTextureFlagsEditV.h"
    #include "MDIHasStepV.h"
    #include "MDIMyModeSettingsEditV.h"
    #include "MDIMyModeSettingListEditV.h"
    #include "MDICanExistsCheckEditV.h"
    #include "MDIMyTextureModesV.h"
    #include "MDIMyTextureModesListV.h"
    #include "MDIMetaVisParamV.h"
    #include "MDIMetaMyModeV.h"
#endif

//--------------------------------------------------------------------------
#pragma package(smart_init)
//--------------------------------------------------------------------------
TImageList *ILDefault;
TVisMaterial *MaterialDefault;
Graphics::TBitmap *BMPDef;

TLinkInfo* curLinkInfo;

TClassNode* THasStep::StaticType = NULL;
TClassNode* THasAngle::StaticType = NULL;
TClassNode* THasSize::StaticType = NULL;
TClassNode* TMetaEps::StaticType = NULL;
TClassNode* TMetaNode::StaticType = NULL;
TClassNode* TMetaLink::StaticType = NULL;
TClassNode* TMyColor::StaticType = NULL;
TClassNode* TMetaMaterial::StaticType = NULL;
TClassNode* TMetaMyMode::StaticType = NULL;
TClassNode* TBMPSet::StaticType = NULL;
TClassNode* TBMPPointer::StaticType = NULL;
TClassNode* TMyTextureFlags::StaticType = NULL;
TClassNode* TMyTextureModes::StaticType = NULL;
TClassNode* TMyTextureModesList::StaticType = NULL;
TClassNode* TMetaTexture::StaticType = NULL;
TClassNode* TMetaVisParam::StaticType = NULL;
TClassNode* TMyModeSettings::StaticType = NULL;
TClassNode* TMyModeSettingList::StaticType = NULL;
TClassNode* TMyActionSettings::StaticType = NULL;
TClassNode* TCanExistCheck::StaticType = NULL;
TClassNode* TMetaElement::StaticType = NULL;
TClassNode* TDynamicLink::StaticType = NULL;


TMetaNode* CreateMetaObject(const AnsiString& ClassName)
{
    return CreateMetaObject( ClassHead->Find(ClassName) );
}

TMetaNode* CreateMetaObject(TClassNode* ClassNode)
{
    if ( !ClassNode )
        return NULL;
    if ( !ClassNode->is(TMetaNode::StaticType) )
        return NULL;
    TMetaNode* MetaNode = (TMetaNode*)ClassNode->CreateFunction();
    MetaNode->DynamicType->RegisterNewInstance(MetaNode);
    return MetaNode;
}



void SetDefaults()
{
    ILDefault = new TImageList(45,30);
    BMPDef = new Graphics::TBitmap();
    BMPDef->HandleType = bmDIB;
    MaterialDefault = new TVisMaterial(NULL);
    MaterialDefault->ColorAmbient->Alpha=1;
    MaterialDefault->ColorDiffuse->Alpha=1;
    MaterialDefault->ColorSpecular->Alpha=1;
    MaterialDefault->ColorEmission->Alpha=1;
    MaterialDefault->ColorAmbient->Color=clGray;
    MaterialDefault->ColorDiffuse->Color=clGray;
    MaterialDefault->ColorSpecular->Color=clBlack;
    MaterialDefault->ColorEmission->Color=clBlack;
    MaterialDefault->Face = mfFront;
    MaterialDefault->Cached = false;
    MaterialDefault->Enabled = true;
    BMPDef->Width = 45;
    BMPDef->Height = 30;
    BMPDef->Canvas->CopyMode = cmWhiteness;
    BMPDef->Canvas->CopyRect(TRect(0,0,44,29),BMPDef->Canvas,TRect(0,0,44,29));
    BMPDef->Canvas->Font->Color = clSkyBlue;
    BMPDef->Canvas->Font->Style<< fsBold;
    int H = BMPDef->Canvas->TextHeight(AnsiString("SOPOS"));
    int W = BMPDef->Canvas->TextWidth(AnsiString("SOPOS"));
    BMPDef->Canvas->TextOut(BMPDef->Width/2-W/2,BMPDef->Height/2-H/2,AnsiString("SOPOS"));
    ILDefault->Add(BMPDef,NULL);
}

TMyObject* THasStep::CreateFunction()
{
    return new THasStep();
}

const AnsiString aBaseStep = AnsiString("BaseStep");
const AnsiString aDefMulti = AnsiString("DefMulti");
const AnsiString aHard = AnsiString("Hard");

THasStep::THasStep()
{
    RegisterNewClass< TMyObject, THasStep >(this,false,&CreateFunction);
    BaseStep = TIntVec(0.075,0.075,0.25);
    DefMulti = TIntVec(1,1,1);
    Hard = false;
    RegisterField(&BaseStep,&aBaseStep,mtIntVec);
    RegisterField(&DefMulti,&aDefMulti,mtIntVec);
    RegisterField(&Hard,&aHard,mtBool);
}

void THasStep::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIHasStep(Owner,Parent,this,"STEP EDIT",Data);
    #endif
}

bool THasStep::CheckFields()
{
    for (int i=0;i<3;i++)
    {
        DefMulti.a[i] = RoundTo(DefMulti.a[i],0);
        if (BaseStep.a[i]<0)
            return false;
    }
    return true;
}

TMyObject* THasAngle::CreateFunction()
{
    return new THasAngle();
}

const AnsiString aMirrored = AnsiString("Mirrored");
//уже описаны
const AnsiString aHI = AnsiString("HI");
const AnsiString aLOW = AnsiString("LOW");

THasAngle::THasAngle()
{
    RegisterNewClass< TMyObject, THasAngle >(this,false,&CreateFunction);
    RegisterField(&Mirrored,&aMirrored,mtBoolVec);
    RegisterField(&HI,&aHI,mtIntVec);
    RegisterField(&LOW,&aLOW,mtIntVec);
    Mirrored=TBoolVec(false,false,false);
    HI=ZEROINTVEC;
    LOW=ZEROINTVEC;
}

void THasAngle::SetLow(const TIntVec & newLow)
{
    FLow = newLow;
}

void THasAngle::SetHi(const TIntVec & newHi)
{
    FHi = newHi;
}

bool THasAngle::CheckFields()
{
    for (int i=0;i<3;i++)
    {
        if (HI.a[i]<0||HI.a[i]>360)
            return(false);
        if (LOW.a[i]<0||LOW.a[i]>360)
            return(false);
        if (LOW.a[i]>HI.a[i])
            return(false);
    }
    return(true);
}

void THasAngle::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIAngle(Owner,Parent,this,"Angle",Data);
    #endif
}

bool THasAngle::Valid(const TIntVec& Angle)
{
    for (int i=0;i<3;i++)
        if (Mirrored.a[i]==false)
        {
            if (Angle.a[i]<LOW.a[i])
                return(false);
            if (Angle.a[i]>HI.a[i])
                return(false);
        }
        else
        {
            if (Angle.a[i]<LOW.a[i]&&A360-Angle.a[i]<LOW.a[i])
                return(false);
            if (Angle.a[i]>HI.a[i]&&A360-Angle.a[i]>HI.a[i])
                return(false);
        }
    return(true);
}

//----------------------------------------TMetaLink----------------------------------
TMyObject* TMetaLink::CreateFunction()
{
    return new TMetaLink();
}

const AnsiString aAngle = AnsiString("Angle");
const AnsiString aHoleCreated = AnsiString("HoleCreated");
const AnsiString aLCM = AnsiString("LCM");
const AnsiString aClient = AnsiString("Client");
const AnsiString aClientNormal0 = AnsiString("ClientNormal0");
const AnsiString aClientNormal1 = AnsiString("ClientNormal1");
const AnsiString aEPS = AnsiString("EPS");
const AnsiString aSTEP = AnsiString("STEP");
const AnsiString aPriority = AnsiString("Priority");
const AnsiString aMetaLinkType = AnsiString("MetaLinkType");
const AnsiString aInWeb = AnsiString("InWeb");
const AnsiString aWallLink = AnsiString("WallLink");
const AnsiString aTransMode = AnsiString("TransMode");
const AnsiString aRunOnStop = AnsiString("RunOnStop");

const AnsiString aSCOPE0TargetDepend = AnsiString("SCOPE0TargetDepend");
const AnsiString aSCOPE1TargetDepend = AnsiString("SCOPE1TargetDepend");
const AnsiString aSCOPE0SourceDepend = AnsiString("SCOPE0SourceDepend");
const AnsiString aSCOPE1SourceDepend = AnsiString("SCOPE1SourceDepend");
const AnsiString aHasLinkModule = AnsiString("HasLinkModule");



TMetaLink::TMetaLink(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
:TMetaNode (_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaLink >(this,false,&CreateFunction);
    SCOPE0 = NULL;
    SCOPE1 = NULL;
    LinkModule = NULL;

    SCOPE0TargetDepend = false;
    SCOPE1TargetDepend = false;
    SCOPE0SourceDepend = false;
    SCOPE1SourceDepend = false;
    HasLinkModule = false;

    ChildType = cNone;
    LCM=ZEROINTVEC;
    TransMode = tmPosition;
    RunOnStop = false;

    RegisterField(&SCOPE0TargetDepend,&aSCOPE0TargetDepend,mtBool);
    RegisterField(&SCOPE1TargetDepend,&aSCOPE1TargetDepend,mtBool);
    RegisterField(&SCOPE0SourceDepend,&aSCOPE0SourceDepend,mtBool);
    RegisterField(&SCOPE1SourceDepend,&aSCOPE1SourceDepend,mtBool);
    RegisterField(&HasLinkModule,&aHasLinkModule,mtBool);

    RegisterField(&RunOnStop,&aRunOnStop,mtBool);
    RegisterField(&TransMode,&aTransMode,mtInt);
    RegisterField(&Angle,&aAngle,mtMyObject);
    RegisterField(&HoleCreated,&aHoleCreated,mtInt);
    RegisterField(&LCM,&aLCM,mtIntVec);
    RegisterField(&Client,&aClient,mtBool);
    RegisterField(&ClientNormal0,&aClientNormal0,mtInt);
    RegisterField(&ClientNormal1,&aClientNormal1,mtInt);
    RegisterField(&EPS,&aEPS,mtMyObject);
    RegisterField(&Priority,&aPriority,mtInt);
    RegisterField(&MetaLinkType,&aMetaLinkType,mtInt);
    RegisterField(&InWeb,&aInWeb,mtBool);
    RegisterField(&STEP,&aSTEP,mtMyObject);
    RegisterField(&WallLink,&aWallLink,mtBool);
//    RegisterField(&RouterLink,&aRouterLink,mtBool);
    MetaLinkType = 0;
    HoleCreated = false;
//    RouterLink = false;
    Client = false;
    ClientNormal0 = 0;
    ClientNormal1 = 0;
    ImageIndex=iiMetaLink;
    Priority = 0;
    InWeb = false;
    WallLink = false;
    //------------------------------
}

TMetaLink::TMetaLink()
{
    RegisterNewClass< TMetaNode, TMetaLink >(this,false,&CreateFunction);
    SCOPE0 = NULL;
    SCOPE1 = NULL;
    LinkModule = NULL;
    SCOPE0TargetDepend = false;
    SCOPE1TargetDepend = false;
    SCOPE0SourceDepend = false;
    SCOPE1SourceDepend = false;
    HasLinkModule = false;

    ChildType = cNone;
    LCM=ZEROINTVEC;
    TransMode = tmPosition;
    RunOnStop = false;

    RegisterField(&SCOPE0TargetDepend,&aSCOPE0TargetDepend,mtBool);
    RegisterField(&SCOPE1TargetDepend,&aSCOPE1TargetDepend,mtBool);
    RegisterField(&SCOPE0SourceDepend,&aSCOPE0SourceDepend,mtBool);
    RegisterField(&SCOPE1SourceDepend,&aSCOPE1SourceDepend,mtBool);
    RegisterField(&HasLinkModule,&aHasLinkModule,mtBool);

    RegisterField(&RunOnStop,&aRunOnStop,mtBool);
    RegisterField(&TransMode,&aTransMode,mtInt);
    RegisterField(&Angle,&aAngle,mtMyObject);
    RegisterField(&HoleCreated,&aHoleCreated,mtInt);
    RegisterField(&LCM,&aLCM,mtIntVec);
    RegisterField(&Client,&aClient,mtBool);
    RegisterField(&ClientNormal0,&aClientNormal0,mtInt);
    RegisterField(&ClientNormal1,&aClientNormal1,mtInt);
    RegisterField(&EPS,&aEPS,mtMyObject);
    RegisterField(&Priority,&aPriority,mtInt);
    RegisterField(&MetaLinkType,&aMetaLinkType,mtInt);
    RegisterField(&InWeb,&aInWeb,mtBool);
    RegisterField(&STEP,&aSTEP,mtMyObject);
    RegisterField(&WallLink,&aWallLink,mtBool);
//    RegisterField(&RouterLink,&aRouterLink,mtBool);
    MetaLinkType = 0;
    HoleCreated = false;
//    RouterLink = false;
    Client = false;
    ClientNormal0 = 0;
    ClientNormal1 = 0;
    ImageIndex=iiMetaLink;
    Priority = 0;
    InWeb = false;
    WallLink = false;
    //------------------------------
}



bool TMetaLink::CheckFields()
{
    if (!TMetaNode::CheckFields())
        return false;
    SCOPE0 = TB->GetModule(trScope0);
    SCOPE1 = TB->GetModule(trScope1);
    LinkModule = TB->GetModule(trLink);

    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    HasLinkModule = LinkModule && !LinkModule->CODE.IsEmpty() && LinkModule->CheckFields();
    SCOPE0TargetDepend = SCOPE0 && SCOPE0->CODE.Pos(".Target")!=0;
    SCOPE1TargetDepend = SCOPE1 && SCOPE1->CODE.Pos(".Target")!=0;
    SCOPE0SourceDepend = SCOPE0 && SCOPE0->CODE.Pos(".Source")!=0;
    SCOPE1SourceDepend = SCOPE1 && SCOPE1->CODE.Pos(".Source")!=0;
    #endif
    return true;
}

void TMetaLink::TargetScope(TElement* Target,TElement* Source,T3DScope& Scope)
{
    bool Recalculate = false;
    T3DScopeMem* TargetMem;
    T3DScopeMem* SourceMem;
    TargetMem = Target->SIZECACHE.Find(&(SCOPE0));
    if (SCOPE0TargetDepend)
        Recalculate = Recalculate||(!(TargetMem->Inited));
    if (SCOPE0SourceDepend)
    {
        SourceMem = Source->SIZECACHE.Find(&(SCOPE0));
        Recalculate = Recalculate||(!(SourceMem->Inited));
    }
    if (Recalculate)
    {
        LinkInfo.Source = Source;
        LinkInfo.Target = Target;
        LinkInfo.TargetScope = &(TargetMem->Scope);
        LinkInfo.SourceScope = NULL;
        curLinkInfo = &(LinkInfo);
        if (SCOPE0)
            SCOPE0->Run();
    }
    Scope = TargetMem->Scope;
    TargetMem->Inited = true;
    if (SCOPE0SourceDepend)
        SourceMem->Inited = true;
}

void TMetaLink::SourceScope(TElement* Target,TElement* Source,T3DScope& Scope)
{
    bool Recalculate = false;
    T3DScopeMem* TargetMem;
    T3DScopeMem* SourceMem;
    SourceMem = Source->SIZECACHE.Find(&(SCOPE1));
    if (SCOPE1SourceDepend)
        Recalculate = Recalculate||(!(SourceMem->Inited));
    if (SCOPE1TargetDepend)
    {
        TargetMem = Source->SIZECACHE.Find(&(SCOPE1));
        Recalculate = Recalculate||(!(TargetMem->Inited));
    }
    if (Recalculate)
    {
        LinkInfo.Source = Source;
        LinkInfo.Target = Target;
        LinkInfo.TargetScope = NULL;
        LinkInfo.SourceScope = &(SourceMem->Scope);
        curLinkInfo = &(LinkInfo);
        if (SCOPE1)
            SCOPE1->Run();
    }
    Scope = SourceMem->Scope;
    if (SCOPE1TargetDepend)
        TargetMem->Inited = true;
    SourceMem->Inited = true;
}

bool TMetaLink::RunLinkModule(TElement* Target,TElement* Source,TLINKPATTERN& SL,bool TransFormSize)
{
    LinkInfo.Source = Source;
    LinkInfo.Target = Target;
    LinkInfo.TargetScope = NULL;
    LinkInfo.SourceScope = NULL;
    LinkInfo.LINKPATTERN = &(SL);
    LinkInfo.OK = false;
    LinkInfo.SizeTransform = (TransFormSize);
    curLinkInfo = &(LinkInfo);
    if (LinkModule)
        LinkModule->Run();
    return LinkInfo.OK;
}

void TMetaLink::SourcePoint(TElement* Target,TElement* Source,TIntVec& Vector)
{
    bool Recalculate = false;
    T3DScopeMem* TargetMem;
    T3DScopeMem* SourceMem;
    SourceMem = Source->SIZECACHE.Find(&(SCOPE1));
    if (SCOPE1SourceDepend)
        Recalculate = Recalculate||(!(SourceMem->Inited));
    if (SCOPE1TargetDepend)
    {
        TargetMem = Source->SIZECACHE.Find(&(SCOPE1));
        Recalculate = Recalculate||(!(TargetMem->Inited));
    }
    if (Recalculate)
    {
        LinkInfo.Source = Source;
        LinkInfo.Target = Target;
        LinkInfo.TargetScope = NULL;
        LinkInfo.SourceScope = &(SourceMem->Scope);
        curLinkInfo = &(LinkInfo);
        if (SCOPE1)
            SCOPE1->Run();
    }
    Vector = SourceMem->Scope.LOW;
    if (SCOPE1TargetDepend)
        TargetMem->Inited = true;
    SourceMem->Inited = true;
}

void TMetaLink::UpdateMetaLinkTargetWithNewSource(TElement* Target)
{
    T3DScopeMem* TargetMem;
    if (SCOPE0SourceDepend)
    {
        TargetMem = Target->SIZECACHE.Find(&(SCOPE0));
        TargetMem->Inited = false;
    }
}

bool TMetaLink::UsedTrigger(int Trigger)
{
    return Trigger == trScope0 || Trigger == trScope1 || Trigger == trLink; 
}




void TMetaLink::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    TComponent *Owner;
    if (TN)
        Owner = TN->TreeView;
    else
        Owner = Application;
    new TMDIConnect(Owner,this);
    #endif
}



TMyObject* THasSize::CreateFunction()
{
    return new THasSize();
}

//const AnsiString aHI = AnsiString("HI");
//const AnsiString aLOW = AnsiString("LOW");
//const AnsiString aSTEP = AnsiString("STEP");
const AnsiString aDEFAULT = AnsiString("DEFAULT");

THasSize::THasSize()
{
    RegisterNewClass< TMyObject, THasSize >(this,false,&CreateFunction);
    RegisterField(&HI,&aHI,mtIntVec);
    RegisterField(&LOW,&aLOW,mtIntVec);
    RegisterField(&STEP,&aSTEP,mtMyObject);
    RegisterField(&DEFAULT,&aDEFAULT,mtIntVec);
    HI=TIntVec(3,3,3);
    LOW=TIntVec(0.01,0.01,0.01);
    DEFAULT=TIntVec(1,1,1);
}

void THasSize::SetLow(const TIntVec & newLow)
{
    FLow = newLow;
}

void THasSize::SetHi(const TIntVec & newHi)
{
    FHi = newHi;
}

void THasSize::SetDefault(const TIntVec & newDefault)
{
    FDefault = newDefault;
}

bool THasSize::CheckFields()
{
    for (int i=0;i<3;i++)
    {                //return this
        if (HI.a[i]<0||LOW.a[i]<0||DEFAULT.a[i]<0)
            return(false);
        if (LOW.a[i]>HI.a[i])
            return(false);
        if (DEFAULT.a[i]<LOW.a[i]||DEFAULT.a[i]>HI.a[i])
            return(false);
    }
    return(true);
}

void THasSize::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDISize(Owner,Parent,this,"Size",Data);
    #endif
}

void THasSize::Validate(TIntVec& Size)
{
    for (int i=0;i<3;i++)
    {
        if (Size.a[i]<LOW.a[i])
            Size.a[i] = LOW.a[i];
        if (Size.a[i]>HI.a[i])
            Size.a[i] = HI.a[i];
    }
}

bool THasSize::Valid(const TIntVec& Size)
{
    for (int i=0;i<3;i++)
    {
        if (Size.a[i]<LOW.a[i])
            return(false);
        if (Size.a[i]>HI.a[i])
            return(false);
    }
    return(true);
}

TMyObject* TMetaEps::CreateFunction()
{
    return new TMetaEps();
}

const AnsiString aPOSEPS = AnsiString("POSEPS");
const AnsiString aANGLEEPS = AnsiString("ANGLEEPS");
const AnsiString aSIZEEPS = AnsiString("SIZEEPS");

TMetaEps::TMetaEps()
{
    RegisterNewClass< TMyObject, TMetaEps >(this,false,&CreateFunction);
    RegisterField(&POSEPS,&aPOSEPS,mtIntVec);
    RegisterField(&ANGLEEPS,&aANGLEEPS,mtIntVec);
    RegisterField(&SIZEEPS,&aSIZEEPS,mtIntVec);
    POSEPS = ZEROINTVEC;
    ANGLEEPS = ZEROINTVEC;
    SIZEEPS = ZEROINTVEC;
}

bool TMetaEps::CheckFields()
{
    if ( !(POSEPS>=ZEROINTVEC) )
        return(false);
    if ( !(ANGLEEPS>=ZEROINTVEC) )
        return(false);
    if ( !(SIZEEPS>=ZEROINTVEC) )
        return(false);
    return(true);
}

TMyObject* TMyColor::CreateFunction()
{
    return new TMyColor();
}

const AnsiString aFColor = AnsiString("FColor");
const AnsiString aFAlpha = AnsiString("FAlpha");

TMyColor::TMyColor()
{
    RegisterNewClass< TMyObject, TMyColor >(this,false,&CreateFunction);
    Color = clBlack;
    FAlpha = 1;
    RegisterField(&FColor,&aFColor,mtInt);
    RegisterField(&FAlpha,&aFAlpha,mtDouble);
};

TColor TMyColor::GetColor() const
{
    return (TColor)FColor;
}

void TMyColor::SetColor(const TColor& _Color)
{
    FColor = (int)_Color;
}

void TMyColor::SetAlpha(const GLfloat& _Alpha)
{
    FAlpha = (double)_Alpha;
}

GLfloat TMyColor::GetAlpha() const
{
    return (GLfloat)FAlpha;
}

TMyObject* TMetaMaterial::CreateFunction()
{
    return new TMetaMaterial();
}

const AnsiString aAmbient = AnsiString("Ambient");
const AnsiString aDiffuse = AnsiString("Diffuse");
const AnsiString aEmission = AnsiString("Emission");
const AnsiString aSpecular = AnsiString("Specular");
const AnsiString aShininess = AnsiString("Shininess");
const AnsiString aFace = AnsiString("Face");
const AnsiString aTransparency = AnsiString("Transparency");

TMetaMaterial::TMetaMaterial()
{
    RegisterNewClass< TMetaNode, TMetaMaterial >(this,false,&CreateFunction);
    Shininess = 0;
    Transparency = true;
    RegisterField(&Ambient,&aAmbient,mtMyObject);
    RegisterField(&Diffuse,&aDiffuse,mtMyObject);
    RegisterField(&Emission,&aEmission,mtMyObject);
    RegisterField(&Specular,&aSpecular,mtMyObject);
    RegisterField(&Shininess,&aShininess,mtInt);
    RegisterField(&Face,&aFace,mtInt);
    RegisterField(&Transparency,&aTransparency,mtBool);
    Face = mfFront;
    VM = new TVisMaterial(NULL);
}

TMetaMaterial::~TMetaMaterial()
{
    delete VM;
}

bool TMetaMaterial::CheckFields()
{
    if (TMetaNode::CheckFields()==false)
        return false;
    VM->ColorAmbient->Color = Ambient.Color;
    VM->ColorDiffuse->Color = Diffuse.Color;
    VM->ColorEmission->Color = Emission.Color;
    VM->ColorSpecular->Color = Specular.Color;

    VM->ColorAmbient->Alpha = Ambient.Alpha;
    VM->ColorDiffuse->Alpha = Diffuse.Alpha;
    VM->ColorEmission->Alpha = Emission.Alpha;
    VM->ColorSpecular->Alpha = Specular.Alpha;
    VM->Shininess = (Shininess>=0)*(Shininess % 129);
    VM->Face = (TMaterialFace)Face;
    return true;
}

TMetaMaterial::TMetaMaterial(TMetaNode *Parent, int _ID, const AnsiString& _Name)
    :TMetaNode(Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaMaterial >(this,false,&CreateFunction);
    Shininess = 0;
    Transparency = true;
    ImageIndex = iiMaterials;
    ChildType = cNone;
    RegisterField(&Ambient,&aAmbient,mtMyObject);
    RegisterField(&Diffuse,&aDiffuse,mtMyObject);
    RegisterField(&Emission,&aEmission,mtMyObject);
    RegisterField(&Specular,&aSpecular,mtMyObject);
    RegisterField(&Shininess,&aShininess,mtInt);
    RegisterField(&Face,&aFace,mtInt);
    RegisterField(&Transparency,&aTransparency,mtBool);
    VM = new TVisMaterial(NULL);
    Face = mfFront;
    CheckFields();
}

void TMetaMaterial::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaMaterial(Owner,this);
    #endif
}

TMyObject* TBMPSet::CreateFunction()
{
    return new TBMPSet();
}


const AnsiString aFX = AnsiString("FX");
const AnsiString aFY = AnsiString("FY");

TBMPSet::TBMPSet()
{
    RegisterNewClass< TMetaNode, TBMPSet >(this,false,&CreateFunction);
    FX = 16;
    FY = 16;
    ImageIndex = iiBMPSet;
    ChildType = cNone;
    FIL = NULL;
    RegisterField(&FX,&aFX,mtInt);
    RegisterField(&FY,&aFY,mtInt);
}

TImageList* TBMPSet::GetIL()
{
    if (!FIL)
    {
        FIL = new TImageList(FX,FY);
        SetXY(FX,FY);
        AnsiString Dir = MainDir+SL+BMPDirName;
        if ( !DirectoryExists(Dir) && !ForceDirectories(Dir))
        {
            AnsiString Str = "Невозможно открыть файл - ";
            ErrorMsg(Str + Dir+SL+Name+BMP);
            Application->Terminate();
        }
        LoadBMP(FIL,Dir+SL+Name+BMP);
    }
    return FIL;
}

TBMPSet::TBMPSet(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TBMPSet >(this,false,&CreateFunction);
    FIL = NULL;
    FX = 16;
    FY = 16;
    R.left = 0;
    R.top = 0;
    R.right = 16;
    R.bottom = 16;
    ImageIndex = iiBMPSet;
    ChildType = cNone;
    RegisterField(&FX,&aFX,mtInt);
    RegisterField(&FY,&aFY,mtInt);

    Parent = _Parent;

    Name = _Name;
}

TBMPSet::~TBMPSet()
{
    if (FIL)
    {
        delete FIL;
        FIL = NULL;
    }
}

void TBMPSet::SetName(const AnsiString &newName)
{
    AnsiString Dir = MainDir+SL+BMPDirName;
    if (!FileExists(Dir+SL+Name+BMP))
    {
        FILE *F = fopen((Dir+SL+Name+BMP).c_str(),"w");
        fclose(F);
    }
    else
    {
        int attr = FileGetAttr(Dir+SL+Name+BMP);
        if (attr & faReadOnly)
            FileSetAttr(Dir+SL+Name+BMP,attr & !faReadOnly);
    }
    if (RenameFile(Dir+SL+Name+BMP,Dir+SL+newName+BMP))
    {
        TMetaNode::SetName(newName);
        if (newName != Name)
            RenameFile(Dir+SL+newName+BMP,Dir+SL+Name+BMP);
    }
}



int TBMPSet::X()
{
    return IL->Width;
}

int TBMPSet::Y()
{
    return IL->Height;
}

void TBMPSet::SetXY(int _X,int _Y)
{
    if (_X>0 &&_Y>0)
    {
        FX = _X;
        FY = _Y;
        IL->Clear();
        IL->Width = _X;
        IL->Height = _Y;
        R.Right = _X;
        R.Bottom = _Y;
    }
}

void TBMPSet::Assign(TMyObject* Obj)
{
    TMetaNode::Assign(Obj);
    IL->Assign( ((TBMPSet*)Obj)->IL );
}


void TBMPSet::SaveData(FILE *F) const
{
    TMetaNode::SaveData(F);
    if (FIL)
    {
        AnsiString Dir = MainDir+SL+BMPDirName;
        if ( (!DirectoryExists(Dir) && !ForceDirectories(Dir)) || !CHECK_FILE_SAVE(Dir+SL+Name+BMP))
        {
            AnsiString Str = "Невозможно создать файл - ";
            ErrorMsg(Str + Dir+SL+Name+BMP);
            Application->Terminate();
                Application->Terminate();
        }
        SaveBMP(FIL,Dir+SL+Name+BMP);
    }
}

void TBMPSet::WriteData(TMemoryStream *MS) const
{
    TMetaNode::WriteData(MS);
    if (FIL)
    {
        AnsiString Dir = MainDir+SL+BMPDirName;
        if ( (!DirectoryExists(Dir) && !ForceDirectories(Dir)) || !CHECK_FILE_SAVE(Dir+SL+Name+BMP))
        {
            AnsiString Str = "Невозможно создать файл - ";
            ErrorMsg(Str + Dir+SL+Name+BMP);
            Application->Terminate();
                Application->Terminate();
        }
        SaveBMP(FIL,Dir+SL+Name+BMP);
    }
}


void TBMPSet::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIBMPSet(Owner,this);
    #endif
}

bool TBMPPointer::Valid()
{
    return BMPSet.ADR && (FIndex < BMPSet.ADR->IL->Count);
}

bool TBMPPointer::GetBitmap(Graphics::TBitmap *BMP)
{
    if (Valid())
    {
        BMP->Width = ImgList->Width;
        BMP->Height = ImgList->Height;
        BMP->Canvas->CopyMode = cmWhiteness;
        TRect R = TRect(0,0,ImgList->Width-1,ImgList->Height-1);
        BMP->Canvas->CopyRect(R,BMP->Canvas,R);
        ImgList->GetBitmap(Index,BMP);
        return true;
    }
    else
    {
        GetStandartBitmap(siSOPOS,BMP);
        return false;
    }
}

void TBMPPointer::GetStandartBitmap(int __index,Graphics::TBitmap * BMP)
{
    BMP->Width = ImageLibrary->ilStandart->Width;
    BMP->Height = ImageLibrary->ilStandart->Height;
    BMP->Canvas->CopyMode = cmWhiteness;
    TRect R = TRect(0,0,ImageLibrary->ilStandart->Width-1,ImageLibrary->ilStandart->Height-1);
    BMP->Canvas->CopyRect(R,BMP->Canvas,R);
    ImageLibrary->ilStandart->GetBitmap(__index,BMP);
}

int TBMPPointer::GetIndex() const
{
    if (BMPSet.ADR && FIndex!=-1 && FIndex < BMPSet.ADR->IL->Count)
        return FIndex;
    else
        return 0;
}

TImageList *TBMPPointer::GetIL() const
{
    if (BMPSet.ADR && FIndex!=-1 && FIndex < BMPSet.ADR->IL->Count)
        return BMPSet.ADR->IL;
    else
        return ImageLibrary->ilStandart;
}



void TBMPPointer::SetIndex(int _Index)
{
    FIndex = _Index;
}

TMyObject* TBMPPointer::CreateFunction()
{
    return new TBMPPointer();
}

const AnsiString aFIndex = AnsiString("FIndex");
const AnsiString aBMPSet = AnsiString("BMPSet");

TBMPPointer::TBMPPointer()
{
    RegisterNewClass< TMyObject, TBMPPointer >(this,false,&CreateFunction);
    RegisterField(&FIndex,&aFIndex,mtInt);
    RegisterField(&BMPSet,&aBMPSet,mtMyObject);
}

void TBMPPointer::Select()
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    TSelectBMP *SBMP = new TSelectBMP(Application);
    SBMP->BMPS = BMPSet.ADR;
    SBMP->Index = Index;
    SBMP->ShowModal();
    if ( (SBMP->BMPS!=NULL && SBMP->Index !=-1) || SBMP->Clear)
    {
        BMPSet.ADR = SBMP->BMPS;
        Index = SBMP->Index;
    }
    delete SBMP;
    #endif
}

void TBMPPointer::Assign(TMyObject* MO)
{
    if ( typeid(*MO) ==typeid(TBMPPointer) )
    {
        TBMPPointer* Else = (TBMPPointer*)MO;
        Index = Else->RealIndex;
        BMPSet.ADR = Else->BMPSet.ADR;
    }
}
////////////TMetaTexture
void ApplyMipMaps(TVisTexture *VT,const TPointer<TBMPSet> &MipMaps)
{
  VT->ClearMipMaps();
  if ( MipMaps.ADR)
    for ( int i=0;i<MipMaps.ADR->IL->Count;i++)
    {
      Graphics::TBitmap * _bmp = new Graphics::TBitmap;
                _bmp->HandleType = bmDIB;
      MipMaps.ADR->IL->GetBitmap(i,_bmp);
      VT->AddMipMap(_bmp);
      delete _bmp;
    }
}

void TMetaTexture::SetAlpha(const GLfloat& _Alpha)
{
    FAlpha = (double)_Alpha;
}

GLfloat TMetaTexture::GetAlpha() const
{
    return (GLfloat)FAlpha;
}

TMyObject* TMetaTexture::CreateFunction()
{
    return new TMetaTexture();
}

const AnsiString aRotate = AnsiString("Rotate");
const AnsiString aTranslation = AnsiString("Translation");
const AnsiString aScale = AnsiString("Scale");
//const AnsiString aFAlpha = AnsiString("FAlpha");
const AnsiString aBlend = AnsiString("Blend");
const AnsiString aMode = AnsiString("Mode");
const AnsiString aBMP = AnsiString("BMP");
const AnsiString aMinFilter = AnsiString("MinFilter");
const AnsiString aMagFilter = AnsiString("MagFilter");
const AnsiString aMipMaps = AnsiString("MipMaps");
const AnsiString aRealSizeX = AnsiString("RealSizeX");
const AnsiString aRealSizeY = AnsiString("RealSizeY");


TMetaTexture::TMetaTexture()
{
    RegisterNewClass< TMetaNode, TMetaTexture >(this,false,&CreateFunction);
    Mode = tmModulate;
    Translation = ZEROINTVEC;
    Rotate = ZEROINTVEC;
    Scale = TIntVec(1,1,1);
    Alpha = 1;
    RegisterField(&Rotate,&aRotate,mtIntVec);
    RegisterField(&Translation,&aTranslation,mtIntVec);
    RegisterField(&Scale,&aScale,mtIntVec);
    RegisterField(&FAlpha,&aFAlpha,mtDouble);
    RegisterField(&Blend,&aBlend,mtMyObject);
    RegisterField(&Mode,&aMode,mtInt);
    RegisterField(&BMP,&aBMP,mtMyObject);
    RegisterField(&MinFilter,&aMinFilter,mtInt);
    RegisterField(&MagFilter,&aMagFilter,mtInt);
    RegisterField(&MipMaps,&aMipMaps,mtMyObject);
    RegisterField(&RealSizeX,&aRealSizeX,mtMBTi);
    RegisterField(&RealSizeY,&aRealSizeY,mtMBTi);

    RealSizeX = 1;
    RealSizeY = 1;
    MinFilter = tfLinear;
    MagFilter = tfLinear;
    VT = new TVisTexture(NULL);
}

TMetaTexture::~TMetaTexture()
{
    delete VT;
}

bool TMetaTexture::CheckFields()
{
    if (TMetaNode::CheckFields()==false)
        return false;
    Graphics::TBitmap *bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    BMP.GetBitmap(bmp);
    VT->Bitmap->Assign(bmp);
    delete bmp;
    VT->Mode = (TVisTexMode)Mode;
    VT->Alpha = Alpha;
    VT->BlendColor->Color = Blend.Color;
    VT->BlendColor->Alpha = Blend.Alpha;
    VT->MagFilter = (TVisTexFilter)MagFilter;
    VT->MinFilter = (TVisTexFilter)MinFilter;
    AssignVisVec(*(VT->Transformation->Rotation),Rotate);
    AssignVisVec(*(VT->Transformation->Translation),Translation);
    AssignVisVec(*(VT->Transformation->Scale),Scale);

    VT->ClearMipMaps();
    if (MinFilter!=tfLinear && MinFilter!=tfNearest)
      ApplyMipMaps(VT,MipMaps);
    return true;
}

TMetaTexture::TMetaTexture(TMetaNode *Parent, int _ID, const AnsiString& _Name)
    :TMetaNode(Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaTexture >(this,false,&CreateFunction);
    Mode = tmModulate;
    Translation = ZEROINTVEC;
    Rotate = ZEROINTVEC;
    Scale = TIntVec(1,1,1);
    Alpha = 1;
    ImageIndex = iiTextures;
    ChildType = cNone;
    RegisterField(&Rotate,&aRotate,mtIntVec);
    RegisterField(&Translation,&aTranslation,mtIntVec);
    RegisterField(&Scale,&aScale,mtIntVec);
    RegisterField(&FAlpha,&aFAlpha,mtDouble);
    RegisterField(&Blend,&aBlend,mtMyObject);
    RegisterField(&Mode,&aMode,mtInt);
    RegisterField(&BMP,&aBMP,mtMyObject);
    RegisterField(&MinFilter,&aMinFilter,mtInt);
    RegisterField(&MagFilter,&aMagFilter,mtInt);
    RegisterField(&MipMaps,&aMipMaps,mtMyObject);
    RegisterField(&RealSizeX,&aRealSizeX,mtMBTi);
    RegisterField(&RealSizeY,&aRealSizeY,mtMBTi);
    RealSizeX = 1;
    RealSizeY = 1;
    MinFilter = tfLinear;
    MagFilter = tfLinear;
    VT = new TVisTexture(NULL);
    CheckFields();
}

TMyObject* TMetaMyMode::CreateFunction()
{
    return new TMetaMyMode();
}

const AnsiString aCAM = AnsiString("CAM");

TMetaMyMode::TMetaMyMode(TMetaNode *Parent, int _ID, const AnsiString& _Name)
    :TMetaNode(Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaMyMode >(this,false,&CreateFunction);
    CAM = 0;
    RegisterField(&CAM,&aCAM,mtInt);
    ImageIndex = iiMetaMyMode;
}

TMetaMyMode::TMetaMyMode()
{
    RegisterNewClass< TMetaNode, TMetaMyMode >(this,false,&CreateFunction);
    CAM = 0;
    RegisterField(&CAM,&aCAM,mtInt);
    ImageIndex = iiMetaMyMode;
}

void TMetaMyMode::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
  new TMDIMetaMyMode(Owner,this);
    #endif
}

void TMetaTexture::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaTexture(Owner,this);
    #endif
}

TMyObject* TMyTextureFlags::CreateFunction()
{
    return new TMyTextureFlags();
}

//const AnsiString aMode = AnsiString("Mode");
const AnsiString aParam = AnsiString("Param");
//const AnsiString aScale = AnsiString("Scale");
const AnsiString aShift = AnsiString("Shift");
const AnsiString aMTF = AnsiString("MTF");

TMyTextureFlags::TMyTextureFlags()
{
    RegisterNewClass< TMyObject, TMyTextureFlags >(this,false,&CreateFunction);
    Shift = TIntVec(-0.5,-0.5,0);
    Scale = TIntVec(1,1,0);
    Mode = 0;
    Param = ZEROINTVEC;
    RegisterField(&Mode,&aMode,mtInt);
    RegisterField(&Param,&aParam,mtIntVec);
    RegisterField(&Scale,&aScale,mtIntVec);
    RegisterField(&Shift,&aShift,mtIntVec);
}

void TMyTextureFlags::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMyTextureFlagsEdit(Owner,Parent,this,"Texture Flags",Data);
    #endif
}

TMyObject* TMetaVisParam::CreateFunction()
{
    return new TMetaVisParam();
}

const AnsiString aTML = AnsiString("TML");
const AnsiString aMAT = AnsiString("MAT");
const AnsiString aTEX = AnsiString("TEX");

TMetaVisParam::TMetaVisParam()
    :TMetaNode()
{
    RegisterNewClass< TMetaNode, TMetaVisParam >(this,false,&CreateFunction);
    ImageIndex = iiMetaVisParam;
    RegisterField(&TML,&aTML,mtMyObject);
    RegisterField(&MAT,&aMAT,mtMyObject);
    RegisterField(&TEX,&aTEX,mtMyObject);
}

TMetaVisParam::TMetaVisParam(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
    :TMetaNode(_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaVisParam >(this,false,&CreateFunction);
    ImageIndex = iiMetaVisParam;
    RegisterField(&TML,&aTML,mtMyObject);
    RegisterField(&MAT,&aMAT,mtMyObject);
    RegisterField(&TEX,&aTEX,mtMyObject);
}

void TMetaVisParam::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaVisParam(Owner,this);
    #endif
}

TMyObject* TMyTextureModes::CreateFunction()
{
    return new TMyTextureModes();
}

const AnsiString aZMin = AnsiString("ZMin");
const AnsiString aZMax = AnsiString("ZMax");

TMyTextureModes::TMyTextureModes()
{
    RegisterNewClass< TMyObject, TMyTextureModes >(this,false,&CreateFunction);
    Mode = 0;
    ZMin = -1;
    ZMax = -1;
    RegisterField(&Mode,&aMode,mtInt);
    RegisterField(&ZMin,&aZMin,mtMBTi);
    RegisterField(&ZMax,&aZMax,mtMBTi);
}

void TMyTextureModes::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMyTextureModes(Owner,Parent,this,"MyTextureModes",Data);
    #endif
}

TMyObject* TMyTextureModesList::CreateFunction()
{
    return new TMyTextureModesList();
}

const AnsiString aTEXMODES = AnsiString("TEXMODES");

TMyTextureModesList::TMyTextureModesList()
{
    RegisterNewClass< TMyObject, TMyTextureModesList >(this,false,&CreateFunction);
    RegisterField(&TEXMODES,&aTEXMODES,mtMyObject);
}

void TMyTextureModesList::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMyTextureModesList(Owner,Parent,this,"TextureFlagsObjectList",Data);
    #endif
}


void TMetaEps::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIEpsEdit(Owner,Parent,this,"EPSILONS",Data);
    #endif
}


//---------------------------TMetaElement-------------------------
TMyObject* TMyActionSettings::CreateFunction()
{
    return new TMyActionSettings();
}

const AnsiString aTools = AnsiString("Tools");
const AnsiString aCreateTools = AnsiString("CreateTools");

TMyActionSettings::TMyActionSettings()
    :Tools( *(new TMDelTList< TPointer<TMetaTool> >()) ),
    CreateTools( *(new TMDelTList< TPointer<TMetaTool> >()) )
{
    RegisterNewClass< TMyObject, TMyActionSettings >(this,false,&CreateFunction);
    RegisterField(&Tools,&aTools,mtMyObject);
    RegisterField(&CreateTools,&aCreateTools,mtMyObject);
}

TMyActionSettings::~TMyActionSettings()
{
    delete &(Tools);
    delete &(CreateTools);
}

void TMyActionSettings::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIActionsEdit(_Owner,Parent,this,"ActionSettings",Data);
    #endif
}

TMyObject* TMyModeSettings::CreateFunction()
{
    return new TMyModeSettings();
}

const AnsiString aOverPosMode = AnsiString("OverPosMode");
const AnsiString aOverSizeMode = AnsiString("OverSizeMode");
const AnsiString aOverSize = AnsiString("OverSize");
const AnsiString aOverPos = AnsiString("OverPos");
const AnsiString aMATs = AnsiString("MATs");
const AnsiString aMeta_Mode = AnsiString("Meta_Mode");
const AnsiString aTEXs = AnsiString("TEXs");
const AnsiString aRender = AnsiString("Render");
const AnsiString aFLAT_2D = AnsiString("FLAT_2D");

TMyModeSettings::TMyModeSettings()
{
    RegisterNewClass< TMyObject, TMyModeSettings >(this,false,&CreateFunction);
  OverSizeMode = 0;
  OverPosMode = 0;
  OverSize = ZEROINTVEC;
  OverPos = ZEROINTVEC;
  FLAT_2D = false;
  Render = true;

  RegisterField(&OverPosMode,&aOverPosMode,mtInt);
  RegisterField(&OverSizeMode,&aOverSizeMode,mtInt);
  RegisterField(&OverSize,&aOverSize,mtIntVec);
  RegisterField(&OverPos,&aOverPos,mtIntVec);

  RegisterField(&MATs,&aMATs,mtMyObject);
  RegisterField(&Meta_Mode,&aMeta_Mode,mtMyObject);
  RegisterField(&TEXs,&aTEXs,mtMyObject);
  RegisterField(&Render,&aRender,mtBool);
  RegisterField(&FLAT_2D,&aFLAT_2D,mtBool);
}

void TMyModeSettings::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMyModeSettingsEdit(_Owner,Parent,this,"Mode Settings",Data);
    #endif
}

TMyObject* TMyModeSettingList::CreateFunction()
{
    return new TMyModeSettingList();
}

const AnsiString aMode_Set_List = AnsiString("Mode_Set_List");
const AnsiString aDefaultMode = AnsiString("DefaultMode");

TMyModeSettingList::TMyModeSettingList()
{
	RegisterNewClass< TMyObject, TMyModeSettingList >(this,false,&CreateFunction);
  Mode_Set_List = new /*TMDelLSTList*/TMDelTList<TMyModeSettings>();
  RegisterField(Mode_Set_List,&aMode_Set_List,mtMyObject);
  RegisterField(&DefaultMode,&aDefaultMode,mtMyObject);
}

TMyModeSettingList::~TMyModeSettingList()
{
  delete Mode_Set_List;
}

void TMyModeSettingList::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMyModeSettingListEdit(Owner,Parent,this,"Mode Setting List",Data);
    #endif
}

TMyModeSettings* TMyModeSettingList::FindByMode(TMetaMyMode * MMM)
{
  int DefModeIndex = -1;
  for (int i=0;i<Mode_Set_List->Count;i++)
  {
	if (Mode_Set_List->Items[i]->Meta_Mode.ADR == MMM)
	  return Mode_Set_List->Items[i];
	if (Mode_Set_List->Items[i]->Meta_Mode.ADR == DefaultMode.ADR)
	  DefModeIndex = i;
  }
  if(DefModeIndex >= 0)
	return Mode_Set_List->Items[DefModeIndex];
  return NULL;
}

TMyObject* TMetaNode::CreateFunction()
{
    return new TMetaNode();
}

const AnsiString aChildType = AnsiString("ChildType");
const AnsiString aImageIndex = AnsiString("ImageIndex");
const AnsiString aTB = AnsiString("TB");
const AnsiString aImg1 = AnsiString("Img1");
const AnsiString aSmallImg = AnsiString("SmallImg");

TMetaNode::TMetaNode(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMyRegObject, TMetaNode >(this,false,&CreateFunction);
    ReadOnly = true;
    Parent = _Parent;
    ChildType = cNone;
    TB = new TTriggerBlock();
    Img1 = new TBMPPointer();
    SmallImg = new TBMPPointer();
    RegisterField(SmallImg,&aSmallImg,mtMyObject);
    RegisterField(Img1,&aImg1,mtMyObject);
    RegisterField(&ChildType,&aChildType,mtString);
    RegisterField(&ImageIndex,&aImageIndex,mtInt);
    RegisterField(TB,&aTB,mtMyObject);
    //registry
    Name = _Name;
}

TMetaNode& TMetaNode::operator = (TMetaNode& MN)
{
    Assign(&MN);
    return *this;
}

bool TMetaNode::UsedTrigger(int Trigger)
{
    bool res = (Trigger == trGlobal) || (Trigger == trAddFloor) || (Trigger == trTechCheck) || (Trigger == trAfterCount);
    return (MetaNodeCollection->Head == this)&& (res);
}

TMetaNode::~TMetaNode()
{
    delete TB;
    delete Img1;
    delete SmallImg;
}

bool TMetaNode::CheckFields()
{
    if (!TMyRegObject::CheckFields())
        return false;
    ReadOnly = true;
    return true;
}

TMetaNode::TMetaNode()
{
	RegisterNewClass< TMyRegObject, TMetaNode >(this,false,&CreateFunction);
	IsNew = false;
	ReadOnly = true;
	TB = new TTriggerBlock();
	Img1 = new TBMPPointer();
	SmallImg = new TBMPPointer();
	RegisterField(SmallImg,&aSmallImg,mtMyObject);
	RegisterField(Img1,&aImg1,mtMyObject);
	RegisterField(&ChildType,&aChildType,mtString);
	RegisterField(&ImageIndex,&aImageIndex,mtInt);
	RegisterField(TB,&aTB,mtMyObject);
	ChildType = cNone;
}

void TMetaNode::SetName(const AnsiString &newName)
{
    TMyRegObject::SetName(newName);
    if (Name != newName)
        TB->Name = newName;
}

//--------------------------------------------------------------------------
void TMetaNode::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    TComponent *Owner;
    if (TN)
        Owner = TN->TreeView;
    else
        Owner = Application;
    new TMDIMetaNode(Owner,this);
    #endif
}

void TMetaNode::GetImage(bool Small,bool Masked,Graphics::TBitmap* bmp,Graphics::TBitmap* mask)
{
    TBMPPointer* USEBMPPTR = NULL;
    if (Small)
    {
        if (SmallImg->Valid())
            USEBMPPTR = SmallImg;
    }
    else
    {
        if (Img1->Valid())
            USEBMPPTR = Img1;
    }
    int index = -1;
    TImageList* USEIL = NULL;
    if (USEBMPPTR)
    {
        index = USEBMPPTR->Index;
        USEIL = USEBMPPTR->ImgList;
    }
    else
    {
        USEIL = ImageLibrary->ilStandart;
        if (typeid(*this) == typeid(TMetaNode))
            index = siFOLDER;
        else
            index = siSOPOS;
        index = index + 2*int(Masked);
    }
    bmp->Width = USEIL->Width;
    bmp->Height = USEIL->Height;
    mask->Width = USEIL->Width;
    mask->Height = USEIL->Height;
    USEIL->GetBitmap(index,bmp);
    USEIL->Draw(mask->Canvas,0,0,index,dsNormal,itMask);
}

TMyObject* TCanExistCheck::CreateFunction()
{
    return new TCanExistCheck();
}

const AnsiString aLinkGroups = AnsiString("LinkGroups");
bool TechnologyCheckPass;
char* TechnologyCheckStr;

TCanExistCheck::TCanExistCheck()
{
    RegisterNewClass< TMyObject, TCanExistCheck >(this,false,&CreateFunction);
    LinkGroups = new /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList< TPointer<TDynamicLink> > >();
    RegisterField(LinkGroups,&aLinkGroups,mtMyObject);
}

TCanExistCheck::~TCanExistCheck()
{
    delete LinkGroups;
}

TMTList<TDynamicLink> *ServiceLinkList = new TMTList<TDynamicLink>();

bool TCanExistCheck::TechCheck(TElement *El,AnsiString& Str)
{
    ServiceLinkList->Clear();
    if (LinkGroups->Count==0)
        return true;
    for (int i=0;i<El->FLinks.Count;i++)
        if ( ServiceLinkList->IndexOf(El->FLinks[i].MyMeta) == -1)
            ServiceLinkList->Add(El->FLinks[i].MyMeta);
    for (int i=0;i<LinkGroups->Count;i++)
    {
        bool consists=true;
        for (int j=0;j<LinkGroups->Items[i]->Count;j++)
            if ( ServiceLinkList->IndexOf(LinkGroups->Items[i]->Items[j]->ADR) == -1 )
            {
                consists = false;
                break;
            }                              
        if (consists)
            return true;
    }
    Str = AnsiString("Object ")+El->MyMeta->Description;
    Str = Str + AnsiString(MSG_7);
    Str = Str + AnsiString("\n\n");
    for (int i=0;i<LinkGroups->Count;i++)
    {
        if (i>0)
            Str = Str + AnsiString("\nили\n");
        for (int j=0;j<LinkGroups->Items[i]->Count;j++)
        {
            if (j>0)
                Str = Str + AnsiString(", ");
            Str = Str + LinkGroups->Items[i]->Items[j]->ADR->El0->Description;
        }
    }
    return false;
}

void TCanExistCheck::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDICanExistsCheckEdit(Owner,Parent,this,AnsiString("Checks permissions"),Data);
    #endif
}

TMyObject* TMetaElement::CreateFunction()
{
    return new TMetaElement();
}

const AnsiString aSize = AnsiString("Size");
//const AnsiString aEPS = AnsiString("EPS");
const AnsiString aIsWall = AnsiString("IsWall");
const AnsiString aIsSupport = AnsiString("IsSupport");
const AnsiString aStartZED = AnsiString("StartZED");
const AnsiString aFILEBMP = AnsiString("FILEBMP");
const AnsiString aMAS = AnsiString("MAS");
//const AnsiString aMAT = AnsiString("MAT");
//const AnsiString aTEX = AnsiString("TEX");
//const AnsiString aMTF = AnsiString("MTF");
const AnsiString aMMSL = AnsiString("MMSL");
const AnsiString aDrawView = AnsiString("DrawView");
const AnsiString aCanExistCheck = AnsiString("CanExistCheck");
//const AnsiString aInWeb = AnsiString("InWeb");
const AnsiString aDEPENDLST = AnsiString("DEPENDLST");
const AnsiString aShowButton = AnsiString("ShowButton");

TMetaElement::TMetaElement(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
:TMetaNode (_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TMetaElement >(this,false,&CreateFunction);
    ShowButton = false;
    IsLight = false;
    ChildType = cDynamicLink;
    RegisterField(&Size,&aSize,mtMyObject);
    RegisterField(&EPS,&aEPS,mtMyObject);
    RegisterField(&IsWall,&aIsWall,mtBool);
    RegisterField(&IsSupport,&aIsSupport,mtBool);
    RegisterField(&StartZED,&aStartZED,mtMBTi);
    RegisterField(&FILEBMP,&aFILEBMP,mtInt);
    RegisterField(&MAS,&aMAS,mtMyObject);
    RegisterField(&MAT,&aMAT,mtMyObject);
    RegisterField(&TEX,&aTEX,mtMyObject);
    RegisterField(&MTF,&aMTF,mtMyObject);
    RegisterField(&MMSL,&aMMSL,mtMyObject);
    RegisterField(&DrawView,&aDrawView,mtBool);
    RegisterField(&CanExistCheck,&aCanExistCheck,mtMyObject);
    RegisterField(&InWeb,&aInWeb,mtBool);
    RegisterField(&DEPENDLST,&aDEPENDLST,mtMyObject);
    RegisterField(&ShowButton,&aShowButton,mtBool);

    InWeb = false;
    IsWall = false;
    IsSupport = false;
    StartZED = 0;
    IsAuto = false;
    FILEBMP = uiDefaultIndex;
    DrawView = false;
}

TMetaElement& TMetaElement::operator = (TMetaElement& ME)
{
    Assign(&ME);
    return *this;        
}

bool TMetaElement::UsedTrigger(int Trigger)
{
    if ((Trigger == trStartEdit)||(Trigger == trChangeSize))
        return true;
    if ((Trigger == trPaymentCount) || (Trigger == trEdit) )
        return true;
    if ((Trigger == trConstruct)||(Trigger == trEndEdit) ||(Trigger == trCreate))
        return true;
    if ((Trigger == trRender2D)||(Trigger == trSuccessDriver))
        return true;
    if ((Trigger == trBeforeDriverStop) || (Trigger == trTechCheck))
        return true;
    if ((Trigger == trEditRender) || (Trigger == trAutoAlign))
        return true;

    return false;
}

TMetaElement::TMetaElement()
{
    RegisterNewClass< TMetaNode, TMetaElement >(this,false,&CreateFunction);
    ShowButton = false;
    IsLight = false;
    ChildType = cDynamicLink;
    RegisterField(&Size,&aSize,mtMyObject);
    RegisterField(&EPS,&aEPS,mtMyObject);
    RegisterField(&IsWall,&aIsWall,mtBool);
    RegisterField(&IsSupport,&aIsSupport,mtBool);
    RegisterField(&StartZED,&aStartZED,mtMBTi);
    RegisterField(&FILEBMP,&aFILEBMP,mtInt);
    RegisterField(&MAS,&aMAS,mtMyObject);
    RegisterField(&MAT,&aMAT,mtMyObject);
    RegisterField(&TEX,&aTEX,mtMyObject);
    RegisterField(&MTF,&aMTF,mtMyObject);
    RegisterField(&MMSL,&aMMSL,mtMyObject);
    RegisterField(&DrawView,&aDrawView,mtBool);
    RegisterField(&CanExistCheck,&aCanExistCheck,mtMyObject);
    RegisterField(&InWeb,&aInWeb,mtBool);
    RegisterField(&DEPENDLST,&aDEPENDLST,mtMyObject);
    RegisterField(&ShowButton,&aShowButton,mtBool);

    InWeb = false;
    IsWall = false;
    IsSupport = false;
    StartZED = 0;
    IsAuto = false;
    FILEBMP = uiDefaultIndex;
    DrawView = false;
}

void TMetaElement::Edit(TComponent *_Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIElement(_Owner,this);
    #endif
}

TDynamicLink* TMetaElement::GetDynLink(int index)
{
    return (TDynamicLink*)ChildList->Items[index];
}

int TMetaElement::GetDynLinkCount()
{
    return ChildList->Count;
}


TMetaElement::~TMetaElement()
{

}

bool TMetaElement::TechCheck(TElement *El,AnsiString& Str)
{
    if ( (TB->GetModule(trTechCheck))!=NULL )
    {
        TechnologyCheckStr = "";
        TechnologyCheckPass = false;
        El->RunElementTrigger(trTechCheck);
        Str = AnsiString(TechnologyCheckStr);
        return TechnologyCheckPass;

    }
    else
        return CanExistCheck.TechCheck(El,Str);
}
/*
TVisMaterial *TMetaElement::GetVisMaterial(TMetaMyMode* Mode)
{
    TMetaMaterial* MetaMat = NULL;
    TMyModeSettings* MMS = MMSL.FindByMode(Mode);
    if (MMS)
        MetaMat =  MMS->MAT.ADR;
    else
        MetaMat = MAT.ADR;
    if (MetaMat)
        return MetaMat->VM;
    else
        return MaterialDefault;
} */

TVisMaterial *TMetaElement::GetMaterial()
{
    if (MAT.ADR)
        return MAT.ADR->VM;
    else
        return MaterialDefault;
}

TDynamicLink* TMetaElement::SearchNeededLinkFor(TMetaElement * Target)
{
    for (int i=0;i<ChildList->Count;i++)
    {
        TDynamicLink* DLink = (TDynamicLink*)ChildList->Items[i];
        if ( DLink->NeededFor(this) && DLink->El0 == Target )
            return DLink;
    }
    return(NULL);
}

//---------------------------TDynamicLink-------------------------
TMyObject* TDynamicLink::CreateFunction()
{
    return new TDynamicLink();
}

const AnsiString aID0 = AnsiString("ID0");
const AnsiString aID1 = AnsiString("ID1");
const AnsiString aIDL = AnsiString("IDL");
const AnsiString aNeeded = AnsiString("Needed");
const AnsiString aEL0 = AnsiString("EL0");
const AnsiString aEL1 = AnsiString("EL1");
const AnsiString aML = AnsiString("ML");

TDynamicLink::TDynamicLink(TMetaElement *_Parent,int _ID,const AnsiString& _Name)
:TMetaNode (_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaNode, TDynamicLink >(this,false,&CreateFunction);
//    FEl0 = NULL;
//    FLink = NULL;
    Needed=false;
//    RegisterField(&ID0,&aID0,mtInt);
//    RegisterField(&ID1,&aID1,mtInt);
//    RegisterField(&IDL,&aIDL,mtInt);
    RegisterField(&Needed,&aNeeded,mtBool);
    RegisterField(&EL0,&aEL0,mtMyObject);
    RegisterField(&EL1,&aEL1,mtMyObject);
    RegisterField(&ML,&aML,mtMyObject);
    ChildType = cNone;
    EL1.ADR = _Parent;
//    ID1 = Parent->ID;
//    ID0 = 0;
//    IDL = 0;
    ImageIndex=iiDynamicLink;
    //потом будет ландшафт и каждый элемент имеет с ним связку по умолчанию
}

bool TDynamicLink::UsedTrigger(int Trigger)
{
    return  (Trigger == trPaymentCount) ||
            (Trigger == trLinkCreate) ||
            (Trigger == trLinkDestroyEl0) ||
            (Trigger == trLinkDestroyEl1);
}

TDynamicLink::TDynamicLink()
{
    RegisterNewClass< TMetaNode, TDynamicLink >(this,false,&CreateFunction);
  //  FEl0 = NULL;
//    FLink = NULL;
    Needed=false;
//    RegisterField(&ID0,&aID0,mtInt);
//    RegisterField(&ID1,&aID1,mtInt);
//    RegisterField(&IDL,&aIDL,mtInt);
    RegisterField(&Needed,&aNeeded,mtBool);
    RegisterField(&EL0,&aEL0,mtMyObject);
    RegisterField(&EL1,&aEL1,mtMyObject);
    RegisterField(&ML,&aML,mtMyObject);
    ChildType = cNone;
//    ID1 = -1;
//    ID0 = -1;
//    IDL = -1;
    ImageIndex=iiDynamicLink;
    //потом будет ландшафт и каждый элемент имеет с ним связку по умолчанию
}

/*void TDynamicLink::LookingTo(TMyObject *Target,TMTList<TMyObject>& OBJL) const
{
    //do not use directly
    if ( Target->Is(TMyRegObject::StaticType) )
    {
        if (((TMyRegObject*)Target)->Table == 0)
        {
            if ( ID0 == ((TMyRegObject*)Target)->ID)
                OBJL.Add( (TMyObject*) this);
            else if ( ID1 == ((TMyRegObject*)Target)->ID)
                OBJL.Add((TMyObject*)this);
            else if ( IDL == ((TMyRegObject*)Target)->ID)
                OBJL.Add((TMyObject*)this);
        }
    }
}
 */
void TDynamicLink::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIDynamicLinkEdit(Owner,this);
    #endif
}

bool TDynamicLink::CheckFields()
{
    if (!TMetaNode::CheckFields())
        return false;
    Parent = EL1.ADR;
/*    FEl0 = NULL;
    FLink = NULL;
    bool Ret = true;
    FEl0 = ((TMetaElement *)MGT->FindByID(0,ID0));
    if (FEl0==NULL)
        Ret = false;
//    else
//        El0 ->AddELLink(this);
    Parent = ((TMetaElement *)MGT->FindByID(0,ID1));
    if (El1==NULL)
        Ret = false;
    FLink = ((TMetaLink *)MGT->FindByID(0,IDL));
    if (Link==NULL)
        Ret = false;
    if (El0 == El1 && Needed)
        Ret=false;
    EL0.ADR = El0;
    EL1.ADR = El1;
    ML.ADR = Link;

    if (!Ret)
    {
        Application->MessageBoxA("Incorrect link will be deleted","Warning",MB_OK);
        delete this;
    }
    return Ret;  */
    bool Ret = EL0.ADR && EL1.ADR && ML.ADR;
    if (!Ret)
    {
        Application->MessageBoxA("Incorrect link will be deleted","Warning",MB_OK);
        delete this;
    }
    return Ret;  
}

TMetaElement *TDynamicLink::GetEl0()
{
    return EL0.ADR;
}

TMetaLink *TDynamicLink::GetLink()
{
    return ML.ADR;
}


int TDynamicLink::Exists(TMetaElement *MetaElement,int i)
{
    if (El0 == El1&&El0 == MetaElement)
    {
        return(true);
    }
    int RealIndex = -1;
    RealIndex  = (MetaElement == El0) ? 0 : RealIndex;
    RealIndex  = (MetaElement == El1) ? 1 : RealIndex;
    return (RealIndex == i);
}

bool TDynamicLink::NeededFor(TMetaElement *MEL)
{
    return(MEL==El1&&Needed);
}

TDynamicLink::~TDynamicLink()
{
//    if (El0)
//        El0->RemoveELLink(this);
}


