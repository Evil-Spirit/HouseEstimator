/** \file
 * \brief iupspeech control.
 *
 * See Copyright Notice in iup.h
 * $Id: iupspeech.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */

#ifndef __IUPSPEECH_H
#define __IUPSPEECH_H

#ifdef __cplusplus
extern "C" {
#endif

int IupSpeechOpen(void);
void IupSpeechClose(void);
Ihandle *IupSpeech(void);

#ifdef __cplusplus
}
#endif

#endif

