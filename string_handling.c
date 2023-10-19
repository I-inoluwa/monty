#include "monty.h"

/**
 * _strdup - returns a pointer to a memory space, containing a str;
 * @str: a string to be copied.
 * Return: returns a pointer to a memory space;
 */

char *_strdup(char *str)
{
	char *s;
	int i, strrlen;

	if (str == NULL)
		return (NULL);
	strrlen = 0;
	for (i = 0; str[i]; i++)
	{
		strrlen++;
	}
	s = malloc((strrlen + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';

	return (s);
}

/**
 * handle_space - function to handle when the input is only spaces;
 * @line: non-parsed input string;
 * Return: returns (1) on success, (0) on failure;
 */

int handle_space(char *line)
{
	size_t ind = 0;

	if (line == NULL)
		return (1);

	for (ind = 0; (line[ind] == ' ' || line[ind] == '\t'); ind++)
		;

	if (line[ind] == '\0')
		return (1);

	return (0);
}
