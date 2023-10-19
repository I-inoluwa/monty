#include "monty.h"

void _push(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *node = NULL;
	int val = 0;

	if (value == NULL || !(is_num(value)))
		handle_error(*stack, line_number, "usage", "push integer", NULL);
	
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_malloc_fail(*stack);

	val = make_number(value);
	node->n = val;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	(*stack)->prev = node;
	node->next = *stack;
	*stack = node;
}

void LIFO_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	(void)line_number;
	if (*stack == NULL)
		return;

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
