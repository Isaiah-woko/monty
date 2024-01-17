#include "monty.h"

sa_struct *saved_struct;



/**
* is_empty_or_whitespace - check if str is empty of just spaces
* @str: the string
* Return: 1 empty 0 not empty
*/
int is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))

		{
			return (0);  /* Not empty or whitespace*/
		}
		str++;
	}
	return (1);  /* Empty or whitespace*/
}
/**
* main - Entry point
* @argc: the number of arguments passed
* @argv: the argument vector of the string passed
* Return: 0 Always success
*/
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len;
	unsigned int line_number = 0;

	init_sa_struct();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		saved_struct->line = line, saved_struct->file = file;
		/*-----------if the line is comment*/
		if (line[0] == '#')
			continue;
		if (is_empty_or_whitespace(line))
		{
			continue;
		}

		process_line(line, line_number);
	}
	free_all_located();
	return (0);
}
/**
* init_sa_struct - init save_struct value
*/
void init_sa_struct(void)
{

	saved_struct = malloc(sizeof(sa_struct));
	if (saved_struct == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	saved_struct->top = NULL;
	saved_struct->file = NULL;
	saved_struct->line = NULL;
	saved_struct->num_command = 0;
	saved_struct->commands = NULL;
}
/**
* free_all_located - free all located memory
*/
void free_all_located(void)
{
	/*free top*/
	stack_t *current = saved_struct->top, *prev;
	int i;

	while (current != NULL)
	{
		prev = current->prev;
		free(current);
		current = prev;
	}
	saved_struct->top = NULL;

	/*free line and file*/
	free(saved_struct->line), fclose(saved_struct->file);
	/*free commands*/
	for (i = 0; i < saved_struct->num_command; i++)
	{
		free(saved_struct->commands[i]);
	}
	if (saved_struct->num_command != 0)
		free(saved_struct->commands);
	free(saved_struct);
}
