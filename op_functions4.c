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
  
  /* EDGE case: If the stack is empty */
  if (*top == NULL || top == NULL)
    {
      dprintf(2, "L%d: can't rolt, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  /* EDGE case: if the stack is one only one node */
  else if ((*top)->next == NULL)
    return;
    
  else
    {
      while (ptr->next != NULL)
	ptr = ptr->next;

      (*top) = (*top)->next;
      ptr->next = (*top)->prev;
      (*top)->prev->next = NULL;
      (*top)->prev->prev = ptr;
      (*top)->prev = NULL;
    }
}
