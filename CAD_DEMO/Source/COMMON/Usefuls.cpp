//---------------------------------------------------------------------------
//#pragma option -zRSegment1

#include <vcl.h>
#include "MTL.h"
#include "Usefuls.h"
#include <windows.h>
#include <ComObj.hpp>
#include "MyTemplates.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#include "math.h"
#include "QuckList.h"
#include "mbstring.h"

#include "MDIVectorEditV.h"
#include "MDIBoolVectorEditV.h"
#include "MDISignVectorEditV.h"
#include "LuaAttributeV.h"
#pragma package(smart_init)

TClassNode* TMyObject::StaticType = NULL;
TClassNode* TMyRegObject::StaticType = NULL;

TClassNode* fClassHead = NULL;
TGarbage* fGarbage = NULL;
AnsiString MainDir = AnsiString();
AnsiString DataDir = AnsiString();

int MyStrCompare(const AnsiString& Str1,const AnsiString& Str2)
{
    return _mbscmp(Str1.c_str(),Str2.c_str());
}

void RegisterUsefuls()
{
    //register class TMyRegObject
    TMyRegObject();
    //--------------------------
    fGarbage = new TGarbage();
    MainDir = GetCurrentDir();
    DataDir = MainDir + SL + DataDirName;
}
#pragma startup RegisterUsefuls 64

void UnRegisterUsefuls()
{
    delete fGarbage;
    delete fClassHead;
}
#pragma exit UnRegisterUsefuls 64


__fastcall EMyException::EMyException(const AnsiString& _Error_Text)
    :Exception(_Error_Text)
{
};    


TMyObject* FindByGUID(TClassNode* CN,const AnsiString& aGUID)
{
    return CN->RecurrentFindByGUID(aGUID);
}

TMyObject* FindByGUID(const AnsiString& aGUID)
{
    return ClassHead->RecurrentFindByGUID(aGUID);
}

TMyObject *Create_Default_Constructor(const AnsiString& ClassType)
{
    if (!ClassHead)
        return NULL;
    TClassNode* CN = ClassHead->Find(ClassType);
    if (!CN)
    {
        AnsiString Str = AnsiString("Class <");
        Str = Str + ClassType;
        Str = Str + AnsiString("> is not registered.");
        throw EMyException(Str);
    }
    ////----------------------------------------
    TMyObject *MN = CN->CreateFunction();
    ////----------------------------------------

    if (MN==NULL)
    {
        Application->MessageBoxA("Error","Can not retrieve object",MB_OK);
        Application->Terminate();
    }
    return(MN);
}

TMyObject* LuaCreateLocal(const AnsiString& ClassName)
{
    return Create_Default_Constructor(ClassName);
}

TMyObject* LuaCreate(const AnsiString& ClassName)
{
    return Create_Default_Constructor(ClassName);
}


void CutDigits(AnsiString & Word)
{
    while(DIGITS.Pos(Word[Word.Length()])!=0)
        Word.Delete(Word.Length(),1);
}

bool CHECK_FILE_LOAD(const AnsiString& FileName)
{
    return FileExists(FileName);
}

bool CHECK_FILE_SAVE(const AnsiString& FileName)
{
    if (!FileExists(FileName))
        return true;
    int attr = FileGetAttr(FileName);
    if (attr & faReadOnly)
        FileSetAttr(FileName,attr & !faReadOnly);
    return !(FileGetAttr(FileName) & faReadOnly);
}

AnsiString ValidateFileName_Dir_Ext(const AnsiString& _Name,const AnsiString& Path,const AnsiString& Ext )
{
    AnsiString NewName = _Name;
    int i=1;
    do{
        CutDigits(NewName);
        NewName = NewName + IntToStr(i);
        i++;
    }while ( FileExists(Path + SL + NewName + Ext) );
    return(NewName);
}

bool IS(TObject * Obj,TClass Class)
{
    return (Obj->ClassType() == Class) || (Obj->InheritsFrom(Class));
}


bool ElseExists(TObject *Object)
{
    TQuickList *L = new TQuickList();
    SelectComponents(Object->ClassType(),L,Application);
    bool _exists = false;
    for (int i=0;i<L->Count;i++)
        if (L->Items[i] != Object)
        {
            _exists = true;
            break;
        }
    delete L;
    return _exists;
}


TComponent *ComponentExists(const TClass& _Class,TComponent *Component)
{
    if (IS(Component,_Class))
        return(Component);
    for (int i = 0;i<Component->ComponentCount;i++)
    {
        TComponent *C = ComponentExists( _Class, Component->Components[i]);
        if (C!=NULL)
            return(C);
    }
    return(NULL);
}

void SelectComponents(const TClass& _Class,TQuickList* CMP,TComponent *Component)
{
    if (IS(Component,_Class))
        CMP->Add(Component);
    for (int i = 0;i<Component->ComponentCount;i++)
        SelectComponents(_Class,CMP,Component->Components[i]);
}

TWinControl *FindActiveWinControl(const TClass& _Class,TWinControl *WinControl)
{
    TQuickList *L = new TQuickList();
    SelectComponents(_Class,L);
    TWinControl *WC = NULL;
    for (int i=0;i<L->Count;i++)
    {
        if ( UnderFocuse((TWinControl *)L->Items[i]) )
        {
            WC = (TWinControl *)L->Items[i];
            break;
        }
    }
    delete L;
    return WC;
}

bool UnderFocuse(TWinControl *WC)
{
    if (!WC)
        return false;
    if (WC->Handle == GetFocus())
        return true;
    else
        return UnderFocuse(WC->Parent);
}

bool TMyObject::Is(const TClassNode* ClassNode) const
{
    return DynamicType->is(ClassNode);
}

void TMyObject::SetName(const AnsiString& Name)
{
    FName = Name;
    if ( RegisterInfo )
    {
        TClassNode* UniqueNode = DynamicType->UniqueNameNode;
        if (UniqueNode)
            UniqueNode->ValidateObjectName(this);
    }
}

TMyObject* TMyObject::CreateFunction()
{
    return new TMyObject();
}

void TMyObject::KillFunction()
{
    delete this;
}

void TMyObject::RecurrentLookingTo(TMyObject * Target,TMTList<TMyObject>& OBJL) const
{
    for (int i=0;i<FAS->Count;i++)
        if (GetFieldType(i)==mtMyObject)
            ((TMyObject *)GetFieldAddress(i))->RecurrentLookingTo(Target,OBJL);
    LookingTo(Target,OBJL);
}

bool TMyObject::LuaCompareAddress(const TMyObject* Obj) const
{
    return (this == Obj);
}

const AnsiString& TMyObject::GetGUID()
{
    return FGUID;
}

void TMyObject::GenerateGUIDIfNeed()
{
    if (!RegisterInfo)
    {
        if (FGUID.IsEmpty())
            GenerateGUID();
        DynamicType->RegisterNewInstance(this);
    }
}

