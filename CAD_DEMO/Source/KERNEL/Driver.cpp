 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "Driver.h"
#include "MyGL.h"
#include "MetaClasses.h"
#include "ElementV.h"
#include "LogicNode.h"
//#include "GraphEngineV.h"
#include "World.h"
#include "AUIV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TDriver Driver;
TDriverQueue* FDriverQueue = NULL;

TDriverQueue& GetDriverQueue()
{
    if (!FDriverQueue)
        FDriverQueue = new TDriverQueue();
    return *FDriverQueue;
}

TObjectAttributePreSet::TObjectAttributePreSet(char* Name,char* Value)
{
    SetAttributeName(Name);
    SetAttributeValue(Value);
}

TObjectAttributePreSet::TObjectAttributePreSet()
{
    AttributeName = "";
    AttributeValue = "";
//    throw EMyException("Can not use default constructor for class <TObjectAttributePreSet>");
}

void TObjectAttributePreSet::SetAttributeName(char* Name)
{
    AttributeName = AnsiString(Name);
}

void TObjectAttributePreSet::SetAttributeValue(char* Value)
{
    AttributeValue = AnsiString(Value);
}

TIntVec Service;

bool TLINKING::ExistsWallLink()
{
    for (int i=0;i<Need.Count;i++)
        if (Need[i].DL->Link->MetaLinkType == mltWallWall)
            return true;
    for (int i=0;i<Opt.Count;i++)
        if (Opt[i].DL->Link->MetaLinkType  == mltWallWall)
            return true;
    for (int i=0;i<Un_Opt.Count;i++)
        if (Un_Opt[i].DL->Link->MetaLinkType  == mltWallWall)
            return true;
    return false;
}

bool TLINKING::KeepCool(int type,bool Needed)
{
    //check called  - OK
    //itsok called  - OK
    if (Needed)
    {
        return(GetTranslate(cNeed)<=LINKINGEPS);
    }

    for (int i=0;i<OIS.Count;i++)
        if (type == ckPos)
        {
            if(ABSINTVEC( GetTranslate(OIS[i].x) )<=LINKINGEPS)
                return(true);
        }
        else
        {
            if(ABSINTVEC( GetScale(OIS[i].x) )<=LINKINGEPS)
                return(true);
        }
    return(false);
}

void TLINKING::Cut(int type)
{
    //KeepCool - OK
    if (type == ckPos)
        while(!(GetTranslate(OIS[0].x)<=LINKINGEPS) )
            OIS.Delete(0);
    else
        while(!(GetScale(OIS[0].x)<=LINKINGEPS) )
            OIS.Delete(0);
}

TLINKING::TLINKING()
{
    Source = NULL;
    Target = NULL;
    NeedInd = -1;
}

