//Set Matrix Zeroes
//
//Given a m x n matrix, 
//if an element is 0, 
//set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up :
//Did you use extra space ?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution ?

#include <vector>
#include <unordered_set>

class Solution 
{
public:
	void setZeroes(std::vector<std::vector<int>>& matrix) 
	{
		std::unordered_set<int> cols;

		for (size_t i = 0; i < matrix.size(); i++)
		{
			bool bSet = false;

			for (size_t j = 0; j < matrix[0].size(); j++)
			{
				if (0 == matrix[i][j])
				{
					if (0 == cols.count(j))
						cols.insert(j);

					bSet = true;
				}
			}

			if (bSet)
				setRowZeroes(matrix, i);
		}

		for (auto it = cols.begin(); it != cols.end(); it++)
		{
			setColZeroes(matrix, *it);
		}
	}

	void setRowZeroes(std::vector<std::vector<int>>& matrix,std::size_t row)
	{
		for (size_t i = 0; i < matrix[0].size(); i++)
		{
			matrix[row][i] = 0;
		}
	}

	void setColZeroes(std::vector<std::vector<int>>& matrix, std::size_t col)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			matrix[i][col] = 0;
		}
	}
};