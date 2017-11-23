#include <string>
#include <iostream>

typedef struct ListNode
{
	int data;
	ListNode* next;
} ListNode, *ListNodePtr;

class LinkedList
{
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList() {}

	bool Append(int value);
	void Print();
	void ReversePrint();
	void ReversePrintRecur(ListNodePtr nPtr);
	ListNodePtr FindKFromTail(int k);
	void Revert();

private:
	ListNodePtr head;
};

