#include "monty.h"

void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);

/**
 * push_func - Puts a new value into the stack's linked list.
 * @stack: pointer to the top node of the linked list.
 * @line_number: The active line number of the bytecodes file.
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *temp, *new_val;

	new_val = malloc(sizeof(stack_t));

	if (new_val == NULL)
	{
		set_op_token_err(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_token_err(no_int_err(line_number));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;

		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_token_err(no_int_err(line_number));
			return;
		}
	}
	new_val->a = atoi(op_toks[1]);

	/* to insert in front/'bottom' of the stack */
	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_val->prev_val = *stack;
		new_val->next_val = temp;
		if (temp)
			temp->prev_val = new_val;
		(*stack)->next = new_val;
	}
	else
	/* else use queue and insert at the back*/
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_val->prev_val = temp;
		new_val->next = NULL;
		temp->next = new_val;
	}
}

/**
 * pall_func - Prints value of stack_t linked list.
 * @stack: A pointer to the top node of the linked list.
 * @line_number: The active line num of a bytecodes file.
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->a);
		temp = temp->next;
	}
	(void)line_number;
}
