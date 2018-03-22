#pragma once

void ReverseArray(int * a, int length)
{
	if (a == nullptr || length <= 1)
	{
		return;
	}
	
	for (int start = 0, end = length - 1; start < end; start++, end--)
	{
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
	}
}