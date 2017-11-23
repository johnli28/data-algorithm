#include "BinarySearch.h"

int BinarySearch(const vector<int>& v, int key)
{
	int low = 0;
	int high = v.size() - 1;

	// Condition is less or equal
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] > key)
		{
			// Made a mistake: high = mid 
			high = mid - 1;
		}
		else if (v[mid] < key)
		{
			//Made a mistake : low = mid
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}