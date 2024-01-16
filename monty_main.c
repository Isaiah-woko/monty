#include "monty.h"
stack_t *head = NULL;
stack_t *top = NULL;

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
		if (is_empty_or_whitespace(line))
		{
			/* Skip processing for empty/whitespace lines */
			continue;
		}
		process_line(line, line_number, file);
	}
	free(line);
	free_dlistint();
	fclose(file);

	return (0);
}
/**
* free_dlistint -function that frees a dlistint_t list.
* @head: the head
*/
void free_dlistint(void)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}
