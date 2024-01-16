#include "monty.h"

/**
* process_line - Construct a new process line object
* @line: the line number
* @line_number: the line number of the file
* @file: the file to free later on when we have exit
*/
void process_line(char *line, unsigned int line_number, FILE *file)
{
	char **words;
	int num_command;

	words = split_commands(line, &num_command, " \n");
	func_pointer(words[0], words, num_command, line_number, line, file);
	free_commands(words, num_command);
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
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			perror("strdup");
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
void free_commands(char **commands, int numofcommands)
{
	int i;

	for (i = 0; i < numofcommands; i++)
	{
		free(commands[i]);
	}
	free(commands);
}
