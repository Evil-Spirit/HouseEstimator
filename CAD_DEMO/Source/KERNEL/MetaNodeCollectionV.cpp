//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MetaNodeCollectionV.h"
#include "MDISelectClassV.h"
#include "MySupportV.h"
#include "MetaClasses.h"
#include "QuckList.h"
#include "Label3DV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TQuickList TMetaNodeCollection::TypesToEdit;

TMetaNodeCollection *MetaNodeCollection;

TClassNode* TMetaNodeCollection::StaticType = NULL;
//---------------------------------------------------------------------------
TMyObject* TMetaNodeCollection::CreateFunction()
{
    return new TMetaNodeCollection();
}

const AnsiString aSupports = AnsiString("Supports");

TMetaNodeCollection::TMetaNodeCollection()
{
    RegisterNewClass< TMyRegTree, TMetaNodeCollection >(this,false,&(CreateFunction));
    RegisterField(&Supports,&aSupports,mtMyObject);
    Supports.Add( new TKernelSupport() ); //всегда первый
}

TKernelSupport* TMetaNodeCollection::GetKernelSupport()
{
    return (TKernelSupport*)Supports.First();
}

TMetaNode *TMetaNodeCollection::CreateMetaFunction(TMetaNode *Owner,const AnsiString& ClassType,int _ID, const AnsiString& vName, bool IsNew)
{
	TMetaNode* NewMN = CreateMetaObject(ClassType);
	NewMN->IsNew = IsNew;
	NewMN->Name = vName;
    if ( NewMN == NULL )
    {
        Application->MessageBoxA("Error requirement of Metaobject","Error",MB_OK);
        {Application->Terminate(); return NULL;}
    }
    NewMN->Parent = Owner;
    if ( !NewMN->Is(TDynamicLink::StaticType) )
        NewMN->CheckFields();
    return(NewMN);
}

void TMetaNodeCollection::RecurrentAllowedParents(TMTList<TMetaNode> *MNL,TMetaNode *Node,TMetaNode *INNode,TMetaNode* For)
{
    if ( For->DynamicType != TDynamicLink::StaticType )
    {
        if ( Node->DynamicType == TMetaNode::StaticType )
            if ( (Node->In(INNode) || Node ==INNode) && !(Node->In(For)) && (Node != For) )
                MNL->Add(Node);
    }
    else
    {
        if ( Node->Is(TMetaElement::StaticType) )
            if ( (Node->In(INNode) || Node ==INNode) && !(Node->In(For)) && (Node != For) )
                MNL->Add(Node);
    }
    for (int i=0;i<Node->ChildList->Count;i++)
        RecurrentAllowedParents(MNL,(TMetaNode*)Node->ChildList->Items[i],INNode,For);
}


void TMetaNodeCollection::AllowedParents(TMetaNode *For,TMTList<TMetaNode> *MNL)
{
    for (int i=0;i<Head->ChildList->Count;i++)
        if (For->In((TMetaNode*)Head->ChildList->Items[i]))
        {
            RecurrentAllowedParents(MNL,(TMetaNode*)Head->ChildList->Items[i],(TMetaNode*)Head->ChildList->Items[i],For);
            return;
        }
}

void TMetaNodeCollection::OnAddNode(TMyRegObject* Node, TMyRegObject* NewNode)
{
}

TMetaNode *TMetaNodeCollection::AddGroup(TMetaNode *Node,int _ID,const AnsiString& _Name)
{
    if (!Node)
        return NULL;
    if (typeid(*Node) != typeid(TMetaNode))
        return NULL;
    TMetaNode *MN = CreateMetaFunction(Node, TMetaNode::StaticType->Name, _ID , _Name);
    MN->ChildType = Node->ChildType;
    MN->ImageIndex = iiGroup;
    if (Node&&Node->TN)
        RecurrentFillTreeView(MN,(TTreeView*)(Node->TN->TreeView));
    return MN;
}

