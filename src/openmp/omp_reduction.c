/******************************************************************************
 * FILE: omp_reduction.c
 * DESCRIPTION:
 *   OpenMP Example - Combined Parallel Loop Reduction - C/C++ Version
 *   This example demonstrates a sum reduction within a combined parallel loop
 *   construct.  Notice that default data element scoping is assumed - there
 *   are no clauses specifying shared or private variables.  OpenMP will
 *   automatically make loop index variables private within team threads, and
 *   global variables shared.
 * AUTHOR: Blaise Barney  5/99
 * LAST REVISED: 04/06/05
 ******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define N       1000000000

void omp_reduction() {
	int i;
	float a[N], b[N], sum;

	/* Some initializations */

	for (i = 0; i < N; i++)
		a[i] = b[i] = i * 1.0;
	sum = 0.0;

	#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < N; i++){
		sum += sin(a[i]*PI/180) + sin(b[i]*PI/180);
	}
	printf("   Sum = %f\n", sum);

}
