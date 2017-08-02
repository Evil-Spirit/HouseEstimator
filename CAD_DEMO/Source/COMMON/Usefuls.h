//---------------------------------------------------------------------------
#ifndef UsefulsH
#define UsefulsH
#include <stdio.h>
#include <typeinfo.h>
#include <ComCtrls.hpp>
#include "MTL.h"
#include "VisComp.hpp"

#define MyShowExc(Exc) ErrorMsg( AnsiString("Exception ") + Exc.Message + AnsiString(" was caught at address ")+ IntToHex((int)ExceptAddr(),8) )
#define _TRY_  try{
#define _ENDTRY_(str,oper) }catch ( Exception& Exc ){MyShowExc(Exc); ErrorMsg(str); oper; };

extern COMMONAL_API AnsiString MainDir;
extern COMMONAL_API AnsiString DataDir;
//---------------------------------------------------------------------------
const AnsiString SPS=AnsiString(".sps");
const AnsiString eHOME=AnsiString(".home");
const AnsiString SGO=AnsiString(".sgo");
const AnsiString MD=AnsiString(".MD");
const AnsiString BMD=AnsiString(".BMD");
const AnsiString SL=AnsiString("\\");
const AnsiString P=AnsiString(".");
const AnsiString DT=AnsiString(".dt");
const AnsiString TMP=AnsiString(".TMP");
const AnsiString BMP=AnsiString(".bmp");
const AnsiString XLS=AnsiString(".xls");
const AnsiString DataDirName = AnsiString("Objects");
const AnsiString BMPDirName = AnsiString("Images");
const AnsiString NDM = AnsiString("_");
const AnsiString MDNAME = AnsiString("CONFIGTREE");
const AnsiString ENDOFSTR = AnsiString("%@%ENDOFSTR%@%");
const AnsiString ENDOFLINE = AnsiString("%@%ENDOFLINE%@%");
const AnsiString MYTAB = AnsiString("%@%TAB%@%");
const AnsiString MYSPACE = AnsiString("%@%SPACE%@%");
const AnsiString MYEND = AnsiString("%@%ENDOBJ%@%");
const AnsiString AnsiSpace = AnsiString(" ");
const char SAVE_NL = '@'; 


const AnsiString MSG_ERR_1 =  AnsiString("Assumed parent node is not defined");
const AnsiString MSG_ERR_2 =  AnsiString("Can not create process of debugger");
const AnsiString MSG_ERR_3 =  AnsiString("Collapsed cut");
const AnsiString MSG_ERR_4 =  AnsiString("Invalid polygon");//В клетках есть то чего нет в полигонах
const AnsiString MSG_ERR_5 =  AnsiString("Point on the plane");
const AnsiString MSG_ERR_6 =  AnsiString("Incorrect angle region");
const AnsiString MSG_ERR_7 =  AnsiString("Parallel not working");
const AnsiString MSG_ERR_8 =  AnsiString("Odd count point on fragmentation polygon");
const AnsiString MSG_ERR_9 =  AnsiString("Incorrect assign region of section");
const AnsiString MSG_ERR_10 =  AnsiString("Root element is not stated");
const AnsiString MSG_ERR_11 =  AnsiString("");

const AnsiString MSG_1 =  AnsiString("Hole ring");
const AnsiString MSG_2 =  AnsiString("Ring");
const AnsiString MSG_3 =  AnsiString("Start");
const AnsiString MSG_4 =  AnsiString("Rotation angles");
const AnsiString MSG_5 =  AnsiString("Region selection");
const AnsiString MSG_6 =  AnsiString("Finish position");
const AnsiString MSG_7 =  AnsiString(" must have one of following groups: "); // должен иметь одну из следующих групп соединений
const AnsiString MSG_8 =  AnsiString("Act"); // Акт -выполненных объемов в соответствии с утвержденными нормами


template <class T> class TMTList;
class TQuickList;

class TMDI3D;
TMDI3D* FindMDI3D();
#define Garbage GetGarbage()
#define ClassHead GetClassHead()

const int STR_LINE_LENGTH_WRITE = 256;
const int STR_LINE_LENGTH_READ = 1024;

