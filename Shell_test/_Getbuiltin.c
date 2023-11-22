#include "Shell.h"

/**
 * handle_builtin_func - handles builtin function
 * @cmd: command to check if it's a builtin
 *
 * Return: builtin function, NULL if it doesn't exist
 */
int (*handle_builtin_func(char *cmd))(char **argv)
{
	builtin_t builtins[] = {
		{"exit", exit_shell},
		{"printenv", print_env},
		{"env", print_env},
		{"setenv", modify_env},
		{"unsetenv", modify_env},
		{"cd", change_dir},
	};
	int a = 0;

	while (a < (int)(sizeof(builtins) / sizeof(builtins[a])))
	{
		if (_strcmp(cmd, builtins[a].name) == 0)
			return (builtins[a].func);
		a++;
	}
	return (NULL);
}
