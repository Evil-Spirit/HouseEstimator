//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RoofEditV.h"
#include "RoofV.h"
#include "LuaAttributeV.h"
#include "ElementV.h"
#include "MultiElementV.h"
#include "math.h"
#include "Main.h"
#include "UI.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int iSide;
int iPlane;
TRoofForm *RoofForm;

void update(TMultiElement *Element);
class RoofParam
{
public:
	AnsiString		name;
	MBTi	 		def;
	MBTi			min;
	MBTi			max;
	MBTi			mine;
	MBTi			maxe;

	RoofParam(const AnsiString &name = "NoName", MBTi def = 0, MBTi min= 0 , MBTi max = 50, MBTi mine = 1, MBTi maxe = 1)
	{
		this->name		= name;
		this->def		= def;
		this->min		= min;
		this->max		= max;
		this->mine		= mine;
		this->maxe		= maxe;
	}

};

class RoofTemplate
{
public:
	AnsiString Name;
	TMDelTList <RoofParam> params;

	virtual void defaultParams(MBTi *pvalue)
	{
		for (int i=0;i<params.Count;i++)
			pvalue[i] = params[i].def;
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
	}

	virtual MBTi getCheckParam(int pindex, bool &value)
	{
		MBTi v = 0;

		v = value;
		if ( v > params[pindex].max-params[pindex].maxe)
			v = params[pindex].max-params[pindex].maxe;

		if (v<params[pindex].min+params[pindex].mine)
			v = params[pindex].min+params[pindex].mine;

		value = (int)v;
		return (int)v;
	}

	virtual MBTi getCheckParam(int pindex, AnsiString &value)
	{
		MBTi v = 0;

		if (IS_FLOAT(value))
		{
			v = TO_DOUBLE(value);
			if ( v > params[pindex].max-params[pindex].maxe)
				v = params[pindex].max-params[pindex].maxe;

			if (v<params[pindex].min+params[pindex].mine)
				v = params[pindex].min+params[pindex].mine;
		} else
			v = params[pindex].def;

		value = FloatToStr( v );
		return v;
	}

	virtual void setToForm(const MBTi *pvalue)
	{

	}
	virtual void getFromForm(MBTi *pvalue)
	{

	}



};

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//------- TEMPLATES -----------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

class SimpleTemplate : public RoofTemplate
{
public:
	SimpleTemplate()
	{
		params.Add(new RoofParam("Slope", 45, 5 , 90, 1, 0));
		params.Add(new RoofParam("Front", 0, 0 , 1, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		roof.Planes.Add(new TRoofPlane());
		roof.Planes[0].Angle	= pvalue[0];
		roof.Planes[0].Height	= 0;
		roof.Planes[0].Front	= (int)pvalue[1];
	}
	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edSimpleAngle->Text		= FloatToStr(pvalue[0]);
		RoofForm->cbSimpleFront->Checked	= (int)pvalue[1];
	}
	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edSimpleAngle->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edSimpleAngle->Text = txt;
		log = RoofForm->cbSimpleFront->Checked; 	pvalue[1] = RoofTemplate::getCheckParam(1, log); RoofForm->cbSimpleFront->Checked = log;
	}
};

class DoubleConvexTemplate : public RoofTemplate
{
public:
	DoubleConvexTemplate()
	{
		params.Add(new RoofParam("Slope1", 60, 5 , 90, 1, 0));
		params.Add(new RoofParam("Front1", 0, 0 , 1, 0, 0));
		params.Add(new RoofParam("Slope2", 30, 5 , 90, 1, 0));
		params.Add(new RoofParam("Front2", 0, 0 , 1, 0, 0));
		params.Add(new RoofParam("Level", 1, 0 , 100, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		roof.Planes.Add(new TRoofPlane());
		roof.Planes.Add(new TRoofPlane());

		roof.Planes[0].Angle	= pvalue[0];
		roof.Planes[0].Height	= 0;
		roof.Planes[0].Front	= (int)pvalue[1];

		roof.Planes[1].Angle	= pvalue[2];
		roof.Planes[1].Height	= pvalue[4];
		roof.Planes[1].Front	= (int)pvalue[3];
	}

	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edDConvexSlope1->Text		= FloatToStr(pvalue[0]);
		RoofForm->cbDConvexFront1->Checked	= (int)pvalue[1];
		RoofForm->edDConvexSlope2->Text		= FloatToStr(pvalue[2]);
		RoofForm->cbDConvexFront2->Checked	= (int)pvalue[3];
		RoofForm->edDConvexLevel->Text		= pvalue[4];
	}

	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edDConvexSlope1->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edDConvexSlope1->Text = txt;
		log = RoofForm->cbDConvexFront1->Checked; 	pvalue[1] = RoofTemplate::getCheckParam(1, log); RoofForm->cbDConvexFront1->Checked = log;
		txt = RoofForm->edDConvexSlope2->Text;		pvalue[2] = RoofTemplate::getCheckParam(2, txt); RoofForm->edDConvexSlope2->Text = txt;
		log = RoofForm->cbDConvexFront2->Checked; 	pvalue[3] = RoofTemplate::getCheckParam(3, log); RoofForm->cbDConvexFront2->Checked = log;
		txt = RoofForm->edDConvexLevel->Text;		pvalue[4] = RoofTemplate::getCheckParam(4, txt); RoofForm->edDConvexLevel->Text = txt;
	}

};