TLINKING::TLINKING(TElement *_Source,TElement *_Target)
{
    if (_Source==NULL||_Target==NULL)
        delete this;
    Source = _Source;
    Target = _Target;
    NeedInd = -1;
    TLINKPATTERN *SNGL;
    TDynamicLink* WALL_DL = NULL;
    for (int i=0;i<Source->MyMeta->ChildList->Count;i++)
    {
        TDynamicLink *DynLink = ((TDynamicLink *)(Source->MyMeta->ChildList->Items[i]));
        if (DynLink->Exists(Source->MyMeta,1)&&DynLink->Exists(Target->MyMeta,0))
        {
                if (DynLink->Link->MetaLinkType == mltWallWall)
                {
                    if (Driver.FloorElement)
                        //это должна быть проверка на то что элементы с одного этажа
                        if ((!Source->Parent && Target->In(Driver.FloorElement)) ||
                        (!Target->Parent && Source->In(Driver.FloorElement)) )
                            WALL_DL = DynLink;
                    continue;
                }
            DynLink->Link->UpdateMetaLinkTargetWithNewSource(Target);
            SNGL = new TLINKPATTERN();
            SNGL->DL = DynLink;
            SNGL->RealLinkType = (TRealLinkTypes)DynLink->Link->MetaLinkType;
            if (DynLink->Needed)
                Need.Add(SNGL);
            else
                Opt.Add(SNGL);
        }
    }
    for (int i=0;i<Target->MyMeta->ChildList->Count;i++)
    {
        TDynamicLink *DynLink = ((TDynamicLink *)(Target->MyMeta->ChildList->Items[i]));
        if (DynLink->Exists(Source->MyMeta,0)&&DynLink->Exists(Target->MyMeta,1))
        {
            DynLink->Link->UpdateMetaLinkTargetWithNewSource(Target);
            if (!DynLink->Needed)
            {
                if (DynLink->Link->MetaLinkType == mltWallWall)
                {
                    if (Driver.FloorElement)
                        //это должна быть проверка на то что элементы с одного этажа
                        if ((!Source->Parent && Target->In(Driver.FloorElement)) ||
                        (!Target->Parent && Source->In(Driver.FloorElement)) )
                            WALL_DL = DynLink;
                    continue;
                }
                SNGL = new TLINKPATTERN();
                SNGL->DL = DynLink;
                SNGL->RealLinkType = (TRealLinkTypes)DynLink->Link->MetaLinkType;
                Un_Opt.Add(SNGL);
            }
        }
    }
    if (WALL_DL)
    {
        WALL_DL->Link->UpdateMetaLinkTargetWithNewSource(Target);
        int WalLinkCount = 4;
        //  type            size            un_opt_pos
        //  lineline        no              no
        //  areapoint       yes             yes
        //  pointpoint      yes             no
        TMTList<TLINKING> LNKLST;
        if ( !(Need.Count+Opt.Count+Un_Opt.Count) )
            LNKLST.Add(this);
        while (WalLinkCount>LNKLST.Count)
        {
            Driver.ALL->Add(new TLINKING());
            LNKLST.Add(Driver.ALL->Last());
        }
        //lineline pos
        LNKLST[0].Target = _Target;
        LNKLST[0].Source = _Source;
        LNKLST[0].Opt.Add(new TLINKPATTERN());
        LNKLST[0].Opt[0].DL = WALL_DL;
        LNKLST[0].Opt[0].RealLinkType = rltLineLine;
        //linepoint opt
        LNKLST[1].Target = _Target;
        LNKLST[1].Source = _Source;
        LNKLST[1].Opt.Add(new TLINKPATTERN());
        LNKLST[1].Opt[0].DL = WALL_DL;
        LNKLST[1].Opt[0].RealLinkType = rltLinePoint;
        //linepoint un_opt
        LNKLST[2].Target = _Target;
        LNKLST[2].Source = _Source;
        LNKLST[2].Un_Opt.Add(new TLINKPATTERN());
        LNKLST[2].Un_Opt[0].DL = WALL_DL;
        LNKLST[2].Un_Opt[0].RealLinkType = rltLinePoint;
        //pointpoint
        LNKLST[3].Target = _Target;
        LNKLST[3].Source = _Source;
        LNKLST[3].Opt.Add(new TLINKPATTERN());
        LNKLST[3].Opt[0].DL = WALL_DL;
        LNKLST[3].Opt[0].RealLinkType = rltPointPoint;
    }
}

TLINKING::~TLINKING()
{
}

bool TLINKING::ITSOK(bool Needed)
{
    if (Needed)
        return(NeedInd!=-1);
    else
        return(OIS.Count>0);
};

TElement *TLINKING::_Target(int ind)
{
    if (ind == cNeed)
        return(Target);
    if (ind == cBest)
        return(_Target(OIS[0].x));
    if (ind<Opt.Count)
        return(Target);
    return(Source);
};

TElement *TLINKING::_Source(int ind)
{
    if (ind == cNeed)
        return(Source);
    if (ind == cBest)
        return(_Source(OIS[0].x));
    if (ind<Opt.Count)
        return(Source);
    return(Target);
};

TDynamicLink *TLINKING::GetDL(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].DL);
    if (ind==cBest)
        return(GetDL(OIS[0].x));
    if (ind<Opt.Count)
        return(Opt[ind].DL);
    return(Un_Opt[ind-Opt.Count].DL);
};

TLINKPATTERN& TLINKING::GetSL(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd]);
    if (ind==cBest)
        return(GetSL(OIS[0].x));
    if (ind<Opt.Count)
        return(Opt[ind]);
    return(Un_Opt[ind-Opt.Count]);
}


TIntVec& TLINKING::GetTranslate(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].TS_Common);
    if (ind==cBest)
        return(GetTranslate(OIS[0].x));
    if (ind<Opt.Count)
        return(Opt[ind].TS_Common);
    return(Un_Opt[ind-Opt.Count].TS_Common);
};

TIntVec& TLINKING::GetCrossPoint(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].CrossPoint);
    if (ind==cBest)
        return(GetCrossPoint(OIS[0].x));
    if (ind<Opt.Count)
        return(Opt[ind].CrossPoint);
    return(Un_Opt[ind-Opt.Count].CrossPoint);
};

TIntVec& TLINKING::GetRotate(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].R_Common);
    if (ind==cBest)
        return(GetRotate(OIS[0].x));
    if (ind<Opt.Count)
        return(Opt[ind].R_Common);
    return(Un_Opt[ind-Opt.Count].R_Common);
};

TIntVec& TLINKING::GetScale(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].TS_Common);
    if (ind==cBest)
        return(GetScale(OIS[0].x));
    return(Opt[ind].TS_Common);
};

