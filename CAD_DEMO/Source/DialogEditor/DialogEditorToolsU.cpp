//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#include<math.h>
#pragma hdrstop

#include "DialogEditorToolsU.h"
#include "ObjectInspectorU.hpp"
#include "MyDialogEditU.h"
#include "MyDialogU.h"
#include "ToolBarU.h"
//---------------------------------------------------------------------------
TCreateTool::TCreateTool(int _ClassId)
{
    ImageId = _ClassId-1;
    ClassId = _ClassId;
    AddStateBlock(ctState1_WaitingMouseDown, WaitingMouseDown, Mouse_Move, btNone, "Ожидание нажатия клавиши для определения места для создания нового объекта на форме.");
    AddStateBlock(ctState2_SelectBorderFrame, SelectBorderFrame, Mouse_Move, btNone, "Выбор границ объекта.");
    AddActionBlock(ctAction1_GetCoords, GetCoords, btNone, "Определение начальных координат.");
    AddActionBlock(ctAction2_CreateObject, CreateObject, btMenu, "Создание объекта: Создание TVCLEditorElement, влючающего создание TComponent и соответствующей ему формы (для не являющихся TWinControl). Добавление объекта в ObjectTree и в ObjectInspector.");
    AddGoToBlockId(WaitingMouseDown, GetCoords, Mouse_Down, mbLeft);
    AddGoToBlockId(GetCoords, SelectBorderFrame);
    AddGoToBlockId(SelectBorderFrame, CreateObject, Mouse_Up, mbLeft);
    AddGoToBlockId(CreateObject, WaitingMouseDown);
}

//---------------------------------------------------------------------------
void TCreateTool::ctState1_WaitingMouseDown()
{
}

//---------------------------------------------------------------------------
void TCreateTool::ctState2_SelectBorderFrame()
{
    int i;
    MyClickControl = (TForm*)UIP.Sender;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    DialogEdit->Canvas->Pen->Width = 2;
    DialogEdit->Canvas->Pen->Mode = pmXor;
    DialogEdit->Canvas->Pen->Color = clWhite;
    Types::TPoint _Point = Point((VCL->Control->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep) * DialogEdit->GridStep, (VCL->Control->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep) * DialogEdit->GridStep);
    Types::TPoint* Points = new TPoint[5];
    Points[0] = Point(MIN(TempX, FirstX),MAX(TempY, FirstY));
    Points[1] = Point(MIN(TempX, FirstX),MIN(TempY, FirstY));
    Points[2] = Point(MAX(TempX, FirstX),MIN(TempY, FirstY));
    Points[3] = Point(MAX(TempX, FirstX),MAX(TempY, FirstY));
    Points[4] = Point(MIN(TempX, FirstX),MAX(TempY, FirstY));
    if ( VCL->Control != DialogEdit )
        for ( i = 0; i < 5; i++ )
            Points[i] = VCL->Control->ClientToParent ( Points[i], DialogEdit );
    DialogEdit->Canvas->Polyline( Points, 4 );
    TempX = _Point.x;
    TempY = _Point.y;
    Points[0] = Point(MIN(TempX, FirstX),MAX(TempY, FirstY));
    Points[1] = Point(MIN(TempX, FirstX),MIN(TempY, FirstY));
    Points[2] = Point(MAX(TempX, FirstX),MIN(TempY, FirstY));
    Points[3] = Point(MAX(TempX, FirstX),MAX(TempY, FirstY));
    Points[4] = Point(MIN(TempX, FirstX),MAX(TempY, FirstY));
    if ( VCL->Control != DialogEdit )
        for ( i = 0; i < 5; i++ )
            Points[i] = VCL->Control->ClientToParent ( Points[i], DialogEdit );
    DialogEdit->Canvas->Polyline( Points, 4 );
    DialogEdit->Canvas->Pen->Mode = pmCopy;
    DialogEdit->Canvas->Pen->Width = 1;
    delete Points;
}

//---------------------------------------------------------------------------
void TCreateTool::ctAction1_GetCoords()
{
    MyClickControl = (TForm*)UIP.Sender;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    while( !VCL->CanHaveChild() )
        VCL = VCL->VCLParent;
    Types::TPoint _Point = Point(VCL->Control->ScreenToClient(Mouse->CursorPos).x,VCL->Control->ScreenToClient(Mouse->CursorPos).y);
    FirstX = TempX = (_Point.x / DialogEdit->GridStep) * DialogEdit->GridStep;
    FirstY = TempY = (_Point.y / DialogEdit->GridStep) * DialogEdit->GridStep;
}

