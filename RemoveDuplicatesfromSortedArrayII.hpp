//Remove Duplicates from Sorted Array II
//
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array nums = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, 
//with the first five elements of nums being 1, 1, 2, 2 and 3. 
//It doesn't matter what you leave beyond the new length.

#include <vector>
using namespace std;

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums) 
	{
		std::size_t len = nums.size();

		if (0 == len)
			return 0;

		int cnt = 1;
		for (size_t i = 1; i < nums.size();)
		{
			if (nums[i] == nums[i - 1])
			{
				if (cnt-- == 0)
				{
					nums[i] = nums[i + 1];
					cnt = 1;
				}
				else
				{

				}
			}
			else if ()
		}

		return len;
	}
};