AnsiString SelectClass(TMTList<TClassNode> *L)
{
    AnsiString ret = AnsiString();
    TMDISelectClass *SC = new TMDISelectClass(NULL,L);
    SC->ShowModal();
    if (SC->Returned!=-1)
        ret = L->Items[SC->Returned]->Name;
    delete SC;
    return(ret);
}

AnsiString TMetaNodeCollection::SelectClassIfNeed(const AnsiString& VirtualClass )
{
    AnsiString NeedCT = VirtualClass;
    TMTList<TClassNode>* L = new TMTList<TClassNode>();
    SelectClassesByName(NeedCT,L);
    if (L->Count==0)
    {
        delete L;
        return(NULL);
    }
    if (L->Count>1)
        NeedCT = SelectClass(L);
    else if (L->Count==1)
        NeedCT = ((TClassNode*)L->Items[0])->Name;
    delete L;
    return NeedCT;
}

TMetaNode *TMetaNodeCollection::AddMetaChild(TMetaNode *Node,AnsiString NeedCT,int _ID ,const AnsiString& _Name,bool load)
{
    if (!Node)
    {
        if (Head)
            delete Head;
        Head = CreateMetaFunction(NULL, NeedCT, _ID , _Name);
        return((TMetaNode *)Head);
    }

    if (NeedCT==cNone)
        NeedCT = Node->ChildType;
        
    if (NeedCT==cNone)
        return(NULL);
    else
    {
        TMetaNode *MN = CreateMetaFunction(Node, NeedCT, _ID , _Name, !load);
        if (Node&&Node->TN)
            RecurrentFillTreeView(MN,(TTreeView*)(Node->TN->TreeView));
        return(MN);
    }        
}

void TMetaNodeCollection::Validate()
{
    /* TODO : Осталось добавить nomenclature и metaui,metaactionlist */
    if (!Head)
    {
        TMetaNode *Head=MetaNodeCollection->AddMetaChild(NULL,cMetaNode,0,AnsiString("Demo"),true);
        Head->ChildType=cMetaNode;
        Head->ImageIndex = iiConfig;
    }
    TQuickList MyClasses;
    MyClasses.Assign(&TypesToEdit);

    for (int i=0;i<Head->ChildList->Count;i++)
    {
        TMetaNode *MN  = (TMetaNode*)(Head->ChildList->Items[i]);
        TClassNode* FindedClass = ClassHead->Find(MN->ChildType);
        if ( FindedClass )
            MyClasses.Remove(FindedClass);
    }
    for (int i=0;i<MyClasses.Count;i++)
    {
        TMetaNode *MN;
        TClassNode* CN = (TClassNode*)MyClasses.Items[i];
        MN = (TMetaNode *)MetaNodeCollection->AddMetaChild((TMetaNode *)Head,cMetaNode,-1,CN->MnChDescription,true);
        MN->ChildType=CN->Name;
        MN->ImageIndex = CN->ImageIndex;
    }
}

void TMetaNodeCollection::Read()
{
    TMemoryStream* MS = new TMemoryStream();
    _TRY_
            MS->LoadFromFile(DataDir+SL+MDNAME+BMD);
            ReadData(MS);
            delete MS;
            if (!TMyObject::RecurrentCheck() )
                throw EMyException("Library check is not completed");
    _ENDTRY_("<TMetaNodeCollection::Read>: Library load error!",delete MS;);
    Validate();
}

bool TMetaNodeCollection::Write()
{
    TMemoryStream* MS = new TMemoryStream();
    _TRY_
        WriteData(MS);
        MS->SaveToFile(DataDir+SL+MDNAME+BMD);
        delete MS;
    _ENDTRY_("<TMetaNodeCollection::Write>: Library save error!", delete MS; return false; );
    return true;
}

