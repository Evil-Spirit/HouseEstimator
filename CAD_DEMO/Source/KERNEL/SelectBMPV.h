//---------------------------------------------------------------------------

#ifndef SelectBMPVH
#define SelectBMPVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TSelectBMP : public TForm
{
__published:	// IDE-managed Components
    TListView *LV;
    TComboBoxEx *CBE;
    TButton *btOK;
    TButton *btCancel;
    TButton *btClear;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btOKClick(TObject *Sender);
    void __fastcall btCancelClick(TObject *Sender);
    void __fastcall btClearClick(TObject *Sender);
    void __fastcall CBEChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TBMPSet *BMPS;
    int Index;
    bool Clear;
    __fastcall TSelectBMP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectBMP *SelectBMP;
//---------------------------------------------------------------------------
#endif
