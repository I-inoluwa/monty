#include "monty.h"

instruction_t opcodes[] = {
		{"push", NULL},
		{"pall", _pall},
		{"pop", LIFO_pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nop", NULL},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

char **code_arr;
char **line_arr;

void global_define(void)
{
	code_arr = NULL;
	line_arr = NULL;
}
