//---------------------------------------------------------------------------

#ifndef SkinEngineVH
#define SkinEngineVH

#include "SUISkinEngine.hpp"

#define SkinEngine GetSkinEngine()
#define SkinFlie GetSkinFile()
COMMONAL_API extern TsuiSkinEngine *fSkinEngine;
COMMONAL_API TsuiSkinEngine *GetSkinEngine();
COMMONAL_API AnsiString GetSkinFile();


//---------------------------------------------------------------------------
#endif
