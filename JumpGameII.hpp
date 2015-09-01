//Jump Game II
//
//Given an array of non - negative integers, you are initially positioned at the first index 
//of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example :
//Given array A = [2, 3, 1, 1, 4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, 
//then 3 steps to the last index.)


#include <climits>

class Solution {
public:
	//int jump(int A[], int n) 
	//{
	//	
	//	if (0 == n && 1 == n)
	//		return 0;

	//	A[n - 1] = 0;
	//	for (int i = n - 1; i > -1; i--)
	//	{
	//		if (A[i] != 0)
	//			A[i] = min(&A[i]+1, A[i]) + 1;
	//	}

	//	return A[0];
	//}
	//
	//int min(int A[], int n)
	//{
	//	int min = INT_MAX;

	//	int i = 0;
	//	while (i < n)
	//	{
	//		if (A[i] < min)
	//			min = A[i];

	//		i++;
	//	}

	//	return min;
	//}

	int jump(int A[], int n)
	{
		if (0 == n || 1 == n)
			return 0;

		int steps = 0;
		int range = 0;
		int max_index = 0;

		for (int i = 0; i < n; i++)
		{
			if (i > range)
			{
				range = max_index;
				++steps;
			}
			max_index = max(max_index, i + A[i]);
		}

		return steps;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};