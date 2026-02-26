// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include "compat/vcl_qt.h"

#include "check.h"
#include <DesignIntf.hpp>
#include "VCLSCILexerV.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
 TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    TSciLexer* SciLexer = new TSciLexer(this);
    SciLexer->Parent = this;
    SciLexer->Align = alClient;
    SciLexer->Visible = true;
}
//---------------------------------------------------------------------------
class TA : public TMyObject {
protected:
    TMDelTList<TMyObject> WAS;
public:
    const TMyObject& operator[](int index) const
    {
        ShowMessage("Const");
        return WAS[index];
    }
    TMyObject& operator[](int index)
    {
        ShowMessage("Change");
        return WAS[index];
    };
    static TClassNode* StaticType;
    TA()
    {
        WAS.Add(new TMyObject);
//        ShowMessage( IntToStr(TMyObject::StaticType == NULL) );
        RegisterNewClass<TMyObject,TA>(this,false,(TCreateFunction)NULL);
    };
    ~TA(){};
};

class IMy_DesignerHook : public IDesignerHook {
public:
    IMy_DesignerHook(){};
    ~IMy_DesignerHook();
    int i;
};

TClassNode* TA::StaticType = NULL;

void DoSomeThing(const TA& A)
{
    AnsiString Str = A[0].Description;
}

void  TForm1::FormClick(TObject *Sender)
{
/*    ShowMessage( IntToStr(TMTList<AnsiString>::StaticType == NULL) );
    Garbage.AddStr(new AnsiString());
    ShowMessage( IntToStr(TMTList<AnsiString>::StaticType == NULL) );
    TMTList<AnsiString> STR;
    ShowMessage( IntToStr(TMTList<AnsiString>::StaticType == NULL) );*/
    TA A;
    DoSomeThing(A);
    A[0].Description = "ss";
//    void* Address = TMyObject::TMyObject;

/*    FILE* F = fopen("C:\\SASHA\\Config_new\\BIN\\Objects\\ConfigTree.md","r");
    char str[256];
    fgets(str,256,F);
    InfoMsg(str);
    fClassHead.Find("");
    fClassHead.Find("");*/
}
//---------------------------------------------------------------------------

void  TForm1::Button2Click(TObject *Sender)
{
/*    TNewVec NewVec;
    TIntVec& Vec = (TIntVec&)NewVec;
    Vec.x = 3;
    Vec.y = 4;
    Vec.z = 5;
    ShowMessage(Vec.x);
    ShowMessage(Vec.y);
    ShowMessage(Vec.z);*/
//    TClass CL = Button1->ClassInfo();
//    CL->
}
//---------------------------------------------------------------------------
MBTi TNewVec::GetX(){return TIntVec::x;};
MBTi TNewVec::GetY(){return TIntVec::y;};
MBTi TNewVec::GetZ(){return TIntVec::z;};
void TNewVec::SetX(MBTi ax){TIntVec::x = ax;};
void TNewVec::SetY(MBTi ay){TIntVec::y = ay;};
void TNewVec::SetZ(MBTi az){TIntVec::z = az;};


void  TForm1::BitBtn1Click(TObject *Sender)
{
//    CustomizeDlg->Show();        
}
//---------------------------------------------------------------------------

