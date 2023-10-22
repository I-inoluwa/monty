#include "monty.h"

/**
 * _mod - function to divide (modulo) the second element by the top element;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

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

/**
 * _pchar - function to print the ascii char equivalent to the top element;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing, outputs error if value is not ASCII;
 */

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

/**
 * _pstr - function to elements of the stack in form of a string (using ASCII);
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

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

/**
 * _rotl - function to rotate the stack, making the top element the last;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

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

/**
 * _rotr - function to rotate the stack, making the bottom element the first;
 * @stack: main data structure of monty programme;
 * @line_number: line number of current operation;
 * Return: returns nothing;
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = NULL, *bot = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	cur = *stack;

	while (cur->next != NULL)
		cur = cur->next;

	bot = cur;
	bot->prev->next = NULL;
	bot->next = *stack;
	bot->prev = NULL;
	(*stack)->prev = bot;
	*stack = bot;

	(void)line_number;
}
