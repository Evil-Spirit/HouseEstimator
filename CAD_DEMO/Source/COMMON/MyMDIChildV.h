// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//----------------------------------------------------------------------------
#ifndef MyMDIChildVH
#define MyMDIChildVH
//----------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include <Windows.hpp>
#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
#include "BaseFormV.h"
//----------------------------------------------------------------------------
class COMMONAL_API TMyMDIChild : public TBaseForm
{
__published:
	void  FormClose(TObject *Sender, TCloseAction &Action);
    void  FormCloseQuery(TObject *Sender, bool &CanClose);
private:
    bool fload;
public:
	virtual  TMyMDIChild(TComponent *Owner);
	virtual  TMyMDIChild(TComponent *Owner,const AnsiString& Caption,bool load);
};

extern COMMONAL_API TMyMDIChild* MyMDIChild;
//----------------------------------------------------------------------------
#endif
