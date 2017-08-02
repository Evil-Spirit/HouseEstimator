/** \file
 * \brief iupdial control.
 *
 * See Copyright Notice in iup.h
 * $Id: iupdial.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPDIAL_H 
#define __IUPDIAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* callbacks */
#ifndef ICTL_MOUSEMOVE_CB
#define ICTL_MOUSEMOVE_CB "MOUSEMOVE_CB"
#endif

#ifndef ICTL_BUTTON_PRESS_CB 
#define ICTL_BUTTON_PRESS_CB "BUTTON_PRESS_CB"
#endif

#ifndef ICTL_BUTTON_RELEASE_CB
#define ICTL_BUTTON_RELEASE_CB "BUTTON_RELEASE_CB"
#endif

#ifndef ICTL_DENSITY
#define ICTL_DENSITY "DENSITY"
#endif

/* Atributos */
#ifndef ICTL_HORIZONTAL
#define ICTL_HORIZONTAL "HORIZONTAL"
#endif

#ifndef ICTL_VERTICAL
#define ICTL_VERTICAL "VERTICAL"
#endif

#ifndef ICTL_CIRCULAR
#define ICTL_CIRCULAR "CIRCULAR"
#endif

#ifndef IUP_FGCOLOR
#define IUP_FGCOLOR "FGCOLOR"
#endif

#ifndef IUP_BGCOLOR
#define IUP_BGCOLOR "BGCOLOR"
#endif

/* iupdial */

Ihandle *IupDial(char *);
void IupDialOpen(void);

#ifdef __cplusplus
}
#endif

#endif
