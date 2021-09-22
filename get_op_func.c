#include "monty.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
void (*get_op_func(char *op_code))(stack_p**, unsigned int)
{
	instruction_t op_fun[] = {
        {"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{NULL, NULL}
    };
	
	int i = 0;

	while (op_fun[i].opcode != NULL)
	{
		if ((strcmp(op_fun[i].opcode, op_code)) == 0)
			return (op_fun[i].f);
		i++;
	}
	return (NULL);
}
