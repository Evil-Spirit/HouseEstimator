//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "IntExplorerV.h"
#include "AUIV.h"
#include "World.h"
#include "MDI3DUserV.h"
#include "ElementV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
TAdvancedUserInterface AUI;

TWorldAndViews::TWorldAndViews(TCurrentViewIndexChanged aCurrentViewIndexChanged)
{
    World = NULL;
    CurrentViewIndexChanged = aCurrentViewIndexChanged;
    CurrentViewIndex = -1;
}

void TWorldAndViews::SetCurrentViewIndex(int aCurrentViewIndex)
{
    if (aCurrentViewIndex<0 || aCurrentViewIndex>Views.Count-1)
        FCurrentViewIndex = -1;
    else
        FCurrentViewIndex = aCurrentViewIndex;
    if (CurrentViewIndexChanged)
        CurrentViewIndexChanged(this);
}

TAdvancedUserInterface::TAdvancedUserInterface()
{
    FActiveWorld = NULL;
    FActiveView = NULL;
    //------------------------------------
    UnRegisterInProcess = false;
    CurrentWorldIndex = -1;
    //------------------------------------
}

int TAdvancedUserInterface::FindWorld(TMainTree* aMainTree)
{
    for (int i=0;i<WAVs.Count;i++)
        if (WAVs[i].World == aMainTree)
            return i;
    return -1;
}

int TAdvancedUserInterface::FindWorld(TMDI3D* aMDI3D)
{
    for (int i=0;i<WAVs.Count;i++)
        if (WAVs[i].Views.IndexOf(aMDI3D) != -1)
            return i;
    return -1;
}

void TAdvancedUserInterface::Register(TMainTree* aMainTree)
{
    PreProcessView();
    if ( FindWorld(aMainTree) == -1)
    {
        WAVs.Add( new TWorldAndViews( &CurrentViewIndexChanged ) );
        WAVs.Last()->World = aMainTree;
    }
    AfterProcessView();
}

void TAdvancedUserInterface::ActivateWorld(TMainTree* aMainTree)
{
    if ( aMainTree == ActiveWorld )
        return;
    PreProcessView();
    CurrentWorldIndex = FindWorld(aMainTree);
    AfterProcessView();
}

bool TAdvancedUserInterface::ProcessSaveProject(TMainTree* aWorld)//возвращает истина если ответ не cancel
{
//-------------
    _TRY_
//-------------
    if (!aWorld)
        return false;
    TSaveDialog* SaveDialog1 = new TSaveDialog(Application);
    SaveDialog1->Filter = "SOPOS Project (*.home)|*.home";
    switch(Application->MessageBox( (AnsiString("Do you want to save changes in project: ")+aWorld->Name+AnsiString("?")).c_str(),"Confirmation",MB_YESNOCANCEL))
    {
        case 0:
        case IDCANCEL:
            return false;
        case IDYES:
        {
            SaveDialog1->FileName = aWorld->Name;
            if (!SaveDialog1->Execute())
                return false;
            aWorld->WriteFile(ChangeFileExt(SaveDialog1->FileName,eHOME));
        }
        case IDNO:
        {
            aWorld->AskedToSave = true;
            return true;
        }
        default:
            return false;
    }
//---------------------
    _ENDTRY_ ("<TAdvancedUserInterface::ProcessSaveProject>: Unknown error",return (Application->MessageBox("An error occured during writing to file. Do you want to close anyway?","Confirmation",MB_YESNO) == IDYES););
}

void TAdvancedUserInterface::SimpleUnRegister(TMainTree* aMainTree)
{
    PreProcessView();
    int index = FindWorld(aMainTree);
    delete aMainTree;
    WAVs.Delete(index);
    if (CurrentWorldIndex >= index)
        CurrentWorldIndex = WAVs.Count-1;
    AfterProcessView();
}

bool TAdvancedUserInterface::UnRegister(TMainTree* aMainTree)
{
    int index = FindWorld(aMainTree);

    if ( !aMainTree->AskedToSave && !ProcessSaveProject(aMainTree) )
        return false;

    //---------------------------
    UnRegisterInProcess = true;
    if ( index!=-1 )
        while (WAVs[index].Views.Count)
            WAVs[index].Views[0].Close();
    UnRegisterInProcess = false;
    //---------------------------
    SimpleUnRegister(aMainTree);
    //---------------------------
    return true;
}

void TAdvancedUserInterface::Register(TMainTree* aMainTree,TMDI3D* aMDI3D)
{
    PreProcessView();
    int index = FindWorld(aMainTree);
    if (index==-1)
    {
        ErrorMsg("MainTree is not registered");
        return;
    }
    WAVs[index].Views.Add(aMDI3D);
    WAVs[index].World->RegisterClient(aMDI3D);
    AfterProcessView();
    ActivateView(aMDI3D);
}

