#pragma once
#include <unordered_set>

using namespace std;

int	 GetLengthOfLongestUnrepeatSubstring(const string& str)
{
	int start = 0, end = 0;

	unordered_set<char> window;

	int ret = 0;

	// Note: use start and end as a slide window
	while (start < str.size() && end < str.size())
	{
		if (window.find(str[end]) == window.end())
		{
			window.insert(str[end]);
			end++;

			if (ret < end - start)
			{
				ret = end - start;
			}

		}
		else
		{
			start++;
			window.erase(str[end]);

		}
	}

	return ret;
}