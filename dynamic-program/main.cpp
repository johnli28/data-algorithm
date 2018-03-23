#include "LongestCommonSubsequence.h"
#include "LongestIncreaseSubsequence.h"

void main()
{
	char a[] = "a1btyu2dop";
	char b[] = "rqb82gmnd";

	//int ret = lcs(a, sizeof(a) - 1, b, sizeof(b) - 1);



	string lcsStr;

	int ret2 = lcsDP(a, sizeof(a) - 1, b, sizeof(b) - 1, lcsStr);

	int c[] = { 5,2,3,6,7,9,4,5,6 };

	vector<int> lis;
	lis = LongestIncreaseSubsequence(c, sizeof(c)/sizeof(int));
}