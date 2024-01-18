#include "monty.h"

/**
* monty_pchar - The opcode pchar prints the char at the top of the stack,
* followed by a new line.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && stack != NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n",
					line_number);
			free_all_located();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all_located();
		exit(EXIT_FAILURE);
	}
}
/**
* monty_pstr - The opcode pchar prints the char at the top of the stack,
* followed by a new line.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (*stack != NULL && stack != NULL)
	{
		while (temp != NULL && temp->n != 0 && (_isascii(temp->n) != 0))
		{
			printf("%c", temp->n);
			temp = temp->prev;
		}
		printf("\n");
	}
	else
	{
		printf("\n");
	}
}
/**
 * _isascii - check if number in between ascii numbers
 * @number: the number
 * Return: 1 if ture 0 if not
 */
int _isascii(int number)
{
	if (number >= 0 && number <= 127)
		return (1);
	return (0);
}


/**
 * monty_rotl - The opcode rotl rotates the stack to the top.
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node, *second_node;
	(void)line_number;

	top_node = *stack;

	if (top_node != NULL && top_node->prev != NULL)
	{
		while (top_node->prev != NULL)
		{
			top_node = top_node->prev;
		}

		second_node = *stack;
		*stack = second_node->prev;

		second_node->prev = NULL;

		top_node->prev = second_node;
	}
}



/**
 * monty_rotr - The opcode rotl rotates the stack to the top.
 * @stack: a double pointer to stack_t structure
 * @line_number: the line of the opcode
*/

oid monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_node;
	(void)line_number;

	if (*stack != NULL && (*stack)->prev != NULL)
	{
		last_node = *stack;

		while (last_node->prev != NULL)
		{
			last_node = last_node->prev;
		}

		last_node->prev = *stack;
		*stack = last_node->prev;
		last_node->prev = NULL;

		*stack = last_node;
	}
}