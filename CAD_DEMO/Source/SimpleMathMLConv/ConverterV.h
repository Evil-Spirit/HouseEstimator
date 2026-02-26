// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ConverterVH
#define ConverterVH
//---------------------------------------------------------------------------
bool Convert(const AnsiString& MathML,AnsiString& Input);
void RecurrentProcessNode(const AnsiString& MathML,AnsiString& Input,int& index);
void RecurrentEnumerate(const AnsiString& MathML,AnsiString& Input,int& index);

#endif
 