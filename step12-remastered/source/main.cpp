#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653589793

void co_ordinates(double r_low, double width, double z){
	double radius = r_low+((double)rand()/RAND_MAX)*width;
	double angle  = ((double)rand()/RAND_MAX)*2*PI;
	printf("1 A %.2f %.2f %.2f ", radius*sin(angle), radius*cos(angle), z);
}

int main()
{
	srand(time(0));	
	for(int i=0;i<21;i++) co_ordinates(28.43,2.0,1.0);
	printf("\n");
	return 0;
}

