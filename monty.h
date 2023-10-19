#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	stack_t *(*f)(stack_t **stack, int val);
} instruction_t;

/*
 *typedef struct instruction_s
 *{
 *	char *opcode;
 *	void (*f)(stack_t **stack, unsigned int line_number);
 *} instruction_t;
 */

extern char *allowed[];

void error_out(char *filename, ...);

char *num_to_str(unsigned int num);
int make_number(char *str);
int is_num(char *str);
size_t array_len(char **array);
void free_arr(char **array);

size_t _strlen(const char *s);
char *join_strs(char *s1, char *s2, char *delim);
int match_str(char *command, char *str);

int validity_check(char *op_code, char *val, unsigned int line_number);
void check_file_stat(int fd, char *filename);
int opcode_in(char *opcode);

char **split_str(char *str, char *delim);
int *get_str_len(char *str, int ix, char *delim);
int is_delim(char c, char *delim);
int get_word_count(char *str, char *delim);

stack_t *LIFO_pop(stack_t **stack, int val);
stack_t *_push(stack_t **stack, int val);
stack_t *_pall(stack_t **stack, int val);

int operations(char *line, int line_number, stack_t **stack, int fd);

void free_stack(stack_t *head);

int handle_file(char *filename, stack_t **stack);

#endif
