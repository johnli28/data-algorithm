#pragma once

#include <unordered_map>

using namespace std;

bool HasDuplicateNumber(int* a, int length, int& dn)
{
	if (a == nullptr || length <= 0)
	{
		return false;
	}

	unordered_map<int, bool> hashTable;

	for (int i = 0; i < length; i++)
	{
		if (hashTable.find(a[i]) == hashTable.end())
		{
			hashTable[a[i]] = true;
		}
		else
		{
			dn = a[i];
			return true;
		}
	}

	return false;
}

bool HasDuplicateNumber1toN(int* a, int N, int& dn)
{
	if (a == nullptr || N <= 0)
	{
		return false;
	}

	// The element value is in range of 1 to N, create an array of size N+1 as hash table
	vector<int> hashTable(N+1);

	for (int i = 0; i < N; i++)
	{
		if (hashTable[a[i]] == 0)
		{
			hashTable[a[i]] = 1;
		}
		else
		{
			dn = a[i];
			return true;
		}
	}

	return false;
}