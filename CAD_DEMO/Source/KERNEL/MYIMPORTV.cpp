 //---------------------------------------------------------------------------
#include <vcl.h>
#include <vector>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
       
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

#include "MYIMPORTV.h"
#include "math.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//Константы со строками параметров в файле ASE
AnsiString GEOMOBJECT               =AnsiString("*GEOMOBJECT ");//начало объекта
AnsiString MESH                     =AnsiString("*MESH ");//начало геометрии объекта
AnsiString MESH_NUMVERTEX           =AnsiString("*MESH_NUMVERTEX ");//количество точек
AnsiString MESH_NUMFACES            =AnsiString("*MESH_NUMFACES ");//количество поверхностей(треугольников)
AnsiString MESH_VERTEX_LIST         =AnsiString("*MESH_VERTEX_LIST "); //начало списка точек
AnsiString MESH_VERTEX              =AnsiString("*MESH_VERTEX ");//точка
AnsiString MESH_FACE_LIST           =AnsiString("*MESH_FACE_LIST "); //  начало списка поверхностей
AnsiString MESH_FACE                =AnsiString("*MESH_FACE "); //  поверхность
AnsiString MESH_NORMALS             =AnsiString("*MESH_NORMALS "); //  список нормалей
AnsiString MESH_FACENORMAL          =AnsiString("*MESH_FACENORMAL "); //  нормаль поверхности
AnsiString MESH_VERTEXNORMAL        =AnsiString("*MESH_VERTEXNORMAL "); //  нормаль точки
AnsiString MATERIAL_REF             =AnsiString("*MATERIAL_REF "); // номер материала


AnsiString NODE_TM                  =AnsiString("*NODE_TM "); //  описание узла
AnsiString TM_POS                   =AnsiString("*TM_POS "); //  положение узла
AnsiString TM_ROTAXIS               =AnsiString("*TM_ROTAXIS "); //  поворот узла
AnsiString TM_SCALE                 =AnsiString("*TM_SCALE "); //  масштаб узла

AnsiString END                      =AnsiString("}"); //  конец текущего раздела
AnsiString START                    =AnsiString("{"); //  начало очередного текущего раздела
AnsiString SP                       =AnsiString(" "); //  пробел
///--------------------------------------------------------------------
AnsiString CAMERAOBJECT             =AnsiString("*CAMERAOBJECT "); //  камера
AnsiString CAMERA_SETTINGS          =AnsiString("*CAMERA_SETTINGS "); //  настройки камеры
AnsiString CAMERA_NEAR              =AnsiString("*CAMERA_NEAR "); //  близость камеры
AnsiString CAMERA_FAR               =AnsiString("*CAMERA_FAR "); //  дальность камеры
AnsiString CAMERA_TDIST             =AnsiString("*CAMERA_TDIST "); //  дистанция камеры
//---------------------------------------------------------------------
AnsiString MATERIAL_LIST            =AnsiString("*MATERIAL_LIST "); //  материалов список
AnsiString MATERIAL_NAME            =AnsiString("*MATERIAL_NAME "); //  имя материала
AnsiString MATERIAL_AMBIENT         =AnsiString("*MATERIAL_AMBIENT "); //
AnsiString MATERIAL_DIFFUSE         =AnsiString("*MATERIAL_DIFFUSE "); //
AnsiString MATERIAL_SPECULAR        =AnsiString("*MATERIAL_SPECULAR "); //
AnsiString MATERIAL_SHINE           =AnsiString("*MATERIAL_SHINE "); //
AnsiString MATERIAL_SHINESTRENGTH   =AnsiString("*MATERIAL_SHINESTRENGTH "); //
AnsiString MATERIAL_TRANSPARENCY    =AnsiString("*MATERIAL_TRANSPARENCY "); //
AnsiString MATERIAL_WIRESIZE        =AnsiString("*MATERIAL_WIRESIZE "); //
AnsiString MATERIAL_SHADING         =AnsiString("*MATERIAL_SHADING "); //
AnsiString MATERIAL_XP_FALLOFF      =AnsiString("*MATERIAL_XP_FALLOFF "); //
AnsiString MATERIAL_SELFILLUM       =AnsiString("*MATERIAL_SELFILLUM "); //
AnsiString MATERIAL_FALLOFF         =AnsiString("*MATERIAL_FALLOFF "); //
AnsiString MATERIAL_XP_TYPE         =AnsiString("*MATERIAL_XP_TYPE "); //
AnsiString MATERIAL                 =AnsiString("*MATERIAL "); //  материал

AnsiString MESH_TVERTLIST           =AnsiString("*MESH_TVERTLIST "); //  список координат текстур
AnsiString MESH_TVERT               =AnsiString("*MESH_TVERT "); //  координата текстуры
AnsiString MESH_TFACELIST           =AnsiString("*MESH_TFACELIST "); //  полигоны текстур
AnsiString MESH_TFACE               =AnsiString("*MESH_TFACE "); //  полигон текстуры

AnsiString MAP_DIFFUSE              =AnsiString("*MAP_DIFFUSE "); //  текстуры
AnsiString MAP_BUMP                 =AnsiString("*MAP_BUMP "); //  текстуры
//AnsiString MATERIAL_XP_TYPE       =AnsiString("*MATERIAL_XP_TYPE "); //  текстуры
AnsiString MAP_GENERIC              =AnsiString("*MAP_GENERIC "); //  текстуры
AnsiString MAP_REFRACT              =AnsiString("*MAP_REFRACT "); //  текстуры
AnsiString MAP_OPACITY              =AnsiString("*MAP_OPACITY "); //  текстуры

AnsiString tBITMAP                  =AnsiString("*BITMAP "); //  файл текстуры
//AnsiString DIGITS=AnsiString("0123456789.");







bool CheckPossibleTexture(AnsiString S)
{
	if (S.AnsiPos(MAP_DIFFUSE)!=0)
    {
        return(true);
    }
    if (S.AnsiPos(MAP_BUMP)!=0)
    {
        return(true);
    }
/*    if (S.AnsiPos(MATERIAL_XP_TYPE)!=0)
    {
        return(true);
    }*/
    if (S.AnsiPos(MAP_GENERIC)!=0)
    {
        return(true);
    }
    if (S.AnsiPos(MAP_REFRACT)!=0)
    {
        return(true);
    }
    if (S.AnsiPos(MAP_OPACITY)!=0)
    {
        return(true);
    }

    return(false);
}
void TMyImport::CloseScope(int &i,TStringList *A)
{
    i++;
    while (A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
}

void TMyImport::TVertList(TVisCustomObj *Obj,TStringList *L,int &i,TStringList *A)
{
    i++;
    double x,y,z;
	int ind;
    while (A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_TVERT)!=0)
        {
            x= TO_DOUBLE( GetData(A->Strings[i],2) );
            y= TO_DOUBLE( GetData(A->Strings[i],3) );
            z= TO_DOUBLE( GetData(A->Strings[i],4) );
            F.ADDTEXEL(TIntVec(x,y,z));
//            L->Add(FLOATTOSTR(x)+SP+FLOATTOSTR(y)+SP+FLOATTOSTR(z));

        }
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
}
void TMyImport::TFaceList(TStringList *FL,TStringList *L,TVisCustomObj *Obj,int &i,TStringList *A)
{
    i++;
    int TexPoints[3];
    int FacePointsIndexes[3];
    int TFace;
    int count;
//    for (int j=0;j<Obj->Points->Count;j++)
  //      Obj->Points->TextureVec[i]=ZEROVEC;
    while (A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_TFACE)!=0)
        {
            TFace=GetData(A->Strings[i],1).ToInt();
            if (TFace>=F.TRI.Count)
                break;
            for (int j=0;j<3;j++)
            {
                TexPoints[j]=GetData(A->Strings[i],j+2).ToInt();
                //FacePointsIndexes[j]=GetData(FL->Strings[TFace],j).ToInt();
            }
            F.SET_TEX_FACE(TFace,TexPoints[0],TexPoints[1],TexPoints[2]);
/*            for (int j=0;j<3;j++)
            {
                TVisMathVector TexCoord;
				TexCoord.x=TO_DOUBLE(GetData(L->Strings[TexPoints[j]],0));
                TexCoord.y=TO_DOUBLE(GetData(L->Strings[TexPoints[j]],1));
                TexCoord.z=TO_DOUBLE(GetData(L->Strings[TexPoints[j]],2));
                int CurIndex=FacePointsIndexes[j];
//                if (VisMathVectorDist(Obj->Points->TextureVec[FacePointsIndexes[j]],ZEROVEC)!=0)
  //                  CurIndex=Obj->Points->Add(Obj->Points->PointVec[CurIndex],Obj->Points->NormalVec[CurIndex],ZEROVEC);
                Obj->Points->TextureVec[CurIndex]=TexCoord;
            } */
        }
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
}

