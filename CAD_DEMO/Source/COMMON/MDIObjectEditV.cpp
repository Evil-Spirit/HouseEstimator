// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
// NOTE: MDIObjectEdit uses VCL-specific mechanisms (Controls[], ClassType(),
// ClassParent(), __classid(), Parent/Align/BoundsRect properties) that have
// no Qt equivalent.  All method bodies are stubs for compilation.
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "MDIObjectEditV.h"
#include "SimpleEditV.h"

TMDIObjectEdit* MDIObjectEdit = nullptr;

TMDIObjectEdit::TMDIObjectEdit(TComponent* Owner, TControl* /*_Parent*/,
                                TMyObject* _Obj, const AnsiString& /*Text*/,
                                void* Data)
    : TBaseForm(Owner)
{
    DATA = Data;
    Obj  = _Obj;
    LBL  = nullptr;
    Count = 0;
    Constructing = true;
}

void  TMDIObjectEdit::Refresh() {}
void  TMDIObjectEdit::Apply()   {}
bool  TMDIObjectEdit::Checked() { return true; }
void  TMDIObjectEdit::ObjectApply() {}
bool  TMDIObjectEdit::ObjectChecked() { return true; }
void* TMDIObjectEdit::Value() { return nullptr; }
