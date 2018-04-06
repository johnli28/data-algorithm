#pragma once

#pragma once

#include <memory>
#include <queue>

using namespace std;

typedef struct BSTNode
{
	// Note: One data, two child pointers
	int data;

	// Inside BSTNode, cannot define member as BSTNodePtr type, must use BSTNode* 
	BSTNode* left;
	BSTNode* right;

} BSTNode;

// Note: Pass two limits min and max
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

	// Note: A node queue for iterate all tree nodes
	queue<BSTNode*> nq;

	// Note: push left and right
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

		// Note: push the following 
		nq.push(l->left);
		nq.push(r->right);
		nq.push(l->right);
		nq.push(r->left);
		
	}

	return true;
}