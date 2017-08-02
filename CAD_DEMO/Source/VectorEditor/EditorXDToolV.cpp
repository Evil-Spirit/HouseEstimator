//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "EditorXDToolV.h"

#include "EditorV.h"

TClassNode* TEditorXDTool::StaticType = NULL;
//---------------------------------------------------------------------------
void TMyEditorControls::MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMyControls::MouseMove( Sender, Shift, CursorPosition);
    TMyView* EXD = (TMyView*)Sender;
    EXD->View->InvalidateGL();
}

void TMyEditorControls::MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMyControls::MouseDown( Sender, Button, Shift, CursorPosition);
    TMyView* EXD = (TMyView*)Sender;
    EXD->View->InvalidateGL();
}

void TMyEditorControls::MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    TMyControls::MouseUp( Sender, Button, Shift, CursorPosition);
    TMyView* EXD = (TMyView*)Sender;
    EXD->View->InvalidateGL();
}

void TMyEditorControls::KeyDown(void* Sender, WORD &Key, TShiftState Shift)
{
    TMyControls::KeyDown( Sender, Key, Shift);
    TMyView* EXD = (TMyView*)Sender;
    EXD->View->InvalidateGL();
}

void TMyEditorControls::KeyUp(void* Sender, WORD &Key, TShiftState Shift)
{
    TMyControls::KeyUp( Sender, Key, Shift);
    TMyView* EXD = (TMyView*)Sender;
    EXD->View->InvalidateGL();
}

//------------------------------------------------------------------------------
TEditor2D* TEditorXDTool::getEditorXD()
{
    return (TEditor2D*)UIP.Sender;
};

void TEditorXDTool::setEditorXD(TEditor2D* EXD)
{
    UIP.Sender = EXD;
};

#pragma package(smart_init)
