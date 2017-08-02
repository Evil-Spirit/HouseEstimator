//---------------------------------------------------------------------------


#include <vcl.h>
#include "MTL.h"
#include "Usefuls.h"
#include <windows.h>
#include <ComObj.hpp>
#include "MyTemplates.h"
#pragma hdrstop

#include "ContainerV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TBaseContainer::StaticType = NULL;

TBaseContainer::TBaseContainer()
{
    RegisterNewClass<TMyObject,TBaseContainer>(this,false,&CreateFunction);
}

TMyObject* TBaseContainer::CreateFunction()
{
    return new TBaseContainer();
}


TStartProcess VarStartProcess = NULL;
TCountProcess VarCountProcess = NULL;

void StartProcess(const AnsiString& ProcessName,int Count)
{
    if (VarStartProcess)
        VarStartProcess(ProcessName,Count);
}

void CountProcess(const AnsiString& ObjectName,int Count)
{
    if (VarCountProcess)
        VarCountProcess(ObjectName,Count);
}

void SetStartProcess(TStartProcess SP)
{
    VarStartProcess = SP;
}

void SetCountProcess(TCountProcess CP)
{
    VarCountProcess = CP;
}