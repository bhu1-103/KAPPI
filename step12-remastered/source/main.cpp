#include <iostream>
#include <random>
using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0,99);
	int nombor = dis(gen);
	cout << "Uh... Here ya go: " << nombor << endl;
	return 0;
}
