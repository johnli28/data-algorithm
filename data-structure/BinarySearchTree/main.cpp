#include "BinarySearchTree.h"
#include "Serializer.h"

void main()
{
	std::string testSer1 = "7!3!2!#!#!5!#!#!9!#!#!";

	BSTNode * bst1 = nullptr;
	Deserialize(testSer1, bst1);

	bool isBSTRet = IsBST(bst1);

	bool isSymmRet = IsSymm(bst1);

	InOrderTraverse(bst1);

	getchar();
}