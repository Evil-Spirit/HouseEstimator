//---------------------------------------------------------------------------

#ifndef MyRegTreeVH
#define MyRegTreeVH
//---------------------------------------------------------------------------

class COMMONAL_API TMyRegTree : public TMyObject{
private:
protected:
    void RecurrentLoad(TMyRegObject *Node,FILE *F);
    void RecurrentSave(TMyRegObject *Node,FILE *F) const;
    void RecurrentRead(TMyRegObject *Node,TMemoryStream *MS);
    void RecurrentWrite(TMyRegObject *Node,TMemoryStream *MS) const;
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    void RecurrentFillTreeView(TMyRegObject *Node,TTreeView *TreeView);
    TMyRegObject *Head;
    TMyRegTree();
    virtual ~TMyRegTree();
    virtual TMyRegObject *AddChild(TMyRegObject *Node,TMyRegObject *NewNode);
    void LoadData(FILE *F);
    void SaveData(FILE *F) const;
    bool CheckFields();
    bool CheckData(TMyRegObject *Node);
    void SelectByCT(TMyRegObject *Node, TClassNode* CN,TMTList<TMyRegObject> *List,bool self,bool Childs) const;
    void FillTreeView(TTreeView *TreeView);
    virtual void OnAddNode(TMyRegObject* Target,TMyRegObject* Source){};
    void GetLookingTo(TMyRegObject *Node,TMyRegObject *MyRegObject,TMTList<TMyObject>& OBJL) const;
    void WriteData(TMemoryStream *MS) const;
    void ReadData(TMemoryStream *MS);
};
extern COMMONAL_API TClassNode* TMyRegTree::StaticType;

#endif
