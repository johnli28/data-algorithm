#pragma once

#include <string>

using namespace std;

// Note: Reverse function takes two char pointers: start, end 
void Reverse(char* start, char* end)
{
	for (; start < end; start++, end--)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
	}
}
void ReverseString(char* str, int length)
{
	int index = 0;
	char* word = str;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			Reverse(word, str + i - 1);

			if (i == length - 1)
			{
				break;
			}
			else
			{
				word = str + i + 1;
			}
		}
		
		if (i == length - 1)
		{
			// Fault: Reverse(word, word + i) 
			// Check the end point of the last word: str + length - 1 
			Reverse(word, str + i);
		}

	}

	Reverse(str, str + length - 1);

	
}
