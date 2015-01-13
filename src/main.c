#include <stdio.h>

extern void omp_getEnvInfo();
extern void omp_mm();
extern void omp_orphan();
extern void omp_reduction();
extern void omp_workshare1();
extern void omp_workshare2();


int main( int argc, const char* argv[] )
{
	printf( "Main started...\n" );

	omp_getEnvInfo();
	omp_mm();
	omp_orphan();
	omp_reduction();
	omp_workshare1();
	omp_workshare2();

	printf( "Main ended.\n" );
}
