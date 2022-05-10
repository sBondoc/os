/* "util.c" - Prototypes for utility functions. */
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
/* Print array of ints. */
int fprintarr_int(FILE *stream, int *arr, int size)
{
	int ret = fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		ret += fprintf(stream, "%d, ", arr[i]);
	}
	ret += fprintf(stream, "%d}\n", arr[size - 1]);
	return ret;
}
/* Generate random array. */
void randarr_int(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % RANGE_RAND;
	}
}