void TMetaNodeCollection::Load()
{
    FILE* F = fopen((DataDir+SL+MDNAME+MD).c_str(),"r");
    _TRY_
        LoadData(F);
        if (!TMyObject::RecurrentCheck() )
            throw EMyException("<TMetaNodeCollection::Load>: Library check is not done!");
        fclose(F);
    _ENDTRY_("<TMetaNodeCollection::Load>: Error loading library!",fclose(F));
    Validate();
}

bool TMetaNodeCollection::Save()
{
    FILE *F = fopen((DataDir+SL+MDNAME+TMP).c_str(),"w");
    _TRY_
        SaveData(F);
        fclose(F);
    _ENDTRY_("<TMetaNodeCollection::Save>: Error saving library! New data is in temporary file!", fclose(F); return false; );
    DeleteFile(DataDir+SL+MDNAME+MD);
    if (!RenameFile(DataDir+SL+MDNAME+TMP,DataDir+SL+MDNAME+MD))
    {
        ErrorMsg("<TMetaNodeCollection::Save>: Could not rename library!");
        return false;
    }
    return true;
}

//адресс обработчика onclick берется из MenuItem
void TMetaNodeCollection::FillMenuItem(TMenuItem *MenuItem,Classes::TNotifyEvent Event)
{
    MenuItem->Clear();
    RecurrentFillMenuItem((TMetaNode *)Head,MenuItem,Event);
}

void TMetaNodeCollection::RecurrentFillMenuItem(TMetaNode *Node,TMenuItem *MenuItem,Classes::TNotifyEvent Event)
{
    if ( Node->Is(TMetaElement::StaticType) && Node->DynamicType != TMetaElement::StaticType )
    {
        TMenuItem *MI = new TMenuItem(MenuItem);
        MI->Caption = Node->Name;
        MI->Tag = Node->ID;
        MI->OnClick = Event;
        MI->Visible=true;
        MenuItem->Add(MI);
    }
    for (int i=0;i<Node->ChildList->Count;i++)
        RecurrentFillMenuItem((TMetaNode *) Node->ChildList->Items[i],MenuItem,Event);

}

void TMetaNodeCollection::FillModes(TPopupMenu *PM,Classes::TNotifyEvent Event)
{
  PM->Items->Clear();
  TMTList<TMyRegObject> *L = new TMTList<TMyRegObject>();
  SelectByCT(NULL,TMetaMyMode::StaticType,L,true,true);
  for (int i=0;i<L->Count;i++)
  {
    TMetaMyMode *Node = (TMetaMyMode *)L->Items[i];
    TMenuItem *MI = new TMenuItem(PM);
    MI->Caption = Node->Description;
    MI->ImageIndex = 25+i;
    MI->Name = AnsiString("Mode") + Node->GUID;
    MI->OnClick = Event;
    MI->Visible=true;
    PM->Items->Add(MI);
    if (i==0)
      MI->Click();
  }
  delete L;
}

void TMetaNodeCollection::RefreshToolBar(TMetaNode *MN,TToolBar *TB)
{
/*  if ( MN == NULL)
  {
    RefreshToolBar((TMetaNode *)Head,TB);
    return;
  }
  if ( MTID(typeid(*MN))->is(MTID(typeid( TMetaElement )))&&  MTID(typeid(*MN))!=MTID(typeid( TMetaElement )))
  {
    bool Visible = ((TMetaElement*)MN)->UserVisible;
    if (BIF && BIF->Mode)
    {
      TMetaElement* EL =  (TMetaElement*)MN;
      TMyModeSettings *MMS = EL->MMSL.FindByMode(BIF->Mode);
      Visible = Visible * (!MMS || MMS->Render);
    }
    for (int i=0;i<TB->ControlCount;i++)
      if (TB->Controls[i]->Tag == MN->ID)
      {
        TB->Controls[i]->Visible = Visible;
        break;
      }
  }
    for (int i=0;i<MN->ChildList->Count;i++)
        RefreshToolBar((TMetaNode *) MN->ChildList->Items[i],TB);    */
}

