 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMyModeSettingsEditV.h"
#include "MetaClasses.h"
#include "MDIPointerEditV.h"
#include "MDIPointerListEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIMyModeSettingsEdit *MDIMyModeSettingsEdit;
//---------------------------------------------------------------------------
__fastcall TMDIMyModeSettingsEdit::TMDIMyModeSettingsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------

void TMDIMyModeSettingsEdit::Refresh()
{
    TMDIObjectEdit::Refresh();
    ((TMDIObjectEdit *)MAT->Controls[0])->Refresh();
    ((TMDIObjectEdit *)TEX->Controls[0])->Refresh();
    cbOverSize->ItemIndex = ((TMyModeSettings *)Obj)->OverSizeMode;
    cbOverPos->ItemIndex = ((TMyModeSettings *)Obj)->OverPosMode;
    cbFLAT_2D->Checked = ((TMyModeSettings *)Obj)->FLAT_2D;
    cbRender->Checked = ((TMyModeSettings *)Obj)->Render;
}

void TMDIMyModeSettingsEdit::Apply()
{
    TMDIObjectEdit::Apply();
    ((TMDIObjectEdit *)MAT->Controls[0])->Apply();
    ((TMDIObjectEdit *)TEX->Controls[0])->Apply();
    ((TMyModeSettings *)Obj)->OverSizeMode = cbOverSize->ItemIndex;
    ((TMyModeSettings *)Obj)->OverPosMode = cbOverPos->ItemIndex;
    ((TMyModeSettings *)Obj)->FLAT_2D = cbFLAT_2D->Checked;
    ((TMyModeSettings *)Obj)->Render = cbRender->Checked;
}

bool TMDIMyModeSettingsEdit::Checked()
{
  if ( ((TMDIObjectEdit *)MAT->Controls[0])->Checked()==false)
    return(false);
  if ( ((TMDIObjectEdit *)TEX->Controls[0])->Checked()==false)
    return(false);
  return true;
}

TPointer<TMetaNode>* COMMONAL_API CreateMetaMaterialPointer()
{
	return (TPointer<TMetaNode>*)new TPointer<TMetaMaterial>;
}

TPointer<TMetaNode>* COMMONAL_API CreateMetaTexturePointer()
{
	return (TPointer<TMetaNode>*)new TPointer<TMetaTexture>;
}

void TMDIMyModeSettingsEdit::SETUP()
{
  P[0] = OverSize;
  P[1] = OverPos;
  Count=2;

  EditPointerList(this,MAT,&(((TMyModeSettings *)Obj)->MATs),AnsiString(), TMetaMaterial::StaticType,(TMetaNode*)-1,CreateMetaMaterialPointer, true );
  EditPointerList(this,TEX,&(((TMyModeSettings *)Obj)->TEXs),AnsiString(), TMetaTexture::StaticType,(TMetaNode*)-1,CreateMetaTexturePointer, true );
}
