//---------------------------------------------------------------------------

#ifndef MDIConfigVH
#define MDIConfigVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "SUISkinEngine.hpp"
//---------------------------------------------------------------------------

class TMDIConfig : public TMyMDIChild
{
__published:	// IDE-managed Components
    TActionList *AL;
    TAction *New;
    TAction *Edit;
    TAction *Del;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TAction *NewFol;
    TMenuItem *N4;
    TTreeView *tvTechnology;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton4;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TAction *UpAction;
    TAction *DownAction;
    TMenuItem *UpAction1;
    TMenuItem *DownAction1;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TPageControl *PageControl1;
    TTabSheet *tsTechnology;
    TTabSheet *tsOptions;
    TPageControl *pcOptions;
    TTabSheet *tsInterface;
    TTabSheet *tsMainVariable;
    TAction *NewCopy;
    TMenuItem *N5;
    TToolButton *ToolButton7;
    TAction *ExportHere;
    TAction *ImportHere;
    TToolButton *ToolButton8;
    TToolButton *ToolButton9;
    TOpenDialog *OD;
    TSaveDialog *SD;
    void __fastcall NewExecute(TObject *Sender);
    void __fastcall EditExecute(TObject *Sender);
    void __fastcall DelExecute(TObject *Sender);
    void __fastcall tvTechnologyDeletion(TObject *Sender, TTreeNode *Node);
    void __fastcall NewFolExecute(TObject *Sender);
    void __fastcall tvTechnologyStartDrag(TObject *Sender,
          TDragObject *&DragObject);
    void __fastcall tvTechnologyDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall tvTechnologyDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall tvTechnologyMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall UpActionExecute(TObject *Sender);
    void __fastcall DownActionExecute(TObject *Sender);
    void __fastcall NewCopyExecute(TObject *Sender);
    void __fastcall ExportHereExecute(TObject *Sender);
    void __fastcall ImportHereExecute(TObject *Sender);
	void __fastcall tvTechnologyDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIConfig(TComponent* Owner);
    TMTList<TMetaNode> *MNL;
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIConfig *MDIConfig;
//---------------------------------------------------------------------------
#endif
