//Jump Game
//
//Given an array of non - negative integers, you are initially positioned at the first index 
//of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.



class Solution {
public:
	bool canJump(int A[], int n) {
		int i = 0;
		int max_index = 0;

		while (max_index < n - 1)
		{
			if (i < n && i + A[i] > max_index)
			{
				max_index = i + A[i];
				i++;
			}
			else if (i < max_index)
			{
				i++;
			}
			else if (i == max_index && 0 == A[i])
			{
				return false;
			}
		}

		if (max_index >= n - 1)
			return true;
	}
};