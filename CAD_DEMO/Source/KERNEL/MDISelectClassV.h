//---------------------------------------------------------------------------

#ifndef MDISelectClassVH
#define MDISelectClassVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
template <class T> class TMTList;

class COMMONAL_API TMDISelectClass : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TListBox *ListBox1;
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDISelectClass(TComponent* Owner,TMTList<TClassNode> *L);
int Returned;
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISelectClass *MDISelectClass;
//---------------------------------------------------------------------------
#endif
