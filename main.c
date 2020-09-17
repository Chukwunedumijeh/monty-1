#include "monty.h"

char *lines_check(char *buffer, unsigned int line_number)
{
    char *token, *num_t;
    unsigned int i;

    token = strtok(buffer, " \t\n");
    if (strcmp(token, "push") == 0)
    {
        num_t = strtok(NULL, " \t\n");
        if (num_t == NULL)
        {
            printf("L%u: usage: push integer\n", line_number);
            return (NULL);
        }
        for (i = 0; num_t[i] != '\0'; i++)
        {
            /*HERE */
            if (num_t[i] < 48 || num_t[i] > 57)
            {
                printf("L%u: usage: push integer\n", line_number);
                return (NULL);
            }
        }
        var_glob[0] = atoi(num_t);
    }
    return (token);
}

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    FILE *file;
    char *buffer = NULL, *command_f = NULL;
    size_t size = 0;
    unsigned int line_number;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (-1 != getline(&buffer, &size, file))
    {
        line_number++;
        if (strlen(buffer) == 1 || strspn(buffer, " \t\n") == strlen(buffer))
            continue;
        command_f = lines_check(buffer, line_number);
        if (command_f == NULL)
            break;
        functions_monty(&stack, command_f, line_number);
    }
    free(buffer);
    fclose(file);
    return (0);
}