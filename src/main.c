#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "multithread.h"
#include "sort.h"
#include "util.h"
int main(void)
{
	int arr[16], size = sizeof(arr) / sizeof(arr[0]);
	// srand(time(NULL));
	randarr_int(arr, size);
	int threads_active = 0;
	struct ArgsSortMerge arg =
	{
		.arr = arr,
		.p = 0,
		.r = size - 1,
		.threads_active = &threads_active,
		.max_threads = 1,
	};
	fprintf(stdout, "Random: ");
	fprintarr_int(stdout, arr, size);
	clock_t start, end;
	start = clock();
	sort_merge_multithread((void *) &arg);
	end = clock();
	fprintf(stdout, "Sorted: ");
	fprintarr_int(stdout, arr, size);
	fprintf(stdout, "Max threads: %d\nTime elapsed: %f\n", arg.max_threads, ((double) end - start) / CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}
