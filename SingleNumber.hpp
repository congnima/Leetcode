//Single Number
//
//Given an array of integers, 
//every element appears twice except for one.
//Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.
//Could you implement it without using extra memory ?

#include <vector>

class Solution
{
public:
	int singleNumber(std::vector<int>& nums)
	{
		int res = 0;

		for (size_t i = 0; i < nums.size(); i++)
			res ^= nums[i];

		return res;
	}
};