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
		{"exit", exit_simple_shell},
		{"printenv", print_env},
		{"env", print_env},
		{"setenv", modify_env},
		{"unsetenv", modify_env},
		{"cd", changeworking_dir},
	};
	int i = 0;

	while (i < (int)(sizeof(builtins) / sizeof(builtins[i])))
	{
		if (_strcmp(cmd, builtins[i].name) == 0)
			return (builtins[i].func);
		i++;
	}
	return (NULL);
}