class DoubleConcaveTemplate : public RoofTemplate
{
public:
	DoubleConcaveTemplate()
	{
		params.Add(new RoofParam("Slope1", 30, 5 , 90, 1, 0));
		params.Add(new RoofParam("Front1", 0, 0 , 1, 0, 0));
		params.Add(new RoofParam("Slope2", 60, 5 , 90, 1, 0));
		params.Add(new RoofParam("Front2", 0, 0 , 1, 0, 0));
		params.Add(new RoofParam("Level", 1, 0 , 100, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		roof.Planes.Add(new TRoofPlane());
		roof.Planes.Add(new TRoofPlane());

		roof.Planes[0].Angle	= pvalue[0];
		roof.Planes[0].Height	= 0;
		roof.Planes[0].Front	= (int)pvalue[1];

		roof.Planes[1].Angle	= pvalue[2];
		roof.Planes[1].Height	= pvalue[4];
		roof.Planes[1].Front	= (int)pvalue[3];
	}

	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edDConcaveSlope1->Text		= FloatToStr(pvalue[0]);
		RoofForm->cbDConcaveFront1->Checked	= (int)pvalue[1];
		RoofForm->edDConcaveSlope2->Text		= FloatToStr(pvalue[2]);
		RoofForm->cbDConcaveFront2->Checked	= (int)pvalue[3];
		RoofForm->edDConcaveLevel->Text		= pvalue[4];
	}

	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edDConcaveSlope1->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edDConcaveSlope1->Text = txt;
		log = RoofForm->cbDConcaveFront1->Checked; 	pvalue[1] = RoofTemplate::getCheckParam(1, log); RoofForm->cbDConcaveFront1->Checked = log;
		txt = RoofForm->edDConcaveSlope2->Text;		pvalue[2] = RoofTemplate::getCheckParam(2, txt); RoofForm->edDConcaveSlope2->Text = txt;
		log = RoofForm->cbDConcaveFront2->Checked; 	pvalue[3] = RoofTemplate::getCheckParam(3, log); RoofForm->cbDConcaveFront2->Checked = log;
		txt = RoofForm->edDConcaveLevel->Text;		pvalue[4] = RoofTemplate::getCheckParam(4, txt); RoofForm->edDConcaveLevel->Text = txt;
	}

};

class RoundConvexTemplate : public RoofTemplate
{
public:
	RoundConvexTemplate()
	{
		params.Add(new RoofParam("Subdiv", 5, 2 , 30, 0, 0));
		params.Add(new RoofParam("Height", 1, 0.1, 100, 0, 0));
		params.Add(new RoofParam("Round", 45, 1 , 90, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		for (int  j=0;j<pvalue[0];j++)
		{
			roof.Planes.Add(new TRoofPlane());

			roof.Planes[j].Height = sin(M_PI/2*j/(pvalue[0]+1))*pvalue[1];
			roof.Planes[j].Front = 0;
			roof.Planes[j].Angle = (pvalue[0]-j)*(pvalue[2]/(pvalue[0]+1.0));
		}
	}

	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edRConvexSubdiv->Text		= FloatToStr(pvalue[0]);
		RoofForm->edRConvexHeight->Text		= FloatToStr(pvalue[1]);
		RoofForm->edRConvexRound->Text		= FloatToStr(pvalue[2]);
	}

	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edRConvexSubdiv->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edRConvexSubdiv->Text = txt;
		txt = RoofForm->edRConvexHeight->Text;		pvalue[1] = RoofTemplate::getCheckParam(1, txt); RoofForm->edRConvexHeight->Text = txt;
		txt = RoofForm->edRConvexRound->Text;		pvalue[2] = RoofTemplate::getCheckParam(2, txt); RoofForm->edRConvexRound->Text = txt;
	}

};

