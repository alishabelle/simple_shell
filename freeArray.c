#include "shell.h"

/**
 * freeArray - Free's the group of pointers
 *@cmd: parameter
 */

void freeArray(char **cmd)
{
	int index = 0;

	while (cmd[index])
	{
		free(cmd[index]);
		index++;
	}
		free(cmd);
}
