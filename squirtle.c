#include "shell.h"
#include <stdio.h>

/**
 *sighandler - function to end when ctrl D is used
 *@n: parameter
 * Return - returns a void
 */
void sighandler(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n$ ", 4);
}



/**
 * main - Simple Shell
 * @argc: number of arguements
 * @argv: Arguments stored as string
 * Return: 0
 */

int main(int argc, char *argv[], char *envp[])

{
	char *buffer = NULL;
	size_t buffsize = 0;
	pid_t newProcess;
	ssize_t charCount;
	int status/* , index = 0 */;
	char **cmd, **path, *fullPath;

	if (argc < 1)
		return (-1);


	signal(SIGINT, sighandler);



	while (1)
	{
		write(STDERR_FILENO, "$ ", 2);
		charCount = getline(&buffer, &buffsize, stdin);

		if (*buffer == '\n')
			continue;
		if (charCount < 1)
			break;

		if (buffer[charCount - 1] == '\n')
			buffer[charCount - 1] = '\0';

		SHELLexit(buffer);



   /*exitShell(buffer;)*/
 /*array = */	cmd = vect(buffer, charCount, "\t\r\n ");
		path = PATHfind(envp);
		fullPath = exists(cmd[0], path);
   /* cd(array[0], array[1]); */
		newProcess = fork();

		if (newProcess < 0)
			perror(argv[0]);

		if (newProcess == 0)
		{
			execve(fullPath, cmd, envp);
			perror(argv[0]);
			freeArray(cmd);
		}
		else
		  {
			wait(&status);
			free(cmd[0]);
			free(cmd);
		  }
	}

	if (charCount < 0)
		write(STDERR_FILENO, "\n", 1);

	free(buffer);
 	/*while (cmd[index])
	{
	  free(cmd[index]);
		index++;
		free(cmd);
		}*/
	return (0);
}
