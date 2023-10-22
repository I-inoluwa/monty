#include "monty.h"

void _push(stack_t **stack, unsigned int line_number, char *value, int flag)
{
	stack_t *node = NULL, *cur = NULL;
	int val = 0;

	if (value == NULL || !(is_num(value)))
		handle_error(*stack, line_number, "usage", "push integer", NULL);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_malloc_fail(*stack);

	val = atoi(value);
	node->n = val;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	if (flag == 0)
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
	else
	{
		cur = *stack;
		while (cur->next != NULL)
			cur = cur->next;

		cur->next = node;
		node->prev = cur;
	}

}

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		handle_error(*stack, line_number, "can't pint, stack empty", NULL);

	printf("%d\n", (*stack)->n);
}

void LIFO_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	(void)line_number;
	if (*stack == NULL)
		handle_error(*stack, line_number, "can't pop an empty stack", NULL);

	node = *stack;
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	node->next = NULL;
	free(node);
}

void _pall(stack_t **stack, unsigned int line_number)
{
	/*int i = 0;*/
	stack_t *cur = NULL;

	(void)line_number;
	if (*stack == NULL)
		return;

	cur = *stack;
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
		/*i++;*/
	}
}
