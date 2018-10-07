#ifndef __GETSTRING_H__
#define __GETSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	NUMCARACTERES		5
#define	ERROR_NOT_MEMORY       -1
#define	ERROR_OR_EOF	       -2
#define	RES_OK	       		0
#define ERR_OUT_OF_MEMORY       2



int getString(char** result);

#endif  // __GETSTRING_H__ 
