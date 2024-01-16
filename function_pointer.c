#include "monty.h"
/**
* func_pointer - find the write funciton for the operation
* @opcode: the command
* @stack: the stack head
* @line_number: the number of the line
*/
void func_pointer(char *opcode, stack_t **stack, unsigned int line_number)
{
	int function_num = 3, i;

	instruction_t function_vector[] = {
		{"push", addToStack},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{NULL, NULL}
	};

	for (i = 0; i < function_num; i++)
	{
		if (strcmp(opcode, function_vector[i].opcode) == 0)
		{
			function_vector[i].f(stack, line_number);
			break;
		}

	}

	if (i == function_num)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}



}
