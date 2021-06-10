#include "sort.h"

/**
 * mergeCall - function that calls merge to merge previously divided arrays
 * @array: data
 * @sub_array: Holder for array
 * @start: Start index
 * @end: End index
 * Return: Nothing
**/
void mergeCall(int *sub_array, int *array, int start, int end)
{
	int middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		mergeCall(sub_array, array, start, middle);
		mergeCall(sub_array, array, middle, end);
		merge(sub_array, array, start, middle, end);
	}
}

/**
 * merge - Merges divided arrays into one
 * @array: Data
 * @sub_array: Holder for array
 * @start: Start index
 * @middle: Middle index
 * @end: End index
 * Return: Nothing
**/
void merge(int *sub_array, int *array, int start, int middle, int end)
{
	int i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	for (i = start, j = middle; i < middle && j < end; k++)
	{
		if (array[i] < array[j])
		{
			sub_array[k] = array[i];
			i++;
		}
		else
		{
			sub_array[k] = array[j];
			j++;
		}
	}
	while (i < middle)
	{
		sub_array[k] = array[i];
		i++;
		k++;
	}
	while (j < end)
	{
		sub_array[k] = array[j];
		j++;
		k++;
	}
	for (i = 0, k = start; k < end; k++)
	{
		array[k] = sub_array[i];
		i++;
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort - Sorts an array with Merge sort algorithm
 * @array: List of data
 * @size: Size of the array
**/
void merge_sort(int *array, size_t size)
{
	int *sub_array;

	if (size < 2 || array == NULL)
		return;

	sub_array = malloc(sizeof(int) * size);
	if (sub_array == NULL)
		return;

	mergeCall(sub_array, array, 0, size);
	free(sub_array);
}
