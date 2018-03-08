#include "QuickSort.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec = { 12, 9, 5, 8, 7, 9, 3, 2, 7 };

	std::cout << "This is before quick sort" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	QuickSort(vec, 0, vec.size() - 1);

	std::cout << "This is after quick sort" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	getchar();

	return 0;
}