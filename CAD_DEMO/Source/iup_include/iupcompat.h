/** \file
 * \brief Internal exported functions. repeted from <iglobal.h>
 * should remove this file!!!!
 *
 * See Copyright Notice in iup.h
 * $Id: iupcompat.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPCOMPAT_H 
#define __IUPCOMPAT_H

#ifdef __cplusplus
extern "C" {
#endif

/* idrv.h */
void  iupdrvGetCharSize (Ihandle* n, int *w, int *h);
void  iupdrvResizeObjects (Ihandle *n);
void  iupdrvGetTextSize(Ihandle* h, char* text, int* size);

/* env.c */
int   iupGetSize (Ihandle* e, int* w, int *h);
int   iupGetColor(Ihandle* n, char *attr, unsigned int *r, unsigned int *g, unsigned int *b);
int   iupGetRGB (char *color, unsigned int *r, unsigned int *g, unsigned int *b);
void  iupSetEnv(Ihandle* n, char* e, char* v);
void  iupStoreEnv(Ihandle* n, char* e, char* v);
char* iupGetEnv(Ihandle* self, char* attr);
int   iupCheck (Ihandle *n, char *a);

/* calcsize.c  */
int iupSetSize(Ihandle* root);

/* tree.c */
typedef int (*Ifindchild_fn) ( Ihandle*,Ihandle*);
Ihandle* iupTreeGetParent( Ihandle* self );
Ihandle* iupTreeFindChild( Ihandle* self, Ifindchild_fn fn);
Ihandle* iupTreeGetFirstChild(Ihandle* self);
Ihandle* iupTreeGetBrother(Ihandle* self);
Ihandle* iupTreeAppendNode(Ihandle* root, Ihandle *n);
void iupTreeKill (Ihandle *n);

/* iup.c */
void  iupSetPosX(Ihandle* self, int x);
void  iupSetPosY(Ihandle* self, int y);
int   iupGetPosX(Ihandle* self);
int   iupGetPosY(Ihandle* self);
void  iupSetCurrentWidth(Ihandle* self, int w);
void  iupSetCurrentHeight(Ihandle* self, int h);
int   iupGetCurrentWidth(Ihandle* self);
int   iupGetCurrentHeight(Ihandle* self);
void* iupGetNativeHandle(Ihandle* self);
void  iupSetNativeHandle(Ihandle* self, void* handle);
void  iupSetNaturalWidth(Ihandle* self, int w);
void  iupSetNaturalHeight(Ihandle* self, int h);
int   iupGetNaturalWidth(Ihandle* self);
int   iupGetNaturalHeight(Ihandle* self);
int   iupHorResizable(Ihandle* self);
int   iupVertResizable(Ihandle* self);
void* iupGetImageData(Ihandle* self);

#ifdef __cplusplus
}
#endif

#endif
