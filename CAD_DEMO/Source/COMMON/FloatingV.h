//---------------------------------------------------------------------------

#ifndef FloatingVH
#define FloatingVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
    void __fastcall FormEndDock(TObject *Sender, TObject *Target, int X,
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
    __property int AL = {read = FAL,write = SetAL};
    __property bool Fixed = {read = FFixed,write = SetFixed};
    __property int FixedSize = {read = FFixedSize,write = SetFixedSize};
    virtual void OnMyResize(){};
    __property int DefaultSize = {read = FDefaultSize,write = SetDefaultSize};
	virtual void __fastcall WndProc(Messages::TMessage &Message);
public:		// User declarations
    __property int DockIndex = {read = FDockIndex,write = SetDockIndex};
    __fastcall TFloatForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
