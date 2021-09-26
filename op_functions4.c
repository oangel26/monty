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
