// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMyModeSettingsEditVH
#define MDIMyModeSettingsEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMyModeSettingsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
  TPanel *OverSize;
  TPanel *OverPos;
  TComboBox *cbOverSize;
  TComboBox *cbOverPos;
  TCheckBox *cbRender;
  TCheckBox *cbFLAT_2D;
  TLabel *Label1;
  TLabel *Label2;
	TPageControl *pcMatTex;
	TTabSheet *MAT;
	TTabSheet *TEX;
private:	// User declarations
public:		// User declarations
  virtual void Refresh();
  virtual void Apply();
  virtual  bool Checked();
  virtual void SETUP();
   TMDIMyModeSettingsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyModeSettingsEdit *MDIMyModeSettingsEdit;
//---------------------------------------------------------------------------
#endif
