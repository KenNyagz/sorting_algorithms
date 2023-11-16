#include "sort.h"

/**
  * swap_ints - Swap two integers in an array.
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
  *shell_sort - sorts a given array using the gap sequence
  *(knuth sequence in this case)
  *
  *@array: The array containing integers
  *@size: Size of the array
  *
  *Return: Nothing
  */

void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;

    if (array == NULL || size < 2)
        return;

    /*Run a loop to initialize the Knuth sequence*/
    for (gap = 1; gap < size/3;)
        gap = gap * 3 + 1;

    for (; gap >= 1; gap = gap / 3) /*Loop iterates over gaps in decreasing order*/
    {
        for (i = gap; i < size; i++) /*Carries out insertion sort on elements at current gap*/
        {
            j = i;
            /*loop below compares and swaps elements with the current gap*/
            while (j >= gap && array[j - gap] > array[j])
            {
                swap(array, j, j - gap);
                j = j - gap;
            }
        }
        print_array(array, size);
    }
    /**
     * No big O notations of the time complexity of the Shell sort
     * (Knuth sequence) algorithm needed - as the complexity is
     * dependent on the size of array and gap
     */
}