//---------------------------------------------------------------------------
void TCreateTool::ctAction2_CreateObject()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    while( !VCL->CanHaveChild() )
        VCL = VCL->VCLParent;
    TVCLEditorElement* NewVCL = new TVCLEditorElement();
    NewVCL->Component = (TComponent*)CreateComponent(DialogEdit, TClassId(ClassId));
    Types::TPoint OldPoint;
    OldPoint = Point((UIP.NewCursorPos.intX() / DialogEdit->GridStep) * DialogEdit->GridStep,(UIP.NewCursorPos.intY() / DialogEdit->GridStep) * DialogEdit->GridStep);
    if ( !IS (NewVCL->Component, __classid(TWinControl)))
    {
        NewVCL->Control = new TForm(DialogEdit);
        NewVCL->Control->Parent = DialogEdit;
        NewVCL->Control->Top = 0;
        NewVCL->Control->Left = 0;
        NewVCL->Control->Height = 4 * DialogEdit->GridStep;
        NewVCL->Control->Width = 4 * DialogEdit->GridStep;
        ((TForm*)NewVCL->Control)->BorderStyle = bsNone;
    }
    else
    {
        NewVCL->Control = (TWinControl*)NewVCL->Component;
        NewVCL->Control->Parent = VCL->Control;
    }
    NewVCL->Component->Name = DialogEdit->GetName(ClassId);
    NewVCL->Control->Visible = true;
    for(int i = 0; i < 8; i++)
        NewVCL->Rects[i] = Rect(0,0,0,0);
    if ( ( abs(FirstX - TempX) > DialogEdit->GridStep ) && ( abs(FirstY - TempY) > DialogEdit->GridStep ) )
    {
        NewVCL->Control->Left = MIN(FirstX,TempX);
        NewVCL->Control->Top = MIN(FirstY,TempY);
        NewVCL->Control->Width = MAX(FirstX,TempX) - MIN(FirstX,TempX);
        NewVCL->Control->Height = MAX(FirstY,TempY) - MIN(FirstY,TempY);
    }
    else
    {
        NewVCL->Control->Left = FirstX;
        NewVCL->Control->Top = FirstY;
    }
    NewVCL->Control->ComponentState<<csDesigning;
    if (NewVCL->CanHaveChild())
        NewVCL->Control->ComponentState<<csDesignInstance;
    VCL->AddChild(NewVCL);
    DialogEdit->ClearSelection();
    DialogEdit->Selected.Add(NewVCL);
    DialogEdit->DrawSelection(false,true,true);
    ToolBarF->DialogTools.ActiveList = (TClassId)cnMouse-1;
    ObjInspector->AddObject(NewVCL->Component, NewVCL->Component->Name);
//    DialogEdit->TreeView->Tree = DialogEdit->Head;
}

