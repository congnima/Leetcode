//Search a 2D Matrix II
//
//Write an efficient algorithm that searches for a value in an m x n matrix.
//This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//For example,
//
//Consider the following matrix :
//
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//Given target = 5, return true.
//
//Given target = 20, return false.

#include <vector>

class Solution 
{
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
	{
		std::size_t cols = matrix[0].size();
		std::size_t rows = matrix.size();

		std::size_t c = cols - 1;
		std::size_t r = 0;

		while (c < cols && r < rows)
		{
			if (matrix[r][c] == target)
				return true;
			else if (matrix[r][c] > target)
				c -= 1;
			else if (matrix[r][c] < target)
				r += 1;
		}

		if (c >= cols || r >= rows)
			return false;
 	}
};