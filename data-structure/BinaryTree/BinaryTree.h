#pragma once

#include <string>

using namespace std;

struct BTNode
{
	int data;
	BTNode* left;
	BTNode* right;
};

typedef BTNode* BinaryTree;

void DeserializeInorder(const string& inStr, int& pos, BinaryTree & outTree);
void Deserialize(const string& inStr, BinaryTree & outTree);

void PrintLeavesNodes(BinaryTree tree);

void UnclockwisePrintEdgeNodes(BinaryTree tree);