//---------------------------------------------------------------------------
TSelectTool::TSelectTool(int _ClassId)
{
    ImageId=_ClassId-1;
    ClassId=_ClassId;
    //State: (Add Block)
    //-----------------------------------------------------------------------
    AddStateBlock(stState1_WaitingFirstAction, WaitingFirstAction, Mouse_Move, btNone, "Ожидание клика мыши, или нажатия клавиши.");
    AddStateBlock(stState2_WaitingMouseUpClickForSelect, WaitingMouseUpClickForSelect, Mouse_Move, btMenu, "Выделение: Ожидание 'MouseUp', чтобы сформировать границы выделения.");
    AddStateBlock(stState3_DragControls, DragControls, Mouse_Move, btMenu, "Перетаскивание: перетаскивание созданных объектов на форме пока не 'MouseUp'.");
    AddStateBlock(stState4_WaitingMouseUpClickForReSize, WaitingMouseUpClickForReSize, Mouse_Move, btMenu, "Изменение размера: Ожидание 'MouseUp', чтобы свормировать новые границы объекта.");
    //Condition: (Add Block)
    //-----------------------------------------------------------------------
    AddConditionalBlock(stCondition1_IfShiftPressed, IfShiftPressed, btNone, "Проверка на нажатие клавиши 'Shift'.");
    AddConditionalBlock(stCondition2_IfMouseOnBorder, IfMouseOnBorder, btNone, "Проверка позиции мыши на границе объекта, для определения: Изменение размера, или Перетаскивание.");
    AddConditionalBlock(stCondition3_IfMouseOnControl, IfMouseOnControl, btNone, "Проверка позиции мыши на объекте, для определения: Выделение, или Перетаскивание.");
    AddConditionalBlock(stCondition4_IfShiftOnControl, IfShiftOnControl, btNone, "Проверка на нажатие клавиши 'Shift' при позиции мыши 'На объекте'.");
    AddConditionalBlock(stCondition5_IfShiftOnSelection, IfShiftOnSelection, btNone, "Проверка на нажатие клавиши 'Shift' при позиции мыши 'На выделении'.");
    //Active: (Add Block)
    //-----------------------------------------------------------------------
    AddActionBlock(stActive_SelectClickControl, SelectClickControl, btNone, "Определение Control'а по клику.");
    AddActionBlock(stActiveStart_StartTool, StartTool, btNone, "Очистка экрана, перерисовка Grid на новом цикле действия SelectTool.");
    AddActionBlock(stActive2_ReactionOnButtonClick, ReactionOnButtonClick, btMenu, "KeyPressed: Определение нажатия клавиш 'Ctrl', 'Shift', или 'Delete' для выбора соответсвующего действия. Исполнение выбранного действия.");
    AddActionBlock(stActive3_SelectControls, SelectControls, btNone, "Выбор выделенных объектов - добавление их в соответствующие списки выделения.");
    AddActionBlock(stActive4_DeleteControlFromList, DeleteControlFromList, btNone, "Удаление объекта из списков выделения.");
    AddActionBlock(stActive5_InsertControlToList, InsertControlToList, btNone, "Добавление объекта в списки выделения.");
    //State: (Go to Block)
    //-----------------------------------------------------------------------
    AddGoToBlockId(WaitingFirstAction, SelectClickControl, Mouse_Down, mbLeft);
    AddGoToBlockId(WaitingFirstAction, ReactionOnButtonClick, Key_Down, VK_UP);
    AddGoToBlockId(WaitingFirstAction, ReactionOnButtonClick, Key_Down, VK_DOWN);
    AddGoToBlockId(WaitingFirstAction, ReactionOnButtonClick, Key_Down, VK_LEFT);
    AddGoToBlockId(WaitingFirstAction, ReactionOnButtonClick, Key_Down, VK_RIGHT);
    AddGoToBlockId(WaitingMouseUpClickForSelect, SelectControls, Mouse_Up, mbLeft);
    AddGoToBlockId(DragControls, StartTool, Mouse_Up, mbLeft);
    AddGoToBlockId(WaitingMouseUpClickForReSize, StartTool, Mouse_Up, mbLeft);
    //Condition: (Go to Block)
    //-----------------------------------------------------------------------
    AddGoToBlockId(IfShiftPressed, IfShiftOnControl, IfMouseOnControl);
    AddGoToBlockId(IfMouseOnBorder, WaitingMouseUpClickForReSize, DragControls);
    AddGoToBlockId(IfMouseOnControl, IfMouseOnBorder, WaitingMouseUpClickForSelect);
    AddGoToBlockId(IfShiftOnControl, IfShiftOnSelection, WaitingMouseUpClickForSelect);
    AddGoToBlockId(IfShiftOnSelection, DeleteControlFromList, InsertControlToList);
    //Active: (Go to Block)
    //-----------------------------------------------------------------------
    AddGoToBlockId(SelectClickControl, IfShiftPressed);
    AddGoToBlockId(StartTool, WaitingFirstAction);
    AddGoToBlockId(ReactionOnButtonClick, StartTool);
    AddGoToBlockId(SelectControls, StartTool);
    AddGoToBlockId(DeleteControlFromList, StartTool);
    AddGoToBlockId(InsertControlToList, StartTool);
}

//---------------------------------------------------------------------------
void TSelectTool::stState1_WaitingFirstAction()
{
    TWinControl* ClickControl = (TWinControl*)UIP.Sender;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(ClickControl);
    Screen->Cursor=crArrow;
    if((DialogEdit->Selected.Count == 1) && (ClickControl != DialogEdit))
    {
        DirectionIndex = -1;
        for(int j = 0; j < 8; j++)
        {
            if((ClickControl->Parent->ScreenToClient(Mouse->CursorPos).x <= VCL->Rects[j].right) &&
               (ClickControl->Parent->ScreenToClient(Mouse->CursorPos).x >= VCL->Rects[j].left) &&
               (ClickControl->Parent->ScreenToClient(Mouse->CursorPos).y >= VCL->Rects[j].top) &&
               (ClickControl->Parent->ScreenToClient(Mouse->CursorPos).y <= VCL->Rects[j].bottom))
                   DirectionIndex = j;
        }
        if(DirectionIndex != -1)
            switch(DirectionIndex)
            {
                case RightMiddle    : Screen->Cursor = crSizeWE; break;
                case RightBottom    : Screen->Cursor = crSizeNWSE; break;
                case MiddleBottom   : Screen->Cursor = crSizeNS; break;
                case LeftBottom     : Screen->Cursor = crSizeNESW; break;
                case RightTop       : Screen->Cursor = crSizeNESW; break;
                case MiddleTop      : Screen->Cursor = crSizeNS; break;
                case LeftMiddle     : Screen->Cursor = crSizeWE; break;
                case LeftTop        : Screen->Cursor = crSizeNWSE; break;
            }
        DirectionIndex = -1;
    }
}

