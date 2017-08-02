//---------------------------------------------------------------------------

#ifndef SimpleEditVH
#define SimpleEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//----------------
//-----------------
//---------------------------------------------------------------------------
class COMMONAL_API TMDISimpleEdit : public TForm
{
__published:	// IDE-managed Components
    TLabel *L;
    void __fastcall lErrorClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
TMyObject *Obj;
virtual void *Value(){return NULL;};
virtual bool CustomChecked(){return(true);}
virtual void Refresh(){};
virtual void SETUP(){};
bool Constructiong;
    __fastcall TMDISimpleEdit(TComponent* Owner);
    __fastcall TMDISimpleEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISimpleEdit *MDISimpleEdit;
//���������� � ���� �������������� ���������� ������ ������� �������� ��� ���
//��������������� ����������� ���� ��������������
//�������� � ���� �� ���������� Apply � Refresh.
//� �������� ������� ���� ��������� � OnCreate
//��� ���� ��� �������� �������� Owner,Parent,Obj,Text,Data
//���� ������ ������� � ��������� �� ��� ����� ���� ���������.
//---------------------------------------------------------------------------
#endif
