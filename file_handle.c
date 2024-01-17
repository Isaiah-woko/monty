#include "monty.h"

/**
* process_line - Construct a new process line object
* @line: the line number
* @line_number: the line number of the file
*/
void process_line(char *line, unsigned int line_number)
{
	char **words;
	int num_command;

	words = split_commands(line, &num_command, " \n");
	saved_struct->num_command = num_command;
	saved_struct->commands = words;
	func_pointer(words[0], words, num_command, line_number);
	free_commands(words, &num_command);
	saved_struct->num_command = num_command;
}

/**
* split_commands - split a line into individual commands separated by ';'
* @line: the input line
* @num_commands: pointer to store the number of commands
* @delimiters: the delimiters
* Return: array of commands
*/
char **split_commands(char *line, int *num_commands, const char *delimiters)
{
	char **commands = NULL;

	char *token;

	int i = 0;

	token = strtok(line, delimiters);

	while (token != NULL)
	{
		commands = realloc(commands, (i + 1) * sizeof(char *));
		if (commands == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		i++;
		token = strtok(NULL, delimiters);
	}

	*num_commands = i;
	return (commands);
}
/**
* free_commands - to free the commands
* @commands: the commands to free
* @numofcommands: the number of commands
*/
void free_commands(char **commands, int *numofcommands)
{
	int i;

	for (i = 0; i < *numofcommands; i++)
	{
		free(commands[i]);
	}
	*numofcommands = 0;
	free(commands);
}