COMMONAL_API TComponent *ComponentExists(const TClass& _Class,TComponent *Component = Application);
COMMONAL_API  void SelectComponents(const TClass& _Class,TQuickList* CMP,TComponent *Component= Application);
COMMONAL_API  bool UnderFocuse(TWinControl *WC);
COMMONAL_API  TWinControl *FindActiveWinControl(const TClass& _Class,TWinControl *WinControl = Application->MainForm);
COMMONAL_API  bool ElseExists(TObject *Obj);
COMMONAL_API int MyStrCompare(const AnsiString& Str1,const AnsiString& Str2);

class TMyObject;
COMMONAL_API TMyObject* Create_Default_Constructor(const AnsiString& ClassType);

COMMONAL_API  bool IS(TObject * Obj,TClass Class);

COMMONAL_API  void ReplaceAll(AnsiString& Str, const AnsiString& Replaced, const AnsiString& Replacer);
COMMONAL_API  bool Replace(AnsiString& Str, const AnsiString& Replaced, const AnsiString& Replacer);

COMMONAL_API  bool CHECK_FILE_LOAD(const AnsiString& FileName);
COMMONAL_API  bool CHECK_FILE_SAVE(const AnsiString& FileName);

COMMONAL_API  void CutDigits(AnsiString & Word);

COMMONAL_API  AnsiString ValidateFileName_Dir_Ext(const AnsiString& _Name,const AnsiString& Path,const AnsiString& Ext );
COMMONAL_API  void ReplaceSymbol(AnsiString& STR,char Replaced,char Replacer);

class TMyObject;
class TClassNode;



COMMONAL_API void Close_Field(TMemoryStream *MS);

class COMMONAL_API TFieldTrio{
public:
    TFieldTrio(){};
    virtual ~TFieldTrio(){};
    void *Address;
    int Type;
    const AnsiString* Name;
};

class TInstanceRegisterInfo;

class COMMONAL_API TMyObject {
friend class TClassNode;
private:
    TInstanceRegisterInfo* FRegisterInfo;
protected:
    void SetName(const AnsiString& Name);
    AnsiString FName;
    AnsiString FGUID;
    const AnsiString& GetGUID();
    TQuickList *FAS;
    virtual void LookingTo(TMyObject * Target,TMTList<TMyObject>& OBJL)const {} ;
    TMyObject* FMyObjectParent;
    void SetMyObjectParent(TMyObject* aMyObjectParent);
    void GenerateGUID();
public:
    void GenerateGUIDIfNeed();
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    virtual void KillFunction();
    //----------------------------------
    TClassNode* DynamicType;
    TMyObject();
    virtual ~TMyObject();
    int GetDepth() const;
    __property TInstanceRegisterInfo* RegisterInfo = {read = FRegisterInfo};
    __property TMyObject* MyObjectParent = {read = FMyObjectParent, write = SetMyObjectParent};
    __property AnsiString Name = {read = FName,write = SetName};
    __property AnsiString GUID = {read = FGUID};
    AnsiString Description;

    char *GetCharName()const{return Name.c_str();} ;
    char *GetCharDescription()const{return Description.c_str();};
    void SetCharDescription(char *newDescription);

    //---------------------fields acess--------------------------
    int GetFieldCount() const;
    int GetFieldIndex(const AnsiString &FN) const;
    const AnsiString* GetFieldName(int index) const;
    const AnsiString* GetFieldName(void *Address) const;
    void *GetFieldAddress(int index) const;
    void *GetFieldAddress(const AnsiString &FN) const;
    void SetField(const AnsiString &FN,void *Value );
    void SetFieldDirectly(const AnsiString &FN,void *Value );
    int GetFieldType(int index) const;
    int GetFieldType(const AnsiString&) const;
    AnsiString GetExcelStrField(int index) const;
    virtual void RegisterField(void *FA,const AnsiString *FN,int FT);
    virtual void UnRegisterField(int i);
    virtual void UnRegisterField(void *FA);
//    virtual void OnFieldAccess()const {};
    //---------------------fields acess--------------------------

