// QuickSort.cpp : Defines the entry point for the console application.
//

#include <algorithm>

#include "QuickSort.h"

// Classic partition:
// Last element as pivot
// From low to high find all items less than pivot
// swap to lower side
// swap pivot to right position

int PartitionOneWay(vector<int>& vec, int low, int high)
{
	int pivot = vec[high]; //The last element as pivot

	int smaller = low;

	for (int i = low; i < high; i++)
	{
		if (vec[i] < pivot)
		{
			std::swap(vec[i], vec[smaller]);
			smaller++;
		}
	}

	std::swap(vec[smaller], vec[high]);

	return smaller;
}

// Two ways partition:
// Last element as pivot
// Start from low side, find the first element larger than pivot
// Start from high side, find the first element less than pivot
// swap pivot to right position

int PartitionTwoWays(vector<int>& vec, int low, int high)
{
	int pivot = vec[high]; //The end element as pivot
	int pivotIndex = high;

	while (low < high)
	{
		// Start from low side, find the first element larger than pivot
		while (low < high && vec[low] <= pivot)
		{
			low++;
		}

		// Start from high side, find the first element less than pivot
		while (low < high && vec[high] >= pivot)
		{
			high--;
		}

		if (low < high)
		{
			//Swap low and pivot
			swap(vec[high], vec[low]);
		}
		else
		{
			break;
		}
		
	}

	swap(vec[pivotIndex], vec[low]);

	return low;
}

/* Note:
Divide and Conquer algorithm
Do partition, then recursion
Start from high, find the first less
Start from low, find the first larger
Partition return low as pivot position
*/

void QuickSort(vector<int>& vec, int low, int high)
{
	if (low < high)
	{
		//Divide the list into two parts
		int pivot = PartitionTwoWays(vec, low, high);

		//Conquer each part
		QuickSort(vec, low, pivot - 1);
		QuickSort(vec, pivot + 1, high);
	}
	
}

