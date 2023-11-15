#Include "Shell.h"

/** Names of functions to be used **/


int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);


/**
 * _strlen - Function that returns the length of a string.
 * @s: The pointer to the characters string.
 *
 * Return: The length of the char string.
 */

int _strlen(const char *s)
{
	int lngth = 0;

	if (!s)
		return (lngth);
	for (lngth = 0; s[lngth]; lngth++)
		;
	return (lngth);
}

/**
 * _strncat - Function that concantenates two strings where n number
 * of bytes are copied from the same source.
 * @dest: The pointer to destination string.
 * @src: The pointer to source string.
 * @n: number of bytes to copy from src.
 *
 * Return:  The pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t desti_len = _strlen(dest);
	size_t a;

	for (a = 0; a < n && src[a] != '\0'; a++)
		dest[desti_len + a] = src[a];
	dest[desti_len + a] = '\0';

	return (dest);
}

/**
 * _strcat - Function that concantenates two strings
 * @src: The pointer to source string
 * @dest: The pointer to destination string
 *
 * Return: The pointer to destination string
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strcpy - Function that copies string pointed to by src,
 * including the terminating null byte, to the buffer pointed by desti.
 * @src: The pointer to the sourcc of the string.
 * @dest: The pointer to the destination of copied string.
 *
 * Return: The pointer to destination.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}
