#include "BinaryTree.h"

#include <iostream>
#include <string>

void Deserialize(const string& inStr, BinaryTree & outTree)
{
	if (inStr.empty())
	{
		return;
	}

	int startPos = 0;

	DeserializeInorder(inStr, startPos, outTree);
	
}

// Note: use pos to track the position, must &
void DeserializeInorder(const string& inStr, int& pos, BinaryTree & outTree)
{
	if (pos >= inStr.size())
	{
		return;
	}

	// Fault: find_first_of would pass pos as offset
	size_t endPos = inStr.find_first_of('!', pos);

	if (endPos == inStr.npos)
	{
		return;
	}
	else
	{
		std::string dataStr = inStr.substr(pos, endPos - pos);

		if (dataStr == "#")
		{
			// Fault: forget to add pos and return directly
			pos += 2;
			return;
		}
		else
		{
			int value = std::stoi(dataStr);

			outTree = new BinaryTreeNode;
			outTree->data = value;
			outTree->left = nullptr;
			outTree->right = nullptr;

		}

		pos += endPos - pos + 1;
		
	}

	DeserializeInorder(inStr, pos, outTree->left);

	DeserializeInorder(inStr, pos, outTree->right);

}

void PrintLeftNodes(BinaryTree tree)
{
	while (tree->left != nullptr)
	{
		cout << tree->data << ", " << std::endl;
		tree = tree->left;
	}
}

void PrintLeavesNodes(BinaryTree tree)
{
	if (tree == nullptr)
	{
		return;
	}

	if (tree->left == nullptr && tree->right == nullptr)
	{
		cout << tree->data << "," << std::endl;
	}

	PrintLeavesNodes(tree->left);

	PrintLeavesNodes(tree->right);

}

void UnclockwisePrintEdgeNodes(BinaryTree tree)
{
	if (tree == nullptr)
	{
		return;
	}
}