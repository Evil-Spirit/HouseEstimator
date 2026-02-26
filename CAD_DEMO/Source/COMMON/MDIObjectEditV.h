// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIObjectEditVH
#define MDIObjectEditVH
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
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
     TMDIObjectEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIObjectEdit *MDIObjectEdit;
//ñòàíäàðòíî å îêíî ðåäàêòèðîâàíèÿ ïåðåáèðàåò ìàññèâ ïàíåëåé âûçûâàåò äëÿ íèõ
//ñîîòâåòñòâóþùèå ñòàíäàðòíûå îêíà ðåäàêòèðîâàíèÿ
//îáùàåòñÿ ñ íèìè íà èíòåðôåéñå Apply è Refresh.
//â äî÷åðíèõ êëàññàõ îêíà ñîçäàþòñÿ â OnCreate
//âñå îêíà ïðè ñîçäàíèè ïîëó÷àþò Owner,Parent,Obj,Text,Data
//îêíà áûâàþò ïðîñòûå è ñîñòàâíûå íî âñå èìåþò îäèí èíòåðôåéñ.
//---------------------------------------------------------------------------
#endif
