#include "monty.h"

void functions_monty(stack_t **stack, char *command_f, unsigned int line_number)
{
	instruction_t funct_monty[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}};
	unsigned int i;
	for (i = 0; command_f != NULL; i++)
	{
		if (strcmp(funct_monty[i].opcode, command_f) == 0)
		{
			funct_monty[i].f(stack, line_number);
		}
	}
}