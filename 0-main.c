#include "monty.h"

int main(int argc, char **argv)
{
	int xstat = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		error_out("USAGE", "monty file", NULL);
		exit(EXIT_FAILURE);
	}

	
	xstat = handle_file(argv[1], &stack);
	(void)xstat;

	free_stack(stack);

	return (0);
}

int operations(char *line, int line_number, stack_t **stack, int fd)
{
	char **code_arr = NULL;
	stack_t *node = NULL;
	int i = 0;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", LIFO_pop}
	};

	code_arr = split_str(line, " \t");
	if (code_arr == NULL)
		return (99);

	if (validity_check(code_arr[0], code_arr[1], line_number))
	{
		free(line);
		free_arr(code_arr);
		close(fd);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 3; i++)
	{
		if (match_str(code_arr[0], opcodes[i].opcode))
		{
			node = opcodes[i].f(stack, make_number(code_arr[1]));
			if (node != NULL)
				free(node);
			break;
		}
	}

	free_arr(code_arr);
	return (i);
}
