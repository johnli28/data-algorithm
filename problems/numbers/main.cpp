#include "palindrome.h"
#include "TwoSum.h"
#include "NumberOfWaysToStep.h"
#include "Fibonacci.h"
#include "MinSizeSubarraySum.h"
#include "ReverseArray.h"
#include "HasDuplicateNumber.h"
#include "MaxSubarraySumEqualK.h"
#include "IntegerToWords.h"

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

	int dn;
	int aDN[10] = {0, 1, 2, 2, 4, 3, 3, 6, 7, 10};

	bool hasDN = HasDuplicateNumber(nullptr, 10, dn);
	hasDN = HasDuplicateNumber(aDN, -2, dn);
	hasDN = HasDuplicateNumber(aDN, sizeof(aDN) / sizeof(int), dn);

	int a1toN[5] = { 1, 2, 3, 5, 5};
	hasDN = HasDuplicateNumber1toN(a1toN, sizeof(a1toN) / sizeof(int), dn);

	int arrMS[] = { 1, -1, 10, 5, 2, 7, 1, 2, -2, 9 };

	int maxSubarraySum = MaxSubarraySumEqualK(arrMS, sizeof(arrMS) / sizeof(arrMS[0]), 15);


	string words = IntegerToWords(1234567);
}