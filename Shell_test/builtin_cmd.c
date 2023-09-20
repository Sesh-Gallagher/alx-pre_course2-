#include "main.h"

/**
 * _builtInCmd - function to assist shell with exit function
 * @arg: argument vector
 *
 * Description: aids shell with function to exit shell prompts
 *
 * Return: 0 on success.
 *
 */

int _builtInCmd(char **arg)
{
	if (strcmp(arg[0], "exit") == 0)
	{
		_printstring("Exiting shell.... \n");
		exit(0);
	}
	else if (strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(arg[1]);
	}

	return (0);
}
