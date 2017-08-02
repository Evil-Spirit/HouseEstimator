 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIBMPSetEditV.h"
#include "MetaClasses.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIBMPSetEdit *MDIBMPSetEdit;
//---------------------------------------------------------------------------
__fastcall TMDIBMPSetEdit::TMDIBMPSetEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void FillLV(TListView *LV, TImageList *IL)
{
    LV->Clear();
    for (int i=0;i<IL->Count;i++)
    {
        TListItem *IT = LV->Items->Add();
        IT->ImageIndex = i;
        IT->StateIndex = -1;
    }
}

TMyRegObject* GETREGOBJ(TMyObject * Target)
{
    while ( Target && !Target->Is (TMyRegObject::StaticType) )
        Target = Target->MyObjectParent;
    return (TMyRegObject*)Target;
}

void __fastcall TMDIBMPSetEdit::tbtDelClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    int index = LV->Selected->Index;
    TBMPSet* BMPS = (TBMPSet*)Obj;
    TMTList<TMyObject> OBJL;
    TMTList<TMyObject> REGL;
    MetaNodeCollection->GetLookingTo(NULL,BMPS,OBJL);
    for (int i=0;i<OBJL.Count;i++)
    {
        if ( typeid(*(OBJL.Items[i])) == typeid(TPointer<TBMPSet>) )
            if ( ((TBMPPointer*)OBJL.Items[i]->MyObjectParent)->Index == findices->CycVal(index) )
            {
                TMyRegObject* REG = GETREGOBJ(OBJL.Items[i]);
                if (REG)
                    REGL.Add(REG);
                else
                    REGL.Add(OBJL.Items[i]);
            }
    }
    if (REGL.Count>0)
    {
        AnsiString STR = AnsiString("This image is linked to by:\n");
        for (int i=0;i<REGL.Count;i++)
            STR = STR + REGL[i].Name + AnsiString("\n");
        STR = STR + AnsiString("\nCan not delete.");
        ShowMessage(STR);
        return;
    }

    IL->Delete(index);
    findices->Delete(index);
    FillLV(LV,IL);
    if (index<LV->Items->Count)
        LV->Selected = LV->Items->Item[index];
}
//---------------------------------------------------------------------------
void __fastcall TMDIBMPSetEdit::tbtUpClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    if (LV->Selected->Index==0)
        return;
    int index = LV->Selected->Index;
    IL->Move(index,index-1);
    findices->Move(index,index-1);
    FillLV(LV,IL);
    LV->Selected = LV->Items->Item[index-1];
}
//---------------------------------------------------------------------------
void __fastcall TMDIBMPSetEdit::tbtDownClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    if (LV->Selected->Index==LV->Items->Count-1)
        return;
    int index = LV->Selected->Index;
    IL->Move(index,index+1);
    findices->Move(index,index+1);
    FillLV(LV,IL);
    LV->Selected = LV->Items->Item[index+1];
}
//---------------------------------------------------------------------------
void __fastcall TMDIBMPSetEdit::tbtAddClick(TObject *Sender)
{
    if (!OpenDialog->Execute())
        return;
    //----------------
    _TRY_
    //----------------
        Graphics::TBitmap *GB = new Graphics::TBitmap();
                GB->HandleType = bmDIB;
        GB->PixelFormat = pf32bit;
        GB->Monochrome = false;
        GB->LoadFromFile(OpenDialog->FileName);
        if (GB->Width == IL->Width && GB->Height == IL->Height)
        {
                if (cbTrans->Checked)
                    IL->AddMasked(GB,ColorBox->Brush->Color);
                else
                    IL->AddMasked(GB,clNone);
                findices->Add(new int(-20));
        }
        else
            Application->MessageBox("Invalid Bitmap size","Information");
        delete GB;

    //-------------------
    _ENDTRY_("<TMDIBMPSetEdit::tbtAddClick>: Bitmap is not added",);
    //-------------------
}
//---------------------------------------------------------------------------
void TMDIBMPSetEdit::SETUP()
{
    findices = new TMDelTList<int>();
//    indices = *findices;
}

void TMDIBMPSetEdit::Refresh()
{
    TBMPSet* BMPS = (TBMPSet*)Obj;
    eX->Text = IntToStr(BMPS->X());
    eY->Text = IntToStr(BMPS->Y());
    IL->Assign(BMPS->IL);
    findices->Clear();
    for (int i=0;i<IL->Count;i++)
        findices->Add(new int(i));
    FillLV(LV,IL);
}

void TMDIBMPSetEdit::Apply()
{
    TBMPSet* BMPS = (TBMPSet*)Obj;
    TMTList<TMyObject> OBJL;
    MetaNodeCollection->GetLookingTo(NULL,BMPS,OBJL);
    StdOut(AnsiString(),true);;
    for (int i=0;i<OBJL.Count;i++)
    for (int index=0;index<IL->Count;index++)
    {
        if ( typeid(*(OBJL.Items[i])) == typeid(TPointer<TBMPSet>) )
            if ( ((TBMPPointer*)OBJL.Items[i]->MyObjectParent)->Index == findices->CycVal(index) )
            {
                TMyObject* REG = GETREGOBJ(OBJL.Items[i]);
                if (REG == NULL)
                    REG = OBJL.Items[i];

                if ( findices->CycVal(index) != index )
                {
                    AnsiString STR = AnsiString("Image index was changed for ") + REG->Name + AnsiString(" object");
                    STR = STR + AnsiString(" from <") + IntToStr(((TBMPPointer*)OBJL.Items[i]->MyObjectParent)->Index);
                    STR = STR + AnsiString("> to <") + IntToStr(index) + AnsiString(">");
                    StdOut(STR);
                    ((TBMPPointer*)OBJL.Items[i]->MyObjectParent)->Index = index;
                    REG->RecurrentCheck();
                    OBJL.Delete(i--);
                    break;
                }
            }
    }


    BMPS->SetXY(IL->Width,IL->Height);
    BMPS->IL->Assign(IL);
    findices->Clear();
    for (int i=0;i<IL->Count;i++)
        findices->Add(new int(i));
}

bool TMDIBMPSetEdit::Checked()
{
    return true;
}

void __fastcall TMDIBMPSetEdit::eXChange(TObject *Sender)
{
    if (ISINTEGER(eX->Text) && ISINTEGER(eY->Text)
        && (eX->Text.ToInt()>0) && (eY->Text.ToInt()>0))
    {
        IL->Clear();
        IL->Width = eX->Text.ToInt();
        IL->Height = eY->Text.ToInt();
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIBMPSetEdit::ColorBoxMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ColorDialog->Color = ColorBox->Brush->Color;
    if (ColorDialog->Execute())
    {
        ColorBox->Brush->Color = ColorDialog->Color;
        FillLV(LV,IL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIBMPSetEdit::FormDestroy(TObject *Sender)
{
    delete findices;
}
//---------------------------------------------------------------------------

