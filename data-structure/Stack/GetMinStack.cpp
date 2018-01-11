#include "GetMinStack.h"

void GetMinStack::Push(int i)
{
	dataStack.push(i);

	// Note: check minStack is empty
	if (minStack.empty())
	{
		minStack.push(i);
	}
	else
	{
		// Note: less or equal, then push to minStack
		if (i <= minStack.top())
		{
			minStack.push(i);
		}
	}
}

bool GetMinStack::Pop(int & i)
{
	if (dataStack.empty())
	{
		return false;
	}

	i = dataStack.top();
	dataStack.pop();

	if (!minStack.empty() && minStack.top() == i)
	{
		minStack.pop();
	}

	return true;
}

int GetMinStack::GetMin()
{
	// Note: throw a runtime_error when minStack is empty
	if (minStack.empty())
	{
		throw runtime_error("minStack is empty");
	}

	return minStack.top();
}