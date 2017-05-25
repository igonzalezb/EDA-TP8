#ifndef CALLBACK_H
#define CALLBACK_H
#include "main.h"

typedef struct {
	const char* path;
#if IAM == COMPRESSOR	
	int threshold;
#endif

} parametros_t;

int Callback(char * Key, char* Value, void * Data);


#endif // _CALLBACK_H