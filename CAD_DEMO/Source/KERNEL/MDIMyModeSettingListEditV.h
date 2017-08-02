//---------------------------------------------------------------------------

#ifndef MDIMyModeSettingListEditVH
#define MDIMyModeSettingListEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>

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
  void __fastcall tbtAddClick(TObject *Sender);
  void __fastcall tbtDelClick(TObject *Sender);
  void __fastcall LVClick(TObject *Sender);
	void __fastcall IsDefaultClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  virtual void Refresh();
  virtual void Apply();
  virtual  bool Checked();
  virtual void SETUP();
  virtual void KILL();
  TMyModeSettingList *EditCopy;
  __fastcall TMDIMyModeSettingListEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyModeSettingListEdit *MDIMyModeSettingListEdit;
//---------------------------------------------------------------------------
#endif
