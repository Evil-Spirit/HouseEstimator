  //---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDI3DUserV.h"
//#include "Main.h"
//#include "MDITransformationV.h"
#include "MDIColorsV.h"
#include "ElementV.h"
//#include "MDIConfigV.h"
#include "Select.h"
#include "UNDO.h"
#include "World.h"
#include "LogicNode.h"
#include "IntExplorerV.h"
#include "MySupportV.h"
#include "BaseToolV.h"
#include "AUIV.h"
#include "MetaToolV.h"
#include "MYIMPORTV.h"
#include "..\GeomObject\GeomObjV.h"
#include "..\GeomObject\TGPrimitive.h"
#include "..\GeomObject\Misc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDI3DV"

#pragma link "VisAttr"
#pragma link "VisCam"
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisComp"
#pragma link "VisLight"
#pragma link "VisMat"
#pragma link "VisObj"
#pragma link "VisPrimitiveObj"
#pragma link "VisShape"
#pragma link "VisView"
#pragma link "VisLabel"
#pragma link "VisTimer"
#pragma link "SUISkinEngine"
#pragma resource "*.dfm"
TMDI3DUser *MDI3DUser;
//---------------------------------------------------------------------------
__fastcall TMDI3DUser::TMDI3DUser(TComponent* Owner,TMainTree* MT)//,const AnsiString& Name,bool load)
    : TMDI3D(Owner,MT)
{
    Obj = NULL;
    ControlCenter = NULL;
//    View->GetSelection()
/*
	suiSkinEngine1->Active = false;
	suiSkinEngine1->SkinFile = GetSkinFile();
	suiSkinEngine1->Active = true;
*/
}
bool firstrender = true;
//---------------------------------------------------------------------------
void TMDI3DUser::CustomRender(TVisCustomView *aView)
{
	AUI.CustomRender();
	IntExplorer->ControlList.CustomRender(this);

/*    if (BIF->VisView == aView)
    {
        BIF->CustomRender();
        ControlCenter->Render(this);
    }*/
      /* TODO : проверка какое окно рендерить в AUI */
}

void TMDI3DUser::CustomMouseDown(TMouseButton Button,
          TShiftState Shift,int X,int Y)
{
    IntExplorer->ControlList.CustomMouseDown(this,Button,Shift,TIntVec(X,Y,0));
}

void TMDI3DUser::CustomMouseMove(TShiftState Shift,int X,int Y)
{
    if (!Active)
        Activate();
    if ( ::GetFocus()!=Handle )
        ::SetFocus(Handle);
    IntExplorer->ControlList.CustomMouseMove(this,Shift,TIntVec(X,Y,0));
}

void TMDI3DUser::CustomMouseUp(TMouseButton Button,
          TShiftState Shift,int X,int Y)
{
    IntExplorer->ControlList.CustomMouseUp(this,Button,Shift,TIntVec(X,Y,0));
}


void __fastcall TMDI3DUser::FormDestroy(TObject *Sender)
{

/*    if (this && !ElseExists(this) && World)
    {
        World->Clear();
        delete World;
        World = NULL;
        MyMT = NULL;
    }       */
    TMDI3D::FormDestroy(Sender);
}

//---------------------------------------------------------------------------
void TMDI3DUser::CustomKeyDown(WORD &Key,TShiftState Shift)
{
    if (Key =='\x1B')
        IntExplorer->ControlList.CustomExit(this);
    else
        IntExplorer->ControlList.CustomKeyDown(this,Key,Shift);
}

void TMDI3DUser::CustomKeyUp(WORD &Key,TShiftState Shift)
{
    IntExplorer->ControlList.CustomKeyUp(this,Key,Shift);
}



void __fastcall TMDI3DUser::FormCreate(TObject *Sender)
{
    TMDI3D::FormCreate(Sender);
    if (ElseExists(this))
        WindowState = wsNormal;
    Mode = MetaNodeCollection->KernelSupport->DEFAULT_MODE;
}
//---------------------------------------------------------------------------
bool TMDI3DUser::Process_Save_Project()//возвращает истина если ответ не cancel
{
//-------------
    _TRY_
//-------------
    if (!World)
        return false;
    switch(Application->MessageBox( (AnsiString("Save changes in ")+World->Name+AnsiString("?")).c_str(),"Confirmation",MB_YESNOCANCEL))
    {
        case 0:
        case IDCANCEL:
            return false;
        case IDYES:
        {
            SaveDialog1->FileName = World->Name;
            if (!SaveDialog1->Execute())
                return false;
            World->WriteFile(ChangeFileExt(SaveDialog1->FileName,eHOME));
        }
        case IDNO:
        {
            World->AskedToSave = true;            
            return true;
        }
        default:
            return false;
    }
//---------------------
    _ENDTRY_("<TMDI3DUser::Process_Save_Project>: File write error",return (Application->MessageBox("File write error! Close anyway?","Confirmation",MB_YESNO) == IDYES););

//---------------------

}
void __fastcall TMDI3DUser::mEditClick(TObject *Sender)
{
/*    if (Select->Element&&Select->SM == smSyngle)
    {
        TElement *El = Select->Element;
        El->Edit(this,NULL,NULL);
        BIF->FirstInit(this,World);
        El->SetMode();
        BIF->Driver.Init(El,true);
        TElement* FloorElement = BIF->Driver.FloorElement;
        if ( !(BIF->Driver.Stop()) )
        {
          DeleteElement(El,true,FloorElement);
          Select->Element = NULL;
        }
        Select->Terminate();
    } */
}
//---------------------------------------------------------------------------


void __fastcall TMDI3DUser::mEditFragmentsClick(TObject *Sender)
{
/*        TVisRender* VR = (TVisRender*)Obj;
        TElement *El = Select->IdentifyElement(VR);
        Screen->Cursor = crDefault;
        if (El)
            if (El->MyMeta->InWeb && El->Is(TCube::StaticType) )
            {
                TCube* Cube = (TCube*)El;
                Cube->SynhronizeFragments();
                TIntVec LocVec = GettedPoint;
                Cube->LocalFromAbs(LocVec,LocVec);
                for (int i=0;i<Cube->FragSet.Count;i++)
                    if (Cube->FragSet[i].FragmentOfPoint(LocVec,0)!=-1)
                    {
                        Cube->FragSet[i].Edit(Application,NULL,Cube);
                        return;
                    }
            } */
}
//---------------------------------------------------------------------------





void __fastcall TMDI3DUser::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    CanClose = AUI.UnRegister(this);
    if (CanClose)
        TMyMDIChild::FormCloseQuery(Sender,CanClose);
}
//---------------------------------------------------------------------------
void TMDI3DUser::SetMode(TMetaMyMode *nMode)
{
    TMDI3D::SetMode(nMode);
    if ( IntExplorer )
        IntExplorer->ControlList.CustomExit(this);
}



