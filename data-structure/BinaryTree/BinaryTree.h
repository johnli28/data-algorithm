#pragma once

#include <string>

using namespace std;

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};



typedef BinaryTreeNode* BinaryTree;

void DeserializeInorder(const string& inStr, int& pos, BinaryTree & outTree);
void Deserialize(const string& inStr, BinaryTree & outTree);

void PrintLeavesNodes(BinaryTree tree);

void UnclockwisePrintEdgeNodes(BinaryTree tree);