class RoundConcaveTemplate : public RoofTemplate
{
public:
	RoundConcaveTemplate()
	{
		params.Add(new RoofParam("Subdiv", 5, 2 , 30, 0, 0));
		params.Add(new RoofParam("Height", 1, 0.1, 100, 0, 0));
		params.Add(new RoofParam("Round", 45, 1 , 90, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		for (int  j=0;j<pvalue[0];j++)
		{
			roof.Planes.Add(new TRoofPlane());
			roof.Planes[j].Height = (1-sin(M_PI/2*(pvalue[0]-j) / pvalue[0]))*pvalue[1];
			roof.Planes[j].Front = 0;
			roof.Planes[j].Angle = (j+1)*(pvalue[2]/(pvalue[0]+2));
		}
	}

	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edRConcaveSubdiv->Text		= FloatToStr(pvalue[0]);
		RoofForm->edRConcaveHeight->Text		= FloatToStr(pvalue[1]);
		RoofForm->edRConcaveRound->Text		= FloatToStr(pvalue[2]);
	}

	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edRConcaveSubdiv->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edRConcaveSubdiv->Text = txt;
		txt = RoofForm->edRConcaveHeight->Text;		pvalue[1] = RoofTemplate::getCheckParam(1, txt); RoofForm->edRConcaveHeight->Text = txt;
		txt = RoofForm->edRConcaveRound->Text;		pvalue[2] = RoofTemplate::getCheckParam(2, txt); RoofForm->edRConcaveRound->Text = txt;
	}

};

class DomeTemplate : public RoofTemplate
{
public:
	DomeTemplate()
	{
		params.Add(new RoofParam("Subdiv", 5, 2 , 30, 0, 0));
		params.Add(new RoofParam("Height", 1, 0.1, 100, 0, 0));
		params.Add(new RoofParam("Round1", 90, 1 , 90, 0, 0));
		params.Add(new RoofParam("Round2", 15, 1 , 90, 0, 0));
	}

	virtual void generate(TRoofSide &roof, const MBTi *pvalue)
	{
		roof.Planes.Clear();
		for (int  j=0;j<pvalue[0];j++)
		{
			roof.Planes.Add(new TRoofPlane());
			roof.Planes[j].Height = j*pvalue[1]/(pvalue[0]+1);
			roof.Planes[j].Front = 0;
			roof.Planes[j].Angle = ((cos(j*2*M_PI/(pvalue[0]+1))+1)*0.5)*(pvalue[2]-pvalue[3]) + pvalue[3];
		}
	}

	virtual void setToForm(const MBTi *pvalue)
	{
		RoofForm->edDomeSubdiv->Text		= FloatToStr(pvalue[0]);
		RoofForm->edDomeHeight->Text		= FloatToStr(pvalue[1]);
		RoofForm->edDomeRound1->Text		= FloatToStr(pvalue[2]);
		RoofForm->edDomeRound2->Text		= FloatToStr(pvalue[3]);
	}

	virtual void getFromForm(MBTi *pvalue)
	{
		AnsiString txt;
		bool 	   log;

		txt = RoofForm->edDomeSubdiv->Text;		pvalue[0] = RoofTemplate::getCheckParam(0, txt); RoofForm->edDomeSubdiv->Text = txt;
		txt = RoofForm->edDomeHeight->Text;		pvalue[1] = RoofTemplate::getCheckParam(1, txt); RoofForm->edDomeHeight->Text = txt;
		txt = RoofForm->edDomeRound1->Text;		pvalue[2] = RoofTemplate::getCheckParam(2, txt); RoofForm->edDomeRound1->Text = txt;
		txt = RoofForm->edDomeRound2->Text;		pvalue[3] = RoofTemplate::getCheckParam(3, txt); RoofForm->edDomeRound2->Text = txt;
	}

};



TMTList <RoofTemplate> Templates;

void initTemplates()
{
	Templates.Add(new SimpleTemplate());
	Templates.Add(new DoubleConvexTemplate());
	Templates.Add(new DoubleConcaveTemplate());
	Templates.Add(new RoundConvexTemplate());
	Templates.Add(new RoundConcaveTemplate());
	Templates.Add(new DomeTemplate());
}

#pragma startup initTemplates

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//--- END OF TEMPLATES --------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////


