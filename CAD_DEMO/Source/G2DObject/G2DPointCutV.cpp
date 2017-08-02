//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DPointCutV.h"
#include "G2DFunctionsV.h"
#include "G2DFunctionsV.h"
#include "MyGL.h"
#include "math.h"
#include "G2DObjectV.h"
#include "Poligon.h"
#include "Math.hpp"
#include "G2DApproxCalcV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TG2DCut::StaticType = NULL;
TClassNode* TG2DPoint::StaticType = NULL;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TG2DCut::TG2DCut()
{
    RegisterNewClass<TGCut,TG2DCut>(this,false,&CreateFunction);
    FFixed = false;
}

TMyObject* TG2DCut::CreateFunction()
{
    return new TG2DCut();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TMyObject* TG2DPoint::CreateFunction()
{
    return new TG2DPoint();
}

TG2DPoint::TG2DPoint()
{
    RegisterNewClass<TGPoint,TG2DPoint>(this,false,&CreateFunction);
    FFixed = false;
}

bool TG2DPoint::Update()
{
    //---------------------------------
    if ( Rules.Count == 2 )
    {
        TMDelTList<TIntVec> CPS;
        CrossPointsOf(Rules[0],Rules[1],CPS,_MBTi_eps_);
        if (CPS.Count==1)
            Point = CPS[0];
        else if (CPS.Count==2)
            Point = ( (Point-CPS[0]).Length() < (Point-CPS[1]).Length() ) ? CPS[0] :CPS[1];
        else
            return false;            
    }
    else if ( Rules.Count == 1 )
        Point = MovePointTo( Point, Rules[0] );
    else if ( Rules.Count > 2 )
        return false;

    return true;        
}


