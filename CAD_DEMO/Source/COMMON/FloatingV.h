// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef FloatingVH
#define FloatingVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "BaseFormV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMyControlState{
public:
    TMyControlState();
    virtual ~TMyControlState(){};
    void ApplyToControl(TControl* Control);
    int Width;
    int Height;
    int Align;
    int Left;
    int Top;
    TWinControl* Parent;
};

const int AlignBottom = 0;
const int AlignLeft = 1;
const int AlignRight = 2;

class COMMONAL_API TFloatForm : public TBaseForm
{
__published:	// IDE-managed Components
    void  FormEndDock(TObject *Sender, TObject *Target, int X,
          int Y);
private:	// User declarations
    bool    NeedToResize;
    bool    DoRestoreSize;

    int     FAL;
    bool    FFixed;
    int     FFixedSize;
    int     FDefaultSize;

    void    SetAL(int aAL);
    void    SetFixed(bool aFixed);
    void    SetFixedSize(int aFixedSize);
    void    SetDefaultSize(int aDefaultSize);
    int 	FDockIndex;
    void	SetDockIndex(int aDockIndex);
    int 	GetParentDockIndex(TWinControl* Parent);
protected:
    // __property int AL {read=FAL, write=SetAL}; // replaced by:
    int& AL = FAL;
    // __property bool Fixed {read=FFixed, write=SetFixed}; // replaced by:
    bool& Fixed = FFixed;
    // __property int FixedSize {read=FFixedSize, write=SetFixedSize}; // replaced by:
    int& FixedSize = FFixedSize;
    virtual void OnMyResize(){};
    // __property int DefaultSize {read=FDefaultSize, write=SetDefaultSize}; // replaced by:
    int& DefaultSize = FDefaultSize;
    virtual void WndProc(Messages::TMessage& /*Message*/) {}
public:		// User declarations
    // __property int DockIndex {read=FDockIndex, write=SetDockIndex}; // replaced by:
    int& DockIndex = FDockIndex;
     TFloatForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
