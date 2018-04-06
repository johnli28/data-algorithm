#pragma once

#include "BinarySearchTree.h"

#include <iostream>
#include <string>

using namespace std;

void DeserializePreOrder(const string& inStr, int& pos, BSTNode* & outTree);

void Deserialize(const string& inStr, BSTNode* & outTree)
{
	if (inStr.empty())
	{
		return;
	}

	int startPos = 0;

	DeserializePreOrder(inStr, startPos, outTree);

}

// Note: use pos to track the position, must &
void DeserializePreOrder(const string& inStr, int& pos, BSTNode* & outTree)
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

			outTree = new BSTNode;
			outTree->data = value;
			outTree->left = nullptr;
			outTree->right = nullptr;

		}

		pos += endPos - pos + 1;

	}

	DeserializePreOrder(inStr, pos, outTree->left);

	DeserializePreOrder(inStr, pos, outTree->right);

}