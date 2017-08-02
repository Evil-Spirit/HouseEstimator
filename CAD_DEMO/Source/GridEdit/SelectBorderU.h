//---------------------------------------------------------------------------

#ifndef SelectBorderUH
#define SelectBorderUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
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
    void __fastcall FormDeactivate(TObject *Sender);
    void __fastcall SetIndex(int Index);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall ToolButton2Click(TObject *Sender);
    void __fastcall ToolButton4Click(TObject *Sender);
    void __fastcall ToolButton5Click(TObject *Sender);
    void __fastcall ToolButton6Click(TObject *Sender);
    void __fastcall ToolButton7Click(TObject *Sender);
    void __fastcall ToolButton8Click(TObject *Sender);
    void __fastcall ToolButton9Click(TObject *Sender);
    void __fastcall ToolButton10Click(TObject *Sender);
    void __fastcall ToolButton11Click(TObject *Sender);
    void __fastcall ToolButton12Click(TObject *Sender);
    void __fastcall ToolButton13Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TSelectBorder(TComponent* Owner);
    int SelectBorderIndex;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectBorder *SelectBorder;
//---------------------------------------------------------------------------
#endif
