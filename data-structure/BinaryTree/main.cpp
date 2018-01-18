#include "BinaryTree.h"

#include <iostream>

using namespace std;

int main()
{
	BinaryTree tree, tree2;

	std::string testSer1 = "1!2!#!#!3!#!#!";
	std::string testSer2 = "1!2!3!#!#!#!#!";

	Deserialize(testSer1, tree);
	Deserialize(testSer2, tree2);


	getchar();
}