// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ComposeV_H
#define ComposeV_H
//---------------------------------------------------------------------------
class TLPoint;
class TLCut;
class TPolygon;
__declspec(dllexport)  void Composing(TMDelTList<TLPoint>& Pnts,TMDelTList<TLCut>& Cuts,TMDelTList<TPolygon>& POLS);
#endif
