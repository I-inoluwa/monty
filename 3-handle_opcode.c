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
