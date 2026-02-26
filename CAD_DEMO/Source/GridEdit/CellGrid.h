// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef CellGridH
#define CellGridH
#include "GridRoutineU.hpp"
#include "UNDO.h"
//---------------------------------------------------------------------------

// ----------- Const ------------------
    const int iPixelTact=2;
//*********************  Color **********
//    const TColor ColorSelect =RGB(182,202,234); // Âûäåëåíèå íåñêîëüêèõ ÿ÷÷åê
//    const TColor ColorSelect =RGB(109,149,213); // Âûäåëåíèå íåñêîëüêèõ ÿ÷÷åê
//    const TColor ColorSelect =RGB(255,255,255); // Âûäåëåíèå íåñêîëüêèõ ÿ÷÷åê
    const TColor ColorFixedSelect =RGB(248, 247, 239);// Âûäåëåíî èëè ñòðîêà èëè ñòîëáåö
    const TColor ColorFixedSelectAll =RGB(255, 192, 111); // Âûäåëåíà Âñÿ òàáëèöà
//*********************  Color ********** END



class TGridForm;
#pragma option push -b-
enum TTextVAlign {tvaTop,tvaCenter,tvaDown};
#pragma option pop
class TCell;
class TCellMatrix;


class COMMONAL_API TCell : public TMyObject{
// Ðàáîòà ñ ÿ÷åéêîé
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    void Assign(TMyObject* MO);
    bool UndoRegistered;

    TCell();
    ~TCell();

    TColor bgColor;// Öâåò ôîíà
    bool LineColorNot;// Ôëàã íàëè÷èÿ çàëèâêè ôîíà ó ÿ÷åéêè
    AnsiString Text;// Òåêñò â ÿ÷åéêå
    AnsiString FontName;// Øðèôò
    TColor FontColor;// Öâåò ôðèôòà
    struct TLineWidth // Íàëè÷åå áîðäþðà è åãî òèï
    {
        byte WidthLeft;
        byte WidthTop;
        byte WidthRight;
        byte WidthBottom;
    } Line;
    TRect* UnionRect;// Îáúåäåíåííàÿ ÿ÷åéêà (ß÷åéêà ïåðâàÿ è ïîñëåäíÿÿ â ðåãèîíå)

    struct TCellFlags
    {
        unsigned FontSize:8;// Ðàçìåð øðèôòà
        unsigned FontStyle:3;// Ñòèëü øðèôòà (Îáû÷íû=0, Êóðñèâ=1, Æèðíûé=2, Æèðíûé êóðñèâ=3)
        unsigned FontStrikeOut:1;// Çà÷åðêíóòûé øðèôò (ÍÅÒ=0, çà÷åðêíóòûé=1)
        unsigned FontUnderline:1;// Ïîä÷åðêíóòûé øðèôò (ÍÅÒ=0, ïîä÷åðêíóòûé=1)
        unsigned ValueType:2;// Òèï Çíà÷åíèÿ (òåêñò =0, âûðàæåíèå =1, øàáëîí =2)
        unsigned TypeAutoSize:2;// òèï ðàñïîëîæåíèÿ òåêñòà â ÿ÷åéêå (áåç àâòî =0, àâòî ðàçìåð ñòðîêè =1)
        unsigned TextHAlign:2;// Âûðàâíèâàíèå òåêñòà ïî ãîðèçîíòàëè (Left=0, Center=1, Right=2)
        unsigned TextVAlign:2;// Âûðàâíèâàíèå òåêñòà ïî âåðòèêàëè (Left=0, Center=1, Right=2)
        unsigned TextWordBreak:1;// ïåðåíîñ ïî ñëîâàì (ÍÅ ïåðåíîñèòü=0, ïåðåíîñèòü=1)
        unsigned TextHeightAuto:1;// Ðàñøèðÿòü âûñîòó ñòðîêè ïîä íàáðàííûé òåêñò (ÍÅ ðàñøèðÿòü=0, Ðàñøèðÿòü=1)

        unsigned reserve:9;
    } CellFlags;

    TFont* Font;
    void InitFont();

    void ReadData(TMemoryStream *MS);
    void WriteData(TMemoryStream *MS) const;
    void SaveData(FILE *F) const ;
    void LoadData(FILE *F);
};
extern COMMONAL_API TClassNode* TCell::StaticType;

class COMMONAL_API TCellFlag : public TCell{
// Ðàáîòà ñ ñòðîêàìè ñòàëáöàìè
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCellFlag();

    int Col;
    int Row;
    TRect UnionCell;

    bool f_UnionCell;
    bool f_SetUnion;
    int ColWidth;
    int RowHeight;
    bool f_ColWidth;
    bool f_bgColor;
    bool f_Text;
    bool f_LineColorNot;
    bool f_FontName;
    bool f_FontColor;

    bool f_WidthLeft;
    bool f_WidthTop;
    bool f_WidthRight;
    bool f_WidthBottom;
    bool f_Flood;

    bool f_FontSize;
    bool f_FontStyle;
    bool f_FontStrikeOut;
    bool f_FontUnderline;
    bool f_ValueType;
    bool f_TypeAutoSize;
    bool f_TextHAlign;
    bool f_TextVAlign;
    bool f_TextWordBreak;
    bool f_TextHeightAuto;
};
extern COMMONAL_API TClassNode* TCellFlag::StaticType;

class COMMONAL_API TCellColRow : public TCell{
// Ðàáîòà ñ ñòðîêàìè ñòàëáöàìè
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCellColRow();
    ~TCellColRow();
    int ColRowWidth;
};
extern COMMONAL_API TClassNode* TCellColRow::StaticType;

class COMMONAL_API TCellTab : public TCell{
// Ðàáîòà ñ ÿ÷åéêîé
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCellTab();
    ~TCellTab();
    int ColWidth;
    int RowHeight;
};
extern COMMONAL_API TClassNode* TCellTab::StaticType;


