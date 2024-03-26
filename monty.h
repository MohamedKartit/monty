#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_infs - content infos
 * @content: line content
 * @arg: value
 * @file: pointer to the monty file
 * @types: stack or queue
 * Description: carries the content over the program
 */
typedef struct monty_infs
{
	char *content;
	char *arg;
	FILE *file;
	int types;
} monty_t;

extern monty_t monty;

void start_running(stack_t **stack, FILE *file);
int exec_func(char *content, stack_t **stack, unsigned int counter,
		FILE *file);
void clear_stack(stack_t *head);
void add_nodeint(stack_t **head, int n);
void add_queueint(stack_t **head, int n);

/*=============== Ops ================*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void divi(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, unsigned int counter);
void ft_queue(stack_t **head, unsigned int counter);
void ft_stack(stack_t **head, unsigned int counter);

#endif

