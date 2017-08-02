//---------------------------------------------------------------------------

#ifndef ContainerVH
#define ContainerVH
#include <stdio.h>
//---------------------------------------------------------------------------
typedef bool __fastcall (*TMyCompareProc)(void *item1, void *item2);
typedef void (*TStartProcess)(const AnsiString& ProcessName,int Count);
typedef void (*TCountProcess) (const AnsiString& ObjectName,int Count);


COMMONAL_API void SetStartProcess(TStartProcess SP);
COMMONAL_API void SetCountProcess(TCountProcess CP);
COMMONAL_API void StartProcess(const AnsiString& ProcessName,int Count);
COMMONAL_API void CountProcess(const AnsiString& ObjectName,int Count);


class COMMONAL_API TBaseContainer : public TMyObject {
public:
    TBaseContainer();
    ~TBaseContainer(){};
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
};

extern COMMONAL_API TClassNode* TBaseContainer::StaticType;

template <class T>
class TContainer : public TBaseContainer{
protected:
    virtual void LookingTo(TMyObject* Target,TMTList<TMyObject>& OBJL) const;
public:
    TContainer();
    ~TContainer(){};
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------TMDelLSTList
    virtual int Add(T* It){return -1;};
    virtual void Clear(){};
    virtual int GetCount() const {return -1;};
    virtual const T* GetItem(int i) const {return NULL;};
    virtual T* GetItem(int i) {return NULL;};
    virtual int GetSimpleType() const {return -1;};

    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    void LoadData(FILE *F);
    void SaveData(FILE *F) const;
    bool CheckFields();
    bool Init();
    bool ShowProcess;
};

template <class T>
TClassNode* TContainer<T>::StaticType = NULL;

template <class T>
TContainer<T>::TContainer()
{
    ShowProcess = false;
    //-------------------------------------------------------------------
    RegisterNewClass< TBaseContainer,TContainer<T> >(this,false,&(CreateFunction));
    //-------------------------------------------------------------------
}

template <class T>
TMyObject* TContainer<T>::CreateFunction()
{
    return new TContainer<T>();
}

template <class T>
void TContainer<T>::WriteData(TMemoryStream *MS) const
{
    int mtid = GetSimpleType();
    AnsiString _Name;
    if (ShowProcess)
        StartProcess("Writing data ...",GetCount());
    for (int i=0;i<GetCount();i++)
    {
        switch (mtid)
        {
            case  mtMyObject:
            {
                _Name = AnsiString(typeid(*GetItem(i)).name());
                if (ShowProcess)
                    CountProcess(((TMyObject*)GetItem(i))->Name,1);
                WriteOne(&_Name,mtString,MS);
                WriteOne(&mtMyObject,mtInt,MS);
                ((TMyObject*)GetItem(i))->WriteData(MS);
            }break;
            default:
            {
                WriteOne(&_Name,mtString,MS);
                WriteOne(GetItem(i),mtid,MS);
            }
        }
    }
    WriteOne(&MYEND,mtString,MS);
}

template <class T>
void TContainer<T>::ReadData(TMemoryStream *MS)
{
    AboutToChange(this);

    int mtid = GetSimpleType();
    Clear();
    AnsiString CT;
    if (ShowProcess)
        StartProcess("Reading data ...",1);
    AnsiString TName = AnsiString(typeid(T).name()).Trim();

    if (ReadOne(&CT,mtString,MS) !=-1 )
      throw EMyException("Error");

    TClassNode* CN = NULL;
    if ( mtid == mtMyObject )
        CN = ClassHead->Find(TName);
    while( CT != MYEND )
    {
        switch (mtid)
        {
            case  mtMyObject:
            {
                Close_Field(MS);
                if ( TName == CT)
                    Add( (T*)CN->CreateFunction() );
                else
                    Add( (T*)Create_Default_Constructor(CT) );
                ((TMyObject*)GetItem(GetCount()-1))->ReadData(MS);
                if (ShowProcess)
                    CountProcess(((TMyObject*)GetItem(GetCount()-1))->Name,1);
            }
            break;
            default:
            {
                Add( (T*)CreateType(mtid) );
                if (ReadOne(GetItem( GetCount()-1 ),mtid,MS) !=-1 )
                    throw EMyException("Error");
            }
        }
        if (ReadOne(&CT,mtString,MS) !=-1 )
            throw EMyException("Error");
    }
}