class COMMONAL_API TCellList : public TSparseList {
// Äèíàìè÷åñêàÿ ñòðîêà
public:
     TCellList(TSPAQuantum Quantum)
    :TSparseList(Quantum){};
    void  Put(int index, TCell * item);
    TCell*  Get(int index);
};

//---------------------------------------------------------------------------
class TEditText;
class TToolBarCellGrid;

class COMMONAL_API TCellGrid : public TMyDrawGrid {
// Ðèñîâàíèå
protected:
	virtual void  WndProc(Messages::TMessage &Message);
private:
    void* FData;
__published:

public:
    TToolBarCellGrid* ToolBarCellGrid;
    TEditText* EditText; // RichEdit -äëÿ ââîäà òåêñòà â ÿ÷åéêó

// Ïåðåìåííûå ÍÀØÅÃÎ Paint
    bool InvalidateRectOK;
    bool StartVisible;
    bool bResizeColRow;

    TGridCoord oldFCurrent;
    TGridCoord oldFAnchor;
    int iMouseDown;
    int iMouseMove;
    TPoint EndColRowCell; // Ïîñëåäíÿÿ ñóùåñòâóþùàÿ ÿ÷åéêà

    TRect CurrentRectMouseDown;
//    bool FieldCut;
//    PIntArray PointsCopy;
    TRect OldRectDown;//Äëÿ êîððåêòíîé âûäåëåíèè ïðè âûõîäå èç îáúåäåíåííîé ÿ÷åéêè
    TRect OldRectDownCurrentAnchor;//Äëÿ êîððåêòíîé âûäåëåíèè ïðè âûõîäå èç îáúåäåíåííîé ÿ÷åéêè


    TRect OldRectMouseDown;
    TRect OldRectMouseDown2;

    TColor ColorSelect;

//    bool MouseDownAndMoveCursor;

    bool MoveCellBorder;
// Ïåðåìåííûå ÍÀØÅÃÎ Paint - END

// Ïåðåìåííûå ÍÀØÅÃÎ Paint V2
//    TRect OldRectCurrentAnchorMouseDown;
    TRect OldRectCurrentAnchorMouseMove;
    TGridRect OldRectCurrentAnchorMouseMoveCell;
    TGridCoord OldCellMouseMove;
    TGridCoord JobFCurrent;
    TGridCoord JobFAnchor;
// Ïåðåìåííûå ÍÀØÅÃÎ Paint END

// Ïåðåìåííûå ÍÀØÅÃÎ Paint V4
    TGridCoord StartMouseDown;
    TRect CurrentUnionRectMouseMove;
    int iCountYes;

    TGridCoord MousePosCellMove;
    TGridCoord CurrentMouseCoordTimer;
    bool CursorMoveStarted();

//    int MouseWhellUp;
    TGridCoord MouseUpCoord;
    TGridRect CurrentAnchorMouseUp;
//    int MouseWhellDown;

    bool MouseUP;

//    int MouseWhellRight;
//    int MouseWhellLeft;

    TGridCoord PointMouseDownOld;

    bool Vert;
    bool Horz;

    bool VertFixed;
    bool HorzFixed;

    bool VertFixedLast;
    bool HorzFixedLast;

    int MouseX;
    int MouseY;
//------- Scroll ---
    int ScrollParam;
//------- Scroll ---

    TGridCoord FCurrent_Mem;
    TGridCoord FAnchor_Mem;
    int V_SCROLL_POS;
    int H_SCROLL_POS;

    TGridCoord OldFAnchorBorder;//

    TPoint CellGridResizeRow; // Äëÿ èçìåíåíèÿ ðàçìåðà âûñîòû ñòðîê
    TPoint CellGridResizeCol; // Äëÿ èçìåíåíèÿ ðàçìåðà âûñîòû ñòðîê
    int NewSizeColRow;

//*********************  Color **********
    TColor ColorCursor; // Ñòàíäàðòíûé ôîí
//*********************  Color ********** END

    TRect FValidSelection;
    TRect FValidSelectionPlus;
    TRect FValidSelectionMinus;
    TGridRect FValidCurAnchor;
//    int iCountCalculation;

    TGridCoord DrawCursCurrent;
    TGridCoord DrawCursAnchor;

    bool PopupMenuNotMouseUp;// Äëÿ òîãî ÷òîáû ïîñëå âûõîäà íå ïîðòèë MouseUP äëÿ ïðàâèëèíîãî îáíîâëåíèÿ ïðåäûäóùåãî ðåêòà
//********************* Function System
    bool SelectTable; // Âûäåëåíà òàáëèöà
    bool SelectColumn;// Âûäåëåí ñòîëáåö
    bool SelectString;// Âûäåëåíà ñòðîêà
    bool SelectCell;// Âûäåëåíà ÿ÷åéêà

    int XM;
    int YM;
    TGridCoord MousePosCellMoveSelect;

    TMDelTList <TPoint> ListFilling; // ñïèñîê ÿ÷ååê ïîäëåæàùèõ èçìåíåíèþ
    TMDelTList <TPoint> ListFilling2; // ñïèñîê ÿ÷ååê ïîäëåæàùèõ èçìåíåíèþ
    TRect OldCurrentAnchorSort;
//********************* Function System END

    bool PrivatEvent_1;// Ïåðåðèñîâàòü ïîñëå Scrool (ñòàðò â ðàá çîíå êîíåö â Fixed)
    bool PrivatEvent_2;// Ïåðåðèñîâàòü âñå äëÿ MouseDown