void TMyObject::GenerateGUID()
{
    FGUID = CreateClassID().LowerCase();
    FGUID.Delete(1,1);
    FGUID.Delete(FGUID.Length(),1);
}

void TMyObject::SetMyObjectParent(TMyObject* aMyObjectParent)
{
/*    if (MyGlobalParent && FMyObjectParent == MyGlobalParent)
        MyGlobalParent->UnRegisterField(this);*/

    FMyObjectParent = aMyObjectParent;

/*    if ( FGUID.IsEmpty() )
    {
        if ( FMyObjectParent == MyGlobalParent )
            FMyObjectParent = NULL;
    }
    else
    {
        if ( FMyObjectParent == NULL )
            FMyObjectParent = MyGlobalParent;
    }

    if (MyGlobalParent && FMyObjectParent == MyGlobalParent)
        MyGlobalParent->RegisterField(this,NULL,mtMyObject); */
}

TMyObject::TMyObject()
{
    RegisterNewClass<TMyObject,TMyObject >(this,false,&CreateFunction);
    FAS = new TQuickList();
    FMyObjectParent = NULL;
    FRegisterInfo = NULL;
}

void TMyObject::AboutToChange(void* Field)
{
    _TRY_

    if (MyObjectParent)
        MyObjectParent->AboutToChange(this);

    _ENDTRY_("<TMyObject::AboutToChange>: Parent was destroyed before child",);
}

void TMyObject::Changed(void* Field)
{
    _TRY_

    if (MyObjectParent)
        MyObjectParent->Changed(this);

    _ENDTRY_("<TMyObject::Changed>: Parent was destroyed before child",);
}


TMyObject::~TMyObject()
{
    if (MyObjectParent && MyObjectParent->Is(TBaseContainer::StaticType) &&
        MyObjectParent->DynamicType->Parent->Parent == TBaseContainer::StaticType )
        {
            AnsiString Str = AnsiString("Deleting object <")+DynamicType->Name;
            Str += AnsiString("> registered in container <")+MyObjectParent->DynamicType->Name+AnsiString(">");
            throw EMyException(Str);
        }
    if (RegisterInfo)
        DynamicType->UnRegisterInstance(this);        
/*    if (MyObjectParent && MyObjectParent==MyGlobalParent )
    {
        MyGlobalParent->UnRegisterField(this);
    }*/
    KillList<TFieldTrio>(FAS);
    delete FAS;
}

void TMyObject::SetCharDescription(char *newDescription)
{
    Description = AnsiString(newDescription);
}

bool TMyObject::operator == (const TMyObject &Obj) const
{
  throw EMyException("Can't compare instances of class TMyObject");
//  return false;
}

const AnsiString aGUID = AnsiString("GUID");
#ifndef GetOldBase
const AnsiString aID = AnsiString("ID");
const AnsiString aTable = AnsiString("Table");
#endif
const AnsiString aName = AnsiString("Name");

void TMyObject::Assign(TMyObject* MO)
{
    TStringList* SKIP = new TStringList();
    if ( Is( TMyRegObject::StaticType ) )
    {
        if (SKIP->IndexOf(aID)==-1)
            SKIP->Add(aID);
        if (SKIP->IndexOf(aName)==-1)
            SKIP->Add(aName);
        if (SKIP->IndexOf(aTable)==-1)
            SKIP->Add(aTable);
    }
    if (SKIP->IndexOf(aGUID)==-1)
        SKIP->Add(aGUID);
    AssignLST(MO,SKIP);
    delete SKIP;
}

void TMyObject::AssignLST(const TMyObject *Obj,TStringList *SKIP)
{
    if ( !Obj->Is( DynamicType ) )
    {
        AnsiString STR = AnsiString("Can not assign ");
        STR = STR + AnsiString( typeid(*Obj).name() )+AnsiString(" to ") + AnsiString(typeid(*this).name());
        throw EMyException( STR );
    }
    const AnsiString* _Name;
    for (int i=0;i<FAS->Count;i++)
    {
        _Name = GetFieldName(i);
        if (SKIP->IndexOf(*_Name)!=-1)
            continue;
        void *OurAddr = GetFieldAddress(i);
        void *ADR = Obj->GetFieldAddress(*_Name);
        if (ADR)
            if (GetFieldType(i) == Obj->GetFieldType(*_Name))
            {
                if (GetFieldType(i) == mtMyObject)
                    ((TMyObject*)OurAddr)->Assign((TMyObject*)ADR);
                else
                    CopyType(GetFieldType(i),OurAddr,ADR);
            }
    }
}

//---------------------Функции Регистрации---------------------------
//--------------------------------------------------------------------------
int IterateByName(TQuickList *QL,const AnsiString& Name)
{
    for (int i=0;i<QL->Count;i++)
        if ( (*((TFieldTrio*)QL->Items[i])->Name) == Name )
            return i;
    return -1;
}

int IterateByAdr(TQuickList *QL,void *ADR)
{
    for (int i=0;i<QL->Count;i++)
        if ( ((TFieldTrio*)QL->Items[i])->Address == ADR )
            return i;
    return -1;
}

void TMyObject::RegisterField(void *FA,const AnsiString *FN,int FT)
{
    TFieldTrio* FIELDTRIO;
    FIELDTRIO = new TFieldTrio();
    FIELDTRIO->Address = FA;
    FIELDTRIO->Name = FN;
    FIELDTRIO->Type = FT;
    FAS->Add(FIELDTRIO);
    if (FT == mtMyObject)
        ((TMyObject*)FA)->MyObjectParent = this;
    else if (FT == mtIntVec)
        ((TIntVec*)FA)->MyObjectParent = this;
}

void TMyObject::UnRegisterField(int i)
{
    TFieldTrio* FIELDTRIO;

    FIELDTRIO = (TFieldTrio*)FAS->Items[i];
    if (FIELDTRIO->Type == mtMyObject)
        ((TMyObject*)FIELDTRIO->Address)->MyObjectParent = NULL;
    else if (FIELDTRIO->Type == mtIntVec)
        ((TIntVec*)FIELDTRIO->Address)->MyObjectParent = NULL;
    delete FIELDTRIO;
    FAS->Delete(i);
}

void TMyObject::UnRegisterField(void *FA)
{
    int index = IterateByAdr(FAS,FA);
    UnRegisterField(index);
}

int TMyObject::GetFieldCount() const
{
    return(FAS->Count);
}

void TMyObject::SetFieldDirectly(const AnsiString &FN,void *Value )
{
    TMyObject::SetField(  FN, Value );
}

int TMyObject::GetFieldType(int index) const
{
    return  ((TFieldTrio*)FAS->Items[index])->Type;
}

const AnsiString* TMyObject::GetFieldName(int index) const
{
    return  ((TFieldTrio*)FAS->Items[index])->Name;
}

