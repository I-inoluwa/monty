#include "monty.h"

size_t array_len(char **array)
{
	size_t i;

	if (array == NULL)
		return (0);

	for (i = 0; array[i] != NULL; i++)
   	;

	return (i);
}


int print_tab(char **array)
{
	int i;

	if (array == NULL)
		return (0);

	for (i = 0; array[i] != NULL; i++)
   	{
        	printf("%s\n", array[i]);
    	}

	return (i);
}


void free_arr(char **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
