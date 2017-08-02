//---------------------------------------------------------------------------
#ifndef CellGridH
#define CellGridH
#include "GridRoutineU.hpp"
#include "UNDO.h"
//---------------------------------------------------------------------------

// ----------- Const ------------------
    const int iPixelTact=2;
//*********************  Color **********
//    const TColor ColorSelect =RGB(182,202,234); // Выделение нескольких яччек
//    const TColor ColorSelect =RGB(109,149,213); // Выделение нескольких яччек
//    const TColor ColorSelect =RGB(255,255,255); // Выделение нескольких яччек
    const TColor ColorFixedSelect =RGB(248, 247, 239);// Выделено или строка или столбец
    const TColor ColorFixedSelectAll =RGB(255, 192, 111); // Выделена Вся таблица
//*********************  Color ********** END



class TGridForm;
#pragma option push -b-
enum TTextVAlign {tvaTop,tvaCenter,tvaDown};
#pragma option pop
class TCell;
class TCellMatrix;


class COMMONAL_API TCell : public TMyObject{
// Работа с ячейкой
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    void Assign(TMyObject* MO);
    bool UndoRegistered;

    TCell();
    ~TCell();

    TColor bgColor;// Цвет фона
    bool LineColorNot;// Флаг наличия заливки фона у ячейки
    AnsiString Text;// Текст в ячейке
    AnsiString FontName;// Шрифт
    TColor FontColor;// Цвет фрифта
    struct TLineWidth // Наличее бордюра и его тип
    {
        byte WidthLeft;
        byte WidthTop;
        byte WidthRight;
        byte WidthBottom;
    } Line;
    TRect* UnionRect;// Объедененная ячейка (Ячейка первая и последняя в регионе)

    struct TCellFlags
    {
        unsigned FontSize:8;// Размер шрифта
        unsigned FontStyle:3;// Стиль шрифта (Обычны=0, Курсив=1, Жирный=2, Жирный курсив=3)
        unsigned FontStrikeOut:1;// Зачеркнутый шрифт (НЕТ=0, зачеркнутый=1)
        unsigned FontUnderline:1;// Подчеркнутый шрифт (НЕТ=0, подчеркнутый=1)
        unsigned ValueType:2;// Тип Значения (текст =0, выражение =1, шаблон =2)
        unsigned TypeAutoSize:2;// тип расположения текста в ячейке (без авто =0, авто размер строки =1)
        unsigned TextHAlign:2;// Выравнивание текста по горизонтали (Left=0, Center=1, Right=2)
        unsigned TextVAlign:2;// Выравнивание текста по вертикали (Left=0, Center=1, Right=2)
        unsigned TextWordBreak:1;// перенос по словам (НЕ переносить=0, переносить=1)
        unsigned TextHeightAuto:1;// Расширять высоту строки под набранный текст (НЕ расширять=0, Расширять=1)

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
// Работа с строками сталбцами
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
// Работа с строками сталбцами
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCellColRow();
    ~TCellColRow();
    int ColRowWidth;
};
extern COMMONAL_API TClassNode* TCellColRow::StaticType;

class COMMONAL_API TCellTab : public TCell{
// Работа с ячейкой
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
// Динамическая строка
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
// Рисование
protected:
	virtual void __fastcall WndProc(Messages::TMessage &Message);
private:
    void* FData;
__published:

public:
    TToolBarCellGrid* ToolBarCellGrid;
    TEditText* EditText; // RichEdit -для ввода текста в ячейку

// Переменные НАШЕГО Paint
    bool InvalidateRectOK;
    bool StartVisible;
    bool bResizeColRow;

    TGridCoord oldFCurrent;
    TGridCoord oldFAnchor;
    int iMouseDown;
    int iMouseMove;
    TPoint EndColRowCell; // Последняя существующая ячейка

    TRect CurrentRectMouseDown;
//    bool FieldCut;
//    PIntArray PointsCopy;
    TRect OldRectDown;//Для корректной выделении при выходе из объедененной ячейки
    TRect OldRectDownCurrentAnchor;//Для корректной выделении при выходе из объедененной ячейки


