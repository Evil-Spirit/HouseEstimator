//---------------------------------------------------------------------------

#ifndef ElementVH
#define ElementVH
#include "RenderParamV.h"
#include "UNDO.h"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void COMMONAL_API CreateNetLine(TVisPrimitiveObj* Net, const TIntVec& MySize, const TIntVec& Step);
void COMMONAL_API CreateNetPoint(TVisPrimitiveObj* Net, const TIntVec& MySize, const TIntVec& Step);

class TMainTree;
class TElement;
class TUnit;
class TDrawView;
class TSide;
class TLink;

COMMONAL_API TElement *CreateElementFunction(TMainTree *_Tree,TMetaNode* MetaNode);
COMMONAL_API TElement *CreateElementFunction(TMainTree *_Tree,int _METAID);
COMMONAL_API TElement *CreateElementFunctionNotReg(TMainTree *_Tree,TMetaNode* MetaNode);
COMMONAL_API TLink* CreateLink(TDynamicLink *DL,TElement *Target,TElement *Source,const TIntVec &AbsCrossPoint);
COMMONAL_API TLink* CreateLinkFunction(TElement* EL0,TElement* EL1,TDynamicLink* DynamicLink,const TIntVec& AbsPoint);
//void COMMONAL_API DeleteElement(TElement* El,bool UpdatePremises,TElement* Floor);
void COMMONAL_API KillElement(TElement* El);

AnsiString COMMONAL_API CutMeta(const AnsiString& _MetaName);

const AnsiString NoName = AnsiString("<Без имени>");

//---------------------------------------
class COMMONAL_API TUnit : public TMyRegObject{
protected:
    TMyRegObject* FMetaObject;
    AnsiString FMETAGUID;
public:
    bool UndoRegistered;
    void UndoRegister(TRegisterMode RM);
    virtual void SetMetaObject(TMyRegObject* aMetaObject);
    void SetMETAGUID(const AnsiString& aMETAGUID);
    __property AnsiString METAGUID = {read = FMETAGUID,write = SetMETAGUID};
    __property TMyRegObject* MetaObject = {read = FMetaObject,write = SetMetaObject};
    static TClassNode* StaticType;
    TUnit();
    virtual ~TUnit(){};
    bool CheckFields();
    TMyObject* CreateFunction();
    void SynchronizeAttributes();
};

extern COMMONAL_API TClassNode* TUnit::StaticType;

class COMMONAL_API T3DScopeMem{
public:
    T3DScopeMem(){};
    virtual ~T3DScopeMem(){};
    T3DScope Scope;
    void* FObject;
    bool Inited;
};

class COMMONAL_API T3DScopeCache {
private:
    TMDelTList<T3DScopeMem> SCM;
public:
    T3DScopeMem *Find(void *Object);
    T3DScopeCache(){};
    virtual ~T3DScopeCache(){};
    void SetFalse();
    void SetTrue(void *Object);
};

class TLink;
class TLabel3D;

class COMMONAL_API THoleClient: public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    THoleClient(TPolygon* Hole,TElement* El);
    THoleClient();
    virtual ~THoleClient();
    TPolygon* Hole;
    TPointer<TElement> Client;
};

extern COMMONAL_API TClassNode* THoleClient::StaticType;

class TElementPoints;



const int efCustomEnabled = 0;
const int efCurrentEnabled = 2;

class COMMONAL_API TElement : public TUnit{
protected:
    static __int64 TotalCount;
    virtual void SetMetaObject(TMyRegObject* aMetaObject);
    TMetaElement* GetMetaElement(){return (TMetaElement*)FMetaObject;};
//-----------------------------------------------------------
    bool NeedCreateView;
    bool NeedUpdatePos;
    bool NeedTexturing;
//-----------------------------------------------------------
    TMainTree *GetMainTree(){return (TMainTree*)FMyTree;}
    void SetMainTree(TMainTree* MT){SetMyTree((TMyRegTree*)MT);}
    virtual void SetParent(TMyRegObject *_Parent);
//-------------------------------------------------------
    bool FEnabled[2];
    bool GetEnabled(int type);
    bool GetModeEnabled();
    bool GetTotalEnabled();
    virtual void SetEnabled(int type,bool Value);
//-------------------------------------------------------
    int GetFragmentCount();
    int GetRenderParamCount();
    int GetSideCount();
//-------------------------------------------------------
    bool FAdvancedTextureView;
    bool FAdvancedTextured;
    void SetAdvancedTextureView(bool Value);
    bool GetTotalAllowAdvancedTexture();
public:
    __int64 IntId;
//-------------------------------------------------------
    TElement();
    virtual ~TElement();
//-------------------------------------------------------
    bool UndoRegistered;
//--------------------------------------------
    void AboutToChange(void* Sender);
    void Changed(void* Sender);
//-----------Register Routine-----------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    virtual void KillFunction();
//-----------Translation Rotation Scaling Projection Routine-----------------
    TChangeVec AbsSize;
    TChangeVec AbsAngle;
    TChangeVec AbsPos;
    TChangeVec SlopeMinus;
    TChangeVec SlopePlus;
    TChangeVec SlopeMinusParam;
    TChangeVec SlopePlusParam;

