#include "Shell.h"

/** Names of functions to be used **/

int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/**
 * _strcmp - Function that compares two strings.
 * @s2: The 2nd string to be compared.
 * @s1: The 1rst string to be compared.
 *
 * Return: The positive byte diff if s1 > s2
 *         0 if s1 = s2
 *         Negative byte diff if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Function that compares two strings
 * @s2: The pointer to the 2nd string.
 * @s1: The pointer to the 1rst string.
 * @n: The 1rst and 2nd string number of bytes to compare.
 *
 * Return: 0 if s1 is shorter than s2. 0 if s1 and s2 match.
 * Greater than 0 if s1 is longer than s2.
 *
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	for (a = 0; s1[a] && s2[a] && a < n; a++)
	{
		if (s1[a] > s2[a])
			return (s1[a] - s2[a]);
		else if (s1[a] < s2[a])
			return (s1[a] - s2[a]);
	}
	if (a == n)
		return (0);
	else
		return (-15);
}

/**
 * _strspn - Function that gets the length of a prefix substring.
 * @accept: prefix to be measured.
 * @s: string to be searched.
 *
 * Return: number of bytes which consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int byts = 0;
	int indx;

	while (*s)
	{
		for (indx = 0; accept[indx]; indx++)
		{
			if (*s == accept[indx])
			{
				byts++;
				break;
			}
		}
		s++;
	}
	return (byts);
}

/**
 * _strchr - Function locates a char in a string.
 * @c: char to be searched.
 * @s: str to be located.
 *
 * Return: If char is found - a pointer to the first occurence.
 *         If char is not found - NULL.
 */

char *_strchr(char *s, char c)
{
	int indx;

	for (indx = 0; s[indx]; indx++)
	{
		if (s[indx] == c)
			return (s + indx);
	}

	return (NULL);
}
