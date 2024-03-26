#include "monty.h"

/**
 * add_nodeint - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_nodeint(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(EXIT_FAILURE); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * add_queueint - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_queueint(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * ft_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void ft_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	monty.types = 1;
}

/**
 * ft_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void ft_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	monty.types = 0;
}

