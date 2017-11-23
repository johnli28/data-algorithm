#pragma once

#include <memory>

typedef struct BSTNode
{
	// One data, two child pointers
	int data;

	// Inside BSTNode, cannot define member as ListNodePtr type, must use BSTNode* 
	std::shared_ptr<BSTNode> lChild;
	std::shared_ptr<BSTNode> rChild;

} BSTNode;

typedef std::shared_ptr<BSTNode> BSTNodePtr;

class BST
{
public:
	BST() { root = nullptr; }
	bool Search(int key, BSTNodePtr& pos);
	bool SearchRecur(BSTNodePtr tree, BSTNodePtr parent, int key, BSTNodePtr& pos);
	bool Insert(int key);
	void PostfixPrint();
	void PostfixPrintRecur(const BSTNodePtr& tree);

	BSTNodePtr root;
};
