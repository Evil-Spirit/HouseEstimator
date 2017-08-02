//---------------------------------------------------------------------------

#ifndef GenImageVH
#define GenImageVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------

class TBMPSet;
class TMDITV;
class COMMONAL_API TGenImage : public TForm
{
__published:	// IDE-managed Components
    TPanel *LIST;
    TLabel *Label1;
    TLabel *Label2;
    TPanel *Panel1;
    TImage *Image;
    TLabel *lWidth;
    TLabel *lHeight;
    TButton *btGen;
    TButton *btCancel;
    TShape *sColor;
    TLabel *Label5;
    TCheckBox *cbAA;
    TCheckBox *cbSmooth;
    TButton *btOK;
    TColorDialog *ColorDialog1;
    TCheckBox *cbAntiAliasingLine;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sColorMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall btGenClick(TObject *Sender);
    void __fastcall ImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TGenImage(TComponent* Owner,TMDITV* _TV,Graphics::TBitmap* bmp,Graphics::TBitmap* mask);
    TMDITV* TV;
    Graphics::TBitmap* bmp;
    Graphics::TBitmap* mask;
    TPointer<TBMPSet> *BMPS;
    void __fastcall OnLISTChange(TObject *Sender);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TGenImage *GenImage;
//---------------------------------------------------------------------------
#endif
