#include "monty.h"

void str_slice(char *s1, int ind, int jnd, char *s2)
{
	int len = _strlen(s1);
	int i, j;

	if (s1 == NULL || s2 == NULL || jnd > len || ind > len || ind > jnd)
		return;

	if (ind < 0)
		ind = 0;

	for (i = ind, j = 0; (i <= jnd && s1[i]); i++, j++)
	{
		s2[j] = s1[i];
	}

	s2[j] = '\0';
}

/**
 * _str_slice - slices a string, and creates a buffer.
 */
char *_str_slice(char *str, int ind, int jnd)
{
	int len = abs(jnd - ind) + 2;
	char *buffer;

	/*will confirm conditions*/
	if (str == NULL || jnd < ind)
		return (NULL);

	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
	{
		perror("Malloc failed");
		return (NULL);
	}
	buffer[0] = '\0';
	str_slice(str, ind, jnd, buffer);

	return (buffer);
}
