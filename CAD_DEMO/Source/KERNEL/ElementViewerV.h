//---------------------------------------------------------------------------

#ifndef ElementViewerVH
#define ElementViewerVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "QuckList.h"

class TElement;
class TMetaElement;
class TLuaModule;
class TMDITV;
class TMainTree;
//---------------------------------------------------------------------------

class COMMONAL_API TElementViewer : public TForm
{
__published:	// IDE-managed Components
		TPanel *pView;
		void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
		TElement *Element;
		TElement *FShowElement;
		TMetaElement *FShowMetaElement;
		void __fastcall SetShowElement(TElement *NewElement);
		void __fastcall SetShowMetaElement(TMetaElement *NewElement);
public:		// User declarations
		__property TElement* ShowElement =
		{
			read = FShowElement,
			write = SetShowElement
		};
		__property TMetaElement* ShowMetaElement=
		{
			read = FShowMetaElement,
			write = SetShowMetaElement
		};
		TMainTree *MT;
		TMDITV *TV;

		__fastcall TElementViewer(TComponent* Owner);
		__fastcall ~TElementViewer();
		void Start();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TElementViewer *ElementViewer;
//---------------------------------------------------------------------------
#endif
