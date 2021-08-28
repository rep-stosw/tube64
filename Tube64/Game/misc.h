#ifndef _LOW_LEVEL_H_
#define _LOW_LEVEL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#include "Type.h"

/*
bit shifts left
*/
#define SHL6    * (1<< 6) /*<<  6*/
#define SHL8    * (1<< 8) /*<<  8*/
#define SHL16   * (1<<16) /*<< 16*/
#define OSHL8   *=(1<< 8) /*<<= 8*/
#define OSHL16  *=(1<<16) /*<<=16*/

extern uintptr_t DSEG3;
extern uintptr_t DSEG4;

extern char *MINIBuf;

void LoadDSEG(void);
void FreeDSEG(void);

u32 FileSize(FILE *f);

#ifdef __cplusplus
}
#endif

#endif
