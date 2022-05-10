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
		bool thread_spawned = false;
		pthread_t t;
		args_cast->r = q;
		if ((*threads_active) < max_threads)
		{
			if (pthread_create(&t, NULL, &sort_merge_multithread, (void *) args_cast) == 0)
			{
				thread_spawned = true;
			}
			else
			{
				fprintf(stderr, "Failed to create new pthread.\n");
				sort_merge_multithread((void *) args_cast);
			}
		}
		args_cast->p = q + 1;
		args_cast->r = r;
		sort_merge_multithread((void *) args_cast);
		if (thread_spawned)
		{
			pthread_join(t, NULL);
		}
		sort_merge_merge(arr, p, q, r);
	}
	return NULL;
}
