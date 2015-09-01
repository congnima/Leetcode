//Subsets
//
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1, 2, 3], a solution is :
//
//[
//	[3],
//	[1],
//	[2],
//	[1, 2, 3],
//	[1, 3],
//	[2, 3],
//	[1, 2],
//	[]
//]


#include <vector>

class Solution 
{
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> res;

		if (0 == nums.size())
			return res;


	}
};