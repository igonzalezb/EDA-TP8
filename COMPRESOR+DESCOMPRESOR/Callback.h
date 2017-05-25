#ifndef CALLBACK_H
#define CALLBACK_H

#include "main.h"
#if IAM == COMPRESSOR	

typedef struct {
	const char* path;
	int threshold;
} parametros_t;
#else

typedef struct {
	const char* path;
} parametros_t;
#endif

int Callback(char * Key, char* Value, void * Data);


#endif // _CALLBACK_H