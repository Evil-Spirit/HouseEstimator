// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ElementViewerVH
#define ElementViewerVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
		void  FormActivate(TObject *Sender);
private:	// User declarations
		TElement *Element;
		TElement *FShowElement;
		TMetaElement *FShowMetaElement;
		void  SetShowElement(TElement *NewElement);
		void  SetShowMetaElement(TMetaElement *NewElement);
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

		 TElementViewer(TComponent* Owner);
		 ~TElementViewer();
		void Start();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TElementViewer *ElementViewer;
//---------------------------------------------------------------------------
#endif
