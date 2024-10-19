#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653589793

/*void co_ordinates(double r_low, double width, double z){
	double radius = r_low+((double)rand()/RAND_MAX)*width;
	double angle  = ((double)rand()/RAND_MAX)*2*PI;
	printf("1 A %.2f %.2f %.2f ", radius*sin(angle), radius*cos(angle), z);
}*/
void sha(double x, double y, double max_radius, double z){
	double radius = ((double)rand()/RAND_MAX)*max_radius;
	double angle  = ((double)rand()/RAND_MAX)*2*PI;
	printf("1 F %.2f %.2f %.2f ", x+radius*sin(angle), y+radius*cos(angle), z);
}

void raja_bro(double r_low, double angle, double z){
	double radius = r_low;
	printf("0 A %.2f %.2f %.2f ", radius*sin(angle), radius*cos(angle), z);
	for(int i=28;i<75;i++)
	{
		sha(radius*sin(angle), radius*cos(angle), 20.0, z);
	}
}

int main()
{
	srand(time(0));	
	
	for(double level=1.0;level<10.0;level++) // levels
	{
		for(int i=0;i<level*10;i+=2) // number of APs per level
		{
			//raja_bro((9.0+level)*9,2*i*PI/(10.0*pow(level,0.5)),level*6.0); //raja_bro
			raja_bro((9.0+level)*9,2*i*PI/(10.0*level),level*6.0);
		}
	}

	printf("\n");
	return 0;
}
