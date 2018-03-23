#pragma once
#include <vector>

using namespace std;

int Fib(int n)
{
	// Note: input value check
	if (n < 0)
	{
		return -1;
	}

	// Note: construct a vector with size = n+1
	vector<int> fibTable(n + 1);

	// Note: init first two elements
	fibTable[0] = 0;
	fibTable[1] = 1;

	// Note: calcuate all others in for loop
	for (int i = 2; i <= n; i++)
	{
		fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
	}

	return fibTable[n];
};
