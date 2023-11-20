#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **opcode_token = NULL;
/**
 *main - get the input string from stander input.
 *Description: to get the input
 *@argc: argument counter
 *@argv: pointer for the input
 *Return: code_exit.
 */
int main(int argc, char **argv)
{
	FILE *file_script = NULL;
	int code_exit = EXIT_SUCCESS;

	if (argc != 2)
		return (user_inperr());
	file_script = fopen(argv[1], "r");
	if (file_script == NULL)
		return (not_open(argv[1]));
	code_exit = montyrun(file_script);
	fclose(file_script);
	return (code_exit);
}
