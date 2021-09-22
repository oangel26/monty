#include "monty.c"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
void (*get_op_func(char *opcode))(stack_t, unsigned int)
{
	instruction_t op_code[] = {
        {"push", push_stack},
        {"pall", pall_stack},
        {"pint", pint_stack},
        {"pop", op_div},
        {"swap", op_mod},
		{"add", op_div},
		{"nop", op_mod},
		{"sub", op_div},
		{"div", op_mod},
		{"mul", op_mod},
		{"mod", op_mod},
		{"pchar", op_mod},
		{"pstr", op_mod},
		{"rotl", op_mod},
		{"rotr", op_mod},
		{"stack", op_mod},
		{"queue", op_mod},
        {NULL, NULL}
    };

	int i = 0;

	while (*(op_code[i]).opcode != NULL)
	{
		if (strcmp(*(op_code[i]).opcode, *opcode) == 0)
			return (stack_t *)((op_code + i)->f);
		i++;
	}
	return (NULL);
}

