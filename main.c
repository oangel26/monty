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
  char *str, *token1, *token2, *format;
  char line[BUFFER];
  unsigned int line_counter = 0;
  stack_t *top = NULL;
  void (*op_func)(stack_t**, unsigned int);
  
  format = NULL;
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
	      if ((strcmp(token1, "stack") == 0))
		{
		  format = "stack";
		  continue;
		}
	      if (strcmp(token1, "queue") == 0)
		{
		  format = "queue";
		  continue;
		}
	      /* format opcode is not placed */
	      if ((strcmp(token1, "push") == 0) && format == NULL)
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
	      /* if stack opcode formt is placed */
	      else if ((strcmp(token1, "push") == 0) && ((strcmp(format, "stack") == 0)))
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
	      /* if queue opcode formt is place */
	      else if ((strcmp(token1, "push") == 0) && (strcmp(format, "queue") == 0))
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
		      push_queue(&top, line_counter);
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
		      push_queue(&top, line_counter);
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
