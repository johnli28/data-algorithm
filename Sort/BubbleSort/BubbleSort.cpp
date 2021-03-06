#include <iostream>
#include <vector>

#include <algorithm>

using std::vector;

/*
	Two tiers of loop
	Internal loop start from the end
	A flag indicates whether swap happens
*/

void BubbleSort(vector<int>& vec)
{
	int i, j;
	bool flag = true;

	for (int i = 0; i < vec.size() && flag; i++)
	{
		flag = false;

		for (int j = vec.size() - 1; j > i; j--)
		{
			if (vec[j - 1] > vec[j])
			{
				std::swap(vec[j - 1], vec[j]);
				flag = true;
			}
		}
	}
}

int main()
{
	vector<int> vec = { 21, 17, 328, 538, 87, 129, 50, 211, 6, 68 };

	std::cout << "This is before bubble sort" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	BubbleSort(vec);

	std::cout << "This is after bubble sort" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;

	getchar();

	return 0;
}