class TMyRoofSide : public TRoofSide
{
	RoofTemplate		*template_;
	RoofTemplate		*old_template;
	void setT(RoofTemplate *t)
	{
		if ( t != NULL )
			old_template = template_;
		template_ = t;

		if (template_ != NULL && old_template != template_)
			template_->defaultParams(templParams);

		if (template_ != NULL)
			template_->generate(*this, templParams);
	}
public:
	__property RoofTemplate* templ = {read = template_, write = setT};

	MBTi				templParams[5];


	TMyRoofSide() : TRoofSide(), template_(NULL), old_template(NULL) {};
	TMyRoofSide(TGCut *c) : TRoofSide(c), template_(NULL), old_template(NULL) {};

	TMyRoofSide& operator =(const TMyRoofSide &o)
	{
		TRoofSide::operator=(o);
		template_ = o.template_;
		old_template = old_template;
		for (int i=0;i<5;i++)
			templParams[i] = o.templParams[i];
		return *this;
	}

};


class TRoofSet
{
public:
	TMDelTList <TMyRoofSide> Roof;
	bool walls_create;
	bool cover;
	bool obresh;
	TRoofSet &operator = (const TRoofSet &o)
	{
		walls_create = o.walls_create;
		cover = o.cover;
		obresh = o.obresh;
		Roof.Clear();
		for (int i=0;i<o.Roof.Count;i++)
		{
			Roof.Add(new TMyRoofSide());
			Roof[Roof.Count-1] = o.Roof[i];
		}
		return *this;
	}

};

TRoofSet RoofSet;
TRoofSet BeforeEditSet;
TIntVec BeforeEditAbsPos;

void applyTemplate(RoofTemplate *temp)
{
	if (iSide != -1)
	{
		RoofSet.Roof[iSide].templ = temp;
		RoofForm->UpdateSide(iSide, iPlane);
	}
}




TLuaAttributeList& GetAttributes(TLuaAttribute& Attribute)
{

	if (Attribute.Type != mtMyObject
		|| !((TMyObject*)Attribute.Value)->Is(TLuaAttributeList::StaticType))
	{
		Attribute.Type = mtMyObject;
		Attribute.Aggregative = true;
		Attribute.Value = new TLuaAttributeList();
	}
	return *( (TLuaAttributeList*)Attribute.Value );
}

bool LoadRoofSet( TElement &Roof, TRoofSet &Set, int Count)
{
	try
	{
		Set.walls_create = Roof.GetAttribute("walls_create")->VALUE.ToInt() ;
		Set.cover = Roof.GetAttribute("cover")->VALUE.ToInt();
		Set.obresh = Roof.GetAttribute("obresh")->VALUE.ToInt();

		TLuaAttributeList& SlopeListAttribute = GetAttributes( *(Roof.GetAttribute("slope")) );

		while (SlopeListAttribute.AttributeICount > Count)
			SlopeListAttribute.DeleteAttributeI(Count);


		while (SlopeListAttribute.AttributeICount < Count)
		{
			TLuaAttributeList& AttributeI = GetAttributes (*SlopeListAttribute.AddAttributeI());
			TLuaAttributeList& AttributeJ = GetAttributes (*AttributeI.AddAttribute(1,"plane"));

			AttributeJ.AddAttribute(0, "fronton")->VALUE	= "0";
			AttributeJ.AddAttribute(1, "angle")->VALUE	= "35";

			AttributeI.AddAttribute(1, "salient")->VALUE	= "0.3";
			AttributeI.AddAttribute(1, "h1")->VALUE		= "0";
		}

		while (Set.Roof.Count<Count)
			Set.Roof.Add(new TMyRoofSide());

		while (Set.Roof.Count>Count)
			Set.Roof.Delete(0);

		for (int i=0;i<Count;i++)
		{
			TLuaAttributeList& AttributeI = GetAttributes( *SlopeListAttribute.GetAttributeI(i) );
			Set.Roof[i].Salient	= TO_DOUBLE(AttributeI.GetAttribute("salient")->VALUE);
			Set.Roof[i].Planes.Clear();
			TLuaAttributeList& Plane = GetAttributes( *AttributeI.GetAttribute("plane") );

			if (Plane.AttributeICount == 0)
			{
				Set.Roof[i].Planes.Add(new TRoofPlane());
				Set.Roof[i].Planes[0].Front = 0;
				Set.Roof[i].Planes[0].Angle = 45;
				Set.Roof[i].Planes[0].Height = 0;
//				Set.Roof[i].templ = Templates.Items[0];
				Set.Roof[i].templParams[0] = 45;
				Set.Roof[i].templParams[1] = 0;
				Set.Roof[i].templParams[2] = 0;
				Set.Roof[i].templParams[3] = 0;
				Set.Roof[i].templParams[4] = 0;
			}
			else
			{
				while (Set.Roof[i].Planes.Count<Plane.AttributeICount)
					Set.Roof[i].Planes.Add(new TRoofPlane());

				while (Set.Roof[i].Planes.Count>Plane.AttributeICount)
					Set.Roof[i].Planes.Delete(0);

				for (int j=0;j<Plane.AttributeICount;j++)
				{
					TLuaAttributeList& AttributeJ = GetAttributes(*Plane.GetAttributeI(j));
					Set.Roof[i].Planes[j].Front = TO_DOUBLE(AttributeJ.GetAttribute("fronton")->VALUE);
					Set.Roof[i].Planes[j].Angle = TO_DOUBLE(AttributeJ.GetAttribute("angle")->VALUE);
					Set.Roof[i].Planes[j].Height = TO_DOUBLE(AttributeJ.GetAttribute("height")->VALUE);
				}
			}

			if (AttributeI.GetAttribute("template")!= NULL)
			{
				TLuaAttributeList& TEMPLATE = GetAttributes ( *AttributeI.GetAttribute("template"));
//				Set.Roof[i].templ = Templates.Items[TEMPLATE.GetAttribute("index")->VALUE.ToInt()];
				Set.Roof[i].templParams[0] = TO_DOUBLE(TEMPLATE.GetAttribute("parameters[1]")->VALUE);
				Set.Roof[i].templParams[1] = TO_DOUBLE(TEMPLATE.GetAttribute("parameters[2]")->VALUE);
				Set.Roof[i].templParams[2] = TO_DOUBLE(TEMPLATE.GetAttribute("parameters[3]")->VALUE);
				Set.Roof[i].templParams[3] = TO_DOUBLE(TEMPLATE.GetAttribute("parameters[4]")->VALUE);
				Set.Roof[i].templParams[4] = TO_DOUBLE(TEMPLATE.GetAttribute("parameters[5]")->VALUE);
			}
		}
	} catch (Exception &e)
	{
		return false;
	}
	return true;
}

