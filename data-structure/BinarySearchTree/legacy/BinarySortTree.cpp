#include "BinarySortTree.h"
#include <iostream>

using namespace std;

// Note: non-recursive function as wrapper, call another recursive function
bool BST::Search(int key, BSTNodePtr& pos)
{
	return SearchRecur(root, nullptr, key, pos);
}

// Fault: forget parameter parent 
// parent is critical, if key is not found, tree is already a null pointer, pos would point to tree's parent (the last traversion node)
bool BST::SearchRecur(BSTNodePtr tree, BSTNodePtr parent, int key, BSTNodePtr& pos)
{
	if (tree == nullptr) // Not found, return parent as the position of last traversion node
	{
		pos = parent;
		return false;
	}
	else if (tree->data == key) //Found it, return tree
	{
		pos = tree;
		return true;
	}
	else if (tree->data > key) // Continue search on left child tree
	{
		// Fault: miss return, the result could be random
		return SearchRecur(tree->lChild, tree, key, pos);
	}
	else // Continue search on right child tree
	{
		// Fault: miss return, the result could be random
		return SearchRecur(tree->rChild, tree, key, pos);
	}
}

// Note: Search first, then Insert
bool BST::Insert(int key)
{
	BSTNodePtr lastPos;
	if (SearchRecur(root, nullptr, key, lastPos))
	{
		return false;
	}
	else
	{
		if (root == nullptr)
		{
			root = std::make_shared <BSTNode>();
			root->data = key;
			root->lChild = nullptr;
			root->rChild = nullptr;
		}
		else if (key < lastPos->data)
		{
			//Insert as the left child
			lastPos->lChild = std::make_shared <BSTNode>();
			lastPos->lChild->data = key;
			lastPos->lChild->lChild = nullptr;
			lastPos->lChild->rChild = nullptr;
		}
		else
		{
			//Insert as right child
			lastPos->rChild = std::make_shared <BSTNode>();
			lastPos->rChild->data = key;
			lastPos->rChild->lChild = nullptr;
			lastPos->rChild->rChild = nullptr;
		}

		return true;
	}
}

// Note: non-recursive function as wrapper, call another recursive function
void BST::PostfixPrint()
{
	if (root == nullptr)
	{
		std::cout << "This is an empty tree" << std::endl;
	}
	else
	{
		PostfixPrintRecur(root);
	}
}

void BST::PostfixPrintRecur(const BSTNodePtr& tree)
{
	if (tree == nullptr)
	{
		return;
	}

	if(tree->lChild != nullptr)
	{
		PostfixPrintRecur(tree->lChild);
	}
	
	std::cout << tree->data << ", " << std::endl;

	if (tree->rChild != nullptr)
	{
		PostfixPrintRecur(tree->rChild);
	}
}

int BST::Depth()
{
	return DepthRecur(root);
}

int BST::DepthRecur(BSTNodePtr tree)
{
	if (tree == nullptr)
	{
		return 0;
	}
	else
	{
		int leftDepth = DepthRecur(tree->lChild);
		int rightDepth = DepthRecur(tree->rChild);

		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
}