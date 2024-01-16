#include "monty.h"
/**
 * initbuiltin - the function vector
 * Return: The init function vector
 */
instruction_t *initbuiltin(void)
{

	static instruction_t function_vector[] = {
		{"push", addToStack},
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
	int function_num = 1;
	int i;
	instruction_t *function_vector = initbuiltin();

	for (i = 0; i < function_num; i++)
	{
		if (strcmp(opcode, function_vector[i].opcode) == 0)
		{
			handle_function_push(opcode, commands, num_command, line_number);
			/*function_vector[i].f(stack, line_number);*/
		}

	}



}
/**
* handle_function_push - check if the commands is on the right format
* @opcode: the operation (push , pall , ...)
* @commands: the command vector of the line
* @num_command: the number of commands
* @line_number: the line number
*/
void handle_function_push(char *opcode, char **commands, int num_command,

			int line_number)
{
	stack_t *new_node;

	if (strcmp(opcode, "push") == 0)
	{
		/*check if the is number after the push*/
		if (num_command  == 1)
		{
			printf(" L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		}
		/*meaning the argument to push is not a digit*/
		else if (isnumber(commands[1]) == 0)
		{
			printf(" L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		}
		/*create new_node to push*/
		new_node =  create_new_node(atoi(commands[1]));
		addToStack(&new_node, line_number);
	}
}
