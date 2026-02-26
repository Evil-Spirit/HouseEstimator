// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDICanExistsCheckEditVH
#define MDICanExistsCheckEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
template <class T> class TMDelTList;
template <class T> class TPointer;
class TDynamicLink;        

class COMMONAL_API TMDICanExistsCheckEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *N4;
    TMenuItem *N3;
    TImageList *ImageList1;
    TTreeView *TV;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton4;
    TToolButton *ToolButton3;
    void  N1Click(TObject *Sender);
    void  N4Click(TObject *Sender);
    void  TVMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  N3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
    virtual void KILL();
    /*TMDelLSTList*/TMDelTList< /*TMDelLSTList*/TMDelTList<TPointer< TDynamicLink > > > *ELSE;
    TTreeNode *FindByData(TTreeNode *TN,void* Data);
     TMDICanExistsCheckEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDICanExistsCheckEdit *MDICanExistsCheckEdit;
//---------------------------------------------------------------------------
#endif
