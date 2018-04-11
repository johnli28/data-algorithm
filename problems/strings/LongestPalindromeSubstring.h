#pragma once

#include <string>

using namespace std;

int ExpandSubstring(const std::string & str, int left, int right)
{

	int L = left, R = right;

	for (; L >= 0 && R < str.size(); )
	{
		// Fault: L-- and R++ is run once than expected, so return R - L - 1;
		if (str[L] == str[R])
		{
			L--;
			R++;
		}
		else
		{
			break;
		}
	}

	// Fault: cannot return R - L + 1, because L-- and R++ execute one more time
	return R - L - 1;
}

string LongestPalindromeSubstring(const std::string & str)
{
	int maxLen = 0;
	int start = 0, end = 0;

	if (str.empty())
	{
		return string();
	}

	for (int i = 0; i < str.size(); i++)
	{
		int len1 = ExpandSubstring(str, i, i);
		int len2 = ExpandSubstring(str, i, i+1);

		int len = len1 > len2 ? len1 : len2;

		if (len > maxLen)
		{
			maxLen = len;
			if (len % 2 == 0)
			{
				start = i - len / 2 + 1;
				end = i + len / 2;
			}
			else
			{
				start = i - len / 2;
				end = i + len / 2;
			}
		}
	}

	return str.substr(start, end - start + 1);
}

