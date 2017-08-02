//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "FloatingV.h"
#include "BaseDockSiteFormV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFormV"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFloatForm::TFloatForm(TComponent* Owner)
    : TBaseForm(Owner)
{
    NeedToResize = true;
    DoRestoreSize = false;
    Fixed = false;
    AL = AlignBottom;
    DefaultSize = 130;
    FixedSize = 22;
    FDockIndex = 0;
}
//---------------------------------------------------------------------------
TMyControlState::TMyControlState()
{
    Parent = NULL;

    Align = -1000;

    Height = -1000;
    Width= -1000;

    Left = -1000;
    Top = -1000;
}

void TMyControlState::ApplyToControl(TControl* Control)
{
    if (Parent!=NULL)
        Control->Parent = Parent;

    if (Align!=-1000)
        Control->Align = (TAlign)Align;

    if (Height!=-1000)
        Control->Height = Height;
    if (Width!=-1000)
        Control->Width = Width;

    if (Left!=-1000)
        Control->Left = Left;
    if (Top!=-1000)
        Control->Top = Top;
}

/*    TMyControlState BackPanel;
    TMyControlState MainToolBar;
    TMyControlState MinPanel;
    TMyControlState PanelPos;
    TMyControlState ParentUp;
    TMyControlState SMALL;
    TMyControlState BIG;
    TMyControlState UgolPanel;
*/

void TFloatForm::SetAL(int aAL)
{
    FAL = aAL;
    NeedToResize=true;
    Invalidate();
}

void TFloatForm::SetFixed(bool aFixed)
{
    FFixed = aFixed;
    NeedToResize=true;
    DoRestoreSize = !FFixed;
    Invalidate();
}

void TFloatForm::SetFixedSize(int aFixedSize)
{
    FFixedSize = aFixedSize;
    NeedToResize=true;
    Invalidate();
}

void TFloatForm::SetDefaultSize(int aDefaultSize)
{
    FDefaultSize = aDefaultSize;
    LRDockWidth = FDefaultSize;
    TBDockHeight = FDefaultSize;
}

void __fastcall TFloatForm::FormEndDock(TObject *Sender, TObject *Target,
      int X, int Y)
{
    if (!Parent)
    {
        AL = AlignBottom;
        DoRestoreSize = true;
        return;
    }
	else if ( DockIndex != GetParentDockIndex(Parent) )
		return;
    if ( Parent->Align == alBottom )
        AL = AlignBottom;
    else if ( Parent->Align == alLeft )
        AL = AlignLeft;
    else if ( Parent->Align == alRight )
        AL = AlignRight;
}
//---------------------------------------------------------------------------
void TFloatForm::SetDockIndex(int aDockIndex)
{
	FDockIndex = aDockIndex;
	if ( Parent )
    {
    	GetParentDockIndex(Parent) != DockIndex;
        Parent = NULL;
    }
}

int TFloatForm::GetParentDockIndex(TWinControl* aParent)
{
	if ( !IS(aParent,__classid(TPanel)) )
    {
    	AnsiString ClassParent = aParent->ClassName();
//    	ErrorMsg(AnsiString("<TFloatForm::GetParentDockIndex>: не допустимый класс родителя плавающей формы - <")+ClassParent+AnsiString(">."));
		return -1;
    }
    if ( !((TPanel*)aParent)->Parent )
    {
//    	ErrorMsg(AnsiString("<TFloatForm::GetParentDockIndex>: родительская панель не имеет родителя."));
		return -1;
    }
    if ( !IS(((TPanel*)aParent)->Parent,__classid(TBaseDockSiteForm)) )
    {
    	AnsiString ClassParent = ((TPanel*)aParent)->Parent->ClassName();
//    	ErrorMsg(AnsiString("<TFloatForm::GetParentDockIndex>: не допустимый класс dock-site формы - <")+ClassParent+AnsiString(">.") );
		return -1;
    }
    return  ((TBaseDockSiteForm*)((TPanel*)aParent)->Parent)->DockIndex;
}


void __fastcall TFloatForm::WndProc(Messages::TMessage &Message)
{
	switch( Message.Msg )
    {
    	case WM_SIZE:
        {
            if (Fixed)
            {
                NeedToResize = true;
                Invalidate();
            }
        }break;
    	case WM_SHOWWINDOW:
        {
            if (NeedToResize)
            {
                FormEndDock(NULL,NULL,0,0);
                //FormPaint(Sender);
            }
        }//break; переход на WM_PAINT
    	case WM_PAINT:
        {
            if (NeedToResize)
            {
                if (Parent)
                {
                    if (AL == AlignLeft || AL == AlignRight)
                        Parent->Width = (Fixed) ? FixedSize : DefaultSize;
                    else
                        Parent->Height = (Fixed) ? FixedSize : DefaultSize;
                }
                else if ( Fixed || DoRestoreSize)
                {
                    if (AL == AlignLeft || AL == AlignRight)
                    {
                        ClientWidth = (Fixed) ? FixedSize : DefaultSize;
                        if (DoRestoreSize && ClientHeight< ClientWidth*3)
                            ClientHeight = ClientWidth*3;
                    }
                    else
                    {
                        ClientHeight = (Fixed) ? FixedSize : DefaultSize;
                        if (DoRestoreSize && ClientWidth < ClientHeight*3)
                            ClientWidth = ClientHeight*3;
                    }
                    DoRestoreSize = false;
                }
                OnMyResize();
                NeedToResize=false;
            }
        }break;
    }
    TBaseForm::WndProc(Message);
}

