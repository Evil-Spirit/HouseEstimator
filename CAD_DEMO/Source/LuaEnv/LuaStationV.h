//---------------------------------------------------------------------------

#ifndef LuaStationVH
#define LuaStationVH
class TLuaModule;
//---------------------------------------------------------------------------
class COMMONAL_API TLuaStation
{
  public:
  TMTList<TLuaModule> *LMS;
  TLuaStation();
  virtual ~TLuaStation();
  AnsiString Register(TLuaModule *Module);
  void UnRegister(TLuaModule *Module);
  void FindInAllModules(const AnsiString& Text, TFindOptions FO);
  TLuaModule* FindByName(const AnsiString& Name);
  void SaveData(FILE *f);
  void LoadData(FILE *f);
};

extern COMMONAL_API TLuaStation LuaStation;

#endif
