#include "monty.h"
/**
* func_pointer - find the write funciton for the operation
* @opcode: the command
* @stack: the stack head
* @line_number: the number of the line
*/
void func_pointer(char *opcode, stack_t **stack, unsigned int line_number)
{
	int function_num = 2, i;

	instruction_t function_vector[] = {
		{"push", addToStack},
		{"pall", monty_pall},
		{NULL, NULL}
	};

	for (i = 0; i < function_num; i++)
	{
		if (strcmp(opcode, function_vector[i].opcode) == 0)
		{
			function_vector[i].f(stack, line_number);
		}

	}



}
