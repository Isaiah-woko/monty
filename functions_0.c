#include "monty.h"

/**
* create_new_node - create new node
* @n: the data
* Return: the node
*/
stack_t *create_new_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
/**
* addToStack - push to the stack at the top
* @new_node: the stack head
* @line_number: the number of the line
*/
void addToStack(stack_t **new_node, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (head == NULL)
	{
		head = *new_node;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		(*new_node)->prev = current;
		current->next = (*new_node);
	}
}

/**
* isnumber - check if string contian only digit number
* @numbers: the string number
* Return: 1 mean ture 0 is not number
*/

int isnumber(char numbers[])
{
	int i = 0;

	if (numbers[0] == '-')
		i = 1;
	while (numbers[i] != '\0')
	{
		if (!isdigit(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}
