#include "ClassSingleLinkedList.h"
#include "LinkedList.h"
#include <iostream>

int main()
{
	/*
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
	*/

	LinkedList temp;

	LinkedList l1 = nullptr;
	Append(l1, 1);

	LinkedList l2 = nullptr;
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

	LinkedList l3 = nullptr;
	Append(l3, 5);
	Append(l3, 6);

	ConcatTwoLists(l2, l3);
	ConcatTwoLists(l1, l3);

	ListNode* common = FindFirstCommonNode(l2, l1);


	LinkedList listToRemoveK = nullptr;
	Append(listToRemoveK, 1);
	Append(listToRemoveK, 2);
	Append(listToRemoveK, 1);
	Append(listToRemoveK, 1);
	Append(listToRemoveK, 2);

	RemoveNodesWithK(listToRemoveK, 1);


	getchar();

}