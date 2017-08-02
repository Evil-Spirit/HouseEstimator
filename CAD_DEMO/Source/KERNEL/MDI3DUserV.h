//---------------------------------------------------------------------------

#ifndef MDI3DUserVH
#define MDI3DUserVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisPrimitiveObj.hpp"
#include "VisShape.hpp"
#include "VisView.hpp"
#include "VisLabel.hpp"
#include "VisTimer.hpp"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>


#include "MDI3DV.h"
#include "SUISkinEngine.hpp"
//---------------------------------------------------------------------------
class TMyControls;
class COMMONAL_API TMDI3DUser : public TMDI3D
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TSaveDialog *SaveDialog1;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall mEditClick(TObject *Sender);
    void __fastcall mEditFragmentsClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
protected:
  virtual void SetMode(TMetaMyMode *nMode);
public:		// User declarations
    virtual void CustomRender(TVisCustomView *aView);
    virtual void CustomMouseDown(TMouseButton Button,TShiftState Shift,int X,int Y);
    virtual void CustomMouseMove(TShiftState Shift,int X,int Y);
    virtual void CustomMouseUp(TMouseButton Button,TShiftState Shift,int X,int Y);
    virtual void CustomKeyDown(WORD &Key,TShiftState Shift);
    virtual void CustomKeyUp(WORD &Key,TShiftState Shift);
    __fastcall TMDI3DUser(TComponent* Owner,TMainTree* MT);//,const AnsiString& Name,bool load);

    TMyControls* ControlCenter;

    bool WasDownPressed;
    TPoint PressPoint;
    int Epsilon;

    TObject* Obj;
    bool Process_Save_Project();//возвращает истина если ответ не cancel
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDI3DUser *MDI3DUser;
//---------------------------------------------------------------------------
#endif
