//---------------------------------------------------------------------------

#ifndef RenderParamVH
#define RenderParamVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
#include "Poligon.h"

class COMMONAL_API TRenderParam: public TMyObject{
private:
	TMDelTList< TPointer<TMetaTexture> > TEXs;
	TMDelTList< TPointer<TMetaMaterial> > MATs;
	

	bool FEnabled;
    bool FOverPosMode;
    bool FOverSizeMode;
    bool FFLAT2D;
    void SetEnabled(bool Value);
    void SetOverPosMode(bool Value);
    void SetOverSizeMode(bool Value);
    void SetFLAT2D(bool Value);
public:
	TVisTexture* GetTexture();
	TVisMaterial* GetMaterial();
	TVisTexture* GetTexture(int i);
	TVisMaterial* GetMaterial(int i);
	void AssignMode(TMyModeSettings* _MMS);

	TMetaMaterial* GetMetaMat();
	TMetaMaterial* GetMetaMat(int);
	TMetaTexture* GetMetaTex();
	TMetaTexture* GetMetaTex(int);

	void SetMetaTex(TMetaTexture* MT);
    void SetMetaMat(TMetaMaterial* MM);
	void SetMetaTex(TMetaTexture* MT, int);
	void SetMetaMat(TMetaMaterial* MM, int);

	//----------------------------------
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	//----------------------------------
	TPointer<TMetaMyMode> MODE;
	int Tag;
	TRenderParam();
	virtual ~TRenderParam(){};
	MBTi Area;
/*    TFieldAboutToChange NeedTexMat;
	TFieldAboutToChange NeedConstruct;
	TFieldAboutToChange NeedPositionAngle;*/

	__property TMetaTexture* Texture = {read = GetMetaTex,write = SetMetaTex};
    __property TMetaMaterial* Material = {read = GetMetaMat,write = SetMetaMat};
	__property TVisTexture* UseTexture = {read = GetTexture};
	__property TVisMaterial* UseMaterial = {read = GetMaterial};

//	__property TMetaTexture* Textures[int i] = {read = GetMetaTex,write = SetMetaTex};
//	__property TMetaMaterial* Materials[int i] = {read = GetMetaMat,write = SetMetaMat};
//	__property TVisTexture* UseTextures[int i] = {read = GetTexture};
//	__property TVisMaterial* UseMaterials[int i] = {read = GetMaterial};

	TIntVec TexCenter;
    TIntVec TexAngle;
    TIntVec OverPos;
    TIntVec OverSize;
    __property bool Enabled = {read = FEnabled,write = SetEnabled};
    __property bool OverPosMode = {read = FOverPosMode,write = SetOverPosMode};
    __property bool OverSizeMode = {read = FOverSizeMode,write = SetOverSizeMode};
    __property bool FLAT2D = {read = FFLAT2D,write = SetFLAT2D};
};
extern COMMONAL_API TClassNode* TRenderParam::StaticType;

//первый полигон всегда общий контур
//остальные в качестве отделки
class COMMONAL_API TFragmentSettings: public TMyObject{
    int GetPolygonCount();
//    TIntVec GetLocalP0();
//    TIntVec GetLocalP1();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TFragmentSettings();
    virtual ~TFragmentSettings(){};
    /*TMDelLSTList*/TMDelTList<TRenderParam> Parameteres;
    /*TMDelLSTList*/TMDelTList<THoledPolygon> Polygons;
//    __property TIntVec LocalP0 = {read = GetLocalP0};
//    __property TIntVec LocalP1 = {read = GetLocalP0};
    TIntVec LocalP0;
    TIntVec LocalP1;
    bool IsOutSide;
    int SideType;
    int SideIndex;
    bool ISWALLEND;
    bool ISWALLSTART;
    int FragmentOfPoint(const TIntVec& LocPoint,MBTi USEEPS);
    __property int PolygonCount = {read = GetPolygonCount};
    TRenderParam* GetRenderParam(int i);
    THoledPolygon* GetPolygon(int i);
    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TFragmentSettings::StaticType;

#endif
