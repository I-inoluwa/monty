#include "monty.h"

stack_t *_push(stack_t **stack, int val)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);

	node->n = val;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return (NULL);
	}

	(*stack)->prev = node;
	node->next = *stack;
	*stack = node;

	return (NULL);
}

stack_t *LIFO_pop(stack_t **stack, int val)
{
	stack_t *node = NULL;

	(void)val;
	if (*stack == NULL)
	{
		return (NULL);
	}

	node = *stack;
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	node->next = NULL;

	return (node);
}

stack_t *_pall(stack_t **stack, int val)
{
	/*int i = 0;*/
	stack_t *cur = NULL;

	(void)val;
	if (*stack == NULL)
		return (0);
	
	cur = *stack;
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
		/*i++;*/
	}

	return (NULL);
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
