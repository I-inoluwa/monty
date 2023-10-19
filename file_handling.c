#include "monty.h"

/**
 * handle_file - handles file arguments in CLI;
 * @filename: file argument passed;
 * Return: returns xstat;
 */

int handle_file(char *filename, stack_t **stack)
{
	char c, *line = NULL;
	int i = 0, fd = 0, xstat = -1, bytes = 0;
	unsigned int line_number = 1;

	fd = open(filename, O_RDONLY);
	check_file_stat(fd, filename);
	while (1)
	{
		line = malloc(sizeof(char) * 1024);
		if (line == NULL)
		{
			error_out("Error", "malloc failed", NULL);
			close(fd);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < 1024; i++)
		{
			bytes = read(fd, &c, sizeof(char));
			if (bytes == -1 || bytes == 0 || c == '\n')
				break;
			line[i] = c;
		}
		line[i] = '\0';

		xstat = operations(line, line_number, stack, fd);

		free(line);
		if (bytes == 0 || bytes == -1)
			break;
		
		line_number++;
	}

	close(fd);
	return (xstat);
}

int validity_check(char *op_code, char *val, unsigned int line_number)
{
	char *err1 = NULL, *err2 = NULL, *line_no = NULL;

	if (!(opcode_in(op_code)))
	{
		line_no = num_to_str(line_number);
		err1 = join_strs("L", line_no, "");
		err2 = join_strs("unknown instruction", op_code, " ");
		error_out(err1, err2, NULL);
		free(err1);
		free(err2);
		free(line_no);
		return (1);
		/*free everything else that needs to be freed. e.g., close(fd)*/
	}

	if (match_str("push", op_code))
	{
		if (val == NULL || (!is_num(val)))
		{
			line_no = num_to_str(line_number);
			err1 = join_strs("L", line_no, "");
			error_out(err1, "usage", "push integer", NULL);
			free(err1);
			free(line_no);
			return (1);
		}
	}

	return (0);
}

int opcode_in(char *opcode)
{
	int ind = 0;

	for (ind = 0; allowed[ind] != NULL; ind++)
	{
		if (match_str(opcode, allowed[ind]))
			return (1);
	}

	return (0);
}

void check_file_stat(int fd, char *filename)
{
	char *err_msg = NULL;

	if (fd == -1)
	{
		err_msg = join_strs("Can't open file", filename, " ");
		error_out("error", err_msg, NULL);
		free(err_msg);
		exit(EXIT_FAILURE);
	}
}
