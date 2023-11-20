#include "monty.h"
/**
 *integr - gets a  pointer to new string containing integer
 *Description: function that get the integr only.
 *@number: number to convert to string
 *
 *Return: character pointer to newly created string. NULL if malloc fails.
 */
char *integr(int number)
{
	unsigned int tempx;
	int len;
	long numx = 0;
	char *new_ret;

	tempx = absalutex(number);
	len = 0;
	len = length_int(tempx, 10);
	if (number < 0 || numx < 0)
		len++;
	new_ret = malloc(len + 1);
	if (new_ret == NULL)
		return (NULL);
	fill_numbase(tempx, 10, new_ret, len);
	if (number < 0 || numx < 0)
		new_ret[0] = '-';

	return (new_ret);
}
/**
 *length_int - gets length of an unsigned int
 *Description: function to get length of an unsigned int
 *@number: number to get length needed for
 *@base_int: base of number representation used by buffer
 *Return: int for length of buffer needed.
 */
int length_int(unsigned int number, unsigned int base_int)
{
	int length;

	for (length = 1; number > (base_int - 1); length++)
	{
		number /= base_int;
	}
	return (length);
}
/**
 *absalutex - gets positive value of an integer
 **Description: function to get absolute value
 *@n: the inpute integer to be absoluted
 *Return: unsigned integer for integer
 */
int absalutex(int n)
{
	if (n >= 0)
		return (n);
	else if (n < 0)
	{
		n = (n * -1);
	}
		return (n);
}
/**
 *fill_numbase - fills buffer with correct numbers
 *Description: function to store a buffer memory
 *@number: number to convert to string given base
 *@base: base of number used in conversion, only works up to base 36
 *@bufer: buffer to fill with result of conversion
 *@bufer_size: size of buffer in bytes
 *Return: always void.
 */
void fill_numbase(unsigned int number, unsigned int base_int,
			char *bufer, int bufer_size)
{
	int remark, x;

	x = bufer_size - 1;
	bufer[bufer_size] = '\0';
	while (x >= 0)
	{
		remark = number % base_int;
		if (remark > 9)
		{
			bufer[x] = remark + 87;
		}
		else
		{
			bufer[x] = remark + '0';
		}
		number /= base_int;
		x--;
	}
}
