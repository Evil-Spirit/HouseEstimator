//---------------------------------------------------------------------------

#ifndef MDIMultiElementVH
#define MDIMultiElementVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIElementV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMetaMultiElement;
class COMMONAL_API TMDIMultiElement : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsMultiElement;
    TCheckBox *cbIsSizer;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    void SETUP();
    __fastcall TMDIMultiElement(TComponent* Owner,TMetaMultiElement *MN);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMultiElement *MDIMultiElement;
//---------------------------------------------------------------------------
#endif
