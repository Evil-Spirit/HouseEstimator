/** \file
 * \brief iupcb control.
 *
 * See Copyright Notice in iup.h
 * $Id: iupcb.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPCB_H 
#define __IUPCB_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************\
* Initializes the color browser interface.                                  *
\***************************************************************************/
void IupColorBrowserOpen(void);

/***************************************************************************\
* Creates the color browser element.                                        *
\***************************************************************************/
Ihandle *IupColorBrowser(void);

/***************************************************************************\
* Control special attributes.                                               *
\***************************************************************************/
#define IUP_RGB "RGB"
#define IUP_CHANGE_CB "CHANGE_CB"
#define IUP_DRAG_CB "DRAG_CB"

#ifdef __cplusplus
}
#endif

#endif