TIntVec& TLINKING::GetScale_Rotate(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].R_Common);
    if (ind==cBest)
        return(GetScale_Rotate(OIS[0].x));
    return(Opt[ind].R_Common);
};

TIntVec& TLINKING::GetDirection(int ind)
{
    if (ind==cNeed)
        return(Need[NeedInd].Direction);
    if (ind==cBest)
        return(GetDirection(OIS[0].x));
    return(Opt[ind].Direction);
};

TPoint* PP1;
TPoint* PP2;
bool __fastcall TLINKING::Scale__MyComp(void* item1,void* item2)
{
    PP1 = (TPoint*)item1;
    PP2 = (TPoint*)item2;
    if ( PP1->y<=PP2->y)
        return false;
    if (PP1->y == PP2->y)
        if (Measure(GetScale(PP1->x))<= Measure(GetScale(PP2->x)))
            return false;
    return true;
}

bool __fastcall TLINKING::Translate__MyComp(void* item1,void* item2)
{
    PP1 = (TPoint*)item1;
    PP2 = (TPoint*)item2;
    if ( PP1->y<=PP2->y)
        return false;
    if (PP1->y == PP2->y)     
        if (Measure(GetTranslate(PP1->x))<= Measure(GetTranslate(PP2->x)))
            return false;
    return true;
}

bool RunLink(TElement* Target,TElement* Source,TLINKPATTERN& SL,int TransMode)
{
    bool CanContinue = true;
    if (SL.DL->Link->TransMode != tmPositionSize)
        CanContinue = (TransMode==ocmSize)&&(SL.DL->Link->TransMode == tmSize) ||
            (TransMode==ocmPosition)&&(SL.DL->Link->TransMode == tmPosition);
    if (CanContinue && SL.DL->Link->RunOnStop && !Driver.Stoping)
        CanContinue = false;
    if (!CanContinue)
        return false;
    SL.SyngleLinks.Clear();
    if (SL.DL->Link->HasLinkModule)
        return SL.DL->Link->RunLinkModule(Target,Source,SL,(TransMode == ocmSize));
    else
        switch (TransMode)
        {
            case ocmSize:
                return SizeLink(Target,Source,SL,false);
            case ocmPosition:
                return PosLink(Target,Source,SL,false);
            default:
                return false;
        }

}


void TLINKING::Check()
{
    NeedInd=-1;
    OIS.Clear();
    MBTi MinStep=Measure(MAXCATCHEPS);
    for (int i=0;i<Need.Count;i++)
        if ( RunLink(Target,Source,Need[i],ocmPosition) )
        {
            if (MinStep>=Measure(Need[i].TS_Common))
            {
                NeedInd = i;
                MinStep = Measure(Need[i].TS_Common);
            }
        }

    for (int i=0;i<Opt.Count;i++)
        if (RunLink(Target,Source,Opt[i],ocmPosition ))
            OIS.Add(new TPoint(i,Opt[i].DL->Link->Priority));

    for (int i=0;i<Un_Opt.Count;i++)
        if ( RunLink(Source,Target,Un_Opt[i],ocmPosition ))
            OIS.Add(new TPoint(i+Opt.Count,Un_Opt[i].DL->Link->Priority));

    bool changed = true;
    while(changed)
    {
        changed = false;
        for (int i=0;i<OIS.Count-1;i++)
        {
            if (OIS[i].y<=OIS[i+1].y)
                continue;
            if (OIS[i].y==OIS[i+1].y)
                if (Measure(GetTranslate(OIS[i].x))<= Measure(GetTranslate(OIS[i+1].x)))
                    continue;
            OIS.Exchange(i,i+1);
            changed = true;
        }
    }
}

void TLINKING::CheckOptionalSizeLinks()
{
    OIS.Clear();
    for (int i=0;i<Opt.Count;i++)
        if (RunLink(        Target,
                            Source,
                            Opt[i],
                            ocmSize) )
            OIS.Add(new TPoint(i,Opt[i].DL->Link->Priority));

    bool changed = true;
    while(changed)
    {
        changed = false;
        for (int i=0;i<OIS.Count-1;i++)
        {
            if (OIS[i].y<=OIS[i+1].y)
                continue;
            if (OIS[i].y==OIS[i+1].y)
                if (Measure(GetScale(OIS[i].x))<= Measure(GetScale(OIS[i+1].x)))
                    continue;
            OIS.Exchange(i,i+1);
            changed = true;
        }
    }  
}

void TLINKING::MakePosition(int ind)
{
  if (ind ==cNeed)
    Source->UserChangePosition( Need[NeedInd].TS_Common,
                                Need[NeedInd].R_Common);
  else if (ind == cBest)
        MakePosition(OIS[0].x);
  else if (ind<Opt.Count)
    Source->UserChangePosition(   Opt[ind].TS_Common,
                                  Opt[ind].R_Common);
  else
    Source->UserChangePosition(     Un_Opt[ind-Opt.Count].TS_Common*(-1),
                                    Un_Opt[ind-Opt.Count].R_Common*(-1));
}

