//Remove Duplicates from Sorted Array

//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1, 1, 2],
//
//Your function should return length = 2, and A is now[1, 2].


class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (1 == n)
			return 1;

		if (0 == n)
			return 0;

		int j = 1;
		for (int i = 1; i < n; i++)
		{
			while (j < n && A[i - 1] == A[j])
				j++;

			if (j < n && A[i - 1] != A[j])
			{
				A[i] = A[j];
				j++;
			}
			else if (j >= n)
				return i;

		}
		return j;
	}
};