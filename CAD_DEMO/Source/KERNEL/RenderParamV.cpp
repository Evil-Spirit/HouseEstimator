//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
           
#include "RenderParamV.h"
#include "LogicNode.h"
#include "MetaNodeCollectionV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TRenderParam::StaticType = NULL;
TClassNode* TFragmentSettings::StaticType = NULL;

TMyObject* TRenderParam::CreateFunction()
{
    return new TRenderParam();
}

const AnsiString aTEXs = AnsiString("TEXs");
const AnsiString aMATs = AnsiString("MATs");
const AnsiString aTexCenter = AnsiString("TexCenter");
const AnsiString aTexAngle = AnsiString("TexAngle");
const AnsiString aEnabled = AnsiString("Enabled");
const AnsiString aOverPosMode = AnsiString("OverPosMode");
const AnsiString aOverPos = AnsiString("OverPos");
const AnsiString aFLAT2D = AnsiString("FLAT2D");
const AnsiString aOverSizeMode = AnsiString("OverSizeMode");
const AnsiString aOverSize = AnsiString("OverSize");
const AnsiString aMODE = AnsiString("MODE");

TRenderParam::TRenderParam()
{
    RegisterNewClass< TMyObject, TRenderParam >(this,false,&CreateFunction);
    RegisterField(&TexCenter,&aTexCenter,mtIntVec);
    RegisterField(&TexAngle,&aTexAngle,mtIntVec);
	RegisterField(&TEXs,&aTEXs,mtMyObject);
	RegisterField(&MATs,&aMATs,mtMyObject);
    RegisterField(&MODE,&aMODE,mtMyObject);

    RegisterField(&Enabled,&aEnabled,mtBool);
    RegisterField(&OverPosMode,&aOverPosMode,mtBool);
    RegisterField(&OverPos,&aOverPos,mtIntVec);
    RegisterField(&FLAT2D,&aFLAT2D,mtBool);
    RegisterField(&OverSizeMode,&aOverSizeMode,mtBool);
    RegisterField(&OverSize,&aOverSize,mtIntVec);

/*    NeedTexMat = NULL;
    NeedConstruct = NULL;
    NeedPositionAngle = NULL;*/
    Tag = -1;
}

void TRenderParam::AssignMode(TMyModeSettings* _MMS)
{
	if (_MMS)
	{
		TEXs.Assign(&_MMS->TEXs);
		TEXs.CheckFields();
		MATs.Assign(&_MMS->MATs);
		MATs.CheckFields();
	}
	OverPos = (_MMS)? _MMS->OverPos : ZEROINTVEC;
	OverSize = (_MMS)? _MMS->OverSize : ZEROINTVEC;
	OverSizeMode = (_MMS)? _MMS->OverSizeMode == omAdd : false;
	OverPosMode = (_MMS)? _MMS->OverPosMode == omReplace : false;
	FLAT2D = (_MMS)? _MMS->FLAT_2D : false;
	Enabled = (_MMS)? _MMS->Render : true;
}

void TRenderParam::SetEnabled(bool Value)
{
    AboutToChange(this);
    FEnabled = Value;
    Changed(this);
}

void TRenderParam::SetOverPosMode(bool Value)
{
    AboutToChange(this);
    FOverPosMode = Value;
    Changed(this);
}

void TRenderParam::SetOverSizeMode(bool Value)
{
    AboutToChange(this);
    FOverSizeMode = Value;
    Changed(this);
}
void TRenderParam::SetFLAT2D(bool Value)
{
    AboutToChange(this);
    FFLAT2D = Value;
    Changed(this);
}


TVisTexture* TRenderParam::GetTexture()
{
	return GetTexture(0);
}

TVisMaterial* TRenderParam::GetMaterial()
{
	return GetMaterial(0);
}

TVisTexture* TRenderParam::GetTexture(int i)
{
	if (TEXs.Count > i && TEXs[i].ADR!=NULL)
		return TEXs[i].ADR->VT;
	else
		return NULL;
}

TVisMaterial* TRenderParam::GetMaterial(int i)
{
	if (MATs.Count > i && MATs[i].ADR!=NULL)
		return MATs[i].ADR->VM;
	else if (MATs.Count > 0 && MATs[0].ADR!=NULL)
		return MATs[0].ADR->VM;
	else
		return MaterialDefault;
}

void TRenderParam::SetMetaTex(TMetaTexture* MT)
{
	SetMetaTex(MT,0);
}

void TRenderParam::SetMetaMat(TMetaMaterial* MM)
{
	SetMetaMat(MM,0);
}

