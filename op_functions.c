#include "monty.h"

/**
 * push_stack - Function that pushs a node at the top of a stack_t stack.
 *
 * Return: Always 0.
 */
void *push_stack(stack_p **top, unsigned int line_number)
{
	stack_p *new_top;

	if (number == '\0')
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_top = malloc(sizeof(stack_p));
	if (new_top == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_top->n = number;
	new_top->prev = NULL;
	new_top->next = NULL;

	if (top == NULL)
	{
		free(new_top);
		return (NULL);
	}
	if (*top == NULL)
		*top = new_top;
	else
	{
		new_top->next = *top;
		(*top)->prev = new_top;
		*top = new_top;
	}
	return (*top);
}

/**
 * pall_stack - Funtion that prints all the values on the stack_t stack
 * starting form the top of the stack
 *
 * Return: Always 0.
 */
void *pall_stack(stack_p **top,unsigned int __attribute__((unused))line_number)
{
	stack_p *ptr = *top;

	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
		return (NULL);

	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
	return (*top);
}

/**
 * pint_stack - Funtion that prints the value at the top of a stack_t stack
 * followed by a new line.
 *
 * Return: void 
 */
void *pint_stack(stack_p **top, unsigned int line_number)
{
	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}
	return (*top);
}
