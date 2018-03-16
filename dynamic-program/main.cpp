#include "lcs.h"

void main()
{
	char a[] = "a1btyu2dop";
	char b[] = "rqb82gmnd";

	//int ret = lcs(a, sizeof(a) - 1, b, sizeof(b) - 1);



	string lcsStr;

	int ret2 = lcsDP(a, sizeof(a) - 1, b, sizeof(b) - 1, lcsStr);
}