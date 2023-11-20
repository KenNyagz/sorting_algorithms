#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

listint_t *create_listint(const int *array, size_t size);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void swap(int *array, int index_a, int index_b);
void lomuto_sort(int *array, size_t size, int start, int end);
int lomuto_partition(int *array, size_t size, int start, int end);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort_helper(int *array, int *temp, size_t start, size_t end);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

int find_max(int *array, int size);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void hoare_sort(int *array, size_t size, int low, int high);
int hoare_partition(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);
void heapify(int *array, size_t size, size_t root, size_t start_pt);
void heap_sort(int *array, size_t size);

void merge(int* array, int* temp, size_t left_start, size_t left_end, size_t right_start, size_t right_end);
#endif
