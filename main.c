#include "monty.h"

#define BUFFER 1024

int number;

/**
 * is_comment - check if the first char is a comment #
 *
 * @s: pointr to char (string)
 * Return: 0 on succes 1 if it fails.
 */
int is_comment(char *s)
{
	if (s[0] == '#')
		return (1);
	else
		return (0);
}

/**
 * is_number - check if an string is number
 *
 * @s: pointr to char (string)
 * Return: 0 on succes 1 if it fails.
 */
int is_number(char *s)
{
	if (s[0] == '-')
		s++;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
		{
			return (1);
		}
    }
	return (0);
}

/**
 * main - check the code
 *
 * @argc: Argument counter
 * @argv: Argument array
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *str, *token1, *token2;
	char line[BUFFER];
	unsigned int line_counter = 0;
	stack_t *top = NULL;
	void (*op_func)(stack_t**, unsigned int);

	if (argc != 2) /* If program is not executed correcly */
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else /* If user gives a file or arg to the program */
	{
		fp = fopen(argv[1], "r"); /* file open and read */
		if (fp == 0) /* If it’s not possible to open the file */
		{
			dprintf(2, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{ /* Read file line by line until EOF */
			while ((str = fgets(line, BUFFER, fp)) != NULL)
			{
				line_counter++; /* Line counter of the monty file */
				token1 = strtok(str, " \n"); /* opcode */
				if (token1 == NULL)
					continue;  /* if opcode is empty: conintue */
				if (is_comment(token1) == 1)
					continue; /* if first char is # continue */
				if (token1 == NULL)
					continue; /* if opcode is empty continue to next line */
				if (strcmp(token1, "push") == 0)
				{
					token2 = strtok(NULL, "  \n");
					if (token2 == NULL)
					{
						dprintf(2, "L%d: usage: push integer\n", line_counter);
						free_stack(&top);
						exit(EXIT_FAILURE);
					}
					else if ((strcmp(token2, "0") == 0) || (strcmp(token2, "-0") == 0))
					{
						number = 0;
						op_func = get_op_func(token1);
						op_func(&top, line_counter);
					}
					else
					{
						number = atoi(token2);
						if (number == '\0' || (is_number(token2) == 1))
						{
							dprintf(2, "L%d: usage: push integer\n", line_counter);
							free_stack(&top);
							exit(EXIT_FAILURE);
						}
						op_func = get_op_func(token1);
						op_func(&top, line_counter);
					}
				}
				else
				{
					op_func = get_op_func(token1);
					if (op_func == NULL)
					{
						dprintf(2, "L%d: unknown instruction %s\n", line_counter, token1);
						free_stack(&top);
						exit(EXIT_FAILURE);
					}
					op_func(&top, line_counter);
				}
			}
			fclose(fp);
		}
    }
	free_stack(&top);
	return (0);
}
