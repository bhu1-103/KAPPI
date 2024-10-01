#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int nombor = rand() % 100;
	printf("here ya go, %d\n", nombor);
	return 0;
}
