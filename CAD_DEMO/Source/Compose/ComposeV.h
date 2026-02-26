// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ComposeVH
#define ComposeVH
//---------------------------------------------------------------------------
class TLPoint;
class TLCut;
class TPolygon;
void Composing(TMDelTList<TLPoint>& Pnts,TMDelTList<TLCut>& Cuts,TMDelTList<TPolygon>& POLS);
#endif
