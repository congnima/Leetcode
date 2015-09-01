//Remove Element

//Given an array and a value, remove all instances of that value in place and 
//return the new length.

//The order of elements can be changed.It doesn't matter what you leave beyond 
//the new length.

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int end = n - 1;

		for (int i = 0; i <= end; i++)
		{
			while (end > 0 && A[end] == elem)
				end--;

			if (0 == end && A[0] == elem)
				return 0;

			if (i < end && A[i] == elem)
				A[i] = A[end--];
		}

		return end + 1;
	}
};