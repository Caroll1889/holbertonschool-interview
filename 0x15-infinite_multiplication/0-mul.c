#include "holberton.h"

/**
 * is_digit - function that checks for a digit
 * @ch: character to check
 * Return: 1 or 0
*/

int is_digit(char ch)
{
	int i;

	if (ch > 47 && ch < 59)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}

/**
 * digits - function that checks for a digit character
 * @ch: character to check
 * Return: 1 or 0
*/

void digits(char *ch)
{
	int i = 0;

	while (ch[i] != '\0')
	{
		if (is_digit(ch[i]))
		{
			i++;
		}
		else
		{
			error();
		}
	}
}

/**
 * *_strcmp - compare two string
 * @s1: string 1
 * @s2: string 2
 * Return: integer
*/

int _strcmp(char *s1, char *s2)
{
	int g;

	for (g = 0; s1[g] != '\0'; g++)
	{

		if (s1[g] < s2[g])
		{
			return (s1[g] - s2[g]);
		}
		if (s1[g] > s2[g])
		{
			return (s1[g] - s2[g]);
		}
	}
	return (0);
}

/**
 * _strlen - function that returns the string's length.
 * @string: char to be measured
 * Return: the length of a string
*/

int _strlen(char *string)
{
	int len = 0;

	while (string[len] != '\0')
	{
		++len;
	}
	return (len);
}

/**
* *_memset - fills memory with a constant byte
 * @s: pointer to the object to fill
 * @b: fill byte
 * @n: number of bytes to fill
 * Return: s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}

/**
 * _memmove - Function to copy block of 'n' bytes from 'src' to 'dest'
 * @dest: char *dest
 * @src: char *src
 * @n: unsigned int n
 * Return: char
*/

void _memmove(void *dest, void *src, int n)
{
	int i;
	char *psrc = (char *)src;
	char *pdest = (char *)dest;
	char *temp;

	temp = (char *)malloc(n * sizeof(char));

	for (i = 0; i < n; i++)
	{
		*(temp + i) = *(psrc + i);
	}

	for (i = 0; i < n; i++)
	{
		*(pdest + i) = *(temp + i);
	}

	free(temp);
}

/**
 * error - Function to print error and exit 98.
 * Return: Nothing
*/

void error(void)
{
	int i;
	char e[] = "Error\n";

	for (i = 0; i <= 5; i++)
	{
		_putchar(e[i]);
	}
	exit(98);
}

/**
 * _multiplication - Function that implements a long multiplication
 * @a: char *a
 * @b: char *b
 * @c: char int n
 * Return: char
*/

void _multiplication(char *a, char *b, char *c)
{
	int i = 0, j = 0, k = 0, n, carry;
	int la, lb;

	if (!_strcmp(a, "0") || !_strcmp(b, "0"))
	{
		c[0] = '0', c[1] = '\0';
		return;
	}

	la = _strlen(a);
	lb = _strlen(b);
	_memset(c, '0', la + lb);
	c[la + lb] = '\0';

	#define I(a) (a - '0')
	for (i = la - 1; i >= 0; i--)
	{
		for (j = lb - 1, k = i + j + 1, carry = 0; j >= 0; j--, k--)
		{
			n = I(a[i]) * I(b[j]) + I(c[k]) + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
		}
		c[k] += carry;
	}
	#undef I
	if (c[0] == '0')
	{
		_memmove(c, c + 1, la + lb);
	}
}

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 en success
*/

int main(int argc, char *argv[])
{
	char c[10240];
	int i;

	if (argc != 3)
	{
		error();
	}

	digits(argv[1]);

	digits(argv[2]);

	_multiplication(argv[1], argv[2], c);

	i = 0;
	while (c[i] == '0' && c[i + 1] != '\0')
	{
		i++;
	}

	while (c[i] != '\0')
	{
		_putchar(c[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