    void ForceCreateView();
    virtual void SetSize(const TIntVec& _Size);
    void SetSlope(const TIntVec& _SlopeMinus,const TIntVec& _SlopePlus,bool Render=true);
    void SetPos(const TIntVec& newPos);
    void SetAngle(const TIntVec& newAngle);
    virtual void ChangeSize(const TIntVec& ChangeVector,const TIntVec& ChangeDirection,bool Try=false);
    virtual void UpgradeChildsPosition();
    virtual void UserChangePosition(const TIntVec& Move,const TIntVec& Rotate);
    void AbsFromLocal(const TIntVec& Vector,TIntVec& Result);
    void LocalFromAbs(const TIntVec& Vector,TIntVec& Result);
    void ConstructByNPoints(TMDelTList<TIntVec>* Points);
    void ConstructBy2Points(TMDelTList<TIntVec>* Points);
//-------Hole Management Routine-------------------------------------
    TMDelTList<THoleClient> LinkHoles;
    TPointer<TElement> HoleElement;
    virtual void HoleInMeFor(TElement* El, TPolygon* Hole){};
    void SetMyHoleFor(TElement *El);
    void DelMyHole();
    void AddHole(TPolygon* Hole,TElement* Client);
    int FindHoleFor(TElement* Element);
    void DeleteHole(int i);
//----------Link Management Routine-------------------------------------------------
    int GetNeededLink();
    TMTList<TLink> FLinks;//список связок (условно первая обязательная)
    int GetLinksCount(){return(FLinks.Count);};
    TLink * GetLink(int i){return(FLinks.Items[i]);}
    __property int LinksCount = {read = GetLinksCount};
    int IOF(TLink *Lnk);
    void DeleteNeededLink();
    __property int NeededLink = {read = GetNeededLink};
    void DeleteAllLinks();
    void DeleteAllLinksOnly();
    void AddLink(TLink *Link);
    void KillLink(void *Sender,int i);
        //for lua------------
    TElement *GetChild(int i);
    int GetChildCount();
    TLink *GetLinkOf(TElement *El);
    bool LinkPosition(TElement * ElOther,TIntVec& Position);
        //--------------------
//----------------- ViewCreation Routine---------------------------
    virtual void StandartCreateView(){};
    void RegisterCreateView(TMyObject* Obj=NULL);
    void UnRegisterCreateView(TMyObject* Obj=NULL);
	void RegisterUpdatePos(TMyObject* Obj=NULL);
    void RegisterTexturing(TMyObject* Obj=NULL);
    virtual void ProcessCreateView();
    virtual void ProcessUpdatePos();
    virtual void ProcessTexturing();
    void ProcessTasks(void* ModeValue);
    void TexturePrimitive(TVisPrimitiveObj* Obj,int Index,TRenderParam& RP);
    void TextureObject(TVisPrimitiveObj* Obj,TRenderParam& RP);
    virtual void TexturePrimitive(TVisPrimitiveObj* Obj,TVisPrimitiveArray* Array,TRenderParam& RP, int Index = 0);
    __property bool AdvancedTextureView = {read = FAdvancedTextureView, write = SetAdvancedTextureView};
    __property bool TotalAllowAdvancedTexture = {read = GetTotalAllowAdvancedTexture};
//-----------Enabled Routine------------------------------------------------
    __property bool CustomEnabled = {read = GetEnabled,write = SetEnabled,index = 0};
    __property bool CurrentEnabled = {read = GetEnabled,write = SetEnabled,index = 1};
    __property bool ModeEnabled = {read = GetModeEnabled};
    __property bool TotalEnabled = {read = GetTotalEnabled};
//------------Working with Render and Tree-----------------------------------------------
    __property TMainTree *MyTree = {read = GetMainTree,write = SetMainTree};
    virtual void Render(TVisCustomView *aView);
    void RemoveRenderFromTree();
    virtual TVisRender *MyRender(){return(NULL);};
    TElement* GetCurrentFloorElement();
//----------------Label and Size Routine----------------------------
    TLabel3D *CreateLabel(bool Rotateble,const TIntVec& Pos = ZEROINTVEC);
    void KillLabel();
    TElement* Create_SIZER(int ID,const TIntVec& P1,const TIntVec& P2);
    void Kill_SIZER(int ID);
//-----------Polygon ---------------
    virtual void GetEdges(TMDelTList<TPolygon> *pList);
    THoledPolygon *HP;
    void ClearPoints();
    void AddArrPoint(const TIntVec &_Point);
    void LocalizePolygon();
    void ValidateConstruction(MBTi USEEPS);
//--------------Mode Management Routine-----------------------------------------------------------
    TMDelTList<TRenderParam> RenPars;
    __property int RenderParamCount = {read = GetRenderParamCount};
    TRenderParam* GetRenderParam(int i);
    void SetMode();
    //-----------OverLoaded from TMyObject--------------------------
    virtual bool CheckFields();
    virtual bool Init();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
//-----------Architecture Routine--------------------------
    TElementPoints* ElementPoints;
    __property int SideCount = {read = GetSideCount};
    TSide* GetSide(int i);
    TMDelTList<TFragmentSettings> FragSet;
    __property int FragmentsCount = {read = GetFragmentCount};
    TFragmentSettings* GetFragment(int i);
    void SynchronizeRenderParams();
    //------------------SizeCache------------------
    T3DScopeCache SIZECACHE;
    //-------------Unsorted-------------------------------
    __property TMetaElement *MyMeta = {read = GetMetaElement};
    bool RunElementTrigger(int Trigger);
    virtual void LOW_HI(TIntVec& LOW,TIntVec& HI);
    bool DependOf(TElement* El);
    void UpdateDependenceElements();
    virtual void ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID){};
    bool EditStatus(int &Operation,int &Type);
    bool TechCheck(AnsiString& Str);
            //not used function
    virtual void CreateClient(TElement* Target);
    //-------------------------------------

    //перекрыть
    //-------------------------------------
    bool Counted;
    bool DoNotDelete;
    int  SideRender;
    bool DestroyStarted;
    bool CanDriver;
    bool ATVChanged;
    TElement& operator =(TElement& MO);
};

