#include "monty.h"

/**
 * _push - function to push all passed data to stack;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * @value: value of data to be pushed;
 * @flag: (0) implies stack, (1) implies queue data structure;
 * Return: returns void;
 */

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

/**
 * _pint - function to print the top element of the stack;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		handle_error(*stack, line_number, "can't pint, stack empty", NULL);

	printf("%d\n", (*stack)->n);
}

/**
 * LIFO_pop - function to pop the top element of the stack;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

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

/**
 * _pall - function to print all elements of the stack;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

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
