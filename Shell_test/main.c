#include "main.h"

/**
 * main - program used to initiate shell
 * @c: string input from client as stdin
 * @env: enviroment
 *
 * Return: 0 on success.
 *
 */

int main(int c, char **env)
{
	char *prompt =  "(Test_Shell)$ ", *buffer = NULL, *path;
	(void)c;
	pid_t Child_ID;
	size_t buffersize = 0;
	int status, i, j, exe;
	ssize_t num_chars;
	char *arg[11], *delim = " \n";

	while (1)
	{

	if (isatty(0))
		_printstring(prompt);

	num_chars = getline(&buffer, &buffersize, stdin);


	if (num_chars == -1)
	{
		free(buffer);
		exit(0);
	}

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = 0;
		i++;
	}

	j = 0;
	arg[j] = strtok(buffer, delim);
	while (arg[j])
	{
		arg[++j] = strtok(NULL, delim);
	}
	arg[j] = NULL;

	path = get_loc(arg[0]);

	if (path == NULL)
	{
		if (_builtInCmd(arg) != 0)
		{
			continue;
		}
		else
		_printstring("command not found\n");
		continue;
	}

	Child_ID = fork();
	if (Child_ID < 0)
	{
		_printstring("Forking failed");
		free(buffer);
		exit(0);
	}
	else if (Child_ID == 0)
	{
	exe = execve(path, arg, env);
		if (exe == -1)
		_printstring("Command not found\n");
	}
	else
		wait(&status);

	/*_printstring(buffer);*/

	}
	free(path);
	free(buffer);

	return (0);
}