//---------------------------------------------------------------------------
void TSelectTool::OnRender()
{
}

//---------------------------------------------------------------------------
void TSelectTool::stState2_WaitingMouseUpClickForSelect()
{
    DialogEdit->Canvas->Pen->Color = clBlack;
    DialogEdit->Canvas->Pen->Mode = pmXor;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    Types::TPoint _Point = Point(DialogEdit->ScreenToClient(Mouse->CursorPos).x, DialogEdit->ScreenToClient(Mouse->CursorPos).y);
    DialogEdit->Canvas->DrawFocusRect( Rect(MIN(px,tx),MIN(py,ty),MAX(px,tx),MAX(py,ty)) );
    tx = _Point.x;
    ty = _Point.y;
    DialogEdit->Canvas->DrawFocusRect( Rect(MIN(px,tx),MIN(py,ty),MAX(px,tx),MAX(py,ty)) );
    DialogEdit->Canvas->Pen->Mode = pmCopy;
}

//---------------------------------------------------------------------------
void TSelectTool::stState3_DragControls()
{
    int i;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    Types::TPoint OldPoint;
    OldPoint = Point((VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep) * DialogEdit->GridStep,((VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep) * DialogEdit->GridStep));
    for(i = 0; i < DialogEdit->Selected.Count; i++)
      DialogEdit->DrawFrameRect(i, VCL);
    for(int i = 0; i<DialogEdit->Selected.Count; i++)
    {
        DialogEdit->BorderFrame.Items[i]->Top += OldPoint.y - SelectionTop;
        DialogEdit->BorderFrame.Items[i]->Left += OldPoint.x - SelectionLeft;
        DialogEdit->BorderFrame.Items[i]->Bottom += OldPoint.y - SelectionTop;
        DialogEdit->BorderFrame.Items[i]->Right += OldPoint.x - SelectionLeft;
    }
    for(i = 0; i<DialogEdit->Selected.Count; i++)
      DialogEdit->DrawFrameRect(i, VCL);
    SelectionTop = OldPoint.y;
    SelectionLeft = OldPoint.x;
    if(!DialogEdit->Change)
      DialogEdit->Change = true;
}

