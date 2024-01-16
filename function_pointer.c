#include "monty.h"
/**
 * initbuiltin - the function vector
 * Return: The init function vector
 */
instruction_t *initbuiltin(void)
{


	static instruction_t function_vector[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"nop", monty_nop},
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

	    unsigned int line_number, char *line, FILE *file)
{
	int function_num = 4, i;
	instruction_t *function_vector = initbuiltin();
	stack_t *new_node;

	if (strcmp(opcode, "push") == 0)
	{
		/*check if the is number after the push*/
		if (num_command  == 1)
		{
			printf("L%d: usage: push integer\n", line_number);
			free_commands(commands, num_command);
			free(line);
			fclose(file);
			free_dlistint();
			exit(EXIT_FAILURE);
		}
		/*meaning the argument to push is not a digit*/
		else if (isnumber(commands[1]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			free_commands(commands, num_command);
			free(line);
			fclose(file);
			free_dlistint();
			exit(EXIT_FAILURE);
		}
		/*create new_node to push*/
		new_node =  create_new_node(atoi(commands[1]));
		addToStack(&new_node, line_number);
	}
	else
	{
		for (i = 0; i < function_num; i++)
		{
			if (strcmp(opcode, function_vector[i].opcode) == 0)
			{
				function_vector[i].f(&top, line_number);
				break;
			}
		}
		if (i == function_num)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_commands(commands, num_command);
			free(line);
			fclose(file);
			free_dlistint();
			exit(EXIT_FAILURE);
		}

	}
}
