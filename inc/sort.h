/* "sort.h" - Prototypes for sorting functions. */
#ifndef SORT_H
#define SORT_H
/* Merge sort merge step. */
void sort_merge_merge(int *arr, int p, int q, int r);
/* Merge sort. */
void sort_merge(int *arr, int p, int r);
#endif
