#include "sort.h"

/**
 * swap - function that swap elements
 * @arr: array
 * @i: element
 * @j: element
 * @r_size: array size
 * Return: Nothing
 */

void swap(int arr[], int i, int j, size_t r_size)
{
	int temp;

	temp = arr[i];

	if (arr[i] == arr[j])
		return;

	arr[i] = arr[j];
	arr[j] = temp;
	print_array(arr, r_size);
}


/**
 * heapify - Function to heapify subtree rooted at index i
 * @arr: array
 * @size: size of the heap
 * @i: index
 * @r_size: array size
 * Return: nothing
 */

void heapify(int arr[], int size, int i, size_t r_size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[left] > arr[max])
		max = left;

	if (right < size && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap(arr, i, max, r_size);
		heapify(arr, size, max, r_size);
	}
}


/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: array
 * @size: array size
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;
	size_t r_size = size;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i, r_size);
		heapify(array, i, 0, r_size);
	}
}
