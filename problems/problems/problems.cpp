#include "problems.h"

#include <stack>
#include <unordered_set>

bool ValidateParentheses(const string& str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.top() == '(')
			{
				s.pop();
			}
		}
		else if (str[i] == ']')
		{
			if (s.top() == '[')
			{
				s.pop();
			}
		}
		else if (str[i] == '}')
		{
			if (s.top() == '{')
			{
				s.pop();
			}
		}
	}

	if (s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int	 GetLengthOfLongestUnrepeatSubstring(const string& str)
{
	int start = 0, end = 0;

	unordered_set<char> window;

	int ret = 0;

	// Note: use const_iterator to iterate const string
	while (start < str.size() && end < str.size()  )
	{
		if (window.find(str[end]) == window.end())
		{
			window.insert(str[end]);
			end++;

			if (ret < end - start)
			{
				ret = end - start;
			}

		}
		else
		{
			start++;
			window.erase(str[end]);

		}
	}

	return ret;
}