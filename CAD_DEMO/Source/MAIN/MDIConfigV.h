// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIConfigVH
#define MDIConfigVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
#include "compat/SUISkinEngine.hpp"
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
    void  NewExecute(TObject *Sender);
    void  EditExecute(TObject *Sender);
    void  DelExecute(TObject *Sender);
    void  tvTechnologyDeletion(TObject *Sender, TTreeNode *Node);
    void  NewFolExecute(TObject *Sender);
    void  tvTechnologyStartDrag(TObject *Sender,
          TDragObject *&DragObject);
    void  tvTechnologyDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void  FormDestroy(TObject *Sender);
    void  tvTechnologyDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void  FormCloseQuery(TObject *Sender, bool &CanClose);
    void  tvTechnologyMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void  UpActionExecute(TObject *Sender);
    void  DownActionExecute(TObject *Sender);
    void  NewCopyExecute(TObject *Sender);
    void  ExportHereExecute(TObject *Sender);
    void  ImportHereExecute(TObject *Sender);
	void  tvTechnologyDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDIConfig(TComponent* Owner);
    TMTList<TMetaNode> *MNL;
};
//---------------------------------------------------------------------------
extern  TMDIConfig *MDIConfig;
//---------------------------------------------------------------------------
#endif
