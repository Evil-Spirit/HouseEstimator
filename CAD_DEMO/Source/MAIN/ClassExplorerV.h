//---------------------------------------------------------------------------

#ifndef ClassExplorerVH
#define ClassExplorerVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TClassExplorer : public TForm
{
__published:	// IDE-managed Components
    TTreeView *TreeView1;
    TButton *bClose;
    void __fastcall bCloseClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TClassExplorer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClassExplorer *ClassExplorer;
//---------------------------------------------------------------------------

void ShowClasses()
{
    TClassExplorer* CE = new TClassExplorer(Application);
    CE->ShowModal();
    delete CE;
}
#endif