//---------------------------------------------------------------------------
void TSelectTool::stState4_WaitingMouseUpClickForReSize()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    Types::TPoint OldPoint;
    OldPoint = Point((DialogEdit->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep) * DialogEdit->GridStep,((DialogEdit->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep) * DialogEdit->GridStep));
    for(int i = 0; i< DialogEdit->Selected.Count; i++)
    {
        DialogEdit->DrawFrameRect(i, VCL);
        DialogEdit->Canvas->Pen->Width = 2;
        DialogEdit->Canvas->Pen->Mode = pmXor;
        DialogEdit->Canvas->Pen->Color = clWhite;
        TPoint *Points = new TPoint[5];
        Points[0] = Point(DialogEdit->Selected.Items[i]->Control->Left, DialogEdit->Selected.Items[i]->Control->Top + DialogEdit->Selected.Items[i]->Control->Height);
        Points[1] = Point(DialogEdit->Selected.Items[i]->Control->Left, DialogEdit->Selected.Items[i]->Control->Top);
        Points[2] = Point(DialogEdit->Selected.Items[i]->Control->Left + DialogEdit->Selected.Items[i]->Control->Width, DialogEdit->Selected.Items[i]->Control->Top);
        Points[3] = Point(DialogEdit->Selected.Items[i]->Control->Left + DialogEdit->Selected.Items[i]->Control->Width, DialogEdit->Selected.Items[i]->Control->Top + DialogEdit->Selected.Items[i]->Control->Height);
        Points[4] = Point(DialogEdit->Selected.Items[i]->Control->Left, DialogEdit->Selected.Items[i]->Control->Top + DialogEdit->Selected.Items[i]->Control->Height);
        DialogEdit->Canvas->Polyline( Points, 4 );
        DialogEdit->Canvas->Pen->Mode = pmCopy;
        DialogEdit->Canvas->Pen->Width = 1;
        delete Points;
    }
    switch(DirectionIndex)
    {
        case RightMiddle :
            if(DialogEdit->BorderFrame.Items[0]->Left <= OldPoint.x) DialogEdit->BorderFrame.Items[0]->Right = OldPoint.x;
            else
            {
                DialogEdit->BorderFrame.Items[0]->Right = DialogEdit->BorderFrame.Items[0]->Left;
                DirectionIndex = LeftMiddle;
            }
        break;
        case RightBottom :
            if((DialogEdit->BorderFrame.Items[0]->Left <= OldPoint.x) || (DialogEdit->BorderFrame.Items[0]->Top <= OldPoint.y))
            {
                DialogEdit->BorderFrame.Items[0]->Right = OldPoint.x;
                DialogEdit->BorderFrame.Items[0]->Bottom = OldPoint.y;
            }
            else
            {
                DialogEdit->BorderFrame.Items[0]->Right = DialogEdit->BorderFrame.Items[0]->Left;
                DialogEdit->BorderFrame.Items[0]->Bottom = DialogEdit->BorderFrame.Items[0]->Top;
                DirectionIndex = LeftTop;
            }
        break;
        case MiddleBottom :
            if(DialogEdit->BorderFrame.Items[0]->Top <= OldPoint.y) DialogEdit->BorderFrame.Items[0]->Bottom = OldPoint.y;
            else
            {
                DialogEdit->BorderFrame.Items[0]->Bottom = DialogEdit->BorderFrame.Items[0]->Top;
                DirectionIndex = MiddleTop;
            }
        break;
        case LeftBottom :
            if((DialogEdit->BorderFrame.Items[0]->Right >= OldPoint.x) || (DialogEdit->BorderFrame.Items[0]->Top <= OldPoint.y))
            {
                DialogEdit->BorderFrame.Items[0]->Left = OldPoint.x;
                DialogEdit->BorderFrame.Items[0]->Bottom = OldPoint.y;
            }
            else
            {
                DialogEdit->BorderFrame.Items[0]->Left = DialogEdit->BorderFrame.Items[0]->Right;
                DialogEdit->BorderFrame.Items[0]->Bottom = DialogEdit->BorderFrame.Items[0]->Top;
                DirectionIndex = RightTop;
            }
        break;
        case RightTop :
            if((DialogEdit->BorderFrame.Items[0]->Left <= OldPoint.x) || (DialogEdit->BorderFrame.Items[0]->Bottom >= OldPoint.y))
            {
                DialogEdit->BorderFrame.Items[0]->Right = OldPoint.x;
                DialogEdit->BorderFrame.Items[0]->Top = OldPoint.y;
            }
            else
            {
                DialogEdit->BorderFrame.Items[0]->Right = DialogEdit->BorderFrame.Items[0]->Left;
                DialogEdit->BorderFrame.Items[0]->Top = DialogEdit->BorderFrame.Items[0]->Bottom;
                DirectionIndex = LeftBottom;
            }
        break;
        case MiddleTop :
            if(DialogEdit->BorderFrame.Items[0]->Bottom >= OldPoint.y) DialogEdit->BorderFrame.Items[0]->Top = OldPoint.y;
            else
            {
                DialogEdit->BorderFrame.Items[0]->Top = DialogEdit->BorderFrame.Items[0]->Bottom;
                DirectionIndex = MiddleBottom;
            }
        break;
        case LeftMiddle :
            if(DialogEdit->BorderFrame.Items[0]->Right >= OldPoint.x) DialogEdit->BorderFrame.Items[0]->Left = OldPoint.x;
            else
            {
                DialogEdit->BorderFrame.Items[0]->Left = DialogEdit->BorderFrame.Items[0]->Right;
                DirectionIndex = RightMiddle;
            }
        break;
        case LeftTop :
            if((DialogEdit->BorderFrame.Items[0]->Right >= OldPoint.x) || (DialogEdit->BorderFrame.Items[0]->Bottom >= OldPoint.y))
            {
                DialogEdit->BorderFrame.Items[0]->Left = OldPoint.x;
                DialogEdit->BorderFrame.Items[0]->Top = OldPoint.y;
            }
            else
            {
                DialogEdit->BorderFrame.Items[0]->Left = DialogEdit->BorderFrame.Items[0]->Right;
                DialogEdit->BorderFrame.Items[0]->Top = DialogEdit->BorderFrame.Items[0]->Bottom;
                DirectionIndex = RightBottom;
            }
        break;
    }
    for(int i = 0; i < DialogEdit->Selected.Count; i++)
        DialogEdit->DrawFrameRect(i, VCL);
    if(!DialogEdit->Change)
        DialogEdit->Change = true;
}

