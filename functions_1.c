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
