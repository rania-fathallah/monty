#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdio.h>
#define __USE_GNU
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DELIMES " \n\t\a\b"
#define STACK 0
#define QUEUE 1

/* global varieble for opcode  */
extern char **opcode_token;

/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**handling main error file error1*/
int user_inperr(void);
int not_open(char *file_nm);
int invld_instruc(char *opcode, unsigned int line_number);
int maloc_fail(void);
int int_error(unsigned int line_number);
/**get string file functions*/
char *integr(int number);
int length_int(unsigned int number, unsigned int base_int);
int absalutex(int n);
void fill_numbase(unsigned int number, unsigned int base,
				char *bufer, int bufer_size);
/**stack function for list malloc and free*/
void token_error(int error);
int checking(stack_t *stack);
int list_stack(stack_t **stack);
void free_stk(stack_t **stack);
unsigned int token_length(void);
/**main monty function*/
int main(int argc, char **argv);
/**the progrem monty runnig file*/
void free_tkn(void);
unsigned int len_tkn(void);
int line_delimit(char *str, char *delims_str);
void (*opcode_function(char *opcode))(stack_t**, unsigned int);
int montyrun(FILE *script_file);
/**the word memory allocation functions in word_count*/
char *next_blkwrd(char *ptrstrng, char *delimit);
int blkwrd_length(char *ptrstrng, char *delimit);
int chk_delimter(char charktr, char *delimit);
int blk_counter(char *ptrstrng, char *delimit);
char **string_end(char *ptrstrng, char *delimit);
/**runing function task functions*/
void tsk0_push_func(stack_t **stk, unsigned int line_number);


#endif
