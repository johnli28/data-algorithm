#pragma once

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int lcs(char* lStr, int lLen, char* rStr, int rLen)
{
	int lcsLen = 0;
	if (lLen == 0 || rLen == 0)
	{
		return lcsLen;
	}
	else if (lStr[lLen - 1] == rStr[rLen - 1])
	{
		lcsLen = 1 + lcs(lStr, lLen - 1, rStr, rLen - 1);
	}
	else
	{
		lcsLen = max(lcs(lStr, lLen - 1, rStr, rLen), lcs(lStr, lLen, rStr, rLen - 1));
	}
}