void TLINKING::UndoPosition(int ind)
{
  if (ind ==cNeed)
    Source->UserChangePosition( Need[NeedInd].TS_Common*(-1),
                                Need[NeedInd].R_Common*(-1));
  else if (ind == cBest)
    UndoPosition(OIS[0].x);
  else if (ind<Opt.Count)
    Source->UserChangePosition( Opt[ind].TS_Common*(-1),
                                Opt[ind].R_Common*(-1));
  else
    Source->UserChangePosition( Un_Opt[ind-Opt.Count].TS_Common,
                                Un_Opt[ind-Opt.Count].R_Common);
}

void TLINKING::MakeSize(bool Try,int ind)
{
    if (ind == cBest)
        MakeSize(Try,OIS[0].x);
    else if (ind<Opt.Count)
    {
        Service = RotateAround( Source->AbsPos,
                                Opt[ind].R_Common,
                                Opt[ind].RotateCenter);
        Source->UserChangePosition(   Service-Source->AbsPos,
                                            Opt[ind].R_Common);
        Source->ChangeSize(   Opt[ind].TS_Common,
                                    Opt[ind].Direction,Try );
    }
    else
    {
      Service = RotateAround( Source->AbsPos,
                              Un_Opt[ind-Opt.Count].R_Common,
                              Un_Opt[ind-Opt.Count].RotateCenter);
      Source->UserChangePosition(   Service-Source->AbsPos,
                                        Un_Opt[ind-Opt.Count].R_Common);
      Source->ChangeSize(   Un_Opt[ind-Opt.Count].TS_Common,
                                Un_Opt[ind-Opt.Count].Direction,Try );
    }
}

void TLINKING::UndoSize(bool Try,int ind)
{
    if (ind == cBest)
        UndoSize(Try,OIS[0].x);
    else if (ind<Opt.Count)
    {
        Source->ChangeSize(   Opt[ind].TS_Common*(-1),
                                    Opt[ind].Direction,
                                    Try );
        Service = RotateAround( Source->AbsPos,
                                Opt[ind].R_Common*(-1),
                                Opt[ind].RotateCenter);
        Source->UserChangePosition(   Service-Source->AbsPos,
                                            Opt[ind].R_Common*(-1));
    }
    else 
    {
      Source->ChangeSize(   Un_Opt[ind-Opt.Count].TS_Common*(-1),
                                Un_Opt[ind-Opt.Count].Direction,Try );
      Service = RotateAround( Source->AbsPos,
                              Un_Opt[ind-Opt.Count].R_Common*(-1),
                              Un_Opt[ind-Opt.Count].RotateCenter);
      Source->UserChangePosition(   Service-Source->AbsPos,
                                        Un_Opt[ind-Opt.Count].R_Common*(-1));
    }
}

TDriver::TDriver()
{
    FPreLinksGenerated = false;
    CORRECT_EPS = TIntVec(0.01,0.01,0.01);
    CORRECT_ANGLEEPS = TIntVec(0.1,0.1,0.1);
    IsNowCorrectMode = false;
    Stoping = false;
    ALL = new TMDelTList<TLINKING>();
    NEED = new TMTList<TLINKING>();
    OPT = new TMTList<TLINKING>();
    FloorElement = NULL;
    Clear();
}

TDriver::~TDriver()
{
    delete ALL;
    delete NEED;
    delete OPT;
}

void TDriver::Clear()
{
    Stoping = false;
    IgnoreAuto = true;
    MainMode = ocmPosition;
    CorrectMode = ocmNone;
    FElement = NULL;
    FloorElement = NULL;
    O_E_L_Count = 0;
    BestTargetLink = -1;
    NEED->Clear();
    OPT->Clear();
    ALL->Clear();
}

