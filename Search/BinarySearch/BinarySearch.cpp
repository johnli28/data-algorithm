#include "BinarySearch.h"

int BinarySearch(const vector<int>& v, int key)
{
	int low = 0;
	int high = v.size() - 1;

	// Fault: while condition is low < high
	// e.g. cannot find 0 in vector(0, 1, 2, 3)  
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] > key)
		{
			// Fault: high = mid 
			high = mid - 1;
		}
		else if (v[mid] < key)
		{
			// Fault: low = mid
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int GetFirstK(const vector<int>& v, int k)
{
	if (v.empty())
	{
		return -1;
	}

	int low = 0;
	int high = v.size() - 1;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] > k)
		{
			high = mid - 1;
		}
		else if (v[mid] < k)
		{
			low =  mid + 1;
		}
		else // v[mid] == k
		{
			// If the left item is also k, go on binary search
			if (mid > low && v[mid - 1] == k)
			{
				high = mid - 1;
			}
			else
			{
				return mid;
			}
		}

	}

	return -1;
}

int GetLastK(const vector<int>& v, int k)
{
	if (v.empty())
	{
		return -1;
	}

	int low = 0;
	int high = v.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] > k)
		{
			high = mid - 1;
		}
		else if (v[mid] < k)
		{
			low = mid + 1;
		}
		else // v[mid] == k
		{
			// If the right item is also k, go on binary search
			if (mid < high && v[mid + 1] == k)
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}

	}

	return -1;
}

int GetNumberOfK(const vector<int>& v, int k)
{
	if (v.empty())
	{
		return 0;
	}

	// Find the first position of k, and last position of k
	int fPos = GetFirstK(v, k);
	int lPos = GetLastK(v, k);

	if (fPos == -1 || lPos == -1)
	{
		return 0;
	}
	else
	{
		return lPos - fPos + 1;
	}
}

