//----------------------------------------------------------------------------
#ifndef MyMDIChildVH
#define MyMDIChildVH
//----------------------------------------------------------------------------
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <StdCtrls.hpp>
#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
#include "BaseFormV.h"
//----------------------------------------------------------------------------
class COMMONAL_API TMyMDIChild : public TBaseForm
{
__published:
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
    bool fload;
public:
	virtual __fastcall TMyMDIChild(TComponent *Owner);
	virtual __fastcall TMyMDIChild(TComponent *Owner,const AnsiString& Caption,bool load);
};

extern COMMONAL_API TMyMDIChild* MyMDIChild;
//----------------------------------------------------------------------------
#endif
