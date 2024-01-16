#include "monty.h"

/**
* addToStack - push to the stack at the top
* @stack: the stack head
* @line_number: the number of the line
*/
void addToStack(stack_t **stack, unsigned int line_number)
{
	(void) stack, (void) line_number;
	printf("you adding to the stack\n");
}



/**
 * monty_pall - a function  handle the pall opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL)
	{
		stack_t *current_node = *stack;

		while (current_node != NULL)
		{
			printf("%d\n", current_node->n);
			current_node = current_node->next;
		}
	}
}




/**
 * monty_pint - a function  handle the pint opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *current_node = *stack;

		printf("%d\n", current_node->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * monty_pop - a function  handle the pop opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_pop(stack_t **stack, unsigned int line_number)
{
	int popped;

	if (*stack != NULL)
	{
		stack_t *current_node = *stack;

		if (current_node->next != NULL)
		{
			*stack = current_node->next;
			current_node->next->prev = NULL;
		}
		else
		{
			*stack = NULL;
		}

		popped = current_node->n;
		free(current_node);

		printf("%d\n", popped);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}



/**
 * monty_nop - a function  handle the nop opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/**
	 * This function does nothing
	 * it acts as a placeholder
	*/
}
