// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef TGUnitVH
#define TGUnitVH
#include "VisLabel.hpp"
#include "VisView.hpp"
#include "VisPrimitiveObj.hpp"
#include "VisCanvasView.hpp"

//---------------------------------------------------------------------------
#pragma option push -b-
enum TLinkDirection {ld0To1,ld1To0};
#pragma option pop


class TGUnit;

class COMMONAL_API TGBaseLink : public TMyObject {
protected:
    TPointer<TGUnit> FClients[2];
    void SetClient(int index,TGUnit* Client);
    TGUnit* GetClient(int index);
    TVisPrimitiveObj* VCO;
public:
    TVisLabel* Label;
    TLinkDirection LinkDirection;
    TIntVec Position;
    TGBaseLink();
    virtual ~TGBaseLink();
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    __property TGUnit* Client0 = {read = GetClient,write = SetClient,index = 0};
    __property TGUnit* Client1 = {read = GetClient,write = SetClient,index = 1};
    virtual void Render(TVisView* aView){};
    TGUnit* AnotherClient(TGUnit* aClient);
    virtual bool ConsistsClient(TGUnit* aClient);
    bool Visible;
};


class COMMONAL_API TGUnit : public TMyObject {
protected:
    TMDelTList< TPointer<TGBaseLink> > FLinks;
    int GetLinksCount() const;
    bool GetFixed();
    void SetFixed(bool Value);
    bool FFixed;
public:
    TGUnit();
    virtual ~TGUnit();
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    // __property int LinksCount {read=GetLinksCount}; // [manual migration needed]
    TGBaseLink& GetLink(int index);
    const TGBaseLink& GetLink(int index) const;
    int Remove( TGBaseLink* aGLink);
    int Add( TGBaseLink* aGLink);
    // __property bool Fixed {read=GetFixed, write=SetFixed}; // [manual migration needed]

};

AnsiString COMMONAL_API MBTiToStrF(MBTi Value,int Precision);
#endif
