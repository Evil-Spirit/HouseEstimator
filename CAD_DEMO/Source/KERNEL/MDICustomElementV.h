//---------------------------------------------------------------------------

#ifndef MDICustomElementVH
#define MDICustomElementVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
//--------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIElementV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TCustomMetaElement;
class COMMONAL_API TMDICustomElement : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsExtended;
    TOpenDialog *OpenDialog1;
    TGroupBox *GroupBox1;
    TEdit *EdEPS;
    TLabel *Label5;
    TCheckBox *cbLoadNormals;
    TButton *btImport;
    TCheckBox *cbLoadTexels;
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall btImportClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDICustomElement(TComponent* Owner,TCustomMetaElement *N);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDICustomElement *MDICustomElement;
//---------------------------------------------------------------------------
#endif
