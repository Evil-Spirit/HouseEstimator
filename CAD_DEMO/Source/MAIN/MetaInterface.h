// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MetaInterfaceH
#define MetaInterfaceH

#include "MetaClasses.h"
//---------------------------------------------------------------------------

class TMetaCommonIF : public TMetaNode{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    TMetaCommonIF();
    TMetaCommonIF(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    ~TMetaCommonIF(){};

};
TClassNode* TMetaCommonIF::StaticType = NULL;



#endif
