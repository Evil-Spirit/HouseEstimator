//---------------------------------------------------------------------------
#ifndef CellGridH
#define CellGridH
#include "GridRoutineU.hpp"
#include "UNDO.h"
//---------------------------------------------------------------------------

// ----------- Const ------------------
    const int iPixelTact=2;
//*********************  Color **********
//    const TColor ColorSelect =RGB(182,202,234); // ��������� ���������� �����
//    const TColor ColorSelect =RGB(109,149,213); // ��������� ���������� �����
//    const TColor ColorSelect =RGB(255,255,255); // ��������� ���������� �����
    const TColor ColorFixedSelect =RGB(248, 247, 239);// �������� ��� ������ ��� �������
    const TColor ColorFixedSelectAll =RGB(255, 192, 111); // �������� ��� �������
//*********************  Color ********** END



class TGridForm;
#pragma option push -b-
enum TTextVAlign {tvaTop,tvaCenter,tvaDown};
#pragma option pop
class TCell;
class TCellMatrix;


class COMMONAL_API TCell : public TMyObject{
// ������ � �������
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    void Assign(TMyObject* MO);
    bool UndoRegistered;

    TCell();
    ~TCell();

    TColor bgColor;// ���� ����
    bool LineColorNot;// ���� ������� ������� ���� � ������
    AnsiString Text;// ����� � ������
    AnsiString FontName;// �����
    TColor FontColor;// ���� ������
    struct TLineWidth // ������� ������� � ��� ���
    {
        byte WidthLeft;
        byte WidthTop;
        byte WidthRight;
        byte WidthBottom;
    } Line;
    TRect* UnionRect;// ������������ ������ (������ ������ � ��������� � �������)

    struct TCellFlags
    {
        unsigned FontSize:8;// ������ ������
        unsigned FontStyle:3;// ����� ������ (������=0, ������=1, ������=2, ������ ������=3)
        unsigned FontStrikeOut:1;// ����������� ����� (���=0, �����������=1)
        unsigned FontUnderline:1;// ������������ ����� (���=0, ������������=1)
        unsigned ValueType:2;// ��� �������� (����� =0, ��������� =1, ������ =2)
        unsigned TypeAutoSize:2;// ��� ������������ ������ � ������ (��� ���� =0, ���� ������ ������ =1)
        unsigned TextHAlign:2;// ������������ ������ �� ����������� (Left=0, Center=1, Right=2)
        unsigned TextVAlign:2;// ������������ ������ �� ��������� (Left=0, Center=1, Right=2)
        unsigned TextWordBreak:1;// ������� �� ������ (�� ����������=0, ����������=1)
        unsigned TextHeightAuto:1;// ��������� ������ ������ ��� ��������� ����� (�� ���������=0, ���������=1)

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
// ������ � �������� ���������
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
// ������ � �������� ���������
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCellColRow();
    ~TCellColRow();
    int ColRowWidth;
};
extern COMMONAL_API TClassNode* TCellColRow::StaticType;

class COMMONAL_API TCellTab : public TCell{
// ������ � �������
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
// ������������ ������
public:
    __fastcall TCellList(TSPAQuantum Quantum)
    :TSparseList(Quantum){};
    void __fastcall Put(int index, TCell * item);
    TCell* __fastcall Get(int index);
};

//---------------------------------------------------------------------------
class TEditText;
class TToolBarCellGrid;

class COMMONAL_API TCellGrid : public TMyDrawGrid {
// ���������
protected:
	virtual void __fastcall WndProc(Messages::TMessage &Message);
private:
    void* FData;
__published:

public:
    TToolBarCellGrid* ToolBarCellGrid;
    TEditText* EditText; // RichEdit -��� ����� ������ � ������

// ���������� ������ Paint
    bool InvalidateRectOK;
    bool StartVisible;
    bool bResizeColRow;

    TGridCoord oldFCurrent;
    TGridCoord oldFAnchor;
    int iMouseDown;
    int iMouseMove;
    TPoint EndColRowCell; // ��������� ������������ ������

    TRect CurrentRectMouseDown;
//    bool FieldCut;
//    PIntArray PointsCopy;
    TRect OldRectDown;//��� ���������� ��������� ��� ������ �� ������������ ������
    TRect OldRectDownCurrentAnchor;//��� ���������� ��������� ��� ������ �� ������������ ������


