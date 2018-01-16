#include "problems.h"

using namespace std;

int main()
{
	string l = "([{}])[]";

	bool ret = ValidateParentheses(l);

	l = "abcdeab";

	int iRet = GetLengthOfLongestUnrepeatSubstring(l);

}