void *TMyObject::GetFieldAddress(int index) const
{
    return  ((TFieldTrio*)FAS->Items[index])->Address;
}

int TMyObject::GetFieldIndex(const AnsiString &FN) const
{
    return IterateByName(FAS,FN);
}

const AnsiString* TMyObject::GetFieldName(void *Address) const
{
    return( GetFieldName( IterateByAdr(FAS,Address) ) );
}

int TMyObject::GetFieldType(const AnsiString& FN) const
{
    return( GetFieldType( IterateByName(FAS,FN) ) );
}

AnsiString TMyObject::GetExcelStrField(int index) const
{
    AnsiString STR;
    int type = GetFieldType(index);
    if (type == mtFloat)
        return FloatToStr( *((float*)GetFieldAddress(index)) );
    else if (type == mtDouble)
        return FloatToStr( *((double*)GetFieldAddress(index)) );
    else
        return TYPETOSTR(GetFieldAddress(index),type);
}

void TMyObject::SetField(const AnsiString &FN,void *Value )
{
    int ind=GetFieldIndex(FN);
    CopyType(GetFieldType(ind),GetFieldAddress(ind),Value);
}

void *TMyObject::GetFieldAddress(const AnsiString &FN) const
{
    return( GetFieldAddress(IterateByName(FAS,FN)) );
}

bool TMyObject::RecurrentCheck()
{
    for (int i=0;i<FAS->Count;i++)
        if (GetFieldType(i)==mtMyObject)
            if (((TMyObject *)GetFieldAddress(i))->RecurrentCheck()==false)
                return(false);
    return(CheckFields());
}

int TMyObject::GetDepth() const
{
    return (MyObjectParent)? MyObjectParent->GetDepth()+1 : 0;
}

void TMyObject::Read(const AnsiString& DataName)
{
    if (FileExists(DataName))
    {
        int attr = FileGetAttr(DataName);
        if (attr & faReadOnly)
            FileSetAttr(DataName,attr & !faReadOnly);
    }
    TMemoryStream* MS = new TMemoryStream();
    MS->LoadFromFile(DataName);
    ReadData(MS);
    delete MS;
}

void TMyObject::Write(const AnsiString& DataName) const
{
    TMemoryStream* MS = new TMemoryStream();
    WriteData(MS);
    MS->SaveToFile(DataName);
    delete MS;
}

void TMyObject::Save(const AnsiString& DataName ) const
{
    FILE *F;
    if (FileExists(DataName))
    {
        int attr = FileGetAttr(DataName);
        if (attr & faReadOnly)
            FileSetAttr(DataName,attr & !faReadOnly);
    }
    F = fopen(DataName.c_str(),"w");

    SaveData(F);
    fclose(F);
}


void TMyObject::Load( const AnsiString& DataName  )
{
    FILE *F;

    F = fopen(DataName.c_str(),"r");

    LoadData(F);
    fclose(F);
}

void ReplaceSymbol(AnsiString& STR,char Replaced,char Replacer)
{
    int Length = STR.Length();
    for (int i=1;i<=Length;i++)
        if (STR[i]==Replaced)
        STR[i] = Replacer;
}

bool Replace(AnsiString& Str, const AnsiString& Replaced, const AnsiString& Replacer)
{
    int pos=Str.Pos(AnsiString(Replaced));
    if (pos!=0)
    {
        Str.Insert(Replacer,pos);
        Str.Delete(pos+Replacer.Length(),Replaced.Length());
    }
    return (pos!=0);
}

void ReplaceAll(AnsiString& Str, const AnsiString& Replaced, const AnsiString& Replacer)
{
    while (Replace(Str,Replaced,Replacer));
}

void SaveString(const AnsiString& TABS,const AnsiString& Str0,FILE *F)
{
    const AnsiString& Str = Str0;
//    ReplaceAll(Str,"\n",ENDOFLINE);
//    ReplaceAll(Str," ",MYSPACE);
//    ReplaceAll(Str,"\t",MYTAB);
    int i=1;
    while (i<=Str.Length())
    {
        fputs(TABS.c_str(),F);
        for (int j=i;j<=MIN( STR_LINE_LENGTH_WRITE +i,Str.Length());j++)
            if (Str[j] == '\n')
                putc('@',F);
            else if (Str[j] == '\t')
                putc('#',F);
            else if (Str[j] == '@')
                putc('_',F);
            else if (Str[j] == '#')
                putc('_',F);
            else
                putc(Str[j],F);
        i = MIN(STR_LINE_LENGTH_WRITE + i,Str.Length()) +1;
        fputs("\n",F);
    }
    fputs(TABS.c_str(),F);
    fputs(ENDOFSTR.c_str(),F);
    fputs("\n",F);
}

void LoadString(AnsiString& Str,FILE *F)
{
    char str[STR_LINE_LENGTH_READ];
    Str=AnsiString();
    AnsiString CurStr;
    do
    {
        fgets(str,STR_LINE_LENGTH_READ,F);
        CurStr = AnsiString(str);
        if (CurStr[CurStr.Length()]=='\n')
            CurStr.Delete(CurStr.Length(),1);
        while (CurStr.Length()>0 && CurStr[1] == '\t')
            CurStr.Delete(1,1);
        Str += CurStr;
    }
    while (CurStr.Pos(ENDOFSTR)==0);
    Str.Delete(Str.Length()-ENDOFSTR.Length()+1,ENDOFSTR.Length());
    int Length = Str.Length();
    for (int i=1;i<=Length;i++)
        if (Str[i]=='@')
            Str[i]='\n';
        else if (Str[i]=='#')
            Str[i]='\t';
/*    Replace(Str,ENDOFSTR,AnsiString());
    ReplaceAll(Str,ENDOFLINE,"\n");
    ReplaceAll(Str,MYSPACE," ");
    ReplaceAll(Str,MYTAB,"\t");*/
}

int SizeOfType(const void* Data,int type,int& sdvig)
{
  if (type == mtIntVec)
      sdvig = (unsigned int)(&(((TIntVec*)Data)->x)) - (unsigned int)(Data);
  else
      sdvig = 0;
      
  switch (type)
  {
    case mtInt:
      return sizeof(int);
    case mtDouble:
      return sizeof(double);
    case mtFloat:
      return sizeof(float);
    case mtString:
      return ((AnsiString *)Data)->Length();
    case mtIntVec:
      return sizeof(MBTi)*3;
    case mtBool:
      return sizeof(bool);
    case mtBoolVec:
      return sizeof(bool)*3;
    case mtSignVec:
      return sizeof(MBTi)*3;
    case mtRect:
      return sizeof(TMBTRect);
  }
  throw EMyException("Incorrect type for changing size");
}

