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
		free_all_located();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
/**
* monty_push_stack - The opcode push pushes an element to the stack.
* @new_node: the stack head
* @line_number: the number of the line
*/
void monty_push_stack(stack_t **new_node, unsigned int line_number)
{
	(void)line_number;
	if (saved_struct->top == NULL)
	{
		saved_struct->top = *new_node;
		saved_struct->front = *new_node;
	}
	else
	{
		(*new_node)->prev = saved_struct->top;
		saved_struct->top = *new_node;
	}
}

/**
* monty_push_queue - The opcode push pushes an element at the begnining.
* @new_node: the stack head
* @line_number: the number of the line
*/
void monty_push_queue(stack_t **new_node, unsigned int line_number)
{
	(void)line_number;
	if (saved_struct->front == NULL)
	{
		saved_struct->top = *new_node;
		saved_struct->front = *new_node;
	}
	else
	{
		saved_struct->front->prev = *new_node;
		(*new_node)->next = saved_struct->front;
		saved_struct->front = *new_node;
	}
}



/**
* monty_pall - The opcode pall prints all the values on the stack,
* starting from the top of the stack.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL)
	{
		stack_t *current_node = *stack;

		while (current_node != NULL)
		{
			printf("%d\n", current_node->n);
			current_node = current_node->prev;
		}
	}

}


/**
* monty_pint - The opcode pint prints the value at the top of
* the stack, followed by a new line.
* @stack: a double pointer to stack_t structure
* @line_number: the line of the opcode
*/

void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all_located();
		exit(EXIT_FAILURE);
	}
}


