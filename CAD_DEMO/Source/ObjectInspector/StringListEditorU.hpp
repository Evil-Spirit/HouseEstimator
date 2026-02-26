// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StringListEditorU.pas' rev: 6.00

#ifndef StringListEditorUHPP
#define StringListEditorUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include "compat/vcl_qt.h"
#include <Variants.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stringlisteditoru
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStringListEditorF;
class PASCALIMPLEMENTATION TStringListEditorF : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OK;
	Stdctrls::TButton* Cancel;
	Extctrls::TPanel* MainPanel;
	Stdctrls::TMemo* MainMemo;
	void  OKClick(System::TObject* Sender);
	void  CancelClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline  virtual TStringListEditorF(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline  virtual TStringListEditorF(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline  virtual ~TStringListEditorF(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TStringListEditorF(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern  TStringListEditorF* StringListEditorF;

}	/* namespace Stringlisteditoru */
using namespace Stringlisteditoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StringListEditorU