    int OldRectDrawCellFixedT; // Äëÿ ïðîâåðêè íåîáõîäèìîñòè âû÷èñëÿòü çíà÷åíèÿ Top îáúåäåíåííîé ÿ÷åéêè
    int OldRectDrawCellFixedL; // Äëÿ ïðîâåðêè íåîáõîäèìîñòè âû÷èñëÿòü çíà÷åíèÿ Left îáúåäåíåííîé ÿ÷åéêè
    int OldRectDrawCellFixedTop;
    int OldRectDrawCellFixedLeft;
    TRect CurrentRectDrawUnionFixed;// Ðåêò òåêóùåé UnionCell

// Ïåðåìåííûå ÍÀØÅÃÎ Paint END4
// Ïåðåìåííûå Äëÿ òåñòà
    int iTest1;
    int iTest2;
// Ïåðåìåííûå END

// Ïåðåìåííûå Edit
    TRect CurrentEditCell;
    AnsiString TempStringCell;
    int CurrentEditCol;
    int CurrentEditRow;
// Ïåðåìåííûå Edit End

// Ïåðåìåííûå ñòàíäàðòíîãî Paint
    TGridDrawInfo DrawInfo;
    TGridRect Sel;
    TRect UpdateRect;

    bool Focused;

    TGridForm* GridForm;
    TCellFlag* gCellFlag;// Äëÿ óñòàíîâêè ôëàãîâ
    TMDelTList <TMDelTList <TCellFlag> > CellF;
    bool ProgressCopy;
// Ïåðåìåííûå ñòàíäàðòíîãî END
    TTimer* Timer;
    TTimer* TStart;

    // - Matrix -
    TCellMatrix* Matrix;
    // - Matrix - END

    void  OnTimer(TObject *Sender);
    void  StartTime(TObject *Sender);

     TCellGrid(Classes::TComponent* AOwner, TGridForm* _Form, TToolBarCellGrid* _ToolBarCellGrid);
	inline  virtual ~TCellGrid(void);
    void Initialize();


//********************* Function System
    void         NewCell(int Col, int Row);// Ñîçäàòü íîâóþ ÿ÷åéêó
    void         NewCell(int Col, int Row, TCell* data);// Ñîçäàòü íîâóþ ÿ÷åéêó
    void         DelCell(int Col, int Row);// Óäàëèòü ÿ÷åéêó

