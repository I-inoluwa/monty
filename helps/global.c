#include "monty.h"

char *allowed[] = {
	"push",
	"pall",
	"pop",
	"pint",
	NULL
};

char **code_arr;
char **line_arr;

void global_define(void)
{
	code_arr = NULL;
	line_arr = NULL;
}
