//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>

#include <vcl.h>
#pragma hdrstop

#include "ParamEnteringV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TParamEntering *ParamEntering;
//---------------------------------------------------------------------------
__fastcall TParamEntering::TParamEntering(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TParamEntering::FormShow(TObject *Sender)
{
    E1->Text = FloatToStrF(Param.x,ffGeneral,4,10);
    E2->Text = FloatToStrF(Param.x,ffGeneral,4,10);
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TParamEntering::sbOKClick(TObject *Sender)
{
    if ( IS_FLOAT(E1->Text) && IS_FLOAT(E2->Text))
    {
        Param.x = StrToMBTi(E1->Text);
        Param.y = StrToMBTi(E2->Text);
        Close();
        ModalResult = mrOk;
    }
}
//---------------------------------------------------------------------------
