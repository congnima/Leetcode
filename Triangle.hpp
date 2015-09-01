//Triangle
//
//Given a triangle, find the minimum path sum from top to bottom.
//Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//	  [2],
//	[3, 4],
// [6, 5, 7],
//[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, 
//where n is the total number of rows in the triangle.

#include <vector>

class Solution 
{
public:
	int minimumTotal(std::vector<std::vector<int>>& triangle)//dynamic programming
	{
		std::size_t row = triangle.size() - 1;
		std::size_t col = 0;

		std::vector<int> vct = triangle[row];
		--row;

		while (row < triangle.size())
		{
			while (col <= row)
			{
				vct[col] = triangle[row][col] + std::min<int>(vct[col], vct[col + 1]);
				++col;
			}
				
			--row;
			col = 0;
		}


		return vct[0];
	}

	int minimumTotal1(std::vector<std::vector<int>>& triangle) //the version of recursion
	{
		return minimumTotal(triangle, 0, 0);
	}

	int minimumTotal(std::vector<std::vector<int>>& triangle,
		std::size_t row,std::size_t col)
	{
		if (row >= triangle.size() || col >= triangle[row].size())
			return 0;

		return triangle[row][col] +
			std::min<int>(minimumTotal(triangle, row + 1, col),
			minimumTotal(triangle, row + 1, col + 1));
	}
};