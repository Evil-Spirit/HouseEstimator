// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "compat/vcl_qt.h"


#include "ParamEnteringV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TParamEntering *ParamEntering;
//---------------------------------------------------------------------------
 TParamEntering::TParamEntering(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TParamEntering::FormShow(TObject *Sender)
{
    E1->Text = FloatToStrF(Param.x,ffGeneral,4,10);
    E2->Text = FloatToStrF(Param.x,ffGeneral,4,10);
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void  TParamEntering::sbOKClick(TObject *Sender)
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
