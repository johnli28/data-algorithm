#pragma once
#include <stack>

using namespace std;

class GetMinStack
{
public:
	void Push(int i);
	bool Pop(int& i);
	int GetMin();

private:

	// Two internal stacks, one for data, the other for min values
	stack<int> dataStack;
	stack<int> minStack;

};