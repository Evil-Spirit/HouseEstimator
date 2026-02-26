// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef InfinityLineVH
#define InfinityLineVH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------

class COMMONAL_API TInfinityLine : public T2DGObject{
public:
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();

    TInfinityLine();
    virtual ~TInfinityLine(){};

//    void Render(TEditor2D* aView);
};

#endif
