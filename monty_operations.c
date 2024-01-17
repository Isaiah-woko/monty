#include "monty.h"

/**
 * monty_add - a function  handle the add opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
	int size = getStackSize(*stack);
	int result;
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;

	middle_node = top_node->prev;

	result = top_node->n + middle_node->n;

	middle_node->n = result;

	*stack = middle_node;

	free(top_node);
}



/**
 * monty_sub - a function  handle the sub opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/
void monty_sub(stack_t **stack, unsigned int line_number)
{
	int size = getStackSize(*stack);
	unsigned int result;
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	middle_node = top_node->prev;

	result = middle_node->n - top_node->n;

	middle_node->n = result;

	*stack = middle_node;

	free(top_node);
}




/**
 * monty_div - a function  handle the div opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
	int size = getStackSize(*stack);
	int result;
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;

	middle_node = top_node->prev;

	if (middle_node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = top_node->n / middle_node->n;

	middle_node->n = result;

	*stack = middle_node;

	free(top_node);
}




/**
 * monty_mul - a function  handle the mul opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int size = getStackSize(*stack);
	int result;
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;

	middle_node = top_node->prev;

	result = top_node->n * middle_node->n;

	middle_node->n = result;

	*stack = middle_node;

	free(top_node);
}




/**
 * monty_mod - a function  handle the mod opcode for monty
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int size = getStackSize(*stack);
	int result;
	stack_t *top_node, *middle_node;


	if (size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;

	middle_node = top_node->prev;

	if (top_node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = top_node->n % middle_node->n;

	middle_node->n = result;

	*stack = middle_node;

	free(top_node);
}