//---------------------------------------------------------------------------
bool TSelectTool::stCondition1_IfShiftPressed()
{
    if(UIP.Shift.Contains(ssShift))
        return true;
    return false;
}

//---------------------------------------------------------------------------
bool TSelectTool::stCondition2_IfMouseOnBorder()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    DirectionIndex = -1;
    TRect *BorderRect[255];
    for(int i = 0; i<DialogEdit->Selected.Count; i++)
    {
        BorderRect[i] = new TRect(0,0,0,0);
        BorderRect[i]->Left = DialogEdit->Selected.Items[i]->Control->Left;
        BorderRect[i]->Top = DialogEdit->Selected.Items[i]->Control->Top;
        BorderRect[i]->Right = DialogEdit->Selected.Items[i]->Control->Left + DialogEdit->Selected.Items[i]->Control->Width;
        BorderRect[i]->Bottom = DialogEdit->Selected.Items[i]->Control->Top + DialogEdit->Selected.Items[i]->Control->Height;
        DialogEdit->BorderFrame.Add(BorderRect[i]);
    }
    for(int i = 0; i< DialogEdit->Selected.Count; i++)
      DialogEdit->DrawFrameRect(i, VCL);
    DialogEdit->DrawSelection(false, false, true);
    for(int j = 0; j < 8; j++)
    {
        if((VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).x <= VCL->Rects[j].right + DialogEdit->GridStep / 2) &&
           (VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).x >= VCL->Rects[j].left - DialogEdit->GridStep / 2) &&
           (VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).y >= VCL->Rects[j].top - DialogEdit->GridStep / 2) &&
           (VCL->VCLParent->Control->ScreenToClient(Mouse->CursorPos).y <= VCL->Rects[j].bottom + DialogEdit->GridStep / 2))
               DirectionIndex = j;
    }
    if((DirectionIndex != -1) && (DialogEdit->Selected.Count == 1))
        return true;
    return false;
}

//---------------------------------------------------------------------------
bool TSelectTool::stCondition3_IfMouseOnControl()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    TVCLEditorElement* VCLParent = DialogEdit->Head;
    if( VCL->Component != DialogEdit ) VCLParent = VCL->VCLParent;
    Types::TPoint OldPoint;
    OldPoint = Point(UIP.NewCursorPos.intX(),UIP.NewCursorPos.intY());
    ty = SelectionTop = (VCLParent->Control->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep) * DialogEdit->GridStep;
    tx = SelectionLeft = (VCLParent->Control->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep) * DialogEdit->GridStep;
    py = (VCL->Control->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep)* DialogEdit->GridStep;
    px = (VCL->Control->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep)* DialogEdit->GridStep;
    if ((VCL->Component == DialogEdit) || (UIP.Shift.Contains(ssCtrl)))
    {
        ty = SelectionTop = (DialogEdit->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep) * DialogEdit->GridStep;
        tx = SelectionLeft = (DialogEdit->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep) * DialogEdit->GridStep;
        py = (DialogEdit->ScreenToClient(Mouse->CursorPos).y / DialogEdit->GridStep)* DialogEdit->GridStep;
        px = (DialogEdit->ScreenToClient(Mouse->CursorPos).x / DialogEdit->GridStep)* DialogEdit->GridStep;
        DialogEdit->ClearSelection();
        return false;
    }
    else
    {
        if ( DialogEdit->Selected.IndexOf(VCL) == -1)
        {
            DialogEdit->ClearSelection();
            DialogEdit->Selected.Add(VCL);
            ObjInspector->ObjectToSelect(VCL->Component, true);
        }
        return true;
    }
}

//---------------------------------------------------------------------------
bool TSelectTool::stCondition4_IfShiftOnControl()
{
    if ((DialogEdit->GetVCLEdEl(MyClickControl))->Component != DialogEdit)
        return true;
    return false;
}

//---------------------------------------------------------------------------
bool TSelectTool::stCondition5_IfShiftOnSelection()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    if (DialogEdit->Selected.IndexOf(VCL) != -1)
        return true;
    return false;
}

