#pragma once

#pragma once

#include <memory>
#include <queue>
#include <stack>
#include <queue>
#include <iostream>
#include <map>

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

void PreOrderTraverse(BSTNode* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	stack<BSTNode*> ns;

	ns.push(tree);

	while (!ns.empty())
	{
		BSTNode* t = ns.top();
		std:cout << t->data << std::endl;

		ns.pop();

		if (t->right != nullptr)
		{
			ns.push(t->right);
		}

		if (t->left != nullptr)
		{
			ns.push(t->left);
		}
	}
}

bool CheckEqual(BSTNode* s, BSTNode* t)
{
	if (s == nullptr && t == nullptr)
	{
		return true;
	}
	
	if (s == nullptr || t == nullptr)
	{
		return false;
	}

	return (s->data == t->data) && (CheckEqual(s->left, t->left)) && (CheckEqual(s->right, t->right));
}

bool IsSubtree(BSTNode* s, BSTNode *t)
{
	if (s == nullptr)
	{
		return s == t;
	}

	bool ret = CheckEqual(s, t);

	if (ret)
	{
		return ret;
	}
	else
	{
		return IsSubtree(s, t->left) || IsSubtree(s, t->right);
	}

}

void GetVerticalOrder(BSTNode* t, int hd, map<int, vector<int>> & hash)
{
	if (t == nullptr)
	{
		return;
	}

	hash[hd].push_back(t->data);

	GetVerticalOrder(t->left, hd - 1, hash);
	GetVerticalOrder(t->right, hd + 1, hash);
}

void PrintVerticalOrder(BSTNode* t)
{
	int hd = 0;

	map<int, vector<int>> hash;

	GetVerticalOrder(t, hd, hash);

	for (auto iter = hash.begin(); iter != hash.end(); iter++)
	{
		for (int i = 0; i<iter->second.size(); ++i)
			cout << iter->second[i] << " ";
		cout << std::endl;
	}
}

void FindMinMax(BSTNode* t, int hd, int& min, int& max)
{
	if (t == nullptr)
	{
		return;
	}

	if (hd < min)
	{
		min = hd;
	}

	if (hd > max)
	{
		max = hd;
	}

	FindMinMax(t->left, hd - 1, min, max);
	FindMinMax(t->right, hd + 1, min, max);
}

void PrintVerticalLine(BSTNode* t, int hd, int lineNo)
{
	if (t == nullptr)
	{
		return;
	}

	if (hd == lineNo)
	{
		std::cout << t->data << " ";
	}

	PrintVerticalLine(t->left, hd - 1, lineNo);
	PrintVerticalLine(t->right, hd + 1, lineNo);
}

void PrintVerticalOrder2(BSTNode* t)
{
	int min = 0, max = 0;
	FindMinMax(t, 0, min, max);

	for (int i = min; i <= max; i++)
	{
		PrintVerticalLine(t, 0, i);
	}
}

int Max(int* arr, int begin, int end)
{
	int maxIndex = begin;
	int max = arr[maxIndex];

	for (int i = begin; i <= end; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

BSTNode* MaxBST(int* arr, int begin, int end)
{
	if (arr == nullptr || begin > end)
	{
		return nullptr;
	}

	int index = Max(arr, begin, end);
	BSTNode* root = new BSTNode();
	root->data = arr[index];

	root->left = MaxBST(arr, begin, index - 1);
	root->right = MaxBST(arr, index + 1, end);

	return root;
}

BSTNode* InOrderSuccessor(BSTNode* root, BSTNode* node)
{
	if (root == nullptr || node == nullptr)
	{
		return nullptr;
	}

	if (node->right != nullptr)
	{
		BSTNode* next = node->right;
		while (next != nullptr)
		{
			next = next->left;
		}

		return next;
	}
	else
	{
		// Note: no right child, find its parent
		// BSTNode* p = node->parent;

		// Note: if parent is null, return
		// if this node is its parent's left, return parent
		// if this node is its parent's right, and parent is not nul, keep finding 
		/*
		while (p != nullptr && node == p->right)
		{
			n = p;
			p = p->parent;
		}

		return parent;
		*/
	}
}

void BST2Vec(BSTNode* t, vector<int>& vec)
{
	if (t == nullptr)
	{
		return;
	}

	BST2Vec(t->left, vec);
	vec.push_back(t->data);
	BST2Vec(t->right, vec);;
}

vector<int> FindPairInBST(BSTNode* t, int k)
{
	vector<int> vec;
	BST2Vec(t, vec);

	vector<int> ret;

	for (int start = 0, end = vec.size() - 1; start < end; )
	{
		if (vec[start] + vec[end] == k)
		{
			ret.push_back(vec[start]);
			ret.push_back(vec[end]);
			return ret;
		}
		else if (vec[start] + vec[end] > k)
		{
			end--;
		}
		else
		{
			start++;
		}

	}

	return ret;
}

vector<int> FindPairInBST2(BSTNode* t, int k)
{
	vector<int> ret;

	if (t == nullptr)
	{
		return ret;
	}

	bool loopFlag1 = true;
	bool loopFlag2 = true;

	stack<BSTNode*> s1;
	stack<BSTNode*> s2;

	BSTNode* cur1 = t;
	BSTNode* cur2 = t;

	int val1 = 0;
	int val2 = 0;

	while (1)
	{
		while (loopFlag1)
		{
			if (cur1 != nullptr)
			{
				s1.push(cur1);
				cur1 = cur1->left;
			}
			else
			{
				if (s1.empty())
				{
					loopFlag1 = false;
				}
				else
				{
					cur1 = s1.top();
					s1.pop();

					val1 = cur1->data;
					cur1 = cur1->right;
					loopFlag1 = false;
				}
			}
		}

		while (loopFlag2)
		{
			if (cur2 != NULL)
			{
				s2.push(cur2);
				cur2 = cur2->right;
			}
			else
			{
				if (s2.empty())
					loopFlag2 = false;
				else
				{
					cur2 = s2.top();
					s2.pop();
					val2 = cur2->data;
					cur2 = cur2->left;
					loopFlag2 = false;
				}
			}
		}

		if ((val1 != val2) && (val1 + val2) == k)
		{
			ret.push_back(val1);
			ret.push_back(val2);
			return ret;
		}

		else if ((val1 + val2) < k)
			loopFlag1 = false;

		else if ((val1 + val2) > k)
			loopFlag2 = false;

		if (val1 >= val2)
			return ret;
	}
}