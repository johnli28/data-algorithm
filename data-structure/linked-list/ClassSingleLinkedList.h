#include <memory>


typedef struct SingleLinkedListNode
{
	// Inside ListNode, cannot define member as ListNodePtr type, must use ListNode*
	int data;
	std::shared_ptr<SingleLinkedListNode> next;
};

typedef std::shared_ptr<SingleLinkedListNode> ListNodePtr;

class SingleLinkedList
{
public:
	SingleLinkedList()
	{
		head = nullptr;
	}
	~SingleLinkedList() {}

	bool Append(int value);
	void Print();
	void ReversePrint();
	void ReversePrintRecur(ListNodePtr nPtr);
	ListNodePtr FindKFromTail(int k);
	void Revert();

private:
	ListNodePtr head;
};

