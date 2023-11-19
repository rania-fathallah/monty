#include "monty.h"
/**
 *tsk0_push_func - function to Push value to the linked list.
 *@stk: the top node pointer of stack_t linked list.
 *@line_number: line number to be access Monty bytecodes file.
 *Return: NULL
 */
void tsk0_push_func(stack_t **stk, unsigned int line_number)
{
	stack_t *temp, *new_stk;
	int x;

	new_stk = malloc(sizeof(stack_t));
	if (new_stk == NULL)
	{
		token_error(maloc_fail());
		return;
	}

	if (opcode_token[1] == NULL)
	{
		token_error(int_error(line_number));
		return;
	}
	for (x = 0; opcode_token[1][x]; x++)
	{
		if (opcode_token[1][x] == '-' && x == 0)
			continue;
		if (opcode_token[1][x] < '0' || opcode_token[1][x] > '9')
		{
			token_error(int_error(line_number));
			return;
		}
	}
	new_stk->n = atoi(opcode_token[1]);
	if (checking(*stk) == STACK)
	{
		temp = (*stk)->next;
		new_stk->prev = *stk;
		new_stk->next = temp;
		if (temp)
			temp->prev = new_stk;
		(*stk)->next = new_stk;
	}
	else
	{
		temp = *stk;
		while (temp->next)
		temp = temp->next;
		new_stk->prev = temp;
		new_stk->next = NULL;
		temp->next = new_stk;
	}
}
