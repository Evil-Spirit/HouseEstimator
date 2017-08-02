//---------------------------------------------------------------------------
#ifndef MetaClassesH
#define MetaClassesH               
#include "VisMat.hpp"
#include "VisTex.hpp"
#include "VisGL.hpp"
#include <ComCtrls.hpp>
#include <typeinfo.h>
#include "TriggerBlockV.h"
#include "VisPrimitiveObj.hpp"

///типы классов для конструктора по строке
 const AnsiString cNone = AnsiString();
 const System::AnsiString cMetaNode = AnsiString("TMetaNode");
 const AnsiString cMetaLink = AnsiString("TMetaLink");
 const AnsiString cDynamicLink = AnsiString("TDynamicLink");
 const AnsiString cMetaElement = AnsiString("TMetaElement");
 const AnsiString cMetaPlatform = AnsiString("TMetaPlatform");
 const AnsiString cCustomMetaElement = AnsiString("TCustomMetaElement");
 const AnsiString cMetaCube = AnsiString("TMetaCube");
 const AnsiString cMetaLabel3D = AnsiString("TMetaLabel3D");
 const AnsiString cMetaRoom = AnsiString("TMetaRoom");
 const AnsiString cMetaCatalogUnit = AnsiString("TMetaCatalogUnit");
 const AnsiString cMetaMultiElement = AnsiString("TMetaMultiElement");
 const AnsiString cMetaMyMode = AnsiString("TMetaMyMode");

 const AnsiString cMetaActionList = AnsiString("TMetaActionList");
 const AnsiString cMetaAction = AnsiString("TMetaAction");
 const AnsiString cMetaUI = AnsiString("TMetaUI");
 const AnsiString cMetaMenuItem = AnsiString("TMetaMenuItem");

 const AnsiString cUnit = AnsiString("TUnit");
 const AnsiString cLink = AnsiString("TLink");
 const AnsiString cElement = AnsiString("TElement");
 const AnsiString cCustomElement = AnsiString("TCustomElement");
 const AnsiString cCube = AnsiString("TCube");
 const AnsiString cPlatform = AnsiString("TPlatform");
 const AnsiString cLabel3D = AnsiString("TLabel3D");
 const AnsiString cRoom = AnsiString("TRoom");
 const AnsiString cCatalogUnit = AnsiString("TCatalogUnit");
 const AnsiString cMultiElement = AnsiString("TMultiElement");

 const AnsiString cNomenclature = AnsiString("TNomenclature");
 const AnsiString cBMPSet = AnsiString("TBMPSet");
 const AnsiString cMetaMaterial = AnsiString("TMetaMaterial");
 const AnsiString cMetaTexture = AnsiString("TMetaTexture");
 const AnsiString cMetaVisParam = AnsiString("TMetaVisParam");


 const int iiConfig = 0;
 const int iiElements = 1;
 const int iiLinks = 2;
 const int iiMetaCube = 3;
 const int iiMetaLink = 4;
 const int iiDynamicLink = 5;
 const int iiCustomMetaElement = 6;
 const int iiMetaPlatform = 7;
 const int iiMetaRoom = 8;
 const int iiMetaLabel3D = 9;
 const int iiMetaCatalogUnit = 29;
 const int iiMetaMultiElement = 12;
 const int iiNomenclature = 13;
 const int iiGroup = 14;
 const int iiBMPSet = 15;
 const int iiBMPSets = 16;
 const int iiMaterials = 17;
 const int iiMaterial = 18;
 const int iiTextures = 19;
 const int iiTexture = 20;
 const int iiLuaModule = 21;
 const int iiMetaMyModes = 22;
 const int iiMetaMyMode = 23;
 const int iiMetaUI = 24;
 const int iiMetaActionList = 25;
 const int iiMetaAction = 26;
 const int iiMetaMenuItem = 27;
 const int iiMetaLUA = 28;
 const int iiMetaVisParam = 30;

const int uiMouseIndex = 1;
const int uiDefaultIndex = 0;

class TMetaNode;
COMMONAL_API TMetaNode* CreateMetaObject(const AnsiString& ClassName);
COMMONAL_API TMetaNode* CreateMetaObject(TClassNode* ClassNode);

