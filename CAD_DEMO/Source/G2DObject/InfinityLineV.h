//---------------------------------------------------------------------------

#ifndef InfinityLineVH
#define InfinityLineVH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------

class COMMONAL_API TInfinityLine : public T2DGObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();

    TInfinityLine();
    virtual ~TInfinityLine(){};

//    void Render(TEditor2D* aView);
};

extern COMMONAL_API TClassNode* TInfinityLine::StaticType;
#endif
