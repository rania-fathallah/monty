#include "monty.h"
/**
 *string_end - for obtain each word from string
 *Description: function to obtain memory for word in string.
 *@ptrstrng: pointer to string
 *@delimit: delimitors to use for delimit the word
 *Return: 2-Dims array  for words in string
*/

char **string_end(char *ptrstrng, char *delimit)
{
	char **new_wrdblk = NULL;
	int wrd_cntr, blk_Len, count, x = 0;

	if (!*ptrstrng || ptrstrng == NULL)
		return (NULL);
	wrd_cntr = blk_counter(ptrstrng, delimit);
	if (wrd_cntr == 0)
		return (NULL);
	new_wrdblk = malloc((wrd_cntr + 1) * sizeof(char *));
	if (new_wrdblk == NULL)
		return (NULL);
	while (x < wrd_cntr)
	{
		blk_Len = blkwrd_length(ptrstrng, delimit);
		if (chk_delimter(*ptrstrng, delimit))
		{
			ptrstrng = next_blkwrd(ptrstrng, delimit);
		}
		new_wrdblk[x] = malloc((blk_Len + 1) * sizeof(char));
		if (new_wrdblk[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(new_wrdblk[x]);
			}
			free(new_wrdblk);
			return (NULL);
		}
		for (count = 0; count < blk_Len; count++)
		{
			new_wrdblk[x][count] = *(ptrstrng + count);
		}
		new_wrdblk[x][count] = '\0'; /* set end of str */
		ptrstrng = next_blkwrd(ptrstrng, delimit);
		x++;
	}
	new_wrdblk[x] = NULL; /* last element is null for iteration */
	return (new_wrdblk);
}
/**
 *blk_counter - counter for the block word in a string
 *Description: function to counte each bloch word in string
 *@ptrstrng: pointer to string
 *@delimit: delimitors to use for delimit the word
 *Return: counter for word in the string
*/

int blk_counter(char *ptrstrng, char *delimit)
{
	int wrd_cntr = 0, next_pnding = 1, x = 0;

	while (*(ptrstrng + x))
	{
		if (chk_delimter(ptrstrng[x], delimit))
			next_pnding = 1;
		else if (next_pnding)
		{
			next_pnding = 0;
			wrd_cntr++;
		}
		x++;
	}
	return (wrd_cntr);
}
/**
 *chk_delimter - checks if stream has delimitor cha
 *Description: function to check if it is the end of string.
 *@charktr: character in stream.
 *@delimit: Pointer to the end of delimitors.
 *
 *Return: 1 in the success OR 0 if it fail
*/

int chk_delimter(char charktr, char *delimit)
{
	int x;

	for (x = 0; delimit[x]; x++)
	{
		if (delimit[x] == charktr)
			return (1);
	}
	return (0);
}

/**
 *blkwrd_length - for the word length of current word in str.
 *Description: function to get length of the word processing.
 *@ptrstrng: pointer to string
 *@delimit: delimitors to use for delimit the word
 *Return: the length of the word in current string.
*/
int blkwrd_length(char *ptrstrng, char *delimit)
{
	int len = 0, pend = 1, x;

	x = 0;
	while (*(ptrstrng + x))
	{
		if (chk_delimter(ptrstrng[x], delimit))
			pend = 1;
		else if (pend)
		{
			len++;
		}
		if (len > 0 && chk_delimter(ptrstrng[x], delimit))
			break;
		x++;
	}
	return (len);
}

/**
 *next_blkwrd - gets the next word in a string
 *Description: function to put the pointer to next word.
 *@ptrstrng: pointer to string
 *@delimit: delimitors to use for delimit the word
 * Return: refer to the pointer in first char in next block
*/

char *next_blkwrd(char *ptrstrng, char *delimit)
{
	int pend = 0, x;

	for (x = 0; *(ptrstrng + x); x++)
	{
		if (chk_delimter(ptrstrng[x], delimit))
			pend = 1;
		else if (pend)
			break;
	}
	return (ptrstrng + x);
}