void TMyImport::Texture(TVisTexture *Obj,int &i,TStringList *A)
{
    i++;
    while (A->Strings[i].AnsiPos(END)==0)
    {
/*        if (A->Strings[i].AnsiPos(tBITMAP)!=0)
        {
            AnsiString FN=ExtractFileName(GetData(A->Strings[i],1));
            FN=ChangeFileExt(FN ,AnsiString(".BMP") );
            AnsiString Dir=ExtractFileDir(OpenDialog->FileName);
            AnsiString SL=AnsiString("\\");
            if ( FileExists(Dir+SL+FN))
                Obj->Bitmap->LoadFromFile(Dir+SL+FN);
        }*/
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
}

void TMyImport::fMaterial(TVisMaterial *Obj,int &i,TStringList *A)
{
    int R,G,B;
    i++;
    TVisAttributes *Atr;
	Atr = new TVisAttributes(NULL);
    Atr->Lighting=true;
//    TVisTexture *Tex= new TVisTexture(VisView1);

    while (A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MATERIAL_AMBIENT)!=0)
        {
            R=(TO_DOUBLE(GetData(A->Strings[i],1))*(double)255);
            G=(TO_DOUBLE(GetData(A->Strings[i],2))*(double)255);
            B=(TO_DOUBLE(GetData(A->Strings[i],3))*(double)255);
            Obj->ColorAmbient->Color=(TColor)RGB(R,G,B);
            Atr->ColorAmbient->Color=(TColor)RGB(R,G,B);
        }
        if (A->Strings[i].AnsiPos(MATERIAL_DIFFUSE)!=0)
        {
            R=(TColor)(TO_DOUBLE(GetData(A->Strings[i],1))*(double)255);
            G=(TColor)(TO_DOUBLE(GetData(A->Strings[i],2))*(double)255);
            B=(TColor)(TO_DOUBLE(GetData(A->Strings[i],3))*(double)255);
            Obj->ColorDiffuse->Color=(TColor)RGB(R,G,B);
        }
        if (A->Strings[i].AnsiPos(MATERIAL_SPECULAR)!=0)
        {
            R=(TColor)(TO_DOUBLE(GetData(A->Strings[i],1))*(double)255);
            G=(TColor)(TO_DOUBLE(GetData(A->Strings[i],2))*(double)255);
            B=(TColor)(TO_DOUBLE(GetData(A->Strings[i],3))*(double)255);
            Obj->ColorSpecular->Color=(TColor)RGB(R,G,B);
        }
        if (A->Strings[i].AnsiPos(MATERIAL_SHINE)!=0)
        {
            Obj->Shininess=TO_DOUBLE(GetData(A->Strings[i],1));
        }
        if (A->Strings[i].AnsiPos(MATERIAL_TRANSPARENCY)!=0)
        {
            double val=TO_DOUBLE(GetData(A->Strings[i],1));
            if (val>0){
                Atr->Transparency=tmAddAlpha;
                Atr->ColorAmbient->Alpha=1-val;
                Obj->ColorAmbient->Alpha=1-val;
                Obj->ColorDiffuse->Alpha=1-val;
                Obj->ColorSpecular->Alpha=1-val;
            }
        }
/*        if (CheckPossibleTexture(A->Strings[i]))
		{
            Texture(Tex,i,A);
        }*/
        //-----------------------------------
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
    VisAttNode->AddIndirect(Atr);
//    VisTexNode->AddIndirect(Tex);
}


AnsiString TMyImport::GetData(AnsiString S,int ind){
    TStringList *B;
    B=new TStringList();
    B->CommaText=S.Trim();
    S=B->Strings[ind].Trim();
    delete B;
    if (CheckData){
        int K=S.Length();
        int i=1;
        while(i<=K)
        {
            if (DIGITS.Pos(S[i])!=0)
            {
                i++;
                continue;
            }
            if (AnsiString(S[i]) == AnsiString("-"))
            {
                i++;
                continue;
            }
            if (DELIMS.Pos(S[i])==0)
            {
                S.Delete(i,1);
                S.Insert("0",i);
            }
			else
            {
                S.Delete(i,1);
				S.Insert(DecimalSeparator,i);
            }
            i++;
        }
    }
    return(S);
}


void TMyImport::GeomObject(TVisCustomObj *Obj,int &i,TStringList *A)
{
//функция берет геометрический объект вместе с нормалями и возможно с коорд. текстур.
    i++;
    //    (TVisMathVector)
    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(NODE_TM)!=0)
            NodeTM(Obj,i,A);
        if (A->Strings[i].AnsiPos(MESH)!=0)
            Mesh(Obj,i,A);

        if (A->Strings[i].AnsiPos(MATERIAL_REF)!=0)
        {
            int matindex=GetData(A->Strings[i],1).ToInt();
            if (matindex<VisMatNode->Count)
                Obj->Material=(TVisMaterial *)VisMatNode->Items[matindex];
            if (matindex<VisAttNode->Count)
                Obj->Attributes=(TVisAttributes *)VisAttNode->Items[matindex];
/*            if (matindex<VisTexNode->Count)
            {
                Obj->Texture=(TVisTexture *)VisTexNode->Items[matindex];
                Obj->Textured=true;
            }*/
        }


        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
	}

}

void TMyImport::CameraSettings(TVisPerspectiveCamera *Obj,int &i,TStringList *A)
{
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(CAMERA_NEAR)!=0)
        {
            Obj->ViewNear=TO_DOUBLE(GetData(A->Strings[i],1))+0.1;
        }
        if (A->Strings[i].AnsiPos(CAMERA_FAR)!=0)
        {
            Obj->ViewFar=TO_DOUBLE(GetData(A->Strings[i],1));
        }
        if (A->Strings[i].AnsiPos(CAMERA_TDIST)!=0)
        {
            Obj->ViewAngle=TO_DOUBLE(GetData(A->Strings[i],1));
        }
        i++;
    }
}

void TMyImport::CameraObject(TVisPerspectiveCamera *Obj,int &i,TStringList *A)
{
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
        bool Node=false;
        if (A->Strings[i].AnsiPos(NODE_TM)!=0)
        {
            if (Node==true)
            {
                while(A->Strings[i].AnsiPos(END)!=0)
                    i++;
            }
            else
            {
                NodeTM(Obj,i,A);
                Node=true;
            }
        }
		if (A->Strings[i].AnsiPos(CAMERA_SETTINGS)!=0)
        {
            CameraSettings(Obj,i,A);
		}
        i++;
    }
}

