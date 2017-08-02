//---------------------------------------------------------------------------

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>

#include "ProgramPropertyV.h"
#include "EditorV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgramProperty *ProgramProperty;
//---------------------------------------------------------------------------
__fastcall TProgramProperty::TProgramProperty(TComponent* Owner)
    : TForm(Owner)
{
    ProgramProperty->cbSnapOn->Checked = Editor2D->Attributes.Snap;
    ProgramProperty->cbAdditionalSnapOn->Checked = Editor2D->Attributes.AdditionalFiguresSnap;
    ProgramProperty->cbMyFigureSnapOn->Checked = Editor2D->Attributes.SnapMyFigures;
    ProgramProperty->eSnapValue->Text = IntToStr(Editor2D->Attributes.SnapValuePix);
    ProgramProperty->eSnapStep->Text = IntToStr(Editor2D->Grid.Attr.SnapStep);
    ProgramProperty->cbGridOn->Checked = Editor2D->Grid.Attr.Visible;
    ProgramProperty->eStep->Text = FloatToStr(Editor2D->Grid.Attr.Step);
    ProgramProperty->eMultiplier->Text = IntToStr(Editor2D->Grid.Attr.Multiplier);
    ProgramProperty->eZoomLimit->Text = IntToStr(Editor2D->Grid.Attr.ZoomLimit);
    ProgramProperty->eSwitchEpsilon->Text = IntToStr(Editor2D->Grid.Attr.SwitchEpsilon);
    ProgramProperty->cbGridMIN->Selected = Editor2D->Grid.Attr.Colors.MIN;
    ProgramProperty->cbGridMAX->Selected = Editor2D->Grid.Attr.Colors.MAX;
    ProgramProperty->cbGridOSI->Selected = Editor2D->Grid.Attr.Colors.OSI;
    ProgramProperty->cbAdditional->Selected = Editor2D->Attributes.Colors.Additional;
    ProgramProperty->cbMyFigures->Selected = Editor2D->Attributes.Colors.MyFigures;
    ProgramProperty->cbSelected->Selected = Editor2D->Attributes.Colors.Selected;
    ProgramProperty->cbFixid->Selected = Editor2D->Attributes.Colors.Fixid;
    ProgramProperty->cbBackGround->Selected = Editor2D->Attributes.Colors.BackGround;
    ProgramProperty->cbCursor->Selected = Editor2D->MyCursor.Color;
}
//---------------------------------------------------------------------------
void __fastcall TProgramProperty::StepExit(TObject *Sender)
{
//    ProgramProperty->Close();
}
//---------------------------------------------------------------------------



