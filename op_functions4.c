#include "monty.h"

/**
 * rotr_stack - Function that rotates the stack to the bottom
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void rotr_stack(stack_t **top, unsigned int line_number __attribute__((unused)))
{
  stack_t *ptr = *top;
  
  /* EDGE case: If the stack is empty or only one node*/
  if (*top == NULL || top == NULL || (*top)->next == NULL)
    return;
     
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;

      ptr->next = *top;
      (*top)->prev = ptr;
      ptr->prev->next = NULL;
      ptr->prev = NULL;
      *top = ptr;
    }
}


/**
 * push_queue - Function that enqueue a node at the rear of a stack_t queue.
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void push_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *new_queue;
	stack_t *ptr = *top;

	new_queue = malloc(sizeof(stack_t));
	if (new_top == NULL && *top != NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_stack(&(*top));
		exit(EXIT_FAILURE);
	}
	else if (new_queue == NULL && *top == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (ptr->next != NULL)
	  ptr = ptr->next;
	
	new_top->n = number;
	new_top->prev = NULL;
	new_top->next = NULL;
	if (*top == NULL)
		*top = new_top;
	else
	{
		new_top->next = *top;
		(*top)->prev = new_top;
		*top = new_top;
	}
}
