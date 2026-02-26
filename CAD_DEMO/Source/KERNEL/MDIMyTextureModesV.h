// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMyTextureModesVH
#define MDIMyTextureModesVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMyTextureModes : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TComboBox *cbMode;
    TLabel *lMode;
    TGroupBox *gbMinMax;
    TLabel *Label1;
    TEdit *edZMax;
    TLabel *Label2;
    TEdit *edZMin;
    void  cbModeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDIMyTextureModes(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    void SETUP();
    void Refresh();
    bool Checked();
    void Apply();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyTextureModes *MDIMyTextureModes;
//---------------------------------------------------------------------------
#endif
