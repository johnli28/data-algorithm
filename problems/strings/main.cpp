#include "KthUnrepeatingChar.h"
#include "ReverseString.h"
#include "LongestPalindromeSubstring.h"

void main()
{
	string test = "abbcdaef";

	char retCh;
	bool ret = KthUnrepeatingChar(test, 3, retCh);

	char rs[] = "Hello a good world";

	ReverseString(rs, sizeof(rs) - 1);

	string str = "abc";

	string lps = LongestPalindromeSubstring(str);
	lps = LongestPalindromeSubstring("");

	lps = LongestPalindromeSubstring("abbacdca");
}
