#include "BinarySortTree.h"

#include <iostream>

using namespace std;

int main()
{
	BST myTree;
	myTree.Insert(7);
	myTree.Insert(5);
	myTree.Insert(3);
	myTree.Insert(4);
	myTree.Insert(6);

	myTree.PostfixPrint();

	getchar();
}