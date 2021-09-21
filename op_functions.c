#include "monty.h"

/**
 * push_stack - Function that pushs a node at the top of a stack_t stack.
 *
 * Return: Always 0.
 */
stack_t *push_stack(stack_t **top, int n)
{
	stack_t *new_top;

	/* Node creation */
	new_top = malloc(sizeof(stack_t));
	/* GUARD condtiion if malloc failed */
	if (new_top == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_top->n = number;
	new_top->prev = NULL;
	new_top->next = NULL;
	
	/* GUARD condition if stack does not exists */
	if (top == NULL)
	{
		free(new_top);
		return (NULL);
	}
	/* top node creation if stack is empty (NULL) */
	if (*top == NULL)
		*top == new_top;
	else
	{
		new_top->next = *top;
		(*top)->prev = new_top;
		new_top = *top;
	}
	return (*top);
}

/**
 * pall_stack - Funtion that prints all the values on the stack_t stack
 * starting form the top of the stack
 *
 * Return: Always 0.
 */
stack_t *pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = *top;

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
 * Return: Always 0.
 */
stack_t *pint_stack(stack_t **top, unsigned int line_number)
{
	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
	{
		fprintf(2, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}

}

/**
 * pop_stack - Function that removes the top element of a stack_t stack
 *
 * Return: Always 0.
 */
stack_t *pop_stack(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = *top;
	
	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
	{
		fprintf(2, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* EDGE case: single element in stack */
		if ((*top)->next == NULL)
		{
			*top = (*top)->next;
			free(ptr);
		}
		else
		{
			*top = (*top)->next;
			free(ptr);
			(*top)->prev = NULL;
		}
		return (*top);
	}
}

/**
 * swap_stack - Function that swaps the top two elementes of a stack_t stack
 *
 * Return: Always 0.
 */
stack_t *swap_stack(stack_t **top, unsigned int line_number)
{
	stack_t *nptr = *top;
	
	if (*top == NULL || top == NULL || (*top)->next == NULL)
     {
         fprintf(2, "L%d: can't swap, stack too short", line_number);
         exit(EXIT_FAILURE);
     }
	else
	{
		/* EDGE case: stack has two elements */
		if ((*top)->next->next == NULL)
		{
			(*top)->prev = (*top)->next;
			(*top)->next->next = (*top);
			(*top)->next->prev = NULL;
			(*top)->next = NULL;
			*top = (*top)->prev;
		}
		else
		{
			(*top)->next->next->prev = *top;
			(*top)->prev = (*top)->next;
			(*top)->next->next = (*top);
			(*top)->next->prev = NULL;
			(*top)->next = ;
			*top =	(*top)->prev;
		}
	}

}

/**
 * add_stack - Function that adds the top two elements of a stack_t stack
 *
 * Return: Always 0.
 */
stack_t *add_stack(stack_t **top, unsigned int line_number)
{
}


/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, unsigned int line_number)
{
	
}



/* DE AQUI PA ABAJO */


/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}

/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, int n)
{
}
