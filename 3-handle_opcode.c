#include "monty.h"

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL, *bot = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(*stack, line_number, "can't mod, stack too short", NULL);

	top = *stack;
	bot = (*stack)->next;
	if (top->n == 0)
		handle_error(*stack, line_number, "division by zero", NULL);
	bot->n %= top->n;

	LIFO_pop(stack, line_number);
}

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack == NULL)
		handle_error(*stack, line_number, "can't pchar, stack empty", NULL);

	top = *stack;
	if (top->n < 0 || top->n > 127)
		handle_error(*stack, line_number, "can't pchar, value out of range", NULL);

	printf("%c\n", top->n);
}

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = NULL;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	cur = *stack;
	while (cur != NULL)
	{
		if (cur->n <= 0 || cur->n > 127)
			break;
		printf("%c", cur->n);
		cur = cur->next;
	}
	printf("\n");

	(void)line_number;
}

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = NULL, *top = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	cur = *stack;
	top = *stack;

	while (cur->next != NULL)
		cur = cur->next;

	*stack = top->next;
	(*stack)->prev = NULL;
	cur->next = top;
	top->prev = cur;
	top->next = NULL;

	(void)line_number;
}
