#pragma once

//Note: Use C to implement linked list and some usual functions

using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

typedef ListNode* LinkedList;

void InitEmptyList(LinkedList& head);
void Append(LinkedList& head, int i);
void AppendNode(LinkedList& head, ListNode* node);

void PrintList(LinkedList head);
void RevertPrint(LinkedList head);

ListNode* FindLastKNode(LinkedList head, int k);

// Note: linked list has only one next pointer, if two lists have a common part, it must from some node until their common ending node
ListNode* FindFirstCommonNode(LinkedList l1, LinkedList l2);

void RevertList(LinkedList& head);

ListNode* ConcatTwoLists(LinkedList& l1, LinkedList& l2);

void RemoveNodesWithK(LinkedList & head, int k);
ListNode* RemoveDuplicatedNodes(LinkedList & head);

bool HasCycle(LinkedList head);