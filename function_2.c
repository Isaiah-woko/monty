#include "monty.h"

/**
* monty_pchar - The opcode pchar prints the char at the top of the stack,
* followed by a new line.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all_located();
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all_located();
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar(10);
}
/**
* monty_pstr - The opcode pchar prints the char at the top of the stack,
* followed by a new line.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pstr(stack_t **stack, unsigned int line_number)
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
