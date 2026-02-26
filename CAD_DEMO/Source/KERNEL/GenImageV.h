// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef GenImageVH
#define GenImageVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  FormDestroy(TObject *Sender);
    void  sColorMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  btGenClick(TObject *Sender);
    void  ImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
     TGenImage(TComponent* Owner,TMDITV* _TV,Graphics::TBitmap* bmp,Graphics::TBitmap* mask);
    TMDITV* TV;
    Graphics::TBitmap* bmp;
    Graphics::TBitmap* mask;
    TPointer<TBMPSet> *BMPS;
    void  OnLISTChange(TObject *Sender);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TGenImage *GenImage;
//---------------------------------------------------------------------------
#endif
