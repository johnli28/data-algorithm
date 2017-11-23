#include "SingleLinkedList.h"


bool LinkedList::Append(int value)
{
	if (head == nullptr)
	{
		// if it is a empty list, head points to the first node
		head = new ListNode();
		head->data = value;
		head->next = nullptr;
	}
	else
	{
		//Traverse to the last node
		ListNodePtr nodeIndex = head;

		while (nodeIndex != nullptr && nodeIndex->next != nullptr)
		{
			nodeIndex = nodeIndex->next;
		}

		ListNodePtr nNode = new ListNode();
		nNode->data = value;
		nNode->next = nullptr;

		nodeIndex->next = nNode;
	}

	return true;

}

void LinkedList::Print()
{
	ListNodePtr p = head;
	while (p != nullptr)
	{
		std::cout << p->data << ",";
		p = p->next;
	}

	std::cout << std::endl;
	std::cout << "This is the end of linked list" << std::endl;
}

// This function is wrapper, calling another recursive function
// Anyway to implement this function via loop?
void LinkedList::ReversePrint()
{
	ReversePrintRecur(head);
	std::cout << std::endl;
}

// Recursion
void LinkedList::ReversePrintRecur(ListNodePtr nPtr)
{
	if (nPtr != nullptr)
	{
		if (nPtr->next != nullptr)
		{
			ReversePrintRecur(nPtr->next);
		}

		std::cout << nPtr->data << ", ";
	}

}

ListNodePtr LinkedList::FindKFromTail(int k)
{
	// Boundary check of input arguments
	if (k <= 0)
	{
		return nullptr;
	}
	else
	{
		ListNodePtr kNode = head;

		//kNode check is necessary because list size might be less than k
		for (int step = 0; step < k && kNode != nullptr; step++)
		{
			kNode = kNode->next;
		}

		if (kNode == nullptr)
		{
			return nullptr;
		}

		ListNodePtr former = head;
		ListNodePtr latter = kNode;

		while (latter != nullptr)
		{
			former = former->next;
			latter = latter->next;
		}

		return former;
	}
}

// Three pointers needed
// p2 assigned to p1 firstly, then p3 assigned to p2
void LinkedList::Revert()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	else
	{
		ListNodePtr origHead = head;
		ListNodePtr p1 = head;
		ListNodePtr p2 = p1->next;

		while (p2 != nullptr)
		{
			ListNodePtr p3 = p2->next;
			p2->next = p1;

			// Cannot make this mistake, equals p1 = p3 
			// p2 = p3; p1 = p2; 
			p1 = p2;
			p2 = p3;
		}

		head = p1;
		origHead->next = nullptr;
	}
}

	