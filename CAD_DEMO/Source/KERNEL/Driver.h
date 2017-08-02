//---------------------------------------------------------------------------

#ifndef DriverH
#define DriverH
#include "LinkGeometry.h"
#include "QueueRoutineV.h"

class TElement;
class TDynamicLink;
//---------------------------------------------------------------------------
/*    TIntVec Translate;
    TIntVec Rotate;
    TIntVec Scale;
    TIntVec Scale_Rotate;
*/
//Real Link Types


class COMMONAL_API TObjectAttributePreSet {
public:
    AnsiString AttributeName;
    AnsiString AttributeValue;
    TObjectAttributePreSet();
    virtual ~TObjectAttributePreSet(){};
    TObjectAttributePreSet(char* Name,char* Value);
    void SetAttributeName(char* Name);
    void SetAttributeValue(char* Value);
};

class COMMONAL_API TSyngleLink {
public:
    TSyngleLink(){};
    virtual ~TSyngleLink(){};
    TIntVec CrossPoint;
    TMDelTList<TObjectAttributePreSet> OAPreSet;
};

class COMMONAL_API TLINKPATTERN {
public:
    TLINKPATTERN(){};
    virtual ~TLINKPATTERN(){};
    TDynamicLink *DL;

    TRealLinkTypes RealLinkType;
    
    TIntVec TS_Common;
    TIntVec R_Common;

    TIntVec CrossPoint;
    TIntVec Direction;
    TIntVec RotateCenter;
    TMDelTList<TSyngleLink> SyngleLinks;
};

const int cBest = -2;
const int cNeed = -1;

const int ckSize = 1;
const int ckPos = 2;

bool COMMONAL_API RunLink(TElement* Target,TElement* Source,TLINKPATTERN& SL,int TransMode);

class COMMONAL_API TLINKING {
protected:
public:
    TElement *Target;
    TElement *Source;
    TLINKING(TElement *_Source,TElement *_Target);
    TLINKING();
    virtual ~TLINKING();
    TMDelTList<TLINKPATTERN> Need;
    TMDelTList<TLINKPATTERN> Opt;
    TMDelTList<TLINKPATTERN> Un_Opt;
    TMDelTList<TPoint> OIS;
    int NeedInd;
    void Check();
    void CheckOptionalSizeLinks();
    bool KeepCool(int type,bool Needed);
    void Cut(int type);
    bool ITSOK(bool Needed);
    TElement *_Target(int ind);
    TElement *_Source(int ind);
    TDynamicLink *GetDL(int ind=cNeed);
    TLINKPATTERN& GetSL(int ind=cNeed);
    TIntVec& GetTranslate(int ind=cNeed);
    TIntVec& GetCrossPoint(int ind=cNeed);
    TIntVec& GetRotate(int ind=cNeed);
    TIntVec& GetScale(int ind=cNeed);
    TIntVec& GetScale_Rotate(int ind=cNeed);
    TIntVec& GetDirection(int ind=cNeed);

    void MakePosition(int ind=cNeed);
    void UndoPosition(int ind=cNeed);
    void MakeSize(bool Try,int ind=cNeed);
    void UndoSize(bool Try,int ind=cNeed);
    bool ExistsWallLink();
    bool __fastcall Scale__MyComp(void* item1,void* item2);
    bool __fastcall Translate__MyComp(void* item1,void* item2);
};

const int ocmNone=-1;
const int ocmPosition=0;
const int ocmSize=1;
class TLinkInfo;

class COMMONAL_API TDriver{
private:
    TMTList<TLINKING> *NEED;
    TMTList<TLINKING> *OPT;
    int BestTargetLink;
    int O_E_L_Count;
    TElement* FElement;
    //-----------------------------------------------------
    TMDelTList<TLinkInfo> FPreLinks;
    bool FPreLinksGenerated;
    void GeneratePreLinks();
    int GetPreLinksCount();
    //-----------------------------------------------------
public:
    TMDelTList<TLINKING> *ALL;
    __property TElement *Element = {read = FElement};
    TDriver();
    virtual ~TDriver();
    TElement* FloorElement;
    void Clear();
    void Init(TElement *_Element,bool IgnoreAuto,TElement* UseFloor=NULL);
    bool Check();
    bool CheckOptional(int index);
    bool Stop();
    int CheckBySize(int index);
    int CheckByPosition(int index);
    //-----------------------------
    TIntVec CORRECT_EPS;
    TIntVec CORRECT_ANGLEEPS;
    int MainMode;
    int CorrectMode;
    bool IsNowCorrectMode;
    bool RealizeLinks();
    bool Stoping;
    bool IgnoreAuto;
    int InitCount;
    bool CheckCrossingAfterRealizeLinks();
    //-----------------------------
    TLinkInfo& GetPreLink(int index);
    __property int PreLinksCount = {read = GetPreLinksCount};
    //-----------------------------
};

extern COMMONAL_API TDriver Driver;

class COMMONAL_API TDriverQueue: public TElementQueue {
public:
    TDriverQueue(){};
    ~TDriverQueue(){};
    void OnProcess();
};

extern COMMONAL_API TDriver Driver;
extern COMMONAL_API TDriverQueue* FDriverQueue;
COMMONAL_API TDriverQueue& GetDriverQueue();
#define DriverQueue GetDriverQueue()
#endif
