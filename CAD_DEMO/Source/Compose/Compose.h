
#ifndef ComposeH
#define ComposeH

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "..\GeomObject\Poligon.h"

__declspec(dllexport) void ComposePolygon(TPolygon& Pol,TMDelTList<TPolygon>& Pols,TMDelTList< TMDelTList<int> >& Indices);
#endif 
