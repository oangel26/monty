#include "monty.h"

#define BUFFER 1024

int number;
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

	/* If the user doesnt give any file or more than one argu to the program */
	if (argc != 2)
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/* If user gives a file or arg to the program */
	else
	{
		fp = fopen(argv[1], "r");

		/* If it’s not possible to open the file */
		if (fp == 0)
		{
			dprintf(2, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Read file line by line until EOF */
			while ((str = fgets(line, BUFFER, fp)) != NULL)
			{
				line_counter++;
				token1 = strtok(str, " \n");
				/* print("token 1: %s\n", token1);*/
				if (strcmp(token1, "push") == 0)
				{
					token2 = strtok(NULL, "  \n");
					if (token2 == NULL)
					{
						/*print("se metio en token2 = NULL") */
						number = '\0';
						op_func = get_op_func(token1);
						op_func(&top, line_counter);
					}
					number = atoi(token2);
					op_func = get_op_func(token1);
					op_func(&top, line_counter);
				}
				else
				{
					op_func = get_op_func(token1);
					op_func(&top, line_counter);
				}
			}
			fclose(fp);
		}
	}
	return (0);
}