    TRect OldRectMouseDown;
    TRect OldRectMouseDown2;

    TColor ColorSelect;

//    bool MouseDownAndMoveCursor;

    bool MoveCellBorder;
// ���������� ������ Paint - END

// ���������� ������ Paint V2
//    TRect OldRectCurrentAnchorMouseDown;
    TRect OldRectCurrentAnchorMouseMove;
    TGridRect OldRectCurrentAnchorMouseMoveCell;
    TGridCoord OldCellMouseMove;
    TGridCoord JobFCurrent;
    TGridCoord JobFAnchor;
// ���������� ������ Paint END

// ���������� ������ Paint V4
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

    TPoint CellGridResizeRow; // ��� ��������� ������� ������ �����
    TPoint CellGridResizeCol; // ��� ��������� ������� ������ �����
    int NewSizeColRow;

//*********************  Color **********
    TColor ColorCursor; // ����������� ���
//*********************  Color ********** END

    TRect FValidSelection;
    TRect FValidSelectionPlus;
    TRect FValidSelectionMinus;
    TGridRect FValidCurAnchor;
//    int iCountCalculation;

    TGridCoord DrawCursCurrent;
    TGridCoord DrawCursAnchor;

    bool PopupMenuNotMouseUp;// ��� ���� ����� ����� ������ �� ������ MouseUP ��� ����������� ���������� ����������� �����
//********************* Function System
    bool SelectTable; // �������� �������
    bool SelectColumn;// ������� �������
    bool SelectString;// �������� ������
    bool SelectCell;// �������� ������

    int XM;
    int YM;
    TGridCoord MousePosCellMoveSelect;

    TMDelTList <TPoint> ListFilling; // ������ ����� ���������� ���������
    TMDelTList <TPoint> ListFilling2; // ������ ����� ���������� ���������
    TRect OldCurrentAnchorSort;
//********************* Function System END

    bool PrivatEvent_1;// ������������ ����� Scrool (����� � ��� ���� ����� � Fixed)
    bool PrivatEvent_2;// ������������ ��� ��� MouseDown

    int OldRectDrawCellFixedT; // ��� �������� ������������� ��������� �������� Top ������������ ������
    int OldRectDrawCellFixedL; // ��� �������� ������������� ��������� �������� Left ������������ ������
    int OldRectDrawCellFixedTop;
    int OldRectDrawCellFixedLeft;
    TRect CurrentRectDrawUnionFixed;// ���� ������� UnionCell

// ���������� ������ Paint END4
// ���������� ��� �����
    int iTest1;
    int iTest2;
// ���������� END

// ���������� Edit
    TRect CurrentEditCell;
    AnsiString TempStringCell;
    int CurrentEditCol;
    int CurrentEditRow;
// ���������� Edit End

// ���������� ������������ Paint
    TGridDrawInfo DrawInfo;
    TGridRect Sel;
    TRect UpdateRect;

    bool Focused;

    TGridForm* GridForm;
    TCellFlag* gCellFlag;// ��� ��������� ������
    TMDelTList <TMDelTList <TCellFlag> > CellF;
    bool ProgressCopy;
// ���������� ������������ END
    TTimer* Timer;
    TTimer* TStart;

    // - Matrix -
    TCellMatrix* Matrix;
    // - Matrix - END

    void __fastcall OnTimer(TObject *Sender);
    void __fastcall StartTime(TObject *Sender);

    __fastcall TCellGrid(Classes::TComponent* AOwner, TGridForm* _Form, TToolBarCellGrid* _ToolBarCellGrid);
	inline __fastcall virtual ~TCellGrid(void);
    void Initialize();


//********************* Function System
    void        __fastcall NewCell(int Col, int Row);// ������� ����� ������
    void        __fastcall NewCell(int Col, int Row, TCell* data);// ������� ����� ������
    void        __fastcall DelCell(int Col, int Row);// ������� ������

