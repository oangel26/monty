#include "monty.h"

/**
 * add_stack - Function that adds the top two elements of a stack_t stack
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void add_stack(stack_t **top, unsigned int line_number)
{
	int sum = 0;
	stack_t *tmp_node = *top;

/* EDGE case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL || (*top)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
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
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void nop_stack(stack_t **top __attribute__((unused)),
	       unsigned int line_number __attribute__((unused)))
{
}
