//---------------------------------------------------------------------------

#ifndef MetaNodeCollectionVH
#define MetaNodeCollectionVH
#include "MyRegTreeV.h"
//---------------------------------------------------------------------------
class TMetaNode;
class TMySupport;
class TDynamicLink;
class TMetaElement;

class TMySupport;
class TKernelSupport;

class COMMONAL_API TMetaNodeCollection  :public TMyRegTree{
private:
    void RecurrentFillMenuItem(TMetaNode *Node,TMenuItem *MenuItem,Classes::TNotifyEvent Event);
    void RecurrentAllowedParents(TMTList<TMetaNode> *MNL,TMetaNode *Where,TMetaNode *IN,TMetaNode* For);
    TMetaNode *CreateMetaFunction(TMetaNode *Owner,const AnsiString& NeedCT,int _ID, const AnsiString& _Name, bool IsNew=false);
    TKernelSupport* GetKernelSupport();
public:
    __property TKernelSupport* KernelSupport = {read = GetKernelSupport};
    static TQuickList TypesToEdit;
    TMDelTList<TMySupport> Supports;
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaNodeCollection();
    virtual ~TMetaNodeCollection(){};
    void Load();
    bool Save();
    void Read();
    bool Write();
    void FillMenuItem(TMenuItem *MenuItem,Classes::TNotifyEvent Event);
    TMetaNode *AddGroup(TMetaNode *Node,int _ID,const AnsiString& _Name);
    TMetaNode *AddMetaChild(TMetaNode *Node,AnsiString NeedCT,int _ID,const AnsiString& _Name,bool load=true);
    void FillToolBar(TMetaNode *MN,TToolBar *TB,TMouseEvent Down,TMouseMoveEvent Move,TMouseEvent Up);
    void RefreshToolBar(TMetaNode *MN,TToolBar *TB);
    //---------------------------------------------------------------------------
    TDynamicLink *FreeLink(TMetaElement * Target, TMetaElement * Source);
    void AllowedParents(TMetaNode *For,TMTList<TMetaNode> *MNL);
    void LoadContextMD(FILE * F);
    void SaveContextMD(FILE * F);
    void WriteContextMD(TMemoryStream *MS);
    void ReadContextMD(TMemoryStream *MS);
    void OnAddNode(TMyRegObject* Node, TMyRegObject* NewNode);
    void Validate();
    void FillModes(TPopupMenu *PM,Classes::TNotifyEvent Event);
    TMetaNode* FindMDByName(char* name);
    TMetaNode* FindMDByGUID(char* GUID);
    TMetaNode* FindParent(const AnsiString& Class);
    void PreProcessActions();
    void AfterProcessActions();
    AnsiString SelectClassIfNeed(const AnsiString& VirtualClass );
};

extern COMMONAL_API TQuickList TMetaNodeCollection::TypesToEdit;

extern COMMONAL_API TClassNode* TMetaNodeCollection::StaticType;

extern COMMONAL_API TMetaNodeCollection *MetaNodeCollection;

AnsiString COMMONAL_API SelectClass(TMTList<TClassNode> *L);



#endif
 