//---------------------------------------------------------------------------

#ifndef checkH
#define checkH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ActnCtrls.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <StdActns.hpp>
#include <CustomizeDlg.hpp>
#include <Buttons.hpp>
#include <ExtActns.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormClick(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};

class TNewVec : private TIntVec {
private:
    MBTi GetX();
    MBTi GetY();
    MBTi GetZ();
    void SetX(MBTi ax);
    void SetY(MBTi ay);
    void SetZ(MBTi az);
public:
    __property MBTi x = {read = GetX ,write = SetX};
    __property MBTi y = {read = GetY ,write = SetY};
    __property MBTi z = {read = GetZ ,write = SetZ};
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