    void        __fastcall SetCell(int aCol, int aRow, TCell* data);//
    void        __fastcall SetNewCell(int aCol, int aRow, TCell* data);
    void        __fastcall NewCellAndSetDefault(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // ������� ������ � ��������� �� Default
    void        __fastcall NewCellAndSetDefault2(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // ������� ������ � ��������� �� Default

    void        __fastcall NewCellAndSetParam(int Col, int Row);// ������� ����� ������ � ��� ������������� ������� �� �����������
    TCellFlag*  __fastcall GetParamCell(int Col, int Row); // �������� ������ �� ����� �����������
    void        __fastcall ClearSelectRect();// ������� ���������� �������
    void        __fastcall ClearSelectRect(const TRect& rect);// ������� Recta
    void        __fastcall ClearCell(int Col, int Row);// ������� ������
    void        __fastcall DelAndSetDefaultCell(int Col, int Row);// ������� � ��������� Defaultam �� 0:0
    void        __fastcall DelAndSetDefaultCell(const TRect& Rect);// ������� � ��������� Defaultam �� 0:0
    void        __fastcall DelAndSetDefaultCellF(const TRect& Rect);// ������� � ��������� Defaultam �� 0:0
    int         __fastcall DelCellF(int Col, int Row, void * TheItem);// ��� DelAndSetDefaultCellF
    void        __fastcall GetSelectCells(bool AllUnion); // ���������� ListFilling
    //(x,y) ����� ��� ���������
    //(AllUnion ���� true ����� ���� ������������ ������ �������� �������
    //� ���������� ������� ����� �������� � ������ ����� ��������� ������� ������������ ������)

//    void        __fastcall GetSelectCellsColRow(); // ���������� ListFilling (x,y) (�����, ��������) - ��� �����
    void        __fastcall ClearListFilling();// ������� ListFilling
    void        __fastcall SetDefaultCell11(); // ������������� � ������ 1:1 �������� Default
    void*       __fastcall EnsureDataRow(int aRow);
    TCell*      __fastcall GetCell(int Col, int Row);// �������� ������ � ������ � ������ �����������
    TCell*      __fastcall GetCellSimple(int Col, int Row);// �������� ������ � ������ ��� ����� �����������
    TCell*      __fastcall GetCellParam(int Col, int Row); // �������� ��������� ������
    TCell*      __fastcall GetCellParamSimple(int Col, int Row);// �������� ��������� ������
    void        __fastcall CopyCell1ToCell2(int Col1, int Row1, int Col2, int Row2);// ����������� �� Cell1 � Cell2
    void        __fastcall CopyCell1ToCell2(int Col,int Row, TCell* Cell2);// ����������� �� Col,Row � Cell2
    void        __fastcall CopyCell1ToCell2(TCell* Cell1, int Col,int Row);// ����������� �� Cell2 � Col,Row
    void        __fastcall InvalidateRect2(const TRect& rect);
    __property TCell* Cells[int i][int j] = {read = GetCell,write = SetCell};
//********************* Function System END

//********************* Function Undo/Redo
    void UndoRegister(int Col, int Row, TGridRegisterMode RM);
//********************* Function Undo/Redo ENDS

//********************* Function Form
    void __fastcall DoModalFormSection();
    void __fastcall DoModalFormCellParameter();
    void __fastcall DoModalSelectColor(int Left, int Top);
//********************* Function Form End

//********************* ��������� ��������� � ��������������� ������
    void            __fastcall CellGridMouseMove(TObject *Sender,TShiftState Shift, int X, int Y);// ���������� ���� ��������
    void            __fastcall CellGridMouseDown(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// ���������� ���� Key � ����
    void            __fastcall CellGridMouseUp(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// ���������� ���� Key � ���
	DYNAMIC bool    __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);// ����� �� �������� � ����
    DYNAMIC bool    __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);// ����� �� �������� � ���
    bool            __fastcall DoMouseWheelLeft(Classes::TShiftState Shift, const Types::TPoint &MousePos);// ����� �� �������� � ����
    bool            __fastcall DoMouseWheelRight(Classes::TShiftState Shift, const Types::TPoint &MousePos);// ����� �� �������� � �����
    DYNAMIC void    __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);// ���������� ����������
    void            __fastcall ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft);// ���������� ������������� ����������
    void            __fastcall ResizeRow(int Index, int OldSize, int NewSize);
    void            __fastcall ResizeCol(int Index, int OldSize, int NewSize);
//********************* ��������� ���������  � ��������������� ������ END

//********************* Function EditText
    void    __fastcall ShowEditText(int Col, int Row, bool clear); // �������� ���� �����
    void    __fastcall SetCanvasParameterCell(int Col, int Row);// ���������� � Canvas ��������� ������
    int     __fastcall GetAlignText(int Col, int Row);// �������������������� ������ ��� DrawText
    void    __fastcall GetRectDrawText(int Col, int Row, const AnsiString& Text, TRect& calcrect);// ��������� ���� ����������� ��� �����
    void    __fastcall UseTextWordBreak(int Col, int Row);// ��������� ������� �� ������
//********************* Function EditText

//********************* ������
    void    __fastcall InvalidateU2();// Invalidate 2��� ������
    void    __fastcall NullRect(TRect& rect1);// ���������� �������� 0 � rect
    void    __fastcall NullLine(TCell& Cell);// ���������� �������� 0 � Line
    void    __fastcall RecalculationEndCell(int Col, int Row);// �������� ��������� ������
    void    __fastcall FForAll(TRect& rect, TMyFunc Func);
    int     __fastcall ProcessCell(int Col, int Row, void * TheItem);
    bool    __fastcall TestingRectToSelection(TCell* Cell, const TRect RectSelection);// ���������� �� ������������ ������  � �������� Recte
    void    __fastcall SelectAllCells(); // �������� ��� �������
//********************* ������ END

//********************* Function MouseMoveCell and CursorDraw
    void    __fastcall DrawCursor(const TRect& Rect);// ������ ������
    void    __fastcall DrawCursorU2(int CurCol, int CurRow, int iLeft,int iTop,int iRight,int iBottom);// ������ ������
    void    __fastcall DrawCursorMove(const TRect& Rect, int Width);
    TColor  __fastcall SetColorCursor(TColor& Color);// ���������� ���� �������
    void    __fastcall DrawCursorMove(int Col, int Row);// ������ ������ �������������� �����
    void    __fastcall DrawCursorMove2(int Col, int Row);// ������ ������ �������������� ����� ������� 2
    bool    __fastcall SelectAllJobField(); // ��������� ��� ������� ����
    void    __fastcall StartScrollingTimer1(TGridCoord& CellHit1);
    void    __fastcall StartScrollingTimer2(TGridCoord& CellHit1);

//********************* Function MouseMoveCell END

//********************* Function  �� ������ � ������������ ��������
    // ������ ���������� �������
    void    RecalculateSelection();
    TRect&  GetValidSelection();
    TRect&  GetValidSelectionPlus();
    TRect&  GetValidSelectionMinus();
    // ������ ���������� ������� END

