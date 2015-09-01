//Search in Rotated Sorted Array
//
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, 
//otherwise return -1.
//
//You may assume no duplicate exists in the array.


#include <vector>

class Solution 
{
public:
	int search(std::vector<int>& nums, int target) 
	{
		if (nums.empty())
			return -1;

		std::size_t l = 0;
		std::size_t u = nums.size() - 1;
		std::size_t m = 0;

		while (l < u && u < nums.size())
		{
			m = (l + u) / 2;

			if (target == nums[m])
				l = u;
			else if (target < nums[m])
				u = m - 1;
			else if (target > nums[m] && nums[l] < nums[u])
				l = m + 1;
			else if (target > nums[m] && nums[l] > nums[u] && target > nums[l])
				u = m - 1;
			else if (target > nums[m] && nums[l] > nums[u] && target < nums[l])
				l = m + 1;
		}


		if (l == u && nums[m] == target)
			return m;
		else
			return -1;
	}
};