void TDriver::Init(TElement *_Element,bool _IgnoreAuto,TElement* UseFloor)
{
    _TRY_
    
        Clear();
        IgnoreAuto = _IgnoreAuto;
        FElement = _Element;
        if (Element->MyMeta->IsAuto && IgnoreAuto)
             return;
        FloorElement = UseFloor;
        if (!FloorElement && World)
        {
            int FloorIndex = World->FloorOf(Element);
            if (FloorIndex!=-1)
                FloorElement = World->Floors[FloorIndex].First.ADR;
            if ( !FloorElement && World->ActiveFloor && World->ActiveFloor->First.ADR)
                FloorElement = World->ActiveFloor->First.ADR;
        }
        if (!FloorElement)
            return;
        //удаление связок
/*        TMTList<TElement> WEBELEMENTS;
        for (int i=0;i<Element->LinksCount;i++)
            if (Element->Links[i]->MyMeta->Link->InWeb)
                for (int j=0;j<2;j++)
                    if (Element->Links[i]->Elements[j]->MyMeta->InWeb && WEBELEMENTS.IndexOf(Element->Links[i]->Elements[j])==-1)
                        WEBELEMENTS.Add(Element->Links[i]->Elements[j]);  */
        Element->DeleteNeededLink();
       /* for (int i=0;i<WEBELEMENTS.Count;i++)
        {
            WEBELEMENTS.Items[i]->AdvancedTextureView = false;
            WEBELEMENTS.Items[i]->CreateView();
        }   */
        //удаление связок
        TMTList<TElement> *List = new TMTList<TElement>();
        Element->MyTree->SelectByElementLinks(Element,List);
        for (int i=0;i<List->Count;i++)
            ALL->Add(new TLINKING(Element, List->Items[i]));
        delete List;
        InitCount = ALL->Count;

    _ENDTRY_("<TDriver::Init>: An Error occured during driver processing.",Stoping = false;return;);
}

TLINKING* ITEM1;
TLINKING* ITEM2;
bool __fastcall TLINKINGCOMPSCALE(void *item1, void *item2)
{
    ITEM1 = (TLINKING*)item1;
    ITEM2 = (TLINKING*)item2;

    if (!ITEM2->ITSOK(false))
        return false;

    if ( ITEM1->ITSOK(false) &&
        (Measure(ITEM1->GetScale(cBest)) <= Measure(ITEM2->GetScale(cBest))))
        return false;
    return true;
}

bool __fastcall TLINKINGCOMPTRANSLATE(void *item1, void *item2)
{
    ITEM1 = (TLINKING*)item1;
    ITEM2 = (TLINKING*)item2;

    if (!ITEM2->ITSOK(false))
        return false;

    if ( ITEM1->ITSOK(false) &&
        (Measure(ITEM1->GetTranslate(cBest)) <= Measure(ITEM2->GetTranslate(cBest))))
        return false;
    return true;
}

int TDriver::CheckBySize(int index)
{
    int index0 = index;
    while(index<OPT->Count)
    {
        for (int i=index;i<OPT->Count;i++)
            OPT->Items[i]->CheckOptionalSizeLinks();
//        OPT->Sort(TLINKINGCOMPSCALE);
        bool changed=true;
        while(changed)
        {
            changed=false;
            for (int i = index; i<OPT->Count-1;i++)
            {
                if (!OPT->Items[i+1]->ITSOK(false))
                    continue;
                if ( OPT->Items[i]->ITSOK(false) &&
                    (Measure(OPT->Items[i]->GetScale(cBest)) <= Measure(OPT->Items[i+1]->GetScale(cBest))))
                        continue;
                OPT->Exchange(i,i+1);
                changed=true;
            }
        }

        if (!OPT->Items[index]->ITSOK(false))
            break;
        OPT->Items[index]->MakeSize(true,cBest);
        bool OK=true;
        NEED->Items[BestTargetLink]->Check();
        OK = OK*(NEED->Items[BestTargetLink]->ITSOK(true));
        if (OK)
            OK = ( NEED->Items[BestTargetLink]->KeepCool(ckPos,true));
        if (OK)
            for (int i=0;i<index0;i++)
            {
                OPT->Items[i]->Check();
                OK = OK*(OPT->Items[i]->ITSOK(false));
                if (OK)
                    OK = OK * ( OPT->Items[i]->KeepCool(ckPos,false) );
                if (!OK)
                    break;
            }
        if (OK)
            for (int i=index0;i<index;i++)
            {
                OPT->Items[i]->CheckOptionalSizeLinks();
                OK = OK*(OPT->Items[i]->ITSOK(false));
                if (OK)
                    OK = OK * ( ABSINTVEC(OPT->Items[i]->GetScale(cBest))<=LINKINGEPS);
                if (!OK)
                    break;
            }
        OPT->Items[index]->UndoSize(true,cBest);
        if (OK)
        {
            OPT->Items[index]->MakeSize(false,cBest);
            index++;
        }
        else
            break;
    }
    return index;
}

