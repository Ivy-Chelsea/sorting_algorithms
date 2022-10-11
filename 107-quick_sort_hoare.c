#include "sort.h"
#include "104-heap_sort.c"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The final index of the subset to oreder
 *
 * Return: The final partition index
 *
 * Description: Uses the last element of the partition as the pivot.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - Implement the quick sort through recursion
 * @array: An array of integers to sort
 * @size: size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 *
 * Description: Uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm
 * @array: Array of ints
 * @size: The size of the array
 *
 * Description: Uses the Hoare partition scheme.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
