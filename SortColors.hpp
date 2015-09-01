//Sort Colors
//
//Given an array with n objects colored red, white or blue, 
//sort them so that objects of the same color are adjacent, 
//with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 
//to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.

#include <vector>
#include <utility>

class Solution 
{
public:
	void sortColors(std::vector<int>& nums) 
	{
		std::size_t begin = -1;
		std::size_t current = 0;
		std::size_t end = nums.size();

		while (current < end)
		{
			if (0 == nums[current])
				std::swap<int>(nums[++begin], nums[current++]);
			else if (1 == nums[current])
				++current;
			else if (2 == nums[current])
				std::swap<int>(nums[current], nums[--end]);
		}
	}
};