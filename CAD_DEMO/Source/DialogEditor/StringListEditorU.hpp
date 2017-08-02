// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StringListEditorU.pas' rev: 6.00

#ifndef StringListEditorUHPP
#define StringListEditorUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <PropDataU.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

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
	void __fastcall OKClick(System::TObject* Sender);
	void __fastcall CancelClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	AnsiString __fastcall SetLuaCode(Stdctrls::TMemo* Editor);
	
public:
	Propdatau::TProp* Prop;
	System::TObject* ThisObject;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TStringListEditorF(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TStringListEditorF(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TStringListEditorF(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStringListEditorF(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TStringListEditorF* StringListEditorF;

}	/* namespace Stringlisteditoru */
using namespace Stringlisteditoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StringListEditorU