int TDriver::CheckByPosition(int index)
{
    int index0 = index;
    while(index<OPT->Count)
    {
        //rechecking
        for (int i=index;i<OPT->Count;i++)
            OPT->Items[i]->Check();
        //----sorting
//        OPT->Sort(TLINKINGCOMPTRANSLATE);
        bool changed=true;
        while(changed)
        {
            changed=false;
            for (int i = index; i<OPT->Count-1;i++)
            {
                if (!OPT->Items[i+1]->ITSOK(false))
                    continue;
                if ( OPT->Items[i]->ITSOK(false) &&
                        (Measure(OPT->Items[i]->GetTranslate(cBest)) <= Measure(OPT->Items[i+1]->GetTranslate(cBest))))
                    continue;
                OPT->Exchange(i,i+1);
                changed=true;
            }
        } 
        if (!OPT->Items[index]->ITSOK(false))
            break;
        OPT->Items[index]->MakePosition(cBest);
        bool OK=true;
        NEED->Items[BestTargetLink]->Check();
        OK = OK*(NEED->Items[BestTargetLink]->ITSOK(true));
        if (OK)
            OK = ( NEED->Items[BestTargetLink]->KeepCool(ckPos,true) );
        if (OK)
            for (int i=0;i<index0;i++)
            {
                OPT->Items[i]->CheckOptionalSizeLinks();
                OK = OK*(OPT->Items[i]->ITSOK(false));
                if (OK)
                    OK = OK * ( ABSINTVEC(OPT->Items[i]->GetScale(cBest))<=LINKINGEPS);
                if (!OK)
                    break;
            }
        if (OK)
            for (int i=index0;i<index;i++)
            {
                OPT->Items[i]->Check();
                OK = OK*(OPT->Items[i]->ITSOK(false));
                if (OK)
                    OK = OK * ( OPT->Items[i]->KeepCool(ckPos,false) );
                if (!OK)
                    break;
            }
        if (!OK)
        {
            OPT->Items[index]->UndoPosition(cBest);
            break;
        }
        else
            index++;
    }
    return index;
}

bool TDriver::Check()
{
    FPreLinksGenerated = false;
    //needed
    IsNowCorrectMode=false;
    if (!Element)
        return false;
    if (Element->MyMeta->IsAuto && IgnoreAuto)
        return true;
    //уничтожим прооемы
    for (int j=0;j<Element->LinkHoles.Count;j++)
    {
        bool donotdelete = false;
        for (int i=0;i<Element->FLinks.Count;i++)
            if (Element->FLinks[i].MyMeta->Link->HoleCreated)
                if (Element->FLinks[i].OtherElement(Element) == Element->LinkHoles[j].Client.ADR)
                {
                    donotdelete = true;
                    break;
                }
        if (!donotdelete)
            Element->LinkHoles[j].Client.ADR->DelMyHole();
    }
    Element->DelMyHole();
/*    if (AUI.BIF_MT->Head)     //return soon
        Element->Enable(false); */
    BestTargetLink = -1;
    NEED->Clear();
    OPT->Clear();
    O_E_L_Count = 0;
    for (int i=0;i<ALL->Count;i++)
    {
        ALL->Items[i]->Check();
        if (ALL->Items[i]->ITSOK(true) &&
        ( ALL->Items[i]->_Target(cNeed) == FloorElement || ALL->Items[i]->_Target(cNeed)->In(FloorElement)))
            NEED->Add(ALL->Items[i]);
    }
    if (NEED->Count==0)
        return(false);

//    Element->CurrentEnabled = true;
    MBTi MinStep = Measure(MAXCATCHEPS);
    BestTargetLink = -1;
    for (int i=0;i<NEED->Count;i++)
    {
        if (Measure(NEED->Items[i]->GetTranslate(cNeed))<MinStep)
        {
            MinStep = Measure(NEED->Items[i]->GetTranslate(cNeed));
            BestTargetLink = i;
        }
    }

//--------------------------------------------------------------------------
    NEED->Items[BestTargetLink]->MakePosition();
    TMetaLink *ML = NEED->Items[BestTargetLink]->GetDL(cNeed)->Link;
//--------------------------------------------------------------------------
    //return(true);
    for (int i=0;i<ALL->Count;i++)
    {
        ALL->Items[i]->Check();
        if (ALL->Items[i]->ITSOK(false))
            OPT->Add(ALL->Items[i]);
        else
        {
            ALL->Items[i]->CheckOptionalSizeLinks();
            if (ALL->Items[i]->ITSOK(false))
                OPT->Add(ALL->Items[i]);
        }

    }
//--------------------------------------------------------------------------
    int index = 0;
    IsNowCorrectMode = false;
    switch  (MainMode)
    {
        case ocmPosition :
            index = CheckByPosition(index);
            break;
        case ocmSize :
            index = CheckBySize(index);
            break;
    }
    int index0 = index;
    IsNowCorrectMode = true;
    switch  (CorrectMode)
    {
        case ocmPosition :
            index = CheckByPosition(index);
            break;
        case ocmSize :
            index = CheckBySize(index);
            break;
    }
    O_E_L_Count = index;
//--------------------------------------------------------------------------
    Element->UserChangePosition(ZEROINTVEC,ZEROINTVEC);
    NEED->Items[BestTargetLink]->Check();
//--------------------------------------------------------------------------
    IsNowCorrectMode=false;
    int i=0;
    switch  (MainMode)
    {
        case ocmPosition :
            while (i<index0)
            {
                OPT->Items[i]->Check();
                if (OPT->Items[i]->ITSOK(false))
                    i++;
                else
                    break;
            }
            break;
        case ocmSize :
            while (i<index0)
            {
                OPT->Items[i]->CheckOptionalSizeLinks();
                if (OPT->Items[i]->ITSOK(false))
                    i++;
                else
                    break;
            }
            break;
    }
    IsNowCorrectMode=true;
    if (i == index0)
        switch  (CorrectMode)
        {
            case ocmPosition :
                while (i<O_E_L_Count)
                {
                    OPT->Items[i]->Check();
                    if (OPT->Items[i]->ITSOK(false))
                        i++;
                    else
                        break;
                }
                break;
            case ocmSize :
                while (i<O_E_L_Count)
                {
                    OPT->Items[i]->CheckOptionalSizeLinks();
                    if (OPT->Items[i]->ITSOK(false))
                        i++;
                    else
                        break;
                }
                break;
        }
    O_E_L_Count = i;
//--------------------------------------------------------------------------
    if (ML->HoleCreated)
        Element->SetMyHoleFor(NEED->Items[BestTargetLink]->_Target(cNeed));
    if (ML->Client)
        Element->CreateClient(NEED->Items[BestTargetLink]->_Target(cNeed));
    for (int i=0;i<O_E_L_Count;i++)
        if (OPT->Items[i]->GetDL(cBest)->Link->HoleCreated )
        {
            OPT->Items[i]->_Source(cBest)->SetMyHoleFor(OPT->Items[i]->_Target(cBest));
        }
    return(true);
}

