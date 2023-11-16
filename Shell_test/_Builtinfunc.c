#include "Shell.h"

/** Names of functions used **/

int print_env(char **argv);
int changeworking_dir(char **argv);
int exit_simple_shell(char **argv);
int modify_env(char **argv);


/**
 * printenv - function that prints enviro variable.
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
 * change_working_dir - c function that changes working directory
 * @argv: argument variable.
 *
 * Return: 0 on success, -1 if failure.
 */

int changeworking_dir(char **argv)
{
	char *path;
	char new_dir[PATH_MAX], old_dir[PATH_MAX];

	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
		path = _getenv("Home");
	else if (_strcmp(argv[1], "-") == 0)
		path = _getenv("oldpwd");
	else
		path = argv[1];

	if (access(path, X_OK) != 0)
		(path)
		    ? dprintf(STDERR_FILENO,
			      "./hsh: 1: cd: can't cd to %s\n", path)
		    : 0;

	/** Function to get old pathwd **/
	if (getcwd(old_dir, sizeof(old_dir)) == NULL)
		return (-1);

	/** Function to change directory**/
	if (chdir(path) != 0)
		return (-1);

	/** Function update old pathwd **/
	if (_setenv("oldpwd", old_dir, 1) != 0)
		return (-1);

	/** Function to get new pathwd **/
	if (getcwd(new_dir, sizeof(new_dir)) == NULL)
		return (-1);

	/** Function to update new pathwd **/
	if (_setenv("pwd", new_dir, 1) != 0)
		return (-1);

	return (0);
}

/**
 * modifyenv - Function that modifies current environment using setenv or unsetenv.
 * @argv: argument variable.
 *
 *
 * Return: 0 if successful, -1 if failed.
 */

int modify_env(char **argv)
{
	char *cmmnd = argv[0];
	int result;

	if (_strcmp(cmmnd, "setenv") == 0 &&
	    (argv[1] != NULL) && (argv[2] != NULL))
	{
		char *name = argv[1];
		char *value = argv[2];

		result = _setenv(name, value, 1);

		return (result);
	}

	if (_strcmp(cmmnd, "unsetenv") == 0 && (argv[1] != NULL))
	{
		char *name = argv[1];

		result = _unsetenv(name);

		return (result);
	}

	perror(": Environment not modified");
	return (-1);
}

/**
 * exit_simple_shell - a function that exits the shell when input is received
 * @argv: argument vector variable
 *
 * Return: 0 on successful exit.
 * and status if exit code is given
 */

int exit_simple_shell(char **argv)
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
