// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDICustomElementVH
#define MDICustomElementVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
//--------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIElementV.h"
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
    void  SpeedButton1Click(TObject *Sender);
    void  btImportClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDICustomElement(TComponent* Owner,TCustomMetaElement *N);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDICustomElement *MDICustomElement;
//---------------------------------------------------------------------------
#endif
