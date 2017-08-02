//---------------------------------------------------------------------------

#ifndef Wizard3DSImportH
#define Wizard3DSImportH
#include <CheckLst.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include <vector>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>

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
class PACKAGE TfrmWizard3DSImport : public TForm
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
	void __fastcall pcStepsChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall lvObjectsListChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
	void __fastcall btnNextClick(TObject *Sender);
	void __fastcall btnPrevClick(TObject *Sender);
	void __fastcall btnRestoreClick(TObject *Sender);
	void __fastcall btnFindClick(TObject *Sender);
	void __fastcall btnReplaceClick(TObject *Sender);
	void __fastcall lvMaterialsChange(TObject *Sender, TListItem *Item,
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
	void __fastcall SyncObjectsList();
	void __fastcall SyncObjects();
	void __fastcall SyncMaterialsList();
	void __fastcall SyncMaterials();
public:		// User declarations
	__fastcall TfrmWizard3DSImport(TComponent* Owner);
	int __fastcall Import(AnsiString fileName);
	static TVisPrimitiveObj* ImportFile(AnsiString, std::vector<TMetaMaterial *>&);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWizard3DSImport *frmWizard3DSImport;
//---------------------------------------------------------------------------
#endif