bool SaveRoofSet(TElement &Roof, TRoofSet &Set, int Count)
{
	try {
		Roof.SetAttributeValue("walls_create", IntToStr(Set.walls_create).c_str());
		Roof.SetAttributeValue("cover", IntToStr(Set.cover).c_str());
		Roof.SetAttributeValue("obresh", IntToStr(Set.obresh).c_str());

		TLuaAttributeList&  SlopeListAttribute = GetAttributes( *Roof.GetAttribute("slope") );

		while (SlopeListAttribute.AttributeICount>0)
			SlopeListAttribute.DeleteAttributeI(0);

		for (int i=0;i<Count;i++)
		{
			TLuaAttributeList& AttributeI = GetAttributes( *SlopeListAttribute.AddAttributeI() );
			TLuaAttributeList& Plane = GetAttributes ( *AttributeI.AddAttribute(1,"plane"));

			for (int j=0;j<Set.Roof[i].Planes.Count;j++)
			{
				TLuaAttributeList& AttributeJ = GetAttributes( *Plane.AddAttributeI());
				AttributeJ.AddAttribute(0, "fronton")->VALUE	= IntToStr(Set.Roof[i].Planes[j].Front);
				AttributeJ.AddAttribute(1, "angle")->VALUE	= FloatToStr(Set.Roof[i].Planes[j].Angle);
				AttributeJ.AddAttribute(1, "height")->VALUE	= FloatToStr(Set.Roof[i].Planes[j].Height);
			}

			AttributeI.AddAttribute(1,"salient")->VALUE = FloatToStr(Set.Roof[i].Salient);
			AttributeI.AddAttribute(1,"h1")->VALUE = "0";

			if (Set.Roof[i].templ != NULL)
			{
				TLuaAttributeList& TEMPLATE = GetAttributes( *AttributeI.AddAttribute(0,"template"));

				TEMPLATE.AddAttribute(1,"index")->VALUE = IntToStr( Templates.IndexOf(Set.Roof[i].templ));

				TEMPLATE.AddAttribute(1,"parameters[1]")->VALUE = FloatToStr(Set.Roof[i].templParams[0]);
				TEMPLATE.AddAttribute(1,"parameters[2]")->VALUE = FloatToStr(Set.Roof[i].templParams[1]);
				TEMPLATE.AddAttribute(1,"parameters[3]")->VALUE = FloatToStr(Set.Roof[i].templParams[2]);
				TEMPLATE.AddAttribute(1,"parameters[4]")->VALUE = FloatToStr(Set.Roof[i].templParams[3]);
				TEMPLATE.AddAttribute(1,"parameters[5]")->VALUE = FloatToStr(Set.Roof[i].templParams[4]);
			}
		}
	} catch (Exception &e)
	{
		return false;
	}
    return true;
}






