// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef UsefulsH
#define UsefulsH
#include <stdio.h>
#include "compat/vcl_qt.h"
#include "MTL.h"
#include "VisComp.hpp"

// Borland ExceptAddr() stub - returns null pointer on non-Borland platforms
#ifndef __BORLANDC__
inline void* ExceptAddr() { return nullptr; }
#endif

#define MyShowExc(Exc) ErrorMsg( AnsiString("Exception ") + Exc.Message + AnsiString(" was caught at address ")+ IntToHex((int)(intptr_t)ExceptAddr(),8) )
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
const AnsiString MSG_ERR_4 =  AnsiString("Invalid polygon");//Â êëåòêàõ åñòü òî ÷åãî íåò â ïîëèãîíàõ
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
const AnsiString MSG_7 =  AnsiString(" must have one of following groups: "); // äîëæåí èìåòü îäíó èç ñëåäóþùèõ ãðóïï ñîåäèíåíèé
const AnsiString MSG_8 =  AnsiString("Act"); // Àêò -âûïîëíåííûõ îáúåìîâ â ñîîòâåòñòâèè ñ óòâåðæäåííûìè íîðìàìè


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
    static TMyObject* CreateFunction();
    virtual void KillFunction();
    //----------------------------------
    TClassNode* DynamicType;
    TMyObject();
    virtual ~TMyObject();
    int GetDepth() const;
    // Cross-platform property accessors (replaces Borland __property)
    TInstanceRegisterInfo* GetRegisterInfo() const { return FRegisterInfo; }
    TMyObject*       GetMyObjectParentProp()  const { return FMyObjectParent; }
    void             SetMyObjectParentProp(TMyObject* p) { SetMyObjectParent(p); }
    const AnsiString& GetNameProp()           const { return FName; }
    void             SetNameProp(const AnsiString& n) { SetName(n); }
    const AnsiString& GetGUIDProp()           const { return FGUID; }
#ifdef _MSC_VER
    __declspec(property(get=GetRegisterInfo))                    TInstanceRegisterInfo* RegisterInfo;
    __declspec(property(get=GetMyObjectParentProp, put=SetMyObjectParentProp)) TMyObject* MyObjectParent;
    __declspec(property(get=GetNameProp,  put=SetNameProp))      AnsiString Name;
    __declspec(property(get=GetGUIDProp))                        AnsiString GUID;
// Public accessor methods available on ALL platforms (complement __declspec(property))
    const AnsiString& GetName_()         const { return FName; }
    const AnsiString& GetGUID_()         const { return FGUID; }
    TMyObject*        GetMyObjectParent_() const { return FMyObjectParent; }
#else
    // GCC/Clang: expose Name, GUID, MyObjectParent as public property shims
    AnsiString& Name           = FName;
    AnsiString& GUID           = FGUID;
    TMyObject*& MyObjectParent = FMyObjectParent;
    TMyObject*& _GetMyObjParentRef() { return FMyObjectParent; }
    AnsiString& _GetNameRef()        { return FName; }
#endif
    AnsiString Description;

    const char *GetCharName()const{return FName.c_str();}
    const char *GetCharDescription()const{return Description.c_str();}
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
COMMONAL_API TMyObject* FindByGUID(const AnsiString& GUID);

class COMMONAL_API EMyException : public Exception{
public:
   EMyException(const AnsiString& _Error_Text);
   virtual ~EMyException(){};
};

//-------------------------TClassNode;
typedef TMyObject* (* TCreateFunction)();

class COMMONAL_API TInstanceRegisterInfo {
friend class TClassNode;
private:
    TMyObject* FMyObject;
    TVisRender* FRender;
public:
    TInstanceRegisterInfo();
    virtual ~TInstanceRegisterInfo(){};
    // Cross-platform accessors
    TMyObject*  GetObjectProp() const { return FMyObject; }
    TVisRender* GetRenderProp() const { return FRender; }
#ifdef _MSC_VER
    __declspec(property(get=GetObjectProp)) TMyObject*  Object;
    __declspec(property(get=GetRenderProp)) TVisRender* Render;
#endif
};

