// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDICountReportVH
#define MDICountReportVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"

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
    void  FormDestroy(TObject *Sender);
    void  FormShow(TObject *Sender);
    void  FormCreate(TObject *Sender);
    void  SGDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void  FormActivate(TObject *Sender);
    void  SGMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
    void  SGMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  SGDblClick(TObject *Sender);
    void  tbTreeClick(TObject *Sender);
    void  tbUpClick(TObject *Sender);
    void  ToolButton1Click(TObject *Sender);
private:	// User declarations
    TQuerryNode* FQNParent;
    void SetQNParent(TQuerryNode* newQNParent);
    TMTList<TQuerryNode> QNS;
public:		// User declarations
    void UpdateReport();
     TMDICountReport(TComponent* Owner);
    TCounterBase* CB;
    void DrawCounterBase();
    void ToExcel(const AnsiString& FileName);
    void DrawCounterBaseStandart();
    void DrawCounterBaseAdvanced();
    // __property TQuerryNode* QNParent {read=FQNParent, write=SetQNParent}; // [manual migration needed]
    THierarchyQuerry* HQ;
    bool ShowName;
    bool TreeView;
    bool AllDirectory;
    void UpdateCellSize(int ACol, int ARow);
    void UpdateAllCelsSize();
};
extern int TakeMode;
//---------------------------------------------------------------------------
extern  TMDICountReport *MDICountReport;
//---------------------------------------------------------------------------
#endif