void TMyImport::NodeTM(TVisTransformed *Obj,int &i,TStringList *A)
{
    double x,y,z;
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
/*        if (A->Strings[i].AnsiPos(TM_POS)!=0)
        {
            x=TO_DOUBLE(GetData(A->Strings[i],1));
            y=TO_DOUBLE(GetData(A->Strings[i],2));
            z=TO_DOUBLE(GetData(A->Strings[i],3));
            Obj->Transformation->Translation->AsMathVector=ToVec(x,y,z);
//            Obj->Transformation->Translation->AsMathVector=ZEROVEC;
        }
        if (A->Strings[i].AnsiPos(TM_SCALE)!=0)
        {
            x=TO_DOUBLE(GetData(A->Strings[i],1));
            y=TO_DOUBLE(GetData(A->Strings[i],2));
            z=TO_DOUBLE(GetData(A->Strings[i],3));
            Obj->Transformation->Scale->AsMathVector=ToVec(x,y,z);
        }
        if (A->Strings[i].AnsiPos(TM_ROTAXIS)!=0)
        {
            x=TO_DOUBLE(GetData(A->Strings[i],1));
            y=TO_DOUBLE(GetData(A->Strings[i],2));
            z=TO_DOUBLE(GetData(A->Strings[i],3));
            Obj->Transformation->Rotation->AsMathVector=ToVec(x,y,z);
        }*/
        i++;
    }
}


void TMyImport::Mesh(TVisCustomObj *Obj,int &i,TStringList *A)
{
//функция берет инфу из файла из раздела Mesh

    int NumVertex;
    int NumFaces;
	i++;
    TStringList *TexCoordList;
    TexCoordList= new TStringList();
    TStringList *FL= new TStringList();

    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_NUMVERTEX)!=0)
            NumVertex=GetData(A->Strings[i],1).ToInt();
        if (A->Strings[i].AnsiPos(MESH_NUMFACES)!=0)
            NumFaces=GetData(A->Strings[i],1).ToInt();
        if (A->Strings[i].AnsiPos(MESH_VERTEX_LIST)!=0)
            MeshVertexList(Obj,i,A,NumVertex);
        if (A->Strings[i].AnsiPos(MESH_FACE_LIST)!=0)
            MeshFaceList(FL,Obj,i,A,NumFaces);
        if (A->Strings[i].AnsiPos(MESH_NORMALS)!=0)
            MeshNormals(Obj,i,A,NumFaces);
        if (LoadTexCoord)
        {
            if (A->Strings[i].AnsiPos(MESH_TVERTLIST)!=0)
                TVertList(Obj,TexCoordList,i,A);
            if (A->Strings[i].AnsiPos(MESH_TFACELIST)!=0)
                TFaceList(FL,TexCoordList,Obj,i,A);
        }

        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
    delete TexCoordList,FL;
}
/*procedure VisMathNormalVector(P1,P2,P3 : TVisMathPoint;Normalize : Boolean;
          var N : TVisMathVector);
var
 A,B : TVisMathVector;
begin
 A.x := P1.x - P2.x;
 A.y := P1.y - P2.y;
 A.z := P1.z - P2.z;
 B.x := P2.x - P3.x;
 B.y := P2.y - P3.y;
 B.z := P2.z - P3.z;
 VisMathCrossProduct(A,B,N);
 if Normalize then VisMathNormalize(N);
end;

procedure VisMathNormalize(var A : TVisMathVector);
var
 D : Double;
begin
 D := sqrtDC((A.x * A.x) + (A.y * A.y) + (A.z * A.z));
 if D>0 then
   begin
     A.x := A.x / D;
     A.y := A.y / D;
     A.z := A.z / D;
   end;
end;

procedure VisMathCrossProduct(A,B : TVisMathVector;var C : TVisMathVector);
begin
 C.x := (A.y * B.z) - (A.z * B.y);
 C.y := (A.z * B.x) - (A.x * B.z);
 C.z := (A.x * B.y) - (A.y * B.x);
end;

    GL_TRIANGLES:
      for b:=0 to (count div 3)-1 do
       begin
        VisMathNormalVector(FPoints.PointVec[Indices[b*3]],FPoints.PointVec[Indices[b*3+1]],FPoints.PointVec[Indices[b*3+2]],true,curvec);
        AddCurVec(b*3);
        AddCurVec(b*3+1);
        AddCurVec(b*3+2);
       end;


 procedure AddCurVec(index:integer);
 var i:integer;
  begin
   //Adds the current normal vector to a point (or its master).
   with TVisPrimitiveArray(FPrimitive[a]) do
    begin
     i:=Indices[index];
	 if FPoints.ShareLight[i] then
       i:=GetLightMaster(i);
     VisMathVectorAddition(curvec,newnorms[i],newnorms[i]);
	 normcount[i]:=normcount[i]+1;
    end;
  end;    */
TIntVec SERV;
void TMyImport::MeshVertexList(TVisCustomObj *Obj,int &i,TStringList *A,int Count)
{
//функция берет инфу из файла из раздела "список точек"

//получает индекс в позиции MESH_VERTEX_LIST, значит нам нужен следующий
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_VERTEX)!=0)
        {
            SERV.x = TO_DOUBLE(GetData(A->Strings[i],2));
            SERV.y=TO_DOUBLE(GetData(A->Strings[i],3));
            SERV.z=TO_DOUBLE(GetData(A->Strings[i],4));
            F.AddPoint(SERV);
        }
        if (A->Strings[i].AnsiPos(START)!=0)
        {
            CloseScope(i,A);
        }
        i++;
    }
}

void TMyImport::MeshFaceList(TStringList *FL,TVisCustomObj *Obj,int &i,TStringList *A,int Count)
{
    int pointindex1,pointindex2,pointindex3;
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_FACE)!=0)
        {
            pointindex1=GetData(A->Strings[i],3).ToInt();
            pointindex2=GetData(A->Strings[i],5).ToInt();
            pointindex3=GetData(A->Strings[i],7).ToInt();
            F.AddTriangle(pointindex1,pointindex2,pointindex3);
        }
        if (A->Strings[i].AnsiPos(START)!=0)
		{
            CloseScope(i,A);
        }
		i++;
    }
}


TVisMathVector Normalize(const TVisMathVector &Vec)
{
    double a = 1;
    if (Vec.x||Vec.y||Vec.z)
        a = sqrtDC(Vec.x*Vec.x+Vec.y*Vec.y+Vec.z*Vec.z);
    return (ToVec(Vec.x/a,Vec.y/a,Vec.z/a));
}

TVisMathVector N[3];
int face_index;
int pointindex[3];
int i_index[3];
void TMyImport::MeshNormals(TVisCustomObj *Obj,int &i,TStringList *A,int Count)
{
    int count=0;
    i++;
    while(A->Strings[i].AnsiPos(END)==0)
    {
        if (A->Strings[i].AnsiPos(MESH_FACENORMAL)!=0)
        {
            face_index = GetData(A->Strings[i],1).ToInt();
        }
        if (A->Strings[i].AnsiPos(MESH_VERTEXNORMAL)!=0)
        {
            pointindex[count] = GetData(A->Strings[i],1).ToInt();
            N[count].x=TO_DOUBLE(GetData(A->Strings[i],2));
            N[count].y=TO_DOUBLE(GetData(A->Strings[i],3));
            N[count].z=TO_DOUBLE(GetData(A->Strings[i],4));
            count++;
            if (count == 3)
            {
                for (int i=0;i<3;i++)
                    i_index[i] = F.Point_In_Triangle_Global(pointindex[i],face_index);
                F.AddTriangle_Norms(face_index,N[i_index[0]],N[i_index[1]],N[i_index[2]]);
                count=0;
            }
		}
        if (A->Strings[i].AnsiPos(START)!=0)
        {
			CloseScope(i,A);
        }
        i++;
    }
}

