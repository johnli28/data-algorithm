#include "ClassSingleLinkedList.h"
#include "LinkedList.h"
#include <iostream>

void TestClassSingleLinkedList()
{
	SingleLinkedList l;
	l.Append(1);
	l.Append(2);
	l.Append(3);
	l.Append(4);
	l.Append(5);

	l.Print();

	l.ReversePrint();

	l.Revert();

	l.Print();

	ListNodePtr kNode = l.FindKFromTail(4);

	if (kNode == nullptr)
	{
		std::cout << "K from tail is not present" << std::endl;
	}
	else
	{
		std::cout << "K from tail is: " << kNode->data << std::endl;
	}
}

void TestLinkedList()
{
	LinkedList temp;

	LinkedList l1;
	InitEmptyList(l1);

	Append(l1, 1);

	LinkedList l2;
	InitEmptyList(l2);

	Append(l2, 1);
	Append(l2, 2);
	Append(l2, 3);
	Append(l2, 4);

	ListNode* lastK = FindLastKNode(l1, -1);
	lastK = FindLastKNode(l1, 0);
	lastK = FindLastKNode(l1, 5);

	lastK = FindLastKNode(l2, -1);
	lastK = FindLastKNode(l2, 0);
	lastK = FindLastKNode(l2, 1);
	lastK = FindLastKNode(l2, 4);
	lastK = FindLastKNode(l2, 5);

	RevertPrint(l2);

	RevertList(l2);

	PrintList(l2);

	LinkedList l3;
	InitEmptyList(l3);

	Append(l3, 5);
	Append(l3, 6);

	ConcatTwoLists(l2, l3);
	ConcatTwoLists(l1, l3);

	ListNode* common = FindFirstCommonNode(l2, l1);


	LinkedList listToRemoveK;

	InitEmptyList(listToRemoveK);

	Append(listToRemoveK, 1);
	Append(listToRemoveK, 2);
	Append(listToRemoveK, 1);
	Append(listToRemoveK, 1);
	Append(listToRemoveK, 2);

	RemoveNodesWithK(listToRemoveK, 1);

	LinkedList listHasCycle;
	InitEmptyList(listHasCycle);

	ListNode * cycleNode = new ListNode;
	cycleNode->data = 4;
	cycleNode->next = nullptr;

	Append(listHasCycle, 1);
	Append(listHasCycle, 2);
	Append(listHasCycle, 3);
	AppendNode(listHasCycle, cycleNode);

	Append(listHasCycle, 5);
	Append(listHasCycle, 6);
	Append(listHasCycle, 7);
	AppendNode(listHasCycle, cycleNode);

	bool isCycle = HasCycle(listHasCycle);
	isCycle = HasCycle(l2);

}

int main()
{
	TestLinkedList();

	getchar();

}