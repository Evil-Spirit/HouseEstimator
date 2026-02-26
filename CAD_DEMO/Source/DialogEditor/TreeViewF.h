// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef TreeViewFH
#define TreeViewFH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TVCLEditorElement;
class TMyDialogEdit;

class  TObjectTreeView : public TForm
{
      __published:
        TToolBar *deToolBar;
        TTreeView *deTreeView;
        TImageList *deImageList;
        TSpeedButton *deAddButton;
        TSpeedButton *deDeleteButton;
        TToolButton *deSeparator;
        TSpeedButton *deUpButton;
        TSpeedButton *deDownButton;
        void  deUpButtonClick(TObject *Sender);
        void  deDownButtonClick(TObject *Sender);
        void  deDeleteButtonClick(TObject *Sender);
        void  deAddButtonClick(TObject *Sender);
        void  deTreeViewChange(TObject *Sender, TTreeNode *Node);
        void  deTreeViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);

        private:
        TList* Selected;
        bool SelectChange;
        int FindByName(AnsiString Name);
        void CreateTreeRecursion(TVCLEditorElement *_Node, TTreeNode *Root, int &Index);
        void CreateTree(TVCLEditorElement *_Node);
        int GetVCLEdEl(AnsiString Name);
        TVCLEditorElement* GetVCLEdEl(AnsiString Name, TVCLEditorElement* Head);
        void NewParent(AnsiString ChildName, AnsiString ParentName);
        void DeleteObject(AnsiString Name);
        void SelectObject(AnsiString Name);

        public:
        TMyDialogEdit* DialogEdit;
       TObjectTreeView(TComponent* Owner);
      __property TVCLEditorElement* Tree = {write = CreateTree};
        void DeleteObject(TComponent *_Object);
        void SelectObject(TComponent *_Object, bool Add = false);
};

//---------------------------------------------------------------------------
extern  TObjectTreeView *TreeView;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
