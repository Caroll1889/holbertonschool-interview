#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
int is_digit(char ch);
void digits(char *ch);
int _strcmp(char *s1, char *s2);
int _strlen(char *string);
char *_memset(char *s, char b, unsigned int n);
void _memmove(void *dest, void *src, int n);
void error(void);
void _multiplication(char *a, char *b, char *c);
int main(int argc, char *argv[]);

#endif /* _HOLBERTON_H_ */