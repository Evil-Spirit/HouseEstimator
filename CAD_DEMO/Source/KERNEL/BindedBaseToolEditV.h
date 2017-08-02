//---------------------------------------------------------------------------

#ifndef BindedBaseToolEditVH
#define BindedBaseToolEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include "MainToolsV.h"
#include <ExtCtrls.hpp>
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class PACKAGE TBindedBaseToolEdit : public TMDIObjectEdit
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
    void __fastcall spmStateBlockClick(TObject *Sender);
    void __fastcall spmActionBlockClick(TObject *Sender);
    void __fastcall spmConditionalBlockClick(TObject *Sender);
    void __fastcall lvBlocksSelectItem(TObject *Sender, TListItem *Item,
          bool Selected);
    void __fastcall tbDeleteClick(TObject *Sender);
    void __fastcall lvBlocksResize(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall pmBlocksTypesPopup(TObject *Sender);
private:	// User declarations
    TBindedBaseTool* GetFObj(){return (TBindedBaseTool*)Obj;};
    __property TBindedBaseTool* FObj = {read = GetFObj};
    TBindedBaseTool& GetMyTool();
//    void SetMyTool(TBindedBaseTool _BBT);
    TBindedBaseTool* FMyTool;
    __property TBindedBaseTool MyTool = {read = GetMyTool};
public:		// User declarations
    __fastcall TBindedBaseToolEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
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
extern PACKAGE TBindedBaseToolEdit *BindedBaseToolEdit;
//---------------------------------------------------------------------------
#endif
