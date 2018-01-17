#pragma once
#include <iostream>
#include <stdexcept> // runtime_error is declared inside

//Note: Use C to implement linked list and some usual functions

using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

typedef ListNode* LinkedList;

// Note: head could change, passing in &
void Append(LinkedList& head, int i)
{
	ListNode* newNode = new ListNode;
	if (newNode == nullptr)
	{
		throw runtime_error("bad allocation in Append");
	}

	newNode->data = i;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		ListNode* cur = head;

		// Fault: typo to head->next
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}

		cur->next = newNode;
	}
}


ListNode* FindLastKNode(LinkedList head, int k)
{
	if (head == nullptr || k <= 0)
	{
		return nullptr;
	}

	int diff = k;
	ListNode* cur = head;

	// Note: calculation diff = k - length
	// Fault: typo to head !=nullptr
	while (cur != nullptr)
	{
		diff--;
		cur = cur->next;
	}

	if (diff > 0)
	{
		// the last K node is not existed
		return nullptr;
	}
	else if (diff == 0)
	{
		return head;
	}
	else
	{
		ListNode* index = head;

		while (index != nullptr && diff < 0)
		{
			diff++;
			index = index->next;
		}

		return index;
	}
}

void PrintList(LinkedList head)
{
	ListNode* cur = head;

	while (cur != nullptr)
	{
		std::cout << cur->data << ", ";
		cur = cur->next;
	}

	std::cout << std::endl;
}

// Note: one way is to use recursion, the other is to use stack 
void RevertPrint(LinkedList head)
{
	if (head == nullptr)
	{
		return;
	}

	if (head->next != nullptr)
	{
		RevertPrint(head->next);
	}

	std::cout << head->data << ", " << std::endl;
}

void RevertList(LinkedList& head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	ListNode* pre = head;
	ListNode* cur = head->next;

	// Fault: typo to == and cause deadlock between two nodes
	head->next = nullptr;

	while (cur != nullptr)
	{
		ListNode* next = cur->next;
		cur->next = pre;

		pre = cur;
		cur = next;
	}

	head = pre;
}

ListNode* ConcatTwoLists(LinkedList& l1, LinkedList& l2)
{
	if (l1 == nullptr)
	{
		return l2;
	}
	else if (l2 == nullptr)
	{
		return l1;
	}
	else
	{
		ListNode* cur = l1;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}

		cur->next = l2;

		return l1;
	}
	
}

int GetListLength(LinkedList l)
{
	int length = 0;

	ListNode* pNode = l;
	while (pNode != nullptr)
	{
		pNode = pNode->next;
		length++;
	}

	return length;
}

// Note: linked list has only one next pointer, if two lists have a common part, it must from some node until their common ending node
ListNode* FindFirstCommonNode(LinkedList l1, LinkedList l2)
{
	if (l1 == nullptr || l2 == nullptr)
	{
		return nullptr;
	}
	else
	{
		int len1 = GetListLength(l1);
		int len2 = GetListLength(l2);

		ListNode* pLong = nullptr;
		ListNode* pShort = nullptr;
		int lenDiff;

		// Note: calculate the length diff and assign long and short
		if (len1 >= len2)
		{
			pLong = l1;
			pShort = l2;
			lenDiff = len1 - len2;
		}
		else
		{
			pLong = l2;
			pShort = l1;
			lenDiff = len2 - len1;
		}

		// Long list go to lenDiff step firstly
		while (lenDiff > 0)
		{
			pLong = pLong->next;
			lenDiff--;
		}

		while (pLong != nullptr && pShort != nullptr && pLong != pShort)
		{
			pLong = pLong->next;
			pShort = pShort->next;
		}

		return pLong;

	}
}

void RemoveNodesWithK(LinkedList & head, int k)
{
	if (head == nullptr)
	{
		return;
	}

	// Note: find new head, the first node with its data not k.
	while (head != nullptr && head->data == k)
	{
		head = head->next;
	}

	ListNode* pre = head;
	ListNode* cur = head;

	// Note: null check for both cur and cur->next
	while (cur != nullptr && cur->next != nullptr)
	{
		cur = pre->next;

		if (cur->data == k)
		{
			pre->next = cur->next;
		}
		else
		{
			pre = cur;
		}
	}
}

ListNode* RemoveDuplicatedNodes(LinkedList & head)
{
	return nullptr;
}