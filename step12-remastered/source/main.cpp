#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653589793

void co_ordinates(){
	srand(time(0));	
	double radius = 9.0+((double)rand()/RAND_MAX)*2.0;
	double angle  = ((double)rand()/RAND_MAX)*2*PI;
	printf("here ya go, %.2f\n", radius);
	printf("here ya go, %.2f\n", angle);
	printf("x and y cp-ordinates are (%.2f, %.2f)\n", radius*sin(angle), radius*cos(angle));
}

int main()
{
	co_ordinates();
	return 0;
}

