#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Note:
// C style two dimension array int[m][n]
// But m and n have to be constant values

const int M = 10;
const int N = 5;

int TwoDimArray[M][N];

std::string str = "abc";

// For example, this will cause a compile error, cannot find str.size() as size of Array in C
// int TwoDimArray2[str.size()][N];

// Note: C++ style of two dimension array
// vector of vector
// push back a vector as a new row

typedef vector<vector<int>> TwoDimTable;

void InitTwoDimArray(TwoDimTable& table, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		// Fault: cannot use table[i][j] directly, because it is not allocated yet
		// Push back a vector to table, as adding a row
		table.push_back(vector<int>(col));
		for (int j = 0; j < col; j++)
		{
			// can access it now
			table[i][j] = 1;
		}
	}
}
