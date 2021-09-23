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
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free(*top);
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

/**
 * free_stack - Function that frees the memory
 *
 * @top: Head of the linked list
 *
 */
void free_stack(stack_t **top)
{
	if (*top == NULL || top == NULL)
	{
		return;
	}
	while ((*top)->next != NULL)
	{
		*top = (*top)->next;
		free((*top)->prev);
	}
	free(*top);
}

/**
 * sub_stack - Function that subtracts the top two elements of a stack_t stack
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void sub_stack(stack_t **top, unsigned int line_number)
{
	int sub = 0;
	stack_t *tmp_node = *top;

/* EDGE case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		sub = (*top)->next->n - (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = sub;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}

/**
 * div_stack - Function that divides the top two elements of a stack_t stack
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void div_stack(stack_t **top, unsigned int line_number)
{
	int div = 0;
	stack_t *tmp_node = *top;

/* EDGE case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_stack(&(*top));
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*top)->next->n / (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = div;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}
