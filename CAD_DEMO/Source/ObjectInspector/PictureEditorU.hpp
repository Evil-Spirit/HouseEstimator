// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PictureEditorU.pas' rev: 6.00

#ifndef PictureEditorUHPP
#define PictureEditorUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include "compat/vcl_qt.h"
#include <ExtDlgs.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pictureeditoru
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPictureEditorF;
class PASCALIMPLEMENTATION TPictureEditorF : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* MainPanel;
	Stdctrls::TButton* OK;
	Stdctrls::TButton* Cancel;
	Extctrls::TPanel* WorkPanel;
	Stdctrls::TButton* Load;
	Stdctrls::TButton* Save;
	Stdctrls::TButton* Clear;
	Extctrls::TImage* Image;
	Extdlgs::TOpenPictureDialog* OpenPictureDialog;
	Extdlgs::TSavePictureDialog* SavePictureDialog;
	void  OKClick(System::TObject* Sender);
	void  CancelClick(System::TObject* Sender);
	void  LoadClick(System::TObject* Sender);
	void  SaveClick(System::TObject* Sender);
	void  ClearClick(System::TObject* Sender);
	void  FormCreate(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline  virtual TPictureEditorF(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline  virtual TPictureEditorF(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline  virtual ~TPictureEditorF(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TPictureEditorF(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern  TPictureEditorF* PictureEditorF;

}	/* namespace Pictureeditoru */
using namespace Pictureeditoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PictureEditorU
