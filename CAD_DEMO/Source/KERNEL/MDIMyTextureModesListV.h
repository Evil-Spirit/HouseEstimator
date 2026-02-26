// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMyTextureModesListVH
#define MDIMyTextureModesListVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class TMyTextureModesList;
class COMMONAL_API TMDIMyTextureModesList : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TToolButton *tbtAdd;
    TToolButton *tbtDel;
    TPanel *SSS;
    TListView *LV;
    void  tbtAddClick(TObject *Sender);
    void  LVClick(TObject *Sender);
    void  tbtDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDIMyTextureModesList(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
  virtual void Refresh();
  virtual void Apply();
  virtual  bool Checked();
  virtual void SETUP();
  virtual void KILL();
    TMyTextureModesList* COPY;
  bool CheckCurrent(bool ApplyIfChecked);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyTextureModesList *MDIMyTextureModesList;
//---------------------------------------------------------------------------
#endif