void TMyObject::WriteOne(const void * Data,int type,TMemoryStream *MS) const
{
  MS->Write(&type,sizeof(int));
  if (type == mtString)
  {
    int size =  ((AnsiString *)Data)->Length();
    MS->Write(&size,sizeof(int));
    MS->Write(((AnsiString *)Data)->c_str(),size);
  }
  else
  {
    int sdvig = 0;
    int size = SizeOfType(Data,type,sdvig);
    void* Data2 = (void*)((unsigned int)Data + (unsigned int)sdvig);
    MS->Write(Data2,size);
  }
}

/*void CodeString(AnsiString& str)
{
    int Length = str.Length();
    for (int i=1;i<=Length;i++)

} */

void Read_One_Exactly(void * Data,int type,TMemoryStream *MS)
{
  if (type == mtString)
  {
    int size;
    MS->Read(&size,sizeof(int));
    ((AnsiString*)Data)->SetLength(size);
    MS->Read( ((AnsiString*)Data)->c_str(),size);

    /*
    int size;
    MS->Read(&size,sizeof(int));
    char *str = new char[size+1];
    *(str)=0;
    MS->Read( str,size);
    *((AnsiString*)Data) = AnsiString(str).Trim();
    ((AnsiString*)Data)->SetLength(size);
    delete [] str;
    */
  }
  else
  {
    int sdvig = 0;
    int size = SizeOfType(Data,type,sdvig);
    void* Data2 = (void*)((unsigned int)Data + (unsigned int)sdvig);
    MS->Read( Data2,size);
  }
}

/*void CloseObject(FILE *F)
{
    TStringList *A = new TStringList();
    char str[STR_LINE_LENGTH_READ];
    do{
        fgets(str,STR_LINE_LENGTH_READ,F);
        A->CommaText=AnsiString(str).Trim();
        if (A->Count>1 && ((int) (A->Strings[1].ToInt()))==mtMyObject )
            CloseObject(F);
    }while(AnsiString(str).Trim() != MYEND );
    delete A;
}*/


void Close_Field_Exactly(int type,TMemoryStream *MS)
{
  if (type == mtString)
  {
    int size;
    MS->Read(&size,sizeof(int));
    MS->Position = MS->Position+size;
  }
  else
  {
    int sdvig = 0;
    int size = SizeOfType(NULL,type,sdvig);
    MS->Position = MS->Position + size;
  }
}

void Close_Field(TMemoryStream *MS)
{
  int load_type;
  MS->Read(&load_type,sizeof(int));
  Close_Field_Exactly(load_type,MS);
}

int TMyObject::ReadOne(  void * Data,int type,TMemoryStream *MS)
{
  int load_type;
  MS->Read(&load_type,sizeof(int));
  if (load_type!=type)
  {
    MS->Position = MS->Position - sizeof(int);
    return load_type;
  }
  Read_One_Exactly( Data,type,MS);
  return -1;
}


void TMyObject::WriteData(TMemoryStream *MS) const
{
  int MT;
  AnsiString _Name;
  for (int i=0;i<GetFieldCount();i++)
  {
    MT = GetFieldType(i);
    _Name =*(GetFieldName(i));
    WriteOne(&_Name,mtString,MS);
    WriteOne(&MT,mtInt,MS);
    if (MT == mtMyObject)
      ((TMyObject *)GetFieldAddress(i))->WriteData(MS);
    else
      WriteOne(GetFieldAddress(i),MT,MS);
  }
  WriteOne(&MYEND,mtString,MS);
}

void TMyObject::ReadData(TMemoryStream *MS)
{
  int MT;
  int MTLoaded;
  AnsiString _Name;
  int CountMyEnd=1;
  TMDelTList<int> *Loaded = new TMDelTList<int>();
  for (int i=0;i<GetFieldCount();i++)
    Loaded->Add(new int(0));
  while(CountMyEnd)
  {
    MT =-1;
    if (ReadOne(&_Name,mtString,MS)!=-1)
      throw EMyException("Unknown error");
    if (_Name.Trim() == MYEND)
    {
      CountMyEnd--;
      continue;
    }
    if (ReadOne(&MTLoaded,mtInt,MS)!=-1)
      throw EMyException("Unknown error");
    int _index = GetFieldIndex(_Name);
    if (_index!=-1)
      MT = GetFieldType(_index);
    if (_index==-1 || MT != MTLoaded)
        throw EMyException("Field is skipped");
    else
    {
      if (MT == mtMyObject)
          ((TMyObject *)GetFieldAddress(_Name))->ReadData(MS);
      else
      {
        if (ReadOne(GetFieldAddress(_index),MT,MS)!=-1)
            throw EMyException("Unknown error");
      }
      *(Loaded->Items[_index]) = 1;
    }
  }
  for (int i=0;i<Loaded->Count;i++)
    if (*(Loaded->Items[i])==0)
    {
      AnsiString AS = Name+AnsiString(": Field is not loaded: ")+(*(GetFieldName(i)));
      StdOut(AS,false);
      AS = AnsiString("-       Assign ")+TYPETOSTR(GetFieldAddress(i),GetFieldType(i));
      StdOut(AS,false);
    }
    delete Loaded;
    if (!FGUID.IsEmpty() && !RegisterInfo)
    {
        DynamicType->RegisterInstance(this);
    }
}


void TMyObject::SaveData(FILE *F) const
{
    TStringList *A = new TStringList();
    int MT;
    AnsiString FName;
    AnsiString StrValue;
    AnsiString TABS = AnsiString::StringOfChar('\t', GetDepth() );
    AnsiString TABS_P_1 = AnsiString::StringOfChar('\t', GetDepth()+1 );
    for (int i=0;i<GetFieldCount();i++)
    {
        A->Clear();
        MT = GetFieldType(i);
        FName =*(GetFieldName(i));
        A->Add( FName);
        int intMT = int (MT);
        A->Add(TYPETOSTR(&intMT,mtInt));
        switch (MT)
        {
            case mtMyObject:
            {
                fputs((TABS_P_1 + A->CommaText).c_str(),F);
                fputs("\n",F);
                ((TMyObject *)GetFieldAddress(i))->SaveData(F);
            }break;
            case mtString:
            {
                fputs((TABS_P_1 + A->CommaText).c_str(),F);
                fputs("\n",F);
                SaveString(TABS_P_1, *((AnsiString*)GetFieldAddress(i)),F);
            }break;
            default:
            {
                StrValue = TYPETOSTR(GetFieldAddress(i),MT);
                A->Add(StrValue);
                fputs((TABS_P_1 + A->CommaText).c_str(),F);
                fputs("\n",F);
            }
        }
    }
    delete A;
    fputs((TABS + MYEND).c_str(),F);
    fputs("\n",F);
}

void CloseObject(FILE *F)
{
    TStringList *A = new TStringList();
    char str[STR_LINE_LENGTH_READ];
    do{
        fgets(str,STR_LINE_LENGTH_READ,F);
        A->CommaText=AnsiString(str).Trim();
        if (A->Count>1 && ISINTEGER( A->Strings[1] ) && ((int) (A->Strings[1].ToInt()))==mtMyObject )
            CloseObject(F);
    }while(AnsiString(str).Trim() != MYEND );
    delete A;
}

