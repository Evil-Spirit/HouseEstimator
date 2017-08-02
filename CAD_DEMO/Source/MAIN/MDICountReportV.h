//---------------------------------------------------------------------------

#ifndef MDICountReportVH
#define MDICountReportVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>

//enum TViewMode
const int vmList = 0;
const int vmTree = 1;

class TCounterBase;
class THierarchyQuerry;
class TQuerryNode;

class TMDICountReport : public TMyMDIChild
{
__published:	// IDE-managed Components
    TStringGrid *SG;
    TToolBar *ToolBar1;
    TToolButton *tbTree;
    TToolButton *tbUp;
    TToolButton *tbFull;
    TToolButton *ToolButton1;
    TImageList *ImageList1;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall SGDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall SGMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
    void __fastcall SGMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall SGDblClick(TObject *Sender);
    void __fastcall tbTreeClick(TObject *Sender);
    void __fastcall tbUpClick(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
private:	// User declarations
    TQuerryNode* FQNParent;
    void SetQNParent(TQuerryNode* newQNParent);
    TMTList<TQuerryNode> QNS;
public:		// User declarations
    void UpdateReport();
    __fastcall TMDICountReport(TComponent* Owner);
    TCounterBase* CB;
    void DrawCounterBase();
    void ToExcel(const AnsiString& FileName);
    void DrawCounterBaseStandart();
    void DrawCounterBaseAdvanced();
    __property TQuerryNode* QNParent = {read = FQNParent, write = SetQNParent};
    THierarchyQuerry* HQ;
    bool ShowName;
    bool TreeView;
    bool AllDirectory;
    void UpdateCellSize(int ACol, int ARow);
    void UpdateAllCelsSize();
};
extern int TakeMode;
//---------------------------------------------------------------------------
extern PACKAGE TMDICountReport *MDICountReport;
//---------------------------------------------------------------------------
#endif