    bool RecurrentCheck();
    void RecurrentLookingTo(TMyObject * Target,TMTList<TMyObject>& OBJL) const;

    //-------------------rw routine------------------------------
    void Save(const AnsiString& DataName) const ;
    void Load(const AnsiString& DataName);
    void WriteOne(const void * Data,int type,TMemoryStream *MS) const;
    int ReadOne( void * Data,int type,TMemoryStream *MS);
    virtual void SaveData(FILE *F) const ;
    virtual void LoadData(FILE *F);
    void Read(const AnsiString& DataName);
    void Write(const AnsiString& DataName) const;
    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    //------------pure abstract methods--------------------------

    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data){};
    virtual bool CheckFields(){return(true);};
    virtual void ProcessTasks(void* ModeValue){};
    virtual bool Init(){return true;};
    virtual void Changed(void* Field);
    virtual void AboutToChange(void* Field);
    //------------------------------------------------------------------
    TMyObject* RecurrentFindByGUID(const AnsiString& GUID);
    virtual void AssignLST(const TMyObject *Obj,TStringList *SKIP);
    virtual void Assign(TMyObject* MO);

    bool operator == (const TMyObject &Obj) const;
    bool LuaCompareAddress(const TMyObject* Obj) const;

    bool Is(const TClassNode* ClassNode) const;
};
extern COMMONAL_API TClassNode* TMyObject::StaticType;
COMMONAL_API TMyObject* FindByGUID(const AnsiString& GUID);

class COMMONAL_API EMyException : public Exception{
public:
  __fastcall EMyException(const AnsiString& _Error_Text);
  __fastcall virtual ~EMyException(){};
};

//-------------------------TClassNode;
typedef TMyObject* (__closure* TCreateFunction)();

class COMMONAL_API TInstanceRegisterInfo {
friend class TClassNode;
private:
    TMyObject* FMyObject;
    TVisRender* FRender;
public:
    TInstanceRegisterInfo();
    virtual ~TInstanceRegisterInfo(){};
    __property TMyObject* Object = {read = FMyObject};
    __property TVisRender* Render = {read = FRender};
};

class COMMONAL_API TClassNode {
protected:
    AnsiString GetName();
    TClassNode* GetUniqueNameNode();
public:
    TClassNode(TClassNode*_Paren,const std::type_info & ti,bool _Virtual,TCreateFunction CreateFunction);
    TClassNode();
    virtual ~TClassNode();
    //----------------------------------
    TCreateFunction CreateFunction;
    const std::type_info& type;
    //----------------------------------
    AnsiString MnChDescription;
    int ImageIndex;
    __property AnsiString Name = {read = GetName};
    bool Virtual;

    
    TClassNode *Parent;
    TQuickList *ChildList;
    TClassNode *GetChild(int i);
    __property TClassNode *Childs[int i] = {read = GetChild};
    int GetChildCount();
    __property int ChildCount = {read = GetChildCount};
    void AddChild(TClassNode *CN);

    TQuickList* RegList;
    TInstanceRegisterInfo *GetRegInfo(int i);
    void AddRegInfo(TInstanceRegisterInfo *CN);
    __property TInstanceRegisterInfo *RegInfo[int i] = {read = GetRegInfo};
    int GetRegInfoCount();
    __property int RegInfoCount = {read = GetRegInfoCount};
    TInstanceRegisterInfo *GetRegInfoByObject(TMyObject* Object);
    TInstanceRegisterInfo *GetRegInfoByRender(TVisRender* Render);

    TMyObject* GetObjectByGUID(const AnsiString& aGUID);
    TMyObject* RecurrentFindByGUID(const AnsiString& aGUID);
    TMyObject* GetObjectByRender(TVisRender* Render);
    TMyObject* RecurrentFindByRender(TVisRender* Render);
    TMyObject* GetObjectByName(const AnsiString& aName);
    TMyObject* RecurrentFindByName(const AnsiString& aName);
    void RecurrentSelectByPattern(TMyObject* NotObject,const AnsiString& aPattern,TMTList<AnsiString>& Lst);
    void SelectByPattern(TMyObject* NotObject,const AnsiString& aPattern,TMTList<AnsiString>& Lst);

