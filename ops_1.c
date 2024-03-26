#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (!monty.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		clear_stack(*stack);
		free(monty.content);
		fclose(monty.file);
		exit(EXIT_FAILURE); }
	else
	{
		if (monty.arg[0] == '-')
			j++;
		for (; monty.arg[j]; j++)
		{
			if (isdigit(monty.arg[j]) == 0)
			{
				flag = 1;
				break; }}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			clear_stack(*stack);
			free(monty.content);
			fclose(monty.file);
			exit(EXIT_FAILURE); }}
	n = atoi(monty.arg);
	if (monty.types == 0)
		add_nodeint(stack, n);
	else
		add_queueint(stack, n);
}

