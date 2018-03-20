#pragma once

bool IsPalindrome(int n)
{
	// Fault: save n to originN, because n is to be used for checking equal when return
	int originN = n;
	int reversedN = 0;

	// minus number cannot be palindrome
	if (originN < 0)
	{
		return false;
	}

	while (originN > 0)
	{
		int place = originN % 10;
		reversedN = reversedN * 10 + place;
		originN /= 10;
	}

	return reversedN == n ? true: false;
}

int FindNextPalindrome(int n)
{
	int m = n + 1;

	// Fault: m = n is in for loop and cause endless loop
	for (; m >= n; m++)
	{
		if (IsPalindrome(m))
		{
			return m;
		}
	}

	return -1;
}
