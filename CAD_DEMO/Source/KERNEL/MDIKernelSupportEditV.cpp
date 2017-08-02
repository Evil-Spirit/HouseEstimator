//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIKernelSupportEditV.h"
#include "MySupportV.h"
#include "MDIPointerEditV.h"
#include "Label3DV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIKernelSupportEdit *MDIKernelSupportEdit;
//---------------------------------------------------------------------------
__fastcall TMDIKernelSupportEdit::TMDIKernelSupportEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent, _Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
TKernelSupport* TMDIKernelSupportEdit::MNC()
{
    return (TKernelSupport*)Obj;
}

void TMDIKernelSupportEdit::Refresh()
{
    ((TMDIObjectEdit*)ARootElement->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ASubRootElement->Controls[0])->Refresh();

    ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADefaultLink->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADefaultTarget->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Refresh();
    ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Refresh();
}

void TMDIKernelSupportEdit::Apply()
{
    ((TMDIObjectEdit*)ARootElement->Controls[0])->Apply();
    ((TMDIObjectEdit*)ASubRootElement->Controls[0])->Apply();

    ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Apply();
    ((TMDIObjectEdit*)ADefaultLink->Controls[0])->Apply();

    ((TMDIObjectEdit*)ADefaultTarget->Controls[0])->Apply();
    ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Apply();

    ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Apply();
    ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Apply();
}

bool TMDIKernelSupportEdit::Checked()
{
    return (((TMDIObjectEdit*)ARootElement->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ASubRootElement->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADefaultLink->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADefaultTarget->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Checked() );
}

void TMDIKernelSupportEdit::SETUP()
{
    EditPointer(this,ARootElement,&(MNC()->ARootElement),
        AnsiString(),TMetaElement::StaticType );

    EditPointer(this,ASubRootElement,&(MNC()->ASubRootElement),
        AnsiString(),TMetaElement::StaticType );

    EditPointer(this,AMetaLabel3D,&(MNC()->AMetaLabel3D),
        AnsiString(),TMetaLabel3D::StaticType );

    EditPointer(this,ADefaultLink,&(MNC()->ADefaultLink),
        AnsiString(),TDynamicLink::StaticType );

    EditPointer(this,ADefaultTarget,&(MNC()->ADefaultTarget),
        AnsiString(),TMetaElement::StaticType );

    EditPointer(this,ADEFAULT_SIZE,&(MNC()->ADEFAULT_SIZE),
        AnsiString(),TMetaElement::StaticType );

    EditPointer(this,ADEFAULT_MODE,&(MNC()->ADEFAULT_MODE),
        AnsiString(),TMetaMyMode::StaticType );

    EditPointer(this,A_3D_MODE,&(MNC()->A_3D_MODE),
        AnsiString(),TMetaMyMode::StaticType );

}
