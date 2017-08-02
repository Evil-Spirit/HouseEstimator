//---------------------------------------------------------------------------

#ifndef OutPutVH
#define OutPutVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include <ComCtrls.hpp>
#include "FloatingV.h"

//---------------------------------------------------------------------------
class COMMONAL_API TOutPut : public TFloatForm
{
__published:	// IDE-managed Components
    TListView *LV;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall LVDblClick(TObject *Sender);
    void __fastcall LVResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TOutPut(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TOutPut *OutPut;
void COMMONAL_API LinkStdOut(const AnsiString& Str,bool opClear,TMyObject *Obj,int Data1,int Data2);
void COMMONAL_API MyStdOut(const AnsiString& Str,bool opClear);

//---------------------------------------------------------------------------
#endif
