#include "monty.h"
​
void functions_monty(stack_t **stack, char *command_f, unsigned int line_number)
{
    instruction_t funct_monty[] = {
	{"pall", pall},
	{"push", push},
	{NULL, NULL}
	};
    int j;
    unsigned int stat_c;
    for (stat_c = 0; j < 2 && command_f != NULL ; stat_c++)
    {
	if (strcmp(funct_monty[stat_c].opcode, command_f) == 0)
	{
	   funct_monty[j].f(stack, line_number);
	   stat_c = 1;
	   break;
	}
    }
​}