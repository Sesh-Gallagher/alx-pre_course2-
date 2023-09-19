#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0,  count = 0;
	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

int main(int c, char **env)
{
	char *prompt =  "(Test_Shell)$ ", *buffer = NULL;
	(void)c;
	pid_t Child_ID;
	size_t buffersize = 0;
	int status, i, j;
	ssize_t num_chars;
	char *arg[10], *delim = " \n";

	while (1)
	{

	if (isatty(0))
		_printstring(prompt);

	num_chars = getline(&buffer, &buffersize, stdin);


	if (num_chars == -1)
	{
		free(buffer);
		exit (0);
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

	Child_ID = fork();
	if (Child_ID < 0)
	{
		_printstring("Forking failed");
		free(buffer);
		exit (0);
	}
	else if (Child_ID == 0)
	{
	if (execve(arg[0], arg, env) == -1);
		_printstring("Command not found\n");
	}
	else
		wait(&status);

	/*_printstring(buffer);*/

	}
	free(buffer);

	return (0);
}