    void ValidateObjectName(TMyObject* Name);

    bool RegisterInstance(TMyObject* Object);
    void RegisterNewInstance(TMyObject* Object);
    void RegisterRender(TMyObject* Object,TVisRender* Render);
    void UnRegisterInstance(TMyObject* Object);

    bool operator == (TClassNode*CN) const;
    bool operator != (TClassNode*CN) const;
    bool is (const TClassNode* CN) const;
    TClassNode* Find(const AnsiString& _Name);
    TClassNode* Find(const std::type_info & ti);
    void FillChildList (TMTList<TClassNode> *L);
    bool UniqueNameFlag;
    __property TClassNode* UniqueNameNode = {read = GetUniqueNameNode};
};

COMMONAL_API TMyObject* FindByGUID(TClassNode* CN,const AnsiString& aGUID);
COMMONAL_API TMyObject* FindByGUID(const AnsiString& aGUID);

namespace SPSObject
{
template <class TParent,class TChild>
void RegisterNewClass(TChild* NewInstance,bool Virtual,TCreateFunction CreateFunction)
{
    if ( TChild::StaticType == NULL )
    {
        if ( typeid(TChild) == typeid(TMyObject) )
        {
            TChild::StaticType = new TClassNode( TParent::StaticType,typeid(TChild),Virtual,CreateFunction );
            fClassHead = TChild::StaticType;
            NewInstance->DynamicType = TChild::StaticType;
            return;
        }
        if ( TParent::StaticType == NULL )
        {
            AnsiString Str = "Can not register class <";
            Str = Str + AnsiString(typeid(TChild).name());
            Str = Str + AnsiString(">, parent class is not registred.");
            throw EMyException(Str);
        }

        TChild::StaticType = ClassHead->Find(typeid(TChild));
        if ( TChild::StaticType == NULL )
            TChild::StaticType = new TClassNode( TParent::StaticType,typeid(TChild),Virtual,CreateFunction );
    }
    NewInstance->DynamicType = TChild::StaticType;
};
}
using namespace SPSObject;

//----RegTable
const int rtNone = -1;
const int rtMeta = 0;
const int rtUnit = 1;
const int rtNomenclatura = 2;

class TMyRegTree;
class TLuaAttribute;
template <class T> class TMTList;
template <class T> class TPointer;
template <class T> class TMDelTList;


class COMMONAL_API TMyRegObject :public TMyObject{
private:
    int FID;
    int FTable;
//    void UnReg();
    int GetSaveChildCount();
protected:
    int FImageIndex;
    void SetImageIndex(int newII);
    TMyRegObject *FParent;
    virtual void SetParent(TMyRegObject *_Parent);
    TMyRegTree *FMyTree;
    void SetMyTree(TMyRegTree *_MyTree);
//    bool Registered;
public:
    //--------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //--------------------------------
//    bool DoNotReg;
    TTreeNode *TN;
    TListItem *LI;
    TMTList<TMyRegObject> *ChildList;
    __property int ImageIndex = {read = FImageIndex, write = SetImageIndex};
    __property TMyRegObject *Parent = {read = FParent, write = SetParent};
    __property TMyRegTree *MyTree = {read = FMyTree, write = SetMyTree};
    virtual void OnChange();
    TMyRegObject();
    virtual ~TMyRegObject();
    __property int ID = {read = FID};
    __property int Table = {read = FTable};
/*    bool RegThis(int _Table,int _ID,const AnsiString& _Name);
    bool NewRegThis(int _Table,const AnsiString& PATTERN);
    bool ReRegThis(int _ID,const AnsiString& _Name);*/
    virtual void ToTree();
    virtual void FromTree();
    bool CheckFields();
    bool ServiceNode;
    __property int SaveChildCount = {read = GetSaveChildCount};
    bool In(TMyRegObject *Node);
    virtual void AssignLST(const TMyObject *Obj,TStringList *SKIP);

    /*TMDelLSTList*/TMDelTList<TLuaAttribute>* Attributes;
    char* GetAttributeValue(char *_name);
    TLuaAttribute* GetAttribute(char *_name);
    void SetAttributeValue(char *_name,char *_value);
    __int16 Tag1;
    int GetAttributeIndex(char* _name);
};

