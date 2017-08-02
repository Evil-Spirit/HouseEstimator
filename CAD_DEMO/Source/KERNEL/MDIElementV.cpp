//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIElementV.h"
#include "MDITVV.h"
#include "MDIHasSizeV.h"
#include "MDIObjectEditV.h"
//#include "MDILuaEditorV.h"
#include "TriggerBlockV.h"
#include "MDIPointerEditV.h"
#include "MDIMyModeSettingListEditV.h"
#include "World.h"
#include "MDIPointerListEditV.h"
#include "GenImageV.h"

#include "MDITVV.h"
#include "ElementV.h"
#include "MySupportV.h"
#include "AUIV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"

#pragma resource "*.dfm"
TMDIElement *MDIElement;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TMDIElement::TMDIElement(TComponent* Owner,TMetaElement *N)
    : TMDIMetaNode(Owner,N)
{
}

void TMDIElement::ShowChanges()
{
    //---------
    _TRY_
    //---------
        if (Element)
        {
            MT->RemoveElement(Element);
            TV->EL = NULL;
            KillElement(Element);
            Element = NULL;
        }
        AnsiString CN = AnsiString(typeid(*MetaNode).name()).Trim();
        CN = CutMeta(CN);
        Element = CreateElementFunction(MT,MetaNode);
        MT->AddFirst(Element);
        MT->RenderLand = true;
        TV->EL = Element;
    //---------
    _ENDTRY_("<TMDIElement::ShowChanges>: Instance has not been constructed",);
    //---------
}

void TMDIElement::SETUP()
{
    Element = NULL;
/*    for (int i=0;i<cbeUserImage->Images->Count;i++)
    {
        cbeUserImage->ItemsEx->AddItem("",i,i,i,0,0);
    } */
    TMDIMetaNode::SETUP();
    ((TMetaElement *)MetaNode)->Size.Edit(this,tSize,NULL);
    ((TMetaElement *)MetaNode)->EPS.Edit(this,EPS,NULL);
    ((TMetaElement *)MetaNode)->MAS.Edit(this,MAS,NULL);
    ((TMetaElement *)MetaNode)->MMSL.Edit(this,tMMSL,NULL);
    EditPointer(this,MAT,&(((TMetaElement *)MetaNode)->MAT),AnsiString(), TMetaMaterial::StaticType );
    EditPointer(this,TEX,&(((TMetaElement *)MetaNode)->TEX),AnsiString(), TMetaTexture::StaticType );
    ((TMetaElement *)MetaNode)->MTF.Edit(this,MTF,NULL);
    ((TMetaElement *)MetaNode)->CanExistCheck.Edit(this,tCanExistCheck,NULL);
    EditPointerList(this,tsDepend,&((TMetaElement *)MetaNode)->DEPENDLST,AnsiString(),TMetaElement::StaticType,MetaNode,CreateMetaElementPointer);
    Panel2->Width=250;
    MT = new TMainTree();
    MT->AddFloor(-1);
    TV = new TMDITV(this,Panel2,MT);
    TV->View->Coordinates->Visible = true;

/*    TDrawView* DV = new TDrawView(this,PanelDraw);
    DV->aWidth = 5;
    DV->aHeight = 5;
    DV->Show();*/
    ShowChanges();
    TV->Mode = MetaNodeCollection->KernelSupport->_3D_MODE;
}

void TMDIElement::KILL()
{
    TMDIMetaNode::KILL();
    Element = NULL;
}

void TMDIElement::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)tSize->Controls[0])->Refresh();
    ((TMDIObjectEdit *)EPS->Controls[0])->Refresh();
    ((TMDIObjectEdit *)MAS->Controls[0])->Refresh();
    ((TMDIObjectEdit *)MAT->Controls[0])->Refresh();
    ((TMDIObjectEdit *)TEX->Controls[0])->Refresh();
    ((TMDIObjectEdit *)MTF->Controls[0])->Refresh();
    ((TMDIObjectEdit *)tMMSL->Controls[0])->Refresh();
    ((TMDIObjectEdit *)tCanExistCheck->Controls[0])->Refresh();
    ((TMDIObjectEdit *)tsDepend->Controls[0])->Refresh();
    eStartZED->Text = MBTiToStr(((TMetaElement *)MetaNode)->StartZED);
    cbEnabled->Checked =((TMetaElement *)MetaNode)->IsSupport;
//    cbeUserImage->ItemIndex = ((TMetaElement *)MetaNode)->FILEBMP;
    cbDrawView->Checked = ((TMetaElement *)MetaNode)->DrawView;
    cbInWeb->Checked = ((TMetaElement *)MetaNode)->InWeb;
    cbLight->Checked = ((TMetaElement *)MetaNode)->IsLight;
}