//---------------------------------------------------------------------------
void TSelectTool::stActive_SelectClickControl()
{
    int Index;
    DialogEdit->Invalidate();
    MyClickControl = (TForm*)UIP.Sender;
    if ( IS ( MyClickControl, __classid ( TPageControl ) ) )
    {
        Index  = ((TPageControl*)MyClickControl)->IndexOfTabAt(MyClickControl->ScreenToClient(Mouse->CursorPos).x, MyClickControl->ScreenToClient(Mouse->CursorPos).y);
        if ( Index != -1 )
        {
            ((TPageControl*)MyClickControl)->ActivePageIndex = Index;
            MyClickControl = ((TPageControl*)MyClickControl)->ActivePage;
        }
    }
}

//---------------------------------------------------------------------------
void TSelectTool::stActiveStart_StartTool()
{
    if ( DialogEdit->ReDraw )
    {
        DialogEdit->Invalidate();
        DialogEdit->Head->InvalidateFrame(DialogEdit->Head, Rect(0, 0, DialogEdit->Width, DialogEdit->Height));
    }
    bool Flag = true;
    if(DialogEdit->Change)
        for(int i = 0; i < DialogEdit->Selected.Count; i++)
        {
            DialogEdit->Selected.Items[i]->Control->Left = MIN(DialogEdit->BorderFrame.Items[i]->Left, DialogEdit->BorderFrame.Items[i]->Right);
            DialogEdit->Selected.Items[i]->Control->Top = MIN(DialogEdit->BorderFrame.Items[i]->Top, DialogEdit->BorderFrame.Items[i]->Bottom);
            DialogEdit->Selected.Items[i]->Control->Height = abs(DialogEdit->BorderFrame.Items[i]->Height());
            DialogEdit->Selected.Items[i]->Control->Width = abs(DialogEdit->BorderFrame.Items[i]->Width());
            ObjInspector->ReAct(DialogEdit->Selected.Items[i]->Control, Flag);
            DialogEdit->Selected.Items[i]->Control->Invalidate();
            delete DialogEdit->BorderFrame.Items[i];
            Flag = false;
        }
    DialogEdit->DrawSelection(false,true,true);
    DialogEdit->DrawSelection(true,false,false);
    DialogEdit->Change = false;
    DialogEdit->ReDraw = true;
    DialogEdit->BorderFrame.Clear();
}

//---------------------------------------------------------------------------
void TSelectTool::stActive2_ReactionOnButtonClick()
{
    bool Flag = true;
    //If Shift Pressed:
    int dx = 0, dy = 0;
    if( UIP.Shift.Contains(ssShift) )
        {
            for(int i = 0; i < DialogEdit->Selected.Count; i++)
            {
                    if( UIP.Key == VK_UP && (DialogEdit->Selected.Items[i]->Control->Height - 1 > DialogEdit->GridStep) ) dy = -1;
                    if( UIP.Key == VK_LEFT && (DialogEdit->Selected.Items[i]->Control->Width - 1 > DialogEdit->GridStep) ) dx = -1;
                    if( UIP.Key == VK_DOWN ) dy=1;
                    if( UIP.Key == VK_RIGHT ) dx=1;
                    DialogEdit->Selected.Items[i]->Control->Width += dx;
                    DialogEdit->Selected.Items[i]->Control->Height += dy;
                    ObjInspector->ReAct(DialogEdit->Selected.Items[i]->Control, Flag);
                    Flag = false;
            }
            DialogEdit->DrawSelection(true,true,true);
            return;
        }
    //If Control Pressed:
    Flag = true;
    if( UIP.Shift.Contains(ssCtrl) )
    {
        for(int i = 0; i<DialogEdit->Selected.Count; i++)
        {
                if( UIP.Key == VK_UP )
                    DialogEdit->Selected.Items[i]->Control->Top -= 1;
                if( UIP.Key == VK_LEFT )
                    DialogEdit->Selected.Items[i]->Control->Left -= 1;
                if( UIP.Key == VK_DOWN )
                    DialogEdit->Selected.Items[i]->Control->Top += 1;
                if( UIP.Key == VK_RIGHT )
                    DialogEdit->Selected.Items[i]->Control->Left += 1;
                ObjInspector->ReAct(DialogEdit->Selected.Items[i]->Control, Flag);
                Flag = false;
        }
        DialogEdit->DrawSelection(true,true,true);
        return;
    }
    //Move Cursor:
    int i,j,path,oldpath = 0x7fffffff;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(DialogEdit);
    if(DialogEdit->Selected.Count == 1)
    {
        for(i = 0, j = -1; i<DialogEdit->Head->VCLChildCount; i++)
            {
                dx = DialogEdit->Head->VCLChild[i]->Control->Left - DialogEdit->Selected.Items[0]->Control->Left;
                dy = DialogEdit->Head->VCLChild[i]->Control->Top - DialogEdit->Selected.Items[0]->Control->Top;
                path = sqrt(dx*dx + dy*dy);
                if(( ( UIP.Key == VK_UP && (DialogEdit->Selected.Items[0]->Control->Top > DialogEdit->Head->VCLChild[i]->Control->Top)) ||
                ( UIP.Key == VK_LEFT && (DialogEdit->Selected.Items[0]->Control->Left > DialogEdit->Head->VCLChild[i]->Control->Left)) ||
                ( UIP.Key == VK_DOWN && (DialogEdit->Selected.Items[0]->Control->Top < DialogEdit->Head->VCLChild[i]->Control->Top)) ||
                ( UIP.Key == VK_RIGHT && (DialogEdit->Selected.Items[0]->Control->Left < DialogEdit->Head->VCLChild[i]->Control->Left))) && (path < oldpath))
                {
                    oldpath = path;
                    j = i;
                }
            }
            if(j != -1)
            {
                DialogEdit->Selected.Clear();
                DialogEdit->Selected.Add( VCL->VCLChild[j] );
            }
    }
    DialogEdit->ReDraw = false;
}

