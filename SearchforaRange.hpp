//Search for a Range
//
//Given a sorted array of integers, find the starting 
//and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].

#include <vector>

class Solution 
{
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target) 
	{
		std::vector<int> res;

		if (0 == nums.size())
			return res;

		int l = 0;
		int u = nums.size() - 1;

		while (l < u)
		{
			int m = (l + u) / 2;

			if (nums[m] < target)
				l = m + 1;
			else if (nums[m] > target)
				u = m - 1;
			else
				l = u = m;
		}


		if (l == u && nums[l] == target)
		{
			while (l >= 0 && nums[l] == target)
				--l;
			while (u < nums.size() && nums[u] == target)
				++u;		
			
			res.push_back(l + 1);
			res.push_back(u - 1);
		}
		else
		{
			res.push_back(-1);
			res.push_back(-1);
		}

		return res;
	}
};