#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct save_instructe - struct to save results
 * @top: the top of the stack
 * @file: the file discripter
 * @line: the line in the file
 * @num_command: the number of command
 * @commands: the commands split it into vector
 */
typedef struct save_instructe
{
	stack_t *top;
	FILE *file;
	char *line;
	int num_command;
	char **commands;
} sa_struct;
extern sa_struct *saved_struct;
/*file and command handle */
void process_line(char *line, unsigned int line_number);
char **split_commands(char *line, int *num_commands, const char *delimiters);
void func_pointer(char *opcode, char **commands, int num_command,
		unsigned int line_number);
int isnumber(char numbers[]);
void handle_function_push(char *opcode, char **commands, int num_command,
			int line_number, instruction_t *function_vector);
void handle_push_instruction(char **commands, unsigned int line_number,
		int num_command, instruction_t *function_vector);
void free_all_located(void);
void init_sa_struct(void);
int getStackSize(stack_t *stack);
int _isascii(int number);
/*stacks and queues methods (operations)*/
stack_t *create_new_node(int n);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void free_commands(char **commands, int *numofcommands);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_hash(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int value);
#endif