void TDriver::GeneratePreLinks()
{
    if (FPreLinksGenerated)
        return;

    FPreLinks.Clear();

    if (BestTargetLink == -1)
    {
        FPreLinksGenerated = true;
        return;
    }
    FPreLinks.SetCount(O_E_L_Count+1);

    FPreLinks[0].Target = NEED->Items[BestTargetLink]->_Target(cNeed);
    FPreLinks[0].Source = NEED->Items[BestTargetLink]->_Source(cNeed);
    FPreLinks[0].LINKPATTERN  = &NEED->Items[BestTargetLink]->GetSL(cNeed);

    for (int i=0;i<O_E_L_Count;i++)
    {
        FPreLinks[i+1].Target = OPT->Items[i]->_Target(cBest);
        FPreLinks[i+1].Source = OPT->Items[i]->_Source(cBest);
        FPreLinks[i+1].LINKPATTERN  = &OPT->Items[i]->GetSL(cBest);
    }
    FPreLinksGenerated = true;
}

int TDriver::GetPreLinksCount()
{
    GeneratePreLinks();
    return FPreLinks.Count;
}

TLinkInfo& TDriver::GetPreLink(int index)
{
    GeneratePreLinks();
    return FPreLinks[index];
}


bool TDriver::RealizeLinks()
{
    TMTList<TElement> EL_TOCREATEVIEW;
    CreateLink(
        NEED->Items[BestTargetLink]->GetDL(cNeed),
        NEED->Items[BestTargetLink]->_Target(cNeed),
        NEED->Items[BestTargetLink]->_Source(cNeed),
		NEED->Items[BestTargetLink]->GetCrossPoint(cNeed) );

	for (int i=0;i<O_E_L_Count;i++)
	{
		TMDelTList<TSyngleLink>* SLS = &OPT->Items[i]->GetSL(cBest).SyngleLinks;
		TLink* L;
		if (SLS->Count>0)
			for (int j=0;j<SLS->Count;j++)
			{
				L = CreateLink(
					OPT->Items[i]->GetDL(cBest),
					OPT->Items[i]->_Target(cBest),
					OPT->Items[i]->_Source(cBest),
					SLS->Items[j]->CrossPoint );
					if ( !ProcessVisualNodeByLink(L,false) )
						return false;
				TMDelTList<TObjectAttributePreSet>* OAPS = &SLS->Items[j]->OAPreSet;
				for (int i=0;i<OAPS->Count;i++)
					L->SetAttributeValue(OAPS->Items[i]->AttributeName.c_str(),OAPS->Items[i]->AttributeValue.c_str());
				L->RunLinkTrigger(trLinkCreate);
			}
	   else
		{
			L = CreateLink(
				OPT->Items[i]->GetDL(cBest),
				OPT->Items[i]->_Target(cBest),
                OPT->Items[i]->_Source(cBest),
                OPT->Items[i]->GetCrossPoint(cBest));
                if ( !ProcessVisualNodeByLink(L,false) )
                    return false;
            L->RunLinkTrigger(trLinkCreate);
        }
/*        if (L->MyMeta->Link->InWeb)
        {
            if (L->Elements[0]->MyMeta->InWeb&& EL_TOCREATEVIEW.IndexOf(L->Elements[0])==-1)
                EL_TOCREATEVIEW.Add(L->Elements[0]);
            if (L->Elements[1]->MyMeta->InWeb&& EL_TOCREATEVIEW.IndexOf(L->Elements[1])==-1)
                EL_TOCREATEVIEW.Add(L->Elements[1]);
        }   */
    }
/*    for (int i=0;i<EL_TOCREATEVIEW.Count;i++)
    {
        EL_TOCREATEVIEW.Items[i]->AdvancedTextureView=true;
        EL_TOCREATEVIEW.Items[i]->CreateView();
    } */
    return true;
}