/*void Center(TVisCustomObj *Obj)
{
    TVisMathVector _Min = ToVec(100000000,100000000,10000000);
    TVisMathVector _Max = ToVec(-100000000,-100000000,-10000000);
    for (int i=0;i<Obj->Points->Count;i++)
        for (int j=0;j<3;j++)
        {
            if (Obj->Points->PointVec[i].a[j]>_Max.a[j])
                _Max.a[j] = Obj->Points->PointVec[i].a[j];
            if (Obj->Points->PointVec[i].a[j]<_Min.a[j])
                _Min.a[j] = Obj->Points->PointVec[i].a[j];
        }
    TVisMathVector _Center;
    for (int i=0;i<3;i++)
        _Center.a[i] = ((_Min.a[i]+_Max.a[i])/2);
    Obj->Points->MovePoints(-_Center.x,-_Center.y,-_Center.z);
}  */

void TMyImport::FromFile(AnsiString FileName,TVisNode *Node)
{
 TStringList *A=new TStringList();
 A->LoadFromFile(FileName);
 Node->Clear();
 VisMatNode->Clear();
 VisAttNode->Clear();
// VisTexNode->Clear();
// VisView1->BackgroundColor=RGB(11,11,11);
 for (int i=0;i<A->Count;i++)
 {
    F.eps = eps;
    if (LoadGeometry&&A->Strings[i].AnsiPos(GEOMOBJECT)!=0)
    {
        TVisCustomObj *Obj;
        Obj = new TVisCustomObj(NULL);
        Obj->Init();
		Obj->AutoCalcNormals=false;
        Obj->Material=MatDefault;
        F.SIM_PNTS.Clear();
		F.TRIO.Clear();
        F.TEXELS.Clear();
        F.PNTS.Clear();
        F.TRI.Clear();
        GeomObject(Obj,i,A);
        F.Process();
        F.CreateTrioList();
        F.Fill_Object(Obj);
        if (!LoadNormals)
            Obj->CalcNormals();
        Node->Add(Obj);
    }
    if (LoadMaterial&&A->Strings[i].AnsiPos(MATERIAL)!=0){
        TVisMaterial *Obj;
        Obj = new TVisMaterial(NULL);
        fMaterial(Obj,i,A);
        VisMatNode->AddIndirect(Obj);
    }
/*    if (A->Strings[i].AnsiPos(CAMERAOBJECT)!=0){
        TVisPerspectiveCamera *Obj;
        Obj = new TVisPerspectiveCamera(VisView1);
        CameraObject(Obj,i,A);
        VisView1->Camera=Obj;
        VisNode1->AddIndirect((TVisRender *)Obj);
        VisView1->InvalidateGL();
    }*/
 }
	delete A;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void SaveGeometry(
	FILE *F,
	TVisPrimitiveObj *CO)
{
    //normalsvect
//    CO->CalcNormals();
    //texturesvect   
	//points
    fputs(IntToStr(CO->Points->Count).c_str(),F);
    fputs("\n",F);
	for (int i=0;i<CO->Points->Count;i++)
        for (int j=0;j<3;j++)
        {
            fputs(FLOATTOSTR(CO->Points->Point[i][j]).c_str(),F);
            fputs("\n",F);
            fputs(FLOATTOSTR(CO->Points->Normal[i][j]).c_str(),F);
            fputs("\n",F);
            fputs(FLOATTOSTR(CO->Points->Texture[i][j]).c_str(),F);
            fputs("\n",F);
        }

    //primitives type
    fputs(IntToStr(CO->PrimitiveCount).c_str(),F);
    fputs("\n",F);
    for (int p=0;p<CO->PrimitiveCount;p++)
    {
        fputs(IntToStr(CO->Primitive[p]->PrimitiveType).c_str(),F);
		fputs("\n",F);
		// Material & texture names
		/*
		while(CO->Primitive[p]->MaterialName.LastDelimiter("\n"))
		{
			CO->Primitive[p]->MaterialName.Delete(CO->Primitive[p]->MaterialName.LastDelimiter("\n"), 1);
		}
		*/
//		fputs(CO->Primitive[p]->MaterialName.Trim().c_str(),F);
		fputs("\n",F);
		//primitive indices;
		fputs(IntToStr(CO->Primitive[p]->Count).c_str(),F);
		fputs("\n",F);
		for (int i=0;i<CO->Primitive[p]->Count;i++)
		{
			fputs(IntToStr(CO->Primitive[p]->Indices[i]).c_str(),F);
			fputs("\n",F);
		}
	}
	//normalsvect
	//texturesvect
}

void LoadGeometry(
	FILE *F,
	TVisPrimitiveObj *CO)
{
	int primitiveIndex;
	CO->Init();
	CO->AutoCalcNormals=false;
	char str[256];
	//points
	fgets(str,256,F);
	int PointCount = AnsiString(str).Trim().ToInt();
	TVisMathVector point;
	TVisMathVector normal;
	TVisMathVector texture;
	for (int i=0;i<PointCount;i++)
	{
		for (int j=0;j<3;j++)
		{
			fgets(str,256,F);
			point.a[j] = TO_DOUBLE(AnsiString(str).Trim());
			fgets(str,256,F);
			normal.a[j] = TO_DOUBLE(AnsiString(str).Trim());
			fgets(str,256,F);
			texture.a[j] = TO_DOUBLE(AnsiString(str).Trim());
		}
		CO->Points->Add(point,normal,texture);
	}
	//primitives type
	fgets(str,256,F);
	int PrimCount = AnsiString(str).Trim().ToInt();
	for (int p=0;p<PrimCount;p++)
	{
		fgets(str,256,F);
		int PrimType = AnsiString(str).Trim().ToInt();
		primitiveIndex = CO->AddPrimitiveArray(PrimType);
		// Material & texture names
		fgets(str,256,F);
//		CO->Primitive[primitiveIndex]->MaterialName = str;
		//indices
        fgets(str,256,F);
        int IndCount = AnsiString(str).Trim().ToInt();
        for (int i=0;i<IndCount;i++)
        {
            fgets(str,256,F);
			CO->AddIndex(AnsiString(str).Trim().ToInt(),p);
        }
    }
    //normalsvect
//    CO->CalcNormals();
    //texturesvect
}

void SaveGeometry(const AnsiString& FN,TVisPrimitiveObj *CO)
{
    FILE *F;
    int attr = FileGetAttr(FN);
    if (attr & faReadOnly)
        FileSetAttr(FN,attr & !faReadOnly);
	F = fopen(FN.c_str(),"w");
	SaveGeometry(F,CO);
	fclose(F);
}

void LoadGeometry(const AnsiString& FN,TVisPrimitiveObj *CO)
{
    CO->Init();
    if (!FileExists(FN))
        return;
    FILE *F = fopen(FN.c_str(),"r");
	LoadGeometry(F,CO);
	fclose(F);
}


void LoadBMP(TImageList *IL,const AnsiString& FileName)
{
    IL->Clear();
    if (!FileExists(FileName))
    {
        FILE *F = fopen((FileName).c_str(),"w");
        fclose(F);
    }
    Graphics::TBitmap * bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;

    //---------
    _TRY_
    //---------
		bmp->LoadFromFile(FileName);
        if ( bmp->Width>=IL->Width && bmp->Height>=IL->Height)
        {
            TRect R0 = TRect(0,0,IL->Width,IL->Height);
            int i=0;
            while ((i+1)*(IL->Width)<=(bmp->Width))
            {
                TRect R = TRect(i*(IL->Width),0,(i+1)*(IL->Width),IL->Height);
                Graphics::TBitmap * _bmp = new Graphics::TBitmap();
    _bmp->HandleType = bmDIB;
                _bmp->Width = IL->Width;
                _bmp->Height = IL->Height;
                _bmp->Canvas->CopyRect(R0,bmp->Canvas,R);

				i++;
                TRect R1 = TRect(i*(IL->Width),0,(i+1)*(IL->Width),IL->Height);
                Graphics::TBitmap * mask_bmp = new Graphics::TBitmap();
	mask_bmp->HandleType = bmDIB;
                mask_bmp->Width = IL->Width;
                mask_bmp->Height = IL->Height;
                mask_bmp->Canvas->CopyRect(R0,bmp->Canvas,R1);

                IL->Add(_bmp,mask_bmp);
                delete _bmp;
                delete mask_bmp;
                i++;
            }
        }
    //-------
	_ENDTRY_("<LoadBMP>: File loading error! ",IL->Clear());
    //-------
    delete bmp;
}

void SaveBMP(TImageList *IL,const AnsiString& FileName)
{
    if (!FileExists(FileName))
    {
        FILE *F = fopen((FileName).c_str(),"w");
        fclose(F);
    }
    else
    {
        int attr = FileGetAttr(FileName);
		if (attr & faReadOnly)
            FileSetAttr(FileName,attr & !faReadOnly);
    }
    if (!IL->Count)
    {
        IL->Clear();
        return;
    }
    TRect R0 = TRect(0,0,IL->Width,IL->Height);
    Graphics::TBitmap * bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    bmp->Width = IL->Width*IL->Count*2;
    bmp->Height = IL->Height;
    for (int k=0;k<IL->Count;k++)
	{
        int i=k;
        IL->Draw(bmp->Canvas,i*2*(IL->Width),0,i,dsNormal,itImage,true);
		IL->Draw(bmp->Canvas,(i*2+1)*(IL->Width),0,i,dsNormal,itMask,true);
    }
    bmp->SaveToFile(FileName);
    delete bmp;
}
/*void SaveBMP(TImageList *IL,const AnsiString& FileName)
{
    if (!FileExists(FileName))
    {
        FILE *F = fopen((FileName).c_str(),"w");
        fclose(F);
    }
    else
    {
        int attr = FileGetAttr(FileName);
        if (attr & faReadOnly)
            FileSetAttr(FileName,attr & !faReadOnly);
    }
    if (!IL->Count)
    {
        IL->Clear();
        return;
    }
    TRect R0 = TRect(0,0,IL->Width,IL->Height);
    Graphics::TBitmap * bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    bmp->Width = IL->Width*IL->Count*2;
	bmp->Height = IL->Height;
    for (int k=0;k<IL->Count;k++)
    {
        int i=2*k;
        Graphics::TBitmap * _bmp = new Graphics::TBitmap();
    _bmp->HandleType = bmDIB;
        _bmp->Width = IL->Width;
        _bmp->Height = IL->Height;
        Graphics::TBitmap * _mask = new Graphics::TBitmap();
    _mask->HandleType = bmDIB;
        _mask->Width = IL->Width;
        _mask->Height = IL->Height;
        TRect R = TRect(i*(IL->Width),0,(i+1)*(IL->Width),IL->Height);
        TRect R2 = TRect((i+1)*(IL->Width),0,(i+2)*(IL->Width),IL->Height);
		IL->GetImages(i,_bmp,_mask);
        bmp->Canvas->CopyRect(R,_bmp->Canvas,R0);
        bmp->Canvas->CopyRect(R,_mask->Canvas,R2);
		delete _bmp;
        delete _mask;
    }
    bmp->SaveToFile(FileName);
    delete bmp;
}
*/

int T_Figure::Point_In_Triangle_Global(int point_index,int triangle)
{
    if (TRI[triangle].indexes[0] == point_index)
        return 0;
    else if (TRI[triangle].indexes[1] == point_index)
        return 1;
    else if (TRI[triangle].indexes[2] == point_index)
        return 2;
    else
        throw EMyException("Error in t_triangle");
}

int T_Figure::Point_In_Triangle(int point_index,int local_triangle)
{
    int triangle = PNTS[point_index].TRI_IND[local_triangle];
    return Point_In_Triangle_Global(point_index,triangle);
}

TIntVec T_Figure::Get_Normal(int indexPoint,int local_triangle)
{
    int triangle = PNTS[indexPoint].TRI_IND[local_triangle];
    return TRI[triangle].Normals[Point_In_Triangle(indexPoint,local_triangle)];
}

void T_Figure::AddPoint(const TIntVec& V)
{
    SIM_PNTS.Add( new TIntVec(V.x,V.y,V.z));
    PNTS.Add( new T_Point() );
    T_Point& T_P = *(PNTS.Last());
    T_P.PNT_IND = SIM_PNTS.Count-1;
}

void T_Figure::ADDTEXEL(const TIntVec& V)
{
    TEXELS.Add( new TIntVec(V.x,V.y,V.z) );
}

void T_Figure::SET_TEX_FACE(int tri_ind,int i1,int i2,int i3)
{
    TRI[tri_ind].texels[0] = i1;
    TRI[tri_ind].texels[1] = i2;
    TRI[tri_ind].texels[2] = i3;
}


void T_Figure::AddTriangle(int i1,int i2,int i3)
{
    TRI.Add( new T_Triangle() );
    T_Triangle& TR = *(TRI.Last());
    TR.indexes[0] = i1;
    TR.indexes[1] = i2;
    TR.indexes[2] = i3;

    TR.total[0] = i1;
    TR.total[1] = i2;
    TR.total[2] = i3;
    
    TR.texels[0] = -1;
    TR.texels[1] = -1;
    TR.texels[2] = -1;
    PNTS[i1].TRI_IND.Add(new int(TRI.Count-1));
    PNTS[i2].TRI_IND.Add(new int(TRI.Count-1));
    PNTS[i3].TRI_IND.Add(new int(TRI.Count-1));
}

void T_Figure::AddTriangle_Norms(int tri_ind,const TIntVec& V0,const TIntVec& V1,const TIntVec& V2)
{
    TRI[tri_ind].Normals[0] = V0;
    TRI[tri_ind].Normals[1] = V1;
    TRI[tri_ind].Normals[2] = V2;
}

void T_Figure::Re_Add_Triangle_Point(int pointindex,const TIntVec& N,int triangle,int point_in_triangle)
{
    for (int i=0;i<PNTS.Count;i++)
        if ( (PNTS[i].PNT_IND == pointindex) && (PNTS[i].TRI_IND.Count>0) )
        {
			TIntVec Normal0 = Get_Normal(i,0);
            if ( (Normal0-N).Length()<eps )
            {
				//добавляем сюда
                TRI[triangle].indexes[point_in_triangle] = i;
                PNTS[i].TRI_IND.Add(new int(triangle));
                return;
            }
        }
    PNTS.Add( new T_Point() );
    T_Point& T_P = *(PNTS.Last());
    T_P.PNT_IND = pointindex;
    T_P.TRI_IND.Add(new int(triangle));
    TRI[triangle].indexes[point_in_triangle] = PNTS.Count-1;
}

void T_Figure::ProcessPoint(int index)
{
    T_Point& T_P = PNTS[index];
    //считаем первый треугольник своим
    int k=1;
    while(k<T_P.TRI_IND.Count)
    {
        TIntVec N0 = Get_Normal(index,0);
        TIntVec NK = Get_Normal(index,k);
        if ( ( NK - N0 ).Length()<eps )
            k++;
        else
        {
            int point_in_triangle = Point_In_Triangle(index,k);
			int triangle = T_P.TRI_IND[k];
            int pointindex = index;
            T_P.TRI_IND.Delete(k);
            Re_Add_Triangle_Point(pointindex,NK,triangle,point_in_triangle);
        }
    }
}

void T_Figure::Process()
{
    int Count = PNTS.Count;
    StartProcess("Surface and vertices analysis ...",Count);
    for (int i=0;i<Count;i++)
    {
		CountProcess(AnsiString(),1);
        if (PNTS[i].TRI_IND.Count>1)
            ProcessPoint(i);
	}
}

void T_Figure::CreateTrioList()
{
    TIntVec trio;
    for (int i=0;i<TRI.Count;i++)
        for (int j=0;j<3;j++)
        {
            trio.x = TRI[i].indexes[j];
            trio.y = TRI[i].texels[j];
            trio.z = -1;
            int index = FindInList(&TRIO,trio);
			if (index == -1)
				index = TRIO.Add( new TIntVec(trio) );
			TRI[i].total[j] = index;
		}
}


void T_Figure::Fill_Object(TVisPrimitiveObj* Obj)
{
    Obj->Init();
    if (Obj->PrimitiveCount==0)
        Obj->AddPrimitiveArray(GL_TRIANGLES);
    StartProcess("Creating vertices ...",PNTS.Count);
    for (int i=0;i<TRIO.Count;i++)
	{
        int pindex = TRIO[i].intX();
        int tindex = TRIO[i].intY();
        TIntVec& V = SIM_PNTS[PNTS[pindex].PNT_IND];
        TIntVec N = (PNTS[pindex].TRI_IND.Count>0) ? Get_Normal(pindex,0) : ZEROINTVEC;
        TIntVec T = (tindex!=-1) ? TEXELS[tindex] : ZEROINTVEC;
        Obj->Points->Add(ToVec(V.x,V.y,V.z),ToVec(N.x,N.y,N.z),ToVec(T.x,T.y,T.z));
        CountProcess(AnsiString(),1);
	}
/*    for (int i=0;i<PNTS.Count;i++)
    {
        TIntVec& V = SIM_PNTS[PNTS[i].PNT_IND];
        TIntVec N;
            if (PNTS[i].TRI_IND.Count>0)
				N = Get_Normal(i,0);
            else
                N = ZEROINTVEC;
		Obj->Points->Add(ToVec(V.x,V.y,V.z),ToVec(N.x,N.y,N.z),ZEROVEC);
        CountProcess(AnsiString(),1);
    }  */
    StartProcess("Creating surfaces ...",TRI.Count);
    for (int i=0;i<TRI.Count;i++)
    {
        Obj->AddIndex(TRI[i].total[0]);
        Obj->AddIndex(TRI[i].total[1]);
        Obj->AddIndex(TRI[i].total[2]);
        CountProcess(AnsiString(),1);
	}
}

//--------------------- 3DS EXPORT CODE BEGINS HERE ----------------------------

// 3ds chunk structure. I appended a begin field for better seeking, but
// read only 2 first fields (Begin is filled by the program itself)
#pragma pack(push, 1)
struct Chunk3DS
{
#define CHUNK3DS_WROTE_SIZE	6
	unsigned short ID;
	unsigned int Length;
	unsigned long Begin;
};

// for reading Vectors (it may happen that they won't be needed)
struct Vector3DS
{
	float X, Y, Z;
};
#pragma pack(pop)

// parser structure for keeping all necessary information
struct Parser3DS
{
	Parser3DS() { Chunks.resize(0); Pos = 0; File = NULL; };
	std::vector<struct Chunk3DS> Chunks;
	unsigned long Pos;
	FILE *File;
};

// Here we read to pointer given number of bytes, it's just an utility.
long ReadPtr(Parser3DS &parser, void *ptr, long size)
{
	long act_read = 0;
	char *pointer = (char*)ptr;
	act_read = fread(pointer, size, 1, parser.File);
	parser.Pos += act_read * size;
	//if(parser.Chunks.size() > 0)
		while(parser.Chunks.size() > 0 && (parser.Chunks[parser.Chunks.size()-1].Begin +
				parser.Chunks[parser.Chunks.size()-1].Length) <= parser.Pos)
		{
			parser.Chunks.resize(parser.Chunks.size() - 1);
		}
	return act_read;
}

// Read information about 3DS chunk and store it to the parser.
bool Read3dsChunk(Parser3DS &parser, Chunk3DS *chunk)
{
	chunk->Begin = parser.Pos;
	chunk->ID = 0;
	chunk->Length = 0;
	static Chunk3DS insertChunk;
	if(!ReadPtr(parser, chunk, CHUNK3DS_WROTE_SIZE))
	{
		return false;
	}
	insertChunk.ID = chunk->ID;
	insertChunk.Length = chunk->Length;
	insertChunk.Begin = chunk->Begin;
	parser.Chunks.push_back(insertChunk);
	return true;
}

AnsiString ReadStringZ(Parser3DS &parser)
{
	static AnsiString str;
	str = "";
	char letter = 0xFF;
	while(ReadPtr(parser, &letter, 1) && letter)
	{
		str += letter;
	}
	return str;
}

// Skip chunk that we are currently in.
bool SkipChunk(Parser3DS &parser, int index)
{
	Chunk3DS chunk;
	long CurPos;
	if((int)parser.Chunks.size() < index || index < 0)
		return false;
	chunk = parser.Chunks[index];
	parser.Chunks.resize(index);

	CurPos = chunk.Begin + chunk.Length;

	if(fseek(parser.File, CurPos, SEEK_SET))
	{
		return false;
	}

	parser.Pos = CurPos;
	// Exit all other chunks that we are passed over occasionally
	//if(parser.Chunks.size() > 0)
		while(parser.Chunks.size() > 0 && (parser.Chunks[parser.Chunks.size()-1].Begin +
				parser.Chunks[parser.Chunks.size()-1].Length) <= (unsigned int)CurPos)
		{
			parser.Chunks.resize(parser.Chunks.size() - 1);
		}
	return true;
}

// Skip chunk that we are currently in.
bool SkipCurrentChunk(Parser3DS &parser)
{
	return SkipChunk(parser, parser.Chunks.size()-1);
}

int ChunkIndex(Parser3DS parser, unsigned int ChunkID)
{
	for(unsigned int i = 0; i < parser.Chunks.size(); i ++)
	{
		if(parser.Chunks[i].ID == ChunkID)
			return i; // return an index of a chunk
	}
	return -1; // no such a chunk
}

//>------ Primary chunk

 #define MAIN3DS       0x4D4D

 //>------ Main Chunks

 #define EDIT3DS       0x3D3D  // this is the start of the editor config
 #define KEYF3DS       0xB000  // this is the start of the keyframer config (is not needed)

 //>------ sub defines of EDIT3DS

 #define EDIT_MATERIAL 0xAFFF
 #define EDIT_CONFIG1  0x0100
 #define EDIT_CONFIG2  0x3E3D
 #define EDIT_VIEW_P1  0x7012
 #define EDIT_VIEW_P2  0x7011
 #define EDIT_VIEW_P3  0x7020
 #define EDIT_VIEW1    0x7001
 #define EDIT_BACKGR   0x1200
 #define EDIT_AMBIENT  0x2100
 #define EDIT_OBJECT   0x4000

 #define EDIT_UNKNW01  0x1100
 #define EDIT_UNKNW02  0x1201
 #define EDIT_UNKNW03  0x1300
 #define EDIT_UNKNW04  0x1400
 #define EDIT_UNKNW05  0x1420
 #define EDIT_UNKNW06  0x1450
 #define EDIT_UNKNW07  0x1500
 #define EDIT_UNKNW08  0x2200
 #define EDIT_UNKNW09  0x2201
 #define EDIT_UNKNW10  0x2210
 #define EDIT_UNKNW11  0x2300
 #define EDIT_UNKNW12  0x2302
 #define EDIT_UNKNW13  0x3000
 #define EDIT_UNKNW14  0xAFFF

  //>------ sub defines of EDIT_OBJECT
 #define OBJ_TRIMESH   0x4100
 #define OBJ_LIGHT     0x4600
 #define OBJ_CAMERA    0x4700

 #define OBJ_UNKNWN01  0x4010
 #define OBJ_UNKNWN02  0x4012 //>>---- Could be shadow

 //>------ sub defines of OBJ_CAMERA
 #define CAM_UNKNWN01  0x4710
 #define CAM_UNKNWN02  0x4720

 //>------ sub defines of OBJ_LIGHT
 #define LIT_OFF       0x4620
 #define LIT_SPOT      0x4610
 #define LIT_UNKNWN01  0x465A

 //>------ sub defines of OBJ_TRIMESH
 #define TRI_VERTEXL   0x4110
 #define TRI_FACEL2    0x4111
 #define TRI_FACEL1    0x4120
 #define TRI_MATERIAL  0x4130
 #define TRI_MAPPING   0x4140
 #define TRI_SMOOTH    0x4150
 #define TRI_LOCAL     0x4160
 #define TRI_VISIBLE   0x4165

 //>>------ sub defs of KEYF3DS

 #define KEYF_UNKNWN01 0xB009
 #define KEYF_UNKNWN02 0xB00A
 #define KEYF_FRAMES   0xB008
 #define KEYF_OBJDES   0xB002

 //>>------  these define the different material chunk types

 #define MAT_NAME	   0xA000
 #define MAT_AMBIENT   0xA010
 #define MAT_DIFFUSE   0xA020
 #define MAT_SPECULAR  0xA030
 #define MAT_SHININESS 0xA040
 #define MAT_TRANS	   0xA050
 #define MAT_TEXTURE1  0xA200
 #define MAT_TEXTURE2  0xA33A

 #define TEX_FILENAME  0xA300
 //>>------  these define the different color chunk types

 #define COL_TRU  0x0010
 #define COL_RGB  0x0011
 #define COL_TRUC 0x0012
 #define COL_RGBC 0x0013

 //>>------ define percent chunks (these are common)

 #define PER_FLOAT	0x0031
 #define PER_INT	0x0030

 //>>------ defines for viewport chunks

 #define TOP           0x0001
 #define BOTTOM        0x0002
 #define LEFT          0x0003
 #define RIGHT         0x0004
 #define FRONT         0x0005
 #define BACK          0x0006
 #define USER          0x0007
 #define CAMERA        0x0008 // 0xFFFF is the actual code read from file
 #define LIGHT         0x0009
 #define DISABLED      0x0010
 #define BOGUS         0x0011

bool ReadColor(Parser3DS &parser, TVisColor *viscolor)
{
	Vector3DS Vector;
	unsigned char RGB[3];
	Chunk3DS chunk;
	TColor color;

	if(!Read3dsChunk(parser, &chunk))
		return false;
	switch(chunk.ID)
	{
	case COL_RGB:
		ReadPtr(parser, &RGB, 3 * sizeof(char));
		color = (TColor)((RGB[2] << 16) + (RGB[1] << 8) + RGB[0]);
		break;
	case COL_RGBC:
		ReadPtr(parser, &RGB, 3 * sizeof(char));
		color = (TColor)((RGB[2] << 16) + (RGB[1] << 8) + RGB[0]);
		break;
	case COL_TRU:
		ReadPtr(parser, &Vector, sizeof(Vector3DS));
		color = (TColor)((int)Vector.Z << 16 + (int)Vector.Y << 8 + (int)Vector.X);
		break;
	case COL_TRUC:
		ReadPtr(parser, &Vector, sizeof(Vector3DS));
		color = (TColor)((int)Vector.Z << 16 + (int)Vector.Y << 8 + (int)Vector.X);
		break;
	default:
		return false;
	}
	viscolor->Color = color;
	viscolor->Alpha = 255;
	return true;
}

bool ReadPercent(Parser3DS &parser, float &percent)
{
	Vector3DS vector;
	unsigned short ipercent;
	Chunk3DS chunk;
	TColor color;

	if(!Read3dsChunk(parser, &chunk))
		return false;
	switch(chunk.ID)
	{
	case PER_FLOAT:
		ReadPtr(parser, &percent, sizeof(float));
		break;
	case PER_INT:
		ReadPtr(parser, &ipercent, sizeof(unsigned short));
		percent = ipercent;
		break;
	default:
		return false;
	}
	return true;
}

AnsiString ReadTextureFileName(Parser3DS &parser)
{
	static AnsiString name;
	Chunk3DS chunk;

	name = "";

	while(!Read3dsChunk(parser, &chunk) &&
			(parser.Chunks[parser.Chunks.size()-2].ID == MAT_TEXTURE1 ||
			 parser.Chunks[parser.Chunks.size()-2].ID == MAT_TEXTURE2))
	{

	}
	switch(chunk.ID)
	{
	case TEX_FILENAME:
		name = ReadStringZ(parser);
	}
	return name;
}

void Read3DS(std::vector<TVisPrimitiveObj*> &Objects, std::vector <Vismat::TVisMaterial*> &Materials ,
			std::vector <AnsiString> &Textures, FILE *F)
{
	Parser3DS parser;
	TVisPrimitiveArray *currentSubObject = NULL;
	TVisPrimitiveObj *Obj = NULL;
	Vismat::TVisMaterial *currentMaterial = NULL;
	Visclass::TVisColor *visColor = new TVisColor();
	TVisPointItem	*point = new TVisPointItem;
	TVisTexture *currentTexture = NULL;
	long vertexBase = 0;
	unsigned short count, i, nVertices = 0, nObjectMaterials = 0;
	int subsetNr;
	bool vertsExpanded;
	unsigned short A, B, C, flags; // That will be indices and flags of a face
	std::vector<unsigned int> indices;
	Vector3DS Vector;
	Chunk3DS chunk;
	AnsiString name, matname, texfname;
	Graphics::TBitmap *bitmap;
	float percent;

	TVisMathVector vertex;
	TVisMathVector normal;
	TVisMathVector texcoord;

	for(i = 0; i < 3; i ++)
	{
		vertex.a[i] = normal.a[i] = texcoord.a[i] = 0;
	}

	parser.File = F;

	while(Read3dsChunk(parser, &chunk))
	{
		switch(chunk.ID)
		{
		case EDIT_OBJECT:
			// First of all, let's read object's name
			name = ReadStringZ(parser);
			/* PASS THROUGH */
		case MAIN3DS:
		case EDIT3DS:
		case EDIT_MATERIAL:
		case MAT_TEXTURE1:
		case MAT_TEXTURE2:
			// We shouldn't skip them as they incapsulate all needed information,
			// But also we have nothing to read there, so we just go back to read
			// all their subchunks
			// Note, that EDIT OBJECT can incapsulate not only TRIMESH objects,
			// but also Lights and cameras which are not needed here.
			// We will handle such a cases later when discover Light and/or camera chunk.
			continue;
			// doesn't need break, does it?
		case OBJ_LIGHT:
		case OBJ_CAMERA:
			// These types of objects are not needed here, so we'll skip the whole
			// EDIT_OBJECT chunk that we are in
			SkipChunk(parser, ChunkIndex(parser, EDIT_OBJECT));
			break;
		case OBJ_TRIMESH:
			// Here is the beginning of the main troubles - now we should read
			// the whole trimesh (but OBJ_TRIMESH itself does                            n't contain any info)
			// Now, when we're sure that we are reading triangle mesh, we should
			// initialize new TVisPrimitiveArray instance.
			vertsExpanded = false; // signals that we have not expanded vertices yet
			vertexBase = 0; // Advance vertex base
			nVertices = 0; // We don't know yet how much points actually is there...
			nObjectMaterials = 0;

			if(Obj != NULL)
			{
				//Obj->Points->ScalePoints(0.01, 0.01, 0.01);
				Obj->CalcNormals();
				Objects.push_back(Obj);
				Obj = NULL;
			}
			Obj = new TVisPrimitiveObj(NULL); // Adding new object!
			Obj->Init();
//			Obj->Alias = name; // We've already read name...
			indices.resize(0);

			continue;
		case TRI_VERTEXL:
			// All vertices are stored in TVisPrimitiveObject. Because of it, we
			// have a vertexBase variable, that holds a number of vertices which are aready
			// read.
			if(ReadPtr(parser, &count, sizeof(unsigned short)))
			{
				nVertices = count;
				for(i = 0; i < count; i ++)
				{
					ReadPtr(parser, &Vector, sizeof(Vector3DS)); // read vector
					if(Obj->Points->Count < (vertexBase + nVertices))
					{
						// We have not yet read this object's points.
						Obj->Points->Add(vertex, normal, texcoord);
					}
					// Points are already read (probably from TRI_MAPPING chunk)
					// so we just need to modify them
					Obj->Points->GetPoint(vertexBase + i, point);
					point->Point->X = (GLfloat)Vector.X;
					point->Point->Y = (GLfloat)Vector.Y;
					point->Point->Z = (GLfloat)Vector.Z;
					Obj->Points->SetPoint(vertexBase + i, point);
				}
			}
			else
			{
				// Failed to read number of vertices
				SkipCurrentChunk(parser);
			}
			break;
		case TRI_MAPPING:
			// All vertices are stored in TVisPrimitiveObject. Because of it, we
			// have a vertexBase variable, that holds a number of vertices which are aready
			// read.
			if(ReadPtr(parser, &count, sizeof(unsigned short)))
			{
				nVertices = count;
				for(i = 0; i < count; i ++)
				{
					Vector.Z = 0;
					ReadPtr(parser, &Vector, sizeof(float) * 2); // read 2 of 3 vector components.
					if(Obj->Points->Count < (vertexBase + nVertices))
					{
						// We have not yet read this object's points, so add dummy point
						Obj->Points->Add(vertex, normal, texcoord);
					}
					// Modify the point
					Obj->Points->GetPoint(vertexBase + i, point);
					point->Texture->X = Vector.X;
					point->Texture->Y = Vector.Y;
					point->Texture->Z = 0; // That's 2d texturing coords
					Obj->Points->SetPoint(vertexBase + i, point);
				}
				Obj->Points->DefineArrays << daTexture;
			}
			else
			{
				// Failed to read number of vertices
				SkipCurrentChunk(parser);
			}
			break;
		case TRI_FACEL1:
			// Read list of indices
			// List of indices consist of 3 points
			if(ReadPtr(parser, &count, sizeof(unsigned short)))
			{
				for(i = 0; i < count; i ++)
				{
					ReadPtr(parser, &A, sizeof(unsigned short));
					ReadPtr(parser, &B, sizeof(unsigned short));
					ReadPtr(parser, &C, sizeof(unsigned short));
					ReadPtr(parser, &flags, sizeof(unsigned short));

					// Add indices to the indices list.
					indices.push_back(A);
					indices.push_back(B);
					indices.push_back(C);
				}
			}
			else
			{
				// Failed to read number of indices
				SkipCurrentChunk(parser);
			}
			break;
		case TRI_MATERIAL:
			// Read SZ Material name
			matname = ReadStringZ(parser);
			if(ReadPtr(parser, &count, sizeof(unsigned short)))
			{
				if(count > 0)
				{
					nObjectMaterials ++;
					subsetNr = Obj->AddPrimitiveArray(GL_TRIANGLES);
//					Obj->Primitive[subsetNr]->MaterialName = matname;
				}
				for(i = 0; i < count; i ++)
				{
					ReadPtr(parser, &A, sizeof(unsigned short));
					// Add 3 indices of read face to the new subset
					Obj->AddIndex(indices[A * 3 + 0], subsetNr);
					Obj->AddIndex(indices[A * 3 + 1], subsetNr);
					Obj->AddIndex(indices[A * 3 + 2], subsetNr);
				}
				// Subset is read and added so well...
			}
			else
			{
				// Failed to read number of indices
				SkipCurrentChunk(parser);
			}
			break;

		// ------ Well, geometry is read, now go ahead to read materials...
		case MAT_NAME:
			if(currentMaterial != NULL)
			{
				Materials[Materials.size()-1] = currentMaterial;
			}
			Materials.resize(Materials.size()+1);
			Textures.resize(Materials.size()+1);
			currentMaterial = new Vismat::TVisMaterial(NULL);
			visColor->Color = 0;
			visColor->Alpha = 255;
			currentMaterial->ColorAmbient = visColor;
			currentMaterial->ColorDiffuse = visColor;
			currentMaterial->ColorSpecular = visColor;
//			currentMaterial->Alias = ReadStringZ(parser);
			break;
		case MAT_AMBIENT:
			ReadColor(parser, visColor);
			if(currentMaterial)
				currentMaterial->ColorAmbient = visColor;
			break;
		case MAT_SPECULAR:
			ReadColor(parser, visColor);
			if(currentMaterial)
				currentMaterial->ColorSpecular = visColor;
			break;
		case MAT_DIFFUSE:
			ReadColor(parser, visColor);
			if(currentMaterial)
				currentMaterial->ColorDiffuse = visColor;
			break;
		case MAT_TRANS:
			ReadPercent(parser, percent);
			if(currentMaterial)
				currentMaterial->ColorDiffuse->Alpha = 1 - percent / 100;
			break;
		case MAT_SHININESS:
			ReadPercent(parser, percent);
			if(currentMaterial)
				currentMaterial->Shininess = percent;
			break;
		case TEX_FILENAME:
			if((parser.Chunks[parser.Chunks.size()-2].ID != MAT_TEXTURE1) &&
				(parser.Chunks[parser.Chunks.size()-2].ID != MAT_TEXTURE2))
				break;
			texfname = ReadStringZ(parser);
			Textures[Materials.size()-1] = texfname;
			break;
		default:
			SkipCurrentChunk(parser);
		}
	}
	if(Obj != NULL)
	{
		//Obj->Points->ScalePoints(0.01, 0.01, 0.01);
		Obj->CalcNormals();
		Objects.push_back(Obj);
	}
	if(currentMaterial != NULL)
	{
		Materials[Materials.size()-1] = currentMaterial;
	}
	for(i = 0; i < Objects.size(); i ++)
	{
		for(int j = 0; j < Objects[i]->PrimitiveCount; j ++)
		{
			for(int k = 0; k < Materials.size(); k ++)
			{
/*				if(Objects[i]->Primitive[j]->MaterialName == Materials[k]->Alias)
				{
					Objects[i]->Primitive[j]->Material = Materials[k];
				}*/
			}
		}
	}
	delete visColor;
	delete point;
}

std::vector<TVisPrimitiveObj *> LoadFromFile(AnsiString fname)
{
	FILE *f = NULL;
	std::vector<TVisPrimitiveObj*> objs;
	std::vector<TVisMaterial*> materials;
	std::vector<AnsiString> textures;
	f = fopen(fname.c_str(), "rb");
	if(f)
	{
		Read3DS(objs, materials, textures, f);
	}
	fclose(f);
	return objs;
}

