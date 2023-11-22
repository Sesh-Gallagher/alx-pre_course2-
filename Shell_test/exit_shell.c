#include "Shell.h"

/** Names of functions used **/

int print_env(char **argv);
int exit_shell(char **argv);
int modify_env(char **argv);


/**
 * print_env - function that prints enviro variable.
 * @argv: argument variable.
 *
 * Return: 0 if successful, -1 if failed.
 */
int print_env(char **argv)
{
	int a = 0;

	(void)argv;

	while (environ[a] != NULL)
	{
		printf("%s\n", environ[a]);
		a++;
	}

	return (0);
}

/**
 * modify_env - Function that modifies thecurrent environment
 * using setenv or unsetenv.
 * @argv: ...
 *
 *
 * Return: 0 if successful, -1 if failed.
 */

int modify_env(char **argv)
{
	char *cmmnd = argv[0];
	int rslt;

	if (_strcmp(cmmnd, "setenv") == 0 &&
	    (argv[1] != NULL) && (argv[2] != NULL))
	{
		char *name = argv[1];
		char *value = argv[2];

		rslt = set_env(name, value, 1);

		return (rslt);
	}

	if (_strcmp(cmmnd, "unsetenv") == 0 && (argv[1] != NULL))
	{
		char *name = argv[1];

		rslt = unsetenv(name);

		return (rslt);
	}

	perror(": Enviro not modified");
	return (-1);
}

/**
 * exit_shell - a function that exits the shell when input is received
 * @argv: ...
 *
 * Return: 0 on successful exit.
 * and status if exit code is given
 */

int exit_shell(char **argv)
{
	char *ext_cde = argv[1];

	if (!ext_cde)
	{
		free_argv(argv);
		exit(0);
	}
	else
	{
		int code = atoi(ext_cde);

		free_argv(argv);
		exit(code);
	}

	return (0);
}
