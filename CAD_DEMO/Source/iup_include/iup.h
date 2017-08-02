/** \file
 * \brief User API
 * IUP - A Portable User Interface Toolkit
 * Tecgraf: Computer Graphics Technology Group, PUC-Rio, Brazil
 * http://www.tecgraf.puc-rio.br/iup	mailto:iup@tecgraf.puc-rio.br
 *
 * See Copyright Notice at the end of this file
 * $Id: iup.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUP_H 
#define __IUP_H

#include <iupkey.h>
#include <iupdef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IUP_COPYRIGHT	"Copyright (C) 1994-2003 Tecgraf/PUC-Rio and PETROBRAS S/A"
#define IUP_RELEASE_VERSION "2.0.1"
#define IUP_RELEASE_DATE "2003/07/31"

typedef struct Ihandle_ Ihandle;
typedef int (*Icallback)(Ihandle*, ...);

/************************************************************************/
/*                      dialogos pre-definidos                          */
/************************************************************************/
int  IupGetFile    (char *arq);
void IupMessage    (char *title, char *msg);
int  IupAlarm      (char *title, char *msg, char *b1, char *b2, char *b3);
int  IupScanf      (const char *format, ...);
int  IupListDialog (int type, char *title, int size, char *lst[],
                      int op, int col, int line, int marks[]);

/************************************************************************/
/*                      Funcoes IUP                                     */
/************************************************************************/
char*     IupMapFont       (char *iupfont);
char*     IupUnMapFont     (char *driverfont);
int       IupMainLoop      (void);
int       IupLoopStep      (void);
int       IupOpen          (void);
void      IupClose         (void);
void      IupFlush         (void);
int       IupHelp          (char* url);
char*     IupVersion       (void);
char*     IupVersionDate   (void);

void      IupDetach        (Ihandle *n);
Ihandle*  IupAppend        (Ihandle *box, Ihandle *exp);

void      IupDestroy       (Ihandle *n);
int       IupPopup         (Ihandle *n, int x, int y);
int       IupShow          (Ihandle *n);
int       IupShowXY        (Ihandle *n, int x, int y);
int       IupHide          (Ihandle *n);
int       IupMap           (Ihandle *n);
Ihandle*  IupSetFocus      (Ihandle *n);
Ihandle*  IupGetFocus      (void);
void      IupSetLanguage   (char *lng);
char*     IupGetLanguage   (void);

char *    IupLoad          (char *fn);

void      IupSetAttribute  (Ihandle *n, char* a, char* v);
void      IupStoreAttribute(Ihandle *n, char* a, char* v);
Ihandle*  IupSetAttributes (Ihandle *n, char *e);
char*     IupGetAttribute  (Ihandle *n, char* a);
char*     IupGetAttributes (Ihandle *n);
int       IupGetInt        (Ihandle *n, char* a);
float     IupGetFloat      (Ihandle *n, char* a);
void      IupSetfAttribute (Ihandle *n, char* a, char* f, ...);
void      IupSetGlobal     (char* key, char* value);
void      IupStoreGlobal   (char* key, char* value);
char*     IupGetGlobal     (char* key);

Ihandle*  IupPreviousField  (Ihandle *h);  
Ihandle*  IupNextField      (Ihandle *h);

Icallback IupGetFunction   (char *n);
Icallback IupSetFunction   (char *n, Icallback fa);
char*     IupGetActionName (void);

Ihandle*  IupGetDialog     (Ihandle *n);
Ihandle*  IupGetHandle     (char *name);
Ihandle*  IupSetHandle     (char *name, Ihandle *exp);
int       IupGetAllNames   (char *names[], int n);
int       IupGetAllDialogs (char *names[], int n);
char*     IupGetName       (Ihandle* n);

char*     IupGetType       (Ihandle *n);

Ihandle*  IupCreate        (char *class_name);
Ihandle*  IupCreatev       (char *name, Ihandle **children);
Ihandle*  IupCreatep       (char *name, Ihandle* first, ...);
Ihandle*  IupVbox          (Ihandle *exp, ...);
Ihandle*  IupZbox          (Ihandle *exp, ...);
Ihandle*  IupHbox          (Ihandle* exp,...);
Ihandle*  IupFill          (void);

