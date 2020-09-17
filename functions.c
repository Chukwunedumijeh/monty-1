#include "monty.h"

void free_malloc(stack_t **head)
{
	stack_t *lista;
	if (head != NULL)
	{
		while (*head != '\0')
		{
			lista = *head;
			*head = (*head)->next;
			free(lista);
		}
		*head = NULL;
	}
}
void functions_monty(stack_t **stack, char *command_f, unsigned int line_number)
{
	instruction_t funct_monty[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};
	unsigned int i;
	int checker = 0;
	for (i = 0; command_f != NULL; i++)
	{

		if (strcmp(funct_monty[i].opcode, command_f) == 0)
		{
			funct_monty[i].f(stack, line_number);
			checker = 1;
			break;
		}
	}
	if (checker == 0)
	{
		printf("L%d: unknown instruction %s\n", line_number, command_f);
		var_glob[1] = -1;
		return;
	}
}