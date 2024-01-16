#include "monty.h"

/**
* create_new_node - create new node
* @n: the data
* Return: the node
*/
stack_t *create_new_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
/**
* addToStack - push to the stack at the top
* @new_node: the stack head
* @line_number: the number of the line
*/
void addToStack(stack_t **new_node, unsigned int line_number)
{

	(void) line_number;
	if (top == NULL)
	{
		top = *new_node;
	}
	else
	{
		(*new_node)->prev = top;
		top = *new_node;
	}
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
			current_node = current_node->prev;
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
