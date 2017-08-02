//---------------------------------------------------------------------------
#ifndef TreeViewFH
#define TreeViewFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TVCLEditorElement;
class TMyDialogEdit;

class PACKAGE TObjectTreeView : public TForm
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
        void __fastcall deUpButtonClick(TObject *Sender);
        void __fastcall deDownButtonClick(TObject *Sender);
        void __fastcall deDeleteButtonClick(TObject *Sender);
        void __fastcall deAddButtonClick(TObject *Sender);
        void __fastcall deTreeViewChange(TObject *Sender, TTreeNode *Node);
        void __fastcall deTreeViewKeyDown(TObject *Sender, WORD &Key,
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
      __fastcall TObjectTreeView(TComponent* Owner);
      __property TVCLEditorElement* Tree = {write = CreateTree};
        void DeleteObject(TComponent *_Object);
        void SelectObject(TComponent *_Object, bool Add = false);
};

//---------------------------------------------------------------------------
extern PACKAGE TObjectTreeView *TreeView;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
