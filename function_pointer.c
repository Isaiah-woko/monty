#include "monty.h"
/**
* initbuiltin - the function vector
* Return: The init function vector
*/
instruction_t *initbuiltin(void)
{


	static instruction_t function_vector[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"nop", monty_nop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"#", monty_hash},
		{NULL, NULL}
	};
	return (function_vector);
}

/**
* func_pointer - find the write funciton for the operation
* @opcode: the command
* @commands: the all command on the line
* @num_command: the number of commands
* @line_number: the number of the line
*/
void func_pointer(char *opcode, char **commands, int num_command,

	    unsigned int line_number)
{
	int function_num = 11, i;

	instruction_t *function_vector = initbuiltin();

	if (strcmp(opcode, "push") == 0)
	{
		handle_push_instruction(commands, line_number, num_command, function_vector);
	}
	else
	{
		for (i = 1; i < function_num; i++)
		{
			if (strcmp(opcode, function_vector[i].opcode) == 0)
			{
				function_vector[i].f(&(saved_struct->top), line_number);
				break;
			}
		}
		if (i == function_num)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_all_located();
			exit(EXIT_FAILURE);
		}
	}
}

/**
* handle_push_instruction - Handle the "push" instruction
* @commands: Array of command tokens
* @line_number: Line number in the file
* @num_command: the number of commands
* @function_vector: the function vector
*/
void handle_push_instruction(char **commands, unsigned int line_number,

			int num_command, instruction_t *function_vector)
{
	stack_t *new_node;

	/*check if the is number after the push*/
		if (num_command  == 1)
		{
			printf("L%u: usage: push integer\n", line_number);
			free_all_located();
			exit(EXIT_FAILURE);
		}
		/*meaning the argument to push is not a digit*/
		else if (isnumber(commands[1]) == 0)
		{
			printf("L%u: usage: push integer\n", line_number);
			free_all_located();
			exit(EXIT_FAILURE);
		}
		/*create new_node to push*/
		new_node =  create_new_node(atoi(commands[1]));
		function_vector[0].f(&new_node, line_number);
}

