//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
     
#include "MySupportV.h"
#include "MetaClasses.h"
#include "MDIKernelSupportEditV.h"
#include "MetaNodeCollectionV.h"
#include "Label3DV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TMySupport::StaticType = NULL;
TClassNode* TKernelSupport::StaticType = NULL;

TMyObject* TMySupport::CreateFunction()
{
    return new TMySupport();
}

TMySupport::TMySupport()
{
    RegisterNewClass< TMyObject,TMySupport >(this,false,&CreateFunction);
}

TMyObject* TKernelSupport::CreateFunction()
{
    return new TKernelSupport();
}

const AnsiString aADefaultLink = AnsiString("ADefaultLink");
const AnsiString aADefaultTarget = AnsiString("ADefaultTarget");
const AnsiString aADEFAULT_SIZE = AnsiString("ADEFAULT_SIZE");
const AnsiString aADEFAULT_MODE = AnsiString("ADEFAULT_MODE");
const AnsiString aA_3D_MODE = AnsiString("A_3D_MODE");
const AnsiString aAMetaLabel3D = AnsiString("AMetaLabel3D");
const AnsiString aARootElement = AnsiString("ARootElement");
const AnsiString aASubRootElement = AnsiString("ASubRootElement");

TKernelSupport::TKernelSupport()
{
    RegisterNewClass< TMySupport,TKernelSupport >(this,false,&CreateFunction);

    RegisterField(&ARootElement,&aARootElement,mtMyObject);
    RegisterField(&ASubRootElement,&aASubRootElement,mtMyObject);

    RegisterField(&ADefaultLink,&aADefaultLink,mtMyObject);
    RegisterField(&ADefaultTarget,&aADefaultTarget,mtMyObject);
    RegisterField(&ADEFAULT_SIZE,&aADEFAULT_SIZE,mtMyObject);
    RegisterField(&ADEFAULT_MODE,&aADEFAULT_MODE,mtMyObject);
    RegisterField(&A_3D_MODE,&aA_3D_MODE,mtMyObject);
    RegisterField(&AMetaLabel3D,&aAMetaLabel3D,mtMyObject);
}


void TKernelSupport::PreProcessActions()
{
    WEBMETA.Clear();
    MLinks.Clear();
    DLinks.Clear();
    MAE.Clear();
    Modes.Clear();
    
    TMTList<TMyRegObject> List;

    //-----------------------------------------------------
    MetaNodeCollection->SelectByCT(NULL,TMetaMyMode::StaticType,&List,true,true);
    for (int i=0;i<List.Count;i++)
        Modes.Add((TMetaMyMode*)List.Items[i]);
    List.Clear();
    //-----------------------------------------------------
    MetaNodeCollection->SelectByCT(NULL,TMetaElement::StaticType,&List,false,true);
    for (int i=0;i<List.Count;i++)
    {
        if ( ((TMetaElement*)List.Items[i])->InWeb )
            WEBMETA.Add( (TMetaElement*)List.Items[i] );
        if (((TMetaElement*)List.Items[i])->IsAuto)
            MAE.Add((TMetaElement*)List.Items[i]);
    }

    if (!RootElement)
    {
        ErrorMsg(MSG_ERR_10);
        inited = false;
        return;
    }
    if (!SubRootElement)
    {
        ErrorMsg("Node element has not been selected");
        inited = false;
        return;
    }
    if (!MetaLabel3D)
    {
        ErrorMsg("Default label element has not been selected");
        inited = false;
        return;
    }
    if (!DefaultLink)
    {
        ErrorMsg("Default link has not been assigned");
        inited = false;
        return;
    }
    if (!DEFAULT_SIZE)
    {
        ErrorMsg("Default size element has not been assigned");
        inited = false;
        return;
    }
    if (!DEFAULT_MODE)
    {
        ErrorMsg("Default 2D-mode is missing");
        inited = false;
        return;
    }                              
    if (!_3D_MODE)
    {
        ErrorMsg("Default 3D-mode is missing");
        inited = false;
        return;
    }

    if (SubRootElement && MetaLabel3D)
        FreeLink(SubRootElement,MetaLabel3D);
    inited = true;
    
}

void TKernelSupport::AfterProcessActions()
{
    WEBMETA.Clear();
    MLinks.Clear();
    DLinks.Clear();
    MAE.Clear();
    Modes.Clear();
}

void TKernelSupport::WriteContextMetaData(TMemoryStream *MS)
{
    MLinks.WriteData(MS);
    DLinks.WriteData(MS);
}

void TKernelSupport::ReadContextMetaData(TMemoryStream *MS)
{
    DLinks.Clear();
    MLinks.Clear();

    MLinks.ReadData(MS);
    DLinks.ReadData(MS);
    if (!(MLinks.CheckFields())||!(DLinks.CheckFields()))
    {
        throw EMyException("Error loading of context");
    }
}

void TKernelSupport::LoadContextMetaData(FILE * F)
{
    DLinks.Clear();
    MLinks.Clear();

    MLinks.LoadData(F);
    DLinks.LoadData(F);
    if (!(MLinks.CheckFields())||!(DLinks.CheckFields()))
    {
        throw EMyException("Error loading of context");
    }
}

void TKernelSupport::SaveContextMetaData(FILE * F)
{
    MLinks.SaveData(F);
    DLinks.SaveData(F);
}

TDynamicLink *TKernelSupport::FreeLink(TMetaElement * Target, TMetaElement * Source)
{
    TMetaLink *FreeLink = DefaultLink->Link;
    TDynamicLink *DL = (TDynamicLink*)CreateMetaObject(TDynamicLink::StaticType);
    DL->Name = AnsiString("FreeLink");
    DL->ServiceNode = true;
    DL->EL0.ADR = Target;
    DL->EL1.ADR = Source;
    DL->ML.ADR  = FreeLink;
    DL->Needed=true;
    DL->CheckFields();
    DLinks.Add(DL);
    return(DL);
}

TMetaElement* TKernelSupport::GetDEFAULT_SIZE()
{
    return ADEFAULT_SIZE.ADR;
}

TMetaMyMode* TKernelSupport::GetDEFAULT_MODE()
{
    return ADEFAULT_MODE.ADR;
}

TMetaMyMode* TKernelSupport::Get_3D_MODE()
{
    return A_3D_MODE.ADR;
}

TDynamicLink* TKernelSupport::GetDefaultLink()
{
    return ADefaultLink.ADR;
}

TMetaElement* TKernelSupport::GetDefaultTarget()
{
    return ADefaultTarget.ADR;
}

TMetaLabel3D* TKernelSupport::GetMetaLabel3D()
{
    return AMetaLabel3D.ADR;
}

TMetaElement* TKernelSupport::GetRootElement()
{
    return ARootElement.ADR;
}

TMetaElement* TKernelSupport::GetSubRootElement()
{
    return ASubRootElement.ADR;
}

void TKernelSupport::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIKernelSupportEdit(Owner,Parent,this,"Basic variables",Data);
    #endif
}