    void         SetCell(int aCol, int aRow, TCell* data);//
    void         SetNewCell(int aCol, int aRow, TCell* data);
    void         NewCellAndSetDefault(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // Ñîçäàòü ÿ÷åéêó è çàïîëíèòü åå Default
    void         NewCellAndSetDefault2(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // Ñîçäàòü ÿ÷åéêó è çàïîëíèòü åå Default

    void         NewCellAndSetParam(int Col, int Row);// Ñîçäàòü íîâóþ ÿ÷åéêó è ïðè íåîáõîäèìîñòè ñîçäàåò íà ïåðåñå÷åíèè
    TCellFlag*   GetParamCell(int Col, int Row); // Ïîëó÷èòü ÿ÷åéêó ñî âñåìè ïàðàìåòðàìè
    void         ClearSelectRect();// Î÷èñòêà âûäåëåííîé îáëàñòè
    void         ClearSelectRect(const TRect& rect);// Î÷èñòêà Recta
    void         ClearCell(int Col, int Row);// Î÷èñòêà ß÷åéêè
    void         DelAndSetDefaultCell(int Col, int Row);// Óäàëèòü è çàïîëíèòü Defaultam îò 0:0
    void         DelAndSetDefaultCell(const TRect& Rect);// Óäàëèòü è çàïîëíèòü Defaultam îò 0:0
    void         DelAndSetDefaultCellF(const TRect& Rect);// Óäàëèòü è çàïîëíèòü Defaultam îò 0:0
    int          DelCellF(int Col, int Row, void * TheItem);// äëÿ DelAndSetDefaultCellF
    void         GetSelectCells(bool AllUnion); // Çàïîëíåíèå ListFilling
    //(x,y) ß÷ååê äëÿ èçìåíåíèÿ
    //(AllUnion åñëè true òîãäà åñëè îáúåäåíåííàÿ ÿ÷åéêà ïîïàäàåò öèëèêîì
    //â âûäåëåííóþ îáëàñòü òîãäà âêëþ÷àòü â ñïèñîê èíà÷å èñêëþ÷àåì îáëàñòü îáúåäåíåííîé ÿ÷åéêè)

//    void         GetSelectCellsColRow(); // Çàïîëíåíèå ListFilling (x,y) (Ñòðîê, Ñòîëáöîâ) - äëÿ ëèíèé
    void         ClearListFilling();// Î÷èñòêà ListFilling
    void         SetDefaultCell11(); // Óñòàíàâëèâàåò â ÿ÷åéêó 1:1 çíà÷åíèå Default
    void*        EnsureDataRow(int aRow);
    TCell*       GetCell(int Col, int Row);// Ïîëó÷èòü äàííûå î ÿ÷åéêå ñ ó÷åòîì îáúåäåíîíîé
    TCell*       GetCellSimple(int Col, int Row);// Ïîëó÷èòü äàííûå î ÿ÷åéêå Áåç ó÷åòà îáúåäåíåíîé
    TCell*       GetCellParam(int Col, int Row); // Ïîëó÷èòü ïàðàìåòðû ÿ÷åéêè
    TCell*       GetCellParamSimple(int Col, int Row);// Ïîëó÷èòü ïàðàìåòðû ÿ÷åéêè
    void         CopyCell1ToCell2(int Col1, int Row1, int Col2, int Row2);// Êîïèðîâàòüü èç Cell1 â Cell2
    void         CopyCell1ToCell2(int Col,int Row, TCell* Cell2);// Êîïèðîâàòüü èç Col,Row â Cell2
    void         CopyCell1ToCell2(TCell* Cell1, int Col,int Row);// Êîïèðîâàòüü èç Cell2 â Col,Row
    void         InvalidateRect2(const TRect& rect);
// [indexed property - needs manual migration]:     __property TCell* Cells[int i][int j] = {read = GetCell,write = SetCell};
//********************* Function System END

//********************* Function Undo/Redo
    void UndoRegister(int Col, int Row, TGridRegisterMode RM);
//********************* Function Undo/Redo ENDS

//********************* Function Form
    void  DoModalFormSection();
    void  DoModalFormCellParameter();
    void  DoModalSelectColor(int Left, int Top);
//********************* Function Form End

//********************* Îáðàáîòêà ñîîáùåíèé è ïåðåîïðåäåëåíèå ôóêöèé
    void             CellGridMouseMove(TObject *Sender,TShiftState Shift, int X, int Y);// Îáðàáîò÷èê Ìûøü äâèæåíèå
    void             CellGridMouseDown(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// Îáðàáîò÷èê Ìûøü Key â âåðõ
    void             CellGridMouseUp(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// Îáðàáîò÷èê Ìûøü Key â íèç
	DYNAMIC bool     DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Ñêðîë ïî êîëÿñèêó â âåðõ
    DYNAMIC bool     DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Ñêðîë ïî êîëÿñèêó â íèç
    bool             DoMouseWheelLeft(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Ñêðîë ïî êîëÿñèêó â ëåâî
    bool             DoMouseWheelRight(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Ñêðîë ïî êîëÿñèêó â ïðàâî
    DYNAMIC void     KeyDown(Word &Key, Classes::TShiftState Shift);// îáðàáîò÷èê êëàâèàòóðû
    void             ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft);// îáðàáîò÷èê ñêðîëèðîâàíèÿ ïîëçóíêàìè
    void             ResizeRow(int Index, int OldSize, int NewSize);
    void             ResizeCol(int Index, int OldSize, int NewSize);
//********************* Îáðàáîòêà ñîîáùåíèé  è ïåðåîïðåäåëåíèå ôóêöèé END

//********************* Function EditText
    void     ShowEditText(int Col, int Row, bool clear); // Ïîêàçàòü ïîëå ââîäà
    void     SetCanvasParameterCell(int Col, int Row);// Óñòàíîâèòü â Canvas ïàðàìåòðû ÿ÷åéêè
    int      GetAlignText(int Col, int Row);// ïîëó÷èòüâûðàâíèâàíèå òåêñòà äëÿ DrawText
    void     GetRectDrawText(int Col, int Row, const AnsiString& Text, TRect& calcrect);// Ðàñ÷èòàòü ðåêò íåîáõîäèìûé ïîä òåêñò
    void     UseTextWordBreak(int Col, int Row);// Ïðèìåíèòü ïåðåíîñ ïî ñëîâàì
//********************* Function EditText

//********************* Ðàçíîå
    void     InvalidateU2();// Invalidate 2îãî óðîâíÿ
    void     NullRect(TRect& rect1);// Óñòàíîâèòü çíà÷åíèå 0 â rect
    void     NullLine(TCell& Cell);// Óñòàíîâèòü çíà÷åíèå 0 â Line
    void     RecalculationEndCell(int Col, int Row);// Ïåðåñ÷åò ïîñëåäíåé ÿ÷åéêè
    void     FForAll(TRect& rect, TMyFunc Func);
    int      ProcessCell(int Col, int Row, void * TheItem);
    bool     TestingRectToSelection(TCell* Cell, const TRect RectSelection);// Íàõîäèòüñÿ ëè îáúåäåíåííàÿ ÿ÷åéêà  â çàäàííîì Recte
    void     SelectAllCells(); // Âûäåëèòü âñþ òàáëèöó
//********************* Ðàçíîå END

//********************* Function MouseMoveCell and CursorDraw
    void     DrawCursor(const TRect& Rect);// Ðèñóåì êóðñîð
    void     DrawCursorU2(int CurCol, int CurRow, int iLeft,int iTop,int iRight,int iBottom);// Ðèñóåì êóðñîð
    void     DrawCursorMove(const TRect& Rect, int Width);
    TColor   SetColorCursor(TColor& Color);// Óñòàíîâèòü öâåò êóðñîðà
    void     DrawCursorMove(int Col, int Row);// Ðèñóåì êóðñîð ïåðåòàñêèâàíèÿ ÿ÷ååê
    void     DrawCursorMove2(int Col, int Row);// Ðèñóåì êóðñîð ïåðåòàñêèâàíèÿ ÿ÷ååê Óðîâåíü 2
    bool     SelectAllJobField(); // Âûäåëåííî âñå ðàáî÷åå ïîëå
    void     StartScrollingTimer1(TGridCoord& CellHit1);
    void     StartScrollingTimer2(TGridCoord& CellHit1);

//********************* Function MouseMoveCell END

//********************* Function  ïî ðàáîòå ñ îáúåäåíåíûìè ÿ÷åéêàìè
    // Ðàñ÷åò âûäåëåííîé îáëàñòè
    void    RecalculateSelection();
    TRect&  GetValidSelection();
    TRect&  GetValidSelectionPlus();
    TRect&  GetValidSelectionMinus();
    // Ðàñ÷åò âûäåëåííîé îáëàñòè END

    TRect        GetAnchorCurrentSort();// ïîëó÷èòü ðåçóëüòàò îòñîðòèðîâàíûõ FCurrent è FAnchor
    void         SetAnchorCurrentSort();// îòñîðòèðîâàòü FCurrent è FAnchor
    TGridRect    GetAnchorCurrentSortGrid();// îòñîðòèðîâàòü FCurrent è FAnchor
    TRect        GetAnchorCurrentSortPlus();// îòñîðòèðîâàòü FCurrent è FAnchor è zoom íà +1 ÿ÷åéêó
    TRect        GetJobAnchorCurrentSort();// îòñîðòèðîâàòü FCurrentJob è FAnchorJob
    void         SetUnionCell(bool Test);// Ñîçäàòü îáúåäåíåííóþ ÿ÷åéêó
    void         SetUnionCell(const TRect& rect,bool Test);// Ñîçäàòü îáúåäåíåííóþ ÿ÷åéêó
    TRect        CalculationRect(TGridCoord mousestart, TGridCoord mousemove);// Ïîëó÷èòü ðåêò ïî êîîðäèíàòàì
    TRect        CalculationRect(int StartX, int StartY, int EndX, int EndY);// Ïîëó÷èòü ðåêò ïî êîîðäèíàòàì
    TRect        CalculationRect(const TRect& rect);// Ïîëó÷èòü ðåêò ïî êîîðäèíàòàì
    TRect        SideRect1InRect2(const TRect& rect1, const TRect& rect2);// ñòðîíà rect1 ìèíüøå èëè ðîâíà ñòîðîíå rect2
    bool         CellInRect(const TRect& rect, const TGridCoord& cell);// ïðèíàäëåæèò ëè ÿ÷åéêà îáúåäåíåííîé ÿ÷åéêå
    bool         CellBeUnionCell(const TGridCoord& cell);// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà îáúåäåíåííîé
    bool         CellBeUnionCell(int Col, int Row);// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà îáúåäåíåííîé
    void         DeleteUnionRect(TCell* Cell);// Óäàëèòü âñþ îáúåäåíåííóþ ÿ÷åéêó
    void         DelUnionCell(TCell* Cell);// Óäàëèòü òîëüêî èíôó îá îáúåäåíåíèè
//********************* Function  ïî ðàáîòå ñ îáúåäåíåíûìè ÿ÷åéêàìè

//********************* Function Ðèñîâàíèÿ áîðäþð
//############# Íàõîäÿòñÿ â DrawBorder #############
    void  CellLineTop(const TRect& Rect);
    void  CellRightBottomPixel(const TRect& RectStart);
    void  CellRightBottomPixel2(const TRect& RectStart);
    void  CellLineBottom(const TRect& Rect);
    void  CellLineBottomColorBk(int Col, int Row);
    void  CellLineTopColorBk(int Col, int Row);
    void  CellLineLeft(const TRect& Rect);
    void  CellLineRight(const TRect& Rect);
    void  CellLineRightColorBk(int Col, int Row);
    void  CellLineLeftColorBk(int Col, int Row);
    void  CellLineTop2(const TRect& Rect);
    void  CellLineBottom2(const TRect& Rect);
    void  CellLineLeft2(const TRect& Rect);
    void  CellLineRight2(const TRect& Rect);
    void  Line(int Col, int Row, TColor Color);// Îòðèñîâàòü ëèíèè ñîãëàñíî ïàðàìåòðàì ÿ÷åéêè
    void  SetBorder(int Col, int Row, /*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine, TColor Color);
    void  SectionLine(const TRect& Rect,int Param/*1=Left, 2=Top*/);
    void  CellLineBottomSection(const TRect& RectStart);
    void  CellLineRightSection(const TRect& RectStart);
    void  CellLineBottom2b(const TRect& RectStart);
    void  CellLineRight2b(const TRect& RectStart);
    bool  TopLineUnion(int Col, int Row);// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà ïðîñòîé èëè Union íî îòëè÷íîé îò íèæíåãî Union
    bool  BottomLineUnion(int Col, int Row);// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà ïðîñòîé èëè Union íî îòëè÷íîé îò èåðõ Union
    bool  LeftLineUnion(int Col, int Row); // ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà ïðîñòîé èëè Union íî îòëè÷íîé îò Ïðàâî Union
    bool  RightLineUnion(int Col, int Row); // ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà ïðîñòîé èëè Union íî îòëè÷íîé îò Ëåâî Union
    void  DrawBorder_0(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void  DrawBorder_1(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void  DrawBorder_2(int Col, int Row, int Border, const TRect& rect, TColor Color);
    int   GetLeftBorder(int Col, int Row);// Ïîëó÷èòü òîëùèíó
    int   GetTopBorder(int Col, int Row);// Ïîëó÷èòü òîëùèíó
    int   GetRightBorder(int Col, int Row);// Ïîëó÷èòü òîëùèíó
    int   GetBottomBorder(int Col, int Row);// Ïîëó÷èòü òîëùèíó
    int   GetLeftBorderEliminateCurrent(int Col, int Row);// Ïîëó÷èòü òîëùèíó Èñêëþ÷àÿ ñåáÿ
    int   GetTopBorderEliminateCurrent(int Col, int Row);// Ïîëó÷èòü òîëùèíó Èñêëþ÷àÿ ñåáÿ
    int   GetRightBorderEliminateCurrent(int Col, int Row);// Ïîëó÷èòü òîëùèíó Èñêëþ÷àÿ ñåáÿ
    int   GetBottomBorderEliminateCurrent(int Col, int Row);// Ïîëó÷èòü òîëùèíó Èñêëþ÷àÿ ñåáÿ
    void  SetCircumferentialBorder(int Col, int Row);// Çàïîëíèòü îêðóæàþùèå ÿ÷åéêè áîðäþðàì èç òåêóùåé
    void  SetCircumferentialBorderRow(int Col, int Row);// Çàïîëíèòü îêðóæàþùèå ÿ÷åéêè áîðäþðàì ïî òåêóùèì ïàðàìåòðàì Ïðèîðèòåò ñòðîê
    void  SetCircumferentialBorderCol(int Col, int Row);// Çàïîëíèòü îêðóæàþùèå ÿ÷åéêè áîðäþðàì ïî òåêóùèì ïàðàìåòðàì Ïðèîðèòåò ñòîëáöîâ
    void  SetToCellBorder(int Col, int Row);//Çàïîëíèòü òåêóùþþ ÿ÷åéêó áîðäþðàì
//############# Íàõîäÿòñÿ â DrawBorder ############# END
//********************* Function End

//********************* Function Fixed
    void  SetScrollStartCol();// Ïðîñêðîëèðîâàòü âñå ñòîëáöû íà íà÷àëî
    void  SetScrollStartRow();// Ïðîñêðîëèðîâàòü âñå ñòðîêè íà íà÷àëî
//********************* Function Fixed END

//********************* Function Test
    void  Test_CellInfo(TGridCoord& CellHit1);
    void  Test_Speed();
//********************* Function Test End

//********************* Function User
//############# Íàõîäÿòñÿ â SetCellParameter #############
    bool  GetVisibleOfficialMargin(); // Îòîáðàæåíèå Ïîëåé ñ íóìåðàöèåé
    void  SetVisibleOfficialMargin(bool Visible);// Îòîáðàæåíèå Ïîëåé ñ íóìåðàöèåé
    bool  GetVisibleSectionLeft(); // Îòîáðàæåíèå ñåêöèé
    void  SetVisibleSectionLeft(bool Visible); // Îòîáðàæåíèå ñåêöèé
    bool  GetVisibleSectionTop(); // Îòîáðàæåíèå ñåêöèé
    void  SetVisibleSectionTop(bool Visible); // Îòîáðàæåíèå ñåêöèé
    void  SetColorRegion(TColor Color, bool FlagLineColor); // Óñòàíîâèòü öâåò âûäåëåííîé îáëàñòè
    void  SetFontNameRegion(AnsiString FontName); // Óñòàíîâèòü Øðèôò âûäåëåííîé îáëàñòè
    void  SetFontSizeRegion(int FontSize); // Óñòàíîâèòü Ðàçìåð Øðèôò âûäåëåííîé îáëàñòè
    void  SetFontColorRegion(TColor FontColor); // Óñòàíîâèòü Öâåò Øðèôòà âûäåëåííîé îáëàñòè
    void  SetValueTypeRegion(int ValueType);// Óñòàíîâèòü Òèï Çíà÷åíèÿ (òåêñò =0, âûðàæåíèå =1, øàáëîí =2)
    void  SetTextHAlignRegion(int TextHAlign);// Óñòàíîâèòü Âûðàâíèâàíèå òåêñòà ïî ãîðèçîíòàëè (Left=0, Center=1, Right=2)
    void  SetTextVAlignRegion(int TextVAlign);// Óñòàíîâèòü Âûðàâíèâàíèå òåêñòà ïî âåðòèêàëè (Left=0, Center=1, Right=2)
    void  SetTypeAutoSizeRegion(int TypeAutoSize);// Óñòàíîâèòü àâòî ðàçìåð ñòðîêè ïî òåêñòó (Not=0, Auto=1)
    void  SetTextWordBreakRegion(int TextWordBreak);// Óñòàíîâèòü àâòî ïåðåíîñ ïî ñëîâàì (Not=0, Auto=1)
    void  SetFontStyleRegion(int FontStyle); // Óñòàíîâèòü Ñòèëü Øðèôòà âûäåëåííîé îáëàñòè (Îáû÷íû=0, Êóðñèâ=1, Æèðíûé=2, Æèðíûé êóðñèâ=3)
    void  SetFontStrikeOutRegion(int FontStrikeOut); // Óñòàíîâèòü çà÷åðêíóòûé øðèôò
    void  SetFontUnderlineRegion(int FontUnderline); // Óñòàíîâèòü ïîä÷åðêíóòûé øðèôò (ÍÅÒ=0, ïîä÷åðêíóòûé=1)
    void  SetCellLine(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// çàïèñàòü ïàðàìåòðû îáâåäåííîé ãðàíèöû â ÿ÷åéêè
    void  SetCellBorder(const TRect& Rect, int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// Íèæíèé óðîâåíü äëÿ SetCellLine
    void  SetCellLineFlood(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// çàïèñàòü ïàðàìåòðû çàëèâêè ãðàíèöû â ÿ÷åéêè
    void  SetCellLineOne(/*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine);// Óñòàíîâèòü áîðäþðû ïî îäíîìó
    void  SetCellBorderOne(const TRect& Rect ,int Border, int WidthLine);// Íèæíèé óðîâåíü äëÿ SetCellLineOne
    void  SetCellLineFloodVert(int WidthLine);// Çàïîëíèòü âåðòèêàëüíûìè ëèíèÿìè
    void  SetCellBorderFloodVert(const TRect& Rect, int WidthLine);// Íèæíèé óðîâåíü äëÿ SetCellLineFloodVert
    void  SetCellLineFloodHorz(int WidthLine);// Çàïîëíèòü ãîðèçîíòàëüíûìè ëèíèÿìè
    void  SetCellBorderFloodHorz(const TRect& Rect, int WidthLine);// Íèæíèé óðîâåíü äëÿ SetCellLineFloodHorz
    void  SetNotChangeParamRegion(const TRect& rectcopy);// Ñîçäàòü ÿ÷åéêó çàïîëíèòü ïàðàìåòðàìè â ñîîòâåòñòâèè ñ åå ïîëîæåíèåì íî íîâûõ èçìåíåíèé íå âíîñèòü (äëÿ CopyCell)
    void  UseTextWordBreakRegion();// Ïðèìåíèòü ïåðåíîñ ïî ñëîâàì ê âûäåëåííîé îáëàñòè

    void  SetFlagRect(const TRect& SetRectCell, TCellFlag* CellFlag);// Óñòàíîâèòü ïàðàìåòð
    void  SetFlagCell(int Col, int Row, TCellFlag* CellFlag);// Óñòàíîâèòü ïàðàìåòð
    void  AssignParamCell(TCellFlag* CellFlag, int Col, int Row);// Ïðàâåðêà íóæíûõ ïàðàìåòðîâ
    bool  ParamCellCompare(TCell* Cell, TCellFlag* CellFlag);// Ïðîâåðêà íà îäèíàêîâîñòü ïàðàìåòðîâ ÿ÷ååê
    void  SetAllFlag(TCellFlag* CellFlag, bool Set); // Óñòàíîâèòü âñå ôëàãè
    void  CopyFlag1ToFlag2(TCellFlag* CellFlag1, TCellFlag* Cell);// Êîïèðîâàòü çàíà÷åíèÿ óñòàíîâëåííûõ ôëàãîâ è óñòàíîâèòü äàííûå ôëàãè
    // Matrix
    void  PasteBuffInGrid(int Col, int Row); //Âñòàâèòü èç áóôåðà â Grid
    void  CopyInBuff(const TRect& rect);// Êîïèðîâàòü â áóôôåð
    void  GetCellToTest(const TRect& rect);
    int   ProcessCellTest(int Col, int Row, void * TheItem);
    int   ProcessCellTest2(int Col, int Row, void * TheItem);
    void  SetParam(const TRect& rect,TCellFlag* CellFlag);// Çàïîëíåíèå ìàòðèöû è çàòåì ïðèìåíåíèå äëÿ Recta
    void  SetListFillingToCopy(const TRect& rect);
    int   CellYes(int Col, int Row, void * TheItem);
    // Matrix END
//############# Íàõîäÿòñÿ â SetCellParameter ############# END
//********************* Function User END

//********************* Function Job Rect
    TRect        GetSelectGridRect(); // Ïîëó÷èòü âûäåëåííûé ðåãèîí â ÿ÷åéêàõ
    TRect        GetRectCellSort(const TRect& rect);// Îòñîðòèðîâàòü rect
    void         SetRectCellSort(TRect& rect);// Îòñîðòèðîâàòü rect è óñòàíîâèòü
    TRect        GetRectCellSort(const TGridRect& rect);// Îòñîðòèðîâàòü rect
    TGridRect    GetGridRectCellSort(const TGridRect& rect);// Îòñîðòèðîâàòü rect
    TRect        GetUnionRect(const TRect& rect1,const TRect& rect2); // Ïîëó÷èòü îáúåäåíåíèå rect1 ñ rect2
    TRect        GetUnionRect(const TGridRect& rect1, const TGridRect& rect2); // Ïîëó÷èòü îáúåäåíåíèå rect1 ñ rect2
    TGridRect    GetUnionGridRect(const TGridRect& rect1,const TGridRect& rect2); // Ïîëó÷èòü îáúåäåíåíèå rect1 ñ rect2
    TGridRect    RectToGridRectType(const TRect& rect);// Òèï TRect â TGridRect
    TRect        GridRectToRectType(const TGridRect& rect);// Òèï TGridRect â TRect
    TRect        Zoom(const TRect& rect, int zoom);// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    TGridRect    ZoomGrid(const TRect& rect, int zoom);// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    TGridRect    ZoomGrid(TGridRect& rect, int zoom);// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    void         ClipRectToJobRect(TRect& rect);// Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    void         ClipRectToJobRect(TGridRect& rect);// Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    void         ZoomAndClipRectToJobRect(TRect& rect,int zoom);// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom è Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    void         ZoomAndClipRectToJobRect(TGridRect& rect,int zoom);// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom è Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    TRect        GetGridRectCell(int iCol,int iRow);// Âîçâðàùàåò Rect â ÿ÷åéêàõ ïî ïîçèöèè Col è Row
    int          SumRow(int Start, int End);// ïîëó÷èòü âûñîòó â ïèêñåëÿõ îò ÿ÷åéêè Start äî ÿ÷åéêè End
    int          SumCol(int Start, int End);// ïîëó÷èòü øèðèíó â ïèêñåëÿõ îò ÿ÷åéêè Start äî ÿ÷åéêè End
    TRect        GetGridRectToRectPixelNotUnion(int iCol,int iRow);// Âîçâðàùàåò Rect â ïèêñåëÿõ
    TRect        GetGridRectToRectPixelNotUnionReal(int iCol,int iRow);// Âîçâðàùàåò Rect â ïèêñåëÿõ â ðåàëüíûõ êîîðäèíàòàõ (áåç ñêðîëèðîâàíèÿ)
    TRect        GetGridRectToRectPixelNotUnionAndScroll(int iCol,int iRow);// Âîçâðàùàåò Rect â ïèêñåëÿõ ñ ó÷åòîì ñêðîëòðîâàíèÿ
    TRect        GetGridRectToRectPixelForBorder(int Col,int Row);// Âîçâðàùàåò Rect â ïèêñåëÿõ Áåç ó÷åòà îáúåäåíåííûõ
    TRect        GetGridRectToRectPixelUnionReal(int iCol,int iRow);// Âîçâðàùàåò Rect â ïèêñåëÿõ â Real è ñ ó÷åòîì Union
    bool         BeEqualRect(const TRect& rect1, const TRect& rect2); // ðàâåíû ëè rect1 è rect2
    bool         EqualSizeRect(const TRect& rect1, const TRect& rect2);// ðàâåíû ëè rect1 è rect2 ïî ðàçìåðàì
    bool         Rect1InRect2(const TRect& rect1, const TRect& rect2);// Íàõîäèòüñÿ rect1 âíóòðè rect2
    bool         PointInRect(int Col, int Row,const TRect& Rect);// Íàõîäèòüñÿ ÿ÷åéêà âíóòðè rect
    int          CalcColumnWidthAutoText(int Col, int Row);// Ðàñ÷åò Max øèðèíû ñòîëáöà ïî òåêñòó
    int          CalcStringHeightAutoText(int Col, int Row);// Ðàñ÷åò Max âûñîòû ñòðîêè ïî òåêñòó
    void         ClipByEndCell(TRect& rect);// Îáçåçàòü Rect ïî ïîñëåäíåé ñóù ÿ÷åéêå è ñêîððåêòèðîâàòü ïî ñòîëáöàì
    bool         Rect1CrossRect2(const TRect& rect1, const TRect& rect2); // Ïåðåñåêàþòüñÿ ëè rect1 è rect2 òîãäà OK
    bool         PointInCut(const TPoint& cut, int point); // òî÷êà íàõîäèòüñÿ â ïðîìåæóòêå cut

//********************* Function Job Rect END

//************* Ìåòîäû ñòàíäàðòíîãî Paint*************
//############# Íàõîäÿòñÿ â DrawCells #############
    void     Paint();
    void     DrawCells(long ACol,long ARow,int StartX,int StartY,int StopX,int StopY,TColor Color,TGridDrawState IncludeDrawState);
    void     SetColorCanvas(int CurCol, int CurRow);
    void     SetNumerColRow(int ACol, int ARow, int type,TColor ColorBk); // Ïðîíóåðîâàòü ïîëÿ ñ íóìåðàöèåé
    bool     PointInGridRect(int Col, int Row,TGridRect Rect);
    void     DrawTextU2(int CurCol, int CurRow, const TRect& RectDrawText);// Ðèñîâàíèå òåêñòà
//############# Íàõîäÿòñÿ â DrawCells ############# END
//************* END *************

    // __property bool VisibleOfficialMargin {read=GetVisibleOfficialMargin, write=SetVisibleOfficialMargin}; // [manual migration needed]
    // __property bool VisibleSectionLeft {read=GetVisibleSectionLeft, write=SetVisibleSectionLeft}; // [manual migration needed]
    // __property bool VisibleSectionTop {read=GetVisibleSectionTop, write=SetVisibleSectionTop}; // [manual migration needed]
};
//---------------------------------------------------------------------------
class TOffsetCell;
class COMMONAL_API TMGrid : public TMyObject {
private:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TMGrid();
    ~TMGrid();

    TMDelTList<int> Cols;
    TMDelTList<int> Rows;
    TMDelTList<TCell> Cells;
    int CopyWidth;
    int CopyHeight;

    TOffsetCell* OffsetCell;
    bool CutCells; // Âûðåçàòü ÿ÷åéêè
    int iOffsetCell; // Íàïðàâëåíèå ñäâèãà ÿ÷ååê ïðè óäàëåíèè (0=Ââåðõ, 1=Âëåâî)
    void  ToCellGrid(TCellGrid* CellGrid);// Çàãðóçèòü
    void  FromCellGrid(TCellGrid* CellGrid);// Ñîõðàíèòü
    void  DelTextToCellGrid(TCellGrid* CellGrid);// Óäàëåíèå òåêñòà
    void  CorrectionRect(TCellGrid* CellGrid, TRect& rect);// Êîððåêòèðîâêà ðåêòà ïðè âûäåëåíèè âñåé îáëàñòè
    void  DelCells(TCellGrid* CellGrid, const TRect& rect); // Óäàëåíèå ÿ÷ååê
    void  dCopyCellGrid(TCellGrid* CellGrid, const TRect& RectCopy); // âñïîìîãàòåëüíûå äëÿ óäàíåíèÿ
    void  dPasteToCellGrid(TCellGrid* CellGrid, int DeltaX, int DeltaY);// âñïîìîãàòåëüíûå äëÿ óäàíåíèÿ
};

extern COMMONAL_API TClassNode* TMGrid::StaticType;
extern COMMONAL_API TMGrid MClipBoard;
//---------------------------------------------------------------------------
class COMMONAL_API TCellMatrix : public TMyDrawGrid  {
protected:
private:
    void* FData;
public:
    TCellFlag* gCellFlag;
    TCellGrid* CellGrid;
    TGridCoord EndCell;

    TRect RectCopy;
    TRect DelRect;

    int ColCount;
    int RowCount;
    
    bool FieldCut;
    bool CopyCell;

//********************* Function System
      TCellMatrix(Classes::TComponent* AOwner, TCellGrid* _CellGrid);
	inline       virtual ~TCellMatrix(void);

    void        Initialize();
    void*        EnsureDataRow(int aRow);
    void         SetCell(int aCol, int aRow, TCellFlag* data);//
    TCellFlag*   GetCell(int Col, int Row);// Ïîëó÷èòü äàííûå î ÿ÷åéêå ñ ó÷åòîì îáúåäåíîíîé
    TCellFlag*   GetCellSimple(int Col, int Row);// Ïîëó÷èòü äàííûå î ÿ÷åéêå Áåç ó÷åòà îáúåäåíåíîé
    void         FForAll(TRect& rect, TMyFunc Func);
    void         MatrixForAllTest();
    void         NewCell(int Col, int Row, TCellFlag* data);
    void         NewCell(int Col, int Row);
    void         DelCell(int Col, int Row);
    void         SetAllFlag(TCellFlag* CellFlag, bool Set);
    void         CopyCell1ToCell2(int Col,int Row, TCellFlag* Cell2);
    TCellFlag*   GetCellParam(int Col, int Row);
    TCellFlag*   GetParamCell(int Col, int Row); // Ïîëó÷èòü ÿ÷åéêó ñî âñåìè ïàðàìåòðàìè
    TCellFlag*   GetParamCellAndFlag(int Col, int Row);
//********************* Function System END

    void  ClearAll();
    int  ProcessMx(int Col, int Row, void * TheItem);
};
//---------------------------------------------------------------------------

#endif
