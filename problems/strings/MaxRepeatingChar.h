#pragma once

#include <string>
#include <exception>

using namespace std;

char MaxRepeatingChar(const string & str)
{
	if (str.empty())
	{
		throw std::exception();
	}

	int count = 0;
	int maxCount = 0;
	char retCh;

	// Note: One loop pass
	for (int i = 0; i < str.size(); i++)
	{
		// Note: initialize return char and count when index == 0
		if (i == 0)
		{
			retCh = str[0];
			count = 1;
		}
		else if (str[i] == str[i - 1])
		{
			// Note: if two consecutive elements are equal, increase count 
			count++;
		}
		else
		{
			// Note: compare count and maxCount and return char
			if (count > maxCount)
			{
				maxCount = count;
				retCh = str[i - 1];
			}
			count = 1;
		}
	}

}