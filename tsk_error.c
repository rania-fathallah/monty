#include "monty.h"
/**
 *pintt_emp_stk - Prints error message if the stack is empty.
 *Description: error message when not an integer or there is no argument given.
 *@line_number: line number where the instruction appears
 *Return: (EXIT_FAILURE) always.
 */
int pintt_emp_stk(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 *pop_empt_stk - Prints error message if the stack is empty.
 *Description: error message when not an integer or there is no argument given.
 *@line_number: line number where the instruction appears
 *Return: (EXIT_FAILURE) always.
 */
int pop_empt_stk(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 *swap_error - Prints error message if the stack is less than 2 .
 *Description: error message when the stack is less than 2.
 *@swapped: the swapped items
 *@line_number: line number where the instruction appears
 *Return: (EXIT_FAILURE) always.
 */
int swap_error(unsigned int line_number, char *swapped)
{
	fprintf(stderr, "L%u: can't %s, stack too short", line_number, swapped);
	return (EXIT_FAILURE);
}
