// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMyModeSettingListEditVH
#define MDIMyModeSettingListEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"

//---------------------------------------------------------------------------
class TMyModeSettingList;

class COMMONAL_API TMDIMyModeSettingListEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
  TListView *LV;
  TToolBar *ToolBar1;
  TToolButton *tbtAdd;
  TToolButton *tbtDel;
  TPanel *SSS;
	TCheckBox *IsDefault;
  void  tbtAddClick(TObject *Sender);
  void  tbtDelClick(TObject *Sender);
  void  LVClick(TObject *Sender);
	void  IsDefaultClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  virtual void Refresh();
  virtual void Apply();
  virtual  bool Checked();
  virtual void SETUP();
  virtual void KILL();
  TMyModeSettingList *EditCopy;
   TMDIMyModeSettingListEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyModeSettingListEdit *MDIMyModeSettingListEdit;
//---------------------------------------------------------------------------
#endif
