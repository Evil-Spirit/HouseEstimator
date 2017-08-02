 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIVectorEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma link "SimpleEditV"
#pragma resource "*.dfm"
TMDIVECEDIT *MDIVECEDIT;
TIntVec IntVec;
//---------------------------------------------------------------------------
__fastcall TMDIVECEDIT::TMDIVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data)
    : TMDISimpleEdit(Owner,_Parent,_Obj,_Text,_Data)
{
}

void TMDIVECEDIT::SETUP()
{
    A[0]=Edit1;
    A[1]=Edit2;
	A[2]=Edit3;
}

//Освежить
void TMDIVECEDIT::Refresh()
{
	IntVec = *((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
	for (int i=0;i<3;i++)
		A[i]->Text = MBTiToStr(RoundTo(IntVec.a[i],UserRound));
}

///значение
void *TMDIVECEDIT::Value()
{
	if (CustomChecked()==false)
		return(NULL);
	for (int i=0;i<3;i++)
		IntVec.a[i] = RoundTo(StrToMBTi(A[i]->Text),UserRound);
	return(&IntVec);
}

//Применить
bool TMDIVECEDIT::CustomChecked()
{
	for (int i=0;i<3;i++)
		if( CHECKTYPE(A[i]->Text,mtMBTi)==false )
			return(false);
	return(true);
}

void __fastcall TMDIVECEDIT::Edit1Change(TObject *Sender)
{
	TIntVec *Vec= ((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
	if(!IS_FLOAT(Edit1->Text) || !IsProportional->Checked)
		return;
	MBTi X = TO_DOUBLE(Edit1->Text);
	MBTi Y, Z;
	if(Vec->x == 0)
		return;
	Y = (Vec->y / Vec->x) * X;
	Z = (Vec->z / Vec->x) * X;
	Edit2->Text = FloatToStr(Y);
	Edit3->Text = FloatToStr(Z);
}
//---------------------------------------------------------------------------



void __fastcall TMDIVECEDIT::Edit2Change(TObject *Sender)
{
	TIntVec *Vec= ((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
	if(!IS_FLOAT(Edit2->Text) || !IsProportional->Checked)
		return;
	MBTi Y = TO_DOUBLE(Edit2->Text);
	MBTi X, Z;
	if(Vec->y == 0)
		return;
	X = (Vec->x / Vec->y) * Y;
	Z = (Vec->z / Vec->y) * Y;
	Edit1->Text = FloatToStr(X);
	Edit3->Text = FloatToStr(Z);
}
//---------------------------------------------------------------------------

void __fastcall TMDIVECEDIT::Edit3Change(TObject *Sender)
{
	TIntVec *Vec= ((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
	if(!IS_FLOAT(Edit3->Text) || !IsProportional->Checked)
		return;
	MBTi Z = TO_DOUBLE(Edit3->Text);
	MBTi Y, X;
	if(Vec->z == 0)
		return;
	Y = (Vec->y / Vec->z) * Z;
	X = (Vec->x / Vec->z) * Z;
	Edit2->Text = FloatToStr(Y);
	Edit1->Text = FloatToStr(X);
}
//---------------------------------------------------------------------------

