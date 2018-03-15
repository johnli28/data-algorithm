#include "lcs.h"

void main()
{
	char a[] = "a1btyu2dop";
	char b[] = "rqb82gmnd";

	int ret = lcs(a, sizeof(a) - 1, b, sizeof(b) - 1);
}