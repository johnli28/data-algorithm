#pragma once

#include <vector>
#include "utils.h"

using namespace std;

vector<int> LongestIncreaseSubsequence(int* arr, int length)
{
	vector<int> dpTable(length);

	// Note: Two for loops to build dp table
	for (int i = 0; i < length; i++)
	{
		// Fault: initialize each element to 1 is essential, otherwise it will have a default value zero
		dpTable[i] = 1;

		for (int j = 0; j < i; j++)
		{
			// Note: if element[j] < element[i], dp[i] is the largest of dp[j] + 1
			if (arr[j] < arr[i])
			{
				dpTable[i] = max(dpTable[j] + 1, dpTable[i]);
			}
		}
	}

	int maxLength = 0;
	int maxLengthIndex = 0;

	for (int i = 0; i < length; i++)
	{
		if (dpTable[i] > maxLength)
		{
			maxLength = dpTable[i];
			maxLengthIndex = i;
		}
	}

	vector<int> retVec(maxLength);
	retVec[--maxLength] = arr[maxLengthIndex];

	int reverseIndex = maxLengthIndex;

	for (int i = reverseIndex; i >= 0; i--)
	{
		// Note: element is less and dpTable
		if (arr[i] < arr[reverseIndex] && (dpTable[i] == dpTable[reverseIndex] - 1))
		{
			retVec[--maxLength] = arr[i];
			reverseIndex = i;
		}
	}

	return retVec;
}
