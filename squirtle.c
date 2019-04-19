#include "shell.h"
#include <stdio.h>


void start(int n);

/**
 *exists - checking if the concatenated space exists
 *@s1: first string passed in
 *@s2: second string passed in
 * Return: returns a pointer to a char
 **/
char *exists(char *s1, char **s2)
{
	int i = 0, chk;
	char *ptr;

	for (; s2[i] != NULL; i++)
	{
		ptr = _strncon(s2[i], s1);
		chk = access(ptr, F_OK);
		if (chk == 0)
			return (ptr);
		else if (chk == -1)
			free(ptr);
	}
	return (NULL);
}
/**
 *_strncon - creates space to put concatenated strings into
 *@s1: first string passed
 *@s2: second string passed
 * Return: returns a pointer to a char
 */
char *_strncon(char *s1, char *s2)
{
	int lens1, lens2, x = 0, y = 0;
	char *fullPath;

	lens1 = _strlen(s1);
	lens2 = _strlen(s2);

	fullPath = malloc(sizeof(char) * (lens1 + lens2 + 2));

	if (fullPath == NULL)
		return (NULL);

	for (; s1[x] != '\0'; x++)
		fullPath[x] = s1[x];

	fullPath[x] = '/';
	x++;

	for (; s2[y] != '\0'; y++, x++)
		fullPath[x] = s2[y];

	fullPath[x] = '\0';

	return (fullPath);
}




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
 *@envp: environment passed in
* Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL, **cmd, **path, *fullPath;
	size_t buffsize = 0;
	pid_t newProcess;
	ssize_t charCount;
	int status/* , index = 0 */;

	if (argc < 1)
		return (-1);
	signal(SIGINT, sighandler);
	while (1)
	{	write(STDERR_FILENO, "$ ", 2);
		charCount = getline(&buffer, &buffsize, stdin);
		if (*buffer == '\n')
			continue;
		if (charCount < 1)
			break;
			if (buffer[charCount - 1] == '\n')
				buffer[charCount - 1] = '\0';
		SHELLexit(buffer);
		cmd = vect(buffer, charCount, "\t\r\n ");
		path = PATHfind(envp);
		fullPath = exists(cmd[0], path);
		newProcess = fork();
		if (newProcess < 0)
			perror(argv[0]);
		if (newProcess == 0)
		{	execve(fullPath, cmd, envp);
			perror(argv[0]);
			freeArray(cmd);
		}
		else
		{
			wait(&status);
			free(cmd[0]), free(cmd);
		}
	}
	if (charCount < 0)
		write(STDERR_FILENO, "\n", 1);
	free(buffer);
	return (0);
}


/**
 * start - makes interactive mode
 * Return: returns a void
 * @n: variable used for start function
*/
void start(int n)
{
	if (n < 0)
		return;
	signal(SIGINT, sighandler);

	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		fool.interactive = 1;
	if (fool.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
