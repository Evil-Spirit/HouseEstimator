//---------------------------------------------------------------------------

#ifndef TriggerBlockVH
#define TriggerBlockVH
//---------------------------------------------------------------------------
const TriggerTypeCount=26;

const trConstruct=0;
const trEdit=1;
const trPaymentCount=2;
const trChangeSize=3;
const trStartEdit=4;
const trEndEdit=5;
const trRender2D=6;
const trSuccessDriver=7;
const trGlobal=8;
const trAddFloor=9;
const trUIExecute=10;
const trUIUpdate=11;
const trScope0=12;
const trScope1=13;
const trBeforeDriverStop=14;
const trLink = 15;
const trTechCheck = 16;
const trView = 17;
const trEditRender = 18;
const trAutoAlign = 19;
const trAfterCount = 20;
const trLinkCreate = 21;
const trLinkDestroyEl0 = 22;
const trLinkDestroyEl1 = 23;
const trCreate = 24;
const trEditFloor = 25;

const AnsiString TriggerTypeStr[TriggerTypeCount] = {
    AnsiString("On Model Assemble"),
    AnsiString("On Model Edit"),
    AnsiString("On Cost Calculate"),
    AnsiString("On Size Change"),
    AnsiString("Before Edit"),
    AnsiString("After Edit"),
    AnsiString("Draft"),
    AnsiString("Driver-Successful"),
    AnsiString("Global"),
    AnsiString("On Floor Add"),
    AnsiString("Execute"),
    AnsiString("Interface Update"),
    AnsiString("Target Object Area"),
    AnsiString("Floating Object Area"),
    AnsiString("Before Driver Stop"),
	AnsiString("Link"),
    AnsiString("On Technology Check"),
    AnsiString("Form Of Nomenclature"),
    AnsiString("Render On Edit"),
    AnsiString("Snap On Positioning"),
    AnsiString("After calculation"),
    AnsiString("On link create"),
    AnsiString("On link delete (Target)"),
    AnsiString("On link delete (Floating)"),
    AnsiString("On Element Create"),
    AnsiString("On Floor Edit")
    };
    
// According x - module index
// According y - trigger index
class TLuaModule;
class COMMONAL_API TTriggerBlock : public TMyObject{
public:
    TTriggerBlock();
    virtual ~TTriggerBlock();
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    void SetName(const AnsiString &newName);
    /*TMDelLSTList*/TMDelTList<TLuaModule> *Modules;
    /*TMDelLSTList*/TMDelTList<TIntVec> *According;
    TMTList<TLuaModule> *FastRunList;
    void AddTrigger(int TriggerType);
    void DeleteTrigger(int TriggerType);
    bool Run(int TriggerType);
    bool Exists(int TriggerType);
    TLuaModule *GetModule(int TriggerType);
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual bool CheckFields();
    __property AnsiString Name = {read=FName, write=SetName};
};
extern COMMONAL_API TClassNode* TTriggerBlock::StaticType;
bool COMMONAL_API RunForm(TLuaModule* LM);


#endif
