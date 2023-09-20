#include "main.h"

/*
 * location - Function used to link path and command
 * @path: path of command provided by stdinput
 * @arg: argument vector
 *
 * Description: links path to commandinorder for shell
 *to action command
 *
 * Return: NULL.
 */

char *location(char *path, char *arg)
{
	char *path_cpy, *pathToken, *filePath;
	char *delim = ":", *buffr;

	path_cpy = strdup(path);

	pathToken = strtok(path_cpy, delim);

	filePath = malloc(strlen(arg) + strlen(pathToken) + 2);
	while (pathToken != NULL)
	{
		strcpy(filePath, pathToken);
		strcat(filePath, "/");
		strcat(filePath, arg);
		strcat(filePath, "\0");

		if (access(filePath, X_OK) == 0)
		{
			free(path_cpy);
				return (filePath);
		}
			pathToken = strtok(NULL, delim);
	}

	free(filePath);
	free(path_cpy);

	/*if (stat(arg, &buffr) == 0)*/
		/*return (arg);*/
	return (NULL);
}

/*
 * get_loc - Function to get location and path of command
 * input by client
 * @arg: argument vector
 *
 * Description: function to match arg with command
 * and get location
 *
 * Return: NULL.
 */

char *get_loc(char *arg)
{
	char *path;

	path = getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);
	}

	return (NULL);
}

