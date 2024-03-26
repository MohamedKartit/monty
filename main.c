#include "monty.h"

void start_running(stack_t **stack, FILE file)
{
	ssize_t r_line = 1;
	size_t size = 0;
	char *content;
	unsigned int counter = 0;

	while (r_line > 0)
	{
		content = NULL;
		r_line = getline(&content, &size, file);
		counter++;
		if (r_line > 0)
			// execute each command 
		free(content);
	}
}

int main(int ac, char **av)
{
	FILE *file;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	start_running(stack, file);
	clear_stack(stack);
	fclose(file);
}

