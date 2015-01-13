/******************************************************************************

 ******************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N       1000000

void serial_pi() {
	int i;
	double x, pi, step, sum = 0.0;
	step = 1.0 / (double) N;
	for (i = 1; i <= N; i++) {
		x = (i - 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	pi = step * sum;

	printf("Serial Pi   = %.20f\n", pi);
}

void omp_reduction_pi() {

	int i;
	double x=0.0, pi=0.0, step=0.0, aux=0.0, sum = 0.0;
	step = 1.0 / (double) N;

	#pragma omp parallel for private(i,x,aux) reduction(+:sum) schedule(static)
	for (i = 1; i <= N; i=i+1) {
		x = (i - 0.5) * step;
		aux = 4.0 / (1.0 + x * x);
		sum = sum + aux;
	}
	pi = step * sum;

//	int i = 0;
//	double x =0.0, pi = 0.0, step=0.0, sum = 0.0;
//	step = 1.0 / (double) N;
//	#pragma omp parallel private(i,x)
//	{
//	#pragma omp for reduction(+:sum) schedule(static)
//		for (i = 0; i < N; i = i + 1) {
//			x = (i + 0.5) * step;
//			sum = sum + 4.0 / (1.0 + x * x);
//		}
//	}
//	pi = step * sum;

	printf("Parallel Pi = %.20f\n", pi);

}
