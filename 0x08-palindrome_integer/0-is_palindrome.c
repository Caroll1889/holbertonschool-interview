#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given unsigned integer is a palindrome
 *@n: number to be checked
 *Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long remaining;/*falta*/
	unsigned long reversed;/*numInvertido*/
	unsigned long rest;/*resto*/

	remaining = n;
	reversed = 0;
	rest = 0;

	while (remaining != 0)
	{
		rest = remaining % 10;
		reversed = reversed * 10 + rest;
		remaining = remaining / 10;
	}

	if (reversed == n)
	{
		return (1);
	}

	else 
	{
		return (0);
	}
}


