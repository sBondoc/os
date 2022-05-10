/* "multithread.h" - Prototypes for multithread functions. */
#ifndef MULTITHREAD_H
#define MULTITHREAD_H
/* Struct for merge sort args. */
struct ArgsSortMerge
{
	int *arr;
	int p;
	int r;
	int *threads_active;
	int max_threads;
};
/* Multithreaded merge sort. */
void *sort_merge_multithread(void *args);
#endif
