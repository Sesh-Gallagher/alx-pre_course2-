#include "Shell.h"

/**
 * createNew_env - Function that adds a new environment variable
 * @value: The value of variable
 * @name: Name of the variable to be used
 *
 * Return: 0 on successful, -1 if failed.
 */
int createNew_env(char *name, char *value)
{
	char **env_new_ptr;
        char **env_ptr;
	char **environ_new;
	size_t new_var_length = _strlen(name) + _strlen(value) + 2;
	char *new_var = malloc(new_var_length);

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

	env_ptr = environ;
	while (*env_ptr)
		env_ptr++;

	environ_new = malloc((env_ptr - environ + 2) * sizeof(char *));
	if (environ_new == NULL)
	{
		perror("Failed to allocate memory"), free(new_var);
		return (-ENOMEM);
	}
	
	env_new_ptr = environ_new;
	env_ptr = environ;
	while (*env_ptr)
		*env_new_ptr++ = *env_ptr++;

	*env_new_ptr++ = new_var;
	*env_new_ptr = NULL;
	environ = environ_new;
	return (0);
}

/**
 * set_env - Function that adds or changes an environment variable
 * @value: The value of variable
 * @name: The given name of variable
 * @
 * @overwrite: integer dedicated to modifying the environment
 *
 * Return: 0 on success. -1 if failed
 */
int set_env(char *name, char *value, int overwrite)
{
	size_t name_length = _strlen(name);
	size_t new_var_len = name_length + _strlen(value) + 2;
	char **env_ptr = environ;

	if (!overwrite)
		return (0); 
	while (*env_ptr)
	{
		if (_strncmp(*env_ptr, name, name_length) == 0 &&
		    ((*env_ptr)[name_length] == '='))
		{
			char *new_var = malloc(new_var_len);

			if (new_var == NULL)
			{
				perror("Failed to allocate memory");
				return (-1);
			}

			new_var = _strcat(new_var, name, value, '=');

			*env_ptr = new_var;

			free(new_var);
			return (0);
		}
		env_ptr++;
	}

	return (createNew_env(name, value));
}

/**
 * _unsetenv - removes an environment variable
 * @name: name of variable
 *
 * Return: 0 if successful
 */
int _unsetenv(char *name)
{
	char **env_ptr;
	char **next_env_ptr;
	size_t name_len = _strlen(name);

	if (name == NULL)
	{
		perror("Invalid argument");
		return (-1);
	}
	env_ptr = environ;
	while (*env_ptr)
	{
		/* find environment variable to remove*/
		if (_strncmp(*env_ptr, name, name_len) == 0 && ((*env_ptr)[name_len] == '='))
		{
			free(*env_ptr);

			/*move the remaining variables up the array*/
			next_env_ptr = env_ptr + 1;
			while (*next_env_ptr)
				*env_ptr++ = *next_env_ptr++;

			*env_ptr = NULL;

			return (0);
		}
		env_ptr++;
	}

	return (-1); /*variable not found*/
}

/**
 * _getenv - gets an environment variable.
 * @name: variable name.
 *
 * Return: returns pointer to value in environment or NUll if not found.
 */
char *_getenv(const char *name)
{
	char **environ_copy;
	char *current_var;
	unsigned int length = _strlen(name);

	environ_copy = environ;
	while (*environ_copy != NULL)
	{
		current_var = *environ_copy;

		/*checks if the current VAR matches name*/
		if ((_strncmp(current_var, name, length) == 0) &&
		    (current_var[length] == '='))
		{
			return (current_var + length + 1);
			/*+1 is added to skip the '=' char*/
		}

		environ_copy++;
	}

	return (NULL);

}

/**
 * create_env_table - creates environment variables
 * @envp: array of strings
 *
 * Return: returns an array of strings containing environment variables.
 */

char **create_env_table(char **envp)
{
	/*Count the number of environment variables*/
	int count = 0, i;
	char **env;

	while (envp[count] != NULL)
		count++;

	/* Allocate memory for the array of environment variables*/
	env = (char **)malloc((count + 1) * sizeof(char *));
	if (env == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	memset(env, 0, (count + 1));

	/* Copy each environment variable to the new array*/
	for (i = 0; i < count; i++)
	{
		env[i] = _strdup(envp[i]);
		if (env[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}
	}
	/* Add a NULL terminator to the end of the array*/
	env[count] = NULL;

	return (env);
}
