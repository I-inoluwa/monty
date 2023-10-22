#include "monty.h"

/**
 * handle_malloc_fail - handles situations in which there is a malloc failure;
 * Return: outputs an error, and exits with (1);
 */

void handle_malloc_fail(void)
{
	error_out("Error", "malloc failed", NULL);
	free_global(NULL);
	exit(EXIT_FAILURE);
}

/**
 * handle_error - handles error situations;
 * @stack: main data structure containing all data passed;
 * @line_number: current line number of instuction being processed;
 * Return: outputs and error, and exits with (1);
 */

void handle_error(stack_t *stack, int line_number, ...)
{
	char *line_no = NULL, *line_err = NULL;
	va_list args;
	char *str;

	line_no = num_to_str(line_number);
	line_err = join_strs("L", line_no, "");
	write(STDERR_FILENO, line_err, _strlen(line_err));

	va_start(args, line_number);
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

	free(line_no);
	free(line_err);
	free_global(stack);

	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees the main data structure of the monty programme;
 * @head: pointer to start of the data structure;
 * Return: returns nothing;
 */

void free_stack(stack_t *head)
{
	stack_t *cur = NULL;

	if (head == NULL)
		return;

	cur = head;
	while (cur != NULL)
	{
		cur = head->next;
		free(head);
		head = cur;
	}
}

/**
 * free_global - frees all global variables including the stack;
 * @stack: main data stucture of monty programme;
 * Return: returns nothing;
 */

void free_global(stack_t *stack)
{
	free_stack(stack);
	free_arr(line_arr);
	free_arr(code_arr);
	code_arr = NULL;
	line_arr = NULL;
}
