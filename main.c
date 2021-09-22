#include "monty.h"

#define BUFFER 1024

/**
 * main - check the code
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *str, *token;
	char line[BUFFER];
	unsigned int line_counter = 0;
	stack_t *top = NULL;
	void (*f)(stack_t, unsigned int);
	
	int number;

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
			dprintf(2,"Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Read file line by line until EOF */
			while ((str = fgets(line, BUFFER, fp)) != NULL)
			{
				line_counter++;
				token = strtok(str, " ");
				if (strcmp(token, "push") == 0)
				{
					token = strtok(NULL, " ");
					number = atoi(token);
					f = push_stack(&top, line_counter);
					printf("print the number: %d\n", number);
				}
				else
				{
					printf("get op func %s\n", token);
					
				}
			}
			fclose(fp);
		}
	}
}
