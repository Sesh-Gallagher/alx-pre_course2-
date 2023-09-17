#include "main.h"

/**
 * main -
 * argv:
 * @c:
 *
 * Return: void
 *
 */

int main(int c, char **argv)
{
	(void)c;
	char *prompt = "(Test Shell)>$ ", *token, *buffer, *cpy_buffr;
	int i, num_tokens = 0;
	size_t size = 0;
	const char *delim = " \n";
	ssize_t num_chars;

	while (1)
	{

	printf("%s", prompt);
	num_chars = getline(&buffer, &size, stdin);

	if (num_chars == -1)
	{
		printf("Exiting Test_Shell>$ ....\n");
		return (-1);
	}

	cpy_buffr = malloc(sizeof(char) * num_chars);
	if (cpy_buffr == NULL)
	{
		perror("Memory allocation failed\n");
				return (-1);
	}

	strcpy(cpy_buffr, buffer);

	token = strtok(NULL, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(cpy_buffr, delim);
	for (i = 0; token != NULL, i++);
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		printf("%s\n", argv[i]);
	}
	
	printf("%s\n", buffer);
	}

	free(cpy_buffr);
	free(argv);
	free(buffer);

	return (0);
}
