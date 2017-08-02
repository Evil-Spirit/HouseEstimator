//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "ConverterV.h"
#include "xmldom.hpp"

//---------------------------------------------------------------------------
const AnsiString ml_apply = "apply";
const AnsiString ml_id = "id";
const AnsiString ml_real = "real";
const AnsiString ml_parens = "parens";

//двух местные функции
const AnsiString ml_plus = "plus";
const AnsiString ml_minus = "minus";
const AnsiString ml_mult = "mult";
const AnsiString ml_indexer = "indexer";
const AnsiString ml_pow = "pow";
const AnsiString ml_neg = "neg";

const int tsOPENED = 1;
const int tsCLOSED = -1;
const int tsOPERATION = 0;

int AnsiPos(const AnsiString& Str,char chr,int Start)
{
	for (int i=Start;i <= Str.Length();i++)
    	if ( Str[i] == chr )
        	return i;
	return 0;            
}

AnsiString OperationFor(const AnsiString& tag)
{
	if (tag == ml_plus)
    	return " + ";
	if (tag == ml_minus)
    	return " - ";
	if (tag == ml_mult)
    	return "*";
	if (tag == ml_indexer)
    	return "_i_";
	if (tag == ml_pow)
    	return "_";
	if (tag == ml_neg)
    	return "- ";
    throw Exception(AnsiString("<OperationFor>: Unknown operation!! - "+tag));
}

AnsiString Read_Tag(const AnsiString& MathML,int& index)
{
	int start_index = AnsiPos(MathML,'<',index);
	if ( start_index == 0 )
    	throw Exception("Read_Tag: error");
	int end_index = AnsiPos(MathML,'>',start_index);
    if (end_index == 0)
    	throw Exception("Read_Tag: error");

	index = end_index + 1;
    return MathML.SubString(start_index+1,end_index-1 - (start_index+1) + 1).Trim();
}

AnsiString Read_BeforeTag(const AnsiString& MathML,int& index)
{
	int start_index = index;
	int end_index = AnsiPos(MathML,'<',start_index);
    if (end_index == 0)
    	throw Exception("Read_Tag: error");
	index = end_index;
    return MathML.SubString(start_index,end_index-1 - start_index + 1).Trim();
}

int TagStatus(const AnsiString& Tag)
{
    if (Tag[1] == '/')
    	return tsCLOSED;
    else if ( Tag[Tag.Length()] == '/')
    	return tsOPERATION;
    else
    	return tsOPENED;
}

void ClearTag(AnsiString& Tag)
{
	Tag = ExtractLocalName(Tag);
    int Space_Pos = Tag.Pos(" ");
    if ( Space_Pos!=0 )
	    Tag.Delete(Space_Pos,Tag.Length()-Space_Pos+1);
	if (Tag[1] == '/' )
    	Tag.Delete(1,1);
	if (Tag[Tag.Length()] == '/' )
    	Tag.Delete(Tag.Length(),1);
}

int NextTagStatus(const AnsiString& MathML,int& index)
{
	int SaveIndex = index;
    AnsiString _tag = Read_Tag(MathML,index);
    index = SaveIndex;
    return TagStatus(_tag);
}

void RecurrentEnumerate(const AnsiString& MathML,AnsiString& Input,int& index)
{
	if ( NextTagStatus(MathML,index) != tsOPERATION )
    	throw Exception("RecurrentProcessNode: error");
    AnsiString _tag = Read_Tag(MathML,index);
    ClearTag(_tag);
    AnsiString operation = OperationFor(_tag);

	if ( _tag == ml_neg )
    {
        //одно местная функция
		Input+=operation;
        RecurrentProcessNode(MathML,Input,index);
    }
    else
    {
        //двух местная функция
        RecurrentProcessNode(MathML,Input,index);
/*        if (_tag == ml_indexer )
            Input+="[";
        else*/
		Input+=operation;
        RecurrentProcessNode(MathML,Input,index);
//        if (_tag == ml_indexer )
  //          Input+="]";
    }
}

void RecurrentProcessNode(const AnsiString& MathML,AnsiString& Input,int& index)
{
	if ( NextTagStatus(MathML,index) != tsOPENED )
    	throw Exception("RecurrentProcessNode: error");
    AnsiString _tag = Read_Tag(MathML,index);
    ClearTag(_tag);
    if (_tag == ml_parens)
	   	Input+="(";
    if (_tag == ml_id || _tag == ml_real)
    {
    	Input += Read_BeforeTag(MathML,index);
	    Read_Tag(MathML,index);
        return;
    }
	while ( NextTagStatus(MathML,index) != tsCLOSED )
    {
    	if ( NextTagStatus(MathML,index) == tsOPERATION )
          	RecurrentEnumerate(MathML,Input,index);
        if (NextTagStatus(MathML,index) == tsOPENED)
        	RecurrentProcessNode(MathML,Input,index);
    }
    if (_tag == ml_parens)
	   	Input+=")";
    Read_Tag(MathML,index);
}

bool Convert(const AnsiString& aMathML,AnsiString& Input)
{
	AnsiString MathML = aMathML;
	for (int i=1;i<=MathML.Length();i++)
    	if ( MathML[i]=='\t' || MathML[i]=='\r' || MathML[i]=='\n')
        	MathML.Delete(i--,1);
	int index=1;
	RecurrentProcessNode(MathML,Input,index);
    return true;
}

#pragma package(smart_init)
 