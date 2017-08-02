/** \file
 * \brief iupgc pre-defined dialog.
 *
 * See Copyright Notice in iup.h
 * $Id: iupgc.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPGC_H 
#define __IUPGC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************\
* Initializes the color browser interface.                                  *
\***************************************************************************/
void IupGetColorOpen(void);

/***************************************************************************\
* Pops up a color choser dialog box. Returns the color in r, g and b.       *
* Returns 1 if the user pressed the OK button, 0 otherwise. The initial     *
* color shown is the color defined in the value of r, g and b at call-time. *
\***************************************************************************/
int IupGetColor(int x, int y, unsigned char *r, unsigned char *g, 
  unsigned char *b);

#ifdef __cplusplus
}
#endif

#endif
