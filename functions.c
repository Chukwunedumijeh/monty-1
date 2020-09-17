#include "monty.h"

void functions_monty(stack_t **stack, char *command_f, unsigned int line_number)
{
	instruction_t funct_monty[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}};
	unsigned int stat_c;
	for (stat_c = 0; command_f != NULL; stat_c++)
	{

		if (strcmp(funct_monty[stat_c].opcode, command_f) == 0)
		{
			printf("%i", stat_c);
			funct_monty[stat_c].f(stack, line_number);
		}
	}
}