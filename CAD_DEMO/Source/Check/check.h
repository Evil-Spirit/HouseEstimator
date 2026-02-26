// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef checkH
#define checkH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <CustomizeDlg.hpp>
#include <ExtActns.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    void  FormClick(TObject *Sender);
    void  Button2Click(TObject *Sender);
    void  BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
         TForm1(TComponent* Owner);
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
    // __property MBTi x {read=GetX, write=SetX}; // [manual migration needed]
    // __property MBTi y {read=GetY, write=SetY}; // [manual migration needed]
    // __property MBTi z {read=GetZ, write=SetZ}; // [manual migration needed]
};

//---------------------------------------------------------------------------
extern  TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
