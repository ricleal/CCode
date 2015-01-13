#include <stdio.h>
#include <sys/time.h>


extern void omp_getEnvInfo();
extern void omp_mm();
extern void omp_orphan();
extern void omp_reduction();
extern void omp_workshare1();
extern void omp_workshare2();
extern void serial_pi();
extern void omp_reduction_pi();

int main( int argc, const char* argv[] )
{
	struct timeval stop, start;

	printf( "Main started...\n" );
	gettimeofday(&start, NULL);

//	omp_getEnvInfo();
//	omp_mm();
//	omp_orphan();
//	omp_reduction();
//	omp_workshare1();
//	omp_workshare2();

	serial_pi();
	omp_reduction_pi();

	gettimeofday(&stop, NULL);
	printf( "Main ended. Took %lu (milisec)\n", (stop.tv_usec - start.tv_usec)/ 1000L);

	return 0;
}
