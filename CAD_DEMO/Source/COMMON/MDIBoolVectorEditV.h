// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIBoolVectorEditVH
#define MDIBoolVectorEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
#include "SimpleEditV.h"
//---------------------------------------------------------------------------
class TMDIBOOLVECEDIT : public TMDISimpleEdit
{
__published:	// IDE-managed Components
    TComboBox *ComboBox1;
    TComboBox *ComboBox2;
    TComboBox *ComboBox3;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
private:	// User declarations
public:		// User declarations
     TMDIBOOLVECEDIT(TComponent* Owner);
 TMDIBOOLVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data);
void Refresh();
void *Value();
void SETUP();
TComboBox *A[3];
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIBOOLVECEDIT *MDIBOOLVECEDIT;
//---------------------------------------------------------------------------
#endif
