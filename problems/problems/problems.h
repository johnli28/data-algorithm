#pragma once

#include <string>

using namespace std;

// Note: use stack
bool ValidateParentheses(const string& str);

//Note: use set as a slide window for checking repeatable, save maximum window length
int	 GetLengthOfLongestUnrepeatSubstring(const string& str);
