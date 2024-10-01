#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653589793

void co_ordinates(double r_low, double width){
	double radius = r_low+((double)rand()/RAND_MAX)*width;
	double angle  = ((double)rand()/RAND_MAX)*2*PI;
	printf("x and y cp-ordinates are (%.2f, %.2f)\n", radius*sin(angle), radius*cos(angle));
}

int main()
{
	srand(time(0));	
	co_ordinates(28.43,2.0);
	co_ordinates(28.43,2.0);
	co_ordinates(28.43,2.0);
	return 0;
}

