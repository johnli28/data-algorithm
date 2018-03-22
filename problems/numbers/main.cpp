#include "palindrome.h"
#include "TwoSum.h"
#include "NumberOfWaysToStep.h"
#include "Fibonacci.h"
#include "MinSizeSubarraySum.h"
#include "ReverseArray.h"

void main()
{
	int m = 1001;
	int np = FindNextPalindrome(m);

	int a[] = { 4, 5, 2, 19, 21, 71, 99, 12, 8, 102 };

	int aSz = sizeof(a) / sizeof(int);

	vector<int> twosum = TwoSum(a, sizeof(a) / sizeof(int), 101);

	int fib10 = Fibonacci(10);

	vector<int> twosumDK = TwoSumDivisibleByK(a, sizeof(a) / sizeof(int), 3);

	int minSizeSubarrarySum = MinSizeSubarraySum(a, sizeof(a) / sizeof(int), 169);

	ReverseArray(a, sizeof(a) / sizeof(int));
}