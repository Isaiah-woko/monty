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

