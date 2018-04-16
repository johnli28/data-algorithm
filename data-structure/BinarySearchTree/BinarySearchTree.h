#pragma once

#pragma once

#include <memory>
#include <queue>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

typedef struct BSTNode
{
	// Note: One data, two child pointers
	int data;

	// Inside BSTNode, cannot define member as BSTNodePtr type, must use BSTNode* 
	BSTNode* left;
	BSTNode* right;

} BSTNode;

// Note: Recursive util function with two limits min and max passing in
bool IsBSTHelper(BSTNode* node, int min, int max)
{
	// Note: Empty tree is BST
	if(node == nullptr)
	{
		return true;
	}

	// Note: data is not between min and max, not BST 
	if (node->data < min || node->data > max)
	{
		return false;
	}

	// Note: Recursive check left and right subtrees with new limits
	return IsBSTHelper(node->left, min, node->data - 1) && IsBSTHelper(node->right, node->data + 1, max);
}


bool IsBST(BSTNode* node)
{
	if (node == nullptr)
	{
		return true;
	}

	int min = INT_MIN;
	int max = INT_MAX;

	return IsBSTHelper(node, INT_MIN, INT_MAX);


}

bool IsSymm(BSTNode* node)
{
	if (node == nullptr)
	{
		return true;
	}

	// Note: Init a queue for iterate all tree nodes and push root's left and right
	queue<BSTNode*> nq;

	nq.push(node->left);
	nq.push(node->right);

	// Note: while queue is not empty
	while (!nq.empty())
	{
		// Note: Pop two and compare each other
		BSTNode* l = nq.front();
		nq.pop();

		BSTNode* r = nq.front();
		nq.pop();

		if (l == nullptr && r == nullptr)
		{
			continue;
		}
		else if (l != nullptr && r == nullptr)
		{
			return false;
		}
		else if (l == nullptr && r != nullptr)
		{
			return false;
		}
		else if (l->data != r->data)
		{
			return false;
		}

		// Note: push subsequent children 
		nq.push(l->left);
		nq.push(r->right);
		nq.push(l->right);
		nq.push(r->left);
		
	}

	return true;
}

// Note: recursive util function with two In & Out parameters: diff and diffKey
void ClosestValueInBSTHelper(BSTNode* tree, double d, int& diff, int& diffKey)
{
	if (tree == nullptr)
	{
		return;
	}

	// Note: if data equals with d, return
	if (tree->data == d)
	{
		diff = 0;
		diffKey = tree->data;
		return;
	}

	// Note: calculate latest diff
	if (diff > abs(tree->data - d))
	{
		diff = abs(tree->data - d);
		diffKey = tree->data;
	}

	// Note: recursive go to left or right child
	if (d < tree->data)
	{
		ClosestValueInBSTHelper(tree->left, d, diff, diffKey);
	}
	else
	{
		ClosestValueInBSTHelper(tree->right, d, diff, diffKey);
	}

}

int ClosestValueInBST(BSTNode* tree, double d)
{
	
	int minDiff = INT_MAX;
	int minDiffKey;

	ClosestValueInBSTHelper(tree, d, minDiff, minDiffKey);

	return minDiffKey;
}


// Note: define a helper function and pass both tree node and value
int SumLeafNumbersHelper(BSTNode* tree, int val)
{
	if (tree == nullptr)
	{
		return 0;
	}

	// Note: calculate current representing value
	int myNumber = val * 10 + tree->data;

	// Note: If it is a leaf, return value, otherwise return recursive left + right
	if (tree->left == nullptr && tree->right == nullptr)
	{	
		return myNumber;
	}
	else
	{
		return SumLeafNumbersHelper(tree->left, myNumber) + SumLeafNumbersHelper(tree->right, myNumber);
	}
	
}

int SumLeafNumbers(BSTNode* tree)
{
	int val = 0;
	return SumLeafNumbersHelper(tree, val);
}


void LevelOrderTraverse(BSTNode* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	// Note: Init a queue and push root in
	queue<BSTNode*> nq;
	nq.push(tree);

	// Note: while queue is not empty, access data, then push left and right
	while (!nq.empty())
	{
		BSTNode* l = nq.front();
		nq.pop();
		std::cout << l->data << std::endl;

		if (l->left != nullptr)
		{
			nq.push(l->left);
		}
		
		if (l->right != nullptr)
		{
			nq.push(l->right);
		}
	}
}

void InOrderTraverse(BSTNode* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	stack<BSTNode*> ns;
	BSTNode* cur = tree;

	while (cur != nullptr)
	{
		ns.push(cur);
		cur = cur->left;
	}

	while (!ns.empty())
	{
		BSTNode* t = ns.top();
		ns.pop();

	std:cout << t->data << std::endl;

		BSTNode* r = t->right;

		while (r != nullptr)
		{
			ns.push(r);
			r = r->left;
		}
	}
}

