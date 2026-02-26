// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef LuaUniFormVH
#define LuaUniFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "QuckList.h"

class TElement;
class TMetaElement;
class TLuaModule;
class TMDITV;
class TMainTree;
//---------------------------------------------------------------------------

class COMMONAL_API TLuaUniForm : public TForm
{
__published:	// IDE-managed Components
    TButton *btOK;
    TButton *btCancel;
    TButton *btApply;
    TPanel *pView;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TPanel *Panel5;
    void  FormCreate(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  FormDestroy(TObject *Sender);
    void  btOKClick(TObject *Sender);
    void  btCancelClick(TObject *Sender);
    void  btApplyClick(TObject *Sender);
    void  FormActivate(TObject *Sender);
private:	// User declarations
    TPanel* FPanels[5];
public:		// User declarations
    TLuaModule *Module;
    bool CloseOK;

    TMDITV *TV;
    TElement *Element;
    TMainTree *MT;

     TLuaUniForm(TComponent* Owner,TLuaModule* _Module);
     TLuaUniForm(TComponent* Owner);

    TWinControl* GetPanel(int PanelIndex);
    void SetPageCountForPanel(int PanelIndex, int PageCount);
    TWinControl* GetPage(int PanelIndex,int PageIndex);
    void SetCaption(char* Caption);
    void SetPageCaption(int PanelIndex,int PageIndex,char* Caption);

    //ìåòàýëåìåíò äëÿ ïîêàçà åñëè íåò òî ïðîïóñòèòü
    TElement* ShowElement;
    //ìåòàýëåìåíò äëÿ ïîêàçà åñëè íåò òî ïðîïóñòèòü
    TMetaElement* ShowMetaElement;
    void Start();
    bool ShowView();
    void SetDialogParent(TWinControl* Parent,char* DialogName);
    TQuickList Ihs;
    TMDelTList<AnsiString> Names;
    bool AutoAlign;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TLuaUniForm *LuaUniForm;
//---------------------------------------------------------------------------
#endif
 