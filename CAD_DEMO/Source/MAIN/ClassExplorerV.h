// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ClassExplorerVH
#define ClassExplorerVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TClassExplorer : public TForm
{
__published:	// IDE-managed Components
    TTreeView *TreeView1;
    TButton *bClose;
    void  bCloseClick(TObject *Sender);
    void  FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TClassExplorer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TClassExplorer *ClassExplorer;
//---------------------------------------------------------------------------

void ShowClasses()
{
    TClassExplorer* CE = new TClassExplorer(Application);
    CE->ShowModal();
    delete CE;
}
#endif
