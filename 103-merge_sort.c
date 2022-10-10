#include "sort.h"

void merge_split(int *subarr, int *buff, size_t front, size_t mid,
		 size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front,
			  size_t back);
/**
 * merge_split - Sort a subarray of int
 * @subarr: A subarray of an array of int to sort.
 * @buff: A buffer to store the sorted subarry.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The last index of the array
 */
void merge_split(int *subarr, int *buff, size_t front, size_t mid,
		 size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Does merge sort through recursion.
 * @subarr: A subarray of an array of int to sort
 * @buff: A buff to store the sorted result
 * @front: The front index of the subarray.
 * @back: The back of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_split(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array in ascending order using
 *              merge sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Implements top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);
	free(buff);
}
