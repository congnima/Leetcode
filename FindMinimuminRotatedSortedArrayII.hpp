//Find Minimum in Rotated Sorted Array II
//
//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.

#include <vector>

class Solution 
{
public:
	int findMin(std::vector<int>& nums) 
	{
		int min = nums[0];

		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] < min)
			{
				min = nums[i];
				break;
			}
		}

		return min;
	}
};