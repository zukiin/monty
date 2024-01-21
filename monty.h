#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKEN */
extern char **op_toks;

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
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* INTERPRETER FUNC DEFINITIONS */
void stack_free(stack_t **stack);
int stack_init(stack_t **stack);
int chk_mode(stack_t *stack);
void token_free(void);
unsigned int len_of_tok_arr(void);
int run_monty_func(FILE *script_fd);
void set_op_token_err(int error_code);

/* ERROR MESSAGING */
int usage_err(void);
int malloc_err(void);
int f_open_err(char *filename);
int unknown_op_err(char *opcode, unsigned int line_number);
int no_int_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int pint_err(unsigned int line_number);
int short_stack_err(unsigned int line_number, char *op);
int div_err(unsigned int line_number);
int pchar_err(unsigned int line_number, char *message);

#endif /* MONTY_H */
