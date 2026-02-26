// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef RegisterKernelVH
#define RegisterKernelVH
//---------------------------------------------------------------------------
extern COMMONAL_API bool KernelIsRegistered;
void COMMONAL_API RegisterKernel();
#endif
