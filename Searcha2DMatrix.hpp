//Search a 2D Matrix
//
//Write an efficient algorithm 
//that searches for a value in an m x n matrix.
//This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix :
//
//[
//	[1, 3, 5, 7],
//	[10, 11, 16, 20],
//	[23, 30, 34, 50]
//]
//Given target = 3, return true.


#include <vector>

class Solution 
{
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
	{
		std::size_t rows = matrix.size();
		std::size_t cols = matrix[0].size();

		int l = 0;
		int u = rows*cols - 1;
		std::size_t m = 0;

		while (l <= u )
		{
			if (l == u)
				return matrix[l / cols][l % cols] == target;

			m = (l + u) / 2;

			if (matrix[m / cols][m % cols] < target)
				l = m + 1;
			else if (matrix[m / cols][m % cols] > target)
				u = m - 1;
			else if (matrix[m / cols][m % cols] == target)
				return true;
		}

		return false;
	}
};