// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SimpleEditVH
#define SimpleEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//----------------
//-----------------
//---------------------------------------------------------------------------
class COMMONAL_API TMDISimpleEdit : public TForm
{
__published:	// IDE-managed Components
    TLabel *L;
    void  lErrorClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
TMyObject *Obj;
virtual void *Value(){return NULL;};
virtual bool CustomChecked(){return(true);}
virtual void Refresh(){};
virtual void SETUP(){};
bool Constructiong;
     TMDISimpleEdit(TComponent* Owner);
     TMDISimpleEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISimpleEdit *MDISimpleEdit;
//ñòàíäàðòíî å îêíî ðåäàêòèðîâàíèÿ ïåðåáèðàåò ìàññèâ ïàíåëåé âûçûâàåò äëÿ íèõ
//ñîîòâåòñòâóþùèå ñòàíäàðòíûå îêíà ðåäàêòèðîâàíèÿ
//îáùàåòñÿ ñ íèìè íà èíòåðôåéñå Apply è Refresh.
//â äî÷åðíèõ êëàññàõ îêíà ñîçäàþòñÿ â OnCreate
//âñå îêíà ïðè ñîçäàíèè ïîëó÷àþò Owner,Parent,Obj,Text,Data
//îêíà áûâàþò ïðîñòûå è ñîñòàâíûå íî âñå èìåþò îäèí èíòåðôåéñ.
//---------------------------------------------------------------------------
#endif
