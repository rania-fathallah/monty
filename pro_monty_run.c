#include "monty.h"
#include <stdlib.h>
#include <string.h>
#define __USE_GNU
#include <stdio.h>
/**
 *free_tkn - Free the global opcode_token array of a string.
 *Description: function to free the token memory.
 *Return: void return nothing
 */
void free_tkn(void)
{
	size_t x;

	if (opcode_token == NULL)
		return;

	for (x = 0; opcode_token[x]; x++)
		free(opcode_token[x]);

	free(opcode_token);
}

/**
 *len_tkn - the length of external token.
 *Description: function to get the length of token.
 * Return: Length of the string length.
 */
unsigned int len_tkn(void)
{
	unsigned int len;

	for (len = 0; opcode_token[len]; len++)
		len++;
	return (len);
}

/**
 *line_delimit - Checks if a line read from getline contains delimiter.
 *Description: function to to check the delimits.
 *@str: A pointer for line.
 *@delims_str: A string of delimiter characters.
 *Return: If contains delimiters = 1 else = 0.
 */
int line_delimit(char *str, char *delims_str)
{
	int x, y;

	for (x = 0; str[x]; x++)
	{
		for (y = 0; delims_str[y]; y++)
		{
			if (str[x] == delims_str[y])
				break;
		}
		if (delims_str[y] == '\0')
			return (0);
	}

	return (1);
}

/**
 *opcode_function - to get the function of opcode.
 *Description: function to get the opcode poiten.
 *@opcode: The opcode required.
 *Return: A pointer to the corresponding function.
 */
void (*opcode_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_functions[] = {
		{"push", tsk0_push_func},
		/**
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{"stack", opcode_stack},
		{"queue", opcode_queue},
		*/
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_functions[x].opcode; x++)
	{
		if (strcmp(opcode, op_functions[x].opcode) == 0)
			return (op_functions[x].f);
	}

	return (NULL);
}

/**
 *montyrun -  function to run executtion prog Monty bytecodes script.
 *Description: function to the runing of the prog.
 *@script_file: File descriptor for an open Monty bytecodes script.
 *Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int montyrun(FILE *script_file)
{
	stack_t *stack = NULL;
	char *ptrline = NULL;
	unsigned int line_number = 0, tokn_prev_len = 0;
	void (*op_functions)(stack_t**, unsigned int);
	size_t length = 0, exit_status = EXIT_SUCCESS;

	if (list_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((getline(&ptrline, &length, script_file)) != -1)
	{
		line_number++;
		opcode_token = string_end(ptrline, DELIMES);
		if (opcode_token == NULL)
		{
			if (line_delimit(ptrline, DELIMES))
				continue;
			free_stk(&stack);
			return (maloc_fail());
		}
		else if (opcode_token[0][0] == '#')
		{
			free_tkn();
			continue;
		}
		op_functions = opcode_function(opcode_token[0]);
		if (op_functions == NULL)
		{
			free_stk(&stack);
			exit_status = invld_instruc(opcode_token[0], line_number);
			free_tkn();
			break;
		}
		tokn_prev_len = len_tkn();
		op_functions(&stack, line_number);
		if (len_tkn() != tokn_prev_len)
		{
			if (opcode_token && opcode_token[tokn_prev_len])
				exit_status = atoi(opcode_token[tokn_prev_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tkn();
			break;
		}
		free_tkn();
	}
	free_stk(&stack);
	if (ptrline && *ptrline == 0)
	{
		free(ptrline);
		return (maloc_fail());
	}
	free(ptrline);
	return (exit_status);
}