void TAdvancedUserInterface::ActivateView(TMDI3D* aMDI3D)
{
    if ( aMDI3D == ActiveView )
        return;
    PreProcessView();
    int index = FindWorld(aMDI3D);
    if (index == -1)
    {
        return;
    }
    ActivateWorld(WAVs[index].World);
    WAVs[index].CurrentViewIndex = WAVs[index].Views.IndexOf(aMDI3D);
    AfterProcessView();
}

void TAdvancedUserInterface::SimpleUnRegister(TMDI3D* aMDI3D)
{
    PreProcessView();

    int index = FindWorld(aMDI3D);
    if ( index ==-1 )
        return;
    
    int ViewIndex = WAVs[index].Views.IndexOf(aMDI3D);

    WAVs[index].World->UnRegisterClient(aMDI3D);
    WAVs[index].Views.Delete(ViewIndex);
    //--------------------------------------------------------------
    if ( WAVs[index].CurrentViewIndex >= ViewIndex)
        WAVs[index].CurrentViewIndex = WAVs[index].Views.Count-1;
    //--------------------------------------------------------------
    AfterProcessView();
}

bool TAdvancedUserInterface::UnRegister(TMDI3D* aMDI3D)
{
    int index = FindWorld(aMDI3D);
    if ( index ==-1 )
        return true;
    //--------------------------------------------
    bool result = true;
    SimpleUnRegister(aMDI3D);
    //--------------------------------------------
    if ( aMDI3D->ClassType() != __classid(TMDI3DUser) )
    {
        if ( WAVs[index].Views.Count == 0 )
            SimpleUnRegister( WAVs[index].World );
    }
    else
    {
        //check to need try unregister maintree
        int CountOfMDI3DUsers = 0;
        for (int i=0;i<WAVs[index].Views.Count;i++)
            CountOfMDI3DUsers += IS(WAVs[index].Views.Items[i],__classid(TMDI3DUser));
        //--------------------------------------------
        if ( CountOfMDI3DUsers == 0 && !UnRegisterInProcess)
        {
            result = UnRegister(WAVs[index].World);
            if (!result)
                Register(WAVs[index].World,aMDI3D);
        }
    }
    return result;
}

void TAdvancedUserInterface::Changed()
{
    IntExplorer->AUIChanged();
}

bool TAdvancedUserInterface::CheckExplorerVisible()
{
    if (AUI.CurrentWorldIndex != -1)
        for (int i=0;i<AUI.WAVs[CurrentWorldIndex].Views.Count;i++)
            if ( IS(AUI.WAVs[CurrentWorldIndex].Views.Items[i],__classid(TMDI3DUser) ) )
                return true;
    return false;
}


void TAdvancedUserInterface::SetCurrentWorldIndex(int aCurrentWorldIndex)
{
    if ( aCurrentWorldIndex <0 || aCurrentWorldIndex> WAVs.Count-1)
        FCurrentWorldIndex = -1;
    else
        FCurrentWorldIndex = aCurrentWorldIndex;
    CurrentViewIndexChanged(NULL);        
}

void TAdvancedUserInterface::CurrentViewIndexChanged(TWorldAndViews* WAV)
{
    if (CurrentWorldIndex == -1)
    {
        FActiveWorld = NULL;
        FActiveView = NULL;
    }
    else if ( WAVs[CurrentWorldIndex].CurrentViewIndex == -1)
    {
        FActiveWorld = WAVs[CurrentWorldIndex].World;
        FActiveView = NULL;
    }
    else
    {
        FActiveWorld = WAVs[CurrentWorldIndex].World;
        FActiveView = WAVs[CurrentWorldIndex].Views.Items[WAVs[CurrentWorldIndex].CurrentViewIndex];
    }
}


void TAdvancedUserInterface::PreProcessView()
{
    if (ActiveView)
        ActiveView->View->AutoClearBuffers = TVisBufferType();
}

void TAdvancedUserInterface::AfterProcessView()
{
    if (ActiveView)
        ActiveView->View->AutoClearBuffers = TVisBufferType()<<btDepth<<btColor;
    Changed();
}

TMetaMyMode* TAdvancedUserInterface::GetMetaMyMode()
{
    TMDI3D* tActiveView = ActiveView;
    if (tActiveView)
        return tActiveView->Mode;
    else
        return NULL;
}

void TAdvancedUserInterface::SetAdvancedTexturing(bool Value)
{
    FPrevAdvancedTexturing = FAdvancedTexturing;
    FAdvancedTexturing = Value;
}

void TAdvancedUserInterface::InvalidateView()
{
    if (ActiveView)
        ActiveView->View->InvalidateGL();    
}

void TAdvancedUserInterface::CustomRender()
{
    if (ActiveView && ActiveWorld)
        ActiveWorld->Render(ActiveView->View);
}

