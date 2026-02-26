// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BindedBlockEditVH
#define BindedBlockEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
class TBaseBlock;
class TBindedBaseTool;
class TBindedGoEdit;
//---------------------------------------------------------------------------
class  TBindedBlockEdit : public TMDIObjectEdit
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
    void  tbNewClick(TObject *Sender);
    void  tbEditClick(TObject *Sender);
    void  tbDeleteClick(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  lvNextBlockDblClick(TObject *Sender);
    void  eNameChange(TObject *Sender);
    void  lvNextBlockResize(TObject *Sender);
private:	// User declarations
    TBaseBlock* GetFObj();
    // __property TBaseBlock* FObj {read=GetFObj}; // [manual migration needed]
    TBindedBaseTool* BT;
    int FBlockType;
    TBindedGoEdit* BindedGoEdit;

    TMDelTList<AnsiString>& GetBlocksNames();
//    void SetBlocksNames(TMDelTList<AnsiString> MDTL);
    TMDelTList<int>& GetBlocksIds();
//    void SetBlocksIds(TMDelTList<int> MDTL);

    TMDelTList<AnsiString>* FBlocksNames;
    TMDelTList<int>* FBlocksIds;

    // __property TMDelTList<AnsiString> BlocksNames {read=GetBlocksNames}; // [manual migration needed]
    // __property TMDelTList<int> BlocksIds {read=GetBlocksIds}; // [manual migration needed]
    int BlocksCount;
    int Size0;
    TBaseBlock& GetMyBaseBlock();
    TBaseBlock* FMyBaseBlock;
    // __property TBaseBlock MyBaseBlock {read=GetMyBaseBlock}; // [manual migration needed]
public:		// User declarations
     TBindedBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
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
extern  TBindedBlockEdit *BindedBlockEdit;
//---------------------------------------------------------------------------
#endif
