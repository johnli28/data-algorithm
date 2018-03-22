#pragma once

int MinSizeSubarraySum(int* a, int length, int sum)
{
	int left = 0;
	int curSum = 0;
	int ans = -1;

	for (int i = 0; i < length; i++)
	{
		curSum += a[i];

		while (curSum > sum)
		{
			if (ans < 0)
			{
				ans = i + 1 - left;
			}
			else
			{
				ans = ans > (i + 1 - left) ? (i + 1 - left) : ans;
			}

			curSum -= a[left];
			left++;
		}
	}

	return ans;
}
