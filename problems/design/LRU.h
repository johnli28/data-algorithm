#pragma once

#include <list>
#include <unordered_map>

using namespace std;

class LRU
{
public:
	LRU(int capacity);
	~LRU();

	int get(int key);
	void put(int key, int value);

private:
	int mCapacity;

	// Note: list to save key and data, hash for key and list iterator
	list<pair<int, int>> mData;
	unordered_map<int, list<pair<int, int>>::iterator> mHash;
};

LRU::LRU(int capacity)
{
	mCapacity = capacity;
}

LRU::~LRU()
{
	mHash.clear();
	mData.clear();
}

void LRU::put(int key, int value)
{
	if (mHash.find(key) != mHash.end())
	{
		mData.erase(mHash[key]);
		mData.push_front(pair<int, int>(key, value));
		mHash[key] = mData.begin();
	}
	else if (mData.size() < mCapacity)
	{
		mData.push_front(pair<int, int>(key, value));
		mHash[key] = mData.begin();
	}
	else
	{
		mHash.erase(mData.back().first);
		mData.pop_back();
	}
}

int LRU::get(int key)
{
	if (mHash.find(key) != mHash.end())
	{
		put(key, mHash[key]->second);
		return mHash[key]->second;
	}
	else
	{
		// Note: page fault
		return -1;
	}
}