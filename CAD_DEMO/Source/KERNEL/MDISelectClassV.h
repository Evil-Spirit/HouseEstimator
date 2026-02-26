// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDISelectClassVH
#define MDISelectClassVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
template <class T> class TMTList;

class COMMONAL_API TMDISelectClass : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TListBox *ListBox1;
    void  Button2Click(TObject *Sender);
    void  Button1Click(TObject *Sender);
    void  FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDISelectClass(TComponent* Owner,TMTList<TClassNode> *L);
int Returned;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISelectClass *MDISelectClass;
//---------------------------------------------------------------------------
#endif
