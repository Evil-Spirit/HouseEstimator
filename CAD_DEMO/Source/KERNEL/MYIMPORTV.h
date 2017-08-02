//---------------------------------------------------------------------------

#ifndef MYIMPORTVH
#define MYIMPORTVH

#include <vector>
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisView.hpp"
#include "VisShape.hpp"
#include "VisCustomObj.hpp"
#include "VisPrimitiveObj.hpp"
//---------------------------------------------------------------------------
//enum TImportOptions = {ioGeometry=0,ioMaterial=1,ioTextureCoord=2};

class COMMONAL_API T_Point {
public:
    T_Point(){};
    virtual ~T_Point(){};
    TMDelTList<int> TRI_IND;
    int PNT_IND;
};

class COMMONAL_API T_Triangle{
public:
    T_Triangle(){};
    virtual ~T_Triangle(){};
    TIntVec Normals[3];
    int indexes[3];
    int texels[3];
    int total[3];
};

class COMMONAL_API T_Figure{
public:
    T_Figure(){eps = 0.00001;};
    virtual ~T_Figure(){};
    TMDelTList<TIntVec> SIM_PNTS;
    TMDelTList<TIntVec> TRIO;
    TMDelTList<TIntVec> TEXELS;
    TMDelTList<T_Point> PNTS;
    TMDelTList<T_Triangle> TRI;
    TIntVec Get_Normal(int Point,int local_triangle);
    void AddPoint(const TIntVec& V);
    void ADDTEXEL(const TIntVec& V);
    void SET_TEX_FACE(int triangle,int i1,int i2,int i3);
    void AddTriangle(int i1,int i2,int i3);
    void AddTriangle_Norms(int tri_ind,const TIntVec& V0,const TIntVec& V1,const TIntVec& V2);
    void Process();
    void ProcessPoint(int index);
    void Re_Add_Triangle_Point(int pointindex,const TIntVec& N,int triangle,int point_in_triangle);
    int Point_In_Triangle(int point_index,int local_triangle);
    int Point_In_Triangle_Global(int point_index,int global_triangle);
    double eps;
    void CreateTrioList();
    void Fill_Object(TVisPrimitiveObj* Obj);
};

class COMMONAL_API TMyImport {
private:
    void GeomObject(TVisCustomObj *Obj,int &i,TStringList *A);
    AnsiString GetData(AnsiString S,int ind);
    void Mesh(TVisCustomObj *Obj,int &i,TStringList *A);
    void fMaterial(TVisMaterial *Obj,int &i,TStringList *A);
    void Texture(TVisTexture *Obj,int &i,TStringList *A);
    void CloseScope(int &i,TStringList *A);
    void TVertList(TVisCustomObj *Obj,TStringList *L,int &i,TStringList *A);
    void TFaceList(TStringList *FL,TStringList *L,TVisCustomObj *Obj,int &i,TStringList *A);
    void CameraSettings(TVisPerspectiveCamera *Obj,int &i,TStringList *A);
    void CameraObject(TVisPerspectiveCamera *Obj,int &i,TStringList *A);
    void NodeTM(TVisTransformed *Obj,int &i,TStringList *A);
    void MeshVertexList(TVisCustomObj *Obj,int &i,TStringList *A,int Count);
    void MeshFaceList(TStringList *FL,TVisCustomObj *Obj,int &i,TStringList *A,int Count);
    void MeshNormals(TVisCustomObj *Obj,int &i,TStringList *A,int Count);
public:		// User declarations
    TMyImport(){CenterFirst=false;eps = 0.0001;};
    virtual ~TMyImport(){};
    void FromFile(  AnsiString FileName,TVisNode *Node);
    bool LoadGeometry;
    bool LoadMaterial;
    bool LoadTexCoord;
    bool LoadNormals;
    bool Econom;
    bool CheckData;
    bool CenterFirst;
    double eps;
    TVisMaterial *MatDefault;
    //AnsiString FileName;
    TVisNode *VisMatNode;
    TVisNode *VisAttNode;
    T_Figure F;
//    TMDelTList<TVisMathVector> V;
//    TVisNode *VisTexNode;
};

std::vector<TVisPrimitiveObj *> LoadFromFile(AnsiString fname);

void COMMONAL_API SaveGeometry(FILE *F,TVisPrimitiveObj *CO);
void COMMONAL_API LoadGeometry(FILE *F,TVisPrimitiveObj *CO);

void COMMONAL_API SaveGeometry(const AnsiString& FN,TVisPrimitiveObj *CO);
void COMMONAL_API LoadGeometry(const AnsiString& FN,TVisPrimitiveObj *CO);

void COMMONAL_API LoadBMP(TImageList *IL,const AnsiString& FileName);
void COMMONAL_API SaveBMP(TImageList *IL,const AnsiString& FileName);

void Read3DS(std::vector<TVisPrimitiveObj*> &Objects, std::vector <Vismat::TVisMaterial*> &Materials ,
			std::vector <AnsiString> &Textures, FILE *F);

#endif

