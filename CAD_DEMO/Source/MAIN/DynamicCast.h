// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef DynamicCastH
#define DynamicCastH
//---------------------------------------------------------------------------
class TMetaElement;
class TElement;
class TPlatform;
class TMetaLink;
class TDynamicLink;
class TMultiElement;
class TMetaNode;
class TPolygon;
class TRoom;
class TCube;
class TMyRegObject;
class TMetaTexture;
class TMetaMaterial;


template <class T>
T* MyCast(TMyObject* Obj)
{
    if (Obj == NULL)
        return (T*)NULL;
    if ( Obj->Is(T::StaticType) )
        return (T*)Obj;
    else
    {
        AnsiString Str = "Îáúåêò êëàññà <";
        Str = Str + Obj->DynamicType->Name;
        Str = Str + AnsiString("> Could not convert to <");
        Str = Str + T::StaticType->Name + AnsiString(">");
        throw EMyException(Str);
    }
}

TCube* ToCube(TMyObject* Obj);
TRoom* ToRoom(TMyObject* Obj);


TMultiElement* ToMultiElement(TMyObject* Obj);
TMyRegObject* ToMyRegObject(TMyObject* Obj);
TPlatform* ToPlatform(TMyObject* Obj);
TElement* ToElement(TMyObject* Obj);

TMetaElement* ToMetaElement(TMyObject* Obj);
TMetaLink* ToMetaLink(TMyObject* Obj);
TDynamicLink* ToDynamicLink(TMyObject *Obj);

TMetaNode* ToMetaNode(TMyObject* Obj);
TPolygon* ToPolygon(TMyObject* Obj);

TMetaTexture* ToMetaTexture(TMyObject* Obj);
TMetaMaterial* ToMetaMaterial(TMyObject* Obj);


char* VecToStr(const TIntVec& Vec);
TIntVec StrToVec(char* str);

#endif
