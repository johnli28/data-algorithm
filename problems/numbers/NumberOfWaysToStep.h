#pragma once

#include <vector>

using namespace std;

int NumberOfWaysToStep(int step)
{
	if (step < 0)
	{
		return -1;
	}
	else if (step == 0)
	{
		return 0;
	}
	else
	{
		vector <int> numberOfWaysVector(step + 1);

		// Initialize elements with indexes 0, 1 and 2
		numberOfWaysVector[0] = 0;
		numberOfWaysVector[1] = 1;
		numberOfWaysVector[2] = 2;

		// Note: since 3 on, it is Fibonacci formula
		for (int i = 3; i <= step; i++)
		{
			numberOfWaysVector[i] = numberOfWaysVector[i - 1] + numberOfWaysVector[i - 2];
		}

		return numberOfWaysVector[step];
	}
}

