#include "monty.h"

/**
* isnumber - check if string contian only digit number
* @numbers: the string number
* Return: 1 mean ture 0 is not number
*/

int isnumber(char numbers[])
{
	int i = 0;

	if (numbers[0] == '-')
		i = 1;
	while (numbers[i] != '\0')
	{
		if (!isdigit(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
* monty_nop - The opcode nop doesn’t do anything.
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


/**
 * getStackSize - a function for getting size of stack
 * @stack: a double pointer to stack_t structure
 * Return: size of stack
*/
int getStackSize(stack_t *stack)
{
	const stack_t *current = stack;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->prev;
	}

	return (count);
}
/**
* monty_pop -The opcode pop removes the top element of the stack.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{

	if (*stack != NULL)
	{
		stack_t *current_node = *stack;

		*stack = (*stack)->prev;

		free(current_node);

	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all_located();
		exit(EXIT_FAILURE);
	}
}
