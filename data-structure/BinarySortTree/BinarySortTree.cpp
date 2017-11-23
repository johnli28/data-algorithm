#include "BinarySortTree.h"
#include <iostream>

using namespace std;

bool BST::Search(int key, BSTNodePtr& pos)
{
	return SearchRecur(root, nullptr, key, pos);
}

// parent is a critical parameter, in case of key not found, tree is already a null pointer, pos would point to tree's parent (the last traversion node)
bool BST::SearchRecur(BSTNodePtr tree, BSTNodePtr parent, int key, BSTNodePtr& pos)
{
	if (tree == nullptr)
	{
		// Not found, return tree's parent, it is the position of last traversion node
		pos = parent;
		return false;
	}
	else if (tree->data == key)
	{
		pos = tree;
		return true;
	}
	else if (tree->data > key)
	{
		// Continue search on left child tree
		// Mistake: without return here, the result will be random
		return SearchRecur(tree->lChild, tree, key, pos);
	}
	else
	{
		// Continue search on right child tree
		// Mistake: without return here, the result will be random
		return SearchRecur(tree->rChild, tree, key, pos);
	}
}

//Insert based on SearchRecur
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