bool TDriver::CheckCrossingAfterRealizeLinks()
{
    if ( Element->MyMeta->InWeb )
    {
        TMTList<TElement> NotLinkedWalls;
        for (int i=0;i<ALL->Count;i++)
        {
            if ( ALL->Items[i]->Target->MyMeta->InWeb &&
            ALL->Items[i]->ExistsWallLink() &&
            Element->GetLinkOf(ALL->Items[i]->Target)==NULL &&
            NotLinkedWalls.IndexOf(ALL->Items[i]->Target)==-1 )
                NotLinkedWalls.Add(ALL->Items[i]->Target);
        }
        TPolygon Pol0;
        Pol0.Vertex->Add(new TIntVec(Element->AbsSize.x/2,Element->AbsSize.y/2,0));
        Pol0.Vertex->Add(new TIntVec(-Element->AbsSize.x/2,Element->AbsSize.y/2,0));
        Pol0.Vertex->Add(new TIntVec(-Element->AbsSize.x/2,-Element->AbsSize.y/2,0));
        Pol0.Vertex->Add(new TIntVec(Element->AbsSize.x/2,-Element->AbsSize.y/2,0));
        for (int j=0;j<Pol0.Vertex->Count;j++)
            Element->AbsFromLocal(*(Pol0.Vertex->Items[j]),*(Pol0.Vertex->Items[j]));
        for (int i=0;i<NotLinkedWalls.Count;i++)
        {
            TPolygon Pol1;
            Pol1.Vertex->Add(new TIntVec(NotLinkedWalls[i].AbsSize.x/2,NotLinkedWalls[i].AbsSize.y/2,0));
            Pol1.Vertex->Add(new TIntVec(-NotLinkedWalls[i].AbsSize.x/2,NotLinkedWalls[i].AbsSize.y/2,0));
            Pol1.Vertex->Add(new TIntVec(-NotLinkedWalls[i].AbsSize.x/2,-NotLinkedWalls[i].AbsSize.y/2,0));
            Pol1.Vertex->Add(new TIntVec(NotLinkedWalls[i].AbsSize.x/2,-NotLinkedWalls[i].AbsSize.y/2,0));
            for (int j=0;j<Pol1.Vertex->Count;j++)
                NotLinkedWalls[i].AbsFromLocal(*(Pol1.Vertex->Items[j]),*(Pol1.Vertex->Items[j]));
            if (Pol0.CrossedWithPolygon(&Pol1,UNISTEP.x))
                return false;
        }
    }
    return true;
}

bool TDriver::Stop()
{
    _TRY_

        Stoping = true;
        bool _returned = true;
        if (!Element)
        {
            Stoping = false;
            return false;
        }
        if (Element->MyMeta->IsAuto && IgnoreAuto)
        {
            Clear();
            Stoping = false;
            return true;
        }
        if (Element->MyMeta->TB->Exists(trBeforeDriverStop))
        {
            Element->RunElementTrigger(trBeforeDriverStop);
        }
        _returned = Check() && RealizeLinks() && CheckCrossingAfterRealizeLinks();
        if (!_returned)
            Element->DeleteNeededLink();
        Clear();
        Stoping = false;
        return _returned;

    _ENDTRY_ (  AnsiString("<TDriver::Stop>: The technology does not allow you to insert element such a way")+Element->MyMeta->Description,
                Element->DeleteNeededLink();
                CurElement = NULL;
                Clear();
                return false; )
}



//---------------------------------------------------------------
//---------------------------------------------------------------
void TDriverQueue::OnProcess()
{ /* TODO : дописать onProcess для DriverQueue:: */
/*    for(int i=0;i<FElements.Count;i++)
    {
        Driver.Init(FElements.Items[i]);
        if ( !Driver.Stop() )
            delete FElements.Items[i];
    }
    Clear(); */
}