class COMMONAL_API TClassNode {
protected:
    AnsiString GetName() const;
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
    const AnsiString GetNameProp() const { return GetName(); }
#ifdef _MSC_VER
    __declspec(property(get=GetNameProp)) AnsiString Name;
#else
    // GCC: proxy struct that allows cn->Name to implicitly convert to AnsiString
    struct _NameProxy {
        const TClassNode* const _owner;
        explicit _NameProxy(const TClassNode* o) noexcept : _owner(o) {}
        operator AnsiString() const { return _owner->GetNameProp(); }
        bool operator==(const AnsiString& s) const { return _owner->GetNameProp() == s; }
        bool operator!=(const AnsiString& s) const { return _owner->GetNameProp() != s; }
        bool operator==(const char* s) const { return _owner->GetNameProp() == AnsiString(s); }
        bool operator!=(const char* s) const { return _owner->GetNameProp() != AnsiString(s); }
    } Name{this};
#endif
    bool Virtual;

    
    TClassNode *Parent;
    TQuickList *ChildList;
    TClassNode *GetChild(int i);
#ifdef _MSC_VER
    __declspec(property(get=GetChild)) TClassNode* Childs[];
#endif
    int GetChildCount();
#ifdef _MSC_VER
    __declspec(property(get=GetChildCount)) int ChildCount;
#endif
    void AddChild(TClassNode *CN);

    TQuickList* RegList;
    TInstanceRegisterInfo *GetRegInfo(int i);
    void AddRegInfo(TInstanceRegisterInfo *CN);
#ifdef _MSC_VER
    __declspec(property(get=GetRegInfo)) TInstanceRegisterInfo* RegInfo[];
#endif
    int GetRegInfoCount();
#ifdef _MSC_VER
    __declspec(property(get=GetRegInfoCount)) int RegInfoCount;
#endif
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
#ifdef _MSC_VER
    __declspec(property(get=GetUniqueNameNode)) TClassNode* UniqueNameNode;
#endif
};

COMMONAL_API TMyObject* FindByGUID(TClassNode* CN,const AnsiString& aGUID);
COMMONAL_API TMyObject* FindByGUID(const AnsiString& aGUID);

// Forward declaration needed by the SPSObject template below
extern COMMONAL_API TClassNode* fClassHead;
// Forward declare GetClassHead() so the template below can use it
COMMONAL_API TClassNode* GetClassHead();

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
    static TMyObject* CreateFunction();
    //--------------------------------
//    bool DoNotReg;
    TTreeNode *TN;
    TListItem *LI;
    TMTList<TMyRegObject> *ChildList;
    int  GetImageIndexProp() const { return FImageIndex; }
#ifdef _MSC_VER
    __declspec(property(get=GetImageIndexProp, put=SetImageIndex)) int ImageIndex;
#endif
#ifdef _MSC_VER
    __declspec(property(get=GetParentProp, put=SetParent)) TMyRegObject* Parent;
#endif
#ifdef _MSC_VER
    __declspec(property(get=GetMyTreeProp, put=SetMyTree)) TMyRegTree* MyTree;
#endif
    virtual void OnChange();
    TMyRegObject();
    virtual ~TMyRegObject();
    int GetIDProp() const { return FID; }
#ifdef _MSC_VER
    __declspec(property(get=GetIDProp)) int ID;
#endif
    int GetTableProp() const { return FTable; }
#ifdef _MSC_VER
    __declspec(property(get=GetTableProp)) int Table;
#endif
/*    bool RegThis(int _Table,int _ID,const AnsiString& _Name);
    bool NewRegThis(int _Table,const AnsiString& PATTERN);
    bool ReRegThis(int _ID,const AnsiString& _Name);*/
    virtual void ToTree();
    virtual void FromTree();
    bool CheckFields();
    bool ServiceNode;
#ifdef _MSC_VER
    __declspec(property(get=GetSaveChildCount)) int SaveChildCount;
#endif
    bool In(TMyRegObject *Node);
    virtual void AssignLST(const TMyObject *Obj,TStringList *SKIP);

    /*TMDelLSTList*/TMDelTList<TLuaAttribute>* Attributes;
    char* GetAttributeValue(char *_name);
    TLuaAttribute* GetAttribute(char *_name);
    void SetAttributeValue(char *_name,char *_value);
    qint16 Tag1;
    int GetAttributeIndex(char* _name);
};

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
        AnsiString Str = "<ValidCast>: àðãóìåíò-êëàññ íå çàðåãèñòðèðîâàí.";
        throw EMyException(Str);
    }
    if ( !Object->DynamicType )
    {
        AnsiString Str = "<ValidCast>: àðãóìåíò-îáúåêò íå çàðåãèñòðèðîâàí.";
        throw EMyException(Str);
    }
    if ( !Object->Is(T::StaticType) )
    {
        AnsiString Str = FuncName + AnsiString(": Expected instance of class - <");
        Str += T::StaticType->Name;
        Str += AnsiString(">, got - <");
        Str += Object->DynamicType->GetNameProp();
        Str += AnsiString(">.");
        throw EMyException(Str);
    }
    return (T*)Object;
}
#endif

