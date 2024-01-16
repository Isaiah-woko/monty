#include "monty.h"

/**
* process_line - Construct a new process line object
* @line: the line number
* @line_number: the line number of the file
*/
void process_line(char *line, int *line_number)
{
	char **words;
	int num_command, i;

	words = split_commands(line, &num_command, " \n");
	printf("%d- ", *line_number);
	for (i = 0; i < num_command; i++)
	{
		printf("[%s] ", words[i]);
	}
	printf("\n");
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
