#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "multithread.h"
#include "sort.h"
#include "util.h"
int main(void)
{
	int arr[16], size = sizeof(arr) / sizeof(arr[0]);
	srand(time(NULL));
	randarr_int(arr, size);
	fprintarr_int(stdout, arr, size);
	int threads_active = 0;
	struct ArgsSortMerge arg =
	{
		.arr = arr,
		.p = 0,
		.r = size - 1,
		.threads_active = &threads_active,
		.max_threads = 3,
	};
	sort_merge(arr, 0, size - 1);
	fprintarr_int(stdout, arr, size);
	return EXIT_SUCCESS;
}
