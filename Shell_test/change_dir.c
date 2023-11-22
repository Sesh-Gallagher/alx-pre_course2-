#include "Shell.h"

/**
 * change_dir - #cd function that changes working directory
 * @argv: ...
 *
 * Return: 0 on success, -1 if failure.
 */

int change_dir(char **argv)
{
	char *pth;
	char _newdir[PATH_MAX], _olddir[PATH_MAX];

	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
		pth = _getenv("Home");
	else if (_strcmp(argv[1], "-") == 0)
		pth = _getenv("oldpwd");
	else
		pth = argv[1];

	if (access(pth, X_OK) != 0)
		(pth)
			? dprintf(STDERR_FILENO,
					"./hsh: 1: cd: can't cd to %s\n", pth)
			: 0;

	/** Function to get old pathwd **/
	if (getcwd(_olddir, sizeof(_olddir)) == NULL)
		return (-1);

	/** Function to change directory**/
	if (chdir(pth) != 0)
		return (-1);

	/** Function update old pathwd **/
	if (set_env("oldpwd", _olddir, 1) != 0)
		return (-1);

	/** Function to get new pathwd **/
	if (getcwd(_newdir, sizeof(_newdir)) == NULL)
		return (-1);

	/** Function to update new pathwd **/
	if (set_env("pwd", _newdir, 1) != 0)
		return (-1);

	return (0);
}