void __fastcall TProgramProperty::bOkClick(TObject *Sender)
{
    Editor2D->Attributes.Snap = ProgramProperty->cbSnapOn->Checked;
    Editor2D->Attributes.AdditionalFiguresSnap = ProgramProperty->cbAdditionalSnapOn->Checked;
    Editor2D->Attributes.SnapMyFigures = ProgramProperty->cbMyFigureSnapOn->Checked;
    Editor2D->Attributes.SnapValuePix = StrToInt(ProgramProperty->eSnapValue->Text);
    Editor2D->Grid.Attr.SnapStep = StrToInt(ProgramProperty->eSnapStep->Text);
    Editor2D->Grid.Attr.Visible = ProgramProperty->cbGridOn->Checked;
    Editor2D->Grid.Attr.Snap = ProgramProperty->cbGridOn->Checked;
    Editor2D->Grid.Attr.Step = StrToFloat(ProgramProperty->eStep->Text);
    Editor2D->Grid.Attr.Multiplier = StrToInt(ProgramProperty->eMultiplier->Text);
    Editor2D->Grid.Attr.ZoomLimit = StrToInt(ProgramProperty->eZoomLimit->Text);
    Editor2D->Grid.Attr.SwitchEpsilon = StrToInt(ProgramProperty->eSwitchEpsilon->Text);
    Editor2D->Grid.Attr.Colors.MIN = ProgramProperty->cbGridMIN->Selected;
    Editor2D->Grid.Attr.Colors.MAX = ProgramProperty->cbGridMAX->Selected;
    Editor2D->Grid.Attr.Colors.OSI = ProgramProperty->cbGridOSI->Selected;
    Editor2D->Attributes.Colors.Additional = ProgramProperty->cbAdditional->Selected;
    Editor2D->Attributes.Colors.MyFigures = ProgramProperty->cbMyFigures->Selected;
    Editor2D->Attributes.Colors.Selected = ProgramProperty->cbSelected->Selected;
    Editor2D->Attributes.Colors.Fixid = ProgramProperty->cbFixid->Selected;
    Editor2D->Attributes.Colors.BackGround = ProgramProperty->cbBackGround->Selected;
    Editor2D->MyView->View->BackgroundColor = ProgramProperty->cbBackGround->Selected;
    Editor2D->MyView->Color = ProgramProperty->cbBackGround->Selected;
    Editor2D->MyCursor.Color = ProgramProperty->cbCursor->Selected;
    ProgramProperty->Close();

    if (CHECK_FILE_SAVE("Attributes\\Attr.ini"))
    {
        TMemoryStream* MS = new TMemoryStream();
        Editor2D->Attributes.WriteData(MS);
        Editor2D->Grid.WriteData(MS);
        Editor2D->MyCursor.WriteData(MS);
        MS->SaveToFile("Attributes\\Attr.ini");
        delete MS;
    }
 //   for (int i = 0; i < Editor2D->CustomFigures.Count; i++)
 //       Editor2D->CustomFigures[i].CreateView();
    Editor2D->Grid.Attr.ReBuild = true;
    Editor2D->MyView->View->InvalidateGL();
}
//---------------------------------------------------------------------------

void __fastcall TProgramProperty::bCancelClick(TObject *Sender)
{
    ProgramProperty->Close();
}
//---------------------------------------------------------------------------

void __fastcall TProgramProperty::FormShow(TObject *Sender)
{
    ProgramProperty->cbSnapOn->Checked = Editor2D->Attributes.Snap;
    ProgramProperty->cbAdditionalSnapOn->Checked = Editor2D->Attributes.AdditionalFiguresSnap;
    ProgramProperty->cbMyFigureSnapOn->Checked = Editor2D->Attributes.SnapMyFigures;
    ProgramProperty->eSnapValue->Text = IntToStr(Editor2D->Attributes.SnapValuePix);
    ProgramProperty->eSnapStep->Text = IntToStr(Editor2D->Grid.Attr.SnapStep);
    ProgramProperty->cbGridOn->Checked = Editor2D->Grid.Attr.Visible;
    ProgramProperty->eStep->Text = FloatToStr(Editor2D->Grid.Attr.Step);
    ProgramProperty->eMultiplier->Text = IntToStr(Editor2D->Grid.Attr.Multiplier);
    ProgramProperty->eZoomLimit->Text = IntToStr(Editor2D->Grid.Attr.ZoomLimit);
    ProgramProperty->eSwitchEpsilon->Text = IntToStr(Editor2D->Grid.Attr.SwitchEpsilon);
    ProgramProperty->cbGridMIN->Selected = Editor2D->Grid.Attr.Colors.MIN;
    ProgramProperty->cbGridMAX->Selected = Editor2D->Grid.Attr.Colors.MAX;
    ProgramProperty->cbGridOSI->Selected = Editor2D->Grid.Attr.Colors.OSI;
    ProgramProperty->cbAdditional->Selected = Editor2D->Attributes.Colors.Additional;
    ProgramProperty->cbMyFigures->Selected = Editor2D->Attributes.Colors.MyFigures;
    ProgramProperty->cbSelected->Selected = Editor2D->Attributes.Colors.Selected;
    ProgramProperty->cbFixid->Selected = Editor2D->Attributes.Colors.Fixid;
    ProgramProperty->cbBackGround->Selected = Editor2D->Attributes.Colors.BackGround;
    ProgramProperty->cbCursor->Selected = Editor2D->MyCursor.Color;
}
//---------------------------------------------------------------------------



