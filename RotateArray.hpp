//Rotate Array
//
//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, 
//the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].

#include <vector>
#include <algorithm>

class Solution
{
public:
	void rotate(std::vector<int>& nums, int k)
	{
		if (nums.size() == k)
			return;

		k = k % nums.size();

		std::reverse(nums.begin(), nums.begin() + nums.size() - k);
		std::reverse(nums.begin() + nums.size() - k, nums.end());
		std::reverse(nums.begin(), nums.end());
	}
};