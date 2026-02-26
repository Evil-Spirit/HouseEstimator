// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef OutPutVH
#define OutPutVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
#include "FloatingV.h"

//---------------------------------------------------------------------------
class COMMONAL_API TOutPut : public TFloatForm
{
__published:	// IDE-managed Components
    TListView *LV;
    void  FormDestroy(TObject *Sender);
    void  LVDblClick(TObject *Sender);
    void  LVResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TOutPut(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TOutPut *OutPut;
void COMMONAL_API LinkStdOut(const AnsiString& Str,bool opClear,TMyObject *Obj,int Data1,int Data2);
void COMMONAL_API MyStdOut(const AnsiString& Str,bool opClear);

//---------------------------------------------------------------------------
#endif
