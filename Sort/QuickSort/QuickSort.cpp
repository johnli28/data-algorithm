// QuickSort.cpp : Defines the entry point for the console application.
//

#include <algorithm>

#include "QuickSort.h"

/*
	Divide and Conquer algorithm
	Do partition, then recursion
	Start from high, find the first less
	Start from low, find the first larger
	Partition return low as pivot position
*/

int Partition(vector<int>& vec, int low, int high)
{
	int pivot = vec[low]; //The first element as pivot

	while (low < high)
	{
		// Start from the high side, find the first element less than pivot
		while (low < high && vec[high] >= pivot)
		{
			high--;
		}

		//Swap high and low
		swap(vec[high], vec[low]);

		// Start from the low side, find the first element larger than pivot
		while (low < high && vec[low] <= pivot)
		{
			low++;
		}

		//Swap low and pivot
		swap(vec[high], vec[low]);
	}

	return low;
}

void QuickSort(vector<int>& vec, int low, int high)
{
	if (low < high)
	{
		//Divide the list into two parts
		int pivot = Partition(vec, low, high);

		//Conquer each part
		QuickSort(vec, low, pivot - 1);
		QuickSort(vec, pivot + 1, high);
	}
	
}

