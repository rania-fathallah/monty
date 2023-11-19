#include "monty.h"
/**
 *user_inperr - Prints user more than one argument error message.
 *Description: error message when user print more than 1 argu.
 * Return: (EXIT_FAILURE) always.
 */
int user_inperr(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 *not_open - Prints error message if not possible to open file.
 *Description: error message when not possible to open file.
 *@file_nm: the file name pointer
 * Return: (EXIT_FAILURE) always.
 */
int not_open(char *file_nm)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_nm);
	return (EXIT_FAILURE);
}
/**
 *invld_instruc - Prints error message if file contains an invalid instruction.
 *Description: error message when file contains an invalid instruction.
 *@opcode_token: where erorr occured .
 *@line_number: line number where the instruction appears
 *Return: (EXIT_FAILURE) always.
 */
int invld_instruc(char *opcode_token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode_token);
	return (EXIT_FAILURE);
}
/**
 *maloc_fail - Prints erorr if malloc fail.
 *Description: error message when file can’t malloc anymore.
 *file contains an invalid instruction
 * Return: (EXIT_FAILURE) always.
 */
int maloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 *int_error - Prints error message if is not an integer or no argument.
 *Description: error message when not an integer or there is no argument given.
 *@line_number: line number where the instruction appears
 *Return: (EXIT_FAILURE) always.
 */
int int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
