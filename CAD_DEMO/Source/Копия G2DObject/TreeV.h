//---------------------------------------------------------------------------

#ifndef TreeVH
#define TreeVH
//---------------------------------------------------------------------------

/*template <class T>
class TMTreeNode {
private:
	TMTreeNode<T> *FParent;
	TMTList < TMTreeNode<T> > FChildren;
    int GetChildCount();
public:

	T *Data;

	TMTreeNode();
	~TMTreeNode(){};
	void SetParent(TMTreeNode *aParent);
	TMTreeNode* GetParent();
	__property TMTreeNode *Parent = {read = GetParent, write = SetParent};
    TMTreeNode<T>* GetChild(int index);
    int AddChild(TMTreeNode<T>* NewChild);
};

template <class T>
class TMTree {
private:
	TMTreeNode<T> *FHead;
public:
	TMDelTList< TMTreeNode<T> > Nodes;
    TMTree();
    ~TMTree(){};
	TMTreeNode<T>* AddNode(TMTreeNode<T> *aParent, T *aData );
	TMTreeNode<T>* FindByData(T *aData );
};

template <class T>
TMTreeNode<T>::TMTreeNode()
{
    FParent = NULL;
    Data = NULL;
}

template <class T>
void TMTreeNode<T>::SetParent(TMTreeNode<T> *aParent)
{
    if (FParent)
        FParent->FChildren.Remove(this);
    FParent = aParent;
    if (!FParent)
        return;
    FParent->FChildren.Add(this);
};

template <class T>
TMTreeNode<T>* TMTreeNode<T>::GetParent()
{
    return FParent;
}


template <class T>
int TMTreeNode<T>::GetChildCount()
{
    return Children.Count;
}

template <class T>
TMTreeNode<T>* TMTreeNode<T>::GetChild(int index)
{
    return Children.Items[index];
}

template <class T>
int TMTreeNode<T>::AddChild(TMTreeNode<T>* NewChild)
{
    NewChild->Parent = this;
}

//---------TMTree-------------------------------------------------------------
template <class T>
TMTree<T>::TMTree()
{
    FHead = NULL;
}

template <class T>
TMTreeNode<T>* TMTree<T>::AddNode(TMTreeNode<T> *aParent, T *node )
{
    if (aParent == NULL)
    {
        FHead = NULL;
        Nodes.Clear();
    }
    Nodes.Add(new TMTreeNode<T>);
    Nodes.Last()->Parent = aParent;
    Nodes.Last()->Data = node;
    if (aParent == NULL)
         FHead = Nodes.Last();
    return Nodes.Last();
}

template <class T>
TMTreeNode<T>* TMTree<T>::FindByData(T *aData )
{
    for (int i=0;i<Nodes.Count;i++)
        if (Nodes[i].Data == aData)
            return &Nodes[i];
    return NULL;
}    */

#endif
