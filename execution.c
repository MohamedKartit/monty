#include "monty.h"

int exec_func(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *option;

	option = strtok(content, " \n\t");
	if (option && option[0] == '#')
		return (0);
	monty.arg = strtok(NULL, " \n\t");	
	while (opcodes[i].opcode && option)
	{
		if (strcmp(option, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, option);
		clear_stack(*stack);
		free(content);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	return (1);
}
