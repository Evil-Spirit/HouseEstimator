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
//стандартно е окно редактирования перебирает массив панелей вызывает для них
//соответствующие стандартные окна редактирования
//общается с ними на интерфейсе Apply и Refresh.
//в дочерних классах окна создаются в OnCreate
//все окна при создании получают Owner,Parent,Obj,Text,Data
//окна бывают простые и составные но все имеют один интерфейс.
//---------------------------------------------------------------------------
#endif
