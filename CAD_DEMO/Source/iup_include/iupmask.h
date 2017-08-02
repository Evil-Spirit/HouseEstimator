/** \file
 * \brief iupmask functions.
 *
 * See Copyright Notice in iup.h
 * $Id: iupmask.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPMASK_H 
#define __IUPMASK_H

#ifdef __cplusplus
extern "C" {
#endif

#define IUPMASK_ACTION    "iupmaskACTION"
#define IUPMASK_K_DEL     "iupmaskK_DEL"
#define IUPMASK_K_BS      "iupmaskK_BS"

#define IUPMASK_MATACTION "iupmaskMATACTION"
#define IUPMASK_MATK_DEL  "iupmaskMATK_DEL"
#define IUPMASK_MATK_BS   "iupmaskMATK_BS"

#define IUPMASK_MATCH_CB  "iupmaskMATCH_CB"
#define IUPMASK_MASK      "iupmaskMASK"

#define IUPMASK_AUTOFILL  "iupmaskAUTOFILL"
#define IUPMASK_CASE      "iupmaskCASE"

#define IUPMASK_TYPE		  "iupmaskTYPE"
#define IUPMASK_MIN		  "iupmaskMIN"
#define IUPMASK_MAX  	  "iupmaskMAX"

#define IUPMASK_TYPE_INT		 "I"
#define IUPMASK_TYPE_FLOAT		 "F"

#define IUPMASK_FLOAT      "[+/-]?(/d+/.?/d*|/./d+)"
#define IUPMASK_UFLOAT     "(/d+/.?/d*|/./d+)"
#define IUPMASK_EFLOAT		"[+/-]?(/d+/.?/d*|/./d+)([eE][+/-]?/d+)?"
#define IUPMASK_INT	      "[+/-]?/d+"
#define IUPMASK_UINT     	"/d+"

void iupmaskInit    (void);

int  iupmaskSet     (Ihandle *h, char *mask, int autofill, int   casei);
int  iupmaskSetInt  (Ihandle *h, int autofill, int   min , int   max);
int  iupmaskSetFloat(Ihandle *h, int autofill, float min , float max);

int  iupmaskCheck   (Ihandle *h);

int  iupmaskGet      (Ihandle *h, char   **val);
int  iupmaskGetFloat (Ihandle *h, float  *fval);
int  iupmaskGetDouble(Ihandle *h, double *dval);
int  iupmaskGetInt   (Ihandle *h, int    *ival);

int  iupmaskMatSet     (Ihandle *h, char *mask  , int autofill        , int casei, int lin, int col);
int  iupmaskMatSetInt  (Ihandle *h, int autofill, int   min, int   max, int lin, int col);
int  iupmaskMatSetFloat(Ihandle *h, int autofill, float min, float max, int lin, int col);

int  iupmaskMatCheck   (Ihandle *h, int lin, int col);

int  iupmaskMatGet      (Ihandle *h, char   **val, int lin, int col);
int  iupmaskMatGetFloat (Ihandle *h, float  *fval, int lin, int col);
int  iupmaskMatGetDouble(Ihandle *h, double *dval, int lin, int col);
int  iupmaskMatGetInt   (Ihandle *h, int    *ival, int lin, int col);

#ifdef __cplusplus
}
#endif

#endif
