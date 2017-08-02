//---------------------------------------------------------------------------

#ifndef DelegateEventVH
#define DelegateEventVH
//---------------------------------------------------------------------------
class TPublisherPointer  : public TMyObject {
public:
    TPointer<TMyRegObject> MRO;

};

class THandlerPointer  : public TMyObject {
public:

};

class TEventPublisher : public TMyObject {
public:
    int ID;
//    TMDelTList< TPointer<TMyRegObject> >
  //  TPointer<TMyRegObject>
    TEventPublisher(){};
};

class TEventHandler : public TMyObject {
public:
    int ID;
    //TMDelTList< TPointer<TMyRegObject> > Publishers;

};
#endif
