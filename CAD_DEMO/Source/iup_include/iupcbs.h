/** \file
 * \brief Contains all function pointer typedefs.
 *
 * See Copyright Notice in iup.h
 * $Id: iupcbs.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPCBS_H 
#define __IUPCBS_H

typedef int (*IFn)(Ihandle*);
typedef int (*IFni)(Ihandle*, int);
typedef int (*IFnii)(Ihandle*, int, int);
typedef int (*IFniii)(Ihandle*, int, int, int);

typedef int (*IFnis)(Ihandle*, int, char *);
typedef int (*IFnsii)(Ihandle*, char*, int, int);
typedef int (*IFnsiii)(Ihandle*, char*, int, int, int);
typedef int (*IFniis)(Ihandle*, int, int, char*);
typedef int (*IFniiiis)(Ihandle*, int, int, int, int, char*);

#endif
