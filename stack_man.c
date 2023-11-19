#include "monty.h"

/**
 *token_error - to get the error code then free malloc.
 *Description: function that get error code if not malloc..
 *@error: number to convert to string
 *Return: character pointer to newly created string. NULL if malloc fails.
 */
void token_error(int error)
{
	int token_len = 0, x = 0;
	char *exit_strng = NULL;
	char **new_tkn = NULL;

	token_len = token_length();
	new_tkn = malloc(sizeof(char *) * (token_len + 2));
	if (!opcode_token)
	{
		maloc_fail();
		return;
	}
	while (x < token_len)
	{
		new_tkn[x] = opcode_token[x];
		x++;
	}
	exit_strng = integr(error);
	if (!exit_strng)
	{
		free(new_tkn);
		maloc_fail();
		return;
	}
	new_tkn[x++] = exit_strng;
	new_tkn[x] = NULL;
	free(opcode_token);
	opcode_token = new_tkn;
}

/**
 *free_stk - Free a stack_t stack.
 *Description: this to free stack.
 *@stack: A pointer to the top stack or bottom queue.
 */
void free_stk(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 *list_stack - Initialize stack with beginning stack and ending queue nodes.
 *@stack: A pointer to an unitialized stack_t stack.
 *Return: If an error occurs - EXIT_FAILURE. Otherwise - EXIT_SUCCESS.
 */
int list_stack(stack_t **stack)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (maloc_fail());

	new->n = STACK;
	new->prev = NULL;
	new->next = NULL;

	*stack = new;

	return (EXIT_SUCCESS);
}

/**
 *checking - Checks if a stack_t linked list is stack or queue.
 *@stack: A pointer to the top stack or bottom queue
 *Return: If the stack_t is in stack mode - STACK (0).
 *        If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int checking(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
/**
 *token_length - to get the length of opcode_token .
 *
 *Return: int for Length of current  opcode_token.
 */
unsigned int token_length(void)
{
	unsigned int token_len;

	token_len = 0;
	while (opcode_token[token_len])
		token_len++;
	return (token_len);
}
