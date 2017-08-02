//---------------------------------------------------------------------------

#ifndef BindedBlockEditVH
#define BindedBlockEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include "MDIObjectEditV.h"
class TBaseBlock;
class TBindedBaseTool;
class TBindedGoEdit;
//---------------------------------------------------------------------------
class PACKAGE TBindedBlockEdit : public TMDIObjectEdit
{
//    friend class TBaseTool;
__published:	// IDE-managed Components
    TPanel *pBlockEdit;
    TPanel *Panel1;
    TLabel *lNameSB;
    TLabel *lExecutedEvent;
    TToolBar *ToolBar1;
    TToolButton *tbNew;
    TToolButton *tbEdit;
    TToolButton *tbDelete;
    TComboBox *cbExEvent;
    TEdit *eName;
    TGroupBox *GroupBox1;
    TPanel *Panel2;
    TListView *lvNextBlock;
    TSplitter *Splitter1;
    TPanel *pLuaModuleEdit;
    void __fastcall tbNewClick(TObject *Sender);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall tbDeleteClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall lvNextBlockDblClick(TObject *Sender);
    void __fastcall eNameChange(TObject *Sender);
    void __fastcall lvNextBlockResize(TObject *Sender);
private:	// User declarations
    TBaseBlock* GetFObj();
    __property TBaseBlock* FObj = {read = GetFObj};
    TBindedBaseTool* BT;
    int FBlockType;
    TBindedGoEdit* BindedGoEdit;

    TMDelTList<AnsiString>& GetBlocksNames();
//    void SetBlocksNames(TMDelTList<AnsiString> MDTL);
    TMDelTList<int>& GetBlocksIds();
//    void SetBlocksIds(TMDelTList<int> MDTL);

    TMDelTList<AnsiString>* FBlocksNames;
    TMDelTList<int>* FBlocksIds;

    __property TMDelTList<AnsiString> BlocksNames = {read = GetBlocksNames};
    __property TMDelTList<int> BlocksIds = {read = GetBlocksIds};
    int BlocksCount;
    int Size0;
    TBaseBlock& GetMyBaseBlock();
    TBaseBlock* FMyBaseBlock;
    __property TBaseBlock MyBaseBlock = {read = GetMyBaseBlock};
public:		// User declarations
    __fastcall TBindedBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    void EditLuaModule();
    bool Checked();
    void Apply();
    void Refresh();
    void FillForm();
    void SETUP();
    void KILL();
    bool NameChanged;
};
//---------------------------------------------------------------------------
extern PACKAGE TBindedBlockEdit *BindedBlockEdit;
//---------------------------------------------------------------------------
#endif
