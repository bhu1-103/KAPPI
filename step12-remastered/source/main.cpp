#include <iostream>
#include <random>
using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0,6);
	int nombor_x = dis(gen);
	int nombor_y = dis(gen);
	cout << "here's x coordinate " << nombor_x*10 << endl;
	cout << "here's y coordinate " << nombor_y*10 << endl;
	return 0;
}
