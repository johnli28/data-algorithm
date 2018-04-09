#pragma once

#include <string>
#include <unordered_map>

using namespace std;

string IntegerToWordsHelper(int num)
{
	unordered_map<int, string> wordsMap;

	wordsMap[1] = "one";
	wordsMap[2] = "two";
	wordsMap[3] = "three";
	wordsMap[4] = "four";
	wordsMap[5] = "five";
	wordsMap[6] = "six";
	wordsMap[7] = "seven";
	wordsMap[8] = "eight";
	wordsMap[9] = "nine";

	wordsMap[11] = "eleven";
	wordsMap[12] = "twelve";
	wordsMap[13] = "thirteen";
	wordsMap[14] = "forteen";
	wordsMap[15] = "fifteen";
	wordsMap[16] = "sixteen";
	wordsMap[17] = "seventeen";
	wordsMap[18] = "eighteen";
	wordsMap[19] = "nineteen";

	wordsMap[20] = "twenty";
	wordsMap[30] = "thirty";
	wordsMap[40] = "forty";
	wordsMap[50] = "fifty";
	wordsMap[60] = "sixty";
	wordsMap[70] = "seventy";
	wordsMap[80] = "eighty";
	wordsMap[90] = "ninety";

	int thisNum = num;
	int remain = 0;
	string result;
	
	if (thisNum >= 100)
	{
		result = wordsMap[thisNum / 100] + " hundread";
		thisNum = thisNum % 100;
	}

	if (thisNum > 0)
	{
		if (thisNum > 20)
		{
			remain = thisNum / 10;
			thisNum = thisNum % 10;

			result += " " + wordsMap[remain * 10] + " " + wordsMap[thisNum];
		}
		else 
		{
			result += " " + wordsMap[thisNum];
		}
	}

	return result;

}

string IntegerToWords(int num)
{
	string result;

	int thisNum = num;
	int remain;

	if (num == 0)
	{
		return "zero";
	}

	if (thisNum >= 1000000000)
	{
		remain = thisNum / 1000000000;
		thisNum = thisNum % 1000000000;

		result += IntegerToWordsHelper(remain) + " billion";
	}

	if (thisNum >= 1000000)
	{
		remain = thisNum / 1000000;
		thisNum = thisNum % 1000000;

		result += IntegerToWordsHelper(remain) + " million";
	}

	if (thisNum >= 1000)
	{
		remain = thisNum / 1000;
		thisNum = thisNum % 1000;

		result += IntegerToWordsHelper(remain) + " thousand";
	}

	if (thisNum > 0)
	{
		result += IntegerToWordsHelper(thisNum);
	}

	return result;
	
}