extern COMMONAL_API TClassNode* TMyRegObject::StaticType;
//---------------------------------------

class TMDelTList<AnsiString>;

class COMMONAL_API TGarbage {
public:
    TGarbage();
    ~TGarbage();
    TMDelTList<AnsiString>* StrGarbage;
    void AddStr(AnsiString* Str);
    void Clear();
};







//COMMONAL_API TClassNode *MTID (const std::type_info& ti);
COMMONAL_API void SelectClassesByName(const AnsiString &Name,TMTList<TClassNode> *L);
COMMONAL_API int MYSIMPLETYPE(const std::type_info& ti);
//COMMONAL_API bool MY_IS(const TMyObject *Obj,const std::type_info& ti);


COMMONAL_API int ErrorDlg(const AnsiString& Caption,TMsgDlgButtons Buttons);
COMMONAL_API int InfoDlg(const AnsiString& Caption,TMsgDlgButtons Buttons);
COMMONAL_API int WarningDlg(const AnsiString& Caption,TMsgDlgButtons Buttons);
COMMONAL_API int ConfirmDlg(const AnsiString& Caption,TMsgDlgButtons Buttons);

COMMONAL_API void ErrorMsg(const AnsiString& Caption);
COMMONAL_API void InfoMsg(const AnsiString& Caption);
COMMONAL_API void WarningMsg(const AnsiString& Caption);

class COMMONAL_API TTypeList{
public:
    TTypeList();
    virtual ~TTypeList(){};
    const std::type_info& tiInt;
    const std::type_info& tiDouble;
    const std::type_info& tiAnsiString;
    const std::type_info& tiIntVec;
    const std::type_info& tiBool;
    const std::type_info& tiBoolVec;
    const std::type_info& tiFloat;
    //const std::type_info& tiSignVec = typeid(TSignVec);
    const std::type_info& tiRect;
    const std::type_info& tiMBTi;
    const std::type_info& tiMBTf;
    const std::type_info& tiMyObject;
    const std::type_info& tiMyRegObject;
    const std::type_info& tiClassNode;

    TClassNode* mtidMyObject;
    TClassNode* mtidMyRegObject;
};

//COMMONAL_API TMyRegObject *MGTFindByID(int Table,int id);

COMMONAL_API extern TGarbage* fGarbage;
COMMONAL_API extern TClassNode* fClassHead;
COMMONAL_API TGarbage& GetGarbage();
COMMONAL_API TClassNode* GetClassHead();

COMMONAL_API void CallDialog(TComponent *Owner,TControl *Parent,TMyObject *Obj,int MT,const AnsiString& Text,void *Data);

typedef void (*TStdOut)(const AnsiString& Text,bool Clear);
COMMONAL_API void SetStdOut(TStdOut aStdOut);
COMMONAL_API void StdOut(const AnsiString& Text,bool Clear = false);
COMMONAL_API void StrOut(char* Text,bool Clear = false);

COMMONAL_API TMyObject* LuaCreateLocal(const AnsiString& ClassName);
COMMONAL_API TMyObject* LuaCreate(const AnsiString& ClassName);
COMMONAL_API bool ClassCheck(const TMyObject* Object,const TClassNode* _Class);

template <class T>
T* AssertCast(const AnsiString& FuncName,const TMyObject* Object)
{
    if (!Object)
        return NULL;
    if ( !T::StaticType )
    {
        AnsiString Str = "<ValidCast>: аргумент-класс не зарегистрирован.";
        throw EMyException(Str);
    }
    if ( !Object->DynamicType )
    {
        AnsiString Str = "<ValidCast>: аргумент-объект не зарегистрирован.";
        throw EMyException(Str);
    }
    if ( !Object->Is(T::StaticType) )
    {
        AnsiString Str = FuncName + AnsiString(": Expected instance of class - <");
        Str += T::StaticType->Name;
        Str += AnsiString(">, got - <");
        Str += Object->DynamicType->Name;
        Str += AnsiString(">.");
        throw EMyException(Str);
    }
    return (T*)Object;
}
#endif

