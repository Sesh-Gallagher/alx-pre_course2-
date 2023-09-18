#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0,  count = 0;
	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

int main(void)
{
	char *prompt =  "(Test_Shell)$ ", *buffer = NULL;
	pid_t Child_ID;
	size_t buffersize = 0;
	ssize_t num_chars;

	while (1)
	{

	_printstring(prompt);

	num_chars = getline(&buffer, &buffersize, stdin);


	if (num_chars == -1)
	{
		_printstring("Exiting shell ...");
		return (-1);
	}

	Child_ID = fork();

	_printstring(buffer);

	}
	free(buffer);

	return (0);
}
