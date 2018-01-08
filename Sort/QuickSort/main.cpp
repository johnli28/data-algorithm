#include "QuickSort.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec = { 5, 8, 7, 3, 2 };

	std::cout << "This is before quick sort" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	QuickSort(vec, 0, 4);

	std::cout << "This is after quick sort" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	getchar();

	return 0;
}