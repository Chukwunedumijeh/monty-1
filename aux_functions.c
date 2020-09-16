#include "monty.h"

/**
 * print_dlistint - print all elements of a dlistint_t list.
 * @h: poirnter to dlisntint_t struct.
 * Return: the number of nodes.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *h = *stack;
	(void)line_number;
​
	while (h != NULL)
	{
	printf("%i\n", h->n);
	h = h->next;
	}
}

/**
 * 
 * 
 * 
 * 
 */

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *node, *copy = *stack;
​
	if (stack == NULL)
	{
	fprintf(stderr, "L%d: usage: push integer", line_number);
	exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node)
	{
	exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->n = n;
    node->next = *stack;
	if (*stack)
	copy->prev = node;
    *stack = node;
}