#pragma once
#include <vector>

using namespace std;

int Fib(int n)
{
	if (n < 0)
	{
		return -1;
	}

	vector<int> fibTable(n + 1);

	fibTable[0] = 0;
	fibTable[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
	}

	return fibTable[n];
};