template <class T>
void TContainer<T>::SaveData(FILE *F) const
{
    AnsiString TABS = AnsiString::StringOfChar('\t',GetDepth());
    AnsiString TABS_P_1 = AnsiString::StringOfChar('\t',GetDepth()+1);
    int mtid = GetSimpleType();
    AnsiString StrValue;
    TStringList *A = new TStringList();
    if (ShowProcess)
        StartProcess("Запись данных ...",GetCount());
    for (int i=0;i<GetCount();i++)
    {
        switch (mtid)
        {
            case  mtMyObject:
            {
                A->Clear();
                A->Add(AnsiString(typeid(*GetItem(i)).name()));
                A->Add(IntToStr(mtMyObject));
                fputs((TABS_P_1 + A->CommaText).c_str(),F);
                fputs("\n",F);
                ((TMyObject*)GetItem(i))->SaveData(F);
                if (ShowProcess)
                    CountProcess(((TMyObject*)GetItem(i))->Name,1);
            }break;
            default:
            {
                StrValue = TYPETOSTR(GetItem(i),mtid);
                fputs((TABS_P_1 + StrValue).c_str(),F);
                fputs("\n",F);
            }
        }
    }
    delete A;
    fputs((TABS+MYEND).c_str(),F);
    fputs("\n",F);
}

template <class T>
void TContainer<T>::LoadData(FILE *F)
{
    AboutToChange(this);
    //its for chek type

    TStringList *A = new TStringList();
    //----------------
    int mtid = GetSimpleType();
    Clear();
    char str[STR_LINE_LENGTH_READ];
    AnsiString CT;
    fgets(str,STR_LINE_LENGTH_READ,F);
    if (ShowProcess)
        StartProcess("Reading data ...",1);
    AnsiString TName = AnsiString(typeid(T).name()).Trim();

    TClassNode* CN = NULL;
    if ( mtid == mtMyObject )
        CN = ClassHead->Find(TName);
    while(AnsiString(str).Trim() != MYEND)
    {
        switch (mtid)
        {
            case  mtMyObject:
            {
                A->CommaText = AnsiString(str).Trim();
                CT = A->Strings[0];
                if ( TName == CT)
                    Add( (T*)CN->CreateFunction() );
                else
                    Add( (T*)Create_Default_Constructor(CT) );
                ((TMyObject*)GetItem(GetCount()-1))->LoadData(F);
                if (ShowProcess)
                    CountProcess(((TMyObject*)GetItem(GetCount()-1))->Name,1);
            }
            break;
            default:
            {
                Add( (T*)CreateType(mtid) );
                CopyType(mtid,GetItem(GetCount()-1),STRTOTYPE(AnsiString(str).Trim(),mtid));
            }
        }
        fgets(str,STR_LINE_LENGTH_READ,F);
    }
    delete A;
}

template <class T>
bool TContainer<T>::CheckFields()
{
    AboutToChange(this);
    if (ShowProcess)
        StartProcess("Checking ...",GetCount());
    int mtid = GetSimpleType();
    if (mtid>=mtMyObject)
        for (int i=0;i<GetCount();i++)
        {
            if (ShowProcess)
                CountProcess(((TMyObject*)GetItem(i))->Name,1);
            if (!((TMyObject*)GetItem(i))->RecurrentCheck())
                return false;
        }
    return true;
}

template <class T>
bool TContainer<T>::Init()
{
    AboutToChange(this);
    if (ShowProcess)
        StartProcess("Initialize ...",GetCount());
    int mtid = GetSimpleType();
    if (mtid>=mtMyObject)
        for (int i=0;i<GetCount();i++)
        {
            if (ShowProcess)
                CountProcess(((TMyObject*)GetItem(i))->Name,1);
            if (!((TMyObject*)GetItem(i))->Init())
                return false;
        }
    return true;
}

template <class T>
void TContainer<T>::LookingTo(TMyObject * Target,TMTList<TMyObject>& OBJL) const
{
    int mtid = GetSimpleType();
    if (mtid>=mtMyObject)
        for (int i=0;i<GetCount();i++)
            ((TMyObject*)GetItem(i))->RecurrentLookingTo(Target,OBJL);
}




#endif
