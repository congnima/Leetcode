//Number of Islands
//
//Given a 2d grid map of '1's(land) and '0's(water), 
//count the number of islands.An island is surrounded 
//by water and is formed by connecting adjacent 
//lands horizontally or vertically.You may assume 
//all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer : 1
//
//		
//Example 2 :
//
//11000
//11000
//00100
//00011
//Answer : 3

#include <vector>
using namespace std;

class Solution 
{
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		int cnt = 0;

		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					cnt++;
					expandIsland(grid, i, j);
				}
			}

		return cnt;
	}

	void expandIsland(std::vector<vector<char>>& grid,
		std::size_t i, std::size_t j)
	{
		if (i >= grid.size() 
			|| i < 0
			|| j >= grid[0].size()
			|| j < 0)
			return;

		if (grid[i][j] == '1')
		{
			grid[i][j] = 'X';
			expandIsland(grid, i - 1, j);
			expandIsland(grid, i + 1, j);
			expandIsland(grid, i, j - 1);
			expandIsland(grid, i, j + 1);
		}
	}
};