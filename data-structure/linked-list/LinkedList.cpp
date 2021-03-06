#include <iostream>
#include <stdexcept> // runtime_error is declared inside

#include "LinkedList.h"

// Note: Use C to implement linked list and some usual functions

using namespace std;

// Fault: init head as nullptr, otherwise it is a raw pointer and cause exception
void InitEmptyList(LinkedList& head)
{
	head = nullptr;
}

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

void AppendNode(LinkedList& head, ListNode* node)
{
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}

		cur->next = node;
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

	// Note: init pre = head and cur = head->next
	ListNode* pre = head;
	ListNode* cur = head->next;

	// Note: init head->next as nullptr
	// Fault: typo to == and cause deadlock between two nodes
	head->next = nullptr;

	
	// Note: while loop when cur is not null
	while (cur != nullptr)
	{
		// Note: assign next, and move cur to pre, and next to cur
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

	if (head == nullptr)
	{
		return;
	}

	ListNode* pre = head;
	ListNode* cur = pre->next;

	// Note: null check for both cur and cur->next
	while (cur != nullptr)
	{
		if (cur->data == k)
		{
			pre->next = cur->next;
		}
		else
		{
			pre = cur;
		}

		cur = pre->next;
	}
}

void RemoveNodesLargerThanK(LinkedList & head, int k)
{
	while (head != nullptr && head->data >= k)
	{
		head = head->next;
	}

	if (head == nullptr)
	{
		return;
	}

	ListNode* pre = head;
	ListNode* cur = head->next;

	while (cur != nullptr)
	{
		if (cur->data >= k)
		{
			pre->next = cur->next;
			cur = cur->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}


ListNode* RemoveDuplicatedNodes(LinkedList & head)
{
	return nullptr;
}

bool HasCycle(LinkedList head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return false;
	}

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != nullptr && slow != nullptr)
	{
		slow = slow->next;
		fast = fast->next;

		if (fast != nullptr)
		{
			fast = fast->next;
		}

		if (fast != nullptr && fast == slow)
		{
			return true;
		}
	}

	return false;


}

LinkedList MergeTwoLists(LinkedList A, LinkedList B)
{
	if (A == nullptr)
	{
		return B;
	}
	else if (B == nullptr)
	{
		return A;
	}

	ListNode* result = nullptr;

	if (A->data >= B->data)
	{
		result = B;
		result->next = MergeTwoLists(A, B->next);
	}
	else
	{
		result = A;
		result->next = MergeTwoLists(A->next, B);
	}

	return result;
}

// Divide and conquer
LinkedList MergeKLists(vector<LinkedList> & listVec)
{
	int totalCount = listVec.size();

	// Note: two while loop pass, external condition is list count more than 1
	while (totalCount > 1)
	{
		int begin = 0;
		int end = totalCount - 1;

		// Merge each of two together
		while (begin < end)
		{
			listVec[begin] = MergeTwoLists(listVec[begin], listVec[end]);
			begin++;
			end--;
		}

		totalCount = end + 1;
	}

	return listVec[0];
}

LinkedList addTwoLists(LinkedList l1, LinkedList l2)
{
	// Note: init result and carry 
	LinkedList result = nullptr;
	LinkedList last = nullptr;
	int carry = 0;

	// Note: while condition, either linkedlist is not empty
	while (l1 != nullptr || l2 != nullptr)
	{
		int val = 0, val2 = 0;

		if (l1 != nullptr)
		{
			val = l1->data;
		}

		if (l2 != nullptr)
		{
			val2 = l2->data;
		}

		// Note: if val > 9, mode and carry = 1, otherwise carry = 0;
		int sum = val + val2 + carry;

		if (sum > 9)
		{
			sum = sum % 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		ListNode* newNode = new ListNode();
		newNode->data = sum;
		newNode->next = nullptr;

		// Append to the end
		if (result == nullptr)
		{
			result = newNode;
			last = result;
		}
		else
		{
			last->next = newNode;
			last = last->next;
		}

		// Fault: check null firstly
		if (l1 != nullptr)
		{
			l1 = l1->next;
		}

		if (l2 != nullptr)
		{
			l2 = l2->next;
		}

	}

	if (carry == 1)
	{
		ListNode* newNode = new ListNode();
		newNode->data = 1;
		newNode->next = nullptr;
		last->next = newNode;
	}

	return result;
}