#include "monty.h"
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
	int line_number = 0;

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
		process_line(line, &line_number);
	}



	free(line);
	fclose(file);

	return (0);
}
