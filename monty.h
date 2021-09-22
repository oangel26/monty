#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Declaration of global variable */
extern int number;

/* Declaration of data structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

/*
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
*/

void *push_stack(stack_t **top, unsigned int line_number);
/*
void *pall_stack)(stack_t **top, unsigned int line_number);
  void *pint_stack(stack_t **top, unsigned int line_number);
  void *pop_stack(stack_t **top, unsigned int line_number);
  void *swap_stack(stack_t **top, unsigned int line_number);
  void *add_stack(stack_t **top, unsigned int line_number);
  void *nop_stack(stack_t **top, unsigned int line_number);
  void *sup_stack(stack_t **top, int n);
  void *div_stack(stack_t **top, int n); */




/* Declaration of functions prototipes 
   void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number);*/

/*
void *push_stack(stack_t **top, unsigned int line_number);
void *pall_stack(stack_t **top, unsigned int line_number);
void *pint_stack(stack_t **top, unsigned int line_number);
void *pop_stack(stack_t **top, unsigned int line_number);
void *swap_stack(stack_t **top, unsigned int line_number);
void *add_stack(stack_t **top, unsigned int line_number);
void *nop_stack(stack_t **top, unsigned int line_number);
void *sup_stack(stack_t **top, int n);
void *div_stack(stack_t **top, int n);
*/



#endif /* MONTY_H */
