#pragma once

#include <iostream>
#include <string>
#include "utils.h"

#include <vector>

using namespace std;

// NOTE:
// dynamic programming: split a big problem into small problems
// A dynamic programming table, store the states (results) of small problems
// Initiate states

int lcsDP(char* lStr, int lLen, char* rStr, int rLen, string & lcsStr)
{
	vector<vector<int>> table;

	int lcsLen = 0;

	for (int i = 0; i <= lLen; i++)
	{
		table.push_back(vector<int>(rLen + 1));

		for (int j = 0; j <= rLen; j++)
		{
			if (i == 0 || j == 0)
			{
				table[i][j] = 0;
			}
			else if (lStr[i - 1] == rStr[j - 1])
			{
				table[i][j] = 1 + table[i - 1][j - 1];
				lcsStr.append(1, lStr[i - 1]);
			}
			else
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}	

	return table[lLen][rLen];
}