extern COMMONAL_API TClassNode* TElement::StaticType;
extern COMMONAL_API __int64     TElement::TotalCount;


class COMMONAL_API TLink : public TUnit {
private:
    //---------------------------------------------------------------------------
    bool Visual;
    TMDelTList< TPointer<TElement> > ELS;
    void SetElement(int index,TElement* El);
    //---------------------------------------------------------------------------
    TDynamicLink* GetDynamicLink(){return (TDynamicLink*)FMetaObject;};
    __property TElement* El0 = {read = GetElement,write = SetElement,index = 0};
    __property TElement* El1 = {read = GetElement,write = SetElement,index = 1};
protected:
    virtual void SetMetaObject(TMyRegObject* aMetaObject);
    TChangeVec Pos0;
    TChangeVec Pos1;
    void CheckIndex(int index);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TLink(TMetaNode *_Meta,TElement *Target,TElement *Source,const TIntVec &AbsCrossPoint);
    TLink();
    virtual ~TLink();
    //--------------------------------------------
    void AboutToChange(void* Sender);
    void Changed(void* Sender);
    //---------------------------------------------
    TChangeVec Angle;
    //-------------Access Routine-----------------
    TElement* GetElement(int index);
    __property TDynamicLink *MyMeta = {read = GetDynamicLink};
    bool Exists(TElement *El,int i=-1);
    bool Exists(TMetaElement *mel,int i=-1);
    __property TChangeVec Position0 = { read = Pos0 };
    __property TChangeVec Position1 = { read = Pos1 };
    __property TElement *Elements[int i] = {read = GetElement};
    TIntVec GetPos(int i);//for lua but not only-
    MBTi GeomAngle();
    TElement* OtherElement(TElement* Sender);
    TIntVec AbsPositionBy(TElement *El);
    //-------------Linking Routine-----------------
    void LinkElement(void * Sender, int i, TElement * El);
    void UnLinkElement(void *Sender,int i);
    bool NeededFor(TElement *El);
    //-------------Depend Routine-----------------
    bool DependElement(TElement* Sender);
    bool El0Depend;
    bool El1Depend;
    void Refresh();
    bool TargetChangeSize(bool Try,const TIntVec &RealSizeChange,const TIntVec& Direction);
    //-------------Standart-----------------
    bool CheckFields();
    bool Init();
    void RunLinkTrigger(int Trigger);
    //-------------Other-----------------
    bool Counted;
    bool Deletion;
    void ProcessVisual();
    void ProcessUnVisual();

    TLink& operator =(TLink& MO);
};
extern COMMONAL_API TClassNode* TLink::StaticType;


TLink* COMMONAL_API CreateLink(TElement* EL0,TElement* EL1,TDynamicLink* DynamicLink,const TIntVec& AbsPoint);

extern COMMONAL_API TElement *CurElement;
extern COMMONAL_API TLink *CurLink;

//typedef void (* TMyDefaultElementAction)(TElement *Element);
//typedef bool (* TMyFindElementAction)(TElement *Element);
//typedef void (* TMyFillListElementAction)(TElement *Element,TMTList<void>* List);
//typedef void (* TMyFillListByTypeElementAction)(TElement *Element,TMTList<void>* List,const std::type_info & ti);

TIntVec COMMONAL_API CalculatePlatformSize();
//void COMMONAL_API CreateSelView(TElement* El,TVisPrimitiveObj *SelObj);
void COMMONAL_API CreateSelView(TElement* El,TVisPrimitiveObj *SelObj, TVisPrimitiveObj *RT, TVisPrimitiveObj *UDT);
#endif
