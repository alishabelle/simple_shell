#include "shell.h"

/**
 * SHELLexit - exit shell
 *@buffer: parameter
 * Return - returns void
 */

void SHELLexit(char *buffer)
{
	char *goodbye = "exit";

	if (_strcmp(buffer, goodbye) == 0)
	{
		free(buffer);
		exit(0);
	}
}
