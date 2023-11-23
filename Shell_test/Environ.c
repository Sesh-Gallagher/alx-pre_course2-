#include "Shell.h"

/** Names of functions to be used **/

char **create_envtable(char **envp);
int createNew_env(char *name, char *value);
int set_env(char *name, char *value, int overwrite);
int unset_env(char *name);
char *get_env(const char *name);

/**
 * create_envtable - Function that creates an environment variable
 * @envp: an array of the string to be provided by the enviroment
 *
 * Return: returns an array of the string 
 * containing theenvironment variable.
 */

char **create_envtable(char **envp)
{
	char **enviro;
	int cnt = 0, a;

	while (envp[cnt] != NULL)
		cnt++;

	enviro = (char **)malloc((cnt + 1) * sizeof(char *));
	if (enviro == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	memset(enviro, 0, (cnt + 1));

	for (a = 0; a < cnt; a++)
	{
		enviro[a] = _strdup(envp[a]);
		if (enviro[a] == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}
	}

	enviro[cnt] = NULL;

	return (enviro);
}

/**
 * createNew_env - Function that adds a new environment variable
 * @value: The value of the variable in the enviro
 * @name: Name of the variable to be used in the envito
 *
 * Return: 0 on successful, -1 if failed.
 */

int createNew_env(char *name, char *value)
{
	char **enviro_ptr;
	char **environ_new;
	char **env_new_ptr;
	size_t new_var_len = _strlen(name) + _strlen(value) + 2;
	char *new_var = malloc(new_var_len);


	if (name == NULL || value == NULL)
	{
		perror("variable name or value not found");
		return (-1);
	}
	if (new_var == NULL)
	{
		perror("Failed to allocate memory");
		return (-ENOMEM);
	}
	new_var = _strcat(new_var, name, value, '=');

	enviro_ptr = environ;
	while (*enviro_ptr)
		enviro_ptr++;

	environ_new = malloc((enviro_ptr - environ + 2) * sizeof(char *));
	if (environ_new == NULL)
	{
		perror("Failed to allocate memory"),
			free(new_var);

		return (-ENOMEM);
	}

	env_new_ptr = environ_new;
	enviro_ptr = environ;
	while (*enviro_ptr)
		*env_new_ptr++ = *enviro_ptr++;

	*env_new_ptr++ = new_var;
	*env_new_ptr = NULL;
	environ = environ_new;
	return (0);
}

/**
 * set_env - Function that adds or changes an environment variable
 * @value: The value of variable
 * @name: The given name of variable
 * @overwrite: integer dedicated to modifying the environment
 *
 * Return: 0 on success. -1 if failed
 */

int set_env(char *name, char *value, int overwrite)
{
	size_t name_length = _strlen(name);
	size_t new_var_len = name_length + _strlen(value) + 2;
	char **enviro_ptr = environ;

	if (!overwrite)
		return (0);
	while (*enviro_ptr)
	{
		if (_strncmp(*enviro_ptr, name, name_length) == 0 &&
		    ((*enviro_ptr)[name_length] == '='))
		{
			char *new_var = malloc(new_var_len);

			if (new_var == NULL)
			{
				perror("Failed to allocate memory");
				return (-1);
			}

			new_var = _strcat(new_var, name, value, '=');

			*enviro_ptr = new_var;

			free(new_var);
			return (0);
		}
		enviro_ptr++;
	}

	return (createNew_env(name, value));
}

/**
 * unset_env - Function that removes an environment variable
 * @name: name of variable in the enviroment
 * Return: 0 if successful, -1 on failure.
 */

int unset_env(char *name)
{
	size_t nme_length = _strlen(name);
	char **_envptr;
	char **nxt_envptr;

	if (name == NULL)
	{
		perror("Invalid argument");
		return (-1);
	}
	_envptr = environ;
	while (*_envptr)
	{
		if (_strncmp(*_envptr, name, nme_length) == 0 && ((*_envptr)[nme_length] == '='))
		{
			free(*_envptr);

			nxt_envptr = _envptr + 1;
			while (*nxt_envptr)
				*_envptr++ = *nxt_envptr++;

			*_envptr = NULL;

			return (0);
		}
		_envptr++;
	}

	return (-1);
}

/**
 * get_env - function that gets an environment variable.
 * @name: variable name in the enviroment
 *
 * Return: return 0 if pointer to value in environment, NUll if not found.
 */

char *get_env(const char *name)
{
	unsigned int length = _strlen(name);
	char **enviro_cpy;
	char *curr_variable;

	enviro_cpy = environ;
	while (*enviro_cpy != NULL)
	{
		curr_variable = *enviro_cpy;

		if ((_strncmp(curr_variable, name, length) == 0) &&
		    (curr_variable[length] == '='))
		{
			return (curr_variable + length + 1);
		}

		enviro_cpy++;
	}

	return (NULL);
}
