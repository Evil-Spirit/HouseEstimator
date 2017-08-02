//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIArchiVarsEditV.h"
#include "OtherMetaClasses.h"
#include "MDIPointerEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIArchiVarsEdit *MDIArchiVarsEdit;
//---------------------------------------------------------------------------
__fastcall TMDIArchiVarsEdit::TMDIArchiVarsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent, _Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
TMainArchitecturalVariables* TMDIArchiVarsEdit::MNC()
{
    return (TMainArchitecturalVariables*)Obj;
}

void TMDIArchiVarsEdit::Refresh()
{
    ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Refresh();
    ((TMDIObjectEdit*)AMetaLabelLink->Controls[0])->Refresh();
    ((TMDIObjectEdit*)AFirstPlatform->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADefaultLand->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Refresh();
    ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Refresh();
    ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Refresh();
    ((TMDIObjectEdit*)APlatform_Land->Controls[0])->Refresh();
}

void TMDIArchiVarsEdit::Apply()
{
    ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Apply();
    ((TMDIObjectEdit*)AMetaLabelLink->Controls[0])->Apply();
    ((TMDIObjectEdit*)AFirstPlatform->Controls[0])->Apply();
    ((TMDIObjectEdit*)ADefaultLand->Controls[0])->Apply();
    ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Apply();
    ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Apply();
    ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Apply();
    ((TMDIObjectEdit*)APlatform_Land->Controls[0])->Apply();
}

bool TMDIArchiVarsEdit::Checked()
{
    return  ((TMDIObjectEdit*)AMetaLabel3D->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)AMetaLabelLink->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)AFirstPlatform->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADefaultLand->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADEFAULT_SIZE->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)ADEFAULT_MODE->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)A_3D_MODE->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)APlatform_Land->Controls[0])->Checked();
}

void TMDIArchiVarsEdit::SETUP()
{
    EditPointer(this,AMetaLabel3D,&(MNC()->AMetaLabel3D),
        AnsiString(),TMetaLabel3D::StaticType );

    EditPointer(this,AMetaLabelLink,&(MNC()->AMetaLabelLink),
        AnsiString(),TDynamicLink::StaticType );

    EditPointer(this,AFirstPlatform,&(MNC()->AFirstPlatform),
        AnsiString(),TMetaPlatform::StaticType );

    EditPointer(this,ADefaultLand,&(MNC()->ADefaultLand),
        AnsiString(),TMetaPlatform::StaticType );

    EditPointer(this,ADEFAULT_SIZE,&(MNC()->ADEFAULT_SIZE),
        AnsiString(),TMetaElement::StaticType );

    EditPointer(this,ADEFAULT_MODE,&(MNC()->ADEFAULT_MODE),
        AnsiString(),TMetaMyMode::StaticType );

    EditPointer(this,A_3D_MODE,&(MNC()->A_3D_MODE),
        AnsiString(),TMetaMyMode::StaticType );

    EditPointer(this,APlatform_Land,&(MNC()->APlatform_Land),
        AnsiString(),TDynamicLink::StaticType);

}