void TMetaNodeCollection::FillToolBar(TMetaNode *MN,TToolBar *TB,TMouseEvent Down,TMouseMoveEvent Move,TMouseEvent Up)
{
    if (MN == NULL)
    {
        while(TB->ComponentCount)
          delete TB->Components[TB->ComponentCount-1];
        TToolButton *SB = new TToolButton(TB);
        SB->Top = 0;//TB->ComponentCount*SB->Height;
        SB->Left = TB->ComponentCount*SB->Width;
        SB->Tag = -1;//IDMouseAction;
        SB->Hint = "";
        SB->OnMouseDown = Down;
        SB->OnMouseMove = Move;
        SB->OnMouseUp = Up;
        SB->ImageIndex = uiMouseIndex;
        SB->Style = tbsCheck;
        SB->Grouped = true;
        SB->AllowAllUp = false;
        SB->Down = true;
        SB->Parent = TB;
        TB->Width = (TB->ButtonCount)*TB->ButtonWidth;
        if (Head)
            FillToolBar((TMetaNode*)Head,TB,Down, Move, Up);
        return;
    }
/*    if ( MTID(typeid(*MN))->is(MTID(typeid( TMetaElement )))&&  MTID(typeid(*MN))!=MTID(typeid( TMetaElement )))
        if ( ((TMetaElement*)MN)->UserVisible )
              {
                TToolButton *SB = new TToolButton(TB);
                SB->Top = 0;//TB->ComponentCount*SB->Height;
                SB->Left = TB->ComponentCount*SB->Width;
                SB->Tag = MN->ID;
                SB->Hint = MN->Description;
                SB->OnMouseDown = Down;
                SB->OnMouseMove = Move;
                SB->OnMouseUp = Up;
                SB->ImageIndex = ((TMetaElement*)MN)->FILEBMP;
                SB->Style = tbsCheck;
                SB->Grouped = true;
                SB->AllowAllUp = false;
                SB->Parent = TB;
                TB->Width = (TB->ButtonCount)*TB->ButtonWidth;
              }
  for (int i=0;i<MN->ChildList->Count;i++)
    FillToolBar((TMetaNode *) MN->ChildList->Items[i],TB, Down, Move, Up);   */
}

void TMetaNodeCollection::PreProcessActions()
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].PreProcessActions();
}

void TMetaNodeCollection::AfterProcessActions()
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].AfterProcessActions();
}

TDynamicLink *TMetaNodeCollection::FreeLink(TMetaElement * Target, TMetaElement * Source)
{
    return KernelSupport->FreeLink(Target,Source);
}

void TMetaNodeCollection::WriteContextMD(TMemoryStream *MS)
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].WriteContextMetaData(MS);
}

void TMetaNodeCollection::ReadContextMD(TMemoryStream *MS)
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].ReadContextMetaData(MS);
}

void TMetaNodeCollection::LoadContextMD(FILE * F)
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].LoadContextMetaData(F);
}

void TMetaNodeCollection::SaveContextMD(FILE * F)
{
    for (int i=0;i<Supports.Count;i++)
        Supports[i].SaveContextMetaData(F);
}

TMetaNode* TMetaNodeCollection::FindMDByName(char* name)
{
    return (TMetaNode*)TMetaNode::StaticType->RecurrentFindByName(name);
//    return (TMetaNode*)MGT->FindByName(0,AnsiString(name));
}

TMetaNode* TMetaNodeCollection::FindMDByGUID(char* GUID)
{
    return (TMetaNode*)TMetaNode::StaticType->RecurrentFindByGUID(GUID);
}


TMetaNode* TMetaNodeCollection::FindParent(const AnsiString& Class)
{
    if (Head)
        for (int i=0;i<Head->ChildList->Count;i++)
            if (  ((TMetaNode*)Head->ChildList->Items[i])->ChildType == Class )
                return (TMetaNode*)Head->ChildList->Items[i];
    return NULL;
}

