#include "BinarySearch.h"
#include <vector>
#include <iostream>

using std::vector;

const int VECTOR_SIZE = 3;

int main()
{
	vector <int> vec;

	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(2);
	

	int pos = GetNumberOfK(vec, 3);

	std::cout << "pos: " << pos << std::endl;

	getchar();

	return 0;
}