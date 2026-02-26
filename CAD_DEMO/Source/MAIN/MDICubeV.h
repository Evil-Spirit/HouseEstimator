// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDICubeVH
#define MDICubeVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIElementV.h"
//---------------------------------------------------------------------------
class TMetaCube;
class TMDICube : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsExtended;
    TGroupBox *GroupBox1;
    TComboBox *cbHoleNormal;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
     TMDICube(TComponent* Owner,TMetaCube *MN);
};

//---------------------------------------------------------------------------
extern  TMDICube *MDICube;
//---------------------------------------------------------------------------
#endif
