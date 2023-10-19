#include "monty.h"

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

void start_operation(stack_t **stack)
{
	int ind = 0, xstat = 0;

	if (line_arr == NULL)
		return;
	
	for (ind = 0; line_arr[ind] != NULL; ind++)
	{
		if (!(handle_space_comment(line_arr[ind])))
			xstat = operations(ind + 1, stack);

		(void)xstat;
	}
}

int operations(int line_number, stack_t **stack)
{
	char *line = NULL;
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", _pall},
		{"pop", LIFO_pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nop", NULL},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	if (line_arr == NULL)
		return (1);
	
	line = line_arr[line_number - 1];
	code_arr = split_str(line, " \t");
	if (code_arr == NULL)
		return (99);

	if (validity_check(code_arr[0], line_number))
	{
		free_global(*stack);
		exit(EXIT_FAILURE);
	}

	if (match_str(code_arr[0], "push"))
		_push(stack, line_number, code_arr[1]);

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (match_str(code_arr[0], opcodes[i].opcode))
		{
			if (opcodes[i].f == NULL)
				break;
			opcodes[i].f(stack, line_number);
			break;
		}
	}

	free_arr(code_arr);
	code_arr = NULL;
	return (i);
}

void free_global(stack_t *stack)
{
	free_stack(stack);
	free_arr(line_arr);
	free_arr(code_arr);
	code_arr = NULL;
	line_arr = NULL;
}
