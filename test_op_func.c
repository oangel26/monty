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
	/* EDGE case: If the stack contains less than two elements */
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
		return (*top);
	}
}

/**
 * add_stack - Function that adds the top two elements of a stack_t stack
 *
 * Return: Always 0.
 */
stack_t *add_stack(stack_t **top, unsigned int line_number)
{
	int sum = 0;
	stack_t *tmp_node = *top;
	
	/* EDGE case: If the stack contains less than two elements */
     if (*top == NULL || top == NULL || (*top)->next == NULL)
      {
          fprintf(2, "L%d: can't add, stack too short", line_number);
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
	 return (*top);
}


/**
 * nop_stack - Function that does not do anything
 *
 * Return: Always 0.
 */
stack_t *nop_stack(stack_t **top, unsigned int line_number)
{
	return;
}
