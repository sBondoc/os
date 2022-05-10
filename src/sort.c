/* "sort.c" - Implementation for sorting functions. */
#include <limits.h>
#include <string.h>
#include "sort.h"
/* Merge sort merge step. */
void sort_merge_merge(int *arr, int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int left[nl + 1], right[nr + 1];
	memcpy(&left[0], &arr[p], nl * sizeof(int));
	memcpy(&right[0], &arr[q + 1], nr * sizeof(int));
	left[nl] = INT_MAX;
	right[nr] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{
		arr[k] = (left[i] < right[j]) ? left[i++] : arr[j++];
	}
}
/* Merge sort. */
void sort_merge(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		sort_merge(arr, p, q);
		sort_merge(arr, q + 1, r);
		sort_merge_merge(arr, p, q, r);
	}
}
