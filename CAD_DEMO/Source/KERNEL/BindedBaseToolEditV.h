// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BindedBaseToolEditVH
#define BindedBaseToolEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MainToolsV.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class  TBindedBaseToolEdit : public TMDIObjectEdit
{
//    friend class TBaseTool;
__published:	// IDE-managed Components
    TPanel *pBlocks;
    TPopupMenu *pmBlocksTypes;
    TMenuItem *spmStateBlock;
    TMenuItem *spmActionBlock;
    TMenuItem *spmConditionalBlock;
    TGroupBox *GroupBox1;
    TSplitter *Splitter1;
    TPanel *Panel2;
    TPanel *Panel3;
    TListView *lvBlocks;
    TToolBar *ToolBar;
    TToolButton *tbNew;
    TToolButton *tbDelete;
    TButton *Button1;
    void  spmStateBlockClick(TObject *Sender);
    void  spmActionBlockClick(TObject *Sender);
    void  spmConditionalBlockClick(TObject *Sender);
    void  lvBlocksSelectItem(TObject *Sender, TListItem *Item,
          bool Selected);
    void  tbDeleteClick(TObject *Sender);
    void  lvBlocksResize(TObject *Sender);
    void  Button1Click(TObject *Sender);
    void  pmBlocksTypesPopup(TObject *Sender);
private:	// User declarations
    TBindedBaseTool* GetFObj(){return (TBindedBaseTool*)Obj;};
    // __property TBindedBaseTool* FObj {read=GetFObj}; // [manual migration needed]
    TBindedBaseTool& GetMyTool();
//    void SetMyTool(TBindedBaseTool _BBT);
    TBindedBaseTool* FMyTool;
    // __property TBindedBaseTool MyTool {read=GetMyTool}; // [manual migration needed]
public:		// User declarations
     TBindedBaseToolEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    void FillForm();
    bool Checked();
    void SETUP();
    void KILL();
    void Apply();
    void Refresh();
    void ApplyAndDestroyBlock();
    void EditBlock();
    void EditLuaModule();
    void GenerateImage( int _Id, int BlockType );
};
//---------------------------------------------------------------------------
extern  TBindedBaseToolEdit *BindedBaseToolEdit;
//---------------------------------------------------------------------------
#endif
