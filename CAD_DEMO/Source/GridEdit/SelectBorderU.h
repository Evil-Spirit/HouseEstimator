// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SelectBorderUH
#define SelectBorderUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class COMMONAL_API TSelectBorder : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton8;
    TToolButton *ToolButton9;
    TToolButton *ToolButton10;
    TToolButton *ToolButton11;
    TToolButton *ToolButton12;
    TToolButton *ToolButton13;
    TPanel *Panel1;
    void  FormDeactivate(TObject *Sender);
    void  SetIndex(int Index);
    void  ToolButton1Click(TObject *Sender);
    void  ToolButton2Click(TObject *Sender);
    void  ToolButton4Click(TObject *Sender);
    void  ToolButton5Click(TObject *Sender);
    void  ToolButton6Click(TObject *Sender);
    void  ToolButton7Click(TObject *Sender);
    void  ToolButton8Click(TObject *Sender);
    void  ToolButton9Click(TObject *Sender);
    void  ToolButton10Click(TObject *Sender);
    void  ToolButton11Click(TObject *Sender);
    void  ToolButton12Click(TObject *Sender);
    void  ToolButton13Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TSelectBorder(TComponent* Owner);
    int SelectBorderIndex;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectBorder *SelectBorder;
//---------------------------------------------------------------------------
#endif
