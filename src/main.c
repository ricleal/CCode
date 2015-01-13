#include <stdio.h>


extern void omp_workshare1();


int main( int argc, const char* argv[] )
{
	printf( "Main started...\n" );

	omp_workshare1();


	printf( "Main ended.\n" );
}