void TMDIElement::MNApply()
{
    TMDIMetaNode::MNApply();
//    ((TMetaElement *)MetaNode)->FILEBMP = cbeUserImage->ItemIndex;
    ((TMDIObjectEdit *)tSize->Controls[0])->Apply();
    ((TMDIObjectEdit *)EPS->Controls[0])->Apply();
    ((TMDIObjectEdit *)MAS->Controls[0])->Apply();
    ((TMDIObjectEdit *)MAT->Controls[0])->Apply();
    ((TMDIObjectEdit *)TEX->Controls[0])->Apply();
    ((TMDIObjectEdit *)MTF->Controls[0])->Apply();
    ((TMDIObjectEdit *)tMMSL->Controls[0])->Apply();
    ((TMDIObjectEdit *)tCanExistCheck->Controls[0])->Apply();
    ((TMDIObjectEdit *)tsDepend->Controls[0])->Apply();
    ((TMetaElement *)MetaNode)->IsSupport = cbEnabled->Checked;
    ((TMetaElement *)MetaNode)->StartZED = StrToMBTi(eStartZED->Text);
    ((TMetaElement *)MetaNode)->DrawView = cbDrawView->Checked;
    ((TMetaElement *)MetaNode)->InWeb = cbInWeb->Checked;
    ((TMetaElement *)MetaNode)->IsLight = cbLight->Checked;
}


bool TMDIElement::MNChecked()
{
    if (TMDIMetaNode::MNChecked()==false)
        return(false);
    return  ((TMDIObjectEdit *)tSize->Controls[0])->Checked()   &&
            ((TMDIObjectEdit *)EPS->Controls[0])->Checked()     &&
            ((TMDIObjectEdit *)MAS->Controls[0])->Checked()     &&
            ((TMDIObjectEdit *)MAT->Controls[0])->Checked()     &&
            ((TMDIObjectEdit *)TEX->Controls[0])->Checked()     &&
            ((TMDIObjectEdit *)MTF->Controls[0])->Checked()     &&
            ((TMDIObjectEdit *)tMMSL->Controls[0])->Checked()   &&
            ((TMDIObjectEdit *)tCanExistCheck->Controls[0])->Checked()&&
            ((TMDIObjectEdit *)tsDepend->Controls[0])->Checked()&&
            CHECKTYPE(eStartZED->Text,mtMBTi);
}

//---------------------------------------------------------------------------

void __fastcall TMDIElement::FormActivate(TObject *Sender)
{
    AUI.ActivateView(TV);
}
//---------------------------------------------------------------------------


void __fastcall TMDIElement::FormCreate(TObject *Sender)
{
    Element = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMDIElement::bShowClick(TObject *Sender)
{
    if (MNChecked())
    {
        MNApply();
        ShowChanges();
    }
}
//---------------------------------------------------------------------------


void __fastcall TMDIElement::btGenClick(TObject *Sender)
{
    Graphics::TBitmap* bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    Graphics::TBitmap* mask = new Graphics::TBitmap();
    mask->HandleType = bmDIB;
    GenImage = new TGenImage(NULL,TV,bmp,mask);
    if (GenImage->ShowModal() == mrOk)
    {
        int index = GenImage->BMPS->ADR->IL->Add(bmp,NULL);
        BMPPointer->BMPSet.ADR = GenImage->BMPS->ADR;
        BMPPointer->Index = index;
        BMPPointer->GetBitmap(Image1->Picture->Bitmap);
    }
    delete GenImage;
    delete bmp;
    delete mask;
}
//---------------------------------------------------------------------------

void __fastcall TMDIElement::Button2Click(TObject *Sender)
{
    Graphics::TBitmap* bmp = new Graphics::TBitmap();
    bmp->HandleType = bmDIB;
    Graphics::TBitmap* mask = new Graphics::TBitmap();
    mask->HandleType = bmDIB;
    GenImage = new TGenImage(NULL,TV,bmp,mask);
    if (GenImage->ShowModal() == mrOk)
    {
        int index = GenImage->BMPS->ADR->IL->Add(bmp,NULL);
        SmallBMPPointer->BMPSet.ADR = GenImage->BMPS->ADR;
        SmallBMPPointer->Index = index;
        SmallBMPPointer->GetBitmap(Image2->Picture->Bitmap);
    }
    delete GenImage;
    delete bmp;
    delete mask;
}
//---------------------------------------------------------------------------