    TRect OldRectMouseDown;
    TRect OldRectMouseDown2;

    TColor ColorSelect;

//    bool MouseDownAndMoveCursor;

    bool MoveCellBorder;
// Переменные НАШЕГО Paint - END

// Переменные НАШЕГО Paint V2
//    TRect OldRectCurrentAnchorMouseDown;
    TRect OldRectCurrentAnchorMouseMove;
    TGridRect OldRectCurrentAnchorMouseMoveCell;
    TGridCoord OldCellMouseMove;
    TGridCoord JobFCurrent;
    TGridCoord JobFAnchor;
// Переменные НАШЕГО Paint END

// Переменные НАШЕГО Paint V4
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

    TPoint CellGridResizeRow; // Для изменения размера высоты строк
    TPoint CellGridResizeCol; // Для изменения размера высоты строк
    int NewSizeColRow;

//*********************  Color **********
    TColor ColorCursor; // Стандартный фон
//*********************  Color ********** END

    TRect FValidSelection;
    TRect FValidSelectionPlus;
    TRect FValidSelectionMinus;
    TGridRect FValidCurAnchor;
//    int iCountCalculation;

    TGridCoord DrawCursCurrent;
    TGridCoord DrawCursAnchor;

    bool PopupMenuNotMouseUp;// Для того чтобы после выхода не портил MouseUP для правилиного обновления предыдущего ректа
//********************* Function System
    bool SelectTable; // Выделена таблица
    bool SelectColumn;// Выделен столбец
    bool SelectString;// Выделена строка
    bool SelectCell;// Выделена ячейка

    int XM;
    int YM;
    TGridCoord MousePosCellMoveSelect;

    TMDelTList <TPoint> ListFilling; // список ячеек подлежащих изменению
    TMDelTList <TPoint> ListFilling2; // список ячеек подлежащих изменению
    TRect OldCurrentAnchorSort;
//********************* Function System END

    bool PrivatEvent_1;// Перерисовать после Scrool (старт в раб зоне конец в Fixed)
    bool PrivatEvent_2;// Перерисовать все для MouseDown

    int OldRectDrawCellFixedT; // Для проверки необходимости вычислять значения Top объедененной ячейки
    int OldRectDrawCellFixedL; // Для проверки необходимости вычислять значения Left объедененной ячейки
    int OldRectDrawCellFixedTop;
    int OldRectDrawCellFixedLeft;
    TRect CurrentRectDrawUnionFixed;// Рект текущей UnionCell

// Переменные НАШЕГО Paint END4
// Переменные Для теста
    int iTest1;
    int iTest2;
// Переменные END

// Переменные Edit
    TRect CurrentEditCell;
    AnsiString TempStringCell;
    int CurrentEditCol;
    int CurrentEditRow;
// Переменные Edit End

// Переменные стандартного Paint
    TGridDrawInfo DrawInfo;
    TGridRect Sel;
    TRect UpdateRect;

    bool Focused;

    TGridForm* GridForm;
    TCellFlag* gCellFlag;// Для установки флагов
    TMDelTList <TMDelTList <TCellFlag> > CellF;
    bool ProgressCopy;
// Переменные стандартного END
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
    void        __fastcall NewCell(int Col, int Row);// Создать новую ячейку
    void        __fastcall NewCell(int Col, int Row, TCell* data);// Создать новую ячейку
    void        __fastcall DelCell(int Col, int Row);// Удалить ячейку

