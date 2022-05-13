/* "multithread.c" - Implementation for multithread functions. */
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include "multithread.h"
#include "sort.h"
/* Multithreaded merge sort. */
void *sort_merge_multithread(void *args)
{
	struct ArgsSortMerge *args_cast = (struct ArgsSortMerge *) args;
	int *arr = args_cast->arr,
	p = args_cast->p,
	r = args_cast->r,
	*threads_active = args_cast->threads_active,
	max_threads = args_cast->max_threads;
	if (p < r)
	{
		int q = (p + r) / 2;
		struct ArgsSortMerge args_left =
		{
			.arr = arr,
			.p = p,
			.r = q,
			.threads_active = threads_active,
			.max_threads = max_threads,
		};
		pthread_t t;
		bool thread_spawned = false;
		if
		(
			(*threads_active < max_threads) &&
			(pthread_create(&t, NULL, sort_merge_multithread, (void *) &args_left) == 0)
		)
		{
			thread_spawned = true;
			(*threads_active)++;
		}
		else
		{
			sort_merge_multithread((void *) &args_left);
		}
		struct ArgsSortMerge args_right =
		{
			.arr = arr,
			.p = q + 1,
			.r = r,
			.threads_active = threads_active,
			.max_threads = max_threads,
		};
		sort_merge_multithread((void *) &args_right);
		if (thread_spawned)
		{
			pthread_join(t, NULL);
			(*threads_active)--;
		}
		sort_merge_merge(arr, p, q, r);
	}
	return NULL;
}