void TRoofForm::SaveSide()
{
	if (iSide < 0 || iSide >= RoofSet.Roof.Count)
		return;
	RoofSet.Roof[iSide].Salient = TO_DOUBLE(edSalient->Text);


	if (RoofSet.Roof[iSide].templ == NULL)
	{
		if (iPlane < 0 || iPlane >= RoofSet.Roof[iSide].Planes.Count)
			return;
		RoofSet.Roof[iSide].Planes[iPlane].Angle = TO_DOUBLE(edSlopeAngle->Text);
		RoofSet.Roof[iSide].Planes[iPlane].Height = TO_DOUBLE(edSlopeLevel->Text);
		RoofSet.Roof[iSide].Planes[iPlane].Front = (MBTi)(int)(cbSlopeFront->Checked);
	} else
	{
		RoofSet.Roof[iSide].templ->getFromForm(RoofSet.Roof[iSide].templParams);
		RoofSet.Roof[iSide].templ->generate(RoofSet.Roof[iSide], RoofSet.Roof[iSide].templParams);
	}
}

void TRoofForm::UpdateSide(int nextSide, int nextPlane)
{
/*	if (iSide != -1)
		Roof[iSide % Roof.Count].Cut->Flags.Intersect = gfFALSE;*/

	if (RoofSet.Roof.Count)
		iSide = (nextSide + RoofSet.Roof.Count) % RoofSet.Roof.Count;
	else
		iSide = -1;

	lbWallIndex->Caption = IntToStr(iSide);
	edSalient->Text = FloatToStr(RoofSet.Roof[iSide].Salient);
	if (iSide != -1)
		RoofForm->TElementViewer1->ShowElement->SetAttributeValue("select", IntToStr(RoofSet.Roof[iSide].templ != NULL).c_str());
	if (iSide != -1 && RoofSet.Roof[iSide].templ == NULL)
	{
		PageControl1->ActivePageIndex = 6;

		if (iSide != -1 && RoofSet.Roof[iSide].Planes.Count)
			iPlane = (nextPlane + RoofSet.Roof[iSide].Planes.Count) % RoofSet.Roof[iSide].Planes.Count;
		else
			iPlane = -1;

		lbSlopeIndex->Caption = IntToStr(iPlane);

	/*	if (iSide != -1)
			Roof[iSide].Cut->Flags.Intersect = gfTRUE;*/

		if (iSide != -1 && iPlane != -1)
			lbSlopeNumber->Caption = IntToStr(RoofSet.Roof[iSide].Planes.Count);
		else
			lbSlopeNumber->Caption = IntToStr(-1);

		if (iPlane == 0)
			edSlopeLevel->Enabled = false;
		else
			edSlopeLevel->Enabled = true;

		if (iSide == -1)
			return;
		if (iPlane == -1)
			return;
		edSlopeAngle->Text = FloatToStr(RoofSet.Roof[iSide].Planes[iPlane].Angle);
		edSlopeLevel->Text = FloatToStr(RoofSet.Roof[iSide].Planes[iPlane].Height);
		cbSlopeFront->Checked = RoofSet.Roof[iSide].Planes[iPlane].Front;
	} else if (iSide != -1 )
	{
		RoofSet.Roof[iSide].templ->setToForm(RoofSet.Roof[iSide].templParams);
		PageControl1->ActivePageIndex = Templates.IndexOf(RoofSet.Roof[iSide].templ);
	}
}
//---------------------------------------------------------------------------
__fastcall TRoofForm::TRoofForm(TComponent* Owner)
	: TForm(Owner)
{
	TElementViewer1 = new TElementViewer(Panel1);
	TElementViewer1->Parent = Panel1;
	TElementViewer1->Left = 8;
	TElementViewer1->Top = 95;
	TElementViewer1->Width = 289;
	TElementViewer1->Height = 320;
	TElementViewer1->Visible = true;
//	initTemplates();
}
//---------------------------------------------------------------------------

void apply(TElement *Element);
void TRoofForm::EditRoof(TElement *el)
{
	el->SetAttributeValue("edit_mode", "1");
	TElementViewer1->ShowElement = el;
	LoadRoofSet(*el, RoofSet, el->HP->Vertex->Count);
	cbWalls->Checked = RoofSet.walls_create;
	UpdateSide(0, 0);
	apply(TElementViewer1->ShowElement);
	BeforeEditSet = RoofSet;
}