class COMMONAL_API THasStep :public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
	TMyObject* CreateFunction();
	//----------------------------------
    THasStep();
    virtual ~THasStep(){};
    TIntVec BaseStep;
    TIntVec DefMulti;
    bool Hard;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual bool CheckFields();
};
extern COMMONAL_API TClassNode* THasStep::StaticType;

class COMMONAL_API THasAngle :public TMyObject {
private:
    TIntVec FLow;
    TIntVec FHi;
    void SetLow(const TIntVec & newLow);
    void SetHi(const TIntVec & newHi);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    THasAngle();
    virtual ~THasAngle(){};
    __property TIntVec LOW = {read = FLow, write = SetLow };
    __property TIntVec HI = {read = FHi, write = SetHi };
    TBoolVec Mirrored;
    virtual bool CheckFields();
    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);    
    bool Valid(const TIntVec& Angle);    
};
extern COMMONAL_API TClassNode* THasAngle::StaticType;

class COMMONAL_API THasSize : public TMyObject {
private:
    TIntVec FLow;
    TIntVec FDefault;
    TIntVec FHi;
    void SetLow(const TIntVec & newLow);
    void SetHi(const TIntVec & newHi);
    void SetDefault(const TIntVec & newDefault);
public:
	//----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    THasSize();
    virtual ~THasSize(){};
    __property TIntVec LOW = {read = FLow, write = SetLow };
    __property TIntVec HI = {read = FHi, write = SetHi };
    __property TIntVec DEFAULT = {read = FDefault, write = SetDefault};
    THasStep STEP;
    virtual bool CheckFields();
    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    bool Valid(const TIntVec& Size);
    void Validate(TIntVec& Size);
};
extern COMMONAL_API TClassNode* THasSize::StaticType;


//LinkChangeMode
const int lcmAuto=0;
const int lcmFreeze=1;
const int lcmMinus=2;
const int lcmZero=3;
const int lcmPlus=4;
const AnsiString LinkChangeModeStr[5]={AnsiString("Keep Auto"),AnsiString("Freeze"),AnsiString("Keep To Minus"),AnsiString("Keep To Zero"),AnsiString("Keep To Plus")};

class COMMONAL_API TMetaEps : public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
	TMyObject* CreateFunction();
    //----------------------------------
    TMetaEps();
    virtual ~TMetaEps(){};
    TIntVec POSEPS;
    TIntVec ANGLEEPS;
    TIntVec SIZEEPS;
    virtual bool CheckFields();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);

};
extern COMMONAL_API TClassNode* TMetaEps::StaticType;

const mltAreaPoint=0;
const mltPointPoint=1;
const mltLineLine=2;
const mltWallWall=3;
//---------------------------------------
class TElement;

//---------------------------------------------------------------------
class TBMPPointer;
class COMMONAL_API TMetaNode : public TMyRegObject{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
	bool ReadOnly;
	bool IsNew;
    void SetName(const AnsiString &newName);
    TMetaNode(TMetaNode *Parent, int _ID, const AnsiString& _Name);
    TMetaNode();
    virtual ~TMetaNode();
    AnsiString ChildType;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    TTriggerBlock *TB;
    virtual bool UsedTrigger(int Trigger);
    bool CheckFields();
    TBMPPointer* Img1;
    TBMPPointer* SmallImg;
    virtual void GetImage(bool Small,bool Masked,Graphics::TBitmap* bmp,Graphics::TBitmap* mask);
    TMetaNode& operator = (TMetaNode& MN);
};
extern COMMONAL_API TClassNode* TMetaNode::StaticType;

//---------------------------TMetaLink-------------------------
//TransformationMode
const tmPosition = 0;
const tmSize = 1;
const tmPositionSize = 2;

class TLINKPATTERN;