void TRenderParam::SetMetaTex(TMetaTexture* MT, int i)
{
	AboutToChange(this);  /* TODO : избыточно */
	while (TEXs.Count<=i)
		TEXs.Add( new TPointer<TMetaTexture>(NULL) );
	TEXs[i].ADR = MT;
	Changed(this);
}

void TRenderParam::SetMetaMat(TMetaMaterial* MM, int i)
{
	AboutToChange(this);  /* TODO : избыточно */
	while (MATs.Count<=i)
		MATs.Add( new TPointer<TMetaMaterial>(NULL) );
	MATs[i].ADR = MM;
	Changed(this);
}

TMetaTexture* TRenderParam::GetMetaTex()
{
	return GetMetaTex(0);
}

TMetaMaterial* TRenderParam::GetMetaMat()
{
	return GetMetaMat(0);
}

TMetaTexture* TRenderParam::GetMetaTex(int i)
{
	if(TEXs.Count > i)
		return TEXs[i].ADR;
	return NULL;
}

TMetaMaterial* TRenderParam::GetMetaMat(int i)
{
	if(MATs.Count > i)
		return MATs[i].ADR;
	return NULL;
}


/////////////////////////////////////////-------------------------------------//
//---------------------------------------///////////////////////////////////////
TMyObject* TFragmentSettings::CreateFunction()
{
    return new TFragmentSettings();
}

const AnsiString aPolygons = AnsiString("Polygons");
const AnsiString aParameteres = AnsiString("Parameteres");
const AnsiString aIsOutSide = AnsiString("IsOutSide");
const AnsiString aSideType = AnsiString("SideType");
const AnsiString aSideIndex = AnsiString("SideIndex");
const AnsiString aLocalP0 = AnsiString("LocalP0");
const AnsiString aLocalP1 = AnsiString("LocalP1");
const AnsiString aISWALLEND = AnsiString("ISWALLEND");
const AnsiString aISWALLSTART = AnsiString("ISWALLSTART");

TFragmentSettings::TFragmentSettings()
{
    RegisterNewClass< TMyObject, TFragmentSettings >(this,false,&CreateFunction);
    Parameteres.Add( new TRenderParam() );
    Polygons.Add( new THoledPolygon() );
    RegisterField(&Polygons,&aPolygons,mtMyObject);
    RegisterField(&Parameteres,&aParameteres,mtMyObject);
    RegisterField(&IsOutSide,&aIsOutSide,mtBool);
    RegisterField(&SideType,&aSideType,mtInt);
    RegisterField(&SideIndex,&aSideIndex,mtInt);

    RegisterField(&ISWALLEND,&aISWALLEND,mtBool);
    RegisterField(&ISWALLSTART,&aISWALLSTART,mtBool);
    RegisterField(&LocalP0,&aLocalP0,mtIntVec);
    RegisterField(&LocalP1,&aLocalP1,mtIntVec);
}

int TFragmentSettings::GetPolygonCount()
{
    return Polygons.Count;
}

TRenderParam* TFragmentSettings::GetRenderParam(int i)
{
    return Parameteres.Items[i];
}

THoledPolygon* TFragmentSettings::GetPolygon(int i)
{
    return Polygons.Items[i];
}


void TFragmentSettings::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
/*    if (!Data || !MY_IS(((TMyObject*)Data),typeid(TCube)) )
        throw EMyException("");
    ( new TFragmentEditor(Application,this,(TCube*)Data) )->ShowModal(); */
}

                                
int TFragmentSettings::FragmentOfPoint(const TIntVec& LocPoint,MBTi USEEPS)
{
    TIntVec LocVec;
    bool Exists = false;
    if ( SideType == stYMinus && LocPoint.y < 0)
    {
        Exists = true;
        LocVec = TIntVec(LocPoint.x,LocPoint.z,0);
    }
    else if  ( SideType == stYPlus && LocPoint.y > 0)
    {
        Exists = true;
        LocVec = TIntVec(LocPoint.x,LocPoint.z,0);
    }
    else if  ( SideType == stXPlus && LocPoint.x > 0)
    {
        Exists = true;
        LocVec = TIntVec(LocPoint.y,LocPoint.z,0);
    }
    else if  ( SideType == stXMinus && LocPoint.x < 0)
    {
        Exists = true;
        LocVec = TIntVec(LocPoint.y,LocPoint.z,0);
    }
    if ( Exists )
        for (int i=0;i<Polygons.Count;i++)
            if (Polygons[i].ConsistsPoint_UseHoles(LocVec,USEEPS) == pipINSIDE)
                return i;
    return -1;
}