void EditRoof(TElement *el)
{
	RoofForm = new TRoofForm(Config);
//	ApplySkinTheme(RoofForm);
	RoofForm->EditRoof(el);
	RoofForm->ShowModal();
	delete RoofForm;
}

void __fastcall TRoofForm::edWallPrevClick(TObject *Sender)
{
	SaveSide();
	UpdateSide(iSide - 1, iPlane);
	update((TMultiElement *)TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::edWallNextClick(TObject *Sender)
{
	SaveSide();
	UpdateSide(iSide + 1, iPlane);
	update((TMultiElement *)TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::edSlopePrevClick(TObject *Sender)
{
	SaveSide();
	UpdateSide(iSide, iPlane - 1);
	update((TMultiElement *)TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::edSlopeNextClick(TObject *Sender)
{
	SaveSide();
	UpdateSide(iSide, iPlane + 1);
	update((TMultiElement *)TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::Button9Click(TObject *Sender)
{
	if (iSide == -1)
		return;
	RoofSet.Roof[iSide].Planes.Add(new TRoofPlane);

	for (int i=0;i<RoofSet.Roof[iSide].Planes.Count;i++)
	{
		RoofSet.Roof[iSide].Planes[i].Angle	= ((MBTi)RoofSet.Roof[iSide].Planes.Count-(MBTi)i)*(90.0/((MBTi)RoofSet.Roof[iSide].Planes.Count+1));
		RoofSet.Roof[iSide].Planes[i].Height	= (MBTi)i*(1.0/((MBTi)RoofSet.Roof[iSide].Planes.Count+1));
		RoofSet.Roof[iSide].Planes[i].Front	= false;
	 }

	UpdateSide(iSide, iPlane);
}
//---------------------------------------------------------------------------
class TIndices
{
public:
	int plane;
	int slope;
	TIndices(int plane = -1, int slope = -1)
	{
		this->plane = plane;
		this->slope = slope;
	}
};

void update(TMultiElement *Element)
{
	Element->SetAttributeValue("wall_index", IntToStr(iSide).c_str());
	Element->SetAttributeValue("plane_index", IntToStr(iPlane).c_str());

	TMetaMaterial *WallMat = (TMetaMaterial *)(MetaNodeCollection->FindMDByGUID("0273"));
	TMetaMaterial *GreenWallMat = (TMetaMaterial *)(MetaNodeCollection->FindMDByGUID("0260"));


	TMDelTList <TIndices> indices;
	TLuaAttributeList& INDICES =  GetAttributes (*Element->GetAttribute("indices"));

	for (int i=0;i<INDICES.AttributeICount;i++)
	{
		TLuaAttributeList& AttributeI =  GetAttributes (*INDICES.GetAttributeI(i));
		indices.Add( new TIndices(
				StrToInt(AttributeI.GetAttribute("plane")->VALUE),
				StrToInt(AttributeI.GetAttribute("slope")->VALUE)) );
	}


	const int IND_WALL	= 7;
	const int IND_COVER	= 0;

	for (int i=0;i<Element->CountOf(IND_WALL);i++)
	{
		TElement *WALL = Element->GetPart(IND_WALL,i);
		if (i == iSide)
		{
			WALL->GetRenderParam(0)->Material = GreenWallMat;
			WALL->GetRenderParam(1)->Material = GreenWallMat;
		} else
		{
			WALL->GetRenderParam(0)->Material = WallMat;
			WALL->GetRenderParam(1)->Material = WallMat;
		}
		WALL->RegisterTexturing();
	}

	if (!RoofSet.Roof[iSide].templ)
	{
//        TGeomObject* GO = (TGeomObject*)(Element->GetAttribute("geometry")->Value);
/*
    for i=0, NEW_HP.Vertex.Count-1 do
        for j=0, table.getn(Set[indices[i]].Plane) do
            if ((Set[indices[i] ].Plane[j].fronton == 0) and GO:GetPolygon(indx).Tag ~= 255) then
                local El = Element:AddOnly(IND_COVER); --добавили
*/
//        for ( int i = 0; i < Element->HP->Vertex->Count; i++ ) {
  //      }
		Element->SetAttributeValue("select", IntToStr(RoofSet.Roof[iSide].templ != NULL).c_str());
		for (int i=0; i<Element->CountOf(IND_COVER);i++)
		{
			TElement *COVER = Element->GetPart(IND_COVER, i);
			if (indices[i].plane == iPlane && indices[i].slope == iSide)
			{
				for (int l=0;l<COVER->RenderParamCount;l++)
					COVER->GetRenderParam(l)->Material = GreenWallMat;
			} else
			{
				for (int l=0;l<COVER->RenderParamCount;l++)
					COVER->GetRenderParam(l)->Material = WallMat;
			}
			COVER->RegisterTexturing();
		}
	} else
	{
		Element->SetAttributeValue("select", IntToStr(RoofSet.Roof[iSide].templ != NULL).c_str());
		for (int i=0; i<Element->CountOf(IND_COVER);i++)
		{
			TElement *COVER = Element->GetPart(IND_COVER, i);
			if (indices[i].slope == iSide)
			{
				for (int l=0;l<COVER->RenderParamCount;l++)
					COVER->GetRenderParam(l)->Material = GreenWallMat;
			} else
			{
				for (int l=0;l<COVER->RenderParamCount;l++)
					COVER->GetRenderParam(l)->Material = WallMat;
			}
			COVER->RegisterTexturing();
		}
	}
}

void apply(TElement *Element)
{
		Element->SetAttributeValue("wall_index", IntToStr(iSide).c_str());
		Element->SetAttributeValue("plane_index", IntToStr(iPlane).c_str());

		RoofForm->SaveSide();
		RoofSet.walls_create  = RoofForm->cbWalls->Checked;
		RoofSet.cover   = RoofForm->cbCover->Checked;
		RoofSet.obresh  = RoofForm->cbConstruction->Checked;
		SaveRoofSet(*Element, RoofSet, Element->HP->Vertex->Count);
		Element->GetAttribute("geometry")->Value = NULL;

		Element->RegisterCreateView();

//		Element:SetAttributeValue("select",((Set[curSide].template~=nil) and 1) or 0);
/*
--        SetToFronton(curSide, curPlane)
--        if (tg_around.value == IUP_ON) then assign_around();end;
--        Set[curSide].template = nil;

		SaveRoofSet(Element, Set);
--        if (roof_has_changed) == 1  then
--            undo_index = undo_index + 1;
--            UndoSet[undo_index] = {};
--            table.assign(UndoSet[undo_index], Set);
	--        for i = undo_index+1, table.getn(UndoSet) do
--                UndoSet[i] = nil;
--            end;
--            bt_undo.active = IUP_YES;
--            bt_redo.active = IUP_NO;
--            Element:GetAttribute("geometry").Value = nil;
--        end;
		Element:CreateView();
		roof_has_changed = 0;
		return true;*/
}


void __fastcall TRoofForm::Button2Click(TObject *Sender)
{
	apply(TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::Button8Click(TObject *Sender)
{
	if (iSide == -1)
		return;

	if (RoofSet.Roof[iSide].Planes.Count>1)
		RoofSet.Roof[iSide].Planes.Delete(0);

	for (int i=0;i<RoofSet.Roof[iSide].Planes.Count;i++)
	{
		RoofSet.Roof[iSide].Planes[i].Angle	= ((MBTi)RoofSet.Roof[iSide].Planes.Count-(MBTi)i)*(90.0/((MBTi)RoofSet.Roof[iSide].Planes.Count+1));
		RoofSet.Roof[iSide].Planes[i].Height	= (MBTi)i*(1.0/((MBTi)RoofSet.Roof[iSide].Planes.Count+1));
		RoofSet.Roof[iSide].Planes[i].Front	= false;
	 }

	UpdateSide(iSide, iPlane);
}
//---------------------------------------------------------------------------

void __fastcall TRoofForm::Button1Click(TObject *Sender)
{
	TElementViewer1->ShowElement->SetAttributeValue("edit_mode", "0");
	apply(TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------


void __fastcall TRoofForm::TabSheet7ContextPopup(TObject *Sender,
	  TPoint &MousePos, bool &Handled)
{
	applyTemplate(NULL);
}
//---------------------------------------------------------------------------


void __fastcall TRoofForm::PageControl1Change(TObject *Sender)
{
	if (PageControl1->ActivePageIndex != 6 )
		applyTemplate(Templates.Items[PageControl1->ActivePageIndex]);
	else
		applyTemplate(NULL);
}
//---------------------------------------------------------------------------

/*








*/
//---------------------------------------------------------------------------


void __fastcall TRoofForm::Button3Click(TObject *Sender)
{
	TElementViewer1->ShowElement->SetAttributeValue("edit_mode", "0");
	RoofSet = BeforeEditSet;
	UpdateSide(iSide, iPlane);
	apply(TElementViewer1->ShowElement);
}
//---------------------------------------------------------------------------
