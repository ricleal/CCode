/******************************************************************************
 * FILE: omp_getEnvInfo.c
 * DESCRIPTION:
 *   OpenMP Example - Get Environment Information - C/C++ Version
 *   The master thread queries and prints selected environment information.
 * AUTHOR: Blaise Barney  7/06
 * LAST REVISED: 07/12/06
 ******************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void omp_getEnvInfo() {

	int nthreads, tid, procs, maxt, inpar, dynamic, nested;

	/**
	 * Ricardo:
	 * Lets get a lock for printing in tid > 0
	 */
	omp_lock_t writelock;
	omp_init_lock(&writelock);

	/* Start parallel region */
#pragma omp parallel private(nthreads, tid)
	{

		/* Obtain thread number */
		tid = omp_get_thread_num();

		/* Only master thread does this */
		if (tid == 0) {
			printf("Thread %d getting environment info...\n", tid);

			/* Get environment information */
			procs = omp_get_num_procs();
			nthreads = omp_get_num_threads();
			maxt = omp_get_max_threads();
			inpar = omp_in_parallel();
			dynamic = omp_get_dynamic();
			nested = omp_get_nested();

			/* Print environment information */
			printf("Number of processors = %d\n", procs);
			printf("Number of threads = %d\n", nthreads);
			printf("Max threads = %d\n", maxt);
			printf("In parallel? = %d\n", inpar);
			printf("Dynamic threads enabled? = %d\n", dynamic);
			printf("Nested parallelism supported? = %d\n", nested);

		} else {
			// Get lock!
			omp_set_lock(&writelock);
			// in the lock!
			printf("Thread >0 : %d getting environment info!\n", tid);

			// Release lock
			omp_unset_lock(&writelock);

		}

	} /* Done */

}

