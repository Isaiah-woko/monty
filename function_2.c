#include "monty.h"

/**
 * monty_swap - a function  handle the swap opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	int size = getStackSize(*stack);
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	middle_node = top_node->prev;

	temp = top_node->n;
	top_node->n = middle_node->n;
	middle_node->n = temp;


}

