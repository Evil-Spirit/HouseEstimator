//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ArchitectElementV.h"
#include "WallV.h"
#include "PlatformV.h"
#include "MyGL.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TMyObject* TMetaArchitectElement::CreateFunction()
{
    return new TMetaArchitectElement();
}


TMetaArchitectElement::TMetaArchitectElement()
{
    RegisterNewClass< TMetaElement, TMetaArchitectElement >(this,false,&CreateFunction);
}


TMyObject* TArchitectElement::CreateFunction()
{
    return new TArchitectElement();
}


TArchitectElement::TArchitectElement()
{
    RegisterNewClass< TElement, TArchitectElement >(this,false,&CreateFunction);
}


void TArchitectElement::HoleInMeFor(TElement* El, TPolygon* Hole)
{
    int Normal = -1;
    if (typeid(*this)==typeid(TCube))
        Normal = ((TCube*)this)->MetaCube->HoleNormal;
    else if (typeid(*this) == typeid(TPlatform))
        Normal =  2;
    if (Normal == -1)
        return;
    int HN[3];
    HN[0] = (Normal+1)%3;
    HN[1] = (Normal+2)%3;
    HN[2] = Normal;

    Hole->Clear();
    if (typeid(*El) == typeid(TPlatform) || Normal == 2)
    {
        if (Normal != 2)
            return;
        if (typeid(*El) == typeid(TPlatform))
            Hole->Assign(El->HP);
        else
        {
            Hole->Vertex->Add(new TIntVec(   El->AbsSize.x/2,   El->AbsSize.y/2,0));
            Hole->Vertex->Add(new TIntVec( - El->AbsSize.x/2,   El->AbsSize.y/2,0));
            Hole->Vertex->Add(new TIntVec( - El->AbsSize.x/2, - El->AbsSize.y/2,0));
            Hole->Vertex->Add(new TIntVec(   El->AbsSize.x/2, - El->AbsSize.y/2,0));
        }
        for (int i=0;i<Hole->Vertex->Count;i++)
            El->AbsFromLocal(*(Hole->Vertex->Items[i]),*(Hole->Vertex->Items[i]));
        for (int i=0;i<Hole->Vertex->Count;i++)
            LocalFromAbs(*(Hole->Vertex->Items[i]),*(Hole->Vertex->Items[i]));
    }
    else
    {
        TIntVec SDVIG = El->AbsPos-AbsPos;
        SDVIG=RotateAround(SDVIG,AbsAngle*(-1),ZEROINTVEC);
        Hole->Vertex->Add(new TIntVec(   El->AbsSize.x/2 + SDVIG.x,   El->AbsSize.z/2 + SDVIG.z,0));
        Hole->Vertex->Add(new TIntVec( - El->AbsSize.x/2 + SDVIG.x,   El->AbsSize.z/2 + SDVIG.z,0));
        Hole->Vertex->Add(new TIntVec( - El->AbsSize.x/2 + SDVIG.x, - El->AbsSize.z/2 + SDVIG.z,0));
        Hole->Vertex->Add(new TIntVec(   El->AbsSize.x/2 + SDVIG.x, - El->AbsSize.z/2 + SDVIG.z,0));
    }
}


