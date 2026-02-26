// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BaseFormVH
#define BaseFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class COMMONAL_API TBaseForm : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	 TBaseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
