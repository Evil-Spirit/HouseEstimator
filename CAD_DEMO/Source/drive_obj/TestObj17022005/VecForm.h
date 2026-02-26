// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef VecFormH
#define VecFormH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MTL.h"
//---------------------------------------------------------------------------

class TForm3 : public TForm
{
	TIntVec FDefault;
	void SetDefault(TIntVec v);
__published:	// IDE-managed Components
	TLabeledEdit *EditX;
	TLabeledEdit *EditY;
	TLabeledEdit *EditZ;
	TBitBtn *Accept;
	void  AcceptClick(TObject *Sender);
	void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	 TForm3(TComponent* Owner);
	// __property TIntVec Default {read=FDefault, write=SetDefault}; // [manual migration needed]
	TIntVec Vector;
};
//---------------------------------------------------------------------------
extern  TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

