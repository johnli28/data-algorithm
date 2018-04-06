#pragma once

#include <unordered_map>
#include "Utils.h"

using namespace std;

int MaxSubarraySumEqualK(int* arr, int n, int K)
{
	int sum = 0;
	int maxLen = 0;
	unordered_map<int, int> sumHash;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		
		if (sum == K)
		{
			maxLen = i + 1;
		}
		else
		{
			// Note: if sum is not in hash, insert it with current index
			if (sumHash.find(sum) == sumHash.end())
			{
				sumHash[sum] = i;
			}
		}

		if (sumHash.find(sum - K) != sumHash.end())
		{
			maxLen = max(i - sumHash[sum - K], maxLen);
		}
	}

	return maxLen;
}
