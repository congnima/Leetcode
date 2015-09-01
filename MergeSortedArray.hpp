//Merge Sorted Array
//
//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Note:
//You may assume that A has enough space(size that is greater or equal to m + n) 
//to hold additional elements from B.The number of elements initialized in A and B 
//are m and n respectively.


class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		for (int i = m-1; i >= 0; i--)
		{
			A[i + n] = A[i];
		}



		int pA = n;
		int pB = 0;

		for (int i = 0; i < m + n; i++)
		{
			if (pA < m+n && (pB == n || A[pA] <= B[pB]))
			{
				A[i] = A[pA];
				pA++;
			}
			else if (pB < n && (pA == m + n  || A[pA] > B[pB]))
			{
				A[i] = B[pB];
				pB++;
			}
		}
	}
};