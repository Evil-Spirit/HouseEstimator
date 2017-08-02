//---------------------------------------------------------------------------

#ifndef LuaUniFormVH
#define LuaUniFormVH
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

class TLuaUniForm : public TForm
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
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall btOKClick(TObject *Sender);
    void __fastcall btCancelClick(TObject *Sender);
    void __fastcall btApplyClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
    TPanel* FPanels[5];
public:		// User declarations
    TLuaModule *Module;
    bool CloseOK;

    TMDITV *TV;
    TElement *Element;
    TMainTree *MT;

    __fastcall TLuaUniForm(TComponent* Owner,TLuaModule* _Module);

    TWinControl* GetPanel(int PanelIndex);
    void SetPageCountForPanel(int PanelIndex, int PageCount);
    TWinControl* GetPage(int PanelIndex,int PageIndex);
    void SetCaption(char* Caption);
    void SetPageCaption(int PanelIndex,int PageIndex,char* Caption);

    //метаэлемент для показа если нет то пропустить
    TElement* ShowElement;
    //метаэлемент для показа если нет то пропустить
    TMetaElement* ShowMetaElement;
    void Start();
    bool ShowView();
    void SetDialogParent(TWinControl* Parent,char* DialogName);
    TQuickList Ihs;
    TMDelTList<AnsiString> Names;
    bool AutoAlign;
};
//---------------------------------------------------------------------------
extern PACKAGE TLuaUniForm *LuaUniForm;
//---------------------------------------------------------------------------
#endif
 