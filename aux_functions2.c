#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{

    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%u: can't add, stack too short\n", line_number);
        var_glob[1] = -1;
        return;
    }
    (*stack)->next->n = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
}
void nop((stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}