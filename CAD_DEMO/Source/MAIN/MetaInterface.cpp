// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MetaInterface.h"


//---------------------------------------------------------------------------
TMyObject* TMetaCommonIF::CreateFunction()
{
    return new TMetaCommonIF();
}

TMetaCommonIF::TMetaCommonIF()
{
    RegisterNewClass< TMetaNode, TMetaCommonIF >(this,false,&CreateFunction);
//    ImageIndex = iiNomenclature;
    ChildType = cNone;
}

TMetaCommonIF::TMetaCommonIF(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TMetaCommonIF >(this,false,&CreateFunction);
//    ImageIndex = iiNomenclature;
    ChildType = cNone;
    Parent = _Parent;
    AnsiString Name = _Name;
}

