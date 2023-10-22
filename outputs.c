#include "monty.h"

/**
 * error_out - prints the error message to STDERR;
 * @filename: name of the executable;
 * Return: returns void;
 */

void error_out(char *filename, ...)
{
	va_list args;
	char *str;

	write(STDERR_FILENO, filename, _strlen(filename));

	va_start(args, filename);
	while (1)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			break;
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, str, _strlen(str));
	}
	va_end(args);

	write(STDERR_FILENO, "\n", 1);
}


