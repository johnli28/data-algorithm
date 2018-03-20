#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

// Note:
// return a vector
// one loop pass, find the complement and return, otherwise insert itself
vector<int> TwoSum(int* arr, int length, int sum)
{
	vector<int> retVec;

	if (arr == nullptr || length <= 0)
	{
		return retVec;
	}

	unordered_map<int, int> hashTable;

	for (int i = 0; i < length; i++)
	{
		int complement = sum - arr[i];

		if (hashTable.find(complement) != hashTable.end())
		{
			retVec.push_back(i);
			retVec.push_back(hashTable[complement]);
			return retVec;
		}
		else
		{
			hashTable[arr[i]] = i;
		}
	}

	return retVec;
}


// Note:

// return a vector
// calculate % k 
// one loop pass, find the complement and return, otherwise insert itself
vector<int> TwoSumDivisibleByK(int* arr, int length, int k)
{
	vector<int> retVec;

	if (arr == nullptr || length <= 0)
	{
		return retVec;
	}

	unordered_map<int, int> hashTable;

	for (int i = 0; i < length; i++)
	{
		int remain = arr[i] % k;
		
		int toFind = k - remain;
		if (hashTable.find(toFind) != hashTable.end())
		{
			retVec.push_back(arr[i]);
			retVec.push_back(hashTable[toFind]);
			return retVec;
		}

		hashTable[remain] = arr[i];
	}

	return retVec;
}
