#include "SingleLinkedList.h"

int main()
{
	LinkedList l;
	l.Append(1);
	l.Append(2);
	l.Append(3);

	//l.Print();

	l.ReversePrint();

	//l.Revert();

	//l.Print();

	ListNodePtr kNode = l.FindKFromTail(4);

	if (kNode == nullptr)
	{
		std::cout << "K from tail is not present" << std::endl;
	}
	else
	{
		std::cout << "K from tail is: " << kNode->data << std::endl;
	}

	getchar();

}