// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
	static TMyObject* CreateFunction();
	//----------------------------------
	TPointer<TMetaMyMode> MODE;
	int Tag;
	TRenderParam();
	virtual ~TRenderParam(){};
	MBTi Area;
/*    TFieldAboutToChange NeedTexMat;
	TFieldAboutToChange NeedConstruct;
	TFieldAboutToChange NeedPositionAngle;*/

	// __property TMetaTexture* Texture {read=GetMetaTex, write=SetMetaTex}; // [manual migration needed]
    // __property TMetaMaterial* Material {read=GetMetaMat, write=SetMetaMat}; // [manual migration needed]
	// __property TVisTexture* UseTexture {read=GetTexture}; // [manual migration needed]
	// __property TVisMaterial* UseMaterial {read=GetMaterial}; // [manual migration needed]

// [indexed property - needs manual migration]: //	__property TMetaTexture* Textures[int i] = {read = GetMetaTex,write = SetMetaTex};
// [indexed property - needs manual migration]: //	__property TMetaMaterial* Materials[int i] = {read = GetMetaMat,write = SetMetaMat};
// [indexed property - needs manual migration]: //	__property TVisTexture* UseTextures[int i] = {read = GetTexture};
// [indexed property - needs manual migration]: //	__property TVisMaterial* UseMaterials[int i] = {read = GetMaterial};

	TIntVec TexCenter;
    TIntVec TexAngle;
    TIntVec OverPos;
    TIntVec OverSize;
    // __property bool Enabled {read=FEnabled, write=SetEnabled}; // [manual migration needed]
    // __property bool OverPosMode {read=FOverPosMode, write=SetOverPosMode}; // [manual migration needed]
    // __property bool OverSizeMode {read=FOverSizeMode, write=SetOverSizeMode}; // [manual migration needed]
    // __property bool FLAT2D {read=FFLAT2D, write=SetFLAT2D}; // [manual migration needed]
};

//ïåðâûé ïîëèãîí âñåãäà îáùèé êîíòóð
//îñòàëüíûå â êà÷åñòâå îòäåëêè
class COMMONAL_API TFragmentSettings: public TMyObject{
    int GetPolygonCount();
//    TIntVec GetLocalP0();
//    TIntVec GetLocalP1();
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    TFragmentSettings();
    virtual ~TFragmentSettings(){};
    /*TMDelLSTList*/TMDelTList<TRenderParam> Parameteres;
    /*TMDelLSTList*/TMDelTList<THoledPolygon> Polygons;
// __property TIntVec LocalP0 {read=GetLocalP0}; // [manual migration needed]
// __property TIntVec LocalP1 {read=GetLocalP0}; // [manual migration needed]
    TIntVec LocalP0;
    TIntVec LocalP1;
    bool IsOutSide;
    int SideType;
    int SideIndex;
    bool ISWALLEND;
    bool ISWALLSTART;
    int FragmentOfPoint(const TIntVec& LocPoint,MBTi USEEPS);
    // __property int PolygonCount {read=GetPolygonCount}; // [manual migration needed]
    TRenderParam* GetRenderParam(int i);
    THoledPolygon* GetPolygon(int i);
    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

#endif
