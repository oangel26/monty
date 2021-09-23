#include "monty.h"

/**
 * mul_stack - Function that multiplies the two elements of a stack_t stack
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void mul_stack(stack_t **top, unsigned int line_number)
{
	int mul = 0;
	stack_t *tmp_node = *top;

/* EDGE case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		mul = (*top)->next->n * (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = mul;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}
