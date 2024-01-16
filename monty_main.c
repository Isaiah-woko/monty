#include "monty.h"
#define _POSIX_C_SOURCE 200809L

/**
 * main - Entry point
 * @argc: the number of arguments passed
 * @argv: the argument vector of the string passed
 * Return: 0 Always success
*/

int main(int argc, char **argv)
{
	int file;
	char *line = NULL;
	ssize_t line_read;
	size_t len = 0;

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


	file = open(argv[1], O_RDONLY);

	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_read = getline(&line, &len, file)) != -1)
	{
		printf("%s", line);
	}

	if (line_read == -1)
		perror("read");
	close(file), free(line);

	free(line);
	close(file);

	return (0);
}
