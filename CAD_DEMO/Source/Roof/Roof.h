
#ifndef RoofH
#define RoofH

#include "Usefuls.h"
#include "MTL.h"
#include "Poligon.h"

#include "MyTemplates.h"
class TGeomObject;
__declspec(dllexport) class TLuaRoofCut{
public:
    TLuaRoofCut(){Slope0=-1;Slope1=-1;};
    virtual ~TLuaRoofCut(){};
    TIntVec LOW;
    TIntVec HI;
    int Slope0;
    int Slope1;
};

__declspec(dllexport) void CreateRoofOld(   TMDelTList<TIntVec>* RoofPolygon,
                                            TMDelTList<TIntVec>* Param,
                                            TMDelTList<TPolygon>* RES,
                                            TMDelTList<TLuaRoofCut>* FLEGS,
                                            TMDelTList<TLuaRoofCut>* FSCATES);

__declspec(dllexport) void CreateRoof(  TMDelTList< TMDelTList<TIntVec> >& pp_N, //контур крыши
										TMDelTList< TMDelTList<TIntVec> >& pp_O, //список векторов параметров (x - угол,y - выступ карниза в случае фронтона)
										TIntVec& b_N,
										TIntVec& b_O,
										TMDelTList< TMDelTList<TPolygon> >& RES,  //результат работы список полигонов
										TMDelTList<TLuaRoofCut>& FLEGS, //список ендов
                                        TMDelTList<TLuaRoofCut>& FSCATES);   //список коньков

__declspec(dllexport) void ConstructRoof(  TMDelTList< TMDelTList<TIntVec> >& pp_N, //контур крыши
										TMDelTList< TMDelTList<TIntVec> >& pp_O, //список векторов параметров (x - угол,y - выступ карниза в случае фронтона)
										TIntVec& b_N,
										TIntVec& b_O,
										TGeomObject& GO);
										
#endif 
