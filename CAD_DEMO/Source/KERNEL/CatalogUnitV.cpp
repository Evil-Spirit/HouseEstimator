//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ImgLibV.h"
#include "CatalogUnitV.h"
    //------------------------------------------------------------------------
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
        #include "MDIMetaCatalogUnitV.h"
    #endif
    //------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
TClassNode* TMetaCatalogUnit::StaticType = NULL;

AnsiString aASSOCIATED = AnsiString("ASSOCIATED");

TMyObject* TMetaCatalogUnit::CreateFunction()
{
    return new TMetaCatalogUnit();
}

TMetaCatalogUnit::TMetaCatalogUnit()
{
    RegisterNewClass< TMetaNode, TMetaCatalogUnit >(this,false,&CreateFunction);
    RegisterField(&ASSOCIATED,&aASSOCIATED,mtMyObject);
    ImageIndex = iiMetaCatalogUnit;
    ChildType = cNone;
}

TMetaCatalogUnit::TMetaCatalogUnit(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TMetaCatalogUnit >(this,false,&CreateFunction);
    RegisterField(&ASSOCIATED,&aASSOCIATED,mtMyObject);
    ImageIndex = iiMetaCatalogUnit;
    ChildType = cNone;
    Parent = _Parent;
}

void TMetaCatalogUnit::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaCatalogUnit(Owner,this);
    #endif
}

void TMetaCatalogUnit::GetImage(bool Small,bool Masked,Graphics::TBitmap* bmp,Graphics::TBitmap* mask)
{
    TBMPPointer* USEBMPPTR = NULL;
    if (Small)
    {
        if ( ASSOCIATED.ADR && ((TMetaNode*)ASSOCIATED.ADR)->SmallImg->Valid() )
            USEBMPPTR = ((TMetaNode*)ASSOCIATED.ADR)->SmallImg;
        else if (SmallImg->Valid())
            USEBMPPTR = SmallImg;
    }
    else
    {
        if ( ASSOCIATED.ADR && ((TMetaNode*)ASSOCIATED.ADR)->Img1->Valid() )
            USEBMPPTR = ((TMetaNode*)ASSOCIATED.ADR)->Img1;
        else if (Img1->Valid())
            USEBMPPTR = Img1;
    }
    int index = -1;
    TImageList* USEIL = NULL;
    if (USEBMPPTR)
    {
        index = USEBMPPTR->Index;
        USEIL = USEBMPPTR->ImgList;
    }
    else
    {
        index = siSOPOS;
        USEIL = ImageLibrary->ilStandart;
    }
    bmp->Width = USEIL->Width;
    bmp->Height = USEIL->Height;
    mask->Width = USEIL->Width;
    mask->Height = USEIL->Height;
    USEIL->GetBitmap(index,bmp);
    USEIL->Draw(mask->Canvas,0,0,index,dsNormal,itMask);
}

TMetaNode* TMetaCatalogUnit::GetAssociated()
{
    return (TMetaNode*)ASSOCIATED.ADR;
}