Ihandle*  IupRadio         (Ihandle *exp);
Ihandle*  IupFrame         (Ihandle* exp);

Ihandle*  IupColor         (unsigned int r, unsigned int g, unsigned int b);
Ihandle*  IupImage         (unsigned width, unsigned height, char *pixmap);
Ihandle*  IupButton        (char* label, char* action);
Ihandle*  IupCanvas        (char* repaint);
Ihandle*  IupDialog        (Ihandle* exp);
Ihandle*  IupUser          (void);
Ihandle*  IupItem          (char* label, char* action);
Ihandle*  IupSubmenu       (char* label, Ihandle* exp);
Ihandle*  IupSeparator     (void);
Ihandle*  IupLabel         (char* label);
Ihandle*  IupList          (char* action);
Ihandle*  IupMenu          (Ihandle *exp,...);
Ihandle*  IupText          (char* action);
Ihandle*  IupMultiLine     (char* action);
Ihandle*  IupToggle        (char* label, char* action);
Ihandle*  IupFileDlg       (void);
Ihandle*  IupTimer         (void);

#ifdef __cplusplus
}
#endif

/************************************************************************/
/*                   Valores de retornos das funcoes IUP                */
/************************************************************************/
#define IUP_ERROR     1
#define IUP_NOERROR   0

/************************************************************************/
/*          Valores de retornos das callbacks da Aplicacao              */
/************************************************************************/
#define IUP_IGNORE    -1
#define IUP_DEFAULT   -2
#define IUP_CLOSE     -3
#define IUP_CONTINUE  -4

/************************************************************************/
/*        Valores dos parametros da funcoes IupPopup e IupShowXY        */
/************************************************************************/
#define IUP_CENTER    -1
#define IUP_LEFT      -2
#define IUP_RIGHT     -3
#define IUP_ANYWHERE  -4
#define IUP_MOUSEPOS  -5
#define IUP_TOP       IUP_LEFT
#define IUP_BOTTOM    IUP_RIGHT

#define IUP_SBUP       1
#define IUP_SBDN       2
#define IUP_SBPGUP     3
#define IUP_SBPGDN     4
#define IUP_SBPOSV     5
#define IUP_SBPGLEFT   6
#define IUP_SBPGRIGHT  7
#define IUP_SBLEFT     8
#define IUP_SBRIGHT    9
#define IUP_SBPOSH    10
#define IUP_SBDRAGH   11
#define IUP_SBDRAGV   12

/************************************************************************/
/*          Valores de para a callback IUP_SHOW_CB                      */
/************************************************************************/
#define IUP_SHOW       0
#define IUP_RESTORE    1
#define IUP_MINIMIZE   2

/************************************************************************/
/*       Valores dos botoes do mouse e das teclas modificadoras        */
/************************************************************************/
#define IUP_BUTTON1   '1'
#define IUP_BUTTON2   '2'
#define IUP_BUTTON3   '3'

#define isshift(r)    (r[0]=='S')
#define iscontrol(r)  (r[1]=='C')
#define isbutton1(r)  (r[2]==IUP_BUTTON1)
#define isbutton2(r)  (r[3]==IUP_BUTTON2)
#define isbutton3(r)  (r[4]==IUP_BUTTON3)
#define isdouble(r)   (r[5]=='D')

/************************************************************************/
/*     Permite que uma aplicacao em Windows comece pela funcao main     */
/************************************************************************/
#if defined (__WATCOMC__) || defined (__MWERKS__)
#ifdef __cplusplus
extern "C" {
int IupMain (int argc, char** argv); /* In C++ we have to declare the prototype */
}
#endif
#define main IupMain /* this is the trick for Watcom and MetroWerks */
#endif

/******************************************************************************
* Copyright (C) 1994-2003 Tecgraf/PUC-Rio and PETROBRAS S/A.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#endif
