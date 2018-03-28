#pragma once

#include <string>
#include <list>

using namespace std;

bool KthUnrepeatingChar(const string & str, int k, char& ch)
{
	int count[256];

	for (int i = 0; i < 256; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		count[str[i]] += 1;
	}

	int j = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (count[str[i]] == 1)
		{
			if (j++ == k)
			{
				ch = str[i];
				return true;
			}
		}
	}

	return false;
}
