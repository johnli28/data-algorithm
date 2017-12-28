#pragma once

#include <vector>

using std::vector;

int BinarySearch(const vector<int>& v, int key);
int GetFirstK(const vector<int>& v, int k);
int GetLastK(const vector<int>& v, int k);
int GetNumberOfK(const vector<int>& v, int k);
int GetMinOfRotatedSortedArray(const vector<int>& v);
//int GetFirstKRecur(const vector<int>& v, int k, int low, int high);