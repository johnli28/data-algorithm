#pragma once

#include <vector>
#include "utils.h"

using namespace std;

int MatrixMinSum(const vector<vector<int>> & matrix, int sum)
{
	int row = matrix.size();
	int col = matrix[0].size();

	vector<vector<int>> dpTable;
	
	for (int i = 0; i < row; i++)
	{
		dpTable.push_back(vector<int>(col));

		if (i == 0)
		{
			dpTable[0][0] = matrix[0][0];
		}
		else
		{
			dpTable[i][0] = dpTable[i - 1][0] + matrix[i][0];
		}	
	}

	for (int j = 1; j < col; j++)
	{
		dpTable[0][j] = dpTable[0][j-1] + matrix[0][j];
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			dpTable[i][j] = min(dpTable[i - 1][j], dpTable[i][j - 1]) + matrix[i][j];
		}
	}

	return dpTable[row - 1][col - 1];
}