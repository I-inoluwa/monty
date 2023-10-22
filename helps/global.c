#include "monty.h"

instruction_t opcodes[] = {
		{"push", NULL},
		{"stack", NULL},
		{"queue", NULL},
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
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

char **code_arr;
char **line_arr;
int flag;

void global_define(void)
{
	code_arr = NULL;
	line_arr = NULL;
	flag = 0;
}
