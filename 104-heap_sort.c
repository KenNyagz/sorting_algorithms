#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @array: contains a list of integers
 * @index_a: The first integer to swap.
 * @index_b: The second integer to swap.
 */

void swap(int *array, int index_a, int index_b)
{
	int temp;

	temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}


/**
  *heapify - builds a heap from an array
  *
  *@array: list of integers
  *@size: size of the array
  *@r_size: size of the heap
  *@start_pt: starting point of where heap is built from
  *
  *Return: nothing
  */

void heapify(int *array, size_t size, size_t r_size, size_t start_pt)
{
	size_t largest = start_pt, left = 2 * start_pt + 1, right = 2 * start_pt + 2;

	/*Check if the left child is largest*/
	if (left < r_size && array[left] > array[largest])
		largest = left;
	/*Check if the right child is largest*/
	if (right < r_size && array[right] > array[largest])
		largest = right;
	/*Update the value of largest if not equal to root value*/
	if (largest != start_pt)
	{
		swap(array, start_pt, largest);
		print_array(array, size);
		heapify(array, size, r_size, largest);
	}

}


/**
  * heap_sort - sorting an array using the heap sort algorithm
  *
  *@array: list of integers to be sorted
  *@size:size of the array
  *
  *Return: nothing
  */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/*This loop builds the heap*/
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	/*This next loop recursively sorts the array by deleting the root nodes*/
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