void CloseString(FILE *F)
{
    char str[STR_LINE_LENGTH_READ];
    do{
        fgets(str,STR_LINE_LENGTH_READ,F);
    }while(AnsiString(str).Trim() != ENDOFSTR );
}

void TMyObject::LoadData(FILE *F)
{
    char str[STR_LINE_LENGTH_READ];
    TStringList *A = new TStringList();
    int MT;
    int MTLoaded;
    AnsiString _Name;
    AnsiString StrValue;
    int CountMyEnd=1;
    TMDelTList<int> *Loaded = new TMDelTList<int>();
    for (int i=0;i<GetFieldCount();i++)
        Loaded->Add(new int(0));
    while(CountMyEnd)
    {
        fgets(str,STR_LINE_LENGTH_READ,F);
        if (AnsiString(str).Trim() == MYEND)
        {
            CountMyEnd--;
            continue;
        }
        A->CommaText=AnsiString(str).Trim();
        _Name = A->Strings[0];
        MTLoaded = A->Strings[1].ToInt();
        int _index = GetFieldIndex(_Name);
        if (_index!=-1)
            MT = GetFieldType(_index);
        if (GetFieldIndex(_Name)==-1 )
        {
            AnsiString AS = Name+AnsiString(": Found field - ")+_Name;
            StdOut(AS,false);
            if (MTLoaded == mtMyObject)
            {
                AS = AnsiString("-       Object is skipped - ")+_Name;
                StdOut(AS,false);
                StdOut(AnsiString(),false);
                CloseObject(F);
            }
            if (MTLoaded == mtString)
            {
                AS = AnsiString("-       String is skipped - ")+_Name;
                StdOut(AS,false);
                StdOut(AnsiString(),false);
                CloseString(F);
            }

        }
        else
        {
            switch (MT)
            {
                case mtMyObject:
                {
                    ((TMyObject *)GetFieldAddress(_Name))->LoadData(F);
                }break;
                case mtString:
                {
                    LoadString( *((AnsiString*)GetFieldAddress(_Name)),F);
                }break;
                default:
                {
                    StrValue = A->Strings[2];
                    SetField(_Name,STRTOTYPE(StrValue,MT));
                }
            }
            *(Loaded->Items[GetFieldIndex(_Name)]) = 1;
        }
    }
    delete A;
    for (int i=0;i<Loaded->Count;i++)
        if (*(Loaded->Items[i])==0)
        {
            AnsiString AS = Name+AnsiString(": Field is not loaded: ")+(*(GetFieldName(i)));
            StdOut(AS,false);
            AS = AnsiString("-       Assign ")+TYPETOSTR(GetFieldAddress(i),GetFieldType(i));
            StdOut(AS,false);
        }
    delete Loaded;
#ifdef GetOldBase
    if ( Is(TMyRegObject::StaticType) )
    {
        FGUID = IntToStr( ((TMyRegObject*)this)->Table ) + IntToStr( ((TMyRegObject*)this)->ID );
    }
#endif
    if (!FGUID.IsEmpty() && !RegisterInfo)
    {
        DynamicType->RegisterInstance(this);
    }
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// если передается 0  в _METAID то идентификаторы генер. автом.
// если имя уже есть к имени добавляется 1,2,3,4,....
const AnsiString aAttributes = AnsiString("Attributes");
//const AnsiString aName = AnsiString("Name");
const AnsiString aDescription = AnsiString("Description");

void TMyRegObject::SetParent(TMyRegObject *_Parent)
{
    if (Parent == _Parent)
        return;//т.к. динамические связки прыгают из конца в начало
    if (Parent)
        Parent->ChildList->Remove(this);
    FParent = _Parent;
    if (Parent)
        Parent->ChildList->Add(this);
}

void TMyRegObject::AssignLST(const TMyObject *OBJ,TStringList *SKIP)
{
    if (SKIP->IndexOf(aID)==-1)
        SKIP->Add(aID);
    if (SKIP->IndexOf(aName)==-1)
        SKIP->Add(aName);
    if (SKIP->IndexOf(aTable)==-1)
        SKIP->Add(aTable);
    if (SKIP->IndexOf(aGUID)==-1)
        SKIP->Add(aGUID);
    TMyObject::AssignLST(OBJ,SKIP);
//    RecurrentCheck();
}

TMyRegObject::TMyRegObject()
{
    RegisterNewClass<TMyObject,TMyRegObject>(this,false,&CreateFunction);
//    Registered = false;
//    DoNotReg = false;
    TN = NULL;
    LI = NULL;
    FMyTree = NULL;
    FParent = NULL;
    ImageIndex=0;
    Attributes = new /*TMDelLSTList*/TMDelTList<TLuaAttribute>();
    RegisterField(&FGUID,&aGUID,mtString);
    RegisterField(Attributes,&aAttributes,mtMyObject);
    RegisterField(&ID,&aID,mtInt);
    RegisterField(&Table,&aTable,mtInt);
    RegisterField(&Name,&aName,mtString);
    RegisterField(&Description,&aDescription,mtString);
    ChildList = new TMTList<TMyRegObject>();
    FTable = rtNone;
    FID = -1;
    ServiceNode = false;
}

TMyObject* TMyRegObject::CreateFunction()
{
    return new TMyRegObject();
}

TMyRegObject::~TMyRegObject()
{
    FromTree();
//    if (Table!= rtNone)
//        UnReg();
    Parent = NULL;
    delete Attributes;
    TMyRegObject *Deleted;
    while (ChildList->Count>0)
    {
        Deleted = (TMyRegObject *)ChildList->Last();
        delete Deleted;
    }
    delete ChildList;
}

int TMyRegObject::GetAttributeIndex(char* _name)
{
    AnsiString _Name = AnsiString(_name).Trim().LowerCase();
    for (int i=0;i<Attributes->Count;i++)
        if (_Name == Attributes->Items[i]->Name.Trim().LowerCase())
            return i;
    return -1;
}

char* TMyRegObject::GetAttributeValue(char* _name)
{
    int index = GetAttributeIndex(_name);
    if (index!=-1)
        return Attributes->Items[index]->GetCharValue();
    else
        return NULL;
}

TLuaAttribute* TMyRegObject::GetAttribute(char *_name)
{
    int index = GetAttributeIndex(_name);
    if (index!=-1)
        return Attributes->Items[index];
    else
        return NULL;
}

void TMyRegObject::SetAttributeValue(char* _name,char* _value)
{
    int index = GetAttributeIndex(_name);
    if (index!=-1)
        Attributes->Items[index]->VALUE = AnsiString(_value);
}

/*bool TMyRegObject::RegThis(int _Table,int _ID,const AnsiString& _Name)
{
    if (DoNotReg)
        return true;
    if (Registered)
        return Registered;
    AnsiString newName = _Name;
    Registered = MGT->RegisterInstance(_Table,this,_ID,newName);
    if (!Registered)
    {
        newName = MGT->ValidateName(_Table,newName);
        Registered = MGT->RegisterInstance(_Table,this,_ID,newName);
    }
    if(Registered)
    {
        FTable = _Table;
        FID = _ID;
        FName = newName;
        return Registered;
    }
    return Registered;
}

bool TMyRegObject::NewRegThis(int _Table,const AnsiString& PATTERN)
{
    if (DoNotReg)
        return true;
    if (Registered)
        return Registered;
    Registered = MGT->RegisterNewInstance(_Table,this,PATTERN,FID,FName);
    if(Registered)
        FTable = _Table;
    return Registered;
}

bool TMyRegObject::ReRegThis(int _ID,const AnsiString& _Name)
{
    if (!Registered || DoNotReg)
    {
        FName = _Name;
        FID = _ID;
        return true;
    }
    if (Table==rtNone)
        return false;
    UnReg();
    Registered = MGT->RegisterInstance(Table,this,_ID,_Name);
    if(!Registered)
        Registered = MGT->RegisterInstance(Table,this,ID,Name);
    else
    {
        FName = _Name;
        FID = _ID;
    }
    return Registered;
}  */


/*void TMyRegObject::UnReg()
{
    if (Registered)
    {
        MGT->UnRegister(Table,this);
        Registered = false;
    }
} */

void TMyRegObject::SetImageIndex(int newII)
{
    FImageIndex=newII;
    OnChange();
}

void TMyRegObject::OnChange()
{
    ToTree();
}


void TMyRegObject::ToTree()
{
    if (TN)
    {
        TN->Text = Name;
        TN->ImageIndex=ImageIndex;
        TN->StateIndex=ImageIndex;
        TN->SelectedIndex=ImageIndex;
    }
}

void TMyRegObject::FromTree()
{
    if (TN)
        delete TN;
}

bool TMyRegObject::CheckFields()
{
    if (Parent&&Parent->ChildList->IndexOf(this)==-1)
        Parent->ChildList->Add(this);
//    if ( DoNotReg )
        return true;
    //if (Table!=-1 && MGT->InstantIndex(Table,this)!=-1)
//        return true;
  //  FGUID = IntToStr(Table)+IntToStr(ID);
//    return (Table!=-1) && RegThis(Table,ID,Name);
}

bool TMyRegObject::In(TMyRegObject *Node)
{
    #ifdef _DEBUG
    if (!Node)
        throw EMyException(MSG_ERR_1);
    #endif
    if (Parent == Node)
        return true;
    if (!Parent)
        return false;
    return Parent->In(Node);
}

int TMyRegObject::GetSaveChildCount()
{
    int res = ChildList->Count;
    for (int i=0;i<ChildList->Count;i++)
        if ( ((TMyRegObject*)ChildList->Items[i])->ServiceNode)
            res--;
    return(res);
}


void TMyRegObject::SetMyTree(TMyRegTree *_MyTree)
{
    if (FMyTree==NULL)
        FMyTree = _MyTree;
}

//--------------------------------------------------------------------------
TInstanceRegisterInfo::TInstanceRegisterInfo()
{
    FMyObject = NULL;
    FRender = NULL;
}

bool TClassNode::RegisterInstance(TMyObject* Object)
{
    if (!Object->RegisterInfo)
    {
        TClassNode* tUniqueNameNode = UniqueNameNode;
        if ( tUniqueNameNode && tUniqueNameNode->RecurrentFindByName(Object->Name) )
            return false;
        if ( Object->GUID.IsEmpty() )
            Object->GenerateGUID();
        Object->FRegisterInfo = new TInstanceRegisterInfo();
        RegList->Add(Object->RegisterInfo);
        Object->RegisterInfo->FMyObject = Object;
        return true;
    }
    return true;
}

void TClassNode::RecurrentSelectByPattern(TMyObject* NotObject,const AnsiString& aPattern,TMTList<AnsiString>& Lst)
{
    SelectByPattern(NotObject,aPattern,Lst);
    /*
    for (int i=0;i<ChildCount;i++)
        Childs[i]->RecurrentSelectByPattern(NotObject,aPattern,Lst);
    */
    for (bool OK = ChildList->Start();OK;OK = ChildList->Next())
    {
        TClassNode* Cur = (TClassNode*)ChildList->Current;
        if ( Cur->GetUniqueNameNode() == Cur )
            continue;
        Cur->RecurrentSelectByPattern(NotObject,aPattern,Lst);
    }
}

void TClassNode::SelectByPattern(TMyObject* NotObject,const AnsiString& aPattern,TMTList<AnsiString>& Lst)
{
/*
    for (int i=0;i<RegList->Count;i++)
    {
        TMyObject* CurObj = RegInfo[i]->Object;
        if ( NotObject != CurObj && CurObj->Name.AnsiPos(aPattern) )
            Lst.Add(&(CurObj->Name));
    }
*/
    for (bool OK = RegList->Start();OK;OK = RegList->Next())
    {
        TMyObject* CurObj = ((TInstanceRegisterInfo*)RegList->Current)->Object;
        if ( NotObject != CurObj && CurObj->Name.AnsiPos(aPattern)==1 )
            Lst.Add(&(CurObj->Name));
    }
}

void TClassNode::ValidateObjectName(TMyObject* Object)
{
    //this is unique name node
    if (Object->FName.IsEmpty())
    {
        Object->FName = Object->DynamicType->Name + AnsiString("_Instance_");
        if ( !Object->FGUID.IsEmpty() )
            Object->FName = Object->FName + Object->FGUID;
        else
            Object->FName = Object->FName + CreateClassID();
    }
    else
    {
        TMTList<AnsiString> Lst;
         RecurrentSelectByPattern(Object,Object->FName,Lst);
        if ( FindInList(&Lst, Object->FName ) == -1 )
            return;
        int i = 1;
        while ( FindInList(&Lst, Object->FName+AnsiString("_")+IntToStr(i) ) != -1 )
            i++;
        Object->FName = Object->FName+AnsiString("_")+IntToStr(i);
    }
}

void TClassNode::RegisterNewInstance(TMyObject* Object)
{
    if (!Object->RegisterInfo)
    {
        if ( Object->GUID.IsEmpty() )
            Object->GenerateGUID();
        TClassNode* tUniqueNameNode = UniqueNameNode;
        if ( tUniqueNameNode )
            tUniqueNameNode->ValidateObjectName(Object);
        Object->FRegisterInfo = new TInstanceRegisterInfo();
        RegList->Add(Object->RegisterInfo);
        Object->RegisterInfo->FMyObject = Object;
    }
}

void TClassNode::RegisterRender(TMyObject* Object,TVisRender* Render)
{
    if (!Object->RegisterInfo)
        throw EMyException("The object is not registered in <TInstanceRegister>");
    Object->RegisterInfo->FRender = Render;
}

void TClassNode::UnRegisterInstance(TMyObject* Object)
{
    if (Object->RegisterInfo)
    {
        if ( RegList->Remove(Object->FRegisterInfo)==-1 )
            throw EMyException("Inadmissible state");
        else
            delete Object->FRegisterInfo;

        Object->FRegisterInfo = NULL;
    }
}

// TClassNode
TClassNode::TClassNode():type(typeid(TMyObject))
{
    ChildList = new TQuickList();
    UniqueNameFlag = false;
}

TClassNode::TClassNode(TClassNode*_Parent,const std::type_info & _type,bool _Virtual,TCreateFunction aCreateFunction):type(_type)
{
    ImageIndex = -1;
    ChildList = new TQuickList();
    RegList = new TQuickList();

    Parent = _Parent;
    Virtual=_Virtual;
    CreateFunction = aCreateFunction;
    if (Parent)
    {
        Parent->AddChild(this);
    }
    UniqueNameFlag = false;
}

TClassNode *TClassNode::GetChild(int i)
{
    return((TClassNode *)ChildList->Items[i]);
}

int TClassNode::GetChildCount()
{
    return(ChildList->Count);
}

void TClassNode::AddChild(TClassNode *CN)
{
    ChildList->Add(CN);
}

TInstanceRegisterInfo *TClassNode::GetRegInfo(int i)
{
    return((TInstanceRegisterInfo *)RegList->Items[i]);
}

int TClassNode::GetRegInfoCount()
{
    return(RegList->Count);
}

void TClassNode::AddRegInfo(TInstanceRegisterInfo *CN)
{
    RegList->Add(CN);
}

TInstanceRegisterInfo *TClassNode::GetRegInfoByObject(TMyObject* Object)
{
/*
    for (int i=0;i<RegList->Count;i++)
        if ( RegInfo[i]->Object == Object )
            return RegInfo[i];
    return NULL;
*/
    for (bool OK = RegList->Start();OK;OK = RegList->Next())
        if ( ((TInstanceRegisterInfo*)RegList->Current)->Object == Object )
            return ((TInstanceRegisterInfo*)RegList->Current);
    return NULL;
}

TInstanceRegisterInfo *TClassNode::GetRegInfoByRender(TVisRender* Render)
{
/*    for (int i=0;i<RegList->Count;i++)
        if ( RegInfo[i]->Render == Render )
            return RegInfo[i];
    return NULL;
*/

    for (bool OK = RegList->Start();OK;OK = RegList->Next())
        if ( ((TInstanceRegisterInfo*)RegList->Current)->Render == Render )
            return ((TInstanceRegisterInfo*)RegList->Current);
    return NULL;
}

TMyObject* TClassNode::GetObjectByGUID(const AnsiString& aGUID)
{
/*
    for (int i=0;i<RegList->Count;i++)
        if ( RegInfo[i]->Object->GUID.AnsiCompare(aGUID) == 0 )
            return RegInfo[i]->Object;
    return NULL;
*/

    for (bool OK = RegList->Start();OK;OK = RegList->Next())
        if ( ((TInstanceRegisterInfo*)RegList->Current)->Object->GUID.AnsiCompare(aGUID) == 0 )
            return ((TInstanceRegisterInfo*)RegList->Current)->Object;
    return NULL;
}

TMyObject* TClassNode::RecurrentFindByGUID(const AnsiString& aGUID)
{
/*
    TMyObject* Temp = GetObjectByGUID(aGUID);
    if ( Temp )
        return Temp;
    for (int i=0;i<ChildList->Count;i++)
    {
        Temp = Childs[i]->RecurrentFindByGUID(aGUID);
        if ( Temp )
            return Temp;
    }
    return NULL;
*/
    TMyObject* Temp = GetObjectByGUID(aGUID);
    if ( Temp )
        return Temp;
    for (bool OK = ChildList->Start();OK;OK = ChildList->Next())
    {
        Temp = ((TClassNode*)ChildList->Current)->RecurrentFindByGUID(aGUID);
        if ( Temp )
            return Temp;
    }
    return NULL; 
}

TMyObject* TClassNode::GetObjectByRender(TVisRender* Render)
{
/*
    for (int i=0;i<RegList->Count;i++)
        if ( RegInfo[i]->Render == Render )
            return RegInfo[i]->Object;
    return NULL;
*/

    for (bool OK = RegList->Start();OK;OK = RegList->Next())
        if ( ((TInstanceRegisterInfo*)RegList->Current)->Render == Render )
            return ((TInstanceRegisterInfo*)RegList->Current)->Object;
    return NULL;
}

TMyObject* TClassNode::RecurrentFindByRender(TVisRender* Render)
{
/*
    TMyObject* Temp = GetObjectByRender(Render);
    if ( Temp )
        return Temp;
    for (int i=0;i<ChildList->Count;i++)
    {
        Temp = Childs[i]->RecurrentFindByRender(Render);
        if ( Temp )
            return Temp;
    }
    return NULL;
*/
    TMyObject* Temp = GetObjectByRender(Render);
    if ( Temp )
        return Temp;
    for (bool OK = ChildList->Start();OK;OK = ChildList->Next())
    {
        Temp = ((TClassNode*)ChildList->Current)->RecurrentFindByRender(Render);
        if ( Temp )
            return Temp;
    }
    return NULL;
}

TMyObject* TClassNode::GetObjectByName(const AnsiString& vName)
{
/*
    for (int i=0;i<RegList->Count;i++)
        if ( RegInfo[i]->Object->Name.AnsiCompare(vName) == 0 )
            return RegInfo[i]->Object;
    return NULL;
*/
    for (bool OK = RegList->Start();OK;OK = RegList->Next())
        if ( ((TInstanceRegisterInfo*)RegList->Current)->Object->Name.AnsiCompare(vName) == 0 )
            return ((TInstanceRegisterInfo*)RegList->Current)->Object;
    return NULL;
}

TMyObject* TClassNode::RecurrentFindByName(const AnsiString& vName)
{
/*
    TMyObject* Temp = GetObjectByName(aName);
    if ( Temp )
        return Temp;
    for (int i=0;i<ChildList->Count;i++)
    {
        Temp = Childs[i]->RecurrentFindByName(vName);
        if ( Temp )
            return Temp;
    }
    return NULL;
*/
    TMyObject* Temp = GetObjectByName(vName);
    if ( Temp )
        return Temp;
    for (bool OK = ChildList->Start();OK;OK = ChildList->Next())
    {
        TClassNode* Cur = (TClassNode*)ChildList->Current;
        if ( Cur->GetUniqueNameNode() == Cur )
            continue;
        Temp = Cur->RecurrentFindByName(vName);
        if ( Temp )
            return Temp;
    }
    return NULL;
}

AnsiString TClassNode::GetName()
{
    return AnsiString(type.name()).Trim();
}

TClassNode::~TClassNode()
{
    for (int i=0;i<ChildCount;i++)
        delete Childs[i];
    delete ChildList;
    for (int i=0;i<RegList->Count;i++)
        delete RegInfo[i];
    delete RegList;
}

bool TClassNode::operator == (TClassNode *CN) const
{
    return (type == CN->type);
}

bool TClassNode::operator != (TClassNode *CN) const
{
    return(type != CN->type);
}

TClassNode* TClassNode::GetUniqueNameNode()
{
    if (UniqueNameFlag)
        return this;
    if (Parent == NULL)
        return NULL;
    return Parent->GetUniqueNameNode();
}

bool TClassNode:: is (const TClassNode *CN) const
{
  if (!this)
    return false;
  if (type==CN->type)
    return(true);
  if (Parent == NULL)
    return(false);
  return(Parent->is(CN));
}

TClassNode *TClassNode::Find(const AnsiString& _Name)
{
    if (Name == _Name)
        return(this);
    for (int i=0;i<ChildCount;i++)
    {
        TClassNode *CN = Childs[i]->Find(_Name);
        if (CN)
            return(CN);
    }
    return(NULL);
}

TClassNode* TClassNode::Find(const std::type_info & ti)
{
    if (type == ti)
        return(this);
    for (int i=0;i<ChildCount;i++)
    {
        TClassNode *CN = Childs[i]->Find(ti);
        if (CN)
            return(CN);
    }
    return(NULL);
}


void TClassNode::FillChildList (TMTList<TClassNode> *L)
{
    if (!Virtual)
        L->Add(this);
    for (int i=0;i<ChildCount;i++)
        Childs[i]->FillChildList(L);
}

TGarbage::TGarbage()
{
    StrGarbage = new TMDelTList<AnsiString>();
}

TGarbage::~TGarbage()
{
    delete StrGarbage;
}

void TGarbage::AddStr(AnsiString* Str)
{
    StrGarbage->Add(Str);
}

void TGarbage::Clear()
{
    StrGarbage->Clear();
}

TClassNode *MTID (const std::type_info& ti)
{
    if (ClassHead)
        return(ClassHead->Find(ti));
    return(NULL);
}

int MYSIMPLETYPE(const std::type_info& pType)
{
    TClassNode* pTypeCN = MTID( pType );
    if ( pTypeCN )
    {
        TClassNode* MROCN = TMyRegObject::StaticType;
        TClassNode* MOCN = TMyObject::StaticType;
        if (MROCN && pTypeCN->is(MROCN))
            return mtMyRegObject;
        if (MOCN && pTypeCN->is(MOCN))
            return mtMyObject;
    }
    if ( pType == typeid(TIntVec) || pType == typeid(TChangeVec) )
        return(mtIntVec);
    if ( pType == typeid(int) )
        return(mtInt);
    if (pType == typeid(double) )
        return(mtDouble);
    if ( pType == typeid(float) )
        return(mtFloat);
    if ( pType == typeid(System::AnsiString) )
        return(mtString);
    if ( pType == typeid(bool) )
        return(mtBool);
    if ( pType == typeid(TBoolVec) )
        return(mtBoolVec);
    if ( pType == typeid(TMBTRect) )
        return(mtRect);
    return(mtNone);
}


void SelectClassesByName(const AnsiString &_Name,TMTList<TClassNode> *L)
{
    L->Clear();
    TClassNode *CN = ClassHead->Find(_Name);
    if (CN)
        CN->FillChildList(L);
}

bool MY_IS(const TMyObject *Obj,const std::type_info& ti)
{
  if (!Obj)
    return false;
  return ( MTID(typeid(*Obj))->is(MTID(ti)) );
}

int ErrorDlg(const AnsiString& Caption,TMsgDlgButtons Buttons)
{
    return MessageDlg(Caption,mtError,Buttons,0);
}

int InfoDlg(const AnsiString& Caption,TMsgDlgButtons Buttons)
{
    return MessageDlg(Caption,mtInformation	,Buttons,0);
}

int WarningDlg(const AnsiString& Caption,TMsgDlgButtons Buttons)
{
    return MessageDlg(Caption,mtWarning	,Buttons,0);
}

int ConfirmDlg(const AnsiString& Caption,TMsgDlgButtons Buttons)
{
    return MessageDlg(Caption,mtConfirmation,Buttons,0);
}

void ErrorMsg(const AnsiString& Caption)
{
    MessageDlg(Caption,mtError,TMsgDlgButtons() << mbOK,0);
}

void InfoMsg(const AnsiString& Caption)
{
    MessageDlg(Caption,mtInformation,TMsgDlgButtons() << mbOK,0);
}

void WarningMsg(const AnsiString& Caption)
{
    MessageDlg(Caption,mtWarning,TMsgDlgButtons() << mbOK,0);
}

/*TMyRegObject *MGTFindByID(int Table,int id)
{
    return MGT->FindByID(Table,id);
} */

TGarbage& GetGarbage()
{
    if (fGarbage == NULL)
        fGarbage = new TGarbage();
    return *fGarbage;
}

TClassNode* GetClassHead()
{
    return fClassHead;
};



void CallDialog(    TComponent *Owner,
                    TControl *Parent,
                    TMyObject *Obj,
                    int MT,
                    const AnsiString& Text,
                    void *Data)
{
    switch (MT)
    {
        case mtInt:
        {
            break;
        }
        case mtDouble:
        {
            break;
        }
        case mtString:
        {
            break;
        }
        case mtIntVec:
        {
            new TMDIVECEDIT(Owner,Parent,Obj,Text,Data);
            break;
        }
        case mtBool:
        {
            break;
        }
        case mtBoolVec:
        {
            new TMDIBOOLVECEDIT(Owner,Parent,Obj,Text,Data);
            break;
        }
        case mtSignVec:
        {
            new TMDISIGNVECEDIT(Owner,Parent,Obj,Text,Data);
            break;
        }
    }
}


TStdOut VarStdOut = NULL;
COMMONAL_API void SetStdOut(TStdOut aStdOut);

COMMONAL_API void StdOut(const AnsiString& Text,bool Clear)
{
    if (VarStdOut)
        VarStdOut(Text,Clear);
}

COMMONAL_API void StrOut(char *Text,bool Clear)
{
    StdOut(AnsiString(Text),Clear);
}

void SetStdOut(TStdOut aStdOut)
{
    VarStdOut = aStdOut;
}

bool ClassCheck(const TMyObject* Object,const TClassNode* _Class)
{
    if ( !Object->DynamicType )
    {
        AnsiString Str = "<ClassCheck>: аргумент-объект не зарегистрирован.";
        throw EMyException(Str);
    }
    return Object->Is(_Class);
}

