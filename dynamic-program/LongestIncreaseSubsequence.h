#pragma once

#include <vector>

using namespace std;

int LongestIncreaseSubsequence(int* arr, int length)
{
	vector<int> lisVec(length);

	int curMax;

	for (int i = 0; i < length; i++)
	{
		if (i == 0)
		{
			lisVec[i] = 1;
			curMax = lisVec[i];
		}
		else if (arr[i] > curMax)
		{
			lisVec[i] = lisVec[i - 1] + 1;
			curMax = lisVec[i];
		}
		else
		{
			lisVec[i] = lisVec[i - 1];
		}
	}

	return lisVec[length - 1];
}
