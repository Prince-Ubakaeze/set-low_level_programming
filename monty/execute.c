#include "monty.h"

void execute_opcode(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    int i = 0;
    instruction_t instructions[] = {
        {"push", f_push},
        {"pall", f_pall},
        {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"div", f_div},
        {"mul", f_mul},
        {NULL, NULL}
    };

    opcode = strtok(line, " \n\t\r");
    if (!opcode || opcode[0] == '#')
        return;

    op_arg = strtok(NULL, " \n\t\r");

    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    free(line);
    free_stack(*stack);
    exit(EXIT_FAILURE);
}
