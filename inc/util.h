/* "util.h" - Prototypes for utility functions. */
#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#define RANGE_RAND 100
/* Print array of ints. */
int fprintarr_int(FILE *stream, int *arr, int size);
/* Generate random array. */
void randarr_int(int *arr, int size);
#endif
