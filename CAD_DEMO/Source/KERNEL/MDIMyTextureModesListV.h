//---------------------------------------------------------------------------

#ifndef MDIMyTextureModesListVH
#define MDIMyTextureModesListVH
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
class TMyTextureModesList;
class COMMONAL_API TMDIMyTextureModesList : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TToolButton *tbtAdd;
    TToolButton *tbtDel;
    TPanel *SSS;
    TListView *LV;
    void __fastcall tbtAddClick(TObject *Sender);
    void __fastcall LVClick(TObject *Sender);
    void __fastcall tbtDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIMyTextureModesList(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
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
