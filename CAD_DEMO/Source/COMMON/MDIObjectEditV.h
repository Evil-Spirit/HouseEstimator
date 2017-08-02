//---------------------------------------------------------------------------

#ifndef MDIObjectEditVH
#define MDIObjectEditVH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "BaseFormV.h"

//----------------
//-----------------
const MaxPanelCount=10;
//---------------------------------------------------------------------------
class COMMONAL_API TMDIObjectEdit : public TBaseForm
{
__published:	// IDE-managed Components
    TLabel *LBL;
private:	// User declarations
public:		// User declarations
TMyObject *Obj;
void *Value();
void *DATA;
TPanel *P[MaxPanelCount];
int Count;

virtual void Refresh();
virtual void Apply();
virtual  bool Checked();
virtual void SETUP(){};

void ObjectApply();
bool ObjectChecked();
bool Constructing;
    __fastcall TMDIObjectEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIObjectEdit *MDIObjectEdit;
//���������� � ���� �������������� ���������� ������ ������� �������� ��� ���
//��������������� ����������� ���� ��������������
//�������� � ���� �� ���������� Apply � Refresh.
//� �������� ������� ���� ��������� � OnCreate
//��� ���� ��� �������� �������� Owner,Parent,Obj,Text,Data
//���� ������ ������� � ��������� �� ��� ����� ���� ���������.
//---------------------------------------------------------------------------
#endif
