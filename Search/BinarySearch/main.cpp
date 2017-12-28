#include "BinarySearch.h"
#include <vector>
#include <iostream>

using std::vector;

const int VECTOR_SIZE = 3;

int main()
{
	vector <int> vec;

	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	

	int pos = GetMinOfRotatedSortedArray(vec);

	std::cout << "pos: " << pos << std::endl;

	getchar();

	return 0;
}