#include <memory>


typedef struct ListNode
{
	// Inside ListNode, cannot define member as ListNodePtr type, must use ListNode*
	int data;
	std::shared_ptr<ListNode> next;
} ListNode;

typedef std::shared_ptr<ListNode> ListNodePtr;

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

