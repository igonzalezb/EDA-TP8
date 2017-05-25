#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "callback.h"
#include <ctype.h>

#define ERROR_CALLBACK 0
#define TERMINADOR_CALLBACK '\0'
#define MAX_STRING 100
#define OK 1

int AllMin(char * string, char mayus[MAX_STRING]);

int Callback(char * Key, char* Value, void * Data)
{
	char key_min[MAX_STRING];
	for (int i = 0; i < MAX_STRING; i++) { key_min[i] = NULL; }

	if (Key != NULL)
	{
		if (AllMin(Key, key_min))
		{
			if (strcmp(key_min, "path") == false)
			{
				((parametros_t *)Data)->path = Value;
			}
#if IAM == COMPRESSOR
			else if (strcmp(key_min, "threshold") == false)
			{
				((parametros_t *)Data)->threshold = std::stoi(Value);
				if (((parametros_t *)Data)->threshold < 0 || ((parametros_t *)Data)->threshold > 765) {
					printf("Error: threshold must be between 0 & 765\n");
					return ERROR_CALLBACK;
				}
					

			}
#endif
			else
				return ERROR_CALLBACK;
		}
		else
			return ERROR_CALLBACK;

	}
	else
		return ERROR_CALLBACK;

	return OK;
}


int AllMin(char * string, char min[MAX_STRING])
{
	int i = 0;
	while ((string[i]) != TERMINADOR_CALLBACK)
	{
		min[i] = tolower(string[i]);
		i++;
	}

	return OK;
}