class COMMONAL_API TLinkInfo {
public:
    TLinkInfo(){};
    virtual ~TLinkInfo(){};
    TElement* Target;
    TElement* Source;
    T3DScope* TargetScope;
    T3DScope* SourceScope;
    TLINKPATTERN* LINKPATTERN;
    bool SizeTransform;
    bool OK;
};
class COMMONAL_API TMetaLink : public TMetaNode {
protected:
    TLuaModule* SCOPE0;
    TLuaModule* SCOPE1;
    TLuaModule* LinkModule;
    bool SCOPE0TargetDepend;
    bool SCOPE1TargetDepend;
    bool SCOPE0SourceDepend;
    bool SCOPE1SourceDepend;
    TLinkInfo LinkInfo;
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaLink(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    TMetaLink();
    virtual ~TMetaLink(){};
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    TIntVec LCM;
    int MetaLinkType;
    int HoleCreated;
    bool Client;
    int ClientNormal0;
    int ClientNormal1;
    TMetaEps EPS;
    int Priority;
    //-----------------------
    bool InWeb;
    bool CheckFields();
    //-----------------------
    THasStep STEP;
    THasAngle Angle;
    bool HasLinkModule;
    void TargetScope(TElement* Target,TElement* Source,T3DScope& Scope);
    void SourceScope(TElement* Target,TElement* Source,T3DScope& Scope);
    void SourcePoint(TElement* Target,TElement* Source,TIntVec& Vector);
    void UpdateMetaLinkTargetWithNewSource(TElement* Target);
    virtual bool UsedTrigger(int Trigger);
    bool WallLink;
    bool RunOnStop;
    int TransMode;
//    bool RouterLink;
    bool RunLinkModule(TElement* Target,TElement* Source,TLINKPATTERN& SL,bool TransFormSize);
};
extern COMMONAL_API TClassNode* TMetaLink::StaticType;

//---------------------------HaveMaterial-------------------------
class COMMONAL_API TMyColor :public TMyObject {
protected:
    int FColor;
    double FAlpha;
    void SetColor(const TColor& _Color);
    TColor GetColor() const;
    void SetAlpha(const GLfloat& _Alpha);
    GLfloat GetAlpha() const;
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    __property TColor Color = {read = GetColor,write = SetColor};
    __property GLfloat Alpha = {read = GetAlpha,write = SetAlpha};
    TMyColor();
    virtual ~TMyColor(){};
};
extern COMMONAL_API TClassNode* TMyColor::StaticType;

class COMMONAL_API TMetaMaterial : public TMetaNode {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMyColor Ambient;
    TMyColor Diffuse;
    TMyColor Emission;
    TMyColor Specular;
    int Shininess;
    bool Transparency;
    TMetaMaterial(TMetaNode *Parent, int _ID, const AnsiString& _Name);
    TMetaMaterial();
    virtual ~TMetaMaterial();
    TVisMaterial *VM;
    bool CheckFields();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    int Face;
};

extern COMMONAL_API TClassNode* TMetaMaterial::StaticType;

const int camPerspective=1;
const int camOrthographic=0;

class COMMONAL_API TMetaMyMode :public TMetaNode{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    int CAM;
    TMetaMyMode(TMetaNode *Parent, int _ID, const AnsiString& _Name);
    TMetaMyMode();
    virtual ~TMetaMyMode(){};
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

extern COMMONAL_API TClassNode* TMetaMyMode::StaticType;

class COMMONAL_API TBMPSet : public TMetaNode{
protected:
    virtual void SetName(const AnsiString &newName);
    int FX;
    int FY;
    TImageList* FIL;
    TImageList* GetIL();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    __property TImageList* IL = {read = GetIL};
    virtual void SaveData(FILE *F) const;
    virtual void WriteData(TMemoryStream *MS) const;
    TRect R;
    TBMPSet();
    TBMPSet(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TBMPSet();
    int X();
    int Y();
    void SetXY(int _X,int _Y);
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual void Assign(TMyObject* Obj);
};

extern COMMONAL_API TClassNode* TBMPSet::StaticType;

//StandartImages
const int siSOPOS = 0;
const int siFOLDER = 1;

class COMMONAL_API TBMPPointer :public TMyObject{
protected:
    int FIndex;
    void SetIndex(int _Index);
    int GetIndex() const;
    TImageList *GetIL() const;
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TPointer<TBMPSet> BMPSet;
    __property int Index = {read = GetIndex,write = SetIndex};
    __property int RealIndex = {read = FIndex};
    bool GetBitmap(Graphics::TBitmap * BMP);
    void GetStandartBitmap(int index,Graphics::TBitmap * BMP);
    bool Valid();
    __property TImageList *ImgList = {read = GetIL};
    TBMPPointer();
    virtual ~TBMPPointer(){};
    void Select();
    void Assign(TMyObject* MO);
};

extern COMMONAL_API TClassNode* TBMPPointer::StaticType;

class COMMONAL_API TMyTextureFlags :  public TMyObject {
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMyTextureFlags();
    virtual ~TMyTextureFlags(){};
    int Mode;
    TIntVec Param;
    TIntVec Scale;
    TIntVec Shift;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

extern COMMONAL_API TClassNode* TMyTextureFlags::StaticType;

