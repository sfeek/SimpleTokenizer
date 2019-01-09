#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

#define BUFFER 1024
#define MAX_TOKENS 20

int main (void) /* Program to demo strtok function use safely */
{
	char buff[BUFFER];
	char *single[MAX_TOKENS];
	int token_flag;
	int i;
	strcpy (buff, "This is a test of the program. I hope that it does not have memory errors."); /* String to tokenize */
	token_flag = tokenize (single, buff, MAX_TOKENS, " "); /* Call tokenizer */

	/* Check token result flags */
	if (token_flag == MAX_TOKENS_REACHED)
	{
		printf ("\nMaximum token count reached!\n");
		return 1;
	}

	if (token_flag == MEMORY_ERROR)
	{
		printf ("\nMemory allocation error occured!\n");
		return 1;
	}

	if (token_flag == NULL_BUFFER)
	{
		printf ("\nNULL buffer error occured!\n");
		return 1;
	}

	for (i = 0; i < token_flag; i++) /* Cycle through and print out the tokens */
	{
		printf ("%s\n", single[i]);
		free (single[i]); /* Free up the allocated token memory! */
	}

	return 0;
}
