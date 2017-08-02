//---------------------------------------------------------------------------

#ifndef NomenclatureVH
#define NomenclatureVH

#include "MetaClasses.h"
//---------------------------------------------------------------------------
class TNomenclature :public TMetaNode{
private:
    TMetaElement* GetAssociated();
protected:
    double FSavePrice;
    double FSaveWeight;
    void SetSavePrice(double newPrice);
    void SetSaveWeight(double newWeight);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TNomenclature();
    TNomenclature(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TNomenclature(){};

    double Price;
    double Weight;

    AnsiString StringCode;
    AnsiString Meter;

    TIntVec Size;
    TIntVec Dimensions;
    AnsiString Memo;
    char* GetMemo(){return Memo.c_str();}
    char *GetStrCode(){return StringCode.c_str();}
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual bool UsedTrigger(int Trigger);
    TPointer<TMetaElement> PME;
    __property TMetaElement* Associated = {read = GetAssociated};
    __property double SavePrice = {read = FSavePrice,write = SetSavePrice};
    __property double SaveWeight = {read = FSaveWeight,write = SetSaveWeight};
//    /*TMDelLSTList*/TMDelTList< TPointer<TNomenclature> > PEOPLE;
//    /*TMDelLSTList*/TMDelTList< TPointer<TNomenclature> > VEHICLES;

    bool CheckFields();
};
TClassNode* TNomenclature::StaticType = NULL;

TNomenclature* FindNomenclatureByID(int ID);
TNomenclature* FindNomenclatureByGUID(char* GUID);
TNomenclature* FindNomenclatureByName(char* Name);
TNomenclature* FindNomenclatureByStrCode(char* StrCode);
extern TNomenclature* CurNomenclature;

#endif