    void        __fastcall SetCell(int aCol, int aRow, TCell* data);//
    void        __fastcall SetNewCell(int aCol, int aRow, TCell* data);
    void        __fastcall NewCellAndSetDefault(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // Создать ячейку и заполнить ее Default
    void        __fastcall NewCellAndSetDefault2(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/); // Создать ячейку и заполнить ее Default

    void        __fastcall NewCellAndSetParam(int Col, int Row);// Создать новую ячейку и при необходимости создает на пересечении
    TCellFlag*  __fastcall GetParamCell(int Col, int Row); // Получить ячейку со всеми параметрами
    void        __fastcall ClearSelectRect();// Очистка выделенной области
    void        __fastcall ClearSelectRect(const TRect& rect);// Очистка Recta
    void        __fastcall ClearCell(int Col, int Row);// Очистка Ячейки
    void        __fastcall DelAndSetDefaultCell(int Col, int Row);// Удалить и заполнить Defaultam от 0:0
    void        __fastcall DelAndSetDefaultCell(const TRect& Rect);// Удалить и заполнить Defaultam от 0:0
    void        __fastcall DelAndSetDefaultCellF(const TRect& Rect);// Удалить и заполнить Defaultam от 0:0
    int         __fastcall DelCellF(int Col, int Row, void * TheItem);// для DelAndSetDefaultCellF
    void        __fastcall GetSelectCells(bool AllUnion); // Заполнение ListFilling
    //(x,y) Ячеек для изменения
    //(AllUnion если true тогда если объедененная ячейка попадает циликом
    //в выделенную область тогда включать в список иначе исключаем область объедененной ячейки)

//    void        __fastcall GetSelectCellsColRow(); // Заполнение ListFilling (x,y) (Строк, Столбцов) - для линий
    void        __fastcall ClearListFilling();// Очистка ListFilling
    void        __fastcall SetDefaultCell11(); // Устанавливает в ячейку 1:1 значение Default
    void*       __fastcall EnsureDataRow(int aRow);
    TCell*      __fastcall GetCell(int Col, int Row);// Получить данные о ячейке с учетом объеденоной
    TCell*      __fastcall GetCellSimple(int Col, int Row);// Получить данные о ячейке Без учета объедененой
    TCell*      __fastcall GetCellParam(int Col, int Row); // Получить параметры ячейки
    TCell*      __fastcall GetCellParamSimple(int Col, int Row);// Получить параметры ячейки
    void        __fastcall CopyCell1ToCell2(int Col1, int Row1, int Col2, int Row2);// Копироватьь из Cell1 в Cell2
    void        __fastcall CopyCell1ToCell2(int Col,int Row, TCell* Cell2);// Копироватьь из Col,Row в Cell2
    void        __fastcall CopyCell1ToCell2(TCell* Cell1, int Col,int Row);// Копироватьь из Cell2 в Col,Row
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

//********************* Обработка сообщений и переопределение фукций
    void            __fastcall CellGridMouseMove(TObject *Sender,TShiftState Shift, int X, int Y);// Обработчик Мышь движение
    void            __fastcall CellGridMouseDown(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// Обработчик Мышь Key в верх
    void            __fastcall CellGridMouseUp(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);// Обработчик Мышь Key в низ
	DYNAMIC bool    __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Скрол по колясику в верх
    DYNAMIC bool    __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Скрол по колясику в низ
    bool            __fastcall DoMouseWheelLeft(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Скрол по колясику в лево
    bool            __fastcall DoMouseWheelRight(Classes::TShiftState Shift, const Types::TPoint &MousePos);// Скрол по колясику в право
    DYNAMIC void    __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);// обработчик клавиатуры
    void            __fastcall ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft);// обработчик скролирования ползунками
    void            __fastcall ResizeRow(int Index, int OldSize, int NewSize);
    void            __fastcall ResizeCol(int Index, int OldSize, int NewSize);
//********************* Обработка сообщений  и переопределение фукций END

//********************* Function EditText
    void    __fastcall ShowEditText(int Col, int Row, bool clear); // Показать поле ввода
    void    __fastcall SetCanvasParameterCell(int Col, int Row);// Установить в Canvas параметры ячейки
    int     __fastcall GetAlignText(int Col, int Row);// получитьвыравнивание текста для DrawText
    void    __fastcall GetRectDrawText(int Col, int Row, const AnsiString& Text, TRect& calcrect);// Расчитать рект необходимый под текст
    void    __fastcall UseTextWordBreak(int Col, int Row);// Применить перенос по словам
//********************* Function EditText

//********************* Разное
    void    __fastcall InvalidateU2();// Invalidate 2ого уровня
    void    __fastcall NullRect(TRect& rect1);// Установить значение 0 в rect
    void    __fastcall NullLine(TCell& Cell);// Установить значение 0 в Line
    void    __fastcall RecalculationEndCell(int Col, int Row);// Пересчет последней ячейки
    void    __fastcall FForAll(TRect& rect, TMyFunc Func);
    int     __fastcall ProcessCell(int Col, int Row, void * TheItem);
    bool    __fastcall TestingRectToSelection(TCell* Cell, const TRect RectSelection);// Находиться ли объедененная ячейка  в заданном Recte
    void    __fastcall SelectAllCells(); // Выделить всю таблицу
//********************* Разное END

//********************* Function MouseMoveCell and CursorDraw
    void    __fastcall DrawCursor(const TRect& Rect);// Рисуем курсор
    void    __fastcall DrawCursorU2(int CurCol, int CurRow, int iLeft,int iTop,int iRight,int iBottom);// Рисуем курсор
    void    __fastcall DrawCursorMove(const TRect& Rect, int Width);
    TColor  __fastcall SetColorCursor(TColor& Color);// Установить цвет курсора
    void    __fastcall DrawCursorMove(int Col, int Row);// Рисуем курсор перетаскивания ячеек
    void    __fastcall DrawCursorMove2(int Col, int Row);// Рисуем курсор перетаскивания ячеек Уровень 2
    bool    __fastcall SelectAllJobField(); // Выделенно все рабочее поле
    void    __fastcall StartScrollingTimer1(TGridCoord& CellHit1);
    void    __fastcall StartScrollingTimer2(TGridCoord& CellHit1);

//********************* Function MouseMoveCell END

//********************* Function  по работе с объеденеными ячейками
    // Расчет выделенной области
    void    RecalculateSelection();
    TRect&  GetValidSelection();
    TRect&  GetValidSelectionPlus();
    TRect&  GetValidSelectionMinus();
    // Расчет выделенной области END

    TRect       __fastcall GetAnchorCurrentSort();// получить результат отсортированых FCurrent и FAnchor
    void        __fastcall SetAnchorCurrentSort();// отсортировать FCurrent и FAnchor
    TGridRect   __fastcall GetAnchorCurrentSortGrid();// отсортировать FCurrent и FAnchor
    TRect       __fastcall GetAnchorCurrentSortPlus();// отсортировать FCurrent и FAnchor и zoom на +1 ячейку
    TRect       __fastcall GetJobAnchorCurrentSort();// отсортировать FCurrentJob и FAnchorJob
    void        __fastcall SetUnionCell(bool Test);// Создать объедененную ячейку
    void        __fastcall SetUnionCell(const TRect& rect,bool Test);// Создать объедененную ячейку
    TRect       __fastcall CalculationRect(TGridCoord mousestart, TGridCoord mousemove);// Получить рект по координатам
    TRect       __fastcall CalculationRect(int StartX, int StartY, int EndX, int EndY);// Получить рект по координатам
    TRect       __fastcall CalculationRect(const TRect& rect);// Получить рект по координатам
    TRect       __fastcall SideRect1InRect2(const TRect& rect1, const TRect& rect2);// строна rect1 миньше или ровна стороне rect2
    bool        __fastcall CellInRect(const TRect& rect, const TGridCoord& cell);// принадлежит ли ячейка объедененной ячейке
    bool        __fastcall CellBeUnionCell(const TGridCoord& cell);// Являеться ли эта ячейка объедененной
    bool        __fastcall CellBeUnionCell(int Col, int Row);// Являеться ли эта ячейка объедененной
    void        __fastcall DeleteUnionRect(TCell* Cell);// Удалить всю объедененную ячейку
    void        __fastcall DelUnionCell(TCell* Cell);// Удалить только инфу об объеденении
//********************* Function  по работе с объеденеными ячейками

//********************* Function Рисования бордюр
//############# Находятся в DrawBorder #############
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
    void __fastcall Line(int Col, int Row, TColor Color);// Отрисовать линии согласно параметрам ячейки
    void __fastcall SetBorder(int Col, int Row, /*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine, TColor Color);
    void __fastcall SectionLine(const TRect& Rect,int Param/*1=Left, 2=Top*/);
    void __fastcall CellLineBottomSection(const TRect& RectStart);
    void __fastcall CellLineRightSection(const TRect& RectStart);
    void __fastcall CellLineBottom2b(const TRect& RectStart);
    void __fastcall CellLineRight2b(const TRect& RectStart);
    bool __fastcall TopLineUnion(int Col, int Row);// Являеться ли эта ячейка простой или Union но отличной от нижнего Union
    bool __fastcall BottomLineUnion(int Col, int Row);// Являеться ли эта ячейка простой или Union но отличной от иерх Union
    bool __fastcall LeftLineUnion(int Col, int Row); // Являеться ли эта ячейка простой или Union но отличной от Право Union
    bool __fastcall RightLineUnion(int Col, int Row); // Являеться ли эта ячейка простой или Union но отличной от Лево Union
    void __fastcall DrawBorder_0(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void __fastcall DrawBorder_1(int Col, int Row, int Border, const TRect& rect, TColor Color);
    void __fastcall DrawBorder_2(int Col, int Row, int Border, const TRect& rect, TColor Color);
    int  __fastcall GetLeftBorder(int Col, int Row);// Получить толщину
    int  __fastcall GetTopBorder(int Col, int Row);// Получить толщину
    int  __fastcall GetRightBorder(int Col, int Row);// Получить толщину
    int  __fastcall GetBottomBorder(int Col, int Row);// Получить толщину
    int  __fastcall GetLeftBorderEliminateCurrent(int Col, int Row);// Получить толщину Исключая себя
    int  __fastcall GetTopBorderEliminateCurrent(int Col, int Row);// Получить толщину Исключая себя
    int  __fastcall GetRightBorderEliminateCurrent(int Col, int Row);// Получить толщину Исключая себя
    int  __fastcall GetBottomBorderEliminateCurrent(int Col, int Row);// Получить толщину Исключая себя
    void __fastcall SetCircumferentialBorder(int Col, int Row);// Заполнить окружающие ячейки бордюрам из текущей
    void __fastcall SetCircumferentialBorderRow(int Col, int Row);// Заполнить окружающие ячейки бордюрам по текущим параметрам Приоритет строк
    void __fastcall SetCircumferentialBorderCol(int Col, int Row);// Заполнить окружающие ячейки бордюрам по текущим параметрам Приоритет столбцов
    void __fastcall SetToCellBorder(int Col, int Row);//Заполнить текущюю ячейку бордюрам
//############# Находятся в DrawBorder ############# END
//********************* Function End

//********************* Function Fixed
    void __fastcall SetScrollStartCol();// Проскролировать все столбцы на начало
    void __fastcall SetScrollStartRow();// Проскролировать все строки на начало
//********************* Function Fixed END

//********************* Function Test
    void __fastcall Test_CellInfo(TGridCoord& CellHit1);
    void __fastcall Test_Speed();
//********************* Function Test End

//********************* Function User
//############# Находятся в SetCellParameter #############
    bool __fastcall GetVisibleOfficialMargin(); // Отображение Полей с нумерацией
    void __fastcall SetVisibleOfficialMargin(bool Visible);// Отображение Полей с нумерацией
    bool __fastcall GetVisibleSectionLeft(); // Отображение секций
    void __fastcall SetVisibleSectionLeft(bool Visible); // Отображение секций
    bool __fastcall GetVisibleSectionTop(); // Отображение секций
    void __fastcall SetVisibleSectionTop(bool Visible); // Отображение секций
    void __fastcall SetColorRegion(TColor Color, bool FlagLineColor); // Установить цвет выделенной области
    void __fastcall SetFontNameRegion(AnsiString FontName); // Установить Шрифт выделенной области
    void __fastcall SetFontSizeRegion(int FontSize); // Установить Размер Шрифт выделенной области
    void __fastcall SetFontColorRegion(TColor FontColor); // Установить Цвет Шрифта выделенной области
    void __fastcall SetValueTypeRegion(int ValueType);// Установить Тип Значения (текст =0, выражение =1, шаблон =2)
    void __fastcall SetTextHAlignRegion(int TextHAlign);// Установить Выравнивание текста по горизонтали (Left=0, Center=1, Right=2)
    void __fastcall SetTextVAlignRegion(int TextVAlign);// Установить Выравнивание текста по вертикали (Left=0, Center=1, Right=2)
    void __fastcall SetTypeAutoSizeRegion(int TypeAutoSize);// Установить авто размер строки по тексту (Not=0, Auto=1)
    void __fastcall SetTextWordBreakRegion(int TextWordBreak);// Установить авто перенос по словам (Not=0, Auto=1)
    void __fastcall SetFontStyleRegion(int FontStyle); // Установить Стиль Шрифта выделенной области (Обычны=0, Курсив=1, Жирный=2, Жирный курсив=3)
    void __fastcall SetFontStrikeOutRegion(int FontStrikeOut); // Установить зачеркнутый шрифт
    void __fastcall SetFontUnderlineRegion(int FontUnderline); // Установить подчеркнутый шрифт (НЕТ=0, подчеркнутый=1)
    void __fastcall SetCellLine(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// записать параметры обведенной границы в ячейки
    void __fastcall SetCellBorder(const TRect& Rect, int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// Нижний уровень для SetCellLine
    void __fastcall SetCellLineFlood(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom);// записать параметры заливки границы в ячейки
    void __fastcall SetCellLineOne(/*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine);// Установить бордюры по одному
    void __fastcall SetCellBorderOne(const TRect& Rect ,int Border, int WidthLine);// Нижний уровень для SetCellLineOne
    void __fastcall SetCellLineFloodVert(int WidthLine);// Заполнить вертикальными линиями
    void __fastcall SetCellBorderFloodVert(const TRect& Rect, int WidthLine);// Нижний уровень для SetCellLineFloodVert
    void __fastcall SetCellLineFloodHorz(int WidthLine);// Заполнить горизонтальными линиями
    void __fastcall SetCellBorderFloodHorz(const TRect& Rect, int WidthLine);// Нижний уровень для SetCellLineFloodHorz
    void __fastcall SetNotChangeParamRegion(const TRect& rectcopy);// Создать ячейку заполнить параметрами в соответствии с ее положением но новых изменений не вносить (для CopyCell)
    void __fastcall UseTextWordBreakRegion();// Применить перенос по словам к выделенной области

    void __fastcall SetFlagRect(const TRect& SetRectCell, TCellFlag* CellFlag);// Установить параметр
    void __fastcall SetFlagCell(int Col, int Row, TCellFlag* CellFlag);// Установить параметр
    void __fastcall AssignParamCell(TCellFlag* CellFlag, int Col, int Row);// Праверка нужных параметров
    bool __fastcall ParamCellCompare(TCell* Cell, TCellFlag* CellFlag);// Проверка на одинаковость параметров ячеек
    void __fastcall SetAllFlag(TCellFlag* CellFlag, bool Set); // Установить все флаги
    void __fastcall CopyFlag1ToFlag2(TCellFlag* CellFlag1, TCellFlag* Cell);// Копировать заначения установленных флагов и установить данные флаги
    // Matrix
    void __fastcall PasteBuffInGrid(int Col, int Row); //Вставить из буфера в Grid
    void __fastcall CopyInBuff(const TRect& rect);// Копировать в буффер
    void __fastcall GetCellToTest(const TRect& rect);
    int  __fastcall ProcessCellTest(int Col, int Row, void * TheItem);
    int  __fastcall ProcessCellTest2(int Col, int Row, void * TheItem);
    void __fastcall SetParam(const TRect& rect,TCellFlag* CellFlag);// Заполнение матрицы и затем применение для Recta
    void __fastcall SetListFillingToCopy(const TRect& rect);
    int  __fastcall CellYes(int Col, int Row, void * TheItem);
    // Matrix END
//############# Находятся в SetCellParameter ############# END
//********************* Function User END

//********************* Function Job Rect
    TRect       __fastcall GetSelectGridRect(); // Получить выделенный регион в ячейках
    TRect       __fastcall GetRectCellSort(const TRect& rect);// Отсортировать rect
    void        __fastcall SetRectCellSort(TRect& rect);// Отсортировать rect и установить
    TRect       __fastcall GetRectCellSort(const TGridRect& rect);// Отсортировать rect
    TGridRect   __fastcall GetGridRectCellSort(const TGridRect& rect);// Отсортировать rect
    TRect       __fastcall GetUnionRect(const TRect& rect1,const TRect& rect2); // Получить объеденение rect1 с rect2
    TRect       __fastcall GetUnionRect(const TGridRect& rect1, const TGridRect& rect2); // Получить объеденение rect1 с rect2
    TGridRect   __fastcall GetUnionGridRect(const TGridRect& rect1,const TGridRect& rect2); // Получить объеденение rect1 с rect2
    TGridRect   __fastcall RectToGridRectType(const TRect& rect);// Тип TRect в TGridRect
    TRect       __fastcall GridRectToRectType(const TGridRect& rect);// Тип TGridRect в TRect
    TRect       __fastcall Zoom(const TRect& rect, int zoom);// Изменить размер rect на величену zoom
    TGridRect   __fastcall ZoomGrid(const TRect& rect, int zoom);// Изменить размер rect на величену zoom
    TGridRect   __fastcall ZoomGrid(TGridRect& rect, int zoom);// Изменить размер rect на величену zoom
    void        __fastcall ClipRectToJobRect(TRect& rect);// Ограничение ректа по рабочей зоне
    void        __fastcall ClipRectToJobRect(TGridRect& rect);// Ограничение ректа по рабочей зоне
    void        __fastcall ZoomAndClipRectToJobRect(TRect& rect,int zoom);// Изменить размер rect на величену zoom и Ограничение ректа по рабочей зоне
    void        __fastcall ZoomAndClipRectToJobRect(TGridRect& rect,int zoom);// Изменить размер rect на величену zoom и Ограничение ректа по рабочей зоне
    TRect       __fastcall GetGridRectCell(int iCol,int iRow);// Возвращает Rect в ячейках по позиции Col и Row
    int         __fastcall SumRow(int Start, int End);// получить высоту в пикселях от ячейки Start до ячейки End
    int         __fastcall SumCol(int Start, int End);// получить ширину в пикселях от ячейки Start до ячейки End
    TRect       __fastcall GetGridRectToRectPixelNotUnion(int iCol,int iRow);// Возвращает Rect в пикселях
    TRect       __fastcall GetGridRectToRectPixelNotUnionReal(int iCol,int iRow);// Возвращает Rect в пикселях в реальных координатах (без скролирования)
    TRect       __fastcall GetGridRectToRectPixelNotUnionAndScroll(int iCol,int iRow);// Возвращает Rect в пикселях с учетом скролтрования
    TRect       __fastcall GetGridRectToRectPixelForBorder(int Col,int Row);// Возвращает Rect в пикселях Без учета объедененных
    TRect       __fastcall GetGridRectToRectPixelUnionReal(int iCol,int iRow);// Возвращает Rect в пикселях в Real и с учетом Union
    bool        __fastcall BeEqualRect(const TRect& rect1, const TRect& rect2); // равены ли rect1 и rect2
    bool        __fastcall EqualSizeRect(const TRect& rect1, const TRect& rect2);// равены ли rect1 и rect2 по размерам
    bool        __fastcall Rect1InRect2(const TRect& rect1, const TRect& rect2);// Находиться rect1 внутри rect2
    bool        __fastcall PointInRect(int Col, int Row,const TRect& Rect);// Находиться ячейка внутри rect
    int         __fastcall CalcColumnWidthAutoText(int Col, int Row);// Расчет Max ширины столбца по тексту
    int         __fastcall CalcStringHeightAutoText(int Col, int Row);// Расчет Max высоты строки по тексту
    void        __fastcall ClipByEndCell(TRect& rect);// Обзезать Rect по последней сущ ячейке и скорректировать по столбцам
    bool        __fastcall Rect1CrossRect2(const TRect& rect1, const TRect& rect2); // Пересекаються ли rect1 и rect2 тогда OK
    bool        __fastcall PointInCut(const TPoint& cut, int point); // точка находиться в промежутке cut

//********************* Function Job Rect END

//************* Методы стандартного Paint*************
//############# Находятся в DrawCells #############
    void    __fastcall Paint();
    void    __fastcall DrawCells(long ACol,long ARow,int StartX,int StartY,int StopX,int StopY,TColor Color,TGridDrawState IncludeDrawState);
    void    __fastcall SetColorCanvas(int CurCol, int CurRow);
    void    __fastcall SetNumerColRow(int ACol, int ARow, int type,TColor ColorBk); // Пронуеровать поля с нумерацией
    bool    __fastcall PointInGridRect(int Col, int Row,TGridRect Rect);
    void    __fastcall DrawTextU2(int CurCol, int CurRow, const TRect& RectDrawText);// Рисование текста
//############# Находятся в DrawCells ############# END
//************* END *************

    __property bool VisibleOfficialMargin = {read =GetVisibleOfficialMargin, write =SetVisibleOfficialMargin}; // Отображать первые 2 Строки и Столбца
    __property bool VisibleSectionLeft = {read =GetVisibleSectionLeft, write =SetVisibleSectionLeft}; // Отображать Зону секций Left
    __property bool VisibleSectionTop = {read =GetVisibleSectionTop, write =SetVisibleSectionTop}; // Отображать Зону секций Top
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
    bool CutCells; // Вырезать ячейки
    int iOffsetCell; // Направление сдвига ячеек при удалении (0=Вверх, 1=Влево)
    void __fastcall ToCellGrid(TCellGrid* CellGrid);// Загрузить
    void __fastcall FromCellGrid(TCellGrid* CellGrid);// Сохранить
    void __fastcall DelTextToCellGrid(TCellGrid* CellGrid);// Удаление текста
    void __fastcall CorrectionRect(TCellGrid* CellGrid, TRect& rect);// Корректировка ректа при выделении всей области
    void __fastcall DelCells(TCellGrid* CellGrid, const TRect& rect); // Удаление ячеек
    void __fastcall dCopyCellGrid(TCellGrid* CellGrid, const TRect& RectCopy); // вспомогательные для уданения
    void __fastcall dPasteToCellGrid(TCellGrid* CellGrid, int DeltaX, int DeltaY);// вспомогательные для уданения
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
    TCellFlag*  __fastcall GetCell(int Col, int Row);// Получить данные о ячейке с учетом объеденоной
    TCellFlag*  __fastcall GetCellSimple(int Col, int Row);// Получить данные о ячейке Без учета объедененой
    void        __fastcall FForAll(TRect& rect, TMyFunc Func);
    void        __fastcall MatrixForAllTest();
    void        __fastcall NewCell(int Col, int Row, TCellFlag* data);
    void        __fastcall NewCell(int Col, int Row);
    void        __fastcall DelCell(int Col, int Row);
    void        __fastcall SetAllFlag(TCellFlag* CellFlag, bool Set);
    void        __fastcall CopyCell1ToCell2(int Col,int Row, TCellFlag* Cell2);
    TCellFlag*  __fastcall GetCellParam(int Col, int Row);
    TCellFlag*  __fastcall GetParamCell(int Col, int Row); // Получить ячейку со всеми параметрами
    TCellFlag*  __fastcall GetParamCellAndFlag(int Col, int Row);
//********************* Function System END

    void __fastcall ClearAll();
    int __fastcall ProcessMx(int Col, int Row, void * TheItem);
};
//---------------------------------------------------------------------------

#endif
