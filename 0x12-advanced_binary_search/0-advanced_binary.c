#include "search_algos.h"

/**
*print_arr - print an array
*@array: pointer to the first element of the array to search in
*@left: left side of an array
*@right: right side of an array
**/

void print_arr(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);

		if (i != right)
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
*binary_search_recursion - function that searches a value in a sorted array.
*@array: pointer to the first element of the array to search in
*@left: start of the array
*@right: finish of array
*@value: index to find
* Return: index where value is located or -1
**/

int binary_search_recursion(int *array, int left, int right, int value)
{
	int middle;

	print_arr(array, left, right);

	if (left == right)
	{
		return (-1);
	}

	if (left <= right)
	{
		middle = left + (right - left) / 2;

		if (array[middle] == value && array[middle - 1] != value)
		{
			return (middle);
		}

		if (array[middle] >= value)
		{
			return (binary_search_recursion(array, left, middle, value));
		}

		if (array[middle] <= value)
		{
			return (binary_search_recursion(array, middle + 1, right, value));
		}
	}
	return (-1);
}


/**
*advanced_binary - function that searches for a value in a sorted array.
*@array: pointer to the first element of the array to search in
*@size: number of elements in array
*@value:  value to search for
* Return: index where value is located or -1
**/

int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_search_recursion(array, 0, size - 1, value));
}