//---------------------------------------------------------------------------
void TSelectTool::stActive3_SelectControls()
{
    int i;
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    TVCLEditorElement* VCLParent = DialogEdit->GetVCLEdEl(DialogEdit);
    if( VCL->Component != DialogEdit ) VCLParent = VCL->VCLParent;
    Types::TPoint OldPoint;
    Types::TRect Selection;
    OldPoint = Point(UIP.NewCursorPos.intX(),UIP.NewCursorPos.intY());
    if(UIP.Shift.Contains(ssCtrl) && ((DialogEdit->GetVCLEdEl(MyClickControl))->Component != DialogEdit))
        Selection = Rect(MIN((long)SelectionLeft - VCL->Control->Left,(VCL->LocalToParent(VCLParent->Control,OldPoint)).x),MIN((long)SelectionTop - VCL->Control->Top,(VCL->LocalToParent(VCLParent->Control,OldPoint)).y),MAX((long)SelectionLeft - VCL->Control->Left,(VCL->LocalToParent(VCLParent->Control,OldPoint)).x),MAX((long)SelectionTop - VCL->Control->Top,(VCL->LocalToParent(VCLParent->Control,OldPoint)).y));
    else Selection = Rect(MIN((long)SelectionLeft,(VCL->LocalToParent(VCLParent->Control,OldPoint)).x),MIN((long)SelectionTop,(VCL->LocalToParent(VCLParent->Control,OldPoint)).y),MAX((long)SelectionLeft,(VCL->LocalToParent(VCLParent->Control,OldPoint)).x),MAX((long)SelectionTop,(VCL->LocalToParent(VCLParent->Control,OldPoint)).y));
    MyClickControl->Invalidate();
    VCL->SelectChildsByRect(Selection, DialogEdit->Selected);
    if (DialogEdit->Selected.Count == 0)
        ObjInspector->ObjectToSelect(DialogEdit, true);
    else
    {
        ObjInspector->ClearSelect();
        for (i = 0; i < DialogEdit->Selected.Count - 1; i++)
        {
           ObjInspector->ObjectToSelect(DialogEdit->Selected.Items[i]->Component, false, true);
//           DialogEdit->TreeView->SelectObject(DialogEdit->Selected.Items[i]->Component, true);
        }
        ObjInspector->ObjectToSelect(DialogEdit->Selected.Items[i]->Component, true, true);
//        DialogEdit->TreeView->SelectObject(DialogEdit->Selected.Items[i]->Component, true);
    }
    DialogEdit->DrawSelection(false,true,true);
}

//---------------------------------------------------------------------------
void TSelectTool::stActive4_DeleteControlFromList()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    DialogEdit->Selected.Delete(DialogEdit->Selected.IndexOf(VCL));
    ObjInspector->ObjectFromSelect(VCL->Component);
//    DialogEdit->TreeView->DeleteObject(VCL->Component);
    DialogEdit->DrawSelection(true,true,false);
}

//---------------------------------------------------------------------------
void TSelectTool::stActive5_InsertControlToList()
{
    TVCLEditorElement* VCL = DialogEdit->GetVCLEdEl(MyClickControl);
    DialogEdit->Selected.Add(VCL);
    ObjInspector->ObjectToSelect(VCL->Component, true, true);
//    DialogEdit->TreeView->SelectObject(VCL->Component, true);
    DialogEdit->DrawSelection(false,true,true);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
