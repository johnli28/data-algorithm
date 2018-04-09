#include "KthUnrepeatingChar.h"
#include "ReverseString.h"

void main()
{
	string test = "abbcdaef";

	char retCh;
	bool ret = KthUnrepeatingChar(test, 3, retCh);

	char rs[] = "Hello a good world";

	ReverseString(rs, sizeof(rs) - 1);
}
