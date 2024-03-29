#include "monty.h"

/**
 * extend - reallocates new memory to a line, to accommodate more input;
 * @line: line to be reallocated;
 * Return: returns a  new line;
 */

char *extend(char *line)
{
	char *temp = NULL;
	int i = 0;

	if (line == NULL)
		return (NULL);

	temp = _strdup(line);
	free(line);

	line = malloc(sizeof(char) * (_strlen(temp) + 1024));
	if (line == NULL)
		handle_malloc_fail();

	for (i = 0; temp[i] != '\0'; i++)
	{
		line[i] = temp[i];
	}

	free(temp);
	return (line);
}

/**
 * handle_file - handles file arguments in CLI;
 * @filename: file argument passed;
 * @line: line argument passed, usually (NULL);
 * Return: returns a new line;
 */

char *handle_file(char *filename, char *line)
{
	char c, prev = '\n';
	int i = 0, fd = 0, bytes = 0;

	fd = open(filename, O_RDONLY);
	check_file_stat(fd, filename);

	line = malloc(sizeof(char) * 1025);
	if (line == NULL)
	{
		close(fd);
		handle_malloc_fail();
	}
	while (1)
	{
		if (i % 1024 == 0)
		{
			line[i] = '\0';
			line = extend(line);
		}

		bytes = read(fd, &c, sizeof(char));
		if (prev == '\n' && c == '\n')
			c = '`';
		if (bytes == -1 || bytes == 0)
			break;
		line[i] = c;
		if (c != '`')
			prev = c;
		i++;
	}
	line[i] = '\0';
	close(fd);

	return (line);
}

/**
 * validity_check  - checks if an opcode is a valid command;
 * @op_code: instruction to be checked;
 * @line_number: line number of said instruction;
 * Return: returns (0) if instruction is valid;
 */

int validity_check(char *op_code, unsigned int line_number)
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
	return (0);
}

/**
 * opcode_in - checks if an opcode is present in a list of commands;
 * @opcode: instruction being checked;
 * Return: returns (0) if no match;
 */

int opcode_in(char *opcode)
{
	int ind = 0;

	for (ind = 0; opcodes[ind].opcode != NULL; ind++)
	{
		if (match_str(opcode, opcodes[ind].opcode))
			return (1);
	}

	return (0);
}

/**
 * check_file_stat - determines if a file is a valid file;
 * @fd: file descriptor of file;
 * @filename: filename of the file;
 * Return: returns nothing;
 */

void check_file_stat(int fd, char *filename)
{
	char *err_msg = NULL;

	if (fd == -1)
	{
		err_msg = join_strs("Can't open file", filename, " ");
		error_out("Error", err_msg, NULL);
		free(err_msg);
		exit(EXIT_FAILURE);
	}
}
