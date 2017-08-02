//---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH

#include "VisView.hpp"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
class TMyObject;
class TElement;
class TLink;
class TMetaNode;
class TUnit;
class TDrawView;


template <class T> class TMTList;
template <class T> class TMDelTList;
template <class T> class /*TMDelLSTList*/TMDelTList;
template <class T> class TPointer;

/*class TRenderBlock {
    TMTList<TVisRender> *VFIRST;
    TMTList<TVisRender> *VTRANS;
    TMTList<TVisRender> *VLABEL;
    Clear();
    void Add(TElement* El);
    void Remove(TElement* El);
}; */

class COMMONAL_API TFloor: public TMyObject {
private:
    TElement* GetFirstElement();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    //Z - положения этажа
    TFloor();
    virtual ~TFloor();
    MBTi AbsZ;//высота над уровнем пола
    MBTi Height;
    MBTi Up_Lost;
    MBTi Down_Lost;

    TVisNode* VLIGHTS;
    TVisNode *VFIRST;
    TVisNode *VTRANS;
    TVisNode *VLABEL;
    TPointer<TElement> First;
    void Add(TElement *CHTO);
    void Remove(TElement *CHTO);
    void Clear();
    bool Visible;
    __property TElement* FirstElement = {read = GetFirstElement};
};
extern COMMONAL_API TClassNode* TFloor::StaticType;

class COMMONAL_API TFloorInfo {
public:
    int AddIndex;
    int EditIndex;
    char* FloorName;
    MBTi Height;
    MBTi Up_Lost;
    MBTi Down_Lost;
    int FloorFrom;
    bool OK_Pressed;
    TMTList<TMetaNode>* ElToMove;
    TFloorInfo();
    virtual ~TFloorInfo();
};

class TMDI3D;
class TMyMDIChild;

class COMMONAL_API TClient3D{
    public:
    TClient3D(){};
    virtual ~TClient3D(){};
    TMTList<TFloor> Floors;
    TMDelTList<bool> Visible;
    TMDI3D* MDI3D;
    int ActiveIndex;
    bool VisibleAll;
    void Render(TVisCustomView* aView,bool RenderNet);
};

class COMMONAL_API TMainTree :public TMyRegTree{
private:
    void RecurrentSelectByElementLinks(TUnit *Node,TMetaElement *MetaElement,TMTList<TElement> *List);
    void RecurrentSelectByMetaElement(TMyRegObject* RO,TMetaElement* MetaElement,TMTList<TElement>* LST);
//    void RecurrentAddRender(TVisRender *Chto);
    TFloor* GetActiveFloor();
    int GetFloorCount();
    TClient3D* GetActiveClient();
    int GetActiveIndex();
    void SetActiveIndex(int index);
    int FModeIndex;
    int FPrevModeIndex;
public:
    //---------------------------------------------------------------------------
    void UpdateMode(TElement* Element = NULL);
    void UpdateRegCreateView(TElement* Element = NULL);
    //---------------------------------------------------------------------------
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    void EditActiveFloor();
    bool load;
    __property int ModeIndex = {read = FModeIndex};
    __property int PrevModeIndex = {read = FPrevModeIndex};
    bool FloorDeleted();
    bool IsFloorElement(TElement* El);
    bool AskedToSave;
    bool CheckPremises;
    TMDelTList<TClient3D> Clients;
    void RegisterClient(TMDI3D* aView);
    void UnRegisterClient(TMDI3D* aView);
    TClient3D* FindClient(TMDI3D* aView);
    __property TClient3D* ActiveClient = {read = GetActiveClient};
    __property int ActiveIndex = {read = GetActiveIndex, write = SetActiveIndex};



    /*TMDelLSTList*/TMDelTList<TLink> LLS;
    /*TMDelLSTList*/TMDelTList<TMyRegObject> ELS;

    bool RenderLand;
    bool RenderNet;
    TFloorInfo* FloorInfo;
    /*TMDelLSTList*/TMDelTList<TFloor> Floors;
    /*TMDelLSTList*/TMDelTList<TPointer<TElement> > *SERVICE;
    int FloorOf(TElement* El);
    int FloorOfUseDriver(TElement* El);
    __property TFloor* ActiveFloor = {read = GetActiveFloor};
    //Z - положения этажа
    void SelectAllLinks(TElement *Element, TMTList<TLink> *LL);
    void WriteFile(const AnsiString& FileName);
    void ReadFile(const AnsiString& FileName);
    TMainTree();
    virtual ~TMainTree();
    TElement *AddFirst(TElement *_Head);
    TElement *AddElement(TElement *Target,TElement *Float);
    void RemoveElement(TElement *Float);
    void SelectByElementLinks(TElement *Element,TMTList<TElement> *List);
    void LOW_HI(TIntVec& LOW,TIntVec& HI,bool No_Platforms,TUnit *Node,bool VisibleOnly);
    void Render(TVisCustomView *aView);
    void Clear();
    void Process_AddElement(TMetaElement *Mel,TElement* UseFloorElement);
    //return this
    //-------------------------------------------------------------------------
    void AutoConnect(TElement * Target, TElement * Source);
    TLink* Connect(TElement * Target, TElement * Source,TDynamicLink *_HardLink);
    virtual void OnAddNode(TMyRegObject* Target,TMyRegObject* Source);
    bool CheckFields();
    bool Init();
    //------------------------------------------------------------------------
    void CompleteToBuffer(TMyRegObject *Node,TMemoryStream *MS);
    void CompleteFromBuffer(TMemoryStream *MS);
    //--------------------------------------------------------------------------
    void Render2D(TDrawView *DrawView);
    virtual TMyRegObject *AddChild(TMyRegObject *Node,TMyRegObject *NewNode);
    bool AddFloor(int index=-1);
    void RemoveFloor(int index);
    int IndexOfFloor(TFloor* Floor);
    //--------------------------------------------------------------------------
    __property int FloorCount = {read = GetFloorCount};
    TFloor* GetFloor(int i);
//    bool SelectByClassName(int Floor,char* classname,bool childs);
    bool SelectByMetaElement(int Floor,TMetaElement* MetaElement,TMTList<TElement>* LST);
    void SetActiveFloor(int i);
    bool TechCheck(AnsiString& Str);
    void SizerList(int FloorIndex,const TMDelTList<T3DScope>& SZR);
    void ReFillElements();
    //----------------------
    void CompleteToBufferUndo(TMTList<TMyRegObject>& Parents,TMemoryStream *MS);
    void CompleteFromBufferUndo(TMemoryStream *MS);

};

extern COMMONAL_API TClassNode* TMainTree::StaticType;

bool COMMONAL_API GoDriver(TElement * Source,TElement* FloorElement=NULL);

extern COMMONAL_API TMainTree* World;

TDynamicLink* COMMONAL_API GetLinkAnyWay(TMetaElement* MetaTarget,TMetaElement* MetaSource);
#endif