     //TMyTextureFlagsObject
//TTextureMode
const int tmCeil = 0;
const int tmFloor = 1;
const int tmOutWall = 2;
const int tmInWall = 3;

const AnsiString TextureModeStr[] = {
                                        AnsiString("Ceiling"),
                                        AnsiString("Floor"),
                                        AnsiString("External wall"),
                                        AnsiString("Internal wall")
                                    };

class COMMONAL_API TMyTextureModes :  public TMyObject {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMyTextureModes();
    virtual ~TMyTextureModes(){};
    int Mode;
    MBTi ZMin;
    MBTi ZMax;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

extern COMMONAL_API TClassNode* TMyTextureModes::StaticType;

class COMMONAL_API TMyTextureModesList : public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
  TMyTextureModesList();
  virtual ~TMyTextureModesList(){};
//  /*TMDelLSTList*/TMDelTList<TMyTextureModes> TEXMODES;
  TMDelTList<TMyTextureModes> TEXMODES;
  virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMyTextureModesList::StaticType;

class COMMONAL_API TMetaTexture : public TMetaNode {
protected:
    double FAlpha;
    void SetAlpha(const GLfloat& _Alpha);
    GLfloat GetAlpha() const;
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    __property GLfloat Alpha = {read = GetAlpha,write = SetAlpha};
    int Mode;
    TMyColor Blend;
    TBMPPointer BMP;
    TMetaTexture(TMetaNode *Parent, int _ID, const AnsiString& _Name);
    TMetaTexture();
    virtual ~TMetaTexture();
    TVisTexture *VT;
    TIntVec Rotate;
    TIntVec Scale;
    TIntVec Translation;
    bool CheckFields();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    int MinFilter;
    int MagFilter;
    TPointer<TBMPSet> MipMaps;
    MBTi RealSizeX;
    MBTi RealSizeY;
};
extern COMMONAL_API TClassNode* TMetaTexture::StaticType;

void COMMONAL_API ApplyMipMaps(TVisTexture *VT,const TPointer<TBMPSet> &MipMaps);

class COMMONAL_API TMetaVisParam :  public TMetaNode {
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaVisParam();
    TMetaVisParam(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TMetaVisParam(){};
    TPointer<TMetaTexture> TEX;
    TPointer<TMetaMaterial> MAT;
    TMyTextureModesList TML;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMetaVisParam::StaticType;

const int omNone=0;
const int omAdd=1;
const int omReplace=2;

class COMMONAL_API TMyModeSettings :public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
  TMyModeSettings();
  virtual ~TMyModeSettings(){};
  TPointer<TMetaMyMode> Meta_Mode;
  TMDelTList< TPointer<TMetaMaterial> > MATs;
  TMDelTList< TPointer<TMetaTexture> > TEXs;

  int OverSizeMode;
  int OverPosMode;
  TIntVec OverSize;
  TIntVec OverPos;
  bool Render;
  bool FLAT_2D;
  virtual void Edit(TComponent *_Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMyModeSettings::StaticType;

class COMMONAL_API TMyModeSettingList : public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
  TMyModeSettingList();
  virtual ~TMyModeSettingList();
  /*TMDelLSTList*/TMDelTList<TMyModeSettings> *Mode_Set_List;
  TPointer<TMetaMyMode> DefaultMode;
  TMyModeSettings* FindByMode(TMetaMyMode * MMM);
  virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMyModeSettingList::StaticType;





//class TDynamicLinkList;
class TDynamicLink;
class TMainTree;
class TMetaTool;
class COMMONAL_API TMyActionSettings: public TMyObject{
private:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMDelTList< TPointer<TMetaTool> >& Tools;
    TMDelTList< TPointer<TMetaTool> >& CreateTools;
    TMyActionSettings();
    virtual ~TMyActionSettings();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMyActionSettings::StaticType;


extern  COMMONAL_API bool TechnologyCheckPass;
extern  COMMONAL_API char* TechnologyCheckStr;

class TElement;
class COMMONAL_API TCanExistCheck :public TMyObject{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TCanExistCheck();
    virtual ~TCanExistCheck();
    /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList< TPointer<TDynamicLink> > > *LinkGroups;
    bool TechCheck(TElement *El,AnsiString& Str);
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TCanExistCheck::StaticType;

class TFloor;
class COMMONAL_API TMetaElement : public TMetaNode{
protected:
    TVisMaterial *GetMaterial();
    int GetDynLinkCount();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TPointer<TMetaMaterial> MAT;
    TPointer<TMetaTexture> TEX;
    TMyTextureFlags MTF;
    __property TVisMaterial* VM = {read =GetMaterial};
    TMetaElement(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaElement();
    virtual ~TMetaElement();
    THasSize Size;
    TMetaEps EPS;
    bool IsSupport;
    bool IsWall;
    MBTi StartZED;
    virtual void Fix_Changes(TMetaElement *MEL,TElement* UseFloorElement){};
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    bool IsAuto;
    TDynamicLink* SearchNeededLinkFor(TMetaElement * Target);
    TDynamicLink* GetDynLink(int index);
    __property int DynLinkCount = {read = GetDynLinkCount};
    int FILEBMP;
    TMyActionSettings MAS;
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    TMyModeSettingList MMSL;
    bool DrawView;
    //---------------------------------------------------------------------------
    bool InWeb;
    virtual bool UsedTrigger(int Trigger);
    TCanExistCheck CanExistCheck;
    bool TechCheck(TElement *El,AnsiString& Str);
//    TVisMaterial *GetVisMaterial(TMetaMyMode* Mode);
    /*TMDelLSTList*/TMDelTList< TPointer<TMetaElement> > DEPENDLST;
    bool ShowButton;
    bool IsLight;
    TMetaElement& operator = (TMetaElement& ME);
};
extern COMMONAL_API TClassNode* TMetaElement::StaticType;

class COMMONAL_API TDynamicLink : public TMetaNode{
private:
//    TMetaElement *FEl0;
//    TMetaLink *FLink;
    TMetaElement *GetParent(){return(TMetaElement *)Parent;}
    TMetaElement *GetEl0();
    TMetaLink *GetLink();
protected:
//    virtual void LookingTo(TMyObject* Target,TMTList<TMyObject>& OBJL) const;
public:
    TPointer<TMetaElement> EL0;
    TPointer<TMetaElement> EL1;
    TPointer<TMetaLink> ML;
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TDynamicLink(TMetaElement *_Parent,int _ID,const AnsiString& _Name);
    TDynamicLink();
    virtual ~TDynamicLink();
    bool Needed;
    bool NeededFor(TMetaElement *MEL);
//    int ID0;
//    int ID1;
//    int IDL;
    int Exists(TMetaElement *mel,int i=-1);
    __property TMetaElement *El1 = { read = GetParent };
    __property TMetaElement *El0 = { read = GetEl0 };
    __property TMetaLink *Link = {read = GetLink};
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual bool CheckFields();
    virtual bool UsedTrigger(int Trigger);
};
extern COMMONAL_API TClassNode* TDynamicLink::StaticType;


extern COMMONAL_API TImageList *ILDefault;
extern COMMONAL_API TVisMaterial *MaterialDefault;
extern COMMONAL_API Graphics::TBitmap *BMPDef;

extern COMMONAL_API TLinkInfo* curLinkInfo;

void COMMONAL_API SetDefaults();


//---------------------------------------------------------------------------
#endif

