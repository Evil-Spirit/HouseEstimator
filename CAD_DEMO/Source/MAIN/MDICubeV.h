//---------------------------------------------------------------------------

#ifndef MDICubeVH
#define MDICubeVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIElementV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    __fastcall TMDICube(TComponent* Owner,TMetaCube *MN);
};

//---------------------------------------------------------------------------
extern PACKAGE TMDICube *MDICube;
//---------------------------------------------------------------------------
#endif
