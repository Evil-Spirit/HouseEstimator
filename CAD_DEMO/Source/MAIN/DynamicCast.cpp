// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------


#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "DynamicCast.h"
#include "MultiElementV.h"
#include "WallV.h"
#include "RoomV.h"
#include "PlatformV.h"
#include "CustomElementV.h"
#include "Label3DV.h"

//---------------------------------------------------------------------------




TCube* ToCube(TMyObject* Obj)
{
    return MyCast<TCube>(Obj);
/*    if (Obj == NULL)
        return NULL;
    if ( Obj->Is(TCube::StaticType) )
        return (TCube*)Obj;
    else
        throw EMyException("Íåâîçìîæíî ïðåîáðàçîâàíèå â 'TCube'"); */
}

TRoom* ToRoom(TMyObject* Obj)
{
    return MyCast<TRoom>(Obj);
}

TMetaTexture* ToMetaTexture(TMyObject* Obj)
{
    return MyCast<TMetaTexture>(Obj);
}

TMetaMaterial* ToMetaMaterial(TMyObject* Obj)
{
    return MyCast<TMetaMaterial>(Obj);
}

TMultiElement* ToMultiElement(TMyObject* Obj)
{
    return MyCast<TMultiElement>(Obj);
}

TPlatform* ToPlatform(TMyObject* Obj)
{
    return MyCast<TPlatform>(Obj);
}

TElement* ToElement(TMyObject* Obj)
{
    return MyCast<TElement>(Obj);
}

//---------------------------------------------------------------------------
TMetaElement* ToMetaElement(TMyObject* Obj)
{
    return MyCast<TMetaElement>(Obj);
}

TMetaLink* ToMetaLink(TMyObject* Obj)
{
    return MyCast<TMetaLink>(Obj);
}

TDynamicLink* ToDynamicLink(TMyObject *Obj)
{
    return MyCast<TDynamicLink>(Obj);
}

char* VecToStr(const TIntVec& Vec)
{
    AnsiString* STR = new AnsiString(VecToStrA(Vec));
    Garbage.AddStr(STR);
    return STR->c_str();
//    char* str = StrAlloc(STR.Length()+1);
//    StrCopy(str,STR.c_str());
//    return str;
}

TIntVec StrToVec(char* str)
{
    AnsiString STR = AnsiString(str);
    if (CHECKSTRVEC(STR,false))
        return IntVecFromStr(STR);
    else
        return ZEROINTVEC;
}

TMetaNode* ToMetaNode(TMyObject* Obj)
{
    return MyCast<TMetaNode>(Obj);
}

TPolygon* ToPolygon(TMyObject* Obj)
{
    return MyCast<TPolygon>(Obj);
}


TMyRegObject* ToMyRegObject(TMyObject* Obj)
{
    return MyCast<TMyRegObject>(Obj);
}

