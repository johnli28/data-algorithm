#include "palindrome.h"
#include "TwoSum.h"
#include "NumberOfWaysToStep.h"
#include "Fibonacci.h"

void main()
{
	int m = 1001;
	int np = FindNextPalindrome(m);

	int a[] = { 4, 5, 2, 19, 21, 71, 99, 12, 8, 102 };

	vector<int> twosum = TwoSum(a, 10, 101);

	int fib10 = Fibonacci(10);

	vector<int> twosumDK = TwoSumDivisibleByK(a, 10, 3);

}