#include "BinarySearch.h"
#include <vector>
#include <iostream>

using std::vector;

const int VECTOR_SIZE = 10;

int main()
{
	vector <int> vec;
	
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		vec.push_back(i);
	}

	int pos = BinarySearch(vec, 200);

	std::cout << "pos: " << pos << std::endl;

	getchar();

	return 0;
}