    TRect       __fastcall GetAnchorCurrentSort();// �������� ��������� �������������� FCurrent � FAnchor
    void        __fastcall SetAnchorCurrentSort();// ������������� FCurrent � FAnchor
    TGridRect   __fastcall GetAnchorCurrentSortGrid();// ������������� FCurrent � FAnchor
    TRect       __fastcall GetAnchorCurrentSortPlus();// ������������� FCurrent � FAnchor � zoom �� +1 ������
    TRect       __fastcall GetJobAnchorCurrentSort();// ������������� FCurrentJob � FAnchorJob
    void        __fastcall SetUnionCell(bool Test);// ������� ������������ ������
    void        __fastcall SetUnionCell(const TRect& rect,bool Test);// ������� ������������ ������
    TRect       __fastcall CalculationRect(TGridCoord mousestart, TGridCoord mousemove);// �������� ���� �� �����������
    TRect       __fastcall CalculationRect(int StartX, int StartY, int EndX, int EndY);// �������� ���� �� �����������
    TRect       __fastcall CalculationRect(const TRect& rect);// �������� ���� �� �����������
    TRect       __fastcall SideRect1InRect2(const TRect& rect1, const TRect& rect2);// ������ rect1 ������ ��� ����� ������� rect2
    bool        __fastcall CellInRect(const TRect& rect, const TGridCoord& cell);// ����������� �� ������ ������������ ������
    bool        __fastcall CellBeUnionCell(const TGridCoord& cell);// ��������� �� ��� ������ ������������
    bool        __fastcall CellBeUnionCell(int Col, int Row);// ��������� �� ��� ������ ������������
    void        __fastcall DeleteUnionRect(TCell* Cell);// ������� ��� ������������ ������
    void        __fastcall DelUnionCell(TCell* Cell);// ������� ������ ���� �� �����������
//********************* Function  �� ������ � ������������ ��������

//********************* Function ��������� ������
//############# ��������� � DrawBorder #############
    void __fastcall CellLineTop(const TRect& Rect);
    void __fastcall CellRightBottomPixel(const TRect& RectStart);
    void __fastcall CellRightBottomPixel2(const TRect& RectStart);
    void __fastcall CellLineBottom(const TRect& Rect);
    void __fastcall CellLineBottomColorBk(int Col, int Row);
    void __fastcall CellLineTopColorBk(int Col, int Row);
    void __fastcall CellLineLeft(const TRect& Rect);
    void __fastcall CellLineRight(const TRect& Rect);
    void __fastcall CellLineRightColorBk(int Col, int Row);
    void __fastcall CellLineLeftColorBk(int Col, int Row);
    void __fastcall CellLineTop2(const TRect& Rect);
    void __fastcall CellLineBottom2(const TRect& Rect);
    void __fastcall CellLineLeft2(const TRect& Rect);
    void __fastcall CellLineRight2(const TRect& Rect);
    void __fastcall Line(int Col, int Row, TColor Color);// ���������� ����� �������� ���������� ������
    void __fastcall SetBorder(int Col, int Row, /*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine, TColor Color);
    void __fastcall SectionLine(const TRect& Rect,int Param/*1=Left, 2=Top*/);
    void __fastcall CellLineBottomSection(const TRect& RectStart);
    void __fastcall CellLineRightSection(const TRect& RectStart);
    void __fastcall CellLineBottom2b(const TRect& RectStart);
    void __fastcall CellLineRight2b(const TRect& RectStart);
    bool __fastcall TopLineUnion(int Col, int Row);// ��������� �� ��� ������ ������� ��� Union �� �������� �� ������� Union
    bool __fastcall BottomLineUnion(int Col, int Row);// ��������� �� ��� ������ ������� ��� Union �� �������� �� ���� Union
    bool __fastcall LeftLineUnion(int Col, int Row); // ��������� �� ��� ������ ������� ��� Union �� �������� �� ����� Union
    bool __fastcall RightLineUnion(int Col, int Row); // ��������� �� ��� ������ ������� ��� Union �� �������� �� ���� Union
    void __fastcall DrawBorder_0(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void __fastcall DrawBorder_1(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void __fastcall DrawBorder_2(int Col, int Row, int Border, const TRect& rect, TColor Color);
    int  __fastcall GetLeftBorder(int Col, int Row);// �������� �������
    int  __fastcall GetTopBorder(int Col, int Row);// �������� �������
    int  __fastcall GetRightBorder(int Col, int Row);// �������� �������
    int  __fastcall GetBottomBorder(int Col, int Row);// �������� �������
    int  __fastcall GetLeftBorderEliminateCurrent(int Col, int Row);// �������� ������� �������� ����
    int  __fastcall GetTopBorderEliminateCurrent(int Col, int Row);// �������� ������� �������� ����
    int  __fastcall GetRightBorderEliminateCurrent(int Col, int Row);// �������� ������� �������� ����
    int  __fastcall GetBottomBorderEliminateCurrent(int Col, int Row);// �������� ������� �������� ����
    void __fastcall SetCircumferentialBorder(int Col, int Row);// ��������� ���������� ������ �������� �� �������
    void __fastcall SetCircumferentialBorderRow(int Col, int Row);// ��������� ���������� ������ �������� �� ������� ���������� ��������� �����
    void __fastcall SetCircumferentialBorderCol(int Col, int Row);// ��������� ���������� ������ �������� �� ������� ���������� ��������� ��������
    void __fastcall SetToCellBorder(int Col, int Row);//��������� ������� ������ ��������
//############# ��������� � DrawBorder ############# END
//********************* Function End

//********************* Function Fixed
    void __fastcall SetScrollStartCol();// ��������������� ��� ������� �� ������
    void __fastcall SetScrollStartRow();// ��������������� ��� ������ �� ������
//********************* Function Fixed END

//********************* Function Test
    void __fastcall Test_CellInfo(TGridCoord& CellHit1);
    void __fastcall Test_Speed();
//********************* Function Test End

//********************* Function User
//############# ��������� � SetCellParameter #############
    bool __fastcall GetVisibleOfficialMargin(); // ����������� ����� � ����������
    void __fastcall SetVisibleOfficialMargin(bool Visible);// ����������� ����� � ����������
    bool __fastcall GetVisibleSectionLeft(); // ����������� ������
    void __fastcall SetVisibleSectionLeft(bool Visible); // ����������� ������
    bool __fastcall GetVisibleSectionTop(); // ����������� ������
    void __fastcall SetVisibleSectionTop(bool Visible); // ����������� ������
    void __fastcall SetColorRegion(TColor Color, bool FlagLineColor); // ���������� ���� ���������� �������
    void __fastcall SetFontNameRegion(AnsiString FontName); // ���������� ����� ���������� �������
    void __fastcall SetFontSizeRegion(int FontSize); // ���������� ������ ����� ���������� �������
    void __fastcall SetFontColorRegion(TColor FontColor); // ���������� ���� ������ ���������� �������
    void __fastcall SetValueTypeRegion(int ValueType);// ���������� ��� �������� (����� =0, ��������� =1, ������ =2)
    void __fastcall SetTextHAlignRegion(int TextHAlign);// ���������� ������������ ������ �� ����������� (Left=0, Center=1, Right=2)
    void __fastcall SetTextVAlignRegion(int TextVAlign);// ���������� ������������ ������ �� ��������� (Left=0, Center=1, Right=2)
    void __fastcall SetTypeAutoSizeRegion(int TypeAutoSize);// ���������� ���� ������ ������ �� ������ (Not=0, Auto=1)
    void __fastcall SetTextWordBreakRegion(int TextWordBreak);// ���������� ���� ������� �� ������ (Not=0, Auto=1)
    void __fastcall SetFontStyleRegion(int FontStyle); // ���������� ����� ������ ���������� ������� (������=0, ������=1, ������=2, ������ ������=3)
    void __fastcall SetFontStrikeOutRegion(int FontStrikeOut); // ���������� ����������� �����
    void __fastcall SetFontUnderlineRegion(int FontUnderline); // ���������� ������������ ����� (���=0, ������������=1)
    void __fastcall SetCellLine(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// �������� ��������� ���������� ������� � ������
    void __fastcall SetCellBorder(const TRect& Rect, int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// ������ ������� ��� SetCellLine
    void __fastcall SetCellLineFlood(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// �������� ��������� ������� ������� � ������
    void __fastcall SetCellLineOne(/*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine);// ���������� ������� �� ������
    void __fastcall SetCellBorderOne(const TRect& Rect ,int Border, int WidthLine);// ������ ������� ��� SetCellLineOne
    void __fastcall SetCellLineFloodVert(int WidthLine);// ��������� ������������� �������
    void __fastcall SetCellBorderFloodVert(const TRect& Rect, int WidthLine);// ������ ������� ��� SetCellLineFloodVert
    void __fastcall SetCellLineFloodHorz(int WidthLine);// ��������� ��������������� �������
    void __fastcall SetCellBorderFloodHorz(const TRect& Rect, int WidthLine);// ������ ������� ��� SetCellLineFloodHorz
    void __fastcall SetNotChangeParamRegion(const TRect& rectcopy);// ������� ������ ��������� ����������� � ������������ � �� ���������� �� ����� ��������� �� ������� (��� CopyCell)
    void __fastcall UseTextWordBreakRegion();// ��������� ������� �� ������ � ���������� �������

    void __fastcall SetFlagRect(const TRect& SetRectCell, TCellFlag* CellFlag);// ���������� ��������
    void __fastcall SetFlagCell(int Col, int Row, TCellFlag* CellFlag);// ���������� ��������
    void __fastcall AssignParamCell(TCellFlag* CellFlag, int Col, int Row);// �������� ������ ����������
    bool __fastcall ParamCellCompare(TCell* Cell, TCellFlag* CellFlag);// �������� �� ������������ ���������� �����
    void __fastcall SetAllFlag(TCellFlag* CellFlag, bool Set); // ���������� ��� �����
    void __fastcall CopyFlag1ToFlag2(TCellFlag* CellFlag1, TCellFlag* Cell);// ���������� ��������� ������������� ������ � ���������� ������ �����
    // Matrix
    void __fastcall PasteBuffInGrid(int Col, int Row); //�������� �� ������ � Grid
    void __fastcall CopyInBuff(const TRect& rect);// ���������� � ������
    void __fastcall GetCellToTest(const TRect& rect);
    int  __fastcall ProcessCellTest(int Col, int Row, void * TheItem);
    int  __fastcall ProcessCellTest2(int Col, int Row, void * TheItem);
    void __fastcall SetParam(const TRect& rect,TCellFlag* CellFlag);// ���������� ������� � ����� ���������� ��� Recta
    void __fastcall SetListFillingToCopy(const TRect& rect);
    int  __fastcall CellYes(int Col, int Row, void * TheItem);
    // Matrix END
//############# ��������� � SetCellParameter ############# END
//********************* Function User END

//********************* Function Job Rect
    TRect       __fastcall GetSelectGridRect(); // �������� ���������� ������ � �������
    TRect       __fastcall GetRectCellSort(const TRect& rect);// ������������� rect
    void        __fastcall SetRectCellSort(TRect& rect);// ������������� rect � ����������
    TRect       __fastcall GetRectCellSort(const TGridRect& rect);// ������������� rect
    TGridRect   __fastcall GetGridRectCellSort(const TGridRect& rect);// ������������� rect
    TRect       __fastcall GetUnionRect(const TRect& rect1,const TRect& rect2); // �������� ����������� rect1 � rect2
    TRect       __fastcall GetUnionRect(const TGridRect& rect1, const TGridRect& rect2); // �������� ����������� rect1 � rect2
    TGridRect   __fastcall GetUnionGridRect(const TGridRect& rect1,const TGridRect& rect2); // �������� ����������� rect1 � rect2
    TGridRect   __fastcall RectToGridRectType(const TRect& rect);// ��� TRect � TGridRect
    TRect       __fastcall GridRectToRectType(const TGridRect& rect);// ��� TGridRect � TRect
    TRect       __fastcall Zoom(const TRect& rect, int zoom);// �������� ������ rect �� �������� zoom
    TGridRect   __fastcall ZoomGrid(const TRect& rect, int zoom);// �������� ������ rect �� �������� zoom
    TGridRect   __fastcall ZoomGrid(TGridRect& rect, int zoom);// �������� ������ rect �� �������� zoom
    void        __fastcall ClipRectToJobRect(TRect& rect);// ����������� ����� �� ������� ����
    void        __fastcall ClipRectToJobRect(TGridRect& rect);// ����������� ����� �� ������� ����
    void        __fastcall ZoomAndClipRectToJobRect(TRect& rect,int zoom);// �������� ������ rect �� �������� zoom � ����������� ����� �� ������� ����
    void        __fastcall ZoomAndClipRectToJobRect(TGridRect& rect,int zoom);// �������� ������ rect �� �������� zoom � ����������� ����� �� ������� ����
    TRect       __fastcall GetGridRectCell(int iCol,int iRow);// ���������� Rect � ������� �� ������� Col � Row
    int         __fastcall SumRow(int Start, int End);// �������� ������ � �������� �� ������ Start �� ������ End
    int         __fastcall SumCol(int Start, int End);// �������� ������ � �������� �� ������ Start �� ������ End
    TRect       __fastcall GetGridRectToRectPixelNotUnion(int iCol,int iRow);// ���������� Rect � ��������
    TRect       __fastcall GetGridRectToRectPixelNotUnionReal(int iCol,int iRow);// ���������� Rect � �������� � �������� ����������� (��� �������������)
    TRect       __fastcall GetGridRectToRectPixelNotUnionAndScroll(int iCol,int iRow);// ���������� Rect � �������� � ������ �������������
    TRect       __fastcall GetGridRectToRectPixelForBorder(int Col,int Row);// ���������� Rect � �������� ��� ����� ������������
    TRect       __fastcall GetGridRectToRectPixelUnionReal(int iCol,int iRow);// ���������� Rect � �������� � Real � � ������ Union
    bool        __fastcall BeEqualRect(const TRect& rect1, const TRect& rect2); // ������ �� rect1 � rect2
    bool        __fastcall EqualSizeRect(const TRect& rect1, const TRect& rect2);// ������ �� rect1 � rect2 �� ��������
    bool        __fastcall Rect1InRect2(const TRect& rect1, const TRect& rect2);// ���������� rect1 ������ rect2
    bool        __fastcall PointInRect(int Col, int Row,const TRect& Rect);// ���������� ������ ������ rect
    int         __fastcall CalcColumnWidthAutoText(int Col, int Row);// ������ Max ������ ������� �� ������
    int         __fastcall CalcStringHeightAutoText(int Col, int Row);// ������ Max ������ ������ �� ������
    void        __fastcall ClipByEndCell(TRect& rect);// �������� Rect �� ��������� ��� ������ � ��������������� �� ��������
    bool        __fastcall Rect1CrossRect2(const TRect& rect1, const TRect& rect2); // ������������� �� rect1 � rect2 ����� OK
    bool        __fastcall PointInCut(const TPoint& cut, int point); // ����� ���������� � ���������� cut

//********************* Function Job Rect END

//************* ������ ������������ Paint*************
//############# ��������� � DrawCells #############
    void    __fastcall Paint();
    void    __fastcall DrawCells(long ACol,long ARow,int StartX,int StartY,int StopX,int StopY,TColor Color,TGridDrawState IncludeDrawState);
    void    __fastcall SetColorCanvas(int CurCol, int CurRow);
    void    __fastcall SetNumerColRow(int ACol, int ARow, int type,TColor ColorBk); // ������������ ���� � ����������
    bool    __fastcall PointInGridRect(int Col, int Row,TGridRect Rect);
    void    __fastcall DrawTextU2(int CurCol, int CurRow, const TRect& RectDrawText);// ��������� ������
//############# ��������� � DrawCells ############# END
//************* END *************

    __property bool VisibleOfficialMargin = {read =GetVisibleOfficialMargin, write =SetVisibleOfficialMargin}; // ���������� ������ 2 ������ � �������
    __property bool VisibleSectionLeft = {read =GetVisibleSectionLeft, write =SetVisibleSectionLeft}; // ���������� ���� ������ Left
    __property bool VisibleSectionTop = {read =GetVisibleSectionTop, write =SetVisibleSectionTop}; // ���������� ���� ������ Top
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
    bool CutCells; // �������� ������
    int iOffsetCell; // ����������� ������ ����� ��� �������� (0=�����, 1=�����)
    void __fastcall ToCellGrid(TCellGrid* CellGrid);// ���������
    void __fastcall FromCellGrid(TCellGrid* CellGrid);// ���������
    void __fastcall DelTextToCellGrid(TCellGrid* CellGrid);// �������� ������
    void __fastcall CorrectionRect(TCellGrid* CellGrid, TRect& rect);// ������������� ����� ��� ��������� ���� �������
    void __fastcall DelCells(TCellGrid* CellGrid, const TRect& rect); // �������� �����
    void __fastcall dCopyCellGrid(TCellGrid* CellGrid, const TRect& RectCopy); // ��������������� ��� ��������
    void __fastcall dPasteToCellGrid(TCellGrid* CellGrid, int DeltaX, int DeltaY);// ��������������� ��� ��������
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
    __fastcall  TCellMatrix(Classes::TComponent* AOwner, TCellGrid* _CellGrid);
	inline      __fastcall virtual ~TCellMatrix(void);

    void        Initialize();
    void*       __fastcall EnsureDataRow(int aRow);
    void        __fastcall SetCell(int aCol, int aRow, TCellFlag* data);//
    TCellFlag*  __fastcall GetCell(int Col, int Row);// �������� ������ � ������ � ������ �����������
    TCellFlag*  __fastcall GetCellSimple(int Col, int Row);// �������� ������ � ������ ��� ����� �����������
    void        __fastcall FForAll(TRect& rect, TMyFunc Func);
    void        __fastcall MatrixForAllTest();
    void        __fastcall NewCell(int Col, int Row, TCellFlag* data);
    void        __fastcall NewCell(int Col, int Row);
    void        __fastcall DelCell(int Col, int Row);
    void        __fastcall SetAllFlag(TCellFlag* CellFlag, bool Set);
    void        __fastcall CopyCell1ToCell2(int Col,int Row, TCellFlag* Cell2);
    TCellFlag*  __fastcall GetCellParam(int Col, int Row);
    TCellFlag*  __fastcall GetParamCell(int Col, int Row); // �������� ������ �� ����� �����������
    TCellFlag*  __fastcall GetParamCellAndFlag(int Col, int Row);
//********************* Function System END

    void __fastcall ClearAll();
    int __fastcall ProcessMx(int Col, int Row, void * TheItem);
};
//---------------------------------------------------------------------------

#endif
