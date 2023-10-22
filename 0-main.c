#include "monty.h"

/**
 * main - main function of the whole code;
 * @argc: len of the number of arguments passed to terminal;
 * @argv: an array of all arguments passed;
 * Return: returns (0) on success, or exits with (1) on fail.
 */

int main(int argc, char **argv)
{
	int xstat = 0;
	stack_t *stack = NULL;
	char *line = NULL;

	if (argc != 2)
	{
		error_out("USAGE", "monty file", NULL);
		exit(EXIT_FAILURE);
	}

	global_define();

	line = handle_file(argv[1], line);
	line_arr = split_str(line, "\n");
	free(line);

	start_operation(&stack);

	free_stack(stack);

	if (xstat == -1)
		exit(EXIT_FAILURE);

	free_arr(line_arr);

	return (0);
}

/**
 * start_operation - starts the whole operation of the monty processor;
 * @stack: a data_structure that contains all data passed;
 * Return: returns void;
 */

void start_operation(stack_t **stack)
{
	int ind = 0, xstat = 1;

	if (line_arr == NULL)
		return;

	for (ind = 0; line_arr[ind] != NULL; ind++)
	{
		if (!(handle_space_comment(line_arr[ind])))
			xstat = operations(xstat, ind + 1, stack);
		xstat++;
	}
}

/**
 * operations - performs an operation based on each line passed;
 * @line_number: line number of line being processed;
 * @index: index of line in the global line_array variable;
 * @stack: data structure containing all data passed;
 * Return: returns the line number in which current operation ends.
 */

int operations(int line_number, int index, stack_t **stack)
{
	char *line = NULL, *temp = NULL;
	int i = 0;

	if (line_arr == NULL)
		return (1);

	line = line_arr[index - 1];
	for (i = 0; line[i] == '`'; i++)
		line_number++;
	temp = _str_slice(line, i, _strlen(line) - 1);
	code_arr = split_str(temp, " \t");
	free(temp);

	if (code_arr == NULL)
		return (line_number);
	if (validity_check(code_arr[0], line_number))
	{
		free_global(*stack);
		exit(EXIT_FAILURE);
	}

	if (match_str(code_arr[0], "stack"))
		flag = 0;
	else if (match_str(code_arr[0], "queue"))
		flag = 1;
	else if (match_str(code_arr[0], "push"))
		_push(stack, line_number, code_arr[1], flag);
	else
		do_main(stack, code_arr, line_number);

	free_arr(code_arr);
	code_arr = NULL;
	return (line_number);
}

/**
 * do_main - an helper function to the operations function.
 * @stack: data_structure containing all data passed;
 * @code_arr: global variable representing a parsed line;
 * @line_number: line number of instruction being processed;
 * Return: returns nothing;
 */

void do_main(stack_t **stack, char **code_arr, int line_number)
{
	int i = 1;

	for (i = 3; opcodes[i].opcode != NULL; i++)
	{
		if (match_str(code_arr[0], opcodes[i].opcode))
		{
			if (opcodes[i].f != NULL)
				opcodes[i].f(stack, line_number);
			break;
		}
	}
}
