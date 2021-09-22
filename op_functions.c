#include "monty.h"

/**
 * push_stack - Function that pushs a node at the top of a stack_t stack.
 *
 * Return: Always 0.
 */
void push_stack(stack_p **top, unsigned int line_number)
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
		return;
	}
	if (*top == NULL)
		*top = new_top;
	else
	{
		new_top->next = *top;
		(*top)->prev = new_top;
		*top = new_top;
	}
}

/**
 * pall_stack - Funtion that prints all the values on the stack_t stack
 * starting form the top of the stack
 *
 * Return: Always 0.
 */
void pall_stack(stack_p **top,unsigned int __attribute__((unused))line_number)
{
	stack_p *ptr = *top;

	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
		return;

	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**
 * pint_stack - Funtion that prints the value at the top of a stack_t stack
 * followed by a new line.
 *
 * Return: void 
 */
void pint_stack(stack_p **top, unsigned int line_number)
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
}

/**
 * pop_stack - Function that removes the top element of a stack_t stack
 *
 * Return: Always 0.
 */
void pop_stack(stack_p **top, unsigned int line_number)
{
	stack_p *ptr = *top;
	
	/* GUARD conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
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
	}
}

/**
 * swap_stack - Function that swaps the top two elementes of a stack_t stack
 *
 * Return: Always 0.
 */
void swap_stack(stack_p **top, unsigned int line_number)
{
	/* EDGE case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL || (*top)->next == NULL)
     {
         dprintf(2, "L%d: can't swap, stack too short", line_number);
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
		/* EDGE case: stack has more than two elements */
		else
		{
			(*top)->prev = (*top)->next;
			(*top)->next = (*top)->next->next;
			(*top)->next->prev = *top;
			(*top)->prev->next = *top;
			(*top)->prev->prev = NULL;
			(*top) = (*top)->prev;
		}
	}
}

/**
 * add_stack - Function that adds the top two elements of a stack_t stack
 *
 * Return: Always 0.
 */
void add_stack(stack_p **top, unsigned int line_number)
{
	int sum = 0;
	stack_p *tmp_node = *top;
	
	/* EDGE case: If the stack contains less than two elements */
     if (*top == NULL || top == NULL || (*top)->next == NULL)
      {
          dprintf(2, "L%d: can't add, stack too short", line_number);
          exit(EXIT_FAILURE);
      }
	 else
	 {
		 sum = (*top)->n + (*top)->next->n;
		 (*top) = (*top)->next;
		 (*top)->n = sum;
		 (*top)->prev = NULL;
		 free(tmp_node);
	 }
}


/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
void nop_stack(stack_p __attribute__((unused))  **top, unsigned int __attribute__((unused)) line_number)
{
	return;
}
