#include "monty.h"

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(*stack, line_number, "can't swap, stack too short", NULL);
	
	cur = (*stack)->next;
	(*stack)->prev = cur;
	(*stack)->next = cur->next;
	if (cur->next != NULL)
		cur->next->prev = *stack;
	cur->next = *stack;
	cur->prev = NULL;
	*stack = cur;
}

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL, *bot = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(*stack, line_number, "can't add, stack too short", NULL);
	
	top = *stack;
	bot = (*stack)->next;
	bot->n += top->n;
	
	LIFO_pop(stack, line_number);
}
