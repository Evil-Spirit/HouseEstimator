//---------------------------------------------------------------------------

#ifndef CustomElementVH
#define CustomElementVH
#include "ElementV.h"

/*#include "VisCustomObj.hpp"
#include "stdlib.h"
#include "string.h"

#include "VisCanvasView.hpp"
//#include "VisClass.hpp"
//#include "VisComp.hpp"
#include "VisView.hpp"
//#include "VisAttr.hpp"
//#include "VisLight.hpp"
#include "VisMat.hpp"
//#include "VisObj.hpp"
//#include "VisPrimitiveObj.hpp"
//#include "VisShape.hpp"
//#include "VisGeom.hpp"
#include "VisPoly.hpp"*/

class TMetaMaterial;
class TMetaTexture;
class TGeomObject;
void PrimitiveObjToGeomObj( TVisPrimitiveObj* PObj,TGeomObject* GObj );

class COMMONAL_API TCustomMetaElement : public TMetaElement{
protected:
	virtual void SetName(const AnsiString &newName);
	mutable TVisPrimitiveObj* FPrimitiveObject;
	TVisPrimitiveObj* GetVisObject();
public:
	//----------------------------------
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	//----------------------------------

    __property TVisPrimitiveObj* VisObject = {read = GetVisObject};
    TCustomMetaElement(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TCustomMetaElement();
    virtual ~TCustomMetaElement();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
	virtual void Assign(TMyObject* Obj);
    virtual void SaveData(FILE *F) const;
    virtual void WriteData(TMemoryStream *MS) const;
};
extern TClassNode* COMMONAL_API TCustomMetaElement::StaticType;


class COMMONAL_API TCustomElement : public TElement{
protected:
    TVisPrimitiveObj *OBJ;
    TCustomMetaElement *GetCustomMetaElement(){return((TCustomMetaElement*)MyMeta);};
    void SetMetaObject(TMyRegObject* aMetaObject);
public:
//    TGeomObject* FGeomObject;
    __property TVisPrimitiveObj* VisObject = {read = OBJ};
    void ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID);
//	void ProcessTexturing();
	void TexturePrimitive(TVisPrimitiveObj* Obj,TVisPrimitiveArray* Array,TRenderParam& RP, int Index = 0);
	//----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TCustomElement();
    virtual ~TCustomElement();
    __property TCustomMetaElement *CustomMetaElement = {read = GetCustomMetaElement};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(OBJ);};
    bool CheckFields();
};
extern TClassNode* COMMONAL_API TCustomElement::StaticType;

void UnpackMaterials(TVisPrimitiveObj *CO,
					 TMDelTList< TPointer<TMetaMaterial> >& MaterialRefs,
					 TMDelTList< TPointer<TMetaTexture> >& TextureRefs);
void MergeObjects(TVisPrimitiveObj *dest, TVisPrimitiveObj *src);

//void Triangulate(THoledPolygon* HP,TMDelTList<TIntVec>* Triangles);
#endif

