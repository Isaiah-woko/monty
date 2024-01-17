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
