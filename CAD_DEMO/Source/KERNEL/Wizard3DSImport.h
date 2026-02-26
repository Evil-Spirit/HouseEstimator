// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef Wizard3DSImportH
#define Wizard3DSImportH
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
#include <vector>

#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisView.hpp"
#include "VisShape.hpp"
#include "VisCustomObj.hpp"
#include "VisPrimitiveObj.hpp"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "MYIMPORTV.h"
#include "MDITVV.h"
#include "MySupportV.h"
//---------------------------------------------------------------------------
class  TfrmWizard3DSImport : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pcSteps;
	TTabSheet *tsSelectObjects;
	TTabSheet *tsSelectMaterial;
	TTabSheet *tsSelectTextures;
	TLabel *Head1;
	TLabel *Label1;
	TListView *lvObjectsList;
	TListView *lvMaterials;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnReplace;
	TButton *btnRestore;
	TButton *btnFind;
	TEdit *EPS;
	TLabel *Label4;
	TPanel *Panel1;
	TPanel *Renderer;
	TPanel *Panel2;
	TButton *btnNext;
	TButton *btnPrev;
	void  pcStepsChange(TObject *Sender);
	void  FormCreate(TObject *Sender);
	void  FormDestroy(TObject *Sender);
	void  lvObjectsListChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
	void  btnNextClick(TObject *Sender);
	void  btnPrevClick(TObject *Sender);
	void  btnRestoreClick(TObject *Sender);
	void  btnFindClick(TObject *Sender);
	void  btnReplaceClick(TObject *Sender);
	void  lvMaterialsChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
private:	// User declarations
	void FinishImport();
	float MaterialMatch(TVisMaterial *mat1, TVisMaterial *mat2, float eps);
	AnsiString WorkDirectory;
	std::vector<bool> ObjectsSelected;
	std::vector<TVisPrimitiveObj *> Objects;
	std::vector<TVisMaterial *> Materials;
	std::vector<TMetaMaterial *> Replacements;
	std::vector<AnsiString> Textures;
	TVisPrimitiveObj *ResultObject;
	std::vector<TMetaMaterial *> ResultMaterials;
	TVisMaterial *SelectedItem;
	void PrepareRenderer();
	TVisNode* VisNode;
    TMDITV *TV;
	TMainTree *MT;
	TCameraEngine *CameraEngine;
	void Restructure();
	void  SyncObjectsList();
	void  SyncObjects();
	void  SyncMaterialsList();
	void  SyncMaterials();
public:		// User declarations
	 TfrmWizard3DSImport(TComponent* Owner);
	int  Import(AnsiString fileName);
	static TVisPrimitiveObj* ImportFile(AnsiString, std::vector<TMetaMaterial *>&);
};
//---------------------------------------------------------------------------
extern  TfrmWizard3DSImport *frmWizard3DSImport;
//---------------------------------------------------------------------------
#endif
